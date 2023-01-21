// Linked List

#include <iostream>
#include <stdlib.h>
using namespace std;

class node{
	public:
		int data;
		node* next;
		
		node(int val){
			data = val;
			next = NULL;
		}
};

void insert_at_tail(node* &head, int val){
	node* n = new node(val);
	
	if(head == NULL){
		head = n;
		return;
	}
	
	node* temp = head;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	
	temp->next = n;
}

void insert_at_head(node* &head, int val){
	node* n = new node(val);
	n->next = head;
	head = n;
}

void delete_from_head(node* &head){
	node* todelete = head;
	head = head->next;
	
	delete todelete;
}

void deletion(node* &head, int val){
	node* n = new node(val);
	
	
	if(head==NULL){
		return;
	}
	if(head->next==NULL){
		delete_from_head(head);
		return;
	}
	
	node* temp = head;
	while(temp->next->data!=val){
		temp = temp->next;
	}
	
	node* todelete = temp->next;
	temp->next = temp->next->next;
	delete todelete;
}

void display(node* head){
	node* temp = head;
	
	while(temp!=NULL){
		cout << temp->data << "->" ;
		temp = temp->next;
	}cout << "NULL" << endl;
}

bool search(node* &head, int key){
	node* n = new node(key);
	node* temp = head;
	
	while(temp->next!=NULL){
		if(temp->data==key){
			return true;
		}
		temp = temp->next;
	}
	return false;
}

node* iterative_reverse(node* &head){        //method 1: iterative approach
	node* previous_ptr = NULL;
	node* current_ptr  = head;
	node* next_ptr;
	
	while(current_ptr!=NULL){
		next_ptr          = current_ptr->next;
		current_ptr->next = previous_ptr;
		
		previous_ptr = current_ptr;
		current_ptr  = next_ptr; 
	}
	
	return previous_ptr;
}

node* recursive_reverse(node* &head){        //method 2: Recursive call - not working properly
	if(head==NULL || head->next==NULL){
		return head;
	}
	
	node* newhead = recursive_reverse(head->next);
	
	head->next->next = head->next;
	head->next       = NULL;
	
	return newhead;
}

node* reverse_k(node* &head, int k){      //output not correct 
	node* previous_ptr = NULL;
	node* current_ptr  = head;
	node* next_ptr;
	
	if(head==NULL || head->next==NULL){
		return head;
	}
	
	int count = 0;
	while(current_ptr!=NULL && count<k){
		next_ptr          = current_ptr->next;
		current_ptr->next = previous_ptr;
		previous_ptr      = current_ptr;
		current_ptr       = next_ptr;
		count++;
	}
	
	if(next_ptr!=NULL){
		head->next = reverse_k(next_ptr, k);
	}
	
	return previous_ptr;
}

int main(){
	
	node* head = NULL;
	
	cout << "INSERTING VALUES AT TAIL AND DISPLAYING THE LINKED LIST: \n";
	insert_at_tail(head, 4);
	insert_at_tail(head, 5);
	insert_at_tail(head, 8);
	insert_at_tail(head, 9);
	display(head);
	cout << endl;
	
	cout << "INSERTING VALUE AT HEAD AND DISPLAYING THE LINKED LIST: \n";
	insert_at_head(head, 1);
	display(head);
	cout << endl;
	
	cout << "DELETING VALUES AND DISPLAYING THE LINKED LIST: \n";
	deletion(head, 5);
	deletion(head, 9);
	display(head);
	cout << endl;
	
	cout << "DELETING VALUE FROM HEAD AND DISPLAYING THE LINKED LIST: \n";
	delete_from_head(head);
	display(head);
	cout << endl;
	
	cout << "SEARCHING VALUES AND DISPLAYING THE LINKED LIST: \n";
	cout << search(head, 4) << endl;
	cout << search(head, 5) << endl;
	cout << endl;
	
	cout << "REVERSING AND DISPLAYING THE LINKED LIST USING ITERATIVE METHOD: \n";
	node* newhead = iterative_reverse(head);
	display(newhead);
	cout << endl;
	
	cout << "INSERTING VALUE AT TAIL AND HEAD AND DISPLAYING THE LINKED LIST: \n";
	insert_at_tail(head, 2);
	insert_at_head(head, 5);
	display(head);
	cout << endl;
	
	cout << "AGAIN REVERSING AND DISPLAYING THE LINKED LIST USING ITERATIVE METHOD: \n";
	node* newhead2 = iterative_reverse(head);
	display(newhead2);
	cout << endl;
	
	cout << "INSERTING VALUE AT HEAD AND TAIL AND DISPLAYING THE LINKED LIST: \n";
	insert_at_head(head, 1);
	insert_at_tail(head, 0);
	display(head);
	cout << endl;	
	
//	cout << "REVERSING AND DISPLAYING THE LINKED LIST USING RECURSIVE METHOD: \n";
//	node* newhead3 = recursive_reverse(head);
//	display(newhead3);
//	cout << endl;
	
	cout << "INSERTING VALUES AT TAIL AND DISPLAYING THE LINKED LIST: \n";
	insert_at_tail(head, 1);
	insert_at_tail(head, 2);
	insert_at_tail(head, 3);
	display(head);
	cout << endl;
	
	cout << "REVERSING K NUMBER OF NODES AND DISPLAYING THE LINKED LIST: \n ";
	node* newhead4 = reverse_k(head, 3);
	display(newhead4);
	cout << endl;
}


















//int main(){
//	 node* head = NULL;
//	 
//	while(true){
//		cout << "OPERATIONS: \n1. insert_at_tail()\n2. insert_at_head()\n3. delete_form_head()\n4. deletion()\n5. search()\n6. display()\n7. exit()";
//		
//		int choice;
//		cout << "\nEnter your choice: ";
//		cin  >> choice;
//		
//		if(choice == 1){
//			int val;
//			cout << "Enter the value: ";
//			cin  >> val;
//			insert_at_tail(head, val);	
//		}
//		else if(choice == 2){
//			int val;
//			cout << "Enter the value: ";
//			cin  >> val;
//			insert_at_head(head, val);
//		}
//		else if(choice == 3){
//			int val;
//			cout << "Enter the value: ";
//			cin  >> val;
//			delete_from_head(head, val);
//		}
//		else if(choice = 4){
//			int val;
//			cout << "Enter the value: ";
//			cin  >> val;
//			deletion(head, val);
//		}
//		else if(choice == 5){
//			int val;
//			cout << "Enter the value: ";
//			cin  >> val;
//			search(head, val);
//		}
//		else if(choice == 6){
//			
//			display(head);
//		}
//		else if(choice == 7){
//			exit(0);
//		}
//		else{
//			cout << "Invalid choice!\n";
//		}
//	}
//	
//}
