/*
    Time Complexity - O(N) + O(2*E)
    Space Complexity - O(N) 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void dfs(int node, int vis[], vector<int> adj[], vector<int> &ans) {
        vis[node] = 1;
        ans.push_back(node);
        
        for(auto it: adj[node]) {
            if(!vis[it]) {
                dfs(it, vis, adj, ans);
            }
        }
    }
    
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V+1] = {0};
        vector<int> ans;
         
        dfs(0, vis, adj, ans);
        
        return ans;
    }
};