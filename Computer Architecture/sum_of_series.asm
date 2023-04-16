# Sum of series 
# Adding first N natural numbers

.text

main:
	# Print msg1
	li $v0, 4	# print_string syscall code = 4
	la $a0, msg1	# this will print msg1
	syscall

	# Getting input from user
	li $v0, 5	#read_int syscall code = 5
	syscall
	move $t0, $v0	#moves the inputed number (N) from $v0 to $t0

	# Initialization of other registers 
	li $t1, 0	#this is the counter, counter = 0
	li $t2, 0	#this is the sum, sum = 0


	#loop body
loop:
	addi $t1, $t1, 1	# counter = counter + 1
	add $t2, $t2, $t1	# sum = sum + counter
	beq $t0, $t1, next 	# if N == counter, go to next
	j loop			# this will keep it in loop

	#next part
next:
	# Print msg2
	li $v0, 4	#print_string syscall code = 4
	la $a0, msg2	#this will print msg2
	syscall

	# Print sum
	li $v0, 1	#print_int syscall code = 3
	move $a0, $t2	#this will print the sum
	syscall

	# Exit
	li $v0, 10	#exit
	syscall

.data
	msg1: .asciiz "Enter a number: "
	msg2: .asciiz "Sum = "

	

