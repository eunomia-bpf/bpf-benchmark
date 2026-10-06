# Minimal Source Shaping Proof Run

This run restores the source-code shaping direction for the two remaining
partial-register verifier failures, but keeps the source edits intentionally
small and leaves the ReverseSim simulator unchanged.

Source edits:

- `payload_prefix_memcmp_scan`: widen `memcmp_prefix_pattern_byte()`,
  `observed`, and `expected` from byte-typed values to `u32`. The value is still
  masked to `0xff`; the purpose is to make native x86 use full 32-bit writes
  (`mov esi,0x1d`, `mov r8d,0x4`) instead of low-byte writes to pointer-typed
  registers.
- `tetragon_process_event_arg_filter`: rewrite the event-weight `switch` as the
  same integer expression. The mapping is unchanged:
  `1->0x11`, `2->0x23`, `5->0x37`, `9->0x41`, `13->0x59`, default `0`.
  A smaller attempt that kept the `switch` and only widened `event_id` to `u32`
  still generated `mov dl,0x1` and failed verifier load, so it was not kept.

Runtime command:

```bash
make micro BENCH="payload_prefix_memcmp_scan tetragon_process_event_arg_filter" \
  RUNTIMES="native kernel native_lab" \
  SAMPLES=5 WARMUPS=1 INNER_REPEAT=100000
```

Runtime result:

- `micro/results/x86_kvm_micro_20260520_032422_672690/metadata.json`

| Micro program | Runtime | Avg exec ns | Median exec ns | Last compile ns | Native code bytes | BPF bytecode bytes | Native vs kernel gap |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: |
| `payload_prefix_memcmp_scan` | native | 48.0 | 48 | 44147 | 548 | 0 | +41.6% |
| `payload_prefix_memcmp_scan` | kernel | 82.2 | 82 | 756763 | 606 | 1136 | baseline |
| `payload_prefix_memcmp_scan` | native_lab | 51.0 | 51 | 115835971 | 528 | 0 | +38.0% |
| `tetragon_process_event_arg_filter` | native | 104.2 | 104 | 40114 | 783 | 0 | +32.3% |
| `tetragon_process_event_arg_filter` | kernel | 154.0 | 154 | 12870302 | 1258 | 2256 | baseline |
| `tetragon_process_event_arg_filter` | native_lab | 107.2 | 107 | 127308950 | 724 | 0 | +30.4% |

Proof command:

```bash
python3 native-sim/x86/micro-prog/run_micro_sim_batch.py --jobs 2 \
  --only payload_prefix_memcmp_scan tetragon_process_event_arg_filter \
  --markdown native-sim/x86/results/README-20260519-202449-source-minimal-proof.md
```

| Micro program | Status | Compile s | Proof BPF insns | Direct BPF insns | Verify s | Test s | Note |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| `payload_prefix_memcmp_scan` | ok | 2.829 | 344 | 142 | 0.006 | 0.000 |  |
| `tetragon_process_event_arg_filter` | ok | 4.343 | 290 | 282 | 0.347 | 0.000 |  |
