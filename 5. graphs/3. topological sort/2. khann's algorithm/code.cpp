#include<bits/stdc++.h>

using namespace std;

void khanns(int n, vector<int> adj[]){

    vector<int> indegree(n);
    // calculate indegree
    for(int i = 0; i < n; ++ i){
        for(int j: adj[i]){
            ++ indegree[j];
        }
    }

    queue<int> q;
    for(int i = 0; i < n; ++ i){
        if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int node = q.front(); q.pop();
        cout << node << " ";

        for(int i: adj[node]){
            -- indegree[i];
            if(indegree[i] == 0) q.push(i);
        }
    }
    
}


int main(){
    int n = 5;
    vector<int> adj[n];
    adj[0] = {1, 3};
    adj[1] = {2, 3};
    adj[2] = {};
    adj[3] = {2, 4};
    adj[4] = {};

    khanns(n, adj);

    return 0;
}