#include <iostream>
#include <unordered_set>

using namespace std;

int t;
unordered_set<int> st;

int main ()
{
    cin >> t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            int m;
            scanf("%d",&m);
            if(!st.count(m))
            {
                printf("%d ",m);
                st.insert(m);
            }
        }
        
        puts("");
        st.clear();
    }

    return 0;
}