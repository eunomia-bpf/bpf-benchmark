ROOT_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/../..)
UNITTEST_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
BUILD_DIR ?= $(UNITTEST_DIR)/build

CC ?= cc
CFLAGS ?= -O2 -g -Wall -Wno-\#warnings
INCLUDES := -isystem $(ROOT_DIR)/vendor/linux-framework/include/uapi

TESTS := rejit_poc rejit_safety_tests rejit_prog_types \
         rejit_regression rejit_tail_call rejit_spectre

BPF_PROGS_DIR := $(UNITTEST_DIR)/progs
BPF_SRCS := $(wildcard $(BPF_PROGS_DIR)/*.bpf.c)
BPF_OBJS := $(patsubst $(BPF_PROGS_DIR)/%.bpf.c,$(BUILD_DIR)/progs/%.bpf.o,$(BPF_SRCS))

.PHONY: all clean run tests

all: $(addprefix $(BUILD_DIR)/,$(TESTS)) $(BPF_OBJS)

$(BUILD_DIR)/%: $(UNITTEST_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $< -lpthread

$(BUILD_DIR)/progs/%.bpf.o: $(BPF_PROGS_DIR)/%.bpf.c | $(BUILD_DIR)/progs
	clang -O2 -g --target=bpf $(INCLUDES) -c $< -o $@

$(BUILD_DIR) $(BUILD_DIR)/progs:
	mkdir -p $@

run: all
	@for t in $(TESTS); do \
	    echo "=== $$t ==="; \
	    sudo $(BUILD_DIR)/$$t || exit 1; \
	done

clean:
	rm -rf $(BUILD_DIR)
