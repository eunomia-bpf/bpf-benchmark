ROOT := /workspaces/repository
RAW := /workspaces/kprog-raw/perf/20261116-otel-regression
TMP := /var/tmp/kprog-tmp/perf/otel-regression

.PHONY: audit profile archive
audit:
	install -d $(RAW) $(TMP)
	python3 $(ROOT)/kprog/results/otel-regression-20261116/audit.py $(RAW) $(TMP) > $(RAW)/audit.log 2>&1

profile:
	flock -s /workspaces/.agent-state/kprog-lanes/locks/image \
		python3 $(ROOT)/kprog/perf/profile/phase-profile.py run --app otelcol-ebpf-profiler/profiling \
		--cpus 20-23 --vcpus 4 --memory 32G --seconds 60 --freq 199 \
		--state-root /var/tmp/kprog-tmp/perf/otel-regression-profile --persist-output --out $(RAW)/profile

archive:
	tar -cJf $(RAW)/stage-artifacts.tar.xz -C $(TMP) .

.PHONY: costs
costs:
	DEBUGINFOD_URLS= python3 $(ROOT)/kprog/results/otel-regression-20261116/costs.py $(RAW) > $(RAW)/costs.log 2>&1

.PHONY: pmu-preflight pmu-profile
pmu-preflight:
	/var/tmp/kprog-tmp/C/perf-build/perf stat -e cycles:G -- true > $(RAW)/pmu-preflight.log 2>&1

pmu-profile:
	DEBUGINFOD_URLS= flock -s /workspaces/.agent-state/kprog-lanes/locks/image \
		python3 $(ROOT)/kprog/perf/profile/phase-profile.py run --app otelcol-ebpf-profiler/profiling \
		--cpus 20-23 --vcpus 4 --memory 32G --seconds 60 --freq 199 --host-event cycles:G \
		--state-root /var/tmp/kprog-tmp/perf/otel-regression-profile --persist-output --out $(RAW)/profile

.PHONY: pmu-decode
pmu-decode:
	DEBUGINFOD_URLS= /var/tmp/kprog-tmp/C/perf-build/perf script -i $(RAW)/pmu/profile/host.data \
		--guestkallsyms $(RAW)/pmu/profile/baseline.start.kallsyms \
		-F time,misc,ip,pid,tid,cpu,period --no-inline --hide-call-graph --ns \
		> $(RAW)/pmu/samples.txt 2> $(RAW)/pmu/decode.stderr

.PHONY: pmu-costs
pmu-costs:
	python3 $(ROOT)/kprog/results/otel-regression-20261116/pmu.py $(RAW) > $(RAW)/pmu/costs.log 2>&1
