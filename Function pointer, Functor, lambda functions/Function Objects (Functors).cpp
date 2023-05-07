#include <iostream>
#include <string>
#include <vector>
#include <span>
#include <iterator>
#include <string_view>
#include <functional>
using namespace std;

// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
// >>>>>>>>>>>>>>>> Function Object <<<<<<<<<<<<<<<<<<<<<
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// A function object or "functor" for short is any object of a class that overloads the function operator

// My first class object
class IsLarger{
    public:
        explicit IsLarger(int value) : mValue {value} {} // note the use of explicit to stop the implicit conversions
        bool operator()(int value1, int value2) const { 
            // note the function operator is marked as const (not necessary for this is example but it is a must for most of the std library algorithms)
            return value1 > mValue && value2 > mValue;
        }
    private:
    int mValue;
};

template<typename Matcher, typename MatchHandler>
void findMatches(span <const int> values1, span <const int> values2, Matcher matcher, MatchHandler handler){
    // look here how const to span is defined^^^^^^^
    if(values1.size() != values2.size()) return;

    for(size_t i{}; i < values1.size(); ++i){
        if(matcher(values1[i], values2[i])){
            handler(i, values1[i], values2[i]);
        }
    }

}

void printMatch(size_t i, int x, int y){
    cout << "Match found at position " << i << " :" << x << ", " << y << endl; 
}

// int main(void){
//     vector v1 {2, 300, 6, 9, 10, 101, 1};
//     vector v2 {4, 4, 2, 9, 0, 300, 1};
//     findMatches(v1, v2, IsLarger{100}, printMatch);

//     // The output is:
//     // Match found at position 5 :101, 300

// }


// Function object in the standard library
// many of std algorithms accept functor on its parameters as callabcks like find_if() and accmulate
// so the standard library has many built-in functors in <functional>

// Arithmatic function object (5)
// 1 - plus
// 2 - minus
// 3 - multiplies
// 4 - divides
// 5 - modulus

// // Example on how to use these functor
// plus<int> myPlus;
// int res {myPlus(4, 5)};
// cout << res << endl;


// you can use them also like that

template<typename Iter, typename startValue, typename operation>
auto accumulateDate(Iter begin, Iter end, startValue start, operation op){
    auto ac {start};
    for(Iter it {begin}; it != end; ++it){
        ac = op(ac, *it);
    }
    return ac;

}

// to use it

// int main (void){
//     vector v1 {2, 3, 6, 9, 6, 2, 1};
//     auto mult{ accumulateDate(begin(v1), end(v1), 1, multiplies<int>{}) };
//     cout << mult << endl;

// }


// or you also able to use "Transparent Operator Functors" like that
// int main (void){
//     vector v1 {2, 3, 6, 9, 6, 2, 1};
//     auto mult{ accumulateDate(begin(v1), end(v1), 1, multiplies<void>{}) }; // this or
//     // note that                                               ^^^^^^
//     auto mult{ accumulateDate(begin(v1), end(v1), 1, multiplies<>{}) }; // this 
//     // note that                                               ^^^
//     cout << mult << endl;

// }


// it is always better to use transparent operator functors
// it improves performance
// it is also good if the start value and the vector elements type are different
// it is also good when work with temporary variables


// Comparison function objects (6)

// 1 - equal_to
// 2 - not_equal_to
// 3 - less
// 4 - greater
// 5 - less_equal
// 6 - greater_equal

// remeber less in the containers => it is a comparison functor

// priority_queue <int> my_queue; // descending order

// priority_queue<int, vector<int>, greater<>> my_queue; // accsending order



// Logical function objects (3)

// 1 - logical_not
// 2 - logical_or
// 3 - logical_and

// they only deals with true or false

// // you can use that as following to makee sure that they all are true
// bool allTrue(span <const bool>& flags){
//     accumulateDate(begin(flags), end(flags), true, logical_and<>{});
// }
// // you can use that as following to makee sure that there is at least one is true
// bool allTrue(span <const bool>& flags){
//     accumulateDate(begin(flags), end(flags), false, logical_or<>{});
// }


// Bitwise function object (4)

// 1 - bit_not
// 2 - bit_or
// 3 - bit_and
// 4 - bit_xor

// Adapter function object
// it used when you want to adapt the std functors to ypur requirements

// 1- Binders in <functional>
// suppose you have this function

void func(int num, string_view s){
    cout << "nums is: " << num << " and string is: " << s << endl;
}

// int main(void){
//     string s1{"ABC"}; // suppose this string will be passed to the function every time it is called
//     // you can make a new function to use it by using bind
//     auto f1{bind(func, placeholders::_1, s1)}; // note the return type of this function should be auto (as the return type is unspecified with C++ std)
//     // note the use of placeholders::_1 that means the first parameter
//     f1(5);
//     // The output is that:
//     // nums is: 5 and string is: ABC
// }

// you can also use bind to swao the order of the parameters
// to pass a ref to non const or ref to const to bind you should use ref(var name) or cref(var name) respectively

// there is a small issue withe bin when you have overloads of the functions show the following example

void overload(int x){}
void overload(float x){}

// if you want to bind one of them use the following to avoid errors
// auto f{bind((void(*)(float)) overload, placeholders::_1)};

// each method of a class has a n implicit parameters which is this (pointer to the class)
// to use bind for methods use it as follows
// bind(&handler, placeholders::_1)

// 2 - Negator
// => not_fn => similar to binders but it's comploment the answer

// 3 -  Calling memeber functions:
// you do that with mem_fn
// mem_fn(&string::empty)
// lampda expression is better than using the mem_fn

