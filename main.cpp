#include <iostream>
using namespace std;

#include "String.h"
#include <cstring>

int main(void)
{	
	cout << "String str1;" << endl;
	String str1;
	cout << "str1 : " << str1 << endl << endl;
	
	cout << "String str2(\"abc\");" << endl;
	String str2("abc");
	cout << "str2 : " << str2 << endl << endl;
	
	cout << "String str3(str2);" << endl;
	String str3(str2);
	cout << "str3 : " << str3 << endl << endl;
	
	cout << "str1 = str2 + str3;" << endl;
	str1 = str2 + str3;
	cout << "str1 : " << str1 << endl << endl;
	
	cout << "str1 += str2;" << endl;
	str1 += str2;
	cout << "str1 : " << str1 << endl;
	cout << "str2 : " << str2 << endl;
	cout << "str3 : " << str3 << endl << endl;
	
	cout << "str2 == str3 : " << (str2 == str3 ? "true" : "false") << endl;
	cout << "str1 == str2 : " << (str1 == str2 ? "true" : "false") << endl;
	cout << "str1 > str2 : " << (str1 > str2 ? "true" : "false") << endl;
	cout << "str2 > str3 : " << (str2 > str3 ? "true" : "false") << endl;
	cout << "str2 < str1 : " << (str2 < str1 ? "true" : "false") << endl;
	cout << "str1 < str2 : " << (str1 < str2 ? "true" : "false") << endl;
	cout << "str2 >= str3 : " << (str2 >= str3 ? "true" : "false") << endl;
	cout << "str2 >= str1 : " << (str2 >= str1 ? "true" : "false") << endl;
	cout << "str2 <= str1 : " << (str2 <= str1 ? "true" : "false") << endl;
	cout << "str1 <= str2 : " << (str1 <= str2 ? "true" : "false") << endl << endl;
	
	cout << "input text for str3 (up to " << STR_INPUT_MAX << " characters, whitespace allowed)" << endl << ">> ";
	cin >> str3;
	cout << endl << "str3 : " << str3 << endl;
	cout << "str3.length() : " << str3.length() << endl << endl;
	
	cout << "str2[1] : " << str2[1] << endl << endl;
	
	cout << "str1.substring(1, 7) : " << str1.substring(1, 7) << endl;

	return 0;
}
