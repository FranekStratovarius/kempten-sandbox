DATA
CODE

start:
mov cx, 200
mov dx, 32000

mov ax, 0b11111111	;weiß
mov bx, 100
mul bx, cx
mov cx, 100
add bx, cx
mov cx, 200	;reset cx
add bx, dx
mov *bx, ax	;mitte oben

mov bx, 101
mul bx, cx
mov cx, 100
add bx, cx
mov cx, 200	;reset cx
add bx, dx
mov *bx, ax	;mitte oben

mov bx, 102
mul bx, cx
mov cx, 100
add bx, cx
mov cx, 200	;reset cx
add bx, dx
mov *bx, ax	;mitte oben

mov bx, 100
mul bx, cx
mov cx, 101
add bx, cx
mov cx, 200	;reset cx
add bx, dx
mov *bx, ax	;mitte oben

mov bx, 101
mul bx, cx
mov cx, 101
add bx, cx
mov cx, 200	;reset cx
add bx, dx
mov *bx, ax	;mitte oben

mov bx, 102
mul bx, cx
mov cx, 101
add bx, cx
mov cx, 200	;reset cx
add bx, dx
mov *bx, ax	;mitte oben

mov bx, 100
mul bx, cx
mov cx, 102
add bx, cx
mov cx, 200	;reset cx
add bx, dx
mov *bx, ax	;mitte oben

mov bx, 101
mul bx, cx
mov cx, 102
add bx, cx
mov cx, 200	;reset cx
add bx, dx
mov *bx, ax	;mitte oben

mov bx, 102
mul bx, cx
mov cx, 102
add bx, cx
mov cx, 200	;reset cx
add bx, dx
mov *bx, ax	;mitte oben

end:
jmp end
