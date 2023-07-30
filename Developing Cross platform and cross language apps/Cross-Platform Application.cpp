// * C++ programs can be compiled on many platforms, it is a platform independent
// the compiler is responsible of converting the C++ code into the processor's native assembly code format.

// ? what platform is?
// the IDE you use, The operating system, The processor that the code run on

// Note That C++ is a general purpose language 

// * Architecture Issues (refers to the preprocessor family)
// ! 1-  Size of Integers 
//      C++ standards do not define the exact size of the integer types
//      but they define a number of types that have clearly specified sizes all of them are defined in <cstdint>

#include <cstdint>  // very reommended with cross platform apps

// it has the following types
// they has exactly the size mentioned in the type name
// int8_t
// int16_t
// int32_t
// int64_t

// the fast means that the compiler should use the fastest integer type with the mentioned size
// int_fast8_t
// int_fast16_t
// int_fast32_t
// int_fast64_t

// The least means that the compiler should use the smallest integer type of the size mentioned
// int_least8_t
// int_least16_t
// int_least32_t
// int_least64_t


// An integer of max size supported by the compiler
// intmax_t


// int that is big enough to store a pointer
// intptr_t


// ! 2-  Binary compatibility
// different processors families do not support the same set of instruction
// One solutions is to compile the code with a compiler on each target platform 
// another solution is to use cross compilation (the compiler generates the binary compatible with another platform)
// open source SW is a reason to make the app cross platform as any one able to compile the code on his platform


// ! 3-  Address Sizes
// on 32 bit machines the address size is 4 bytes while it is 8 bytes on 64-bit machines 
// never assume that the pointer is 4 bytes and never case a pointer to integer except you use std::intptr_t

// ! 4-  Byte Order
// there are big-endian(most common) and little-endian
// Big endian => store the bigger part of the number first
// little endian => store the smaller part of the number first

// the ordering is important when moves data between architecture only like sending data across the network (the default through the network is big endian)

// How to get if your system is big or little endian?

// 1- using C++20 std::endian
// #include <bit>
// #include <iostream>
// int main(void){
//     switch(std::endian::native){
//         case std::endian::big:
//             std::cout << "The system is big endian ^^" << std::endl;
//             break;
//         case std::endian::little:
//             std::cout << "The system is little endian ^^" << std::endl;
//             break;
//     }
//     // The output is 
//     //  The system is little endian ^^ 
//     // Ooh my system is little endian
// }



// 2- using int casting to char pointer
// #include <iostream>
// int main(void){
//     int x {0x0001};

//     char* ptr {(char*)&x};

//     if(*ptr){
//         std::cout << "The system is little endian ^^" << std::endl;
//     }
//     else{
//         std::cout << "The system is big endian ^^" << std::endl;
//     }
// }



// There is another way using array of char then convert it to short or int depending on the number of elements on the array




// * Implementation Issues --Compilers have bugs--
// Note that variable length stack based arrays are not part of C++
// But this is part of C, some compilers support it in both C and C++

// Library implementation 
// Sometimes it is better to use 3rd party library rather than using the std one as it is optimized for speed or memory use as example
// standards do not contain the implementation not the specifications
// not all std library implementation behave the same on all the toolchains


// Platform-Specific Features
// C++ does not provide:
//  GUI
//  Networking
//  OS event and application interaction (Copy and paste operations)
//  low level files (How to get the home directory of the current user)
//  Threads (added since C++11)

// if you want a feature that is not provided by the C++ language
// it is better to find a 3rd party cross platform library then find platform-specific API (you app will be platform specific)
// it will be great if you find the the source code of the 3rd party library

