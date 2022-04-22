	PRESERVE8
	THUMB   
	
	export CallbackSon
	export SortieSon
	export Index
	export StartSon
	import Son
	import LongueurSon

	include DriverJeuLaser.inc
; ====================== zone de réservation de données,  ======================================
;Section RAM (read only) :
	area    mesdata,data,readonly


;Section RAM (read write):
	area    maram,data,readwrite
SortieSon dcw 0
Index dcd 0
		

	
; ===============================================================================================
	


		
;Section ROM code (read only) :		
	area    moncode,code,readonly
; écrire le code ici		

;CallbackSon(){
	;SortieSon=Son[index];
	;SortieSon=(SortieSon*719)>>16;
	;if (index<LongueurSon){
		;index++;
	;}
	;return SortieSon;



CallbackSon proc
	push {r4-r11,lr}

	ldr r1,=Index
	ldr r7,[r1]
	ldr r2,=Son ;pour prendre 16 bit seulement => ldrh , pour garder le signe conservé ldrsh
	ldr r5,=LongueurSon
	ldr r4,=SortieSon
	ldrsh r3,[r2,r7,lsl#1]
	add R3,#32768
	mov r8,#719
	mul r3,r8
	asr r3,#16
	str r3,[r4]
	ldr r6,[r5]
	cmp r6,r7
	beq fin
	add R7,#1
	str r7,[r1]
	mov r0,r3
	bl PWM_Set_Value_TIM3_Ch3
fin
	pop {r4-r11,lr}
	bx lr
	endp
		
		
		
StartSon proc
	ldr r1,=Index
	mov r2,#0
	str r2,[r1]
	bx lr
	endp




		
		
	END	