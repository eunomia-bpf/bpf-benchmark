ROOT_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/..)
DAEMON_DIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))

TARGET_DIR ?= $(DAEMON_DIR)/target
CARGO ?= cargo
TARGET_TRIPLE ?=

.PHONY: release clean

release:
	$(CARGO) build --release $(if $(TARGET_TRIPLE),--target "$(TARGET_TRIPLE)",) --target-dir "$(TARGET_DIR)" --manifest-path "$(DAEMON_DIR)/Cargo.toml"

clean:
	$(CARGO) clean --manifest-path "$(DAEMON_DIR)/Cargo.toml"
