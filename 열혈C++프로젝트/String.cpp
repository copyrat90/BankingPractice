#include "pch.h"
#include "String.h"
#include <cstring>

String::String()
	: len(0), str(NULL)
{
}

String::String(const char * s)
	: len(strlen(s))
{
	str = new char[len + 1];
	strcpy(str, s);
}

String::String(const String & s)
	: len(s.len)
{
	str = new char[len + 1];
	strcpy(str, s.str);
}

String::~String()
{
	if (str != NULL)
		delete []str;
}

String& String::operator =(const String & s)
{
	if (this == &s)
		return *this;

	if (str != NULL)
		delete []str;
	len = s.len;
	if (s.str == NULL)
	{
		str = NULL;
		return *this;
	}
	str = new char[len + 1];
	strcpy(str, s.str);
	return *this;
}

String& String::operator +=(const String & s)
{
	if (s.str == NULL)
		return *this;
	if (str == NULL)
		return this->operator =(s);
	
	len += s.len;
	char * pszTemp = new char[len + 1];
	strcpy(pszTemp, str);
	strcat(pszTemp, s.str);
	delete []str;
	str = new char[len + 1];
	strcpy(str, pszTemp);
	delete []pszTemp;
	return *this;
}

String String::operator +(const String & s) const
{
	int newLen = len + s.len;
	if (newLen == 0)
		return String();
	char * pszTemp = new char[newLen + 1];
	if (str != NULL)
		strcpy(pszTemp, str);
	if (s.str != NULL)
		strcat(pszTemp, s.str);
	String strTemp(pszTemp);
	delete []pszTemp;
	return strTemp;
}

bool String::operator ==(const String & s) const
{
	if (str == NULL || s.str == NULL)
		return (len == s.len);

	return !strcmp(str, s.str);
}

bool String::operator >(const String & s) const
{
	if (str == NULL || s.str == NULL)
		return (len > s.len);
	
	int min_len = (len < s.len) ? len : s.len; 
	for (int i = 0; i < min_len; i++)
	{
		if (str[i] > s.str[i])
			return true;
		if (str[i] < s.str[i])
			return false;
	}
	return (len > s.len);
}

bool String::operator <(const String & s) const
{
	if (str == NULL || s.str == NULL)
		return (len < s.len);
		
	int min_len = (len < s.len) ? len : s.len; 
	for (int i = 0; i < min_len; i++)
	{
		if (str[i] > s.str[i])
			return false;
		if (str[i] < s.str[i])
			return true;
	}
	return (len < s.len);
}

bool String::operator >=(const String & s) const
{
	if (str == NULL || s.str == NULL)
		return (len >= s.len);
		
	int min_len = (len < s.len) ? len : s.len; 
	for (int i = 0; i < min_len; i++)
	{
		if (str[i] > s.str[i])
			return true;
		if (str[i] < s.str[i])
			return false;
	}
	return (len >= s.len);
}

bool String::operator <=(const String & s) const
{
	if (str == NULL || s.str == NULL)
		return (len <= s.len);
		
	int min_len = (len < s.len) ? len : s.len; 
	for (int i = 0; i < min_len; i++)
	{
		if (str[i] > s.str[i])
			return false;
		if (str[i] < s.str[i])
			return true;
	}
	return (len <= s.len);
}

char String::operator[](unsigned idx)
{
	if (idx >= len)
		return '\0';

	return str[idx];
}

String String::substring(unsigned s, unsigned e) const
{
	if (s >= e || str == NULL)
		return String();
	if (e > len)
		e = len;

	char * pszTemp = new char[e-s + 1];
	strncpy(pszTemp, str + s, e-s);
	pszTemp[e-s] = '\0';
	String strTemp(pszTemp);
	delete []pszTemp;
	return strTemp;
}

unsigned String::length() const
{
	return len;
}

ostream& operator <<(ostream& os, const String & s)
{
	if (s.str != NULL)
		os << s.str;
	return os;
}

istream& operator >>(istream& is, String & s)
{
	delete []s.str;
	char szTemp[STR_INPUT_MAX];
	is.getline(szTemp, STR_INPUT_MAX);
	s.len = strlen(szTemp);
	if (s.len == 0)
		s.str = NULL;
	else
	{
		s.str = new char[s.len + 1];
		strcpy(s.str, szTemp);
	}
	return is;
}
