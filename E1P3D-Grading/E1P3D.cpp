#include "pch.h"
#include "CppUnitTest.h"
#include "IntegerList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace E1P3D
{
	TEST_CLASS(E1P3D)
	{
	public:


		//********************************************
		// Unit tests for Debug mode only
		//********************************************


		// -----------------------------------------------------------------------------------
		// List6()
		// -----------------------------------------------------------------------------------
		//! replaces self
		//! ensures: self = <>
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT01Constructor)
		{
			IntegerList s1;
			Text x1;

			Logger::WriteMessage(L"UT01Constructor: List6();");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>)");

			// Validate ensures: self = (<>,<>)
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<>]", x1, true, L"s1's internal rep = [<>,<>]");
		} // UT01Constructor

		// -----------------------------------------------------------------------------------
		// clear
		// -----------------------------------------------------------------------------------
		//! clears self
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT02Clear)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT02Clear: s1.clear();");
			Logger::WriteMessage(L"\tincoming: s1 = (<83>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>)");

			// Test set up
			k = 83;
			s1.addRightFront(k);
			s1.advance();

			// Execute operation: clear
			s1.clear();

			// Validate clears parameter mode: clears self
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<>]", x1, true, L"s1's internal rep = [<>,<>]");
		} // UT02Clear

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT03Clear)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT03Clear: s1.clear();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<83>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>)");

			// Test set up
			k = 83;
			s1.addRightFront(k);

			// Execute operation: clear
			s1.clear();

			// Validate clears parameter mode: clears self
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<>]", x1, true, L"s1's internal rep = [<>,<>]");
		} // UT03Clear

		TEST_METHOD(UT04Clear)
		{
			IntegerList s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT04Clear: s2.clear();");
			Logger::WriteMessage(L"\tincoming: s2 = (<20,15>,<10>) ");
			Logger::WriteMessage(L"\toutgoing: s2 = (<>,<>)");

			// Test set up
			k = 10;
			s2.addRightFront(k);
			k = 15;
			s2.addRightFront(k);
			k = 20;
			s2.addRightFront(k);
			s2.advance();
			s2.advance();

			// Execute operation: clear
			s2.clear();

			// Validate clears parameter mode: clears self
			toText(s2, x1);
			Assert::AreEqual(L"[<>,<>]", x1, true, L"s2's internal rep = [<>,<>]");
		} // UT04Clear

		// -----------------------------------------------------------------------------------
		// TransferFrom (self & source)
		// -----------------------------------------------------------------------------------
		//! replaces self
		//! clears source
		//! ensures: self = #source
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT05TransferFrom)
		{
			IntegerList s1;
			IntegerList s2;
			Text x1, x2;
			Integer k;

			Logger::WriteMessage(L"UT05TransferFrom: s1.transferFrom(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<>) and s2 = (<>,<11>) ");
			Logger::WriteMessage(L"\toutgoing:  s1 = (<>,<11>) and s2 = (<>,<>)");

			// Test set up
			k = 11;
			s2.addRightFront(k);

			// Execute operation: transferFrom
			s1.transferFrom(s2);

			// Validate ensures: self = #source
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<11>]", x1, true, L"s1's internal rep = [<>,<11>]");

			//Validate parameter mode clears: clears source
			toText(s2, x2);
			Assert::AreEqual(L"[<>,<>]", x2, true, L"s2's internal rep = [<>,<>]");
		} // UT05TransferFrom

		TEST_METHOD(UT06TransferFrom)
		{
			IntegerList s1;
			IntegerList s2;
			Text x1, x2;
			Integer k;

			Logger::WriteMessage(L"UT06TransferFrom: s1.transferFrom(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<>) and s2 = (<20,15>,<10>) ");
			Logger::WriteMessage(L"\toutgoing:  s1 = (<20,15>,<10>) and s2 = (<>,<>)");

			// Test set up
			k = 10;
			s2.addRightFront(k);
			k = 15;
			s2.addRightFront(k);
			k = 20;
			s2.addRightFront(k);
			s2.advance();
			s2.advance();

			// Execute operation: transferFrom
			s1.transferFrom(s2);

			// Validate ensures: self = #source
			toText(s1, x1);
			Assert::AreEqual(L"[<15,20>,<10>]", x1, true, L"s1's internal rep = [<15,20>,<10>]");

			//Validate parameter mode clears: clears source
			toText(s2, x2);
			Assert::AreEqual(L"[<>,<>]", x2, true, L"s2's internal rep = [<>,<>]");
		} // UT06TransferFrom

		TEST_METHOD(UT34TransferFrom)
		{
			IntegerList s1;
			IntegerList s2;
			Text x1, x2;
			Integer k;

			Logger::WriteMessage(L"UT34TransferFrom: s1.transferFrom(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<>) and s2 = (<20,15>,<>) ");
			Logger::WriteMessage(L"\toutgoing:  s1 = (<20,15>,<>) and s2 = (<>,<>)");

			// Test set up
			k = 15;
			s2.addRightFront(k);
			k = 20;
			s2.addRightFront(k);
			s2.advance();
			s2.advance();

			// Execute operation: transferFrom
			s1.transferFrom(s2);

			// Validate ensures: self = #source
			toText(s1, x1);
			Assert::AreEqual(L"[<15,20>,<>]", x1, true, L"s1's internal rep = [<15,20>,<>]");

			//Validate parameter mode clears: clears source
			toText(s2, x2);
			Assert::AreEqual(L"[<>,<>]", x2, true, L"s2's internal rep = [<>,<>]");
		} // UT34TransferFrom

		// -----------------------------------------------------------------------------------
		// = operator
		// -----------------------------------------------------------------------------------
		//! replaces self
		//! restores rhs
		//! ensures: self = rhs
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT07Assignment)
		{
			IntegerList s1;
			IntegerList s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT07Assignment: s1 = s2;");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<>) and s2 = (<>,<10>) ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<10>) and s2 = (<>,<10>)");

			// Test set up
			k = 10;
			s2.addRightFront(k);

			// Execute operation:  operator =
			s1 = s2;

			// Validate ensures self = rhs
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<10>]", x1, true, L"s1's internal rep = [<>,<10>]");
			// Validate restores parameter mode: restores rhs
			toText(s2, x1);
			Assert::AreEqual(L"[<>,<10>]", x1, true, L"s2's internal rep = [<>,<10>]");
		} // UT07Assignment


		TEST_METHOD(UT08Assignment)
		{
			IntegerList s1;
			IntegerList s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT08Assignment: s1 = s2;");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<>) and s2 = (<20,15>,<10>) ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<20,15>,<10>) and s2 = (<20,15>,<10>)");

			// Test set up
			k = 10;
			s2.addRightFront(k);
			k = 15;
			s2.addRightFront(k);
			k = 20;
			s2.addRightFront(k);
			s2.advance();
			s2.advance();

			// Execute operation:  operator =
			s1 = s2;

			// Validate ensures self = rhs
			toText(s1, x1);
			Assert::AreEqual(L"[<15,20>,<10>]", x1, true, L"s1's internal rep = [<15,20>,<10>]");
			// Validate restores parameter mode: restores rhs
			toText(s2, x1);
			Assert::AreEqual(L"[<15,20>,<10>]", x1, true, L"s2's internal rep = [<15,20>,<10>]");
		} // UT08Assignment


		TEST_METHOD(UT35Assignment)
		{
			IntegerList s1;
			IntegerList s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT35Assignment: s1 = s2;");
			Logger::WriteMessage(L"\tincoming: s1 = (<5>,<10>) and s2 = (<20,15>,<>) ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<20,15>,<>) and s2 = (<20,15>,<>)");

			// Test set up
			k = 5;
			s1.addRightFront(k);
			s1.advance();
			k = 10;
			s1.addRightFront(k);

			k = 15;
			s2.addRightFront(k);
			k = 20;
			s2.addRightFront(k);
			s2.advance();
			s2.advance();

			// Execute operation:  operator =
			s1 = s2;

			// Validate ensures self = rhs
			toText(s1, x1);
			Assert::AreEqual(L"[<15,20>,<>]", x1, true, L"s1's internal rep = [<15,20>,<>]");
			// Validate restores parameter mode: restores rhs
			toText(s2, x1);
			Assert::AreEqual(L"[<15,20>,<>]", x1, true, L"s2's internal rep = [<15,20>,<>]");
		} // UT35Assignment

		// -----------------------------------------------------------------------------------
		// AddRightFront (T& x)
		// -----------------------------------------------------------------------------------
		//! updates self.right
		//! clears x
		//! ensures: self.left = #self.left  and  self.right = <#x> * #self.right
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT09AddRightFront)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT09AddRightFront: s1.addRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<>), k = 18 ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<18>), k = 0");

			// Test set up
			k = 18;

			// Execute operation:  addRightFront
			s1.addRightFront(k);

			// Validate ensures self.left = #self.left and  self.right = <#x> * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<18>]", x1, true, L"s1's internal rep = [<>,<18>]");

			// Validate clears parameter mode: clears x
			Assert::AreEqual(0., k, true, L"k = 0");
		} // UT09AddRightFront

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT10AddRightFront)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT10AddRightFront: s1.addRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<22>), k = 83");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<83,22>), k = 0");

			// Test set up
			k = 22;
			s1.addRightFront(k);
			k = 83;

			// Execute operation:  addRightFront
			s1.addRightFront(k);

			// Validate ensures self.left = #self.left and  self.right = <#x> * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<83,22>]", x1, true, L"s1's internal rep = [<>,<83,22>]");

			// Validate clears parameter mode: clears x
			Assert::AreEqual(0., k, true, L"k = 0");
		} // UT10AddRightFront

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT11AddRightFront)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT11AddRightFront: s1.addRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<17,2,10>,<11>), k = 83 ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<17,2,10>,<83,11>), k = 0");

			// Test set up
			k = 11;
			s1.addRightFront(k);
			k = 10;
			s1.addRightFront(k);
			k = 2;
			s1.addRightFront(k);
			k = 17;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();
			s1.advance();
			k = 83;
			// Execute operation:  addRightFront
			s1.addRightFront(k);

			// Validate ensures self.left = #self.left and  self.right = <#x> * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[<10,2,17>,<83,11>]", x1, true, L"s1's internal rep = [<10,2,17>,<83,11>]");

			// Validate clears parameter mode: clears x
			Assert::AreEqual(0., k, true, L"k = 0");
		} // UT11AddRightFront

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT12AddRightFront)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT12AddRightFront: s1.addRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<17,2,10,83>,<>), k = 11 ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<17,2,10,83>,<11>), k = 0");

			// Test set up
			k = 83;
			s1.addRightFront(k);
			k = 10;
			s1.addRightFront(k);
			k = 2;
			s1.addRightFront(k);
			k = 17;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();
			s1.advance();
			s1.advance();
			k = 11;

			// Execute operation:  addRightFront
			s1.addRightFront(k);

			// Validate ensures self.left = #self.left and  self.right = <#x> * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[<83,10,2,17>,<11>]", x1, true, L"s1's internal rep = [<83,10,2,17>,<11>]");

			// Validate clears parameter mode: clears x
			Assert::AreEqual(0., k, true, L"k = 0");
		} // UT12AddRightFront

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
		TEST_METHOD(UT13RemoveRightFront)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT13RemoveRightFront: s1.removeRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<22,41,-5,33,29>), k = 0 ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<41,-5,33,29>), k = 22");

			//setup test
			k = 29;
			s1.addRightFront(k);
			k = 33;
			s1.addRightFront(k);
			k = -5;
			s1.addRightFront(k);
			k = 41;
			s1.addRightFront(k);
			k = 22;
			s1.addRightFront(k);

			// Execute operation:  removeRightFront
			s1.removeRightFront(k);

			// Validate ensures self.left = #self.left  and self.right = #self.right[1,|#self.right|)
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<41,-5,33,29>]", x1, true, L"s1's internal rep = [<>,<41,-5,33,29>]");

			// Validate ensures <x> = #self.right[0,1)
			Assert::AreEqual(22., k, true, L"k = 22");
		} // UT13RemoveRightFront

		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT14RemoveRightFront)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT14RemoveRightFront: s1.removeRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<22,41>,<-5,33,29>), k = 0 ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<22,41>,<33,29>), k = -5");

			//setup test
			k = 29;
			s1.addRightFront(k);
			k = 33;
			s1.addRightFront(k);
			k = -5;
			s1.addRightFront(k);
			k = 41;
			s1.addRightFront(k);
			k = 22;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();
			// Execute operation:  removeRightFront
			s1.removeRightFront(k);

			// Validate ensures self.left = #self.left  and self.right = #self.right[1,|#self.right|)
			toText(s1, x1);
			Assert::AreEqual(L"[<41,22>,<33,29>]", x1, true, L"s1's internal rep = [<41,22>,<33,29>]");

			// Validate ensures <x> = #self.right[0,1)
			Assert::AreEqual(-5., k, true, L"k = -5");
		} // UT14RemoveRightFront

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT15RemoveRightFront)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT15RemoveRightFront: s1.removeRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<22,41,-5,33>,<29>), k = 0 ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<22,41,-5,33>,<>), k = 29");

			//setup test
			k = 29;
			s1.addRightFront(k);
			k = 33;
			s1.addRightFront(k);
			k = -5;
			s1.addRightFront(k);
			k = 41;
			s1.addRightFront(k);
			k = 22;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();
			s1.advance();
			s1.advance();
			// Execute operation:  removeRightFront
			s1.removeRightFront(k);

			// Validate ensures self.left = #self.left  and self.right = #self.right[1,|#self.right|)
			toText(s1, x1);
			Assert::AreEqual(L"[<33,-5,41,22>,<>]", x1, true, L"s1's internal rep = [<33,-5,41,22>,<>]");

			// Validate ensures <x> = #self.right[0,1)
			Assert::AreEqual(29., k, true, L"k = 29");
		} // UT15RemoveRightFront

		// -----------------------------------------------------------------------------------
		// Advance 
		// -----------------------------------------------------------------------------------
		//! updates self
		//! requires: self.right /= <>
		//! ensures: self.left * self.right = #self.left * #self.right  and
		//!          |self.left| = |#self.left| + 1
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT16Advance)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT16Advance: s1.advance();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<22,41,-5,33,29>) ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<22,41>,<-5,33,29>)");

			//setup test
			k = 29;
			s1.addRightFront(k);
			k = 33;
			s1.addRightFront(k);
			k = -5;
			s1.addRightFront(k);
			k = 41;
			s1.addRightFront(k);
			k = 22;
			s1.addRightFront(k);

			// Execute operation: advance
			s1.advance();
			s1.advance();

			// Validate ensures self.left * self.right = #self.left * #self.right  and
			//!          |self.left| = |#self.left| + 1
			toText(s1, x1);
			Assert::AreEqual(L"[<41,22>,<-5,33,29>]", x1, true, L"s1's internal rep = [<41,22>,<-5,33,29>]");
		} // UT16Advance

		// -----------------------------------------------------------------------------------
		// moveToStart
		// -----------------------------------------------------------------------------------
		//! updates self
		//! ensures: self.left = <>  and  self.right = #self.left * #self.right
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT17MoveToStart)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT17MoveToStart: s1.moveToStart();");
			Logger::WriteMessage(L"\tincoming: s1 = (<22,41>,<-5,33,29>) ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<22,41,-5,33,29>)");

			//setup test
			k = 29;
			s1.addRightFront(k);
			k = 33;
			s1.addRightFront(k);
			k = -5;
			s1.addRightFront(k);
			k = 41;
			s1.addRightFront(k);
			k = 22;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();

			// Execute operation: moveToStart
			s1.moveToStart();

			// Validate ensures self.left = <>  and  self.right = #self.left * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<22,41,-5,33,29>]", x1, true, L"s1's internal rep = [<>,<22,41,-5,33,29>]");
		} // UT17MoveToStart

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT18MoveToStart)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT18MoveToStart: s1.moveToStart();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<22,41,-5,43,39>) ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<22,41,-5,33,29>)");

			//setup test
			k = 39;
			s1.addRightFront(k);
			k = 43;
			s1.addRightFront(k);
			k = -5;
			s1.addRightFront(k);
			k = 41;
			s1.addRightFront(k);
			k = 22;
			s1.addRightFront(k);

			// Execute operation: moveToStart
			s1.moveToStart();

			// Validate ensures self.left = <>  and  self.right = #self.left * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<22,41,-5,43,39>]", x1, true, L"s1's internal rep = [<>,<22,41,-5,43,39>]");
		} // UT18MoveToStart

		TEST_METHOD(UT19MoveToStart)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT19MoveToStart: s1.moveToStart();");
			Logger::WriteMessage(L"\tincoming: s1 = (<22,41,-5>,<>) ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<22,41,-5>)");

			//setup test
			k = -5;
			s1.addRightFront(k);
			k = 41;
			s1.addRightFront(k);
			k = 22;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();
			s1.advance();

			// Execute operation: moveToStart
			s1.moveToStart();

			// Validate ensures self.left = <>  and  self.right = #self.left * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<22,41,-5>]", x1, true, L"s1's internal rep = [<>,<22,41,-5>]");
		} // UT19MoveToStart

		// -----------------------------------------------------------------------------------
		// moveToFinish
		// -----------------------------------------------------------------------------------
		//! updates self
		//! ensures: self.right = <>  and  self.left = #self.left * #self.right
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT20MoveToFinish)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT20MoveToFinish: s1.moveToFinish();");
			Logger::WriteMessage(L"\tincoming: s1 = (<22,41>,<-5,33,29>) ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<22,41,-5,33,29>,<>)");

			//setup test
			k = 29;
			s1.addRightFront(k);
			k = 33;
			s1.addRightFront(k);
			k = -5;
			s1.addRightFront(k);
			k = 41;
			s1.addRightFront(k);
			k = 22;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();

			// Execute operation: moveToFinish
			s1.moveToFinish();

			// Validate ensures self.right = <>  and  self.left = #self.left * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[<29,33,-5,41,22>,<>]", x1, true, L"s1's internal rep = [<29,33,-5,41,22>,<>]");
		} // UT20MoveToFinish

		TEST_METHOD(UT21MoveToFinish)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT21MoveToFinish: s1.moveToFinish();");
			Logger::WriteMessage(L"\tincoming: s1 = (<-5,33,29>,<>) ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<-5,33,29>,<>)");

			//setup test
			k = 29;
			s1.addRightFront(k);
			k = 33;
			s1.addRightFront(k);
			k = -5;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();
			s1.advance();

			// Execute operation: moveToFinish
			s1.moveToFinish();

			// Validate ensures self.right = <>  and  self.left = #self.left * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[<29,33,-5>,<>]", x1, true, L"s1's internal rep = [<29,33,-5>,<>]");
		} // UT21MoveToFinish


		TEST_METHOD(UT36MoveToFinish)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT36MoveToFinish: s1.moveToFinish();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<-5,33,29>) ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<-5,33,29>,<>)");

			//setup test
			k = 29;
			s1.addRightFront(k);
			k = 33;
			s1.addRightFront(k);
			k = -5;
			s1.addRightFront(k);

			// Execute operation: moveToFinish
			s1.moveToFinish();

			// Validate ensures self.right = <>  and  self.left = #self.left * #self.right
			toText(s1, x1);
			Assert::AreEqual(L"[<29,33,-5>,<>]", x1, true, L"s1's internal rep = [<29,33,-5>,<>]");
		} // UT36MoveToFinish

		// -----------------------------------------------------------------------------------
		// replaceRightFront
		// -----------------------------------------------------------------------------------
		//! updates self.right, x
		//! requires: self.right /= <>
		//! ensures: self.left = #self.left  and
		//!          <x> = #self.right[0,1)  and
		//!          self.right = <#x> * #self.right[1, |#self.right|)
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT22ReplaceRightFront)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT22ReplaceRightFront: s1.replaceRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<22,41>,<-5,33,29>), k = 5 ");
			Logger::WriteMessage(L"\toutgoing: s1 = (<22,41>,<5,33,29>), k = -5");

			//setup test
			k = 29;
			s1.addRightFront(k);
			k = 33;
			s1.addRightFront(k);
			k = -5;
			s1.addRightFront(k);
			k = 41;
			s1.addRightFront(k);
			k = 22;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();
			k = 5;

			// Execute operation: replaceRightFront
			s1.replaceRightFront(k);

			// Validate ensures: self.left = #self.left  and self.right = <#x> * #self.right[1, |#self.right|)
			toText(s1, x1);
			Assert::AreEqual(L"[<41,22>,<5,33,29>]", x1, true, L"s1's internal rep = [<41,22>,<5,33,29>]");

			// Validate ensures: <x> = #self.right[0,1)
			Assert::AreEqual(-5., k, true, L"k = -5");
		} // UT22ReplaceRightFront

		TEST_METHOD(UT23ReplaceRightFront)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT23ReplaceRightFront: s1.replaceRightFront(k);");
			Logger::WriteMessage(L"\tincoming: s1 = (<-5,33>,<29>), k = -29");
			Logger::WriteMessage(L"\toutgoing: s1 = (<-5,33>,<-29>), k = 29");

			//setup test
			k = 29;
			s1.addRightFront(k);
			k = 33;
			s1.addRightFront(k);
			k = -5;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();
			k = -29;

			// Execute operation: replaceRightFront
			s1.replaceRightFront(k);

			// Validate ensures: self.left = #self.left  and self.right = <#x> * #self.right[1, |#self.right|)
			toText(s1, x1);
			Assert::AreEqual(L"[<33,-5>,<-29>]", x1, true, L"s1's internal rep = [<33,-5>,<-29>]");

			// Validate ensures: <x> = #self.right[0,1)
			Assert::AreEqual(29., k, true, L"k = 29");
		} // UT23ReplaceRightFront

		// -----------------------------------------------------------------------------------
		// rightFront
		// -----------------------------------------------------------------------------------
		//! restores self
		//! requires: self.right /= <>
		//! ensures: <rightFront> = self.right[0,1)
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT24RightFront)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT24RightFront: s1.rightFront();");
			Logger::WriteMessage(L"\tincoming: s1 = (<3,41>,<22>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<3,41>,<22>)");

			//setup test
			k = 22;
			s1.addRightFront(k);
			k = 41;
			s1.addRightFront(k);
			k = 3;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();

			// Execute operation: replaceRightFront
			k = s1.rightFront();

			// Validate ensures: <rightFront> = self.right[0,1)
			Assert::AreEqual(22., k, true, L"k = 22");

			// Validate restores parameter mode: restores self
			toText(s1, x1);
			Assert::AreEqual(L"[<41,3>,<22>]", x1, true, L"s1's internal rep = [<41,3>,<22>]");
		} // UT24RightFront

		TEST_METHOD(UT25RightFront)
		{
			IntegerList s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT25RightFront: s1.rightFront();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<3,41,22>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<3,41,22>)");

			//setup test
			k = 22;
			s1.addRightFront(k);
			k = 41;
			s1.addRightFront(k);
			k = 3;
			s1.addRightFront(k);

			// Execute operation: replaceRightFront
			k = s1.rightFront();

			// Validate ensures: <rightFront> = self.right[0,1)
			Assert::AreEqual(3., k, true, L"k = 3");

			// Validate restores parameter mode: restores self
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<3,41,22>]", x1, true, L"s1's internal rep = [<>,<3,41,22>]");
		} // UT25RightFront

		// -----------------------------------------------------------------------------------
		// swapRights
		// -----------------------------------------------------------------------------------
		//! updates self.right, otherS.right
		//! ensures: self.left = #self.left  and  otherS.left = #otherS.left  and
		//!          otherS.right = #self.right  and  self.right = #otherS.right
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT26SwapRights)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT26SwapRights: s1.swapRights(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<3,41>,<22>) and s2 = (<>,<-5,33,29>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<3,41>,<-5,33,29>) and s2 = (<>,<22>)");

			//setup test
			k = 22;
			s1.addRightFront(k);
			k = 41;
			s1.addRightFront(k);
			k = 3;
			s1.addRightFront(k);

			s1.advance();
			s1.advance();

			k = 29;
			s2.addRightFront(k);
			k = 33;
			s2.addRightFront(k);
			k = -5;
			s2.addRightFront(k);

			// Execute operation: swapRights
			s1.swapRights(s2);

			// Validate ensures: self.left = #self.left  and  self.right = #otherS.right
			toText(s1, x1);
			Assert::AreEqual(L"[<41,3>,<-5,33,29>]", x1, true, L"s1's internal rep = [<41,3>,<-5,33,29>]");

			// Validate ensures:   otherS.left = #otherS.left  and otherS.right = #self.right  
			toText(s2, x1);
			Assert::AreEqual(L"[<>,<22>]", x1, true, L"s2's internal rep = [<>,<22>]");
		} // UT26SwapRights

				// -----------------------------------------------------------------------------------

		TEST_METHOD(UT27SwapRights)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT27SwapRights: s1.swapRights(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<3,41,22>,<>) and s2 = (<>,<-5,33,29>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<3,41,22>,<-5,33,29>) and s2 = (<>,<>)");

			//setup test
			k = 22;
			s1.addRightFront(k);
			k = 41;
			s1.addRightFront(k);
			k = 3;
			s1.addRightFront(k);

			s1.advance();
			s1.advance();
			s1.advance();

			k = 29;
			s2.addRightFront(k);
			k = 33;
			s2.addRightFront(k);
			k = -5;
			s2.addRightFront(k);

			// Execute operation: swapRights
			s1.swapRights(s2);

			// Validate ensures: self.left = #self.left  and  self.right = #otherS.right
			toText(s1, x1);
			Assert::AreEqual(L"[<22,41,3>,<-5,33,29>]", x1, true, L"s1's internal rep = [<22,41,3>,<-5,33,29>]");

			// Validate ensures:   otherS.left = #otherS.left  and otherS.right = #self.right  
			toText(s2, x1);
			Assert::AreEqual(L"[<>,<>]", x1, true, L"s2's internal rep = [<>,<>]");
		} // UT27SwapRights

		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT28SwapRights)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT28SwapRights: s1.swapRights(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<>) and s2 = (<>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>) and s2 = (<>,<>)");

			// Execute operation: swapRights
			s1.swapRights(s2);

			// Validate ensures: self.left = #self.left  and  self.right = #otherS.right
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<>]", x1, true, L"s1's internal rep = [<>,<>]");

			// Validate ensures:   otherS.left = #otherS.left  and otherS.right = #self.right  
			toText(s2, x1);
			Assert::AreEqual(L"[<>,<>]", x1, true, L"s2's internal rep = [<>,<>]");
		} // UT28SwapRights


		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT29SwapRights)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT29SwapRights: s1.swapRights(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<3,41,22>) and s2 = (<-5,33,29>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<>) and s2 = (<-5,33,29>,<3,41,22>)");

			//setup test
			k = 22;
			s1.addRightFront(k);
			k = 41;
			s1.addRightFront(k);
			k = 3;
			s1.addRightFront(k);

			k = 29;
			s2.addRightFront(k);
			k = 33;
			s2.addRightFront(k);
			k = -5;
			s2.addRightFront(k);
			s2.advance();
			s2.advance();
			s2.advance();

			// Execute operation: swapRights
			s1.swapRights(s2);

			// Validate ensures: self.left = #self.left  and  self.right = #otherS.right
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<>]", x1, true, L"s1's internal rep = [<>,<>]");

			// Validate ensures:   otherS.left = #otherS.left  and otherS.right = #self.right  
			toText(s2, x1);
			Assert::AreEqual(L"[<29,33,-5>,<3,41,22>]", x1, true, L"s1's internal rep = [<29,33,-5>,<3,41,22>]");
		} // UT29SwapRights

		// -----------------------------------------------------------------------------------
		// leftLength
		// -----------------------------------------------------------------------------------
		//! restores self
		//! ensures: leftLength = |self.left|
		// -----------------------------------------------------------------------------------
		TEST_METHOD(UT30LeftLength)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT30LeftLength: s1.leftLength();");
			Logger::WriteMessage(L"\tincoming: s1 = (<22,41>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<22,41>,<>)");

			//setup test
			k = 41;
			s1.addRightFront(k);
			k = 22;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();

			// Validate ensures: leftLength = |self.left|
			Assert::AreEqual(2., s1.leftLength(), true, L"s1.leftLength() = 2");

			// Validate restores parameter mode: restores self
			toText(s1, x1);
			Assert::AreEqual(L"[<41,22>,<>]", x1, true, L"s1's internal rep = [<41,22>,<>]");
		} // UT30LeftLength

		TEST_METHOD(UT31LeftLength)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT31LeftLength: s1.leftLength();");
			Logger::WriteMessage(L"\tincoming: s1 = (<>,<22,41>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<>,<22,41>)");

			//setup test
			k = 41;
			s1.addRightFront(k);
			k = 22;
			s1.addRightFront(k);

			// Validate ensures: leftLength = |self.left|
			Assert::AreEqual(0., s1.leftLength(), true, L"s1.leftLength() = 0");

			// Validate restores parameter mode: restores self
			toText(s1, x1);
			Assert::AreEqual(L"[<>,<22,41>]", x1, true, L"s1's internal rep = [<>,<22,41>]");
		} // UT31LeftLength

		// -----------------------------------------------------------------------------------
		// rightLength
		// -----------------------------------------------------------------------------------
		//! restores self
		//! ensures: rightLength = |self.right|
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT32RightLength)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT32RightLength: s1.rightLength();");
			Logger::WriteMessage(L"\tincoming: s1 = (<22>,<41,-5,33>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<22>,<41,-5,33>)");

			//setup test
			k = 33;
			s1.addRightFront(k);
			k = -5;
			s1.addRightFront(k);
			k = 41;
			s1.addRightFront(k);
			k = 22;
			s1.addRightFront(k);
			s1.advance();

			// Validate ensures: rightLength = |self.right|
			Assert::AreEqual(3., s1.rightLength(), true, L"s1.rightLength() = 3");

			// Validate restores parameter mode: restores self
			toText(s1, x1);
			Assert::AreEqual(L"[<22>,<41,-5,33>]", x1, true, L"s1's internal rep = [<22>,<41,-5,33>]");
		} // UT32RightLength

		TEST_METHOD(UT33RightLength)
		{
			IntegerList s1, s2;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT33RightLength: s1.rightLength();");
			Logger::WriteMessage(L"\tincoming: s1 = (<22,41,-5,33>,<>)");
			Logger::WriteMessage(L"\toutgoing: s1 = (<22,41,-5,33>,<>)");

			//setup test
			k = 33;
			s1.addRightFront(k);
			k = -5;
			s1.addRightFront(k);
			k = 41;
			s1.addRightFront(k);
			k = 22;
			s1.addRightFront(k);
			s1.advance();
			s1.advance();
			s1.advance();
			s1.advance();

			// Validate ensures: rightLength = |self.right|
			Assert::AreEqual(0., s1.rightLength(), true, L"s1.rightLength() = 0");

			// Validate restores parameter mode: restores self
			toText(s1, x1);
			Assert::AreEqual(L"[<33,-5,41,22>,<>]", x1, true, L"s1's internal rep = [<22,33,-5,41>,<>]");
		} // UT33RightLength

	};

	
}
