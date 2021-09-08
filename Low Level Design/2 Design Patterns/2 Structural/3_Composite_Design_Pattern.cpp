#include <bits/stdc++.h>
using namespace std;

// It composes object into tree structures to represent hierarchies

// CRTP - Curiously Recurring Template Pattern --- Neuron class and Neuron Layer class are there ... 
// A vector containg both class objects .. For conntecting the having a base Some_Neuron class and implementing a same feature
// of connection for both classes

struct GraphicObject
{
    virtual void draw() = 0;
};

struct Circle : GraphicObject
{
    void draw() override
    {
        cout << "Circle" << endl;
    }
};

struct Group : GraphicObject
{
    string name;


    explicit Group(const string& name) : name{name} {}

    void draw() override
    {
        cout << "Group " << name.c_str() << " contains:" << endl;

        int i = 1;

        for (auto&& o : objects)
        {
            cout << i++ << " : ";

            o->draw();
        }
    }

    vector<GraphicObject*> objects;
};

int main()
{
    Circle c1, c2;

    Group root("root");  root.objects.push_back(&c1);
    Group subgroup("sub");  subgroup.objects.push_back(&c2);

    root.objects.push_back(&subgroup);

    root.draw();

    //          root group
    //           /    \
    //    circle_1    sub group
    //                /
    //             circle_2

    return 0;
}

// Notes -- Array Backend Properties
 
// class Creature
// {
//     enum Abilities { str, agl, intl, count }; // array instaed of single data members .. Easy to handle
//     array<int, count> abilities;
   
//     public:
//         int get_strength() const { return abilities[str]; }
//         void set_strength(int value) { abilities[str] = value; }

//         int get_agility() const { return abilities[agl]; }
//         void set_agility(int value) { abilities[agl] = value; }

//         int get_intelligence() const { return abilities[intl]; }
//         void set_intelligence(int value) { abilities[intl] = value; }

//         int sum() const
//         {
//             return accumulate(abilities.begin(), abilities.end(), 0);
//         }

//         double average() const
//         {
//             return sum() / (double)count;
//         }

//         int max() const
//         {
//             return *max_element(abilities.begin(), abilities.end()); // max(max(max(max(,),),),) --- Ugly
//         }
// };

// int main()
// {
//     Creature orc;  orc.set_strength(16);  orc.set_agility(11);  orc.set_intelligence(9);

//     cout << "The orc has an average stat of " << orc.average() << " and a maximum stat of " << orc.max() << "\n";

//     return 0;
// }