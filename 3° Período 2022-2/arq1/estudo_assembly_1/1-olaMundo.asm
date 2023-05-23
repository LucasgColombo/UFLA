.data	#Área para a especificação de variaveis
	msg: .asciiz "olá mundo"	#Mensagem a ser exibida pelo usuário 

.text	#Área para as instruções do programa

	li $v0, 4	#Instrução para impreção de string
	
	la $a0, msg	#la (load adress)(serve para cadeis de caracteres): escreve a mensagem em a0
			#O comando syscall imprime por padrão aquilo que estiver em a0, por isso é necessario passar a mensagem para o registrador
	syscall		#Imprima
