#include<bits/stdc++.h>

using namespace std;
// same as dfs
int timer = 1;
int articulation = 0;
vector<int> articulations;
int dfs(int u, int parent, vector<int> adj[], vector<bool>& visited, vector<int>& tin, vector<int>& low){
    // mark the U as visited
    int childern = 0;

    visited[u] = true;
    // mark time of insertion and low time of the U which are same at the beginning
    tin[u] = low[u] = timer;
    //  increase the timer;
    ++ timer;
    // now traverse the U adjacent nodes
    for(int v: adj[u]){
        // if the V is parent U we dont need to do anything as it would have already visited
        if(v == parent) continue;
        // if V is not visited then call dfs for V 
        if(!visited[v]){
            ++ childern;
            dfs(v, u, adj, visited, tin, low); 
            // after coming back:
            // if tin of the  U is less than the lowest time of V, V cannot go further U without UV, 
            // so UV is a articulation add it to the articulations and count articulation 
            if(tin[u] <= low[v]){
                ++articulation;
                articulations.push_back(u);
            }
            // update the low of U
            low[u] = min(low[u], low[v]);
        }
        // if the V is already visited update U low with the in time of the v node as all the nodes are visited
        else{
            low[u] = min(low[u], tin[v]);

        }
    }
    return childern;
}

int main(){
    int n = 12;
    vector<int> adj[n];
    adj[0] = {1, 3};
    adj[1] = {0, 2};
    adj[2] = {3, 1};
    adj[3] = {0, 2, 4};
    adj[4] = {3, 5};
    adj[5] = {4, 6, 8};
    adj[6] = {5, 7};
    adj[7] = {6, 8, 9};
    adj[8] = {5, 7};
    adj[9] = {7, 10, 11};
    adj[10] = {9, 11};
    adj[11] = {9, 10};
    vector<int> tin(n), low(n);
    vector<bool> visited(n);
    for(int i = 0; i < n; ++ i){
        if(!visited[i]){
            int childern = dfs(i, -1, adj, visited, tin, low);
            if(childern > 1){
                ++ articulation;
                articulations.push_back(i);
            }
        }
    }
    cout << "no of articulations: " << articulation << endl;
    cout << "brigde edges:\n";
    for(auto i: articulations){
        cout << i << endl;
    }
    return 0;
}

// output 3
// 3, 4
// 4, 5
// 7, 9
/*

        0 -- 1
        |    |
        3 -- 2
        |
        4 --  5
            /   \
           6     8
            \   /
              7
            /   \
           11 -- 10


*/
