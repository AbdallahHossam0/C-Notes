// Resource Acquisition is Initialization (RAII)
// it is used to acquire the resource on the constructor and then automatically
// free if in the destructor when it goes out of the scope "Resource Acquisition
// is Initialization" (RAII) is a programming concept in C++ where the
// acquisition of resources, such as memory or file handles, is tied to the
// initialization of an object. This means that when an object is created, it
// automatically acquires the necessary resources, and when it is destroyed, the
// resources are automatically released.

// In practice, this means that resources are managed through the use of classes
// and objects in C++. For example, when a file needs to be opened, a file
// object is created that opens the file in its constructor. When the object is
// destructed, the file is automatically closed.

// The RAII approach helps with managing resources and avoiding common
// programming errors, such as forgetting to release resources or releasing them
// in the wrong order. It ensures that resources are always properly acquired
// and released, even in the presence of exceptions or other error conditions.

// Here is an example of a file RAII class that safely wraps a C-style file
// Handle (std::file)

// * RAII usually disallow copy constructor and copy assignment

#include <cstdio>

class File final {
  private:
    std::FILE *m_file{nullptr};

  public:
    explicit File(std::FILE *file) : m_file{file} {};
    // the file is closed and freed in the destructor using the reset method
    ~File(){reset()}; // note that (the destructor is not virtual as the class
                      // is marked as final)

    // prevent copy constructor and copy assignment
    File(const File &src) = delete;
    File &operator=(const File &rhs) = delete;

    // allow move constructor and move assignment
    File(const File &&src) noexcept = default;
    File &operator=(const File &&rhs) noexcept = default;

    // this function is used to get the file the class is capturing
    std::FILE *get() const noexcept { return m_file; }

    // return the file and free the private member
    [[nodiscard]] std::FILE *release() noexcept {
        std::FILE *file{m_file};
        m_file = nullptr;
        return file;
    }

    // close the file and acquire new file
    void reset(std::FILE *file = nullptr) noexcept {
        if (m_file) {
            fclose(m_file);
        }
        m_file = file;
    }

}


// this class can be used like that
int main(void){
    File my_file{fopen("input.txt", "r")};
    // the file is now acquired and it is free as my file go out of scope
}

// ! note that
// you can accidentally write a line of code that you think is properly creating
// a RAII instance while you are creating a temp object which is immediately
// destroyed when that one line finishes

// It is a good idea to always not include default constructor in RAII instances
// ! never forget the name of the RAII instance