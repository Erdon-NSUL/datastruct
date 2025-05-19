#include<bits/stdc++.h>
using namespace std;
/*0 2 1 1 1 2 2 0 3 3 3 5 4 4 6 5 5 7 5 6 4*/

typedef struct{
	int value;
	int row;
	int col;
}_Tri;

typedef struct{
	int row;
	int col;
	vector<_Tri*>data;
}_Mat;

int _TranMat(_Mat *&p){
	int tmp;
	tmp = p->col;
	p->col = p->row;
	p->row = tmp;
	for(auto i:p->data){
		tmp = i->row;
		i->row = i->col;
		i->col = tmp;
	}
	return 0;
}

int _PrintMat(_Mat *p){
	vector<vector<int>>tmp(p->row,vector<int>(p->col,0));
	for(auto i:p->data){
		tmp[i->row][i->col] = i->value;
	}
	for(auto k:tmp){
		for(auto t:k){
			cout << t << " ";
		}
		cout <<endl;
	}
	return 0;
}

int main(){
	_Mat *l;
	l = new(nothrow) _Mat;
	
	cout << "请输入矩阵的行列数" << endl;
	cin >> l->row >> l->col;
	

	cout << "请输入矩阵的三元组表示"<< endl;
	string D;
	cin.get();
	getline(cin,D);
	istringstream stream(D);
	int r,c,num;
	
	while(stream >> r >> c >> num){
		_Tri *p;
		p = new(nothrow) _Tri;
		p->row = r;
		p->col = c;
		p->value = num;
		
		l->data.push_back(p);
	}
	cout <<"现在进行稀疏矩阵的快速转置，同意打Y，否则随便打:" << endl;
	char check;cin >> check;
	if(check == 'Y'){
		_TranMat(l);
		cout <<"转置操作成功！"<<endl;
		check = 'o';
	}
	cout <<"现在准备打印稀疏矩阵，同意打Y，否则随便打:" << endl;
	cin>>check;
		if(check == 'Y'){
			_PrintMat(l);
		}
	return 0;
}
