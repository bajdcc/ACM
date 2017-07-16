#include <iostream>

using namespace std;

int f[10002][2];//f[][0]=偶数个3，f[][1]=奇数个3 

int main() {
	int n;
	cin>>n;
	f[1][0]=8,f[1][1]=1;
	for (int i=2;i<=n;i++) {
		f[i][0]=(9*f[i-1][0]+f[i-1][1])%12345;
		f[i][1]=(f[i-1][0]+9*f[i-1][1])%12345;
	}
	cout<<f[n][0];
	return 0;
}