/*
  Time Complexity - O(nlogn)
  Space Complexity - O(n)
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());

        while(pq.size()>1) {
          int max1 = pq.top();
          pq.pop();

          int max2 = pq.top();
          pq.pop();

          if(max1 != max2) {
            pq.push(max1-max2);
          }
        }

        return pq.empty() ? 0 : pq.top();
    }
};