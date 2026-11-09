SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c
HERE := /workspaces/repository/corpus/results/kprog_app_coverage_20261109/map-lookup-native/tetragon
.PHONY: prepare build
prepare:
	PYTHONDONTWRITEBYTECODE=1 python3 -B $(HERE)/producer.py prepare
build:
	unshare --mount --propagation private python3 -B $(HERE)/producer.py build
