#include<bits/stdc++.h>
using namespace std;
const int N=10000;
int prime[N/3],con;
bool isprime[N+5];
int phi[N+5];
void prime_table();

int main()
{
    prime_table();
    
    return 0;
}

void prime_table()
{
	isprime[1]=1;
	phi[1]=1;
	for(int i=2;i<=N;i++)
	{
		if(!isprime[i])
		{
			prime[++con]=i;
			phi[i]=i-1;
		}
		for(int j=1;j<=con&&i*prime[j]<=N;j++)
		{
			isprime[i*prime[j]]=1;
			if(i%prime[j]==0)
			{
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			else phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}
}