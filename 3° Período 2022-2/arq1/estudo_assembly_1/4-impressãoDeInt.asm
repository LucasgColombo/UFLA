.data
	idade: .word 56		#idade da pessoa

.text
	li $v0, 1
	lw $a0, idade	#lw (load word) serve para .word
	syscall