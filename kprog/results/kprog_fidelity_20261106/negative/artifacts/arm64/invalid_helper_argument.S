.text
.global entry
entry:
mov x0, #1
mov x1, #0
bl bpf_map_lookup_elem
ret
