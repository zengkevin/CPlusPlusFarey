#pragma once
#include <vector>
using namespace std;

struct fraction {
	int numerator;
	int denominator;
};

#ifdef FARCEYGENERATOR_EXPORTS
#define FARCEYGENERATOR_API __declspec(dllexport)
#else
#define FARCEYGENERATOR_API __declspec(dllimport)
#endif

class FARCEYGENERATOR_API FareyGenerator
{
public:
	FareyGenerator();
	~FareyGenerator();

public:
	bool FareyGeneration(int base, vector<fraction>& fareyPairs);
};

