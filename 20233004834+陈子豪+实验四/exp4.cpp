#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	bool tag;
	char value;
	node *subh,*nxt;
	node(char v): tag(true),value(v),subh(nullptr),nxt(nullptr){}
	node(): tag(false),value('\0'),subh(nullptr),nxt(nullptr){}
}Node,*PNODE;

void create(PNODE &l,const string &D,int &index){
	while(index < D.size()){
		if(isspace(D[index])){
			cout<<"space: "<<index<<endl;
			index++;
			continue;
		}
			if(D[index]== '('){
				l = new(nothrow) Node;
				index++;
				create(l->subh,D,index);
				if (index < D.size() && D[index] == ')') {
				    index++; // 跳过')'
				}
				if (index < D.size() && D[index] == ',') {
				    index++; // 跳过','
				    PNODE p = new(nothrow) Node();
				    l->nxt = p;
				    l = p;
				}
			}
			else if( D[index]==')'){
				index++;
				return;
			}
			else if(D[index] == ','){
				index++;
				PNODE p = new(nothrow) Node();
				l->nxt = p;
				l = p;
			}
			else{
				l = new(nothrow) Node(D[index]);
				l->value = D[index];
				index++;
				if (index < D.size() && (D[index] == ',' || D[index] == ')')) {
					PNODE p = new(nothrow) Node();
					l->nxt = p;
				    l = p;
				}
			}
		}
	}
	
void print(PNODE l){
	if(!l) cout << -1 ; return;
	if(l->tag){
		cout <<l->value;
	}else{
		cout << "(";
		PNODE p =l->subh;
		while(p){
			print(p);
			p = p->nxt;
			if(p) cout <<",";
		}
		cout << ")";
	}
}

//(a,b,(c,d),e)
int main(){
	cout << "输入广义表: "<<endl;
	string input;
	getline(cin,input);
	int index = 0;
	PNODE p = new(nothrow) Node();
	create(p->subh,input,index);
	cout << "打印：";
	print(p->subh);
	return 0;
}
