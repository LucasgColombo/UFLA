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
	syscall	#Valor lido está em $f0
	
	lwc1 $f1, zero
	add.s $f12, $f1, $f0	# Não é possivel utiçizar o comando move para float, por isso é necessario soma-lo com zero (0),
				#mas como não existe registrador de falor 0 não existe por padrao no coprocessador 1, é necessa-
				#rio criar uma constante de valor zero na área .data
	
	#Imprime o numero
	li $v0, 2
	syscall