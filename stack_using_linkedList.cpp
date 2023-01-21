//Program 7: Implement a stack using Linked list representation

#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node* next;

		Node(int n)
		{
			this->data = n;
			this->next = NULL;
		}
};

class Stack {
	Node* top;

	public:
		Stack() 
		{
			top = NULL; 
		}

		void push(int data)
		{
			Node* temp = new Node(data);			
			temp->data = data;	
			if (top==NULL){
				temp-> next=NULL;
			}
			else {
				temp->next = top;
			}
	
			top = temp;
			cout << "Element " << data << " pushed in the stack." << endl;
		}

		
		void pop()
		{	
			if (top == NULL) {
				cout << "\nStack Underflow" << endl;
			}
			else {
				Node* temp;
				temp = top;
				top = top->next;
				delete(temp);
			}
		}
	

		bool empty()
		{
			if (top == NULL){
				cout << "The Stack is Empty." << endl;
			}
			else {
				cout << "The Stack is NOT Empty." << endl;
			}
		}

	
		int peek()
		{
			if (top !=NULL){
				cout << "Top element in the stack" << endl;
				return top->data;
			}

			else{
				cout << "No element to access." << endl;
				return -1;
			}
		}


		void display()
		{
			Node* temp;
	
			if (top == NULL) {
				cout << "\nStack Underflow!" << endl;
			}
			else {
				temp = top;
				while (temp->next != NULL) {
					cout << temp->data <<"->";
					temp = temp->next;
				}
				cout << temp->data << "-> NULL" << endl;
			}
		}
};


int main()
{
	Stack st;
	char ans = 'y';
	while(ans=='y' or ans == 'Y'){
		cout << endl << "-----------------------------------";
		cout << endl << "  STACK : LINKED LIST IMPLEMENTION ";	
		cout << endl << "-----------------------------------";		
		cout << endl << "OPERATIONS:\n1. push()\n2. pop()\n3. top()\n4. empty()\n5. Exit\n";
		
		int choice;
		cout << endl << "Enter your choice: ";
		cin  >> choice;
		
		if(choice == 1){
			int data;
			cout << "Enter the value: ";
			cin  >> data;
			st.push(data);
			st.display();
		}
		
		else if(choice == 2){
			st.pop();
			st.display();
		}
		
		else if(choice == 3){
			cout << st.peek() << endl;
		}
		
		else if(choice == 4){
			st.empty();
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


