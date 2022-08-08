/*
    Time Complexity - O(nlogn) + O(nlogn) + O(n) ~ O(nlogn)
    Space Complexity - O(1)
*/

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr, arr+n);
        sort(dep, dep+n);
        
        int i=0;
        int j=0;
        
        int maxTrain = 0;
        int plat = 0;
        
        while(i<n && j<n) {
            if(arr[i] <= dep[j]) {
                maxTrain++;
                i++;
            } else {
                maxTrain--;
                j++;
            }
            
            plat = max(plat, maxTrain);
        }
        
        return plat;
    }
};