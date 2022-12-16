#include<bits/stdc++.h>

using namespace std;

void dfs(int root, vector<bool>& visited, vector<int> adj[]){
    visited[root] = true;
    cout << root << " ";
    for(int i: adj[root]){
        if(!visited[i]){
            dfs(i, visited, adj);
        }
    }

}


int main(){
    int n = 5;
    vector<int> adj[n];
    adj[0] = {1, 2, 4};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 4};
    adj[3] = {1, 4};
    adj[4] = {0, 1, 2, 3};
    vector<bool> visited(n);
    for(int i = 0; i < n; ++ i){
        if(!visited[i]){
            dfs(i, visited, adj);
        }
    }
    return 0;
}