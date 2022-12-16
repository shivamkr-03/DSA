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

// Driver's code
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

	head->data = 1; // assign data in first node
	head->next = second; // Link first node with
	// assign data to second node
	second->data = 2;

	// Link second node with the third node
	second->next = third;

	

	third->data = 3; // assign data to third node
	third->next = NULL;
	struct Node* temp = head;

	while(temp != NULL){
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << endl;

	struct Node* prev = NULL;

	struct Node* curr = head;
	struct Node* nxt;

	while(curr != NULL){
		nxt = curr -> next;    		
		curr -> next = prev;
		prev = curr;
		curr = nxt;
	}
	

	temp = prev;
	while(temp != NULL){
		cout << temp -> data << " ";
		temp = temp -> next;

	}
	cout << endl;
	cout << "the end";

	return 0;
}
