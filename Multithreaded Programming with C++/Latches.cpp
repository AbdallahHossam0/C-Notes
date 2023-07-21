// it is a C++20 feature
// it is defined in <latch>

// A latch is a single use thread coordination point
// A number of threads block at a latch point. once the given number of threads
// reach the latch point, all threads are unblocks and continue execution
// -can be implemented using a non binary semaphore-

// std::latch constructor accepts the required number of threads that need to
// reach the latch point

// the thread arrived to the latch point call (arrive_and_wait()) which
// decrements the counter
// or you can call wait() to wait without decrement the counter
// or use try_wait() to check if the counter has reached 0
// or you can decrement the counter without waiting by calling count_down()

// ! this feature can be used for synchronization ^^
