/*
	Time Complexity - O(M)
	Space Complexity - O(N*M)
*/

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n, m; cin>>n>>m;

	int adj[n+1][m+1];
	for(int i=0; i<m; i++) {
		int u, v; cin>>u>>v;
		adj[u][v] = adj[v][u] = 1;
	}

	return 0;
}