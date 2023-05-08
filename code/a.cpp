#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define int long long
using namespace std;
const int _=2e6+7;
int read() {int x;scanf("%lld",&x);return x;}
int n;
int fx[]={0,0,1,-1,1,-1};
int fy[]={1,-1,0,0,1,-1};
void solve() {
    int n=read();
    
    vector<int> l(20,0),siz(20,0);
    vector vis(20,vector<int>(20,0));
    FOR(i,1,17) {
        l[i]=0x3f3f3f3f;
        if(i<=13) l[i]=min(l[i],5ll);
        if(i>=5) l[i]=min(l[i],i-4ll);
    }
    FOR(i,1,4) siz[i]=siz[17-i+1]=i;
    FOR(i,5,9) siz[i]=siz[17-i+1]=18-i;
    FOR(i,1,17) {
        FOR(j,l[i],l[i]+siz[i]-1) {
            vis[i][j]=1;
        }
    }
    vector g(20,vector<int>(20,0));
    FOR(i,1,n) {
        int x=read(),y=read();
        g[x][l[x]+y-1]=1;
    }
    auto judge=[&](array<int,2> a,array<int,2> b) -> bool {
        if(g[b[0]][b[1]]==0) return 0;
        array<int,2> c={b[0]+b[0]-a[0],b[1]+b[1]-a[1]};
        if(1<=c[0]&&c[0]<=17&&1<=c[1]&&c[1]<=17);else return 0;
        // cout<<"!\n";
        if(vis[c[0]][c[1]]==1&&g[c[0]][c[1]]==0) {
            int x=a[0],y=a[1];
            int ad_x=b[0]-a[0];
            int ad_y=b[1]-a[1];
            if(ad_x!=0) ad_x/=abs(ad_x);
            if(ad_y!=0) ad_y/=abs(ad_y);
            while(233) {
                x+=ad_x,y+=ad_y;
                if(x==c[0]&&y==c[1]) break;
                if(x!=b[0]&&y!=b[1]) if(g[x][y]) return 0;
            }
            return 1;
        }
        return 0;
    };
    int ans=0;
    // FOR(i,1,17) {
    //     FOR(j,1,17) {
    //         cout<<g[i][j];
    //     } cout<<"\n";
    // }
    FOR(i,1,17) FOR(j,1,17) if(g[i][j]) {
        // if(i==3&&j==5);else continue;
        vector f(20,vector<int>(20,0));
        g[i][j]=0;f[i][j]=1;
        queue<array<int,2>> q;
        q.push({i,j});
        while(!q.empty()) {
            auto [x,y]=q.front();q.pop();
            for(int kkk=0;kkk<6;++kkk) {
                int nx=x+fx[kkk],ny=y+fy[kkk];
                while(vis[nx][ny]&&g[nx][ny]==0) nx+=fx[kkk],ny+=fy[kkk];
                if(vis[nx][ny]==0) continue;
                // cout<<g[nx][ny]<<" "<<nx<<" "<<ny<<"!!!\n";
                // continue;
                if(judge({x,y},{nx,ny})==0) continue;
                // cout<<"?\n";
                array<int,2> c={nx+nx-x,ny+ny-y};
                // cout<<c[0]<<" "<<c[1]<<"!\n";
                if(f[c[0]][c[1]]==0) {
                    f[c[0]][c[1]]=1;
                    q.push(c);
                }
            }
        }
        int res=0;
        FOR(i,1,17) FOR(j,1,17) res+=f[i][j];
        ans+=res-1;
        // cout<<i<<" "<<j<<" "<<rses-1<<"\n";
        g[i][j]=1;
    }
    cout<<ans<<"\n";
}
signed main() {
    int T=read();
    while(T--) {
        solve();
    }
    return 0;
}