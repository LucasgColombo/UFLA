.data
	pergunta: .asciiz "Qual � o seu nome? "
	sauda��o: .asciiz "ol�, "
	nome: .space 25
	
.text
	#impress�o da pergunta
	li $v0, 4
	la $a0, pergunta
	syscall
	
	#leitura da string
	li $v0, 8 
	la $a0, nome
	la $a1, 25
	syscall
	
	#sauda��o
	li $v0, 4
	la $a0, sauda��o
	syscall
	
	#impress�o do nome
	li $v0, 4
	la $a0, nome
	syscall