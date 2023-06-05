// Atomics

// Atomic types allow atomic access
// it is defined in <atomic>

#include <atomic>
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <functional>
using namespace std;

// to define an atomic variable use that

atomic<int> counter_atomic{};

// ++counter => can be safely used in multiple threads

// atomic_bool
// atomic<bool>

// atomic_char
// atomic<char>

// atomic_uchar
// atomic<unsigned char>

// atomic_int
// atomic<int>

// atomic_uint
// atomic<unsigned int>

// atomic_long
// atomic<long>
// and so on ...........

// and  Use Atomics to stop Data Race (race conditionas)

// Atomic Operations
// There are some atomic operations like compare_exchange_strong, fetch add, fetch_sub, 
// fetch_and, fetch_or, fetch_xor, ++, --, +=, -=, &=, |= and ^=

// also atomic pointers support fetch_add, fetch_sub, ++, --, +=, -=

// Example
// int main(void){
//     atomic_int value {10};
//     cout << "value =" << value << endl;
//     int fetched {value.fetch_add(4)};
//     cout << "value =" << value << endl;
//     cout << "fetched =" << fetched << endl;
// }

// note that
// the fetched value is the same as value before the addition
// but value is the new value after addition "Atomic Oeration"

// C++20 Add the ability for float and double to be fetched fetch_add, fetch_sub ^^
// C++20 adds the ability for atomic<std::shared_ptr<T>>
// C++20 introduces std::atomic_ref. it helps to make the reference atomic while the variable itsself is not atomic

// How to use Atomic Types
// Example 1
// void increment(int& counter)
// {
// 	for (int i{ 0 }; i < 100; ++i) {
// 		++counter;
// 		this_thread::sleep_for(1ms);
// 	}
// }

// int main()
// {
// 	int counter{ 0 };
// 	vector<thread> threads;

// 	for (int i{ 0 }; i < 10; ++i) {
// 		threads.push_back(thread{ increment, ref(counter) });
// 	}

// 	for (auto& t : threads) {
// 		t.join();
// 	}

// 	cout << "Result = " << counter << endl;
//     // The output is 903, 906 {wrong answer^^} (data race occured)
// }

void increment(atomic<int>& counter)
{
	for (int i{ 0 }; i < 100; ++i) {
		++counter;
		this_thread::sleep_for(1ms);
	}
}

int main()
{
	atomic<int> counter{ 0 };
	vector<thread> threads;

	for (int i{ 0 }; i < 10; ++i) {
		threads.push_back(thread{ increment, ref(counter) });
	}

	for (auto& t : threads) {
		t.join();
	}

	cout << "Result = " << counter << endl;
    // The output is 1000 (accurate -no data race-) code is now thread-safe
}


// note the use of C++20 atomic_ref by making the counter atomic while the variable itself is not atomic

// note that 
// it is better to make the use of atomic operations and types as minimum as you can
// as it lower the performance


// Wating on Atomic Variables
// for std::atomic and std::atomic_ref
// the available methods
// wait(old) =>< breals the thread until another thread calls notify_one() or notify_all and the value is not equal to the old one
// notify_one()
// notify_all()



