.data
	pergunta: .asciiz "Qual é o seu nome? "
	saudação: .asciiz "olá, "
	nome: .space 25
	
.text
	#impressão da pergunta
	li $v0, 4
	la $a0, pergunta
	syscall
	
	#leitura da string
	li $v0, 8 
	la $a0, nome
	la $a1, 25
	syscall
	
	#saudação
	li $v0, 4
	la $a0, saudação
	syscall
	
	#impressão do nome
	li $v0, 4
	la $a0, nome
	syscall