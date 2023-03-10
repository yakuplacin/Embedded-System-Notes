	THUMB
	AREA	DATA, ALIGN=4 
				
	AREA	|.text|, CODE, READONLY, ALIGN=2
	EXPORT  main
		   
main	MOV R0, #1	
		MOV R1, #0
startLoop	CMP R0,#10
			BGT endloop
				ADD R1,R1,R0
				ADD R0,R0,#1
				B startLoop
endloop

endless B endless
				
	ALIGN	  
	END