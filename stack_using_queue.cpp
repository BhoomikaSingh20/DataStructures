// Stack Using Queue

#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;

class stack_using_queue{
	queue<int> q1;
	queue<int> q2;
	
	public:
		void push(int x){
			q2.push(x);
			while(!q1.empty()){
				q2.push(q1.front());
				q1.pop();
			}
			
			queue<int> q;
			q1 = q2;
			q2 = q;
			q  = q1;
		}
		
		void pop(){
			if(q1.empty()){
				cout << "Stack is Underflow!\n";
				return;
			}
			q1.pop();
		}
		
		int Top(){
			if(q1.empty()){
				cout << "No elemnt to access!\n";
				return -1;
			}
			return q1.front();;
		}
};

int main(){
	stack_using_queue sq;
	
	sq.push(2);
	sq.push(4);
	sq.push(5);
	sq.push(3);
	
	cout << sq.Top() << endl;
	
	sq.pop();
	
	cout << sq.Top() << endl;
	
	sq.pop();
	sq.pop();
	sq.pop();
	
	cout << sq.Top() << endl;
		
}
