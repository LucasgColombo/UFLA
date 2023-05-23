#REGISTRADORES
	$zero	#Constante zero (0)
	$at	#Assember temporary
	$v0, $v1	#Retornam resultados de fun��es
	$a0, $a1, $a2, $a3	#Argumentos de fun��o (quatro por padr�o)
	$ra	#Return adress: endere�o de retirno de uma fun��o
	$t1 a $t9	#Registradores tempor�rios que podem ser modificados por fun��es
	$s1 a $s7	#Similar ao anterior mas salva o valor
	$k0, $k1	#Registrador do kernel
	$gp	#Registrador de variavel global
	$sp	#Stack pointer: aponta para o inicio da stack e muda progressivamente
	$fp	#Frame pointer: aponta para o inicio da pilha e n�o muda at� que a fun��o seja executada
	
#COMANDOS
	li $v0, 1	#Imprime inteiro
	li $v0, 2	#Imprime float
	li $v0, 3	#Imprime double
	li $v0, 4	#Imprime string ou char
	li $v0, 5	#ler inteiro 
	li $v0, 6	#ler float
	li $v0, 7	#ler double
	li $v0, 8	#ler string ou char
	li $v0, 10	#Encerrar programa princiapa
