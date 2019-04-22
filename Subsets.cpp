/*Given a set of distinct integers, nums, return all possible subsets (the power set).
Note: The solution set must not contain duplicate subsets.

Example:
Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

#include <iostream>
#include <vector>

void generate_powersetUtil(std::vector<int> &vec, std::vector<int> &chosen)
{
    if (vec.empty()) {
	std::cout<<"[";
	for (int i = 0; i < chosen.size(); i++) {
	    std::cout<<chosen[i]<<" ";
	}
	std::cout<<"]"<<std::endl;
    } else {
	int num = vec[0];
	vec.erase(vec.begin());

	generate_powersetUtil(vec, chosen);

	chosen.push_back(num);
	generate_powersetUtil(vec, chosen);

	vec.insert(vec.begin(), num);
	chosen.pop_back();
    }
}

void generate_powerset(std::vector<int> &vec)
{
    std::vector<int> chosen;
    generate_powersetUtil(vec, chosen);
}

int main()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    generate_powerset(vec);
}
