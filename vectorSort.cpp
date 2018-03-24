#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

	int n;
	vector<int> v;
	
	cin >> n;
	int m;
	for (int i = 0; i < n; i++) {
		cin >> m;
		v.push_back(m);
	}

	sort(v.begin(), v.end());

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}



	return 0;
}