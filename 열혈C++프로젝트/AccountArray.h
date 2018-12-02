// AccountArray class
// ver 1.0
// Last Update 2018.12.2


#ifndef ACCOUNT_ARRAY_H
#define ACCOUNT_ARRAY_H

#include "pch.h"
#include "Account.h"

typedef Account* ACC_PTR;

class BoundCheckAccountPtrArray
{
public:
	BoundCheckAccountPtrArray(int len);
	~BoundCheckAccountPtrArray();
	ACC_PTR& operator [] (int idx);
	ACC_PTR operator [] (int idx) const;
	int GetArrLen() const;

private:
	ACC_PTR * accPtrArr;
	int arrLen;
};

#endif // ACCOUNT_ARRAY_H