// Inside library.hpp
//It is a structural design pattern that allows the programmer maintain abstraction and allows the client to extend the class Implementation.
#include <bits/stdc++.h>
using namespace std;

class Person
{
    public:
        string name;

        Person(); // These
        ~Person(); // These

        class PersonImpl; // These components do not have implementation details ... Programmer who is using Person class
        PersonImpl *impl; // can implement in his/her program.cpp file ... In this way programmer can add his/her 
                          // implementations in the class and abstraction of the class is maintained .. Secret functions are hidden
    private:
        // Secret Functions
};

// Inside program.cpp

// #include "library.hpp"

class Person::PersonImpl
{
    public:
        void greet() { cout << "Welcome !!";  }
};

Person::Person() : impl{new PersonImpl} {}

Person::~Person() { delete impl; }

signed main()
{
    // Our Program.....

    return 0;
}
