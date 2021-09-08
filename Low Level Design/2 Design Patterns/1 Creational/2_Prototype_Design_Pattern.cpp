#include <bits/stdc++.h>
using namespace std;

// Prototype Design Pattern is a Creational Design Pattern that allows cloning objects,
// even complex ones, without coupling to their specific classes.

// It is used when the type of objects to create is determined by a prototypical Instance...

struct Address
{
    string street;
    string city;
    int suite;

    Address(const string& street, const string& city, const int suite) : street{street}, city{city}, suite{suite} {}

    Address(const Address& other) : street{other.street}, city{other.city}, suite{other.suite} {}
  

    friend ostream &operator<<(ostream& os, const Address& obj)
    {
        return os << "street: " << obj.street << " city: " << obj.city << " suite: " << obj.suite;
    }
};


struct Contact
{
    string name;
    Address* address;

    Contact(string name, Address* address) : name{name}, address{address} {}

    Contact(const Contact& other) : name{other.name}, address{ new Address{*other.address} } {}

    ~Contact() { delete address; }


    friend ostream& operator<<(ostream& os, const Contact& obj)
    {
        return os << "name: " << obj.name << " works at " << *obj.address;
    }
};

int main()
{
  auto addr = new Address{ "123 East Dr", "London", 0 };

  Contact john{ "John Doe", addr };
  john.address->suite = 123;

  Contact jane{john};          // Deep Copy ... This is Prototype Design Pattern
  jane.name = "Jane Smith";
  jane.address->suite = 124;

  cout << john << endl << jane << endl;

  return 0;
}

// Shallow copy problem

// struct Address
// {
//     string street;
//     string city;
//     int suite;

//     Address(const string& street, const string& city, const int suite) : street{street}, city{city}, suite{suite} {}

//     friend ostream &operator<<(ostream& os, const Address& obj)
//     {
//         return os << "street: " << obj.street << " city: " << obj.city << " suite: " << obj.suite;
//     }
// };


// struct Contact
// {
//     string name;
//     Address* address;

//     Contact(string name, Address* address) : name{name}, address{address} {}

//     friend ostream& operator<<(ostream& os, const Contact& obj)
//     {
//         return os << "name: " << obj.name << " works at " << *obj.address;
//     }
// };

// int main()
// {
//   auto addr = new Address{ "123 East Dr", "London", 0 };

//   Contact john{ "John Doe", addr };
//   john.address->suite = 123;

//   Contact jane = john;     // Shallow Copy
//   jane.name = "Jane Smith";
//   jane.address->suite = 124;

//   cout << john << endl << jane << endl;

//   // The problem is While copying jane = john and jane->address.suite = 124. john's address is also changing

//   return 0;
// }



// Prototype Factory

// struct Address
// {
//     string street;
//     string city;
//     int suite;

//     Address(const string& street, const string& city, const int suite) : street{street}, city{city}, suite{suite} {}

//     Address(const Address& other) : street{other.street}, city{other.city}, suite{other.suite} {}
  

//     friend ostream &operator<<(ostream& os, const Address& obj)
//     {
//         return os << "street: " << obj.street << " city: " << obj.city << " suite: " << obj.suite;
//     }
// };


// struct Contact
// {
//     string name;
//     Address* address;

//     Contact(string name, Address* address) : name{name}, address{address} {}

//     Contact(const Contact& other) : name{other.name}, address{ new Address{*other.address} } {}

//     ~Contact() { delete address; }


//     friend ostream& operator<<(ostream& os, const Contact& obj)
//     {
//         return os << "name: " << obj.name << " works at " << *obj.address;
//     }
// };



// struct EmployeeFactory // Employee Factory For default Prototype
// {
//     static unique_ptr<Contact> NewMainOfficeEmployee(string name, int suite)
//     {
//         static Contact p{ "", new Address{ "123 East Dr", "London", 0 } };
//         return NewEmployee(name, suite, p);
//     }

//     private:
//     static unique_ptr<Contact> NewEmployee(string name, int suite, Contact& proto)
//     {
//         auto result = make_unique<Contact>(proto);
//         result->name = name;
//         result->address->suite = suite;
//         return result;
//     }
// };



// int main()
// {
//     auto john = EmployeeFactory::NewMainOfficeEmployee("John", 123);

//     cout << *john << endl;

//     return 0;
// }