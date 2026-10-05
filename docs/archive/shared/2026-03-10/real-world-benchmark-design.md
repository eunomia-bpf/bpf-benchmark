# Real-World eBPF Benchmark Design

## Scope and hard constraints

This document designs a practical expansion from the current 62 XDP-only synthetic micro-benchmarks to a kernel-only real-world benchmark suite for the BPF JIT backend paper.

The non-negotiable constraint is that every benchmark in the runnable suite must execute through `bpf_prog_test_run`, not through live attachment and not through `llvmbpf`.

The first consequence is that the suite cannot simply mirror "interesting production eBPF programs". It must be filtered by what the kernel can honestly execute through `test_run` in this tree.

### Verified `bpf_prog_test_run` support in this tree

The support matrix below was checked in the local kernel tree under:

- `vendor/linux-baseline/net/bpf/test_run.c`
- `vendor/linux-baseline/net/core/filter.c`
- `vendor/linux-baseline/kernel/trace/bpf_trace.c`
- `vendor/linux-baseline/kernel/bpf/bpf_struct_ops.c`
- `vendor/linux-baseline/net/bpf/bpf_dummy_struct_ops.c`

| Program type | `test_run` status | Repeat support | Practical note |
| --- | --- | --- | --- |
| `xdp` | supported | kernel repeat | best immediate fit |
| `sched_cls` / `sched_act` (`tc`) | supported | kernel repeat | best immediate non-XDP fit |
| `cgroup_skb` | supported | kernel repeat | good breadth with small runner changes |
| `raw_tracepoint` | supported | no kernel repeat | only `ctx_in`; usable for harnesses, weak for production tracing |
| `tracing` (`fentry`, `fexit`, `fmod_ret`, `fsession`) | supported | no generic repeat path | `test_run` calls fixed kernel test functions like `bpf_fentry_test1..10`, not arbitrary attach targets |
| `flow_dissector` | supported | kernel repeat | viable stretch type if we add a dedicated exec mode |
| `sk_lookup` | supported | kernel repeat | viable stretch type if we add a dedicated ctx fixture |
| `tracepoint` | not supported | n/a | cannot be part of the runnable suite under current constraint |
| `kprobe` | not supported | n/a | cannot be part of the runnable suite under current constraint |
| `perf_event` | not supported | n/a | cannot be part of the runnable suite under current constraint |
| `lsm` | not supported | n/a | cannot be part of the runnable suite under current constraint |
| `struct_ops` | test-run exists, but dummy-oriented | not practical | not a faithful path for real TCP CC programs like `bpf_cubic` |

Two important corrections fall out of this:

- Arbitrary production `fentry` programs from BCC or Tetragon are not honest `test_run` benchmarks in this tree, because `bpf_prog_test_run_tracing()` only exercises fixed kernel test functions, not the program's real attach target.
- Real `struct_ops` TCP CC programs should not be presented as ready-to-run paper benchmarks here; the current tree's test path is not a real datapath replay.

## 1. Candidate program catalog

### 1.1 Immediate runnable candidates

These are the programs that are either already runnable with the current helper binary, or require only bounded framework work that is clearly worth doing.

| Candidate | Object / source | Program(s) | Type | Domain | Complexity | Standalone `.bpf.o` | `test_run` fit | Minimal fixture | Priority |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Katran balancer | `corpus/build/katran/balancer.bpf.o` / `corpus/repos/katran/katran/lib/bpf/balancer.bpf.c` | `balancer_ingress` | XDP | networking, L4 LB | high: 2322 entry insns, 17 maps | yes | yes; verified load+run with current runner | IPv4/TCP VIP packet plus `vip_map`, `ch_rings`, `reals`, `stats` profile | P0 |
| Katran healthchecking | `corpus/build/katran/healthchecking.bpf.o` / `corpus/repos/katran/katran/lib/bpf/healthchecking.bpf.c` | `healthcheck_encap` | TC | networking, health-check encapsulation | medium: 325 insns, 7 maps | yes | yes; verified load+run, but meaningful path wants `__sk_buff.mark` or dst-match maps | IPv4 packet plus `hc_reals_map`, `hc_ctrl_map`, `hc_pckt_macs`, optional `skb.mark` | P1 |
| Suricata XDP filter | `corpus/build/suricata/xdp_filter.bpf.o` | `xdp_hashfilter` | XDP | security, packet filtering | medium: 334 insns, 7 maps | yes, object exists locally | yes; verified load+run | IPv4 packet plus `cpus_count`, `cpus_available`, optional flow-table seeds | P0 |
| Suricata XDP LB | `corpus/build/suricata/xdp_lb.bpf.o` | `xdp_loadfilter` | XDP | networking, load distribution | medium: 410 insns, 3 maps | yes, object exists locally | yes; verified load+run | IPv4 packet plus `cpus_count`, `cpus_available`, optional `cpu_map` seeds | P0 |
| xdp-tools forward | `corpus/build/xdp-tools/xdp_forward.bpf.o` / upstream `xdp-forward` | `xdp_fwd_fib_direct`, `xdp_fwd_fib_full` | XDP | networking, forwarding | small-medium: 151 insns, 1 map | yes | yes; verified load+run | IPv4 packet, optional `xdp_md.ingress_ifindex`, optional `xdp_tx_ports` map seeds | P0 control |
| selftest TC packet access | `vendor/linux-baseline/tools/testing/selftests/bpf/progs/test_pkt_access.c` | `test_pkt_access` | TC | networking, packet parse/write | medium: 84 entry insns plus 7 subprograms | compile from source | yes; verified load+run after local compile | Ethernet + IPv4/TCP or IPv6/TCP packet; result should come from `retval`, not packet bytes | P0 |
| selftest cgroup direct packet access | `vendor/linux-baseline/tools/testing/selftests/bpf/progs/cgroup_skb_direct_packet_access.c` | `direct_packet_access` | `cgroup_skb/ingress` | policy, cgroup | tiny: 6 insns | compile from source | yes; verified load+run after local compile | any Ethernet packet; result should come from `retval` | P0 |
| Cilium XDP datapath | `corpus/build/cilium/bpf_xdp.bpf.o` / `corpus/repos/cilium/bpf/bpf_xdp.c` | `cil_xdp_entry` | XDP | networking, service LB / policy | very high: about 26.1k object-wide insns, about 60 maps | yes | conceptually yes, but currently blocked at object open | IPv4 or IPv6 service packet plus large Cilium map profile | P1 |
| Cilium LXC datapath | `corpus/build/cilium/bpf_lxc.bpf.o` / `corpus/repos/cilium/bpf/bpf_lxc.c` | `cil_from_container`, `cil_lxc_policy`, `cil_lxc_policy_egress`, `cil_to_container` | TC | networking, endpoint policy | very high: about 41.9k object-wide insns, about 70 maps | yes | conceptually yes, but currently blocked at object open | pod ingress/egress packet plus `__sk_buff` metadata and large policy/LB map profile | P1 |
| Cilium overlay datapath | `corpus/build/cilium/bpf_overlay.bpf.o` / `corpus/repos/cilium/bpf/bpf_overlay.c` | `cil_from_overlay`, `cil_to_overlay` | TC | networking, tunneling | very high: about 29.6k object-wide insns, about 59 maps | yes | conceptually yes, but currently blocked at object open | tunneled packet plus tunnel key, interface metadata, and large map profile | P2 |

### 1.2 Deferred or non-honest candidates under the current constraint

These candidates are still worth cataloging, but they should not be part of the first runnable paper suite unless we add a more honest harness.

| Candidate | Object / source | Type | Domain | Why not first-wave runnable | What would make it usable |
| --- | --- | --- | --- | --- | --- |
| xdp-tools flowtable | `corpus/build/xdp-tools/xdp_flowtable.bpf.o` | XDP | networking | verified load failure in this kernel: missing kfunc `bpf_xdp_flow_lookup` in kernel BTF | newer kernel or feature-gated benchmark entry |
| selftest flow dissector | `vendor/linux-baseline/tools/testing/selftests/bpf/progs/bpf_flow.c` | `flow_dissector` | networking | supported by `test_run`, but current runner has no flow-dissector exec mode or result/ctx model | add dedicated `flow_dissector` exec mode and `bpf_flow_keys` fixture |
| selftest fentry test | `vendor/linux-baseline/tools/testing/selftests/bpf/progs/fentry_test.c` | `fentry` | tracing harness | runnable and verified, but not production-like | keep only as tracing-harness validation, not as a headline benchmark |
| selftest raw tracepoint test | `vendor/linux-baseline/tools/testing/selftests/bpf/progs/test_raw_tp_test_run.c` | `raw_tp` | tracing harness | runnable and verified, but tiny and no repeat support | use as raw-tp harness bring-up only |
| BCC `tcprtt` | `corpus/build/bcc/libbpf-tools/tcprtt.bpf.o` | `fentry` + `kprobe` | observability, networking | `kprobe` has no `test_run`; `fentry` `test_run` only exercises `bpf_fentry_test*`, not `tcp_rcv_established` | custom harness-derived variant or a different trigger path |
| BCC `runqlat` | `corpus/build/bcc/libbpf-tools/runqlat.bpf.o` | `tp_btf` + `raw_tp` | scheduling, observability | tracepoint path unsupported; raw-tp path has no repeat and synthetic ctx would not be faithful | either live-trigger benchmarks or a derived harness port |
| BCC `cpudist` | `corpus/build/bcc/libbpf-tools/cpudist.bpf.o` | `tp_btf` + `raw_tp` | scheduling, observability | same limitation as `runqlat` | same |
| BCC `biolatency` | `corpus/build/bcc/libbpf-tools/biolatency.bpf.o` | `tp_btf` + `raw_tp` | storage, observability | same limitation as `runqlat` | same |
| BCC `execsnoop` | `corpus/build/bcc/libbpf-tools/execsnoop.bpf.o` | `tracepoint` | security, observability | `tracepoint` has no `test_run` in this tree | live-trigger framework or derived harness port |
| Tetragon execve event | `corpus/build/tetragon/bpf_execve_event.bpf.o` | `tracepoint` | security, observability | tracepoint path unsupported | live-trigger framework or derived harness port |
| Tetragon generic kprobe | `corpus/build/tetragon/bpf_generic_kprobe.bpf.o` | `kprobe` + `fmod_ret` | security | `kprobe` unsupported; `fmod_ret`/tracing path is harness-limited | live-trigger framework or derived harness port |
| selftest `bpf_cubic` / `bpf_dctcp` | `vendor/linux-baseline/tools/testing/selftests/bpf/progs/bpf_cubic.c`, `bpf_dctcp.c` | `struct_ops` | scheduling / congestion control | current struct-ops test path is dummy-oriented, not faithful to real TCP CC execution | real in-kernel harness beyond current `test_run` path |

### 1.3 What this means for domain coverage

Under the strict `bpf_prog_test_run` constraint, honest first-wave production coverage is strongest in:

- networking: Katran, Cilium, xdp-tools, selftests
- network security: Suricata XDP filter, Cilium policy datapaths
- policy / control: `cgroup_skb` support programs

Observability and security tracing are important for the paper narrative, but current kernel `test_run` support prevents an honest "real production tracing program" suite. The right answer is to say that explicitly, not to benchmark arbitrary tracepoint or fentry objects with zero-filled fake context and over-claim realism.

### 1.4 Environment checks already performed

I checked a representative subset with the current `micro_exec` binary:

| Program | Current status |
| --- | --- |
| `corpus/build/katran/balancer.bpf.o:balancer_ingress` | loads and runs today |
| `corpus/build/katran/healthchecking.bpf.o:healthcheck_encap` | loads and runs today |
| `corpus/build/suricata/xdp_filter.bpf.o:xdp_hashfilter` | loads and runs today |
| `corpus/build/suricata/xdp_lb.bpf.o:xdp_loadfilter` | loads and runs today |
| `corpus/build/xdp-tools/xdp_forward.bpf.o:xdp_fwd_fib_direct` | loads and runs today |
| `vendor/.../test_pkt_access.c:test_pkt_access` | compiles, loads, and runs today |
| `vendor/.../cgroup_skb_direct_packet_access.c:direct_packet_access` | compiles, loads, and runs today |
| `corpus/build/xdp-tools/xdp_flowtable.bpf.o` | load fails today because `bpf_xdp_flow_lookup` is unavailable |
| `corpus/build/cilium/*.bpf.o` | open fails today because current libbpf path rejects static `xdp/tail` / `tc/tail` programs |

This is important for roadmap ordering: the suite should start from Katran, Suricata, xdp-tools `xdp_forward`, and the selftest TC/cgroup programs, because those are already operational in the current environment.

## 2. Framework extension design

### 2.1 Design goals

The existing micro framework is too XDP-shaped for real-world objects. It assumes:

- one object layout: `micro/programs/<base_name>.bpf.o`
- one main selection key: benchmark name only
- a narrow `io_mode` axis: `map`, `staged`, `packet`, `context`
- result extraction keyed by `io_mode`
- "context mode means no repeat"

Real-world benchmarks need a different decomposition:

- object provenance: arbitrary object path, often outside `micro/programs`
- exact entry selection: `program_name` matters
- hook-aware execution: XDP, TC, `cgroup_skb`, raw-tp, tracing, flow-dissector do not share the same ctx rules
- packet plus context together: many hooks need packet bytes and metadata at the same time
- explicit result source: for real packet programs the interesting output is usually `retval`, not the first 8 bytes of modified packet data
- explicit repeat model: kernel repeat, userspace loop, or single-shot should be chosen per hook, not per old `io_mode`
- map fixtures: meaningful execution often depends on non-zero map state

### 2.2 Proposed manifest schema

I would keep the existing synthetic benchmark YAMLs intact and add a new manifest for the real-world suite, for example `config/real_world_kernel.yaml`.

Suggested per-benchmark schema:

```yaml
suite_name: real_world_kernel

benchmarks:
  - name: katran_balancer_ipv4_tcp
    description: Katran XDP balancer on a configured IPv4/TCP VIP
    object: corpus/build/katran/balancer.bpf.o
    source: corpus/repos/katran/katran/lib/bpf/balancer.bpf.c
    project: katran
    program_name: balancer_ingress
    program_type: xdp
    exec_mode: packet_ctx
    ctx_model: xdp_md
    result_source: retval
    repeat_mode: kernel
    kernel_input_size: 54
    packet_fixture: ipv4_tcp_vip_syn
    ctx_fixture:
      ingress_ifindex: loopback
      rx_queue_index: 0
    map_fixture: katran_balancer_basic
    expected_retval: xdp_tx
    tags: [production, networking, xdp, katran]

  - name: tc_pkt_access_ipv4
    object: micro/build/real_world/test_pkt_access.bpf.o
    source: vendor/linux-baseline/tools/testing/selftests/bpf/progs/test_pkt_access.c
    project: linux-selftests
    program_name: test_pkt_access
    program_type: tc
    exec_mode: packet_ctx
    ctx_model: __sk_buff
    result_source: retval
    repeat_mode: kernel
    kernel_input_size: 54
    packet_fixture: ipv4_tcp_urg123
    ctx_fixture:
      ifindex: loopback
      ingress_ifindex: loopback
    expected_retval: tc_act_ok
    tags: [support, tc, parser]
```

Recommended new fields:

- `object`: exact `.bpf.o` path
- `source`: source path for provenance
- `project`: short provenance label such as `katran`, `cilium`, `bcc`
- `program_name`: exact entry program to load
- `program_type`: declared hook type for validation and reporting
- `exec_mode`: `packet`, `packet_ctx`, `context_only`, `map_packet`
- `ctx_model`: `xdp_md`, `__sk_buff`, `u64_args`, `bpf_flow_keys`, `sk_lookup`
- `result_source`: `retval`, `packet_u64`, `map_u64:<name>`, `none`
- `repeat_mode`: `kernel`, `userspace`, `single`
- `packet_fixture`: name of packet generator profile
- `ctx_fixture`: named or inline metadata values
- `map_fixture`: named map initialization profile
- `expected_retval`: optional action code for validation

### 2.3 Why `io_mode` is not enough

The current runner conflates unrelated concerns.

Problems in the current design:

- `packet` implies "read result from packet bytes", which is wrong for almost every real XDP/TC/cgroup benchmark
- `context` implies "disable repeat", which is wrong for future types like `sk_lookup`
- there is no way to provide packet bytes and hook-specific metadata together
- `run_micro.py` never passes `--program-name`, even though the runner already supports it

The real suite should split those concerns into separate axes:

- transport: packet, context, map staging
- hook: XDP, TC, `cgroup_skb`, raw-tp, tracing
- result source: retval, packet bytes, map lookup
- repeat model: kernel repeat or userspace repeat

### 2.4 Runner behavior by hook

Recommended runtime behavior:

| Hook | Input model | Result source | Repeat model | Notes |
| --- | --- | --- | --- | --- |
| XDP | packet plus optional `xdp_md` | usually `retval` | kernel | allow `ingress_ifindex`, `rx_queue_index`, `data_meta` |
| TC | packet plus optional `__sk_buff` | usually `retval` | kernel | allow `mark`, `priority`, `ingress_ifindex`, `ifindex`, `cb[]`, `wire_len`, `gso_*` |
| `cgroup_skb` | packet plus optional `__sk_buff` | `retval` | kernel | same underlying skb test path as TC |
| raw-tp | `ctx_in` only | `retval` | userspace or single | no kernel repeat; no data buffers |
| tracing (`fentry`/`fexit`) | usually none or harness ctx | `retval` | userspace or single | use only for harness programs; do not claim production fidelity |
| flow dissector | context only | `retval` or ctx-out | kernel | stretch goal |
| `sk_lookup` | context only | `retval` / cookie in ctx | kernel | stretch goal |

### 2.5 Map fixture model

Real-world objects need more than packet bytes. They need map state.

I recommend a two-layer fixture system:

1. Generic map updates for simple cases.
2. Named code-driven fixtures for complex objects.

Generic fixture example:

```yaml
map_fixture:
  kind: generic
  updates:
    - map: cpus_count
      key_u32: 0
      value_u32: 1
    - map: cpus_available
      key_u32: 0
      value_u32: 0
```

Code-driven fixture example:

```yaml
map_fixture:
  kind: builtin
  name: katran_balancer_basic
```

Why both are needed:

- Suricata and selftests can mostly use generic updates.
- Katran and especially Cilium need struct-aware initialization, map-of-maps, or large table fills that are awkward to express in plain YAML.

### 2.6 Packet and context fixtures

Packet fixtures should be named and reusable, not ad-hoc binary blobs committed by hand.

Recommended fixture families:

- `ipv4_tcp_vip_syn`
- `ipv4_udp_healthcheck`
- `ipv6_tcp_service`
- `ipv4_tcp_urg123` for `test_pkt_access`
- `ipv4_basic_l2l3` for `cgroup_skb`

Context fixtures should support symbolic fields such as:

- `loopback` for ifindex resolution
- `rxq0`
- `mark: <value>`
- `priority: <value>`

That keeps the manifest readable and avoids baking host-specific ifindices into YAML.

### 2.7 Lessons worth borrowing from existing benchmark suites

Useful reference points:

- `xdp-bench` from `xdp-tools`: the important lesson is not the exact programs, but the scenario matrix. It exposes packet-operation and load-mode combinations explicitly instead of hiding them behind one benchmark label.
- Linux selftests `tools/testing/selftests/bpf/benchs/`: the important lesson is that hook-specific benchmarks deserve hook-specific harness logic. The kernel project does not force all BPF subsystems through one fake generic runner.
- `eunomia-bpf/bpf-benchmark`: useful as an example of metadata and result aggregation across heterogeneous BPF suites, but not a model for hook-faithful kernel `test_run` execution.

## 3. Implementation plan with code sketches

### 3.1 Cross-cutting file changes

Core framework files to modify:

| File | Change |
| --- | --- |
| `micro/benchmark_catalog.py` | extend `BenchmarkSpec` to support `object`, `source`, `project`, `program_name`, `program_type`, `exec_mode`, `ctx_model`, `result_source`, `repeat_mode`, `packet_fixture`, `ctx_fixture`, `map_fixture`, `expected_retval` |
| `micro/run_micro.py` | pass `--program-name`; materialize packet/context fixtures; pass `--result-source`, `--repeat-mode`, and map fixture path or name |
| `micro/runner/include/micro_exec.hpp` | add CLI fields for context blob, result source, repeat mode, map fixture |
| `micro/runner/src/common.cpp` | parse new CLI switches and validate combinations |
| `micro/runner/src/kernel_runner.cpp` | support packet+ctx execution, hook-aware result extraction, map fixture initialization, userspace repeat path for non-repeatable hooks |
| `config/real_world_kernel.yaml` | new suite manifest |

New helper files to add:

| File | Purpose |
| --- | --- |
| `micro/build_real_world.py` | build selected selftests objects and verify required corpus objects exist |
| `micro/real_world_fixtures.py` | packet and small context fixture materialization |
| `micro/runner/src/map_fixture.cpp` and header | named builtin map initializers for Katran, Suricata, later Cilium |

### 3.2 Practical per-candidate integration tasks

| Candidate | Files to add or modify | Input data needed | Main difficulty |
| --- | --- | --- | --- |
| Katran balancer | new manifest entry; map fixture code; packet fixture | IPv4/TCP VIP packet; `vip_map`, `ch_rings`, `reals`, `stats` seeds | map profile is non-trivial but contained |
| Katran healthchecking | manifest entry; map fixture code; `__sk_buff` ctx fixture support | packet plus `hc_reals_map`, `hc_ctrl_map`, MAC maps, optional `skb.mark` | needs `packet + ctx` support and cleaner retval extraction |
| Suricata XDP filter | manifest entry; simple map fixture | packet plus CPU-map related seeds; optional prefilled flow table | source repo should be vendored or upstream commit recorded |
| Suricata XDP LB | manifest entry; simple map fixture | packet plus CPU-map related seeds | source repo should be vendored or upstream commit recorded |
| xdp-tools xdp_forward | manifest entry; optional xdp ctx fixture | packet plus optional `xdp_tx_ports` devmap seed | mostly a control benchmark, not a reviewer-answer by itself |
| selftest `test_pkt_access` | build script entry; manifest entry; packet fixture | Ethernet+TCP packet with known header values | needs `retval` result source because packet bytes are not the oracle |
| selftest `cgroup_skb_direct_packet_access` | build script entry; manifest entry | any Ethernet packet | breadth benchmark, very small program |
| Cilium XDP | loader compatibility fix; large builtin map fixture | service packet plus many LB/policy maps | current object open failure in libbpf path |
| Cilium LXC | loader compatibility fix; large builtin map fixture; skb ctx fixtures | pod ingress/egress packet plus endpoint/policy maps | large map surface and multi-entry object |
| Cilium overlay | loader compatibility fix; tunnel key handling; map fixtures | tunneled packet plus tunnel metadata and maps | highest setup complexity among current candidates |

### 3.3 Code sketch: extended Python benchmark spec

```python
@dataclass(frozen=True)
class BenchmarkSpec:
    name: str
    description: str
    object_path: Path
    source_path: Path | None
    project: str
    program_name: str | None
    program_type: str
    exec_mode: str
    ctx_model: str | None
    result_source: str
    repeat_mode: str
    kernel_input_size: int
    packet_fixture: str | None = None
    ctx_fixture: dict[str, object] | None = None
    map_fixture: dict[str, object] | str | None = None
    expected_retval: int | None = None
```

### 3.4 Code sketch: helper command construction

```python
def resolve_helper_command(...):
    command = [
        binary,
        "run-kernel",
        "--program", str(benchmark.object_path),
        "--io-mode", benchmark.exec_mode_compat(),
        "--input-size", str(benchmark.kernel_input_size),
        "--result-source", benchmark.result_source,
        "--repeat-mode", benchmark.repeat_mode,
    ]
    if benchmark.program_name:
        command += ["--program-name", benchmark.program_name]
    if packet_file:
        command += ["--memory", str(packet_file)]
    if ctx_file:
        command += ["--context", str(ctx_file)]
    if map_fixture_file:
        command += ["--map-fixture", str(map_fixture_file)]
```

The important point is that `--program-name` already exists in the C++ runner. The suite plumbing simply does not expose it today.

### 3.5 Code sketch: runner result extraction

```cpp
uint64_t extract_result(
    const cli_options &options,
    const bpf_test_run_opts &test_opts,
    const std::vector<uint8_t> &packet_out,
    int result_fd)
{
    if (options.result_source == "retval") {
        return test_opts.retval;
    }
    if (options.result_source == "packet_u64") {
        return read_u64_result(packet_out.data(), packet_out.size());
    }
    if (options.result_source == "map_u64") {
        uint32_t key = 0;
        uint64_t value = 0;
        if (bpf_map_lookup_elem(result_fd, &key, &value) != 0) {
            fail("result map lookup failed");
        }
        return value;
    }
    fail("unknown result source");
}
```

This change is essential. Today real packet programs return a meaningless `result` because the runner reads the first eight output bytes from the packet buffer.

### 3.6 Code sketch: packet plus context execution

```cpp
if (options.exec_mode == "packet_ctx") {
    packet = materialize_packet(...);
    packet_out.assign(packet.size(), 0);

    context_in = materialize_context(...);  // xdp_md or __sk_buff

    test_opts.data_in = packet.data();
    test_opts.data_size_in = packet.size();
    test_opts.data_out = packet_out.data();
    test_opts.data_size_out = packet_out.size();
    test_opts.ctx_in = context_in.data();
    test_opts.ctx_size_in = context_in.size();
}
```

This is the missing capability for meaningful TC and some XDP programs. The kernel supports it today for skb and xdp test paths; the runner just does not expose it.

### 3.7 Code sketch: repeat handling should depend on hook, not old `context` mode

```cpp
if (options.repeat_mode == "kernel") {
    test_opts.repeat = options.repeat;
    run_once();
} else if (options.repeat_mode == "userspace") {
    for (uint32_t i = 0; i < options.repeat; ++i) {
        test_opts.repeat = 0;
        run_once();
        aggregate_durations(...);
    }
} else {
    test_opts.repeat = 0;
    run_once();
}
```

Current behavior disables kernel repeat whenever `io_mode == "context"`. That is too coarse for a hook-aware suite.

### 3.8 Code sketch: builtin map fixture registry

```cpp
using map_fixture_fn = std::function<void(bpf_object *, const runtime_env &)>;

static const std::unordered_map<std::string, map_fixture_fn> kBuiltins = {
    {"katran_balancer_basic", init_katran_balancer_basic},
    {"katran_healthcheck_basic", init_katran_healthcheck_basic},
    {"suricata_xdp_filter_basic", init_suricata_xdp_filter_basic},
    {"suricata_xdp_lb_basic", init_suricata_xdp_lb_basic},
};
```

For the first wave, a builtin registry is more practical than trying to express every C struct in YAML. Generic YAML map updates can still exist for simple cases.

### 3.9 Build plan for real-world objects

Recommended build strategy:

- keep using `corpus/build/...` for externally built production objects that already exist
- add a small build script for support-program objects that must be compiled from the vendored kernel selftests tree
- do not copy everything into `micro/programs`, because that directory is optimized for synthetic micro sources, not for provenance-rich external corpora

`micro/build_real_world.py` should:

- verify required corpus objects exist
- compile selected selftests programs into `micro/build/real_world/*.bpf.o`
- emit a small manifest or log with source path and build command for artifact provenance

## 4. Priority-ordered implementation roadmap

### P0: add the first honest runnable suite

This is the set I would implement first because it materially answers reviewer criticism with bounded engineering work.

Framework work:

- expose `object` and `program_name` in YAML and Python
- add `result_source=retval`
- add `packet_ctx` execution mode
- add basic map fixture support
- add `config/real_world_kernel.yaml`
- add build script entries for `test_pkt_access` and `cgroup_skb_direct_packet_access`

Benchmarks:

- `katran_balancer_ipv4_tcp`
- `suricata_xdp_filter`
- `suricata_xdp_lb`
- `xdp_forward_fib_direct` as a control/reference XDP program
- `selftest_tc_test_pkt_access`
- `selftest_cgroup_direct_packet_access`

Why this is enough for the first paper revision:

- projects: Katran, Suricata, xdp-tools, Linux selftests
- hook types: XDP, TC, `cgroup_skb`
- domains: networking, network security, cgroup policy/control
- engineering risk: low to medium; all except the selftest builds are already present as objects and most already load in the current environment

### P1: extend coverage without changing the truthfulness bar

Framework work:

- richer `__sk_buff` fixture support for `mark`, `priority`, `ingress_ifindex`, `ifindex`
- richer `xdp_md` fixture support for `ingress_ifindex` and `rx_queue_index`
- more builtin map fixtures

Benchmarks:

- `katran_healthcheck_encap`
- `cilium_bpf_xdp` once the object-open issue is fixed
- `cilium_bpf_lxc` once the object-open issue is fixed

Specific blockers:

- Cilium currently fails at `bpf_object__open_file` with the exact complaint that static programs inside `xdp/tail` or `tc/tail` sections are unsupported by the current libbpf/open path.
- Suricata source should be vendored or pinned to an exact upstream commit for artifact completeness.

### P2: stretch goals and deferred classes

Stretch types that are technically supported but need dedicated work:

- `flow_dissector` via selftest `bpf_flow.c`
- `sk_lookup`
- raw-tp harness benchmarks with userspace repeat
- tracing harness validation via `fentry_test`

Deferred production-derived work:

- Cilium overlay datapath
- xdp-tools `xdp_flowtable` after kernel support for `bpf_xdp_flow_lookup`
- derived harness ports of BCC/Tetragon logic for observability and security domains

Not recommended for this paper under the current kernel-only `test_run` constraint:

- arbitrary BCC tracepoint objects
- arbitrary BCC/Tetragon `kprobe` objects
- arbitrary production `fentry` objects presented as real attach-target benchmarks
- real TCP `struct_ops` benchmarks

## Recommended first benchmark set for the paper

If the goal is to ship something reviewer-visible quickly, the paper-safe first set is:

1. Katran `balancer_ingress`
2. Suricata `xdp_hashfilter`
3. Suricata `xdp_loadfilter`
4. xdp-tools `xdp_fwd_fib_direct`
5. selftest `test_pkt_access`
6. selftest `direct_packet_access` for `cgroup_skb`

Then add:

7. Katran `healthcheck_encap`
8. Cilium `cil_xdp_entry` after the loader fix
9. Cilium `cil_from_container` after the loader fix

That sequence maximizes reviewer-visible breadth while minimizing the chance of spending the next iteration buried in Cilium-specific loader and map-fixture work.

## Reference points

Kernel-source references checked locally:

- `vendor/linux-baseline/net/bpf/test_run.c`
- `vendor/linux-baseline/net/core/filter.c`
- `vendor/linux-baseline/kernel/trace/bpf_trace.c`
- `vendor/linux-baseline/kernel/bpf/bpf_struct_ops.c`
- `vendor/linux-baseline/net/bpf/bpf_dummy_struct_ops.c`

Upstream or external references checked:

- Linux mainline `net/bpf/test_run.c`: <https://raw.githubusercontent.com/torvalds/linux/master/net/bpf/test_run.c>
- Linux mainline `net/core/filter.c`: <https://raw.githubusercontent.com/torvalds/linux/master/net/core/filter.c>
- xdp-tools `xdp-bench` README: <https://raw.githubusercontent.com/xdp-project/xdp-tools/master/xdp-bench/README.org>
- Katran README: <https://raw.githubusercontent.com/facebookincubator/katran/main/README.md>
- `eunomia-bpf/bpf-benchmark` README: <https://raw.githubusercontent.com/eunomia-bpf/bpf-benchmark/master/README.md>
