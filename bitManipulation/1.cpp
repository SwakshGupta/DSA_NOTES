// Striver A to z series bits manipulation 

/*
1. here we are going to have multiple parts  decimal to binary approach  (check notebook for thory part )








*/


#include<iostream>
using namespace std;

string convert2Binary(int n) // this is our code to covert decimal to binary 
{
string res="";

while(n!=1) 
{
    if(n%2==1) 
    {
        res+='1'; // if remiander is equal to 1 then push 1 to the res 
        
    }
    else
    {
        res+='0'; // if remainder  is 0 then push zero to the string 
    }
    n=n/2;
}

reverse(res.begin(),res.end()); // we have to reverse the string at the end cuz res has reversed answer 
return res;


}


int covert2Decimal(string x) // so we are given a string and we have to return a int by converting into decimal
{

int len=x.length();
int num=0; // this is going to be out answer 

int p2=1; // initially the power of 2 is one 


for(int i=len-1; i>=0; i--) // we are starting with last digit of string and multiplying it with 2^0
{

if(x[i]=='1') // if the string is 1 then only the power gets added to the answer otherwise not 
{
    num=num+p2;
}
p2 =p2*2; // with each iteration our power gets increased check the notebook 

}
return num;
}

// time complexity  o(len)   and space complecxity o(1)






int main()
{






    return 0;
}