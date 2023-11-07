#include <iostream>
#include <sstream>
using namespace std;


int main() {
    ios::sync_with_stdio(false);

    int N, R, S, R1, R2, S1, S2, D; string line;
    cin >> N; cin.ignore();

    while(N--)
    {
        getline(cin, line);
        istringstream firstRow (line);
        firstRow >> R >> S;

        int **matrix = new int * [R];
        for(int i = 0; i < R; ++i)
            matrix[i] = new int [S];

        // read matrix
        for(int i = 0; i < R; i++)
        {
            getline(cin, line);
            istringstream seats (line);
            for(int j = 0; j < S; ++j)
            {
                seats >> matrix[i][j];
                // right prefix sum
                if(j > 0)
                    matrix[i][j] += matrix[i][j-1];
                // down prefix sum
                if(i > 0)
                    matrix[i][j] += matrix[i -1][j];
                // overlay
                if(j > 0 && i > 0)
                    matrix[i][j] -= matrix[i-1][j-1];
            }
        }
        cin >> D; cin.ignore();

        while(D--)
        {
            getline(cin, line);
            istringstream query (line);
            query >> R1 >> S1 >> R2 >> S2;
            R1--;R2--;S1--;S2--;

            int sum = matrix[R2][S2];
            // remove upper edge
            if (R1 > 0) sum -= matrix[R1 - 1][S2];
            // remove left edge
            if (S1 > 0) sum -= matrix[R2][S1 - 1];
            // if both remove add the overlaying part
            if (R1 > 0 && S1 > 0) sum += matrix[R1 - 1][S1 - 1];
            cout << "Absolutni hodnota pohodlnosti je " << sum <<  " bodu." << '\n';
        }
        cout << endl;
    }
    return 0;
}
