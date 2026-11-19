ROOT := /workspaces/repository
KDIR := /workspaces/.agent-state/kprog-ck/build-x86
LOADER := /workspaces/.agent-state/kprog-ck/verified-loader/trusted-native-loader
COMPILER := /workspaces/.agent-state/kprog-ck/verified-compiler
GUEST_BUILD := /var/tmp/kprog-tmp/verified/lto-config

.PHONY: checked-timing analyze
checked-timing:
	install -d $(OUT) $(OUT)/loader-inputs $(OUT)/bounds-inputs $(GUEST_BUILD)
	$(MAKE) -C $(ROOT) kvm-host-cpu
	taskset -c 0-7 prlimit --as=103079215104 -- vng --run $(KDIR)/arch/x86/boot/bzImage \
		--cwd $(ROOT) --rwdir $(ROOT) --rwdir $(OUT) --rwdir /var/tmp=$(GUEST_BUILD) \
		--rodir $(OUT)/loader-inputs=$(dir $(LOADER)) --rodir $(OUT)/bounds-inputs=$(COMPILER) \
		--overlay-rwdir /tmp --overlay-rwdir /run --overlay-rwdir /usr/local \
		--disable-monitor --verbose --cpus 8 --memory 64G --append 'loglevel=4 panic=30 oops=panic' \
		--exec 'bash $(ROOT)/kprog/results/lto-config-20261119/run_lto.sh $(OUT) bcc/set $(OUT)/loader-inputs/$(notdir $(LOADER)) $(OUT)/bounds-inputs/packet-bounds 3 180 1'
	rm -f $(GUEST_BUILD)/bpf-benchmark-docker.img

analyze:
	install -d $(OUT)
	$(MAKE) -f $(ROOT)/kprog/results/native-cohort-check-20261119/Makefile summarize RAW=$(BATCH)/timing OUT=$(OUT)/coverage.json SOURCE_COMMIT=$(BATCH)/source-commit EXIT_FILE=$(BATCH)/exit-code RUN_LOG=$(BATCH)/timing.log
	python3 $(ROOT)/kprog/results/flag-tuning-20261117/may29_ratio.py off=$(RUN) on=$(RUN) > $(OUT)/timing-summary.txt
	python3 $(ROOT)/kprog/results/flag-tuning-20261117/inst.py $(RUN) > $(OUT)/installed.txt
	python3 $(ROOT)/kprog/results/checked-hash-ops-20261119/per_program.py $(RUN)/details/apps/bcc__set.json $(OUT)/per-program.json
