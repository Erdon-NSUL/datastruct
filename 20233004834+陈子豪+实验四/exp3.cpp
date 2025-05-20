#include<bits/stdc++.h>
using namespace std;

int main(){
	map<int,int> ciallo;
	cout << "请输入m"<< endl;
	int m ;cin >> m;
	cout << "请输入成绩(只记录m个)"<< endl;
	
	int qwq,cnt = 0;
	while(cnt < m){
		cin >> qwq;
		ciallo[qwq]++;
		cnt++;
	}
	cout << "以下是成绩计数："<< endl;
	for(auto i = ciallo.begin();i != ciallo.end();++i ){
		cout << i->first << ": " << i->second << endl;
	}
	
	
}
