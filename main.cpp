#include <iostream>
#include <vector>
#include <algorithm>
int n;
using namespace std;

void pop_td(vector<int>& ls)
{
    while (!ls.empty() && ls.back() < 1)
        ls.pop_back();
}

void AncestryIn(vector<int>& ls, int *res)
{
    int f = ls.size();
    for(int x = 0; x < f; x++)
    {
        ls[x] = ls[x] - (f - x);    // Injection & Spreading - Inyectar y Propagar
        (*res)++;
    }
}

void BlastIn(vector<int>& ls,int* res)
{
    if (ls.empty()) {   // Null
        return;
    }
    int last = 0;
    for (int i = 0; i < ls.size(); ++i)
    {
        if (ls[i] > 0)
        {
            last = i;
            break;
        }
    }
    ls[last]--;    // Injection - Inyectar
    for (int i = 0; i < ls.size(); i++) {
        ls[i]--;    // Spreading - Propagar
    }
    (*res)++;
    sort(ls.rbegin(), ls.rend());   // Sort Data
    pop_td(ls); // Delete junk data
    BlastIn(ls, res);   // Recursive
}

int main() 
{
	int t;
	cin >> t;
	while (t > 0)
	{
		cin >> n;
		vector<int> ls(n+1);
		ls[0] = 1;

		for (int i = 1; i < n; i++)
		{
			int pi;
			cin >> pi;
			ls[pi]++;   // Amount of data per ancestor
		}

		sort(ls.rbegin(), ls.rend());   // Sort Data
		pop_td(ls); // Delete junk data
		int res = 0;
        AncestryIn(ls, &res);   // Injects all the ancestors and propagates
        sort(ls.rbegin(), ls.rend());   // Sort Data
		pop_td(ls); // Delete junk data
        BlastIn(ls, &res);  // Injects and spreads, more aggressive
		cout << res << endl;

		t--;

	}
    return 0;
}
