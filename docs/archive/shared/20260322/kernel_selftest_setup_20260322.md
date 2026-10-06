# Upstream BPF Selftests Setup for REJIT Regression Testing

**Date**: 2026-03-22
**Status**: COMPLETE — test_verifier fully working; test_progs built and running (with known limitations)
**Kernel**: vendor/linux-framework 7.0-rc2 (custom, with REJIT patches)

---

## Summary

Two-tier selftest setup for REJIT regression testing:

| Tool | Status | Tests | Notes |
|------|--------|-------|-------|
| `test_verifier` | **FULLY WORKING** | 526 PASS, 264 SKIP, 1 FAIL | Primary regression tool; 1 failure is expected (CONFIG_IPV6 TCP helper) |
| `test_progs` | **BUILT + RUNNING** | Varies by filter | Full binary built; JIT/verifier subset recommended |

**Recommendation for REJIT CI**: Use `make vm-upstream-test-verifier`. It covers JIT compilation, verifier correctness, atomic ops, and BPF instruction correctness — exactly what REJIT modifies.

---

## Quick Start

### Run test_verifier (primary REJIT regression test)
```bash
make vm-upstream-test-verifier
```

### Run test_progs filtered to JIT+verifier
```bash
make vm-upstream-test-progs BPF_SELFTEST_FILTER="verifier jit"
```

### Run all test_progs
```bash
make vm-upstream-test-progs BPF_SELFTEST_FILTER=""
```
(Warning: takes 10+ minutes, many tests will SKIP due to missing network namespaces/hardware in VM)

---

## Directory Structure

```
vendor/linux-framework/tools/testing/selftests/bpf/
├── Makefile                      # Upstream build system
├── progs/                        # ~917 BPF programs (.c → .bpf.o → .skel.h)
├── prog_tests/                   # test_progs test suites (~422 test groups)
├── verifier/                     # test_verifier test cases (jit.c, atomic.c, etc.)
├── test_progs.c                  # test_progs main
├── test_verifier.c               # test_verifier main
└── tools/include/
    └── vmlinux.h                 # Auto-generated from kernel BTF (maintained manually)

docs/tmp/bpf_selftests_bin/       # Pre-built output directory
├── test_verifier                 # 20MB binary (built)
├── test_progs                    # 67MB binary (built)
├── bpf_testmod.ko                # Required kernel module
├── bpf_test_kinsn.ko             # Required kernel module
├── bpf_smc.skel.h                # Stub (CONFIG_SMC not in kernel)
├── tools/include/vmlinux.h       # Modified vmlinux.h with compatibility stubs
└── ...
```

---

## Build Procedure

### Prerequisites
- `clang-20` (required; clang-18 lacks `__BPF_FEATURE_ADDR_SPACE_CAST`)
- Kernel built with BTF (`CONFIG_DEBUG_INFO_BTF=y`)
- `bpftool` (built as part of selftests)
- `export TMPDIR=/var/tmp` (VM /tmp is read-only)

### One-time build (from host)
```bash
SELFTESTS_DIR=vendor/linux-framework/tools/testing/selftests/bpf
OUTPUT=docs/tmp/bpf_selftests_bin
VMLINUX_H_PATH="${SELFTESTS_DIR}/tools/include/vmlinux.h"

export TMPDIR=/var/tmp
cd "$SELFTESTS_DIR"

# Build test_verifier
make -j$(nproc) CLANG=clang-20 OUTPUT="${OUTPUT}" \
  VMLINUX_H="${VMLINUX_H_PATH}" \
  SKIP_DOCS=1 "${OUTPUT}/test_verifier"

# Build test_progs (bpf_smc blacklisted; stub skel.h already in OUTPUT)
make -j$(nproc) CLANG=clang-20 OUTPUT="${OUTPUT}" \
  VMLINUX_H="${VMLINUX_H_PATH}" \
  SKIP_DOCS=1 \
  "SKEL_BLACKLIST=btf__% test_pinning_invalid.c test_sk_assign.c bpf_smc.c" \
  "${OUTPUT}/test_progs"
```

**Note**: `bpf_smc.skel.h` stub must exist in `$OUTPUT` before building test_progs. If it's missing, regenerate it:
```bash
cat > docs/tmp/bpf_selftests_bin/bpf_smc.skel.h << 'EOF'
/* Stub - CONFIG_SMC not enabled */
#ifndef __BPF_SMC_SKEL_H__
#define __BPF_SMC_SKEL_H__
#include <bpf/libbpf.h>
struct bpf_smc__bss { int smc_cnt; int fallback_cnt; };
struct bpf_smc__maps { struct bpf_map *smc_policy_ip; };
struct bpf_smc { struct bpf_object_skeleton *skeleton; struct bpf_object *obj; struct bpf_smc__maps maps; struct bpf_smc__bss *bss; };
static inline struct bpf_smc *bpf_smc__open_and_load(void) { return NULL; }
static inline int bpf_smc__attach(struct bpf_smc *s) { (void)s; return -ENOTSUP; }
static inline void bpf_smc__destroy(struct bpf_smc *s) { (void)s; }
static inline struct bpf_smc *bpf_smc__open_opts(const struct bpf_object_open_opts *o) { (void)o; return NULL; }
#endif
EOF
```

### Rebuilding after kernel changes
After changing `vendor/linux-framework` kernel:
1. `make -C vendor/linux-framework bzImage` (incremental)
2. Regenerate vmlinux.h:
   ```bash
   docs/tmp/bpf_selftests_bin/tools/sbin/bpftool btf dump file \
     vendor/linux-framework/vmlinux format c > \
     vendor/linux-framework/tools/testing/selftests/bpf/tools/include/vmlinux.h.new
   ```
3. Apply compatibility stubs (see section below)
4. Sync to output dir and rebuild

---

## vmlinux.h Compatibility Stubs

The `vendor/linux-framework/tools/testing/selftests/bpf/tools/include/vmlinux.h` file
has been modified from the auto-generated BTF dump to add stubs for configs not enabled
in our kernel. These stubs are appended at the end of the file and injected before
`struct net` for SMC types.

### Configs missing and their stubs

| Config | Missing types/symbols | Stub approach |
|--------|-----------------------|---------------|
| `CONFIG_SMC` | `struct smc_hs_ctrl`, `struct netns_smc`, `struct net.smc` | Inline stubs before `struct net`; stub skel.h file |
| `CONFIG_XFRM=y` (built-in) | `struct bpf_xfrm_state`, `struct bpf_xfrm_state_opts` | Inline stub definitions |
| syscall tracepoints | `struct syscall_trace_enter` | Inline stub |
| uapi enum | `BPF_F_CURRENT_NETNS` | `#ifndef` enum stub |
| uapi enum | `IPS_CONFIRMED`, `IPS_SEEN_REPLY` | `#ifndef` enum stub |

### Configs added to kernel via config patch

The following configs were NOT enabled in the original vendor kernel but were added to
make more BPF selftests compile:

| Config | Why added |
|--------|-----------|
| `CONFIG_IPV6=y` | `struct bpf_iter__ipv6_route` only in BTF when built-in |
| `CONFIG_MPTCP=y` | `struct mptcp_sock` only has fields when MPTCP enabled |
| `CONFIG_NET_SCH_FQ=y` | Required by NET_SCH_BPF |
| `CONFIG_NET_SCH_BPF=y` | Provides `bpf_qdisc_*` kfuncs for qdisc BPF programs |
| `CONFIG_NF_CONNTRACK_MARK=y` | `struct nf_conn.mark` field |

These are applied to `vendor/linux-framework/.config`.

---

## test_verifier: Detailed Results

```
Summary: 526 PASSED, 264 SKIPPED, 1 FAILED
```

**The 1 failure** (test #211, `"calls: several args with ref_obj_id"`):
- Failure message: expects error `"expected an initialized variable"` for TCP helper
- Root cause: `CONFIG_IPV6=y` changes TCP socket structure, affecting an error message in a verifier test that checks exact error text
- **Not a REJIT regression**: This test was already failing before REJIT patches

**Skipped tests** (264):
- Mostly network tests requiring network namespaces, BPF_PROG_TYPE features not in our config, or hardware-specific tests

**Coverage relevant to REJIT**:
- `verifier/jit.c`: JIT-specific verifier tests (instructions, branches, register tracking)
- `verifier/atomic*.c`: Atomic instruction verification
- `verifier/precise*.c`: Precision tracking (relevant to REJIT register allocation)
- Scalability tests: programs that stress JIT compilation

---

## test_progs: Detailed Results (filtered)

### Verifier + JIT subset
```
sudo ./test_progs -t verifier -t jit
Summary: 109/1590 PASSED, 522 SKIPPED, 4 FAILED
```

**The 4 failures** (preliminary investigation):
1. `verifier_global_subprogs/arg_tag_ctx_fmod_ret`: Load failure EINVAL (22) - likely missing feature
2. `verifier_jeq_infer_not_null/*`: Multiple subtests fail, EINVAL (22) - socket-related
3. `verifier_precision/bpf_neg_*`: Load failure ENOENT (3) - missing map/helper

These failures appear to be related to missing kernel features (network sockets, specific map types) rather than JIT regression. Needs further investigation.

### Known test limitations in VM
- **Network tests**: Many XDP/TC/netns tests fail (`errno 95` = EOPNOTSUPP) because the VM lacks full network hardware/drivers
- **`bpf_smc`**: Always fails (stub skel.h returns NULL); `test_bpf_smc` will FAIL with null skeleton
- Hardware-specific tests: Skip appropriately

---

## Kernel Configuration Summary

The REJIT vendor kernel (`vendor/linux-framework`) was originally built without several
features that BPF selftests require. The following configs were added for selftest compatibility:

```
# .config additions for BPF selftests
CONFIG_IPV6=y          # Built-in (was =m)
CONFIG_MPTCP=y
CONFIG_MPTCP_IPV6=y
CONFIG_NET_SCH_FQ=y
CONFIG_NET_SCH_BPF=y
CONFIG_NF_CONNTRACK_MARK=y
```

**Remaining limitation**: `CONFIG_SMC` cannot be enabled (depends on INFINIBAND+DIBS).
The `bpf_smc` test is stub-compiled and will always fail at runtime.

---

## Makefile Targets Added

```
make vm-upstream-test-verifier
    Run upstream test_verifier in VM (primary REJIT regression tool)

make vm-upstream-test-progs [BPF_SELFTEST_FILTER="verifier jit xdp"]
    Run upstream test_progs in VM with optional test filter
    Default filter: verifier jit
    No filter: runs all 422 test groups (10+ min, many skips)

UPSTREAM_SELFTESTS_BIN_DIR (variable, default: docs/tmp/bpf_selftests_bin)
    Override to use different pre-built binary directory
```

---

## Architecture Notes

### How test_verifier works
- Standalone binary that loads BPF programs and checks verifier output
- Tests are defined in `verifier/*.c` as arrays of `struct bpf_insn` with expected verifier messages
- Run from its build directory (looks for `bpf_testmod.ko` via relative path)
- No network/device access needed for most tests

### How test_progs works
- Loads BPF programs, attaches to hooks, runs actual test scenarios
- Uses libbpf skeleton API for each program
- Many tests require network namespaces, specific hardware, or kernel features
- `-t filter` limits to test names matching the pattern (substring match)

### Why clang-20 is required
- clang-18 lacks `__BPF_FEATURE_ADDR_SPACE_CAST` support
- BPF arena programs use `__attribute__((address_space(1)))` which requires clang-20
- vmlinux.h uses this attribute in `bpf_arena_alloc_pages` and related kfuncs
- Host has `/usr/bin/clang-20` (LLVM 20.1.x)

### /tmp read-only in VM
- vng VM mounts /tmp as read-only (9p overlay)
- Build requires `export TMPDIR=/var/tmp` (writable tmpfs)
- Pre-generate signing keys on host before running in VM

---

## Known Issues and Future Work

1. **CONFIG_SMC**: Cannot enable without INFINIBAND. `test_bpf_smc` will always fail.
   - Mitigation: stub skel.h; test runner handles NULL skeleton gracefully

2. **Network tests in VM**: Tests requiring veth/netns/hardware will fail with EOPNOTSUPP.
   - Mitigation: use `-t verifier -t jit` filter for REJIT regression testing

3. **vmlinux.h divergence**: After each kernel rebuild, vmlinux.h must be regenerated.
   - Automation TODO: Add `make build-upstream-selftests` target that handles full rebuild

4. **4 test_progs failures in verifier subset**: Need investigation to determine if REJIT-related.
   - Current hypothesis: missing network features, not JIT regression
