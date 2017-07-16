#include <iostream>

using namespace std;

#define MOD 12345

// 快速幂取模 
int fast(int a, int N, int mod) {
    long long r = 1, aa=a;
    while(N) {
    	//取N的二进制位，是一则乘上相应幂并求余 
        if (N & 1) r = (r * aa) % mod;
        N >>= 1;
        aa = (aa * aa) % mod;
    }
    return (int)r;
}

// 快速幂取模（2为底） 
int fast2(int N, int mod) {
	static long long a=(1LL<<62)%mod;
	int s=N%62,t=N/62;// 2^N=2^s*a^t
	int r = (1LL<<s) % mod;
	if (t>0) {
		r *= fast(a,t,mod);// 2^s*a^t % mod
		r %= mod;
	}
    return (int)r;
}

int main() {
	int n;
	cin>>n;
	//化简：
	// an=1/2*{7*2^(3n-3)+9*2^(n-1)*5^(n-1)}
	// an=2^(n-2)*{9*5^(n-1)+7*2^(2n-2)} 
	int a=fast2(n-2,MOD);
	int b=a<<1;
	int ans=a*(9*fast(5,n-1,MOD)+7*((b*b)%MOD));
	ans%=MOD;
	cout<<ans<<endl;
	return 0;
}