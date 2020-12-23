#include <iostream>
#include <list>
#include <iterator>
using namespace std;

int main()
{
    list<int> arr(100);
    list<int>::iterator it;
    //it = arr.begin();
    int i;
    int sum=0;
    for(i=1; i<=100; i++)
    {
        arr.push_back(i);
    }
    for(it=arr.begin(); it!=arr.end(); ++it)
    {
        sum += *it;
    }
    cout << sum << endl;
    system("pause");
    return 0;
}