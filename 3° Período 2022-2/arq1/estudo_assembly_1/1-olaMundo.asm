.data	#�rea para a especifica��o de variaveis
	msg: .asciiz "ol� mundo"	#Mensagem a ser exibida pelo usu�rio 

.text	#�rea para as instru��es do programa

	li $v0, 4	#Instru��o para impre��o de string
	
	la $a0, msg	#la (load adress)(serve para cadeis de caracteres): escreve a mensagem em a0
			#O comando syscall imprime por padr�o aquilo que estiver em a0, por isso � necessario passar a mensagem para o registrador
	syscall		#Imprima
