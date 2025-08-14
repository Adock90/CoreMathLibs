#ifndef AUTOCALCMATH_PERCENTAGE_H
#define AUTOCALCMATH_PERCENTAGE_H
#endif

#include "AutoCalcMath.Type.Definer.h"

AUTOCALCMATH_FLOAT FindPercentage(AUTOCALCMATH_FLOAT Subject, AUTOCALCMATH_FLOAT NumOf)
{
	AUTOCALCMATH_FLOAT Result;

	AUTOCALCMATH_FLOAT Dec = Subject / NumOf;

	Result = Dec * 100;

	return Result;
}

AUTOCALCMATH_FLOAT AddPercentage(AUTOCALCMATH_FLOAT BaseNum, AUTOCALCMATH_FLOAT Percentage)
{
	AUTOCALCMATH_FLOAT Result;

	AUTOCALCMATH_FLOAT FindPercentDec = Percentage / 100;

	Result = BaseNum / FindPercentDec;

	return Result;
}

AUTOCALCMATH_FLOAT SubPercentage(AUTOCALCMATH_FLOAT BaseNum, AUTOCALCMATH_FLOAT Percentage)
{
        AUTOCALCMATH_FLOAT Result;

        AUTOCALCMATH_FLOAT FindPercentDec = Percentage / 100;

        Result = BaseNum * FindPercentDec;

        return Result;
}


AUTOCALCMATH_FLOAT MultiPercentage(AUTOCALCMATH_FLOAT BaseNum, AUTOCALCMATH_FLOAT Percentage)
{
        AUTOCALCMATH_FLOAT Result;

	AUTOCALCMATH_FLOAT FindDigi = BaseNum * Percentage;

        Result = BaseNum * FindDigi;

        return Result;
}


AUTOCALCMATH_FLOAT DivPercentage(AUTOCALCMATH_FLOAT BaseNum, AUTOCALCMATH_FLOAT Percentage)
{
        AUTOCALCMATH_FLOAT Result;

        AUTOCALCMATH_FLOAT FindDigi = BaseNum * Percentage;

        Result = BaseNum / FindDigi;

        return Result;
}

