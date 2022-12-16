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

    stack<struct node*> stk;
    
    struct node *current = root;
    
    while(current != NULL or !stk.empty()) {
        
        if(current != NULL){
            stk.push(current);
            current = current -> left;
        }
        
        else {

            struct node *prev = stk.top()-> right;
            // if the prev is null then the node is root node hence print it
            if(prev == NULL){
                prev = stk.top(); stk.pop();

                cout << prev -> data << " ";
                // as long as the previously printed node is right of top node pop the top node from the stack
                while(!stk.empty() and prev == stk.top() -> right){
                    
                    prev = stk.top(); stk.pop();
                    cout <<  prev -> data << " ";
                }
            }
            // else go to right of the top node from the stack
            else{
                current = prev; 
            }
            
            
        }
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