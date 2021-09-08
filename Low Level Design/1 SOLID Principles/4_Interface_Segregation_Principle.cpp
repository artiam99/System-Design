#include<bits/stdc++.h>
using namespace std;

// No client should be forced to depend on methods it does not use.
// Spliting interfaces that are very large into smaller and more specific ones so that clients will only have to know about the methods
// that are interest to them

struct Document;

struct IPrinter
{
    virtual void print(Document& doc) = 0;
};

struct IScanner
{
    virtual void scan(Document& doc) = 0;
};

struct Printer : IPrinter
{
    void print(Document& doc) override;
};

struct Scanner : IScanner
{
    void scan(Document& doc) override;
};

struct IMachine: IPrinter, IScanner
{

};

struct Machine : IMachine
{
    IPrinter& printer;
    IScanner& scanner;

    Machine(IPrinter& printer, IScanner& scanner) : printer{printer}, scanner{scanner} {}

    void print(Document& doc) override
    {
        printer.print(doc);
    }
    
    void scan(Document& doc) override;
};

// Instead of implementing printing and scanning for every machine separately we are implementing one common printing and scanning functions


signed main()
{

    return 0;   
}