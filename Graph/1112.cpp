#include <bits/stdc++.h>
using namespace std;

const int oo = 1e8;
const int N = 110;

int a[N][N], n, m, ex, timer, T;

void solve()
{
    int ans = 0;
    for (int i=1; i<=n; i++)
        a[i][i] = 0;
    for (int k=1; k<=n; k++)
        for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
        if (a[i][j] > a[i][k]+a[k][j])
            a[i][j] = a[i][k]+a[k][j];
    for (int i=1; i<=n; i++)
        if (a[i][ex] <= timer)
            ++ans;
    printf("%d\n",ans);
    if (T) printf("\n");
}

int main()
{
    int x, y, d;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d%d%d",&n,&ex,&timer,&m);
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
            a[i][j] = oo;
        while(m--) {
            scanf("%d%d%d",&x,&y,&d);
            a[x][y] = d;
        }
        solve();
    }
    return 0;
}
