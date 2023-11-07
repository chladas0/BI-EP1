#include <iostream>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;

    while(n--)
    {
        int maxLength = 0;
        int currentLength = 0;
        int prev = -1;
        int x;
        while(cin >> x && x != 0)
        {
            if(x >= prev)
                ++currentLength;
            else
            {
                currentLength = 1;
            }
            prev = x;
            if(currentLength > maxLength)
                maxLength = currentLength;
        }
        cout << maxLength << "\n";
    }
    return 0;
}
