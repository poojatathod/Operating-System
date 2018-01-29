bits 16




main: 
    cli
    mov ax,0x7c0 	
    mov ds,ax 		
    mov es,ax
    mov ss,ax
    sti

  
    mov si,name       
    call print         
    call newline
 
 
    mov si,rollno       
    call print 
 
    jmp $		
 
print:
    
  next:
     lodsb           	
     or al,al           
     jz return		
     mov ah,0x0E        
     int 0x10           
     jmp next       

  return:
     ret                

newline:
     mov ah,0x0E  	
     mov al,0x0D        
     int 0x10           
     mov al,0x0A        
     int 0x10           
     ret



	
name db 'Pooja Tathod', 0x0     
rollno db 'Rollno - 16157  ', 0x0
times 510 - ($-$$) db 0                           
dw 0xAA55                                         
