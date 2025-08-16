section .data
	global Sin
	global Cos
	global Tan

Sin:
	fld qword [esp+4]
	fsin
	ret

Cos:
	fld qword [esp+4]
	fcos
	ret

Tan:
	fld qword [esp+4]
	fsin
	fld qword [esp+4]
	fcos
	fdiv st1, st0
	ret
