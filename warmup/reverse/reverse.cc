#include <string>
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void printReversed(const string & line)
{
    vector<char> sizes(80);

    for(int j = 0; j < line.size();)
    {
        unsigned char firstByte = static_cast<unsigned char>(line[j]);

        if (firstByte <= 0x7F)
            sizes.push_back(1);
        else if ((firstByte & 0xE0) == 0xC0)
            sizes.push_back(2);
        else if ((firstByte & 0xF0) == 0xE0)
            sizes.push_back(3);
        else if ((firstByte & 0xF8) == 0xF0)
            sizes.push_back(4);
        j += sizes.back();
    }

    for (int i = line.size() - 1, j = sizes.size() - 1; i >= 0; --j)
    {
        cout.write(&line[i - sizes[j] + 1], sizes[j]);
        i -= sizes[j];
    }
    cout << endl;
}

int main() {

    std::ios::sync_with_stdio(false);

    int cases;
    string line;

    cin >> cases;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < cases; ++i)
    {
        getline(cin, line);
        printReversed(line);
    }
}

