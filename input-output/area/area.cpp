#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    int cases;
    cin >> cases; cin.ignore();

    while(cases--)
    {
        int x, y, res = 0;
        cin >> x >> y; cin.ignore();

        string line;
        getline(cin, line);
        istringstream iss(line);

        char c;
        while(iss >> c)
            switch (c)
            {
                case 'S':
                    --y;
                    break;
                case 'N':
                    ++y;
                    break;
                case 'E':
                    res += y;
                    break;
                case 'W':
                    res -= y;
                    break;
                default:
                    break;
            }
        cout << "The area is " << abs(res) << " squares." << endl;
    }
    return 0;
}
