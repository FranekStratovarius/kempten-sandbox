DATA
CODE
start:
mov ax, 30
mov bx, 50
mov cx, 100
mov dx, 0b11100011

;backup machen
mov *0x3e8, ax
mov *0x3ea, bx
mov *0x3ec, cx
mov *0x3ee, dx

mov ax, *0x3ec	;länge
loop:
je end

mov bx, *0x3ea	;höhe
mov cx, 200
mul bx, cx	;höhe stimmt

mov cx, *0x3e8	;breite
add bx, cx	;breite an anfang
mov cx, 32000
add bx, cx
mov cx, *0x3ec	;länge laden
add bx, cx	;offset addieren
sub bx, ax	;breite stimmt

mov cx, *0x3ee	;farbe
mov *bx, cx

dec ax
jmp loop
end:
jmp end
