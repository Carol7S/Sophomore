#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int m[1001][1001],s[1001][1001];

void matrix_chain(int a[], int n)
{
	int l, i, j, k, tmp;
	for(l=2; l<=n; l++)
	{
		for(i=1; i<=n-l+1; i++)		//长度为l的区间，其最小下标为1～n-l+1
		{
			j=i+l-1;
			m[i][j] = 0x7fffffff;
			for(k=i; k<j; k++)		//i~k, k+1~j, 所以k<j
			{
				tmp = m[i][k]+m[k+1][j]+a[i-1]*a[k]*a[j];
				if(tmp < m[i][j])
				{
					m[i][j] = tmp;
					s[i][j] = k;
				}
			}
		}
	}
 
}

int main()
{
	int n, a[1002];
	int i,j,l;
	cin >> n;	
	for(i=0; i<n+1; i++)
		cin >> a[i];
	for(i=0; i<n+1; i++)
		m[i][i] = 0;
	matrix_chain(a, n);
	cout << m[1][n] << endl;
    system("pause");
	return 0;
}