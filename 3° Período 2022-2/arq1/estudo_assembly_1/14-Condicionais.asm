#L� um n�mero inteiro e imprime se ele � par ou impar
.data
	msg: .asciiz "Insira um n�mero: "
	par: .asciiz "O n�mero � par"
	impar: .asciiz "O n�mero � impar"

.text
	#Exibe mensagem
	li $v0, 4
	la $a0, msg
	syscall
	
	#L� um numero inteiro
	li $v0, 5
	syscall
	
	li $t0, 2
	div $v0, $t0 #Divide 5 por 2 para depois conferir o resto
	
	mfhi $t1 #Recebe o resto da divis�o (registrador hi guarda ele e pode ser acessado apenas por mfhi)
	
	beq $t1, $zero, imprimePar
	li $v0, 4
	la $a0, impar
	syscall
	
	#encerrar o programa
	li $v0, 10
	syscall
	
	imprimePar:
		li $v0, 4
		la $a0, par
		syscall
	