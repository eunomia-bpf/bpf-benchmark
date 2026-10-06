# New App Integration Review 2026-04-25

## Scope

Reviewed these app integrations:

- `suricata`
- `loxilb`
- `otelcol-ebpf-profiler`
- `cilium`
- `calico`

Ran:

- `make vm-e2e`
- `make vm-corpus`

No commit was made.

## Findings

### Fixed during review

1. `suricata/xdp-filter` and `suricata/xdp-lb` were not actually distinct runtime integrations.
   Fix:
   - `runner/libs/app_runners/suricata.py`
     - made the runner mode-aware
     - resolved packaged config + eBPF asset paths
     - auto-detected the benchmark interface
     - generated a runtime overlay so the real `suricata` binary loads its own XDP program
     - used `xdp-mode: soft` on the synthetic benchmark veth
   - `runner/libs/benchmark_catalog.py`
     - `suricata/xdp-filter` now passes `mode: xdp-filter`
     - `suricata/xdp-lb` now passes `mode: xdp-lb`

2. `cilium/default` needed a real isolated runtime state/BPF root instead of the earlier broken setup.
   Fix:
   - `runner/libs/app_runners/cilium.py`
     - switched to `EtcdBackedNativeRunner`
     - added runtime `--bpf-root` and `--state-dir`
     - set `--ipv4-native-routing-cidr`
     - removed the bad `--lib-dir` override that broke upstream templates

3. `calico/felix` initially booted and attached BPF programs, but failed in the VM on `iptables-legacy-save`.
   Fix:
   - `runner/libs/app_runners/calico.py`
     - added netfilter module/table priming before `calico-node -startup`
     - switched Felix to nftables backend with:
       - `FELIX_IPTABLESBACKEND=NFT`
       - `FELIX_NFTABLESMODE=Enabled`
     - kept `FELIX_GenericXDPEnabled=true` on the synthetic benchmark veth

4. `tracee/default` in corpus regressed because the runner no longer excluded the known-bad `syscall__init_module` live ReJIT target.
   Fix:
   - `runner/libs/app_runners/tracee.py`
     - restored `live_rejit_programs()` filtering for `syscall__init_module`

5. etcd-backed runners were vulnerable to VM tempdir / 9p filesystem behavior.
   Fix:
   - `runner/libs/app_runners/etcd_support.py`
     - added synthetic benchmark veth fallback
     - fixed LocalEtcdSession error reporting
     - moved etcd runtime tempdir selection away from the shared runtime tmp root

6. Runtime image setup was incomplete for some recovered apps.
   Fix:
   - `runner/containers/runner-runtime.Dockerfile`
     - changed `loxilb` install from `dpkg -i` to `dpkg-deb -x`
     - removed `sudo` from `mkllb_bpffs`
     - added `ipset`, `iptables`, `nftables`
     - copied `/usr/lib/calico/bpf/` from the upstream Calico image

### Review checks

#### 1. Loader mode audit

All reviewed runners launch the real upstream/native app binary and let the app load BPF itself.

Confirmed no runner-side use of:

- `bpf_object_open`
- `bpftool prog load`
- direct `.bpf.o` loading

Known exception remains external to this review: Katran `xdp_root`.

#### 2. Registration completeness

Confirmed all reviewed apps are registered in:

- `runner/libs/app_runners/__init__.py`
- `runner/libs/benchmark_catalog.py`
- `corpus/config/macro_apps.yaml`

#### 3. Runner code quality

Confirmed for reviewed runners:

- start/stop paths are implemented
- binary lookup paths are reasonable
- no references to deleted dependencies were found
- `python3 -m py_compile` passed

Checked files:

- `runner/libs/app_runners/__init__.py`
- `runner/libs/app_runners/suricata.py`
- `runner/libs/app_runners/loxilb.py`
- `runner/libs/app_runners/otel_profiler.py`
- `runner/libs/app_runners/cilium.py`
- `runner/libs/app_runners/calico.py`
- `runner/libs/app_runners/tracee.py`
- `runner/libs/app_runners/etcd_support.py`
- `runner/libs/benchmark_catalog.py`

#### 4. Dockerfile audit

`runner/containers/runner-runtime.Dockerfile` contains install/runtime setup for:

- `suricata`
- `loxilb`
- `otelcol-ebpf-profiler`
- `cilium`
- `calico`

Architecture coverage:

- `otelcol-ebpf-profiler`: explicit `amd64` and `arm64`
- `cilium`: upstream image copied with `TARGETPLATFORM`
- `calico`: upstream image copied with `TARGETPLATFORM`
- `suricata`: distro package in runtime image
- `loxilb`: still `amd64` only

#### 5. Disallowed logic audit

Confirmed absent in the reviewed app integration path:

- `LifecycleAbort`
- runner-side `skip` / `exclude` logic
- `scx` references
- object-level BPF loader logic

#### 6. `macro_apps.yaml` count

- Total entries: `31`

## Remaining notes

1. `loxilb` is still only installed for `amd64` in `runner/containers/runner-runtime.Dockerfile`.

2. `suricata` now uses the correct app-loader pattern, but the packaged upstream eBPF assets in the runtime image still fail on this VM with:
   - `libbpf: elf: legacy map definitions in 'maps' section are not supported by libbpf v1.0+`
   This is no longer a runner wiring issue; it is an upstream userspace/asset compatibility issue.

3. `systemd/*` remains missing from the VM/runtime image and still fails in the full corpus.
   Those failures are outside the five reviewed app integrations.

## Validation Runs

### Targeted checks used while fixing

- `make vm-corpus VM_CORPUS_SUITE_ARGS='--samples "1" --suite "docs/tmp/new-app-integration-review-20260425/tracee-only.yaml"'`
  - result: `ok`
  - artifact: `corpus/results/x86_kvm_corpus_20260426_040053_741268`
  - log: `docs/tmp/new-app-integration-review-20260425/tracee-only.log`

- `make vm-corpus VM_CORPUS_SUITE_ARGS='--samples "1" --suite "docs/tmp/new-app-integration-review-20260425/calico-only.yaml"'`
  - result: `ok`
  - artifact: `corpus/results/x86_kvm_corpus_20260426_040948_351469`
  - log: `docs/tmp/new-app-integration-review-20260425/calico-only.log`

### Final `make vm-e2e`

- Result: `PASS`
- Log: `docs/tmp/new-app-integration-review-20260425/vm-e2e.log`
- Guest run ended with `e2e: ALL PASSED`

Required existing apps all passed in e2e:

- `tracee`
- `tetragon`
- `bpftrace`
- `bcc`
- `katran`

### Final `make vm-corpus`

- Command: `make vm-corpus`
- Result: `ERROR` at suite level
- Log: `docs/tmp/new-app-integration-review-20260425/vm-corpus.log`
- Final artifact: `corpus/results/x86_kvm_corpus_20260426_041620_440166`

Per-app outcome summary:

- `bcc/capable`: `ok`
- `bcc/execsnoop`: `ok`
- `bcc/bindsnoop`: `ok`
- `bcc/biosnoop`: `ok`
- `bcc/vfsstat`: `ok`
- `bcc/opensnoop`: `ok`
- `bcc/syscount`: `ok`
- `bcc/tcpconnect`: `ok`
- `bcc/tcplife`: `ok`
- `bcc/runqlat`: `ok`
- `calico/felix`: `ok`
- `suricata/xdp-filter`: `error`
- `suricata/xdp-lb`: `error`
- `systemd/bind-iface`: `error`
- `systemd/restrict-ifaces`: `error`
- `systemd/socket-bind`: `error`
- `systemd/restrict-fs`: `error`
- `systemd/sysctl-monitor`: `error`
- `systemd/userns-restrict`: `error`
- `loxilb/default`: `ok`
- `otelcol-ebpf-profiler/default`: `ok`
- `cilium/default`: `ok`
- `tetragon/default`: `ok`
- `katran`: `ok`
- `tracee/default`: `ok`
- `bpftrace/capable`: `ok`
- `bpftrace/biosnoop`: `ok`
- `bpftrace/vfsstat`: `ok`
- `bpftrace/runqlat`: `ok`
- `bpftrace/tcplife`: `ok`
- `bpftrace/tcpretrans`: `ok`

Existing five-app requirement in final corpus:

- `tracee/default`: `ok`
- `tetragon/default`: `ok`
- `bpftrace/*`: all reviewed corpus entries `ok`
- `bcc/*`: all reviewed corpus entries `ok`
- `katran`: `ok`

Reviewed new-app outcome in final corpus:

- `calico/felix`: `ok`
- `loxilb/default`: `ok`
- `otelcol-ebpf-profiler/default`: `ok`
- `cilium/default`: `ok`
- `suricata/xdp-filter`: `error` due upstream eBPF asset/libbpf incompatibility
- `suricata/xdp-lb`: `error` due upstream eBPF asset/libbpf incompatibility

## Conclusion

Review is complete.

Final state after fixes:

- loader mode is correct for all reviewed app runners
- registration is complete
- code compiles
- runtime image coverage is in place, with `loxilb` still `amd64`-only
- final `make vm-e2e` passed
- final `make vm-corpus` completed and produced results
- all previously required legacy apps passed in the final corpus run
- remaining corpus errors are:
  - `suricata` upstream packaged eBPF asset incompatibility
  - pre-existing `systemd/*` binary absence in the VM image
