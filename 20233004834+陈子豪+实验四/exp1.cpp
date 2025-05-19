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
	
	cout << "����������������" << endl;
	cin >> l->row >> l->col;
	

	cout << "������������Ԫ���ʾ"<< endl;
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
	cout <<"���ڽ���ϡ�����Ŀ���ת�ã�ͬ���Y����������:" << endl;
	char check;cin >> check;
	if(check == 'Y'){
		_TranMat(l);
		cout <<"ת�ò����ɹ���"<<endl;
		check = 'o';
	}
	cout <<"����׼����ӡϡ�����ͬ���Y����������:" << endl;
	cin>>check;
		if(check == 'Y'){
			_PrintMat(l);
		}
	return 0;
}
