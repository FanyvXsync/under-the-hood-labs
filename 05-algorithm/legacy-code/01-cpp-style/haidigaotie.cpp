#include <iostream>

typedef long long LL;
using namespace std;
const LL N = 1e5+10;

LL f[N];
LL n,m;
LL ret;
// int A[N],B[N],C[N];
// int a[N],f[N],f2[N];
// int n,m;
// int ret;

// int main()
// {
//     cin >> n >> m;
//     for(int i = 1; i <= m ;i++) cin >> a[i];

//     for(int i = 1; i <= m ; i++)
//     {
//         int l = min(a[i],a[i+1]);
//         int r = max(a[i],a[i+1]);
//         f[l]++;
//         f[r]--;
//     }

//     for(int i = 1; i <= n; i++)
//     {
//         cin >> A[i] >> B[i] >> C[i];
//     }

//     for(int i = 1 ; i <= m ;i++)
//     {
//         f2[i] = f2[i-1] + f[i];
//         ret += min(f2[i] * A[i], C[i] + f2[i] * B[i]);
//     }

//     cout << ret;

//     return 0;
// }
int main()
{
    cin >> n >> m;
    int x;
    cin >> x;
    for(int i = 2; i <= m; i++)
    {
        int y; cin >> y;
        if(x > y) f[x]--,f[y]++;  // 处理从大到小还是从小大
        else f[y]--,f[x]++; // 这里是让 l 到 r-1 全部++

        x = y;
    }

    for(int i = 1 ; i <= n ; i++) f[i] += f[i-1]; // 对差分求一次前缀和

    for(int i = 1; i < n ; i++)
    {
        LL a, b , c;
        cin >> a >> b >> c;

        ret += min(f[i]* a , f[i]*b + c);

    }

    cout << ret << endl;


    return 0;
}

