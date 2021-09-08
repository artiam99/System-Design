#include <bits/stdc++.h>
using namespace std;

// Singleton is a creational design pattern, which ensures that only one object
// of its kind exists and provides a single point of access to it for any other code.

// It is used when we have single instance available to all clients
// Eg. A single database shared by different parts of our program. It disables the class to make other objects

class SingletonDatabase // This is Naive Singleton ... There is another ... Thread-safe Singleton
{
    SingletonDatabase()
    {
        cout << "Initializing database" << endl;

        ifstream ifs("4_Singleton_Database.txt");

        string s, s2;

        while (getline(ifs, s))
        {
            getline(ifs, s2);
            int pop = stoi(s2);
            capitals[s] = pop;
        }
    }

    map<string, int> capitals;

    public:
    SingletonDatabase(SingletonDatabase const&) = delete; // delete copy Constructor ... No one can replicate
    void operator=(SingletonDatabase const&) = delete; // delete equal initialization ... No one can replicate

    static SingletonDatabase& get()
    {
        static SingletonDatabase db; // This is the Single Instance object ... Another object can not be created
        
        return db;
    }

    int get_population(const string& name)
    {
        return capitals[name];
    }
};

int main()
{
    string city = "Tokyo";

    cout << city << " has population " <<  SingletonDatabase::get().get_population("Tokyo") << endl;

}



// Monostate is a conceptual singleton. All data members of a monostate are static,
// so all instances of the monostate use the same (static) data.
// Not recomended

// class Printer
// {
//     static int id;

//     public:
//         int get_id() const { return id; }

//         void set_id(int value) { id = value; }
// };

// int Printer::id = 0;

// signed main()
// {
//     Printer p;

//     int id = p.get_id();

//     Printer p2;
// }


// Multiton Design Pattern

// enum class Importance // Limited Instances .. Here 3 ... 3 Instances of class MUltiton can be created
// {
//     primary,
//     secondary,
//     tertiary
// };

// template <typename T, typename Key = string>
// class Multiton
// {
//     public:
//         static shared_ptr<T> get(const Key& key)
//         {
//             const auto it = instances.find(key);
            
//             if(it != instances.end())
//             {
//                 return it->second;
//             }

//             auto instance = make_shared<T>();
//             instances[key] = instance;
            
//             return instance;
//         }

//     protected:
//         Multiton() = default;
//         virtual ~Multiton() = default;
        
//     private:
//         static map<Key, shared_ptr<T>> instances;
// };

// template <typename T, typename Key>
// map<Key, shared_ptr<T>> Multiton<T, Key>::instances;

// class Printer
// {
//     public:
//         Printer()
//         {
//             ++Printer::totalInstanceCount;

//             cout << "A total of " << Printer::totalInstanceCount << " instances created so far\n";
//         }

//     private:
//         static int totalInstanceCount;
// };

// int Printer::totalInstanceCount = 0;

// int main()
// {
//     typedef Multiton<Printer, Importance> mt;

//     auto main = mt::get(Importance::primary);
//     auto aux = mt::get(Importance::secondary);
//     auto aux2 = mt::get(Importance::secondary);
//     auto aux3 = mt::get(Importance::primary);
//     auto aux4 = mt::get(Importance::secondary);
//     auto aux5 = mt::get(Importance::tertiary);

// }
