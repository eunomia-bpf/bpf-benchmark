# SPDX-License-Identifier: GPL-2.0

OUTPUT_DIR ?= build
CROSS_COMPILE ?= aarch64-linux-gnu-
AARCH64_AS ?= $(CROSS_COMPILE)as
AARCH64_OBJCOPY ?= $(CROSS_COMPILE)objcopy

BLOB := $(OUTPUT_DIR)/arm64_native_kernel_xdp_result.blob

.PHONY: all clean

all: $(BLOB)

$(OUTPUT_DIR):
	install -d "$@"

$(OUTPUT_DIR)/xdp_result.o: xdp_result.S | $(OUTPUT_DIR)
	$(AARCH64_AS) -o "$@" "$<"

$(BLOB): $(OUTPUT_DIR)/xdp_result.o
	$(AARCH64_OBJCOPY) -O binary -j .text "$<" "$@"

clean:
	rm -f "$(OUTPUT_DIR)/xdp_result.o" "$(BLOB)"
