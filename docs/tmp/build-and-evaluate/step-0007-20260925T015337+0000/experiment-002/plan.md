# Experiment 002 Plan: Attribute Cilium `map_inline` Opportunities

Date: 2026-09-25T02:06:00+00:00
Phase: BUILD_AND_EVALUATE
Selected paper question: RQ2, "When Do Runtime Side Inputs Add Value?"

This experiment asks a narrower prerequisite question: which live map
snapshots supplied the sites that `map_inline` reported applying during one
real Cilium startup, and were those maps frozen deployment configuration or
mutable runtime state?

## Paper-value admission

The historical Cilium `map_inline` batch has a positive repeated throughput
difference but no per-step reports.  A newer single-pass Cilium artifact
retains the optimizer reports and the exact map metadata and dumps supplied to
each invocation.  Step 0005 correctly found that this artifact cannot prove a
bytecode transformation because its actual before images were overwritten.
That defect does not erase the independently retained map snapshots or the
optimizer's recorded site decisions.  This experiment makes the narrower,
directly testable attribution and keeps the failed bytecode claim failed.

The distinction is important to the paper: specialization of loader-populated,
then-frozen `.rodata` is deployment-time specialization, while specialization
of a mutable map would require a phase-stability argument and fallback policy.
Knowing which class supplies the current opportunity changes both RQ2's
mechanism interpretation and the design of the next retained KVM run.

The sole input is the complete local single-pass artifact:

`corpus/results/x86_kvm_corpus_20260919_041801_813418`

It is the already-audited current artifact with exact `map_inline` policy,
one Cilium optimized application start, per-load map snapshots, report stream,
and shim log.  No workload result is selected or filtered for this analysis.

## Hypothesis and competing result

Exploratory inspection of one changed workdir suggests that the applied entry
belongs to a frozen map named `.rodata.config`.  The predeclared hypothesis is
that every reported applied site across the artifact joins to a snapshot of a
frozen `.rodata.config` map.  The competing result is a mixed population that
also contains mutable or differently named maps.  A structurally complete
zero-opportunity result is also valid and contradicts the hypothesis.

This experiment does not assert that reported rewrites occurred, survived
later processing, attached, executed, or caused the paired throughput
observation.  It does not establish cross-start stability.  Counts refer to
load instances and reported sites; repeated loads are retained rather than
deduplicated into a fictitious program population.

## Declared evidence and classifications

An analysis-only tool will validate:

- completed x86 KVM corpus metadata, `SAMPLES=1`, 30-second workload, and exact
  enabled pass list `map_inline`;
- Cilium status `ok`, empty error, and a one-step `map_inline` load-time plan;
- every nonblank JSONL report row parses, names `map_inline` at step zero, and
  has `sites_matched == sites_applied + sites_skipped`, exactly
  `sites_applied` inlined-entry records, and no entries when `sites_applied`
  is zero;
- every reported inlined entry has an integer `map_id`, hexadecimal key and
  value, and `phase-stable` label;
- within that report's retained workdir, exactly one
  `map-values/map-<id>.show.json` names the same integer ID and provides map
  name, type, flags, and frozen state;
- a corresponding dump exists and contains the reported key; reported-value
  containment is printed only as a weak consistency diagnostic because the
  report omits the source byte offset and short values are not unique;
- missing metadata, dump entries, ambiguous joins, malformed hex, and report
  inconsistencies are printed and make the result invalid rather than being
  silently skipped.

The tool prints raw totals and grouped counts by map name, map type, frozen
state, flags, program name/type, changed load instance, and applied-site
occurrence.  It also prints the number of report rows with no applied sites.
It computes no workload summary and uses no program or artifact hashes.

The predeclared outcome is:

- **supported:** the applied set is nonempty and every applied entry joins to
  an `array` map named `.rodata.config` with `frozen == 1`;
- **mixed:** the applied set is nonempty and structurally valid but includes
  both that frozen map class and at least one other map class;
- **contradicted:** the evidence is structurally valid but has no applied
  entry, or none of its applied entries belong to frozen `.rodata.config`;
- **invalid/inconclusive:** any required report, metadata record, map dump, or
  unambiguous join is absent or inconsistent.

Supported, mixed, and contradicted exit zero.  Invalid/inconclusive exits
nonzero.  No classification depends on throughput direction.

## Execution and completion

After plan approval, a parser/data-path preflight uses the first changed
workdir only and writes stdout/stderr beneath this experiment directory.  The
formal run then analyzes the complete artifact exactly once:

```sh
timeout 120s python3 analysis/audit_map_inline_snapshots.py \
  corpus/results/x86_kvm_corpus_20260919_041801_813418 \
  > docs/tmp/build-and-evaluate/step-0007-20260925T015337+0000/experiment-002/formal-output.json \
  2> docs/tmp/build-and-evaluate/step-0007-20260925T015337+0000/experiment-002/formal-stderr.txt
```

The analyzer will expose `--workdir` for the one-workdir preflight and require
that name to occur in the report stream.  A Cilium artifact with no retained
workdirs is used only as a parser-negative development check, not a scientific
completion gate.

An independent result reviewer must directly recompute total applied sites,
changed load instances, the map-class groups, and at least one dump join
without importing the analyzer.  Completion requires an approved plan, real
one-workdir preflight, complete formal output, and result review.

A supported result may add only this narrowly worded observation to the paper:
in this one retained Cilium startup, every optimizer-reported applied entry
referenced a workdir-local map ID whose metadata named a frozen
`.rodata.config` array.  A mixed result may report the observed class counts
but cannot use the word `every`.  Either statement must carry the
missing-before-image limitation and
must not imply that rewrites occurred, values were independently reconstructed
at exact offsets, opportunities are stable across starts, runtime inputs
improved performance, or RQ2 is answered.  It must not be placed in the
throughput table or described as causal performance evidence.  The next causal
experiment remains a clean Make-backed single-pass run with
`KEEP_WORKDIRS=1` after the AE owner commits or removes its optimizer WIP.

This experiment modifies no workload, application, runner, Makefile, runtime
image, pass policy, optimizer, or raw artifact.
