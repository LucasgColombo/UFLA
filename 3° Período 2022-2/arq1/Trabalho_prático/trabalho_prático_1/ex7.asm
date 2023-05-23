.data
   entrada1: .asciiz "Digite o número base: "
   entrada2: .asciiz "Digite o número expoente: "
   saidaString: .asciiz "O resultado da potência é: "

.text
   #--------------- main ---------------
   
   .main:
   #imprimindo a entrada
   la $a0, entrada1
   jal imprimeString

   #lendo o número base 
   jal leInteiro
   
   #guardando o valor aa base
   move $a1, $v0
   
   #imprimindo a entrada
   la $a0, entrada2
   jal imprimeString
   
   #lendo o número expoente
   jal leInteiro
   
   #guardando o valor do expoente
   move $a2, $v0
   
   #chamando função pow
   jal pow
   
   #guardando o resultado da função
   move $t0, $v0 
   
   #imprimindo a saida
   la $a0, saidaString
   jal imprimeString
   
   li $v0, 1
   move $a0, $t0
   syscall
      
   #encerrando o programa
   jal encerraPrograma
	
	
   #--------------- funções --------------- 	
	
   pow:
     move $t0, $zero #$t0 será o iterador, inicializando iterador
     while:
        addi $t0, $t0, 1 #i++
        beq $t0, $a2, saida #condição do while
        mul $a1, $a1, $a1 #operação de potência
        
        j while
     saida:
        move $v0, $a1
        jr $ra
	
   imprimeString:
      li $v0, 4
      syscall
      jr $ra
  
   leInteiro:
      li $v0, 5
      syscall
      jr $ra 
      
   encerraPrograma:
      li $v0, 10
      syscall