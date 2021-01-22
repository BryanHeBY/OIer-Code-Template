# 一、STL set
```cpp
struct BST
{
	multiset<int> T;
	BST()
	{
		insert(-inf),insert(inf);
	}
	void insert(int key){T.insert(key);}
	void del(int key){T.erase(T.find(key));}
	int pre(int key)
	{
		multiset<int>::iterator it=T.lower_bound(key);
		while(*it>key)it--;
		return *it;
	}
	int next(int key)
	{
		multiset<int>::iterator it=T.lower_bound(key);
		while(*it<key)it++;
		return *it;
	}
	int Pre(int key)
	{
		multiset<int>::iterator it=T.lower_bound(key);
		while(*it>=key)it--;
		return *it;
	}
	int Next(int key)
	{
		multiset<int>::iterator it=T.lower_bound(key);
		while(*it<=key)it++;
		return *it;
	}
}tree;
```


# 二、treap

```cpp
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
```
# 三、splay
```cpp
struct tree
{
    int ch[N][2],data[N],fa[N],size[N],cnt[N],now,root;
    void up(int x){size[x]=size[ch[x][0]]+size[ch[x][1]]+cnt[x];}
    void rotate(int x)
    {
        int y=fa[x],z=fa[y],k=x==ch[y][1];
        if(z)ch[z][y==ch[z][1]]=x;fa[x]=z;
        ch[y][k]=ch[x][k^1],fa[ch[x][k^1]]=y;
        ch[x][k^1]=y,fa[y]=x;
        up(y),up(x);
    }
    void splay(int x,int goal)
    {
        while(fa[x]!=goal)
        {
            int y=fa[x],z=fa[y];
            if(z!=goal)
                (x==ch[x][1])^(y==ch[z][1])?rotate(x):rotate(y);
            rotate(x);
        }
        if(!goal)root=x;
    }
    void insert(int key)
    {
        int x=root,ff=0;
        while(x&&data[x]!=key)ff=x,x=ch[x][key>data[x]];
        if(x)cnt[x]++;
        else
        {
            x=++now;
            ch[x][0]=ch[x][1]=0,data[x]=key,size[x]=cnt[x]=1,fa[x]=ff;
            if(ff)ch[ff][key>data[ff]]=x;
        }
        splay(x,0);//splay里面是用splay到根来更新整棵树的 
    }
    void build(){insert(-inf),insert(inf);}
    int find(int key)
    {
        int x=root;
        while(data[x]!=key&&ch[x][key>data[x]])x=ch[x][key>data[x]];
        return x;
    }
    int next(int key,int d)
    {
        splay(find(key),0);
        int x=root;
        if((!d&&data[x]<key)||(d&&data[x]>key))return x;
        x=ch[x][d];
        while(ch[x][d^1])x=ch[x][d^1];
        return x;
    }
    void del(int key)
    {
        int pre=next(key,0),nextn=next(key,1);
        splay(pre,0),splay(nextn,pre);
        int x=ch[nextn][0];
        if(cnt[x]>1)cnt[x]--,splay(x,0);
        else ch[nextn][0]=0,splay(nextn,0);
    }
    int K_th(int rank)
    {
        int x=root;
        while(233)
        {
            if(rank<=size[ch[x][0]])x=ch[x][0];
            else if(rank<=size[ch[x][0]]+cnt[x])return x;
            else rank-=size[ch[x][0]]+cnt[x],x=ch[x][1];
        }
    }
    //附加操作，类似线段树一样建树 
    void build(int l,int r,int ff)
    {
        if(l>r)return;
        int mid=(l+r)>>1;
        ch[mid][0]=ch[mid][1]=data[mid]=0;
        if(ff)ch[ff][mid>ff]=mid;
        cnt[mid]=1,fa[mid]=ff;
        if(l!=r)build(l,mid-1,mid),build(mid+1,r,mid);
        up(mid);
    }
}T;
```

理解：

1.STL无法执行排名与数值的相互查询

2.treap是通过递归回溯完成整棵树的更新，splay是通过每一次修改操作后的splay到根操作完成整颗树的更新

3.对于传统的区间操作，splay可不是有序二叉树，而是通过中序遍历维持大小关系

# FHQ_treap

```cpp
int x,y,z;
struct fhq_treap
{
	int data[N],fix[N],ch[N][2],size[N],root,cnt;
	void up(int x){size[x]=size[ch[x][0]]+size[ch[x][1]]+1;}
	int newn(int key){return data[++cnt]=key,fix[cnt]=rand(),ch[cnt][0]=ch[cnt][1]=0,up(cnt),cnt;}
	int merge(int x,int y)
	{
		if(!x||!y)return x+y;//down(x),down(y);
		if(fix[x]<fix[y])return ch[x][1]=merge(ch[x][1],y),up(x),x;
		else return ch[y][0]=merge(x,ch[y][0]),up(y),y;
	}
	void split(int now,int val,int &x,int &y)
	{
		if(!now){x=y=0;return;}
		if(data[now]<=val)x=now,split(ch[now][1],val,ch[now][1],y);
		else y=now,split(ch[now][0],val,x,ch[now][0]);
		up(now);
	}
    /*
    void split(int now,int rank,int &x,int &y)
	{
		if(!now){x=y=0;return;}down(now);
		if(size[l[now]]+1<=rank)x=now,split(r[now],rank-(size[l[now]]+1),r[now],y);
		else y=now,split(l[now],rank,x,l[now]);
		up(now);
	}//根据排名拆分
    */
	void insert(int val){split(root,val,x,y);root=merge(merge(x,newn(val)),y);}
	void del(int val)
	{
		split(root,val,x,z),split(x,val-1,x,y);
		root=merge(merge(x,merge(ch[y][0],ch[y][1])),z);
	}
	int grank(int val)
	{
		split(root,val-1,x,y);
		int ans=size[x]+1;root=merge(x,y);
		return ans;
	}
	int Kth(int x,int rank)
	{
		while(233)
		{
			if(rank<=size[ch[x][0]])x=ch[x][0];
			else if(rank<=size[ch[x][0]]+1)return x;
			else rank-=size[ch[x][0]]+1,x=ch[x][1];
		}
	}
	int pren(int val)
	{
		split(root,val-1,x,y);
		int ans=data[Kth(x,size[x])];root=merge(x,y);
		return ans;
	}
	int nextn(int val)
	{
		split(root,val,x,y);
		int ans=data[Kth(y,1)];root=merge(x,y);
		return ans;
	}
}T; 

```
