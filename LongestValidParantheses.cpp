/* Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:
Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"

Example 2:
Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
*/

#include <iostream>
#include <stack>

int findLengthOfLongestValidParantheses(std::string s)
{
    std::stack<int> st;
    st.push(-1);
    int result = 0;
    
    for (int i = 0; i <= s.length() - 1; i++) {
	if (s[i] == '(') {
	    st.push(i);
	} else {
	    st.pop();
	    if (st.empty()) {
		st.push(i);
	    } else {
		result = std::max(result, i - st.top());
	    }
	}
    }
    
    return result;
}

int main()
{
    std::string s("(()");
    std::cout<<findLengthOfLongestValidParantheses(s)<<std::endl;

    std::string s1(")()())");
    std::cout<<findLengthOfLongestValidParantheses(s1)<<std::endl;

    std::string s2("((()))");
    std::cout<<findLengthOfLongestValidParantheses(s2)<<std::endl;
}
