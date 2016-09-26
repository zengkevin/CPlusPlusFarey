// CPPFarey.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main()
{
	int i;

	while (true)
	{
		cin >> i;

		if (i<=0) break;

		cout << 0 << "/" << i << endl;

		for (int m = 1; m <= i; m++)
		{
			int x = m, y = i;

			for (int n = m; n >= 2; n--)
			{
				if (((m % n) == 0) && ((i % n) == 0))
				{
					x = m / n;
					y = i / n;
					break;
				}
			}

			cout << x << "/" << y << endl;
		}
	}

	return 0;
}

