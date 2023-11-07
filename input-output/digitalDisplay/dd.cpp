#include <iostream>
#include <string>
#include <sstream>

using namespace std;

char shl [5] = {'+', '-', '-',  '-', '+'};
char svl [5] = {'+', '|', '|',   '+'};
char longlineh[7] = {'+', '|', '|', '+', '|', '|', '+'};
char display [7][30];
int offset = 0;

void ph(int x, int y)
{
    int end = x + 5;
    for(int j = 0; x < end; ++x, ++j)
        display[y][x + offset] = shl[j];
}

void pv(int x, int y)
{
    int end = y + 4;
    for(int j = 0; y < end; ++y, ++j)
        display[y][x+ offset] = svl[j];
}

void pvl(int x, int y)
{
    int end = y + 7;
    for(int j = 0; y < end; ++y, ++j)
        display[y][x+ offset] = longlineh[j];
}


void printDisplay()
{
    for(auto & l : display)
        std::cout << l << '\n';
    std::cout << "\n\n";
}

void displayClear()
{
    for (auto & i : display)
        for (int j = 0; j < 29; ++j)
            i[j] = ' ';
    display[2][14] = display[4][14] = 'o';
}

void writeNumber(int n)
{
    switch (n) {
        case 0:
            pvl(0, 0); pvl(4, 0); ph(0, 0); ph(0, 6);
            break;
        case 1:
            pvl(4, 0);
            break;
        case 2:
            ph(0, 0); pv(4, 0); ph(0, 3); pv(0, 3); ph(0, 6);
            break;
        case 3:
            ph(0, 0); pv(4, 0); ph(0, 3); pv(4, 3); ph(0, 6);
            break;
        case 4:
            pv(0, 0); ph(0, 3); pvl(4, 0);
            break;
        case 5:
            ph(0, 0); pv(0, 0); ph(0, 3); pv(4, 3); ph(0, 6);
            break;
        case 6:
            ph(0, 0); ph(0, 3); pv(4, 3); ph(0, 6); pvl(0, 0);
            break;
        case 7:
            ph(0, 0); pvl(4, 0);;
            break;
        case 8:
            pvl(0, 0); pvl(4, 0); ph(0, 0); ph(0, 6); ph(0, 3);
            break;
        default:
            pv(0, 0); pvl(4, 0); ph(0, 0); ph(0, 6); pv(4, 3); ph(0, 3);
            break;
    }
}


int main()
{
    for(auto & row : display)
        row[29] = '\0';

    std::string line;

    while(getline(std::cin, line))
    {
        int x, y; char indent;

        istringstream iss (line);
        if(!(iss >> x >> indent >> y))
            break;

        displayClear();
        writeNumber(x / 10); offset = 7;
        writeNumber(x % 10); offset = 17;
        writeNumber(y / 10); offset = 24;
        writeNumber(y % 10); offset = 0;
        printDisplay();
    }
    cout << "end" << endl;
    return 0;
}
