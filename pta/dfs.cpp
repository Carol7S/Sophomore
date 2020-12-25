#include <iostream>
#include <algorithm>
using namespace std;
const int N = 105;
int n, a[N], vis[N];

void print()
{
    for(int i=1; i<=n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void dfs(int i)
{
    int j;
    if(i==n+1)
    {
        print();
        return;
    } 
    else
    {
        for(j=1; j<=n; j++)
        {
            if(!vis[j])
            {
                a[i] = j;
                vis[j] = 1; 
                dfs(i+1);
                vis[j] = 0;
            }
        }
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    dfs(1);
    system("pause");
    return 0;
}