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
struct Node {
	int data;
	struct Node* next;
};

void print_LL(struct Node* head){
    struct Node* temp = head;

	while(temp != NULL){
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << endl;
}


void remove_loop(struct Node* head){

    struct Node* slow = head, *fast = head;

    if(fast ->next -> next != NULL){
        slow = slow -> next;
        fast = fast ->next -> next;
    }
    while(fast -> next -> next != NULL){
        if(slow == fast)
        break;
        fast = fast ->next -> next;
        slow = slow -> next;
    }

    struct Node* slow2 = head, *prev;
    while(slow2 != slow){
        prev = slow;
        slow = slow ->next;
        slow2 = slow2 -> next;
    }
    printf("loop detected at %d\n", slow -> data);
    printf("removing loop... \n");
    prev -> next = NULL;



}


int main()
{
	// init();
	struct Node* head = NULL;
	struct Node* node2 = NULL;
	struct Node* node3 = NULL;
	struct Node* node4 = NULL;
	struct Node* node5 = NULL;
	struct Node* node6 = NULL;
	struct Node* node7 = NULL;
	struct Node* node8 = NULL;
	struct Node* node9 = NULL;



	// allocate 3 nodes in the heap
	head = (struct Node*)malloc(sizeof(struct Node));
	node2 = (struct Node*)malloc(sizeof(struct Node));
	node3 = (struct Node*)malloc(sizeof(struct Node));
	node4 = (struct Node*)malloc(sizeof(struct Node));
	node5 = (struct Node*)malloc(sizeof(struct Node));
	node6 = (struct Node*)malloc(sizeof(struct Node));
	node7 = (struct Node*)malloc(sizeof(struct Node));
	node8 = (struct Node*)malloc(sizeof(struct Node));
	node9 = (struct Node*)malloc(sizeof(struct Node));

	head->data = 1;
	head->next = node2;
	node2->data = 2;
	node2->next = node3;
	node3->data = 3; 
	node3->next = node4;
    node4->data = 4; 
	node4->next = node5;
    node5->data = 5; 
	node5->next = node6;
    node6->data = 6; 
	node6->next = node7;
	node7->data = 3; 
	node7->next = node8;
	node8->data = 8; 
	node8->next = node9;
	node9->data = 9; 
	node9->next = node3;

    remove_loop(head);

	print_LL(head);

	cout << "the end";

	return 0;
}
