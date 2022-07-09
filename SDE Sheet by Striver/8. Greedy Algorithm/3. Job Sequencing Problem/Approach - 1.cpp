/*
    Time Complexity - O(nlogn) + O(n*m)
    Space Complexity - O(m)
*/

class Solution 
{
    public:
    
    static bool comparator(Job arr1, Job arr2) {
        if(arr1.profit > arr2.profit) {
            return true;
        }
    
        return false;
    }
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    {
        sort(arr, arr+n, comparator);
        
        int maxDays = 1;
        for(int i=0; i<n ;i++) {
            maxDays = max(maxDays, arr[i].dead);
        }
        
        vector<int> v(maxDays+1, -1);
        
        int maxProfit = 0;
        int cntJobs = 0;
        for(int i=0; i<n; i++) {
            for(int j=arr[i].dead; j>0; j--) {
                if(v[j] == -1) {
                    v[j] = i;
                    cntJobs++;
                    maxProfit += arr[i].profit;
                    break;
                }
            }
        }
        
        return {cntJobs, maxProfit};
    } 
};