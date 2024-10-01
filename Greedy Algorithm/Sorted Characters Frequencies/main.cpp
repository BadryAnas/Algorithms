#include <bits/stdc++.h>

using namespace std;

void Merge(int array[][2], int start , int mid , int end)
{

    int left_Length = mid - start + 1;
    int right_length = end - mid;

    int left_Array[left_Length][2];
    int right_Array[right_length][2];

    for(int i = 0 ; i < left_Length ; i++ )
    {
        left_Array[i][0] = array[i + start][0];
        left_Array[i][1] = array[i + start][1];
    }

    for(int i = 0 ; i < right_length ; i++ )
    {
        right_Array[i][0] = array[i + mid + 1][0];
        right_Array[i][1] = array[i + mid + 1][1];
    }

    int i = 0 , j = 0 , k = start;

    while( i < left_Length && j < right_length)
    {
        if(left_Array[i][1] < right_Array[j][1])
        {
            array[k][0] = left_Array[i][0];
            array[k][1] = left_Array[i][1];
            i++;
        }
        else if(left_Array[i][1] == right_Array[j][1])
        {
            if(left_Array[i][0] < right_Array[j][0])
            {
                array[k][0] = left_Array[i][0];
                array[k][1] = left_Array[i][1];
                i++;
            }
            else
            {
                array[k][0] = right_Array[j][0];
                array[k][1] = right_Array[j][1];
                j++;
            }
        }
        else
        {
            array[k][0] = right_Array[j][0];
            array[k][1] = right_Array[j][1];
            j++;
        }
        k++;
    }

    while( i < left_Length )
    {
        array[k][0] = left_Array[i][0];
        array[k][1] = left_Array[i][1];
        i++;
        k++;
    }

    while( j < right_length )
    {
        array[k][0] = right_Array[j][0];
        array[k][1] = right_Array[j][1];
        j++;
        k++;
    }
}


void MergeSort(int array[][2] , int start , int end)
{
    if(end <= start) return;

    int mid = (start + end) / 2;

    MergeSort(array , start  , mid);
    MergeSort(array , mid + 1  , end);

    Merge(array , start , mid , end);
}



void FrequencyOfCharacters(string str)
{
    map<char, int>mp;

    for(int i = 0 ; i < str.size() ; i++)
    {
        mp[ str[i] ]++ ;
    }


    /// Convert from map to 2D Array
    int array[mp.size()][2];
    int index = 0;

    for(auto &[i , j] : mp)
    {
        array[index][0] = i;
        array[index][1] = j;
        index++;
    }



    MergeSort(array , 0 , mp.size() - 1);

    /// Print Array After Sort ( By value then  Alphapitecal )
    for(int i = 0 ; i < mp.size() ; i++)
    {
        cout<<(char)array[i][0] << " " << array[i][1]<<endl;
    }

}



int main()
{

    string str = "The output from Huffman's algorithm can be viewed as a variable length code table for encoding a source symbol. The algorithm derives this table from the estimated probability or frequency of occurrence for each possible value of the source symbol. as in other entropy encoding methods, more common symbols are generally represented using fewer bits than less common symbols. Huffman's method can be efficiently implemented, finding a code in time linear to the number of input weights if these weights are sorted. However, although optimal among methods encoding symbols separately, Huffman coding is not always optimal among all compression methods it is replaced with arithmetic coding or asymmetric numeral systems if better compression ratio is required.";
    FrequencyOfCharacters(str);

    return 0;
}
