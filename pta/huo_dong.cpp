#include <iostream>
#include <algorithm>
 
using namespace std;
 
struct tmp
{
    int x;
    int y;
}ls[100010];
 
int cmp(struct tmp a,struct tmp b)//这个函数就代表我上面说的排序规则
{
    if(a.y==b.y)
    {
        return a.x<b.x;
    }
    else
    {
        return a.y<b.y;
    }
}
 
int main()
{
    int i,n,js=0,p;
    cin >> n;
    js=0;
    for(i=0;i<n;i++)
    {
        cin >> ls[i].x >> ls[i].y;
    }
    sort(ls,ls+n,cmp);
    js++;
    p=ls[0].y;//p一直记录结束时间（选择的活动的最后时刻）
    for(i=1;i<n;i++)
    {
        if(ls[i].x>=p)//判断所选的活动的开始时间是否符合题意
        {
            js++;//计数变量+1
            p=ls[i].y;//记录最后的时间
        }
    }
    cout << js << endl;
    system("pause");
    return 0;
}