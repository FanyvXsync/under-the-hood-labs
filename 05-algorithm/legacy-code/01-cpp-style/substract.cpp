#include <iostream>

using namespace std;

const int N = 1e6+10;
int a[N],b[N],c[N];
int la,lb,lc;

bool cmp(string& x,string& y)
{
    if(x.size() != y.size()) return x.size() < y.size();

    return x < y;
}

// 一定要先比大小


void Sub(int a[],int b[],int c[])
{
    for(int i=0;i<lc;i++)
    {
        c[i] += a[i] - b[i]; //要加等上，有借位
        if(c[i] < 0) c[i]+=10, c[i+1] -= 1;
    }

    while(lc > 1 && c[lc-1] == 0) lc--;  //处理前导零，是1的话特判一下，注意是左闭右开的。所以是 lc-1

}




int main ()
{
    string x,y;
    cin >> x >> y;
    

    if(cmp(x,y))
    {
        swap(x,y);
        cout << "-";
    }  //一定是先比大小

    la = x.size();
    lb = y.size();
    lc = max(la,lb);

    for(int i=0; i<la;i++) a[i] = x[la-i-1] - '0';
    for(int i=0; i<lb;i++) b[i] = y[lb-i-1] - '0';
    
    Sub(a,b,c);

    for(int i=lc-1;i>=0;i--) cout << c[i];

    return 0;
}