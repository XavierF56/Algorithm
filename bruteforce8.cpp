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
#include <cctype>

using namespace std;

vector<int> splitt(const string &s) {
    vector<int> elems;

    istringstream iss(s);

    do {
        string sub;
        iss >> sub;
        elems.push_back(stoi(sub));
    } while (iss);
    
    return elems;
}

int main (int argc, char const* argv[])
{
	int n = 0;
	cin >> n >> ws;
	while (n--) {
		int k, v;
		string input;
		cin >> input;
		
		vector<int> list = splitt(input);
		sort(list.begin()+1, list.end());	
		
		printf("%d\n", list[list[0]]);
	}
	return 0;
}
