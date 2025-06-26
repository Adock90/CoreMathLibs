;This is abandoned for now

section .text
	global AutoCalcMath_Sin
	global AutoCalcMath_Cos
	global AutoCalcMath_Tan

section .data
	th_div dd 3h
	fi_div dd 5h
	se_div dd 7h
	ni_div dd 9h
	ele_div dd 11h
	thr_div dd 13h	
	fith_div dd 15h
	seventin_div dd 17h
	
section .bss
	sinbuf resb 32

AutoCalcMath_Sin:
	push eax

	mov eax, sinbuf

	mov ebx, th_div
	mov eax, eax
	
	mul ebx
	mul ebx
	mul ebx
	
	div ebx
	
	sub [sinbuf], eax

	mov eax, sinbuf

	mov ebx, fi_div
	mov eax, eax
	
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	
	div ebx
	
	add [sinbuf], eax
	
	mov eax, sinbuf	

	mov ebx, se_div
	mov eax, eax
	
	mul ebx
	mul ebx	
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx

	div ebx
	
	sub [sinbuf], eax

	mov eax, sinbuf
	
	mov ebx, ni_div
	mov eax, eax
	
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx

	div ebx

	add [sinbuf], eax
	
	mov eax, sinbuf

	mov ebx, ele_div
	mov eax, eax
	
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	
	div ebx
	
	sub [sinbuf], eax
	
	mov eax, sinbuf

	mov ebx, thr_div
	mov eax, eax
	
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	
	div ebx
	
	add [sinbuf], eax
	
	mov eax, sinbuf

	mov ebx, fith_div
	mov eax, eax
	
	mul ebx
        mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	
	div ebx

	sub [sinbuf], eax

	mov eax, sinbuf
	
	mov ebx, seventin_div
	mov eax, eax
	
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	mul ebx
	
	div ebx

	ret
