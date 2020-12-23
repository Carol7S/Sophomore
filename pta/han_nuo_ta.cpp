
#include<bits/stdc++.h>
using namespace std;
 
int n,cou=0;
 
void hanio(int n,char a,char b,char c)	//b为中间 
{
	cou++;
	if(n==1)
	{
		printf("%c-->%c\n",a,c);
	}
	else
	{
		hanio(n-1,a,c,b);
		printf("%c-->%c\n",a,c);
		hanio(n-1,b,a,c);
	}
}
 
int main()
{
	cin>>n;
	hanio(n,'A','B','C');
	printf("%d\n",cou);
    system("pause");
	return 0;
}