/*Question Based on HeapSort
8b. Find smallest range containing elements from k lists
Example:
Input:
K = 3
arr1[] : [4, 7, 9, 12, 15]
arr2[] : [0, 8, 10, 14, 20]
arr3[] : [6, 12, 16, 30, 50]
Output:
The smallest range is [6 8]
Input:
k = 3
arr1[] : [4, 7]
arr2[] : [1, 2]
arr3[] : [20, 40]
Output
The smallest range is [2 20]*/

#include <iostream>
#include <limits.h>
using namespace std; 
#define N 5 
int ptr[501]; 
void findSmallestRange(int arr[][N], int n, int k) 
{ 
	int i,minval,maxval,minrange,minel,maxel,flag,minind; 
	for(i = 0;i <= k;i++) 
		ptr[i] = 0; 
	minrange = INT_MAX; 
	while(1)	 
	{ 
		minind = -1; 
		minval = INT_MAX; 
		maxval = INT_MIN; 
		flag = 0; 
		for(i = 0;i < k;i++) 
		{	 
				
			if(ptr[i] == n) 
			{ 
				flag = 1; 
				break; 
			} 
			
			if(ptr[i] < n && arr[i][ptr[i]] < minval) 
			{ 
				minind=i; 
				minval=arr[i][ptr[i]]; 
			} 
			
			if(ptr[i] < n && arr[i][ptr[i]] > maxval)	 
			{ 
				maxval = arr[i][ptr[i]]; 
			} 
		} 
		if(flag) 
			break; 
		ptr[minind]++; 
		if((maxval-minval) < minrange) 
		{ 
			minel = minval; 
			maxel = maxval; 
			minrange = maxel - minel; 
		} 
	} 
	cout<<"The smallest range is "<<"["<<minel<<" "<<maxel<<"]"<<endl;
}	
int main() 
{ 
	int arr[][N] = { 
					{4, 7, 9, 12, 15}, 
					{0, 8, 10, 14, 20}, 
					{6, 12, 16, 30, 50} 
					}; 
	int k = 3;
	findSmallestRange(arr,N,k); 
	return 0;
} 
/*
OUTPUT
The smallest range is [6 8]
*/
