#include <iostream>
#include <time.h>
using namespace std;
int sqrt_of_num(int num)
{
	int result;
	int start = 1;
	int end = num/2;
	if (num <= 2)
		return num;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		long sqr = mid*mid;
		if (sqr == num)
			return mid;
		else if (sqr < num)
		{
			start = mid + 1;
			result = mid;
		}
		else
		{
			end = mid - 1;
		}
	}
	return result;
}

int main()
{
	int num;
	int temp=0;
	double time;
	clock_t start,end;
	start=clock();
	cout << "Enter the number to find the square root:";
	cin >> num;
	temp=sqrt_of_num(num);
	cout << "Square root of a given number "<< num << " is:" << temp << endl;
	end=clock();
	time=(double)(end-start)/CLOCKS_PER_SEC;
	cout << "Time complexity is:" << time <<"secs"<<endl;
	return 0;
}
