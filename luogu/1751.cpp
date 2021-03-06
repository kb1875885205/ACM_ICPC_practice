// P1751.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#define min(a,b) (a>b?b:a)
using namespace std;
int mat[105][105];
int pri[105];
int dis[105][105];
int dp[4096][105];
//long long ans = 0;
void floyd(int n)
{
	memset(dis, 0x3f3f3f3f, sizeof(dis));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			dis[i][j] = mat[i][j];
	for (int k = 1; k <= n; ++k)
		for (int j = 1; j <= n; ++j)
			for (int i = 1; i <= n; ++i)
				if (dis[i][j] > dis[i][k] + dis[k][j])
					dis[i][j] = dis[i][k] + dis[k][j];
}
void solve(int n,int m)
{
	memset(dp, 0x3f3f3f3f, sizeof(dp));
	for (int i = 1; i <= n; ++i)
		dp[1 << (i - 1)][pri[i]] = dis[1][pri[i]];
	for (int i = 1; i < 1 << n; ++i)
		for (int j = 1; j <= n; ++j)
			if (i & 1 << (j - 1))//状态i中含有j
				for (int k = 1; k <= n; ++k)
					if (!(i & 1 << (k - 1)))//状态i中不包含k
						dp[i | 1 << (k - 1)][pri[k]] = min(dp[i | 1 << (k - 1)][pri[k]], dp[i][pri[j]] + dis[pri[j]][pri[k]]);
	int ans = 0x3f3f3f3f;
	for (int i = 1; i <= m; ++i)
		ans = min(ans, dp[(1 << n) - 1][pri[i]] + dis[pri[i]][m]);
	cout << ans << endl;
}
int main()
{
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> mat[i][j];
	cin >> m;
	for (int i = 1; i <= m; ++i)
		cin >> pri[i];
	pri[0] = 1;
	floyd(n);
	solve(m, n);
	return 0;
}