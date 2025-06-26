#ifndef AUTOCALCMATH_FRACTION_H
#define AUTOCALCMATH_FRACTION_H
#endif

#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#include "AutoCalcMath.Simple.h"

typedef struct
{
	int Fract1Num;
	int Fract1Denom;
	int Fract2Num;
	int Fract2Denom;
} TwoFractions;

typedef struct
{
	int WholeNums;
	int Numer;
	int Denom;
} MixedNumFormat;

TwoMathNums AddFractions(TwoMathNums FractionOne, TwoMathNums FractionTwo);

TwoMathNums SubFractions(TwoMathNums FractionOne, TwoMathNums FractionTwo);

TwoMathNums MultiFractions(TwoMathNums FractionOne, TwoMathNums FractionTwo);

TwoMathNums DivFractions(TwoMathNums FractionOne, TwoMathNums FractionTwo);

MixedNumFormat ImpropFractToMixedNum(TwoMathNums ImpropFract);

TwoMathNums MixedNumToImpropFract(MixedNumFormat MixedNum);

TwoMathNums SimplifyFract(TwoMathNums UnsimFract);

TwoFractions EqualPropFract(TwoMathNums SmallerFract, TwoMathNums BiggerFract);
