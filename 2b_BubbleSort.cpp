#include <iostream>
#include <time.h>
using namespace std;
int main()
{
    int arr[100],size,i,j,k,swap;
    clock_t start,end;
    double time;
    cout << "Enter the size of an array:";
    cin >> size;
    cout << "Enter the elements of an array:";
    for(i=0;i<size;i++)
    {
        cin >> arr[i];
    }
    cout << "Enter largest k elements to print:";
    cin >> k;
    start=clock();
    for(i=0;i<size;i++)
    {  
        for(j=0;j<size-i-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = swap;
            }
        
        }
        
    }
    end=clock();
    cout << "K largest elements are:";
    for(i=size-1;i>size-1-k;i--)
    {
        cout << arr[i] << " ";
    }
    time = (double)(end-start)/CLOCKS_PER_SEC;
    cout << "\nExecution time is:" << time << "secs" << endl;
    return 0;

}
