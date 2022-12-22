#include<bits/stdc++.h>

using namespace std;
// for doing first dfs traversal and store the nodes in stack
void dfs(int node, vector<int> adj[], vector<bool>& visited, stack<int>& stk){
    visited[node] = true;
    for(int i: adj[node]){
        if(!visited[i]){
            dfs(i, adj, visited, stk);
        }
    }
    stk.push(node);
}
// for the reversed edges traversals
void dfs2(int node, vector<int> adj[], vector<bool>& visited, vector<int>& temp){
    visited[node] = true;
    for(int i: adj[node]){
        if(!visited[i]){
            dfs2(i, adj, visited, temp);
        }
    }
    temp.push_back(node);
}
void kosaraju(vector<int> adj[], int n){
    vector<bool> visited(n);
    stack<int> stk;
    // perform the dfs
    for(int i = 0; i < n; ++ i){
        if(!visited[i]){
            dfs(i, adj, visited, stk);
        }
    }
    // transpose the graph(reverse the edges) and also reset the visited array
    vector<int> rev_adj[n];
    for(int i = 0; i < n; ++i){
        visited[i] = false;
        for(int j: adj[i]){
            rev_adj[j].push_back(i);
        }
    }
    // perform dfs on the stack nodes
    int scc = 0;
    vector<vector<int>> sccs;
    
    while(!stk.empty()){
        int node = stk.top(); stk.pop();
        vector<int> temp;
        if(!visited[node]){
            dfs2(node, rev_adj, visited, temp);
            ++scc;
            sccs.push_back(temp);

        }
    }
    cout << "no of scc: " << scc << endl;
    cout << "sccs:\n";
    for(auto i: sccs){
        for(int j: i){
            cout << j << " ";
        }
        cout << endl;
    }


}

int main(){
    int n = 5;
    vector<int> adj[n];
    adj[0] = {2, 3};
    adj[1] = {0};
    adj[2] = {1};
    adj[3] = {4};
    adj[4] = {};
    kosaraju(adj, n);
    return 0;
}

// output 3
// 0,1,2
// 3
// 4
