REPO_ROOT ?= $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/../..)
RUNNER_DIR ?= $(REPO_ROOT)/runner

CROSS_COMPILE_ARM64 ?= aarch64-linux-gnu-
DOCKER ?= docker

ARM64_WORKTREE_DIR ?= $(REPO_ROOT)/.worktrees/linux-framework-arm64-src
ARM64_HOST_CACHE_ROOT ?= $(REPO_ROOT)/.cache/arm64-host
ARM64_AWS_CACHE_ROOT ?= $(REPO_ROOT)/.cache/aws-arm64
ARM64_AWS_BUILD_DIR ?= $(ARM64_AWS_CACHE_ROOT)/kernel-build
ARM64_AWS_BASE_CONFIG ?=

ARM64_CROSSBUILD_DOCKERFILE ?= $(RUNNER_DIR)/docker/arm64-crossbuild.Dockerfile
ARM64_CROSSBUILD_CONTEXT ?= $(RUNNER_DIR)/docker
ARM64_CROSSBUILD_IMAGE ?= bpf-benchmark-arm64-crossbuild:latest
ARM64_CROSSBUILD_STAMP ?= $(REPO_ROOT)/.cache/arm64-crossbuild-image.stamp
ARM64_CROSSBUILD_LOCK ?= $(REPO_ROOT)/.cache/arm64-crossbuild-image.lock
ARM64_DOCKER_PLATFORM ?= linux/arm64
ARM64_CROSSBUILD_JOBS ?= 4
ARM64_CROSSBUILD_ENABLE_LLVMBPF ?= OFF
ARM64_HOST_RUNNER_BUILD_DIR ?= $(ARM64_HOST_CACHE_ROOT)/runner-host-cross/build
ARM64_HOST_RUNNER_OUTPUT_DIR ?= $(ARM64_HOST_CACHE_ROOT)/runner-host-cross/output
ARM64_HOST_RUNNER_BINARY ?= $(ARM64_HOST_RUNNER_OUTPUT_DIR)/micro_exec
