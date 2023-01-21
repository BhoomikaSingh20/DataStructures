// Queue Using Stack

#include <iostream>
#include <stack>
using namespace std;

class queue_using_stack{
	stack<int> st1;
	stack<int> st2;

	public:
		void enqueue(int x){
			st1.push(x);
		}
		
//		int dequeue(){                                //method 1: not working
//			if(st1.empty()){
//				cout << "Queue is UnderFlow!\n";
//				return -1;
//			}
//			int x = st1.top();
//			st1.pop();
//			if(st1.empty()){
//				return x;
//			}
//			int pop_value = st1.top();
//			st1.pop();
//			st1.push(x);
//			return pop_value;
//		}

		int dequeue(){                                //method 2
			if(st1.empty() and st2.empty()){
				cout << "Queue is UnderFlow!\n";
				return -1;
			}			
			if(st2.empty()){
				while(!st1.empty()){
					st2.push(st1.top());
					st1.pop();
				}
			}
			int top_value = st2.top();
			st2.pop();
			return top_value;
		}
			
		int peek(){
			if(st1.empty() and st2.empty()){
				cout << "No element to access.\n";
				return -1;
			}
			if(st2.empty()){
				while(!st1.empty()){
				st2.push(st1.top());
				st1.pop();
				}
			}
			
			return st2.top();
		}
		
		bool empty(){
			if(st1.empty() && st2.empty()){
			//if(st1.empty()){
				return true;
			}
			return false;
		}
};

int main(){
	queue_using_stack qs;
	
	cout << qs.empty() << endl;
	
	qs.enqueue(4);
	qs.enqueue(5);
	qs.enqueue(1);
	qs.enqueue(6);
	
	cout << qs.peek() << endl;
	
	cout << qs.dequeue() << endl;
	
	cout << qs.peek() << endl;
	
	cout << qs.dequeue() << endl;
	cout << qs.dequeue() << endl;
//	cout << qs.dequeue() << endl;
//	cout << qs.dequeue() << endl;
//	cout << qs.peek() << endl;
	
	cout << qs.empty() << endl;
	 

}
