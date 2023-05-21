// #include <iostream>
// #include <any>
// #include <string>
// #include <vector>
// using namespace std;


// // any data type

// // std::any is defined in <any>
// // * it can contain a single value of any type
// // you can make the variable with any constructor or use std::make_any

// // To get the access of the value you need to use any_cast that throws an exception of "bad_any_cast" in case of failure

// // Example 1:
// int main(void){
//     any empty;
//     any anyInt{3};
//     any anyString{"Hello"s};
//     // To check if it has a value:
//     // we can use .has_value() method
//     cout << empty.has_value() << endl;
//     cout << anyInt.has_value() << endl;
//     cout << endl;
//     // to check the type that it has we can use .type().name() methods
//     cout << anyInt.type().name() << endl;
    
//     // to get the value it has you have to use any_cast

//     try{
//         int test{any_cast<int>(anyInt)};
//         cout << test << endl;
//     } catch (const bad_any_cast& ex){
//         cout << ex.what() << endl;
//     }
//     cout << endl;

//     // any can has diff types
//     any something {15};
//     something = "Ahmed"s;

//     cout << any_cast<string>(something) << endl;
//     cout << endl;

//     // you can use a vector of any but you need to know the exact type before you retrieve those elements

//     vector<any> anyVec;

//     anyVec.push_back(15);
//     anyVec.push_back("Mona"s);

//     cout << any_cast<string>(anyVec[1]) << endl;

//     return 0;
// }
// // The output is 0
// // 1

// // i
// // 3

// // Ahmed

// // Mona