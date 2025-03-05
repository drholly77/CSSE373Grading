#pragma once
#pragma warning( disable : 4716; disable : 4172 )
/*  TODO: put your name as the author
	Author:
*/
#include "List/ListKernel.hpp"
#include "PreemptableQueue\PreemptableQueue1.hpp"

//-----------------------------------------------------------------------
// template Class Specification
//-----------------------------------------------------------------------

template <class T>
class List6 : public StdOps<List6<T>>, public ListKernel<List6<T>, T>

{
public: // Standard Operations
	List6();
	List6(const List6& s) = delete;
	~List6();
	void clear(void);
	void transferFrom(List6& source);
	List6& operator = (List6& rhs);

	// List6 Specific Operations
	void moveToStart(void);
	void moveToFinish(void);
	void advance(void);
	void addRightFront(T& x);
	void removeRightFront(T& x);
	T& rightFront(void);
	void replaceRightFront(T& x);
	void swapRights(List6& otherS);
	Integer leftLength(void);
	Integer rightLength(void);

	friend wostream& operator<< <T>(wostream& os, List6<T>& s);
	//! updates os
	//! restores s

private: // Representation
	typedef PreemptableQueue1<T> PQueueOfT;

	PQueueOfT qL;
	PQueueOfT qR;
	//! correspondence:
	//! self.left = rev(qL) and self.right = qR
	//! self = (<11,22,33>,<44,55>)
	//! self.left = <33,22,11>
	//! self.right = <44,55>

};

//-----------------------------------------------------------------------
// member Function Implementations
//-----------------------------------------------------------------------

//-----------------------------------------------------------------------
// private Operations
//-----------------------------------------------------------------------


//-----------------------------------------------------------------------
// exported Operations
//-----------------------------------------------------------------------

template <class T>
List6<T>::List6 ()
{
}	// List6

//-----------------------------------------------------------------------

template <class T>
List6<T>::~List6 ()
{
}	// ~List6

//-----------------------------------------------------------------------

template <class T>
void List6<T>::transferFrom(List6& source)
{
	// TODO: Finish me
	qL.transferFrom(source.qL);
	qR.transferFrom(source.qR);
} // transferFrom

//-----------------------------------------------------------------------

template <class T>
List6<T>& List6<T>::operator = (List6& rhs)
{
	// TODO: Finish me
	qL = rhs.qL;
	qR = rhs.qR;
	return *this;
} // operator =

//-----------------------------------------------------------------------

template <class T>
void List6<T>::clear (void)
{
	// TODO: Finish me
	qL.clear();
	qR.clear();
}	// clear

//-----------------------------------------------------------------------

template <class T>
void List6<T>::moveToStart (void)
{
	// TODO: Finish me - Optional
	//! self = (<11,22,33>,<44,55>)
	//! self.left = <33,22,11>
	//! self.right = <44,55>
	for (int k = 0, z = qL.length(); k < z; k++) {
		T x;
		qL.dequeue(x);
		qR.inject(x);
	} // end for
}	// moveToStart

//-----------------------------------------------------------------------

template <class T>
void List6<T>::moveToFinish (void)
{
	// TODO: Finish me - Required
	for (int k = 0, z = qR.length(); k < z; k++) {
		T x;
		qR.dequeue(x);
		qL.inject(x);
	} // end for
}	// moveToFinish

//-----------------------------------------------------------------------

template <class T>
void List6<T>::advance (void)
{
	// TODO: Finish me - Required
	T x;
	qR.dequeue(x);
	qL.inject(x);
}	// advance

//-----------------------------------------------------------------------

template <class T>
void List6<T>::addRightFront (T& x)
{
	// TODO: Finish me - Required
	qR.inject(x);
}	// addRightFront

//-----------------------------------------------------------------------

template <class T>
void List6<T>::removeRightFront (T& x)
{
	// TODO: Finish me
	qR.dequeue(x);
}	// removeRightFront

//-----------------------------------------------------------------------

template <class T>
T& List6<T>::rightFront(void)
{
	// TODO: Finish me
	return qR.front();  // A return is required, this one is incorrect, here only to avoid compiler error
}  // rightFront


//-----------------------------------------------------------------------

template <class T>
void List6<T>::replaceRightFront (T& x)
{
	// TODO: Finish me
	qR.replaceFront(x);
} // replaceRightFront

//-----------------------------------------------------------------------

template <class T>
void List6<T>::swapRights (List6& s)
{
	// TODO: Finish me
	PQueueOfT temp;
	temp.transferFrom(s.qR);
	s.qR.transferFrom(qR);
	qR.transferFrom(temp);
}	// swapRights

//-----------------------------------------------------------------------

template <class T>
Integer List6<T>::leftLength (void)
{
	// TODO: Finish me
	return qL.length();
}	// leftLength

//-----------------------------------------------------------------------

template <class T>
inline Integer List6<T>::rightLength (void)
{
	// TODO: Finish me
	return qR.length();
}	// rightLength

//-----------------------------------------------------------------------

//-----------------------------------------------------------------------

template <class T>
wostream& operator<<(wostream& os, List6<T>& s)
{
	// Do not change this operation
#ifdef _DEBUG
	// When in Debug mode produce the internal representation for
	// the Lists' string representation 
	os << "[" << s.qL << "," << s.qR << "]";
#else
	// When in Release mode produce the abstract representation for
	// the List's string representation 
	os << L"(<";
	int lengthOfLeft = s.leftLength();

	s.moveToStart();
	for (int k = 0, lastItem = lengthOfLeft - 1; k < lengthOfLeft; k++) {
		os << s.rightFront();
		s.advance();
		if (k < lastItem) {
			os << L",";
		} // end if
	}
	os << L">,<";

	int lengthOfRight = s.rightLength();
	for (int k = 0, lastItem = lengthOfRight - 1; k < lengthOfRight; k++) {
		os << s.rightFront();
		s.advance();
		if (k < lastItem) {
			os << L",";
		} // end if
	}
	os << L">)";

	// reset fence to original location
	s.moveToStart();
	for (int k = 0; k < lengthOfLeft; k++) {
		s.advance();
	}
#endif

	return os;
}