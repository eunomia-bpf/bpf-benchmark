# syntax=docker/dockerfile:1.6
FROM bpf-benchmark/runner-runtime:x86_64
COPY libnative_loader.so /usr/local/lib/bpfrejit/libnative_loader.so
COPY libbpfrejit_shim.so /usr/local/lib/bpfrejit/libbpfrejit_shim.so
COPY native-link /usr/local/bin/native-link
RUN rm -rf /artifacts/kinsn /artifacts/lib/modules
COPY kinsn/ /artifacts/kinsn/
COPY modules/ /artifacts/lib/modules/
COPY kernel/ /artifacts/kernel/
COPY manifest.json /artifacts/manifest.json
RUN depmod -b /artifacts "$(python3 -c 'import json; print(json.load(open("/artifacts/manifest.json"))["kernel_release"])')"
COPY native-bpf/ /artifacts/user/native-bpf/x86_64/
COPY code/ /workspaces/repository/
