// Cross language Development

// for Text precessing, perl language is the best
// for databases, java + C# are the best
// fro modern GUIs, C# with WPF or with UNO platforms are the best

// So, you need to be able to call another language code from C++ and vice versa.


// * Mixing C and C++
// C++ is a super set of C
// all c code can run in C++ with no problems 
// There are few exceptions for example
// ! C supports variable length stack based arrays (VLAs) while C++ not and reserved words also
// For example "class" is not a reserved word in C so you can name a variable class while this is not possible in C++


// mixing C and C++ may start losing the OOP properties your programs will mix 2 paradigms (OOP and procedural programming)
// There are a common design pattern called "facade" used to make a wrapper between C(procedural code) and convert it to be OOP code



// Linking with C code (you have a compiled C code)

// There is a concept called "Name Modeling" To  implement function overloading the linker
// does not support function overloading so the compiler gives the overloads unique names to be able to match the call of the definition
// and C++ standard does not specify how function overloading should be implemented 
// In C function overloading is not supported and the compiler is simple it puts an underscore before the function name

// so to make the function able to link with C code, we should extern the deceleration of it with the language link that

extern "C" void dec1();
extern "C" void dec2();

// or 

extern "C" {
    void x (int y);
    void y (int x);
}

// or you can extern the whole .h file by

// header.hpp
extern "C" {
    #include "header.h"
}

// Note that the C++ compilers define the symbol __cplusplus
// using this feature to make able to be compiled with C and CPP

#ifdef __cplusplus
    extern "C" {
#endif
        void xx(void);
        void yy(void);

#ifdef __cplusplus
    }
#endif