"""Kill wrong widths/offsets and erased/reordered kernel memory effects.

Every mutation starts from the actual captured kernel byte stream and must
fail the same Lean semantic assertions as the unchanged copy passes.
"""
from pathlib import Path
import shutil
import subprocess

root = Path(__file__).resolve().parent
work = root / "build/context-mutations"
cases = ["unchanged", "pointer_width", "end_offset", "ingress_order", "erased_access"]
for case in cases:
    directory = work / case
    directory.mkdir(parents=True, exist_ok=True)
    capture = directory / "capture"
    shutil.copytree(root / "build/context-access", capture, dirs_exist_ok=True)
    name = "ingress_ifindex" if case in ("ingress_order", "erased_access") else (
        "data_end" if case == "end_offset" else "data")
    path = capture / f"tv_ctx_{name}.xlated.bin"
    data = bytearray(path.read_bytes())
    if case == "pointer_width":
        data[0] = 0x61
    elif case == "end_offset":
        data[2] = 0
    elif case == "ingress_order":
        data[:16] = data[8:16] + data[:8]
    elif case == "erased_access":
        del data[8:16]
    path.write_bytes(data)
    subprocess.run(["python3", "extract_context.py", "--input-dir", str(capture),
                    "--output", str(directory / "KernelContexts.lean")], cwd=root, check=True)
    with (directory / "lean.log").open("w") as log:
        result = subprocess.run(["make", "context-certificate",
            f"CONTEXT_BLOCK_DIR={directory.relative_to(root)}"], cwd=root, stdout=log, stderr=subprocess.STDOUT)
    if (result.returncode == 0) != (case == "unchanged"):
        raise RuntimeError(f"{case}: unexpected Lean result {result.returncode}; see {directory / 'lean.log'}")
    if case != "unchanged" and "ContextChecks.lean:" not in (directory / "lean.log").read_text():
        raise RuntimeError(f"{case}: rejection did not reach the semantic assertions")
    print(f"{case}: {'PASS' if case == 'unchanged' else 'REJECTED by Lean semantics'}")
