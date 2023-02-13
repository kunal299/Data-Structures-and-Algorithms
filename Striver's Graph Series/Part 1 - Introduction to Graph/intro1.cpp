#include "bits/stdc++.h"
using namespace std;

int main() {

    int noOfNodes, noOfEdges;
    cin>>noOfNodes>>noOfEdges;
    
    vector<vector<int>> adj(noOfNodes+1, vector<int> (noOfNodes+1, 0));
    
    for(int i=0; i<noOfEdges; i++) {
        int v, u; cin>>v>>u;
        adj[v][u] = 1;
        adj[u][v] = 1;
    }
    
    for(int i=0; i<noOfNodes+1; i++) {
        for(int j=0; j<noOfNodes+1; j++) {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}