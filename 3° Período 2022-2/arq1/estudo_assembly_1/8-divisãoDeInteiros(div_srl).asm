.text
	li $t0, 32
	li $t1, 5
	
	div $t0, $t1	#Divide $t0 por $t1 
			#Parte inteira vai para o registrador lo
			#O resto vai para o registrador hi
	
	mflo $s0	# Armazena a parte inteira da divis�o em $s0, pois o hi e o lo apesar de serem registradores
			#n�o podem ser usador em opera��es diretas, tendo que ser passados para outro registrador
			
	mfhi $s1	# Armazena o resto da divis�o em $s1
	
			#Podemos usar o comando shift right, que faz divis�o por pot�ncias de 2 (srl)
			
	#srl $s2, $t0, 2
