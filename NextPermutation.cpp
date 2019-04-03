#include <iostream>
#include <vector>

void swap(std::vector<int> &input, int i, int j)
{
    int temp = input[i];
    input[i] = input[j];
    input[j] = temp;
}

void reverse(std::vector<int> &input, int start, int end)
{
    while (start < end) {
	int temp = input[start];
	input[start] = input[end]; 
	input[end] = temp;
	start++;
	end--;
    }
}

//Current Sequence: [6, 2, 1, 5, 4, 3, 0]
void find_next_permutation(std::vector<int> &input)
{
    if (input.size() == 0) {
	return;
    }

    if (input.size() == 1) {
	return;
    }

    //Find the number just before the decreasing subsequence!!!
    int numtoswap = INT_MIN;
    int firstindextoswap = -1;
    for (int num = input.size() - 1; num >= 0; num--) {
	if (input[num] > input[num - 1]) {
	    firstindextoswap = num - 1;
	    numtoswap = input[num - 1];
	    break;
	}
    }

    //Find the number to be swapped with!!!
    int numtoswapwith = INT_MIN;
    int secondindextoswap = -1;
    int mindiff = input[firstindextoswap + 1] - numtoswap;
    
    int currMinDiff = mindiff;
    for (int i = firstindextoswap + 1; i <= input.size() - 1; i++) {
	if (input[i] - numtoswap > 0) {	//We don't want to consider the case where numtoswap > input[i],here in this eg. 0, since 0 would have been taken care in backtrack
	    currMinDiff = std::min(currMinDiff, input[i] - numtoswap);
	    secondindextoswap = i;
	    numtoswapwith = input[i];
	}
    }

    swap(input, firstindextoswap, secondindextoswap);

    //reverse the elements of the vector from firstindextoswap + 1 to input.size() - 1 
    reverse(input, firstindextoswap + 1, input.size() - 1);
}

int main()
{
    //Current Sequence: [6, 2, 1, 5, 4, 3, 0]
    std::vector<int> vec;
    vec.push_back(6);
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(4);
    vec.push_back(3);
    vec.push_back(0);
 
    find_next_permutation(vec);	//[6, 2, 3, 0, 1, 4, 5]

    //Print the contents of the vector!!!
    for (int i = 0; i <= vec.size() - 1; i++) {
	std::cout<<vec[i]<<" ";
    }
    std::cout<<std::endl;

    //Current Sequence: [1, 2, 3]
    std::vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
 
    find_next_permutation(vec1);    //[1, 3, 2]

    //Print the contents of the vector!!!
    for (int i = 0; i <= vec1.size() - 1; i++) {
	std::cout<<vec1[i]<<" ";
    }
    std::cout<<std::endl;

    //Current Sequence: [1, 3, 2]
    std::vector<int> vec2;
    vec2.push_back(1);
    vec2.push_back(3);
    vec2.push_back(2);
 
    find_next_permutation(vec2);    //[2, 1, 3]

    //Print the contents of the vector!!!
    for (int i = 0; i <= vec2.size() - 1; i++) {
	std::cout<<vec2[i]<<" ";
    }
    std::cout<<std::endl;
}
