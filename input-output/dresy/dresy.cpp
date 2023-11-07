#include <iostream>
#include <stack>
#include <sstream>
#include <limits>

using namespace std;

bool isMatching(char x, char y)
{
    return (x == '{' && y == '}') || (x == '[' && y == ']') || (x == '(' && y == ')') || (x == '<' && y == '>');
}

bool isOpening(char x)
{
    return x == '{' || x == '[' || x =='(' || x == '<';
}

bool isClosing(char x)
{
    return x == '}' || x == ']' ||  x == ')' || x == '>';
}

int main() {

    int n; char c;
    cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while(n--)
    {
        stack<char> stack; string line;
        getline(cin, line);
        istringstream iss(line);
        bool fail = false;

        while(iss >> c)
        {
            // opening bracket -----------------------------------------------------------------------------------------
            if(isOpening(c))
            {
                // special case for * check next char
                if(c == '(' && iss.peek() == '*')
                {
                    iss >> c;
                    stack.push('(');
                }
                stack.push(c);
                continue;
            }
            // closing bracket -----------------------------------------------------------------------------------------
            else if(isClosing(c))
            {
                if(stack.empty())
                {
                    fail = true;
                    break;
                }
                char s = stack.top(); stack.pop();
                if(!isMatching(s, c))
                {
                    fail = true;
                    break;
                }
            }
            // special case for * --------------------------------------------------------------------------------------
            if(c == '*' && iss.peek() == ')')
            {
                iss >> c;
                char st, l;

                if(stack.size() < 2 || (st = stack.top(), stack.pop(), l = stack.top(), stack.pop(), st != '*' || l != '('))
                {
                    fail = true;
                    break;
                }
            }
            // normal char skip
        }
        std::cout << (fail || !stack.empty() ? "V planu je chyba." : "Plan je v poradku.") << std::endl;
    }
    return 0;
}
