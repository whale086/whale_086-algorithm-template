
template <typename T>
using matrix = vector<vector<T>>;

template <typename T>
matrix<T> mul(const matrix<T>& a, const matrix<T>& b, long long MOD) {
	size_t aRows = a.size();
	size_t aCols = a[0].size();
	size_t bCols = b[0].size();
	
	matrix<T> result(aRows, vector<T>(bCols));
	
	for (size_t i = 0; i < aRows; ++i) {
		for (size_t j = 0; j < bCols; ++j) {
			T sum = 0;
			for (size_t k = 0; k < aCols; ++k) {
				sum += a[i][k] * b[k][j];
				if (MOD != 0) {
					sum %= MOD;
				}
			}
			result[i][j] = sum;
			if (MOD != 0) {
				result[i][j] %= MOD;
			}
		}
	}
	return result;
}

template <typename T>
matrix<T> power(const matrix<T>& base, long long exponent, const T MOD) {
	size_t rows = base.size();
	size_t cols = base[0].size();
	matrix<T> result(rows, vector<T>(cols, 0));
	
	for (size_t i = 0; i < rows; ++i) {
		result[i][i] = 1; 
	}
	
	matrix<T> temp = base; 
	
	while (exponent > 0) {
		if (exponent & 1) {
			result = mul(result, temp, MOD); 
		}
		temp = mul(temp, temp, MOD);
		exponent >>= 1; 
	}
	
	return result;
}
using mx = matrix<int>;
