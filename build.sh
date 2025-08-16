#!/bin/bash

OperatingSystem=$1
NASMFormat=""

if [ $OperatingSystem == "linux" ];
then
	NASMFormat="-felf64"
elif [ $OperatingSystem == "windows" ];
then
	echo "Windows is not compatible with .so format"
	exit
else
	NASMFormat="-fmacho32"
fi

$(gcc -shared -o ../libs/AutoCalcMath.Fraction.so -fPIC AutoCalcMath.Fraction.c)
$(gcc -shared -o ../libs/AutoCalcMath.Ratio.so -fPIC AutoCalcMath.Ratio.c)
$(gcc -shared -o ../libs/AutoCalcMath.Simple.so -fPIC AutoCalcMath.Simple.c) 
$(gcc -shared -o ../libs/AutoCalcMath.TrigonomitryARM.so -fPIC AutoCalcMath.Trigonomitry.c)
$(nasm -DPIC $NASMFormat -o ../libs/AutoCalcMath.TrigonomitryX86.o AutoCalcMath.Trigonomitry.asm)
$(gcc -shared -o ../libs/AutoCalcMath.TrigonomitryX86.so ../libs/AutoCalcMath.TrigonomitryX86.o)
$(gcc -shared -o ../libs/AutoCalcMath.TrigonomitryX86.so -fPIC AutoCalcM
$(gcc -shared -o ../libs/AutoCalcMath.Percentage.so -fPIC AutoCalcMath.Percentage.c)
$(gcc -shared -o ../libs/AutoCalcMath.Powers.so -fPIC AutoCalcMath.Powers.c)

