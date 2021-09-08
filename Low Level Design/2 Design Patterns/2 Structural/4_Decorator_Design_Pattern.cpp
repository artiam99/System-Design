#include <bits/stdc++.h>
using namespace std;

// Decorator Design Pattern is a Structural Design Pattern which allows user to add new
// functionality to an existing class. It wraps an existing class and provide aditional features.

// Dynamic Decorators are Decorators we pick at runtime ... Where we don't know which Decorator to choose at compile time

struct Shape
{
    virtual string str() const  = 0;
};

struct Circle : Shape
{
    float radius;

    Circle() {}

    Circle(float radius) : radius(radius) {}

    void resize(float factor)
    {
        radius *= factor;
    }

    string str() const override
    {
        ostringstream oss;

        oss << "A Circle of radius " << radius;

        return oss.str();
    }
};

struct Square : Shape
{
    float side;

    Square() {}

    Square(float side) : side(side) {}

    string str() const override
    {
        ostringstream oss;

        oss << "A Square with side " << side;

        return oss.str();
    }
};

struct ColoredShape : Shape
{
    Shape &shape;
    string color;

    ColoredShape(Shape &shape, const string &color) : shape(shape), color(color) {}

    string str() const override
    {
        ostringstream oss;

        oss << shape.str() << " has the color " << color;

        return oss.str();
    }
};

struct TransparentShape : Shape
{
    Shape& shape;
    uint8_t transparency;

    TransparentShape(Shape &shape, uint8_t transparency) : shape(shape), transparency(transparency) {}

    string str() const override
    {
        ostringstream oss;

        oss << shape.str() << " has " << static_cast<float>(transparency) / 255.f * 100.f << "% transparency";

        return oss.str();
    }
};

int main()
{
    Square square{5};

    ColoredShape red_square{square, "red"}; // adding red color to square. ... Dynamic Coz we don't know at compile time which shape we are going to pass.

    cout << square.str() << endl << red_square.str() << endl;


    TransparentShape my_square{red_square, 51}; // adding transparency to red square.

    cout << my_square.str() << endl;

    return 0;
}

// Static Decorators are Decorators we pick at compile-time ... Where we know which Decorator to choose at compile time

// struct Shape
// {
//     virtual string str() const  = 0;
// };

// struct Circle : Shape
// {
//     float radius;

//     Circle() {}

//     Circle(float radius) : radius(radius) {}

//     void resize(float factor)
//     {
//         radius *= factor;
//     }

//     string str() const override
//     {
//         ostringstream oss;

//         oss << "A Circle of radius " << radius;

//         return oss.str();
//     }
// };

// struct Square : Shape
// {
//     float side;

//     Square() {}

//     Square(float side) : side(side) {}

//     string str() const override
//     {
//         ostringstream oss;

//         oss << "A Square with side " << side;

//         return oss.str();
//     }
// };

// template <typename T>
// struct ColoredShape : T
// {
//     static_assert(is_base_of<Shape, T>::value, "Template argument must be a Shape.");

//     string color;

//     ColoredShape() {}

//     template <typename...Args>
//     ColoredShape(const string& color, Args ...args) : T(forward<Args>(args)...), color{ color } {}
    
//     string str() const override
//     {
//         ostringstream oss;

//         oss << T::str() << " has the color " << color;

//         return oss.str();
//     }
// };

// template <typename T>
// struct TransparentShape : T
// {
//     uint8_t transparency;

//     template <typename...Args>
//     TransparentShape(const uint8_t transparency, Args ...args) : T(forward<Args>(args)...), transparency{ transparency } {}

//     string str() const override
//     {
//         ostringstream oss;
        
//         oss << T::str() << " has " << static_cast<float>(transparency) / 255.f * 100.f << "% transparency";
        
//         return oss.str();
//     }
// };



// int main()
// {
//     ColoredShape<Circle> green_circle{"green", 10};

//     green_circle.resize(2); // This is static decorator so resize can be used.

//     cout << green_circle.str() << endl;

//     TransparentShape<ColoredShape<Square>> square{ 51, "blue", 10 };

//     cout << square.str() << endl;

//     return 0;
// }