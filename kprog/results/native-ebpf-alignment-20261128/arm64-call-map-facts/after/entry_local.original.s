.text
.global _start
_start:
 bl entry_local
 mov x8, #93
 svc #0

.data
.balign 8
.global frozen_word
frozen_word: .word 17, 0
.global mutable_word
mutable_word: .word 34, 0
