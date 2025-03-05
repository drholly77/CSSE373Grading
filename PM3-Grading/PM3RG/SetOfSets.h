#pragma once
#pragma once
#include "IntSet.h"

static Boolean setEqual(IntegerSet& s1, IntegerSet& s2) {
	return s1 == s2;
}
typedef SetEqCapability1<IntegerSet, Set1<IntegerSet, setEqual>> SetOfIntegerSets;