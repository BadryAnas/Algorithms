#include <iostream>

using namespace std;

int main()
{
    string str1 = "OHELOD" , str2 = "HELLOWORLD" ;

    str1 = ' ' + str1;
    str2 = ' ' + str2;

    int rows = str1.size();
    int columns = str2.size();


    int dp[rows][columns];

    for(int i = 0 ; i < rows ; i++)
    {
        for(int j = 0 ; j < columns ; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else
            {
                if(str1[i] == str2[j])
                {
                    /// top left corner + 1
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                {
                    /// max between top and left
                    dp[i][j] = max(dp[i][j-1] , dp[i-1][j]);
                }
            }
        }
    }

    string solution = "";

    int i = rows - 1 ;
    int j = columns - 1 ;

    while(i > 0 && j > 0)
    {
        if(dp[i][j] > dp[i][j-1])
        {
            if(dp[i][j] == dp[i - 1][j])
            {
                i--;
            }
            else
            {
                /// There is Matching
                solution = str1[i] + solution;
                i--;
                j--;
            }
        }
        else
        {
            j--;
        }
    }

    cout<<solution;

    return 0;
}
