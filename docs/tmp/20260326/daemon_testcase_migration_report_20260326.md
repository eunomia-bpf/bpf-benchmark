# Daemon Real `.bpf.o` Test Migration Report

Date: 2026-03-26

## Outcome

- Implemented a real ELF parser and real-object test harness for daemon pass tests without requiring kernel or VM execution.
- Added committed `.bpf.o` fixtures under `daemon/tests/fixtures/` and added real-object coverage for all 15 passes.
- Preserved the existing hand-written edge-case tests; the real-object tests are additional coverage.
- Verified with the canonical repo target:
  - `make daemon-tests`
  - Result: `513` total tests, `501` passed, `12` ignored, `0` failed

## ELF Parser Changes

Implemented `daemon/src/elf_parser.rs` and switched the legacy test helper in `daemon/src/insn.rs` to use it.

The parser now:

- Parses all executable eBPF program sections from a `.bpf.o`
- Decodes instructions per program section
- Infers `prog_type` from section name
- Parses `.maps` map symbols and raw map definitions
- Parses `.BTF` plus `.rel.BTF`
- Resolves program map relocations for `LD_IMM64` map references
- Returns structured object metadata:
  - object path
  - program list
  - per-program instructions
  - per-program used map indices
  - parsed map metadata

Dependency change:

- Added `goblin` to `daemon/Cargo.toml`

Compatibility note:

- `load_bpf_insns_from_elf()` still works for older tests, but now delegates to the new parser and returns the first parsed program's instructions.

## Test Harness Changes

Added `daemon/src/test_utils.rs` for shared real-object testing support:

- fixture path loading
- program selection by section name
- synthetic map installation for map-dependent passes
- permissive `PassContext` construction
- mock branch profiling injection
- structural BPF validation after transforms

The structural validator was updated to support real ELF sections that contain multiple subprograms in one section. It now validates:

- non-empty program
- at least one `EXIT`
- no truncated `LD_IMM64`
- no branch or pseudo-call targets outside the program
- no branch or pseudo-call into an `LD_IMM64` continuation slot

It no longer incorrectly requires the entire section to end in a single final `EXIT`.

## Fixture Inventory

Committed fixtures under `daemon/tests/fixtures/`:

- `bcc/libbpf-tools/bindsnoop.bpf.o`
- `bcc/libbpf-tools/tcplife.bpf.o`
- `calico/from_hep_debug.bpf.o`
- `calico/to_hep_debug.bpf.o`
- `cilium/bpf_lxc.bpf.o`
- `cilium/bpf_overlay.bpf.o`
- `cilium/bpf_xdp.bpf.o`
- `katran/xdp_pktcntr.bpf.o`
- `linux-selftests/tools/testing/selftests/bpf/progs/decap_sanity.bpf.o`
- `linux-selftests/tools/testing/selftests/bpf/progs/test_endian.bpf.o`
- `tracee/tracee.bpf.o`
- `xdp-tools/xdp_flowtable.bpf.o`
- `xdp-tools/xdp_load_bytes.bpf.o`

Total committed fixtures: `13`

## Real Test Coverage

Added `44` real `.bpf.o` tests in `daemon/src/passes/mod.rs`:

- `38` single-pass real-object tests
- `6` pipeline real-object tests

Coverage by pass:

- `map_inline`: katran, bindsnoop, cilium xdp
- `const_prop`: `map_inline -> const_prop` on katran, bindsnoop, cilium xdp
- `dce`: `map_inline -> const_prop -> dce` on katran, bindsnoop, cilium xdp
- `skb_load_bytes_spec`: cilium lxc `tc/tail`, cilium overlay `tc/tail`, selftest `decap_sanity`
- `bounds_check_merge`: cilium xdp, xdp-flowtable, calico from-hep
- `wide_mem`: cilium xdp, cilium lxc, calico to-hep
- `bulk_memory`: calico to-hep, calico from-hep, xdp-flowtable
- `rotate`: cilium xdp, cilium lxc
- `cond_select`: cilium xdp tail, cilium lxc tail, calico to-hep
- `extract`: cilium xdp, calico to-hep, tracee
- `endian_fusion`: kernel selftest `test_endian`, calico to-hep, cilium lxc
- `branch_flip`: cilium xdp, cilium lxc, tracee
- `speculation_barrier`: cilium xdp, cilium lxc, tracee
- `dangerous_helper_firewall`: tracee `kprobe/check_helper_call`, tcplife, calico from-hep
- `live_patch`: cilium lxc, calico from-hep, tracee

## Notes From Migration

### `skb_load_bytes_spec`

Initial candidate sections such as `cilium/bpf_lxc.bpf.o:tc/entry` and Calico `tc` sections were real no-op cases under the actual pass because the helper sites did not keep `arg1 == ctx` at the callsite.

Final changed fixtures are:

- `cilium/bpf_lxc.bpf.o:tc/tail`
- `cilium/bpf_overlay.bpf.o:tc/tail`
- `linux-selftests/.../decap_sanity.bpf.o:tc`

### `bounds_check_merge`

The review doc identified strong heuristic candidates, but running the actual pass logic against the available corpus did not produce any changed real-object sections. For that reason, the three real `.bpf.o` tests for `bounds_check_merge` are structural smoke tests:

- they verify the pass runs on real packet programs
- they verify the output remains structurally valid BPF
- they do not assert `changed == true`

Hand-written tests remain the source of exact rewrite-shape coverage for this pass.

### `dangerous_helper_firewall`

The initial Tracee section used for testing only contained audit-only helper sites. The final Tracee test was moved to `kprobe/check_helper_call`, which exercises a real rewrite path.

## Files Added Or Changed For This Work

- `daemon/Cargo.toml`
- `daemon/Cargo.lock`
- `daemon/src/main.rs`
- `daemon/src/insn.rs`
- `daemon/src/elf_parser.rs`
- `daemon/src/test_utils.rs`
- `daemon/src/passes/mod.rs`
- `daemon/tests/fixtures/**`

## Verification

Executed on 2026-03-26:

```bash
make daemon-tests
```

Observed result:

```text
running 513 tests
test result: ok. 501 passed; 0 failed; 12 ignored; 0 measured; 0 filtered out
```

No kernel, VM, module loading, or host `bpftool` actions were used for this migration.
