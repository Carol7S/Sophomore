#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    set<double> s;
    s.insert(10.1);
    s.insert(20.2);
    s.insert(50.5);
    s.insert(30.3);
    s.insert(11.1);
    
    for(auto it=s.begin(); it!=s.end(); ++it)
    {
        cout << *it << endl;
    }
    
    system("pause");
    return 0;
}