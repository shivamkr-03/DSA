#include <bits/stdc++.h>
using namespace std;
void solve();
void init(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

// C program to implement a
// linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};



struct Node* reverse(struct Node* node, struct Node* head=NULL){
    
    if(node -> next == NULL){
        head = node;
        return head;
    }
    head = reverse(node -> next, head);

    node -> next -> next = node;
    node -> next = NULL;
    return head;
}


int main()
{
	// init();
	struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;

	// allocate 3 nodes in the heap
	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));

	head->data = 1;
	head->next = second;
	second->data = 2;
	second->next = third;
	third->data = 3; 
	third->next = NULL;
	struct Node* temp = head;

	while(temp != NULL){
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << endl;

	temp = reverse(head);
	while(temp != NULL){
		cout << temp -> data << " ";
		temp = temp -> next;

	}
	cout << endl;
	cout << "the end";

	return 0;
}
