#include <iostream>
#include <variant>
#include <string>

using namespace std;

// Variant data type


// std::variant is defined in <variant>
// can only hold a single value of set of types

// How to define a variant variable 
// Example 1 
// int main(void){
//     variant<int, bool, string> x; 

//     // data types of variant must be unique (logical)
//     // variant<int, int> y; // => this won't compile 

//     // data types of variant must have a default constructor
//     // if the default constructor is deleted so the variant can not be created

//     return 0;
// }

// Example 2

// int main(void){
//     variant<int, string, float> v;
//     v = 12;
//     v = 12.5f;
//     v = "Hello"s;
//     // note that a variant can only contain 1 value at a time

//     cout << "Type Index: " << v.index() << endl; // the output is Type Index: 1 => as string has index 1
//     cout << "is contain int? " << holds_alternative<int>(v) << endl; // the output is is contain int? 0 => as it has a string not an int

//     // you can also use get<index> or get<type> but it throws an exception if the variable is not of this type
//     // you can use use get_if<index> or get_if<type> with no exceptions it returns nullptr if the var is not of this type

//     string* stringPtr {get_if<string>(&v)};
//     int* intptr{get_if<int>(&v)};

//     cout << "string => " << (stringPtr ? *stringPtr : "NULL") << endl;
//     cout << "int => " << (intptr ? *intptr : 0) << endl;
//     // The output is 
//     //  string => Hello
//     //  int => 0


// }


// Note That : variant can not store an array and as with optional and any. also they can not store references
// It can store pointers or instances of (reference_wrapper<T> or reference_wrapper<const T>)

