#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int step, segments, cases;
    double curSegment;
    cin >> cases;

    while(cases--){
        cin >> step >> segments;
        double rest = 0.0; int count = 0;
        while(segments--){
            cin >> curSegment;
            curSegment -= sqrt(step * step - rest * rest); // the part we skipped using prev step
            int stepCount = floor(curSegment / step);
            count += stepCount + 1;
            rest = curSegment - stepCount * step;
        }
        cout << "Strazny ujde " << (rest * 2 >= step ? count + 1 : count) << " ponorku." << '\n';
    }
}
