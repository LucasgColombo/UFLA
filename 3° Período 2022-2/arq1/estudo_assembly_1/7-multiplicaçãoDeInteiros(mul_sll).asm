.text
	li $t0, 12
	li $t1, 10
	
	sll $s1, $t1, 10 #Multiplica por 2^10
	
	mul $s0, $t0, $t1
	
	li $v0, 1
	move $a0, $s0	#coloca o valor de $s0 em $a0
	
	syscall
	
	# Multiplicar numeros por pot�ncia de 2  � trivial para o computador. basta realizar a opera��o shift left, 
	#que significa mover os bits para a esquerda
	
	#Se movermos os bits de um numero bin�rio uma casa para a esquerda, multiplicamos por 2 
	
	#Se movermos os bits de um numero bin�rio duas casas para a esquerda, multiplicamos por 4 
	
	#Se movermos os bits de um numero bin�rio n casas para a esquerda, multiplicamos por 2^n
	
	#EX: 6 shift left 3 = 48
	
	#EX: sll $s1, $t1, n	Faz shift left de $t1 n casas para a esquerda e armazena em $s1  