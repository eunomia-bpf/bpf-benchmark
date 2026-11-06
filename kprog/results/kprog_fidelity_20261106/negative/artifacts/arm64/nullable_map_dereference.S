.text
.global entry
entry:
ldr x1, [x0]
ldr x2, [x0, #8]
add x3, x1, #4
cmp x3, x2
b.hi 1f
adrp x0, :got:neg_map
ldr x0, [x0, :got_lo12:neg_map]
bl bpf_map_lookup_elem
ldr x0, [x0]
ret
1: mov x0, #0
ret
