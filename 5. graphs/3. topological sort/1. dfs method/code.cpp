#include<bits/stdc++.h>

using namespace std;

void dfs(int root, vector<bool>& visited, vector<int> adj[], stack<int>& stk){
    
    visited[root] = true;

    for(int i: adj[root]){
        if(!visited[i]){
            dfs(i, visited, adj, stk);
        }
    }
    stk.push(root);
}


int main(){
    int n = 5;
    vector<int> adj[n];
    adj[0] = {1, 3};
    adj[1] = {2, 3};
    adj[2] = {};
    adj[3] = {2, 4};
    adj[4] = {};
    
    vector<bool> visited(n);
    stack<int> stk;
    for(int i = 0; i < n; ++ i){
        
        if(!visited[i]){
            dfs(i, visited, adj, stk);
        }
    }
    // print topological sort

    while(!stk.empty()){
        cout << stk.top() << " "; stk.pop();
    }
    return 0;
}