/*Program based on Depth First search
4a. Given an undirected graph, print all connected components line by line.*/

#include <iostream>
#include <time.h>
using namespace std;

int adjacent[10][10],visited[10],n;

void DFS(int v)
{
	cout << v+1 <<" ";
	visited[v]=1;
	for(int i=0;i<n;i++)
	{
		if(adjacent[v][i]==1 && visited[i]==0)
		{
			DFS(i);
		}
	}
}

int main()
{
	int i,j;
	double time;
	clock_t start,end;
	start=clock();
	cout << "Enter the number of components: ";
	cin >> n;
	for (i=0;i<n;i++)
	{
		visited[i]=0;
	}
	cout << "Enter the adjacent matrix of graph: \n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin >> adjacent[i][j];
		}
	}
	cout << "DFS traversal: ";
	for(i=0;i<n;i++)
	{
		if(visited[i] == 0)
			DFS(i);
	}
	end=clock();
	time=(double)(end-start)/CLOCKS_PER_SEC;
	cout<<"\nExecution time is: "<<time<<"secs\n";
	return 0;
}


