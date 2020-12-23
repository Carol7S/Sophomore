#include <bits/stdc++.h>
const int  N=110;
using namespace std;

int sum, n, cnt;
int C[N];
bool vis[3][N];
int Map[N][N];

void Search(int cur)
{
    cnt++;
    if(cur == n)
    {
        sum++;
        if(sum > 1)
            cout << endl;
        for(int i=0; i<n; i++)
            Map[i][C[i]] = 1;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(Map[i][j])
                    cout << "Q";
                else
                {
                    cout << ".";
                }
                if(j != n-1)
                {
                    cout << " ";
                }
                else
                {
                    cout << endl;
                }
            }
        }
        memset(Map, 0, sizeof(Map));
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            if(!vis[0][i] && !vis[1][cur+i] && !vis[2][cur-i+n])
            {
                vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = true;
                C[cur] = i;
                Search(cur + 1);
                vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = false;
            }
        }
    }
}

int main()
{
    cin >> n;
    //memset(vis, false, sizeof(vis));
    //memset(Map, 0, sizeof(Map));
    //sum = cnt = 0;
    Search(0);
    if(!sum)
    {
        cout << "None" << endl;
    }
    system("pause");
    return 0;
}