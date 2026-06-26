#include <iostream>
using namespace std;

int n;


int main ()
{
    cin >> n;
    for(int i=n;i>=0;i--)
    {
        int x; cin >> x;
        
        if(x>0 && i!=n) cout << '+';
        if(x<0) cout << '-';

        x=abs(x);
        if((x!=1&&x!=0) || (x==1&&i==0)) cout << x;

        if(i>1&&x!=0) cout << 'x'<< '^' << i;
        else if (i==1&&x!=0) cout << 'x';
        


    }



    return 0;
}