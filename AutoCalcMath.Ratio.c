#ifndef AUTOCALCMATH_RATIO_H
#define AUTOCALCMATH_RATIO_H
#endif

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "AutoCalcMath.Type.Definer.h"


TwoMathNums CommonRatio(AUTOCALCMATH_FLOAT RatOne, AUTOCALCMATH_FLOAT RatTwo, AUTOCALCMATH_BOOLEAN BypassIntegerInteg)
{
	TwoMathNums Result;

	AUTOCALCMATH_BOOLEAN RatOneBigger;
	AUTOCALCMATH_BOOLEAN RatTwoBigger;

	if (RatOne > RatTwo)
	{
		RatOneBigger = TRUE;
		RatTwoBigger = FALSE;
	}
	else if (RatTwo > RatOne)
	{
		RatOneBigger = FALSE;
		RatTwoBigger = TRUE;
	}
	else
	{
		RatOneBigger = FALSE;
		RatTwoBigger = FALSE;
	}

	if (RatOneBigger && !RatTwoBigger)
	{
		if ((AUTOCALCMATH_INT)RatOne % (AUTOCALCMATH_INT)RatTwo)
		{
			Result.x = RatOne / RatTwo;
			Result.y = RatTwo;
		}
		else
		{
			if (BypassIntegerInteg)
			{
				printf("Bypassing Integer Enforcement\n");
				Result.x = RatOne;
				Result.y = RatOne / RatTwo;
			}
			else
			{
				printf("ERROR: %d\n", AUTOCALCMATHS_ERROR);
				Result.x = RatOne;
				Result.y = RatTwo;
			}
		}
	}
	else if (!RatOneBigger && RatTwoBigger)
	{
		if ((AUTOCALCMATH_INT)RatTwo % (AUTOCALCMATH_INT)RatOne)
		{
			Result.x = RatOne;
			Result.y = RatTwo / RatOne;
		}
		else
		{
			if (BypassIntegerInteg)
			{
				printf("Bypassing Integer Enforcement\n");
				Result.x = RatTwo / RatOne;
				Result.y = RatTwo;
			}
			else
			{
				printf("ERROR: %d\n", AUTOCALCMATHS_ERROR);
				Result.x = RatOne;
				Result.y = RatTwo;
			}
		}
	}
	else
	{
		Result.x = RatOne;
		Result.y = RatTwo;
	}

	return Result;
}


TwoMathNums FindTot(AUTOCALCMATH_FLOAT NumOne, AUTOCALCMATH_FLOAT NumTwo, AUTOCALCMATH_FLOAT TotalVal)
{
	TwoMathNums Result;

	AUTOCALCMATH_FLOAT Diver = NumOne + NumTwo;

	Result.x = (NumOne/Diver) * TotalVal;
	Result.y = (NumTwo/Diver) * TotalVal;

	return Result;
}

TwoMathNums MultipleRat(AUTOCALCMATH_FLOAT NumOne, AUTOCALCMATH_FLOAT NumTwo, AUTOCALCMATH_FLOAT BorderTarget)
{
	TwoMathNums Result;

	if (BorderTarget == 0)
	{
		printf("Cannot When do i Stop");
		printf(" %d\n", AUTOCALCMATHS_INVALID);
	}

	for (int i = 0; i <= BorderTarget; i++)
	{
		Result.x = NumOne * i;
		Result.y = NumTwo * i;
	}

	return Result;

}

