# Link Cut Tree——解决动态树问题的利器
## 前置技能
~~1. splay~~ 

2.splay区间操作 ~~（就是能完全代替线段树的内种）~~ 

此时的splay已不再是从前的那个~~纯洁的~~ splay，甚至都不是有序二叉树，而是通过**中序遍历**序来维持（位置、排名等）**大小关系**，模板题奉上

[splay区间操作~~线段树~~模板题 洛谷P3372 ](https://www.luogu.org/problemnew/show/P3372)

[My code](https://www.luogu.org/recordnew/show/16972910)

(真正的勇士，敢于直面[洛谷 P2042](https://www.luogu.org/problemnew/show/P2042)）

还有，**区间翻转**是重点

3.树链剖分的基本思想和实现

## 正式讲解

### 定义&性质

儿子：重（偏爱）儿子、轻儿子（这里一个节点只能有一个重儿子，但可以是任意儿子）

边：实边（重边），虚边（轻边）

链：重链（偏爱链，链接重边的链）

也就是说除了不能保证子树大小，其他定义及性质均与树剖相似

LCT维护的是**所有重链（可以是一个点）构成的splay森林**，其中以**树的深度**作为中序遍历排列的依据

### 操作


1. pushup&pushdown 同splay，这里pushdown主要下传翻转标记

2. up_down(这名是我瞎起的，别人叫clear)down掉从当前节点到根节点的所有节点，以免向上splay时出错

```cpp
void up_down(int x)
    {
        if(nroot(x))up_down(fa[x]);
        down(x);
		/*
		sta[++cnt]=x;
		while(nroot(x))sta[++cnt]=x=fa[x];
		while(cnt)down(sta[cnt--]);
		*/
    }
```


3. not_root x不是根节点

```cpp
bool nroot(int x){return fa[x]&&ch[fa[x]][x==ch[fa[x]][1]]==x;}
//fa[x]&&(ch[fa[x]][0]==x||ch[fa[x]][1]==x)
```

4. rotate

在LCT中，你可以叫你的父亲爸爸，但是如果你的父亲不承认你是他的偏爱儿子，你也丝毫没有办法，这种情况只发生在你是根的时候

```cpp
void rotate(int x)
    {
        int y=fa[x],z=fa[y],k=x==ch[y][1],w=ch[x][k^1];
        if(nroot(y))ch[z][y==ch[z][1]]=x;fa[x]=z;//一定要在前面，而且不能丢掉判断是否是根节点
        ch[y][k]=w;if(w)fa[w]=y;
        ch[x][k^1]=y,fa[y]=x;
        up(y),up(x);
    }
```

5. splay&splay到根的儿子

```cpp
    void splay(int x)
    {
        up_down(x);
        while(nroot(x))
        {
            int y=fa[x],z=fa[y];
            if(nroot(y))
                rotate((x==ch[y][0])^(y==ch[z][0])?x:y);
            rotate(x);
        }
    }
    void splay_next(int x)
    {
        up_down(x);
        while(nroot(fa[x]))
        {
            int y=fa[x],z=fa[y];
            if(nroot(z))
                rotate((x==ch[y][0])^(y==ch[z][0])?x:y);
            rotate(x);
        }
    }
```

5. **核心操作**：access

access的作用就是构造从当前节点到根节点的重链splay
具体过程就是先splay到次根，再顺着虚边替换掉父节点的右子树（深度更深的点集），此处可再网上找到图片演示

```cpp
	void access(int x)
    {
    	for(int y=0;x;x=fa[y=x])
        	splay(x),ch[x][1]=y,up(x);
    }
```

6. makeroot

此操作顾名思义——换根。通过想(shou)象(tui)我们可以得知，在换根前后，只有从整个LCT的根节点到该节点的链上的边，端点的父子关系，即splay里的**相对大小关系**发生翻转，因此我们只需构造x—>root的splay，然后整体翻转就大功告成

```cpp
void makeroot(int x){access(x),splay(x),pushr(x)/*翻转标记*/;}
```

7. linked(+split)

该操作作用是检验两点是否联通，并且若联通则事实上构造了一条重链，具体操作为构造重链，将两端点分别splay到根和其右儿子，然后判断

```cpp
bool linked(int x,int y)
    {
        makeroot(x),access(y);
    	splay(x),splay_next(y);
    	return fa[y]==x;
    }
```
8. link

连边；此操作很好理解，直接把一端点splay后连一条虚边即可

```cpp
void Link(int x,int y){if(!linked(x,y))fa[x]=y;}//顺序不能颠倒

/*
若确定不连通，则直接
makeroot(x),fa[x]=y;
*/
```
9. cut

删边；思路相似，但需要保证两端点直接相连，也就是右儿子没有左儿子

```cpp
void Cut(int x,int y)
    {
    	if(linked(x,y)&&!ch[y][0])fa[y]=ch[x][1]=0,up(x);
    }
```
*其他大佬还有找根判断的link,cut做法，请读者自行理解
```cpp
    /*
    int findroot(int x)
    {
        access(x),splay(x);
        while(ch[x][0])x=ch[x][0],down(x);
        splay(x);
        return x;
    }
    void Link(int x,int y)
    {
        makeroot(x);
        if(findroot(y)!=x)fa[x]=y;
    }
    void Cut(int x,int y)
    {
        makeroot(x);
        if(findroot(y)==x&&fa[y]==x&&!ch[y][0])
        {
            fa[y]=ch[x][1]=0;
            up(x);
        }
    }*/
```

完整代码
```cpp
struct LCT
{
    int data[N],ch[N][2],fa[N],sum[N];bool tag[N];
    bool nroot(int x){return fa[x]&&ch[fa[x]][x==ch[fa[x]][1]]==x;}
    void pushr(int x){swap(ch[x][0],ch[x][1]),tag[x]^=1;}
    void up(int x){sum[x]=sum[ch[x][0]]^sum[ch[x][1]]^data[x];}
    void down(int x)
    {
        if(tag[x])
        {
            if(ch[x][0])pushr(ch[x][0]);
            if(ch[x][1])pushr(ch[x][1]);
            tag[x]=0;
        }
    }
    void rotate(int x)
    {
        int y=fa[x],z=fa[y],k=x==ch[y][1],w=ch[x][k^1];
        if(nroot(y))ch[z][y==ch[z][1]]=x;fa[x]=z;//一定要在前面
        ch[y][k]=w;if(w)fa[w]=y;
        ch[x][k^1]=y,fa[y]=x;
        up(y),up(x);
    }
    void up_down(int x)
    {
        if(nroot(x))up_down(fa[x]);
        down(x);
    }
    void splay(int x)
    {
        up_down(x);
        while(nroot(x))
        {
            int y=fa[x],z=fa[y];
            if(nroot(y))
                rotate((x==ch[y][0])^(y==ch[z][0])?x:y);
            rotate(x);
        }
    }
    void splay_next(int x)
    {
        up_down(x);
        while(nroot(fa[x]))
        {
            int y=fa[x],z=fa[y];
            if(nroot(z))
                rotate((x==ch[y][0])^(y==ch[z][0])?x:y);
            rotate(x);
        }
    }
    void access(int x)
    {
    	for(int y=0;x;x=fa[y=x])
        	splay(x),ch[x][1]=y,up(x);
    }
    void makeroot(int x){access(x),splay(x),pushr(x);}
    bool linked(int x,int y)
    {
        makeroot(x),access(y);
    	splay(x),splay_next(y);
    	return fa[y]==x;
    }
    void Link(int x,int y){if(!linked(x,y))fa[x]=y;}//顺序不能颠倒
    void Cut(int x,int y)
    {
    	if(linked(x,y)&&!ch[y][0])fa[y]=ch[x][1]=0,up(x);
    }
}T;
```

### 例题

1.[P3690](https://www.luogu.org/problemnew/show/P3690)必过模板题

2.[NOI2014魔法森林](https://www.luogu.org/problemnew/show/P2387)

对于这些在边上乱搞的题，我们只需将边转化为一点，分别连接两端点，即可转化普通题目

动态最小生成树，需要在线判环，并删去环上最劣答案边

3. [P4219](https://www.luogu.org/problemnew/show/P4219)

LCT维护子树，作为扩展知识了解
