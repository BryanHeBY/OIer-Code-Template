#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
int a[N],c[N];

int main()
{
    
    return 0;
}

void init()
{
    for(int i=1;i<=n;i++)
    {
        int t=i&(-i),now=1;
        while(now!=t)
        {
            c[i]+=c[i-now];
            now<<=1;
        }
        c[i]+=a[i];
    }
}
void add(int pos,int x)
{
    for(;pos<=n;pos+=pos&-pos)
        c[pos]+=x;
}
int ask(int pos)
{
    int ans=0;
    for(;pos;pos-=pos&-pos)ans+=c[pos];
    return ans;
}

/*洛谷例题
[P3374](https://www.luogu.org/problemnew/show/P3374)
[P3368](https://www.luogu.org/problemnew/show/P3368)

*/
