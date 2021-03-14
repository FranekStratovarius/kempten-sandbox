DATA
CODE
start:
mov cx, 200
mov dx, 32000

mov ax, 0b11100000	;rot
mov bx, 32000
mov *bx, ax	;links oben

mov ax, 0b00011100	;grün
mov bx, 32199
mov *bx, ax	;rechts oben

mov ax, 0b00000011	;blau
mov bx, 159
mul bx, cx	;zeilen verschieben
add bx, dx	;im speicher verschieben
mov *bx, ax	;links unten

mov ax, 0b11111100	;gelb
mov bx, 159
mul bx, cx
mov cx, 199
add bx, cx
mov cx, 200	;reset cx
add bx, dx
mov *bx, ax	;rechts unten

mov ax, 0b11111111	;weiß
mov bx, 79
mul bx, cx
mov cx, 99
add bx, cx
add bx, dx
mov *bx, ax	;mitte oben

ende:
jmp ende

