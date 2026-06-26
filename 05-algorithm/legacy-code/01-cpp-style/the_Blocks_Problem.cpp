#include <iostream>
#include <vector>
#include <string>

using namespace std;


typedef pair<int ,int> PII;

const int N = 30;
vector<int> v[N];

PII find(int a,int n)
{
   for(int i=0;i<n;i++)
   {
        for(int j=0;j<v[i].size();j++)
        {
            if(v[i][j] == a)
            {
                return {i,j};
            }

        }
   
   
    }

    return {-1,0};

}


void move_B(int x1,int x2,int y1)
{
    for(int i = y1;i < v[x1].size();i++)
    {
        v[x2].push_back(v[x1][i]);
    }

    v[x1].resize(y1);
}


void clean(int x, int y)
{
    for(int i = y+1;i<v[x].size();i++)
    {
        int tmp = v[x][i];
        v[tmp].push_back(tmp);
    }

    v[x].resize(y+1);


}


int main()
{

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        v[i].push_back(i);
    }

    int a,b;
    string op1,op2;
    
    while(cin >> op1 >> a >> op2 >> b)
    {

        PII p1 =find(a,n);
        int x1 = p1.first, y1 = p1.second;
        PII p2 =find(b,n);
        int x2 = p2.first, y2 = p2.second;


        if(x1 == x2) continue;


        

        if(op1 == "move")
        {
            clean(x1,y1);
        }

        if(op2 == "onto")
        {
            clean(x2,y2);
        }


        move_B(x1,x2,y1);

    }

    for(int i=0;i<n;i++)
    {
        
        cout << i << ":";
        for(int j=0;j<v[i].size();j++)
        {
            cout << " " << v[i][j] ;
        }

        cout << endl;
    }


    return 0;
}
