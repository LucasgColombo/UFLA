.data
	msg: .asciiz "Insira um numero decimal: "
	zero: .double 0.0
	
.text
	#Imprime mendagem
	li $v0, 4
	la $a0, msg
	syscall
	
	#Lendo o numero
	li $v0, 7
	syscall	#Valor lido está em $f0
	
	ldc1 $f2, zero	#Não poderia ser utilizado o $f1 pois o double ocupa tanto o $f0 quanto o $f1
	add.d $f12, $f2, $f0	
	
	#Imprime o numero
	li $v0, 3
	syscall