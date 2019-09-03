/*Write a program to sort the elements in ascending order using Merge Sort*/

#include <iostream>
#include <time.h>
using namespace std;
void mergesort(int[],int,int);
void merge(int[],int,int,int);
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
	mergesort(a,0,n-1);
	end=clock();
	cout<<"Sorted elements are: ";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	time=(double)(end-start)/CLOCKS_PER_SEC;
	cout<<"\nTime complexity is: "<<time<<"secs\n";
}

void mergesort(int a[],int low,int high)
{
	int mid;
	if(low>=high)
		return;
	mid=(low+high)/2;
	mergesort(a,low,mid);
	mergesort(a,mid+1,high);
	merge(a,low,mid,high);
}

void merge(int a[],int low,int mid,int high)
{
	int i,j,k,b[10];
	i=low;
	j=mid+1;
	k=low;
	while(i<=mid && j<=high)
	{
		if(a[i]<=a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	}
	while(i<=mid)
		b[k++]=a[i++];
	while(j<=high)
		b[k++]=a[j++];
	for(k=low;k<=high;k++)
		a[k]=b[k];
}
