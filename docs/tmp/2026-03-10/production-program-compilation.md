# Production Program Compilation

## Summary

- Verified `EM_BPF` outputs now exist under `corpus/build/katran`, `corpus/build/xdp-tools`, `corpus/build/xdp-tutorial`, and `corpus/build/cilium`.
- Total compiled objects in this pass: 46.
- Total raw BPF instructions across those objects: 112073.
- Total directive sites from the `micro/directive_census.py` matcher logic: 802.
- Highest-value wins for the paper are in place:
  - `corpus/build/katran/balancer.bpf.o`
  - `corpus/build/katran/healthchecking.bpf.o`
  - `corpus/build/cilium/bpf_xdp.bpf.o`
  - `corpus/build/cilium/bpf_lxc.bpf.o`
  - `corpus/build/cilium/bpf_overlay.bpf.o`
  - all 13 `xdp-tools` `.bpf.o` targets
  - all 25 `xdp-tutorial` kernel lesson objects

## Verified Build Paths

### Katran

Direct `clang` compilation worked once I stopped mixing the repo with `vendor/libbpf/include/linux/types.h`. The working include set was the repo root, Katran's `linux_includes`, and `/usr/include/x86_64-linux-gnu`.

Working pattern:

```bash
clang -O2 -g -target bpf -D__TARGET_ARCH_x86 \
  -I/usr/include/x86_64-linux-gnu \
  -I/home/yunwei37/workspace/bpf-benchmark/corpus/repos/katran \
  -I/home/yunwei37/workspace/bpf-benchmark/corpus/repos/katran/katran/lib/linux_includes \
  -I/home/yunwei37/workspace/bpf-benchmark/corpus/repos/katran/katran/lib/bpf \
  -I/home/yunwei37/workspace/bpf-benchmark/corpus/repos/katran/katran/lib \
  -c corpus/repos/katran/katran/lib/bpf/<file>.c \
  -o corpus/build/katran/<name>.bpf.o
```

### xdp-tools

The repo build system works, but `configure` does not enable the extra BPF utilities in `all` on this machine because its `bpftool` autodetection falls through to `whereis -b bpftool`, which returns both `/usr/local/sbin/bpftool` and `/usr/sbin/bpftool`. The workaround is to configure once, then invoke the needed utility targets explicitly.

Verified command:

```bash
cd corpus/repos/xdp-tools
sh configure
make -j1 xdp-bench xdp-forward xdp-monitor xdp-trafficgen
```

The per-directory BPF build rules are valid; for example:

```bash
cd corpus/repos/xdp-tools/xdp-bench
make xdp_basic.bpf.o
```

### xdp-tutorial

`sh configure && make lib` works. Lesson-local kernel object builds work, but top-level `make` is not sufficient by itself for a clean end-to-end run because `packet-solutions` tries to copy `../lib/xdp-tools/xdp-loader`, which is not present in this clone layout.

Verified lesson-local pattern:

```bash
cd corpus/repos/xdp-tutorial
sh configure
make -j1 lib
make -C basic01-xdp-pass xdp_pass_kern.o
make -C packet-solutions xdp_prog_kern_02.o xdp_prog_kern_03.o tc_reply_kern_02.o xdp_vlan01_kern.o xdp_vlan02_kern.o
...
```

One lesson needs an extra workaround on modern system libbpf headers:

```bash
clang -target bpf -Wall -Wno-unused-value -Wno-pointer-sign \
  -Wno-compare-distinct-pointer-types -Wno-visibility -Werror \
  -Wno-macro-redefined -fno-stack-protector \
  -DBPF_DIR_MNT='"/sys/fs/bpf"' -DBPF_OBJECT_PATH='"/usr/local/lib/bpf"' -DDEBUG \
  -I/usr/include/x86_64-linux-gnu \
  -Icorpus/repos/xdp-tutorial/lib/install/include \
  -O2 -c -g \
  -o corpus/build/xdp-tutorial/experiment01-tailgrow/xdp_prog_kern3.bpf.o \
  corpus/repos/xdp-tutorial/experiment01-tailgrow/xdp_prog_kern3.c
```

The same direct-`clang` fallback also works for the other `experiment01-tailgrow` kernel files.

### Cilium

The repo-native `bpf/Makefile` works for the three production datapath objects directly.

Verified command:

```bash
make -C corpus/repos/cilium/bpf -j1 bpf_xdp.o bpf_lxc.o bpf_overlay.o
```

The compile lines came from the native make rules and use Cilium's own `MAX_*_OPTIONS` plus:

```bash
-I.../corpus/repos/cilium/bpf -I.../corpus/repos/cilium/bpf/include \
--target=bpf -std=gnu99 -nostdinc -O2 -g -mcpu=v3
```

I then copied the resulting objects into `corpus/build/cilium/` as `bpf_xdp.bpf.o`, `bpf_lxc.bpf.o`, and `bpf_overlay.bpf.o`.

## Results

### Katran

- Compiled objects: 5
- Total instructions: 3013
- Total directive sites: 30

| Program | SEC / type | Insns | ROTATE | WIDE | LEA | CMOV | Total |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: |
| `balancer.bpf.o` | `xdp` | 2546 | 20 | 4 | 0 | 5 | 29 |
| `healthchecking.bpf.o` | `tc` | 325 | 0 | 0 | 0 | 1 | 1 |
| `healthchecking_ipip.bpf.o` | `tc` | 103 | 0 | 0 | 0 | 0 | 0 |
| `xdp_pktcntr.bpf.o` | `xdp` | 22 | 0 | 0 | 0 | 0 | 0 |
| `xdp_root.bpf.o` | `xdp` | 17 | 0 | 0 | 0 | 0 | 0 |

### xdp-tools

- Compiled objects: 13
- Total instructions: 9094
- Total directive sites: 52

| Program | SEC / type | Insns | ROTATE | WIDE | LEA | CMOV | Total |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: |
| `xdp_basic.bpf.o` | `tp_btf/xdp_redirect_err, tp_btf/xdp_redirect, tp_btf/xdp_cpumap_enqueue, tp_btf/xdp_cpumap_kthread, tp_btf/xdp_exception, tp_btf/xdp_devmap_xmit, xdp` | 1116 | 0 | 1 | 0 | 3 | 4 |
| `xdp_flowtable.bpf.o` | `xdp` | 2744 | 0 | 0 | 0 | 30 | 30 |
| `xdp_flowtable_sample.bpf.o` | `xdp` | 25 | 0 | 0 | 0 | 1 | 1 |
| `xdp_forward.bpf.o` | `xdp` | 302 | 0 | 0 | 0 | 2 | 2 |
| `xdp_load_bytes.bpf.o` | `xdp` | 13 | 0 | 0 | 0 | 1 | 1 |
| `xdp_monitor.bpf.o` | `tp_btf/xdp_redirect_err, tp_btf/xdp_redirect, tp_btf/xdp_cpumap_enqueue, tp_btf/xdp_cpumap_kthread, tp_btf/xdp_exception, tp_btf/xdp_devmap_xmit` | 541 | 0 | 0 | 0 | 2 | 2 |
| `xdp_redirect_basic.bpf.o` | `tp_btf/xdp_redirect_err, tp_btf/xdp_redirect, tp_btf/xdp_cpumap_enqueue, tp_btf/xdp_cpumap_kthread, tp_btf/xdp_exception, tp_btf/xdp_devmap_xmit, xdp` | 630 | 0 | 0 | 0 | 2 | 2 |
| `xdp_redirect_cpumap.bpf.o` | `tp_btf/xdp_redirect_err, tp_btf/xdp_redirect, tp_btf/xdp_cpumap_enqueue, tp_btf/xdp_cpumap_kthread, tp_btf/xdp_exception, tp_btf/xdp_devmap_xmit, xdp, xdp/cpumap, xdp/devmap` | 1364 | 0 | 0 | 0 | 3 | 3 |
| `xdp_redirect_devmap.bpf.o` | `tp_btf/xdp_redirect_err, tp_btf/xdp_redirect, tp_btf/xdp_cpumap_enqueue, tp_btf/xdp_cpumap_kthread, tp_btf/xdp_exception, tp_btf/xdp_devmap_xmit, xdp, xdp/devmap` | 632 | 0 | 0 | 0 | 2 | 2 |
| `xdp_redirect_devmap_multi.bpf.o` | `tp_btf/xdp_redirect_err, tp_btf/xdp_redirect, tp_btf/xdp_cpumap_enqueue, tp_btf/xdp_cpumap_kthread, tp_btf/xdp_exception, tp_btf/xdp_devmap_xmit, xdp, xdp/devmap` | 612 | 0 | 0 | 0 | 2 | 2 |
| `xdp_sample.bpf.o` | `tp_btf/xdp_cpumap_kthread` | 28 | 0 | 0 | 0 | 0 | 0 |
| `xdp_trafficgen.bpf.o` | `tp_btf/xdp_redirect_err, tp_btf/xdp_redirect, tp_btf/xdp_cpumap_enqueue, tp_btf/xdp_cpumap_kthread, tp_btf/xdp_exception, tp_btf/xdp_devmap_xmit, xdp` | 1070 | 0 | 0 | 0 | 3 | 3 |
| `xdpsock.bpf.o` | `xdp` | 17 | 0 | 0 | 0 | 0 | 0 |

### Cilium

- Compiled objects: 3
- Total instructions: 97621
- Total directive sites: 658

| Program | SEC / type | Insns | ROTATE | WIDE | LEA | CMOV | Total |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: |
| `bpf_lxc.bpf.o` | `tc/tail, tc/entry` | 41881 | 0 | 0 | 0 | 142 | 142 |
| `bpf_overlay.bpf.o` | `tc/tail, tc/entry` | 29611 | 0 | 0 | 0 | 108 | 108 |
| `bpf_xdp.bpf.o` | `xdp/tail, xdp/entry` | 26129 | 0 | 0 | 0 | 408 | 408 |

### xdp-tutorial

- Compiled objects: 25
- Total instructions: 2345
- Total directive sites: 62

| Program | SEC / type | Insns | ROTATE | WIDE | LEA | CMOV | Total |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: |
| `advanced03-AF_XDP/af_xdp_kern.bpf.o` | `xdp` | 31 | 0 | 0 | 0 | 0 | 0 |
| `basic01-xdp-pass/xdp_pass_kern.bpf.o` | `xdp` | 2 | 0 | 0 | 0 | 0 | 0 |
| `basic02-prog-by-name/xdp_prog_kern.bpf.o` | `xdp` | 4 | 0 | 0 | 0 | 0 | 0 |
| `basic03-map-counter/xdp_prog_kern.bpf.o` | `xdp` | 14 | 0 | 0 | 0 | 0 | 0 |
| `basic04-pinning-maps/xdp_prog_kern.bpf.o` | `xdp` | 62 | 0 | 0 | 0 | 0 | 0 |
| `experiment01-tailgrow/xdp_prog_fail1.bpf.o` | `xdp_fail1` | 13 | 0 | 0 | 0 | 0 | 0 |
| `experiment01-tailgrow/xdp_prog_fail2.bpf.o` | `xdp_fail2` | 7 | 0 | 0 | 0 | 1 | 1 |
| `experiment01-tailgrow/xdp_prog_fail3.bpf.o` | `xdp_fail3` | 14 | 0 | 0 | 0 | 0 | 0 |
| `experiment01-tailgrow/xdp_prog_kern.bpf.o` | `xdp_tailgrow_parse, xdp_tailgrow, xdp_pass, xdp_tailgrow_tx, xdp_tx` | 210 | 0 | 0 | 0 | 0 | 0 |
| `experiment01-tailgrow/xdp_prog_kern2.bpf.o` | `xdp_end_loop` | 18 | 0 | 0 | 0 | 0 | 0 |
| `experiment01-tailgrow/xdp_prog_kern3.bpf.o` | `xdp_works1` | 16 | 0 | 0 | 0 | 0 | 0 |
| `experiment01-tailgrow/xdp_prog_kern4.bpf.o` | `xdp_test1` | 25 | 0 | 0 | 0 | 1 | 1 |
| `packet-solutions/tc_reply_kern_02.bpf.o` | `tc` | 97 | 0 | 0 | 0 | 0 | 0 |
| `packet-solutions/xdp_prog_kern_02.bpf.o` | `xdp_patch_ports, xdp_vlan_swap, xdp_pass` | 338 | 0 | 9 | 0 | 1 | 10 |
| `packet-solutions/xdp_prog_kern_03.bpf.o` | `xdp_icmp_echo, xdp_redirect, xdp_redirect_map, xdp_router, xdp_pass` | 507 | 0 | 4 | 0 | 5 | 9 |
| `packet-solutions/xdp_vlan01_kern.bpf.o` | `xdp_vlan01` | 113 | 0 | 6 | 0 | 12 | 18 |
| `packet-solutions/xdp_vlan02_kern.bpf.o` | `xdp_vlan02` | 127 | 0 | 0 | 0 | 9 | 9 |
| `packet01-parsing/xdp_prog_kern.bpf.o` | `xdp` | 35 | 0 | 0 | 0 | 0 | 0 |
| `packet02-rewriting/xdp_prog_kern.bpf.o` | `xdp` | 117 | 0 | 1 | 0 | 2 | 3 |
| `packet03-redirecting/xdp_prog_kern.bpf.o` | `xdp` | 306 | 0 | 2 | 0 | 4 | 6 |
| `tracing01-xdp-simple/trace_prog_kern.bpf.o` | `tracepoint/xdp/xdp_exception` | 29 | 0 | 0 | 0 | 0 | 0 |
| `tracing01-xdp-simple/xdp_prog_kern.bpf.o` | `xdp` | 2 | 0 | 0 | 0 | 0 | 0 |
| `tracing02-xdp-monitor/trace_prog_kern.bpf.o` | `tracepoint/xdp/xdp_redirect_err, tracepoint/xdp/xdp_redirect_map_err, tracepoint/xdp/xdp_redirect, tracepoint/xdp/xdp_redirect_map, tracepoint/xdp/xdp_exception, tracepoint/xdp/xdp_cpumap_enqueue, tracepoint/xdp/xdp_cpumap_kthread, tracepoint/xdp/xdp_devmap_xmit` | 176 | 0 | 0 | 0 | 4 | 4 |
| `tracing03-xdp-debug-print/xdp_prog_kern.bpf.o` | `xdp` | 49 | 0 | 0 | 0 | 0 | 0 |
| `tracing04-xdp-tcpdump/xdp_sample_pkts_kern.bpf.o` | `xdp` | 33 | 0 | 0 | 0 | 1 | 1 |

## Remaining Gaps And Suggested Follow-up

- `xdp-tools`: the objects are compiled, but the top-level `make all` path still misses the four BPF-heavy utilities on this host because `configure` mishandles multiple `bpftool` binaries. A small patch to `configure` to keep only the first `whereis` result would make the build more deterministic.
- `xdp-tutorial`: the top-level lesson runner still fails in `packet-solutions` because it expects `../lib/xdp-tools/xdp-loader`. For the paper corpus, lesson-local kernel object builds are the correct path anyway. `experiment01-tailgrow/xdp_prog_kern3.c` also needs `-Wno-macro-redefined` with modern `bpf_helpers.h`.
- `cilium`: the three production datapath objects compile cleanly. `bpf/tests/` is still blocked in this trimmed checkout because `pkg/datapath/loader/tools/clang_cflags.go` is missing, the Scapy-generated packet header path has to be materialized, and direct one-off `clang` retries still ran into Cilium-specific builtin/trap header issues plus some LLVM BPF backend crashes.
- `katran`: the important production objects are compiled. If we want more coverage later, the same direct-`clang` pattern should extend to the remaining small helper XDP/TC programs in `katran/lib/bpf/`.

## Method

- I verified each artifact is `EM_BPF`.
- Instruction counts and directive site counts were collected with the same raw-ELF matcher logic used by `micro/directive_census.py`, via `micro.directive_census.analyze_object(...)`.
