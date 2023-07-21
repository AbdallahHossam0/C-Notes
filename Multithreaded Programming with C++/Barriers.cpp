// * std::barrier is defined in <barrier>
// ! CPP20 feature

// A number of threads block at the barrier point (they are blocked now)
// when a given number of threads reach the barrier point a phase completion
// call back is executed and teh threads are now unblocked and the thread
// counter is reset and the next phase is started and during each phase the
// number of expected threads can be adjusted
// it is used to perform synchronization between loops

// the most important method is arrive and wait
