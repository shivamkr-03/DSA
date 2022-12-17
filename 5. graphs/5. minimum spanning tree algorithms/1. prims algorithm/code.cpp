#include<bits/stdc++.h>

using namespace std;
void prims(vector<pair<int, int>> adj[], int n){

    vector<pair<int, int> > mst;
    vector<bool> visited(n);
    // we pass {weight, parent, child} into the priority queue
    priority_queue< vector<int>, vector<vector<int> >, greater<vector<int>>> pq;

    pq.push({0, -1, 0});
    int sum = 0;
    // while priority queue is not empty
    while(!pq.empty()){
        // pop the smallest distance node from the priority queue i.e top node
        auto node = pq.top(); pq.pop();
        //  node = {weight, parent, child}
        int weight = node[0];
        int parent = node[1];
        int child = node[2];
        // if the child node is visited already then continue
        if(visited[child]) continue;
        // else mark it as visited
        
        visited[child] = true;
        // if the parent -> "parent = -1"is not there dont add it to the mst else , add the node to the mst
        if(parent != -1){
            mst.push_back({parent, child});
            // increase the sum with the weight
            sum += weight;
        }
        

        // iterate through the adjacent nodes of the child
        for(auto i: adj[child]){
            
            int cost = i.first;
            int adjacent = i.second;
            // if the adjacent node is not visited add it to the priority queue
            if(!visited[adjacent])
                pq.push({cost, child, adjacent});
        }
    }
    cout << "total cost = " << sum << endl;
    printf("the mst:\n");
    for(auto i: mst){
        cout << i.first << " -> " << i.second << endl; 
    }


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
    
    prims(adj, n);
    return 0;
}