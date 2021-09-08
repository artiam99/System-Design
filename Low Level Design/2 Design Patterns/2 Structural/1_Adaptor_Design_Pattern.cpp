#include <bits/stdc++.h>
using namespace std;

// Adaptor Allows the interface of an existing class to be used as another interface w/o modifying their source code.

struct Point
{
  int x, y;
};

struct Line
{
  Point start, end;
};


struct LineToPointAdapter
{
    LineToPointAdapter(Line& line)
    {
        static int count = 0;
        
        cout << count++ << " : Generating points for line (no caching) " << endl;

        int left = min(line.start.x, line.end.x);
        int right = max(line.start.x, line.end.x);
        int top = min(line.start.y, line.end.y);
        int bottom = max(line.start.y, line.end.y);
        int dx = right - left;
        int dy = line.end.y - line.start.y;


        if(dx == 0)
        {
            for(int y = top ; y <= bottom ; ++y)
            points.emplace_back(Point{ left, y });
        }
        else if(dy == 0)
        {
            for(int x = left ; x <= right ; ++x)
            points.emplace_back(Point{ x, top });
        }
        else
        {
            // Somthing else
        }
    }

    vector<Point>::iterator begin() { return points.begin(); }
    vector<Point>::iterator end() { return points.end(); }
    
    private:
        vector<Point> points;
};


void Print(vector<Point>::iterator begin, vector<Point>::iterator end)
{
    // Print points

    // for(auto i = begin ; i != end ; i++)
    // PrintPoints(*i);

    // cout << endl;
}

signed main() // PrintPoints function can print points only ... we have a line .. 
{             // So LineToPointAdapter is a an interface to change line to points
    Line a;

    // Print this line

    LineToPointAdapter la(a);

    Print(la.begin() , la.end());

    return 0;
}