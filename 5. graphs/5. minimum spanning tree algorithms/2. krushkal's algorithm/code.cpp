#include<bits/stdc++.h>

using namespace std;


void sort_edges(vector<pair<int, int>> adj[], set<vector<int>>& edges, int n){
    // store edges from adj list in the form {weight, src, dest}
    for(int i = 0; i < n; ++ i){
        for(auto node: adj[i]){
            int weight = node.first;
            int dest = node.second;
            edges.insert({weight, min(i, dest), max(i, dest)});
        }
    }
}
// code for disjoint set
int parent(int node, vector<int>& parents){
    if(parents[node] == -1) return node;
    return parent(parents[node], parents);
}

void krushkals(vector<pair<int, int>> adj[], int n){
    
    // set ds is used to remove duplicate edges and to store the edges
    set<vector<int>> edges;
    // sort the edges of the form {weight, src, dest}
    sort_edges(adj, edges, n);
    
    // create parent vector of length where every parent = -1
    vector<int> parents(n, -1);
    // iterate through the sorted edges
    int sum = 0;
    for(auto edge: edges){
        int weight = edge[0];
        int src = edge[1];
        int dest = edge[2];

        // get the parents of source and destination
        int src_parent = parent(src, parents);
        int dest_parent = parent(dest, parents);

        // if both parents are equal they belongs to same component so no need to alter parents
        if(src_parent == dest_parent) continue;
        // if there is no ultimate parent to only src make dest as its parent 
        else if(src_parent == src and dest_parent != dest){
            parents[src] = dest;
            sum += weight;
        }
        // even if dest dont have a parent or both have different parents make src as the parent of dest 
        else{
            parents[dest] = src;
            sum += weight;

        }
   
    }
    cout << "minimum length:"<< sum << endl;
    cout << "parent array:";
    for(int i: parents) cout << i << " ";




}

int main(){
    int n = 5;
    vector<pair<int, int>> adj[n];
    // graph representation in adjacency list {d, v} where:
    // d = distance or weight
    // v = destination vertix

    adj[0] = {{2, 1}, {1, 2}};
    adj[1] = {{1, 2}, {2, 0}};
    adj[2] = {{1, 0}, {1, 1}, {2, 4}, {2, 3}};
    adj[3] = {{1, 4}, {2, 2}};
    adj[4] = {{2, 2}, {1, 3}};
    
    krushkals(adj, n);
    return 0;
}