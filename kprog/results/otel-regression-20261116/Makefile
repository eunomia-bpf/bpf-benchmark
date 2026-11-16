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
