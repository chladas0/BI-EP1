#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <limits>

int main()
{
    std::ios::sync_with_stdio(false);
    double EPS = 1E-8;
    int n;
    while(std::cin >> n)
    {
        if(n == 0)
            break;

        double max = -1;
        int count = 0;
        while(n--)
        {
            double x1, y1, x2, y2;
            std::cin >> x1 >> y1 >> x2 >> y2;
            double resSquared = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

            if(resSquared > max + EPS)
            {
                max = resSquared;
                count = 1;
            }

            else if(fabs(max - resSquared) < EPS)
                count++;
        }
        std::cout << count << " usecek ma delku " << std::fixed << std::setprecision(2) << sqrt(max) << "." << '\n';
    }
    return 0;
}