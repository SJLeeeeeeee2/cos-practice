.global test

test:
    leaq	(%rdx, %rsi), %rax
    subq	%rdi, %rax
    cmpq	$5, %rdx
    jle	.label2
    cmpq	$2, %rsi
    jle	.label3
    movq	%rdi, %rax
    idivq	%rdx, %rax
.label3:
    movq	%rdi, %rax
    idivq	%rsi, %rax
.label2:
    cmpq	$3, %rdx
    jge	.label4
    movq	%rdx, %rax
    idivq	%rsi, %rax
.label4:
    ret