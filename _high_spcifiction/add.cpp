#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

string a,b;
int na[N],nb[N];
int nc[N];
int la,lb,lc;

void Add(int a[],int b[])
{
    for(int i = 0; i < lc;i++)
    {
        nc[i] += na[i]+nb[i];
        nc[i+1] += nc[i] / 10;
        nc[i]%=10;
    }

    if(nc[lc]) lc++;

}   // 模板问题不大，主要是nc[i+1]里面存着数，记得+=


int main ()
{
    cin >> a >> b;
    la = a.size();
    lb = b.size();
    lc = max(la,lb);

    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());

    for(int i = 0; i < a.size(); i++) na[i] = a[i] - '0';
    for(int i = 0; i < b.size(); i++) nb[i] = b[i] - '0';
    //  这里的逆置可以不用reverse，用下标对应就行  两个下标相加等于 n - 1 


    Add(na,nb);
    
    for(int i = lc-1;i>=0;i--) cout << nc[i];

    return 0;
}