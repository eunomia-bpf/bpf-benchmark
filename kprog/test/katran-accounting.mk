SHELL := /bin/bash
.SHELLFLAGS := -eu -o pipefail -c
ROOT := /workspaces/repository
OUTPUT ?= /workspaces/kprog-raw/perf/20261114-katran-c4-accounting

.PHONY: comparison-analysis
comparison-analysis:
	taskset -c 16 prlimit --as=2147483648 -- python3 $(ROOT)/kprog/results/perf_20261113/katran_compare_analysis.py $(COMPARISON_RUNS) --output $(OUTPUT)/comparison.json

.PHONY: analyze
analyze:
	taskset -c 19 prlimit --as=4294967296 -- python3 $(ROOT)/kprog/results/perf_20261113/katran_counter_accounting.py --run $(ROOT)/corpus/results/x86_kvm_corpus_20261114_012718_572545 --profile-run $(ROOT)/corpus/results/x86_kvm_corpus_20261114_183513_065331 --profile-capture /workspaces/kprog-raw/C/limits/katran --output $(OUTPUT)

.PHONY: reference-jit-audit
reference-jit-audit:
	taskset -c 8-11 prlimit --as=4294967296 -- python3 $(ROOT)/kprog/test/audit_native_helper_sites.py --native $(ROOT)/corpus/results/katran-c-hdr-20261115/objects/balancer.native.o --symbol balancer_ingress --linker /workspaces/kprog-raw/paper-tree-untracked/native-sim/x86/native_lab/native_link/target/release/native-link --link-plan /workspaces/kprog-raw/perf/20261115-word-hash-lto/timing/ab/post_rejit-27aee6c02466/35d7f2355be09ef4.tmp.3020.link-plan.json --jit-capture /workspaces/kprog-raw/C/limits/katran/post_rejit.jit-lines.json --jit-program 16 --output $(OUTPUT)

.PHONY: reference-lru-profile
reference-lru-profile:
	taskset -c 8-11 prlimit --as=4294967296 -- python3 $(ROOT)/kprog/test/katran_reference_profile.py --capture /workspaces/kprog-raw/C/limits/katran --match /workspaces/kprog-raw/perf/20261116-reference-lru-profile/match --perf /var/tmp/kprog-tmp/C/perf-build/perf --output $(OUTPUT)

REFERENCE_COMPARISON_ARGS ?=
.PHONY: reference-comparison
reference-comparison:
	prlimit --as=103079215104 -- bash $(ROOT)/kprog/test/run_katran_reference_comparison.sh $(REFERENCE_COMPARISON_ARGS)

.PHONY: rotate-after-pair
rotate-after-pair:
	prlimit --as=103079215104 -- bash -eu -o pipefail -c 'tail --pid="$(PAIR_PID)" -f /dev/null; cat "$(PAIR_OUTPUT)/current-rebuilt"; exec flock -x /workspaces/.agent-state/kprog-lanes/locks/timing flock -s /workspaces/.agent-state/kprog-lanes/locks/image make -f $(ROOT)/kprog/perf/one-image/Makefile rotate'

.PHONY: rerun-after-pair
rerun-after-pair:
	prlimit --as=103079215104 -- bash -eu -o pipefail -c 'tail --pid="$(PAIR_PID)" -f /dev/null; cat "$(PAIR_OUTPUT)/current-rebuilt"; exec env KPROG_KATRAN_REFERENCE_OUTPUT="$(RERUN_OUTPUT)" make -r -f $(ROOT)/kprog/test/katran-accounting.mk reference-comparison'
