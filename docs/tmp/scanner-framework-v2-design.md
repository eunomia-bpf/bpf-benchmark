# Scanner Framework v2 Design Rationale

**Status:** Design rationale only  
**Date:** 2026-03-10  
**Context:** Follow-on to the standalone scanner extraction, the policy decision layer design, and the kernel-fixed baselines experiment design.

## 1. Why Redesign

The current scanner library is a good v1 extraction: it reuses the runner's pattern matchers, emits `bpf_jit_scan_rule` entries, and builds a v4 policy blob without changing kernel UAPI. Its main limitation is that it still conflates three different concerns:

1. **Candidate discovery**: find structurally valid sites in xlated BPF.
2. **Policy selection**: choose `native_choice` for each site.
3. **Experiment control**: export comparable artifacts for `kernel-fixed-*` versus userspace-guided runs.

That coupling is now the main blocker. The policy-layer document explicitly shows that hardcoded `native_choice` is wrong for policy-sensitive cases such as CMOV, while the kernel-fixed-baselines document requires an apples-to-apples comparison where the pattern census stays constant and only the policy location changes. Scanner framework v2 therefore keeps the existing blob format and rule kinds, but redesigns the userspace control plane around a stricter pipeline:

```text
xlated BPF
  -> pattern registry
  -> candidate set
  -> policy engine (static -> config -> profile)
  -> finalized rules
  -> policy blob / re-JIT apply / debug dump
```

The redesign is userspace-only. The kernel legality plane, validators, emitters, and `BPF_PROG_JIT_RECOMPILE` interface remain unchanged.

## 2. Pluggable Pattern Registry

v2 replaces the monolithic "scan-all in fixed order, assign fixed choice immediately" model with a **pluggable pattern registry**. Each directive family registers:

- `rule_kind` and CLI name
- scan flag / enable bit
- matcher callback over xlated BPF
- static feature extractor
- default native choices and CPU gating metadata
- serializer support for text/JSON dump output

Conceptually:

```c
struct pattern_family {
    const char *name;
    uint32_t    scan_flag;
    uint32_t    rule_kind;
    int  (*scan)(const uint8_t *xlated, uint32_t len, candidate_sink *);
    void (*extract_features)(const candidate *, site_features *);
};
```

Rationale:

- **Open-ended family set**: the optimization plan already treats directive families as extensible. Adding a new family should not require editing a central dispatcher, printer, and policy path in multiple places.
- **Single source of truth**: the same registry drives scan, dump, policy, and experiment census. This avoids drift between "scanner coverage" and "fixed-kernel coverage."
- **Consistent with fixed baselines**: the kernel-fixed experiment reuses the same validators and emitters via synthetic rules. The userspace side should likewise produce synthetic-rule-equivalent candidates before policy is chosen.

The registry outputs **candidates**, not final rules. A candidate says "this site is structurally eligible for `rule_kind`," while policy later decides whether that means `CMOVCC` or `BRANCH`, `RORX` or `ROR`, or "do not apply."

## 3. Policy Engine: Static, Config, Profile

The v2 policy engine is a layered reducer from candidates to final `bpf_jit_scan_rule` entries. It follows the mechanism/policy split in `docs/kernel-jit-optimization-plan.md`: kernel owns legality; userspace owns profitability.

### 3.1 Static Layer

The static layer always runs first. It computes deterministic defaults from bytecode shape and CPU facts:

- `ADDR_CALC` -> usually `LEA`
- `WIDE_MEM` -> usually `WIDE_LOAD`
- `ROTATE` -> `RORX` if BMI2 is allowed, otherwise `ROR`
- `COND_SELECT` -> conservative default plus site metadata for later refinement

This layer is the userspace analog of the `advisor-static` baseline from the policy design doc. It is cheap, reproducible, and sufficient for directive families that are not obviously workload-sensitive.

### 3.2 Config Layer

The config layer applies operator or experiment policy on top of static defaults. It is the place for:

- enable/disable per family
- force a specific `native_choice`
- pin or exclude specific sites
- set thresholds, budgets, and CPU allowlists
- emulate experiment presets such as `fixed-rotate`, `fixed-wide`, `fixed-lea`, `fixed-cmov`, and `fixed-all`

This layer matters because the paper argument is not only "profile can help," but also "deployment owners need control." It also provides the reproducible control surface needed for A/B and kernel-fixed parity experiments.

### 3.3 Profile Layer

The profile layer is optional and runs last on sites that are still policy-flexible. It consumes runtime evidence from `bpf_prog_test_run` and, when available, perf counters or A/B timing:

- promote `COND_SELECT` sites to `CMOVCC` only when branch behavior justifies it
- keep predictable sites as `BRANCH`
- validate that profile-guided choices do not regress final `exec_ns`

This directly matches the policy-decision-layer design: runtime evidence is needed for policy-sensitive profitability, especially CMOV. The profile layer should be able to explain each flip in a decision log so the same run can feed debugging and paper tables.

### 3.4 Layering Rule

The merge rule is:

```text
static defaults
  -> config constraints / pins
  -> profile refinement on unpinned sites
  -> finalized rules
```

This ordering preserves operator control while still allowing measured refinement where the config intentionally leaves room for it.

## 4. Integration with the Kernel-Fixed Baselines Experiment

The kernel-fixed experiment asks a narrow falsification question: if fixed in-kernel heuristics achieve the same gains, the framework story is weak. Scanner v2 supports that experiment in three ways.

First, it provides a **shared candidate census**. The same xlated program can be scanned once, dumped once, and then used to verify that:

- `kernel-fixed-rotate` covers the same rotate sites as userspace `fixed-rotate`
- `kernel-fixed-wide` covers the same wide-load sites as userspace `fixed-wide`
- `kernel-fixed-lea` covers the same LEA sites as userspace `fixed-lea`
- `kernel-fixed-cmov` covers the same cmov sites as userspace `fixed-cmov`

Second, the config layer can **emulate the fixed baselines in userspace** before kernel patches are measured. That lets us test the decision surface with identical candidate sets and then compare against the true in-kernel fixed heuristics later.

Third, v2 makes the experiment cleaner by ensuring that differences are attributable to **where policy runs**, not to scanner drift. For ROTATE, WIDE_MEM, and LEA, parity is the expected honest outcome. For CMOV, the expected non-parity between `kernel-fixed-cmov` and `scanner-v2 profile` is exactly the paper's policy-sensitive case.

## 5. CLI Shape

v2 should make the three phases explicit: `scan`, `apply`, and `dump`. The subcommands clarify intent while keeping the data sources simple: live programs via `--prog-fd` and offline xlated bytecode via `--xlated`.

### 5.1 Scan

Discover candidates only; do not build or apply policy.

```bash
bpf-jit-scanner scan --prog-fd 5 --all
bpf-jit-scanner scan --xlated dump.bin --rotate --wide-mem
```

Primary use: candidate census, debugging matcher coverage, offline analysis, and parity checks for the kernel-fixed experiment. When `--output` is supplied, `scan` also writes the policy blob that corresponds to the chosen decisions.

### 5.2 Apply

Scan, run the policy stack, build a blob, and when `--prog-fd` is present issue `BPF_PROG_JIT_RECOMPILE`.

```bash
bpf-jit-scanner apply --prog-fd 5 --policy policy.yaml
```

`apply` always performs the full userspace flow: fetch xlated bytecode, scan all enabled families, run static/config/profile policy selection, build the blob, and issue `BPF_PROG_JIT_RECOMPILE`. For fixed-baseline emulation, the config file can force specific choices such as "always branch" or "always cmovcc."

### 5.3 Dump

Dump post-verifier xlated bytecode for offline analysis:

```bash
bpf-jit-scanner dump --prog-fd 5 --output dump.bin
```

`dump` is important for paper hygiene because it lets one experiment produce the exact xlated input later consumed by offline `scan` runs.

## 6. Summary

Scanner framework v2 is not a new kernel interface and not a new rule format. It is a userspace redesign that separates candidate discovery from profitability policy, introduces a pluggable registry for directive families, and turns policy into a layered control surface with static, config, and profile phases. That structure is required both for the profile-guided story in the policy-layer design and for the falsification discipline in the kernel-fixed-baselines experiment.
