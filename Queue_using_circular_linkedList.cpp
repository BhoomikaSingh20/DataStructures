//Program 10: Implement a Double ended queue using Linked list representation

#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node *prev, *next;
};

Node* createnode(int data){
	Node *temp = new Node();
	temp -> data = data;
	temp -> prev = NULL;
	temp -> next = NULL;
	return temp;
}

class DEQueue{
	Node* front, *back;
	int size;

	public:
		DEQueue() 
		{
			front = NULL;
			back  = NULL; 
			size  = 0;
		}
		
		void enqueueAtFront(int data){
		Node *temp = createnode(data);
		if (temp == NULL){
			back = front = temp;
		}
		else{
			if (front == NULL){
				back = front = temp;
			}
			else{
				temp  -> next = front;
				front -> prev = temp;
				front = temp;
			}
			cout << "Element enqueued at Front.";
			size++;
		}
	}
	
	void enqueueAtBack(int data){
		Node* temp = createnode(data);
		if (temp == NULL){
			cout << "Queue Overflow\n";
		}
		else
		{
			if (back == NULL){
				front = back = temp;
			}
			else{
				temp -> prev = back;
				back -> next = temp;
				back = temp;
			}
			cout << "Element enqueued at Back.";
			size++;
		}
	}
			
	void dequeueAtFront(){
		if (size == 0)
		{
			cout << "Queue Underflow!\n";
		}			
		else
		{
			Node* temp = front;
			front = front -> next;
				
			if (front == NULL){
				back = NULL;
			}
			else{
				front -> prev = NULL;
			}
			delete (temp);	
			cout << "Element dequeued from Front.";
			size--;
		}
	}
			
	void dequeueAtBack(){
		if (size == 0){
			cout << "Queue Underflow!\n";
		}	
		else
		{
			Node* temp = back;
			back = back -> prev;	
					
			if (back == NULL){
				front = NULL;
			}
			else{
				back -> next = NULL;
			}
			delete (temp);	
			cout << "Element dequeued from Back.";
			size--;
		}
	}
	void display()
	{
		Node* temp;
		if (front == NULL && back == NULL) {
			cout << "\nQueue is Underflow!" << endl;
		}
		else {
			temp = front;
			cout << endl << "Double Ended Queue: " << endl;
			while (temp != back) {
				cout << temp -> data <<" <=> ";
				temp = temp -> next;
			}
			cout << temp -> data << " " << endl;
		}
	}
		
};

	


int main()
{
	DEQueue dq;
	char ans = 'y';
	while(ans=='y' or ans == 'Y'){
		cout << endl << "------------------------------------------------";
		cout << endl << "  DOUBLE ENDED QUEUE : LINKED LIST IMPLEMENTION ";	
		cout << endl << "------------------------------------------------";		
		cout << endl << "OPERATIONS: \n1. enqueueAtFront()\n2. enqueueAtBack()\n3. dequeueAtFront()\n4. dequeueAtBack()\n5. Exit\n";

		int choice;
		cout << endl << "Enter your choice: ";
		cin  >> choice;
		
		if(choice == 1){
			int data;
			cout << "Enter the value: ";
			cin  >> data;
			dq.enqueueAtFront(data);
			cout << endl;
			dq.display();
		}
		
		else if(choice == 2){
			int data;
			cout << "Enter the value: ";
			cin  >> data;
			dq.enqueueAtBack(data);
			cout << endl;
			dq.display();
		}
		
		else if(choice == 3){
			dq.dequeueAtFront();
			cout << endl;
			dq.display();
		}
		
		else if(choice == 4){
			dq.dequeueAtBack();
			cout << endl;
			dq.display();
		}
		
		else if(choice == 5){
			exit(0);
		}
		
		else{
			cout << "Invalid choice!" << endl;
		}
		cout << "\nWant to continue?(y/n) ";
		cin  >> ans;
	}
	return 0;
}


