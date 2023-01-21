//Program 4: To implement DLL and perform various operations on it

#include<iostream>
using namespace std;

class node{
	int data;
	node *next;
	node *prev;
	public:
		friend class DLL;
		
		node()
		{
			next = 0;
			prev = 0;
		}
		
		node(int val, node* ptr=0, node* ctr=0)
		{
			data = val;
			next = ptr;
			prev = ctr;
		}
};

class DLL{
	
	node* header;
	node *trailer;
	
	public: 
	DLL()
	{
		header = new node();
		trailer = new node();
		header -> next = trailer;
		trailer -> prev = header;
	}
	
	void add(node* v, int el)
	{
		node* u = new node(el);
		u -> next = v;
		u -> prev = v -> prev;
		v -> prev -> next = u;
		v -> prev = u;
	}
	
	void remove(node* v)
	{
		node* u = v -> prev;
		node* w = v -> next;
		
		u -> next = w;
		w -> prev = u;
		delete v;	
	}
	
	bool isempty()
	{
		return(header->next==trailer);
	}
	
	//(i) insert element at beginning
	void addToHeader(int val)
	{
		add(header -> next, val);
	}
	
	// (ii) insert an element at ith position
	void insertAt(int val, int i)
	{
		node *ptr = header -> next;
		int count = 0;
		
		while(!isempty() && count!= i-1)
		{
				ptr = ptr -> next;
				count++;
		}
		
		add(ptr, val);
	}
	
	// (iii) insert an element at end
	void addToTrailer(int val)
	{
		add(trailer, val);
	}
	
	// (iv) remove an element from beginning
	void removeAtHeader()
	{	
		if(!isempty())
			remove(header->next);
	}
	
	
	//(v) remove an element at ith position
	void removeAt(int i)
	{
		node *ptr = header -> next;
		int count = 0;
		
		while(!isempty() && count!= i-1)
		{
				ptr = ptr -> next;
				count++;
		}
		
		remove(ptr);
	}

	// (vi) remove an element from the end
	void removeAtTrailer()
	{	
		if(!isempty())
			remove(trailer->prev);
	}
	
	// (vii) search an element
	
	node* search(int val)
	{
		node* ptr = header -> next;
		
		while(!isempty() && ptr!=trailer)
		{
			if(ptr->data==val)
			{
				return ptr;
			}
			
			ptr=ptr->next;
		}
		return 0;
	}
	
	//(viii) concatenate 2 DLLs
	void concatenate(DLL &l)
	{
		if(!isempty())
		{
			node* ptr = trailer-> prev;
			ptr->next = l.header->next;
			l.header->next->prev = ptr;
			l.trailer->prev->next = trailer;
			trailer->prev = l.trailer->prev;
			l.header->next=l.trailer;
			l.trailer->prev=l.header;
		}
		else
		{
			header=l.header;
			trailer=l.trailer;
			l.header->next=l.trailer;
			l.trailer->prev = l.header;
		}
		
	} 	
	int back()
	{
		return (trailer->prev->data);
	}
	int front()
	{
		return (header->next->data);
	}
	
	// display
	void display()
	{
		node *ptr = header->next;
		cout<<"The List is: ";
		while(ptr != trailer)
		{
			cout<<ptr->data<<" ";
			ptr=ptr->next;
		}
		cout<<endl<<endl;
	}
};

int main(){
	DLL l,l1;
	int ch,el,i;
	node* x;
	char ans = 'y';
	do
	
	{
		cout<<endl<<"******* DOUBLY LINKED LIST ********"<<endl;
		
		cout<<endl<<"-----------------------------------";		
		cout<<endl<<"            OPERATIONS             ";
		cout<<endl<<"-----------------------------------";	
		cout<<endl<<"1. Insert element at beginning";
		cout<<endl<<"2. Insert an element at ith position";
		cout<<endl<<"3. Insert an element at end";
		cout<<endl<<"4. Remove an element from beginning ";
		cout<<endl<<"5. Remove an element from ith position";
		cout<<endl<<"6. Remove an element from the end";
		cout<<endl<<"7. Search an element";
		cout<<endl<<"8. Concatenate two DLLs";
		cout<<endl<<"9. Exit ";
		
		cout<<endl<<endl<<"Enter your choice: ";
		cin>>ch;
		
		switch(ch)
		{
			
			case 1: cout<<endl<<"Enter the element to be inserted: ";
					cin>>el;
					l.addToHeader(el);
					l.display();
					break;
			case 2: cout<<endl<<"Enter the element to be inserted: ";
					cin>>el;
					cout<<endl<<"Enter its position: ";
					cin>>i;
					l.insertAt(el,i);
					l.display();
					break;
			case 3: cout<<endl<<"Enter the element to be inserted: ";
					cin>>el;
					l.addToTrailer(el);
					l.display();
					break;
			case 4: l.removeAtHeader();
					l.display();
					break;
			case 5: cout<<endl<<"Enter the position from where the element should be removed: ";
					cin>>i;
					l.removeAt(i);
					l.display();
					break;
			case 6: l.removeAtTrailer();
					l.display();
					break;
			case 7: cout<<endl<<"Enter the element to be searched: ";
					cin>>el;
					x=l.search(el);
					if(x==0){
						cout<<endl<<"Element not found."<<endl;
					}
					else
						cout<<"Element is at->"<<x<<endl;
					break;
			case 8: cout<<endl<<"Enter number of elements in new list: ";
					cin>>i;
					if(i)
					{
						cout<<"Enter elements: ";
						for(int j=0;j<i;j++)
						{
							cin>>el;
							l1.addToHeader(el);
						}
						l.concatenate(l1);
					}
					cout<<endl;
					l.display();
					break;
			case 9: exit(0); break;
			default: cout<<endl<<"Invalid choice!!"<<endl;
				break;
			
		}
		cout << "\nWant to continue?(y/n) ";
		cin  >> ans;
	}while(ans=='y' or ans == 'Y');
	
	return 0;
	
}




