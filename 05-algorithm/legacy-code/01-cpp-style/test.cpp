#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5+10;
vector<int> v[N];


int main()
{
	int n,q;
	cin >> n >> q;

	while(q--)
	{
		int op,i,j;

		cin >> op >> i >> j;
		if(op ==1)
		{
			int k;
			cin >> k;

			if( v[i].size() <= j )
			{
				v[i].resize(j+1);
			}

			v[i][j] = k;

		}
		if(op==2)
		{
			cout << v[i][j] << endl;
		}



	}


	

	return 0;
}
