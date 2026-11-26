.text
.global lr_after_blr
.type lr_after_blr,%function
lr_after_blr:
 stp x29,x30,[sp,#-16]!
 adrp x30,:got:frozen_map
 ldr x30,[x30,:got_lo12:frozen_map]
 blr x9
 ldr x0,[x30]
 ldp x29,x30,[sp],#16
 ret
.size lr_after_blr,.-lr_after_blr
.global lr_after_bl
.type lr_after_bl,%function
lr_after_bl:
 stp x29,x30,[sp,#-16]!
 adrp x30,:got:frozen_map
 ldr x30,[x30,:got_lo12:frozen_map]
 bl bpf_ktime_get_ns
 ldr x0,[x30]
 ldp x29,x30,[sp],#16
 ret
.size lr_after_bl,.-lr_after_bl
