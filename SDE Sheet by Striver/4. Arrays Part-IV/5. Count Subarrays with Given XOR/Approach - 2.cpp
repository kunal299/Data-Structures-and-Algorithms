/*
    Time Complexity - O(n * logn) (for ordered map) 
        (worst case searching in an unordered_map is O(n) so it's safer to use ordered map)
    Space Complexity - O(n)
*/

#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    map<int, int> mp;
    int xor_sum = 0, cnt = 0;
    
    for(int i=0; i<arr.size(); i++) {
        xor_sum ^= arr[i];
        
        if(xor_sum == x) {
            cnt++;
        } 
        
        if(mp.find(xor_sum ^ x) != mp.end()) {
            cnt += mp[xor_sum ^ x];        
        } 
        
        mp[xor_sum]++;
    }
    
    return cnt;
}