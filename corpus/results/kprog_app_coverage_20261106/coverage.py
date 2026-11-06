"""Reproduce this coverage experiment; each case retains its complete log."""
import concurrent.futures
import json
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[3]


def compile_one(row, directory):
    source = Path(row["source"])
    build = directory / "objects"
    build.mkdir(exist_ok=True)
    command = ["clang", "-O2", "-target", "bpf", "-mllvm", "-bpf-stack-size=4096",
               "-D__TARGET_ARCH_x86", "-I", str(ROOT / "vendor/libbpf/include/uapi"),
               "-I", str(ROOT / "vendor/libbpf/src"), "-I", "/usr/include/x86_64-linux-gnu",
               "-I", str(ROOT / "kprog/x86/micro-prog"), "-c", str(source),
               "-o", str(build / (row["name"] + ".bpf.o"))]
    return execute(row, directory, "compile", command, 120)


def execute(row, directory, stage, command, timeout):
    log = directory / stage / (row["name"] + ".json")
    if log.exists():
        return json.loads(log.read_text())
    try:
        result = subprocess.run(command, cwd=ROOT, text=True, capture_output=True,
                                timeout=timeout, check=False)
        code, stdout, stderr = result.returncode, result.stdout, result.stderr
    except subprocess.TimeoutExpired as error:
        code = 124
        stdout, stderr = error.stdout or b"", error.stderr or b""
        if isinstance(stdout, bytes):
            stdout = stdout.decode(errors="replace")
        if isinstance(stderr, bytes):
            stderr = stderr.decode(errors="replace")
        stderr += f"\n{stage} timeout after {timeout}s\n"
    record = {"name": row["name"], "proof": row["proof"], "source": row["source"],
              "command": command, "returncode": code, "stdout": stdout, "stderr": stderr}
    temporary = log.with_suffix(".tmp")
    temporary.write_text(json.dumps(record) + "\n")
    temporary.replace(log)
    return record


def verify_one(row, directory):
    command = [str(ROOT / "kprog/loader/target/debug/reversesim-loader"),
               "--object", str(directory / "objects" / (row["name"] + ".bpf.o")),
               "--program", row["name"] + "_x86_sim_xdp", "--load-only",
               "--verifier-log", str(directory / "verify" / (row["name"] + ".verifier.log"))]
    return execute(row, directory, "verify", command, 60)


def main():
    stage, path = sys.argv[1:]
    directory = Path(path).resolve()
    (directory / stage).mkdir(exist_ok=True)
    rows = [json.loads(line) for line in (directory / "programs.jsonl").read_text().splitlines()]
    rows = [row for row in rows if row["stage"] == "generate" and row["ok"]]
    if stage == "compile":
        worker, jobs = compile_one, 6
    elif stage == "verify":
        worker, jobs = verify_one, 2
        completed = {p.stem: json.loads(p.read_text())
                     for p in (directory / "compile").glob("*.json")}
        print(f"compile pending: {len(rows) - len(completed)}", flush=True)
        rows = [row for row in rows if row["name"] in completed
                and completed[row["name"]]["returncode"] == 0]
    else:
        raise ValueError(stage)
    failures = 0
    with concurrent.futures.ThreadPoolExecutor(max_workers=jobs) as pool:
        futures = [pool.submit(worker, row, directory) for row in rows]
        for count, future in enumerate(concurrent.futures.as_completed(futures), 1):
            record = future.result()
            failures += record["returncode"] != 0
            print(f"{stage} {count}/{len(rows)} {record['name']}: {record['returncode']}", flush=True)
    print(f"{stage}: {failures}/{len(rows)} failures", flush=True)
    return int(failures != 0)


if __name__ == "__main__":
    raise SystemExit(main())
