# Build an executable using the following:
#
# clang barebones.s -o barebones  # clang is another compiler like gcc
#
.text
_barebones:

.data
	
.globl main


main:
				# (1) What are we setting up here?
				# Ans:
	pushq %rbp		#save the base pointer "rbp" on the stack using pushq instruction
	movq  %rsp, %rbp	#the stack pointer "rsp" is moved to "rbp" using the "movq" instruction

				# (2) What is going on here
				# Ans:setting up a system call to print the string to the standard output
	movq $1, %rax		# load the appropriate values into "rax",
	movq $1, %rdi		# "rdi",
	leaq .hello.str,%rsi	#and "rsi" registers, which specify the system call number 


			# (3) What is syscall? We did not talk about this
			# in class.
			# Ans:make the system call, request services from the operating system
			#
	syscall			# Which syscall is being run?
				# Ans:

				# (4) What would another option be instead of 
				# using a syscall to achieve this?
				# Ans:

	movq	$60, %rax	# (5) We are again setting up another syscall
	movq	$0, %rdi	# What command is it?
				# Ans:	set up another system call to exit the program with a status code of 0
				# The movq instructions set the rax register to the system call number for exit,
				# and the rdi register to the exit status code (in this case, 0). 

	syscall

	popq %rbp		# (Note we do not really need
			 	# this command here after the syscall)

.hello.str:
	.string "Hello World!\n"
	.size	.hello.str,13		# (6) Why is there a 13 here?
					# Ans: hello.str is a null-terminated string, ".size" directive specifies the size of the section, which is 13 bytes
					# 12 for the string plus 1 for the null terminator.
FooterNortheastern University
Northeastern University
