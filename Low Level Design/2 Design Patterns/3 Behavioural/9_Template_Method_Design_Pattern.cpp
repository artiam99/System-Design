#include <bits/stdc++.h>
using namespace std;

// Template Method Design Pattern is a Behavioral Design Pattern that allows us
// to defines a skeleton of an algorithm in a base class and let subclasses override the steps
// without changing the overall algorithm’s structure.

class AbstractClass
{
    public:
    void TemplateMethod() const
    {
        this->BaseOperation1();
        this->RequiredOperations1();
        this->BaseOperation2();
        this->Hook1();
        this->RequiredOperation2();
        this->BaseOperation3();
        this->Hook2();
    }

    protected:
        void BaseOperation1() const
        {
            cout << "AbstractClass says: I am doing the bulk of the work\n";
        }
        
        void BaseOperation2() const
        {
            cout << "AbstractClass says: But I let subclasses override some operations\n";
        }

        void BaseOperation3() const
        {
            cout << "AbstractClass says: But I am doing the bulk of the work anyway\n";
        }

        virtual void RequiredOperations1() const = 0;
        virtual void RequiredOperation2() const = 0;

        virtual void Hook1() const {}
        virtual void Hook2() const {}
};

class ConcreteClass1 : public AbstractClass
{
    protected:
        void RequiredOperations1() const override
        {
            cout << "ConcreteClass1 says: Implemented Operation1\n";
        }
        
        void RequiredOperation2() const override
        {
            cout << "ConcreteClass1 says: Implemented Operation2\n";
        }
};

class ConcreteClass2 : public AbstractClass
{
    protected:
        void RequiredOperations1() const override
        {
            cout << "ConcreteClass2 says: Implemented Operation1\n";
        }
        
        void RequiredOperation2() const override
        {
            cout << "ConcreteClass2 says: Implemented Operation2\n";
        }
        
        void Hook1() const override
        {
            cout << "ConcreteClass2 says: Overridden Hook1\n";
        }
};

void ClientCode(AbstractClass *class_)
{
    // ...
    class_->TemplateMethod();
    // ...
}

int main()
{
    cout << "Same client code can work with different subclasses:\n";
    
    ConcreteClass1 *concreteClass1 = new ConcreteClass1;
    
    ClientCode(concreteClass1);
    
    cout << "\n";
    
    cout << "Same client code can work with different subclasses:\n";
    
    ConcreteClass2 *concreteClass2 = new ConcreteClass2;
    
    ClientCode(concreteClass2);
    
    delete concreteClass1;
    delete concreteClass2;
    
    return 0;
}