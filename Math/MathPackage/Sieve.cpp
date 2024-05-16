struct Sieve{
	vector<int>prime,v;
	Sieve(int n):v(n){
		for(int i=2;i<=n;i++){
			if(!v[i])prime.push_back(i),v[i]=i;
			for(int j=0;j<prime.size()&&prime[j]*i<=n;j++){
				v[i*prime[j]]=prime[j];
				if(v[i]==prime[j])break;
			}
		}
	}
	vector<int>get(int x){
		vector<int>_div(1,1);
		while(x>1){
			int D=v[x];
			int l=0,r=_div.size();
			while(x%D==0){
				for(int k=l;k<r;k++)
					_div.push_back(_div[k]*D);
				x/=D,l=r,r=_div.size();
			}
		}
		return _div;
	}
};
Sieve p(10000005);
