/*Program based on Depth First search
4b. Given a 2D matrix of 0s and 1s, find total number of clusters or Islands formed by 
elements with value 1.*/

#include <iostream>
#include <time.h>
using namespace std;

int matrix[10][10],visited[10][10],m,n;

void DFS(int row,int col)
{
	int rownum[]={-1,-1,-1,0,0,1,1,1};
	int colnum[]={-1,0,1,-1,1,-1,0,-1};
	visited[row][col]=1;
	for(int k=0;k<8;k++)
	{
		if((row+rownum[k])>=0 && (row+rownum[k])<m && (col+colnum[k])>=0 && (col+colnum[k]<n) && matrix[row+rownum[k]][col+colnum[k]]==1 && visited[row+rownum[k]][col+colnum[k]]==0)
		{
			DFS(row+rownum[k],col+colnum[k]);
		}
	}
}

int main()
{
	int j,i;
	double time;
	clock_t start,end;
	start=clock();
	cout << "Enter the number of rows: ";
	cin >> m;
	cout << "Enter the number of columns: ";
	cin >> n;
	cout << "Entre the adjacency matrix: \n";
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>matrix[i][j];
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			visited[i][j]=0;
		}
	}
	int count=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(matrix[i][j]==1 && visited[i][j]==0)
			{
				DFS(i,j);
				++count;
			}
		}
	}
	cout << "Number of islands: " << count;
	end=clock();
	time=(double)(end-start)/CLOCKS_PER_SEC;
	cout<<"\nExecution time is: "<<time<<"secs\n";
	return 0;
	
}
