#pragma once
#include "Set/Set1.hpp"
#include "Set/SetEqCapability.hpp"

static Boolean areEqual(Integer& x1, Integer& x2) {
	return x1 == x2;
}
typedef SetEqCapability1<Integer, Set1<Integer, areEqual>> IntegerSet;