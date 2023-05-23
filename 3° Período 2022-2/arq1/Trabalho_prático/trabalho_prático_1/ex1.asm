#Lê um número inteiro positivo e imprime todos os inteiros de zero até o numero lido
.data
	msg: .asciiz "insira um numero inteiro e positivo: "
	
.text 
	la $a0, msg
	jal imprimeString
	jal leInteiro
	
	move $a0, $v0	#Numero dado pelo usuário
	move $a1, $zero	#Contador
	
	jal soma
	move $a0, $v0
	jal imprimeInteiro
	
	la $v0, 10
	syscall 
	
	imprimeInteiro:
		li $v0, 1
		syscall
		jr $ra
		
	soma:
		loop:
			beq $a1, $a0, exit	#Comparação
		
			add $v0, $v0, $a1	#Soma
		
			addi $a1, $a1, 1	#Aumenta o contador
			j loop
		
		exit:
			jr $ra
	
	leInteiro:
		li $v0, 5
		syscall
		jr $ra
		
	imprimeString:
		li $v0, 4
		syscall
		jr $ra
