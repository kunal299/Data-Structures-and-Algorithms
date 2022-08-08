/*
    Time Complexity - O(n^2)
    Space Complexity - O(1)
*/

#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    int cnt = 0;
    
    for(int i=0; i<arr.size(); i++){
        int xor_sum = 0;
        for(int j=i; j<arr.size(); j++){
            xor_sum ^= arr[j];
            if(xor_sum == x) cnt++;
        }
    }
    
    return cnt;
}