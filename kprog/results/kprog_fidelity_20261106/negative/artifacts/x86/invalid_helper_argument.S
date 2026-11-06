.intel_syntax noprefix
.text
.global entry
entry:
mov rdi, 1
mov rsi, 0
call bpf_map_lookup_elem
ret
