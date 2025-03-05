#include "pch.h"
#include "CppUnitTest.h"
#include "IntegerList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace L3D
{
	TEST_CLASS(L3D)
	{

	public:


		//********************************************
		// Unit tests for Debug mode only
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

			// Verify ensures: self = (<>,<>)
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<>]", x1, true, L"s1's internal rep = [<>,<>]");
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

			// Verify clears parameter mode: clears self
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<>]", x1, true, L"s1's internal rep = [<>,<>]");
		} // UT02ClearV1

		// -----------------------------------------------------------------------------------

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

			// Verify clears parameter mode: clears self
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<>]", x1, true, L"s1's internal rep = [<>,<>]");
		} // UT03ClearV2


		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT19ClearV3)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT19ClearV3: s1.clear();");
			Logger::WriteMessage(L"\tincoming: s1 = (<33>,<44>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>)");

			// Test set up
			k = 33;
			s1.addRightFront(k);
			s1.advance();
			k = 44;
			s1.addRightFront(k);

			// Execute operation: clear
			s1.clear();

			// Verify clears parameter mode: clears self
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<>]", x1, true, L"s1's internal rep = [<>,<>]");
		} // UT19ClearV3


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

			// Verify ensures: self = #source
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<44>]", x1, true, L"s1's internal rep = [<>,<44>]");

			//Verify parameter mode clears: clears source
			toText(s2, x2);
			Assert::AreEqual(L"[<>,<>]", x2, true, L"s2's internal rep = [<>,<>]");
		} // UT04TransferFromv1

		TEST_METHOD(UT20TransferFromV2)
		{
			IntegerList s1;
			IntegerList s2;
			Text x1, x2;
			Integer k;

			Logger::WriteMessage(L"UT20TransferFromV2: s1.transferFrom(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<>) and s2 = (<44>,<55>)");
			Logger::WriteMessage(L"\toutgoing:  s1 = (<44>,<55>) and s2 = (<>,<>)");

			// Test set up
			k = 44;
			s2.addRightFront(k);
			s2.advance();
			k = 55;
			s2.addRightFront(k);

			// Execute operation: transferFrom
			s1.transferFrom(s2);

			// Verify ensures: self = #source
			toText(s1, x1);
			Assert::AreEqual(L"[<44>,<55>]", x1, true, L"s1's internal rep = [<44>,<55>]");

			//Verify parameter mode clears: clears source
			toText(s2, x2);
			Assert::AreEqual(L"[<>,<>]", x2, true, L"s2's internal rep = [<>,<>]");
		} // UT20TransferFromV2


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

			// Verify ensures self = rhs
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<17>]", x1, true, L"s1's internal rep = [<>,<17>]");
			// Verify restores parameter mode: restores rhs
			toText(s2, x1);
			Assert::AreEqual(L"[<>,<17>]", x1, true, L"s2's internal rep = [<>,<17>]");
		} // UT05AssignmentV1

		TEST_METHOD(UT21AssignmentV2)
		{
			IntegerList s1;
			IntegerList s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT21AssignmentV2: s1 = s2;");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<>) and s2 = (<17>,<37>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<17>,<37>) and s2 = (<17>,<37>)");

			// Test set up
			k = 17;
			s2.addRightFront(k);
			s2.advance();
			k = 37;
			s2.addRightFront(k);

			// Execute operation:  operator =
			s1 = s2;

			// Verify ensures self = rhs
			toText(s1, x1);
			Assert::AreEqual(L"[<17>,<37>]", x1, true, L"s1's internal rep = [<17>,<37>]");
			// Verify restores parameter mode: restores rhs
			toText(s2, x1);
			Assert::AreEqual(L"[<17>,<37>]", x1, true, L"s2's internal rep = [<17>,<37>]");
		} // UT21AssignmentV2

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
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<>), k = 35");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<35>), k = 0");

			// Test set up
			k = 35;

			// Execute operation:  addRightFront
			s1.addRightFront(k);

			// Verify ensures self.left = #self.left and  self.right = <#x> * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<35>]", x1, true, L"s1's internal rep = [<>,<35>]");

			// Verify clears parameter mode: clears x
			Assert::IsTrue(k == 0, L"k = 0");
		} // UT06AddRightFrontV1

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT16AddRightFrontV2)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT16AddRightFrontV2: s1.addRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<21>), k = 35");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<35,21>), k = 0");

			// Test set up
			k = 21;
			s1.addRightFront(k);
			k = 35;

			// Execute operation:  addRightFront
			s1.addRightFront(k);

			// Verify ensures self.left = #self.left and  self.right = <#x> * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<35,21>]", x1, true, L"s1's internal rep = [<>,<35,21>]");

			// Verify clears parameter mode: clears x
			Assert::IsTrue(k == 0, L"k = 0");
		} // UT16AddRightFrontV2

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

			// Verify ensures self.left = #self.left and  self.right = <#x> * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[<13,17,19>,<23,29>]", x1, true, L"s1's internal rep = [<13,17,19>,<23,29>]");

			// Verify clears parameter mode: clears x
			Assert::IsTrue(k == 0, L"k = 0");
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

			// Verify ensures self.left = #self.left and  self.right = <#x> * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[<13,17,19,23>,<29>]", x1, true, L"s1's internal rep = [<13,17,19,23>,<29>]");

			// Verify clears parameter mode: clears x
			Assert::IsTrue(k == 0, L"k = 0");
		} // UT18AddRightFrontV4

		// -----------------------------------------------------------------------------------
		// RemoveRightFront (T& x)
		// -----------------------------------------------------------------------------------
		//! updates self.right
		//! replaces x
		//! requires: self.right /= <>
		//! ensures: self.left = #self.left  and
		//!          <x> is prefix of #self.right  and 
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

			// Verify ensures self.left = #self.left  and self.right = #self.right[1,|#self.right|)
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<33,55,77,99>]", x1, true, L"s1's internal rep = [<>,<33,55,77,99>]");

			// Verify ensures <x> is prefix of #self.right
			Assert::IsTrue(k == 11, L"k = 11");
		} // UT07RemoveRightFrontV1

		TEST_METHOD(UT22RemoveRightFrontV2)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT22RemoveRightFrontV2: s1.removeRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<11>,<33,55,77,99>), k = 0");
			Logger::WriteMessage(L"\toutgoing: s1 = (<11>,<55,77,99>), k = 33");

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

			// Execute operation:  removeRightFront
			s1.removeRightFront(k);

			// Verify ensures self.left = #self.left  and self.right = #self.right[1,|#self.right|)
			toText(s1, x1);
			Assert::AreEqual(L"[<11>,<55,77,99>]", x1, true, L"s1's internal rep = [<11>,<55,77,99>]");

			// Verify ensures <x> is prefix of #self.right
			Assert::IsTrue(k == 33, L"k = 33");
		} // UT22RemoveRightFrontV2

		TEST_METHOD(UT23RemoveRightFrontV3)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT23RemoveRightFrontV3: s1.removeRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<11,33,55,77>,<99>), k = 0");
			Logger::WriteMessage(L"\toutgoing: s1 = (<11,33,55,77>,<>), k = 99");

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
			s1.advance();
			s1.advance();

			// Execute operation:  removeRightFront
			s1.removeRightFront(k);

			// Verify ensures self.left = #self.left  and self.right = #self.right[1,|#self.right|)
			toText(s1, x1);
			Assert::AreEqual(L"[<11,33,55,77>,<>]", x1, true, L"s1's internal rep = [<11,33,55,77>,<>]");

			// Verify ensures <x> is prefix of #self.right
			Assert::IsTrue(k == 99, L"k = 99");
		} // UT23RemoveRightFrontV3

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

			// Verify ensures self.left * self.right = #self.left * #self.right  and
			//!          |self.left| = |#self.left| + 1
			toText(s1, x1);
			Assert::AreEqual(L"[<11,33>,<55,77,99>]", x1, true, L"s1's internal rep = [<11,33>,<55,77,99>]");
		} // UT08AdvanceV1

		TEST_METHOD(UT24AdvanceV2)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT24AdvanceV2: s1.advance();");
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

			// Execute operation: advance
			s1.advance();
			s1.advance();
			s1.advance();
			s1.advance();
			s1.advance();

			// Verify ensures self.left * self.right = #self.left * #self.right  and
			//!          |self.left| = |#self.left| + 1
			toText(s1, x1);
			Assert::AreEqual(L"[<11,33,55,77,99>,<>]", x1, true, L"s1's internal rep = [<11,33,55,77,99>,<>]");
		} // UT24AdvanceV2

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

			// Verify ensures self.left = <>  and  self.right = #self.left * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<11,33,55,77,99>]", x1, true, L"s1's internal rep = [<>,<11,33,55,77,99>]");
		} // UT09MoveToStartV1

		TEST_METHOD(UT25MoveToStartV2)
		{
			IntegerList s1;
			Text x1, x3;
			Integer k;

			Logger::WriteMessage(L"UT25MoveToStartV2: s1.moveToStart();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<55,77,99>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<55,77,99>)");

			//setup test
			k = 99;
			s1.addRightFront(k);
			k = 77;
			s1.addRightFront(k);
			k = 55;
			s1.addRightFront(k);

			// Execute operation: moveToStart
			s1.moveToStart();

			// Verify ensures self.left = <>  and  self.right = #self.left * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<55,77,99>]", x1, true, L"s1's internal rep = [<>,<55,77,99>]");
		} // UT25MoveToStartV2

		TEST_METHOD(UT26MoveToStartV3)
		{
			IntegerList s1;
			Text x1, x3;
			Integer k;

			Logger::WriteMessage(L"UT26MoveToStartV3: s1.moveToStart();");
			Logger::WriteMessage(L"\tincoming: s1 = (<55,77,99>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<55,77,99>)");

			//setup test
			k = 99;
			s1.addRightFront(k);
			k = 77;
			s1.addRightFront(k);
			k = 55;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();
			s1.advance();

			// Execute operation: moveToStart
			s1.moveToStart();

			// Verify ensures self.left = <>  and  self.right = #self.left * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<55,77,99>]", x1, true, L"s1's internal rep = [<>,<55,77,99>]");
		} // UT26MoveToStartV3

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

			// Verify ensures self.right = <>  and  self.left = #self.left * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[<11,33,55,77,99>,<>]", x1, true, L"s1's internal rep = [<11,33,55,77,99>,<>]");
		} // UT10MoveToFinishV1

		TEST_METHOD(UT27MoveToFinishV2)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT27MoveToFinishV2: s1.moveToFinish();");
			Logger::WriteMessage(L"\tincoming: s1 = (<11,33>,<55,77,99>)");
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
			s1.advance();
			s1.advance();

			// Execute operation: moveToFinish
			s1.moveToFinish();

			// Verify ensures self.right = <>  and  self.left = #self.left * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[<11,33,55,77,99>,<>]", x1, true, L"s1's internal rep = [<11,33,55,77,99>,<>]");
		} // UT27MoveToFinishV2

		TEST_METHOD(UT28MoveToFinishV3)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT28MoveToFinishV3: s1.moveToFinish();");
			Logger::WriteMessage(L"\tincoming: s1 = (<11,33,55>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<11,33,55>,<>)");

			//setup test
			k = 55;
			s1.addRightFront(k);
			k = 33;
			s1.addRightFront(k);
			k = 11;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();
			s1.advance();

			// Execute operation: moveToFinish
			s1.moveToFinish();

			// Verify ensures self.right = <>  and  self.left = #self.left * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[<11,33,55>,<>]", x1, true, L"s1's internal rep = [<11,33,55>,<>]");
		} // UT28MoveToFinishV3

		// -----------------------------------------------------------------------------------
		// replaceRightFront
		// -----------------------------------------------------------------------------------
		//! updates self.right, x
		//! requires: self.right /= <>
		//! ensures: self.left = #self.left  and
		//!          <x> is prefix of #self.right  and
		//!          self.right = <#x> * #self.right[1, |#self.right|)
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT11ReplaceRightFrontV1)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT11ReplaceRightFrontV1: s1.replaceRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<11,33>,<55,77,99>), k = 200");
			Logger::WriteMessage(L"\toutgoing: s1 = (<11,33>,<200,77,99>), k = 55");

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

			// Verify ensures: self.left = #self.left  and self.right = <#x> * #self.right[1, |#self.right|)
			toText(s1, x1);
			Assert::AreEqual(L"[<11,33>,<200,77,99>]", x1, true, L"s1's internal rep = [<11,33>,<200,77,99>]");

			// Verify ensures: <x> is prefix of #self.right
			Assert::IsTrue(k == 55, L"k = 55");
		} // UT11ReplaceRightFrontV1

		TEST_METHOD(UT29ReplaceRightFrontV2)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT29ReplaceRightFrontV2: s1.replaceRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<55,77,99>), k = 200");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<200,77,99>), k = 55");

			//setup test
			k = 99;
			s1.addRightFront(k);
			k = 77;
			s1.addRightFront(k);
			k = 55;
			s1.addRightFront(k);
			k = 200;

			// Execute operation: replaceRightFront
			s1.replaceRightFront(k);

			// Verify ensures: self.left = #self.left  and self.right = <#x> * #self.right[1, |#self.right|)
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<200,77,99>]", x1, true, L"s1's internal rep = [<>,<200,77,99>]");

			// Verify ensures: <x> is prefix of #self.right
			Assert::IsTrue(k == 55, L"k = 55");
		} // UT29ReplaceRightFrontV2

		TEST_METHOD(UT30ReplaceRightFrontV3)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT29ReplaceRightFrontV2: s1.replaceRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<55,77>,<99>), k = 200");
			Logger::WriteMessage(L"\toutgoing: s1 = (<55,77>,<200>), k = 99");

			//setup test
			k = 99;
			s1.addRightFront(k);
			k = 77;
			s1.addRightFront(k);
			k = 55;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();
			k = 200;

			// Execute operation: replaceRightFront
			s1.replaceRightFront(k);

			// Verify ensures: self.left = #self.left  and self.right = <#x> * #self.right[1, |#self.right|)
			toText(s1, x1);
			Assert::AreEqual(L"[<55,77>,<200>]", x1, true, L"s1's internal rep = [<55,77>,<200>]");

			// Verify ensures: <x> is prefix of #self.right
			Assert::IsTrue(k == 99, L"k = 99");
		} // UT30ReplaceRightFrontV3

		// -----------------------------------------------------------------------------------
		// rightFront
		// -----------------------------------------------------------------------------------
		//! restores self
		//! requires: self.right /= <>
		//! ensures: <rightFront> is prefix of self.right
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

			// Verify ensures: <rightFront> is prefix of self.right
			Assert::IsTrue(k == 11, L"k = 11");

			// Verify restores parameter mode: restores self
			toText(s1, x1);
			Assert::AreEqual(L"[<3,7>,<11>]", x1, true, L"s1's internal rep = [<3,7>,<11>]");
		} // UT12RightFrontV1

		TEST_METHOD(UT31RightFrontV2)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT31RightFrontV2: s1.rightFront();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<3,7,11>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<3,7,11>)");

			//setup test
			k = 11;
			s1.addRightFront(k);
			k = 7;
			s1.addRightFront(k);
			k = 3;
			s1.addRightFront(k);

			// Execute operation: replaceRightFront
			k = s1.rightFront();

			// Verify ensures: <rightFront> is prefix of self.right
			Assert::IsTrue(k == 3, L"k = 3");

			// Verify restores parameter mode: restores self
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<3,7,11>]", x1, true, L"s1's internal rep = [<>,<3,7,11>]");
		} // UT31RightFrontV2

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

			// Verify ensures: self.left = #self.left  and  self.right = #otherS.right
			toText(s1, x1);
			Assert::AreEqual(L"[<3,7>,<55,77,99>]", x1, true, L"s1's internal rep = [<3,7>,<55,77,99>]");

			// Verify ensures:   otherS.left = #otherS.left  and otherS.right = #self.right  
			toText(s2, x1);
			Assert::AreEqual(L"[<>,<11>]", x1, true, L"s2's internal rep = [<>,<11>]");
		} // UT13SwapRightsV1

		TEST_METHOD(UT32SwapRightsV2)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT32SwapRightsV2: s1.swapRights(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<3,7>,<>) and s2 = (<55>,<77,99>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<3,7>,<77,99>) and s2 = (<55>,<>)");

			//setup test
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
			s2.advance();

			// Execute operation: swapRights
			s1.swapRights(s2);

			// Verify ensures: self.left = #self.left  and  self.right = #otherS.right
			toText(s1, x1);
			Assert::AreEqual(L"[<3,7>,<77,99>]", x1, true, L"s1's internal rep = [<3,7>,<77,99>]");

			// Verify ensures:   otherS.left = #otherS.left  and otherS.right = #self.right  
			toText(s2, x1);
			Assert::AreEqual(L"[<55>,<>]", x1, true, L"s2's internal rep = [<55>,<>]");
		} // UT32SwapRightsV2

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

			// Verify ensures: leftLength = |self.left|
			Assert::IsTrue(s1.leftLength() == 2, L"s1.leftLength() = 2");

			// Verify restores parameter mode: restores self
			toText(s1, x1);
			Assert::AreEqual(L"[<11,33>,<>]", x1, true, L"s1's internal rep = [<11,33>,<>]");
		} // UT14LeftLengthV1

		TEST_METHOD(UT33LeftLengthV2)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT33LeftLengthV2: s1.leftLength();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<11,33>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<11,33>)");

			//setup test
			k = 33;
			s1.addRightFront(k);
			k = 11;
			s1.addRightFront(k);

			// Verify ensures: leftLength = |self.left|
			Assert::IsTrue(s1.leftLength() == 0, L"s1.leftLength() = 0");

			// Verify restores parameter mode: restores self
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<11,33>]", x1, true, L"s1's internal rep = [<>,<11,33>]");
		} // UT33LeftLengthV2

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

			// Verify ensures: leftLength = |self.left|
			Assert::IsTrue(s1.rightLength() == 3, L"s1.rightLength() = 3");

			// Verify restores parameter mode: restores self
			toText(s1, x1);
			Assert::AreEqual(L"[<11>,<33,55,77>]", x1, true, L"s1's internal rep = [<11>,<33,55,77>]");
		} // UT15RightLengthV1

		TEST_METHOD(UT34RightLengthV2)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT34RightLengthV2: s1.rightLength();");
			Logger::WriteMessage(L"\tincoming: s1 = (<11>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<11>,<>)");

			//setup test
			k = 11;
			s1.addRightFront(k);
			s1.advance();

			// Verify ensures: leftLength = |self.left|
			Assert::IsTrue(s1.rightLength() == 0, L"s1.rightLength() = 0");

			// Verify restores parameter mode: restores self
			toText(s1, x1);
			Assert::AreEqual(L"[<11>,<>]", x1, true, L"s1's internal rep = [<11>,<>]");
		} // UT34RightLengthV2
	};
}
