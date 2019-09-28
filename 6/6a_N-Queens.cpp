/*6a.Solving N-Queens Problem using backtracking*/

#include <bits/stdc++.h>
using namespace std;
int x[100];
int flag = false;
bool place(int k, int i){
    for(int j=1;j<k;j++){
        if(x[j] == i || (abs(i - x[j]) == abs(j-k))){
            return false;
        }
    }
    return true;
}
void NQueens(int k,int n){
    for(int i=1;i<=n;i++){
        if(place(k,i)){
            x[k] = i;
            if(k == n){
                for(int queen : x){
                    if(queen != 0)
                    cout<<queen<<" ";
                }
                flag = true;
                cout<<endl;
            }
            else{
                NQueens(k+1,n);
            }
            }
        }
    }

int main(){
    int n,t;
    cout<<"Enter no. of Test Cases"<<endl;
    cin>>t;
    cout<<t<<endl;
    while(t--){
    flag = false;
    cout<<"Enter size of chess board: "<<endl;
    cin>>n;
    cout<<n<<endl;
    for(int i =0;i<n;i++){
        x[i] == 0;
    }
    NQueens(1,n);
    if(!flag){
        cout<<"No Possible Solution"<<endl;
    }
    }

}
