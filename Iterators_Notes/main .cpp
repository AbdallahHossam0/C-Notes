// There are 6 types of iterators:
// 1- input
// 2- output
// 3- forward
// 4- bi-directional
// 5- random access
// 6- contigouos

// it's better to use functions in <iterator> std:: namespace instead of custom container methods
// begin(), end()               normal          iterators
// cbegin(), cend()             const           iterators
// rbegin(), rend()             reverse         iterators
// crbegin(), crend()           const reverse   iterators


// reverseIterator++ means --
// reverseIterator.begin = end
// reverseIterator,end   = begin 
// remember to substract 1 ^^ if you start from the end by reverse iterator and you want to get its base by =>>> --revIt.base() {important}

// std :: distance(it1, it2) =>> used to get the distance between 2 iterators of a container


// *it =>> to access the element the iterator is pointing to ^^

// iterator traits: value_type =>> returns the element the type is referred to.




#include <iostream>
#include <iterator>
#include <vector>

using namespace std;


// Example 1

// template <typename IteratorType>
// void iteratorTraitsTest(IteratorType it){ // from this line we now know the iteratorType 
//     typename iterator_traits<IteratorType>::value_type temp;
//     // on the prev line we made variable called temp of type "typename iterator_traits<IteratorType>::value_type"
//     // we called the class template iterator traits with the type of the iterator 
//     // and access the value_type to get the type of the element the iterator is pointing to ^^
//     temp = *it;
//     cout << temp  << endl;
    
// }

// int main(void){
//     vector v {5};
//     iteratorTraitsTest(cbegin(v));
// }


// Example 2 {Great}

// #include <string>

// template <typename inputIterator, typename outputIterator>
// void myCopy(inputIterator begin, inputIterator end, outputIterator target){
//     for(auto it{begin}; it != end; it++, target++){
//         *target = *it;
//     }
// }


// // this function template is able to print any vector of any type
// template <typename inputIterator>
// void vecPrint(inputIterator begin, inputIterator end, const char* seperator = " ", const char* endCharacter = "\n"){
//     ostream_iterator<typename iterator_traits<inputIterator>::value_type> cursor {cout, seperator};
//     for(auto it{begin}; it != end; it++){
//         *cursor = *it;
//     }
//     cout << endCharacter;
// }

// int main(void){
//     vector vec {"1", "mona", "Aya", "Boda"};
//     vector<string> anotherVec(vec.size()); // note that =>> this vector is constructed with same size of vec. replace Not push_back;
//     myCopy(begin(vec), end(vec), begin(anotherVec));

//     vecPrint(begin(vec), end(vec));

//     vecPrint(begin(anotherVec), end(anotherVec), "#", "haha");

// }



// Example 3 (Continue of Example 2) Example on iterator adapter for insert iterator

// #include <string>

// template <typename inputIterator, typename outputIterator>
// void myCopy(inputIterator begin, inputIterator end, outputIterator target){
//     for(auto it{begin}; it != end; it++, target++){
//         *target = *it;
//     }
// }


// // this function template is able to print any vector of any type
// template <typename inputIterator>
// void vecPrint(inputIterator begin, inputIterator end, const char* seperator = " ", const char* endCharacter = "\n"){
//     ostream_iterator<typename iterator_traits<inputIterator>::value_type> cursor {cout, seperator};
//     for(auto it{begin}; it != end; it++){
//         *cursor = *it;
//     }
//     cout << endCharacter;
// }

// int main(void){
//     vector vec {"1", "mona", "Aya", "Boda"};
//     vector<string> anotherVec; // note that =>> this vector is Empty

//     myCopy(begin(vec), end(vec), back_inserter(anotherVec));

//     vecPrint(begin(vec), end(vec));

//     vecPrint(begin(anotherVec), end(anotherVec), "#", "haha");

// }
