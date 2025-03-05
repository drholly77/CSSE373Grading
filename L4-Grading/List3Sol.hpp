#pragma once
#pragma warning( disable : 4716 )
/*
	Author: Dr. Holly
*/
#include "Queue\Queue1.hpp"

//-----------------------------------------------------------------------
// template Class Specification
//-----------------------------------------------------------------------

template <class T>
class List3
	//! is modeled by (
	//!      left: string of T
	//!      right: string of T
	//!   )
	//! exemplar self
{
public: // Standard Operations
	List3();
	//! replaces self
	//! ensures: self = (<>,<>)
	~List3();
	void clear(void);
	//! clears self
	void transferFrom(List3& source);
	//! replaces self
	//! clears source
	//! ensures: self = #source
	List3& operator = (List3& rhs);
	//! replaces self
	//! restores rhs
	//! ensures: self = rhs

	// List3 Specific Operations
	void moveToStart(void);
	//! updates self
	//! ensures: self.left = <>  and  self.right = #self.left * #self.right
	void moveToFinish(void);
	//! updates self
	//! ensures: self.right = <>  and  self.left = #self.left * #self.right
	void advance(void);
	//! updates self
	//! requires: self.right /= <>
	//! ensures: self.left * self.right = #self.left * #self.right  and
	//!          |self.left| = |#self.left| + 1
	void addRightFront(T& x);
	//! updates self.right
	//! clears x
	//! ensures: self.left = #self.left  and  self.right = <#x> * #self.right
	void removeRightFront(T& x);
	//! updates self.right
	//! replaces x
	//! requires: self.right /= <>
	//! ensures: self.left = #self.left  and
	//!          <x> is prefix of #self.right  and 
	//!          self.right = #self.right[1,|#self.right|)
	T& rightFront(void);
	//! restores self
	//! requires: self.right /= <>
	//! ensures: <rightFront> is prefix of self.right
	void replaceRightFront(T& x);
	//! updates self.right, x
	//! requires: self.right /= <>
	//! ensures: self.left = #self.left  and
	//!          <x> is prefix of #self.right  and
	//!          self.right = <#x> * #self.right[1, |#self.right|)
	void swapRights(List3& otherS);
	//! updates self.right, otherS.right
	//! ensures: self.left = #self.left  and  otherS.left = #otherS.left  and
	//!          otherS.right = #self.right  and  self.right = #otherS.right
	Integer leftLength(void);
	//! restores self
	//! ensures: leftLength = |self.left|
	Integer rightLength(void);
	//! restores self
	//! ensures: rightLength = |self.right|

	friend wostream& operator<< <T>(wostream& os, List3<T>& s);
	//! updates os
	//! restores s

private: // Representation
	typedef Queue1<T> QueueOfT;

	Integer repRZ;
	QueueOfT repQ;
	//! correspondence:
	//! 	|self.right| = repRZ and
	//! 	self.left = repQ[repRZ,|repQ|) and
	//!	    self.right = repQ[0,repRZ)


	void movePart(QueueOfT& receiver, QueueOfT& giver, Integer numberToMove);
	void moveAll(void);

private: // disallowed List3 Operations
	List3(const List3& s);
	List3* operator & (void) { return (this); };
	const List3* operator & (void) const { return (this); };
};

//-----------------------------------------------------------------------
// member Function Implementations
//-----------------------------------------------------------------------

//-----------------------------------------------------------------------
// private Operations
//-----------------------------------------------------------------------


template <class T>
void List3<T>::movePart(QueueOfT& receiver, QueueOfT& giver, Integer numberToMove) 
//! updates receiver, giver
//! restores numberToMove
//! requires: numberToMove <= |giver|
//! ensures: receiver = #receiver * #giver[0,numberToMove) and
//!          giver = #giver[numberToMove,|giver|)
{
	for (int k = 0; k < numberToMove; k++) {
		T y;
		giver.dequeue(y);
		receiver.enqueue(y);
	} // end for
} // movePart

//-----------------------------------------------------------------------

template <class T>
void List3<T>::moveAll(void)
{
	for (int k = 0; k < repRZ; k++) {
		T x;
		repQ.dequeue(x);
		repQ.enqueue(x);
	} // end for
}	// moveToFinish

//-----------------------------------------------------------------------
// exported Operations
//-----------------------------------------------------------------------

template <class T>
List3<T>::List3()
{
}	// List3

//-----------------------------------------------------------------------

template <class T>
List3<T>::~List3()
{
}	// ~List3

//-----------------------------------------------------------------------

template <class T>
void List3<T>::transferFrom(List3& source)
{
	repQ.transferFrom(source.repQ);
	repRZ.transferFrom(source.repRZ);
} // transferFrom

//-----------------------------------------------------------------------

template <class T>
List3<T>& List3<T>::operator = (List3& rhs)
{
	repQ = rhs.repQ;
	repRZ = rhs.repRZ;
	return *this;
} // operator =

//-----------------------------------------------------------------------

template <class T>
void List3<T>::clear(void)
{
	//wcout << "*******" << repQ << endl;
	//Text x1;
	//toText(repQ, x1);
	//Logger::WriteMessage(x1);
	repQ.clear();
	repRZ.clear();
}	// clear

//-----------------------------------------------------------------------

template <class T>
void List3<T>::moveToStart(void)
{
	moveAll();
	repRZ = repQ.length();
}	// moveToStart

//-----------------------------------------------------------------------

template <class T>
void List3<T>::moveToFinish(void)
{
	moveAll();
	repRZ = 0;
}	// moveToFinish

//-----------------------------------------------------------------------

template <class T>
void List3<T>::advance(void)
{
	T x;
	repQ.dequeue(x);
	repQ.enqueue(x);
	repRZ--;
}	// advance

//-----------------------------------------------------------------------

template <class T>
void List3<T>::addRightFront(T& x)
{
	QueueOfT temp;

	temp.enqueue(x);
	movePart(temp, repQ, repQ.length());
	repQ.transferFrom(temp);
	repRZ++;
}	// addRightFront

//-----------------------------------------------------------------------

template <class T>
void List3<T>::removeRightFront(T& x)
{
	repQ.dequeue(x);
	repRZ--;
}	// removeRightFront

//-----------------------------------------------------------------------

template <class T>
T& List3<T>::rightFront(void)
{
	return repQ.front();
}  // rightFront


//-----------------------------------------------------------------------

template <class T>
void List3<T>::replaceRightFront(T& x)
{
	repQ.replaceFront(x);
} // replaceRightFront

//-----------------------------------------------------------------------

template <class T>
void List3<T>::swapRights(List3& s)
{
	QueueOfT cR; // c = controlling List
	QueueOfT oR; // o = other List

	// Move each list's right
	movePart(cR, repQ, repRZ);
	movePart(oR, s.repQ, s.repRZ);

	// Now move each list's left
	movePart(cR, s.repQ, s.repQ.length());
	movePart(oR, repQ, repQ.length());

	repQ.transferFrom(oR);
	s.repQ.transferFrom(cR);

	Integer temp = repRZ;
	repRZ = s.repRZ;
	s.repRZ = temp;
}	// swapRights

//-----------------------------------------------------------------------

template <class T>
Integer List3<T>::leftLength(void)
{
	return repQ.length() - repRZ;
}	// leftLength

//-----------------------------------------------------------------------

template <class T>
inline Integer List3<T>::rightLength(void)
{
	return repRZ;
}	// rightLength

//-----------------------------------------------------------------------

//-----------------------------------------------------------------------

template <class T>
wostream& operator<<(wostream& os, List3<T>& s)
{
#ifdef _DEBUG
	os << "[" << s.repRZ << "," << s.repQ << "]";
#else
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