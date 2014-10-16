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

vector<int> splitt(const string &input) {
    vector<int> elems;
	int n;
	istringstream sstr(input);
    while (sstr >> n) {
        elems.push_back(n);
    }
    
    return elems;
}

int main() {

	int val_max, nb_boules;

	while (scanf("%d %d", &val_max, &nb_boules) == 2 && (val_max || nb_boules)) {
		
		int i = nb_boules;
		string input;
		getline(cin, input);
		getline(cin, input);
		vector<int> values = splitt(input);

		if (nb_boules == val_max + 1) {
			cout << "Y" << endl;
		} else {
			sort(values.begin(), values.end());
			if (values[0] != 0) {
				cout << "N" << endl;
			} else {
				list<int> possibilities;
				for (int j = 1; j < val_max; j++) {
					possibilities.push_back(j);
				}
				
				for (auto j = values.end(); j != values.begin() + 1 && possibilities.size() > 0; j--) {
					for (auto k = j - 1; k != values.begin(); k--) {
						possibilities.remove(abs(*j - *k));
					}
				}

				if (possibilities.size() > 0) {
					cout << "N" << endl;
				}
				else {
					cout << "Y" << endl;
				}
			}
		}
	}
	return 0;
}
