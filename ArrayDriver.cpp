//---------------------------------------------------------------------
// Tabitha Roemish; CS 132; Section A
//
// driver example of a template Array Class using dynamic allocation
// by Paul Bladek
// compiled using MS Visual C++.NET 2003
// v1.0  completed May 20, 2003
// v1.01 completed November 30, 2005
// v1.02 completed February 23, 2017 by Tabitha Roemish
//---------------------------------------------------------------------
#include <iostream>
#include <cstdlib>
#include <string>
#include "CArray.h"

using namespace std;

const int BUFFER_SIZE = 256;

int main(void)
{
	using PB_ARRAY::CArray;

	CArray<int> intArray(5);
	int index = 0;
	cout << intArray;
	intArray[3] = 7;
	cout << intArray << endl;

	CArray<double> doubleArray(7);
	doubleArray.print(cout, '|');
	doubleArray[3] = 7.4;
	doubleArray[2] = intArray[3];
	doubleArray.print(cout);
	cout << endl;

	CArray<double> doubleArrayCopy(doubleArray);
	CArray<double> doubleArray3;
	doubleArrayCopy.print(cout, ';');
	doubleArray[1] = 1;
	doubleArray3 = doubleArrayCopy = doubleArray;
	cout << doubleArray << doubleArrayCopy <<
		doubleArray3 << endl;

	doubleArray3 *= 2;
	cout << doubleArray * 3 << endl << doubleArray3
		<< endl << endl;;

	cout << "enter index of element to change: ";
	while (!(cin >> index))
	{
		cin.clear();
		cin.ignore(BUFFER_SIZE, '\n');
		cout << "enter index NUMBER of element to change: ";
	}

	cin.ignore(BUFFER_SIZE, '\n');
	try
	{
		doubleArray[index] = 5;
		cout  << "\tdoubleArray3 += doubleArray\n"
		<<  (doubleArray3 += doubleArray) << endl;
		cout << "\tdoubleArray3 + doubleArray\n" 
		<<  (doubleArray3 + doubleArray) << endl;
	}
	catch (exception e)
	{
		cerr << "SHUTTING DOWN; " << e.what() << endl;
		cerr << "Press \"Enter\" to continue";
		cin.get();
		return EXIT_FAILURE;
	}
	// additional constructor with strings
		//CArray<string> strArray(5); - program aborts with this construction
		//cout << "Passing \"5\" to constructor with two default paramenters";
		//cout << strArray << endl; - this object is not created. 
		
		//testing where default value fails
		// string element = static_cast<string>(0);
		// cout << element << endl;

	 // CArray type string with 2 arguments
	CArray<string> strArray2(5, "X");
	cout << "Passing \"5 and \"X\"\" to constructor with two defaults";
	cout << endl << strArray2 << endl;
	
	

	cout << doubleArray << endl;
	cout << "Press \"Enter\" to continue";
	cin.get();
	return EXIT_SUCCESS;
}