#include<bits/stdc++.h>
using namespace std;

int main(){
	map<int,int> ciallo;
	cout << "������m"<< endl;
	int m ;cin >> m;
	cout << "������ɼ�(ֻ��¼m��)"<< endl;
	
	int qwq,cnt = 0;
	while(cnt < m){
		cin >> qwq;
		ciallo[qwq]++;
		cnt++;
	}
	cout << "�����ǳɼ�������"<< endl;
	for(auto i = ciallo.begin();i != ciallo.end();++i ){
		cout << i->first << ": " << i->second << endl;
	}
	
	
}
