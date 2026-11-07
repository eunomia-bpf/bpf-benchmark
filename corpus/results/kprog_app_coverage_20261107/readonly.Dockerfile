FROM bpf-benchmark/kprog-corpus-base:c-20261107
COPY libnative_loader.so /usr/local/lib/bpfrejit/libnative_loader.so
COPY capture-python /usr/local/bin/kprog-capture-python
