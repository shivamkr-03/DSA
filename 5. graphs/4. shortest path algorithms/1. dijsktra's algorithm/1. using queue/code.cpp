#include<bits/stdc++.h>

using namespace std;


void dj_algo(vector<pair<int, int>> adj[], int n) {
    // initilize distance vector;
    //  IT REPRESENTS SHORTEST DISTANCE FROM "FIRST NODE" TO ALL THE "OTHER NODES" dist[node];
    vector<int> dist(n, INT_MAX);



    queue< pair<int, int> > q;
    
    // the distance that will take to travel to first node from first node is 0 so:
    // 1. mark distance as 0
    dist[0] = 0;
    // 2. insert first node to initiate the process
    q.push({dist[0], 0});
    
    // as long as there are nodes in queue
    while(!q.empty()){

        // take out the front node
        pair<int, int> node = q.front(); q.pop();

        int distance = node.first;
        int u = node.second;
        // traverse all its adjacent nodes and check if any shortest path possible
        for(auto i: adj[u]){
            // destination node
            int destination = i.second;

            // total_distance = distance to travel from present node(u) to the destination node(destination);
            int total_distance = distance + i.first;
            
            // if total_distance is shorter than the current distance that takes to travel to destination:
            if(total_distance < dist[destination]){
            //  1. update the distance of that node
                dist[destination] = total_distance;
            //  2. push the updated node to the priority queue -> to check if there is any other shorter route available  
                q.push({dist[destination], destination});
            }
        }
        
    }
    cout << "\noutput: ";
    for(int i: dist){
        cout << i << " ";
    }


}




int main(){
    int n = 9;
    vector<pair<int, int>> adj[n];
    // graph representation in adjacency list {d, v} where:
    // d = distance or weight
    // v = destination vertix

    adj[0] = {{4, 1}, {8, 7}};
    adj[1] = {{4, 0}, {11, 7}, {8, 2}};
    adj[2] = {{8, 1}, {7, 3}, {2, 8}, {4, 5}};
    adj[3] = {{7, 2}, {9, 4}, {14, 5}};
    adj[4] = {{9, 3}, {10, 5}};
    adj[5] = {{14, 3}, {10, 4}, {2, 6}};
    adj[6] = {{2, 5}, {1, 7}, {6, 8}};
    adj[7] = {{8, 0}, {1, 6}, {11, 1}, {7, 8}};
    adj[8] = {{2, 2}, {7, 7}, {6, 6}};

    dj_algo(adj, n);

    return 0;
}

// Output: 0 4 12 19 21 11 9 8 14
// Explanation: The distance from 0 to 1 = 4.
// The minimum distance from 0 to 2 = 12. 0->1->2
// The minimum distance from 0 to 3 = 19. 0->1->2->3
// The minimum distance from 0 to 4 = 21. 0->7->6->5->4
// The minimum distance from 0 to 5 = 11. 0->7->6->5
// The minimum distance from 0 to 6 = 9. 0->7->6
// The minimum distance from 0 to 7 = 8. 0->7
// The minimum distance from 0 to 8 = 14. 0->1->2->8