//---------------------------------------------------------------------
// Tabitha Roemish; CS 132; Section A
//
//example of a template Array Class using dynamic allocation
// by Paul Bladek
// compiled using MS Visual C++.NET 2013
// v1.0  completed May 20, 2003
// v1.01 completed November 30, 2005
// v1.02 completed February 23, 2012
// v1.03 completed February 22, 2017 by Tabitha Roemish
//---------------------------------------------------------------------

#ifndef CARRAY_H
#define CARRAY_H

#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

namespace PB_ARRAY
{
	template <class T>
	class CArray
	{
	public:
		// constructors
		CArray(unsigned size = DEFAULT_SIZE, T element = static_cast<T>(0));
		CArray(const CArray<T>& otherArray);

		// destructor
		~CArray() { if (m_array != nullptr) delete[] m_array; }
		unsigned getSize() const { return m_size; }
		void print(ostream& sout, char delimiter = ' ') const;

		// operators
		CArray<T> operator=(const CArray<T>& otherArray);
		T& operator[](unsigned index);
		const T& operator[](unsigned index) const;
		CArray<T> operator*=(unsigned scalar);
		CArray<T> operator*(unsigned scalar) const;
		CArray<T> operator+(const CArray<T> &array) const;
		CArray<T> operator+=(const CArray<T> &array);
		static const int DEFAULT_SIZE = 10;
	private: // properties
		T* m_array;
		unsigned m_size;
	};

	template <class T>
	ostream & operator<<(ostream & sout, const CArray<T> &array);

	//---------------------------------------------------------------------
	// constructor
	//---------------------------------------------------------------------
	template <class T>
	CArray<T>::CArray(unsigned size, T element)
		: m_array(nullptr), m_size(size)
	{
		if (size > 0)
			m_array = new T[size];
		else
			size = 0;
		for (unsigned i = 0; i < size; i++)
			m_array[i] = element;
	}

	//---------------------------------------------------------------------
	// copy constructor
	//---------------------------------------------------------------------
	template <class T>
	CArray<T>::CArray(const CArray<T>& otherArray)
		: m_array(nullptr), m_size(otherArray.m_size)
	{
		if (m_size > 0)
			m_array = new T[m_size];
		else
			m_size = 0;
		for (unsigned i = 0; i < m_size; i++)
			m_array[i] = otherArray.m_array[i];
	}

	//---------------------------------------------------------------------
	// print()	prints the elements of the array to sout
	//---------------------------------------------------------------------
	template <class T>
	void CArray<T>::print(ostream& sout, char delimiter) const
	{
		for (unsigned i = 0; i < m_size; i++)
			sout << m_array[i] << delimiter;
		sout << endl;
	}

	//---------------------------------------------------------------------
	// operator=     deep copy
	//---------------------------------------------------------------------
	template <class T>
	CArray<T> CArray<T>::operator=(const CArray<T>& otherArray)
	{
		if (this != &otherArray)  // don't let it copy over itself
		{
			m_size = otherArray.m_size;
			if (m_array)
				delete[] m_array;
			m_array = nullptr;
			if (m_size > 0)
				m_array = new T[m_size];
			for (unsigned i = 0; i < m_size; i++)
				m_array[i] = otherArray.m_array[i];
		}
		return *this;
	}

	//---------------------------------------------------------------------
	// operator[]    modify individual array members
	//---------------------------------------------------------------------
	template <class T>
	T& CArray<T>::operator[](unsigned index)
	{
		if (index >= m_size)
			throw range_error("index out of range");
		return m_array[index];
	}

	//---------------------------------------------------------------------
	// operator[]    access individual array members
	//---------------------------------------------------------------------
	template <class T>
	const T& CArray<T>::operator[](unsigned index) const
	{
		if (index >= m_size)
			throw range_error("index out of range");
		return m_array[index];
	}

	//---------------------------------------------------------------------
	// operator*   scalar multiplication--multiplies each element by scalar
	//---------------------------------------------------------------------
	template <class T>
	CArray<T> CArray<T>::operator*(unsigned scalar) const
	{
		CArray<T> temp(*this);
		for (unsigned i = 0; i < m_size; i++)
			temp[i] = m_array[i] * scalar;
		return temp;
	}

	//---------------------------------------------------------------------
	// operator*=    scalar multiplication and assignment
	//---------------------------------------------------------------------
	template <class T>
	CArray<T> CArray<T>::operator*=(unsigned scalar)
	{
		return *this = *this * scalar;
	}

	//---------------------------------------------------------------------
	// operator<<    outputs array to sout
	//---------------------------------------------------------------------
	template <class T>
	ostream & operator<<(ostream & sout, const CArray<T> &array)
	{
		array.print(sout);
		return sout;
	}
	//---------------------------------------------------------------------
	// operator+
	//---------------------------------------------------------------------
	template <class T>
	CArray<T> CArray<T>::operator+(const CArray<T> &array) const
	{
		CArray<T> temp(m_size + array.m_size);
		
		for (unsigned i = 0; i < m_size; i++)
			temp[i] = m_array[i];
	
		for (unsigned j = 0; j < array.m_size; j++)
			temp[j + m_size] = array.m_array[j];
			
		return temp;
	}

	//---------------------------------------------------------------------
	// operator+=
	//---------------------------------------------------------------------
	template <class T>
	CArray<T> CArray<T>::operator+=(const CArray<T> &array)
	{
		return *this = *this + array;
	}

}

#endif


