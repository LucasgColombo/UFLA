#L� um numero inteiro e retorna se ele � maior, menor ou igual a zero
.data
	maior: .asciiz "O n�mero � maior que zero"
	menor: .asciiz "O n�mero � menor que zero"
	igual: .asciiz "O n�mero � igual a zero"
	
.text 
	#L� um n�mero inteiro
	li $v0, 5
	syscall
	
	move $t0, $v0 #guarda o numero em outro registrador para facilitar
	
	beq $t0, $zero, imprimeIgual
	bgt $t0, $zero, imprimeMaior
	blt $t0, $zero, imprimeMenor
	 
	imprimeIgual: 
		li $v0, 4
		la $a0, igual
		syscall
		
		li $v0, 10
		syscall
		
	imprimeMaior:
		li $v0, 4
		la $a0, maior
		syscall
		
		li $v0, 10
		syscall
		
	imprimeMenor:
		li $v0, 4
		la $a0, menor
		syscall
		
		li $v0, 10
		syscall