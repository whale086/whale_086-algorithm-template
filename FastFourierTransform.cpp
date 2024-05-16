#include <bits/stdc++.h>
using namespace std;
//#define int long long
//#define double long double
struct Complex{
	double r,i;
	Complex(double rr,double ii):r(rr),i(ii){}
	Complex():r(0),i(0){}
	Complex operator+(const Complex &o){
		return Complex(r+o.r,i+o.i);
	}
	Complex operator-(const Complex &o){
		return Complex(r-o.r,i-o.i);
	}
	Complex operator*(const Complex &o){
		return Complex(r*o.r-i*o.i,i*o.r+r*o.i);
	}
};
using Comp=Complex;

const double pi=acos(-1);

vector<Comp>w[2];
vector<int>r;

void init(int _log){
	if(r.size()==(1<<_log))return;
	
	int n=1<<_log;
	r.assign(n,0);
	for(int i=1;i<n;i++)r[i]=(r[i>>1]>>1)|((i&1)<<(_log-1));
	w[0].assign(n,Comp());
	w[1].assign(n,Comp());
	for(int i=0;i<n;i++){
		double th=1.l*pi*i/n;
		w[0][i]=Comp(cos(th),sin(th));
		w[1][i]=Comp(cos(th),-sin(th));
	}
}

void fft(vector<Comp>&a,int op){
	int n=a.size();
	init(__lg(n));
	for(int i=0;i<n;i++){
		if(i<r[i]){
			swap(a[i],a[r[i]]);
		}
	}
	for(int mid=1;mid<n;mid<<=1){
		int d=n/mid;
		for(int R=mid<<1,j=0;j<n;j+=R){
			for(int k=0;k<mid;k++){
				Comp x=a[j+k],y=w[op][d*k]*a[j+mid+k];
				a[j+k]=x+y;
				a[j+mid+k]=x-y;
			}
		}
	}
}

struct Polynomial:vector<double>{
	Polynomial(int n=0,double v=0):vector(n,v){}
	Polynomial(vector<double>&a):vector<double>(a){}
	Polynomial(initializer_list<double>&a):vector<double>(a){}
	Polynomial(iterator first,iterator last):vector<double>(first,last){}
	
	Polynomial operator*(const Polynomial &b){
		const Polynomial &a=*this;
		if(a.size()==0||b.size()==0)return Polynomial();
		int n=a.size()+b.size()-1;
		int _log=__lg(2*n-1);
		int s=1<<_log;
		if (min(a.size(), b.size()) < 128) {
			Polynomial res(n);
			for (int i = 0; i < a.size(); i++)
				for (int j = 0; j < b.size(); j++)
					res[i + j] += a[i] * b[j];
			return res;
		}
		vector<Comp>p(s),q(s);
		for(int i=0;i<a.size();i++)p[i].r=a[i];
		for(int i=0;i<b.size();i++)q[i].r=b[i];
		fft(p,0);fft(q,0);
		for(int i=0;i<s;i++)p[i]=p[i]*q[i];
		fft(p,1);
		Polynomial res(n);
		for(int i=0;i<n;i++)res[i]=p[i].r/s;
		return res;
	}
};

using poly=Polynomial;

inline int read()
{
	int x = 0,f = 1;
	char ch = getchar();
	while (ch < '0' || ch>'9')
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}

void solve(){
//	int n,m;cin>>n>>m;
//	poly a(n+1),b(m+1);
//	for(int i=0;i<=n;i++)a[i]=read();
//	for(int i=0;i<=m;i++)b[i]=read();
//	a=a*b;
//	for(auto i:a)cout<<(int)(i+1e-4)<<" ";
//	for(auto i:a)cout<<(int)(i)<<" ";
	return;
}

signed main(){
	int ____=1;
//	cin>>____;
	while(____--)solve();
	return 0;
}	
