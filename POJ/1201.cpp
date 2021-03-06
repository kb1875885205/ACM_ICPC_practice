// 差分约束系统.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
struct Edge
{
	int to;
	int weight;
	//bool operator>(const Edge& a)const
	//{
		//return a.weight > this->weight;
	//}
};
const int INF = 0x3f3f3f3f;
vector<Edge>Node[50005];//五万个点
int dis[50005];
bool visit[50005];
int cnt[50005];//五万个点
int node_num, edge_num;
bool spfa(int sta)//求最值路径并判环
{
	int len;
	//priority_queue<Edge,vector<Edge>,greater<Edge>>Q;
	queue<Edge>Q;
	memset(dis, -INF, sizeof(dis));
	memset(visit, 0, sizeof(visit));
	//memset(cnt, 0, sizeof(cnt));
	dis[sta] = 0;
	Edge tmp;
	tmp.to = sta;
	tmp.weight = 0;
	Q.push(tmp);
	visit[sta] = 1;
	cnt[sta] = 1;
	while (!Q.empty())
	{
		Edge now = Q.front(), nowto;
		//Edge now = Q.top(), nowto;
		Q.pop();
		visit[now.to] = 0;
		len = Node[now.to].size();
		for (int i = 0; i < len; ++i)
		{
			nowto = Node[now.to][i];
			if (dis[nowto.to] < dis[now.to] + nowto.weight)
			{
				cnt[nowto.to] = cnt[now.to] + 1;
				dis[nowto.to] = dis[now.to] + nowto.weight;
				if (visit[nowto.to] == 0)
				{
					Q.push(nowto);
					visit[nowto.to];
				}
			}
		}
	}
	return true;
}
void solve()
{
	int a, b, k;
	string c;
	scanf("%d", &edge_num);
	int L = INF, R = -1;
	Edge tmp;
	for (int i = 0; i < edge_num; ++i)
	{
		scanf("%d%d%d", &a, &b, &k);
		tmp.to = b + 1;
		tmp.weight = k;
		Node[a].push_back(tmp);
		L = Min(a, L);
		R = Max(b + 1, R);
	}
	for (int i = L; i <= R; ++i)
	{
		tmp.to = i + 1;
		tmp.weight = 0;
		Node[i].push_back(tmp);
		tmp.to = i;
		tmp.weight = -1;
		Node[i + 1].push_back(tmp);
	}
	if (spfa(L))
		cout << dis[R] << endl;
	//else
		//cout << "No solution" << endl;
}
int main()
{
	solve();
	return 0;
}
