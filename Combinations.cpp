/*Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
Example:
Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
#include <vector>
#include <iostream>

void CombinationsUtil(std::vector<int> &vec, int k, std::vector<int> chosen)
{
    if (vec.empty()) {
	if (chosen.size() == k) {
	    std::cout<<"[";
	    for (int i = 0; i < chosen.size(); i++) {
		std::cout<<chosen[i]<<" ";
	    }
	    std::cout<<"]"<<std::endl;
	}
    } else {
	int num = vec[0];
	vec.erase(vec.begin());

	CombinationsUtil(vec, k, chosen);

	chosen.push_back(num);
	CombinationsUtil(vec, k, chosen);

	vec.insert(vec.begin(), num);
	chosen.pop_back();
    }
}

void Combinations(std::vector<int> &vec, int k)
{
    std::vector<int> chosen;
    CombinationsUtil(vec, k, chosen);
}

void Combinations(int n, int k)
{
    std::vector<int> vec;
    for (int i = 1; i <= n; i++) {
	vec.push_back(i);
    }
    
    Combinations(vec, k);
}

int main()
{
    int n = 4, k = 2;
    Combinations(n, k);
}
