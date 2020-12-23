#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
    vector<int> n(101);
    vector<int>::iterator it;
    int i;
    for(i=0; i<=100; i++)
    {
        n[i] = 100+i;
    }
    for(i=0; i<100; i++)
    {
        if(n[i]%7==0)
            cout << n[i] <<" ";
    }
    system("pause");
    return 0;
}