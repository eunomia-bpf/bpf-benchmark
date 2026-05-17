# x86 eBPF VM Prototype

This prototype asks one small question: can an eBPF program interpret a compact
x86-like instruction stream and pass the normal eBPF verifier?

The initial smoke case mirrors `micro/programs/simple.bpf.c`:

```c
*out = 12345678ULL;
```

The hardcoded verifier artifact represents this x86-like instruction sequence:

```text
mov rax, 12345678
ret
```

The BPF program interprets the hardcoded instruction stream, writes `rax` to the
first eight packet bytes, and returns `XDP_PASS`. The loader runs it with
`BPF_PROG_TEST_RUN` and checks that the output value is `12345678`.

The instruction sequence is hardcoded in the `.bpf.c` file, while all VM
machinery lives in headers.

The specialized artifact is the more relevant ReverseJIT direction. It uses a
single include plus one macro-expanded call per native instruction:

```c
#include "x86_vm_bpf.h"

SEC("xdp")
int x86_vm_hardcoded_xdp(struct xdp_md *ctx)
{
	return X86_VM_BEGIN_XDP(ctx)
	/* 0x0: mov rax, 12345678 */
	X86_VM_STEP(X86_OP_MOV_IMM64, X86_RAX, 0, 0, 0, 12345678ULL)
	/* 0x5: ret */
	X86_VM_STEP(X86_OP_RET, 0, 0, 0, 0, 0)
	X86_VM_END_XDP();
}
```

The program is not a global variable, is not a local BPF stack array, and is not
emitted as a `.rodata` map. Each instruction field is a compile-time immediate.
`x86_vm_bpf.h` includes the BPF entry helpers, result writer, and per-instruction
execution macros. `x86_interp.h` contains the instruction semantics. LLVM
currently folds the two-instruction `simple` case into straight-line BPF that
writes `12345678` directly.

## Build And Run

```sh
make -C ebpf-vm/x86 run
```

This is a functional prototype, not a benchmark entrypoint.

If unprivileged BPF is disabled, build as the normal user and run the loader with
privilege:

```sh
make -C ebpf-vm/x86 build
sudo ebpf-vm/loader/target/debug/ebpf-vm-loader \
  --object ebpf-vm/x86/build/x86_vm_hardcoded.bpf.o \
  --program x86_vm_hardcoded_xdp \
  --case simple
```

Observed smoke result:

```text
case=simple retval=2 result=12345678 repeat=1 data_size_out=48
```

Object inspection for the hardcoded artifact:

```text
no .maps section
no .rodata section
xdp section size: 0xa0 bytes
```

Supported opcodes:

- `0x01`: `mov r64, imm64`
- `0x02`: `mov r64, r64`
- `0x03`: `add r64, imm64`
- `0x04`: `add r64, r64`
- `0x05`: `xor r32, r32` with x86 zero-extension semantics
- `0xff`: `ret`

Register numbers follow the usual x86 encoding order: `rax=0`, `rcx=1`,
`rdx=2`, `rbx=3`, `rsp=4`, `rbp=5`, `rsi=6`, `rdi=7`, `r8=8`, ... `r15=15`.

## Micro Program Status

Status comes from the current generated x86 proof batch using
`BPF_PROG_TEST_RUN`. `ok` means compile, verifier load, run, and expected-result
check all passed. `run-fail` means the object compiled but verifier load or
runtime result check failed. `compile-fail` means clang could not produce the
BPF object in the current proof shape. `pending` means the current batch has not
finished that program yet.

| Micro program | Input mode | Expected result | Status | Note |
| --- | --- | ---: | --- | --- |
| `simple` | `packet` | `12345678` | ok | |
| `simple_packet` | `packet` | `12345678` | ok | |
| `bitmap_popcount_scan` | `packet` | `12830754992348206170` | ok | |
| `sorted_rule_binary_search` | `packet` | `126` | ok | |
| `bcc_runqlat_log2_histogram_bucket` | `packet` | `17790125373615940312` | ok | |
| `trace_event_type_switch_dispatch` | `packet` | `16` | ok | |
| `packet_checksum_fold` | `packet` | `0` | ok | loop canonicalized for verifier |
| `payload_prefix_memcmp_scan` | `packet` | `9377358970524074984` | ok | fixed LEA base+index*scale |
| `packet_vlan_tcpopt_parser` | `packet` | `7124500222221` | ok | |
| `bpf_local_call_fanout_dispatch` | `packet` | `1171593469689687806` | run-fail | verifier complexity: 8193 jumps |
| `flow_5tuple_rss_hash` | `packet` | `11016707074064960918` | ok | |
| `katran_lb_consistent_hash_select` | `packet` | `5895923248507644458` | compile-fail | clang stuck on huge generic proof |
| `cilium_policy_guard_tree_filter` | `packet` | `5333736376993440184` | run-fail | needs log triage |
| `siphash_rotate64_mixer` | `packet` | `2666935177028490406` | compile-fail | clang stuck on huge generic proof |
| `packet_record_bounds_window` | `packet` | `1610777047308888911` | ok | |
| `flow_record_field_scan` | `packet` | `9354240374969449171` | ok | |
| `packed_header_bitfield_decode` | `packet` | `12211926182125163441` | compile-fail | clang stuck on huge generic proof |
| `bpftrace_string_search_prefix_scan` | `packet` | `15111065535037762995` | pending | |
| `tracee_syscall_name_table_lookup` | `packet` | `4063733557757466536` | pending | |
| `tracee_http_method_prefix_detect` | `packet` | `11562433829591280482` | pending | |
| `cilium_socket_lb_service_select` | `packet` | `2868565165525030065` | pending | |
| `bcc_tcpconnect_ipv4_tuple_filter` | `packet` | `18109187572642697766` | pending | |
| `tetragon_process_event_arg_filter` | `packet` | `12641586655603153431` | pending | |
| `otel_stack_frame_unwind_scan` | `packet` | `12043289854646947360` | pending | |
| `cilium_ct_nat_tuple_rewrite` | `packet` | `14199193300769829204` | pending | |
| `packet_toeplitz_rss_hash` | `packet` | `13526464303109995596` | pending | |
| `bpftrace_comm_key_fnv_hash` | `packet` | `8524536671075880526` | pending | |
| `tc_packet_checksum_fold` | `staged` | `0` | not-run | current loader only runs XDP proof objects |
| `cgroup_skb_hash_chain` | `staged` | `12027228624407116210` | not-run | current loader only runs XDP proof objects |

## Current Issues

This prototype has already exposed several verifier-facing design constraints:

- Hardcoding the guest instruction stream as C data is not enough. Large local
  arrays become BPF stack pressure, so generated proof sources use one immediate
  macro call per native instruction.
- The verifier does not reliably recover packet ranges from a generic
  `packet + variable_index + negative_disp` helper. `packet_checksum_fold`
  needed loop canonicalization from `rdx + rcx - 3/-1` to the equivalent
  positive offsets `packet + 16/18 + 4*i`.
- Input-dependent interpreter loops are a state-explosion risk. The current
  generator hardcodes the instruction sequence and normalizes known bounded
  loops so the verifier sees constants and bounded `bpf_loop` trip counts.
- Native stack state must be modeled explicitly for programs with `push`, `pop`,
  or `[rsp]` accesses. A generic pointer-tag path made the verifier explore
  impossible `rsp`-as-packet states, so RSP stack accesses now need dedicated
  stack fast paths.
- `bpf_local_call_fanout_dispatch` showed that dumping only the entry symbol is
  incomplete for native direct calls. The generator now rebuilds the native
  object and disassembles call-target symbols when the markdown `## Native ASM`
  block has unresolved call targets.
- The current full local-call proof still fails verifier complexity:
  `The sequence of 8193 jumps is too complex`. Splitting call targets into BPF
  subprograms makes clang compile, but each instruction still expands through
  the generic `x86_exec_one` branch tree. The next design step is generated
  per-op BPF semantics instead of a branchy interpreter body for large programs.

For formal verification, clang optimization is not part of the trusted
argument. This C implementation is a prototype for finding the VM semantics and
verifier constraints. A real proof should target either the actual compiled BPF
bytecode or a generated/handwritten eBPF instruction sequence with a small,
specified translation relation to native x86 emission.
