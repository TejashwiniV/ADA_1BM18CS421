#include <iostream>
#include <time.h>
using namespace std;
void quick(int[],int,int);
int partition(int[],int,int);
int main()
{
	int a[10],n,i;
	double time;
	clock_t start,end;
	cout<<"Enter the size of an array: ";
	cin>>n;
	cout<<"Enter the elements of an array: ";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	start=clock();
	quick(a,0,n-1);
	end=clock();
	cout<<"Sorted elements are:";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	time=(double)(end-start)/CLOCKS_PER_SEC;
	cout<<"\nTime complexity is: "<<time<<"secs\n";
}
void quick(int a[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=partition(a,low,high);
		quick(a,low,mid-1);
		quick(a,mid+1,high);
	}
}
int partition(int a[],int low,int high)
{
	int pivot,i,j,temp;
	pivot=a[low];
	i=low;
	j=high;
	while(i<=j)
	{
		while(a[i]<=pivot)
			i++;
		while(a[j]>pivot)
			j--;
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		temp=a[low];
		a[low]=a[j];
		a[j]=temp;
	return j;
	}
}
