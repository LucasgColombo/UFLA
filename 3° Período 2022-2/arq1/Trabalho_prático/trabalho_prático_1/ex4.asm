# Title: Produto de pares até  n
# Input: um numero inteiro n
# Output: o produto dos pares entre  1 até n
################# Data segment #####################
.data
	espaco: .byte ' '
################# Code segment #####################

.text
	li $v0,5
	syscall
	
	move $t0, $v0
	li $t1, 1
		addi $t0, $t0,1
	move $s0, $zero
	while:
		beq $t1,$t0,saida 
		move $t2,$t1
		div $t2, $t2, 2
		mfhi $t3
		beq $t3,$zero,multiplica
		addi $t1,$t1,1
		j while
	
	multiplica:
		mul $s0,$s0,$t1
		addi $t1,$t1,1
		j while
	
	saida:
		li $v0,1
		move $a0,$s0
		syscall
		
		
		
		
