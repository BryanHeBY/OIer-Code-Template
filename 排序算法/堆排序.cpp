#include<bits/stdc++.h>
#define ll unsigned long long 
#define F(i,l,r) for(int i=l;i<=r;i++)
const int N=1e5+5;
using namespace std;
int n;
int a[N]; 
int boc[N],top;
void push(int key)
{
	boc[++top]=key;
	int i=top;
	while(i>1&&boc[i]<boc[i>>1])swap(boc[i],boc[i>>1]),i>>=1;
}
int pop()
{
	int ans=boc[1],i=1;
	boc[1]=boc[top--];
	while((i<<1)<=top)
	{
		int j=(i<<1);
		if(j+1<=top&&boc[j+1]<boc[j])j++;
		if(boc[i]<=boc[j])break;
		else swap(boc[i],boc[j]),i=j;
	}
	return ans;
}
void psort(int n)
{
	F(i,1,n)push(a[i]);
	F(i,1,n)a[i]=pop();
}

int main()
{
	scanf("%d",&n);
	F(i,1,n)scanf("%d",&a[i]);
	psort(n);
	F(i,1,n)printf("%d ",a[i]);
	return 0;
}
