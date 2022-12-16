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
void iterative_inorder(struct node *root) {

    stack<struct node*> stk;
    node *curr = root;

     while (curr != NULL || stk.empty() == false)
    {
        while (curr !=  NULL)
        {
            stk.push(curr);
            curr = curr->left;
        }
 
        curr = stk.top();
        stk.pop();
 
        cout << curr->data << " ";
 
        curr = curr->right;
 
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


    iterative_inorder(root);
    return 0;
}