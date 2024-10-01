#include <bits/stdc++.h>

using namespace std;

vector<int> GreedyActivitySelector(int start[] , int end[], int size)
{
    int  j = 0;
    vector<int> result;
    result.push_back(0);

    for(int i = 1 ; i < size ; i++)
    {
        if(start[i] >= end[j])
        {
            result.push_back(i);
            j = i;
        }
    }
//    for(int i = 0 ; i < result.size() ; i++)
//    {
//        cout<<result[i]<<" ";
//    }

    return result;
}



int main()
{
    /// Greedy Algorithm
    /// Actually it is not Algorithm But it is Technique
    /// Like Divide & Conquer not Algorithm but Technique

    int startHours[] = {9,10,11,12,13,15};
    int endHours[] = {11,11,12,14,15,16};

    int size  = sizeof(startHours) / sizeof(startHours[0]);

    vector<int> result = GreedyActivitySelector(startHours, endHours, size);

    for(int i = 0 ; i < result.size() ; i++)
    {
        cout<<result[i]<<" ";
    }

    return 0;
}
