#include <iostream>
#include <algorithm>

using namespace std;
#define N 10001
int main()
{
    int sum=0;
    int n, i;
    int x[N], y[N];
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> x[i] >> y[i];
    }
    sort(y, y+n);
    int y0 = y[n/2];
    for(i=0; i<n; i++)
    {
        sum += abs(y0-y[i]);
    }
    cout << sum << endl;
    system("pause");
    return 0;
}