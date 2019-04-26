/* Check if a given string can be broken into valid substrings, such that, each substring is in the dictionary! */
#include <iostream>
#include <unordered_set>
#include <unordered_map>

bool stringbreak(std::string s, std::unordered_set<std::string> &dictionary)
{
    if (dictionary.find(s) != dictionary.end()) {   //check if the entire string can be found in the dictionary!
	return true;
    }

    if (s.empty()) {
	return true;
    }

    for (int pos = 1; pos <= s.length() - 1; pos++) {
	if (dictionary.find(s.substr(0, pos)) == dictionary.end()) {
	    continue;
	}
	std::string rem = s.substr(pos);
	if (stringbreak(rem, dictionary)) {
	    return true;
	}
    }
    return false;
}

bool stringbreakWithMemoHelper(std::string s, std::unordered_set<std::string> &dictionary, std::unordered_map<std::string, bool> &memo)
{
    if (memo.find(s) != memo.end()) {
	return true;
    }

    if (dictionary.find(s) != dictionary.end()) {
	memo[s] = true;
	return true;
    }

    if (s.empty())
	return true;

    for (int pos = 1; pos <= s.size() - 1; pos++) {
	if (dictionary.find(s.substr(0, pos)) == dictionary.end()) {
	    continue;
	}
	std::string remaining = s.substr(pos);
	if (stringbreakWithMemoHelper(remaining, dictionary, memo) == true) {
	    memo[s] = true;
	    return true;
	}
    }
    return false;
}

bool stringbreakWithMemo(std::string s, std::unordered_set<std::string> &dictionary)
{
    std::unordered_map<std::string, bool> memo;
    return stringbreakWithMemoHelper(s, dictionary, memo);
}

int main()
{
    std::unordered_set<std::string> dictionary;
    dictionary.insert("i");
    dictionary.insert("like");
    dictionary.insert("water");
    dictionary.insert("melon");
    dictionary.insert("watermelon");

    std::string s("ilikewatermelon");
    std::cout<<stringbreak(s, dictionary)<<std::endl;

    std::string s1("idontlikewatermelon");
    std::cout<<stringbreak(s1, dictionary)<<std::endl;

    std::cout<<stringbreakWithMemo(s, dictionary)<<std::endl;
    std::cout<<stringbreakWithMemo(s1, dictionary)<<std::endl;

    std::cout<<stringbreakWithMemo("", dictionary)<<std::endl;
}
