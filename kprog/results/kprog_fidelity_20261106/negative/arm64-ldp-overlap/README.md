# Reject constrained-unpredictable LDP destination overlap

Four native pair-load variants were accepted by the actual generation-bound
Arm QEMU loader before the repair. None was executed. Each uses an allocated,
initialized16-byte native stack frame; failure is the instruction's destination
overlap, rather than an unrelated out-of-bounds or undefined-input error.

| Pair-load variant | Before: bound program ID / generation | After |
| --- | --- | --- |
| `ldp x1,x1,[sp]`, result returned | 8 /1 | specialization rejects |
| `ldp x1,x1,[sp]`, result overwritten | 16 /1 | specialization rejects |
| `ldp w1,w1,[sp]`, result returned | 24 /1 | specialization rejects |
| `ldp xzr,xzr,[sp]`, result discarded | 32 /1 | specialization rejects |
| Distinct `ldp x1,x2,[sp]` control | 40 /1 | accepted, ID8 /generation1 |

Arm DDI0602's LDP shared decode (pages504–505, local primary-source extraction
`/workspaces/.agent-state/kprog-lanes/V/arm-a64.txt:17190`) permits unknown
results, an undefined instruction, or a NOP when Rt equals Rt2. A deterministic
last-load-wins model cannot justify admitting these encodings. Overwriting the
result does not eliminate the possible instruction fault. No platform witness
selecting a particular constrained behavior is supplied by this framework.

The production ABI checker now rejects exactly the duplicate-destination LDP
condition, before modeling its loads. There is no new runtime check, arbitrary
loaded value, or changed successful native instruction semantics. The exact
diagnostics for the first two cases are identical:

```text
constrained-unpredictable native LDP destination overlap at 0xc: ldp x1, x1, [sp]
```

The W and ZR cases report the same message with `ldp w1, w1, [sp]` and
`ldp xzr, xzr, [sp]` respectively. `before/outcomes.json` and
`after/outcomes.json` retain every native input and exact diagnostic.
Assembler warnings about the real encodings are retained in the source archive.

The permanent Arm suite now has19 cases:9 verifier rejections,7 specialization
rejections,1 loader rejection and2 accepted findings. All11 original negatives
reject; SP alignment and LDP overlap reject. The accepted numeric stack-base
and entry-return-address flag cases remain active safety defects. The suite
exits1 for those findings, with zero infrastructure errors. All40 existing
real-encoding ABI regressions pass, and the negative proof plus all29
workload-derived positive proofs rebuild. The valid LDP control still loads
with a nonzero generation; it is a load-only control, not a native result test.

```sh
taskset -c 16-23 make -C kprog/results/kprog_fidelity_20261106/negative/arm64-ldp-overlap build run
taskset -c 16-23 make -C kprog/results/kprog_fidelity_20261106/negative/arm64-ldp-overlap PHASE=after build run
taskset -c 16-23 make -C kprog/results/kprog_fidelity_20261106/negative/arm64-ldp-overlap full-build full-run
taskset -c 16-23 make -C kprog/results/kprog_fidelity_20261106/negative/arm64-sp-alignment check BUILD=/workspaces/repository/kprog/fidelity/build-arm64/ldp-overlap-bound/after
taskset -c 16-23 make -C kprog/arm64 micro-proofs-build PROOF_BUILD_DIR=build/fidelity-ldp/micro-proofs NEGATIVE_NATIVE_BUILD_DIR=build/fidelity-ldp/negative-native MICRO_SIM_PROOF_ARGS='--jobs 1'
```

The first command is the preserved before-repair run and must use the saved
before source snapshot to reproduce acceptance. It is not a request to undo
the production fix. The after command checks every targeted rejection and the
positive control; the full suite deliberately exits nonzero for the two
separate findings. All guests use cortex-a57,2vCPUs and2GiB on host CPUs16–23.

`artifacts.tar.gz` restores `ldp-overlap-bound/` under
`kprog/fidelity/build-arm64/`, including exact before/after import and include
snapshots, native assembly/objects, generated C/proofs, compiler diagnostics,
19-case inputs and40 ABI regressions. Unchanged kernel/module, static probe,
loader, linker and companion assets are deduplicated: restore them from
`../arm64-sp-alignment/artifacts.tar.gz` into its original owning build path;
`prepare.py` copies those matched assets. Rebuild initramfs files with the
Make target. `raw-logs.tar.gz` preserves every complete guest console and
individual load log. Compressed Make logs retain all commands and exit status.

The contemporaneous x86 rerun is in `../x86-post-ldp-matched/README.md`:
all17 cases attempted,16 rejections, one retained stack-base finding, zero
infrastructure failures after restoring a matched loader/kernel/module tuple.
