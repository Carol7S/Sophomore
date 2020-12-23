#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<char> s;
    int i;
    char c = 'a';
    for(i=0; i<26; i++)
    {
        s.push(c+i);
    }
    for(i=0; i<26; i++)
    {
        cout << s.top() << endl;
        s.pop();
    }
    system("pause");
    return 0;
}