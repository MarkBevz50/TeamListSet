#pragma once
#include "set.h"
int digit(int n) // Mark
{
	Set<int> Test;
	while (n > 0)
	{
		int digit = n % 10;
		Test.Add(digit);
		n /= 10;
	}
	return Test.Size();
}