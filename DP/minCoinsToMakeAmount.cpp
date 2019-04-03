/* Filling the DP table!
 *   Coins: [1, 2, 5]
 *
 * Amount:  [0  1  2  3  4  5  6  7  8  9  10  11]
 * Values:  [0  1  1  2  2  1  2  2  3  3   2   3]   :min number of coins!
 */
#include <vector>
#include <iostream>

int minAmountOfCoinsToMakeChange(std::vector<int> coins, int amount)
{
    int arr[amount + 1];
    arr[0] = 0;     //Minimum amount of coins needed to make an amount of 0

    for (int i = 1; i <= amount; i++) {
        arr[i] = INT_MAX;
    }

    for (int i = 1; i <= amount; i++) {
        int coinindex = 0;
        while (coinindex <= coins.size()) {
            if (coins[coinindex]  <= i)  { //Only when the coin denomination is <= amount, it can contribute to making change!
                int val = i - coins[coinindex];
                arr[i] = std::min(arr[i], arr[val] + 1); //arr[val] + 1 -> + 1, because we are making use of this coin!
            }
            coinindex++;
        }
    }

    for (int i = 0; i <= amount; i++) {
        std::cout<<arr[i]<<"    ";
    }
    std::cout<<std::endl;

    if (arr[amount] == INT_MAX)
        return -1;
    else
        return arr[amount];
}

int main()
{
    std::vector<int> coins;
    coins.push_back(1);
    coins.push_back(2);
    coins.push_back(5);

    int amount = 11;

    std::cout<<minAmountOfCoinsToMakeChange(coins, amount)<<std::endl;

    std::vector<int> coins1;
    coins1.push_back(1);
    coins1.push_back(2);
    coins1.push_back(5);

    int amount1 = 5;

    std::cout<<minAmountOfCoinsToMakeChange(coins1, amount1)<<std::endl;
}
