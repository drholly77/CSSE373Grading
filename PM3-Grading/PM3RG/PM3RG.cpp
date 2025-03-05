#include "pch.h"
#include "CppUnitTest.h"
#include "UUGraph.h"
#include "IntSet.h"
#include "SetOfSets.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PM3RG
{

	TEST_CLASS(PM2RG)
	{
	public:

		// -----------------------------------------------------
		// UnlabeledUndirectedGraph
		// -----------------------------------------------------
		//! replaces self
		//! ensures: self = ({},{})
		// -----------------------------------------------------
		TEST_METHOD(UT01Constructor)
		{
			UnlabeledUndirectedGraph g1;
			Text x1;

			Logger::WriteMessage(L"UnlabeledUndirectedGraph();");
			Logger::WriteMessage(L"\toutgoing: g1 = ({},{})");

			// Validate ensures: self = ({},{})
			toText(g1, x1);
			Assert::AreEqual(L"({},{})", x1);
		} // UT01Constructor

		TEST_METHOD(UT02Constructor)
		{
			UnlabeledUndirectedGraph g1;
			Text x1;

			Logger::WriteMessage(L"UnlabeledUndirectedGraph();");
			Logger::WriteMessage(L"\toutgoing: |g1.vertices| = 0");

			// Validate ensures: self = ({},{})

			Assert::AreEqual(0, (int)g1.numberOfVertices(), L"g1.numberOfVertices() = 0");
		} // UT02Constructor

		TEST_METHOD(UT03Constructor)
		{
			UnlabeledUndirectedGraph g1;
			Text x1;

			Logger::WriteMessage(L"UnlabeledUndirectedGraph();");
			Logger::WriteMessage(L"\toutgoing: |g1.edges| = 0");

			// Validate ensures: self = ({},{})

			Assert::AreEqual(0, (int)g1.numberOfEdges(), L"g1.numberOfEdges() = 0");
		} // UT03Constructor

		// -----------------------------------------------------
		// clear
		// -----------------------------------------------------
		//! clears self
		// -----------------------------------------------------
		TEST_METHOD(UT04Clear)
		{
			UnlabeledUndirectedGraph g1;
			Text x1;

			Logger::WriteMessage(L"g1.clear();");
			Logger::WriteMessage(L"\tincoming: g1 = ({},{})");
			Logger::WriteMessage(L"\toutgoing: g1 = ({},{})");

			// Test set up

			// Execute operation: clear
			g1.clear();

			// Validate parameter mode clears: clears self
			toText(g1, x1);
			Assert::AreEqual(L"({},{})", x1);
		}

		TEST_METHOD(UT05Clear)
		{
			UnlabeledUndirectedGraph g1;
			Text x1;
			Integer k, v1, v2, nv;

			Logger::WriteMessage(L"g1.clear();");
			Logger::WriteMessage(L"\tincoming: g1 = ({1,2},{{1,2}})");
			Logger::WriteMessage(L"\toutgoing: g1 = ({},{})");

			// Test set up
			nv = 2;
			g1.setNumberOfVertices(nv);
			v1 = 1;	v2 = 2;
			g1.addEdge(v1, v2);

			// Execute operation: clear
			g1.clear();

			// Validate parameter mode clears: clears self
			toText(g1, x1);
			Assert::AreEqual(L"({},{})", x1);
		}

		TEST_METHOD(UT06Clear)
		{
			UnlabeledUndirectedGraph g1;
			Text x1;
			Integer k, v1, v2, nv;

			Logger::WriteMessage(L"g1.clear();");
			Logger::WriteMessage(L"\tincoming: g1 = ({1,2},{{1,2}})");
			Logger::WriteMessage(L"\toutgoing: |g1.vertices| = 0");

			// Test set up
			nv = 2;
			g1.setNumberOfVertices(nv);
			v1 = 1;	v2 = 2;
			g1.addEdge(v1, v2);

			// Execute operation: clear
			g1.clear();

			// Validate parameter mode clears: clears self
			Assert::AreEqual(0, (int)g1.numberOfVertices(), L"g1.numberOfVertices() = 0");
		}


		TEST_METHOD(UT07Clear)
		{
			UnlabeledUndirectedGraph g1;
			Text x1;
			Integer k, v1, v2, nv;

			Logger::WriteMessage(L"g1.clear();");
			Logger::WriteMessage(L"\tincoming: g1 = ({1,2,3,4},{{1,2},{2,4}})");
			Logger::WriteMessage(L"\toutgoing: |g1.edges| = 0");

			// Test set up
			nv = 4;
			g1.setNumberOfVertices(nv);
			v1 = 1;	v2 = 2;
			g1.addEdge(v1, v2);
			v1 = 2;	v2 = 4;
			g1.addEdge(v1, v2);

			// Execute operation: clear
			g1.clear();

			// Validate parameter mode clears: clears self
			Assert::AreEqual(0, (int)g1.numberOfEdges(), L"g1.numberOfEdges() = 0");
		}

		// -----------------------------------------------------
		// transferFrom
		// -----------------------------------------------------
		//! replaces self
		//! clears source
		//! ensures: self = #source
		// -----------------------------------------------------
		TEST_METHOD(UT08TransferFrom)
		{
			UnlabeledUndirectedGraph g1, g2;
			Text x1, x2;
			Integer v1, v2, nv1, nv2;

			Logger::WriteMessage(L"g1.transferFrom(g2);");
			Logger::WriteMessage(L"\tincoming: g1 = ({1,2},{}) and g2 = ({1,2,3,4,,5},{{3,5}})");
			Logger::WriteMessage(L"\toutgoing: g1 = ({1,2,3,4,5},{{1,2}}) and g2 = ({},{})");

			// Test set up
			nv1 = 2;
			g1.setNumberOfVertices(nv1);
			nv2 = 5;
			g2.setNumberOfVertices(nv2);
			v1 = 3;	v2 = 5;
			g2.addEdge(v1, v2);

			// Execute operation: transferFrom
			g1.transferFrom(g2);

			// Validate ensures: self = #source
			toText(g1, x1);
			Assert::AreEqual(L"({1,2,3,4,5},{{3,5}})", x1);

			// Validate clears parameter mode: clears source
			toText(g2, x2);
			Assert::AreEqual(L"({},{})", x2);
		}

		// -----------------------------------------------------
		// operator =
		// -----------------------------------------------------
		//! replaces self
		//! restores rhs
		//! ensures: self = rhs
		// -----------------------------------------------------
		TEST_METHOD(UT09Assignment)
		{
			UnlabeledUndirectedGraph g1, g2;
			Text x1, x2;
			Integer k, v1, v2, nv;

			Logger::WriteMessage(L"g1 = g2;");
			Logger::WriteMessage(L"\tincoming: g1 = ({},{}) and g2 = ({1,2},{{1,2}})");
			Logger::WriteMessage(L"\toutgoing: g1 = ({1,2},{{1,2}}) and g2 = ({1,2},{{1,2}})");

			// Test set up
			nv = 2;
			g2.setNumberOfVertices(nv);
			v1 = 1;	v2 = 2;
			g2.addEdge(v1, v2);

			// Execute operation: operator =
			g1 = g2;

			// Validate ensures: self = rhs
			toText(g1, x1);
			toText(g2, x2);
			Assert::IsTrue(x1 == x2, L"g1 = g2");

			// Validate restores parameter mode: restores rhs
			toText(g2, x2);
			Assert::AreEqual(L"({1,2},{{1,2}})", x2);
		}



		// -----------------------------------------------------
		// setNumberOfVertices
		// -----------------------------------------------------
		//! updates self
		//! restores nv
		//! ensures: self.vertices = {n: integer
		//!			 where (1 <= n <= nv) (n)}
		//!			 and self.edges = {}
		// -----------------------------------------------------
		TEST_METHOD(UT10SetNumberOfVertices)
		{
			UnlabeledUndirectedGraph g1;
			Text x1;
			Integer nv;

			Logger::WriteMessage(L"g1.setNumberOfVertices(nv);");
			Logger::WriteMessage(L"\tincoming: g1 = ({},{}), nv = 1");
			Logger::WriteMessage(L"\toutgoing: g1 = ({1},{}), nv = 1");

			// Test set up
			nv = 1;

			// Execute operation: setNumberOfVertices
			g1.setNumberOfVertices(nv);

			// Validate ensures: self.verices = {n: integer where (1 <= n <= nv) (n)}
			//                 and self.edges = {}
			toText(g1, x1);
			Assert::AreEqual(L"({1},{})", x1);

			// Validate restores parameter mode: restores nv
			Assert::AreEqual(1, (int)nv, L"nv = 1");
		}

		TEST_METHOD(UT11SetNumberOfVertices)
		{
			UnlabeledUndirectedGraph g1;
			Text x1;
			Integer nv;

			Logger::WriteMessage(L"g1.setNumberOfVertices(nv);");
			Logger::WriteMessage(L"\tincoming: g1 = ({},{}), nv = 3");
			Logger::WriteMessage(L"\toutgoing: g1 = ({1,2,3},{}), nv = 3");

			// Test set up
			nv = 3;

			// Execute operation: setNumberOfVertices
			g1.setNumberOfVertices(nv);

			// Validate ensures: self.verices = {n: integer where (1 <= n <= nv) (n)}
			//                 and self.edges = {}
			toText(g1, x1);
			Assert::AreEqual(L"({1,2,3},{})", x1);

			// Validate restores parameter mode: restores nv
			Assert::AreEqual(3, (int)nv, L"nv = 3");
		}

		// -----------------------------------------------------
		// addEdge
		// -----------------------------------------------------
		//! updates self
		//! restores v1, v2
		//! requires: v1 is in g.vertices and v2
		//!			  is in g.vertices and {v1,v2}
		//!			  is not in g.edges
		//! ensures: g.vertices = #g.vertices and 
		//!			 g.edges = #g.edges union {{v1,v2}}
		// -----------------------------------------------------
		TEST_METHOD(UT12AddEdge)
		{
			UnlabeledUndirectedGraph g1;
			Integer v1, v2, nv;
			Text x1;

			Logger::WriteMessage(L"g1.addEdge(v1, v2);");
			Logger::WriteMessage(L"\tincoming: g1 = ({1,2,3},{})");
			Logger::WriteMessage(L"\toutgoing: g1 = ({1,2,3},{{1,3}})");

			// Test set up

			nv = 3;
			g1.setNumberOfVertices(nv);

			v1 = 1;	v2 = 3;

			// Execute operation: addEdge
			g1.addEdge(v1, v2);

			// Validate ensures: self.vertices = {n: integer where (1 <= n <= nv) (n)}
			//                 and self.edges = {}
			toText(g1, x1);
			Assert::AreEqual(L"({1,2,3},{{1,3}})", x1);

			// Validate restores parameter mode: restores v1, v2
			Assert::AreEqual(1, (int)v1, L"v1 = 1");
			Assert::AreEqual(3, (int)v2, L"v2 = 3");
		}


		TEST_METHOD(UT13AddEdge)
		{
			UnlabeledUndirectedGraph g1;
			Integer v1, v2, nv;
			Text x1;

			Logger::WriteMessage(L"g1.addEdge(v1, v2);");
			Logger::WriteMessage(L"\tincoming: g1 = ({1,2,3,4,5},{{1,3}})");
			Logger::WriteMessage(L"\toutgoing: g1 = ({1,2,3,4,5},{{1,3},{1,5}})");

			// Test set up
			nv = 5;
			g1.setNumberOfVertices(nv);
			v1 = 3;	v2 = 1;
			g1.addEdge(v1, v2);

			// Execute operation: addEdge
			v1 = 1;	v2 = 5;
			g1.addEdge(v1, v2);

			// Validate ensures: self.vertices = {n: integer where (1 <= n <= nv) (n)}
			//                 and self.edges = {}
			toText(g1, x1);
			Assert::AreEqual(L"({1,2,3,4,5},{{1,3},{1,5}})", x1);

			// Validate restores parameter mode: restores v1, v2
			Assert::AreEqual(1, (int)v1, L"v1 = 1");
			Assert::AreEqual(5, (int)v2, L"v2 = 5");
		}// UT07AddEdge

		// -----------------------------------------------------
		// removeEdge
		// -----------------------------------------------------
		//! updates self
		//! restores v1,v2
		//! requires: v1 is in g.vertices and v2 is
		//!			  in g.vertices and {v1,v2} is
		//!           in g.edges
		//! ensures: g.vertices = #g.vertices and
		//!          g.edges = #g.edges - {{v1,v2}}
		// -----------------------------------------------------
		TEST_METHOD(UT14RemoveEdge)
		{
			UnlabeledUndirectedGraph g1;
			Integer v1, v2, nv;
			Text x1;

			Logger::WriteMessage(L"g1.removeEdge(v1, v2);");
			Logger::WriteMessage(L"\tincoming: g1 = ({1,2,3,4},{{1,2},{3,4}})");
			Logger::WriteMessage(L"\toutgoing: g1 = ({1,2,3,4},{{3,4}})");

			// Test set up
			nv = 4;
			g1.setNumberOfVertices(nv);
			v1 = 1;	v2 = 2;
			g1.addEdge(v1, v2);
			v1 = 3;	v2 = 4;
			g1.addEdge(v1, v2);
			v1 = 1;	v2 = 2;

			// Execute operation: removeEdge
			g1.removeEdge(v1, v2);

			// Validate ensures: g.vertices = #g.vertices and g.edges = #g.edges - {{v1,v2}}
			toText(g1, x1);
			Assert::AreEqual(L"({1,2,3,4},{{3,4}})", x1);

			// Validate restores parameter mode: restores v1, v2
			Assert::AreEqual(1, (int)v1, L"v1 = 1");
			Assert::AreEqual(2, (int)v2, L"v2 = 2");
		}


		// -----------------------------------------------------
		// removeAnyIncidentEdge
		// -----------------------------------------------------
		//! updates self
		//! restores v1
		//! replaces v2
		//! requires: v1 is in g.vertices and there exists
		//!           v : integer ({v1, v} is in g.edges)
		//! ensures: g.vertices = #g.vertices and {v1,v2}
		//!          is in #g.edges and g.edges = #g.edges - {{v1,v2}}
		// -----------------------------------------------------
		TEST_METHOD(UT15RemoveAnyIncidentEdge)
		{
			UnlabeledUndirectedGraph g1;
			Integer v1, v2, nv;
			Text x1;

			Logger::WriteMessage(L"g1.removeAnyIncidentEdge(v1, v2);");
			Logger::WriteMessage(L"\tincoming: g1 = ({1,2,3,4},{{1,2},{1,4},{3,4}})");
			Logger::WriteMessage(L"\toutgoing: g1 = ({1,2,3,4},{{1,4},{3,4}})");

			// Test set up
			nv = 4;
			g1.setNumberOfVertices(nv);
			v1 = 1;	v2 = 2;
			g1.addEdge(v1, v2);
			v1 = 3;	v2 = 4;
			g1.addEdge(v1, v2);
			v1 = 1;	v2 = 4;
			g1.addEdge(v1, v2);


			// Execute operation: removeAnyIncidentEdge
			v1 = 2;	v2 = 7;
			g1.removeAnyIncidentEdge(v1, v2);

			// Validate ensures: g.vertices = #g.vertices and {v1,v2} is in
			//                 #g.edges and g.edges = #g.edges - {{v1,v2}}
			toText(g1, x1);
			Assert::AreEqual(L"({1,2,3,4},{{1,4},{3,4}})", x1);

			// Validate restores parameter mode: restores v1
			Assert::AreEqual(2, (int)v1, L"v1 = 2");
			// Validate replaces parameter mode: replaces v2
			Assert::AreEqual(1, (int)v2, L"v2 = 1");
		}

		TEST_METHOD(UT16RemoveAnyIncidentEdge)
		{
			UnlabeledUndirectedGraph g1;
			Integer v1, v2, v2Copy, nv;
			Text x1;
			IntegerSet sActual, sExpected;

			Logger::WriteMessage(L"g1.removeAnyIncidentEdge(v1, v2);");
			Logger::WriteMessage(L"\tincoming: g1 = ({1,2,3,4,5,6,7},{{1,2},{1,4},{1,7},{3,4}})");
			Logger::WriteMessage(L"\toutgoing: g1 = ({1,2,3,4,5,6,7},{{3,4}})");

			// Test set up
			nv = 7;
			g1.setNumberOfVertices(nv);
			v1 = 1;	v2 = 2;
			v2Copy = v2;
			sExpected.add(v2Copy);
			g1.addEdge(v1, v2);
			v1 = 1;	v2 = 4;
			v2Copy = v2;
			sExpected.add(v2Copy);
			g1.addEdge(v1, v2);
			v1 = 1;	v2 = 7;
			v2Copy = v2;
			sExpected.add(v2Copy);
			g1.addEdge(v1, v2);

			// Add edge not related to vertex 1
			v1 = 3;	v2 = 4;
			g1.addEdge(v1, v2);

			// Execute operation: removeAnyIncidentEdge
			v1 = 1;	v2 = 7;
			while (g1.degree(v1) > 0) {
				g1.removeAnyIncidentEdge(v1, v2);
				sActual.add(v2);
			}

			// Validate ensures: g.vertices = #g.vertices and 
			//                   g.edges = #g.edges - {{v1,v2}}
			toText(g1, x1);
			Assert::AreEqual(L"({1,2,3,4,5,6,7},{{3,4}})", x1);

			// Validate restores parameter mode: restores v1
			Assert::AreEqual(1, (int)v1, L"v1 = 1");
			// Validate replaces parameter mode: replaces v2
			Assert::IsTrue(sExpected == sActual, L"sExpected = {2,4,7}");
		}

		// -----------------------------------------------------
		// removeAnyEdge
		// -----------------------------------------------------
		//! updates self
		//! replaces v1,v2
		//! requires: g.edges /= {}
		//! ensures: g.vertices = #g.vertices and {v1,v2}
		//!          is in #g.edges and g.edges = #g.edges - {{v1,v2}}
		// -----------------------------------------------------
		TEST_METHOD(UT17RemoveAnyEdge)
		{
			UnlabeledUndirectedGraph g1;
			Integer v1, v2, v1Copy, v2Copy, nv;
			Text x1;
			SetOfIntegerSets sExpected, sActual;
			IntegerSet si;

			Logger::WriteMessage(L"g1.removeAnyEdge(v1, v2);");
			Logger::WriteMessage(L"\tincoming: g1 = ({1,2,3,4},{{3,4}})");
			Logger::WriteMessage(L"\toutgoing: g1 = ({1,2,3,4},{})");

			// Test set up
			nv = 4;
			g1.setNumberOfVertices(nv);
			v1 = 3;	v2 = 4;
			v1Copy = v1; v2Copy = v2;
			si.add(v1Copy);
			si.add(v2Copy);
			sActual.add(si);
			g1.addEdge(v1, v2);
			v1 = 0;	v2 = 0;

			// Execute operation: removeAnyEdge
			g1.removeAnyEdge(v1, v2);
			si.add(v1);
			si.add(v2);
			sExpected.add(si);

			// Validate ensures: g.vertices = #g.vertices and {v1,v2} is in
			//                 #g.edges and g.edges = #g.edges - {{v1,v2}
			toText(g1, x1);
			Assert::AreEqual(L"({1,2,3,4},{})", x1);


			// Validate replaces parameter mode: replaces v1 and v2
			Assert::IsTrue(sExpected == sActual, L"sExpected = {{3,4}}");
		}

		TEST_METHOD(UT18RemoveAnyEdge)
		{
			UnlabeledUndirectedGraph g1;
			Integer v1, v2, v1Copy, v2Copy, nv;
			Text x1;
			SetOfIntegerSets sExpected, sActual;
			IntegerSet si;

			Logger::WriteMessage(L"g1.removeAnyEdge(v1, v2);");
			Logger::WriteMessage(L"\tincoming: g1 = ({1,2,3,4,5},{{1,2},{1,3},{2,3},{2,4},{3,5}})");
			Logger::WriteMessage(L"\toutgoing: g1 = ({1,2,3,4,5},{})");

			// Test set up
			nv = 5;
			g1.setNumberOfVertices(nv);

			v1 = 1;	v2 = 2;
			v1Copy = v1; v2Copy = v2;
			si.add(v1Copy);
			si.add(v2Copy);
			sActual.add(si);
			g1.addEdge(v1, v2);

			v1 = 1;	v2 = 3;
			v1Copy = v1; v2Copy = v2;
			si.add(v1Copy);
			si.add(v2Copy);
			sActual.add(si);
			g1.addEdge(v1, v2);

			v1 = 3;	v2 = 2;
			v1Copy = v1; v2Copy = v2;
			si.add(v1Copy);
			si.add(v2Copy);
			sActual.add(si);
			g1.addEdge(v1, v2);

			v1 = 4;	v2 = 2;
			v1Copy = v1; v2Copy = v2;
			si.add(v1Copy);
			si.add(v2Copy);
			sActual.add(si);
			g1.addEdge(v1, v2);

			v1 = 3;	v2 = 5;
			v1Copy = v1; v2Copy = v2;
			si.add(v1Copy);
			si.add(v2Copy);
			sActual.add(si);
			g1.addEdge(v1, v2);

			v1 = 0;	v2 = 0;

			// Execute operation: removeAnyEdge
			while (g1.numberOfEdges() > 0) {
				g1.removeAnyEdge(v1, v2);
				IntegerSet si;
				si.add(v1);
				si.add(v2);
				sExpected.add(si);
			}


			// Validate ensures: g.vertices = #g.vertices and {v1,v2} is in
			//                 #g.edges and g.edges = #g.edges - {{v1,v2}
			toText(g1, x1);
			Assert::AreEqual(L"({1,2,3,4,5},{})", x1);

			// Validate replaces parameter mode: replaces v1 and v2
			Assert::IsTrue(sExpected == sActual, L"sExpected = {{1,2},{1,3},{2,3},{2,4},{3,5}}");
		}

		// -----------------------------------------------------
		// numberOfVertices
		// -----------------------------------------------------
		//! restores self
		//! ensures: numberOfVertices = |g.vertices|
		// -----------------------------------------------------
		TEST_METHOD(UT19NumberOfVertices)
		{
			UnlabeledUndirectedGraph g1;
			Integer nv;
			Text x1;

			Logger::WriteMessage(L"nv = g1.numberOfVertices();");
			Logger::WriteMessage(L"\tincoming: g1 = ({1,2,3,4,5,6,7},{})");
			Logger::WriteMessage(L"\toutgoing: g1 = ({1,2,3,4,5,6,7},{})");

			// Test set up

			nv = 7;
			g1.setNumberOfVertices(nv);
			nv = 0;

			// Execute operation: numberOfVertices
			nv = g1.numberOfVertices();

			// Validate ensures: numberOfVertices = |g.vertices|
			Assert::AreEqual(7, (int)nv, L"nv = 7");

			// Validate restores parameter mode: restores self
			toText(g1, x1);
			Assert::AreEqual(L"({1,2,3,4,5,6,7},{})", x1);
		}

		TEST_METHOD(UT20NumberOfVertices)
		{
			UnlabeledUndirectedGraph g1;
			Integer nv;
			Text x1;

			Logger::WriteMessage(L"nv = g1.numberOfVertices();");
			Logger::WriteMessage(L"\tincoming: g1 = ({1},{})");
			Logger::WriteMessage(L"\toutgoing: g1 = ({1},{})");

			// Test set up

			nv = 1;
			g1.setNumberOfVertices(nv);
			nv = 0;

			// Execute operation: numberOfVertices
			nv = g1.numberOfVertices();

			// Validate ensures: numberOfVertices = |g.vertices|
			Assert::AreEqual(1, (int)nv, L"nv = 7");

			// Validate restores parameter mode: restores self
			toText(g1, x1);
			Assert::AreEqual(L"({1},{})", x1);
		}

		// -----------------------------------------------------
		// numberOfEdges
		// -----------------------------------------------------
		//! restores self
		//! ensures: numberOfEdges = |g.edges|
		// -----------------------------------------------------
		TEST_METHOD(UT21NumberOfEdges)
		{
			UnlabeledUndirectedGraph g1;
			Integer k, v1, v2, nv;
			Text x1;

			Logger::WriteMessage(L"k = g1.numberOfEdges();");
			Logger::WriteMessage(L"\tincoming: g1 = ({1,2,3,4,5},{{3,4}})");
			Logger::WriteMessage(L"\toutgoing: g1 = ({1,2,3,4,5},{{3,4}})");

			// Test set up
			nv = 5;
			g1.setNumberOfVertices(nv);
			v1 = 3;	v2 = 4;
			g1.addEdge(v1, v2);

			// Execute operation: numberOfEdges
			k = g1.numberOfEdges();

			// Validate ensures: numberOfEdges = |g.edges|
			Assert::AreEqual(1, (int)k, L"k = 1");

			// Validate restores parameter mode: restores self
			toText(g1, x1);
			Assert::AreEqual(L"({1,2,3,4,5},{{3,4}})", x1);
		}

		// -----------------------------------------------------
		// degree
		// -----------------------------------------------------
		//! restores self,v
		//! ensures: degree = |{v2: integer where ({v,v2} is in g.edges) (v2)}|
		// -----------------------------------------------------
		TEST_METHOD(UT22Degree)
		{
			UnlabeledUndirectedGraph g1;
			Integer k, v1, v2, nv;
			Text x1;

			Logger::WriteMessage(L"k = g1.degree(v1);");
			Logger::WriteMessage(L"\tincoming: g1 = ({1,2,3,4,5},{})");
			Logger::WriteMessage(L"\toutgoing: g1 = ({1,2,3,4,5},{})");

			// Test set up
			nv = 5;
			g1.setNumberOfVertices(nv);

			v1 = 1;
			// Execute operation: degree
			k = g1.degree(v1);

			// Validate ensures: degree = |{v2: integer where ({v,v2} is in g.edges) (v2)}|
			Assert::AreEqual(0, (int)k, L"k = 0");

			// Validate restores parameter mode: restores self, v
			toText(g1, x1);
			Assert::AreEqual(L"({1,2,3,4,5},{})", x1);
			Assert::AreEqual(1, (int)v1, L"v1 = 1");
		}

		TEST_METHOD(UT23Degree)
		{
			UnlabeledUndirectedGraph g1;
			Integer k, v1, v2, nv;
			Text x1;

			Logger::WriteMessage(L"k = g1.degree(v1);");
			Logger::WriteMessage(L"\tincoming: g1 = ({1,2,3,4},{{1,2},{1,3},{1,4}})");
			Logger::WriteMessage(L"\toutgoing: g1 = ({1,2,3,4},{{1,2},{1,3},{1,4}})");

			// Test set up
			nv = 4;
			g1.setNumberOfVertices(nv);
			v1 = 4;	v2 = 1;
			g1.addEdge(v1, v2);
			v1 = 1;	v2 = 2;
			g1.addEdge(v1, v2);
			v1 = 1;	v2 = 3;
			g1.addEdge(v1, v2);

			v1 = 1;
			// Execute operation: degree
			k = g1.degree(v1);

			// Validate ensures: degree = |{v2: integer where ({v,v2} is in g.edges) (v2)}|
			Assert::AreEqual(3, (int)k, L"k = 3");

			// Validate restores parameter mode: restores self, v
			toText(g1, x1);
			Assert::AreEqual(L"({1,2,3,4},{{1,2},{1,3},{1,4}})", x1);
			Assert::AreEqual(1, (int)v1, L"v1 = 1");
		}

		TEST_METHOD(UT24Degree)
		{
			UnlabeledUndirectedGraph g1;
			Integer k, v1, v2, nv;
			Text x1;

			Logger::WriteMessage(L"k = g1.degree(v1);");
			Logger::WriteMessage(L"\tincoming: g1 = ({1,2,3,4},{{1,2},{1,3},{1,4},{2,3},{3,4}})");
			Logger::WriteMessage(L"\toutgoing: g1 = ({1,2,3,4},{{1,2},{1,3},{1,4},{2,3},{3,4}})");

			// Test set up
			nv = 4;
			g1.setNumberOfVertices(nv);
			v1 = 4;	v2 = 1;
			g1.addEdge(v1, v2);
			v1 = 1;	v2 = 2;
			g1.addEdge(v1, v2);
			v1 = 1;	v2 = 3;
			g1.addEdge(v1, v2);

			// Other edges
			v1 = 2;	v2 = 3;
			g1.addEdge(v1, v2);
			v1 = 4;	v2 = 3;
			g1.addEdge(v1, v2);

			v1 = 1;
			// Execute operation: degree
			k = g1.degree(v1);

			// Validate ensures: degree = |{v2: integer where ({v,v2} is in g.edges) (v2)}|
			Assert::AreEqual(3, (int)k, L"k = 3");

			// Validate restores parameter mode: restores self, v
			toText(g1, x1);
			Assert::AreEqual(L"({1,2,3,4},{{1,2},{1,3},{1,4},{2,3},{3,4}})", x1);
			Assert::AreEqual(1, (int)v1, L"v1 = 1");
		}

		// -----------------------------------------------------
		// idEdge
		// -----------------------------------------------------
		//! restores self,v1,v2
		//! ensures: isEdge = ({v1,v2} is in g.edges)
		// -----------------------------------------------------
		TEST_METHOD(UT25IsEdge)
		{
			UnlabeledUndirectedGraph g1;
			Integer v1, v2, nv;
			Text x1;

			Logger::WriteMessage(L"g1.isEdge(v1, v2) = true");
			Logger::WriteMessage(L"\tincoming: g1 = ({1,2,3,4},{{1,4},{2,4},{3,4}})");
			Logger::WriteMessage(L"\toutgoing: g1 = ({1,2,3,4},{{1,4},{2,4},{3,4}})");

			// Test set up
			nv = 4;
			g1.setNumberOfVertices(nv);
			v1 = 4;	v2 = 2;
			g1.addEdge(v1, v2);
			v1 = 4;	v2 = 1;
			g1.addEdge(v1, v2);
			v1 = 4;	v2 = 3;
			g1.addEdge(v1, v2);

			v1 = 2;	v2 = 4;
			// Execute operation: isEdge
			// Validate ensures: isEdge = ({v1,v2} is in g.edges)
			Assert::IsTrue(g1.isEdge(v1, v2), L"g1.isEdge(v1, v2) = true");

			// Validate restores parameter mode: restores self, v1, v2
			toText(g1, x1);
			Assert::AreEqual(L"({1,2,3,4},{{1,4},{2,4},{3,4}})", x1);
			Assert::AreEqual(2, (int)v1, L"v1 = 2");
			Assert::AreEqual(4, (int)v2, L"v2 = 4");
		}

		TEST_METHOD(UT26IsEdge)
		{
			UnlabeledUndirectedGraph g1;
			Integer v1, v2, nv;
			Text x1;

			Logger::WriteMessage(L"g1.isEdge(v1, v2) = false");
			Logger::WriteMessage(L"\tincoming: g1 = ({1,2,3,4,5,6},{{1,3},{2,4}})");
			Logger::WriteMessage(L"\toutgoing: g1 = ({1,2,3,4,5,6},{{1,3},{2,4}})");

			// Test set up
			nv = 6;
			g1.setNumberOfVertices(nv);
			v1 = 2;	v2 = 4;
			g1.addEdge(v1, v2);
			v1 = 3;	v2 = 1;
			g1.addEdge(v1, v2);

			v1 = 3;	v2 = 4;
			// Execute operation: isEdge
			// Validate ensures: isEdge = ({v1,v2} is in g.edges)
			Assert::IsFalse(g1.isEdge(v1, v2), L"g1.isEdge(v1, v2) = false");

			// Validate restores parameter mode: restores self, v1, v2
			toText(g1, x1);
			Assert::AreEqual(L"({1,2,3,4,5,6},{{1,3},{2,4}})", x1);
			Assert::AreEqual(3, (int)v1, L"v1 = 3");
			Assert::AreEqual(4, (int)v2, L"v2 = 4");
		}

		TEST_METHOD(UT27IsEdge)
		{
			UnlabeledUndirectedGraph g1;
			Integer v1, v2;
			Text x1;

			Logger::WriteMessage(L"g1.isEdge(v1, v2) = false");
			Logger::WriteMessage(L"\tincoming: g1 = ({},{})");
			Logger::WriteMessage(L"\toutgoing: g1 = ({},{})");

			// Test set up
			v1 = 3;	v2 = 4;
			// Execute operation: isEdge
			// Validate ensures: isEdge = ({v1,v2} is in g.edges)
			Assert::IsFalse(g1.isEdge(v1, v2), L"g1.isEdge(v1, v2) = false");

			// Validate restores parameter mode: restores self, v1, v2
			toText(g1, x1);
			Assert::AreEqual(L"({},{})", x1);
			Assert::AreEqual(3, (int)v1, L"v1 = 3");
			Assert::AreEqual(4, (int)v2, L"v2 = 4");
		}
	};
}
