.text
	li $t0, 32
	li $t1, 5
	
	div $t0, $t1	#Divide $t0 por $t1 
			#Parte inteira vai para o registrador lo
			#O resto vai para o registrador hi
	
	mflo $s0	# Armazena a parte inteira da divisão em $s0, pois o hi e o lo apesar de serem registradores
			#não podem ser usador em operações diretas, tendo que ser passados para outro registrador
			
	mfhi $s1	# Armazena o resto da divisão em $s1
	
			#Podemos usar o comando shift right, que faz divisão por potências de 2 (srl)
			
	#srl $s2, $t0, 2
