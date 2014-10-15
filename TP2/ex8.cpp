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
#include <cstdio>
#include <iostream>

using namespace std;

string file = "ex8.txt";

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

void generate() {
	ofstream myfile;
	myfile.open (file);
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
}

vector<int> splitt(const string &input) {
    vector<int> elems;
	int n;
	istringstream sstr(input);
    while (sstr >> n) {
        elems.push_back(n);
    }
    
    return elems;
}


/* Smart but not working Solution */
void swap(vector<int>& v, int i, int j) {
	int tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
}
int partition(vector<int>& v, int lo, int hi) {
	int i = lo, j = hi+1;
	while (true) {
		while (v[++i] < v[lo])
			if (i == hi) 
				break;
		while (v[lo] < v[--j]);
			if (i >= j) 
				break;
		swap(v, i, j);
	}
	swap(v, lo, j);
	return j;
}

int select(const vector<int>& v, int k) {
	vector<int> aux = v;
	random_shuffle(aux.begin(), aux.end() - 1);
	int lo = 0, hi = v.size() - 2;
	while (hi > lo) {
		int j = partition(aux, lo, hi);
		if (j < k) 
			lo = j + 1;
		else if (j > k) 
			hi = j - 1;
		else return 
			aux[k];
	}
	return aux[k];
}

/* Brute force */
int brute_force(vector<int> v, int k) {
	sort(v.begin(), v.end());
	return v[k-1];
}

int main (int argc, char const* argv[])
{
	generate();
	ifstream myfile(file);
	int n = 0;
	myfile >> n >> ws;
	while (n--) {
		string input;
		getline(myfile,input);
		
		cout << input << endl;
		
		vector<int> v = splitt(input);
		int k = v[0];
		v.erase(v.begin());
		
		int res_brute = brute_force(v, k);
		int res = select(v, k);
		
		cout << "Res brute force " << res_brute << endl;
		cout << "Res bugged function " << res << endl << endl;
	}
	myfile.close();
	
	return 0;
}
