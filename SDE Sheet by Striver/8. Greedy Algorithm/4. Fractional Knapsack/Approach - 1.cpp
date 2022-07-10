/*
    Time Complexity - O(nlogn) + O(n)
    Space Complexity - O(1)
*/

class Solution
{
    public:
    
    static bool comparator(Item arr1, Item arr2) {
        if(((double)(arr1.value)/(double)(arr1.weight)) > ((double)(arr2.value)/(double)(arr2.weight))) {
            return true;
        }
        
        return false;
    }
    
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr+n, comparator);
        
        double maxValue = 0.0;
        int currWeight = 0;
        for(int i=0; i<n; i++) {
            
            if(currWeight + arr[i].weight <= W) {
                currWeight += arr[i].weight;
                maxValue += arr[i].value;
            } else {            
                maxValue += ((double)arr[i].value / (double)arr[i].weight) * (double)(W-currWeight);
                break;
            }
        }
        
        return maxValue;
    }
        
};