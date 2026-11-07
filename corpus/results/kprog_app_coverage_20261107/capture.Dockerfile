FROM bpf-benchmark/kprog-tail-frame:c-20261107
COPY capture-python /usr/local/bin/kprog-capture-python
ENTRYPOINT ["/usr/local/bin/kprog-capture-python"]
