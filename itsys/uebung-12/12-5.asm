DATA
CODE
start:
mov cx, 64000

green:
mov bx, 32000
loopgreen:
mov ax, 0b00011100000011100
cmp bx,cx
je black
mov *bx,ax
inc bx
inc bx
jmp loopgreen

black:
mov bx, 32000
loopblack:
mov ax, 0b00000000000000000
cmp bx,cx
je magenta
mov *bx,ax
inc bx
inc bx
jmp loopblack

magenta:
mov bx, 32000
loopmagenta:
mov ax, 0b1110001111100011
cmp bx,cx
je green
mov *bx,ax
inc bx
inc bx
jmp loopmagenta
