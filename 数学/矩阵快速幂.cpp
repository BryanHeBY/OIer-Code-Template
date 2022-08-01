#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=102,mod=1000000007;
struct matrix
{
	int r,c;
	ll m[N][N];
	matrix(int r,int c)
    {
        this->r=r,this->c=c;
        memset(this->m,0,sizeof(this->m));
    }
    void identity()//单位矩阵
    {
    	for(int i=1;i<=r;i++)m[i][i]=1;
    }
};
matrix operator *=(matrix &a,matrix b)
{
	matrix temp(a.r,b.c);
	for(int i=1;i<=a.r;i++)
	for(int j=1;j<=b.c;j++)
		for(int k=1;k<=a.c;k++)
			temp.m[i][j]=(temp.m[i][j]+a.m[i][k]*b.m[k][j]%mod)%mod;
	a=temp;//千万别丢这一行
	return temp;
}
matrix qpow(matrix a,ll q);

int main()
{
	//do something
	return 0;
}

matrix qpow(matrix base,ll q)
{
	matrix res(base.r,base.r);
	res.identity();
	while(q)
	{
		if(q&1)res*=base;
		base*=base;
		q>>=1;
	}
	return res;
}