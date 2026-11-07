ROOT := $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/../../../..)
HERE := $(ROOT)/corpus/results/kprog_arm64_app_coverage_20261107/tetragon-mixed-probe
.PHONY: build
build:
	PYTHONDONTWRITEBYTECODE=1 taskset -c 20-23 python3 $(HERE)/prepare.py
