FROM bpf-benchmark/kprog-map-capture:c-20261107
RUN rm -f /artifacts/user/native-bpf/x86_64/katran/balancer.proof.o /artifacts/user/native-bpf/x86_64/katran/balancer.*.proof.o /artifacts/user/native-bpf/x86_64/tetragon/bpf_generic_kprobe_v61.proof.o /artifacts/user/native-bpf/x86_64/tetragon/bpf_generic_kprobe_v61.*.proof.o
COPY katran/ /artifacts/user/native-bpf/x86_64/katran/
COPY tetragon/ /artifacts/user/native-bpf/x86_64/tetragon/
