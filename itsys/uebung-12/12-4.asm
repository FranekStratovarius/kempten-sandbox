DATA
CODE
start:
mov ax, 0b11100011
mov bx, 32000
mov *100, ax
mov *101, ax
mov ax, *100
loop:
mov *bx,ax
inc bx
inc bx
mov cx, 63999
cmp bx,cx
je end
jmp loop

end:
jmp end
