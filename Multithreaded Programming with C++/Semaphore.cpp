// std::counting_semaphore and binary_semaphore are defined in <semaphore>
// ! C++20 feature

// primitive time can be used to as building block for synch mechanisms such as
// (latches, barrier and mutex)
// the counter of the semaphore is initialized in the constructor

// 0 means that this semaphore is locked
// non 0 means that this semaphore is unlocked

// * Semaphore methods
// 1- acquire => decrement the counter if the counter is now 0 this thread is
// blocked

// 2- try acquire() => tries to decrement the counter but does not block if the
// counter is 0 returns true if possible and false otherwise.

// 3- try_acquire_for(duration)
// 4- try_acquire_until(abs_time)

// release => increment the counter by a given number and unblock threads that
// are blocking due to acquire call

// conditional variables can be implemented using semaphores initialized to 0
