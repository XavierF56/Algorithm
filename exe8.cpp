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

list<int> generate_random_list(int min_size, int max_size, int min_value, int max_value) {
	list<int> res;
	default_random_engine dre(chrono::system_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> s(min_size, max_size);
	uniform_int_distribution<int> di(min_value, max_value);
	int size = s(dre);
	for (int i=0; i<size; ++i) {
		res.push_back(di(dre));
	}
	return res;
}

int generate_random_int(int min_value, int max_value) {
	int res;
	default_random_engine dre(chrono::system_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> di(min_value, max_value);
	res = di(dre);
	return res;
}

int main (int argc, char const* argv[]) {
	ofstream myfile;
	myfile.open ("exo8.txt");
	int test = generate_random_int(1,10);
	myfile << test << endl;
	for (int i = 0; i < test; i += 1) {
		list<int> list = generate_random_list(1, 20, 1, 100);
		int search = generate_random_int(1, list.size());
		myfile << search << " ";
		for (auto j = list.begin(); j != list.end(); j ++) {
			myfile << *j << " ";
		}
		myfile << endl;
	}
	myfile.close();
	
	return 0;
}
