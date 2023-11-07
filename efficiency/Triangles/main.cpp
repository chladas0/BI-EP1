#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int caseNumber = 1, n;

    while (cin >> n && n != 0)
    {
        cin.ignore();
        vector<vector<bool>> triangle(n + 2, vector<bool>(2 * n + 2, false)); // padding
        vector<vector<int>> max(n + 2, vector<int>(2 * n + 2, 0));            // padding so we can access [i+1]
        int result = 0;

        // Read the triangle pattern
        for (int i = 1; i <= n; i++)
        {
            string line;
            getline(cin, line);
            // with indexing from i we skip the leading spaces in the triangle
            // each line has length 2 * n - current row
            for (int j = i; j <= 2 * n - i; j++)
                if (line[j-1] == '-')
                    triangle[i][j] = true;
        }

        // Calculate the largest triangle area -> downward triangle
        for (int i = 1; i <= n; ++i)
            for (int j = i; j <= 2 * n - i; j += 2)
            {
                // current is #
                if (!triangle[i][j])
                    max[i][j] = 0;

                    // # is above
                else if (!triangle[i - 1][j])
                    max[i][j] = 1;
                else
                    max[i][j] = min(max[i - 1][j - 1], max[i - 1][j + 1]) + 1;

                if(max[i][j] > result)
                    result = max[i][j];
            }

        // Calculate the largest triangle area -> upward triangle
        for(int i = n - 1; i >= 0; i--)
            for(int j = i + 1; j <= 2*n - i; j+=2)
            {
                // current is #
                if(!triangle[i][j])
                    max[i][j] = 0;

                // # is above
                else if(!triangle[i+1][j])
                    max[i][j] = 1;

                else
                    max[i][j] = std::min(max[i+1][j-1], max[i+1][j+1]) + 1;

                // found a new maximum
                if(max[i][j] > result)
                    result = max[i][j];
            }
        // Print the result (as triangle is 1,3,5,7 ... add up, simplify -> r * r)
        cout << "Triangle #" << caseNumber++ << '\n' << "The largest triangle area is " << result * result << "." << "\n\n";
    }
    return 0;
}