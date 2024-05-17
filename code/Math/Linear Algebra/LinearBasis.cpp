
struct LinearBasis{
	const int logn;
	vector<int>b;
	int flag=0,r=0;
	// flag 表示线性基能不能异或出 0
	// r 表示线性基的秩
	
	LinearBasis(int n):logn(__lg(n)),b(__lg(n)+1){}
	
	void insert(int x){// 插入一个数到线性基里
		for(int i=logn;i>=0;i--){
			if(x>>i&1){
				if(!b[i]){// 线性基里没有第i位的项
					b[i]=x;
					r++;
					return;
				}
				x^=b[i];// 线性基里有,则异或掉第i位
			}
		}
		flag=true;
	}
	
	bool check(int x){// 询问线性基能不能异或出 x
		for(int i=logn;i>=0;i--){
			if(x>>i&1){
				if(!b[i])return false;// 线性基里没有第i位的项
				x^=b[i];// 线性基里有,则异或掉第i位
			}
			return true;
		}
	}
};
