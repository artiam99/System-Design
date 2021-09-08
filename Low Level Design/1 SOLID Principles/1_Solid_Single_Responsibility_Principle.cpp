#include<bits/stdc++.h>
using namespace std;

// A class should have a single primary responsibility and it should not take up other responsibility

// journal class handles its title and entries but saving the journal in a file is handled by other class

class journal
{
    public:
    
        string title;
        vector<string> entries;
        
        journal(string title) : title(title) {} // constructor Shortcut

        void add_entry(string s)
        {
            static int cnt = 1;

            entries.push_back(to_string(cnt++) + " : " + s);
        }
};

class persistenceManager
{
    public:
        void save(journal j , string filename)
        {
            ofstream file(filename);

            for(auto e : j.entries)
            file << e << endl;
        }
};

signed main()
{
    journal j1("My Journal");

    j1.add_entry("I read a book");
    j1.add_entry("I didn't like it");

    persistenceManager pm;

    pm.save(j1 , "1_Solid_Single_Responsibility_Principle.txt");

    return 0;
}