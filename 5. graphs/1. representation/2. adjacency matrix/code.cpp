#include<bits/stdc++.h>

using namespace std;

int main(){
    
    int n, m;
    printf("enter number of nodes: ");
    cin >> n;
    printf("\nenter number of edges: ");
    cin >> m;
    
    // for zero based indexing we take adj[n][n] as size.
    // for 1 based indexing we take adj[n + 1][n + 1] size.
    // we took zero based indexing...
    
    vector<vector<int>> adj(n, vector<int>(n));
    int u, v;
    printf("\nenter nodes that connect:\n");
    // consider input as 1 based indexing
    for(int i = 0; i < m; ++ i){
        cin >> u >> v;
        // mark the value in matrix connecting both nodes as 1
        adj[u - 1][v - 1] = 1;
        adj[v - 1][u - 1] = 1;
    }
    printf("\nadjacency matrix:\n");
    for(auto it: adj){
        for(auto i: it){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}