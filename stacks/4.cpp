/*
Asteroid problem 

Q----->We are given an array asteroids of integers representing asteroids in a row. The indices of the asteriod in the array represent their relative position in space.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

*/

#include<stack>
#include<iostream>
using namespace std;

// although this soution is good but it gives error for some test cases 
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n = ast.size();
        stack<int> s;
        for(int i = 0; i < n; i++) {
            if(ast[i] > 0 || s.empty()) { // whenever we encounter a positive asteroid we will push that into stack 
                s.push(ast[i]);
            }
            else {
                while(!s.empty() and s.top() > 0 and s.top() < abs(ast[i])) { // if asteroid is negative and its value is greater than the positive asteroid then it would pop out that asteroid 
                    s.pop();
                }
                if(!s.empty() and s.top() == abs(ast[i]) && abs(ast[i]<0)) { // if value of negative asteroid is equal to the positive asteroid then it would again pop out the positive asteroid 
                    s.pop();
                }
                else {
                    if(s.empty() && s.top() < 0) { // if due to knocking  stack becomes empty then current asteroid will enter in the stack 
                        s.push(ast[i]);
                    }
                }
            }
        }
		// here we have created the res vector where we will be pushing the final elements of the stack which is the answer

        vector<int> res(s.size());
        for(int i = (int)s.size() - 1; i >= 0; i--) {
            res[i] = s.top();
            s.pop();
        }
        return res;
    }
};

// striver approach 






int main()
{






    return 0;
}