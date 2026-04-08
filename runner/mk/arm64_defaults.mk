REPO_ROOT ?= $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/../..)
RUNNER_DIR ?= $(REPO_ROOT)/runner

CROSS_COMPILE_ARM64 ?= aarch64-linux-gnu-

ARM64_WORKTREE_DIR ?= $(REPO_ROOT)/.worktrees/linux-framework-arm64-src
ARM64_AWS_CACHE_ROOT ?= $(REPO_ROOT)/.cache/aws-arm64
ARM64_AWS_BUILD_DIR ?= $(ARM64_AWS_CACHE_ROOT)/kernel-build
ARM64_AWS_BASE_CONFIG ?=

ARM64_DOCKER_PLATFORM ?= linux/arm64
ARM64_CROSSBUILD_JOBS ?= 4
