/* Count the number of ways to make change from a given set of coins
 * Count the number of ways to reach a score given different scores a player can get on every move
 */

/*
 *
 *      Amt:      0   1   2   3   4   5
 * coin:     [ ]  1   0   0   0   0   0
 *           [1]  1   1   1   1   1   1
 *         [1,2]  1   1   2   2   3   3
 *       [1,2,5]  1   1   2   2   3   4     --> ANSWER!!!
*/

#include <vector>
#include <iostream>

int CountUniqueWays(std::vector<int> coins, int totalAmt)
{
    int numCoins = coins.size();
    int arr[numCoins + 1][totalAmt + 1];
    for (int i = 0; i < numCoins + 1; i++) {    //numCoins --> 0, 1, 5 ==> 3 {row "", 0, 1, 2}
        for (int j = 0; j < totalAmt + 1; j++) {        //totalAmt --> 5
            if (j == 0) {
                arr[i][j] = 1;
            } else {
                if (i == 0) {
                    arr[i][j] = 0;
                } else {
                    if (coins[i - 1] > j) {
                         int waysNotUsingCoin = arr[i - 1][j];
                         arr[i][j] = waysNotUsingCoin;      //Since a coin of higher denomination cannot be used to make change for an amount of lesser value!!!
                    } else {
                        int waysNotUsingCoin = arr[i - 1][j];
                        int coltopickcoin = j - coins[i - 1];
                        int waysUsingCoin = arr[i][coltopickcoin];
                        arr[i][j] = waysNotUsingCoin + waysUsingCoin;
                    }
                }
            }
        }
    }

    for (int i = 0; i < numCoins + 1; i++) {
        for (int j = 0; j < totalAmt + 1; j++) {
            std::cout<<arr[i][j]<<"     ";
        }
        std::cout<<std::endl;
    }

    return arr[numCoins][totalAmt];
}

int main()
{
    int totalAmt = 5;
    std::vector<int> coins;
    coins.push_back(1);
    coins.push_back(2);
    coins.push_back(5);


    std::cout<<"Counting total number of unique ways: "<<std::endl;
    int ways = CountUniqueWays(coins, totalAmt);
    std::cout<<ways<<std::endl;
//Answer here is 4:
//      1) 1, 1, 1, 1, 1
//      2) 2, 2, 1
//      3) 5
//      4) 1, 1, 1, 2

    int totalAmt1 = 12;

    std::vector<int> coins1;
    coins1.push_back(2);
    coins1.push_back(3);
    coins1.push_back(7);


    std::cout<<"Counting total number of unique ways: "<<std::endl;
    int ways1 = CountUniqueWays(coins1, totalAmt1);
    std::cout<<ways1<<std::endl;

    int totalScore = 20;
        std::vector<int> score;
    score.push_back(3);
    score.push_back(5);
    score.push_back(10);


    std::cout<<"Counting total number of unique ways to reach the total score: "<<std::endl;
    int waystoscore = CountUniqueWays(score, totalScore);
    std::cout<<waystoscore<<std::endl;


    int totalScore1 = 13;

    std::vector<int> score1;
    score1.push_back(3);
    score1.push_back(5);
    score1.push_back(10);


    std::cout<<"Counting total number of unique ways to reach the total score: "<<std::endl;
    int waystoscore1 = CountUniqueWays(score1, totalScore1);
    std::cout<<waystoscore1<<std::endl;
}
