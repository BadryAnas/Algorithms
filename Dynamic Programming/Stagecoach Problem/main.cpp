#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<char> labels = {'A' , 'B' , 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    int n = labels.size() ;

    int data [n][n] = {
                        {0, 2, 4, 3, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 7, 4, 6, 0, 0, 0},
                        {0, 0, 0, 0, 3, 2, 4, 0, 0, 0},
                        {0, 0, 0, 0, 4, 1, 5, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 1, 4, 0},
                        {0, 0, 0, 0, 0, 0, 0, 6, 3, 0},
                        {0, 0, 0, 0, 0, 0, 0, 3, 3, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
                    };

    vector<pair<int , char >> costs( n ); /// Cost , Parent

    vector< char > path;

    costs[n-1].first = 0 ;
    costs[n-1].second = ' ';

    for(int i = n-2 ; i >= 0  ; i--)
    {
        int tempCost = INT_MAX;
        int pos;
        for(int j = i + 1 ; j < n ; j++ )
        {
            if(data[i][j] == 0) continue;
            if(tempCost > data[i][j] + costs[j].first )
            {
                tempCost = data[i][j] + costs[j].first;
                pos = j;
            }

        }
        costs[i].first = tempCost;
        costs[i].second= labels[pos];
    }


    cout<<"Minimum Cost => " << costs[0].first<<endl;
    cout<<"Path is => ";

    int i = 0;

    char parent =  labels[i];

    while(parent != ' ')
    {
        if(labels[i] == parent)
        {
            cout<<parent<<" ==> " ;
            parent = costs[i].second;
        }
        i++;
    }

    return 0;
}
