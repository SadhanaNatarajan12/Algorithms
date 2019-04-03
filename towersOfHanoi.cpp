/*Towers of Hanoi*/
#include <iostream>

void towersOfHanoi(char src, char dest, char aux, int numdisks)
{
	if (numdisks <= 0)
	    return;
	towersOfHanoi(src, aux, dest, numdisks - 1);
	std::cout<<"Moving disc "<<numdisks<<" from "<<src<<" to "<<dest<<std::endl;
	towersOfHanoi(aux, dest, src, numdisks - 1);
}

int main()
{
    towersOfHanoi('A', 'B', 'C', 4);
}
