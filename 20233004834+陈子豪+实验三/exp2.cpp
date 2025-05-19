#include<bits/stdc++.h>
using namespace std;
/*aaabbbababaabb abaa*/
/*abcdefgh ecde*/
string M;
string C;

vector<int> build_next(string y){
	int n = y.length();
	vector<int> _next(n,0);
	_next[0] = -1;
	int i = 0,j = -1;
	while(i <n-1){
		if(j ==-1 || y[i] == y[j]){
			++i;
			++j;
			_next[i] = j;
		}
		else{
			j = _next[j];
		}
	}
	return _next;
}
void kmp(vector<int> _next,string x,string y){
	int m = x.length(),n =y.length();
	if(n == 0){
		cout << "Error：空模式串！"<<endl;
		return;
	};
	int i = 0,j = 0;
	while(i<m && j <n){
		if(j ==-1 || x[i] == y[j]){
			++i;
			++j;
		}
		else{
			j = _next[j];
		}
	}
	if(j == n){
		cout << "匹配位：" << i-j<<endl;
	}
	else{
		cout << "未匹配成功！"<< endl;
	};
	return;
}

int main(){
    cin >> M >> C;
    vector<int> _next = build_next(C);
    kmp(_next,M,C);
    return 0;
}
