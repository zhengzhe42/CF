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
#include <cassert>
#include <ctime>
#include <climits>
#include <random>
#include <utility>      // std::pair, std::make_pair
#include <unordered_set>

#define scan(x) scanf("%d",&x)
using namespace std;

bool list[1000100];
int main()
{
	
	int m,n,k;
	cin >> n >> m >> k;
	for(int i=0; i<m; i++)
	{
		int temp;
		scan(temp);
		list[temp]=1;
	}
	int point=1;
	for(int i=0; i<k; i++)
	{
		int temp1, temp2;   
		scan(temp1); scan(temp2);
		if(temp1==point && list[point]==0) point = temp2;
		else if(temp2==point && list[point]==0) point = temp1;
	}
	cout << point << endl;
	
	return 0;
}

