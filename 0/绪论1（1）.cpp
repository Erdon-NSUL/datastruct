#include<iostream>
#include<ctime>
using namespace std;
double f1(double n){
	double s = 0;
		while(n > 0){
			s += n;
			n--;
		}
	return s;	
}
int f2(int n){
	return n*(n+1)/2;	
}
int main(){
	double n,s1,s2 = 0;
	cout << "n:";
	cin >> n;
	clock_t cs1 = clock();
	s1 = f1(n);
	clock_t ce1 = clock();
	clock_t cs2 = clock();
	s2 = f2(n);
	clock_t ce2 = clock(); 
	double time1 = double(ce1-cs1)/CLOCKS_PER_SEC;
	double time2 = double(ce2-cs2)/CLOCKS_PER_SEC;
	cout << "����1��" << endl;
	cout << "  ���" << s1 << endl;
	cout << "  ��ʱ��" << time1 <<"��" << endl;
	cout << "����2��" << endl;
	cout << "  ���:" << s2 << endl;
	cout << "  ��ʱ��" << time2 <<"��" << endl;
	return 0;
}
