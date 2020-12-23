#include<iostream>
#include<algorithm>
 
using namespace std;
const int maxn=110;
const int maxv=1010;
 
int n,V;
int dp[maxv]={0},w[maxn],c[maxn];
 
 
int main()
{
	cin>>n>>V;
	for(int i=0;i<n;i++)
	  cin>>w[i]>>c[i];
	for(int i=0;i<n;i++){
		for(int v=V;v>=w[i];v--){
			dp[v]=max(dp[v],dp[v-w[i]]+c[i]);
		}
	}  
	int max=dp[0];
	for(int i=1;i<=V;i++){
		if(max<dp[i])
			max=dp[i];
	}
	cout<<max<<endl;
    system("pause");
    return 0;
}