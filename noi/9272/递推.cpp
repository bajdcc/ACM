#include <iostream>

using namespace std;

int g(int n);
int f(int n) {
	return n==1?8:(g(n-1)+9*f(n-1))%12345;
}

int g(int n) {
	return n==1?1:(f(n-1)+9*g(n-1))%12345;
}

int main() {
	int n;
	cin>>n;
	cout<<f(n);
	return 0;
}