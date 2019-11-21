/*Question Based on HeapSort
8a. Check if a given array represents a Binary Max Heap*/

#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n;
    bool flag=true;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;
    int a[n+1];
    cout<<"Enter the array elements : "<<endl;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=floor(n/2);i++)
    {
        if(2*i+1<=n)
        {
            if(a[i]<=max(a[2*i],a[2*i+1]))
            {
                flag=false;
                break;
            }
        }
        else
        {
            if(a[i]<=a[2*i])
            {
                flag = false;
                break;
            }
        }
    }
    if(flag)
    {
        cout<<"Array forms a Max heap"<<endl;
    }
    else
    {
        cout<<"Array does not forms a Max heap"<<endl;
    }
}
/*
OUTPUT:
Enter the size of the array: 10
Enter the array elements : 70 12 30 10 8 15 20 9 5 2
Array forms a Max heap
*/
