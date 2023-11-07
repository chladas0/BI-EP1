#include <iostream>
#include <climits>
using namespace std;

enum Directions{ UP, DOWN, RIGHT, LEFT };
int min [4], max [4];

void clearArr(){
    for(int i = 0 ; i < 4; i++)
    {
        ::min[i] = INT_MAX;
        ::max[i] = INT_MIN;
    }
}

void checkEdge(int x1, int y1, int x2 ,int y2)
{
    int direction, position = x1 == x2 ? x1 : y1;

    // Up or Down edge
    if(x1 != x2)
        direction = x1 < x2 ? RIGHT : LEFT;
    // Left or Right edge
    else
        direction = y1 < y2 ? UP : DOWN;

    // update the current min and max for the direction of the edge
    ::min[direction] = std::min(::min[direction], position);
    ::max[direction] = std::max(::max[direction], position);
}

bool unreachable()
{
    // that means we found two walls (left and right) and between them there are 2 walls with
    // different orientation   like  |->     <-|   |->     <-| same for the up\down
    bool leftRightProblem = ::max[LEFT] > ::min[RIGHT] && ::max[RIGHT] > ::min[LEFT];
    bool upDownProblem =    ::max[UP]   > ::min[DOWN]  && ::max[DOWN]  > ::min[UP];

    return leftRightProblem || upDownProblem;
}

int main()
{
    int x, y, prevX, prevY, n, floor = 1, firstX, firstY;

    while(cin >> n && n != 0)
    {
        clearArr();
        cin >> prevX >> prevY;
        firstX = prevX; firstY = prevY;

        while(--n)
        {
            cin >> x >> y;
            checkEdge(prevX, prevY, x, y);
            prevX = x; prevY = y;
        }
        // edge from the last point to the first
        checkEdge(prevX, prevY, firstX, firstY);                      // crazy trick from the lecture :)
        cout << "Floor #" << floor++ << "\n" << "Surveillance is " << (unreachable() ? "im" : "") << "possible." << "\n\n";
    }
    return 0;
}