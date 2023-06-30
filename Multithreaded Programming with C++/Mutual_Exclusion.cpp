// Mutual Exclusion
// To avoid data race => only 1 thread at a time can change the data

// Mutex Classes
// can be used for primary and user made data types
// but is's better to use atomics for the primary data type and use mutex for non-primary data types

// The C++ standard library provides non times and timed mutex classes ^^

// Mutex types

// 1- spinlock
// busy loop trying to acquire the lock, while acquiring the thread is active but not doing any useful work
// example
#include <vector>
#include <atomic>
#include <mutex>
#include <thread>
#include <iostream>
using namespace std;

atomic_flag spinlock = ATOMIC_FLAG_INIT; // we define the atomic flag to ATOMIC_FLAG_INIT

void doWork(int threadID, vector<size_t>& data){
    for(size_t i{}; i < 100; ++i){
        while (spinlock.test_and_set()){}
        data.push_back(threadID);
        spinlock.clear();
    }
}


// Non timed Mutex Classes
// std::mutex, std::recursive_mutex, std::shared_mutex

// They all support the following methods:
// lock=> try to get the lock and block till the lock has been acquired 
// try_lock=>   try to get the lock, but if the lock is already acquired by another thread then then it returns immediately
//              if the lock is acquired it returns true and false otherwise.
// unlock=> teh calling thraed releasethe lock it currently holds

// std::recursive_mutex
// non-binary mutex (can be acquired many times and unlock as times as it acquired)

// std::shared_mutex
// this makes the mutex be shared on read access and exclusive in write access
// these method id added to the shared mutex => lock_shared, try_lock_shared, unlock_shared

// timed mutex
// the mutex also supports these methods
// try_lock_for(duration) => it tries to lock for a certain duration if it can't do that within this duration it returns false
// try_lock_until(abs_time) => it tries to lock for till a time point if it can't do that it returns false
// these timed mutex help to avoid dead locks


// RAII locks 
// There are 4 types of locks => lock_gaurd, unique_lock, shared_lock and scoped_lock

// 1- lock_gaurd => it has 2 constructors 
// explicit lock_gaurd(mutex_type& m);
// lock_gaurd(mutex_type& m, adopt_lock_t); => adopt_lock_t => to release the lock automatically after the lock is destroyed 
// this lock waits until the lock is obtained
// example
mutex m;
lock_guard l{ m };

// 2-unique_lock (more sophisticated than lock_gaurd)
// it has 6 constructors
// 1- explicit unique_lock(mutex& m); => try to get the lock and wait till the lock is obtained
// 2- unique_lock(mutex& m, defer_lock_t) noexcept; => the lock can be obtained later
// 3- unique_lock(mutex& m, try_to_lock_t); => try to lock but it failse it does not block (the lock can be obtained later)
// 4- unique_lock(mutex& m, adopt_lock_t); => automatically release the mutex after the lock is destroyed 
// 5- unique_lock(mutex& m, abs_time); => try to obtain to lock till this time point
// 6- unique_lock(mutex& m, abs_time);  => try to obtain to lock within this duration
// Note_that => this unique lock has the following methods => lock, try_lock. try_lock_for, try_lock_until and unlock

// 3- shared_lock
// same as unique_lock but there are some extra methods as lock_shared, try_lock_shared, unlock_shared

// 4- scoped_lock
// same as lock_guard except it accepts a variable number of mutexes

// Acquring mutiple locks at once
// you are able to do that as following
mutex mut1;
mutex mut2;

void process_locks()
{
	unique_lock lock1{ mut1, defer_lock };
	unique_lock lock2{ mut2, defer_lock };
	//unique_lock<mutex> lock1{ mut1, defer_lock };
	//unique_lock<mutex> lock2{ mut2, defer_lock };
	lock(lock1, lock2);	// Locks acquired.

} // Locks automatically released.


// std::call_once
// you can use std::call_once() + std::onceflag to make certain function is called exctly once
// it commonly used to initialize one shared resource

// Example

// one global flag
once_flag g_onceFlag; 

void initialize_shared_resource(void){
    cout << "I am initialized" << endl;
}

void process(void){
    call_once(g_onceFlag, initialize_shared_resource);
    // if there is args to this function it is possible to pass them after pssing the function pointer
    cout << "processing" << endl;
}

int main(void){
    vector<thread> threads{};
    threads.emplace_back(process);
    threads.emplace_back(process);
    threads.emplace_back(process);
    for(auto& t : threads){
        t.join();
    }
    // The output will be like that
//  I am initialized
//  processing
//  processing
//  processing
}


