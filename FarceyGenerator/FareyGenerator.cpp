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

shared_ptr<fraction> FareyGenerator::FareyGeneration(int base)
{
	shared_ptr<fraction> p(new fraction[base]);

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

		(p.get()+m-1)->numerator = x;
		(p.get()+m-1)->denominator = y;
	}

	return p;
}
