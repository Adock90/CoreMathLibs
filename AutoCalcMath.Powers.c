#ifndef AUTOCALCMATH_POWERS_H
#define AUTOCALCMATH_POWERS_H
#endif

#include "AutoCalcMath.Type.Definer.h"

AUTOCALCMATH_FLOAT Square(AUTOCALCMATH_FLOAT Subject)
{
        Subject *= Subject;
        return Subject;
}


AUTOCALCMATH_FLOAT SquareRoot(AUTOCALCMATH_FLOAT Subject)
{
	AUTOCALCMATH_FLOAT x, y = 0;
	
	while(Subject >= y)
	{
		x++;
		y = Square(x);
	}

	for(int i = 0; i < 10; i++)
	{
		x = (Subject/x + x)/2;
		if(Square(x) == Subject)
		{
			return x;
		}
		else
		{
			continue;
		}
	}
}


AUTOCALCMATH_FLOAT CubeRoot(AUTOCALCMATH_FLOAT Subject)
{
	AUTOCALCMATH_FLOAT StartingPoint = 0, EndingPoint = Subject, Percision = 0.0000001;
	
	AUTOCALCMATH_FLOAT Result, middle, err;

	while(TRUE)
	{
		middle = (StartingPoint + EndingPoint)/2;
		if (Subject > (middle*middle*middle))
		{
			err = (Subject - (middle*middle*middle));
		}
		else
		{
			err = ((middle*middle*middle) - Subject);
		}

		if (err <= Percision)
		{
			Result = middle;
		}
		if ((middle*middle*middle) > Subject)
		{
			EndingPoint = middle;
		}
		else
		{
			StartingPoint = middle;
		}
	}
	
	return Result;
}


AUTOCALCMATH_FLOAT Cube(AUTOCALCMATH_FLOAT Subject)
{
	AUTOCALCMATH_FLOAT Result = (Subject * Subject * Subject);
	return Result;
}

AUTOCALCMATH_FLOAT ToPowerOff(AUTOCALCMATH_FLOAT Subject, AUTOCALCMATH_FLOAT PowerOf)
{

	for (int i = 1; i <= PowerOf; i++)
	{
		Subject *= Subject;
	}

	return Subject;
}

