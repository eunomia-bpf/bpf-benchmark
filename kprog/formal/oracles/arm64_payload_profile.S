/* Three retained words in a four-word frame. Copies exercise both directions
 * through the nonidentity logical-slot3 -> physical-slot2 mapping. */
.text
.global arm64_payload_profile
.type arm64_payload_profile, %function
arm64_payload_profile:
	sub sp, sp, #32
	add x1, sp, #16
	str x30, [sp]
	str x1, [sp, #8]
	add x0, sp, #24
	add x1, sp, #8
	mov x2, #8
	bl memcpy
	/* The second copy must restore metadata, not reuse the old destination. */
	mov x1, sp
	str x1, [sp, #8]
	add x0, sp, #8
	add x1, sp, #24
	mov x2, #8
	bl memcpy
	ldr x2, [sp, #8]
	ldr x3, [sp]
	eor x0, x2, x3
	lsr x4, x0, #32
	eor x0, x0, x4
	ldr x30, [sp]
	add sp, sp, #32
	ret
.size arm64_payload_profile, .-arm64_payload_profile
