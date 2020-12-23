#include <iostream>
using namespace std;
int a[10001][10001], k;
int main()
{
	int n;
	cin >> n;
	for(int i=1; i<=n; i++)
	{
		a[i][i]=0;
	}
	for(int i=1; i<n; i++)
	{  
		for(int j=i+1; j<=n; j++)
		{
			cin >> a[i][j];
		}
	}
	for(int i=2; i<=n; i++)
	{
		for(int j=i+1; j<=n; j++)
		{
			k=j-i;   //k从1开始
			for(int p=k; p<j; p++)
			{
				if(a[k][j] > a[k][p]+a[p][j])
				{
					a[k][j]=a[k][p]+a[p][j];
				}
			} 
		}
	}
	cout << a[1][n];
    system("pause");
    return 0;
}
