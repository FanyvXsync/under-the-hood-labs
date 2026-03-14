#include <iostream>
#include <set>

using namespace std;

typedef long long LL;

const LL INF = 1e9+10;
int m;
int c,l;




set<int> st;

void into(int l)
{
    if(st.count(l))
    {
        cout << "Already Exis" << endl;
       
    }
    else
    {
        st.insert(l);
    }

    return ;
}

void output(int l)
{
    if(st.size()==2)
    cout << "Empty" << endl;
    else
    {
        auto it = st.lower_bound(l);
        auto tmp = it;
        tmp--;

        if(abs(*tmp-l) <= abs(*it-l))
        {
            cout << *tmp << endl;
            st.erase(*tmp);
        }
        else
        {
            cout << *it << endl;
            st.erase(*it);
        }
    }
    
}


int main ()
{
    cin >> m;
    st.insert(-INF);
    st.insert(INF);

    while(m--)
    {
        cin >> c >> l;

        if(c==1)
        into(l);
        else
        output(l);

    }


    return 0;
}