# Phase 1 CLI Host Smoke Validation

Date: 2026-04-28

Repository HEAD: `e68ddbd6`

Binary directory: `bpfopt/target/release`

Host note: `/proc/sys/kernel/unprivileged_bpf_disabled` is `2`, so live BPF program enumeration/open by the normal user fails with `EPERM`. I ran the requested non-root commands and added `sudo -n` supplemental checks to validate the same live-kernel CLI paths with BPF privileges.

## Setup

Command:

```sh
cd bpfopt
cargo build --release
```

Output:

```text
   Compiling bpfverify v0.1.0 (/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/bpfverify)
   Compiling bpfprof v0.1.0 (/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/bpfprof)
    Finished `release` profile [optimized] target(s) in 4.75s
```

Status: PASS

Release binaries used:

```text
/home/yunwei37/workspace/bpf-benchmark/bpfopt/target/release/bpfopt
/home/yunwei37/workspace/bpf-benchmark/bpfopt/target/release/bpfget
/home/yunwei37/workspace/bpf-benchmark/bpfopt/target/release/bpfrejit
```

Minimal bytecode input:

```sh
printf '\xb7\x00\x00\x00\x00\x00\x00\x00\x95\x00\x00\x00\x00\x00\x00\x00' > /tmp/min.bin
```

## bpfopt

Command:

```sh
$BIN/bpfopt list-passes
```

Exit: 0

Stdout:

```text
map-inline
const-prop
dce
skb-load-bytes
bounds-check-merge
wide-mem
bulk-memory
rotate
cond-select
extract
endian
branch-flip
```

Stderr: empty

Check: 12 lines

Status: PASS

Command:

```sh
$BIN/bpfopt list-passes --json
```

Exit: 0

Stdout:

```json
[
  {
    "name": "map-inline",
    "canonical_name": "map_inline",
    "description": "Inline stable map lookups and frozen pseudo-map-value loads"
  },
  {
    "name": "const-prop",
    "canonical_name": "const_prop",
    "description": "Fold register constants into MOV/LD_IMM64/JA rewrites"
  },
  {
    "name": "dce",
    "canonical_name": "dce",
    "description": "Remove CFG-unreachable blocks and NOPs after simplification"
  },
  {
    "name": "skb-load-bytes",
    "canonical_name": "skb_load_bytes_spec",
    "description": "Specialize eligible skb_load_bytes helper sites into direct packet access"
  },
  {
    "name": "bounds-check-merge",
    "canonical_name": "bounds_check_merge",
    "description": "Merge direct packet bounds-check ladders into a dominant guard"
  },
  {
    "name": "wide-mem",
    "canonical_name": "wide_mem",
    "description": "Fuse byte-by-byte loads into wider memory accesses"
  },
  {
    "name": "bulk-memory",
    "canonical_name": "bulk_memory",
    "description": "Lower large scalarized memcpy/memset runs into bulk-memory kinsn calls"
  },
  {
    "name": "rotate",
    "canonical_name": "rotate",
    "description": "Replace shift+or patterns with rotate kfunc (ROL/ROR)"
  },
  {
    "name": "cond-select",
    "canonical_name": "cond_select",
    "description": "Replace branch-over-mov with conditional select kfunc (CMOV/CSEL)"
  },
  {
    "name": "extract",
    "canonical_name": "extract",
    "description": "Replace shift+mask with bit field extract kfunc (BEXTR)"
  },
  {
    "name": "endian",
    "canonical_name": "endian_fusion",
    "description": "Fuse endian swap patterns into endian load kfunc (MOVBE)"
  },
  {
    "name": "branch-flip",
    "canonical_name": "branch_flip",
    "description": "Flip branch polarity using PGO data to improve branch prediction"
  }
]
```

Stderr: empty

Check: valid JSON array, length 12

Status: PASS

Command:

```sh
$BIN/bpfopt --help
```

Exit: 0

Stdout:

```text
BPF bytecode optimizer

Usage: bpfopt [OPTIONS] <COMMAND>

Commands:
  wide-mem            Fuse byte-by-byte loads into wider memory accesses
  rotate              Replace shift+or patterns with rotate kinsn calls
  const-prop          Fold register constants
  cond-select         Replace branch-over-mov with conditional select kinsn calls
  extract             Replace shift+mask with bit-field extract kinsn calls
  endian              Fuse endian load+swap sequences
  branch-flip         Reorder if/else bodies using PGO profile data
  dce                 Remove unreachable blocks, NOPs, and dead register definitions
  map-inline          Inline stable map lookup values
  bulk-memory         Lower large memcpy/memset runs into bulk-memory kinsn calls
  bounds-check-merge  Merge packet bounds-check ladders
  skb-load-bytes      Specialize skb_load_bytes helper sites
  optimize            Run a pass pipeline in-process
  analyze             Emit a JSON analysis summary
  list-passes         List available optimization passes
  help                Print this message or the help of the given subcommand(s)

Options:
      --input <FILE>            Input bytecode file. Defaults to stdin
      --output <FILE>           Output bytecode or JSON file. Defaults to stdout
      --report <FILE>           Pass report JSON output file
      --platform <ARCH>         Target architecture: x86_64 or aarch64
      --kinsns <LIST>           Available kinsns, comma-separated. Entries may be name or name:btf_id
      --target <FILE>           Target platform JSON file
      --profile <FILE>          PGO profile JSON file
      --verifier-states <FILE>  Verifier states JSON file
      --map-values <FILE>       Map values JSON file
      --map-ids <LIST>          Map IDs used by the program, comma-separated in kernel used_maps order
  -h, --help                    Print help
  -V, --version                 Print version
```

Stderr: empty

Status: PASS

Command:

```sh
$BIN/bpfopt analyze < /tmp/min.bin
```

Exit: 0

Stdout:

```json
{
  "insn_count": 2,
  "subprog_count": 1,
  "map_lookups": [],
  "kinsn_calls": [],
  "ld_imm64_count": 0,
  "branch_count": 0
}
```

Stderr: empty

Check: valid JSON, `insn_count=2`

Status: PASS

Command:

```sh
$BIN/bpfopt wide-mem < /tmp/min.bin > /tmp/out.bin
```

Exit: 0

Stdout: binary output redirected

Stderr: empty

Check:

```text
wide-mem-cmp=same
sha256(/tmp/min.bin)=59f4a931744dcdc62944a018ed3990e666ec6444616418d3b09a82dc5c753d52
sha256(/tmp/out.bin)=59f4a931744dcdc62944a018ed3990e666ec6444616418d3b09a82dc5c753d52
```

Status: PASS

Command:

```sh
$BIN/bpfopt wide-mem --report /tmp/r.json < /tmp/min.bin > /tmp/out.bin
```

Exit: 0

Stdout: binary output redirected

Stderr: empty

Report JSON:

```json
{
  "pass": "wide_mem",
  "changed": false,
  "sites_applied": 0,
  "insn_count_before": 2,
  "insn_count_after": 2,
  "insn_delta": 0
}
```

Check: valid JSON, `changed=false`, output binary matches input

Status: PASS

Command:

```sh
$BIN/bpfopt optimize --report /tmp/r.json < /tmp/min.bin > /tmp/out.bin
```

Exit: 0

Stdout: binary output redirected

Stderr: empty

Report JSON:

```json
{
  "passes": [
    {
      "pass": "dce",
      "changed": false,
      "sites_applied": 0,
      "insn_count_before": 2,
      "insn_count_after": 2,
      "insn_delta": 0
    },
    {
      "pass": "skb_load_bytes_spec",
      "changed": false,
      "sites_applied": 0,
      "insn_count_before": 2,
      "insn_count_after": 2,
      "insn_delta": 0
    },
    {
      "pass": "bounds_check_merge",
      "changed": false,
      "sites_applied": 0,
      "insn_count_before": 2,
      "insn_count_after": 2,
      "insn_delta": 0
    },
    {
      "pass": "wide_mem",
      "changed": false,
      "sites_applied": 0,
      "insn_count_before": 2,
      "insn_count_after": 2,
      "insn_delta": 0
    }
  ]
}
```

Check: valid JSON, `passes` is an array with 4 entries, output binary matches input

Status: PASS

Command:

```sh
$BIN/bpfopt optimize --passes wide-mem,dce --report /tmp/r.json < /tmp/min.bin > /tmp/out.bin
```

Exit: 0

Stdout: binary output redirected

Stderr: empty

Report JSON:

```json
{
  "passes": [
    {
      "pass": "wide_mem",
      "changed": false,
      "sites_applied": 0,
      "insn_count_before": 2,
      "insn_count_after": 2,
      "insn_delta": 0
    },
    {
      "pass": "dce",
      "changed": false,
      "sites_applied": 0,
      "insn_count_before": 2,
      "insn_count_after": 2,
      "insn_delta": 0
    }
  ]
}
```

Check: pass names are exactly `wide_mem,dce`, output binary matches input

Status: PASS

Command:

```sh
$BIN/bpfopt const-prop < /tmp/min.bin
```

Exit: 1

Stdout: empty

Stderr:

```text
error: const-prop requires --verifier-states
```

Status: PASS

Command:

```sh
echo -n "12345" | $BIN/bpfopt wide-mem
```

Exit: 1

Stdout: empty

Stderr:

```text
error: bytecode length 5 is not a multiple of 8 bytes
```

Status: PASS

Command:

```sh
printf '%s' '{"arch":"x86_64","features":["cmov"],"kinsns":{}}' > /tmp/empty-target.json
$BIN/bpfopt rotate --target /tmp/empty-target.json < /tmp/min.bin
```

Exit: 1

Stdout: empty

Stderr:

```text
error: kinsn 'bpf_rotate64' not in target
```

Status: PASS

## bpfget

Command:

```sh
$BIN/bpfget --list
```

Exit: 1

Stdout: empty

Stderr:

```text
enumerate BPF programs after id 0: BPF_PROG_GET_NEXT_ID: Operation not permitted (os error 1)
```

Status: FAIL for the exact non-root command. The error is friendly and stays on stderr, but the expected smoke result was exit 0. This host denies unprivileged BPF enumeration.

Supplemental privileged command:

```sh
sudo -n $BIN/bpfget --list
```

Exit: 0

Stdout:

```text
25 sd_devices cgroup_device
26 sd_devices cgroup_device
27 sd_fw_egress cgroup_skb
28 sd_fw_ingress cgroup_skb
29 sd_devices cgroup_device
30 sd_devices cgroup_device
31 sd_devices cgroup_device
32 sd_fw_egress cgroup_skb
33 sd_fw_ingress cgroup_skb
34 sd_fw_egress cgroup_skb
35 sd_fw_ingress cgroup_skb
36 sd_devices cgroup_device
40 sd_devices cgroup_device
41 sd_fw_egress cgroup_skb
42 sd_fw_ingress cgroup_skb
43 sd_devices cgroup_device
44 sd_devices cgroup_device
45 sd_fw_egress cgroup_skb
46 sd_fw_ingress cgroup_skb
47 sd_fw_egress cgroup_skb
48 sd_fw_ingress cgroup_skb
49 s_cups_cupsd cgroup_device
53 s_snapd_desktop cgroup_device
54 s_snapd_desktop cgroup_device
1522 s_snapd_desktop cgroup_device
```

Supplemental status: PASS

Command:

```sh
$BIN/bpfget --list --json
```

Exit: 1

Stdout: empty

Stderr:

```text
enumerate BPF programs after id 0: BPF_PROG_GET_NEXT_ID: Operation not permitted (os error 1)
```

Status: FAIL for the exact non-root command. Expected JSON array was not produced because the kernel rejected enumeration before output.

Supplemental privileged command:

```sh
sudo -n $BIN/bpfget --list --json
```

Exit: 0

Checks:

```text
stdout JSON type=array
array length=25
stderr=empty
```

Supplemental status: PASS

Command:

```sh
$BIN/bpfget 999999999
```

Exit: 1

Stdout: empty

Stderr:

```text
open BPF program id 999999999: BPF_PROG_GET_FD_BY_ID: Operation not permitted (os error 1)
```

Status: FAIL for the intended not-found path under the exact non-root command. The message is friendly and contextual, but permission denied occurs before the nonexistent-ID path.

Supplemental privileged command:

```sh
sudo -n $BIN/bpfget 999999999
```

Exit: 1

Stdout: empty

Stderr:

```text
open BPF program id 999999999: BPF_PROG_GET_FD_BY_ID: No such file or directory (os error 2)
```

Supplemental status: PASS

Command:

```sh
$BIN/bpfget --help
```

Exit: 0

Stdout:

```text
Read live BPF program bytecode and metadata

Usage: bpfget [OPTIONS] [PROG_ID]

Arguments:
  [PROG_ID]  Live BPF program ID. Not used with --list or --target

Options:
      --info           Write program metadata JSON
      --full           Write prog.bin, prog_info.json, and map_fds.json to --outdir
      --outdir <DIR>   Output directory for --full
      --list           List live BPF programs
      --json           Use JSON output for --list
      --target         Write target.json for the host platform
      --output <FILE>  Output file. Defaults to stdout
      --kinsns <LIST>  Manual kinsn descriptors for --target, comma-separated name:btf_func_id
  -h, --help           Print help
  -V, --version        Print version
```

Stderr: empty

Status: PASS

## bpfrejit

Command:

```sh
$BIN/bpfrejit 999999999 /tmp/min.bin
```

Exit: 1

Stdout: empty

Stderr:

```text
open BPF program id 999999999: BPF_PROG_GET_FD_BY_ID: Operation not permitted (os error 1)
```

Status: FAIL for the intended not-found path under the exact non-root command. The error is friendly and separated from stdout, but host permissions prevent reaching the nonexistent-ID result.

Supplemental privileged command:

```sh
sudo -n $BIN/bpfrejit 999999999 /tmp/min.bin
```

Exit: 1

Stdout: empty

Stderr:

```text
open BPF program id 999999999: BPF_PROG_GET_FD_BY_ID: No such file or directory (os error 2)
```

Supplemental status: PASS

Command:

```sh
echo -n "1234567890" | $BIN/bpfrejit 0
```

Exit: 1

Stdout: empty

Stderr:

```text
input bytecode length 10 is not a multiple of 8
```

Status: PASS

Command:

```sh
$BIN/bpfrejit --help
```

Exit: 0

Stdout:

```text
Submit replacement BPF bytecode

Usage: bpfrejit [OPTIONS] <PROG_ID> [FILE]

Arguments:
  <PROG_ID>  Live BPF program ID
  [FILE]     Raw struct bpf_insn[] input file. Defaults to stdin

Options:
      --fd-array <FILE>  kinsn fd_array JSON manifest
      --dry-run          Verify the bytecode with BPF_PROG_LOAD and do not call BPF_PROG_REJIT
      --output <FILE>    Optional summary JSON output file
  -h, --help             Print help
  -V, --version          Print version
```

Stderr: empty

Status: PASS

## Pipeline Tests

Command:

```sh
$BIN/bpfopt list-passes | head -3
```

Exit: 0

Stdout:

```text
map-inline
const-prop
dce
```

Stderr: empty

Status: PASS

Command:

```sh
find micro/cases -name '*.bpf.o' -print
```

Exit: 1

Stdout: empty

Stderr:

```text
find: '/home/yunwei37/workspace/bpf-benchmark/micro/cases': No such file or directory
```

Status: SKIPPED for the exact `micro/cases/*` input path because this checkout has no `micro/cases` directory.

Fallback bytecode source used for the same stdin/stdout protocol check:

```text
.cache/micro-programs/x86_64/simple.bpf.o
```

Command:

```sh
llvm-objcopy --dump-section=xdp=/tmp/simple-xdp.bin .cache/micro-programs/x86_64/simple.bpf.o /tmp/simple-copy.bpf.o
$BIN/bpfopt analyze < /tmp/simple-xdp.bin
```

Exit: 0

Stdout:

```json
{
  "insn_count": 24,
  "subprog_count": 1,
  "map_lookups": [],
  "kinsn_calls": [],
  "ld_imm64_count": 0,
  "branch_count": 3
}
```

Stderr: empty

Status: PASS

Command:

```sh
for f in .cache/micro-programs/x86_64/*.bpf.o; do
  section=$(llvm-readelf -S "$f" | awk '$4=="PROGBITS" && $7!="000000" && $9 ~ /AX/ {print $3; exit}')
  llvm-objcopy --dump-section="$section=/tmp/prog.bin" "$f" /tmp/prog.copy
  $BIN/bpfopt analyze < /tmp/prog.bin
done
```

Summary output:

```text
count	62
failures	0
sections	.text=3,cgroup_skb/egress=1,xdp=56,tc=2
first10
addr_calc_stride.bpf.o	xdp	PASS	147
alu32_64_pingpong.bpf.o	xdp	PASS	148
binary_search.bpf.o	xdp	PASS	180
bitcount.bpf.o	xdp	PASS	130
bitfield_extract.bpf.o	xdp	PASS	247
bounds_check_heavy.bpf.o	xdp	PASS	699
bounds_ladder.bpf.o	xdp	PASS	180
bpf_call_chain.bpf.o	.text	PASS	103
branch_dense.bpf.o	xdp	PASS	177
branch_fanout_32.bpf.o	xdp	PASS	423
```

Status: PASS

## Failed Or Skipped Cases

- FAIL: exact non-root `$BIN/bpfget --list` returned EPERM instead of exit 0 because host unprivileged BPF is disabled.
- FAIL: exact non-root `$BIN/bpfget --list --json` returned EPERM and no JSON for the same host permission reason.
- FAIL: exact non-root `$BIN/bpfget 999999999` returned EPERM before reaching the expected nonexistent-ID path. Privileged supplemental run returned `No such file or directory`.
- FAIL: exact non-root `$BIN/bpfrejit 999999999 /tmp/min.bin` returned EPERM before reaching the expected nonexistent-ID path. Privileged supplemental run returned `No such file or directory`.
- SKIPPED: exact `micro/cases/*.bpf.o` path is absent in this checkout. The equivalent available generated micro bytecode under `.cache/micro-programs/x86_64` analyzed successfully.

## Conclusion

The Phase 1 pure bytecode CLI path is ready for benchmark integration: `bpfopt` release commands run, stdin/stdout raw `struct bpf_insn[]` protocol is correct, reports are valid JSON, no-op output remains byte-identical, and error messages stay on stderr with useful flag or context.

`bpfget` and `bpfrejit` live-program paths are ready when invoked with BPF privileges, as shown by the `sudo -n` supplemental checks. Unprivileged host execution is not sufficient on this machine because the kernel denies BPF program enumeration/open with `EPERM`.
