#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main ()
{
    std::ios::sync_with_stdio(false);

    int r,s,c;
    unordered_map<char, pair<int, string>> names;

    while(cin >> r >> s >> c && r != 0)
    {
        std::cin.ignore();

        while(c--)
        {
            string name;
            cin >> name;
            names.emplace(name[0], make_pair(0, name));
        }

        std::cin.ignore();

        while(r--)
        {
            string line;
            getline(cin, line);
            for(const auto & x : line)
                if( x != '*' )
                    ++(names[x].first);
        }

        char winner;
        int currentMax = -1;
        for(const auto & x : names)
            if(x.second.first > currentMax)
            {
                winner = x.first;
                currentMax = x.second.first;
            }
        cout << "Nejzravejsi cervotoc je " << names[winner].second << ".\n";
        names.clear();
    }
    return 0;
}