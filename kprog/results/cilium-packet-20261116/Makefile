ROOT := /workspaces/repository
HERE := $(ROOT)/kprog/results/cilium-packet-20261116
RAW := /workspaces/kprog-raw/perf/20261116-cilium-packet
STATE := /var/tmp/kprog-tmp/perf/cilium-packet

.PHONY: prepare run
prepare:
	install -d $(STATE) $(RAW)
	cc -I$(ROOT)/vendor/linux-framework/include/uapi -I$(ROOT)/vendor/linux-framework/arch/x86/include/uapi -I/workspaces/.agent-state/kprog-ck/build-x86/arch/x86/include/generated/uapi $(HERE)/layout.c -o $(STATE)/layout
	$(STATE)/layout > $(HERE)/layout.json
	python3 -c 'import ast,pathlib; [ast.parse(p.read_text()) for p in pathlib.Path("$(HERE)").glob("*.py")]'

run:
	DEBUGINFOD_URLS= flock -s /workspaces/.agent-state/kprog-lanes/locks/image python3 $(HERE)/profile.py run --app cilium/agent --cpus 20-23 --vcpus 4 --memory 32G --seconds 60 --freq 199 --host-event cycles:G --state-root $(STATE)/guest --persist-output --out $(RAW)/run
