ROOT := kprog/results/lpm-body-20261118
OUT ?= /workspaces/kprog-raw/perf/lpm-body-20261118/current
.PHONY: run
run:
	python3 $(ROOT)/prepare.py --output $(OUT)
	$(CC) -O2 -Wall -Wextra -Werror -I$(OUT) $(ROOT)/driver.c -o $(OUT)/driver
	$(OUT)/driver $(OUT)/kernel-host.bin $(OUT)/native-host.bin > $(OUT)/samples.csv
