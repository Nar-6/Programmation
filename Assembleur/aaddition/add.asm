global _main
    extern _printf
    section .text
_main :
    MOV eax,2
    MOV ecx,5
    ADD eax,ecx
    push eax
    push message
    call _printf
    ADD esp,8
    ret

    section .data
message :
    db 'CA FAIT %d',10,0    