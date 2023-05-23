#Escreva uma fun��o que verifica se um n�mero inteiro positivo � par ou impar

.data
	msg: .asciiz "Digite um numero inteiro e positivo: "
	par: .asciiz "O n�mero � par"
	impar: .asciiz "O n�mero � impar"

.text
	la $a0, msg
	jal imprimeString
	jal leInteiro
	
	move $a0, $v0
	
	jal ehImpar
	
	beq $v0, $zero, imprimePar
	la $a0, impar
	jal imprimeString
	
	jal encerraPrograma
	
	imprimePar:
		la $a0, par
		jal imprimeString
		jal encerraPrograma	

	#Fun��o que verifica se o argumento $a0 � impar
	#Retorna 1 se for impar
	#Retorna 0 se for falso
	ehImpar:
		li $t0, 2
		div $a0, $t0
		
		mfhi $v0
		
		jr $ra
		
	#fun��o que recebe uma string em $a0 ea imprime
	imprimeString:
		li $v0, 4
		syscall
		jr $ra
		
	leInteiro:
		li $v0, 5
		syscall
		jr $ra
		
	encerraPrograma:
		la $v0, 10
		syscall
	
