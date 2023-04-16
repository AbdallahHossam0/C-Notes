// Ranges in <ranges>

// Ranges used to make sure that you don't provide a mismatch iterators
// Ranges Major Components: 
// 1-   Ranges are everything that have a begin and an end iterator
//      like arrays C-style arrays, vectors, string, span
// 2-   Range based algorithms =>> Standard library algorithms that used a pair of iterators
//      can be replaced by range based algorithms that accepting a range instead of a pair of iterators
// 3-   Projection =>> projection is so called projection call-back.
//      this callback is called for each element in the range
// 4-   Views =>> used to transform and filter the elements of the range. they also can be pipelined together.


// you can either use std library functions sort(begin(x), end(x)) or use range based algorithms like ranges::sort(x).

// Projection Example:

// as person class has not operator<
// you can use this projection to sort person by:
// ranges::sort(persons, {}, [](const Person& person){return person.getFirstName();});
// or simply =>> ranges::sort(persons, {}, &person::getFirstName)
// sort Args:
//      1- Range you want to sort
//      2- Comparator to use (by default: std::ranges::less)
//      3- The projection parameter


// Views

// you can combine different views using bitwise or operator| 
// Views add 3 important properties:
// 1-   lazily evaluated: the operation of view is only applied when you iterate over the elements.
// 2-   NonOwning: no copying or moving or destoring
// 3-   NonMutating: A view never modifies in the underlying range
// A view is a range. but, not every range is a view.


// Example 1: on ranges view

#include <iostream>
#include <ranges>
#include <vector>
#include <iterator>
using namespace std;

// this function template is able to print any vector of any type
template <typename inputIterator>
void vecPrint(inputIterator begin, inputIterator end, const char* seperator = " ", const char* endCharacter = "\n"){
    ostream_iterator<typename iterator_traits<inputIterator>::value_type> cursor {cout, seperator};
    for(auto it{begin}; it != end; it++){
        *cursor = *it;
    }
    cout << endCharacter;
}

// int main(void){
    
//     vector values{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

//     vecPrint(begin(values), end(values));

//     auto vec1 {values | views::filter([](const auto& value) {return value % 2 == 0;})};

//     vecPrint(begin(values), end(values));

//     vecPrint(begin(vec1), end(vec1));

//     auto vec2 {vec1 | views::transform([](const auto& value) {return value * 2;})};

//     vecPrint(begin(vec2), end(vec2));

//     auto vec3 {vec2 | views::drop(2)};
    
//     vecPrint(begin(vec3), end(vec3));

//     auto vec4 {vec3 | views::reverse};
    
//     vecPrint(begin(vec4), end(vec4));

//     // you can also pipeline all of that into one command

//     auto vec5 {values
//     | views::filter([](const auto& value){return value % 2 == 0;})
//     | views::transform([](const auto& value){return value * 2;})
//     | views::drop(2)
//     | views::reverse};

//     vecPrint(begin(vec5), end(vec5));
// }


// Example 2:

// modifying elements through a view:

// int main(void){
    
//     vector values{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

//     vecPrint(begin(values), end(values));

//     auto vec1 {values | views::filter([](const auto& value) {return value % 2 == 0;})};

//     vecPrint(begin(values), end(values));

//     auto vec3 {vec1 | views::drop(2)};
    
//     vecPrint(begin(vec3), end(vec3));

//     for(auto& value: vec3){
//         value *= 10;
//     }
//     vecPrint(values.begin(), values.end());
    
// }


// Example 3

// Mapping Elements
// return differnet type
// int main(void){
//     vector values{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

//     vecPrint(begin(values), end(values));

//     auto vec5 {values
//     | views::filter([](const auto& value){return value % 2 == 0;})
//     | views::transform([](const auto& value){return static_cast<double>(value) / 3;})
//     };


//     vecPrint(begin(vec5), end(vec5));
// }



// Range Factories

// used to construct views that produces elements lazily on demand
// Available range factories:
// 1-   empty_view =>> to create empty view
// 2-   single_view =>> create a view of a single element
// 3-   iota_view =>> creates an infinite or a bounded view
// 4-   (basic_istream_view) or (istream_view) =>> creates a view containing elements retrieved by the extraction operator>>

// you can use either =>> std::ranges::iota_view{} or std::ranges::views::iota()

void printRange(auto& x){
    for(auto num:x){
        cout << num << " ";
    }
}


// Range factories Examples:
// Example 1

// int main(void){
//     auto values {views::iota(10)};

//     auto res{values
//     | views::filter([](const auto& value){return value % 2 == 0;})
//     | views::transform([](const auto& value){return value * 2;})
//     | views::take(10)};

//     printRange(res);
// }


// Input streams as views =>>
// Example 1
// we read element with condition and operation done on each element

// int main(void){
//     for(auto value: ranges::istream_view<int>(cin)
//     | views::take_while([](const auto& val){return val < 5;})
//     | views::transform([](const auto& val){return val * 2;})){
//         // we can push them back on a vector as example^^
//         cout << value << endl;
//     }

//     cout << "Terminatting.......";

// }