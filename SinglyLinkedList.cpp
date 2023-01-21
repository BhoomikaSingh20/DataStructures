//Program 3: To implement SLL and perform various operations on it

#include<iostream>
using namespace std;

class node{
	int data;
	node *next;
	public:
		friend class SLL;
		node(int val, node* ptr = 0)
		{
			data = val;
			next = ptr;
		}
};

class SLL{
	
	node* head;
	
	public: 
	SLL()
	{
		head = 0;
	}
	
	bool isempty()
	{
		return (head == 0);
	}
	//(i) insert element at beginning
	void addToHead(int val)
	{
		head = new node(val,head);
	}
	
	// (ii) insert an element at ith position
	void insertAt(int val, int i){
		node* ptr = head;
		int count = 0;
		while(ptr && count != i-1){
			ptr = ptr -> next;
			count++;
		}
		ptr->next = new node(val, ptr->next);
	}
	
	// (iii) remove an element from beginning
	int removeAtHead(){
		if(head){
			node* ptr = head;
			int val = ptr->data;
			head = head->next;
			delete ptr;
			return val;
		}
		else
			return 0;
	}
	
	//(iv) remove an element at ith position
	int removeAt(int i){
		int val;
		if(head){
		node* ptr = head;
		int count = 0;
		while(ptr && count != i-1){
			ptr = ptr->next;
			count++;
		}
			node* cur = ptr->next->next;
			delete ptr->next;
			ptr->next = cur;
			
			
		if(count<i-1){
				cout << "Position doesn't exist";
		}
	}
	return 0;
		
		
	}
	
	// (v) search an element
	
	node* search(int val)
	{
		node* ptr = head;
		
		while(ptr)
		{
			if(ptr->data==val)
			{
				return ptr;
			}
			
			ptr = ptr->next;
		}
		return 0;
	}
	
	//(vi) concatenate 2 SLLs
	void concatenate(SLL &l){
		if(!isempty())
		{
			node* ptr = head;
			while(ptr->next)
			{
				ptr = ptr->next;
			}
			ptr->next = l.head;
			l.head = 0;
		}
		else
		{
			head = l.head;
			l.head = 0;
		}
		
	}
	
	//display
	void display()
	{
		node *ptr = head;
		cout << "The List is: ";
		while(ptr)
		{
			cout << ptr->data << " ";
			ptr = ptr->next;
		}
		cout << endl << endl;
	}
	
	~SLL()
	{
		removeAtHead();
	}
};

int main(){
	SLL l,l1;
	int ch,el,i;
	node* x;
	char ans ='y';
	do
	
	{	
		cout << endl << "******* SINGLE LINKED LIST ********" << endl;	
		cout << endl << "-----------------------------------";		
		cout << endl << "            OPERATIONS             ";
		cout << endl << "-----------------------------------";	
		cout << endl << "1. Insert element at beginning";
		cout << endl << "2. Insert an element at ith position";
		cout << endl << "3. Remove an element from beginning ";
		cout << endl << "4. Remove an element at ith position";
		cout << endl << "5. Search an element";
		cout << endl << "6. Concatenate two SLLs";
		cout << endl << "7. Exit ";
		
		cout << endl << endl << "Enter your choice: ";
		cin  >> ch;
		
		switch(ch)
		{
			
			case 1: cout << endl << "Enter the element to be inserted: ";
					cin  >> el;
					l.addToHead(el);
					l.display();
					break;
			case 2: cout << endl << "Enter the element to be inserted: ";
					cin  >> el;
					cout << endl << "Enter its position: ";
					cin  >> i;
					l.insertAt(el,i);
					l.display();
					break;
			case 3: cout << endl << "The element removed is: "<<l.removeAtHead() << endl;
					l.display();
					break;
			case 4: cout << endl << "Enter the position from where the element should be removed: ";
					cin  >> i;
					l.removeAt(i);
					l.display();
					break;
			case 5: cout << endl << "Enter the element to be searched: ";
					cin  >> el;
					x = l.search(el);
					if(x == 0){
						cout << endl << "Element not found." << endl;
					}
					else
						cout << "Element is at ->" << x << endl;
					break;
			case 6: cout << endl << "Enter number of elements in new list: ";
					cin  >> i;
					
					if(i)
					{
						cout<<"Enter elements: ";
						for(int j = 0; j < i; j++)
						{
							cin >> el;
							l1.addToHead(el);
						}
						l.concatenate(l1);
					}
					cout << endl;
					l.display();
					break;
			case 7: exit(0); break;
			
			default: cout << endl << "Invalid choice!!" << endl;
				break;		
		}
		cout << "\nWant to continue?(y/n) ";
		cin  >> ans;
	}while(ans=='y' or ans == 'Y');
	
	return 0;	
}




