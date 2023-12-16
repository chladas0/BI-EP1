#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;

void solve(int empty, int full, const vector<pair<int, int>> & coins) {
    int weight = full - empty;

    vector<int> dp(weight + 1, INF);
    dp[0] = 0;

    // for each possible weight try all coins
    for(int i = 0; i <= weight; i++)
        for(const auto & coin : coins)
            if(i + coin.second <= weight && dp[i] != INF)
                dp[i + coin.second] = min(dp[i + coin.second], dp[i] + coin.first);

    cout << (dp[weight] == INF
    ? "This is impossible.\n"
    : "The minimum amount of money in the piggy-bank is " + to_string(dp[weight]) + ".\n");
}

int main() {
    int testCases;
    cin >> testCases;

    while(testCases--)
    {
        int Empty, Full, types;
        cin >> Empty >> Full >> types;

        vector<pair<int, int>> coins(types);

        for (int i = 0; i < types; ++i)
            cin >> coins[i].first >> coins[i].second;

        solve(Empty, Full, coins);
    }
    return 0;
}