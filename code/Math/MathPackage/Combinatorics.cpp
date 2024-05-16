#define int long long
//const int mod=998244353;
const int mod=1e9+7;
//const int mod=1e5+7;
struct Comb{
	int n;
	
	vector<int>fact,invfact;
	
	Comb(int nn){
		n=nn;
		fact.resize(n+1);
		invfact.resize(n+1);
		fact[0]=1;
		for(int i=1;i<=n;i++)fact[i]=fact[i-1]*i%mod;
		/////////////////mod - prime
		invfact[n]=qpow(fact[n],mod-2);
		for(int i=n;i;i--)invfact[i-1]=invfact[i]*i%mod;
	}
	
	int qpow(int a,int b){
		int base=1;
		while(b){
			if (b&1)base=base*a%mod;
			b>>=1;
			a=a*a%mod;
		}
		return base;
	}
	
	int C(int x,int y){
		if(y>x)return 0;
		return fact[x]*invfact[y]%mod*invfact[x-y]%mod;
	}
	
	int A(int x,int y){
		if(y>x)return 0;
		return fact[x]*invfact[x-y]%mod;
	}
	
	int inv(int x){
		return invfact[x]*fact[x-1]%mod;
	}
}com(1000005);
