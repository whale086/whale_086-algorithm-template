
const double eps=1e-9;
int sgn(double &a){
	return (a<-eps?-1:a>eps);
}
string gauss(vector<vector<double> >&a){
	int n=a.size();
	int c,r;
	for(c=0,r=0;c<n;c++){ // c列r行，遍历列
		int tmp=r;
		for(int i=r;i<n;i++){ // 寻找列主元
			if(sgn(a[i][c])) tmp=i;
		}
		if(sgn(a[tmp][c])==0)continue;// 当前列全为0
		swap(a[tmp],a[r]);// 交换列主元
		
		for(int i=n;i>=c;i--)a[r][i]/=a[r][c];// 倒序处理
		
		for(int i=r+1;i<n;i++){
			if(sgn(a[i][c])){
				for(int j=n;j>=c;j--){
					a[i][j]-=a[r][j]*a[i][c];
				}
			}
		}
		r++;
	}
	if(r<n){
		for(int i=r;i<n;i++){
			if(sgn(a[i][n]))return "NoSolution";
		}
		return "InfSolution";
	}
	for(int i=n-1;i>=0;i--){ // 解放在 a[i][n]  (0<= i < n)
		for(int j=i+1;j<n;j++){
			a[i][n]-=a[j][n]*a[i][j];
		}
	}
	return "OK";
}
