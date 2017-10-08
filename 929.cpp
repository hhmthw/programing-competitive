#include <bits/stdc++.h>
using namespace std;

const int oo = 1e9+1e6;
const int N = 1e3+10;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int n, m, a[N][N], d[N][N], T;
ii nxt[4] = {{1,0},{-1,0},{0,1},{0,-1}};

void solve()
{
    priority_queue <iii,vector<iii>,greater<iii>> q;
    int u, v, du, t1, t2;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            d[i][j] = oo;
    q.push(iii(a[0][0],ii(0,0)));
    d[0][0] = a[0][0];
    while (q.size()) {
        u = q.top().second.first;
        v = q.top().second.second;
        du = q.top().first;
        q.pop();
        if (d[u][v] != du) continue;
        for (int i = 0; i < 4; i++) {
            t1 = u+nxt[i].first;
            t2 = v+nxt[i].second;
            if (t1>=0 && t1<n && t2>=0 && t2<m && d[t1][t2] > du+a[t1][t2]) {
                d[t1][t2] = du+a[t1][t2];
                q.push(iii(d[t1][t2],ii(t1,t2)));
            }
        }
    }
    printf("%d\n",d[n-1][m-1]);
}

int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            scanf("%d",&a[i][j]);
        solve();
    }
    return 0;
}
