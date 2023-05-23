#Lê um número inteiro positivo e imprime todos os inteiros de zero até o numero lido
.data
	espaço: .byte ' '
	
.text 
	#Leitura de um inteiro 
	li $v0, 5
	syscall
	
	move $t0, $v0 #Valor lido é armazenado aqui
	move $t1, $zero #Contador
	
	laco:
		bgt $t1, $t0, caiFora
		
		#soma os numeros
#		add $t2, $t2, $t1	parte do exercicio 1 do trabalho pratico
						
		#Imprime $t1
		li $v0, 1
		move $a0, $t1
		syscall
		
		#Imprime espaço em branco
		li $v0, 4
		la $a0, espaço
		syscall
		
		addi $t1, $t1, 1
		j laco	
		
	caiFora:
#		li $v0, 1		parte do exercicio 1 do trabalho pratico
#		move $a0, $t2		parte do exercicio 1 do trabalho pratico
#		syscall			parte do exercicio 1 do trabalho pratico
		
		
