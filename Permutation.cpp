#include <iostream>
#include <vector>

void PermuteUtil(std::vector<int> &vec, std::vector<int> &chosen)
{
    if (vec.empty()) {
	//Print chosen!
	std::cout<<"[";
	for (int i = 0; i < chosen.size(); i++) {
		std::cout<<chosen[i]<<" ";
	}
	std::cout<<"]"<<std::endl;
    } else {
	for (int i = 0; i <= vec.size() - 1; i++) {
	    int num = vec[i];
	    chosen.push_back(num);
	    vec.erase(vec.begin() + i);

	    PermuteUtil(vec, chosen);

	    chosen.pop_back();
	    vec.insert(vec.begin() + i, num);
	}
    }
}

void Permute(std::vector<int> &vec)
{
    std::vector<int> chosen;
    PermuteUtil(vec, chosen);
}

int main()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    Permute(vec);

    std::vector<int> vec1;
    vec1.push_back(1);	//1

    Permute(vec1);  //1

    std::vector<int> vec2;
    vec2.push_back(1);
    vec2.push_back(1);

    Permute(vec2);  //1, 1  1, 1
}
