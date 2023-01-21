//Stack: Array implementation

#include <iostream>
#include <stdlib.h>
using namespace std;

class Stack{
	
	int* arr;
	int top;
	int n;
	
	public:
		Stack(){
			cout << "Enter size of the stack: ";
			cin  >> n; 
			arr = new int[n];
			top = -1;
		}
		
		void push(int x){
			if(top == n-1){
				cout << "Stack Overflow!" << endl;
			}
			top++;
			arr[top]=x;
			
		}
		
		void pop(){
			if(top == -1){
				cout << "Stack Underflow!" << endl;
				return;
			}
			top--;
		}
		
		int Top(){
			if(top == -1){
				cout << "No element to access!\n";
				return -1;
		    }
		    return arr[top];
		}
		
		bool empty(){
			if(top == -1){
				return true;
			}
			return false;
		}

};


int main(){

	Stack st;
	
	while(true){
		
		cout << "OPERATION:\n1. push()\n2. pop()\n3. top()\n4. empty()\n5. exit\n";
		
		int choice;
		cout << "Enter your choice: ";
		cin  >> choice;
		
		if(choice == 1){
			int x;
			cout << "Enter the value: ";
			cin  >> x;
			st.push(x);
		}
		
		else if(choice == 2){
			st.pop();
		}
		
		else if(choice == 3){
			cout << st.Top() << endl;
		}
		
		else if(choice == 4){
			cout << st.empty() << endl;
		}
		
		else if(choice == 5){
			exit(0);
		}
		
		else{
			cout << "Invalid choice!" << endl;
		}
	}
}
