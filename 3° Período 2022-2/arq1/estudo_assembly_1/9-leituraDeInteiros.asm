.data
	sauda��o: .asciiz "forne�a sua idade: "
	saida: .asciiz "sua idade �: "

.text
	li $v0, 4 	#Imprime uma string
	la $a0, sauda��o
	syscall
	
	li $v0, 5	#leitura de um inteiro
	syscall
	
	move $t0, $v0	#valor fornecido na leitura agora � armazenado em $t0 para que seja possivel utilizar $v0 mais vezes
	
	li $v0, 4
	la $a0, saida
	syscall
	
	li $v0, 1
	move $a0, $t0
	syscall
