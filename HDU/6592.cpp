#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
int f[MAXN][2], g[MAXN][2], num[MAXN];
//f[i][0]��ʾѡ��a[i]֮��a[1~i]������������У�f[i][1]��ʾѡ��a[i]֮��a[i~n]�������������
//g[i][0]��ʾѡ��a[i]֮��a[i~n]����½������У�g[i][1]��ʾѡ��a[i]֮��a[i~n]�������������
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n)
    {
        for (int i = 1; i <= n; ++i)
            cin >> num[i];
        f[0][0] = f[0][1] = 0;
        g[n + 1][0] = g[n + 1][1] = 0;
        for (int i = 1; i <= n; ++i)
        {
            f[i][0] = f[i - 1][0];
        }
    }
}
