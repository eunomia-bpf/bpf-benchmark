.text
.global _start
_start:
 b linked_entry
.balign 8
linked_entry:
.incbin "/workspaces/repository/kprog/results/native-ebpf-alignment-20261128/arm64-call-map-facts/after/entry_local.blob.bin"
 mov x0, x7
 mov x8, #93
 svc #0

.data
.balign 8
.global frozen_word
frozen_word: .word 17, 0
.global mutable_word
mutable_word: .word 34, 0
