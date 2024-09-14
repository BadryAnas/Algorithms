#include <iostream>

using namespace std;

/// Analysis
/// Time complexity O( log(n) )


int BinarySearch(int array[] , int key, int high )
{
    int low = 0;

    while(low <= high)
    {
        int mid = (low + high ) / 2 ;

        // Check if key is present at mid
        if(array[mid] == key)
            return  mid;

        // If key greater, ignore left half
        if(array[mid] < key)
            low = mid + 1;

        // If key is smaller, ignore right half
        else
            high = mid - 1;
    }

    // If we reach here, then element was not present
    return -1;

}



int main()
{
    int array [] = {1 , 2 , 3 , 4 , 6 , 30 };
//                  0   1   2   3   4   5

    /// We have to use this line at the Scope where we define function
    /// Because it will be different from another Scope where the result will be
    /// The size of pointer

    int n = sizeof(array)/sizeof(array[0]) ;

    int indexOfKey = BinarySearch( array , 9 , n - 1 );

    if(indexOfKey != -1)
        cout<< "The element at position number : " << indexOfKey;
    else
        cout<<"The element isn't exist";

    return 0;
}
