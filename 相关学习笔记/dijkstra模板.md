此namespace已通过P4779，请放心食用
```cpp

namespace dijkstra
{
    typedef int T;
    const int NUM_POINT=100005,NUM_EDGE=500005;
    T inf=2147483647;
    struct edge
    {
   	 	int next,to;
   		T dis;
    }e[NUM_EDGE];
    int head[NUM_POINT],num_edge;
    void add_edge(int from,int to,T dis)
    {
  	 		e[++num_edge].next=head[from];
    		e[num_edge].to=to;
    		e[num_edge].dis=dis;
    		head[from]=num_edge;
    }
    
    struct node
    {
    		int v;
    		T d;
    		bool operator<(const node& a) const {return d>a.d;}
    };
    
    T dis[NUM_POINT];
    void main(int num_edge,int from)
    {
        for(int i=1;i<=num_edge;i++)dis[i]=inf;
        dis[from]=0;
        priority_queue<node> pq;
   	 	pq.push((node){from,0});
   		while(!pq.empty())
    		{
        		node t=pq.top();
        		pq.pop();
        		if(t.d!=dis[t.v])continue;
        		for(int j=head[t.v];j;j=e[j].next)
            		{
                		int tt=e[j].to;
                		if(dis[t.v]+e[j].dis<dis[tt])
                		{
                			dis[tt]=dis[t.v]+e[j].dis;
                			pq.push((node){tt,dis[tt]});
                		}
            		}
    		}
    }
}
```
