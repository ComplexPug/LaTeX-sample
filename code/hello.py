int n,m,rt,w[_];
struct node {
    int v,nxt;
}e[_<<1];
int head[_],tot;
void add(int u,int v) {
    e[++tot].v=v;
    e[tot].nxt=head[u];
    head[u]=tot;
}
int siz[_],f[_],dep[_],son[_];
int top[_],idx[_],cnt,dsr[_];
void dfs1(int u,int fa) {
    dep[u]=dep[fa]+1;
    siz[u]=1;
    f[u]=fa;
    for(int i=head[u];i;i=e[i].nxt) {
        int v=e[i].v;
        if(v==fa) continue;
        dfs1(v,u);
        siz[u]+=siz[v];
        if(siz[son[u]]<siz[v]) son[u]=v;
    }
}
void dfs2(int u,int topf) {
    top[u]=topf;
    dsr[++cnt]=u;
    idx[u]=cnt;
    if(!son[u]) return;
    dfs2(son[u],topf);
    for(int i=head[u];i;i=e[i].nxt) {
        int v=e[i].v;
        if(!top[v]) dfs2(v,v);
    }
}
void MM(int x,int y,int ad) {
    while(top[x]!=top[y]) {
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        seg::modify(idx[top[x]],idx[x],ad,1);
        x=f[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    seg::modify(idx[x],idx[y],ad,1);
}
void QQ(int x,int y) {
    int ans=0;
    while(top[x]!=top[y]) {
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        ans+=seg::query(idx[top[x]],idx[x],1);
        x=f[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    ans+=seg::query(idx[x],idx[y],1);
    printf("%d\n",ans);
}
int main() {
    n=read(),m=read(),rt=read();
    for(int i=1;i<=n;++i) w[i]=read();
    for(int i=1;i<n;++i) {
        int u=read(),v=read();
        add(u,v),add(v,u);
    }
    dfs1(rt,0),dfs2(rt,rt);
    seg::build(1,n,1);
    return 0;
}