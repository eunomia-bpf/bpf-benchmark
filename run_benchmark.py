from pathlib import Path
from typing import Optional, TypedDict
import subprocess
import os
import multiprocessing
PROGS_DIR = Path("./bpf_progs")
EXECUTABLES = ["./bpftime-ubpf", "./bpftime-llvm", "<NATIVE>"]


class RunResult(TypedDict):
    jit_usage: int
    exec_usage: int
    result: int
    name: str


class RunArgs(TypedDict):
    runtime: str
    bpf_prog: str
    memory: Optional[str]
    name: str


def run_single(runtime: str, bpf_prog: str, memory: Optional[str], name: str) -> RunResult:
    if runtime == "<NATIVE>":
        command_line = [bpf_prog.replace(".bpf.bin", ".native")]
        if memory:
            command_line.append(memory)
    else:
        command_line = [runtime, bpf_prog] + ([memory]
                                              if memory else [])
    ret = subprocess.run(command_line, text=True,
                         capture_output=True, check=True)
    jit, exec, ret = (int(x) for x in ret.stdout.strip().split(" "))
    return {
        "exec_usage": exec,
        "jit_usage": jit,
        "result": ret,
        "name": name
    }


def run_multiple_wrapper(cfg: RunArgs):
    ret = {
        "exec_usage": 0,
        "jit_usage": 0,
        "result": [],
        "name": cfg["name"]
    }
    for _ in range(5):
        r = run_single(**cfg)
        ret["exec_usage"] += r["exec_usage"]
        ret["jit_usage"] += r["jit_usage"]
        ret["result"].append(r["result"])
    ret["exec_usage"] /= 5
    ret["jit_usage"] /= 5
    return ret


def main():
    all_tests = [

    ]
    for bpf_prog in os.listdir(PROGS_DIR):
        if bpf_prog.endswith(".bpf.bin"):
            name = bpf_prog.replace(".bpf.bin", "")
            memory_file = str(PROGS_DIR/(name+".mem"))
            all_tests.append({
                "name": name,
                "bpf_prog": str(PROGS_DIR/bpf_prog),
                "memory": memory_file if os.path.exists(memory_file) else None
            })
    print("TESTS")
    print("--------------")
    for item in all_tests:
        print(item["name"])
    print("--------------")
    print(f"Loaded {len(all_tests)} tests")
    for runtime in EXECUTABLES:
        print(f"Testing {runtime}")
        with multiprocessing.Pool() as pool:
            results = pool.map(
                run_multiple_wrapper, ({**x, "runtime": runtime} for x in all_tests))
        for item in results:
            print(
                f"TEST <{item['name']}> JIT {item['jit_usage']/10**6}ms EXEC {item['exec_usage']/10**6}ms RET {item['result']}")


if __name__ == "__main__":
    main()
