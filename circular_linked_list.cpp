// Circular Linked List

#include <iostream>
using namespace std;

class node{
	public:
		node* next;
		int data;
		
		node(int val){
			data = val;
			next = NULL;
		}
};

void insert_at_head(node* &head, int val){
	node* n = new node(val);
	
	if(head == NULL){
		n->next = n;
		head    = n;
		return;	
	}
	
	node* temp = head;
	while(temp->next!=head){
		temp = temp->next;
	}
	
	temp->next = n;
	n->next    = head;
	head       = n;
}

void insert_at_tail(node* &head, int val){
	node* n = new node(val);
	
	if(head==NULL){
		insert_at_head(head, val);
		return;
	}
	
	node* temp = head;
	while(temp->next!=head){
		temp = temp->next;
	}
	
	temp->next = n;
	n->next    = head;
}

void delete_from_head(node* &head){
	node* temp = head;
	
	while(temp->next!=head){
		temp = temp->next;
	}
	
	node* to_delete = head;
	temp->next = head->next;
	head       = head->next;
	
	delete to_delete;
}

void deletion(node* &head, int pos){
	node* temp = head;
	
	if(pos==1){
		delete_from_head(head);
		return;
	}
	
	int count = 1;
	while(count!=pos-1){
		temp = temp->next;
		count++;
	}
	
	node* to_delete = temp->next;
	temp->next = temp->next->next;
	
	delete to_delete;
}

void display(node* head){
	node* temp = head;
	
	do{
		cout << temp->data << " " ;
		temp = temp->next;
	}while(temp!=head);
	cout << endl;
}

int main(){
	node* head = NULL;
	
	insert_at_tail(head, 6);
	insert_at_tail(head, 5);
	insert_at_tail(head, 4);
	insert_at_head(head, 3);
	insert_at_head(head, 2);
	
	display(head);
	
	delete_from_head(head);
	display(head);
	
	deletion(head, 2);
	display(head);	
}
