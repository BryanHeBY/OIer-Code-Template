#include<bits/stdc++.h>
using namespace std;
const int N=1e5,inf=1e8;

struct treap
{
	int data[N],fix[N],ch[N][2],cnt[N],size[N],tot,root;
	treap()
	{
		root=tot=0;
		insert(root,-inf),insert(root,inf);
	}
	int newn(int key){return data[++tot]=key,fix[tot]=rand(),ch[tot][0]=ch[tot][1]=0,cnt[tot]=size[tot]=1,tot;}
	void up(int x){size[x]=size[ch[x][0]]+size[ch[x][1]]+cnt[x];}
	void rotate(int &x,int d){int y=ch[x][d^1];ch[x][d^1]=ch[y][d],ch[y][d]=x,x=y;up(ch[x][d]),up(x);}
	int cmp(int a,int b){return a==b?-1:a>b;}
	void insert(int &x,int key)
	{
    	if(!x){x=newn(key);return;}
    	int d=cmp(key,data[x]);
    	if(d==-1){cnt[x]++,up(x);return;}
    	insert(ch[x][d],key);
    	if(fix[x]<fix[ch[x][d]])rotate(x,d^1);
    	up(x);
	}
	void del(int &x,int key)
	{
    	if(!x)return;
    	int d=cmp(key,data[x]);
    	if(d!=-1){del(ch[x][d],key),up(x);return;}
    	if(cnt[x]>1){cnt[x]--,up(x);return;}
    	if(ch[x][0]&&ch[x][1])
    	{
        	d=fix[ch[x][0]]>fix[ch[x][1]];
        	rotate(x,d),del(ch[x][d],key);
    	}
    	else x=ch[x][0]+ch[x][1];
    	up(x);
    }
	int get_key(int x,int key,int d)
	{
    	if(!x)return d==0?-inf:inf;
    	if(d==0)return data[x]<key?max(data[x],get_key(ch[x][1],key,d)):get_key(ch[x][0],key,d);
    	else return data[x]>key?min(data[x],get_key(ch[x][0],key,d)):get_key(ch[x][1],key,d); 
    }
    int getrankbykey(int x,int key)
	{
    	if(!x)return 0;
   		return key==data[x]?size[ch[x][0]]+1:(key<data[x]?getrankbykey(ch[x][0],key):getrankbykey(ch[x][1],key)+size[ch[x][0]]+cnt[x]);
	}
	int getkeybyrank(int x,int rank)
	{
    	if(!x)return 0;
    	return rank<=size[ch[x][0]]?getkeybyrank(ch[x][0],rank):(rank<=size[ch[x][0]]+cnt[x]?data[x]:getkeybyrank(ch[x][1],rank-size[ch[x][0]]-cnt[x]));
	}
}T;

int main()
{
	
	return 0;
}
