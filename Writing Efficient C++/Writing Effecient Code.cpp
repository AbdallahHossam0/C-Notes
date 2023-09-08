// Performance => speed, memory usage, disk access and network use.
// Efficiency  => as quickly as possible without any wasted effort.

// ! A program can be efficient without being fast!!!

// * there are 2 approaches to efficiency
// 1- language level efficiency => pass by ref instead of passing by by value
// 2- design level efficiency => efficient algorithms, avoid unnecessary steps
// and computations and select appropriate design optimization

// ? Is C++ an inefficient language?
// C++ has high level language [Exceptions, concepts and virtual methods], so it
// is slower than other procedural languages. that is not correct.
// C++ might be faster than C it is dependent of the compiler and compiler
// optimization A generic rule in C++ is that "if you don't use a feature then
// you don't need to pay for it"
// C++ OOP help you write much cleaner code than any procedural languages like C
// C++ code is executed directly by a CPU not like C# and Java that need to run
// on virtual environment

// * 1- Language Level Efficiency
// this can be performed automatically using a good optimizing compilers

// * Handle Objects Efficiently
// pass by value => when move is possible and with primitive types and use pass
// by ref otherwise

// ! Avoid pass by pointers use pass by ref instead.

// Returning object by value is usually better than returning by value as there
// are move semantics and return value optimization is used.
// stop using ternary operator in the return statement as it disables the return
// value optimization

// Catch Exception by ref to avoid slicing

// use move semantics (your class should support move semantics)

// ! remember rule of '0'

// Avoid creating temp object (use explicit constructor when it is possible)

// for preallocating memory use vector.resize() and vector.capacity() to stop
// reallocating

// Use inline Methods and Functions
// To reduce the overhead of the function call
// ! note that inline is a recommendation for the compiler
// inline increases the footprint(the code size)

// * 2- Design level Efficiency
// choose the algorithm and data structure carefully
// Cache when necessary and use object pools