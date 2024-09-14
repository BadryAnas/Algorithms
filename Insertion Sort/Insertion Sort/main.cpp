#include <iostream>

using namespace std;

int main()
{
    /// How does this Algorithm Work ?
    /// array
    ///   We Start With Index (ONE)
    ///   n0 n1 n2 n3
    ///   <----
    ///   <-------
    ///   <----------
    /// (Nested LOOP)
    ///



    int n = 4;
    int a[n] = {9, 5, 1, 4};

    for(int i = 1 ; i < n ; i++)
    {
        int key = a[i];
        int j = i-1;

        for( ;j >= 0 ; j--)
        {
            if(key < a[j])
                a[j+1] = a[j];
            else
                break;
        }

        a[j+1] = key;

    }

    for(int i = 0 ; i < n ; i++)
    {
        cout<< a[i] << " ";
    }

    return 0;
}
