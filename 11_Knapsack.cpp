/*Sole Knapsack problem using Greedy Technique.*/

#include <iostream>
using namespace std;

void fracKnap(int w[],int v[],int n,int c){
	double p[n],x[n];
	for(int i=0;i<n;i++){
		p[i]=double(v[i])/w[i];
		x[i]=0;
	}
	
	double k=0,m,y;int s,r=0;
	while(k<c && r<n){
		m=0;
		for(int i=0;i<n;i++){
			if(m<=p[i] && x[i]==0){
				m=p[i];s=i;
			}
		}
		if(w[s]+k<=c){
			k+=w[s];
			x[s]=1;
		}
		else{
			y=(c-k)/w[s];
			x[s]=y;
			k+=(c-k);
		}
		r++;
	}
	
	double q=0;
	cout<<"\nItems : ";
	for(int i=0;i<n;i++){
		if(x[i]>0){
			if(x[i]!=1)
				cout<<x[i]<<" of ";
			cout<<"item "<<i+1<<"\t";
			q+=x[i]*v[i];
		}
	}
	cout<<"\nProfit = "<<q<<endl;
}

int main(){
	int n,c;
	cout<<"Enter no. of items : ";
	cin>>n;
	int w[n],v[n];
	cout<<"Enter weights:\n";
	for(int i=0;i<n;i++)
		cin>>w[i];
	cout<<"Enter value:\n";
	for(int i=0;i<n;i++)
		cin>>v[i];
	cout<<"Enter capacity : ";
	cin>>c;
	fracKnap(w,v,n,c);
}


/*Output:
Enter no. of items : 5
Enter weights :
10 
20 
30 
40 
50 
Enter weights :
20
30
66
40
60
Enter capacity : 100
Items : item 1	item 2	item 3	0.8 of item 5	
Profit = 164
*/
