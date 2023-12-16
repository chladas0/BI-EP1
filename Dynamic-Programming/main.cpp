#include <iostream>
#include <vector>
using namespace std;

int dp[5010][5010];

int solve(const int * ducks, int n)
{
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            dp[i][j] = 0;

    for (int len = 2; len <= n; len++) // shooting just 1 duck would be bad round
        for (int i = 0; i <= n - len; i++){ // j is out of range we can end
            int j = i + len - 1;
            dp[i][j] = (ducks[i] == ducks[j])
                    // Shot ducks at sides + best from inner
                    ? 1 + dp[i+1][j-1]
                    // Try shooting left and rest, right and rest, take maximum
                    : max(dp[i+1][j], dp[i][j-1]);
        }
    return dp[0][n-1];
}

int main() {
    ios::sync_with_stdio(false);
    int N, ducks [5000];

    while(cin >> N){
        for(int i = 0; i < N; i++)
            cin >> ducks[i];
        cout << solve(ducks, N) << endl;
    }
    return 0;
}
