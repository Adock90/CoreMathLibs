#ifndef AUTOCALCMATH_SIMPLE_H
#define AUTOCALCMATH_SIMPLE_H
#endif

#include <stdlib.h>
#include <math.h>
#include <ctype.h>

enum RETURN_ID
{
        AUTOCALCMATHS_VALID = 1,
        AUTOCALCMATHS_SUCCESS = 0,
        AUTOCALCMATHS_FAILED = -1,
        AUTOCALCMATHS_INVALID = -2,
        AUTOCALCMATHS_ERROR = -3,
        AUTOCALCMATHS_KILLED = -4
}; 

typedef int AUTOCALCMATH_INT;
typedef float AUTOCALCMATH_FLOAT;

typedef struct AUTOCALCMATH_FLOAT
{       
        AUTOCALCMATH_FLOAT x;
        AUTOCALCMATH_FLOAT y;
} TwoMathNums;

AUTOCALCMATH_FLOAT AddNums(TwoMathNums Nums)
{
	AUTOCALCMATH_FLOAT FirstNum = Nums.x;
	AUTOCALCMATH_FLOAT SecNum = Nums.y;

	AUTOCALCMATH_FLOAT Result = FirstNum + SecNum;
	if(isdigit(Result))
	{
		AUTOCALCMATH_INT ReturnRes = (AUTOCALCMATH_INT)Result;
		return ReturnRes;
	}
	else if (!isdigit(Result))
	{
		AUTOCALCMATH_FLOAT ReturnRes = Result;
		return ReturnRes;
	}
	else
	{
		return AUTOCALCMATHS_ERROR;
	}
}

AUTOCALCMATH_FLOAT SubNums(TwoMathNums Nums)
{
        AUTOCALCMATH_FLOAT FirstNum = Nums.x;
        AUTOCALCMATH_FLOAT SecNum = Nums.y;

        AUTOCALCMATH_FLOAT Result = FirstNum - SecNum;
        if(isdigit(Result))
        {
                AUTOCALCMATH_INT ReturnRes = (AUTOCALCMATH_INT)Result;
                return ReturnRes;
        }
        else if (!isdigit(Result))
        {
                AUTOCALCMATH_FLOAT ReturnRes = Result;
                return ReturnRes;
        }
        else
        {
                return AUTOCALCMATHS_ERROR;
        }
}


AUTOCALCMATH_FLOAT MultiNums(TwoMathNums Nums)
{
	AUTOCALCMATH_FLOAT FirstNum = Nums.x;
	AUTOCALCMATH_FLOAT SecNum = Nums.y;

	AUTOCALCMATH_FLOAT Result = FirstNum * SecNum;

	if(isdigit(Result))
	{
		AUTOCALCMATH_INT ReturnRes = (AUTOCALCMATH_INT)Result;
		return ReturnRes;
	}
	else if (!isdigit(Result))
	{
		AUTOCALCMATH_FLOAT ReturnRes = Result;
		return ReturnRes;
	}
	else
	{
		return AUTOCALCMATHS_ERROR;
	}
}

AUTOCALCMATH_FLOAT DivNums(TwoMathNums Nums)
{
	AUTOCALCMATH_FLOAT FirstNum = Nums.x;
	AUTOCALCMATH_FLOAT SecNum = Nums.y;

	AUTOCALCMATH_FLOAT Result = FirstNum / SecNum;

	if(isdigit(Result))
	{
		AUTOCALCMATH_INT ReturnRes = (AUTOCALCMATH_INT)Result;
		return ReturnRes;
	}
	else if (!isdigit(Result))
	{
		AUTOCALCMATH_FLOAT ReturnRes = Result;
		return ReturnRes;
	}
	else
	{
		return AUTOCALCMATHS_ERROR;
	}
}

