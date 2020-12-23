#include <iostream>
#include <cstdio>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <stack>
#include <list>
#include <vector>
#include <set>
using namespace std;
 
typedef long long ll;
 
int main()
{
	int v,e,k;
	cin>>v>>e>>k;
	
	vector<int> vec[v];
	
	for(int i=0;i<e;i++)
    {
		int a,b;
		cin>>a>>b;
		vec[a-1].push_back(b-1);
		vec[b-1].push_back(a-1);
	}

	int t;
	
	cin>>t;
	
	for(int i=0;i<t;i++){
		bool flag = true;
		
		set<int> s; 
		
		int b[v];
		for(int j=0;j<v;j++){
			cin>>b[j];
			s.insert(b[j]);
		}
		
		if(s.size() != k){ //第三个测试点坑啊！！！
			cout<<"No"<<endl;
			continue;
		}
		
		for(int j=0;j<v;j++){
			for(vector<int>::iterator it = vec[j].begin();it!=vec[j].end();it++){
				if(b[*it] == b[j]){
					flag = false;
					break;
				}
			}
			if(!flag){
				break;
			}
		}
		
		if(flag){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
	system("pause");
	return 0;
}