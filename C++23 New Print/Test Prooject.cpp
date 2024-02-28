import std;

using namespace std;


int main()
{
	// C++23 Introduces a new print and println function to make working with printing output more easy
	// it is similar to fstring in python
	// the main difference between print and println is that println add the end-of-line char at the end of the text while print not
	int x{ 5 };
	println("Hello {}", x);
	print("Hello {}", x);
	print("Hello {}\n", x);

	// in print and println you can specify the stream class you need to use 
	println(cout, "Hello {}", x);
	println(cerr, "Hello {}", x);

	// also C++20 format is still supported you can use it as following
	// it is just used to format the text not to pass it as output
	cout << format("Hello {}", x) << endl;

	// ? cout, cin are safer that printf and scanf because
	// 1- Type Safety
	// 2- Support for user defined types
	// 3- Object-Oriented Approach

	// Remember Row Strings
	println(R"(Line 1
Line 2)");

	return 0;
}