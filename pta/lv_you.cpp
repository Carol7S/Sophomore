#include <iostream>
#include <cstring>
 
using namespace std;
 
int g[502][502][2];
int dis[502]; // 顶点到定源点的最近距离 
bool sed[502]; // selected:是否已加入集合 
const int inf = 0x3f3f3f3f;
 
int main(){
    int n, m, s, d;
    int min;
    int u, v, distance, charge;
    
    cin >> n >> m >> s >> d;
    memset(sed, 0, sizeof(sed));
    for (int i = 0; i < n; i++) // 初始化为最大值 
        for (int j = 0; j <= i; j++)
            g[i][j][0] = g[j][i][0] = g[i][j][1] = g[j][i][1] = inf;
    
    for (int i = 0; i < m; i++){ // 构图 
        cin >> u >> v >> distance >> charge;
        g[u][v][0] = g[v][u][0] = distance;
        g[v][u][1] = g[u][v][1] = charge;
    }
    
    for (int i = 0; i < n; i++) // 初始dis 
        dis[i] = g[s][i][0];
    sed[s] = true; // 源点 
    
    for (int k = 1; k < n; k++){ // Dijkstra 
        min = inf;
        for (int i = 0; i < n; i++){
            if (!sed[i] && dis[i] < min){
                min = dis[i];
                u = i; // 距源点最近的点 
            }
        }
        sed[u] = true; // 加入集合 
        for (int v = 0; v < n; v++){ // 刷新数据 
            if (g[u][v][0]< inf)
                if (dis[u]+g[u][v][0]<dis[v] 
                    || (dis[u]+g[u][v][0]==dis[v] && g[s][u][1]+g[u][v][1]<g[s][v][1])){
                    dis[v] = dis[u] + g[u][v][0];
                    g[s][v][1] = g[s][u][1] + g[u][v][1];
                }
                if (v == d) // 已找到所求终点 
                    break;
        }
    }
    
    cout << dis[d] << " " << g[s][d][1];
    system("pause");
    return 0;
} 