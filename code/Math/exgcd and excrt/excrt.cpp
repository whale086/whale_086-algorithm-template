#define int long long
int qmul(int a,int b,int mod){
	int base=0;
	if(b<0)b=-b,a=-a;
	while(b){
		if(b&1)base=(base+a)%mod;
		b>>=a;
		a=(a+a)%mod;
	}
	return base;
}
int exgcd(int a,int b,int &x,int &y){
	if(!b){x=1;y=0;return a;}
	int d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
int excrt(vector<pair<int,int> >q){
	int res=0,M=1;
	for(auto i:q){
		int &a=i.first,&mod=i.second;
		int r=(a-res)%mod;
		r+=(r<0?mod:0);
		
		int x,y;
		int g=exgcd(M,mod,x,y);
		if(r%g){
			q.clear();/////////清空
			return -1;
		}
		x=(x*r/g%(mod/g));
		x+=(x<0?mod/g:0);
		
		int last=M;
		M=M/g*mod;
		res=(qmul(x,last,M)+res)%M;
	}
	q.clear();//////////
	return res;
}
