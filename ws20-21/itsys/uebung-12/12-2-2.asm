DATA
CODE
start:
mov ax, 0b11111111	;weiß
mov bx, 100	;x
mov cx, 100	;y
call draw
mov bx, 101
mov cx, 100
call draw
mov bx, 102
mov cx, 100
call draw
mov bx, 100
mov cx, 101
call draw
mov bx, 101
mov cx, 101
call draw
mov bx, 102
mov cx, 101
call draw
mov bx, 100
mov cx, 102
call draw
mov bx, 101
mov cx, 102
call draw
mov bx, 102
mov cx, 102
call draw

end:
jmp end
draw:
mov dx, 200	;zeilenmult
mul bx, dx
add bx, cx	;x koordinate addieren
mov dx, 32000	;ram offset addieren
add bx, dx
mov *bx, ax	;pixel schreiben
ret
