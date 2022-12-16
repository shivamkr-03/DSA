#include<bits/stdc++.h>

using namespace std;

void bfs(int root, vector<bool>& visited, vector<int> adj[]){
    queue<int> q;
    q.push(root);
    visited[root] = true;

    while(!q.empty()){
        int node = q.front(); q.pop();
        cout << node << " ";
        for(int i: adj[node]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
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
            bfs(i, visited, adj);
        }
    }
    return 0;
}