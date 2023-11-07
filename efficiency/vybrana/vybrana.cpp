#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    std::ios::sync_with_stdio(false);

    int N, x;
    cin >> N;

    while(N--)
    {
        vector<int> bestSolution;

        while(cin >> x && x != 0)
        {
            auto it = upper_bound(bestSolution.begin(), bestSolution.end(), x);

            if(it == bestSolution.end())
                bestSolution.push_back(x);
            else
                *it = x;
        }
        std::cout << bestSolution.size() << '\n';
    }
    return 0;
}