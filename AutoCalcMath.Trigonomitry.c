#ifndef AUTOCALCMATH_TRIGONOMITRY_H
#define AUTOCALCMATH_TRIGONOMITRY_H 
#endif

#include "AutoCalcMath.Type.Definer.h"
#include <math.h>

AUTOCALCMATH_FLOAT AutoCalcMath_Sin(AUTOCALCMATH_FLOAT x)
{
	AUTOCALCMATH_FLOAT RetSinVal;

	asm(
			"fsin"
			:
			"=t"
			(RetSinVal)
			:
			"0"
			(x));
	return RetSinVal;
}

AUTOCALCMATH_FLOAT AutoCalcMath_Cos(AUTOCALCMATH_FLOAT x)
{
	AUTOCALCMATH_FLOAT RetCosVal;

	asm(
			"fcos"
			:
			"=t"
			(RetCosVal)
			:
			"0"
			(x));
	return RetCosVal;
}

AUTOCALCMATH_FLOAT AutoCalcMath_Tan(AUTOCALCMATH_FLOAT x)
{
	AUTOCALCMATH_FLOAT RetTanVal;
	RetTanVal = tan(x);
	return RetTanVal;
}
