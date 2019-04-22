#include <iostream>
#include <sstream>

int stringToInt(std::string &s)
{
    int result = 0;
    bool isNegative = false;
    if (s[0]=='-') {
        isNegative = true;
    }

    int i = 0;
    if (isNegative) {
        i = 1;
    }

    for (; i < s.size(); i++) {
	//std::cout<<"char: "<<s[i]<<std::endl;
        int value = s[i] - '0';
        result = result * 10 + value;
	//std::cout<<"result = "<<result<<std::endl;
    }

    if (isNegative) {
        result = result* (-1);
    }
    return result;
}

int stringToIntUsingStringStream(std::string s)
{
    std::stringstream ss;
    ss << s;
    int val;
    ss >> val; 
    return val;
}

int main(int argc, const char * argv[])
{
    std::cout<<"Negative num: "<<std::endl;
    std::string s1 ="-100332";
    std::cout<<stringToInt(s1)<<std::endl;

    std::cout<<"Positive num: "<<std::endl;
    std::string s2 ="100";
    std::cout<<stringToInt(s2)<<std::endl;

    std::string s3 = "01010101";
    std::cout<<stringToInt(s3)<<std::endl;

    std::cout<<"stringToIntUsingStringStream : "<<stringToIntUsingStringStream(s1)<<std::endl;
    std::cout<<"stringToIntUsingStringStream : "<<stringToIntUsingStringStream(s2)<<std::endl;
    std::cout<<"stringToIntUsingStringStream : "<<stringToIntUsingStringStream(s3)<<std::endl;
}
