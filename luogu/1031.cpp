#include <iostream>
#include <algorithm>
using namespace std;
int num[105];
int main()
{
    int n,tot=0;
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>num[i],tot+=num[i];
    int aver=tot/n;
    for(int i=0;i<n;++i)
        num[i]-=aver;
    int ans=0;
    for(int i=1;i<n;++i)
    {
        if(num[i-1]==0)//ǰһ������Ҫ�ƶ�
            continue;
        num[i]=num[i]+num[i-1];
        if(num[i]==0)//�պô���
            ++ans,++i;
        else    //û�д���
            ++ans;
    }
    cout<<ans<<endl;
    return 0;
}
