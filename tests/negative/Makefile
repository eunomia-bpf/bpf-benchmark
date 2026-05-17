ROOT_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/../..)
NEGATIVE_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
BUILD_DIR ?= $(NEGATIVE_DIR)/build

CC ?= cc
CFLAGS ?= -O2 -g -Wall -Wno-cpp
INCLUDES := -I$(ROOT_DIR)/vendor/linux-framework/include/uapi

TESTS :=

.PHONY: all clean run

all: $(addprefix $(BUILD_DIR)/,$(TESTS))

$(BUILD_DIR)/%: $(NEGATIVE_DIR)/%.c $(NEGATIVE_DIR)/common.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $< -lpthread

$(BUILD_DIR):
	mkdir -p $@

run: all
	@:

clean:
	rm -rf $(BUILD_DIR)
