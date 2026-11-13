ROOT := /workspaces/repository
OUT := $(ROOT)/kprog/results/equal-work-20261113
$(OUT)/eqcodex-jit: $(OUT)/eqcodex-jit.c
	$(CC) -O2 -Wall -Wextra -Werror $< -lbpf -o $@
