
/*
Best day to buy and sell the stock 

so while moving forward we will keep track of the element on the left and that will give us the answer 


*/






#include<iostream>
using namespace std;


int maxProfit(vector<int>&prices)
{
int mini=prices[0]; // initiated everything as minimal element 
int maxProfit=0;

int n=prices.size();


for(int i=0; i<n; i++)
{
    int cost=prices[i]-mini;  // calulared the cost which is next element-prevous element 
      
    maxProfit=max(maxProfit,cost);

    mini=min(mini,prices[i]); // updating the minimum element 
}




}




int main()
{





    return 0;
}