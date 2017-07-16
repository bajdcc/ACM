#include <iostream>

using namespace std;

#define LL long long
#define NUM 3

int main() {
	LL m,n,i,j,t,count;
	cin>>n;
	for(i=0,m=1;i<n;i++) m*=10; // 求N位数上界 
	for(i=m/10,count=0;i<m;i++) { // 从10..000 ~ 99..999
		for (j=0,t=i;t;t/=10) // 取每一位 
			if (t%10==NUM) j++; // 如果是NUM计数j加一 
		if (j%2==0) {
		    count++; // 偶数个NUM计数count加一
		    count%=12345;
		}
	}
	cout<<count;
	return 0;
}