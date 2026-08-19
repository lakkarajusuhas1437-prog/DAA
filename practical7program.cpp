#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, amount;

    // Number of coin denominations
    cout << "Enter number of coins: ";
    cin >> n;

    vector<int> coins(n);

    // Input coin denominations
    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // Input amount
    cout << "Enter amount: ";
    cin >> amount;

    // dp[i] = minimum number of coins required to make amount i
    vector<int> dp(amount + 1, amount + 1);

    // Base case
    dp[0] = 0;

    // Dynamic Programming
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    // Check if amount can be formed
    if (dp[amount] == amount + 1) {
        cout << "Amount cannot be formed using the given coins." << endl;
    } else {
        cout << "Minimum number of coins required = "
             << dp[amount] << endl;
    }

    return 0;
}
