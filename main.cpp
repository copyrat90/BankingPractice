#include <iostream>
using namespace std;

#include "String.h"


int main(void)
{
	String testStr("Test");
	cout << "testStr : " << testStr << " (" << testStr.length() << ")" << endl;
	
	cout << "strInput >> ";
	String strInput;
	cin >> strInput;
	cout << "strInput : " << strInput << " (" << strInput.length() << ")" << endl;
	
	if (testStr == strInput)
		cout << "testStr == strInput" << endl;
	else
		cout << "testStr != strInput" << endl;
	
	cout << endl;
	cout << "testStr = testStr + strInput;" << endl;
	testStr = testStr + strInput;
	cout << "testStr : " << testStr << " (" << testStr.length() << ")" << endl;
	
	if (testStr.length() > 0)
	{
		cout << "testStr[0] = '#';" << endl;
		testStr[0] = '#';
		cout << "testStr : " << testStr << " (" << testStr.length() << ")" << endl;
	}
	
	cout << "String testStr2(testStr);" << endl;
	String testStr2(testStr);
	cout << "testStr2 : " << testStr2 << " (" << testStr2.length() << ")" << endl;
	
	return 0;
}
