#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string,int> mp;
int q;
int op,sc;
string name;
int count;

void insert()
{
    cin >> name >> sc;
    mp[name] = sc;
    cout << "OK" << endl;
}

void found()
{
    cin >> name;
    if(mp.count(name))
    {
        cout << mp[name] << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

}

void st_delete()
{
    cin >> name;
    if(mp.count(name))
    {
        mp.erase(name);
        
        cout << "Deleted successfully" << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

}

void st_all()
{
    cout << mp.size() << endl;
}


int main ()
{
    cin >> q;
    while(q--)
    {
        
        cin >> op;
        if(op==1)
        insert();
        else if(op==2)
        found();
        else if(op==3)
        st_delete();
        else
        st_all();


    }

    return 0;
}
