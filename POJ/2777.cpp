#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define Tree 100005
struct Segtree
{
	struct node
	{
		int l, r;
		int val, lazy;
	}tree[Tree * 4];
	void build(int l, int r, int k)
	{
		tree[k].l = l, tree[k].r = r, tree[k].lazy = 0;
		if (l == r)
		{
			tree[k].val = 1;
			return;
		}
		int m = (l + r) / 2;
		build(l, m, k * 2);
		build(m + 1, r, k * 2 + 1);
		tree[k].val = tree[k * 2].val | tree[k * 2 + 1].val;
	}
	void down(int k)
	{
		tree[k * 2].lazy = tree[k].lazy;
		tree[k * 2 + 1].lazy = tree[k].lazy;
		tree[k * 2].val = tree[k].lazy;
		tree[k * 2 + 1].val = tree[k].lazy;
		tree[k].lazy = 0;
	}
	void change(int l, int r, int k, int val)
	{
		if (l <= tree[k].l && r >= tree[k].r)
		{
			tree[k].val = (1 << (val - 1));
			tree[k].lazy = (1 << (val - 1));
			return;
		}
		if (tree[k].lazy)
			down(k);
		int m = (tree[k].l + tree[k].r) / 2;
		if (l <= m)
			change(l, r, k * 2, val);
		if (r >= m + 1)
			change(l, r, k * 2 + 1, val);
		tree[k].val = tree[k * 2].val | tree[k * 2 + 1].val;
	}
	long long ask(int l, int r, int k)
	{
		if (l <= tree[k].l && r >= tree[k].r)
			return tree[k].val;
		if (tree[k].lazy)
			down(k);
		long long ans = 0;
		int m = (tree[k].l + tree[k].r) / 2;
		if (l <= m)
			ans |= ask(l, r, k * 2);
		if (r >= m + 1)
			ans |= ask(l, r, k * 2 + 1);
		return ans;
	}
};
Segtree seg;
int cal(long long num)
{
	int n = 0;
	while (num)
	{
		if (num % 2)
			++n;
		num /= 2;
	}
	return n;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, t, m, a, b, c;
	char ch;
	cin >> n >> t >> m;
	seg.build(1, n, 1);
	for (int i = 0; i < m; ++i)
	{
		cin >> ch;
		if (ch == 'C')
		{
			cin >> a >> b >> c;
			if (a > b)
				swap(a, b);
			seg.change(a, b, 1, c);
		}
		else if (ch == 'P')
		{
			cin >> a >> b;
			if (a > b)
				swap(a, b);
			cout << cal(seg.ask(a, b, 1)) << endl;
		}
	}
	return 0;
}
