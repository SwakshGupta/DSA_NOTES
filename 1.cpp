#include<iostream>
using namespace std;


int fn(int n)
{
string s="";
s.push_back(n);
int ans=0;


for(int i=0; i<1e9; i++)
{
string m="i";
s+=i;
int l=stoi(s);

if(l%(n+i)==0)
{
    ans=i;
    break;
}
s.erase(s.size()-m.size());
}

return ans;
}


int main()
{




    return 0;
}