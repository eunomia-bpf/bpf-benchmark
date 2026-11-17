# Diagnostic load-input capture; shared benchmark and guest recipes stay frozen.
include /workspaces/repository/kprog/perf/one-image/Makefile
CAPTURE_ADAPTER := $(ROOT)/corpus/results/current-link-capture-20261117/capture-link
.DEFAULT_GOAL := capture
.PHONY: capture
capture:
	install -d $(STATE)/var-tmp $(LOGS)
	ln -sfn $(IMAGE_TAR) $(STATE)/var-tmp/runtime.image.tar
	ln -sfn $(KINSN_OUT)/bpf_x86_native_lab.ko $(STATE)/var-tmp/bpf_x86_native_lab.ko
	$(MAKE) -C $(ROOT) kvm-host-cpu
	taskset -c $(CPUS) vng --run $(KDIR)/arch/x86/boot/bzImage --cwd $(ROOT) --rwdir $(ROOT) --rwdir /var/tmp=$(STATE)/var-tmp --overlay-rwdir /tmp --overlay-rwdir /run --overlay-rwdir /usr/local --disable-monitor $(VNG_FLAGS) --cpus $(VM_CPUS) --memory $(VM_MEM) --append 'loglevel=4 panic=30 oops=panic' --exec 'env BPFREJIT_NATIVE_LINK_BINARY=$(CAPTURE_ADAPTER) make -f $(HERE)/Makefile guest APPS=$(APPS) SAMPLES=$(SAMPLES) WORKLOAD_DURATION=$(WORKLOAD_DURATION) BPFREJIT_CORPUS_BPF_STATS=$(BPFREJIT_CORPUS_BPF_STATS) NATIVE_MANIFEST=$(NATIVE_MANIFEST) BENCH_PASSES=$(BENCH_PASSES) SKIP_REJIT_MODE=$(SKIP_REJIT_MODE) NATIVE_LOADER_MODE=$(NATIVE_LOADER_MODE)'
	rm -f $(STATE)/var-tmp/bpf-benchmark-docker.img
