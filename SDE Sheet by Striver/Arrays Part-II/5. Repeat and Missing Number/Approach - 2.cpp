/*
    Time Complexity - O(n)
    Space Complexity - O(1)
*/

//Using some mathematical equations

#include <bits/stdc++.h> 
typedef long long int lli;

pair<int,int> missingAndRepeating(vector<int> &arr, lli n)
{
    pair<lli, lli> p;
    
    //Sum of 1..n 
    lli sum1 = n*(n+1)/2;

    //Sum of squares of 1..n
    lli sum2 = n*(n+1)*((2*n)+1)/6;
    
    for(int i=0; i<n; i++) {
        sum1 -= (lli)arr[i];
        sum2 -= (lli)arr[i]*(lli)arr[i];
    }
    
    /*  
        Solving equations:
            1) x - y = sum1

            2) x^2 - y^2 = sum2
    */
    p.first = ((sum2/sum1) + sum1)/2;
    p.second = p.first - sum1;
    
    return p;
}
