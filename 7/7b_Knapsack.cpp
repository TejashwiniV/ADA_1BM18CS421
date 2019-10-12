/*Program under Dynamic Programming:
7b. Solve the 0-1 Knapsack Problem*/

#include<iostream>
using namespace std;
void knapsack();
int max(int,int);
int i,j,n,m,p[10],w[10],v[10][10];
int main()
{
	cout<<"Enter the number of items: ";
	cin>>n;
	cout<<"Enter the weight of each item: ";
	for(i=1;i<=n;i++)
	{
		cin>>w[i];
	}
	cout<<"Enter the profit of each item: ";
	for(i=1;i<=n;i++)
	{
		cin>>p[i];
	}
	cout<<"Enter the knapsack capacity: ";
	cin>>m;
	knapsack();
}
void knapsack()
{
	int x[10];
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(i==0 || j==0)
			{
				v[i][j]=0;
			}
			else if(j-w[i] < 0)
			{
				v[i][j]=v[i-1][j];
			}
			else
			{
				v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
			}
		}
	}
	cout<<"The output is: \n";
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			cout<<"\t"<<v[i][j];
		}
		cout<<"\n";
	}
	cout<<"The optimal solution is: "<<v[n][m];
	cout<<"\nThe solution vector is: ";
	for(i=n;i>=1;i--)
	{
		if(v[i][m]!=v[i-1][m])
		{
			x[i]=1;
			m=m-w[i];
		}
		else
		{
			x[i]=0;
		}
	}
	for(i=1;i<=n;i++)
	{
		cout<<" "<<x[i];
	}
	cout<<"\n";
}
int max(int x,int y)
{
	if(x>y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

/*
OUTPUT
Enter the number of items: 5
Enter the weight of each item: 3 2 1 4 5
Enter the profit of each item: 25 20 15 40 50
Enter the knapsack capacity: 6
The output is: 
	0   0   0	  0	  0	  0	  0
	0	  0   0	  25	25	25	25
	0	  0   20	25	25	45	45
	0   15  20	35	40	45	60
	0	  15	20	35	40	55	60
	0	  15	20	35	40	55	65
The optimal solution is: 65
The solution vector is:  0 0 1 0 1
*/
