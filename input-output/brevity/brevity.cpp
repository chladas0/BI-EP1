#include <iostream>
#include <vector>
using namespace std;


int main() {
    vector<vector<bool>> firedShots(11, vector<bool>(11, false));
    string ans;
    int destroyed = 0;

    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            if (!firedShots[i][j])
            {
                cout << (char) ('a' + i) << j << endl;
                firedShots[i][j] = true;
                getline(cin, ans);

                // we can skip surrounding points as ships can be right next to each other :)
                if (ans == "sunk")
                {
                    firedShots[i+1][j] = true;
                    firedShots[i][j+1] = true;
                    if (++destroyed == 9)
                        return 0;
                }
            }
    return 0;
}