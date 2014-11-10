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

using namespace std;

class union_find{
private:
	std::vector<int> id; // id[i] = parent of i
	std::vector<int> sz;//sz[i] = number of objects in subtree rooted at i
	int count; // number of components
	
public:
	union_find(int N) {
		count = N;
		id.assign(N, 1);
		sz.assign(N, 0);
		for (int i = 0; i < N; i++) {
			id[i] = i;
			sz[i] = 1;
		}
	}
	
	int nb_components() {
		return count;
	}
	
	int size_set(int i) {
		return sz[find_set(i)];
	}
	
	int find_set(int i) {
		return (id[i] == i) ? i : (id[i] = find_set(id[i]));
	}
	
	bool connected(int i, int j) {
		return find_set(i) == find_set(j);
	}
	
	void union_set(int p, int q) {
		int i = find_set(p);
		int j = find_set(q);
		if (i == j) return;
		// make smaller root point to larger one
		if (sz[i] < sz[j]) {
			id[i] = j; sz[j] += sz[i]; 
		} else {
			id[j] = i; sz[i] += sz[j];
		}
		count--;
	}
};

int main (int argc, char const* argv[])
{
	int rg = 1;
	int n, m;
	
	while ((cin >> n >> m) && n != 0){

		union_find network(n);

		while (m--) {
			int a, b;	
			cin >> a >> b >> ws;
			
			network.union_set(--a, --b);
		
		}
		
		cout << "Case " << rg++ << ": " << network.nb_components() << endl;
	}

	
	
	return 0;
}
