#!/usr/bin/env python3
"""Where each arm's CPU time goes, inside one run, per BPF program.

Order item 1 (lane C, 2026-11-13): the workload ratio says Tracee's two arms cost about
the same; it does not say where either arm spends the time.  This profiles both arms of
ONE run (baseline = eBPF/JIT, post_rejit = native, installed only after the baseline
phase), so the two profiles share the guest, the workload and the machine.

`perf record -a -g -e cpu-clock` runs in the guest, bracketed by the driver's own
`measurement_start`/`measurement_done` progress lines, so each sample belongs to a known
phase.  Callchains are recorded so a sample can be attributed to the code that called it
(an out-of-line helper entry such as memset is reached from a caller, and the caller
is what the arm's change is about).  With kptr_restrict=0 and bpf_jit_kallsyms=1 every
JIT'd program appears in
/proc/kallsyms as `bpf_prog_<tag>_<name>`, and perf records the guest kallsyms into the
data file, so the report symbolizes afterwards.  A sample's symbol is the code that was
running on the CPU: for these programs, samples under `bpf_prog_*` are BPF time.

The report has two levels:
  * per program: samples per arm (samples are CPU-time, so they compare the two arms'
    share of the guest directly), with each arm's own run counts from the corpus result;
  * per instruction, inside one program: `perf annotate` output for the named symbol,
    which is what shows a native body spending time where the JIT body does not.

Usage:
  phase-profile.py run --app tracee/monitor --seconds 60 [--cpus 20-23] [--freq 999]
  phase-profile.py report <output dir>
"""

from __future__ import annotations

import argparse
import collections
import json
import os
import pathlib
import re
import shutil
import subprocess
import sys
import symbolize

ROOT = pathlib.Path("/workspaces/repository")
HERE = ROOT / "kprog/perf/profile"
MAKEFILE = ROOT / "kprog/perf/one-image/Makefile"
KERNEL = pathlib.Path("/workspaces/.agent-state/kprog-ck/build-x86/arch/x86/boot/bzImage")
IMAGE_TAR = ROOT / ".cache/container-images/x86_64-runner-runtime.image.tar"
KINSN = pathlib.Path("/workspaces/repository/kinsn/module/x86/build/bpf_x86_native_lab.ko")
PERF = pathlib.Path("/var/tmp/kprog-tmp/C/perf-build/perf")
RAW_ROOT = pathlib.Path("/workspaces/kprog-raw/C")
PHASES = ("baseline", "post_rejit")

GUEST = r"""#!/bin/sh
# Guest half of phase-profile.py: one corpus run, one perf record window per phase.
# perf writes into /dev/shm because the 9p mount fails perf's mmap of the data file
# ("failed to mmap file" at /var/tmp); the file is copied to the shared mount after
# recording ends.
set -u
O=$1 APP=$2 SECS=$3 FREQ=$4 MANIFEST=$5 EVENT=$6
cd /workspaces/repository || exit 2
if [ "$EVENT" != cpu-clock ]; then
  /var/tmp/perf stat -e "$EVENT" -- true > "$O/profile-event-preflight.log" 2>&1 || exit 2
fi
echo 0 > /proc/sys/kernel/kptr_restrict
echo 1 > /proc/sys/net/core/bpf_jit_kallsyms
echo "phase-profile: kptr_restrict=$(cat /proc/sys/kernel/kptr_restrict) \
bpf_jit_kallsyms=$(cat /proc/sys/net/core/bpf_jit_kallsyms)" >> "$O/phase-profile.log"

make -f kprog/perf/one-image/Makefile guest APPS="$APP" SAMPLES=1 WORKLOAD_DURATION="$SECS" \
  BPFREJIT_CORPUS_BPF_STATS=1 BPFREJIT_SHIM_NATIVE_LOADER=post \
  NATIVE_MANIFEST="$MANIFEST" BENCH_PASSES= SKIP_REJIT_MODE=norejit > "$O/guest.log" 2>&1 &
G=$!
for _ in $(seq 1 150); do
  grep -q '"event": "app_start"' "$O/guest.log" 2>/dev/null && break
  sleep 2
done
for ph in baseline post_rejit; do
  for _ in $(seq 1 240); do
    grep -q "\"event\": \"measurement_start\", \"phase\": \"$ph\"" "$O/guest.log" 2>/dev/null && break
    sleep 2
  done
  echo "phase-profile: perf start $ph $(date -u +%FT%TZ)" >> "$O/phase-profile.log"
  /var/tmp/perf record -a -g -e "$EVENT" -F "$FREQ" -o "/dev/shm/$ph.data" \
    >> "$O/phase-profile.log" 2>&1 &
  P=$!
  for _ in $(seq 1 300); do
    grep -q "\"event\": \"measurement_done\", \"phase\": \"$ph\"" "$O/guest.log" 2>/dev/null && break
    sleep 2
  done
  # Snapshot the guest's own symbol table while this phase's programs are still
  # loaded.  The host's kallsyms belongs to another kernel, and perf report
  # resolves guest addresses against whatever it is given, so without this file
  # every sample is named after an unrelated host symbol.
  cat /proc/kallsyms > "$O/$ph.kallsyms"
  kill -INT "$P" 2>/dev/null
  wait "$P" 2>/dev/null
  echo "phase-profile: perf stop $ph $(date -u +%FT%TZ) kallsyms=$ph.kallsyms" \
    >> "$O/phase-profile.log"
  cp "/dev/shm/$ph.data" "$O/$ph.data"
  rm -f "/dev/shm/$ph.data"
done
wait "$G"
echo "phase-profile: guest done rc=$? $(date -u +%FT%TZ)" >> "$O/phase-profile.log"
"""


def _stamp() -> str:
    return subprocess.check_output(["date", "-u", "+%Y%m%dT%H%M%SZ"], text=True).strip()


def run(args: argparse.Namespace) -> int:
    if not KERNEL.is_file():
        raise SystemExit(f"missing kernel image: {KERNEL}")
    if not PERF.is_file():
        raise SystemExit(f"missing perf: {PERF}")
    stamp = _stamp()
    name = args.label or args.app.replace("/", "_")
    out = pathlib.Path(args.out) if args.out else RAW_ROOT / f"{stamp}-phase-profile-{name}"
    state = pathlib.Path(args.state_root) / stamp
    var_tmp = state / "var-tmp"
    if out.exists():
        raise SystemExit(f"output directory exists: {out}")
    out.mkdir(parents=True)
    var_tmp.mkdir(parents=True)
    shutil.copy2(PERF, var_tmp / "perf")
    shutil.copy2(KINSN, var_tmp / "bpf_x86_native_lab.ko")
    shutil.copy2(IMAGE_TAR, var_tmp / "runtime.image.tar")
    guest = var_tmp / "phase-profile-guest.sh"
    manifest = args.manifest or (
        f"/opt/bpf-benchmark/native-bpf/x86_64/{args.app.split('/')[0]}/manifest.json")
    guest.write_text(GUEST, encoding="utf-8")
    guest.chmod(0o755)
    command = [
        "taskset", "-c", args.cpus, "vng", "--run", str(KERNEL),
        "--cwd", str(ROOT), "--rwdir", str(ROOT), "--rwdir", f"/var/tmp={var_tmp}",
        "--overlay-rwdir", "/tmp", "--overlay-rwdir", "/run", "--overlay-rwdir", "/usr/local",
        "--disable-monitor", "--cpus", str(args.vcpus), "--memory", args.memory,
        "--append", "loglevel=4 panic=30 oops=panic",
        "--exec", f"/var/tmp/phase-profile-guest.sh /var/tmp/out {args.app} {args.seconds} "
                  f"{args.freq} {manifest} {args.event}",
    ]
    if args.persist_output:
        command[command.index("--exec"):command.index("--exec")] = ["--rwdir", str(out)]
        (var_tmp / "out").symlink_to(out, target_is_directory=True)
    else:
        (var_tmp / "out").mkdir(exist_ok=True)
    (out / "command.json").write_text(
        json.dumps({"command": command, "app": args.app, "seconds": args.seconds,
                    "freq": args.freq, "event": args.event,
                    "cpus": args.cpus, "vcpus": args.vcpus},
                   indent=2, sort_keys=True) + "\n", encoding="utf-8")
    log = (out / "host.log").open("w", encoding="utf-8")
    completed = subprocess.run(command, stdout=log, stderr=subprocess.STDOUT)
    log.close()
    for name_ in ("guest.log", "phase-profile.log", "baseline.data", "post_rejit.data",
                  "baseline.kallsyms", "post_rejit.kallsyms"):
        source = var_tmp / "out" / name_
        if not source.is_file():
            print(f"missing guest artifact: {source}", file=sys.stderr)
            continue
        if not args.persist_output:
            shutil.copy2(source, out / name_)
    shutil.rmtree(state)
    print(f"run directory: {out}")
    if completed.returncode != 0:
        return completed.returncode
    return report(out, annotate=args.annotate, limit=args.limit)


def _kallsyms_args(out: pathlib.Path, phase: str) -> list[str]:
    """The guest's own symbol table for one phase, when the run captured one."""
    path = out / f"{phase}.kallsyms"
    return ["--kallsyms", str(path)] if path.is_file() else []


def _perf_report(out: pathlib.Path, phase: str, *extra: str) -> str:
    done = subprocess.run(
        [str(PERF), "report", "-i", str(out / f"{phase}.data"), *_kallsyms_args(out, phase),
         *extra],
        capture_output=True, text=True)
    if done.returncode != 0:
        raise SystemExit(f"perf report failed for {phase}: {done.stderr.strip()}")
    return done.stdout


def _symbols(out: pathlib.Path, phase: str) -> collections.Counter:
    """Root samples only, resolved with this phase's guest JIT symbols."""
    ips = symbolize.samples(out / f"{phase}.data", perf=PERF)
    if not ips:
        raise SystemExit(f"no root samples for {phase}")
    counts = symbolize.resolve(ips, *symbolize.load_kallsyms(out / f"{phase}.kallsyms"))
    return collections.Counter({name: count * 100 / len(ips) for name, count in counts.items()})


def _program_name(symbol: str) -> str | None:
    """`bpf_prog_<tag>_<name>` -> `<name>`; None for anything else."""
    match = re.match(r"bpf_prog_[0-9a-f]+_(.+)$", symbol)
    return match.group(1) if match else None


def report(out: pathlib.Path, *, annotate: int = 3, limit: int = 25) -> int:
    profiles = {}
    for phase in PHASES:
        data = out / f"{phase}.data"
        if not data.is_file():
            raise SystemExit(f"missing {data}")
        if not (out / f"{phase}.kallsyms").is_file():
            raise SystemExit(f"missing {out / f'{phase}.kallsyms'}: run the guest half first")
        profiles[phase] = _symbols(out, phase)
        (out / f"{phase}.report.txt").write_text(
            _perf_report(out, phase, "--stdio", "--sort", "symbol",
                         "--percent-limit", "0.2", "--no-children"),
            encoding="utf-8")

    programs = {}
    for phase in PHASES:
        programs[phase] = collections.Counter()
        for symbol, percent in profiles[phase].items():
            name = _program_name(symbol)
            if name is not None:
                programs[phase][name] += percent

    lines = []
    lines.append(f"phase profile: {out}")
    for phase in PHASES:
        bpftotal = sum(programs[phase].values())
        idle = profiles[phase].get("pv_native_safe_halt", 0.0)
        lines.append(f"{phase:11} bpf {bpftotal:6.2f}% of samples, "
                     f"idle(pv_native_safe_halt) {idle:6.2f}%")
    lines.append("")
    lines.append(f"{'program':44} {'eBPF %':>8} {'native %':>9} {'native/eBPF':>12}")
    names = set(programs["baseline"]) | set(programs["post_rejit"])
    ranked = sorted(names, key=lambda n: -(programs["baseline"][n]
                                           + programs["post_rejit"][n]))[:limit]
    for name in ranked:
        base = programs["baseline"].get(name, 0.0)
        native = programs["post_rejit"].get(name, 0.0)
        ratio = f"{native / base:.3f}" if base else "-"
        lines.append(f"{name[:44]:44} {base:>8.2f} {native:>9.2f} {ratio:>12}")
    lines.append("")
    lines.append("'%' is this phase's share of all guest CPU-time samples; a program loaded")
    lines.append("twice appears under two tags and is summed by name.")
    text = "\n".join(lines) + "\n"
    (out / "summary.txt").write_text(text, encoding="utf-8")
    print(text)

    for phase in PHASES:
        for name in ranked[:annotate]:
            for symbol in (s for s in profiles[phase] if _program_name(s) == name):
                done = subprocess.run(
                    [str(PERF), "annotate", "-i", str(out / f"{phase}.data"),
                     *_kallsyms_args(out, phase), "-s", symbol, "--stdio", "-q"],
                    capture_output=True, text=True)
                if done.returncode != 0:
                    raise SystemExit(f"perf annotate failed for {symbol}: {done.stderr.strip()}")
                (out / f"annotate-{phase}-{symbol}.txt").write_text(
                    done.stdout, encoding="utf-8")
    return 0


def main(argv: list[str]) -> int:
    global PERF
    parser = argparse.ArgumentParser(description=__doc__)
    sub = parser.add_subparsers(dest="command", required=True)
    run_parser = sub.add_parser("run")
    run_parser.add_argument("--app", required=True, help="e.g. tracee/monitor")
    run_parser.add_argument("--seconds", type=int, default=60)
    run_parser.add_argument("--cpus", default="20-23")
    run_parser.add_argument("--vcpus", default="4")
    run_parser.add_argument("--memory", default="32G")
    run_parser.add_argument("--freq", default="999")
    run_parser.add_argument("--event", default="cpu-clock",
                            help="perf event; cycles:k can sample interrupt-context BPF work")
    run_parser.add_argument("--limit", type=int, default=25)
    run_parser.add_argument("--annotate", type=int, default=3)
    run_parser.add_argument("--out", default="")
    run_parser.add_argument("--label", default="")
    run_parser.add_argument("--manifest", default="",
                            help="native manifest to load instead of the image's own")
    run_parser.add_argument("--state-root", default="/var/tmp/kprog-tmp/C/phase-profile")
    run_parser.add_argument("--perf", default=str(PERF))
    run_parser.add_argument("--persist-output", action="store_true",
                            help="write guest artifacts directly to the persistent output directory")
    report_parser = sub.add_parser("report")
    report_parser.add_argument("directory")
    report_parser.add_argument("--annotate", type=int, default=3)
    report_parser.add_argument("--limit", type=int, default=25)
    report_parser.add_argument("--perf", default=str(PERF))
    args = parser.parse_args(argv)
    PERF = pathlib.Path(args.perf)
    if args.command == "run":
        return run(args)
    return report(pathlib.Path(args.directory), annotate=args.annotate, limit=args.limit)


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
