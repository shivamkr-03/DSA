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
    
    vector<int> adj_list[n];
    int u, v;
    printf("\nenter nodes that connect:\n");
    // consider input as 1 based indexing
    for(int i = 0; i < m; ++ i){
        cin >> u >> v;
        // mark the value in matrix connecting both nodes as 1
        adj_list[u - 1].push_back(v);
        adj_list[v - 1].push_back(u);
    }
    printf("\nadjacency matrix:\n");
    for(auto it: adj_list){
        for(auto i: it){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}