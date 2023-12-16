#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
const double INF = 1e9;

double solve(double maxLoad, double bridgeLength, const vector<pair<double, double>> & vehicles) {
    int n = (int) vehicles.size();
    double weight = 0.0, speed = INF;

    vector<double> dp(n + 1, INF);
    dp[0] = 0.0;

    for (int i = 1; i <= n; ++i){
        for (int j = i; j > 0; --j)
        {
            weight += vehicles[j - 1].first;
            speed = min(speed, vehicles[j - 1].second);

            if (weight <= maxLoad)
                dp[i] = min(dp[i], dp[j - 1] + 60.0 * bridgeLength / speed);
            else
                break;
        }
        weight = 0.0;
        speed = INF;
    }

    return dp[n];
}

int main() {
    ios::sync_with_stdio(false);
    double maxLoad, bridgeLength;
    int n;

    while (cin >> maxLoad >> bridgeLength >> n && !(maxLoad == 0 && bridgeLength == 0 && n == 0)){
        vector<pair<double, double>> vehicles(n);
        for (int i = 0; i < n; ++i)
            cin >> vehicles[i].first >> vehicles[i].second;

        cout << fixed << setprecision(1) << solve(maxLoad, bridgeLength, vehicles) << endl;
    }
    return 0;
}
