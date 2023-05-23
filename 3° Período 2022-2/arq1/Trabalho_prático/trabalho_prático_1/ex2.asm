.data
	myarray: .space 40 
	msgInicial: .asciiz "digite 10 n�meros inteiros: "
	msgFinal: .asciiz "Numeros ordenados: "			#Mensagem para o usu�rio
	espa�o: .byte ' '

.text
	main:
		li $v0, 4
   		la $a0, msgInicial
    	syscall
    	
    	jal iniciaArray
	
		la $a3, myarray				#Faz o load address de myArray para $a3
		jal bubbleSort				#Chamada da fun��o
		
		
	iniciaArray:
		beq $t0, 40, exit
		li $v0, 5
    	syscall	
    	sw $v0, myarray($t0)
   		add $t0, $t0, 4
    	j iniciaArray

	exit:
    	jr $ra
    	
		
	bubbleSort:
		li $s0, 0					#Inicializa o contador 1 do loop 1
		li $s6, 9 					#n - 1
	
		li $s1, 0 					#Inicializa o contador 2 do loop 2

		li $t3, 0					#Inicializa o contador para imprimir os n�meros ordenados
		li $t4, 10

		li $v0, 4,					#Imprime a mensagem
		la $a0, msgFinal
		syscall

		loop:
			sll $t7, $s1, 2					#multiplica $s1 por 2 e coloca em t7
			add $t7, $a3, $t7 				#adiciona o endere�o dos n�meros em t7

			lw $t0, 0($t7)  				#carrega os n�meros na posi��o[j]	
			lw $t1, 4($t7) 					#carrega os n�meros na posi��o[j+1]

			slt $t2, $t1, $t0				#if t1 < t0 
			bne $t2, $zero, increment					

			sw $t1, 0($t7) 					#swap		
			sw $t0, 4($t7)								

		increment:	
			addi $s1, $s1, 1				#incrementa t1
			sub $s5, $s6, $s0 				#subtrai s0 de s6

			bne  $s1, $s5, loop				#if s1 (contador do segundo loop) n�o for igual a 9, loop
			addi $s0, $s0, 1 				#se n�o add 1 to s0
			li $s1, 0 						#reseta s1 para 0

			bne  $s0, $s6, loop				#Volta para o loop com s1 = s1 + 1
	
		print:
			beq $t3, $t4, final				#if t3 = t4 vai para final
	
			lw $t5, 0($a3)					#carrega de numbers
	
			li $v0, 1						#imprime o n�mero
			move $a0, $t5
			syscall				
			 
			li $v0, 4						#imprime espa�o em branco
			la $a0, espa�o
			syscall
	
			addi $a3, $a3, 4				#incrementa atrav�s de numbers 		
			addi $t3, $t3, 1				#incrementa o contador

			j print

		final:	
			li $v0, 10						#encerra o programa
			syscall
