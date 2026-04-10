REPO_ROOT ?= $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/../..)
RUNNER_DIR ?= $(REPO_ROOT)/runner

ARM64_AWS_CACHE_ROOT ?= $(REPO_ROOT)/.cache/aws-arm64
ARM64_AWS_BUILD_DIR ?= $(ARM64_AWS_CACHE_ROOT)/kernel-build
ARM64_AWS_BASE_CONFIG ?= $(ARM64_AWS_CACHE_ROOT)/config-al2023-arm64
