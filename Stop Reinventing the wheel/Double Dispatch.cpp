// * double dispatch is a technique that adds an extra dimension of polymorphism

// Sometimes you need a method that behave on according to rub-type of 2 or more
// object

// C++ does not provide such mechanism, Other OOP languages support this feature
// and is called (multi methods)

// * you can implement such a feature using double dispatch technique

// ! double dispatch is a special case of multiple dispatch

// * Attempt 1 (Brute Force)
// it is a simple if else

// Example
// #include <typeinfo>
// // this class is an abstract class
// class Animal {
//   public:
//     virtual bool eats(const Animal &prey) const = 0;
//     // this function is pure virtual function
// };

// class Bear : public Animal {
//     bool eats(const Animal &prey) const override {
//         if (typeid(prey) == typeid(Bear)) {
//             return false;
//         } else if (typeid(prey) == typeid(Fish)) {
//             return true;
//         } else if (typeid(prey) == typeid(TRex)) {
//             return false;
//         }
//         return false;
//     }
// };

// class Fish : public Animal {
//     bool eats(const Animal &prey) const override {
//         if (typeid(prey) == typeid(Bear)) {
//             return false;
//         } else if (typeid(prey) == typeid(Fish)) {
//             return true;
//         } else if (typeid(prey) == typeid(TRex)) {
//             return false;
//         }
//         return false;
//     }
// };

// class TRex : public Animal {
//     // TRex is eating every thing ^^
//     bool eats(const Animal &prey) const override { return true; }
// };

// Brute force is straight forward technique and suitable for a small number of
// classes you should avoid using that because 1- not compatible with OOP 2-
// code becomes messy and repetitive 3- not able to add new types

// * 2- Single Polymorphism with Overloading

// * 3- Double Dispatch
// it is the most truly polymorphic solution

// this class is an abstract class
class Animal {
  public:
    // these functions are pure virtual functions
    // the first polymorphism is done in the deceleration and the second one is
    // on the defintion
    virtual bool eats(const Animal &prey) const = 0;

    virtual bool eaten_By(const Bear &) const = 0;
    virtual bool eaten_By(const Fish &) const = 0;
    virtual bool eaten_By(const TRex &) const = 0;
};

class Bear : public Animal {
  public:
    bool eats(const Animal &prey) const override {
        return prey.eaten_By(*this);
    }

    bool eaten_By(const Bear &) const override { return false; }
    bool eaten_By(const Fish &) const override { return false; }
    bool eaten_By(const TRex &) const override { return true; }
};

class Fish : public Animal {
  public:
    bool eats(const Animal &prey) const override {
        return prey.eaten_By(*this);
    }

    bool eaten_By(const Bear &) const override { return true; }
    bool eaten_By(const Fish &) const override { return true; }
    bool eaten_By(const TRex &) const override { return true; }
};

class TRex : public Animal {
  public:
    bool eats(const Animal &prey) const override {
        return prey.eaten_By(*this);
    }

    bool eaten_By(const Bear &) const override { return false; }
    bool eaten_By(const Fish &) const override { return false; }
    bool eaten_By(const TRex &) const override { return true; }
};