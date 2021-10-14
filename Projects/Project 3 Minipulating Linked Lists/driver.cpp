
// DRIVER
#include <iostream>
#include "Header.h"
using namespace std;

void main() {
	OOLList test;
	test.getListSizeInBytes();
	test.CosolePrint();
	test.getListSize();
	test.getListSizeInBytes();
	test.addElement(9);
	test.getListSizeInBytes();
	test.CosolePrint();
	test.addElement(5);
	test.CosolePrint();
	test.addElement(6);
	test.CosolePrint();
	test.getListSizeInBytes();
	test.addElement(4);
	test.CosolePrint();

	test.deleteElement(6);
	test.CosolePrint();
	test.addElement(9);
	test.CosolePrint();
	test.deleteElement(4);
	test.CosolePrint();
	test.addElement(7);
	test.CosolePrint();
	test.addElement(8);
	test.CosolePrint();
	test.addElement(1);
	test.CosolePrint();
	test.addElement(10);
	test.CosolePrint();
	test.deleteElement(10);

	test.CosolePrint();
	test.getListSize();
	test + 2;
	test.CosolePrint();
	test + 100;
	test.CosolePrint();
	test - 5;
	test.CosolePrint();
	test.getListSize();

}