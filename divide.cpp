#include<iostream>

int divide_using_subtract(int dividend, int divisor)
{
    int sign = 1;
    if (dividend < 0 && divisor < 0)
	sign = 1;
    else if (dividend < 0 || divisor < 0)
	sign = -1;

    int absdividend = abs(dividend);
    int absdivisor = abs(divisor);
    
    int quotient = 0;
    while (absdividend >= absdivisor) {
	absdividend = absdividend - absdivisor;
	quotient = quotient + 1;
    }
    return sign * quotient;
}

int main()
{
   int a = 10, b = 3;
   std::cout<<divide_using_subtract(a, b)<<std::endl;

   a = 43, b = -8;
   std::cout<<divide_using_subtract(a, b)<<std::endl;

   a = -10, b = -1;
   std::cout<<divide_using_subtract(a, b)<<std::endl;
}
