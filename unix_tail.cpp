/* Implement the unix tail functionality!*/

#include <iostream>
#include <fstream>

void unix_tail(const std::string &filename, int linecount)
{
    std::ifstream fp;
    fp.open(filename);
    if (fp.fail()) {
	std::cout<<"Failed to read the file"<<std::endl;
	return;
    }
    fp.seekg(0, std::ios::end);

    int tellg = fp.tellg();
    std::string output;
    int numlines = 0;

    for (int i = 0; i < tellg; i++) {
	int pos = (-1-i);
	fp.seekg(pos, std::ios::end);
	char c = fp.get();
	if (c == '\n') {
	    numlines++;
	    if (numlines == linecount + 1) {
		 break;
	    }
	 }
	 output.push_back(c);
    }
    fp.close();
    reverse(output.begin(), output.end());
    std::cout<<output;
}

int main()
{
    std::string filename("tailtest");
    std::cout<<"Last 10 lines!!!"<<std::endl;
    unix_tail(filename, 10);

    std::cout<<"Last 30 lines!!!"<<std::endl;
    unix_tail(filename, 30);

    std::cout<<"Last 45 lines!!!"<<std::endl;
    unix_tail(filename, 45);
}
