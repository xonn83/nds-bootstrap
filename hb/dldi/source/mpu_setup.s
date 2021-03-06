@---------------------------------------------------------------------------------
@ DS processor selection
@---------------------------------------------------------------------------------
	.arch	armv5te
	.cpu	arm946e-s

	.text
	.arm
	
	.global myMemCached
	.type	myMemCached STT_FUNC
@---------------------------------------------------------------------------------
myMemCached:
@---------------------------------------------------------------------------------
	ldr	r1,=masks
	ldr	r1, [r1]
	ldr	r2,[r1],#4
	and	r0,r0,r2
	ldr	r2,[r1]
	orr	r0,r0,r2
	bx	lr

	.global	myMemUncached
	.type	myMemUncached STT_FUNC
@---------------------------------------------------------------------------------
myMemUncached:
@---------------------------------------------------------------------------------

	ldr	r1,=0x4004008
	ldr	r1,[r1]
	tst	r1,#0x8000
	bne	dsi_mode

    ds_mode:
    
    ldr	r1,=masks
	ldr	r1, [r1]
	ldr	r2,[r1],#8
	and	r0,r0,r2
	ldr	r2,[r1]
	orr	r0,r0,r2
	bx	lr
    
    dsi_mode:
    ldr	r1,=dsimasks
	ldr	r2,[r1],#8
	and	r0,r0,r2
	ldr	r2,[r1]
	orr	r0,r0,r2
	bx	lr

	.data
	.align	2

dsmasks:
	.word	0x00Cfffff, 0x02000000, 0x02400000
debugmasks:
	.word	0x007fffff, 0x02000000, 0x02800000
dsimasks:
	.word	0x00ffffff, 0x02000000, 0x0c000000

masks:	.word	dsmasks
