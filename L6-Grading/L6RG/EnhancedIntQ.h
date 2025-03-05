#pragma once

#include "Queue/Queue1.hpp"
#include "Queue/AppendCapability1.hpp" // remove this comment when doing TODO #1
#include "Queue/InjectCapability1.hpp" // remove this comment when doing TODO #
#include "Queue/FindLocOfXCapability1.hpp" // remove this comment when doing TODO #2
#include "Queue/QueueEqCapability1.hpp"  // remove this comment when doing TODO #3
typedef Queue1<Integer> IntegerQueueBase1;
typedef AppendCapability1<Integer, IntegerQueueBase1> IntegerQueueBase2;
typedef InjectCapability1<Integer, IntegerQueueBase2> IntegerQueueBase3;

static Boolean areEqual(Integer& lhs, Integer& rhs)
{
	return (lhs == rhs);
}
typedef FindLocOfXCapability1<Integer, IntegerQueueBase3, areEqual> IntegerQueueBase4;

typedef QueueEqCapability1<Integer, IntegerQueueBase4> IntegerQueueBase5;

typedef IntegerQueueBase5 IntegerQueue;