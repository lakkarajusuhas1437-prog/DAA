#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    // dp[i] = minimum coins needed to make amount i
    vector<int> dp(amount + 1, amount + 1);

    // Base case
    dp[0] = 0;

    // Calculate minimum coins for each amount
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin <= i) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    // If amount cannot be made
    if (dp[amount] > amount)
        return -1;

    return dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int result = coinChange(coins, amount);

    if (result == -1)
        cout << "Amount cannot be formed" << endl;
    else
        cout << "Minimum number of coins = " << result << endl;

    return 0;
}
