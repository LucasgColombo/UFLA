#Escreva uma função que verifica se um número inteiro positivo é par ou impar

.data
	msg: .asciiz "Digite um numero inteiro e positivo: "
	par: .asciiz "O número é par"
	impar: .asciiz "O número é impar"

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

	#Função que verifica se o argumento $a0 é impar
	#Retorna 1 se for impar
	#Retorna 0 se for falso
	ehImpar:
		li $t0, 2
		div $a0, $t0
		
		mfhi $v0
		
		jr $ra
		
	#função que recebe uma string em $a0 ea imprime
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
	
