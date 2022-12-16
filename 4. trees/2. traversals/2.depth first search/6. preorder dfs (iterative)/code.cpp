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
void iterative_preorder(struct node *root) {

    stack<struct node*> stk;
    stk.push(root);
    // as the order is root left right first we pushed the root

    while(!stk.empty()){
        
        struct node* temp = stk.top(); stk.pop();
        cout << temp -> data << " ";
        if(temp -> right != NULL) stk.push(temp -> right);
        if(temp -> left != NULL) stk.push(temp -> left);            

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


    iterative_preorder(root);
    return 0;
}