#include "stdafx.h"
#include "FareyGenerator.h"


FareyGenerator::FareyGenerator()
{
}


FareyGenerator::~FareyGenerator()
{
}


bool FareyGenerator::FareyGeneration(int base, vector<fraction>& fareySet)
{
	for (int m = 1; m <= base; m++)
	{
		int x = m, y = base;

		for (int n = m; n >= 2; n--)
		{
			if (((m % n) == 0) && ((base % n) == 0))
			{
				x = m / n;
				y = base / n;
				break;
			}
		}

		fareySet.push_back({ x, y });
	}

	return true;
}
