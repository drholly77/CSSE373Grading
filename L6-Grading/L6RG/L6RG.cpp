#include "pch.h"
#include "CppUnitTest.h"
#include "wrapper.h"
#include "EnhancedIntQ.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace L6RG
{
	TEST_CLASS(L6RG)
	{
	public:

		TEST_METHOD(UT01Equal)
		{
			IntegerQueue q1, q2;
			Text x1;

			Logger::WriteMessage(L"UT01Equal: q1 == q2;");
			Logger::WriteMessage(L"\tincoming: q1 = <> and q2 = <>");
			Logger::WriteMessage(L"\toutgoing: q1 = <> and q2 = <>");

			// Test set up

			// Execute operation: 


			// Validate ensures: self = rhs
			Assert::IsTrue(q1 == q2, L"q1 == q2");

			// Validate restores parameter mode: restores self
			toText(q1, x1);
			Assert::AreEqual(L"<>", x1, true, L"q1 = <>");

			// Validate restores parameter mode: restores rhs
			toText(q2, x1);
			Assert::AreEqual(L"<>", x1, true, L"q2 = <>");
		} // UT01Equal

		TEST_METHOD(UT02Equal)
		{
			IntegerQueue q1, q2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT02Equal: q1 == q2;");
			Logger::WriteMessage(L"\tincoming: q1 = <17> and q2 = <17>");
			Logger::WriteMessage(L"\toutgoing: q1 = <17> and q2 = <17>");

			// Test set up
			k = 17;
			q1.enqueue(k);
			k = 17;
			q2.enqueue(k);


			// Execute operation: 
			// Validate ensures: self = rhs
			Assert::IsTrue(q1 == q2, L"q1 == q2");

			// Validate restores parameter mode: restores self
			toText(q1, x1);
			Assert::AreEqual(L"<17>", x1, true, L"q1 = <17>");

			// Validate restores parameter mode: restores rhs
			toText(q2, x1);
			Assert::AreEqual(L"<17>", x1, true, L"q2 = <17>");
		} // UT02Equal

		TEST_METHOD(UT03Equal)
		{
			IntegerQueue q1, q2;
			Text x1;

			Logger::WriteMessage(L"UT03Equal: q1 == q2;");
			Logger::WriteMessage(L"\tincoming: q1 = <0,3,6> and q2 = <0,3,6>");
			Logger::WriteMessage(L"\toutgoing: q1 = <0,3,6> and q2 = <0,3,6>");

			// Test set up
			for (int k = 0, z = 3; k < z; k++) {
				Integer j = k * 3;
				q1.enqueue(j);
				j = k * 3;
				q2.enqueue(j);
			}


			// Execute operation: 
			// Validate ensures: self = rhs
			Assert::IsTrue(q1 == q2, L"q1 == q2");

			// Validate restores parameter mode: restores self
			toText(q1, x1);
			Assert::AreEqual(L"<0,3,6>", x1, true, L"q1 = <0,3,6>");

			// Validate restores parameter mode: restores rhs
			toText(q2, x1);
			Assert::AreEqual(L"<0,3,6>", x1, true, L"q2 = <0,3,6>");
		} // UT03Equal

		TEST_METHOD(UT04Equal)
		{
			IntegerQueue q1, q2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT04Equal: !(q1 == q2);");
			Logger::WriteMessage(L"\tincoming: q1 = <0,3,6> and q2 = <0,3,9>");
			Logger::WriteMessage(L"\toutgoing: q1 = <0,3,9> and q2 = <0,3,9>");

			// Test set up
			for (int k = 0, z = 3; k < z; k++) {
				Integer j = k * 3;
				q1.enqueue(j);
			}

			k = 0;
			q2.enqueue(k);
			k = 3;
			q2.enqueue(k);
			k = 9;
			q2.enqueue(k);


			// Execute operation: 
			// Validate ensures: self = rhs
			Assert::IsTrue(!(q1 == q2), L"!(q1 == q2)");

			// Validate restores parameter mode: restores self
			toText(q1, x1);
			Assert::AreEqual(L"<0,3,6>", x1, true, L"q1 = <0,3,6>");

			// Validate restores parameter mode: restores rhs
			toText(q2, x1);
			Assert::AreEqual(L"<0,3,9>", x1, true, L"q2 = <0,3,9>");
		} // UT04Equal

		TEST_METHOD(UT05Inject)
		{
			IntegerQueue q1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT05Inject: q1.inject(k);");
			Logger::WriteMessage(L"\tincoming: q1 = <> and k = 15");
			Logger::WriteMessage(L"\toutgoing: q1 = <15> and k = 0");

			// Test set up
			k = 15;

			// Execute operation: inject
			q1.inject(k);

			// Validate ensures: self = <#x> * #self
			toText(q1, x1);
			Assert::AreEqual(L"<15>", x1, true, L"q1 = <15>");

			// Validate clears parameter mode: clears x
			Assert::AreEqual(0, (int)k, L"k = 0");
		} // UT05Inject


		TEST_METHOD(UT06Inject)
		{
			IntegerQueue q1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT06Inject: q1.inject(k);");
			Logger::WriteMessage(L"\tincoming: q1 = <0> and k = 15");
			Logger::WriteMessage(L"\toutgoing: q1 = <15,0> and k = 0");

			// Test set up
			k = 0;
			q1.enqueue(k);
			k = 15;

			// Execute operation: inject
			q1.inject(k);

			// Validate ensures: self = <#x> * #self
			toText(q1, x1);
			Assert::AreEqual(L"<15,0>", x1, true, L"q1 = <15,0>");

			// Validate clears parameter mode: clears x
			Assert::AreEqual(0, (int)k, L"k = 0");
		} // UT06Inject
		TEST_METHOD(UT07Inject)
		{
			IntegerQueue q1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT07Inject: q1.inject(k);");
			Logger::WriteMessage(L"\tincoming: q1 = <0,0,0> and k = 15");
			Logger::WriteMessage(L"\toutgoing: q1 = <15,0,0,0> and k = 0");

			// Test set up
			for (int j = 0, zeroMax = 3; j < zeroMax; j++) {
				k = 0;
				q1.enqueue(k);
			} // end for
			k = 15;

			// Execute operation: inject
			q1.inject(k);

			// Validate ensures: self = <#x> * #self
			toText(q1, x1);
			Assert::AreEqual(L"<15,0,0,0>", x1, true, L"q1 = <15,0,0,0>");

			// Validate clears parameter mode: clears x
			Assert::AreEqual(0, (int)k, L"k = 0");
		} // UT07Inject



		TEST_METHOD(UT08Inject)
		{
			IntegerQueue q1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT08Inject: q1.inject(k);");
			Logger::WriteMessage(L"\tincoming: q1 = <0,1,2,3,4> and k = 15");
			Logger::WriteMessage(L"\toutgoing: q1 = <15,0,1,2,3,4> and k = 0");

			// Test set up
			for (int j = 0, zeroMax = 5; j < zeroMax; j++) {
				k = j;
				q1.enqueue(k);
			} // end for
			k = 15;

			// Execute operation: inject
			q1.inject(k);

			// Validate ensures: self = <#x> * #self
			toText(q1, x1);
			Assert::AreEqual(L"<15,0,1,2,3,4>", x1, true, L"q1 = <15,0,1,2,3,4>");

			// Validate clears parameter mode: clears x
			Assert::AreEqual(0, (int)k, L"k = 0");
		} // UT08Inject


		TEST_METHOD(UT09FindLocOfX)
		{
			IntegerQueue q1;
			Text x1;
			Integer j;

			Logger::WriteMessage(L"UT09FindLocOfX: q1.findLocOfX(j);");
			Logger::WriteMessage(L"\tincoming: q1 = <15,5,35,7> and j = 35");
			Logger::WriteMessage(L"\toutgoing: q1 = <15,5,35,7> and j = 35");

			// Test set up 
			j = 15;
			q1.enqueue(j);
			j = 5;
			q1.enqueue(j);
			j = 35;
			q1.enqueue(j);
			j = 7;
			q1.enqueue(j);

			j = 35;

			// Validate ensures: q1.findLocOfX(j) = 2
			//Assert::AreEqual(0, (int)q1.length(), L"|q1| = 0");
			Assert::AreEqual(2, (int)q1.findLocOfX(j), L"loc = 2");
			int loc = q1.findLocOfX(j);

			Logger::WriteMessage(L"oh oh, look at me!:");
			toText(loc, x1);
			Logger::WriteMessage(x1);
			// Validate restores parameter mode: restores self, x
			toText(q1, x1);
			Assert::AreEqual(L"<15,5,35,7>", x1, true, L"q1 = <15,5,35,7>");
			Assert::AreEqual(35, (int)j, L"j = 35");

		} // UT09FindLocOfX

		TEST_METHOD(UT10FindLocOfX)
		{
			IntegerQueue q1;
			Text x1;
			Integer j, loc;

			Logger::WriteMessage(L"UT10FindLocOfX: q1.findLocOfX(j);");
			Logger::WriteMessage(L"\tincoming: q1 = <15,5,35,7> and j = 15");
			Logger::WriteMessage(L"\toutgoing: q1 = <15,5,35,7> and j = 15");

			// Test set up 
			j = 15;
			q1.enqueue(j);
			j = 5;
			q1.enqueue(j);
			j = 35;
			q1.enqueue(j);
			j = 7;
			q1.enqueue(j);

			j = 15;

			// Validate ensures: q1.findLocOfX(j) = 0
			Assert::AreEqual(0, (int)q1.findLocOfX(j), L"loc = 0");

			// Validate restores parameter mode: restores self, x
			toText(q1, x1);
			Assert::AreEqual(L"<15,5,35,7>", x1, true, L"q1 = <15,5,35,7>");
			Assert::AreEqual(15, (int)j, L"j = 15");

		} // UT10FindLocOfX
		TEST_METHOD(UT11FindLocOfX)
		{
			IntegerQueue q1;
			Text x1;
			Integer j, loc;

			Logger::WriteMessage(L"UT11FindLocOfX: q1.findLocOfX(j);");
			Logger::WriteMessage(L"\tincoming: q1 = <15,5,35,7> and j = 7");
			Logger::WriteMessage(L"\toutgoing: q1 = <15,5,35,7> and j = 7");

			// Test set up 
			j = 15;
			q1.enqueue(j);
			j = 5;
			q1.enqueue(j);
			j = 35;
			q1.enqueue(j);
			j = 7;
			q1.enqueue(j);


			toText(q1, x1);
			Logger::WriteMessage(x1);

			j = 7;

			// Validate ensures: q1.findLocOfX(j) = 3
			Assert::AreEqual(3, (int)q1.findLocOfX(j), L"loc = 3");

			// Validate restores parameter mode: restores self, x
			toText(q1, x1);
			Assert::AreEqual(L"<15,5,35,7>", x1, true, L"q1 = <15,5,35,7>");
			Assert::AreEqual(7, (int)j, L"j = 7");

		} // UT11FindLocOfX

		TEST_METHOD(UT12FindLocOfX)
		{
			IntegerQueue q1;
			Text x1;
			Integer j;

			Logger::WriteMessage(L"UT12FindLocOfX: q1.findLocOfX(j);");
			Logger::WriteMessage(L"\tincoming: q1 = <19> and j = 19");
			Logger::WriteMessage(L"\toutgoing: q1 = <19> and j = 19");

			// Test set up 
			j = 19;
			q1.enqueue(j);

			j = 19;

			// Validate ensures: q1.findLocOfX(j) = 0
			Assert::AreEqual(0, (int)q1.findLocOfX(j), L"loc = 0");

			// Validate restores parameter mode: restores self, x
			toText(q1, x1);
			Assert::AreEqual(L"<19>", x1, true, L"q1 = <19>");
			Assert::AreEqual(19, (int)j, L"j = 19");

		} // UT12FindLocOfX

	};
}
