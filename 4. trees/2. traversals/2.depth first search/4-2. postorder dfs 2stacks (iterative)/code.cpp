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
void iterative_postorder(struct node *root) {

    stack<struct node*> stack1, stack2;
    node *curr = root;
    // push root to stack 1
    stack1.push(root);
    // as long as stack1 is not empty:
    while(!stack1.empty()){
        // pop the stack
        node *temp = stack1.top(); stack1.pop();
        
        // push popped node to the 2nd stack
        stack2.push(temp);
        // add left and right childern of popped node
        if(temp -> left) stack1.push(temp -> left);
        if(temp -> right) stack1.push(temp -> right);
    }
    // print stack2

    while(!stack2.empty()){
        cout << stack2.top() -> data << " "; stack2.pop();
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


    iterative_postorder(root);
    return 0;
}