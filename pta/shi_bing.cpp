#include <iostream>
#include <algorithm>
using namespace std;
#define N 10001
#define ll int
int main()
{
    ll sum=0;
    int n, i;
    ll x[N], y[N];
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> x[i] >> y[i];
    }
    sort(y, y+n);
    sort(x, x+n);
    ll y0 = y[n/2];
    for(i=0; i<n; i++)
    {
        sum += abs(y[i]-y0);
        x[i] -= i;
    }
    sort(x, x+n); //注意，要再排序一次
    ll x0 = x[n/2];
    for(i=0; i<n; i++)
    {
        sum += abs(x[i]-x0);
    }
    cout << sum << endl;
    system("pause");
    return 0;
}