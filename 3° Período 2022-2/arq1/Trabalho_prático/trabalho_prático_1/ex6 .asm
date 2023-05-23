.data
	qntMultiplos: .asciiz "Digite a quantidade de múltiplos a serem impressos: "
	numeros: .asciiz "Digite dois números para saber seus múltiplos: "
	msgFinal: .asciiz "Os múltiplos desses números são: "
	espaço: .byte ' '

.text
	main:
		la $a0, qntMultiplos
		jal imprimeString
    	
    	#num de multiplos a serem exibidos no final
    	jal leInteiro  	
    	move $t0, $v0
    	
   		la $a0, numeros
		jal imprimeString
    	
    	#num1 que se deseja saber os multiplos
    	jal leInteiro   	
    	move $t1, $v0
    	
    	#num2 que se deseja saber os multiplos
    	jal leInteiro   	
    	move $t2, $v0
    	
    	move $t3, $zero	#candidato a multiplo
    	move $t4, $zero	#contador
    	
   		la $a0, msgFinal
   		jal imprimeString
    	
    	loop:
    		beq $t4, $t0, exit
    		
    		div $t3, $t1
    		mfhi $s0
    		beq $s0, $zero, imprimeMult
    		
    		div $t3, $t2
    		mfhi $s1
    		beq $s1, $zero, imprimeMult
    		
    		addi $t3, $t3, 1	#incrementa o concorrente multiplo
    		j loop
    		
    		imprimeMult:
    			li $v0, 1	#imprime o múltiplo
				move $a0, $t3
				syscall	
					
				la $a0, espaço	#imprime espaço em branco
				jal imprimeString
				
				addi $t4, $t4, 1	#incrementa o contador
				addi $t3, $t3, 1	#incrementa o concorrente multiplo
				j loop
    		
    	exit: 
    		li $v0, 10
    		syscall
    	
    	imprimeString:
			li $v0, 4
			syscall
			jr $ra
			
		leInteiro:
			li $v0, 5
			syscall
			jr $ra