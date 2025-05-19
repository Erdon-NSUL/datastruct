#include<iostream>
#include<string>
#include <cctype>
#include<vector>
using namespace std;
typedef char ElemType;


void _Transform(string infix, string &postfix){
	vector<ElemType> stack;
	int i = 0;
	
	while(i < infix.size()){
		switch (infix[i]) {
			case '(':
				stack.push_back(infix[i]);
				i++;
				break;
			case ')':
				while(!stack.empty() && stack.back() != '('){
					postfix += stack.back();
					stack.pop_back();
				}
				if (!stack.empty()){
					stack.pop_back();
				}
				i++;
				break;
			case '+':
			case '-':
				while (!stack.empty() && stack.back() != '(') {
				    postfix += stack.back();
				    stack.pop_back();
				}
				stack.push_back(infix[i]);
				i++;
				break;
			case '*':
			case '/':
				while (!stack.empty() && 
                       (stack.back() == '*' || stack.back() == '/')) {
                    postfix += stack.back();
                    stack.pop_back();
                }
                stack.push_back(infix[i]);
                i++;				
				break;
			default:
				if(isdigit(infix[i])){
					while(i < infix.size() && isdigit(infix[i])){
						postfix += infix[i];
						i++;
					}
					postfix += '#';
				}
				else{
					i++;
				}
				break;
		}
	}
	while(!stack.empty()){
		postfix += stack.back();
		stack.pop_back();
	}
}

double _Calculate(string postfix){
	vector<double> opnd;
	int i = 0;
	double a,b,c,d;
	
	while(i < postfix.size()){
		switch (postfix[i]) {
			case '+':
				a = opnd.back();
				opnd.pop_back();
				b = opnd.back();
				opnd.pop_back();
				c = b+a;
				opnd.push_back(c);
				i++;
				break;
			case '-':
				a = opnd.back();
				opnd.pop_back();
				b = opnd.back();
				opnd.pop_back();
				c = b-a;
				opnd.push_back(c);
				i++;
				break;
			case '*':
				a = opnd.back();
				opnd.pop_back();
				b = opnd.back();
				opnd.pop_back();
				c = a*b;
				opnd.push_back(c);
				i++;
				break;
			case '/':
				a = opnd.back();
				opnd.pop_back();
				b = opnd.back();
				opnd.pop_back();
				
				if(a!=0){
					c = b/a;
					opnd.push_back(c);
					i++;
					break;
				}
				else{
					cout << "Error:除零错误" << endl;
					exit(0);
				}			
			default:
				string tmp;
				while( i < postfix.size() && postfix[i]!= '#'){
					tmp += postfix[i];
					i++;
				}
				if(!tmp.empty()){
					d = stoi(tmp);
					opnd.push_back(d);
				}
				i++;
				break;
			}
	}	
	
	return opnd.back();	
}

int main(){
	string infix,postfix;
	cout << "请输入表达式：" ;
	getline(cin,infix);
	_Transform(infix,postfix);
	cout << "计算结果为："<< endl;
	cout << _Calculate(postfix);
	return 0;
}
