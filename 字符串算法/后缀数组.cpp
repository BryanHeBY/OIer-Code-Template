#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int wa[N],wb[N],pot[N],sa[N],*rankn;
char t[N];
int n,z=27;
bool cmp(int *t,int a,int b,int j){return t[a]==t[b]&&t[a+j]==t[b+j];}
void da();
int height[N];
void get_height();
int f[20][N],logn[N];
void rmq();
int query(int,int);

int main()
{
	cin>>t;
	n=strlen(t);
	for(int i=0;i<n;i++)t[i]-='a'-1;
	n++;
	get_height();
	rmq();
	return 0;
}

int query(int l,int r)
{
	int k=logn[r-l+1];
	return min(f[k][l],f[k][r-(1<<k)+1]);
}
void rmq()
{
	memcpy(f[0],height,n<<2);
	logn[1]=0;
	for(int i=2;i<=n;i++)logn[i]=logn[i>>1]+1;
	int maxd=logn[n]+1;
	for(int k=1;k<maxd;k++)
		for(int i=0;i<n-(1<<k)+1;i++)
			f[k][i]=min(f[k-1][i],f[k-1][i+(1<<(k-1))]);
}
void get_height()
{
	da();
	height[0]=0;
	int temp=n-1,k=0,j;
	for(int i=0;i<temp;height[rankn[i]]=k,i++)
		for(k?--k:0,j=sa[rankn[i]-1];t[i+k]==t[j+k];k++);
}
void da()
{
	int *x=wa,*y=wb,i,j,p;
	memset(pot,0,z<<2);
	for(i=0;i<n;i++)pot[x[i]=t[i]]++;
	for(i=1;i<z;i++)pot[i]+=pot[i-1];
	for(i=n-1;i>=0;i--)sa[--pot[x[i]]]=i;
	for(j=1,p=1;p<n;j<<=1,z=p)
	{
		for(p=0,i=n-j;i<n;i++)y[p++]=i;
		for(i=0;i<n;i++)
			if(sa[i]>=j)y[p++]=sa[i]-j;
		memset(pot,0,z<<2);
		for(i=0;i<n;i++)pot[x[y[i]]]++;
		for(i=1;i<z;i++)pot[i]+=pot[i-1];
		for(i=n-1;i>=0;i--)sa[--pot[x[y[i]]]]=y[i];
		swap(x,y),x[sa[0]]=0,p=1;
		for(i=1;i<n;i++)
			x[sa[i]]=cmp(y,sa[i],sa[i-1],j)?p-1:p++;
	}
	rankn=x;
}
