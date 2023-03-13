	THUMB
	AREA	DATA, ALIGN=4 
				
	AREA	|.text|, CODE, READONLY, ALIGN=2
	EXPORT  main
		   
main
	MOV R0, #30
	MOV R1, #0
	MOV R2, #1
	MOV R6, #1
	

loop	
	
	ADD R6, R2, #0 
	ADD R2, R1, R2
	ADD R1, R6, #0
	SUB R0, R0, #1
	CMP R0, #0 
	BLE exit
	B loop
exit
endless B endless
	ALIGN	  
	END
