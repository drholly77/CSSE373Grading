#include "pch.h"
#include "CppUnitTest.h"
#include "IntegerList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace L4R
{
	TEST_CLASS(L4R)
	{
	public:

		//********************************************
		// Unit tests for Release mode only
		//********************************************


		// -----------------------------------------------------------------------------------
		// List2()
		// -----------------------------------------------------------------------------------
		//! replaces self
		//! ensures: self = <>
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT01ConstructorV1)
		{
			IntegerList s1;
			Text x1;

			Logger::WriteMessage(L"UT01ConstructorV1: List2();");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>)");

			// Validate ensures: self = (<>,<>)
			toText(s1, x1);
			Assert::AreEqual(L"(<>,<>)", x1, true, L"s1 = (<>,<>)");
		} // UT01ConstructorV1

		// -----------------------------------------------------------------------------------
		// clear
		// -----------------------------------------------------------------------------------
		//! clears self
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT02ClearV1)
		{
			IntegerList s1;
			Text x1;


			Logger::WriteMessage(L"UT02ClearV1: s1.clear();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>)");

			// Execute operation: clear
			s1.clear();

			// Validate clears parameter mode: clears self
			toText(s1, x1);
			Assert::AreEqual(L"(<>,<>)", x1, true, L"s1 = (<>,<>)");
		} // UT02ClearV1

		TEST_METHOD(UT03ClearV2)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT03ClearV2: s1.clear();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<33>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>)");

			// Test set up
			k = 33;
			s1.addRightFront(k);

			// Execute operation: clear
			s1.clear();

			// Validate clears parameter mode: clears self
			toText(s1, x1);
			Assert::AreEqual(L"(<>,<>)", x1, true, L"s1 = (<>,<>)");
		} // UT03ClearV2

		// -----------------------------------------------------------------------------------
		// TransferFrom (self & source)
		// -----------------------------------------------------------------------------------
		//! replaces self
		//! clears source
		//! ensures: self = #source
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT04TransferFromV1)
		{
			IntegerList s1;
			IntegerList s2;
			Text x1, x2;
			Integer k;

			Logger::WriteMessage(L"UT04TransferFromV1: s1.transferFrom(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<>) and s2 = (<>,<44>)");
			Logger::WriteMessage(L"\toutgoing:  s1 = (<>,<44>) and s2 = (<>,<>)");

			// Test set up
			k = 44;
			s2.addRightFront(k);

			// Execute operation: transferFrom
			s1.transferFrom(s2);

			// Validate ensures: self = #source
			toText(s1, x1);
			Assert::AreEqual(L"(<>,<44>)", x1, true, L"s1 = (<>,<44>)");

			//Validate parameter mode clears: clears source
			toText(s2, x2);
			Assert::AreEqual(L"(<>,<>)", x2, true, L"s2 = (<>,<>)");
		} // UT04TransferFromv1

		// -----------------------------------------------------------------------------------
		// = operator
		// -----------------------------------------------------------------------------------
		//! replaces self
		//! restores rhs
		//! ensures: self = rhs
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT05AssignmentV1)
		{
			IntegerList s1;
			IntegerList s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT05AssignmentV1: s1 = s2;");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<>) and s2 = (<>,<17>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<17>) and s2 = (<>,<17>)");

			// Test set up
			k = 17;
			s2.addRightFront(k);

			// Execute operation:  operator =
			s1 = s2;

			// Validate ensures self = rhs
			toText(s1, x1);
			Assert::AreEqual(L"(<>,<17>)", x1, true, L"s1 = (<>,<17>)");
			// Validate restores parameter mode: restores rhs
			toText(s2, x1);
			Assert::AreEqual(L"(<>,<17>)", x1, true, L"s2 = (<>,<17>)");
		} // UT05AssignmentV1

		// -----------------------------------------------------------------------------------
		// AddRightFront (T& x)
		// -----------------------------------------------------------------------------------
		//! updates self.right
		//! clears x
		//! ensures: self.left = #self.left  and  self.right = <#x> * #self.right
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT06AddRightFrontV1)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT06AddRightFrontV1: s1.addRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<21>), k = 35");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<35,21>), k = 0");

			// Test set up
			k = 21;
			s1.addRightFront(k);
			k = 35;

			// Execute operation:  addRightFront
			s1.addRightFront(k);

			// Validate ensures self.left = #self.left and  self.right = <#x> * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"(<>,<35,21>)", x1, true, L"s1 = (<>,<35,21>)");

			// Validate clears parameter mode: clears x
			Assert::AreEqual(0., k, true, L"k = 0");
		} // UT06AddRightFrontV1


		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT16AddRightFrontV2)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT16AddRightFrontV2: s1.addRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<21>,<>), k = 35");
			Logger::WriteMessage(L"\toutgoing: s1 = (<21>,<35>), k = 0");

			// Test set up
			k = 21;
			s1.addRightFront(k);
			k = 35;
			s1.advance();

			// Execute operation:  addRightFront
			s1.addRightFront(k);

			// Validate ensures self.left = #self.left and  self.right = <#x> * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"(<21>,<35>)", x1, true, L"s1 = (<21>,<35>)");

			// Validate clears parameter mode: clears x
			Assert::AreEqual(0., k, true, L"k = 0");
		} // UT16AddRightFrontV2

		// -----------------------------------------------------------------------------------
		// RemoveRightFront (T& x)
		// -----------------------------------------------------------------------------------
		//! updates self.right
		//! replaces x
		//! requires: self.right /= <>
		//! ensures: self.left = #self.left  and
		//!          <x> = #self.right[0,1)  and 
		//!          self.right = #self.right[1,|#self.right|)
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT07RemoveRightFrontV1)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT07RemoveRightFrontV1: s1.removeRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<11,33,55,77,99>), k = 0");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<33,55,77,99>), k = 11");

			//setup test
			k = 99;
			s1.addRightFront(k);
			k = 77;
			s1.addRightFront(k);
			k = 55;
			s1.addRightFront(k);
			k = 33;
			s1.addRightFront(k);
			k = 11;
			s1.addRightFront(k);

			// Execute operation:  removeRightFront
			s1.removeRightFront(k);

			// Validate ensures self.left = #self.left  and self.right = #self.right[1,|#self.right|)
			toText(s1, x1);
			Assert::AreEqual(L"(<>,<33,55,77,99>)", x1, true, L"s1 = (<>,<33,55,77,99>)");

			// Validate ensures <x> = #self.right[0,1)
			Assert::AreEqual(11., k, true, L"k = 11");
		} // UT07RemoveRightFrontV1

		// -----------------------------------------------------------------------------------
		// Advance 
		// -----------------------------------------------------------------------------------
		//! updates self
		//! requires: self.right /= <>
		//! ensures: self.left * self.right = #self.left * #self.right  and
		//!          |self.left| = |#self.left| + 1
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT08AdvanceV1)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT08AdvanceV1: s1.advance();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<11,33,55,77,99>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<11,33>,<55,77,99>)");

			//setup test
			k = 99;
			s1.addRightFront(k);
			k = 77;
			s1.addRightFront(k);
			k = 55;
			s1.addRightFront(k);
			k = 33;
			s1.addRightFront(k);
			k = 11;
			s1.addRightFront(k);

			// Execute operation: advance
			s1.advance();
			s1.advance();

			// Validate ensures self.left * self.right = #self.left * #self.right  and
			//!          |self.left| = |#self.left| + 1
			toText(s1, x1);
			Assert::AreEqual(L"(<11,33>,<55,77,99>)", x1, true, L"s1 = (<11,33>,<55,77,99>)");
		} // UT08AdvanceV1

		// -----------------------------------------------------------------------------------
		// moveToStart
		// -----------------------------------------------------------------------------------
		//! updates self
		//! ensures: self.left = <>  and  self.right = #self.left * #self.right
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT09MoveToStartV1)
		{
			IntegerList s1;
			Text x1, x3;
			Integer k;

			Logger::WriteMessage(L"UT09MoveToStartV1: s1.moveToStart();");
			Logger::WriteMessage(L"\tincoming: s1 = (<11,33>,<55,77,99>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<11,33,55,77,99>)");

			//setup test
			k = 99;
			s1.addRightFront(k);
			k = 77;
			s1.addRightFront(k);
			k = 55;
			s1.addRightFront(k);
			k = 33;
			s1.addRightFront(k);
			k = 11;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();

			// Execute operation: moveToStart
			s1.moveToStart();

			// Validate ensures self.left = <>  and  self.right = #self.left * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"(<>,<11,33,55,77,99>)", x1, true, L"s1 = (<>,<11,33,55,77,99>)");
		} // UT09MoveToStartV1


		// -----------------------------------------------------------------------------------
		// moveToFinish
		// -----------------------------------------------------------------------------------
		//! updates self
		//! ensures: self.right = <>  and  self.left = #self.left * #self.right
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT10MoveToFinishV1)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT10MoveToFinishV1: s1.moveToFinish();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<11,33,55,77,99>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<11,33,55,77,99>,<>)");

			//setup test
			k = 99;
			s1.addRightFront(k);
			k = 77;
			s1.addRightFront(k);
			k = 55;
			s1.addRightFront(k);
			k = 33;
			s1.addRightFront(k);
			k = 11;
			s1.addRightFront(k);

			// Execute operation: moveToFinish
			s1.moveToFinish();

			// Validate ensures self.right = <>  and  self.left = #self.left * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"(<11,33,55,77,99>,<>)", x1, true, L"s1 = (<11,33,55,77,99>,<>))");
		} // UT10MoveToFinishV1



		// -----------------------------------------------------------------------------------
		// replaceRightFront
		// -----------------------------------------------------------------------------------
		//! updates self.right, x
		//! requires: self.right /= <>
		//! ensures: self.left = #self.left  and
		//!          <x> = #self.right[0,1)  and
		//!          self.right = <#x> * #self.right[1, |#self.right|)
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT11ReplaceRightFrontV1)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT11ReplaceRightFrontV1: s1.replaceRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<11,33>,<55,77,99>), k = 200");
			Logger::WriteMessage(L"\toutgoing: s1 = (<11,33>,<200,77,99>),k = 55");

			//setup test
			k = 99;
			s1.addRightFront(k);
			k = 77;
			s1.addRightFront(k);
			k = 55;
			s1.addRightFront(k);
			k = 33;
			s1.addRightFront(k);
			k = 11;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();
			k = 200;

			// Execute operation: replaceRightFront
			s1.replaceRightFront(k);

			// Validate ensures: self.left = #self.left  and self.right = <#x> * #self.right[1, |#self.right|)
			toText(s1, x1);
			Assert::AreEqual(L"(<11,33>,<200,77,99>)", x1, true, L"s1 = (<11,33>,<200,77,99>))");

			// Validate ensures: <x> = #self.right[0,1)
			Assert::AreEqual(55., k, true, L"k = 55");
		} // UT11ReplaceRightFrontV1

		// -----------------------------------------------------------------------------------
		// rightFront
		// -----------------------------------------------------------------------------------
		//! restores self
		//! requires: self.right /= <>
		//! ensures: <rightFront> = self.right[0,1)
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT12RightFrontV1)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT12RightFrontV1: s1.rightFront();");
			Logger::WriteMessage(L"\tincoming: s1 = (<3,7>,<11>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<3,7>,<11>)");

			//setup test
			k = 11;
			s1.addRightFront(k);
			k = 7;
			s1.addRightFront(k);
			k = 3;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();

			// Execute operation: replaceRightFront
			k = s1.rightFront();

			// Validate ensures: <rightFront> = self.right[0,1)
			Assert::AreEqual(11., k, true, L"k = 11");

			// Validate restores parameter mode: restores self
			toText(s1, x1);
			Assert::AreEqual(L"(<3,7>,<11>)", x1, true, L"s1 = (<3,7>,<11>))");
		} // UT12RightFrontV1

		// -----------------------------------------------------------------------------------
		// swapRights
		// -----------------------------------------------------------------------------------
		//! updates self.right, otherS.right
		//! ensures: self.left = #self.left  and  otherS.left = #otherS.left  and
		//!          otherS.right = #self.right  and  self.right = #otherS.right
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT13SwapRightsV1)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT13SwapRightsV1: s1.swapRights(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<3,7>,<11>) and s2 = (<>,<55,77,99>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<3,7>,<55,77,99>) and s2 = (<>,<11>)");

			//setup test
			k = 11;
			s1.addRightFront(k);
			k = 7;
			s1.addRightFront(k);
			k = 3;
			s1.addRightFront(k);

			s1.advance();
			s1.advance();

			k = 99;
			s2.addRightFront(k);
			k = 77;
			s2.addRightFront(k);
			k = 55;
			s2.addRightFront(k);

			// Execute operation: swapRights
			s1.swapRights(s2);

			// Validate ensures: self.left = #self.left  and  self.right = #otherS.right
			toText(s1, x1);
			Assert::AreEqual(L"(<3,7>,<55,77,99>)", x1, true, L"s1 = (<3,7>,<55,77,99>))");

			// Validate ensures:   otherS.left = #otherS.left  and otherS.right = #self.right  
			toText(s2, x1);
			Assert::AreEqual(L"(<>,<11>)", x1, true, L"s2 = (<>,<11>))");
		} // UT13SwapRightsV1


		// -----------------------------------------------------------------------------------
		// leftLength
		// -----------------------------------------------------------------------------------
		//! restores self
		//! ensures: leftLength = |self.left|
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT14LeftLengthV1)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT14LeftLengthV1: s1.leftLength();");
			Logger::WriteMessage(L"\tincoming: s1 = (<11,33>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<11,33>,<>)");

			//setup test
			k = 33;
			s1.addRightFront(k);
			k = 11;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();

			// Validate ensures: leftLength = |self.left|
			Assert::AreEqual(2., s1.leftLength(), true, L"s1.leftLength() = 2");

			// Validate restores parameter mode: restores self
			toText(s1, x1);
			Assert::AreEqual(L"(<11,33>,<>)", x1, true, L"s1 = (<11,33>,<>))");
		} // UT14leftLengthV1



		// -----------------------------------------------------------------------------------
		// rightLength
		// -----------------------------------------------------------------------------------
		//! restores self
		//! ensures: rightLength = |self.right|
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT15RightLengthV1)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT15RightLengthV1: s1.rightLength();");
			Logger::WriteMessage(L"\tincoming: s1 = (<11>,<33,55,77>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<11>,<33,55,77>)");

			//setup test
			k = 77;
			s1.addRightFront(k);
			k = 55;
			s1.addRightFront(k);
			k = 33;
			s1.addRightFront(k);
			k = 11;
			s1.addRightFront(k);
			s1.advance();

			// Validate ensures: rightLength = |self.right|
			Assert::AreEqual(3., s1.rightLength(), true, L"s1.rightLength() = 3");

			// Validate restores parameter mode: restores self
			toText(s1, x1);
			Assert::AreEqual(L"(<11>,<33,55,77>)", x1, true, L"s1 = (<11>,<33,55,77>))");
		} // UT15rightLengthV1






		// -----------------------------------------------------------------------------------
		// ***** Two additional addRightFront tests *****
		// -----------------------------------------------------------------------------------
		// AddRightFront (T& x)
		// -----------------------------------------------------------------------------------
		//! updates self.right
		//! clears x
		//! ensures: self.left = #self.left  and  self.right = <#x> * #self.right
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT17AddRightFrontV3)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT17AddRightFrontV3: s1.addRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<13,17,19>,<29>), k = 23");
			Logger::WriteMessage(L"\toutgoing: s1 = (<13,17,19>,<23,29>), k = 0");

			// Test set up
			k = 29;
			s1.addRightFront(k);
			k = 19;
			s1.addRightFront(k);
			k = 17;
			s1.addRightFront(k);
			k = 13;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();
			s1.advance();
			k = 23;

			// Execute operation:  addRightFront
			s1.addRightFront(k);

			// Validate ensures self.left = #self.left and  self.right = <#x> * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"(<13,17,19>,<23,29>)", x1, true, L"s1 = (<13,17,19>,<23,29>)");

			// Validate clears parameter mode: clears x
			Assert::AreEqual(0., k, true, L"k = 0");
		} // UT17AddRightFrontV3

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT18AddRightFrontV4)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT18AddRightFrontV4: s1.addRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<13,17,19,23>,<>), k = 29");
			Logger::WriteMessage(L"\toutgoing: s1 = (<13,17,19,23>,<29>), k = 0");

			// Test set up
			k = 23;
			s1.addRightFront(k);
			k = 19;
			s1.addRightFront(k);
			k = 17;
			s1.addRightFront(k);
			k = 13;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();
			s1.advance();
			s1.advance();
			k = 29;

			// Execute operation:  addRightFront
			s1.addRightFront(k);

			// Validate ensures self.left = #self.left and  self.right = <#x> * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"(<13,17,19,23>,<29>)", x1, true, L"s1 = (<13,17,19,23>,<29>)");

			// Validate clears parameter mode: clears x
			Assert::AreEqual(0., k, true, L"k = 0");
		} // UT18AddRightFrontV4


	};
}
