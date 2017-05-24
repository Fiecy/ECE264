	.file	"boa.c"
	.text
.Ltext0:
	.section	.rodata
.LC0:
	.string	"Hello.  What is your name?"
.LC1:
	.string	"Hello, %s."
	.text
	.globl	greet_visitor
	.type	greet_visitor, @function
greet_visitor:
.LFB0:
	.file 1 "boa.c"
	.loc 1 3 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	.loc 1 4 0
	movl	$-1431655766, -4(%rbp)
	.loc 1 6 0
	movl	$.LC0, %edi
	call	puts
	.loc 1 7 0
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	gets
	.loc 1 8 0
	leaq	-32(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	.loc 1 9 0
	movl	$-1430537302, -8(%rbp)
	.loc 1 10 0
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	greet_visitor, .-greet_visitor
	.globl	scare_visitor
	.type	scare_visitor, @function
scare_visitor:
.LFB1:
	.loc 1 12 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	.loc 1 13 0
	movl	$-1429418838, -4(%rbp)
	.loc 1 14 0
	movabsq	$729901041440608834, %rax
	movq	%rax, -32(%rbp)
	movw	$0, -24(%rbp)
	.loc 1 15 0
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	.loc 1 16 0
	movl	$-1428300374, -8(%rbp)
	.loc 1 17 0
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	scare_visitor, .-scare_visitor
	.globl	main
	.type	main, @function
main:
.LFB2:
	.loc 1 19 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	.loc 1 20 0
	movl	$-1427181910, -4(%rbp)
	.loc 1 21 0
	movl	$0, %eax
	call	greet_visitor
	.loc 1 22 0
	movl	$-1426063446, -8(%rbp)
	.loc 1 23 0
	movl	$0, %eax
	.loc 1 24 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
.Letext0:
	.file 2 "/package/gcc/6.1.0/lib/gcc/x86_64-pc-linux-gnu/6.1.0/include/stddef.h"
	.file 3 "/usr/include/bits/types.h"
	.file 4 "/usr/include/libio.h"
	.file 5 "/usr/include/stdio.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x3d0
	.value	0x4
	.long	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.long	.LASF62
	.byte	0xc
	.long	.LASF63
	.long	.LASF64
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.uleb128 0x2
	.long	.LASF7
	.byte	0x2
	.byte	0xd8
	.long	0x38
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.long	.LASF0
	.uleb128 0x3
	.byte	0x1
	.byte	0x8
	.long	.LASF1
	.uleb128 0x3
	.byte	0x2
	.byte	0x7
	.long	.LASF2
	.uleb128 0x3
	.byte	0x4
	.byte	0x7
	.long	.LASF3
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.long	.LASF4
	.uleb128 0x3
	.byte	0x2
	.byte	0x5
	.long	.LASF5
	.uleb128 0x4
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x3
	.byte	0x8
	.byte	0x5
	.long	.LASF6
	.uleb128 0x2
	.long	.LASF8
	.byte	0x3
	.byte	0x8d
	.long	0x69
	.uleb128 0x2
	.long	.LASF9
	.byte	0x3
	.byte	0x8e
	.long	0x69
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.long	.LASF10
	.uleb128 0x5
	.byte	0x8
	.uleb128 0x6
	.byte	0x8
	.long	0x95
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.long	.LASF11
	.uleb128 0x7
	.long	.LASF41
	.byte	0xd8
	.byte	0x4
	.value	0x10f
	.long	0x223
	.uleb128 0x8
	.long	.LASF12
	.byte	0x4
	.value	0x110
	.long	0x62
	.byte	0
	.uleb128 0x8
	.long	.LASF13
	.byte	0x4
	.value	0x115
	.long	0x8f
	.byte	0x8
	.uleb128 0x8
	.long	.LASF14
	.byte	0x4
	.value	0x116
	.long	0x8f
	.byte	0x10
	.uleb128 0x8
	.long	.LASF15
	.byte	0x4
	.value	0x117
	.long	0x8f
	.byte	0x18
	.uleb128 0x8
	.long	.LASF16
	.byte	0x4
	.value	0x118
	.long	0x8f
	.byte	0x20
	.uleb128 0x8
	.long	.LASF17
	.byte	0x4
	.value	0x119
	.long	0x8f
	.byte	0x28
	.uleb128 0x8
	.long	.LASF18
	.byte	0x4
	.value	0x11a
	.long	0x8f
	.byte	0x30
	.uleb128 0x8
	.long	.LASF19
	.byte	0x4
	.value	0x11b
	.long	0x8f
	.byte	0x38
	.uleb128 0x8
	.long	.LASF20
	.byte	0x4
	.value	0x11c
	.long	0x8f
	.byte	0x40
	.uleb128 0x8
	.long	.LASF21
	.byte	0x4
	.value	0x11e
	.long	0x8f
	.byte	0x48
	.uleb128 0x8
	.long	.LASF22
	.byte	0x4
	.value	0x11f
	.long	0x8f
	.byte	0x50
	.uleb128 0x8
	.long	.LASF23
	.byte	0x4
	.value	0x120
	.long	0x8f
	.byte	0x58
	.uleb128 0x8
	.long	.LASF24
	.byte	0x4
	.value	0x122
	.long	0x25b
	.byte	0x60
	.uleb128 0x8
	.long	.LASF25
	.byte	0x4
	.value	0x124
	.long	0x261
	.byte	0x68
	.uleb128 0x8
	.long	.LASF26
	.byte	0x4
	.value	0x126
	.long	0x62
	.byte	0x70
	.uleb128 0x8
	.long	.LASF27
	.byte	0x4
	.value	0x12a
	.long	0x62
	.byte	0x74
	.uleb128 0x8
	.long	.LASF28
	.byte	0x4
	.value	0x12c
	.long	0x70
	.byte	0x78
	.uleb128 0x8
	.long	.LASF29
	.byte	0x4
	.value	0x130
	.long	0x46
	.byte	0x80
	.uleb128 0x8
	.long	.LASF30
	.byte	0x4
	.value	0x131
	.long	0x54
	.byte	0x82
	.uleb128 0x8
	.long	.LASF31
	.byte	0x4
	.value	0x132
	.long	0x267
	.byte	0x83
	.uleb128 0x8
	.long	.LASF32
	.byte	0x4
	.value	0x136
	.long	0x277
	.byte	0x88
	.uleb128 0x8
	.long	.LASF33
	.byte	0x4
	.value	0x13f
	.long	0x7b
	.byte	0x90
	.uleb128 0x8
	.long	.LASF34
	.byte	0x4
	.value	0x148
	.long	0x8d
	.byte	0x98
	.uleb128 0x8
	.long	.LASF35
	.byte	0x4
	.value	0x149
	.long	0x8d
	.byte	0xa0
	.uleb128 0x8
	.long	.LASF36
	.byte	0x4
	.value	0x14a
	.long	0x8d
	.byte	0xa8
	.uleb128 0x8
	.long	.LASF37
	.byte	0x4
	.value	0x14b
	.long	0x8d
	.byte	0xb0
	.uleb128 0x8
	.long	.LASF38
	.byte	0x4
	.value	0x14c
	.long	0x2d
	.byte	0xb8
	.uleb128 0x8
	.long	.LASF39
	.byte	0x4
	.value	0x14e
	.long	0x62
	.byte	0xc0
	.uleb128 0x8
	.long	.LASF40
	.byte	0x4
	.value	0x150
	.long	0x27d
	.byte	0xc4
	.byte	0
	.uleb128 0x9
	.long	.LASF65
	.byte	0x4
	.byte	0xb4
	.uleb128 0xa
	.long	.LASF42
	.byte	0x18
	.byte	0x4
	.byte	0xba
	.long	0x25b
	.uleb128 0xb
	.long	.LASF43
	.byte	0x4
	.byte	0xbb
	.long	0x25b
	.byte	0
	.uleb128 0xb
	.long	.LASF44
	.byte	0x4
	.byte	0xbc
	.long	0x261
	.byte	0x8
	.uleb128 0xb
	.long	.LASF45
	.byte	0x4
	.byte	0xc0
	.long	0x62
	.byte	0x10
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0x22a
	.uleb128 0x6
	.byte	0x8
	.long	0x9c
	.uleb128 0xc
	.long	0x95
	.long	0x277
	.uleb128 0xd
	.long	0x86
	.byte	0
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0x223
	.uleb128 0xc
	.long	0x95
	.long	0x28d
	.uleb128 0xd
	.long	0x86
	.byte	0x13
	.byte	0
	.uleb128 0xe
	.long	.LASF66
	.uleb128 0xf
	.long	.LASF46
	.byte	0x4
	.value	0x15a
	.long	0x28d
	.uleb128 0xf
	.long	.LASF47
	.byte	0x4
	.value	0x15b
	.long	0x28d
	.uleb128 0xf
	.long	.LASF48
	.byte	0x4
	.value	0x15c
	.long	0x28d
	.uleb128 0x10
	.long	.LASF49
	.byte	0x5
	.byte	0xa5
	.long	0x261
	.uleb128 0x10
	.long	.LASF50
	.byte	0x5
	.byte	0xa6
	.long	0x261
	.uleb128 0x10
	.long	.LASF51
	.byte	0x5
	.byte	0xa7
	.long	0x261
	.uleb128 0x11
	.long	.LASF67
	.byte	0x1
	.byte	0x13
	.long	0x62
	.quad	.LFB2
	.quad	.LFE2-.LFB2
	.uleb128 0x1
	.byte	0x9c
	.long	0x331
	.uleb128 0x12
	.long	.LASF52
	.byte	0x1
	.byte	0x13
	.long	0x62
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x12
	.long	.LASF53
	.byte	0x1
	.byte	0x13
	.long	0x331
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x13
	.long	.LASF54
	.byte	0x1
	.byte	0x14
	.long	0x62
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x13
	.long	.LASF55
	.byte	0x1
	.byte	0x16
	.long	0x62
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0x8f
	.uleb128 0x14
	.long	.LASF68
	.byte	0x1
	.byte	0xc
	.quad	.LFB1
	.quad	.LFE1-.LFB1
	.uleb128 0x1
	.byte	0x9c
	.long	0x37f
	.uleb128 0x13
	.long	.LASF56
	.byte	0x1
	.byte	0xd
	.long	0x62
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x13
	.long	.LASF57
	.byte	0x1
	.byte	0xe
	.long	0x37f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x13
	.long	.LASF58
	.byte	0x1
	.byte	0x10
	.long	0x62
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.uleb128 0xc
	.long	0x95
	.long	0x38f
	.uleb128 0xd
	.long	0x86
	.byte	0x9
	.byte	0
	.uleb128 0x15
	.long	.LASF69
	.byte	0x1
	.byte	0x3
	.quad	.LFB0
	.quad	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x13
	.long	.LASF59
	.byte	0x1
	.byte	0x4
	.long	0x62
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x13
	.long	.LASF60
	.byte	0x1
	.byte	0x5
	.long	0x37f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x13
	.long	.LASF61
	.byte	0x1
	.byte	0x9
	.long	0x62
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x13
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x12
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x13
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x14
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x15
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",@progbits
	.long	0x2c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x8
	.byte	0
	.value	0
	.value	0
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.quad	0
	.quad	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF20:
	.string	"_IO_buf_end"
.LASF28:
	.string	"_old_offset"
.LASF57:
	.string	"message"
.LASF23:
	.string	"_IO_save_end"
.LASF62:
	.string	"GNU C99 6.1.0 -mtune=generic -march=x86-64 -g -std=c99"
.LASF5:
	.string	"short int"
.LASF7:
	.string	"size_t"
.LASF10:
	.string	"sizetype"
.LASF33:
	.string	"_offset"
.LASF17:
	.string	"_IO_write_ptr"
.LASF12:
	.string	"_flags"
.LASF19:
	.string	"_IO_buf_base"
.LASF56:
	.string	"sv_top"
.LASF24:
	.string	"_markers"
.LASF14:
	.string	"_IO_read_end"
.LASF68:
	.string	"scare_visitor"
.LASF51:
	.string	"stderr"
.LASF32:
	.string	"_lock"
.LASF6:
	.string	"long int"
.LASF29:
	.string	"_cur_column"
.LASF48:
	.string	"_IO_2_1_stderr_"
.LASF66:
	.string	"_IO_FILE_plus"
.LASF45:
	.string	"_pos"
.LASF54:
	.string	"mn_top"
.LASF53:
	.string	"argv"
.LASF60:
	.string	"name"
.LASF44:
	.string	"_sbuf"
.LASF41:
	.string	"_IO_FILE"
.LASF1:
	.string	"unsigned char"
.LASF52:
	.string	"argc"
.LASF4:
	.string	"signed char"
.LASF46:
	.string	"_IO_2_1_stdin_"
.LASF64:
	.string	"/home/shay/a/li1652/264/hw15"
.LASF3:
	.string	"unsigned int"
.LASF42:
	.string	"_IO_marker"
.LASF31:
	.string	"_shortbuf"
.LASF59:
	.string	"gt_top"
.LASF16:
	.string	"_IO_write_base"
.LASF40:
	.string	"_unused2"
.LASF58:
	.string	"sv_btm"
.LASF13:
	.string	"_IO_read_ptr"
.LASF2:
	.string	"short unsigned int"
.LASF63:
	.string	"boa.c"
.LASF11:
	.string	"char"
.LASF69:
	.string	"greet_visitor"
.LASF67:
	.string	"main"
.LASF43:
	.string	"_next"
.LASF34:
	.string	"__pad1"
.LASF35:
	.string	"__pad2"
.LASF36:
	.string	"__pad3"
.LASF37:
	.string	"__pad4"
.LASF38:
	.string	"__pad5"
.LASF0:
	.string	"long unsigned int"
.LASF18:
	.string	"_IO_write_end"
.LASF9:
	.string	"__off64_t"
.LASF8:
	.string	"__off_t"
.LASF25:
	.string	"_chain"
.LASF55:
	.string	"mn_btm"
.LASF22:
	.string	"_IO_backup_base"
.LASF49:
	.string	"stdin"
.LASF27:
	.string	"_flags2"
.LASF39:
	.string	"_mode"
.LASF15:
	.string	"_IO_read_base"
.LASF30:
	.string	"_vtable_offset"
.LASF21:
	.string	"_IO_save_base"
.LASF26:
	.string	"_fileno"
.LASF61:
	.string	"gt_btm"
.LASF50:
	.string	"stdout"
.LASF47:
	.string	"_IO_2_1_stdout_"
.LASF65:
	.string	"_IO_lock_t"
	.ident	"GCC: (GNU) 6.1.0"
	.section	.note.GNU-stack,"",@progbits
