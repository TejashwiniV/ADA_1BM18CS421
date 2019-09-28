/* 6b. Find the ordering of tasks from given dependencies */

#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int n;
void findorder(){
    cout<<"The jobs have to be completed in the order..."<<endl;
    int indegree[100],k,s[100],top=-1;
    for(int i=0;i<n;i++){
        indegree[i]=0;
        for(int j=0;j<n;j++){
            indegree[i] +=a[j][i];
        }
    }
    for(int i=0;i<n;i++){
            if(indegree[i]==0){
                s[++top]=i;
            }
    }
    while(top!=-1 ){
            k=s[top--];
            cout<<k<<" ";
            indegree[k]=-1;
            for(int r=0;r<n;r++){
                if(a[k][r]==1){
                    indegree[r] -=1;
                    if(indegree[r]== 0){
                        s[++top]=r;
                    }
                }
            }
    }
    cout<<endl;
}
int main(){
    int t,p,q,d;
    cout<<"Enter no. of test cases"<<endl;
    cin>>t;
    cout<<t<<endl;
    while(t--){
        a[n][n] = {0};
        cout<<"Enter no. of tasks"<<endl;
        cin>>n;
        cout<<n<<endl;
        cout<<"Enter np. of dependencies"<<endl;
        cin>>d;
        cout<<d<<endl;
        for(int i=0;i<d;i++){
            cout<<"Enter pre-requisite job"<<endl;
            cin>>p;
            cout<<p<<endl;
            cout<<"Enter the job"<<endl;
            cin>>q;
            cout<<q<<endl;
            a[p][q] = 1;
        }
        findorder();
    }
    
}
