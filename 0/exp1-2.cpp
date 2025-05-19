#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
void sc(int n){
	double x = log(n)/log(2);
	int i = 1,y = 1;
	while(i<=n){
			y *= i;
			i++;
		}
	cout << setw(12)<< right << x << setw(12)<< right << pow(n,0.5) ;
	cout << setw(12)<< right<< n << setw(12)<< right<<  x*n ;
	cout << setw(12)<< right<< n*n << setw(12)<< right<< n*n*n ;
	cout << setw(12)<< right<< 2*n << setw(12)<< right<< y << endl;
}
int main(){
	double n;
	int k = 1;
	cin >> n ;
	cout << setw(12)<< right <<"log2n " ;
	cout << setw(12)<< right <<"¡Ìn";
	cout << setw(12)<< right <<"n";
	cout << setw(12)<< right <<"nlog2n";
	cout << setw(12)<< right <<"n2";
	cout << setw(12)<< right <<"n3";
	cout << setw(12)<< right <<"2n";
	cout << setw(12)<< right <<"n!"<< endl;
	while(k <= n){
		sc(k);
		k++;
	}
	return 0;
}
