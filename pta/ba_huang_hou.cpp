//
// Created by TIGA_HUANG on 2020/10/5.
//

// n皇后问题：优化的回溯法
#include <bits/stdc++.h>

const int maxn = 100 + 10;
using namespace std;

int sum, n, cnt;
int C[maxn];
bool vis[3][maxn];
int Map[maxn][maxn];//打印解的数组

//一般在回溯法中修改了辅助的全局变量，一定要及时把他们恢复原状
void Search(int cur)   //逐行放置皇后
{
    cnt++;
    if (cur == n) 
    {
        sum++;
        if (sum > 1)
            cout << '\n';
        for (int i = 0; i < cur; i++)
            Map[i][C[i]] = 1;//打印解
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (Map[i][j]) 
                {
                    cout << "Q";
                } else
                    cout << ".";
                if (j != n - 1) 
                {
                    cout << ' ';
                } else {
                    cout << '\n';
                }
            }
        }
        memset(Map, 0, sizeof(Map)); //还原
    } 
    else
    {
        for (int i = 0; i < n; i++)  //尝试在 cur行的 各 列 放置皇后
        {
            if (!vis[0][i] && !vis[1][cur + i] && !vis[2][cur - i + n]) //判断当前尝试的皇后的列、主对角线
            {
                vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = true;
                C[cur] = i;//cur 行的列是 i
                Search(cur + 1);
                vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = false;//切记！一定要改回来
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    memset(vis, false, sizeof(vis));
    memset(Map, 0, sizeof(Map));
    sum = cnt = 0;
    Search(0);
    if (!sum) 
    {
        cout << "None" << endl;
    }
    system("pause");
    return 0;
}

