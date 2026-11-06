ROOT := $(abspath ../../../../..)
SNAPSHOT := $(ROOT)/kprog/fidelity/build-x86/reference-extend-snapshot
.PHONY: replay
replay:
	cp ../arm64-sp-reference/cpu-states.bin cpu-states.bin
	cp ../arm64-sp-reference/forms.tsv forms.tsv
	cp ../arm64-sp-reference/native-code.json native-code.json
	python3 -c "import sys; from pathlib import Path; sys.path.insert(0,'$(SNAPSHOT)'); import reference_check as r; r.ROOT=Path('$(SNAPSHOT)'); sys.argv=['reference_check.py','--reuse-trace','--binary','$(ROOT)/kprog/fidelity/build-arm64-sp-observer/cpu-differential','--arch','arm64','--cases','1024','--out','.']; raise SystemExit(r.main())"
