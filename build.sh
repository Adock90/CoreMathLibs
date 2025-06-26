#!/bin/bash


$(gcc -shared -o ../libs/AutoCalcMath.Fraction.so -fPIC AutoCalcMath.Fraction.c)
$(gcc -shared -o ../libs/AutoCalcMath.Ratio.so -fPIC AutoCalcMath.Ratio.c)
$(gcc -shared -o ../libs/AutoCalcMath.Simple.so -fPIC AutoCalcMath.Simple.c) 
$(gcc -shared -o ../libs/AutoCalcMath.Trigonomitry.so -fPIC AutoCalcMath.Trigonomitry.c)

