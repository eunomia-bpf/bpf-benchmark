# BPFOptBench Exploration Process Analysis

Date: 2026-06-24

## Executive Summary

The 2,874 sessions documented in BPFOptBench were generated through a **hybrid approach**:
1. **Scripted shell-script loops** for batch ablation studies (minority)
2. **LLM agent-driven runs** via Claude Code, where the agent invoked `make corpus` with varying configurations (majority)

This is **genuinely agentic exploration**, not pure grid search. The exploration strategy is **LLM-guided adaptive iteration** where Claude Code observed results, diagnosed failures, adjusted pass configurations, and re-ran experiments.

---

## 1. Evidence for LLM Agent Involvement

### 1.1 Git Commit Authorship

```
Total commits by codex@openai.com: 1,651
Date range: March 2026 - June 2026
```

The `codex@openai.com` author indicates OpenAI Codex CLI agent commits, representing autonomous agent work. This is the authoritative signal of agent involvement.

### 1.2 Claude Code Session Metadata

From `/home/yunwei37/.claude/usage-data/session-meta/`:
- 214 tracked Claude Code sessions
- 14 sessions directly in the bpf-benchmark project
- Example session (`031b32a9-...`):
  - Duration: 304 minutes (5+ hours)
  - 64 user messages, 693 assistant messages
  - 267 Bash invocations, 27 Edit operations
  - Output tokens: 1,003,091 (~1M tokens of agent reasoning)
  - First prompt: "apply 数目和之前的 corpus 对比分析一下, 然后试试重新跑一下 corpus?"

The high Bash invocation count (267) combined with Edit operations (27) shows the agent was iteratively running benchmarks and modifying code based on observations.

### 1.3 Workflow Rules from Memory

From `/home/yunwei37/.claude/projects/-home-yunwei37-workspace-bpf-benchmark/memory/MEMORY.md`:

> **2026-05-20 起: Claude 自己跑所有 build/test/实现，不用 codex**

Before May 20: Codex CLI (via `codex exec`) drove runs
After May 20: Claude Code directly invokes `make corpus` via Bash tool

This transition explains the 2,874 sessions:
- Pre-May-20: Codex agent sessions (commits by codex@openai.com)
- Post-May-20: Claude Code sessions (Bash tool with `run_in_background`)

---

## 2. Evidence for Script Automation (Minority)

### 2.1 Explicit Shell Scripts

Two scripts in `/home/yunwei37/workspace/bpf-benchmark/scripts/`:

1. `run_isolated_passes_20260508.sh` - 3-configuration ablation:
   - K5: 5-pass kinsn (rotate, cond_select, extract, endian_fusion, bulk_memory)
   - K6: 6-pass kinsn (+prefetch)
   - BR: bytecode-rewriting only (noop, wide_mem, const_prop, dce, bounds_check_merge, skb_load_bytes_spec)

2. `rerun_widemem_after_queue_20260507.sh` - Watchdog script that waits for queue completion then re-runs wide_mem

These scripts invoke `make corpus` in loops but represent **scripted batch jobs**, not agentic exploration.

### 2.2 Script-Driven Session Patterns

Some sessions show tight temporal clustering (e.g., May 21: 157 sessions, May 22: 142 sessions). This density could indicate:
- Agent rapidly iterating with short workloads
- Batch scripts cycling through configurations

However, the metadata shows `enabled_passes` varies between runs (25 unique configurations), indicating adaptive selection rather than exhaustive grid search.

---

## 3. Exploration Strategy Analysis

### 3.1 Not Grid Search

Grid search would enumerate all combinations:
- 11 passes * 6 apps * 3 samples * 2 architectures = 396 combinations
- But we see 25 unique pass configurations, not 2^11 = 2048 possible subsets

The exploration is **sparse and targeted**, focusing on:
1. Individual passes (e.g., `noop`, `map_inline only`, `rotate only`)
2. Family groupings (e.g., "kinsn 5-pass", "bytecode-rewriting only")
3. Full pipeline (11 passes)

### 3.2 Adaptive Iteration Pattern

The session timeline reveals reactive exploration:

1. **May 7-8 Noise Floor Discovery**:
   - Sessions: `x86_kvm_corpus_20260507_190554_205137` (Q1 noop ReJIT)
   - Sessions: `x86_kvm_corpus_20260508_000244_131324` (P1 skip-rejit)
   - Finding: 4.3% baseline drift
   - Response: Subsequent runs adjusted interpretation thresholds

2. **June 2 LEA Crash Day**:
   - 94 sessions, 77 errors (82% failure rate)
   - This is clearly debugging iteration, not batch job failure

3. **June 3 Kinsn Breakthrough**:
   - Session: `x86_kvm_corpus_20260603_175429_964295`
   - Result: 0.938x geomean (6.2% improvement)
   - Response: ARM64 expansion prioritized

These patterns show **learning from failures** - a hallmark of agentic exploration.

### 3.3 Decision Tracing

The agent's reasoning is traceable through:

1. **Git commit messages** (by codex@openai.com):
   - "Enhance native loader with key offset support and post-processing for lookup calls"
   - "Refactor BPF optimization commands and update Dockerfile"
   - These show agent-synthesized understanding, not templated descriptions

2. **Session metadata** showing tool error categories:
   - "Command Failed": 8 errors in one session
   - These failures prompted agent adaptation

3. **MEMORY.md feedback entries**:
   - 40+ feedback rules accumulated over project lifetime
   - Each rule records a lesson learned and policy adjustment
   - Example: "feedback_no_rejit_filtering: 严禁过滤/排除/跳过任何 BPF 程序的 ReJIT"

---

## 4. Hybrid Model Characterization

### 4.1 Invocation Mechanism

All 2,874 sessions ultimately run through:

```makefile
make corpus
  PLATFORM=kvm ARCH=x86 SAMPLES=3
  BPFREJIT_BENCH_PASSES="noop,map_inline"
  ...
```

The Makefile is the **execution primitive**, but **parameter selection** comes from:
1. Agent reasoning (Claude Code/Codex)
2. User directives (in conversation)
3. Batch scripts (minority)

### 4.2 Agent Autonomy Spectrum

| Aspect | Human-Driven | Agent-Driven |
|--------|--------------|--------------|
| Pass selection | User says "test kinsn" | Agent picks after observing failure |
| Sample count | User sets SAMPLES=3 | Agent uses defaults |
| Failure response | User reads log | Agent diagnoses, modifies code, re-runs |
| Configuration combinations | User enumerates | Agent explores adaptively |

The project operates at **high agent autonomy** for most exploration work.

### 4.3 Not Reinforcement Learning

This is not RL because:
- No explicit reward function
- No learned policy parameters
- No exploration-exploitation tradeoff formalization

It is **LLM-guided heuristic search** where:
- Prior results inform next configuration choice
- Agent uses semantic understanding of pass semantics
- Human provides high-level direction, agent handles iteration

---

## 5. Visualization Recommendations

### 5.1 Timeline Visualization

A Gantt-style chart showing:
- X-axis: Time (March 2026 - June 2026)
- Y-axis: Stacked by platform (x86 KVM, AWS ARM64, QEMU ARM64)
- Color: Pass configuration cluster
- Annotations: Key discoveries (noise floor, LEA crash, kinsn breakthrough)

### 5.2 Configuration Space Heatmap

Matrix showing:
- Rows: Pass configurations (25 unique)
- Columns: Apps (6)
- Cell color: Session count or success rate

### 5.3 Agent Decision Flow

Sankey diagram showing:
- Sources: Session outcomes (completed, error, timeout)
- Targets: Next configuration choice
- Width: Number of transitions

This would visualize how failure types influenced subsequent exploration.

### 5.4 Commit-Session Correlation

Scatter plot showing:
- X: Commit timestamp
- Y: Session start timestamp
- Color: Author (codex@openai.com vs human)

This would show the tight coupling between code changes and experiment runs.

---

## 6. Conclusions

### 6.1 Is This "Agentic" Exploration?

**Yes.** The evidence shows:
1. 1,651 commits by LLM agent (codex@openai.com)
2. 214 tracked Claude Code sessions with iterative tool usage
3. Adaptive configuration selection (25 configs from 2048 possible)
4. Failure-driven learning (LEA crash day -> June 3 breakthrough)
5. Accumulated policy rules in MEMORY.md

### 6.2 What Kind of Agent System?

- **Architecture**: Claude Code CLI (Anthropic) + Codex CLI (OpenAI) as execution agents
- **Invocation**: User conversation -> Agent reasoning -> Bash tool -> `make corpus`
- **State**: MEMORY.md (accumulated rules), git history (code changes), results/ (data)
- **Strategy**: Heuristic adaptive search, not grid search or RL

### 6.3 Reproducibility Implications

The exploration is **not deterministically reproducible** because:
- LLM agent reasoning is stochastic
- Configuration choices depend on prior session outcomes
- User directives in conversation are not fully logged

However, the **final configurations** are reproducible (YAML + env vars), and the **design space coverage** could be approximated by re-running the 25 observed configurations.

---

## Appendix: Key Files

| File | Purpose |
|------|---------|
| `/home/yunwei37/.claude/usage-data/session-meta/*.json` | Claude Code session metadata |
| `/home/yunwei37/.claude/projects/-home-yunwei37-workspace-bpf-benchmark/memory/MEMORY.md` | Accumulated agent rules |
| `/home/yunwei37/workspace/bpf-benchmark/corpus/results/*/metadata.json` | Per-run configuration |
| `/home/yunwei37/workspace/bpf-benchmark/scripts/*.sh` | Batch automation scripts |
| Git log `--author="codex@openai.com"` | Agent commits (1,651 total) |
