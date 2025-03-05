#include "pch.h"
#include "CppUnitTest.h"
#include "IntegerList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace L4D
{
	TEST_CLASS(L4D)
	{
	public:


		//********************************************
		// Unit tests for Debug mode only
		//********************************************


		// -----------------------------------------------------------------------------------
		// List3()
		// -----------------------------------------------------------------------------------
		//! replaces self
		//! ensures: self = <>
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT01ConstructorV1)
		{
			IntegerList s1;
			Text x1;

			Logger::WriteMessage(L"UT01ConstructorV1: List3();");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>)");

			// Validate ensures: self = (<>,<>)
			toText(s1, x1);
			Assert::AreEqual(L"[0,<>]", x1, true, L"s1's internal rep = [0,<>]");
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
			Assert::AreEqual(L"[0,<>]", x1, true, L"s1's internal rep = [0,<>]");
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

			// Validate clears parameter mode: clears self
			toText(s1, x1);
			Assert::AreEqual(L"[0,<>]", x1, true, L"s1's internal rep = [0,<>]");
		} // UT03ClearV2

		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT04ClearV3)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT04ClearV3: s1.clear();");
			Logger::WriteMessage(L"\tincoming: s1 = (<33>,<33>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>)");

			// Test set up
			k = 33;
			s1.addRightFront(k);
			s1.advance();
			k = 11;
			s1.addRightFront(k);


			// Execute operation: clear
			s1.clear();

			// Validate clears parameter mode: clears self
			toText(s1, x1);
			Assert::AreEqual(L"[0,<>]", x1, true, L"s1's internal rep = [0,<>]");
		} // UT04ClearV3

		// -----------------------------------------------------------------------------------
		// TransferFrom (self & source)
		// -----------------------------------------------------------------------------------
		//! replaces self
		//! clears source
		//! ensures: self = #source
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT05TransferFromV1)
		{
			IntegerList s1;
			IntegerList s2;
			Text x1, x2;
			Integer k;

			Logger::WriteMessage(L"UT05TransferFromV1: s1.transferFrom(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<>) and s2 = (<>,<44>) ");
			Logger::WriteMessage(L"\toutgoing:  s1 = (<>,<44>) and s2 = (<>,<>)");

			// Test set up
			k = 44;
			s2.addRightFront(k);

			// Execute operation: transferFrom
			s1.transferFrom(s2);

			// Validate ensures: self = #source
			toText(s1, x1);
			Assert::AreEqual(L"[1,<44>]", x1, true, L"s1's internal rep = [1,<44>]");

			//Validate parameter mode clears: clears source
			toText(s2, x2);
			Assert::AreEqual(L"[0,<>]", x2, true, L"s2's internal rep = [0,<>]");
		} // UT05TransferFromV1

		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT06TransferFromV2)
		{
			IntegerList s1;
			IntegerList s2;
			Text x1, x2;
			Integer k;

			Logger::WriteMessage(L"UT06TransferFromV2: s1.transferFrom(s2);");
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

			// Validate ensures: self = #source
			toText(s1, x1);
			Assert::AreEqual(L"[1,<55,44>]", x1, true, L"s1's internal rep = [1,<55,44>]");

			//Validate parameter mode clears: clears source
			toText(s2, x2);
			Assert::AreEqual(L"[0,<>]", x2, true, L"s2's internal rep = [0,<>]");
		} // UT06TransferFromV2

		// -----------------------------------------------------------------------------------
		// = operator
		// -----------------------------------------------------------------------------------
		//! replaces self
		//! restores rhs
		//! ensures: self = rhs
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT07AssignmentV1)
		{
			IntegerList s1;
			IntegerList s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT07AssignmentV1: s1 = s2;");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<>) and s2 = (<>,<17>) ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<17>) and s2 = (<>,<17>)");

			// Test set up
			k = 17;
			s2.addRightFront(k);

			// Execute operation:  operator =
			s1 = s2;

			// Validate ensures self = rhs
			toText(s1, x1);
			Assert::AreEqual(L"[1,<17>]", x1, true, L"s1's internal rep = [1,<17>]");
			// Validate restores parameter mode: restores rhs
			toText(s2, x1);
			Assert::AreEqual(L"[1,<17>]", x1, true, L"s2's internal rep = [1,<17>]");
		} // UT07AssignmentV1

		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT08AssignmentV2)
		{
			IntegerList s1;
			IntegerList s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT08AssignmentV2: s1 = s2;");
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

			// Validate ensures self = rhs
			toText(s1, x1);
			Assert::AreEqual(L"[1,<37,17>]", x1, true, L"s1's internal rep = [1,<37,17>]");
			// Validate restores parameter mode: restores rhs
			toText(s2, x1);
			Assert::AreEqual(L"[1,<37,17>]", x1, true, L"s2's internal rep = [1,<37,17>]");
		} // UT08AssignmentV2

		// -----------------------------------------------------------------------------------
		// AddRightFront (T& x)
		// -----------------------------------------------------------------------------------
		//! updates self.right
		//! clears x
		//! ensures: self.left = #self.left  and  self.right = <#x> * #self.right
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT09AddRightFrontV1)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT09AddRightFrontV1: s1.addRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<>), k = 35 ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<35>), k = 0");

			// Test set up
			k = 35;

			// Execute operation:  addRightFront
			s1.addRightFront(k);

			// Validate ensures self.left = #self.left and  self.right = <#x> * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[1,<35>]", x1, true, L"s1's internal rep = [1,<35>]");

			// Validate clears parameter mode: clears x
			Assert::AreEqual(0., k, true, L"k = 0");
		} // UT09AddRightFrontV1

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT10AddRightFrontV2)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT10AddRightFrontV2: s1.addRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<21>), k = 35 ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<35,21>), k= 0");

			// Test set up
			k = 21;
			s1.addRightFront(k);
			k = 35;

			// Execute operation:  addRightFront
			s1.addRightFront(k);

			// Validate ensures self.left = #self.left and  self.right = <#x> * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[2,<35,21>]", x1, true, L"s1's internal rep = [2,<35,21>]");

			// Validate clears parameter mode: clears x
			Assert::AreEqual(0., k, true, L"k = 0");
		} // UT10AddRightFrontV2

		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT11AddRightFrontV3)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT11AddRightFrontV3: s1.addRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<13,17,19>,<29>), k = 23 ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<13,17,19>,<23,29>), k= 0");

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
			Assert::AreEqual(L"[2,<23,29,13,17,19>]", x1, true, L"s1's internal rep = [2,<23,29,13,17,19>]");

			// Validate clears parameter mode: clears x
			Assert::AreEqual(0., k, true, L"k = 0");
		} // UT11AddRightFrontV3

		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT12AddRightFrontV4)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT12AddRightFrontV4: s1.addRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<13,17,19,23>,<>), k = 29 ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<13,17,19,23>,<29>), k= 0");

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
			Assert::AreEqual(L"[1,<29,13,17,19,23>]", x1, true, L"s1's internal rep = [1,<29,13,17,19,23>]");

			// Validate clears parameter mode: clears x
			Assert::AreEqual(0., k, true, L"k = 0");
		} // UT12AddRightFrontV4

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
		TEST_METHOD(UT13RemoveRightFrontV1)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT13RemoveRightFrontV1: s1.removeRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<11,33,55,77,99>), k = 0 ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<33,55,77,99>), k= 11");

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
			Assert::AreEqual(L"[4,<33,55,77,99>]", x1, true, L"s1's internal rep = [4,<33,55,77,99>]");

			// Validate ensures <x> = #self.right[0,1)
			Assert::AreEqual(11., k, true, L"k = 11");
		} // UT13RemoveRightFrontV1

		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT14RemoveRightFrontV2)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT14RemoveRightFrontV2: s1.removeRightFront(k);");
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

			// Validate ensures self.left = #self.left  and self.right = #self.right[1,|#self.right|)
			toText(s1, x1);
			Assert::AreEqual(L"[3,<55,77,99,11>]", x1, true, L"s1's internal rep = [3,<55,77,99,11>]");

			// Validate ensures <x> = #self.right[0,1)
			Assert::AreEqual(33., k, true, L"k = 33");
		} // UT14RemoveRightFrontV2

		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT15RemoveRightFrontV3)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT15RemoveRightFrontV3: s1.removeRightFront(k);");
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

			// Validate ensures self.left = #self.left  and self.right = #self.right[1,|#self.right|)
			toText(s1, x1);
			Assert::AreEqual(L"[0,<11,33,55,77>]", x1, true, L"s1's internal rep = [0,<11,33,55,77>]");

			// Validate ensures <x> = #self.right[0,1)
			Assert::AreEqual(99., k, true, L"k = 99");
		} // UT15RemoveRightFrontV3

		// -----------------------------------------------------------------------------------
		// Advance 
		// -----------------------------------------------------------------------------------
		//! updates self
		//! requires: self.right /= <>
		//! ensures: self.left * self.right = #self.left * #self.right  and
		//!          |self.left| = |#self.left| + 1
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT16AdvanceV1)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT16AdvanceV1: s1.advance();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<11,33,55,77,99>) ");
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
			Assert::AreEqual(L"[3,<55,77,99,11,33>]", x1, true, L"s1's internal rep = [3,<55,77,99,11,33>]");
		} // UT16AdvanceV1

		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT17AdvanceV2)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT17AdvanceV2: s1.advance();");
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

			// Validate ensures self.left * self.right = #self.left * #self.right  and
			//!          |self.left| = |#self.left| + 1
			toText(s1, x1);
			Assert::AreEqual(L"[0,<11,33,55,77,99>]", x1, true, L"s1's internal rep = [0,<11,33,55,77,99>]");
		} // UT17AdvanceV2

		// -----------------------------------------------------------------------------------
		// moveToStart
		// -----------------------------------------------------------------------------------
		//! updates self
		//! ensures: self.left = <>  and  self.right = #self.left * #self.right
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT18MoveToStartV1)
		{
			IntegerList s1;
			Text x1, x3;
			Integer k;

			Logger::WriteMessage(L"UT18MoveToStartV1: s1.moveToStart();");
			Logger::WriteMessage(L"\tincoming: s1 = (<11,33>,<55,77,99>) ");
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
			Assert::AreEqual(L"[5,<11,33,55,77,99>]", x1, true, L"s1's internal rep = [5,<11,33,55,77,99>]");
		} // UT18MoveToStartV1

		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT19MoveToStartV2)
		{
			IntegerList s1;
			Text x1, x3;
			Integer k;

			Logger::WriteMessage(L"UT19MoveToStartV2: s1.moveToStart();");
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

			// Validate ensures self.left = <>  and  self.right = #self.left * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[3,<55,77,99>]", x1, true, L"s1's internal rep = [3,<55,77,99>]");
		} // UT19MoveToStartV2

		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT20MoveToStartV3)
		{
			IntegerList s1;
			Text x1, x3;
			Integer k;

			Logger::WriteMessage(L"UT20MoveToStartV3: s1.moveToStart();");
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

			// Validate ensures self.left = <>  and  self.right = #self.left * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[3,<55,77,99>]", x1, true, L"s1's internal rep = [3,<55,77,99>]");
		} // UT20MoveToStartV3

		// -----------------------------------------------------------------------------------
		// rightFront
		// -----------------------------------------------------------------------------------
		//! restores self
		//! requires: self.right /= <>
		//! ensures: <rightFront> = self.right[0,1)
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT21RightFrontV1)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT21RightFrontV1: s1.rightFront();");
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
			Assert::AreEqual(L"[1,<11,3,7>]", x1, true, L"s1's internal rep = [1,<11,3,7>]");
		} // UT21RightFrontV1

		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT22RightFrontV2)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT22RightFrontV2: s1.rightFront();");
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

			// Validate ensures: <rightFront> = self.right[0,1)
			Assert::AreEqual(3., k, true, L"k = 3");

			// Validate restores parameter mode: restores self
			toText(s1, x1);
			Assert::AreEqual(L"[3,<3,7,11>]", x1, true, L"s1's internal rep = [3,<3,7,11>]");
		} // UT22RightFrontV2

		// -----------------------------------------------------------------------------------
		// moveToFinish
		// -----------------------------------------------------------------------------------
		//! updates self
		//! ensures: self.right = <>  and  self.left = #self.left * #self.right
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT23MoveToFinishV1)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT23MoveToFinishV1: s1.moveToFinish();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<11,33,55,77,99>) ");
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
			Assert::AreEqual(L"[0,<11,33,55,77,99>]", x1, true, L"s1's internal rep = [0,<11,33,55,77,99>]");
		} // UT23MoveToFinishV1

		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT24MoveToFinishV2)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT24MoveToFinishV2: s1.moveToFinish();");
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

			// Validate ensures self.right = <>  and  self.left = #self.left * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[0,<11,33,55,77,99>]", x1, true, L"s1's internal rep = [0,<11,33,55,77,99>]");
		} // UT24MoveToFinishV2

		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT25MoveToFinishV3)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT25MoveToFinishV3: s1.moveToFinish();");
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

			// Validate ensures self.right = <>  and  self.left = #self.left * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[0,<11,33,55>]", x1, true, L"s1's internal rep = [0,<11,33,55>]");
		} // UT25MoveToFinishV3

		// -----------------------------------------------------------------------------------
		// replaceRightFront
		// -----------------------------------------------------------------------------------
		//! updates self.right, x
		//! requires: self.right /= <>
		//! ensures: self.left = #self.left  and
		//!          <x> = #self.right[0,1)  and
		//!          self.right = <#x> * #self.right[1, |#self.right|)
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT26ReplaceRightFrontV1)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT26ReplaceRightFrontV1: s1.replaceRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<11,33>,<55,77,99>), k = 200 ");
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
			Assert::AreEqual(L"[3,<200,77,99,11,33>]", x1, true, L"s1's internal rep = [3,<200,77,99,11,33>]");

			// Validate ensures: <x> = #self.right[0,1)
			Assert::AreEqual(55., k, true, L"k = 55");
		} // UT26ReplaceRightFrontV1

		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT27ReplaceRightFrontV2)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT27ReplaceRightFrontV2: s1.replaceRightFront(k);");
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

			// Validate ensures: self.left = #self.left  and self.right = <#x> * #self.right[1, |#self.right|)
			toText(s1, x1);
			Assert::AreEqual(L"[3,<200,77,99>]", x1, true, L"s1's internal rep = [3,<200,77,99>]");

			// Validate ensures: <x> = #self.right[0,1)
			Assert::AreEqual(55., k, true, L"k = 55");
		} // UT27ReplaceRightFrontV2

		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT28ReplaceRightFrontV3)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT28ReplaceRightFrontV3: s1.replaceRightFront(k);");
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

			// Validate ensures: self.left = #self.left  and self.right = <#x> * #self.right[1, |#self.right|)
			toText(s1, x1);
			Assert::AreEqual(L"[1,<200,55,77>]", x1, true, L"s1's internal rep = [1,<200,55,77>]");

			// Validate ensures: <x> = #self.right[0,1)
			Assert::AreEqual(99., k, true, L"k = 99");
		} // UT28ReplaceRightFrontV3

		// -----------------------------------------------------------------------------------
		// swapRights
		// -----------------------------------------------------------------------------------
		//! updates self.right, otherS.right
		//! ensures: self.left = #self.left  and  otherS.left = #otherS.left  and
		//!          otherS.right = #self.right  and  self.right = #otherS.right
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT29SwapRightsV1)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT29SwapRightsV1: s1.swapRights(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<3,7>,<11>) and s2 = (<>,<55,77,99>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<3,7>,<55,77,99>) and s2 = (<>,<>)");

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
			Assert::AreEqual(L"[3,<55,77,99,3,7>]", x1, true, L"s1's internal rep = [3,<55,77,99,3,7>]");

			// Validate ensures:   otherS.left = #otherS.left  and otherS.right = #self.right  
			toText(s2, x1);
			Assert::AreEqual(L"[1,<11>]", x1, true, L"s2's internal rep = [1,<11>]");
		} // UT29SwapRightsV1

		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT30SwapRightsV2)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT30SwapRightsV2: s1.swapRights(s2);");
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
			Assert::AreEqual(L"[3,<55,77,99,3,7>]", x1, true, L"s1's internal rep = [3,<55,77,99,3,7]");

			// Validate ensures:   otherS.left = #otherS.left  and otherS.right = #self.right  
			toText(s2, x1);
			Assert::AreEqual(L"[1,<11>]", x1, true, L"s2's internal rep = [1,<11>]");
		} // UT30SwapRightsV2

		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT31SwapRightsV3)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT31SwapRightsV3: s1.swapRights(s2);");
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

			// Validate ensures: self.left = #self.left  and  self.right = #otherS.right
			toText(s1, x1);
			Assert::AreEqual(L"[2,<77,99,3,7>]", x1, true, L"s1's internal rep = [2,<77,99,3,7>]");

			// Validate ensures:   otherS.left = #otherS.left  and otherS.right = #self.right  
			toText(s2, x1);
			Assert::AreEqual(L"[0,<55>]", x1, true, L"s2's internal rep = [0,<55>]");
		} // UT31SwapRightsV3

		// -----------------------------------------------------------------------------------
		// leftLength
		// -----------------------------------------------------------------------------------
		//! restores self
		//! ensures: leftLength = |self.left|
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT32LeftLengthV1)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT32LeftLengthV1: s1.leftLength();");
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
			Assert::AreEqual(L"[0,<11,33>]", x1, true, L"s1's internal rep = [<0,<11,33>]");
		} // UT32LeftLengthV1

		// -----------------------------------------------------------------------------------
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

			// Validate ensures: leftLength = |self.left|
			Assert::AreEqual(0., s1.leftLength(), true, L"s1.leftLength() = 0");

			// Validate restores parameter mode: restores self
			toText(s1, x1);
			Assert::AreEqual(L"[2,<11,33>]", x1, true, L"s1's internal rep = [2,<11,33>]");
		} // UT33LeftLengthV2

		// -----------------------------------------------------------------------------------
		// rightLength
		// -----------------------------------------------------------------------------------
		//! restores self
		//! ensures: rightLength = |self.right|
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT34RightLengthV1)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT34RightLengthV1: s1.rightLength();");
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
			Assert::AreEqual(L"[3,<33,55,77,11>]", x1, true, L"s1's internal rep = [3,<33,55,77,11>]");
		} // UT34RightLengthV1

		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT35RightLengthV2)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT35RightLengthV2: s1.rightLength();");
			Logger::WriteMessage(L"\tincoming: s1 = (<11>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<11>,<>)");

			//setup test
			k = 11;
			s1.addRightFront(k);
			s1.advance();

			// Validate ensures: rightLength = |self.right|
			Assert::AreEqual(0., s1.rightLength(), true, L"s1.rightLength() = 0");

			// Validate restores parameter mode: restores self
			toText(s1, x1);
			Assert::AreEqual(L"[0,<11>]", x1, true, L"s1's internal rep = [0,<11>]");
		} // UT35RightLengthV2
	};
}
