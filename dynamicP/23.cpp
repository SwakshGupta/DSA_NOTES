/*
Best time to buy and sell stock 2

similar to the previous problem we can just buy and sell the stock immedietly so we can multiple stocks and sell multiple stocks but the only catch is 
you can buy another stock only when you have sold the previous stock 


1.  here we are changing index and the condition to buy and sell the stock 

2. So we will create a 2d dp with index as variable and flag (which will tell us to buy or sell the stock)




*/


#include<iostream>
using namespace std;


// This is the memorization approach 

long f(int ind,int buy,long *values,int n,vector<vector<long>>&dp)
{

if(ind==n) // base case
return 0;

if(dp[ind][buy]!=-1)
return dp[ind][buy]; // buy is like a flag it can only take 0,1 values 


long profit=0;
if(buy)
{
    profit=max(-values[ind]+f(ind+1,0,values,n,dp),0+f(ind+1,1,values,n,dp)); // if we are buying a stock then we will ad negative of the price and then call for the sell course
}

else
{
    profit=max(values[ind]+f(ind+1,1,values,n,dp),0+f(ind+1,0,values,n,dp)); // if have bought the stock and we can either sell it or not sell it then we will find max out of it 
}
return dp[ind][buy]=profit;

}



// lets do the tabulation approach 

long getMax(int ind,int buy,long*values,int n)
{

 vector<vector<long>>dp(n+1,vector<long>(2,0));

 dp[n][0]=dp[n][1]=0; // if the index is reachedd then it does not matter whether the stock is buyed or not it is equal to zero 


 for(int ind=n-1; ind>=0; ind--)
 {
    for(int buy=0; buy<=1; buy++)
{
    long profit=0;

    if(buy)
{
    profit=max(-values[ind]+dp[ind+1][0],0+dp[ind+1][1]); // if we are buying a stock then we will ad negative of the price and then call for the sell course
}

else
{
    profit=max(values[ind]+dp[ind+1][1],0+dp[ind+1][0]); // if have bought the stock and we can either sell it or not sell it then we will find max out of it 
}
return dp[ind][buy]=profit;


}
 }



}


// since we are depending upon the previous state so we can do optimization here that is what we will do now 






long getMaximumProfit(long*values,int n)
{
    vector<vector<long>>dp(n,vector<long>(2,-1));

    return f(0,1,values,n,dp);

     
}



int main()
{




    return 0;
}