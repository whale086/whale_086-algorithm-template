

template <typename T>
struct line_basis
{
	T a[70] = {0};
	bool flag = 0;
	void insert(T x) // 插入操作
	{
		for (int i = 60; ~i; i--)
		{
			if (x & (1ll << i))
			{
				if (!a[i])
				{
					a[i] = x;
					return;
				}
				else
				{
					x ^= a[i];
				}
			}
		}
		flag = true; // 代表存在没插入成功的
	}
	bool check(T x) // 判断x能否由线性基导出 能否插入线性基
	{
		for (int i = 60; ~i; --i)
		{
			if (x & (1ll << i))
			{
				if (!a[i])
				{
					return false;
				}
				else
				{
					x ^= a[i];
				}
			}
		}
		return true;
	}
	
	T qmax() // 求最大值
	{
		T res = 0;
		for (int i = 60; ~i; --i)
		{
			res = std::max(res, res ^ a[i]);
		}
		return res;
	}
	T qmin() // 求最小值
	{
		if (flag) // 可以为0
		{
			return 0;
		}
		for (int i = 0; i <= 60; ++i)
		{
			if (a[i])
			{
				return a[i];
			}
		}
	}
	T val(int k) // 第k小
	{
		std::vector<T> tmp(70);
		T res = 0;
		int cnt = 0;
		k -= flag;
		if (!k)
		{
			return 0;
		}
		for (int i = 0; i <= 60; ++i)
		{
			T now = a[i];
			for (int j = i - 1; ~j; j--) // 从大到小贪心
			{
				if (now & (1ll << j)) // 能否清空这一位
				{
					now ^= a[j];
				}
			}
			if (now)
			{
				tmp[cnt++] = now;
			}
		}
		if (k >= (1ll << cnt)) // 不存在第k小
		{
			return -1;
		}
		for (int i = 0; i < cnt; ++i)
		{
			if (k & (1ll << i))
			{
				res ^= tmp[i];
			}
		}
		return res;
	}
	
	T rank(T val) // 查询x是第几小 查询比x小的数有几个
	{
		std::vector<T> st(70);
		int cnt = 0;
		T res = 0;
		for (int i = 0; i <= 60; ++i)
		{
			if (a[i])
			{
				st[cnt++] = i;
			}
		}
		for (int i = 0; i < cnt; ++i)
		{
			if (val >> st[i] & 1)
			{
				res += 1 << i;
			}
		}
		return res;
	}
	
	int n;
	
	line_basis(const std::vector<T> &a) : n(a.size())
	{
		for (int i = 1; i <= n - 1; ++i)
		{
			insert(a[i]);
		}
	}
	line_basis() {}
};
