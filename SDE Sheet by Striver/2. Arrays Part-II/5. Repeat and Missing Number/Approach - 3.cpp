/*
    Time Complexity - O(n)
    Space Complexity - O(1)
*/

//Using the XOR property

#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    //Step 1: Cal Xor of all a[i]
    int x = arr[0];
    for(int i=1; i<n; i++) {
        x ^= arr[i];
    }
    
    //Step2: Cal Xor of 1..n 
    int y = 1;
    for(int i=2; i<=n; i++) {
        y ^= i;
    }
    
    //Step3: Cal x^y 
    int nums = x^y;
    
    //Step4: Separate in 2 baskets
    int basket1 = 0;
    int basket2 = 0;
    int r_set_bit = nums & ~(nums - 1);
    
    for(int i=0; i<n; i++) {
        if(r_set_bit & arr[i]) {
            basket1 ^= arr[i];
        } else {
            basket2 ^= arr[i];
        }
    }
    
    //Step5: Separate (1..n) in 2 baskets
    for(int i=1; i<=n; i++) {
        if(r_set_bit & i) {
            basket1 ^= i;
        } else {
            basket2 ^= i;
        }
    }
    
    //Step6: Xor both baskets to find the number
    //Done in Step4 and Step5 
    
    //Step7: Check if the number is present or not
    bool flag = false;
    for(int i=0; i<n; i++) {
        if(basket1 == arr[i]) {
            flag = true; 
            break;
        }
    }
    
    //Step8: According to Step7, return the values in a pair
    if(flag) {
        return {basket2, basket1};
    } else {
        return {basket1, basket2};
    }
}
