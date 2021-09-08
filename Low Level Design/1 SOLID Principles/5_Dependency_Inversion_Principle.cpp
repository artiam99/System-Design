#include<bits/stdc++.h>
using namespace std;

// High Level Modules should not import anything from Low Level modules. Both should depend on abstraction (eg. Interface)

enum class Relationship
{
    parent,
    child,
    sibling
};

struct Person
{
    string name;
};

// Interface
struct RelationshipBrowser
{
    virtual vector<Person> find_all_children_of(string name) = 0;
};

struct Relationships : RelationshipBrowser // Low-Level Module .. Coz it provieds functionality for data storage
{
    vector<tuple<Person, Relationship, Person>> relations;

    void add_parent_and_child(Person& parent, Person& child)
    {
        relations.push_back({parent, Relationship::parent, child});
        relations.push_back({child, Relationship::child, parent});
    }

    vector<Person> find_all_children_of(string name) override
    {
        vector<Person> result;

        for(auto&& i : relations)
        {
            Person first = get<0>(i);
            Relationship rel = get<1>(i);
            Person second = get<2>(i);

            if(first.name == name && rel == Relationship::parent)
            {
                result.push_back(second);
            }
        }

        return result;
    }
};

struct Research // High-Level Module .. performs research on data storage

{
    Research(RelationshipBrowser& browser)
    {
        for(auto& child : browser.find_all_children_of("John"))
        {
            cout << "John has a child called " << child.name << endl;
        }
    }

    //  Research(Relationships& relationships) // depended on low level module ... in low level module is changed .. 
    //  {                                      // It may crash .. So we nee an Interface (Here .. RelationshipBrowser)
    //    auto& relations = relationships.relations;
    //    for(auto&& [first, rel, second] : relations)
    //    {
    //      if(first.name == "John" && rel == Relationship::parent)
    //      {
    //        cout << "John has a child called " << second.name << endl;
    //      }
    //    }
    //  }
};

signed main()
{
    Person parent{"John"};
    Person child1{"Chris"}, child2{"Matt"};

    Relationships relationships;
    relationships.add_parent_and_child(parent, child1);
    relationships.add_parent_and_child(parent, child2);

    Research _(relationships);

    return 0;   
}