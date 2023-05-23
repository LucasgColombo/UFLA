.data
	digite:    .asciiz "Digite o numero: "
	positivo:  .asciiz "Formam um Triangulo Retangulo"
	negativo:  .asciiz "Não formam um Triangulo Retangulo"

.text
	.main
		la $a0, digite
		
		# Ler o primeiro número e guardar em t1
		jal printString
		jal lerInteiro
		move $t1, $v0
		
		# Ler o segundo número e guardar em t2
		jal printString
		jal lerInteiro
		move $t2, $v0
		
		# Ler o terceiro número e guardar em t3
		jal printString
		jal lerInteiro
		move $t3, $v0
		
		# Elevando os números ao quadrado para aplicarmos o teorema de pitágoras
		mul $t1, $t1, $t1
		mul $t2, $t2, $t2
		mul $t3, $t3, $t3
		
		# Fazendo as possíveis soma dos catetos
		add $t4, $t1, $t2
		add $t5, $t1, $t3
		add $t6, $t2, $t3
	
		# Se as soma for igual a hipotesuna, é um triangulo retangulo
		beq $t1, $t6, ehTriangulo
		beq $t2, $t5, ehTriangulo
		beq $t3, $t4, ehTriangulo
	
		# Se todas falhar, não é um triangulo
		la $a0, negativo
		jal printString
		
		# Encerra o programa
		la $v0, 10
		syscall
	
	ehTriangulo:
		# Função de saida, caso seja um triangulo retangulo
		la $a0, positivo
		jal printString
		
		li $v0, 10
		syscall
	
	printString:
		# Função para impressão de string
		li $v0, 4
		syscall
		jr $ra
	
	lerInteiro:
		# Função para ler um número inteiro
		li $v0, 5
		syscall
		jr $ra
