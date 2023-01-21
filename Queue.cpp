// Queue: Operations Implementation

#include <iostream>
#include <stdlib.h>
#include <exception>
using namespace std;

class Queue{
	int* arr;
	int front;
	int back;
	int size;
	
	public:
		Queue(){
			cout << "Enter size of the Queue: ";
			cin  >> size;
			
			arr = new int[size];
			front = -1;
			back  = -1;		
		}
		
		void enqueue(int x){
			if(back == size-1){
				cout << "Queue is OverFlow!\n";
				return;
			}
			back++;
			arr[back] = x;
			if(front == -1){
				front++;
			}
		}
		
		void dequeue(){
			if(front==-1 || front>back){
				cout << "Queue is UnderFlow!\n";
				return;
			}
			front++;
		}
		
		int peek(){
			if(front==-1 || front>back){
				cout << "No element present in the Queue.\n";
				return -1;
			}
			return arr[front];
		}
		
		bool empty(){
			if(front==-1 || front>back){
				return true;
			}
			return false;
		}
};

int main(){
	Queue q;
	
	while(true){
		cout << "OPERATIONS: \n1. enqueue()\n2. dequeue()\n3. peek()\n4. empty()\n5. exit()\n";
		
		int choice;
		cout << "Enter your choice: ";
		cin  >> choice;
		
		if(choice == 1){
			int x;
			cout << "Enter the value: ";
			cin  >> x;
			q.enqueue(x);	
		}
		else if(choice == 2){
			q.dequeue();
		}
		else if(choice == 3){
			cout << q.peek()  << endl ;
		}
		else if(choice = 4){
			cout << q.empty() << endl;
		}
		else if(choice == 5){
			exit(0);
		}
		else{
			cout << "Invalid choice!\n";
		}
	}
	
}
