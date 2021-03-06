#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int check(const string &a)
{
	int l = a.size();
	int k = 1, tot = 0;
	for (int i = 0; i < l - 1; ++i)
		if (isdigit(a[i]))
		{
			tot += (a[i] - '0') * k;
			++k;
		}
	if (tot % 11 == a[l - 1] - '0' || (tot % 11 == 10 && a[l - 1] == 'X'))
		return 11;
	else
		return tot % 11;
}
int main()
{
	string a;
	cin >> a;
	int aa = check(a);
	if (aa == 11)
		cout << "Right" << endl;
	else
	{
		if (aa < 10)
			a[a.size() - 1] = aa + '0';
		else 
			a[a.size() - 1] = 'X';
		cout << a << endl;
	}
	return 0;
}