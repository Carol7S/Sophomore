#include <iostream>
#include <deque>
#include <iterator>

using namespace std;
#define elem double
void Ave(deque<elem> arr, int n)
{
    elem sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += arr[i];
    }
    sum /= n;
    cout << sum << endl;
}

int main()
{
    int n;
    cin >> n;
    deque<elem> arr(n);
    int i;
    for(i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    for(i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    Ave(arr, n);
    system("pause");
    return 0;
}