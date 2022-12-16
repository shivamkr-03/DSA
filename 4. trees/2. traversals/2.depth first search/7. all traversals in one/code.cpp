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
void iterative_all(struct node *root) {

    stack<pair<struct node*, int>> stk;
    vector<int> preorder, inorder, postorder;
    stk.push({root, 1});
    while(!stk.empty()){
        auto it = stk.top(); stk.pop();
        // if it.second == 1 it belongs to pre order
        if(it.second == 1){
            preorder.push_back(it.first -> data);
            ++ it.second;
            stk.push(it);
            if(it.first -> left != NULL){
                stk.push({it.first -> left, 1});
            }
        }
        else if(it.second == 2){
            inorder.push_back(it.first -> data);
            ++ it.second;
            stk.push(it);
            if(it.first -> right != NULL){
                stk.push({it.first -> right, 1});
            }
        }
        else {
            postorder.push_back(it.first -> data);
        }
    }
    cout << "preorder: ";
    for(auto i: preorder){
        cout << i << " ";
    }
    cout << endl;

    cout << "inorder: ";
    for(auto i: inorder){
        cout << i << " ";
    }
    cout << endl;
    
    cout << "postorder: ";
    for(auto i: postorder){
        cout << i << " ";
    }
    cout << endl;
    
}
int main(){

    struct node* root = new node(1);
    root -> left = new node(2);
    root -> right = new node(3);

    root -> left -> left = new node(4);
    root -> left -> right = new node(5);

    root -> right -> left = new node(6);
    root -> right -> right = new node(7);                   


    iterative_all(root);
    return 0;
}