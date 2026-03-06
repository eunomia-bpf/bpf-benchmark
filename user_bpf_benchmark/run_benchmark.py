from pathlib import Path
from typing import Optional, TypedDict
import subprocess
import os
import multiprocessing
import matplotlib.pyplot as plt
import shutil
import json

PROGS_DIR = Path("./bpf_progs")
EXECUTABLES = [
    "./ubpf-jit",
    "./llvm-jit",
    "./rbpf-jit",
    "./rbpf-jit-vm",
    "./ubpf-jit-vm",
    "<NATIVE>",
    "<WASM>",
]


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


def run_single(
    runtime: str, bpf_prog: str, memory: Optional[str], name: str
) -> RunResult:
    if runtime == "<NATIVE>":
        command_line = [bpf_prog.replace(".bpf.bin", ".native")]
        if memory:
            command_line.append(memory)
    elif runtime == "<WASM>":
        command_line = ["./wasm-wasmtime-runtime", bpf_prog.replace(".bpf.bin", ".wasm")]
        if memory:
            command_line.append(memory)
    else:
        command_line = [runtime, bpf_prog] + ([memory] if memory else [])
    ret = subprocess.run(command_line, text=True, capture_output=True, check=True)
    jit, exec, ret = (int(x) for x in ret.stdout.strip().split(" "))
    return {"exec_usage": exec, "jit_usage": jit, "result": ret, "name": name}


def run_multiple_wrapper(cfg: RunArgs):
    ret = {
        "exec_usage": 0,
        "jit_usage": 0,
        "result": [],
        "name": cfg["name"],
        "metrics": {
            "distribution": {},
            "avg": 0,
            "median": 0,
            "max": None,
            "min": None,
        },
    }

    for _ in range(10):
        r = run_single(**cfg)
        ret["exec_usage"] += r["exec_usage"]
        ret["jit_usage"] += r["jit_usage"]
        ret["result"].append(r["result"])

        # Update distribution
        ret["metrics"]["distribution"][r["result"]] = (
            ret["metrics"]["distribution"].get(r["result"], 0) + 1
        )

        # Update max and min
        if ret["metrics"]["max"] is None or r["result"] > ret["metrics"]["max"]:
            ret["metrics"]["max"] = r["result"]
        if ret["metrics"]["min"] is None or r["result"] < ret["metrics"]["min"]:
            ret["metrics"]["min"] = r["result"]

    ret["exec_usage"] /= 50
    ret["jit_usage"] /= 50

    # Calculate average and median
    ret["metrics"]["avg"] = sum(ret["result"]) / len(ret["result"])
    sorted_results = sorted(ret["result"])
    mid_idx = len(sorted_results) // 2
    if len(sorted_results) % 2 == 0:
        ret["metrics"]["median"] = (
            sorted_results[mid_idx - 1] + sorted_results[mid_idx]
        ) / 2
    else:
        ret["metrics"]["median"] = sorted_results[mid_idx]

    return ret


def main():
    all_tests = []
    for bpf_prog in os.listdir(PROGS_DIR):
        if bpf_prog.endswith(".bpf.bin"):
            name = bpf_prog.replace(".bpf.bin", "")
            memory_file = str(PROGS_DIR / (name + ".mem"))
            all_tests.append(
                {
                    "name": name,
                    "bpf_prog": str(PROGS_DIR / bpf_prog),
                    "memory": memory_file if os.path.exists(memory_file) else None,
                }
            )
    print("TESTS")
    print("--------------")
    for item in all_tests:
        print(item["name"])
    print("--------------")
    print(f"Loaded {len(all_tests)} tests")
    test_results = []
    for runtime in EXECUTABLES:
        print(f"Testing {runtime}")
        with multiprocessing.Pool() as pool:
            results = pool.map(
                run_multiple_wrapper, ({**x, "runtime": runtime} for x in all_tests)
            )
        test_results.append(results)
        for item in results:
            print(
                f"TEST <{item['name']}> JIT {item['jit_usage']/10**6}ms EXEC {item['exec_usage']/10**6}ms RET {item['result']}"
            )
        print("-----------------")
    images_out = Path("example-output")
    with open(images_out / "data.json", "w") as f:
        json.dump({"executables": EXECUTABLES, "results": test_results}, f)
    for test_line in zip(*test_results):
        jit_values = [x["jit_usage"] for x in test_line]
        exec_values = [x["exec_usage"] for x in test_line]
        name = test_line[0]["name"]

        plt.figure()
        plt.bar(EXECUTABLES, jit_values, 0.35, label="Compilation", color="orange")
        plt.ylabel("Time (nanoseconds)")
        plt.xticks(rotation=45)
        plt.title(f'Time usage on compiling "{name}"')
        plt.legend()
        plt.savefig(images_out / f"{name}.compilation.png")
        plt.close()

        plt.figure()
        plt.bar(EXECUTABLES, exec_values, 0.35, label="Execution", color="orange")
        plt.ylabel("Time (nanoseconds)")
        plt.title(f'Time usage on executing "{name}"')
        plt.legend()
        plt.savefig(images_out / f"{name}.execution.png")
        plt.close()

        plt.figure()
        plt.bar(EXECUTABLES, jit_values, 0.35, label="Compilation", color="blue")
        plt.bar(
            EXECUTABLES,
            exec_values,
            0.35,
            bottom=jit_values,
            label="Execution",
            color="orange",
        )
        plt.xticks(rotation=45)
        plt.ylabel("Time (nanoseconds)")
        plt.title(f'Time usage on example "{name}"')
        plt.legend()
        plt.savefig(images_out / f"{name}.png")
        plt.close()
    print("Visualized images and data json are in output")


if __name__ == "__main__":
    main()
