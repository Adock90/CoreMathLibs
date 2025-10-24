#!/bin/bash

OperatingSystem=$1
NASMFormat=""

if [ "$OperatingSystem" == "linux" ];
then
	NASMFormat="-felf64"
elif [ "$OperatingSystem" == "windows" ];
then
	echo "[AutoCalcMathBuildScript] Windows is not compatible with .so format. But don't worry, Windows is supported. Use build.bat or build.ps1"
	exit
elif [ "$OperatingSystem" == "macos" ] || [ "$OperatingSystem" == "darwin" ];
then
	NASMFormat="-fmacho32"
elif [ "$OperatingSystem" == "--BypassOSChecks" ];
then
	echo "[AutoCalcMathBuildScript] Bypassing OS Checks. May not be compatible. Please Supply a NASM Flag. default is '-felf64'"
	read input
	if [ -z $input ]
	then
		echo "[AutoCalcMathBuildScript] Okay Contiuing"
		NASMFormat="-felf64"
	else
		echo "[AutoCalcMathBuildScript] Assinging input"
		NASMFormat=$input
	fi
else
	echo "[AutoCalcMathBuildScript] No Args submitted"
	echo "[AutoCalcMathBuildScript] Auto-Detecting OS"

	OperatingSystem=$(uname)
	
	if [ "$OperatingSystem" == "Linux" ];
	then
		echo "[AutoCalcMathBuildScript] Detected Linux"
		NASMFormat="-felf64"
	elif [ "$OperatingSystem" == "FreeBSD" ];
	then
		echo "[AutoCalcMathBuildScript] Detected FreeBSD"
		NASMFormat="-felf64"
	elif [ "$OperatingSystem" == "Darwin" ];
	then
		echo "[AutoCalcMathBuildScript] Detected MacOS"
		NASMFormat="-fmacho32"
	elif [ "$OperatingSystem" == "win32" ] || [ "$OperatingSystem" == "msys" ] || [ "$OperatingSystem" == "cgywin" ];
	then
		echo "[AutoCalcMathBuildScript] Detected Windows"
		echo "[AutoCalcMathBuildScript] Windows is not compatible with .so format. But don't worry, Windows is supported. Use build.bat or build.ps1"
        	exit
	else
		echo "[AutoCalcMathBuildScript] We cannot contiue as your OS is unknown. If your OS is compatible with .so files you can run the script again with the 'linux' flag or '--BypassOSChecks'"
		exit
	fi
fi

echo "[AutoCalcMathBuildScript] Building sources"

echo "[AutoCalcMathBuildScript] Running: gcc -shared -o ../libs/AutoCalcMath.Fraction.so -fPIC AutoCalcMath.Fraction.c"
$(gcc -shared -o ../libs/AutoCalcMath.Fraction.so -fPIC AutoCalcMath.Fraction.c)
echo "[AutoCalcMathBuildScript] Running: gcc -shared -o ../libs/AutoCalcMath.Ratio.so -fPIC AutoCalcMath.Ratio.c"
$(gcc -shared -o ../libs/AutoCalcMath.Ratio.so -fPIC AutoCalcMath.Ratio.c)
echo "[AutoCalcMathBuildScript] Running: gcc -shared -o ../libs/AutoCalcMath.Simple.so -fPIC AutoCalcMath.Simple.c"
$(gcc -shared -o ../libs/AutoCalcMath.Simple.so -fPIC AutoCalcMath.Simple.c)
echo "[AutoCalcMathBuildScript] Running: gcc -shared -o ../libs/AutoCalcMath.TrigonomitryARM.so -fPIC AutoCalcMath.Trigonomitry.c"
$(gcc -shared -o ../libs/AutoCalcMath.TrigonomitryARM.so -fPIC AutoCalcMath.Trigonomitry.c)
echo "[AutoCalcMathBuildScript] Running: nasm -DPIC $NASMFormat -o ../libs/AutoCalcMath.TrigonomitryX86.o AutoCalcMath.Trigonomitry.asm"
$(nasm -DPIC $NASMFormat -o ../libs/AutoCalcMath.TrigonomitryX86.o AutoCalcMath.Trigonomitry.asm)
echo "[AutoCalcMathBuildScript] Running: gcc -shared -o ../libs/AutoCalcMath.TrigonomitryX86.so ../libs/AutoCalcMath.TrigonomitryX86.o"
$(gcc -shared -o ../libs/AutoCalcMath.TrigonomitryX86.so ../libs/AutoCalcMath.TrigonomitryX86.o)
echo "[AutoCalcMathBuildScript] Running: gcc -shared -o ../libs/AutoCalcMath.Percentage.so -fPIC AutoCalcMath.Percentage.c"
$(gcc -shared -o ../libs/AutoCalcMath.Percentage.so -fPIC AutoCalcMath.Percentage.c)
echo "[AutoCalcMathBuildScript] Running: gcc -shared -o ../libs/AutoCalcMath.Powers.so -fPIC AutoCalcMath.Powers.c"
$(gcc -shared -o ../libs/AutoCalcMath.Powers.so -fPIC AutoCalcMath.Powers.c)

echo "[AutoCalcMathBuildScript] Done Compiling"
echo "[AutoCalcMathBuildScript] Removing leftovers"

$(rm "../libs/AutoCalcMath.TrigonomitryX86.o")

exit
