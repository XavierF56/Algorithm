#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <set>
#include <list>
#include <cmath>
#include <random>
#include <chrono>
#include <numeric>

using namespace std;

int main (int argc, char const* argv[])
{
	int n = 0;
	cin >> n >> ws;
	int n_initial = n;
	
	while (n--) {
		int mp = 0;
		int tmp;
		vector<int> p;
		vector<int> q;
		
		cin >> mp >> ws;
		int mq = mp;

		
		while (mp--) {
			scanf("%d", &tmp);

			p.push_back(tmp);
		}
		
		while (mq--) {
			scanf("%d", &tmp);

			q.push_back(tmp);
		}
		
		int sum_p = accumulate(p.begin(), p.end(), 0);
		int sum_q = accumulate(q.begin(), q.end(), 0);
		
		if (sum_p < sum_q) {
			printf("Case %d: Not possible\n", n_initial-n);
		} else {
			int st = 0;
			int pp = 0;
			for (int i = 0; i < p.size(); i += 1) {
				if (p[i] + pp > q[i]) {
					pp = p[i] + pp - q[i];
				} else {
					pp = 0;
					st = i + 1;
				}
			}
			printf("Case %d: Possible from station %d\n", n_initial-n, st + 1);
			
		}
	}
	return 0;
}

/*
2
5
1 1 1 1 1
1 1 2 1 1
7
1 1 1 10 1 1 1
2 2 2 2 2 2 2
*/

