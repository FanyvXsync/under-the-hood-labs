#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main()
{

	int n = 0;
	cin >> n;
	string s;
	getchar();
	getline(cin, s);

	for (int i = 0; i < s.size(); i++)
	{
		while (s[i]+ n > 'z')
		{
			n -= 26;
		}

		
		if( s[i] + n == 'z')
		{
			s[i] = 'a' + n - 1;
		}
		else
		{
			s[i] = s[i] + n;
		}

	}

	for (auto e : s)
	{
		cout << e;
	}
	return 0;
}
