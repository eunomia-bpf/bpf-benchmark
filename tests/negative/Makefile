ROOT_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/../..)
NEGATIVE_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
BUILD_DIR ?= $(NEGATIVE_DIR)/build

CC ?= cc
CFLAGS ?= -O2 -g -Wall -Wno-\#warnings
# Use -I (not -isystem) so vendor REJIT headers override system linux/bpf.h
INCLUDES := -I$(ROOT_DIR)/vendor/linux-framework/include/uapi

TESTS := fuzz_rejit adversarial_rejit scx_bad_rejit_replay

.PHONY: all clean run

all: $(addprefix $(BUILD_DIR)/,$(TESTS))

$(BUILD_DIR)/%: $(NEGATIVE_DIR)/%.c $(NEGATIVE_DIR)/common.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $< -lpthread

$(BUILD_DIR):
	mkdir -p $@

run: all
	@echo ""
	@echo "=== Running adversarial_rejit ==="
	$(BUILD_DIR)/adversarial_rejit
	@echo ""
	@echo "=== Running fuzz_rejit (1000 rounds) ==="
	$(BUILD_DIR)/fuzz_rejit 1000

clean:
	rm -rf $(BUILD_DIR)
