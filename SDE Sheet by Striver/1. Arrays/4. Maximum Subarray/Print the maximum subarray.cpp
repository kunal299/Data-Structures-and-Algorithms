#include <bits/stdc++.h>
using namespace std;

//This solution may be wrong...
void maxSubArray(vector<int>& nums) {
    int size = nums.size();
        
    int sum = 0;
    int maxi = INT_MIN;
    
    int si, ei;        
    for(int i=0; i<size; i++) {
        sum += nums[i];
        if(sum>maxi) {
            ei = i;
        }
        maxi = max(maxi, sum);
        if(sum<0) {
            sum = 0;
        } 
    }
    
    si = ei;
    while(si>=0) {
        maxi -= nums[si];
        if(maxi==0) {
            break;
        }    
        si--;
    }

    for(int i=si; i<=ei; i++) {
        cout<<nums[i]<<" ";
    }
}

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    maxSubArray(nums);
}
