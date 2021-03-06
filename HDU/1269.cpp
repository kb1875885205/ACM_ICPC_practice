#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define min(a,b) (a>b?b:a)
using namespace std;
vector<int>Node[50005];//50000个点，存图
vector<int>sol;
int DFN[50005], LOW[50005], stack[50005];
bool instack[50005];
int index = 0, pos = 0;
int scc_cnt;
void tarjan(int u)
{
	DFN[u] = LOW[u] = ++index;
	stack[pos++] = u;
	instack[u] = 1;
	int len = Node[u].size();
	for (int i = 0; i < len; ++i)
	{
		if (!DFN[Node[u][i]])
		{
			tarjan(Node[u][i]);
			LOW[u] = min(LOW[u], LOW[Node[u][i]]);
		}
		else if (instack[Node[u][i]])
			LOW[u] = min(LOW[u], DFN[Node[u][i]]);
	}
	if (LOW[u] == DFN[u])//cautious！//出现强连通分量
	{
		++scc_cnt;
		do {
			instack[stack[pos - 1]] = 0;
		} while (u != stack[--pos]);
	}
}
void solve(int n)
{
	sol.clear();
	memset(instack, 0, sizeof(instack));
	memset(DFN, 0, sizeof(DFN));
	memset(LOW, 0, sizeof(LOW));
	tarjan(0);
	for (int i = 0; i < n; ++i)
		if (!DFN[i])
			tarjan(i);
}
int main()
{
	int n, m, a, b;
	while (cin >> n >> m && m + n)
	{
		for (int i = 0; i < n; ++i)
			Node[i].clear();
		scc_cnt = 0;
		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b;
			Node[a - 1].push_back(b - 1);
		}
		solve(n);
		if (scc_cnt == 1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}