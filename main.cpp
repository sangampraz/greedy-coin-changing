#include <iostream>
#include <vector>
#include <algorithm>


/***
 * Greedy coin-changing funciton
 */
std::vector<int> coinChanging(std::vector<int> coins, int amount) {
    std::vector<int> selectedCoins;

    // sort coins in ascending order: c1 < c2 < c3 .....
    std:: sort(coins.begin(), coins.end());

    while (amount != 0) {
        int next = -1;

        // find the larges coin such that coin < amount
        for (int i = 0; i < coins.size(); i++) {
            if (coins[i] <= amount) {
                next = i;
            }
        }

        // check if no valid coin exists
        if (next == -1) {
            std::cout << "No solution found.\n";
            return {};
        }

        amount = amount - coins[next];          // subtract coin value from reamaining amount

        selectedCoins.push_back(coins[next]);  // add coin to the selected set
    }
    return selectedCoins;
}


int main() {
    std::vector<int> coins = {1, 5, 10, 25, 100};
    int amount;

    std::cout << "Enter the amount: ";
    std::cin >> amount;

    std:: vector<int> result = coinChanging(coins, amount);

    if (!result.empty()) {
        std::cout << "Coins seleted are: ";
        for (int i = 0; i < result.size(); i++) {
            std:: cout << result[i] << " ";
        }
        std:: cout << "\nTotal number of coins used: " << result.size() << std::endl;
    }
    return 0;
}