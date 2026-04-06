ROOT_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
BUILD_DIR := $(ROOT_DIR)/build
PROGRAM_OUTPUT_DIR ?= $(ROOT_DIR)/programs

.PHONY: all programs clean

all: programs

programs:
	$(MAKE) -C $(ROOT_DIR)/programs OUTPUT_DIR="$(PROGRAM_OUTPUT_DIR)"

clean:
	$(MAKE) -C $(ROOT_DIR)/programs OUTPUT_DIR="$(PROGRAM_OUTPUT_DIR)" clean
	rm -f $(ROOT_DIR)/generated-inputs/*.mem
	@if [ -d "$(ROOT_DIR)/results/dev" ]; then \
		find "$(ROOT_DIR)/results/dev" -maxdepth 1 -type f ! -name '.gitkeep' -delete; \
	fi
	rm -rf $(ROOT_DIR)/__pycache__
	rm -rf "$(BUILD_DIR)"
