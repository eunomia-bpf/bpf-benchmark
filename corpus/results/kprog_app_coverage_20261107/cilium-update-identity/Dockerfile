FROM bpf-benchmark/kprog-cilium-identity-base:c-20261107
COPY libnative_loader.so /usr/local/lib/bpfrejit/libnative_loader.so
COPY native-link /usr/local/bin/native-link
COPY --chmod=0755 capture /usr/local/bin/cilium-identity-capture
ENTRYPOINT ["/usr/local/bin/cilium-identity-capture"]
