# ARM64 vs x86 BPF JIT ReJIT diagnosis for katran `balancer_ingress`

Date: 2026-05-06

Scope: read-only source and artifact investigation. Kernel source line numbers below are from
`git -C vendor/linux-framework show HEAD:<path>` in the `vendor/linux-framework`
submodule.

## 1. ARM64 JIT `EOPNOTSUPP` / non-JIT failure inventory

### Direct `-EOPNOTSUPP`

`arch/arm64/net/bpf_jit_comp.c:1213-1214`

```c
if (!kop || !kop->emit_arm64)
	return -EOPNOTSUPP;
```

Condition: ARM64 is compiling a `BPF_PSEUDO_KOP_CALL` and the kop payload either
does not exist or has no ARM64 emitter. The call site is
`arch/arm64/net/bpf_jit_comp.c:1643-1648`, under:

```c
case BPF_JMP | BPF_CALL:
	if (src == BPF_PSEUDO_KOP_CALL) {
		ret = emit_kop_desc_call_arm64(insn, ctx);
		break;
	}
```

Assessment for katran `balancer_ingress` noop ReJIT: weak match. The failing input is
the bootstrap identity/noop bytecode. The captured verifier log shows normal helper
calls and BPF-to-BPF calls, not kop calls. This direct `-EOPNOTSUPP` path is present
but is not the likely failure for this case.

### Early return that leaves the temp program non-JITed

`arch/arm64/net/bpf_jit_comp.c:2081-2082`

```c
if (!prog->jit_requested)
	return orig_prog;
```

Condition: the verifier/runtime re-enters `bpf_int_jit_compile()` with
`prog->jit_requested` already cleared. This returns the original program without
setting `prog->jited`.

Assessment for katran `balancer_ingress`: strong match as the final ARM64 JIT line
that leaves `tmp->jited == 0` before the REJIT syscall reports `EOPNOTSUPP`.
The bridge is:

- `kernel/bpf/verifier.c:23276` first JITs each subprogram with
  `bpf_int_jit_compile(func[i])`.
- `kernel/bpf/verifier.c:23279-23282` returns `-ENOTSUPP` if any subprogram is not
  JITed.
- `kernel/bpf/verifier.c:23322-23325` performs the final/extra pass and returns
  `-ENOTSUPP` if the JIT changes the function object or `bpf_func`.
- `kernel/bpf/verifier.c:23405-23406` clears `prog->jit_requested` and
  `prog->blinding_requested` on `jit_subprogs()` failure.
- `kernel/bpf/verifier.c:23479-23481` can still return verifier success when
  `CONFIG_BPF_JIT_ALWAYS_ON` is not forcing a hard failure.
- `kernel/bpf/core.c:2549-2553` calls `bpf_int_jit_compile(fp)` during runtime
  selection.
- ARM64 then reaches `arch/arm64/net/bpf_jit_comp.c:2081-2082`, returns without
  setting `tmp->jited`, and the REJIT path reports unsupported at
  `kernel/bpf/syscall.c:3784-3786`.

### ARM64 multi-subprogram extra-pass image growth bailout

`arch/arm64/net/bpf_jit_comp.c:2247-2253`

```c
if (extra_pass && ctx.idx > jit_data->ctx.idx) {
	pr_err_once("multi-func JIT bug %d > %d\n",
		    ctx.idx, jit_data->ctx.idx);
	prog->bpf_func = NULL;
	prog->jited = 0;
	prog->jited_len = 0;
	goto out_free_hdr;
}
```

Condition: during the final pass used for BPF-to-BPF-call/multi-subprogram JIT,
ARM64 emits more A64 instructions than the saved first-pass context budget. The JIT
explicitly treats this as a multi-function JIT bug and clears `prog->jited`.

Assessment for katran `balancer_ingress`: strongest root-cause candidate inside the
ARM64 JIT. It is shape-gated by multi-subprogram JIT (`extra_pass`) and directly
explains how `jit_subprogs()` can return `-ENOTSUPP`, clear the main program's
`jit_requested`, and leave the later REJIT runtime-selection JIT call non-JITed.

### Generic ARM64 JIT build/finalize failures that return the original program

`arch/arm64/net/bpf_jit_comp.c:2157-2159`

```c
if (build_body(&ctx, extra_pass)) {
	prog = orig_prog;
	goto out_off;
}
```

Condition: the initial sizing/body pass returns an error.

`arch/arm64/net/bpf_jit_comp.c:2209-2211`

```c
if (build_body(&ctx, extra_pass)) {
	prog = orig_prog;
	goto out_off;
}
```

Condition: the image-emission body pass returns an error.

`arch/arm64/net/bpf_jit_comp.c:2220-2223`

```c
if (build_body(&ctx, extra_pass) || ctx.idx != jit_data->ctx.idx) {
	pr_err_once("multi-func JIT bug %d != %d\n",
		    ctx.idx, jit_data->ctx.idx);
	prog->bpf_func = NULL;
```

Condition: final multi-function pass failed or emitted a different instruction count
than the saved context. The subsequent block clears the JIT result and exits.

`arch/arm64/net/bpf_jit_comp.c:2230-2232`

```c
if (validate_ctx(&ctx)) {
	prog = orig_prog;
	goto out_off;
}
```

Condition: context validation failed after emission.

`arch/arm64/net/bpf_jit_comp.c:2255-2259`

```c
if (bpf_jit_binary_lock_ro(header)) {
	prog = orig_prog;
	goto out_off;
}
```

Condition: finalizing/locking the JIT image failed.

Assessment for katran `balancer_ingress`: possible but less specific than
`2247-2253`. These paths all leave the program non-JITed, but the artifacts do not
show an allocation/finalization failure. The observed program shape points more
strongly at multi-subprogram final-pass accounting.

### ARM64 branch/immediate range checks

`arch/arm64/net/bpf_jit_comp.c:37-42`

```c
if (!is_simm##bits(imm)) {				\
	pr_info("[%2d] imm=%d(0x%x) out of range\n",	\
		i, imm, imm);				\
	return -EINVAL;					\
}							\
```

Primary call sites:

- `arch/arm64/net/bpf_jit_comp.c:1505` for BPF unconditional jumps through
  `check_imm26`.
- `arch/arm64/net/bpf_jit_comp.c:1532` for BPF conditional jumps through
  `check_imm19`.
- `arch/arm64/net/bpf_jit_comp.c:1677` for exit/prologue branch through
  `check_imm26`.

Condition: ARM64 fixed-width branch immediate cannot encode the target displacement.

Assessment for katran `balancer_ingress`: plausible in principle for very large
programs, but weakly supported here. The failing program is large, but there is no
captured `imm out of range` kernel message in the run artifacts, and the same app was
already JITed during normal load on ARM64.

### Exception table failures

`arch/arm64/net/bpf_jit_comp.c:1140-1141`

```c
if (!ex || ctx->exentry_idx >= prog->aux->num_exentries)
	return -EINVAL;
```

`arch/arm64/net/bpf_jit_comp.c:1152-1154`

```c
if (WARN_ON_ONCE(off >= S32_MAX || off < S32_MIN))
	return -ERANGE;
```

Condition: exception table metadata is unavailable, overrun, or cannot encode the
relative fixup offset.

Assessment for katran `balancer_ingress`: weak match. The verifier log is dominated
by XDP packet access, helper calls, and subprogram calls, not probe-memory exception
metadata.

### Unknown/unsupported opcode fallback

`arch/arm64/net/bpf_jit_comp.c:1950`

```c
pr_err_once("unknown opcode %02x\n", code);
return -EINVAL;
```

Condition: `build_insn()` receives an opcode the ARM64 JIT does not implement.

Assessment for katran `balancer_ingress`: weak match. The program was JITed by ARM64
during normal load and x86 JITed the same ReJIT input successfully.

## 2. x86 JIT `EOPNOTSUPP` / non-JIT failure inventory

### Direct `-EOPNOTSUPP`

`arch/x86/net/bpf_jit_comp.c:592-593`

```c
if (!kop || !kop->emit_x86)
	return -EOPNOTSUPP;
```

Condition: x86 is compiling a `BPF_PSEUDO_KOP_CALL` and the kop payload is absent
or has no x86 emitter. The analogous x86 call path is in the x86 `BPF_CALL` handling
logic.

Assessment for katran `balancer_ingress`: same weak match as ARM64. The x86 run
successfully completed noop/rotate, `cond_select`, and `endian_fusion` for this
program before failing later in `prefetch` with `E2BIG`, so this path did not block
the initial ReJITs.

### Early return when JIT was already disabled

`arch/x86/net/bpf_jit_comp.c:3826-3827`

```c
if (!prog->jit_requested)
	return orig_prog;
```

Condition: identical high-level behavior to ARM64: if the verifier has cleared
`jit_requested`, the arch JIT returns without setting `jited`.

Assessment for katran `balancer_ingress`: x86 did not reach this state for the
identity/noop or early transformed versions in the comparison run.

### x86 multi-pass/final-pass failures

`arch/x86/net/bpf_jit_comp.c:3906-3908`

```c
if (proglen <= 0) {
	image = NULL;
	if (header)
```

Condition: `do_jit()` failed or emitted no valid image. The later block falls through
the image cleanup/error path.

`arch/x86/net/bpf_jit_comp.c:3915-3921`

```c
if (image) {
	if (unlikely(proglen + ilen > oldproglen)) {
		pr_err("bpf_jit: fatal error\n");
		prog->bpf_func = NULL;
		prog->jited = 0;
		prog->jited_len = 0;
	```

Condition: during the final image pass, x86 emitted more bytes than the allocated
budget.

`arch/x86/net/bpf_jit_comp.c:3924-3927`

```c
if (proglen != oldproglen) {
	pr_err("bpf_jit: proglen=%d != oldproglen=%d\n",
	       proglen, oldproglen);
	prog->bpf_func = NULL;
```

Condition: final emitted length differs from the fixed point that x86 expects.

`arch/x86/net/bpf_jit_comp.c:3968-3971`

```c
if (bpf_jit_binary_lock_ro(header)) {
	prog = orig_prog;
	goto out_addrs;
}
```

Condition: final image lock/finalization failed.

Success point:

`arch/x86/net/bpf_jit_comp.c:3999-4001`

```c
prog->bpf_func = (void *)image;
prog->jited = 1;
prog->jited_len = proglen;
```

The x86 comparison run reached this success path for the initial and early transformed
katran `balancer_ingress` programs.

### x86 call-displacement range check

`arch/x86/net/bpf_jit_comp.c:559-567`

```c
if (!is_simm32(r1)) {
	pr_err("extable->insn doesn't fit into 32-bit\n");
	return -ERANGE;
}
```

Condition: x86 cannot encode a direct call/jump displacement in 32 bits.

Assessment for katran `balancer_ingress`: not hit in the successful x86 identity and
early transformed ReJITs.

## 3. ARM64/x86 differences relevant to `balancer_ingress`

The important difference is not the existence of a direct `-EOPNOTSUPP` for kop
calls. Both JITs have that path, and the failing katran noop ReJIT does not match it.

The important difference is the multi-subprogram final-pass accounting model:

- ARM64 has a specific multi-function bailout at
  `arch/arm64/net/bpf_jit_comp.c:2247-2253`: if the final `extra_pass` emits more
  A64 instructions than the previously saved context, it clears `prog->jited` and
  exits. This is explicitly guarded by `extra_pass`, so it is tied to BPF-to-BPF
  calls/subprogram JIT.
- x86 estimates a large upper bound, iterates until the generated image reaches a
  stable size, then verifies the final byte length at
  `arch/x86/net/bpf_jit_comp.c:3915-3927`. For the comparison katran
  `balancer_ingress`, x86 successfully JITed the identity/noop and early transformed
  versions.

ARM64 also has explicit fixed-width branch range checks (`check_imm19` and
`check_imm26`) that can fail large programs with `-EINVAL`, whereas x86 has its own
branch/call displacement mechanics. However, the available artifacts do not show an
ARM64 branch range diagnostic, and the multi-subprogram-only path is a better match
to the observed verifier log.

Both JITs return the original program when `prog->jit_requested` is false
(`arm64:2081-2082`, `x86:3826-3827`). In this case that early return is a consequence,
not a root cause: it becomes observable after ARM64 `jit_subprogs()` failure clears
the main program's JIT request.

## 4. `balancer_ingress` bytecode features vs failure paths

Artifacts checked:

- ARM64 failure run:
  `corpus/results/aws_arm64_corpus_20260506_194818_115918/details/result.json`.
- ARM64 app payload:
  `corpus/results/aws_arm64_corpus_20260506_194818_115918/details/apps/katran.json`.
- x86 comparison run:
  `corpus/results/x86_kvm_corpus_20260506_073134_900272/details/result.json`.
- The requested
  `corpus/results/x86_kvm_corpus_20260506_205924_738444/details/failure-artifacts/100.tar.gz`
  was inspected, but it is not katran `balancer_ingress`; its `target.json` is
  `arch: x86_64`, pass `rotate`, 351 input instructions, and belongs to the cilium
  run. I did not use it as `balancer_ingress` evidence.

Observed `balancer_ingress` features:

- Multi-subprogram program: confirmed by the ARM64 verifier log headers
  `func#0 @0`, `func#1 @2320`, and `func#2 @2468`.
- Large XDP program: ARM64 `balancer_ingress` baseline has `bytes_xlated: 23824`
  and `bytes_jited: 14464`; the noop pass reports about 2544 input instructions.
- BPF-to-BPF calls: implied by the three verifier functions and subprogram layout.
  This directly exercises `kernel/bpf/verifier.c:23131-23415` `jit_subprogs()`.
- Helpers present in the verifier log include `bpf_map_lookup_elem#1`,
  `bpf_map_update_elem#2`, `bpf_ktime_get_ns#5`,
  `bpf_get_smp_processor_id#8`, and `bpf_xdp_adjust_head#44`.
- `LD_IMM64` map-pointer loads are present and expected around map helper calls.
- Tail-call helper `bpf_tail_call#12`: not observed in the failing
  `balancer_ingress` verifier log. Katran uses an XDP chain, but the failing
  balancer program itself does not match a tail-call-helper failure path in the
  collected log.
- Atomic operations: no evidence in the collected verifier log.
- KOperation/kfunc pseudo calls: no evidence in the noop input/log, so the direct
  ARM64 `-EOPNOTSUPP` at `arch/arm64/net/bpf_jit_comp.c:1214` is not a good match.

Hypothesis ranking:

1. Multi-subprogram image accounting / final extra-pass growth:
   strong evidence. The program has three subprograms, the failure is inside the
   arch JIT after verifier acceptance, and ARM64 has a specific multi-function
   bailout at `arch/arm64/net/bpf_jit_comp.c:2247-2253`.
2. Multi-subprogram branch range / image-size limit:
   possible but weaker. The program is large and ARM64 branch immediates are range
   checked, but no `imm out of range` diagnostic was captured.
3. Specific helper unsupported by ARM64 JIT:
   weak. Helper calls are normal call sequences; `bpf_get_smp_processor_id` even has
   ARM64 inline support. x86 succeeds, and ARM64 normal load already JITed the app.
4. Atomic operation fallback:
   weak. No atomic evidence.
5. Cumulative image size greater than ARM64 JIT allocation limit:
   weak to moderate. Size contributes to the risk, but the specific observed x86
   later failure was syscall `E2BIG` after `prefetch`, not the ARM64 noop failure.
6. Extable/fault recovery metadata regeneration:
   weak. No matching probe-memory/extable evidence in the log.

## 5. Verdict

The user-visible `EOPNOTSUPP` is returned by the REJIT syscall post-JIT gate:

`kernel/bpf/syscall.c:3784-3786`

```c
err = -EOPNOTSUPP;
if (!bpf_prog_rejit_supported(tmp) || !tmp->jited)
	goto free_tmp_noref;
```

The exact ARM64 JIT line that most directly explains `tmp->jited == 0` at that gate
is:

`arch/arm64/net/bpf_jit_comp.c:2081-2082`

```c
if (!prog->jit_requested)
	return orig_prog;
```

This is the observable final ARM64 JIT behavior after verifier subprogram JIT
fallback has cleared `tmp->jit_requested`.

The most likely root failure inside the ARM64 JIT is:

`arch/arm64/net/bpf_jit_comp.c:2247-2253`

```c
if (extra_pass && ctx.idx > jit_data->ctx.idx) {
	pr_err_once("multi-func JIT bug %d > %d\n",
		    ctx.idx, jit_data->ctx.idx);
	prog->bpf_func = NULL;
	prog->jited = 0;
	prog->jited_len = 0;
	goto out_free_hdr;
}
```

Why this is the best match:

- Katran `balancer_ingress` is a three-subprogram XDP program, so it exercises
  `jit_subprogs()`.
- `jit_subprogs()` converts subprogram JIT failure into `-ENOTSUPP`, then clears the
  main program's `jit_requested` at `kernel/bpf/verifier.c:23405`.
- The verifier can still accept the program when JIT fallback is allowed, so the
  later runtime-selection call to ARM64 JIT returns at `arm64:2081-2082`.
- The REJIT syscall then sees `!tmp->jited` and returns `EOPNOTSUPP`.
- x86 has the same high-level `jit_subprogs()` contract but successfully JITed this
  program through the identity/noop and early transformed passes.

Confidence: medium. The source-path match is strong, but the artifacts do not include
the ARM64 kernel log line that would prove the `multi-func JIT bug %d > %d` branch
executed. Without instrumentation or dmesg capture, the exact root branch cannot be
proven beyond the source/control-flow and program-shape evidence. The direct
`-EOPNOTSUPP` at `arch/arm64/net/bpf_jit_comp.c:1214` is lower confidence because
the failing noop bytecode does not show kop pseudo calls.

## 6. Daemon-side pre-check feasibility

A hard pre-check that skips or blocks ReJIT is not appropriate under the benchmark
rules: programs must not be filtered out of ReJIT. Also, the strongest ARM64 failure
condition, `ctx.idx > jit_data->ctx.idx` during the final arch JIT pass, is not
statically knowable from daemon-side bytecode inspection with a reliable numeric
limit.

Feasible daemon-side diagnostic, without changing benchmark semantics:

- On ARM64, after `BPF_PROG_REJIT` returns `EOPNOTSUPP`, inspect the verifier log and
  raw bytecode metadata already available to the daemon.
- If the log has multiple `func#N` entries or the bytecode contains
  `BPF_PSEUDO_CALL`, classify the failure as:
  `arm64_jit_multisubprog_rejit_unsupported`.
- Include a friendly error string such as:
  `ARM64 JIT accepted verifier output but did not produce a JIT image for a
  multi-subprogram program; likely arch/arm64 final extra-pass image accounting
  failure. Kernel returned EOPNOTSUPP from the REJIT post-JIT gate.`

Possible static indicators for diagnostic enrichment:

- `prog_type == XDP`.
- more than one verifier function (`func#1` or higher in the log).
- `BPF_PSEUDO_CALL` instructions in the pre-ReJIT bytecode.
- large instruction count, for example this case is about 2544 input instructions
  and 23824 xlated bytes.
- `bpf_xdp_adjust_head#44` and map-heavy helper use, as descriptive context only.

Not feasible as a precise pre-check:

- There is no source-level ARM64 limit like `func_cnt > Y` or `insn_count > Y` for
  this failure.
- The suspected condition depends on final emitted A64 instruction count versus a
  saved pass budget, which only the arch JIT computes.
- A daemon-side static limit would be heuristic and could incorrectly label programs
  that ARM64 can JIT.

Recommended behavior: keep attempting ReJIT, record the raw kernel failure, and add
post-failure classification text for ARM64 multi-subprogram `EOPNOTSUPP`. Do not skip
the program before ReJIT.

## 7. Paper-language

Suggested wording:

> On ARM64, Katran's `balancer_ingress` XDP program failed the bootstrap identity
> `BPF_PROG_REJIT` despite verifier acceptance. The program contains three BPF
> subprograms, and the failure occurs after verifier subprogram JIT orchestration:
> the ARM64 JIT does not leave a JIT image for the temporary program, so the REJIT
> syscall reports `EOPNOTSUPP` at its post-JIT gate. Source inspection points to the
> ARM64 multi-function final-pass image-accounting bailout
> (`arch/arm64/net/bpf_jit_comp.c:2247-2253`) as the most likely arch-specific
> limitation; the final observable JIT behavior is the ARM64 early return when
> `jit_requested` has been cleared (`arch/arm64/net/bpf_jit_comp.c:2081-2082`). The
> x86 JIT does not hit this limitation for the same Katran program and successfully
> compiles the identity and early transformed variants; its later `E2BIG` in a
> `prefetch` transform is a separate size-budget failure. We therefore classify the
> ARM64 Katran result as a kernel/JIT unsupported ReJIT case rather than a benchmark
> performance result.

Shorter table wording:

`katran/balancer_ingress` on ARM64: unsupported by kernel ReJIT path for a large
multi-subprogram XDP program; verifier succeeds, but the ARM64 JIT leaves the ReJIT
temporary program non-JITed and the syscall returns `EOPNOTSUPP`. Source-path match:
`arch/arm64/net/bpf_jit_comp.c:2247-2253` likely root, observed gate
`kernel/bpf/syscall.c:3784-3786`.
