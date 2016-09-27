#include "stdafx.h"
#include "CppUnitTest.h"
#include "../FarceyGenerator/FareyGenerator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CPPUnitTest
{		
	TEST_CLASS(CPPUnitTest)
	{
	public:
		
		TEST_METHOD(FareyGeneration)
		{
			vector<fraction> fareySet;
			vector<fraction> fareySet12 = {
				{1, 12},
				{1, 6}, 
				{1, 4},
				{1, 3},
				{5, 12},
				{1, 2},
				{7, 12},
				{2, 3},
				{3, 4},
				{5, 6},
				{11, 12},
				{1, 1},
			};
			FareyGenerator fareyGenerator;
			fareyGenerator.FareyGeneration(12, fareySet);

			for (vector<fraction>::size_type i = 0; i != fareySet.size(); i++) {
				Assert::AreEqual(fareySet12[i].numerator, fareySet[i].numerator);
				Assert::AreEqual(fareySet12[i].denominator, fareySet[i].denominator);
			}
		}

	};
}