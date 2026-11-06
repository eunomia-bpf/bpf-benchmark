"""Catch chunk fuel exhaustion changing an ordinary native loop's return."""
import importlib.util
import json
from pathlib import Path
import subprocess
import sys
import tempfile

ROOT = Path(__file__).resolve().parents[3]
HERE = Path(__file__).resolve().parent
BUILD = HERE / "dispatch-build"
BUILD.mkdir(exist_ok=True)
sys.path.insert(0, str(ROOT / "kprog/x86/micro-prog"))


def load(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    module = importlib.util.module_from_spec(spec)
    sys.modules[name] = module
    spec.loader.exec_module(module)
    return module


old = load("bounded_generator", HERE / "baseline/simulator/generator.py")
current = load("current_generator", Path(sys.argv[1]) if len(sys.argv) > 1 else
               ROOT / "kprog/x86/micro-prog/generate_micro_sim_proofs.py")
current.REPO_ROOT = ROOT
# Lower only the chunk selection/size, so the real bounded dispatcher can be
# tested with seven instructions rather than thousands of macro expansions.
old.CHUNKED_PROOF_INSN_THRESHOLD = 4
old.CHUNKED_PROOF_CHUNK_INSNS = 3
assembly = [("mov", ("eax", "1")), ("mov", ("ecx", "10000")),
            ("add", ("eax", "1")), ("mov", ("edx", "0")),
            ("dec", ("ecx",)), ("jne", ("2",)), ("ret", ())]
for name, module in (("old", old), ("current", current)):
    insns = [module.NativeInsn(i, op + " " + ",".join(args), op, args)
             for i, (op, args) in enumerate(assembly)]
    source = module.render_program("dispatch_" + name, insns, exit_addr=7)
    source = source.replace('#include "../x86_sim_local_bpf.h"',
                            f'#include "{ROOT}/kprog/x86/x86_sim_local_bpf.h"')
    (BUILD / (name + ".c")).write_text(source)
large = [current.NativeInsn(i, "nop", "nop", ()) for i in range(2048)]
large.append(current.NativeInsn(2048, "ret", "ret", ()))
source = current.render_program("large_dispatch", large, exit_addr=2049)
assert source.count("/* 0x") == 2049
assert "__x86_iter" not in source and "_x86_chunk_" not in source
assert source.count("X86_SIM_RUN_OP(X86_OP_NOP,") == 2048
old.CHUNKED_PROOF_INSN_THRESHOLD = 2048
old.CHUNKED_PROOF_CHUNK_INSNS = 384
for operand in ("rax", "eax", "QWORD PTR [rax]"):
    jump = current.NativeInsn(0, "jmp " + operand, "jmp", (operand,))
    for operation in (lambda: current.encode(jump, {}),
                      lambda: current.render_program("indirect_jump", [jump], exit_addr=1)):
        try:
            operation()
        except ValueError as error:
            assert "indirect" in str(error)
        else:
            raise AssertionError(f"indirect jump silently accepted: {operand}")
assert current.encode(current.NativeInsn(0, "jmp 0", "jmp", ("0",)), {}).imm == "0ULL"
print("unknown indirect jumps rejected; direct jump to zero preserved", flush=True)
smoke = load("app_smoke", ROOT / "kprog/x86/run_app_sim_smoke.py")
smoke.REPORT_DIR = Path(tempfile.mkdtemp(prefix="timeout-", dir=BUILD))
try:
    smoke.run([sys.executable, "-u", "-c",
               "import sys,time; print('stdout marker'); print('stderr marker', file=sys.stderr); time.sleep(10)"],
              timeout_s=2)
except subprocess.TimeoutExpired:
    record = json.loads((smoke.REPORT_DIR / "commands.jsonl").read_text())
    assert record["returncode"] == 124 and record["timeout_s"] == 2
    assert record["stdout"] == "stdout marker\n" and record["stderr"] == "stderr marker\n"
else:
    raise AssertionError("timed-out subprocess did not propagate failure")
print("timeout retained complete stdout/stderr and propagated failure", flush=True)
(BUILD / "native.S").write_text(""".text
.globl dispatch_native
dispatch_native:
    movl $1, %eax
    movl $10000, %ecx
1:  addl $1, %eax
    movl $0, %edx
    decl %ecx
    jne 1b
    ret
.section .note.GNU-stack,"",@progbits
""")
(BUILD / "main.c").write_text("""#include <linux/bpf.h>
#include <stdio.h>
int dispatch_old_x86_sim_xdp(struct xdp_md *);
int dispatch_current_x86_sim_xdp(struct xdp_md *);
int dispatch_native(void);
int main(void) {
    struct xdp_md ctx = {0};
    int old = dispatch_old_x86_sim_xdp(&ctx);
    int current = dispatch_current_x86_sim_xdp(&ctx);
    int native = dispatch_native();
    printf("old=%d current=%d native=%d\\n", old, current, native);
    return old == native || current != native || native != 10001;
}
""")
