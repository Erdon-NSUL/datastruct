#include<iostream>
#include<ctime>
using namespace std;
int f1(int n){
	int i,c =1 ;
	for (i = 3; i<=n; i++){
		for (int j =2;j<n;j++){
			if (i%j == 0){
				break;
			}
		}
		c += 1;
	}
	return c;
}
int f2(int n){
	int i,c =1 ;
	for (i = 3; i<=n; i++){
		for (int j =2;j*j<n;j++){
			if (i%j == 0){
					break;
				}
			}
		c += 1;
	}
	return c;
}
int main(){
	int n,c,k;
	cout << "n:";
	cin >> n;
	clock_t cs1 = clock();
	c = f1(n);
	clock_t ce1 = clock();
	clock_t cs2 = clock();
	k = f2(n);
	clock_t ce2 = clock();
	
	double time1 = double(ce1-cs1)/CLOCKS_PER_SEC;
	double time2 = double(ce2-cs2)/CLOCKS_PER_SEC;
	cout << "����1��" << endl;
	cout << "  �����2~" << n <<"������������" << c << endl;
	cout << "  ��ʱ��" << time1 <<"��" << endl;
	cout << "����2��" << endl;
	cout << "  �����2~" << n <<"������������" << k << endl;
	cout << "  ��ʱ��" << time2 <<"��" << endl;
	return 0;
}
