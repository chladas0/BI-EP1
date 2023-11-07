#include <iostream>
#include <iomanip>
using namespace std;

string input;
bool picture [512][512];
int pos = 0, n;

void decode(int x, int y, int size, int index)
{
    pos++;
    if(input[index] == 'Q')
    {
        size /= 2;
        // Recursively decode each sub quadrant
        decode(x, y, size, pos);
        decode(x + size, y, size, pos);
        decode(x, y + size, size, pos);
        decode(x + size, y + size, size, pos);
    }
    else
        // B is 1, W is 0
        for(int i = x ; i < x + size; i++)
            for(int j = y ; j < y + size ; j++)
                picture[j][i] = input[index] == 'B';
}

void printPicture()
{
    cout << "#define quadtree_width "  << n << '\n'
         << "#define quadtree_height " << n << '\n'
         << "static char quadtree_bits[] = {" << '\n';

    // numbers per one row
    int perRow = n/8;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < perRow; j++)
        {
            int decimal = 0;
            int base = 1;    // 1,2,4,8 ...

            // start from 0, 8, 16 ... and go 8 pos
            for(int k = j*8; k < j*8 + 8; k++)
            {
                if(picture[i][k])
                    decimal += base;
                base *= 2;
            }
            cout << "0x" << setw(2) << setfill('0') << hex << decimal << ",";
        }
        std::cout << endl;
    }
    cout << "};" << endl;
}

int main ()
{
    std::ios::sync_with_stdio(false);
    cin >> n >> input;
    decode(0, 0, n, 0);
    printPicture();
    return 0;
}