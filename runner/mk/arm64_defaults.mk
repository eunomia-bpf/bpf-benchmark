REPO_ROOT ?= $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/../..)
RUNNER_DIR ?= $(REPO_ROOT)/runner

ARM64_AWS_CACHE_ROOT ?= $(REPO_ROOT)/.cache/aws-arm64
ARM64_AWS_BUILD_DIR ?= $(ARM64_AWS_CACHE_ROOT)/kernel-build
