//Revrse a Stack 

#include <iostream>
#include <stack>
using namespace std;

void insert_at_end(stack<int> &st, int element){
	if(st.empty()){
		st.push(element);
		return;
	}
	int top_element = st.top();
	st.pop();
	insert_at_end(st, element);
	st.push(top_element);
	
}

void reverse(stack<int> &st){
	if(st.empty()){
		return;
	}
	int element = st.top();
	st.pop();
	reverse(st);
	insert_at_end(st,element);
	return;
}

int main(){
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	
//	cout << "Original stack: ";
//	while(!st.empty()){
//		cout << st.top() << " ";
//		st.pop();
//	}cout << endl;
//	
	reverse(st);
	
	cout << "Reversed stack: ";
	while(!st.empty()){
		cout << st.top() << " ";
		st.pop();
	}
	return 0;
}
