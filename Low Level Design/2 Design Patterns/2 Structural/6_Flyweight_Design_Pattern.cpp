#include <bits/stdc++.h>
using namespace std;

// Flayweight design pattern provies a space optimization thechnique that lets us use less memory by storing externally the data associated with similar objects.

#include <boost/bimap.hpp>
using namespace boost;


typedef uint32_t key;

struct User
{
    User(const string& first_name, const string& last_name) : first_name{add(first_name)}, last_name{add(last_name)} {}

    const string& get_first_name() const
    {
        return names.left.find(first_name)->second; // Finding with key
    }

    const string& get_last_name() const
    {
        return names.left.find(last_name)->second; // Finding with key
    }

    protected:
        key first_name, last_name;
        static bimap<key, string> names;  // allows both side finding .. both key and values are unique .. In other words every unique string has unique key
        static int seed;

        static key add(const string& s)
        {
            auto it = names.right.find(s); // Finding with name(string)

            if(it == names.right.end())
            {
                key id = ++seed;

                names.insert({seed, s});

                return id;
            }

            return it->first;
        }
};
key User::seed{0};
bimap<key, string> User::names{};

ostream &operator<<(ostream &os, const User &user)
{
    os << "first_name: " << user.get_first_name() << " last_name: " << user.get_last_name();

    return os;
}

signed main()
{
    User user1{"John", "Smith"};
    User user2{"Jane", "Smith"};

    cout << user1 << endl << user2 << endl;

    return 0;
}

// Using boost/flyweight Library

// #include <boost/flyweight.hpp>
// #include <boost/flyweight/key_value.hpp>
// using namespace boost;
// using namespace flyweights;


// struct User2
// {
//   flyweight<string> first_name, last_name;

//   User2(const string& first_name, const string& last_name) : first_name(first_name), last_name(last_name) {}
// };

// signed main()
// {
//     User2 user1{"John", "Smith"};
//     User2 user2{"Jane", "Smith"};

//     cout << user1 << endl << user2 << endl;

//     return 0;
// }