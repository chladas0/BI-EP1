#include <iostream>
#include <unordered_map>
#include <math.h>
#include "iomanip"
using namespace std;

struct Point
{
    double x;
    double y;

    void operator += (const Point p)
    {
        x += p.x;
        y += p.y;
    }

    Point operator * (int scalar)
    {
        return Point{x * scalar, y * scalar};
    }

    Point operator * (const Point p)
    {
        return Point{x * p.x, y * p.y};
    }
};

void printResult(const Point destination)
{
    static int map = 1;

     cout << "Map #" << map << "\n"
          << "The treasure is located at (" << std::fixed << setprecision(3) << destination.x << "," << destination.y << ")." << "\n"
          << "The distance to the treasure is " << sqrt((destination.x * destination.x + destination.y * destination.y)) << "." << "\n\n";
     ++map;
}

int main ()
{
    std::ios::sync_with_stdio(false);

    unordered_map<string, Point> directionMap = {
            {"N", {0, 1}}, {"NE", {1, 1}}, {"E", {1, 0}}, {"SE", {1, -1}},
            {"S", {0, -1}}, {"SW", {-1, -1}}, {"W", {-1, 0}}, {"NW", {-1, 1}}};

    Point current = {0, 0};
    string direction;

    int distance;
    char first, indent;

    while(cin >> distance >> first >> indent)
    {
        direction = first;

        if(indent == ',' || indent == '.')
            current += directionMap[direction] * distance;
        // There is direction containing 2 characters
        else
        {
            // in indent there is second char for direction
            direction += indent;
            cin >> indent;

            constexpr double angleRad = 45 * M_PI / 180;
            // sin 45, cos 45 to calculate the x and y move
            current += directionMap[direction] * Point{distance * sin(angleRad), distance * cos(angleRad)};
        }

        if(indent == '.')
        {
            printResult(current);
            current = {0,0};
        }
    }
    return 0;
}