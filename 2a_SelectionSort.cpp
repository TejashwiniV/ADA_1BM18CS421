#include <iostream>
#include <time.h>
using namespace std;
int main()
{
    int arr[100],size,i,j,k,min,swap;
    clock_t start,end;
    double time;
    cout << "Enter the size of an array:";
    cin >> size;
    cout << "Enter the elements of an array:";
    for(i=0;i<size;i++)
    {
        cin >> arr[i];
    }
    cout << "Enter k'th index:" <<endl;
    cin >> k;
    start = clock();
    for(i=0;i<size-2;i++)
    {
        min = i;
        for(j=i+1;j<size-1;j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap = arr[i];
        arr[i] = arr[min];
        arr[min] = swap;
    }
    end = clock();
    cout << "K'th smallest element is:" << arr[k-1] << endl;
    time = (double)(end-start)/CLOCKS_PER_SEC;
    cout << "Execution time is:" << time << "secs" << endl;
    return 0;
    
}
