ROOT := /workspaces/repository
BASE := /workspaces/.agent-state/kprog-ck
INPUTS := /var/tmp/kprog-tmp/perf/kernel-probe-live
NATIVE_FLAGS := -O3 -march=native -Xclang -fembed-bitcode=all -fPIC -mno-red-zone -mgeneral-regs-only -fomit-frame-pointer -fno-stack-protector -fno-asynchronous-unwind-tables -fno-unwind-tables

.PHONY: programs run guest
programs:
	install -d $(INPUTS)
	clang-18 $(NATIVE_FLAGS) -c $(ROOT)/kprog/test/trusted_native.c -o $(INPUTS)/control.o
	set -e; for n in 0 1 2 3 4 5 6 7 8 9 10 11; do \
		clang-18 $(NATIVE_FLAGS) -DPROBE_CASE=$$n -c $(ROOT)/kprog/results/kernel-probe-live-20261120/program.c -o $(INPUTS)/case-$$n.o; \
	done

run:
	install -d $(OUT) $(OUT)/program-inputs
	git -C $(ROOT) rev-parse HEAD > $(OUT)/source-commit
	tar -C $(INPUTS) -czf $(OUT)/native-inputs.tar.gz .
	date -u +%FT%TZ > $(OUT)/started
	status=0; flock -s /workspaces/.agent-state/kprog-lanes/locks/image \
		taskset -c 16-17 prlimit --as=17179869184 -- vng \
		--run $(BASE)/build-x86/arch/x86/boot/bzImage \
		--cwd $(ROOT) --rwdir $(ROOT) --rwdir $(OUT) --rodir $(OUT)/program-inputs=$(INPUTS) \
		--overlay-rwdir /tmp --disable-monitor --cpus 2 --memory 4G \
		--append 'loglevel=4 panic=30 oops=panic' \
		--exec 'make -f kprog/results/kernel-probe-live-20261120/Makefile guest OUT=$(OUT)' || status=$$?; \
		printf '%s\n' "$$status" > $(OUT)/exit-code; date -u +%FT%TZ > $(OUT)/finished; exit $$status

guest:
	CLANG=$(ROOT)/kprog/stock-path/bin/clang BPFREJIT_NATIVE_LINK_BINARY=$(ROOT)/kprog/x86/native_lab/native_link/target/release/native-link python3 $(ROOT)/kprog/results/kernel-probe-live-20261120/guest.py $(OUT)

.PHONY: receipt
receipt:
	cp $(OUT)/cases.json $(ROOT)/kprog/results/kernel-probe-live-20261120/$(NAME)-cases.json
	tar -C $(dir $(OUT)) -czf $(ROOT)/kprog/results/kernel-probe-live-20261120/$(NAME)-evidence.tar.gz $(notdir $(OUT))

.PHONY: summary
summary:
	python3 $(ROOT)/kprog/results/kernel-probe-live-20261120/summarize.py $(OUT)
