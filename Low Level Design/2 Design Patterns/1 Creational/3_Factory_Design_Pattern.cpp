#include<bits/stdc++.h>
using namespace std;

// Factory Design Pattern is a Creational Design Pattern which solves the problem
// of creating product objects without specifying their concrete classes.

// It uses factory methods to deal with the problem of creating objects
// w/o having to specify the exact class of the object that will be created

enum class PointType
{
    cartesian,
    polar
};

class Point
{
    public:
        Point(const float x, const float y) : x{x}, y{y} {}

        public:
        float x, y;


        friend std::ostream& operator<<(std::ostream& os, const Point& obj)
        {
            return os << "x: " << obj.x << " y: " << obj.y;
        }
};

class PointFactory
{
    public:
        static Point NewCartesian(float x, float y)
        {
            return Point{ x,y };
        }

        static Point NewPolar(float r, float theta)
        {
            return Point{ r * cos(theta), r * sin(theta) };
        }
};

int main()
{
    auto p = PointFactory::NewPolar(5, M_PI_4); // Easily understandable for client

    std::cout << p << std::endl;

    return 0;
}


// Inner Factory

// enum class PointType
// {
//     cartesian,
//     polar
// };

// class Point
// {
//     float x, y;

//     Point(float x, float y) : x(x), y(y) {}

//     class PointFactory // Private members are available to Inner Factory
//     {
//         PointFactory() {}

//         public:
//             static Point NewCartesian(float x, float y)
//             {
//                 return { x, y };
//             }

//             static Point NewPolar(float r, float theta)
//             {
//                 return{ r * cos(theta), r * sin(theta) };
//             }
//     };

//     public:
//         static PointFactory Factory;

//         friend std::ostream& operator<<(std::ostream& os, const Point& obj)
//         {
//             return os << "x: " << obj.x << " y: " << obj.y;
//         }
// };

// int main()
// {
//     auto pp = Point::Factory.NewCartesian(2, 3);

//     std::cout << pp << std::endl;

//     return 0;
// }