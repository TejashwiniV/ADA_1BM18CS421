#include<bits/stdc++.h>
using namespace std;
int grid[100][100];
int N,SQN;
bool usedInRow(int row,int num){
    for(int col=0;col<N;col++){
        if(grid[row][col] == num)
            return true;
    }
    return false;
}
bool usedInColumn(int col,int num){
    for(int row=0;row<N;row++){
        if(grid[row][col] == num)
            return true;
    }
    return false;
}
bool usedInBox(int boxStartRow,int boxStartCol, int num){
    for(int row=0;row< SQN;row++){
        for(int col =0;col<SQN;col++){
            if(grid[row+boxStartRow][col+boxStartCol] == num){
                return true;
            }
        }
    }
    return false;
}
bool isSafe(int row,int col,int num){
    return(!usedInRow(row,num) && !usedInColumn(col,num) && !usedInBox(row-row%SQN,col-col%SQN,num));
}
bool findUnassignedLocation(int *row, int *col){
    for(int i =0;i<N;i++){
        for(int j =0;j<N;j++){
            if(grid[i][j] == 0){
                *row = i;
                *col = j;
                return true;
            }
        }
    }
    return false;
}
bool solveSuduko(){
    int row,col;
    if(!findUnassignedLocation(&row,&col)){
        return true;
    }
    for(int num=1;num<=N;num++){
        if(isSafe(row,col,num)){
            grid[row][col] = num;
            if(solveSuduko()){
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}
int main(){
    cout<<"Enter Sudoku size(perfect square within 100):";
    cin>>N;
    cout<<"\nEnter Sudoku elements:";
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>grid[i][j];
        }
    }
    SQN = sqrt(N);
        cout<<"\nSudoku"<<endl;
         for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }   
    
    bool t = solveSuduko();
    cout<<endl;
    Solution:
    if(t){
     for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }   
    }
    else
    {
        cout<<"No Solution";
    }
    
}



/*
OUTPUT 1:
Enter Sudoku size(perfect square within 100):4
Enter Sudoku elements:
1 0 3 0
4 0 2 0
3 0 1 0
2 0 4 0
Sudoku
1 0 3 0
4 0 2 0
3 0 1 0
2 0 4 0
Solution:
1 2 3 4
4 3 2 1
3 4 1 2
2 1 4 3
OUTPUT 2:
Enter Sudoku size(perfect square within 100):4
Enter Sudoku elements:
1 0 3 0
2 0 4 0
3 0 1 0
1 0 3 0
Sudoku
1 0 3 0
2 0 4 0
3 0 1 0
1 0 3 0
Solution:
No Solution
OUTPUT 3:
Enter Sudoku size(perfect square within 100):9
Enter Sudoku elements:
1 0 3 0 5 0 7 0 9
0 5 0 7 0 9 0 2 0
7 0 9 0 2 0 4 0 6
0 1 0 3 0 5 0 9 0
3 0 5 0 9 0 2 0 4
8 9 7 2 1 4 3 6 5
0 3 0 6 0 2 0 7 0
6 4 2 9 7 8 5 3 1
9 7 8 5 3 1 6 4 2
Sudoku
1 0 3 0 5 0 7 0 9
0 5 0 7 0 9 0 2 0
7 0 9 0 2 0 4 0 6
0 1 0 3 0 5 0 9 0
3 0 5 0 9 0 2 0 4
8 9 7 2 1 4 3 6 5
0 3 0 6 0 2 0 7 0
6 4 2 9 7 8 5 3 1
9 7 8 5 3 1 6 4 2
Solution:
1 2 3 4 5 6 7 8 9
4 5 6 7 8 9 1 2 3
7 8 9 1 2 3 4 5 6
2 1 4 3 6 5 8 9 7
3 6 5 8 9 7 2 1 4
8 9 7 2 1 4 3 6 5
5 3 1 6 4 2 9 7 8
6 4 2 9 7 8 5 3 1
9 7 8 5 3 1 6 4 2
*/
