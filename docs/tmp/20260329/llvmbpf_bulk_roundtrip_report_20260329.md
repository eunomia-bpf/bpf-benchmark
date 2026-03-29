# llvmbpf Bulk Round-Trip Report (2026-03-29)

## Scope

- Objects tested: `170`
- Programs discovered from symbol tables: `962`
- Program lift success: `556/962` (57.8%)
- Program LLVM lower success: `309/556` (55.6%)
- Program verifier pass success: `7/309` (2.3%)
- End-to-end program coverage over the tested corpus slice: `7/962` (0.7%)
- Total `map_lookup_elem` candidate sites in lifted LLVM IR: `4292`
- Programs that lowered but were not pinned by `bpftool prog loadall` in the VM: `145`

## Families

- `KubeArmor`: 3 object(s)
- `bcc`: 57 object(s)
- `bpftrace`: 7 object(s)
- `calico`: 8 object(s)
- `cilium`: 7 object(s)
- `katran`: 5 object(s)
- `libbpf-bootstrap`: 15 object(s)
- `netbird`: 2 object(s)
- `suricata`: 2 object(s)
- `systemd`: 10 object(s)
- `tetragon`: 12 object(s)
- `tracee`: 3 object(s)
- `xdp-tools`: 16 object(s)
- `xdp-tutorial`: 23 object(s)

## Failure Breakdown

### Lift failures: top 5

- `program not reported by llvmbpf build output`: 376
- `Unable to generate llvm module`: 30

### Verifier / VM failures: top 5

- `program not pinned by bpftool prog loadall`: 145
- `BPF_PROG_LOAD: Invalid argument (os error 22)
verifier log:
func#0 @0
func#1 @8
last insn is not an exit or jmp
processed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0
`: 9
- `BPF_PROG_LOAD: Invalid argument (os error 22)
verifier log:
func#0 @0
func#1 @13
func#2 @19
func#3 @30
last insn is not an exit or jmp
processed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0
`: 8
- `BPF_PROG_LOAD: Invalid argument (os error 22)
verifier log:
func#0 @0
processed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0
`: 8
- `BPF_PROG_LOAD: Invalid argument (os error 22)
verifier log:
func#0 @0
func#1 @10
last insn is not an exit or jmp
processed 0 insns (limit 1000000) max_states_per_insn 0 total_states 0 peak_states 0 mark_read 0
`: 4

## Conclusion

The LLVM IR round-trip path is viable on a meaningful slice of real-world BPF programs: 7 programs from 170 real-world objects completed host lift/O2/lower and then passed a fresh VM-side `BPF_PROG_LOAD` verifier check. The main blockers remain llvmbpf lift failures on specific control-flow patterns and VM-side loadability gaps where `bpftool prog loadall` could not materialize the original program context.

## Artifacts

- Manifest: `docs/tmp/20260329/llvmbpf_bulk_roundtrip/bulk_roundtrip_manifest.json`
- Guest verify results: `docs/tmp/20260329/llvmbpf_bulk_roundtrip/bulk_roundtrip_guest_results.json`
- Guest helper binary: `docs/tmp/20260329/llvmbpf_bulk_roundtrip/guest_verify_helper/target/release/llvmbpf-bulk-guest-verify`
