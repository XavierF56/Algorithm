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

vector<tuple<int, int>> save; 

typedef tuple<int, int, int> couple_ws;
 
bool mycompare (const couple_ws &lhs, const couple_ws &rhs){
	return get<0>(lhs) <= get<0>(rhs);
}


int main (int argc, char const* argv[])
{
	vector<couple_ws> inputs;
	
	string line;
	
	int rg = 1;
	int w, s;
	while (cin >> w >> s) {
		inputs.push_back(make_tuple(w, s, rg++));
	}
	
	save = vector<tuple<int, int>>(inputs.size());
	sort(inputs.begin(), inputs.end(), mycompare);
	for (unsigned int i=0; i<save.size(); i++) {
		if (i==0) {
			save[i] = make_tuple(1, 0);
		} else {
			int max = 0;
			int pred = -1;
			for (unsigned int j = 0; j < i; j += 1)
			{	
				if (get<0>(inputs[j]) != get<0>(inputs[i]) && get<1>(inputs[i]) < get<1>(inputs[j])) {
					if (get<0>(save[j]) > max) {
						max = get<0>(save[j]);
						pred = j;
					}
				}
			}
			save[i] = make_tuple(max + 1, pred);
		}
	}
	
	
	
	tuple<int, int> max = save[0];
	int pos = 0;
	for (unsigned int i = 1; i < save.size(); i += 1)
	{
		if(get<0>(max) < get<0>(save[i])) {
			max = save[i];
			pos = i;
		}
	}
	
	cout << get<0>(max) << endl;
	list<int> output;
	while (pos != -1) {
		output.push_back(get<2>(inputs[pos]));
		pos = get<1>(save[pos]);
	}
	
	output.reverse();
	
	for (auto it = output.begin(); it != output.end(); it ++)
	{
		cout << *it << endl;
	}
	
	return 0;
}
