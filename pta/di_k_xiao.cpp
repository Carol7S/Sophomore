#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[1000005];
int findmid(int a[], int l, int r)
{
    if (l == r)
        return a[l];
    int n = 0;
    int i = 0;
    for (i = l;i< r-5; i+=5){
        sort(a+i,a+i+5);
        n = i - l;
        swap(a[i+2], a[l+n/5]);
    }
    int num = r-i+1;
    if (num > 0){
        sort(a+i, a+i+num);
        n = i- l;
        swap(a[l+n/5], a[i+num/2]);
    }
    n /= 5;
    if (n == l)
        return a[l];
    else
        return findmid(a, l, l+n);

}

int findindex(int a[], int l, int r, int num)
{
    for (int i = l; i <= r; i++)
        if (a[i] == num)
        return i;
    return -1;
}

int parition(int a[], int l, int r, int p)
{
    swap(a[p], a[l]);
    int left = l, right = r;
    int base = a[l];
    while (left < right){
        while (left < right && a[right] >= base)
            right--;
        a[left] = a[right];
        while (left < right && a[left] <= base)
            left++;
        a[right] = a[left];
    }
    a[left] = base;
    return left;
}

int BFPRT(int a[], int l, int r, int k)
{
    int num = findmid(a, l, r);
    int top = findindex(a, l, r, num);
    int left = parition(a, l, r, top);
    if (left == k-1)
        return a[left];
    else if (left > k-1)
        return BFPRT(a, l, left-1, k);
    else
        return BFPRT(a, left+1, r, k);
}


int main()
{
    int n;
    int k;
    scanf("%d %d", &n, &k);
    for (int i =0; i < n; i++)
        scanf("%d", &a[i]);
    printf("%d\n", BFPRT(a, 0, n-1, k));
    return 0;
}