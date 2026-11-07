# Restored classical ROR and high-byte ROL CPU evidence

All 240 selected rotate forms and 245,760 fresh hardware states agree across
the real x86-64 CPU, simulator and canonical native-byte reference. The
common generator restores ROR after V's published1b114d3e4 implementation;
the earlier unsupported-encoder diagnostic remains in its original result.

| Forms | Rows | Cases | CPU/C | CPU/reference | C/reference |
| --- | ---: | ---: | ---: | ---: | ---: |
| ROR, ordinary register widths8/16/32/64 |48|49,152|0|0|0|
| ROR, AH/CH/DH/BH |48|49,152|0|0|0|
| ROR, memory widths8/16/32/64 |48|49,152|0|0|0|
| ROL, ordinary register widths8/16/32/64 |48|49,152|0|0|0|
| ROL, AH/CH/DH/BH |48|49,152|0|0|0|

Every operand variant has immediate counts0/1/7/8/15/16/31/32/63/64/255 and
CL input. This exercises zero/masked/full-circle counts, high-byte aliases
(including CH sharing RCX with CL), partial writeback and preserved flags.
All sixteen GPRs, six defined arithmetic flags, XMM0,64 stack bytes and
256 external-memory bytes are compared. Undefined OF is excluded according
to the native count rules; count-zero state preservation is checked. These
memory cases use mapped writable input bytes; no new fault/page-permission
coverage is claimed by this run. The existing42 auxiliary observers also
pass43,008 CPU/C cases but were not canonically replayed here. Total CPU/C:
282rows,288,768cases,zero differences. Per-form counts are retained.

The frozen producer is published1b114d3e4 plus the private F SP-v1 overlay
identified in source-pins.json. That overlay is not presented as a production
fix: its low-level raw-setter issue was caught by the separate FULL check.
These rotate operands do not use copied stack aliases. Every actual source,
static CPU executable, generated code and diagnostic is archived; no ROOT
foreign stack prototype is used. Canonical executable/source remain in
sibling x86-multiply-xchg at47de9665d, including the unchanged e803 ROR step.
No second instruction interpreter is added. CPU and reference stages exit0.

Through bws.sh from /workspaces/repository:

```sh
taskset -c 20-23 make -C kprog/results/kprog_fidelity_20261107/differential/x86-rotate-final build cpu reference
```

The recipe uses a new fresh-run/ output. The completed raw trace is deleted
only after summary publication/no-reader checks, per coordinator disk
instruction; its hash/size remain in trace-retention.json. Later invocations
produce fresh states and can have different native addresses.
