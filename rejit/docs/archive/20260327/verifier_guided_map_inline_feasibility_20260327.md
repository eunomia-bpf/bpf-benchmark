# Verifier-Guided `map_inline` Feasibility

Date: 2026-03-27

## TL;DR

`verifier-guided map_inline` is feasible and useful.

The kernel verifier's `log_level=2` output already contains enough information to recover many constant `bpf_map_lookup_elem()` keys that the current backward scan misses, especially the common BCC/libbpf-tools pattern where the key is written via a wider zero store and `r2` points to a subrange of that stack slot.

The practical integration point in this repo is:

1. Before running `map_inline` in the apply path, ask the kernel for a verifier log on the original program.
2. Parse per-PC verifier states, including stack slots.
3. For each `bpf_map_lookup_elem` call, use verifier state to recover the stack key when possible.
4. Keep the existing backward scan and pseudo-map-value logic as fallback.

## 1. Verifier Log Format Findings

### 1.1 State lines we care about

Observed `log_level=2` state snapshots have forms like:

```text
from 4 to 6: R0_w=pkt(off=8,r=8) R1=ctx() R2_w=pkt(r=8) R10=fp0
6: R1=map_ptr(map=test_array,ks=4,vs=4) R2=fp-4 R10=fp0
6: (85) call bpf_map_lookup_elem#1    ; R0=map_value_or_null(id=1,map=test_array,ks=4,vs=4)
3: frame1: R1=ctx() R2=fp-24 R10=fp0 fp-24=scalar(id=1) fp-32=0000???? fp-40=fp-56
1: (7b) *(u64 *)(r10 -8) = r3         ; R3=0 R10=fp0 fp-8=0
```

Important observations:

- `R1` does show up as `map_ptr(...)` on state snapshots before the helper call, so verifier log can identify the map argument.
- `R2` does show up as `fp-<off>` when the key pointer is stack-backed.
- Stack slots do show up in the log, and they may carry either:
  - raw slot-type bytes, e.g. `fp-24=mmmm????`
  - a known scalar, e.g. `fp-8=0`
  - a spilled pointer, e.g. `fp-40=fp-56`
  - a non-constant scalar state, e.g. `fp-24=scalar(id=1)`

### 1.2 What the CALL line itself contains

At the `call bpf_map_lookup_elem#1` line, the verifier usually prints post-call `R0`, not pre-call `R1`/`R2`.

So the usable pattern is not "read everything from the CALL line itself". The usable pattern is:

1. Find the verifier snapshots at the helper's PC.
2. Walk backward through earlier verifier snapshots in the same frame.
3. Recover the latest `R2=fp-<off>` and the stack state that led to it.

That is still good enough for `map_inline`.

### 1.3 Stack slot encoding details

From `vendor/linux-framework/kernel/bpf/log.c`:

- stack is printed in 8-byte slots
- slot base offsets are printed as `fp%d`, where the offset is `(-i - 1) * 8`
- slot-type characters are one of `? r m 0 d i f`
- when a spilled register exists, the verifier may print slot-type bytes immediately followed by the spilled register state

This matters because a source instruction like:

```text
*(u32 *)(r10 - 20) = 0
```

may show up as something anchored at `fp-24`, not `fp-20`, because the log is slot-based.

## 2. Existing Daemon Infrastructure

Relevant existing pieces:

- `daemon/src/verifier_log.rs`: verifier log parser
- `daemon/src/passes/map_inline.rs`: current key recovery and rewrite logic
- `daemon/src/commands.rs`: apply path orchestration
- `daemon/src/bpf.rs`: REJIT syscall wrappers

The daemon already had verifier-log plumbing for REJIT diagnostics, but that was too late for `map_inline`: the pass needs verifier state before REJIT of the rewritten program.

## 3. Why Not Replay `BPF_PROG_LOAD`?

The original idea was "load the original bytecode once with `BPF_PROG_LOAD(log_level=2)` and parse that log before passes run."

That is not the best fit here for arbitrary live programs, because the daemon generally does not have enough original load attributes to reliably replay the exact load:

- program type / expected attach type
- attach BTF / attach target information
- other `BPF_PROG_LOAD` attributes that were present at original load time

For live programs that we already have a prog FD for, `BPF_PROG_REJIT` is a much better probe:

- it reuses the existing loaded program context
- it only needs the original instruction stream plus live map-FD relocation
- the daemon already has REJIT wrappers and log handling

So the practical design here is verifier-guided analysis via a pre-pass REJIT of the original bytecode, not a synthetic `BPF_PROG_LOAD` replay.

## 4. Implemented Approach

### 4.1 Parser side

`verifier_log.rs` now parses enough state for this pass:

- `pc`
- optional `from_pc`
- `frame`
- register states
- stack slot states keyed by `fp` offset

That gives `map_inline` structured access to:

- `R2=fp-4`
- `fp-8=0`
- `fp-24=scalar(id=1)`
- `fp-40=fp-56`

instead of raw string matching.

### 4.2 Pre-pass verifier-state capture

Before `map_inline` runs in the apply path, the daemon now:

1. clones the original instructions
2. relocates pseudo map FDs to live map FDs
3. invokes REJIT with verifier logging enabled on that original program
4. parses the returned verifier log
5. stores the parsed verifier states on the `BpfProgram`

This keeps the new analysis on the real kernel verifier path without requiring a second private constant-propagation engine in user space.

### 4.3 Key extraction algorithm

For each `bpf_map_lookup_elem` site:

1. Collect all verifier snapshots at the helper PC.
2. For each occurrence, walk backward within the same frame.
3. Find the latest verifier state where `R2` is a concrete `fp-<off>`.
4. Find a prior stack store whose written range fully covers the key bytes.
5. Recover the store value from the verifier-known source register value or immediate.
6. Require all occurrences to agree on the derived key.
7. If verifier-guided extraction fails, fall back to:
   - the existing backward scan
   - then the pseudo-map-value constant path

The conservative "all occurrences must agree" rule avoids path-dependent miscompiles.

## 5. What This Buys Us

The main newly-covered pattern is:

```text
r3 = 0
*(u64 *)(r10 - 8) = r3
r2 = r10
r2 += -4
call bpf_map_lookup_elem
```

The old backward scan wants a store exactly at `fp-4`, so it misses this.

The verifier-guided approach can recover:

- `R2=fp-4`
- prior stack state showing the wider zero store
- constant source value `r3=0`

and conclude that the 4-byte key read from `fp-4..fp-1` is still constant zero.

This is exactly the common ARRAY-map key-zero pattern seen in many BCC/libbpf-tools programs.

## 6. Limitations

### 6.1 The CALL line alone is not enough

The helper-call line usually only exposes post-call `R0`. The implementation must correlate multiple verifier snapshots around the call site.

### 6.2 Stack values are not always directly materialized

If the verifier only knows that a stack slot is `scalar(id=1)` or otherwise non-constant, this approach correctly fails closed.

### 6.3 Extra verifier pass cost

This adds one extra verifier pass in the apply path for programs that may use `map_inline`.

That is acceptable:

- verifier latency is typically milliseconds
- the pass already performs other kernel interactions
- the precision gain is materially better than the old heuristic scan

### 6.4 Scope

The current integration point is the apply/optimization path where REJIT already exists. This does not automatically make offline analysis paths verifier-guided.

## 7. Comparison: Verifier-Guided vs `const_prop`-First

### Verifier-guided

Pros:

- reuses the kernel's real constant propagation and range reasoning
- path-sensitive and verifier-accurate
- better coverage for stack-addressing patterns that are awkward to recover syntactically
- no need to maintain a parallel abstract interpreter in the daemon

Cons:

- requires a kernel round-trip
- only available where verifier logging is available
- must parse evolving verifier text formats conservatively

### `const_prop` first, then old `map_inline`

Pros:

- simpler and entirely local
- works in offline/unit-test contexts without kernel interaction
- potentially useful as a cheap preconditioning step for multiple passes

Cons:

- substantially weaker than the kernel verifier
- duplicates analysis effort the verifier already performs
- still needs to reason about stack aliases and partial-width stores well enough to help `map_inline`

## 8. Recommendation

Recommended strategy:

1. Keep verifier-guided key extraction as the primary path in `map_inline`.
2. Keep the old backward scan as a cheap fallback.
3. Keep pseudo-map-value extraction as a final fallback.
4. Treat `const_prop`-first as optional future work, not as the main solution to this problem.

Reason: verifier-guided analysis solves the actual coverage gap with better fidelity and less duplicated logic.

## 9. Validation

Validated with:

- targeted unit tests for verifier stack parsing
- targeted unit tests for wide-store/subrange constant-key recovery
- end-to-end `map_inline` unit coverage for the verifier-guided zero-key case
- full `make daemon-tests`

Result at validation time:

- `make daemon-tests` passed
- 528 passed, 0 failed, 12 ignored

## 10. Bottom Line

This approach is feasible, the verifier log contains the needed information, and the repo is now close to the right architecture for it:

- capture verifier states before `map_inline`
- parse register + stack state
- use verifier-guided constant-key extraction first
- fall back conservatively when the verifier state is not strong enough

That is a better long-term direction than continuing to grow ad-hoc backward scans.
