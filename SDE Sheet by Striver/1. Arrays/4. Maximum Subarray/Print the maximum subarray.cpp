#include <bits/stdc++.h>
using namespace std;

void maxSubArray(vector<int>& nums) {
    int size = nums.size();
        
    int sum = 0;
    int maxi = INT_MIN;
    
    int si=0, ei=0;
    int s = 0;        
    for(int i=0; i<size; i++) {
        sum += nums[i];
        if(sum>maxi) {
            si = s;
            ei = i;
        }
        maxi = max(maxi, sum);
        if(sum<0) {
            sum = 0;
            s = i+1;
        } 
    }

    for(int i=si; i<=ei; i++) {
        cout<<nums[i]<<" ";
    }
}

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    maxSubArray(nums);
}
