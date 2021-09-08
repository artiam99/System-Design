#include<bits/stdc++.h>
using namespace std;

// Software entities should be open for extension but closed for modification

enum class Color { red, green, blue };
enum class Size { small, medium, large };

struct product
{
    string name;
    Color color;
    Size size;
};

class productFilter
{
    public:
        typedef vector<product*> Items;

        Items by_color(Items items, Color color)
        {
            Items result;

            for(auto& i : items)
            if(i->color == color)
            result.push_back(i);
            
            return result;
        }

        Items by_size(Items items, Size size)
        {
            Items result;
            
            for(auto& i : items)
            if(i->size == size)
            result.push_back(i);
            
            return result;
        }

        Items by_size_and_color(Items items, Size size, Color color)
        {
            Items result;
            
            for(auto& i : items)
            if(i->size == size && i->color == color)
            result.push_back(i);
            
            return result;
        }
};


// Better Product Filter

template <typename T>
class Specification
{
    public:
        virtual bool is_satisfied(T* item) = 0;
};

template <typename T>
class Filter
{
    public:
        virtual vector<T*> filter(vector<T*> items, Specification<T>& spec) = 0;
};

class betterProductFilter : public Filter<product>
{
    public:
        vector<product*> filter(vector<product*> items, Specification<product> &spec) override
        {
            vector<product*> result;
            
            for(auto& p : items)
            if(spec.is_satisfied(p))
            result.push_back(p);
            
            return result;
        }
};

class ColorSpecification : public Specification<product>
{
    public:            
        Color color;

        ColorSpecification(Color color) : color(color) {}

        bool is_satisfied(product *item) override
        {
            return item->color == color;
        }
};

class SizeSpecification : public Specification<product>
{
    public:
        Size size;

        SizeSpecification(Size size) : size(size) {}


        bool is_satisfied(product* item) override
        {
            return item->size == size;
        }
};

template <typename T>
class AndSpecification : public Specification<T>
{
    public:
        Specification<T>& first;
        Specification<T>& second;

        AndSpecification(Specification<T>& first, Specification<T>& second) : first(first), second(second) {}

        bool is_satisfied(T *item) override
        {
            return first.is_satisfied(item) && second.is_satisfied(item);
        }
};


signed main()
{
    product apple{"Apple", Color::green, Size::small};
    product tree{"Tree", Color::green, Size::large};
    product house{"House", Color::blue, Size::large};

    vector<product*> items { &apple, &tree, &house };




    cout << "Bad Filter : " << endl << endl;

    productFilter pf;

    for(auto &i : pf.by_size_and_color(items, Size::large, Color::green))
    cout << i->name << " is green and large" << endl;




    cout << endl << "Good Filter : " << endl << endl;

    betterProductFilter bpf;

    ColorSpecification green(Color::green);

    auto green_things = bpf.filter(items, green);
    
    for(auto& x : green_things)
    cout << x->name << " is green\n";



    SizeSpecification large(Size::large);

    AndSpecification<product> green_and_large(green, large);
    
    for(auto& x : bpf.filter(items, green_and_large))
    cout << x->name << " is green and large\n";

    return 0;
}