"""Exercise real XDP context identity through the common native-only service."""
import hashlib
import importlib.util
import json
from pathlib import Path
import shutil
import subprocess
import sys
import tarfile

ROOT = Path(__file__).resolve().parents[3]
HERE = Path(__file__).resolve().parent
CANDIDATE = ROOT / "kprog/arm64/build/trusted-transport/context-candidate"
BUILD = CANDIDATE / "inputs"
OUT = HERE / "trusted-bcc-frame-result/context-candidate"
LINK = ROOT / "kprog/fidelity/build-return-linker/aarch64-unknown-linux-gnu/release/native-link"
sys.path.insert(0, str(ROOT / "kprog"))


def module(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    result = importlib.util.module_from_spec(spec)
    sys.modules[name] = result
    spec.loader.exec_module(result)
    return result


def pins():
    paths = [CANDIDATE / "arm64_sim_local_bpf.h", CANDIDATE / "source-pins.json"]
    paths += sorted((CANDIDATE / "includes").rglob("*.h"))
    return {str(p.relative_to(CANDIDATE)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths}


def adapter(service):
    worker = service.adapter(2)
    render, specialize = worker.gen.render_program, worker.specialize

    def generate(*args, **kwargs):
        return render(*args, **kwargs).replace('#include "../arm64_sim_local_bpf.h"',
            "#include " + json.dumps(str(CANDIDATE / "arm64_sim_local_bpf.h")))

    def build(native, entry, metadata, output, native_link):
        before = pins()
        (Path(output).parent / "context-candidate-inputs.json").write_text(json.dumps(before, indent=2) + "\n")
        result = specialize(native, entry, metadata, output, native_link)
        if before != pins():
            raise RuntimeError("context candidate inputs changed during compilation")
        return result

    worker.gen.render_program, worker.specialize = generate, build
    worker.__file__ = __file__
    return worker


def prepare():
    BUILD.mkdir(exist_ok=False)
    OUT.mkdir(exist_ok=True)
    old = ROOT / "kprog/fidelity/build-context-arm64"
    for name in ["bound-probe", "context_array.bpf.o", "context_hash.bpf.o"]:
        shutil.copy2(old / name, BUILD / name)
    original = ROOT / "kprog/results/kprog_fidelity_20261107/negative/context-projection/arm64/cases.json"
    rows = json.loads(original.read_text())
    for row in rows:
        shutil.copy2(old / (row["name"] + ".native.o"), BUILD / (row["name"] + ".native.o"))
    additions = {
        "valid_context_pointer_read": "ldr x1,[x0]; add x2,x0,#8; ldr x2,[x2]; add x3,x1,#4; cmp x3,x2; b.hi 1f; ldr w4,[x1]; 1: mov w0,#2; ret",
        "context_alias_write": "add x1,x0,#8; str xzr,[x1]; mov w0,#2; ret",
        "context_scalar_alias_write": "eor x1,x0,xzr; str xzr,[x1]; mov w0,#2; ret",
        "context_byte_write": "strb wzr,[x0]; mov w0,#2; ret",
        "context_libc_memset": "stp x29,x30,[sp,#-16]!; mov x2,#8; mov w1,#0; bl memset; ldp x29,x30,[sp],#16; mov w0,#2; ret",
        "context_buffer_helper": "stp x29,x30,[sp,#-16]!; mov w1,#8; bl bpf_get_current_comm; ldp x29,x30,[sp],#16; mov w0,#2; ret",
    }
    for name, assembly in additions.items():
        source, native = BUILD / (name + ".S"), BUILD / (name + ".native.o")
        source.write_text(".text\n.global entry\n.type entry,%function\nentry:\n" +
            assembly.replace("; ", "\n") + '\n.size entry,.-entry\n.section .note.GNU-stack,"",@progbits\n')
        subprocess.run(["aarch64-linux-gnu-gcc", "-c", source, "-o", native], check=True)
        rows.append(dict(name=name, assembly=assembly, negative=not name.startswith("valid_"),
            native_sha256=hashlib.sha256(native.read_bytes()).hexdigest()))
    for row in rows:
        native = BUILD / (row["name"] + ".native.o")
        assert hashlib.sha256(native.read_bytes()).hexdigest() == row["native_sha256"]
        manifest = BUILD / (row["name"] + ".manifest.json")
        manifest.write_text(json.dumps(dict(objects=[dict(program="neg_source", source_btf_symbol="neg_source",
            native_object=str(native), symbol="entry")]), indent=2) + "\n")
        row["manifest"] = str(manifest)
    (BUILD / "cases.json").write_text(json.dumps(rows, indent=2) + "\n")
    with tarfile.open(OUT / "candidate-inputs.tar.gz", "w:gz") as archive:
        archive.add(CANDIDATE, arcname="context-candidate")
    print("prepared", len(rows), "native-only cases; original two native identities unchanged")


def check():
    import trusted_service
    worker = adapter(trusted_service)
    host_link = ROOT / "kprog/fidelity/build-return-linker/release/native-link"
    output = CANDIDATE / "compiler"
    output.mkdir(exist_ok=False)
    reports = []
    for row in json.loads((BUILD / "cases.json").read_text()):
        job = output / row["name"]
        job.mkdir()
        result = worker.specialize((BUILD / (row["name"] + ".native.o")).read_bytes(),
            "entry", dict(version=1, prog_type=6, section="xdp", maps=[]), job / "generated", host_link)
        dump = subprocess.check_output(["llvm-objdump", "-d", result["simulator_object"]], text=True)
        (job / "proof.asm").write_text(dump)
        reports.append(dict(name=row["name"], native_sha256=row["native_sha256"],
            object_sha256=hashlib.sha256(Path(result["simulator_object"]).read_bytes()).hexdigest()))
    (OUT / "compiler-summary.json").write_text(json.dumps(dict(
        scope="compiler only; no verifier/native execution", cases=reports, candidate_pins=pins()), indent=2) + chr(10))
    with tarfile.open(OUT / "compiler-inputs.tar.gz", "w:gz") as archive:
        archive.add(output, arcname="compiler")
    print("compiled", len(reports), "exact native inputs with isolated context candidate", flush=True)


def guest(live):
    suite = module("context_native_safety", ROOT / "kprog/results/kprog_fidelity_20261107/negative/x86-trusted-sp/check.py")
    suite.ARCH, suite.BUILD, suite.OUT = "arm64", BUILD, live
    suite.native_link = lambda: LINK
    rows = json.loads((BUILD / "cases.json").read_text())
    (live / "cases.json").write_text(json.dumps(rows, indent=2) + "\n")
    popen = suite.subprocess.Popen

    def start(command, *args, **kwargs):
        if len(command) > 1 and Path(command[1]) == ROOT / "kprog/trusted_service.py":
            command = [command[0], __file__, "service", *command[2:]]
        return popen(command, *args, **kwargs)

    suite.subprocess.Popen = start
    try:
        suite.check()
    finally:
        path = live / "outcomes.json"
        outcomes = json.loads(path.read_text()) if path.exists() else []
        ok = len(outcomes) == len(rows) and all(r["stage"] in {
            "valid_executed", "verifier_rejected", "specialization_rejected",
            "loader_rejected", "compiler_rejected"} for r in outcomes)
        (live / "guest.json").write_text(json.dumps(dict(ok=ok, cases=len(outcomes),
            expected_cases=len(rows), accepted_unsafe=sum(r["stage"] == "accepted_finding" for r in outcomes)), indent=2) + "\n")


if __name__ == "__main__":
    if sys.argv[1:] == ["prepare"]:
        prepare()
    elif sys.argv[1:] == ["check"]:
        check()
    elif len(sys.argv) > 1 and sys.argv[1] == "service":
        import trusted_service
        worker = adapter(trusted_service)
        def select(arch):
            if arch != 2:
                raise ValueError("context candidate is AArch64 only")
            return worker
        trusted_service.adapter = select
        del sys.argv[1]
        trusted_service.main()
    elif sys.argv[1:] == ["host"]:
        transport = module("context_transport", HERE / "trusted_service_arm64.py")
        transport.HERE, transport.__file__, transport.NATIVE_LINK = OUT, __file__, LINK
        transport.host()
    elif len(sys.argv) in (3, 4) and sys.argv[1] == "guest":
        guest(Path(sys.argv[2]))
    else:
        raise SystemExit("usage: trusted_context_check.py prepare | host | guest LIVE [control] | service [broker args]")
