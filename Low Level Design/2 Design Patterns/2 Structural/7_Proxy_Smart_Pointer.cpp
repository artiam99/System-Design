#include <bits/stdc++.h>
using namespace std;

// Proxy Design Pattern , in most general form, is a class functioning as an interface to something else.

// It lets us provide a substitute or placeholder for another object.
// A proxy controls access to the original object, allowing you to perform something
// either before or after the request gets through to the original object

// Whenever we need filtering in our system .. like only admins can delete user .. We use proxy


class Subject
{
    public:
        virtual void Request() const = 0;
};

class RealSubject : public Subject
{
    public:
    void Request() const override
    {
        cout << "RealSubject: Handling request.\n";
    }
};

class Proxy : public Subject
{
    private:
        RealSubject *real_subject_;

        bool CheckAccess() const
        {
            cout << "Proxy: Checking access prior to firing a real request.\n";
            
            return true;
        }

        void LogAccess() const
        {
            cout << "Proxy: Logging the time of request.\n";
        }

    public:
        Proxy(RealSubject *real_subject) : real_subject_(new RealSubject(*real_subject)) {}

        ~Proxy()
        {
            delete real_subject_;
        }

        void Request() const override
        {
            if(this->CheckAccess()) // filtering is happening here ... Like ... if admin then delete user 
            {
                this->real_subject_->Request();
                this->LogAccess();
            }
        }
};

void ClientCode(const Subject &subject)
{
  // ...
  subject.Request();
  // ...
}

int main()
{
    cout << "Client: Executing the client code with a real subject:\n";

    RealSubject *real_subject = new RealSubject;

    ClientCode(*real_subject);

    cout << "\n";
    cout << "Client: Executing the same client code with a proxy:\n";
    
    Proxy *proxy = new Proxy(real_subject);
    
    ClientCode(*proxy);

    delete real_subject;
    delete proxy;
    
    return 0;
}