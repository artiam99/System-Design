#include<bits/stdc++.h>
using namespace std;

// Subtypes should be immediately substitutable for their basetype
// If S is subtype of T then object of T may be replaced with object of S w/o altering any desired property

class Rectangle
{
    protected:
        int width, height;
    public:
        Rectangle(int width, int height) : width(width), height(height) {}

        int getWidth()
        {
            return width;
        }
        virtual void setWidth(int width)
        {
            Rectangle::width = width;
        }

        int getHeight()
        {
            return height;
        }
        virtual void setHeight(int height)
        {
            Rectangle::height = height;
        }

        int area()
        {
            return width * height;
        }
};

class Square : public Rectangle
{
    public:
        Square(int size) : Rectangle(size, size) {}

        void setWidth(int width) override
        {
            this->width = this->height = width;
        }

        void setHeight(int height) override
        {
            this->width = this->height = height;
        }
    
};

void process(Rectangle &r)
{
    int w = r.getWidth();

    r.setHeight(10);

    cout << "Expected Area : " << w * 10 << " | We got : "<< r.area() << endl;
}

signed main()
{
    Rectangle r { 3 , 4 };

    process(r);

    Square s {5};

    process(s);

    return 0;   
}