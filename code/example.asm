data segment
score dw 85,68,98,78,85
      dw 89,85,75,25,14
;fjdk
data ends
code segment
assume cs:code,ds:data
start:
    mov ax,data
    mov ds,ax
    mov ax,ds:[14]

    mov si,14
    mov ax,[si]

    mov bp,14
    mov ax,ds:[bp]

    mov bx,14
    mov ax,score[bx]

    mov bx,offset score
    mod di,14
    mov ax,[bx][di]

    ;2,3 al 
    mov ah,1 
    int 21h 
    sub al,30h 
    dec al
    mov cl,10 
    mul cl
    mov bx,ax
    
    mov ah,1
    int 21h 
    sub al, 30h 
    dec al
    mov cl,2 
    mul cl 
    mov si,ax

    mov ax,score[bx][si]
    mov ah,4ch
    int 21h
code ends 
end start