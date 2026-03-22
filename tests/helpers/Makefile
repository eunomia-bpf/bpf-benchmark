ROOT_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/../..)
HELPERS_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
BUILD_DIR ?= $(HELPERS_DIR)/build

LIBBPF_A ?= $(ROOT_DIR)/micro/build/vendor/libbpf/obj/libbpf.a
LIBBPF_PREFIX ?= $(ROOT_DIR)/micro/build/vendor/libbpf/prefix

.PHONY: all clean hold_bpf_prog

all: $(BUILD_DIR)/hold_bpf_prog

$(BUILD_DIR)/hold_bpf_prog: $(HELPERS_DIR)/hold_bpf_prog.c | $(BUILD_DIR)
	$(CC) -O2 -g -I$(LIBBPF_PREFIX)/include \
	    -o $@ $< $(LIBBPF_A) -lelf -lz -lzstd -lpthread

$(BUILD_DIR):
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR)
