#include <iostream>
#include <functional>
using namespace std;


// Multi Threaded Programming with C++

// Multiple CPU systesms
//  1- Many chpis each chip has its own CPU
//  2- One chips has multiple CPUs in it (multi-Core)

// Note that: One system can have BOTH ^^

// Multi Threaded code is availbale in C++ since C++11

// C++ multi-thread code targets CPUs not GPUs

// Why multi-Threaded Code???
//  1- Boast Performance
//  2- as Example UI remains responsivewhile a big computations run in the background

// Problems of multi-Threaded Code?
//  1- How to convert your algorithm to be work in parallel?
//  2- Race conditions
//  3- Deadlocks
//  4- False Sharing

// Race Condition (Before using semaphores)
// Many threads want to access the same shared variable and at least one thread is writing at this shared variable.
// To solve this race condition you can use atomic instructions and
// atomic operations or use mutual exclusion but avoid deadlocks


// DeadLocks
// Two threads are deadlocked if they are both waiting for the other thread to do something.
// Solutions to avoid deadlocks
//  1- acquire semaphores on the same order
//  2- wait a time in then release the semaphore
//  3- lock all semaphores in one atomic instruction with help of RAII locks


// False Sharing
// They work in parallel in multiple threads but each thread waits the another thread finishing accessing the data


// ====================================================================================================

// Threads
// defined in <thread>
#include <thread>


// Thread with function pointer

void counter(int id, int numIteration){
    for(int i{}; i < numIteration; ++i){
        cout << "Counter " << id << " has value " << i << endl;
    }
}

// To make it in thread and run it do that like that:
thread t1 {counter, 1, 6}; // can accept any number of args (Varadic Template)
// Note that as the thread is created the thread starts execution
// before the tread object is destroyed (its scope is ended it will be destroyed automatically)
// you need to call .join() method to this thread to wait until the thread finish its execution
// if a not finished thread is destroyed (std::terminate will be called and terminate the whore program)

// cout is thread safe but its output can be interleaved to prevent that you can use the following line
// cout.sync_with_stdio(false);

// use ref(x), or cref(x) defined in <functional> to pass the function parameters by reference



// Thread with function object

// define a functor to be used as example

class Counter
{
public:
	Counter(int id, int numIterations)
		: m_id{ id }, m_numIterations{ numIterations }
	{
	}

	void operator()() const
	{
		for (int i{ 0 }; i < m_numIterations; ++i) {
			cout << "Counter " << m_id << " has value " << i << endl;
		}
	}

private:
	int m_id;
	int m_numIterations;
};	

// initialize the thread. It will run now
thread t2{ Counter{ 1, 20 } };
// Don't destroy it while the thread is still joinable
// To pass the object it self you ref or cref
Counter c {2, 12};
thread t3 {ref(c)};


// With Function pointer => the args to the function
// With function object  => you can access data memebers


// Thread with Lambda
// Lambda expression can fit nicely with the standard C++ threading library
// int main()
// {
// 	int id{ 1 };
// 	int numIterations{ 5 };
// 	thread t1{ [id, numIterations] {
// 		for (int i{ 0 }; i < numIterations; ++i) {
// 			cout << "Counter " << id << " has value " << i << endl;
// 		}
// 	} };
// 	t1.join();
// }

// Thread with Member Function
// you can specify a member function of a class to be executed in a thread
class Request
{
public:
	Request(int id) : m_id{ id } { }

	void process()
	{
		cout << "Processing request " << m_id << endl;
	}

private:
	int m_id;
};

// int main()
// {
// 	Request req{ 100 };
// 	thread t{ &Request::process, &req };

// 	t.join();
// }



// Thread Local Storage
// you can mark any variable as thread local 
// which means the thread will have its own copy of teh variable

// To declare a thread local variable 
thread_local int x;

// Note that:
// 	C++ does not include any mechansim for cancelling running threads from another thread.
// 	But it is possible to make the thread terminate itself
// 	One possible solution to make thread be able to terminate another thread is to use shared variable and 
// 	periodically check this variable

// C++20 introduces std::jthread
// 	It is automatically joins in its destructor and 
// 	supports cooperative cancellation (periodically check ir it need to cancel itself)

// there is 2 key classes defined in <stop_token>
// 1- std::stop_token	check if the thread should be cancelled
// 2- std::stop_source	request cancellation for the thread


// To get a result from a thread
// 	1- pass a pointer or a reference
// 	2- a data member of a functor
// 	3- use std::promise and std::future

// Exception on threads:
// 	Each exception must be caught on the thread that throws that exception 
// 	If the exception is not caught then C++ will call std::terminate()