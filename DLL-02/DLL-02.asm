; DLL-02.asm

.code

_DllMainCRTStartup proc h:QWORD, r:DWORD, u:QWORD
	mov rax, 1
	ret
_DllMainCRTStartup endp

multip proc
	mov rax,11223344h
	;mov rax,1
	ret
multip endp


end
