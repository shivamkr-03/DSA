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
    cout << root -> data << endl;
    if(root -> left != NULL)
    bfs(root -> left);
    if(root -> right != NULL)

    bfs(root -> right);
}
int main(){

    struct node* root = new node(1);
    root -> left = new node(2);
    root -> right = new node(3);                   
    bfs(root);
    return 0;
}