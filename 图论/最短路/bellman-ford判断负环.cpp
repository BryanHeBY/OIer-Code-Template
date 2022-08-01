#include<bits/stdc++.h>
//#define GQD
const int N=2e3+5,M=2e3+5;
const int inf=1e9;
using namespace std;
#define F(i,l,r) for(int i=l;i<=r;++i)
#define DF(i,r,l) for(int i=r;i>=l;i--)
typedef long long ll;

int dis[N];
struct E{
    int u,v;
    int d;
}e[M];
int n,m;

bool bf() {
    F(i,1,n)dis[i]=inf;
    dis[1]=0;
    F(i,1,n-1){
        bool flag=false;
        F(j,1,m){
            if(dis[e[j].v]>dis[e[j].u]+e[j].d){
                dis[e[j].v]=dis[e[j].u]+e[j].d;
                flag=true;
            }
        }
        if(!flag)return false;
    }
    F(j,1,m){
        if(dis[e[j].v]>dis[e[j].u]+e[j].d){
            return true;
        }
    }
    return false;
}

int main(){
    
    return 0;
}