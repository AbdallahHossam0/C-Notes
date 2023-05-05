#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <span>
#include <functional>
using namespace std;


/*********************************************************
 * *******************************************************
 * Function Pointers, Function Objects, Lampda Function
 * *******************************************************
 * *******************************************************
*/

//>>>>>>>>>>>>>>>>>>>  Function Pointers  <<<<<<<<<<<<<<<<<<<<<<


// Functions in C and C++ are so-called ""First Class Functions"" so it can be passed to other functions
// returning from other function and assign them to variables

// a class that overloads the operator() is called function object or functor for short

/********************************************
 * to define a function pointer use
 * bool(*func_ptr)(int, int);
 * to make the type of the function is a short type or a typedef you can use
 * using Matcher = bool (*) (int, int);
 * SHOW the Following Example 
*/



// Example 1:

using Matcher = bool (*) (int, int);
using MatchHandler = void (*) (size_t, int, int);


void findMatches(span <const int> values1, span <const int> values2, Matcher matcher, MatchHandler handler){
    // look here how const to span is defined^^^^^^^
    if(values1.size() != values2.size()) return;

    for(size_t i{}; i < values1.size(); ++i){
        if(matcher(values1[i], values2[i])){
            handler(i, values1[i], values2[i]);
        }
    }

}

bool intEqual(int x, int y){
    return x == y;
}

void printMatch(size_t i, int x, int y){
    cout << "Match found at position " << i << " :" << x << ", " << y << endl; 
}


// int main(void){
//     vector values1{2, 5, 6, 9, 10, 1, 1};
//     vector values2{4, 4, 2, 9, 0, 3, 1};

//     cout << "Calling findMatches using int equal: " << endl;
//     findMatches(values1, values2, &intEqual, &printMatch); // WoW
// // The output:
// // Calling findMatches using int equal: 
// // Match found at position 3 :9, 9
// // Match found at position 6 :1, 1

// }

// Example 2

// bool bothOdd(int item1, int item2){
//     return ((item1 % 2) && (item2 % 2));
// }

// int main(void){
//     vector values1{2, 5, 6, 9, 10, 1, 1};
//     vector values2{4, 4, 2, 9, 0, 3, 1};

//     cout << "Calling findMatches using int equal: " << endl;
//     findMatches(values1, values2, &bothOdd, &printMatch); // WoW
// // The output:
// Calling findMatches using int equal:
// // Match found at position 3 :9, 9
// // Match found at position 5 :1, 3
// // Match found at position 6 :1, 1

// }

// Note how function pointers can make the functions generic


// We always use function pointers when using DLL (Dynamic Linkage Libraries)

/***********************************************************************************/
/***********************************************************************************/
/***********************************************************************************/
/***********************************************************************************/
/***********************************************************************************/

// ******** Pointers to method and data members ********************

// We can't get the address of non-static methods and data members without an object as they are per-object basis
// so to use a method or data-member address you shpuld dereference them in the context of an object

// assume you have an Employee class that has a get salary method
// to make a pointer to method do the following 

/**
 * int (Employess::*methodPtr) () const {&Employee::getSalary}; methodptr now is a pointer to get salary method (You can simplify that with auto -type deduction-)
 * Employee emp {"Ahmed", "Ali"}; object to call the method on
 * cout << (emp.*methodPtr)() << endl;  the method is called for the object emp
*/

// Note that
// C++ permits you to dereference a pointer to a static data member or static method without an object

// std::function in <functional> which is a ployformic function wrapper
// can be used to create types that can point to any callable thing such as functions, function object or a lambda expression
// cab be used as a function pointer or for a callback

// syntax >>>> std::function<R(ArgTypes...)
// R is the return type of the function
// ArgTypes is a comma seperated list of types for the function parameters


// // Example 3
// void func(int num){
//     cout << "The num is " << num << endl;
// }

// int main (void){
//     // function<void(int)> f1{func};
//     function f1 {func}; // using CTAD
//     // or auto f1{func}; // => Now it is a pointer to function not of type "function" 
//     f1(5);
// }

// The output is
// The num is 5

// or you can use CTAD as following
// function f1 {func};


// To use function template for callbacks notice the following syntax
// template<typename Matcher, typename MatchHandler>
// void findMatches(span<const int> v1, span<const int> v2, Matcher matcher, MatchHandler handler){
//     /* .............................................................. */
// }



// in C++20 you can make call backs like that:
// void findMatches(span<const int> v1, span<const int> v2, auto matcher, auto handler)
// notice that                                             ^^^^^^^^^^^^^^^^^^^^^^^^^^^
// This is called abbreviated function template syntax


// To use callbacks in C or in C++ it's recommended for callbacks to use function template or abbreviated function template
// not to use function pointers or std::function in functional 

