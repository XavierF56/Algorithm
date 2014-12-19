#include "stdafx.h"
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
	int nb;

public:
	union_find(int N) {
		nb = N;
		count = N;
		id.assign(2 * N, 1);
		sz.assign(2 * N, 0);

		for (int i = 0; i < N; i++) {
			id[i] = i + N;
			sz[i] = 1;
		}

		for (int i = N; i < 2 * N; i++) {
			id[i] = i;
			sz[i] = 1;
		}
	}

	int nb_components() {
		return count;
	}

	int size_set(int i) {
		return sz[find_set(i)] / 2;
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
		}
		else {
			id[j] = i; sz[i] += sz[j];
		}
		count--;
	}

	void move(int p, int q) {
		int i = find_set(p);
		int j = find_set(q);
		if (i == j) return;

		int grandpapa = id[id[p]];
		int papa = id[p];

		if (sz[papa] > 1) {
			sz[papa]--;
			id[p] = p;
			union_set(p, q);
			count++;
		} else {
			if (id[papa] != papa) {
				sz[grandpapa] -= 1;
				id[papa] = papa;
				count++;
			}
			union_set(p, q);
		}		
	}

	int sum(int p) {
		int tmp = 0;

		for (int i = 0; i < nb; i++) {
			if (connected(i, p)) {
				tmp += i;
			}
		}

		return tmp;
	}
};

vector<int> split(const string &input) {
	vector<int> elems;
	int n;
	istringstream sstr(input);
	while (sstr >> n) {
		elems.push_back(n);
	}

	return elems;
}


int main(int argc, char const* argv[])
{
	int rg = 1;
	int n, m;

	cin >> n >> m;

	union_find network(n);

	while (m-- != 0){
		string input;
		getline(cin, input);
		vector<int> cmd = split(input);

		switch (cmd[0]) {
		case 1:
			network.union_set(cmd[1], cmd[2]);
			break;
		case 2:
			network.move(cmd[1], cmd[2]);
			break;
		case 3:
			int size = network.size_set(cmd[1]);
			int sum = network.sum(cmd[1]);
			cout << size << " " << sum << endl;
		}
	


//		cout << "Case " << rg++ << ": " << network.nb_components() << endl;
	}



	return 0;
}