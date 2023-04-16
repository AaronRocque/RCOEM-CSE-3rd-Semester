# Smallest of three integers

.text

main:
	# Print msg1
	li $v0, 4	# print_string syscall code = 4
	la $a0, msg1	# this will print msg1
	syscall

	# Getting input from user
	li $v0, 5	#read_int syscall code = 5
	syscall
	move $t0, $v0	#moves the inputed number (a) from $v0 to $t0

	# Print msg2
	li $v0, 4	# print_string syscall code = 4
	la $a0, msg2	# this will print msg2
	syscall

	# Getting input from user
	li $v0, 5	#read_int syscall code = 5
	syscall
	move $t1, $v0	#moves the inputed number (b) from $v0 to $t1

	# Print msg3
	li $v0, 4	# print_string syscall code = 4
	la $a0, msg3	# this will print msg3
	syscall

	# Getting input from user
	li $v0, 5	#read_int syscall code = 5
	syscall
	move $t2, $v0	#moves the inputed number (c) from $v0 to $t2

	# Print msg4
	li $v0, 4	# print_string syscall code = 4
	la $a0, msg4	# this will print msg3
	syscall

	# Determining the smallest number
	blt $t0, $t1, L0	# if a < b, go to L0
	blt $t1, $t0, L1	# if b < a, go to L1



L0:
	blt $t0, $t2, L2	#if a < c, go to L2
	blt $t2, $t0, L3	#if c < a, go to L3



L2:
	li $v0, 1	#print_int syscall code = 1
	move $a0, $t0	#this will print a
	syscall

	li $v0, 10	#exit
	syscall


L3:
	li $v0, 1	#print_int syscall code = 1
	move $a0, $t2	#this will print c
	syscall

	li $v0, 10	#exit
	syscall



L1:
	blt $t1, $t2, L4	#if a < c, go to L4
	blt $t2, $t1, L3	#if c < a, go to L3



L4:
	li $v0, 1	#print_int syscall code = 1
	move $a0, $t1	#this will print b
	syscall

	li $v0, 10	#exit
	syscall





.data
	msg1: .asciiz "Enter the first number: "
	msg2: .asciiz "Enter the second number: "
	msg3: .asciiz "Enter the third number: "
	msg4: .asciiz "The smallest number is: "




