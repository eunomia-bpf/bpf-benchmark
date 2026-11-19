ROOT := /workspaces/repository
SOURCE_COMMIT ?= $(RAW)/source-commit
EXIT_FILE ?= $(RAW)/host-exit-code
RUN_LOG ?= $(RAW)/run.log
.PHONY: summarize
summarize:
	python3 $(ROOT)/kprog/results/native-cohort-check-20261119/summarize.py $(RAW) $(OUT) $(SOURCE_COMMIT) $(EXIT_FILE) $(RUN_LOG)
