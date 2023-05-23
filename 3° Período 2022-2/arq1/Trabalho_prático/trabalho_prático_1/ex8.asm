.data
   entrada: .asciiz "Digite um número: "
   saida1: .asciiz "Este número É triangular"
   saida2: .asciiz "Este número NÂO é triangular"

.text
   #--------------- main ---------------
   
   .main:
   
   #imprime entrada
   la $a0, entrada
   jal imprimeString
   
   #le inteiro a ser analisado
   jal leInteiro
   
   #guardando inteiro em $a0 e chamando a função de verificação
   move $a1, $v0
   jal verificaTriangular
   
   		
   #--------------- funções --------------- 	
	
   verificaTriangular:
      move $t0, $zero #inicializando iterador com valor 0
      
      # for (i = 1; i*(i+1)*(i+2) < n; i++)
      while: 
         addi $t0, $t0, 1 #i++
         
         #chamando a função que faz a operação
         move $a2, $t0
         jal continha
         move $t2, $v0
         
         #repete o laço enquanto: i*(i+1)*(i+2) < n
         bge $t2, $a1, saida
         j while
          
      saida:
         bne $t2, $a1, exit #se não for triangular
         
         #se for triangular, imprime que é triangular
         jal ehTriangular
         
         exit:
            #senão imprime que NÂO é triangular
            la $a0, saida2
            jal imprimeString 
            jal encerraPrograma
  
   #i*(i+1)*(i+2)
   continha:
      move $t1, $a2 # $t1 = i
      addi $t1, $t1, 1 # $t1 = (i+1)
      mul $a2, $a2, $t1 # (i) * (i+1)		
      addi $t1, $t1, 1 # (i+2) , $t1 já vale (i+1), somando 1, fica (i+2)					
      mul $a2, $a2, $t1 # ((i) * (i+1)) * (i+2)
      
      move $v0, $a2
      jr $ra
   			
   
   ehTriangular:
      la $a0, saida1
      jal imprimeString
      jal encerraPrograma		
   						
   												
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