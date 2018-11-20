#ifndef __STRING_H__
#define __STRING_H__


#include <iostream>
using namespace std;


class String
{
public:
	String();
	String(const char *);
	String(const String &);
	~String();
	
	String& operator =(const String &);
	String operator +(const String &) const;
	bool operator ==(const String &) const;
	
	int length() const;
	char& operator[](int idx);
	
	friend ostream& operator <<(ostream&, const String &);
	
private:
	char * str;
	int len;
};

ostream& operator <<(ostream&, const String &);
istream& operator >>(istream&, const String &);



#endif
