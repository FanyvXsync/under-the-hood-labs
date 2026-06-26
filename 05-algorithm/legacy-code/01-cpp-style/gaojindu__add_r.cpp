#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int a[N], b[N], c[N];
int la, lb, lc;



void add(int c[], int a[], int b[])
{
    for(int i = 0; i < lc; i++)
    {
        c[i] += a[i] + b[i]; 
        c[i + 1] += c[i] / 10;
        c[i] %= 10;

 
    }
    if(c[lc]) lc++;
}

int main()
{
string x, y; cin >> x >> y;

 
la = x.size(); lb = y.size(); lc = max(la, lb);
for(int i = 0; i < la; i++) a[la - 1 - i] = x[i] - '0';
for(int i = 0; i < lb; i++) b[lb - 1 - i] = y[i] - '0';

 
add(c, a, b); // c = a + b


 
for(int i = lc - 1; i >= 0; i--) cout << c[i];
return 0;
}