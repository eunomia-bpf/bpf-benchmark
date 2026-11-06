# Explicit canonical exclusive-monitor semantics

The existing canonical AArch64 reference now decodes LDXR/LDAXR/STXR/STLXR
at32/64-bit width and all16 CLREX immediates. It models the physical reservation
range, interference, conditional commit, status0/1, no write on failure,
acquire/release attributes, SP and natural alignment, reserved status-register
aliases and implementation-dependent fault checks on failed stores.

**Validation:** the immutable full `make check` passes all352 Lean modules,
all existing C/static encoder/wire checks, and82 new full-state/effect/fault
examples plus10 precise encoding/input rejections. All old Arm wire cases
remain. The new reference-property lemmas prove empty/interfered/global-failed
or commit-failed monitors cannot force success; the failed-store transition
preserves memory/NZCV/vector/SP and every register except status; CLREX clears
the monitor; and an explicitly witnessed physical alias can succeed.
`axioms.log.gz` records only `propext` and `Quot.sound` for the displayed lemmas.
No admitted theorem or new axiom is introduced.

These are canonical/API and reference-property results. They do **not** claim
that the current constant-success production simulator has been repaired or
refined. The four accepted failure-branch negatives remain active. Lane A owns
the production encoder/C repair; T owns the bound per-dynamic-invocation choice
marker and O4 site descriptor; F owns the canonical relation and replay.

`State.exclusiveMonitor` is an optional physical range (`physicalStart`, byte
count). `ExclusiveInputs` supplies the current translated physical address,
the actual reservation granule for a load, local interference, optional virtual
monitor check, global-monitor and commit choices, and the implementation's
fault-check profile. Physical address/granule facts come from the current
platform relation; they are not guessed from virtual pointer bits or fixed
entry addresses. Interference and outcomes are fresh for each dynamic attempt.

The wire interface requires explicit monitor state for every exclusive
instruction, and explicit environment inputs for each load/store. Missing or
malformed fields reject. A load reservation must cover its translated physical
range. Ordinary requests retain their old constructor/wire shape; their default
exclusive fields are never inspected by ordinary instructions.

Example **test inputs**, not captured hardware physical-address evidence:

```json
{
  "exclusive_monitor": {"physical_start": 36864, "bytes": 64},
  "exclusive_inputs": {
    "physical_address": 36880,
    "reservation": {"physical_start": 36864, "bytes": 64},
    "retain_local": true,
    "virtual_pass": true,
    "global_pass": true,
    "commit_pass": false,
    "abort_on_failure": false
  }
}
```

That commit choice produces status1/no write despite a matching reservation.
The tests also cover physical aliases with different virtual addresses,
reservation-range misses, lost local/global monitors, faulting and nonfaulting
failed-store profiles, ZR, alignment and precise full-state preservation.
The optional virtual check may fail **before** local-monitor clearing, as in
Arm's shared pseudocode; a failed attempt does not unconditionally establish
that the next attempt has an empty monitor.

`ExclusiveStep` relates a concrete execution to an admissible environment
witness. Certification must cover every actual environment via a checked
native-to-proof relation. A fresh0/1 marker can provide a conservative status
abstraction only with that relation, source-PC/width/order binding and address/
fault/ordering obligations. An arbitrary entry monitor cannot be assumed empty.
CLREX proves no successful write, but the implementation's failure-fault policy
still matters for invalid addresses.

Successful stores emit one `.memory.write` carrying written bytes, plus an
explicit `.exclusive.attempt` event with width/release/success. Exclusive loads
emit one native-width read plus an explicit reservation/acquire event. There
is no fake helper effect or extra old-value read. The first prototype used the
existing `.memory.atomic` label, but T correctly identified that its BPF model
uses that label for RMW/pre-write bytes. The prototype was corrected and the
entire formal check rerun. Both full-check logs are retained. A proof store
cannot be silently relabeled atomic: its single-copy atomicity and ordering
must be established for the actual matched platform. Using an exchange would
introduce read/permission effects that a native exclusive store does not have.

```sh
taskset -c 20-23 make -C /workspaces/.agent-state/kprog-lanes/F/exclusive-export/kprog/formal -f exclusive.mk model exclusive-wire wire axioms
taskset -c 20-23 prlimit --as=12884901888 -- make -C /workspaces/.agent-state/kprog-lanes/F/exclusive-export/kprog/formal check
```

The private source base is23f3c6931 plus the five exclusive files and one Make
invocation. No other lane's source/cache was mutated by this check.
`source-artifacts.tar.gz` preserves that exact source export and recipes;
`reference.gz` is the tested executable. Full logs and theorem dependencies
are preserved alongside them. Primary definitions are Arm DDI0602 STXR/STLXR,
CLREX and exclusive shared pseudocode, as linked in the parent finding report.
The hardware evidence in the parent directory compares registers/memory with
an explicitly cleared monitor; it does not invent physical reservation facts.
