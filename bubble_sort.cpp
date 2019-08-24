#include <iostream>
#include<cmath>
using namespace std;

int main()
{
	int a[10],n,k,i,j;
	clock_t start,end;
	cout<<"Enter the number of elements of elements"<<endl;
	cin>>n;
	cout<<"Enter the elements";
	for(int i =0;i<n;i++)
	cin>>a[i];
	cout<<"Enter the k'th position"<<endl;
	cin>>k;
	
	start = clock();
	
	for(i =0 ; i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
			{
				if(a[j]>a[j+1])
				{
					int temp = a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
	}
	end=clock();
	cout<<"'k' Largest elements:"<<endl;
	for(i=n-1;i>n-1-k;i--)
	cout<<a[i]<<endl;
	float exe= float(end-start)/CLOCKS_PER_SEC;
	cout<<"\n"<<exe;
	
	return 0;
}
