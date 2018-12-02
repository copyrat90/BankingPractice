// AccountArray class Implementation
// ver 1.0
// Last Update 2018.12.2


#include "pch.h"
#include "AccountArray.h"


BoundCheckAccountPtrArray::BoundCheckAccountPtrArray(int len)
	:arrLen(len)
{
	accPtrArr = new ACC_PTR[arrLen];
}


BoundCheckAccountPtrArray::~BoundCheckAccountPtrArray()
{
	delete[]accPtrArr;
}


ACC_PTR& BoundCheckAccountPtrArray::operator [] (int idx)
{
	if (idx < 0 || idx >= arrLen)
	{
		std::cout << "Exception : Array index out of bound" << std::endl;
		exit(1);
	}

	return accPtrArr[idx];
}


ACC_PTR BoundCheckAccountPtrArray::operator [] (int idx) const
{
	if (idx < 0 || idx >= arrLen)
	{
		std::cout << "Exception : Array index out of bound" << std::endl;
		exit(1);
	}

	return accPtrArr[idx];
}


int BoundCheckAccountPtrArray::GetArrLen() const
{
	return arrLen;
}