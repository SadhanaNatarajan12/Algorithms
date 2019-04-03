/*Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
Each number in candidates may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

Example 2:
Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
*/
//This is a Combination sum problem, where the elements can be chosen only once. There is another variant where the numbers can be chosen more than once!!! 
#include <iostream>
#include <vector>
#include <set>

//https://www.daniweb.com/programming/software-development/threads/470864/using-std-find-with-vector-objects#

struct uniquecombination
{
    std::set<int> uniqset;
    bool operator==(const uniquecombination& rhs) {
	return this->uniqset.size() == rhs.uniqset.size() 
        && equal(this->uniqset.begin(), this->uniqset.end(), rhs.uniqset.begin());
    }
};

//bool operator==(const uniquecombination& lhs, const uniquecombination& rhs)

void UniqueCombinationSumUtil(std::vector<int> &vec, std::vector<int> &chosen, std::vector<uniquecombination> &printed, int targetSum)
{
    if (vec.empty()) {
	uniquecombination printcheck;
	if (targetSum == 0) {
	    for (int i = 0; i <= chosen.size(); i++) {
		printcheck.uniqset.insert(chosen[i]);
	    }
	    std::set<int>::iterator it;
	    if (std::find(printed.begin(), printed.end(), printcheck) == printed.end()) {
		std::set<int>::iterator tempit;
		std::cout<<"[";
		for (tempit = printcheck.uniqset.begin(); tempit != printcheck.uniqset.end(); tempit++) {
		    std::cout<<*tempit<<" ";
		}
		std::cout<<"]"<<std::endl;
	    }
	}
    } else {
	int num = vec[0];
	vec.erase(vec.begin());

	UniqueCombinationSumUtil(vec, chosen, printed, targetSum);

	chosen.push_back(num);
	UniqueCombinationSumUtil(vec, chosen, printed, targetSum - num);

	vec.insert(vec.begin(), num);
	chosen.pop_back();
    }
}

void UniqueCombinationSum(std::vector<int> &vec, int targetSum)
{
    std::vector<int> chosen;
    std::vector<uniquecombination> printed;
    UniqueCombinationSumUtil(vec, chosen, printed, targetSum);
}

void CombinationSumUtil(std::vector<int> &vec, std::vector<int> &chosen, int targetSum)
{
    if (vec.empty()) {
	if (targetSum == 0) {
	    std::cout<<"[";
	    for (int i = 0; i < chosen.size(); i++)  {
		std::cout<<chosen[i]<<" ";
	    }
	    std::cout<<"]"<<std::endl;
	}
    } else {
	int num = vec[0];
	vec.erase(vec.begin());

	CombinationSumUtil(vec, chosen, targetSum);

	chosen.push_back(num);
	CombinationSumUtil(vec, chosen, targetSum - num);

	vec.insert(vec.begin(), num);
	chosen.pop_back();
    }
}

void CombinationSum(std::vector<int> &vec, int targetSum)
{
    std::vector<int> chosen;
    CombinationSumUtil(vec, chosen, targetSum);
}

int main()
{
    std::cout<<"CombinationSum test1"<<std::endl;
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(7);
    vec.push_back(6);
    vec.push_back(1);
    vec.push_back(5);

    int targetSum = 8;
    CombinationSum(vec, targetSum);

    std::cout<<"CombinationSum test2"<<std::endl;
    std::vector<int> vec1;
    vec1.push_back(2);
    vec1.push_back(5);
    vec1.push_back(2);
    vec1.push_back(1);
    vec1.push_back(2);

    int targetSum1 = 5;
    CombinationSum(vec1, targetSum1);
}
