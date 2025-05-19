#include<bits/stdc++.h>
using namespace std;

string M;
string C;
void bf(string x,string y){
	int i = 0;
	int j,k,flag, flagr = 0;
	while(i < x.length()-y.length()+1){
		j = 0;
		if(x[i] == y[j]){
			k = i;
			flag =1;
			while(j<y.length()){
				if(x[k] != y[j]){
					flag = 0;
					break;
				}
				else{
					++j;
					++k;	
				}
			}
			if(flag){
				flagr = 1;
				cout << "Æ¥ÅäÎ»£º" << i+1 <<endl;
			}	
		}
		++i;
	}
	if(!flagr){
		cout << "Î´Æ¥Åä³É¹¦£¡" << endl;
	}
}
int main(){
    cin >> M >> C;
    bf(M,C);
    return 0;
}
/*aaabbbababaabb abaa*/
