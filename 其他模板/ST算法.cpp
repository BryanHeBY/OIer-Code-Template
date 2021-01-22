#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;
int a[N],f[N][20];
int logn[N];
void ST_prework();
int ST_query(int,int);

int main()
{
	ST_prework();
	
	return 0;
}

void ST_prework()
{
	for(int i=1;i<=n;i++)
	{
		f[i][0]=a[i];
		logn[i]=logn[i-1]+((1<<(logn[i-1]+1))==i);
	}//初始化
	int maxd=logn[n]+1;
	for(int k=1;k<maxd;k++)
		for(int i=1;i<=n-(1<<k)+1;i++)
			f[i][k]=max(f[i][k-1],f[i+(1<<(k-1))][k-1]);//类似dp
}
int ST_query(int l,int r)
{
	int k=logn[r-l+1];
	return max(f[l][k],f[r-(1<<k)+1][k]);//左右重叠
}

//[p3865](https://www.luogu.org/problemnew/show/P3865)