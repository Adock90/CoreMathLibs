#ifndef AUTOCALCMATH_FRACTION_H 
#define AUTOCALCMATH_FRACTION_H
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <pthread.h>

#include "AutoCalcMath.Type.Definer.h"

typedef struct
{
	AUTOCALCMATH_INT Fract1Num;
	AUTOCALCMATH_INT Fract1Denom;
	AUTOCALCMATH_INT Fract2Num;
	AUTOCALCMATH_INT Fract2Denom;
} TwoFractions;

typedef struct
{
        int WholeNums;
        int Numer;
        int Denom;
} MixedNumFormat;

TwoMathNums SimplifyFract(TwoMathNums UnsimFract)
{
	AUTOCALCMATH_FLOAT CheckerOne;
	AUTOCALCMATH_FLOAT CheckerTwo;

	TwoMathNums Result;

	for (int i = 0; i < UnsimFract.y; i++)
	{
		switch (i)
		{
		case 0:
			continue;
		default:
			CheckerOne = (AUTOCALCMATH_INT)UnsimFract.y % i;
			CheckerTwo = (AUTOCALCMATH_INT)UnsimFract.x % i;
			
			if (CheckerOne == 0 && CheckerTwo == 0)
			{
				Result.x = UnsimFract.x / i;
				Result.y = UnsimFract.y / i;
				break;
			}
			else
			{
				continue;
			}
		}
	}
	return Result;
}


TwoFractions EqualPropFract(TwoMathNums SmallerFract, TwoMathNums BiggerFract)
{
	AUTOCALCMATH_FLOAT x = 0;
	AUTOCALCMATH_FLOAT y = 0;

	AUTOCALCMATH_BOOLEAN Found = FALSE;
	
	TwoMathNums SimCheckerOne;
	TwoMathNums SimCheckerTwo;

	TwoFractions Result;

	if ((AUTOCALCMATH_INT)SmallerFract.y % (AUTOCALCMATH_INT)BiggerFract.y == 0 && (AUTOCALCMATH_INT)SmallerFract.x % (AUTOCALCMATH_INT)BiggerFract.y == 0)
	{
		Result.Fract1Denom = SmallerFract.y / BiggerFract.y;
		Result.Fract2Denom = BiggerFract.y;
		Result.Fract1Num = SmallerFract.x / BiggerFract.y;
		Result.Fract2Num = BiggerFract.x;
		
		SimCheckerOne.x = Result.Fract1Num;
		SimCheckerOne.y = Result.Fract1Denom;

		SimCheckerTwo.x = Result.Fract2Num;
		SimCheckerTwo.y = Result.Fract2Denom;

		TwoMathNums SimpOne;
		TwoMathNums SimpTwo;

		SimpOne	= SimplifyFract(SimCheckerOne);
		SimpTwo = SimplifyFract(SimCheckerTwo);

		Result.Fract1Denom = SimCheckerOne.y;
		Result.Fract1Num = SimCheckerOne.x;
		Result.Fract2Denom = SimCheckerTwo.y;
		Result.Fract2Num = SimCheckerTwo.x;
	}
	else
	{
		AUTOCALCMATH_INT i = 0;
		
		while (!Found)
		{
			BiggerFract.y *= i;
	
			AUTOCALCMATH_INT CheckerDenom = (AUTOCALCMATH_INT)BiggerFract.y % (AUTOCALCMATH_INT)SmallerFract.y;
			AUTOCALCMATH_INT CheckerNum = (AUTOCALCMATH_INT)BiggerFract.x % (AUTOCALCMATH_INT)SmallerFract.y;

			switch (CheckerDenom && CheckerNum)
			{
			case 0 && 0:
				Result.Fract1Denom = BiggerFract.y / SmallerFract.y;
				Result.Fract2Denom = SmallerFract.y;
				Result.Fract1Num = BiggerFract.x / SmallerFract.y;
				Result.Fract2Num = SmallerFract.x;

				Found = TRUE;

				break;		
			default:
				continue;
				break;	
			}
		}
	}
	return Result;
}


TwoMathNums AddFractions(TwoMathNums FractionOne, TwoMathNums FractionTwo)
{
	TwoFractions Normalize;

	if (FractionOne.y != FractionTwo.y)
	{
		Normalize = EqualPropFract(FractionOne, FractionTwo);
	}
	else
	{
		Normalize.Fract1Num = FractionOne.x;
		Normalize.Fract1Denom = FractionOne.y;
		Normalize.Fract2Num = FractionTwo.x;
		Normalize.Fract2Denom = FractionTwo.y;
	}

	TwoMathNums Result;
    	Result.x = Normalize.Fract1Num + Normalize.Fract2Num;

	return Result;
}
	
TwoMathNums SubFractions(TwoMathNums FractionOne, TwoMathNums FractionTwo)
{
	TwoFractions Normalize;
	if (FractionOne.y != FractionTwo.y)
	{
		Normalize = EqualPropFract(FractionOne, FractionTwo);
	}
	else
	{
		Normalize.Fract1Num = FractionOne.x;
		Normalize.Fract1Denom = FractionOne.y;
		Normalize.Fract2Num = FractionTwo.x;
		Normalize.Fract2Denom = FractionTwo.y;
	}

	TwoMathNums Result;
	Result.y = Normalize.Fract1Denom;

	if(Normalize.Fract1Num > Normalize.Fract2Num)
	{
		Result.x = Normalize.Fract1Num - Normalize.Fract2Num;
	}
	else
	{
		Result.x = Normalize.Fract2Num - Normalize.Fract1Num;
	}

	return Result;
}


TwoMathNums MultiFractions(TwoMathNums FractionOne, TwoMathNums FractionTwo)
{
	TwoFractions Normalize;
	if (FractionOne.y != FractionTwo.y)
	{
		Normalize = EqualPropFract(FractionOne, FractionTwo);
	}
	else
	{
		Normalize.Fract1Num = FractionOne.x;
		Normalize.Fract1Denom = FractionOne.y;
		Normalize.Fract2Num = FractionTwo.x;
		Normalize.Fract2Denom = FractionTwo.y;
	}

	TwoMathNums Result;
	Result.y = Normalize.Fract1Denom;

	Result.x = Normalize.Fract1Num * Normalize.Fract2Num;

	return Result;
}

TwoMathNums DivFractions(TwoMathNums FractionOne, TwoMathNums FractionTwo)
{
	TwoFractions Normalize;
	if (FractionOne.y != FractionTwo.y)
	{
		Normalize = EqualPropFract(FractionOne, FractionTwo);
	}
	else
	{
		Normalize.Fract1Num = FractionOne.x;
		Normalize.Fract1Denom = FractionOne.y;
		Normalize.Fract2Num = FractionTwo.x;
		Normalize.Fract2Denom = FractionTwo.y;
	}

	AUTOCALCMATH_FLOAT NumCache = Normalize.Fract2Num;

	Normalize.Fract2Num = Normalize.Fract2Denom;
	Normalize.Fract2Denom = NumCache;

	NumCache = 0.00;

	TwoMathNums Result;
	Result.x = Normalize.Fract1Num * Normalize.Fract2Num;
	Result.y = Normalize.Fract1Denom * Normalize.Fract2Denom;

	return Result;
}

MixedNumFormat ImpropFractToMixedNum(TwoMathNums ImpropFract)
{
	MixedNumFormat Result;
	bool DoWeNeedToCalculate;

	if (ImpropFract.x < ImpropFract.y && ImpropFract.x != 0)
	{
		
		DoWeNeedToCalculate = false;

		Result.Numer = ImpropFract.x;
		Result.Denom = ImpropFract.y;
		Result.WholeNums = 0;

		return Result;
	}
	else if (ImpropFract.x == ImpropFract.y)
	{
		DoWeNeedToCalculate = false;

		Result.Numer = 0;
		Result.Denom = 0;
		Result.WholeNums = 1;
	}
	else if (ImpropFract.x == 0)
	{
		DoWeNeedToCalculate = false;

		Result.Numer = 0;
		Result.Denom = 0;
		Result.WholeNums = 0;

		return Result;
	}
	else
	{
		DoWeNeedToCalculate = true;
	}

	switch (DoWeNeedToCalculate)
	{
	case false:
		printf("Failed at:%d\n", AUTOCALCMATHS_ERROR);
		return Result;
		break;
	default:
		for (int i = 0; i < ImpropFract.x; i++)
		{
			AUTOCALCMATH_FLOAT TimeTableFractDenom = ImpropFract.y * i;
			if (TimeTableFractDenom == ImpropFract.x)
			{
				Result.Numer = 0;
				Result.Denom = 0;
				Result.WholeNums = i;
				break;
			}
			else if (TimeTableFractDenom > ImpropFract.x)
			{
				Result.Numer = TimeTableFractDenom - ImpropFract.x;
				Result.Denom = ImpropFract.y;
				Result.WholeNums = i - 1;
				break;
			}
			else
			{
				continue;
			}
		}
		break;
	}
	return Result;
}

TwoMathNums MixedNumToImpropFract(MixedNumFormat MixedNum)
{
	TwoMathNums Reuslt;

	if (MixedNum.WholeNums == NULL || MixedNum.Denom == NULL || MixedNum.Numer == NULL)
	{
		printf("Failed At:", AUTOCALCMATHS_INVALID);
		return Reuslt;
	}
	else
	{
		Reuslt.x = (MixedNum.WholeNums * MixedNum.Denom) + MixedNum.Numer;
		Reuslt.y = MixedNum.Denom;
		
		return Reuslt;
	}
}


AUTOCALCMATH_FLOAT ForceCheckCommon(AUTOCALCMATH_FLOAT ChangeNum, AUTOCALCMATH_FLOAT CompareNum, AUTOCALCMATH_BOOLEAN ContinueAtAllCosts)
{
	AUTOCALCMATH_FLOAT EvalutatedValue;

	AUTOCALCMATH_INT LogI;

	for (int i = 0; i < CompareNum; i++)
	{
		EvalutatedValue = i * ChangeNum;

		LogI = i;

		if (EvalutatedValue == CompareNum)
		{
			break;
		}
		else
		{
			continue;
		}
	}
	
	if (EvalutatedValue == CompareNum)
	{
		return EvalutatedValue;
	}
	else
	{
		while(true)
		{
			if (LogI > (CompareNum*100000) && !ContinueAtAllCosts)
			{
				printf("Failed\n");
				return AUTOCALCMATHS_FAILED;
			}
			else if (LogI > (CompareNum*100000) && ContinueAtAllCosts)
			{
				printf("Passing Safe Point\n");
				EvalutatedValue *= LogI;
			}
			else
			{
				EvalutatedValue *= LogI;
			}

			

		}
	}
}

