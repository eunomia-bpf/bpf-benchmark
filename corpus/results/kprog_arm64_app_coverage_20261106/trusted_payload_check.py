"""Replay the compact-payload candidate through the existing trusted service.

Only the bootstrap worker changes. Applications still submit native bytes to
that service through the kernel, and the corpus Katran runner is unchanged.
The candidate stays private until its real load/execution evidence is known.
"""
import hashlib
import importlib.util
import json
from pathlib import Path
import re
import sys
import tempfile

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
CANDIDATE = ROOT / "kprog/arm64/build/trusted-transport/payload-candidate"
sys.path.insert(0, str(ROOT / "kprog"))


def load_module(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    module = importlib.util.module_from_spec(spec)
    sys.modules[name] = module
    spec.loader.exec_module(module)
    return module


def snapshot_hashes():
    paths = [CANDIDATE / name for name in ("arm64_abi.py", "arm64_sim_local_bpf.h", "source-pins.json")]
    paths += sorted((CANDIDATE / "includes").rglob("*.h"))
    hashes = {str(p.relative_to(CANDIDATE)): hashlib.sha256(p.read_bytes()).hexdigest() for p in paths}
    hashes["bootstrap_source"] = hashlib.sha256(Path(__file__).read_bytes()).hexdigest()
    return hashes


def adapter(service):
    worker = service.adapter(2)
    analysis = load_module("compact_payload_abi", CANDIDATE / "arm64_abi.py")
    state = {}
    render = worker.gen.render_program
    specialize = worker.specialize

    def check(*args):
        bounds = analysis.check_definedness(*args)
        state["bounds"] = bounds
        return bounds[:2]

    def generate(*args, **kwargs):
        state.clear()
        text = render(*args, **kwargs)
        _, _, offsets = state["bounds"]
        bias = re.search(r"^#define ARM64_SIM_STACK_BIAS (-?\d+)LL$", text, re.M)
        if bias and offsets is not None:
            indexes = [(off + int(bias[1])) // 8 for off in offsets]
            rank = " + ".join("((__u64)(INDEX) > " + str(i) + "ULL)" for i in indexes) or "0ULL"
            text = "\n".join([
                "#define ARM64_SIM_STACK_PAYLOAD_WORDS " + str(max(1, len(indexes))) + "U",
                "#define ARM64_SIM_L_STACK_PAYLOAD_LOAD(INDEX) (__a64_stack_payload[(" + rank + ")])",
                "#define ARM64_SIM_L_STACK_PAYLOAD_STORE(INDEX, VALUE) do { __a64_stack_payload[(" + rank + ")] = (VALUE); } while (0)",
            ]) + "\n" + text
        return text.replace('#include "../arm64_sim_local_bpf.h"',
                            "#include " + json.dumps(str(CANDIDATE / "arm64_sim_local_bpf.h")))

    def build(native, entry, metadata, output_dir, native_link):
        output_dir = Path(output_dir)
        pins = snapshot_hashes()
        (output_dir.parent / "candidate-inputs.json").write_text(json.dumps(pins, indent=2) + "\n")
        result = specialize(native, entry, metadata, output_dir, native_link)
        (output_dir / "candidate-layout.json").write_text(json.dumps(dict(
            stack_min=state["bounds"][0], stack_max=state["bounds"][1],
            ghost_offsets=state["bounds"][2], hashes_unchanged=pins == snapshot_hashes()), indent=2) + "\n")
        return result

    worker.gen.check_definedness = check
    worker.gen.render_program = generate
    worker.specialize = build
    worker.__file__ = __file__
    return worker


def transport():
    module = load_module("compact_payload_transport", HERE / "trusted_service_arm64.py")
    module.__file__ = __file__
    module.HERE = HERE / "trusted-bcc-frame-result"
    return module


def main():
    if len(sys.argv) > 1 and sys.argv[1] == "service":
        import trusted_service
        worker = adapter(trusted_service)
        def select(arch):
            if arch != 2:
                raise ValueError("candidate is AArch64 only")
            return worker
        trusted_service.adapter = select
        del sys.argv[1]
        trusted_service.main()
    elif sys.argv[1:] == ["check"]:
        import trusted_service
        worker = adapter(trusted_service)
        with tempfile.TemporaryDirectory(prefix="control-", dir=CANDIDATE) as temporary:
            output = Path(temporary) / "generated"
            artifacts = worker.specialize((ROOT / "kprog/libnativeloader/build-arm64-a-map-order-v3/trusted-native.o").read_bytes(),
                "trusted_entry", dict(version=1, prog_type=6, section="xdp", maps=[]), output,
                ROOT / "kprog/arm64/build/app-native-link/release/native-link")
            layout = json.loads((output / "candidate-layout.json").read_text())
            if not layout["hashes_unchanged"]:
                raise RuntimeError("candidate source changed during control compilation")
            print(json.dumps(dict(compiled=True, layout=layout, native_sha256=artifacts["native_sha256"],
                                  object_sha256=hashlib.sha256(Path(artifacts["simulator_object"]).read_bytes()).hexdigest())))
    elif sys.argv[1:] == ["host"]:
        transport().host("katran")
    elif len(sys.argv) == 4 and sys.argv[1] == "guest" and sys.argv[3] == "katran":
        module = transport()
        popen = module.subprocess.Popen

        def start(command, *args, **kwargs):
            if len(command) > 1 and Path(command[1]) == ROOT / "kprog/trusted_service.py":
                command = [command[0], __file__, "service", *command[2:]]
            return popen(command, *args, **kwargs)

        module.subprocess.Popen = start
        module.guest(sys.argv[2], "katran")
    else:
        raise SystemExit("usage: trusted_payload_check.py check | host | guest LIVE katran | service [broker arguments]")


if __name__ == "__main__":
    main()
