// Buy and sell stock part 3  (this is a 3d dp problem)
/*

similar to previous ones we can only do at max of two transactions 

1. Here  the function is going to have 3 changing variable index,flag of buy , number of transaction completed (in the question there are two transactions)

*/

#include<iostream>
#include<vector>
using namespace std;

// memorizatoion 

int f(int ind, int buy, int cap, vector<int>& prices, int n, vector<vector<vector<int>>>& dp)
{
    if (ind == n || cap == 0)
    {
        return 0;
    }

    if (dp[ind][buy][cap] != -1)
        return dp[ind][buy][cap];

    if (buy == 1)
    {
        return dp[ind][buy][cap] = max(
            -prices[ind] + f(ind + 1, 0, cap, prices, n, dp),
            f(ind + 1, 1, cap, prices, n, dp)
        ); // similar to the previous code we have just introduced cap
    }

    return dp[ind][buy][cap] = max(
        prices[ind] + f(ind + 1, 1, cap - 1, prices, n, dp),
        f(ind + 1, 0, cap, prices, n, dp)
    ); // max of sell vs no sell
}

// the memo code will give us TLE due to the auxillary stack space so instead we will use tabulation process

int solve(int n, vector<int>& prices)
{
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    // lets write the base case if cap is zero than dp is zero no matter what is the value of ind,buy
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            dp[i][j][0] = 0; // no matter what is the value of  ind,buy if the cap is zero than everything is zero 
        }
    }

    // similarly if ind==n then dp is zero no matter what is the value of buy,cap
    for (int j = 0; j < 2; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            dp[n][j][k] = 0;
        }
    }

    // now we will  write the tabulation code here   i have written three loops and the rest cases are similar to the previous one



    for (int i = n - 1; i >= 0; i--) // here dp is calculated from the future value of function (ind+1) so we have to first calculate the future value that is why n-1........0
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {
                if (buy == 1)
                {
                    dp[i][buy][cap] = max(
                        -prices[i] + dp[i + 1][0][cap],
                        dp[i + 1][1][cap]
                    ); // similar to the previous code we have just introduced cap
                }
                else
                {
                    dp[i][buy][cap] = max(
                        prices[i] + dp[i + 1][1][cap - 1],
                        dp[i + 1][0][cap]
                    ); // max of sell vs no sell
                }
            }
        }
    }

    return dp[0][1][2];
}


// optimized case in striver lecture 





int maxProfit(vector<int>& prices, int n)
{
    // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1))); 
    // here is a 3d dp which has n rows and (2columns which has 3 options in it)
    // rows represent the index , colmns represent the flag to buy and sell the stock and 3 options inside the colm represent teh number of transactions

    // return f(0,1,2,prices,n,dp);
    return solve(n, prices);
}

int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4}; // Sample input
    int n = prices.size();

    cout << "Maximum Profit: " << maxProfit(prices, n) << endl;

    return 0;
}
