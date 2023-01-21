//Stack: Infix to Postfix

#include<iostream>
#include<math.h>
#include<stack>
using namespace std;

int precedence(char c){
	if(c=='^'){
		return 3;
	}
	else if (c=='*' || c=='/'){
		return 2;
	}
	else if(c=='+' || c=='-'){
		return 1;
	}
	else{
		return -1;
	}
}

string infix_to_postfix(string str){
	stack<char> st;
	string result="";
	
	for (int i=0; i<str.length(); i++){
		if(str[i]>='a'&&str[i]<='z' || str[i]>='A'&&str[i]<='Z'){
			result+=str[i];
		}
		else if(str[i]=='('){
			st.push(str[i]);
		}
		else if(str[i]==')'){
			while(!st.empty() && st.top()!='('){
				result+=st.top();
				st.pop();
			}	
			if(!st.empty()){
				st.pop();
			}	
		}
		else{
			while(!st.empty() && precedence(st.top())>precedence(str[i])){
				result+=st.top();
				st.pop();
			}
			st.push(str[i]);
		}	

	}
	while (!st.empty()){
		result+=st.top();
		st.pop();
	}
	return result;
}


int main(){
	cout << "infix: (a-b/c)*(a/k-l)" << endl;
	cout << "Postfix: " << infix_to_postfix("(a-b/c)*(a/k-l)");
}
