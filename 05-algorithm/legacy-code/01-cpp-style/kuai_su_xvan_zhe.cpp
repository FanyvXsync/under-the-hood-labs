#include <iostream>
using namespace std;
const int N = 5e6+10;

typedef long long LL;

int a[N];
int n;
int k;

int get_random(int left , int right)
{
    return a[rand()% (right - left + 1) + left];
}

int quick_select(int left , int right , int k)
{
    if(left >= right) return a[left];

    int mid = (left + right) / 2;
    int p = get_random(left , right);

    int l = left - 1 , i = left , r = right + 1;
    while(i < r)
    {
        if(a[i] < p) swap(a[++l], a[i++]);
        else if(a[i] == p) i++;
        else swap(a[--r],a[i]);
    }

    int a = l - left + 1, b = r - 1 -l , c = right - r + 1;

    if(k <= a) return quick_select(left, l , k);
    else if( k <= a + b) return p;
    else return quick_select(r, right,k - a -b); 
}


int main()
{
    scanf("%d%d",&n,&k);
    k++;
    for(int i = 1; i <= n ; i++) scanf("%d",&a[i]);

   printf("%d",quick_select(1,n,k));

    return 0;
}