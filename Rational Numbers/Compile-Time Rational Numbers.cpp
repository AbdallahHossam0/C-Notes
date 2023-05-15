#include <iostream>
// This file is a summery for compile-time rational numbers


// it is defined in <ratio> in the "std" namespace
#include <ratio>
using namespace std;


// the num and den of the ratio is of type => std::intmax_t which is signed

// note that: the value of the ratio is always normalized

// the rational numbers support adding, substracting, multiplying and dividing
// by ratio_add, ratio_substract, ratio_multiply and ratio_divide

// it also supports ratio comparison templates
// ratio_equal, ratio_not_equal, ratio_less, ratio_greater, ratio_less_equal, ratio_greater_equal
// and these returns a new type => std::bool_constant


int main(void){
    using r1 = ratio<1, 60>; // compile tiem only, can't be a run time values. (can be a const variable)
    intmax_t num{r1::num};
    intmax_t den{r1::den};

    cout << "r1 = " << num << " / " << den << endl;

    using r2 = ratio<1, 30>;
    cout << "r2 = " << r2::num << " / " << r2::den << endl;

    using res = ratio_add<r1, r2>;
    
    cout << "res = " << res::num << " / " << res::den << endl;
    
    using res2 = ratio_less<r2, r1>;

    cout << "res2 = " << res2::value << endl;
    // The output is as following
        // r1 = 1 / 60
        // r2 = 1 / 30
        // res = 1 / 20
        // res2 = 0
}

// note that the library provides SI type aliases =>
// yocto, zepto, atto, femto, pico, nano, micro, milli, centi, deci
// deca, hecto, kilo, mega, giga, tera, peta, exa, zetta, yotta
