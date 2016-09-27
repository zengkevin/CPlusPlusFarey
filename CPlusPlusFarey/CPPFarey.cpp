// CPPFarey.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include "../FarceyGenerator/FareyGenerator.h"

using namespace std;

int main()
{
	int i;
	vector<fraction> fareySet;

	FareyGenerator fareyGenerator;

	while (true)
	{
		fareySet.clear();

		cin >> i;
		if (i<=0) break;

		cout << 0 << "/" << i << endl;

		fareyGenerator.FareyGeneration(i, fareySet);

		for (vector<fraction>::iterator it = fareySet.begin(); it != fareySet.end(); ++it) {
			cout << it->numerator << "/" << it->denominator << endl;
		}
	}

	return 0;
}

