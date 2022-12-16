#include<bits/stdc++.h>

using namespace std;


struct node {
    int data;
    struct node* left;
    struct node* right;
    
    node(int val){
        data = val;
        left = right = NULL;
    }
};
void bfs(struct node *root) {

    if(root == NULL) return;

    queue<struct node*> q;
    q.push(root);
    cout << "bfs traversal of the tree: ";

    while(!q.empty()){
        struct node* n = q.front();
        cout << n -> data << " ";
        if(n -> left != NULL) q.push(n -> left);
        if(n -> right != NULL) q.push(n -> right);
        q.pop();
    }
}
int main(){

    struct node* root = new node(1);
    root -> left = new node(2);
    root -> right = new node(3);

    root -> left -> left = new node(4);
    root -> left -> right = new node(5);

    root -> right -> left = new node(6);
    root -> right -> right = new node(7);                   


    bfs(root);
    return 0;
}