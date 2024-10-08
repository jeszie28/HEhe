#include <iostream>
#include <string>
#include <stack>
using namespace std;

int precedence(char op){
	if ( op == '+' || op == '-'){
		return 1;
	}
	if ( op == '*'|| op == '/'){
		return 2;
	}
	return 0;
}

string infixtopostfix (string infix){
	stack <char> stackop;
	string postfix = " ";
	for (int i=0; i<infix.length(); i++){
		char c = infix [i];
		if (isalnum(c)){
			postfix += c;
		}
		else {
			while (!stackop.empty() && precedence(c)<= precedence (stackop.top())){
				postfix += stackop.top();
				stackop.pop();
			}
			stackop.push(c);
		}
	}
	while (!stackop.empty()){
		postfix += stackop.top();
		stackop.pop();
	}
	return postfix;
	
}

int main () {
	string infix = "A*B+C-D*F";
	cout << "Infix: " << infix << endl;
	cout << "Postfix: " << infixtopostfix (infix);
	return 0;
}
