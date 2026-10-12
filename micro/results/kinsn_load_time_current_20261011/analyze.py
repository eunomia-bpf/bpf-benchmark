#!/usr/bin/env python3
"""Kernel-side load time of the 62 paper micro programs with and without kinsn.

Run from the clone root:
  python3 micro/results/kinsn_load_time_current_20261011/analyze.py \
      --here micro/results/kinsn_load_time_current_20261011 kinsn-current kinsn-june full-current

Inputs (read-only; each raw file may also be read from its .gz copy):
  * <here>/runs/<arm>/result/details/result.json  micro driver output (runtimes kernel, kernel_rejit)
  * <here>/runs/<arm>/kprobe-trace.txt             guest kprobe trace of bpf_prog_load, bpf_check,
                                                   bpf_prog_select_runtime and (kinsn-june,
                                                   full-current) lower_kinsn_proof_regions and
                                                   do_check_common (x86-tsc clock)
  * <here>/runs/<arm>/make-vars, dmesg.txt          suite settings, guest TSC frequency
  * <here>/paper-62.txt, prog-names.txt             population and ELF program names
  * kinsn/paper/atc26/data/micro/...               May14 campaigns and the Apr29 population

Outputs: <here>/per-program.csv, <here>/summary.json, <here>/per-program-tables.md

Two families of numbers:
  1. Paper protocol: geomean over the 62 programs of median(kernel_rejit field) /
     median(kernel field) for compile_ns and phases_ns.object_load_ns, as in
     kinsn/paper/atc26/scripts/regenerate.py.  In kernel_rejit, micro_exec times the
     ORIGINAL object load before it waits for the ReJIT signal (runner/src/kernel_runner.cpp),
     so these fields never include verification or JIT of the kinsn-rewritten program.
  2. Kernel trace: in-kernel durations of BPF_PROG_LOAD (total), bpf_check (verification,
     including kinsn proof lowering/restore; for programs with subprograms it also contains
     their JIT) and bpf_prog_select_runtime (JIT), plus prog->aux->verified_insns, for
     (a) the original program in the `kernel` runtime and (b) the kinsn-rewritten program
     that the shim loads during ReJIT in the `kernel_rejit` runtime.
"""
from __future__ import annotations

import argparse
import csv
import gzip
import json
import math
import re
import statistics
from pathlib import Path

PAPER_DATA = Path("kinsn/paper/atc26/data/micro")
POPULATION = "x86_kvm_micro_20260429_035938_203074"
MAY14 = ["x86_kvm_micro_20260514_031744_210343", "x86_kvm_micro_20260514_181806_133778"]
PROG_TYPES = {3, 6, 8}  # sched_cls, xdp, cgroup_skb
ERRNO = {-7: "E2BIG", -12: "ENOMEM", -13: "EACCES", -22: "EINVAL", -28: "ENOSPC", -14: "EFAULT"}

LINE = re.compile(
    r"^\s*(?P<comm>.*)-(?P<pid>\d+)\s+\(\s*(?P<tgid>\d+|-+)\)\s+\[(?P<cpu>\d+)\]\s+\S+\s+"
    r"(?P<ts>\d+):\s+(?P<ev>\w+):\s+\((?P<loc>[^)]*)\)\s*(?P<args>.*)$"
)
ARG = re.compile(r'(\w+)=("(?:[^"\\]|\\.)*"|\S+)')


def gm(values):
    values = list(values)
    if not values:
        return None
    return math.exp(statistics.mean(math.log(v) for v in values))


def med(values):
    values = [v for v in values if v is not None]
    return statistics.median(values) if values else None


def read_text(path: Path) -> str:
    """Read a file, falling back to its .gz copy (the committed form of the raw run outputs)."""
    if path.is_file():
        return path.read_text(errors="replace")
    gz = path.with_name(path.name + ".gz")
    with gzip.open(gz, "rt", errors="replace") as fh:
        return fh.read()


def load_json(path: Path):
    return json.loads(read_text(path))


# ---------------------------------------------------------------- paper protocol

def sample_field(sample, field):
    if field in ("object_load_ns", "object_open_ns"):
        return (sample.get("phases_ns") or {}).get(field)
    return sample.get(field)


def medians(result, runtime, field):
    out = {}
    for bench in result.get("benchmarks", []):
        for run in bench.get("runs", []):
            if run["runtime"] != runtime:
                continue
            vals = [sample_field(s, field) for s in run.get("samples", [])]
            vals = [v for v in vals if v is not None]
            if vals:
                out[bench["name"]] = statistics.median(vals)
    return out


def paper_ratio(result, population, field):
    base, cand = medians(result, "kernel", field), medians(result, "kernel_rejit", field)
    if any(n not in base or n not in cand for n in population):
        return None
    return gm(cand[n] / base[n] for n in population)


# ---------------------------------------------------------------- kprobe trace

def parse_trace(path: Path):
    """Completed bpf_prog_load records in time order (one per syscall)."""
    loads, current = [], {}
    for raw in read_text(path).splitlines():
        if raw.startswith("#"):
            continue
        m = LINE.match(raw)
        if not m:
            continue
        pid, ts, ev = int(m["pid"]), int(m["ts"]), m["ev"]
        args = {k: (v[1:-1] if v.startswith('"') else v) for k, v in ARG.findall(m["args"])}
        if ev == "load":
            current[pid] = {
                "tid": pid, "tgid": int(m["tgid"]) if m["tgid"].isdigit() else pid,
                "comm": m["comm"].strip(), "t0": ts, "ptype": int(args.get("ptype", -1)),
                "insn_cnt": int(args.get("insn_cnt", -1)), "log_level": int(args.get("log_level", -1)),
                "name": args.get("name", ""),
            }
            continue
        rec = current.get(pid)
        if rec is None:
            continue
        if ev == "check":
            rec["c0"] = ts
        elif ev == "check_ret":
            rec["c1"] = ts
        elif ev == "sel":
            rec["s0"], rec["verified_insns"] = ts, int(args.get("vi", -1))
        elif ev == "sel_ret":
            rec["s1"], rec["jited_len"] = ts, int(args.get("jlen", -1))
        elif ev == "proof":
            rec.setdefault("proofs", []).append((args.get("fn", "").split("+")[0], int(args.get("cnt", 0))))
        elif ev in ("lower", "docheck"):
            rec["_" + ev] = ts
        elif ev in ("lower_ret", "docheck_ret"):
            key = ev[:-4]
            if "_" + key in rec:
                rec[key + "_ticks"] = rec.get(key + "_ticks", 0) + ts - rec.pop("_" + key)
        elif ev == "load_ret":
            rec["t1"], rec["ret"] = ts, int(args.get("ret", 0))
            loads.append(rec)
            del current[pid]
    return loads


def tsc_hz(run_dir: Path, result):
    dmesg = run_dir / "dmesg.txt"
    if dmesg.is_file():
        text = dmesg.read_text(errors="replace")
        for pat in (r"tsc: Refined TSC clocksource calibration: ([0-9.]+) MHz", r"tsc: Detected ([0-9.]+) MHz"):
            m = re.search(pat, text)
            if m:
                return float(m.group(1)) * 1e6
    vals = [s.get("tsc_freq_hz") for b in result["benchmarks"] for r in b["runs"] for s in r["samples"]]
    return statistics.median(v for v in vals if v)


def assign_processes(loads, names, prog_names, runtimes, samples):
    """Map micro_exec processes to (benchmark, runtime) in driver order.

    micro/driver.py runs benchmarks in manifest order; with two runtimes, sample i uses the
    RUNTIMES order for even i and the reverse for odd i.  Each sample is one micro_exec
    process; its program loads (original, and in kernel_rejit the shim's reloads from a
    shim thread of the same process) carry the program name.
    """
    procs = {}
    for rec in loads:
        if rec["ptype"] in PROG_TYPES and rec["name"] and rec["comm"] == "micro_exec":
            procs.setdefault(rec["tgid"], []).append(rec)
    ordered = sorted(procs.values(), key=lambda recs: recs[0]["t0"])
    out, idx = {}, 0
    for bench in names:
        prefix = prog_names[bench][:15]
        for i in range(samples):
            for rt in (runtimes if i % 2 == 0 else list(reversed(runtimes))):
                while idx < len(ordered) and ordered[idx][0]["name"] != prefix:
                    idx += 1
                if idx >= len(ordered):
                    raise SystemExit(f"trace ran out of processes at {bench}/{rt}/{i}")
                out.setdefault(bench, {}).setdefault(rt, []).append(
                    [r for r in ordered[idx] if r["name"] == prefix])
                idx += 1
    return out


def dur(rec, a, b, hz):
    return (rec[b] - rec[a]) * 1e9 / hz if a in rec and b in rec else None


def ticks(rec, key, hz):
    """Summed duration of a probed inner function (lower / docheck), if it was traced."""
    return rec[key + "_ticks"] * 1e9 / hz if key + "_ticks" in rec else None


# ---------------------------------------------------------------- rejit reports

def rejit_steps(result, prog_names):
    """Per benchmark: list over kernel_rejit samples of per-pass step dicts for the benchmark
    program (the shim also reports libbpf's feature-probe programs, which it leaves unchanged)."""
    info = {}
    for bench in result["benchmarks"]:
        samples = []
        if bench["name"] not in prog_names:  # e.g. katran_like, outside the 62-program population
            continue
        prefix = prog_names[bench["name"]][:15]
        for run in bench.get("runs", []):
            if run["runtime"] != "kernel_rejit":
                continue
            for s in run["samples"]:
                for prog in ((s.get("rejit_result") or {}).get("per_program") or {}).values():
                    if ((prog.get("program") or {}).get("prog_name") or "")[:15] != prefix:
                        continue
                    steps = []
                    for p in prog.get("passes", []):
                        summary = p.get("bpfopt_summary") or {}
                        steps.append({
                            "pass": (p.get("step") or {}).get("name") or summary.get("pass"),
                            "status": p.get("status"), "error": p.get("error") or "",
                            "sites_applied": summary.get("sites_applied"),
                            "rejit_syscall_ms": p.get("rejit_syscall_ms"),
                            "ops": summary.get("kinsn_calls_by_name") or {},
                        })
                    samples.append({"status": prog.get("status"), "program": prog.get("program") or {},
                                    "steps": steps})
        info[bench["name"]] = samples
    return info


# ---------------------------------------------------------------- per arm

def analyze_arm(run_dir: Path, names, prog_names):
    result = load_json(run_dir / "result" / "details" / "result.json")
    by_name = {b["name"]: b for b in result["benchmarks"]}
    make_vars = dict(l.split("=", 1) for l in (run_dir / "make-vars").read_text().splitlines() if "=" in l)
    runtimes = [t for t in make_vars["RUNTIMES"].replace(",", " ").split()]
    samples = int(make_vars["SAMPLES"])
    hz = tsc_hz(run_dir, result)
    loads = parse_trace(run_dir / "kprobe-trace.txt")
    procs = assign_processes(loads, names, prog_names, runtimes, samples)
    steps_by_bench = rejit_steps(result, prog_names)

    rows = []
    for n in names:
        b = by_name.get(n, {})
        kp = procs[n].get("kernel", [])
        rp = procs[n].get("kernel_rejit", [])
        k = [p[0] for p in kp]
        orig = [p[0] for p in rp]
        last_attempt, ok_reload, path_total, diag_total = [], [], [], []
        attempt_rets = set()
        for p in rp:
            attempts = [r for r in p[1:] if r["log_level"] == 0]
            diags = [r for r in p[1:] if r["log_level"] != 0]
            if attempts:
                last_attempt.append(attempts[-1])
                attempt_rets.add(attempts[-1]["ret"])
                if attempts[-1]["ret"] >= 0:
                    ok_reload.append(attempts[-1])
            path_total.append(sum(dur(r, "t0", "t1", hz) for r in p))
            diag_total.append(sum(dur(r, "t0", "t1", hz) for r in diags))
        row = {"benchmark": n, "prog_name": prog_names[n]}
        for rt in ("kernel", "kernel_rejit"):
            run = next((r for r in b.get("runs", []) if r["runtime"] == rt), None)
            ss = run["samples"] if run else []
            row[f"{rt}_samples"] = len(ss)
            row[f"{rt}_compile_ns_median"] = med(s.get("compile_ns") for s in ss)
            row[f"{rt}_object_load_ns_median"] = med((s.get("phases_ns") or {}).get("object_load_ns") for s in ss)
        row["bench_error"] = (b.get("error") or "")[:300]
        row["orig_insn_cnt"] = med(r["insn_cnt"] for r in k)
        row["orig_load_ret_min"] = min((r["ret"] for r in k + orig), default=None)
        row["orig_load_ns"] = med(dur(r, "t0", "t1", hz) for r in k)
        row["orig_check_ns"] = med(dur(r, "c0", "c1", hz) for r in k)
        row["orig_jit_ns"] = med(dur(r, "s0", "s1", hz) for r in k)
        row["orig_verified_insns"] = med(r.get("verified_insns") for r in k)
        row["orig_load_in_rejit_proc_ns"] = med(dur(r, "t0", "t1", hz) for r in orig)
        row["reload_attempted_samples"] = len(last_attempt)
        row["reload_ok_samples"] = len(ok_reload)
        row["reload_ret"] = ",".join(str(x) for x in sorted(attempt_rets))
        row["reload_errno"] = ",".join(ERRNO.get(x, str(x)) for x in sorted(attempt_rets) if x < 0)
        row["kinsn_insn_cnt"] = med(r["insn_cnt"] for r in last_attempt)
        row["kinsn_attempt_ns"] = med(dur(r, "t0", "t1", hz) for r in last_attempt)
        row["kinsn_load_ns"] = med(dur(r, "t0", "t1", hz) for r in ok_reload)
        row["kinsn_check_ns"] = med(dur(r, "c0", "c1", hz) for r in ok_reload)
        row["kinsn_jit_ns"] = med(dur(r, "s0", "s1", hz) for r in ok_reload)
        row["kinsn_verified_insns"] = med(r.get("verified_insns") for r in ok_reload)
        # optional finer probes (runs with lower_kinsn_proof_regions / do_check_common kprobes)
        row["orig_docheck_ns"] = med(ticks(r, "docheck", hz) for r in k)
        row["kinsn_lower_ns"] = med(ticks(r, "lower", hz) for r in ok_reload)
        row["kinsn_docheck_ns"] = med(ticks(r, "docheck", hz) for r in ok_reload)
        # kinsn proof sequences lowered for the rewritten program (runs with the
        # validate_kinsn_proof_seq probe); taken from the last attempt of the first sample
        proofs = last_attempt[0].get("proofs") if last_attempt else None
        if proofs:
            by_fn = {}
            for fn, cnt in proofs:
                op = fn.replace("instantiate_", "")
                c, t, mx = by_fn.get(op, (0, 0, 0))
                by_fn[op] = (c + 1, t + cnt, max(mx, cnt))
            row["proof_calls"] = len(proofs)
            row["proof_insns_total"] = sum(c for _, c in proofs)
            row["proof_max"] = max(c for _, c in proofs)
            row["proof_by_fn"] = ";".join(f"{op}:{c}x/{t}/max{mx}" for op, (c, t, mx)
                                          in sorted(by_fn.items(), key=lambda kv: -kv[1][1]))
            # lowering runs from the last instruction backwards; when it fails (ENOMEM:
            # 16-bit jump range) the last lowered call is the one that could not be patched
            row["last_lowered_proof"] = f"{proofs[-1][0].replace('instantiate_', '')}:{proofs[-1][1]}"
        else:
            row["proof_calls"] = row["proof_insns_total"] = row["proof_max"] = None
            row["proof_by_fn"] = row["last_lowered_proof"] = ""
        row["kinsn_path_total_ns"] = med(path_total)
        row["diag_reload_ns"] = med(diag_total)
        # ratios against the original program's load in the `kernel` runtime
        o = row["orig_load_ns"]
        row["ratio_kinsn_load"] = row["kinsn_load_ns"] / o if row["kinsn_load_ns"] else None
        attempt_or_orig = row["kinsn_attempt_ns"] if row["kinsn_attempt_ns"] else row["orig_load_in_rejit_proc_ns"]
        row["ratio_kinsn_attempt_or_unchanged"] = attempt_or_orig / o
        row["ratio_kinsn_path_total"] = row["kinsn_path_total_ns"] / o
        row["ratio_check"] = (row["kinsn_check_ns"] / row["orig_check_ns"]) if row["kinsn_check_ns"] else None
        row["ratio_verified_insns"] = ((row["kinsn_verified_insns"] / row["orig_verified_insns"])
                                       if row["kinsn_verified_insns"] else None)
        # rejit report
        ss = steps_by_bench.get(n, [])
        row["rejit_status"] = ",".join(sorted({str(s["status"]) for s in ss}))
        last = {}
        for s in ss:
            for st in s["steps"]:
                last[st["pass"]] = st
        row["passes"] = ";".join(f"{p}:{st['status']}:{st['sites_applied']}" for p, st in last.items())
        kin = last.get("kinsn") or {}
        row["kinsn_step_status"] = kin.get("status") or ""
        row["kinsn_sites_applied"] = kin.get("sites_applied")
        row["kinsn_ops"] = ";".join(f"{k.replace('bpf_x86_', '')}:{v}" for k, v in sorted(kin.get("ops", {}).items()))
        row["kinsn_rejit_syscall_ms_median"] = med(st["rejit_syscall_ms"] for s in ss for st in s["steps"]
                                                   if st["pass"] == "kinsn")
        errors = [st["error"] for s in ss for st in s["steps"] if st["error"]]
        row["rejit_error_tail"] = (errors[-1][-700:] if errors else "").replace("\n", " | ")
        rows.append(row)
    return {"rows": rows, "result": result, "tsc_hz": hz, "traced_loads": len(loads),
            "samples": samples, "runtimes": runtimes, "make_vars": make_vars}


def summarize_arm(a, names):
    rows = a["rows"]
    ok = [r for r in rows if r["reload_ok_samples"]]
    failed = [r for r in rows if r["reload_errno"]]
    unchanged = [r for r in rows if not r["reload_attempted_samples"]]
    s = {
        "make_vars": {k: v for k, v in a["make_vars"].items()
                      if k in ("RUNTIMES", "SAMPLES", "WARMUPS", "INNER_REPEAT", "BPFREJIT_BENCH_PASSES")},
        "tsc_hz": a["tsc_hz"], "traced_loads": a["traced_loads"],
        "paper_protocol_geomean": {f: paper_ratio(a["result"], names, f) for f in ("compile_ns", "object_load_ns")},
        "original_program_load_ok": sum(1 for r in rows if (r["orig_load_ret_min"] or 0) >= 0
                                        and r["kernel_samples"] == a["samples"]
                                        and r["kernel_rejit_samples"] == a["samples"]),
        "kinsn_reload_ok": len(ok),
        "kinsn_reload_failed": {r["benchmark"]: r["reload_errno"] for r in failed},
        "kinsn_unchanged_no_reload": [r["benchmark"] for r in unchanged],
        "geomean": {
            "kinsn_load_over_orig_load__reload_ok_only": gm(r["ratio_kinsn_load"] for r in ok),
            "kinsn_check_over_orig_check__reload_ok_only": gm(r["ratio_check"] for r in ok if r["ratio_check"]),
            "kinsn_verified_insns_over_orig__reload_ok_only": gm(r["ratio_verified_insns"] for r in ok
                                                                 if r["ratio_verified_insns"]),
            "kinsn_attempt_or_unchanged_over_orig__all62": gm(r["ratio_kinsn_attempt_or_unchanged"] for r in rows),
            "kinsn_path_total_over_orig__all62": gm(r["ratio_kinsn_path_total"] for r in rows),
            "orig_load_in_rejit_proc_over_orig__all62": gm(r["orig_load_in_rejit_proc_ns"] / r["orig_load_ns"]
                                                          for r in rows),
            # programs whose original load takes >= 1 ms, where the reload path's fixed cost
            # (tens of microseconds, visible on `simple` with identical verified insns) is negligible
            "kinsn_load_over_orig_load__reload_ok_orig_ge_1ms": gm(r["ratio_kinsn_load"] for r in ok
                                                                    if r["orig_load_ns"] >= 1e6),
            "count_reload_ok_orig_ge_1ms": sum(1 for r in ok if r["orig_load_ns"] >= 1e6),
            # programs whose rewritten form is accepted, counting every failed or skipped
            # program as unchanged (1.0x): the most favourable 62-program reading
            "kinsn_load_over_orig__all62_failures_as_1": gm(
                [r["ratio_kinsn_load"] for r in ok] + [1.0] * (len(rows) - len(ok))),
        },
        "lowering_share_of_bpf_check__reload_ok_median": med(
            r["kinsn_lower_ns"] / r["kinsn_check_ns"] for r in ok if r["kinsn_lower_ns"] and r["kinsn_check_ns"]),
        "docheck_ratio__reload_ok_geomean": gm(
            r["kinsn_docheck_ns"] / r["orig_docheck_ns"] for r in ok if r["kinsn_docheck_ns"] and r["orig_docheck_ns"]),
        "sum_ms": {
            "orig_load": sum(r["orig_load_ns"] for r in rows) / 1e6,
            "kinsn_attempt_or_unchanged": sum((r["kinsn_attempt_ns"] or r["orig_load_in_rejit_proc_ns"])
                                              for r in rows) / 1e6,
        },
    }
    top = sorted(ok, key=lambda r: r["kinsn_load_ns"] - r["orig_load_ns"], reverse=True)[:10]
    s["largest_absolute_increase__reload_ok"] = [
        {"benchmark": r["benchmark"], "orig_ms": r["orig_load_ns"] / 1e6, "kinsn_ms": r["kinsn_load_ns"] / 1e6,
         "ratio": r["ratio_kinsn_load"], "verified_insns": [r["orig_verified_insns"], r["kinsn_verified_insns"]],
         "kinsn_ops": r["kinsn_ops"]} for r in top]
    return s


def verifier_message(tail: str) -> str:
    """The verifier's rejection line: the log line just before the 'processed N insns' summary."""
    parts = [p.strip() for p in tail.split(" | ")]
    for i, p in enumerate(parts):
        if p.startswith("processed ") and i > 0:
            return parts[i - 1]
    if "stack spills exceed" in tail:
        return "bpfopt: LLVM output stack spills exceed the BPF 512-byte frame"
    return tail[-160:]


def failure_cause(row) -> str:
    """Operation/module behind a failed reload, from the verifier message and the program's kinsn calls."""
    msg, ops = verifier_message(row["rejit_error_tail"]), row["kinsn_ops"]
    if "cannot be patched due to 16-bit range" in msg:
        if "bextrq" in ops:
            return "kinsn lowering: BEXTR proof (bpf_x86_bmi1, 25,214 insns) exceeds 16-bit jump offsets"
        if "rolq" in ops:
            return "kinsn lowering: summed ROL proofs (bpf_x86_rotate) exceed 16-bit jump offsets"
        return "kinsn lowering: proof sequences exceed 16-bit jump offsets"
    if "jumps is too complex" in msg:
        return "verifier jump-history limit (8192) in the counting loop: BLSR bit-scan proof (bpf_x86_bmi1, 321 insns)"
    if "BPF program is too large" in msg:
        return "verifier 1M processed-insn limit: ROL proofs (bpf_x86_rotate) on the branchy paths"
    if "pointer arithmetic with *= operator prohibited" in msg:
        return "MOV SIB-load proof (bpf_x86_mov: index *= 1<<scale) applied to a packet-pointer index"
    if "stack spills exceed" in msg:
        return "userspace bpfopt kinsn rewrite fails; program not reloaded (stays original)"
    if row["arm"] == "kinsn-june":
        return "June proof sequence rejected by the current verifier (pointer type/bounds lost); op not isolated"
    return ""


def write_tables(path: Path, names, by_arm, summary):
    ms = lambda v: f"{v / 1e6:.2f}" if v else "-"
    num = lambda v: f"{int(float(v))}" if v not in (None, "") else "-"
    lines = ["# Per-program kernel-side load cost (generated by analyze.py)", "",
             "Times are in-kernel medians from the kprobe trace (ms). `orig` is the original program loaded",
             "by the `kernel` runtime; `kinsn` is the kinsn-rewritten program loaded by the shim's ReJIT",
             "(BPF_PROG_LOAD) in the `kernel_rejit` runtime; for a failed reload the time of the failed",
             "attempt is shown in the status column. `verified` is prog->aux->verified_insns.", ""]
    for arm, rows in by_arm.items():
        s = summary["arms"][arm]
        lines += [f"## {arm}", "",
                  f"Settings: {s['make_vars']}. Original loads OK: {s['original_program_load_ok']}/62; "
                  f"kinsn program loads OK: {s['kinsn_reload_ok']}/62.", "",
                  "| benchmark | orig load | orig bpf_check | orig verified | kinsn load | kinsn bpf_check "
                  "| kinsn verified | load ratio | sites | kinsn ops | status |",
                  "|---|---:|---:|---:|---:|---:|---:|---:|---:|---|---|"]
        for n in names:
            r = rows[n]
            if r["reload_ok_samples"]:
                status = "ok"
            elif r["reload_errno"]:
                status = (f"**{r['reload_errno']}** after {ms(r['kinsn_attempt_ns'])} ms: "
                          f"`{verifier_message(r['rejit_error_tail'])}` -- {failure_cause(r)}")
            else:
                status = f"not reloaded: {failure_cause(r) or r['kinsn_step_status']}"
            ratio = f"{r['ratio_kinsn_load']:.2f}" if r["ratio_kinsn_load"] else "-"
            lines.append(
                f"| {n} | {ms(r['orig_load_ns'])} | {ms(r['orig_check_ns'])} | {num(r['orig_verified_insns'])} "
                f"| {ms(r['kinsn_load_ns'])} | {ms(r['kinsn_check_ns'])} | {num(r['kinsn_verified_insns'])} "
                f"| {ratio} | {r['kinsn_sites_applied'] if r['kinsn_sites_applied'] is not None else '-'} "
                f"| {r['kinsn_ops'].replace(';', ' ')} | {status} |")
        lines.append("")
    path.write_text("\n".join(lines) + "\n")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--here", type=Path, required=True, help="results directory (relative to clone root)")
    ap.add_argument("arms", nargs="+", help="run directory names under <here>/runs")
    args = ap.parse_args()
    here = args.here
    pop = [b["name"] for b in load_json(PAPER_DATA / POPULATION / "details/result.json")["benchmarks"]]
    names = [l.strip() for l in (here / "paper-62.txt").read_text().splitlines() if l.strip()]
    assert names == pop and len(names) == 62, "population mismatch"
    prog_names = dict(l.split() for l in (here / "prog-names.txt").read_text().splitlines() if l.strip())

    summary = {"population": len(names), "paper_may14": {}, "arms": {}}
    for c in MAY14:
        res = load_json(PAPER_DATA / c / "details/result.json")
        steps = rejit_steps(res, prog_names)
        summary["paper_may14"][c] = {
            "paper_protocol_geomean": {f: paper_ratio(res, names, f) for f in ("compile_ns", "object_load_ns")},
            "kernel_rejit_passes": sorted({",".join(s.get("passes", [])) for b in res["benchmarks"]
                                           for r in b["runs"] if r["runtime"] == "kernel_rejit"
                                           for s in r["samples"]}),
            "programs_with_rejit_status_not_ok": sorted(n for n in names
                                                        if any(s["status"] != "ok" for s in steps[n])),
        }

    all_rows, by_arm = [], {}
    for arm in args.arms:
        a = analyze_arm(here / "runs" / arm, names, prog_names)
        for r in a["rows"]:
            r["arm"] = arm
        all_rows.extend(a["rows"])
        by_arm[arm] = {r["benchmark"]: r for r in a["rows"]}
        summary["arms"][arm] = summarize_arm(a, names)

    # Pairwise comparison over the programs whose kinsn-rewritten form loads in both arms.
    summary["pairs"] = {}
    arms = list(by_arm)
    for i, x in enumerate(arms):
        for y in arms[i + 1:]:
            both = [n for n in names if by_arm[x][n]["reload_ok_samples"] and by_arm[y][n]["reload_ok_samples"]]
            entry = {"programs_loading_in_both": len(both)}
            for arm in (x, y):
                rs = [by_arm[arm][n] for n in both]
                entry[arm] = {
                    "kinsn_load_over_orig_load": gm(r["ratio_kinsn_load"] for r in rs),
                    "kinsn_check_over_orig_check": gm(r["ratio_check"] for r in rs if r["ratio_check"]),
                    "kinsn_verified_insns_over_orig": gm(r["ratio_verified_insns"] for r in rs
                                                         if r["ratio_verified_insns"]),
                }
            entry[f"{y}_kinsn_load_over_{x}_kinsn_load"] = gm(
                by_arm[y][n]["kinsn_load_ns"] / by_arm[x][n]["kinsn_load_ns"] for n in both)
            summary["pairs"][f"{x}__vs__{y}"] = entry

    fields = ["arm"] + [k for k in all_rows[0] if k != "arm"]
    with (here / "per-program.csv").open("w", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=fields)
        w.writeheader()
        w.writerows(all_rows)
    (here / "summary.json").write_text(json.dumps(summary, indent=2) + "\n")
    write_tables(here / "per-program-tables.md", names, by_arm, summary)
    print(json.dumps(summary, indent=2))


if __name__ == "__main__":
    main()
