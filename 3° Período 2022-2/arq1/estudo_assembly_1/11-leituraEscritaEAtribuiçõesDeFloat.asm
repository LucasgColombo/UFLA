.data
	msg: .asciiz "Insira um numero decimal: "
	zero: .float 0.0
	
.text
	#Imprime mendagem
	li $v0, 4
	la $a0, msg
	syscall
	
	#Lendo o numero
	li $v0, 6
	syscall	#Valor lido est� em $f0
	
	lwc1 $f1, zero
	add.s $f12, $f1, $f0	# N�o � possivel uti�izar o comando move para float, por isso � necessario soma-lo com zero (0),
				#mas como n�o existe registrador de falor 0 n�o existe por padrao no coprocessador 1, � necessa-
				#rio criar uma constante de valor zero na �rea .data
	
	#Imprime o numero
	li $v0, 2
	syscall