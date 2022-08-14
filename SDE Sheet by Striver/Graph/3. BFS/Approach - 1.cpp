/*
    Time Complexity - O(V) + O(2*E)
    Space Complexity - O(3*V) ~ O(V)

    where E - no. of edges
          V - no. of vertices
*/

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0};
        vis[0] = 1;
        
        queue<int> q;
        q.push(0);
        
        vector<int> bfs;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            
            for(auto &it: adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        
        return bfs;
    }
};