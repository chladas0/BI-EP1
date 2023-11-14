#include <iostream>
#include <vector>
using namespace std;

vector<char> operatorsAndOperands;
int idx = 0;

void convert()
{
    char cur = operatorsAndOperands[idx++];
    // operand is only printed out, for operators we need to process both operands first
    if(!isdigit(cur)){ convert(); convert();}
    cout << cur << " ";
}

int main() {
    string input;
    while(getline(cin, input) && input != "0")
    {
        for(int i = 0; i < input.length(); i += 2) // skip the ws
            operatorsAndOperands.push_back(input[i]);

        convert(); cout << endl;
        idx = 0; operatorsAndOperands.clear();
    }
    return 0;
}
