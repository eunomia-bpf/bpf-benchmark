# Katran xdp_pktcntr map_inline perf test (2026-03-26)

## Scope

- VM-only run on the x86 guest via `runner/scripts/run_vm_shell.py --action vm-corpus --target x86`
- Object: `corpus/build/katran/xdp_pktcntr.bpf.o`
- Program: `pktcntr`
- Stock vs REJIT with passes `map_inline,const_prop,dce`
- 9 stock samples and 9 REJIT samples at `repeat=500`
- 9 stock samples and 9 REJIT samples at `repeat=1000`
- Warmup per invocation: `50`
- Raw JSONL outputs:
  - `docs/tmp/20260326/raw/katran_xdp_pktcntr_stock_repeat500.jsonl`
  - `docs/tmp/20260326/raw/katran_xdp_pktcntr_rejit_repeat500.jsonl`
  - `docs/tmp/20260326/raw/katran_xdp_pktcntr_stock_repeat1000.jsonl`
  - `docs/tmp/20260326/raw/katran_xdp_pktcntr_rejit_repeat1000.jsonl`

## Results

| Repeat | Stock `exec_ns` median | REJIT `exec_ns` median | REJIT/stock | Stock `wall_exec_ns` median | REJIT `wall_exec_ns` median |
| --- | ---: | ---: | ---: | ---: | ---: |
| 500 | 5 ns | 10 ns | 2.00x | 32,779 ns | 33,169 ns |
| 1000 | 4 ns | 10 ns | 2.50x | 16,543 ns | 16,493 ns |

Per-run `exec_ns` samples:

- `repeat=500` stock: `[11, 5, 12, 11, 6, 4, 4, 4, 5]`
- `repeat=500` REJIT: `[10, 4, 5, 14, 11, 18, 4, 10, 5]`
- `repeat=1000` stock: `[4, 4, 4, 4, 4, 14, 13, 11, 11]`
- `repeat=1000` REJIT: `[4, 10, 4, 10, 11, 3, 10, 4, 10]`

Median `exec_cycles` stayed nearly flat:

- `repeat=500`: stock `120,826`, REJIT `122,257`
- `repeat=1000`: stock `60,979`, REJIT `60,798`

## Optimization Evidence

- `map_inline` applied on every REJIT run.
- `passes_applied`: `map_inline,const_prop,dce`
- `map_inline` `sites_applied`: `1`
- `map_inline` also reported `1` skipped site with diagnostic `map type 6 not inlineable in v1`
- Pipeline `total_sites_applied`: `12`
- Per-pass sites:
  - `map_inline`: `1`
  - `const_prop`: `1`
  - `dce`: `10`
- Inlined map entry reported by the daemon:
  - `map_id=3`
  - `key_hex=00000000`
  - `value_hex=00000000`

## Instruction Count Before/After

- Daemon-reported program instruction count: `22 -> 12` (`insn_delta=-10`)
- Runtime xlated program length: `288 -> 144` bytes (`36 -> 18` xlated insns)
- Runtime JIT native length: `177 -> 94` bytes

## Takeaway

The requested `map_inline,const_prop,dce` pipeline clearly fired and shrank `pktcntr` substantially. Despite that, the reported `exec_ns` metric did not improve: the REJIT median was slower than stock at both repeat settings, `2.00x` slower at `repeat=500` and `2.50x` slower at `repeat=1000`.

`wall_exec_ns` and `exec_cycles` medians were nearly flat between stock and REJIT, so the steady-state result should be treated cautiously: the code-size win is real, but the low single-digit `exec_ns` values remain highly quantized/noisy even with `repeat=1000`.
