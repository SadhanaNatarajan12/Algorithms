//Reference: https://algorithms.tutorialhorizon.com/dynamic-programming-coin-in-a-line-game-problem/
//And EPI
//	Ci, Ci+1, Ci+2,	... Cj-2, Cj-1, Cj
/*Alice plays first, Bob plays next. Bob is also smart enough that, once Alice picks a coin, Bob will pick his coin in such a way that Alice gets the min value next!!!
 * In every move Alice has 2 options –

Either pick the ith coin (from starting)
OR pick the jth coin ( from the end).
Let’s discuss both the options

1.  Alice Picks the ith coin (from starting)
Alice collection will be:   Vi + Min(MV(i+1, j-1), MV(i+2, j))

2. Alice Picks the jth coin (ending)
Alice collection will be:   Vj + Min(MV(i+1,j-1), MV(i,j-2)) 

Alice startegy must be:

MV(i, j) = MAX ({Vi + Min(MV(i+1, j-1), MV(i+2, j))}, {Vj + Min(MV(i+1,j-1), MV(i,j-2))})
*/

#include <iostream>
#include <vector>

int pickUpCoinsDPHelper(std::vector<int> &coins,int i, int j, std::vector<std::vector<int> > &T)
{
    if (i > j) {
        return 0; //base case
    }

    T[i][j] = std::max(coins[i] + std::min(pickUpCoinsDPHelper(coins, i + 2, j, T), pickUpCoinsDPHelper(coins, i + 1, j - 1, T)),
		      (coins[j] + std::min(pickUpCoinsDPHelper(coins, i + 1, j - 1, T), pickUpCoinsDPHelper(coins, i, j - 2, T))));

    /*std::cout<<"PRINTING the values, cuurently i and j index is in top right corner !!!"<<" i = "<<i<<" , j = "<<j<<std::endl;
    for (int i = 0; i <= T.size() - 1; i++) {
	for (int j = 0; j <= T[i].size() - 1; j++) {
	    std::cout<<T[i][j]<<"   ";
	}
	std::cout<<std::endl;
    }*/
    return T[i][j];
}

int pickUpCoinsDP(std::vector<int> &coins)
{
    std::vector<std::vector<int> > T(coins.size(), std::vector<int> (coins.size(), 0));
    return pickUpCoinsDPHelper(coins, 0, coins.size() - 1, T);
}

int pickUpCoinsRecurseHelper(std::vector<int> &coins,int i, int j)
{
    if (i > j) {
	return 0;
    } else {
	return std::max(coins[i] + std::min(pickUpCoinsRecurseHelper(coins, i + 2, j), pickUpCoinsRecurseHelper(coins, i + 1, j - 1)),
			coins[j] + std::min(pickUpCoinsRecurseHelper(coins, i + 1, j - 1), pickUpCoinsRecurseHelper(coins, i, j - 2)));
    }
}

int pickUpCoinsRecursion(std::vector<int> &coins)
{
    return pickUpCoinsRecurseHelper(coins, 0, coins.size() - 1);
}

int main()
{
    std::vector<int> coins;
    coins.push_back(8);
    coins.push_back(15);
    coins.push_back(3);
    coins.push_back(7);
    

    std::vector<int> coins1;
    coins1.push_back(2);
    coins1.push_back(3);
    coins1.push_back(5);
    coins1.push_back(1);

    std::vector<int> coins2;
    coins2.push_back(4);
    coins2.push_back(7);
    coins2.push_back(3);
    coins2.push_back(2);
    coins2.push_back(9);
    coins2.push_back(6);
    
/*    std::cout<<"pickUpCoinsRecursion TEST 1"<<std::endl;
    std::cout<<pickUpCoinsRecursion(coins)<<std::endl;
    std::cout<<"pickUpCoinsRecursion TEST 2"<<std::endl;
    std::cout<<pickUpCoinsRecursion(coins1)<<std::endl;
    std::cout<<"pickUpCoinsRecursion TEST 3"<<std::endl;
    std::cout<<pickUpCoinsRecursion(coins2)<<std::endl;

    std::cout<<"pickUpCoinsDP TEST 1"<<std::endl;
    std::cout<<pickUpCoinsDP(coins)<<std::endl; */
    std::cout<<"pickUpCoinsDP TEST 2"<<std::endl;
    std::cout<<pickUpCoinsDP(coins1)<<std::endl;
/*    std::cout<<"pickUpCoinsDP TEST 3"<<std::endl;
    std::cout<<pickUpCoinsDP(coins2)<<std::endl; */
}
