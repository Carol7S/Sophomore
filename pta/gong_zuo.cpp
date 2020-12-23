#include<cstdio> 
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1010;
 
int n,minCost=1e9;
int c[maxn][maxn];
bool vis[maxn]={false};
 
void dfs(int i,int curCost)
{
	if(i==n+1) 
    {
	    if(curCost<minCost)
	        minCost=curCost;
	    return;	
	}
	
	for(int j=1;j<=n;j++) 
    {
		if(vis[j]==false && curCost+c[i][j]<minCost)
        {
			vis[j]=true;
			dfs(i+1,curCost+c[i][j]);
			vis[j]=false;
		}
	}
}
 
int main()
{	
	cin>>n;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    cin>>c[i][j];
	dfs(1,0);
	cout<<minCost<<endl;	
    system("pause");
    return 0;
}