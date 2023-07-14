// * Mixin Classes
// What else is this class abel to do?
// The answer is usually ends with -able (clickable as example)

// Mixin classes are a way that you can add functionality to a class without
// committing a full is a relationship

// * There are 2 option to implement mixin classes
// 1- using mutiple inheritance
// 2- using class templates

// ! Using Multiple Inheritance

class Movable {
  public:
    virtual void move() {
        // implementation of how to move an item
    }
}

class Castle; // forward declaration

class FloatingCastle : public Castle, public Movable {
    // implementation of the floating castle that is a castle and also movable
};

// ! using class templates
// this option is so called CRTP (Curiously Recurring Template Pattern)

// we design it as following

template <typename> class SelfDrivable : public T {
    // implementation of the mixin class and the type that inherit from it will
    // be self derivable
};

// if you want a car and a truck to be self derivable you can do that

class Car;
class Truck;

SelfDrivable<Car> selfDrivableCar;
SelfDrivable<Truck> selfDrivableTruck;
