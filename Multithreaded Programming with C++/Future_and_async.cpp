// How to get the computed result back from a thread?

// A promise is something where a thread stores its result. (input side of the
// result)
// A future can be used to access the result stored in promise (output
// side of the result)

// this mechanism is an inter-thread communication for a result

// Example
#include <future>
#include <iostream>
#include <thread>

using namespace std;

void doWork(promise<int> thePromise) {
    // Do some work

    thePromise.set_value(42);
}

// int main(void) {
//     promise<int> myPromise;

//     // get the future of this promise
//     auto theFuture{myPromise.get_future()};

//     // create the thread which us auto joinable
//     jthread theThread{doWork, move(myPromise)};
//     // use move no copies

//     int res{theFuture.get()};

//     cout << "Result is " << res << endl;
//     // The output is
//     //  Result is 42
// }

// ! note that future and exception can be used to pass exception between
// ! threads
// ! remember that the exception must be caught by the thread throws it
// ! or the std::terminate will be called

// * or you can use std::packaged_task instead of std::promise

int calc(int x, int y) { return x + y; }

// int main(void) {
//     packaged_task<int(int, int)> task(calc);

//     auto theFuture{task.get_future()};

//     jthread theThread{move(task), 5, 9};

//     int res{theFuture.get()};

//     cout << "Result is " << res << endl;
//     // The output is
//     //  Result is 14
// }

// * std::async
// async usually accepts a function to be executed and returns a future to be
// used to retrieve the result

// there are 2 types of it
// 1 - running the function in a separate thread. [async]
// 2 - running the function when you call get to the future returned

// async (default or pass launch :: async)
// sync (pass launch :: deferred)
// let the runtime choose (launch :: async | launch :: deferred)

// Example
int calculate(void) { return 42; }

// int main(void) {
//     auto myFuture{async(calculate)};
//     int res{myFuture.get()};
//     cout << "the result is " << res << endl;
// }