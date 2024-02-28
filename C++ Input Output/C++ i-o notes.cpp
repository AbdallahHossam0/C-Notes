// > C++ Input/Output

// * printf() and scanf()
// They don't handle the errors and they are not type safe
// Not able to handle custom types
// not OOP => They are procedural oriented

// note: printf("%d", object of class)
// note: the output will be the function address of their class blueprint if they are the same

// # C++ defined Streams to solve these problems [user-friendly and safe solution]

// Popular Streams
// 1- cout: c means console, out means out to console form the program
// 2- cin: c means console, in means in to the program and from the console

// Streams can be buffered or unbuffered

// Streams can be buffered or unbuffered.
// The difference between them is that a buffered stream does not immediately send the data to the destination.
// Instead, it buffers, that is collects, incoming data and then sends it in blocks.
// An unbuffered stream, on the other hand, immediately sends the data to the destination.
// Buffering is usually done to improve performance, as certain destinations, such as files,
// perform better when writing bigger blocks at once.

// you are able to flush the buffer using the flush member function [Method]

// Stream | Description
// ---------------------
// cin    | An input stream, reads data from the “input console”
// cout   | A *buffered* output stream, writes data to the “output console”
// cerr   | An *unbuffered* output stream, writes data to the “error console,” which is often the same as the “output console”
// clog   | A buffered version of cerr

// std::endl flushes the stream buffer, '\n does not flush the stream buffer

// There are wide-character versions of them wcin, wcout, wcerr, and wclog [for Chinese language Support]

// each stream should has a src or destination [one of them only]
// there are 3 common sources and destinations for streams: consoles, files, strings

// * in C
// for output in file: fprintf(), fwrite()
// to read file content: fputs() for output, and fscanf(), fread(), and fgets()

// * in C++
// Note: You have to avoid these function and use C++ new streams

// > Member Functions of Output Streams
// You need to include <ostream>
// the better way to use the output stream is using the << operator [stream insertion operator]
// cout.write(test, strlen(test)); //  accepts a character array
// cout.put('a'); // # for a single character

// flush(); the output stream does not necessarily write the data to its destination right away.
// so you can use it to flush the buffer of the output stream to the destination

// note: if we didn't use the flush() method when the output stream is flushed?
// endl, out of scope, buffer is full, Input is requested from a corresponding input stream

// * to check if the output stream is good and no errors it has the .good() method returns true
// * if everything is good, false otherwise
// also there is another methods to check the status of the output stream => bad(), fail(), eof()
// good() == (!fail() && !eof()).
// to reset the error state of the output stream you can use .clear() method

// > Output Manipulators

// 1- boolalpha: prints true or false instead of 1, 0
// 2- noboolalpha: stops boolalpha
// 3- hex, oct, and dec: prints the numbers in the required format
// 4- setprecision: to set the precision of the floating numbers
// 5- setw, setfill: setw, to give the responsible output a width to be printed in
// setfill, to fill with what?

// > Input with Streams

// form feed('\f') means new page
// t\The >> operator tokenize values according to whitespace

// to input the date till it finished
// while(cin >> w) { ... }
// it returns true as there are words to fill
// for that in console you can write ctrl + D in UNIX and Linux and ctrl + Z in Windows, both followed by Enter

// The good(), bad(), and fail() member functions can be called on input streams,

// when you write or read date from a stream you change it -add new date or removing the data you read-
// so, it can't be constant

// > Input Member Functions
// 1 - get(): it gets the input from the stream, usually used to avoid the automatic tokenization done by >>
// 2- unget(): it is used to return the data we got back to the stream
// 3- putback('char'): you can use to append a char to the input stream to the stream
// 4- peek(): allows you to preview the next value that would be returned if you were to call get()
// 5- getline(): it gets chars till it found '\0'

// > Input Manipulators
// 1- boolalpha: string false will be treated as the Boolean value false, anything else will be the Boolean value true.
// 2- noboolalpha: to read
// 3- dec, hex, and oct: reads the given number with which format

// > File streams [bidirectional I/O]
// the ofstream and ifstream classes provide output and input functionality for files. They are defined in <fstream>
// Working with files is error prone
// - The file may be not found, un-accessible, can't be accessed while no internet, disk is full, no permission

// open file second arg:
// CONSTANT         | DESCRIPTION
// ios_base::app    | Open, and go to the end before each write operation
// ios_base::ate    | Open, and go to the end once immediately after opening.
// ios_base::binary | Perform input and output in binary mode
// ios_base::in     | Open for input, start reading at the beginning.
// ios_base::out    | Open for output, start writing at the beginning, overwriting existing data.
// ios_base::trunc  | Option for out. Delete all existing data (truncate).

// Note that: they can be combined {{ios_base::out | ios_base::binary | ios_base::trunc}}
// To open file
// ofstream outFile{"test.txt", ios_base::trunc};
// seekg() [-get-to read form the file]
// seekp() [-put-to write in the file]

// There are 2 overloads of each one
// One overload accepts a single argument -an absolute position- and seeks to this absolute position
// The second overload: accepts an offset and a position and seeks an offset relative to the given position

// Positions are of the type {{std::streampos}}
// Offsets are of the type {{std::streamoff}}
// Both are measured in Bytes

// * There are 3 positions defined in C++
// Position     | DESCRIPTION
// ios_base::beg| The beginning of the stream
// ios_base::end| The end of the stream
// ios_base::cur| The current position in the stream

// outStream.seekp(ios_base::beg);      => Go to the begin of the stream
// outStream.seekp(2, ios_base::beg);   => Go to the second byte after the begin of the stream
// inStream.seekg(-3, ios_base::end);   => go to the third to end byte in the stream

// You can query a stream’s current location using the tellx(), it returns position of type {{std::streampos}}
// tellg() for input streams
// tellp() for output streams

// * Write the following program
// 1. Outputs the string 54321 to the file
// 2. Verifies that the marker is at position 5 in the stream
// 3. Moves to position 2 in the output stream
// 4. Outputs a 0 in position 2 and closes the output stream
// 5. Opens an input stream on the test.out file
// 6. Reads the first token as an integer
// 7. Confirms that the value is 54021

// ! Important Example

// #include <fstream>
// #include <iostream>

// using namespace std;

// int main() {
//     ofstream file_out{"Text.txt"};

//     if(!file_out) {
//         cout << "There is an error opening the file" << endl;
//         return 1;
//     }

//     file_out << "54321";

//     streampos pos{file_out.tellp()};

//     if(pos == 5) {
//         cout << "The marker is at position 5 as expected" << endl;
//     }

//     file_out.seekp(2, ios_base::beg);

//     file_out << '0';

//     file_out.close();

//     ifstream file_in{"Text.txt"};

//     if(!file_in) {
//         cout << "Error opening the file" << endl;
//     }

//     int test;
//     file_in >> test;

//     if(!file_in) {
//         cout << "Error reading from the file" << endl;
//     }

//     cout << test << endl;
//     file_in.close();

//     return 0;
// }

// > Linking Streams Together

//* A link can be established between any input and output streams to give them flush-on-access behavior
//* Stream linking is accomplished with the tie() member function
// we call tie to the input stream and pass the output stream
// you are able to break this link between them recall the tie method to the input stream and pass nullptr to it
// You also able to link between the output stream and another output stream

//* to read the content of one file in one go
// you can do that
// getline(inputFile, fileContents, '\0');
// The delimiter is '\0', this delimiter should only appear at the end of the file
// The default delimiter of the getline function is -'\n'-

// > BIDIRECTIONAL I/O

// There is a bidirectional stream
// bidirectional streams support both the >> and << operators
// example fstream ioData {filename};

// NOTE Bidirectional streams have separate pointers for the read position and the write position.
// NOTE When switching between reading and writing, you need to seek the appropriate position.

// > FILESYSTEM SUPPORT LIBRARY
// defined in <filesystem> on std::filesystem namespace
// [The following example is not working in windows but worked in Linux]
// #include <filesystem>
// #include <iostream>
// #include <string>

// namespace fs = std::filesystem;

// int main() {
//     fs::path filePath(R"(/c/tmp)");

//     std::string filePathString = filePath.string();

//     std::cout << "Original Path: " << filePath << std::endl;
//     std::cout << "Path as String: " << filePathString << std::endl;

//     return 0;
// }

#include <filesystem>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

int main() {
    fs::path myPath{"c:/windows/win.ini"};
    fs::directory_entry dirEntry{myPath};

    if(dirEntry.exists() && dirEntry.is_regular_file()) {
        std::cout << "File size: " << dirEntry.file_size() << std::endl;
    } else {
        std::cout << "File does not exist" << std::endl;
    }

    return 0;
}

// > Helper functions
// copy() to copy files or directories
// create_directory() to create a new directory on the filesystem
// exists() to query whether a given directory or file exists
// file_size() to get the size of a file
// last_write_time() to get the time the file was last modified
// remove() to delete a file
// temp_directory_path() to get a directory suitable for storing temporary files
// space() to query the available space on a filesystem
// and more
