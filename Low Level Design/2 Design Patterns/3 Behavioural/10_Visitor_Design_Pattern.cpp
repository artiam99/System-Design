#include <bits/stdc++.h>
using namespace std;

// Visitor Design Pattern is a Behavioral Design Pattern that allows adding new
// behaviors to existing class hierarchy without altering any existing code.

// Read why Visitors can’t be simply replaced with method overloading

class ConcreteComponentA;
class ConcreteComponentB;

class Visitor
{
    public:
        virtual void VisitConcreteComponentA(const ConcreteComponentA *element) const = 0;
        virtual void VisitConcreteComponentB(const ConcreteComponentB *element) const = 0;
};

class Component
{
    public:
        virtual ~Component() {}
        virtual void Accept(Visitor *visitor) const = 0;
};

class ConcreteComponentA : public Component
{
    public:
        void Accept(Visitor *visitor) const override
        {
            visitor->VisitConcreteComponentA(this);
        }
        
        string ExclusiveMethodOfConcreteComponentA() const {
        
        return "A";
    }
};

class ConcreteComponentB : public Component
{

    public:
        void Accept(Visitor *visitor) const override
        {
            visitor->VisitConcreteComponentB(this);
        }
        
        string SpecialMethodOfConcreteComponentB() const
        {
            return "B";
        }
};

class ConcreteVisitor1 : public Visitor
{
    public:
        void VisitConcreteComponentA(const ConcreteComponentA *element) const override
        {
            cout << element->ExclusiveMethodOfConcreteComponentA() << " + ConcreteVisitor1\n";
        }

        void VisitConcreteComponentB(const ConcreteComponentB *element) const override 
        {
            cout << element->SpecialMethodOfConcreteComponentB() << " + ConcreteVisitor1\n";
        }
};

class ConcreteVisitor2 : public Visitor
{
    public:
        void VisitConcreteComponentA(const ConcreteComponentA *element) const override
        {
            cout << element->ExclusiveMethodOfConcreteComponentA() << " + ConcreteVisitor2\n";
        }
        void VisitConcreteComponentB(const ConcreteComponentB *element) const override
        {
            cout << element->SpecialMethodOfConcreteComponentB() << " + ConcreteVisitor2\n";
        }
};

void ClientCode(array<const Component *, 2> components, Visitor *visitor)
{
    // ...
    for(const Component *comp : components)
    comp->Accept(visitor);
    // ...
}

int main()
{
    array<const Component *, 2> components = {new ConcreteComponentA, new ConcreteComponentB};
    
    cout << "The client code works with all visitors via the base Visitor interface:\n";
    
    ConcreteVisitor1 *visitor1 = new ConcreteVisitor1;
    
    ClientCode(components, visitor1);
    
    cout << "\n";
    
    cout << "It allows the same client code to work with different types of visitors:\n";
    
    ConcreteVisitor2 *visitor2 = new ConcreteVisitor2;
    
    ClientCode(components, visitor2);

    for(const Component *comp : components)
    delete comp;
    
    delete visitor1;
    delete visitor2;

    return 0;
}