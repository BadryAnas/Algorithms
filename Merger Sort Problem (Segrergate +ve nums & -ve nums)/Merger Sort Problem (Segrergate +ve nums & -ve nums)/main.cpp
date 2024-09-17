#include <iostream>

using namespace std;


void Merge(int array[], int start , int mid , int end)
{
    int k = start;

    int left_Length = mid - start + 1;
    int right_length = end - mid;

    int left[left_Length];
    int right[right_length];

    for(int x = 0 ; x < left_Length ; x++)
    {
        left[x] = array[x + start];
    }

    for(int x = 0 ; x < right_length ; x++)
    {
        right[x] = array[x + mid + 1];
    }


    for(int x = 0 ; x < left_Length ; x++)
    {
        if(left[x] < 0)
        {
            array[k] = left[x];
            k++;
        }
    }

    for(int x = 0 ; x < right_length ; x++)
    {
        if(right[x] < 0)
        {
            array[k] = right[x];
            k++;
        }
    }

    for(int x = 0 ; x < left_Length ; x++)
    {
        if(left[x] >= 0)
        {
            array[k] = left[x];
            k++;
        }
    }

    for(int x = 0 ; x < right_length ; x++)
    {
        if(right[x] >= 0)
        {
            array[k] = right[x];
            k++;
        }
    }

}


void MergeSort(int array[] , int start , int end)
{
    if(start >= end)
        return;

    int mid = ( end + start ) / 2;

    MergeSort(array , start , mid);
    MergeSort(array , mid + 1 , end);

    Merge(array , start , mid , end);
}


int main()
{
    int arr[] = {10 , 9 , 8 , 7 , -1 , -90 , -50 , -4};

    int size = sizeof(arr) / sizeof(arr[0]);

    cout<<"Collection Before Segregate :"<<endl;
    for(int i = 0 ; i < size ; i++)
        cout<<arr[i]<< " ";

    cout<<endl;
    cout<<"================================="<<endl;

    MergeSort(arr , 0 , size - 1);

    cout<<"Collection After Segregate :"<<endl;

    for(int i = 0 ; i < size ; i++)
        cout<<arr[i]<< " ";

    return 0;
}
