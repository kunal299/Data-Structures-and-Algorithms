/*
    Time Complexity - O(nlogn) + O(n^2) 
    Space Complexity - O(n)
*/

class Solution {
public:
    vector<pair<int, int>> merge(vector<pair<int, int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        vector<pair<int, int>> ans;

        for (int i = 0; i < intervals.size(); i++) {
            int start = intervals[i].first, end = intervals[i].second;

            //since the intervals already lies 
            //in the data structure present we continue
            if (!ans.empty()) {
                if (start <= ans.back().second) {
                    continue;
                }
            }

            for (int j = i + 1; j < intervals.size(); j++) {
                if (intervals[j].first <= end) {
                    end = intervals[j].second;
                }
            }

            ans.push_back({start,end});
        }

        return ans;
    }
};