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

bool sortAlpha(char a, char b) 
{
	if (toupper(a) == toupper(b))
		return a < b;
	else
		return toupper(a) < toupper(b);	
}

int main (int argc, char const* argv[])
{
	int TC = 0;
	cin >> TC >> ws;
	while (TC--)
	{
		string input;
		getline(cin, input);
		sort(input.begin(), input.end(), sortAlpha);
		cout << input << endl;
		while (next_permutation(input.begin(), input.end(), sortAlpha)) {
			cout << input << endl;
		}
	}
	return 0;
}
