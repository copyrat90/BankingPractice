#ifndef __STRING_H__
#define __STRING_H__

#include <iostream>
using namespace std;

#define STR_INPUT_MAX 100


class String
{
public:
	String();
	String(const char *);
	String(const String &);
	~String();
	
	String& operator =(const String &);
	String& operator +=(const String &);
	String operator +(const String &) const;
	
	bool operator ==(const String &) const;
	bool operator >(const String &) const;
	bool operator <(const String &) const;
	bool operator >=(const String &) const;
	bool operator <=(const String &) const;
	
	char operator[](unsigned idx);
	String substring(unsigned s, unsigned e) const;
	unsigned length() const;
	
	friend ostream& operator <<(ostream&, const String &);
	friend istream& operator >>(istream&, String &);
	
private:
	char * str;
	unsigned len;
};

ostream& operator <<(ostream&, const String &);
istream& operator >>(istream&, String &);



#endif
