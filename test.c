#include "AutoCalcMath.Simple.h"
#include "AutoCalcMath.Fraction.h"
#include "AutoCalcMath.Trigonomatry.h"

#include <stdio.h>
#include <unistd.h>

int main(void)
{
	TwoMathNums MyNums = {78.5,32};

	AUTOCALCMATH_FLOAT Output = AddNums(MyNums);
	AUTOCALCMATH_FLOAT TwoOutput = SubNums(MyNums);
	AUTOCALCMATH_FLOAT ThreeOutput = MultiNums(MyNums);
	AUTOCALCMATH_FLOAT FourOutput = DivNums(MyNums);
	printf("%f\n", FourOutput);
	printf("%f\n", ThreeOutput);
	printf("%f\n", TwoOutput);
	printf("%f\n", Output);
	
	TwoMathNums FractProp = {11323, 11};

	MixedNumFormat CheckConvert = ImpropFractToMixedNum(FractProp);

	printf("%d\n%d\n%d\n", CheckConvert.WholeNums, CheckConvert.Numer, CheckConvert.Denom);

	AUTOCALCMATH_FLOAT

	return 0;
}
