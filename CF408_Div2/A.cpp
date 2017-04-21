#include <algorithm>  
#include <iostream>
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
#include <random>

using namespace std;

int main()
{
	int m,n,k;
	cin >> n >> m >> k;
	vector<int> list(n+1, 0);
	for(int i=1; i<=n; i++)
	{
		int temp;   cin >> temp;
        list[i] = temp;
	}
	int l=m-1, r=m+1, count=1;

	while(1<=l || r<=n)
	{
		if(1<=l)
		{
			if(list[l]!=0 && list[l]<=k) break;
		}
		if(r<=n)
		{
			if(list[r]!=0 && list[r]<=k) break;
		}
		l--;r++;count++;
	}
	cout << count*10 << endl;
	return 0;
}