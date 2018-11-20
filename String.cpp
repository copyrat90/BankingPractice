#include "String.h"
#include <cstring>

#define STR_INPUT_MAX 100

String::String()
	: len(0), str(NULL)
{
}

String::String(const char * szParam)
	: len(strlen(szParam))
{
	str = new char[len + 1];
	strcpy(str, szParam);
}

String::String(const String & other)
	: len(other.len)
{
	str = new char[len + 1];
	strcpy(str, other.str);
}

String::~String()
{
	delete []str;
}

String& String::operator =(const String & other)
{
	delete []str;
	len = other.len;
	str = new char[len + 1];
	strcpy(str, other.str);
}

String String::operator +(const String & other) const
{
	int newLen = len + other.len;
	char * pszTemp = new char[newLen + 1];
	strcpy(pszTemp, str);
	strcat(pszTemp, other.str);
	String strTemp(pszTemp);
	delete []pszTemp;
	return strTemp;
}

bool String::operator ==(const String & other) const
{
	return !strcmp(str, other.str);
}

int String::length() const
{
	return len;
}

char& String::operator[](int idx)
{
	return str[idx];
}

ostream& operator <<(ostream& os, const String & s)
{
	os << s.str;
	return os;
}

istream& operator >>(istream& is, String & s)
{
	char szTemp[STR_INPUT_MAX];
	is >> szTemp;
	s = String(szTemp);
	return is;
}
