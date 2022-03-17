#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e5+5;

struct edge{int next,to;}e[2*M];
int head[N],num_edge=1;
void add_edge(int,int);

int n,m;
void init();

int dfn[N],low[N],now=0;
int root,cnt;

void add_edge(int from,int to)
{
    e[++num_edge]=(edge){head[from],to};
    head[from]=num_edge;
}

void tarjan(int x,int in_edge){
    dfn[x]=low[x]=++now;
    for(int _iter=head[x];_iter;_iter=e[_iter].next){
        int y=e[_iter].to;
        if(!dfn[y])
        {
            tarjan(y,_iter);
            low[x]=min(low[x],low[y]);
            if(low[y]>dfn[x]){
                //<x, y>为割边
            }
        }
        else if(_iter!=(in_edge^1))low[x]=min(low[x],dfn[y]);
    }
}

int main()
{
    init();
    
    return 0;
}

