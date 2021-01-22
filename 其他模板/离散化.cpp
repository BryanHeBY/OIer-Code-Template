#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],id[N],b[N],c[N],n,cnt;
bool cmp(int x,int y){return a[x]<a[y];}
void discrete()
{
	sort(id+1,id+n+1,cmp);
	b[id[1]]=cnt=1,c[1]=a[id[1]];
	//for(int i=2;i<=n;i++)b[id[i]]=a[id[i-1]]==a[id[i]]?cnt:++cnt;
	for(int i=2;i<=n;i++)
		if(a[id[i]]!=a[id[i-1]])c[++cnt]=a[id[i]];
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),id[i]=i;
	discrete();
	
	return 0;
}


/*
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],tot;
void discrete();
int query(int x);

int temp[N],cnt[N];

int main()
{
    discrete();
    
    return 0;
}

void discrete()//离散化
{
	sort(a+1,a+tot+1);
	tot=unique(a+1,a+tot+1)-a-1;
}
int query(int x)//查找位置
{
	return lower_bound(a+1,a+tot+1,x)-a;
}
//计数版本
void discrete()
{
	int t=0;
	sort(a+1,a+tot+1);
	for(int i=1;i<=tot;i++)
		{
			if(a[i]!=a[i-1])temp[++t]=a[i];
			cnt[t]++;
		}
	tot=t;
}
int query(int x)
{
	return lower_bound(temp+1,temp+tot+1,x)-temp;
}
*/
