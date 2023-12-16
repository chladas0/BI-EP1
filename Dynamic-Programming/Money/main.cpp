#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
using namespace std;

int INF = 1e9;

void readInput(vector<int> & arr)
{
    double value; char dot; int amount, valueAsInt;

    while (cin >> value && value != -1)
    {
        valueAsInt = (int)round(value * 100);
        cin >> amount >> dot;

        for (int i = 0; i < amount; i++)
            arr.push_back(valueAsInt);
    }
}

void solve(const std::vector<int> & arr, std::vector<int> & dp) {
    int max = accumulate(arr.begin(), arr.end(), 0);
    dp.resize(max + 1, INF); dp[0] = 0;

    for (int value : arr)
        for (int j = max - value; j >= 0; --j)
            dp[j + value] = min(dp[j + value], dp[j] + 1);
}

int main() {
    double amount;
    while (cin >> amount && amount != -1)
    {
        vector<int> customers, shopkeeper, dpCustomer, dpShopkeeper;
        int target = (int)round(amount * 100), result = INF;

        readInput(customers); readInput(shopkeeper);
        solve(customers, dpCustomer); solve(shopkeeper, dpShopkeeper);

        for (int i = target; i < dpCustomer.size(); i++)
                result = min(result, dpCustomer[i] + dpShopkeeper[i - target]);

        cout << (result != INF  ? to_string(result) +  " tenders must be exchanged.\n" : "The payment is impossible.\n");
    }
    return 0;
}
