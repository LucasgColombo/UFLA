#L� um n�mero inteiro positivo e imprime todos os inteiros de zero at� o numero lido
.data
	msg: .asciiz "insira um numero inteiro e positivo: "
	saida1: .asciiz "E perfeito"
	saida2: .asciiz "Nao e perfeito"
.text
   #--------------- main ---------------
   
   .main:
   #imprimindo a entrada
   la $a0, msg
   jal imprimeString

   #lendo o número base 
   jal leInteiro
   
   #guardando o numero
   move $a1,$v0
   jal ePerfeito
   
   #imprime o produto
   jal imprimeString
      
   #encerrando o programa
   jal encerraPrograma
	
	
   #--------------- funções --------------- 	
   
   
   ePerfeito:
      li $t0,1
      li $s0, 0   
      loop:
        move $t2,$a1
        beq $t0,$a1,compara
        div $t2,$t0
        mfhi $t3
        beq $t3,$zero,sum
        addi $t0, $t0,1
        j loop
      
      sum:
        add $s0,$s0,$t0
        addi $t0,$t0,1
        j loop
      
      compara:
        beq $s0,$a1,exit
        la $a0, saida2
        jr $ra
      exit:
      	la $a0,saida1
      	jr $ra
        

   leInteiro:
      li $v0, 5
      syscall
      jr $ra 
      
   encerraPrograma:
      li $v0, 10
      syscall
     
   imprimeString:
      li $v0, 4
      syscall
      jr $ra
     
   imprimeInteiro:
      li $v0, 1
      syscall
      jr $ra