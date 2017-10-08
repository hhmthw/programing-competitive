#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
const int N=110;
int a[N][N], n, m, d;
ii nxt[5] = {{0,0},{-1,0},{0,1},{1,0},{0,-1}};
bool vis[N][N];

int main()
{
    //freopen("input.txt","r",stdin);
    char ch;
    int pin1, pin2, st, ans;
    while (1) {
        ans = 0;
        scanf("%d%d%d",&n,&m,&d);
        if (n==0 && m==0 && d==0)
            break;
        getchar();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = getchar();
                if (a[i][j]!='*' && a[i][j]!='#' && a[i][j]!='.') {
                    switch (a[i][j]) {
                    case 'O': st = 4; break;
                    case 'L': st = 2; break;
                    case 'N': st = 1; break;
                    case 'S': st = 3; break;
                    }
                    pin1 = i;
                    pin2 = j;
                }
            }
            getchar();
        }
        int t1, t2;
        memset(vis,true,sizeof(vis));
        for (int i = 0; i < d; i++) {
            ch = getchar();
            if (ch=='F') {
                t1 = pin1+nxt[st].first;
                t2 = pin2+nxt[st].second;
                if (t1<0 || t1>=n || t2<0 || t2>=m || a[t1][t2]=='#')
                    continue;
                pin1 = t1;
                pin2 = t2;
                if (a[pin1][pin2]=='*' && vis[pin1][pin2]) {
                    vis[pin1][pin2] = false;
                    ++ans;
                }
            }
            else if (ch=='D') if (st==4) st = 1; else st+=1;
            else if (st==1) st = 4;
            else st-=1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
