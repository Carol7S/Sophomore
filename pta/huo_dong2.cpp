#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn = 1e4;

int n, x[Maxn], y[Maxn], cnt=0, p;

int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> x[i] >> y[i];
    }
    sort(x, x+n);
    sort(y, y+n);
    cnt++;
    p = y[0];
    for(int i=1; i<n; i++)
    {
        if(x[i]>=p)
        {
            cnt++;
            p = y[i];
        }
    }
    cout << cnt << endl;
    system("pause");
    return 0;
}