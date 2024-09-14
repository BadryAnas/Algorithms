#include <iostream>

using namespace std;



void Merge(int array[] ,  int start ,int mid , int end)
{
    int i = 0 , j = 0, k = start ;

    // Find the lengths of the left and right sub-arrays

    int leftLength = mid - start + 1;
    int rightLength = end - mid;

    // Create two temporary arrays to hold the left and right sub-arrays

    int left[leftLength];
    int right[rightLength];

    // Copy the elements of the left and right sub-arrays from the main array to the temporary arrays
    for(int x = 0 ; x <= leftLength ; x++)
    {
        left[x] = array[x + start];
    }

    for(int x = 0 ; x <= rightLength ; x++)
    {
        right[x] = array[x + mid + 1];
    }

    while(i < leftLength && j < rightLength)
    {
        if(left[i] <= right[j])
        {
            array[k] = left[i];
            i++;
        }
        else{
            array[k] = right[j];
            j++;
        }
        k++;
    }

    while(i < leftLength)
    {
        array[k] = left[i];
        i++;
        k++;
    }

    while(j < rightLength)
    {
        array[k] = right[j];
        j++;
        k++;
    }

}


// Recursively divide the array into two halves

void MergeSort(int array[] ,  int start , int end)
{
    // Base Case
    if(end <= start)
        return;

    int mid = (end + start) / 2;

    MergeSort(array, start , mid );
    MergeSort(array, mid + 1 , end);

    Merge(array , start , mid , end);

    return;
}

// Test the MergeSort function with an example array
int main()
{
    int array[] = {50,40,30,20,10};
    int size  = sizeof(array)/sizeof(array[0]);

    // Print the original array
    cout<< "Array Before MergeSort Algorithm :"<<endl;

    for(int i = 0 ; i < size ; i++)
    {
        cout<< array[i] << " " ;
    }

    cout<<endl;
    cout<< "==================================="<<endl;

    // Sort the array and print the Sorted array
    MergeSort(array, 0 , size - 1);

    cout<< "Array After MergeSort Algorithm :"<<endl;

    for(int i = 0 ; i < size ; i++)
    {
        cout<< array[i] << " " ;
    }

    return 0;
}
