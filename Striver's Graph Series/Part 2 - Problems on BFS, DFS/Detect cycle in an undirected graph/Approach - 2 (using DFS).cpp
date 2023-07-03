/*
    Time Complexity - O(V + 2*E) + O(V)
    Space Complexity - O(V) + O(V)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool detect(int node, int parent, vector<int> adj[], int vis[]) {
        
        vis[node] = 1;
        
        for(auto it: adj[node]) {
            if(!vis[it]) {
                if(detect(it, node, adj, vis)) return true;
            } else if(it != parent) {
                return true;
            }
        }
        
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        int vis[V] = {0};
        
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(detect(i, -1, adj, vis)) return true;
            }
        }
        
        return false;
    }
};