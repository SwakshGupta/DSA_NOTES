/*A celebrity is a person which is known by everyone but the celbrity itself does not know anyone  so we are given with nxn matrix  

0-means i person does not know the jth person and 1 means ith person know 

m[i][i] is always going to be zero we have to find whether a celebrity exist in a party or not ]


solution-

1. diagonal element is going to be zero 

2. the row of the  celebrity is going to be zero 

3. but the colmn of celebrity is going to be 1 except for a[i][i] obviously

so  we are checking the rows and column of the element 

Brute force -

1. Start a loop which will check celebrity in a row and then start a loop which will check the celebrity in the colmn 

2. tine complexity is o(n^2)


Optimized solution :-

1. Put all the element in the stack and use this condition while(s.size()!=1) and write the code inside this while loop 

2.  This while loop will stop only if one element is remaining in the stack say 3 have three element in the stack A,B,C

3. We will pop A and B and will check (if A knows B ) then remove A and push B  (if B knows A ) then push A and remove B

4. Then we will check the resultant with C in this way we will remain with only one element that could be our potential celebrity 

5. now we will check for this last element 
*/
#include<iostream>
using namespace std;

int main()
{




    return 0;
}