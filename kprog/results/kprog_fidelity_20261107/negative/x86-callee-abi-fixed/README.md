# Original RBX ABI finding after the published repair

F's exact original native object and simulator proof now load with ABI mask1
and execute correctly: packet result0, XDP return2. No fixture source or ISA
semantics changed. This confirms T's published699e0cee1 repair for the
previously reported `callee_saved_clobber` case.

| Observation | Before repair | This replay |
| --- | --- | --- |
| Required RBX preservation mask |0, unsafe accepted finding|1|
| Generation-bound load |accepted|accepted, generation4|
| Actual JIT outside15-byte native body |not established|PUSH RBX at12; POP RBX at28|
| Native body position | |offset13, end28|
| Inspected repaired native execution |not attempted here|packet0, retval2|
| Old proof metadata declaring mask0 |accepted previously|linker rejects|

The exact rejection is:

```
Error: x86 .native_link_abi callee_saved_mask 0x0 omits native writes 0x1
```

`observed/` contains both actual bound-load captures, original proof inputs,
checked snapshots, native/JIT bytes, disassembly and execution logs. T's
existing checked-snapshot decoder verifies the actual binding. RBX save
and restore must surround the entire unique native body before execution.
The loader links the same original F object/proof through the repaired
producer. The old understated metadata object is tested only in userspace;
it is never executed. The previous finding remains unchanged in sibling
`x86-lea-addressing-fixed/published/abi-observation/`.

The frozen native-link executable matches T's published source-pin hash;
its archived x86.rs is byte-identical to699e0cee1. Original native/BPF inputs,
private module/probe and exact executable are in `inputs.tar.gz`; source
and dependency identities are retained in `sources.tar.gz` and
`source-pins.json`. The kernel is the existing matching private TV kernel;
this job changed no shared kernel, module, loader or producer file.
The first preparation failed because T's temporary source export had been
cleaned. Its log is retained; the successful retry verifies the source from
T's committed archive instead. Neither attempt executed the old unsafe ABI.

From `/workspaces/repository`, through bws.sh:

```sh
taskset -c 16-19 make -C kprog/results/kprog_fidelity_20261107/negative/x86-callee-abi-fixed run
```

The recipe restores frozen binaries and uses a new `fresh-run/` output.
The archived probe embeds `kprog/fidelity/build-abi-fixed/native-link`, so
that private build path is fixed. Build a probe with a different
NATIVE_LINK_PATH to relocate it. The initial job used two KVM vCPUs,2GiB,
host CPUs16-19. All run stages exit0. The existing25-case negative suite's
SP finding and remaining whole-program obligations are separate; this
one repaired ABI case does not close them. A later archive preparation
failed on an incorrect module source pathname; the corrected archive uses
the existing kinsn/module/x86 path and changes no observed result.
