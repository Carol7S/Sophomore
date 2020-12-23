#include <algorithm>
#include <iostream>

using namespace std;

const int Maxn=1e4;

int main()
{
    int n,a[Maxn],b[Maxn],i,ans=0,j=0;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> a[i] >> b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    for(i=0;i<n;i++)
    {
        if(a[i]<b[j])
            ans++;
        else
            j++;
    }
    cout << ans << endl;
    system("pause");
    return 0;
}

