//Stack: Balanced Parenthesis

#include<iostream>
#include<stack>
using namespace std;

bool isvalid(string str){
	stack<char> st;
	
	for(int i=0; i<str.length(); i++){
		if(str[i]=='(' || str[i]=='{' || str[i]=='['){
			st.push(str[i]);
		}
		else if(str[i]==')' && !st.empty()){
			if(st.top()=='('){
				st.pop();
			}
		}
		else if(str[i]==']' && !st.empty()){
			if(st.top()=='['){
				st.pop();
			}
		}
		else if(str[i]=='}' && !st.empty()){
			if(st.top()=='{'){
				st.pop();
			}
		}
	}
	if(!st.empty()){
		return false;
	}
	return true;
}

int main(){
	bool flag=true;
	if(isvalid("({[})")){
		cout << "Valid String!" << endl;
	}
	else{
		cout << "Invalid String!" << endl;
	}
}
