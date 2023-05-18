// Random Number Facilities

// defined in <random> in the std namespace

// Random Number major components
// 1-   Engines
// 2-   Engine Adapters
// 3-   Distributions

// C-Style random number generation using rand and srand
// we usually use current time as a seed of this random generation

#include <ctime>
#include <iostream>
#include <random>

using namespace std;
// Example 1

// int main(void) {
//   srand(static_cast<unsigned int>(time(nullptr)));
// 	for(int i{}; i < 15; ++i){
// 		cout << rand() << endl;
// 	}
//   	return 0;
// }

// int getRand(int min, int max){
// 	return rand() % (max + 1UL - min) + min;
// }

// int main(void){
// 	srand(static_cast<unsigned int>(time(nullptr)));
	
// 	for(int i{}; i < 10; ++i){
// 		cout << getRand(1, 6) << "\n";
// 	}
	
// 	return 0;
// }


// ! This C style is not not flexible and has a bad quality
// * Stop using rand() and srand


// Modern C++ random Engines
// 1- random_device (HW)
// 2- linear_congruential_engine
// 3- mersenne_twister_engine(Best)
// 4- subtract_with_carry_engine

// 1- random_device
// int main(void){
// 	random_device rnd; // define the engine
// 	cout << rnd.entropy() << endl; // the output is 0 (no HW found to generate random numbers) so it will use the SW
// 	cout << rnd() << endl;

// }

// * it is always a good practice to generate the seed using random_device

// * There are 3 Engine Adapters
// 1- discard_block_engine
// 2- independent_bits_engine
// 3- shuffle_order_engine

// * There is many predefined engines and engine adapters (The most common one is mt19937)


// To generate Random Numbers

// int main(void){
// 	random_device seeder;
// 	auto seed {seeder.entropy() ? time(nullptr) : seeder()};
// 	mt19937 engine {static_cast<mt19937::result_type>(seed)};

// 	uniform_int_distribution <int> distribution(1, 6);   // uniform distribution
// 	for(int i{}; i < 50; ++i)
// 		cout << distribution(engine) << " ";
// 	cout << endl;
// 	return 0;
// }

// ! it is good to use bind
#include <functional> // for bind
#include <algorithm> // for generate
int main(void){
	random_device seeder;
	auto seed {seeder.entropy() ? time(nullptr) : seeder()};
	mt19937 engine {static_cast<mt19937::result_type>(seed)};

	uniform_int_distribution <int> distribution(1, 6);   // uniform distribution

	auto generator{bind(distribution, engine)};

	vector<int> vec(10);

	generate(begin(vec), end(vec), generator);

	for(auto num : vec){
		cout << num << " ";
	}
	cout << endl;

	return 0;
}

// * you can use function templates or abbreviated function templates or function<int()> to make a function to fill a vector and take (generator) as parameter


// There are many types of distributions
// 1- uniform => all values has repeated approximately equal times => good to roll a dice as example
// 2- normal => the values on the middle occurs more than values on the edges (normal gaussian distribution)
