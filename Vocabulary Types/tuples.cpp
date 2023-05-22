#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <functional>
// to use typeid
#include <typeinfo>     

using namespace std;

// * std::tuples is a generalization of std::pair
// You can store any number of values each is with its own specific type
// * tuples should have a fixed size and fixed types known at the compile time

// ! you can use tuples like that
using MyTuple = tuple<int, string, bool>;
MyTuple x {15, "str"s, true}; // global tuple


// you can get the vars of tuple like that:
// int main(void){
//     cout << get<0>(x) << ", " << get<1>(x) << ", " << get<2>(x) << endl;
// or you can use the name of the type
//      cout << get<string>(x) << endl;
// if there is multiple strings an error will be pushed
// you the index or the type name
// The output is:
// 15, str, 1
// }

// you also can print the type of an element of the tuple
// int main(void){
//     cout << typeid(get<2>(x)).name() << endl;
// The output is b which means boolean
// }


// ! iterating over the elements of a tuple is not straight forward you should use templates (Meta programming)

// * How to get the size of the a tuple
// int main(void){
//     // if you know the exact type
//     cout << tuple_size<MyTuple>::value << endl;

//     // if you don't know the exact type you can use decltype
//     cout << tuple_size<decltype(x)>::value << endl;
// }

// * You can use C-TAD or FTAD while defining the tuple
// int main(void){
//     tuple t1 {16, "test"s, false}; // it will deduce the types automatically
//     // you also can use ref and cref while using CTAD "They defined in <functional>"
//     double d{3.14};
//     string str{"test"s};
//     tuple t2{16, ref(d), cref(d), ref(str)};
//     cout << "d = " << d << endl;
//     get<1>(t2) *= 2;
//     cout << "d = " << d << endl;
//     // get<2>(t2) *= 2;    // we can not use that as it ref-to-const

//     // The output is :
//     // d = 3.14
//     // d = 6.28
    
//     // We can also use FTAD as the following

//     // auto t2 { make_tuple(16, ref(d), cref(d), ref(str)) };

// }

// * Decompose Tuples
// There are 2 ways 1 - structured Binding      2 - std::tie()

// Structured Binding from C++117
// it can be either by ref or by value 

// int main(void){
//     // by value
//     tuple t1 {16, "test"s, true};
//     auto [i, str, b] {t1}; 
//     // by ref
//     auto& [i2, str2, b2] {t1};
// }


// std::tie()
// it has an advantage more than structured binding as it cab ignore certain elements
// int main(void){
//     tuple t1 {16, "test"s, true};
//     int i {};
//     string str {"Hazem"s};
//     bool b {false};
//     tie(i, str, b) = t1;
//     // To ignore the string use std::ignore
//     tie(i, ignore, b) = t1; // the string is now ignored
// }



// * Tuple Concatenation
// you can make it using std::tuple_cat()
// int main(void){
//     tuple t1{16, "test1", true};
//     tuple t2{3.14, true};
//     tuple t3 {tuple_cat(t1, t2)};
// }


// * Comparisons
// you can compare tuples using the comparisons operator 
// ! remember that: you can add all comparison operator using the spaceship overload operator only <=> if it has many data members 

// You also can use std::make_from_tuple to construct object from a tuple or array or pair ...

// * std::apply 
// it used to call a given function or function object or lambda expression and pass the given elements of the tuple as arguments
// Example

int add (int x, int y){return x + y;}
int main(void){
    cout << apply(add, tuple{5, 7}) << endl;
    return 0;
}
// * this function (std::apply) is very important while writing generic code using templates and meta-programming 

