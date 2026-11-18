ROOT := kprog/results/helper-arguments-20261118
CC := clang
DEFINES ?=
FLAGS := -O3 -g -fPIC -fomit-frame-pointer -march=native -mno-red-zone -mgeneral-regs-only -fno-stack-protector -fno-asynchronous-unwind-tables -fno-unwind-tables -Wall -Wextra -Werror -Wno-unused-function -Wno-unused-variable -I.
.PHONY: run
run:
	$(CC) $(FLAGS) $(DEFINES) -DACTUAL_IR -S -emit-llvm $(ROOT)/fixture.c -o $(OUT)/actual.ll > $(OUT)/ir-build.txt 2>&1
	$(CC) $(FLAGS) $(DEFINES) $(ROOT)/fixture.c -o $(OUT)/fixture > $(OUT)/host-build.txt 2>&1
	python3 $(ROOT)/execute.py $(OUT)
