	PRESERVE8
	THUMB   
	INCLUDE DriverJeuLaser.inc
	
			
	export timer_callback
	export Flag_Cligno

; ====================== zone de réservation de données,  ======================================
;Section RAM (read only) :
	area    mesdata,data,readonly



;Section RAM (read write):
	area    maram,data,readwrite
Flag_Cligno dcb 0 		

	
; ===============================================================================================
	


		
;Section ROM code (read only) :		
	area    moncode,code,readonly
; écrire le code ici		
timer_callback proc
	ldr r0,=Flag_Cligno
	ldrb r1,[r0] ; ldrb load le bit
	cmp r1,#1
	bne NOT_EQUAL
	mov r1,#0
	strb r1,[r0]; strb store le bit
	push {lr}
	mov r0,#1	
	bl GPIOB_Set;
	pop {lr}
	b fin

NOT_EQUAL
	mov r1,#1
	strb r1,[r0]
	push {lr}
	mov r0,#1	
	bl GPIOB_Clear;
	pop {lr}
	b fin

fin
	bx lr
	endp

	END	