struct LinearBasis{
	int a[70]={0};
	bool flag=0;
	void insert(int x){// 插入操作 
		for(int i=60;~i;i--){
			if(x&(1ll<<i)){
				if(!a[i]){
					a[i]=x;
					return;
				}
				else x^=a[i];
			}
		}
		flag=true;// 代表存在没插入成功的
	}
	bool check(int x){// 判断x能否由线性基导出 能否插入线性基
		for(int i=60;~i;i--){
			if(x&(1ll<<i)){
				if(!a[i])return false;
				else x^=a[i];
			}
		}
		return true;
	}
	int qmax(){//求最大
		int res=0;
		for(int i=60;~i;i--)res=max(res,res^a[i]);
		return res;
	}
	int qmin(){//求最小
		if(flag)return 0;
		for(int i=0;i<=60;i++){
			if(a[i])return a[i];
		}
	}
	int val(int k){//第k小
		vector<int>tmp(70);
		int res=0;
		int cnt=0;
		k-=flag;
		if(!k)return 0;
		for(int i=0;i<=60;i++){
			int now=a[i];
			for(int j=i-1;~j;j--){// 从大到小贪心
				if(now&(1ll<<j))now^=a[j];// 能否清空这一位
			}
			if(now)tmp[cnt++]=now;
		}
		if(k>=(1ll<<cnt))return -1;// 不存在第k小
		for(int i=0;i<cnt;i++){
			if(k&(1ll<<i))res^=tmp[i];
		}
		return res;
	}
	int rank(int v){// 查询x是第几小 查询比x小的数有几个
		vector<int>st(70);
		int cnt=0;
		int res=0;
		for(int i=0;i<=60;i++){
			if(a[i])st[cnt++]=i;
		}
		for(int i=0;i<cnt;i++){
			if(v>>st[i]&1)res+=1ll<<i;
		}
		return res;
	}
	
	int n;
	
	LinearBasis(vector<int>&a):n(a.size()){
		for(int i=0;i<n;i++)insert(a[i]);
	}
	LinearBasis(){}
};
