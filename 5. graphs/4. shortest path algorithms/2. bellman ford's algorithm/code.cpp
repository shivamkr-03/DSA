#include<bits/stdc++.h>

using namespace std;


void bellman(vector<vector<int>> adj, int n) {
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;

    // iterate over all edges for n - 1 number of times
    for(int i = 1; i <= n - 1; ++ i){

        for(auto i: adj){
            int u = i[0];
            int v = i[1];
            int w = i[2];
            // relax the edges
            if(dist[u] != INT_MAX and dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }

    }
    // to detect if there is any negative cycle relax the edges again
    //  if any distance updates then there must be a negative cycle
    // else there is no negative cycle...
    for(auto i: adj){
            int u = i[0];
            int v = i[1];
            int w = i[2];
            // relax the distance
            if(dist[u] + w < dist[v]){
                cout << "negative cycle occoured...\n";
                return;
            }
    }
    for(int i: dist) cout << i << " ";
        cout << endl;
        
}


int main(){
    // vector<pair<int, int>> adj[n];
    // // graph representation in adjacency list {d, v} where:
    // // d = distance or weight
    // // v = destination vertix

    // adj[0] = {{4, 1}, {8, 7}};
    // adj[1] = {{4, 0}, {11, 7}, {8, 2}};
    // adj[2] = {{8, 1}, {7, 3}, {2, 8}, {4, 5}};
    // adj[3] = {{7, 2}, {9, 4}, {14, 5}};
    // adj[4] = {{9, 3}, {10, 5}};
    // adj[5] = {{14, 3}, {10, 4}, {2, 6}};
    // adj[6] = {{2, 5}, {1, 7}, {6, 8}};
    // adj[7] = {{8, 0}, {1, 6}, {11, 1}, {7, 8}};
    // adj[8] = {{2, 2}, {7, 7}, {6, 6}};
    
    // input for bellman ford will be in the form of {src, dest, weight}

    vector<vector<int>> adj;
    int n = 6;

    adj = {
        {3, 2, 6},
        {5, 3, 1},
        {0, 1, 5}, 
        {1, 5, -3},
        {1, 2, -2},
        {3, 4, -2}, 
        {2, 4, 3}

    };
    bellman(adj, n);

    return 0;
}

