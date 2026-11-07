"""Collect immutable instruction replay evidence for the central formal table."""
from collections import defaultdict
import csv
import hashlib
import gzip
import importlib.util
from dataclasses import asdict
import sys
import io
import json
from pathlib import Path
import re
import subprocess
import tarfile

ROOT = Path(__file__).resolve().parents[5]
OUT = Path(__file__).resolve().parent
BASE = ROOT / "kprog/results/kprog_fidelity_20261107/differential"
INPUTS = {}
HEAD = subprocess.check_output(["git", "rev-parse", "HEAD"], cwd=ROOT, text=True).strip()


def sha(data):
    return hashlib.sha256(data).hexdigest()


def read(path):
    path = path.resolve()
    relative = str(path.relative_to(ROOT))
    raw = path.read_bytes()
    published = subprocess.check_output(["git", "show", HEAD + ":" + relative], cwd=ROOT)
    assert raw == published, relative
    INPUTS[relative] = dict(sha256=sha(raw))
    return raw


def table(path):
    return list(csv.DictReader(io.StringIO(read(path).decode()), delimiter="\t"))


def write_tsv(path, rows):
    with path.open("w") as f:
        writer = csv.DictWriter(f, fieldnames=list(rows[0]), delimiter="\t", lineterminator="\n")
        writer.writeheader()
        writer.writerows(rows)


def compiled_header(path, arch):
    raw = read(path)
    with tarfile.open(fileobj=io.BytesIO(raw)) as archive:
        members = [m for m in archive.getmembers()
                   if m.name.endswith("/" + arch + "_sim_local_bpf.h")]
        assert len(members) == 1, path
        return sha(archive.extractfile(members[0]).read())



def immediate_alias_adoption(directory, summary, archive):
    production = "f0517e4931be058ddd8ce0d0df87612ee3ffb250"
    changes = json.loads(read(directory / "candidate-changes.json"))
    manifest = json.loads(read(directory / "actual-compiled-inputs.json"))
    bindings = json.loads(read(directory / "numeric-bindings.json"))
    native = json.loads(read(directory / "native-code.json"))["forms"]
    pins = json.loads(read(directory / "executable-pins.json"))
    observer = gzip.decompress(read(directory / "cpu-differential-arm64.gz"))
    assert sha(observer) == pins["binary_sha256"] == summary["binary_sha256"]
    assert observer[:4] == b"\x7fELF" and int.from_bytes(observer[18:20], "little") == 183
    assert pins["reference_sha256"] == summary["reference_sha256"]
    integration_path = ROOT / "corpus/results/kprog_arm64_app_coverage_20261107/numeric-contract-sync/production-integration.json"
    integration_bytes = read(integration_path)
    assert integration_bytes == subprocess.check_output(
        ["git", "show", production + ":" + str(integration_path.relative_to(ROOT))], cwd=ROOT)
    integration = json.loads(integration_bytes)
    assert all(row["exit"] == 0 for row in integration["checks"])
    prefix = "kprog/fidelity/build-arm64-contract-aliases/snapshot/"
    headers, python_changes = {}, {}
    with tarfile.open(fileobj=io.BytesIO(archive.read_bytes())) as compiled:
        members = {m.name:m for m in compiled.getmembers() if m.isfile()}
        assert set(members) == set(manifest)
        for name,digest in manifest.items():
            value = compiled.extractfile(members[name]).read()
            assert sha(value) == digest
            if name.startswith(prefix):
                relative = name[len(prefix):]
                published = subprocess.check_output(["git","show",production+":"+relative],cwd=ROOT)
                assert read(ROOT / relative) == published
                if relative.endswith(".h"):
                    assert value == published
                    headers[relative] = digest
                else:
                    assert relative.endswith(".py")
                    python_changes[relative] = dict(captured_sha256=digest,production_sha256=sha(published))
        assert json.loads(compiled.extractfile("kprog/fidelity/build-arm64-contract-aliases/numeric-bindings.json").read()) == bindings
        assert json.loads(compiled.extractfile("kprog/fidelity/build-arm64-contract-aliases/candidate-changes.json").read()) == changes
        assembly = compiled.extractfile("kprog/fidelity/build-arm64-contract-aliases/instructions.asm").read().decode()
    assert len(manifest) == summary["compiled_input_files"] == 91
    assert len(headers) == 72 and len(python_changes) == 7
    assert sum(row["captured_sha256"] != row["production_sha256"] for row in python_changes.values()) == 2
    assert len(headers)+len(python_changes) == summary["production_snapshot_files"]+summary["candidate_snapshot_files"] == 79
    for path,change in changes["changes"].items():
        assert headers[path] == change["after_sha256"]
    sys.path.insert(0,str(ROOT / "kprog/fidelity"))
    sys.path.insert(0,str(ROOT / "kprog/arm64/micro-prog"))
    def module(name,path):
        spec = importlib.util.spec_from_file_location(name,path)
        value = importlib.util.module_from_spec(spec);sys.modules[name] = value
        spec.loader.exec_module(value)
        return value
    modules_before = set(sys.modules)
    encoder = module("f_adopted_alias_encoder",ROOT / "kprog/arm64/micro-prog/generate_micro_sim_proofs.py")
    generator = module("f_adopted_alias_generator",ROOT / "kprog/fidelity/generate.py")
    encoder_inputs = {}
    for name in set(sys.modules)-modules_before:
        module_path = getattr(sys.modules[name],"__file__",None)
        if module_path and Path(module_path).resolve().is_relative_to(ROOT):
            path = Path(module_path).resolve()
            relative = str(path.relative_to(ROOT))
            data = read(path)
            assert data == subprocess.check_output(["git","show",production+":"+relative],cwd=ROOT)
            encoder_inputs[relative] = sha(data)
    assert len(encoder_inputs) == 8
    instructions = encoder.parse_flat_instructions(assembly)
    matrix = generator.arm64_forms()
    assert len(matrix) == len(instructions) == 807
    by_assembly = dict(zip(matrix,instructions))
    tokens = {"ARM64_OP_ADD_IMM","ARM64_OP_SUB_IMM","ARM64_OP_ALU_IMM"}
    assert len(bindings) == len(native) == summary["forms"] == 60
    for index in range(0,60,6):
        group = bindings[index:index+6]
        encoded = asdict(encoder.encode(by_assembly[group[0]["assembly"]],{},{}))
        assert [row["route"] for row in group] == ["raw","direct"]*3
        assert {row["bound"]["op"] for row in group} == tokens
        for offset,binding in enumerate(group):
            assert encoded == binding["original"]
            assert {k:v for k,v in binding["bound"].items() if k!="op"} == {
                k:v for k,v in encoded.items() if k!="op"}
            assert native[index+offset]["native_bytes"] == native[index]["native_bytes"]
    assert summary["cases"] == 61440 and summary["forms_awaiting_reference"] == 0
    assert summary["unchanged_memory_cases"] == 61440
    return dict(production_commit=production,compiled_input_files=91,
        compiled_snapshot_sources=79,production_equal_compiled_c_headers=72,production_equal_snapshot_sources=77,
        compiled_c_header_sha256=headers,producer_python_snapshot_epochs=python_changes,
        current_encoder_source_sha256=encoder_inputs,encoded_native_forms_equal=10,
        numeric_route_form_bindings_equal=60,raw_direct_native_byte_pairs=30,
        production_integration_checks=integration["checks"],
        original_candidate_commit=summary["candidate_commit"],
        original_candidate_adoption=summary["production_adoption"],
        scope="Captured QEMU/C/reference observations with byte-identical adopted C headers and current producer field correspondence.")


catalogs, aliases, header_identities = {}, {}, {}
for arch in ["x86", "arm64"]:
    path = ROOT / "kprog" / arch / (arch + "_sim.h")
    data = read(path)
    text = data.decode()
    constants = re.findall(r"^#define (" + arch.upper() + r"_OP_\w+) (0x[0-9a-f]+)U$", text, re.M)
    catalogs[arch] = {name: int(value, 16) for name, value in constants}
    assert len(set(catalogs[arch].values())) == len(constants)
    aliases[arch] = dict(re.findall(
        r"^#define (" + arch.upper() + r"_OP_\w+) (" + arch.upper() + r"_OP_\w+)$", text, re.M))
    header_identities[arch] = sha(data)

# Each row retains its own source epoch and backend.
specs = [
    ("x86", "x86-cmp-signed-current", "real_x86_cpu", "enumerated_instruction_forms"),
    ("x86", "x86-rorx-current", "real_x86_cpu", "enumerated_instruction_forms"),
    ("x86", "x86-numeric-tokens", "real_x86_cpu", "legal_numeric_token_binding"),
    ("x86", "x86-dshift-cl", "real_x86_cpu", "cl_register_alias_forms"),
    ("x86", "x86-dshift-cl16", "real_x86_cpu", "defined_16bit_cl_domain"),
    ("x86", "x86-lea-address-matrix", "real_x86_cpu", "production_correspondent_lea_forms"),
    ("x86", "x86-control", "real_x86_cpu", "finite_control_composites"),
    ("arm64", "arm64-current-core", "qemu_user", "enumerated_instruction_forms"),
    ("arm64", "arm64-control-branches", "qemu_user", "finite_control_composites"),
    ("arm64", "arm64-current-bank32/fmov", "qemu_user", "full_vector_bank_forms"),
    ("arm64", "arm64-current-bank32/memory", "qemu_user", "full_vector_bank_memory_forms"),
    ("arm64", "arm64-current-bank32/bitfield", "qemu_user", "enumerated_bitfield_forms"),
    ("arm64", "arm64-current-bank32/exclusive/observed-projection", "qemu_user",
     "explicit_monitor_observation"),
    ("x86", "x86-production-current", "real_x86_cpu", "production_instruction_epoch"),
    ("arm64", "arm64-contract-aliases", "qemu_user", "production_correspondent_immediate_alias_forms"),
]
observations, source_summaries = [], []
for arch, name, backend, scope in specs:
    directory = BASE / name
    summary = json.loads(read(directory / "summary.json"))
    forms, reference = table(directory / "forms.tsv"), table(directory / "reference-forms.tsv")
    assert len(forms) == len(reference) == summary["forms"], name
    grouped = defaultdict(lambda: dict(forms=0, device_c_cases=0, device_c_differences=0,
        device_reference_cases=0, device_reference_differences=0,
        c_reference_cases=0, c_reference_differences=0))
    for native, canonical in zip(forms, reference):
        assert native["assembly"] == canonical["assembly"], name
        cases, refcases = int(native["cases"]), int(canonical["reference_cases"])
        assert cases == int(canonical["cases"]) == refcases, native
        assert int(native["mismatches"]) == int(canonical["cpu_mismatches"]) == int(canonical["simulator_mismatches"]) == 0
        if "status" in canonical:
            assert canonical["status"] == "checked"
        op = native["opcode"]
        if scope != "finite_control_composites":
            assert op in catalogs[arch], op
        row = grouped[op]
        row["forms"] += 1
        row["device_c_cases"] += cases
        row["device_c_differences"] += int(native["mismatches"])
        row["device_reference_cases"] += refcases
        row["device_reference_differences"] += int(canonical["cpu_mismatches"])
        row["c_reference_cases"] += refcases
        row["c_reference_differences"] += int(canonical["simulator_mismatches"])
    archive = directory / "actual-compiled-inputs.tar.gz"
    if not archive.exists():
        archive = directory / "compiled-inputs.tar.gz"
    production_directory = directory
    if scope == "explicit_monitor_observation":
        production_directory = directory.parent
        archive = production_directory / "compiled-inputs.tar.gz"
        production_summary = json.loads(read(production_directory / "summary.json"))
        pins = json.loads(read(directory / "pins.json"))
        refs = [value for path, value in pins.items() if path.endswith("/reference")]
        assert len(refs) == 1
        binary = production_summary["binary_sha256"]
        reference_sha = refs[0]
    else:
        binary = summary["binary_sha256"]
        reference_sha = summary["reference_sha256"]
    header = compiled_header(archive, arch)
    if scope == "production_correspondent_lea_forms":
        interface = json.loads(read(directory / "production-interface.json"))
        manifest = json.loads(read(directory / "actual-compiled-inputs.json"))
        bindings = json.loads(read(directory / "numeric-bindings.json"))
        changes = json.loads(read(directory / "candidate-changes.json"))
        correspondence = summary["production_source_correspondence"]
        assert sha((directory / "production-interface.json").read_bytes()) == correspondence["report_sha256"]
        assert summary["candidate_patch_reproduced"] and summary["production_snapshot_git_equal"]
        assert correspondence["commit"] == interface["production_commit"]
        assert correspondence["identical_compiled_headers"] == interface["compiled_headers"] == 72
        assert correspondence["encoded_forms_equal"] == correspondence["direct_statements_equal"] == 384
        assert len(bindings) == 768 and set(grouped) == {"X86_OP_LEA"}
        assert summary["cases"] == grouped["X86_OP_LEA"]["device_c_cases"] == 196608
        for index in range(384):
            a, b = bindings[2*index:2*index+2]
            assert [a["route"], b["route"]] == ["raw", "direct"] and a["encoded"] == b["encoded"]
        raw = (archive).read_bytes()
        with tarfile.open(fileobj=io.BytesIO(raw)) as captured:
            for path, digest in interface["headers_sha256"].items():
                matches = [member for member in captured.getmembers() if member.name.endswith("/snapshot/" + path)]
                assert len(matches) == 1
                member = matches[0]
                assert sha(captured.extractfile(member).read()) == manifest[member.name] == digest
                production = subprocess.check_output(["git", "show", correspondence["commit"] + ":" + path], cwd=ROOT)
                assert sha(production) == digest
        assert set(changes["used_snapshot_changes"]) == set(summary["candidate_source_sha256"])
        for path in changes["used_snapshot_changes"]:
            assert changes["changes"][path]["after_sha256"] == summary["candidate_source_sha256"][path]

    if scope == "production_instruction_epoch":
        interface = json.loads(read(directory / "replay-interface.json"))
        manifest = json.loads(read(directory / "actual-compiled-inputs.json"))
        control_rows = table(directory / "control-reference/reference-forms.tsv")
        control_status = json.loads(read(directory / "control-reference/status.json"))
        collection = json.loads(read(directory / "collection-status.json"))
        assert summary["initial_command_exit"] == interface["initial_command_exit"] == 2
        assert summary["canonical_completion_exit"] == control_status["exit"] == collection["exit"] == 0
        assert summary["reference_cases"] == interface["final_reference_cases"] == 292864
        assert summary["forms_awaiting_reference"] == 0
        assert interface["control_forms"] == sorted(int(row["form"]) for row in control_rows)
        assert len(control_rows) == interface["initial_forms_awaiting_reference"] == 38
        assert interface["control_cases"] == sum(int(row["reference_cases"]) for row in control_rows) == 9728
        assert interface["binary_sha256"] == control_status["binary_sha256"] == binary
        assert interface["trace_sha256"] == control_status["trace_sha256"] == summary["trace_sha256"]
        assert interface["control_table_sha256"] == sha((directory / "control-reference/reference-forms.tsv").read_bytes())
        assert interface["final_reference_table_sha256"] == sha((directory / "reference-forms.tsv").read_bytes())
        with tarfile.open(fileobj=io.BytesIO(read(directory / "initial-canonical-attempt.tar.gz"))) as initial:
            old_table = initial.extractfile("reference-forms.tsv").read()
            old_rows = list(csv.DictReader(io.StringIO(old_table.decode()), delimiter=chr(9)))
        assert sha(old_table) == interface["initial_reference_table_sha256"]
        assert len(old_rows) == len(reference)
        selected = {int(row["form"]): row for row in control_rows}
        assert all(reference[i] == selected[i] if i in selected else reference[i] == old_rows[i]
                   for i in range(len(reference)))
        assert sum(int(row["reference_cases"]) for row in old_rows) == interface["initial_canonical_cases"] == 283136
        with tarfile.open(fileobj=io.BytesIO(read(directory / "launch-inputs.tar.gz"))) as launch:
            reader = launch.extractfile("kprog/fidelity/reference_check.py").read()
            assert sha(reader) == control_status["source_sha256"]
        source_count = 0
        with tarfile.open(fileobj=io.BytesIO((archive).read_bytes())) as compiled:
            members = {m.name:m for m in compiled.getmembers() if m.isfile()}
            assert set(members) == set(manifest)
            for path, digest in manifest.items():
                assert sha(compiled.extractfile(members[path]).read()) == digest
                if "/snapshot/" in path:
                    relative = path.split("/snapshot/",1)[1]
                    published = subprocess.check_output(["git","show",summary["source_head"]+":"+relative],cwd=ROOT)
                    assert sha(published) == digest
                    source_count += 1
        assert source_count == summary["production_snapshot_files"] == 82
        assert len(manifest) == summary["compiled_input_files"] == 90
        assert summary["production_snapshot_git_equal"]

    adoption = immediate_alias_adoption(directory, summary, archive) if scope == "production_correspondent_immediate_alias_forms" else None

    forms_path = str((directory / "forms.tsv").relative_to(ROOT))
    refs_path = str((directory / "reference-forms.tsv").relative_to(ROOT))
    for op, values in sorted(grouped.items()):
        observations.append(dict(isa=arch, operation=op, source=name, scope=scope,
            backend=backend, **values, simulator_header_sha256=header,
            executable_sha256=binary, reference_sha256=reference_sha,
            forms_table=forms_path, reference_table=refs_path))
    source_summaries.append(dict(isa=arch, source=name, scope=scope,
        backend=backend, forms=len(forms), cases=sum(int(r["cases"]) for r in forms),
        operation_rows=len(grouped), simulator_header_sha256=header,
        executable_sha256=binary, reference_sha256=reference_sha))
    if adoption is not None:
        source_summaries[-1]["production_source_correspondence"] = adoption

# LEAVE uses a native architectural fixture and canonical fault-class replay.
name = "x86-leave64-boundaries/canonical-after"
directory = BASE / name
summary = json.loads(read(directory / "summary.json"))
assert summary["cpu_cases"] == summary["reference_cases"] == 33792
assert summary["mismatches"] == summary["unavailable_classes"] == 0
observations.append(dict(isa="x86", operation="NATIVE_LEAVE64", source=name,
    scope="architectural_fault_classes", backend="real_x86_cpu", forms=1,
    device_c_cases=0, device_c_differences=0,
    device_reference_cases=summary["reference_cases"], device_reference_differences=0,
    c_reference_cases=0, c_reference_differences=0,
    simulator_header_sha256="architectural_fixture", executable_sha256=summary["cpu_binary_sha256"],
    reference_sha256=summary["reference_sha256"],
    forms_table=str((directory / "summary.json").relative_to(ROOT)),
    reference_table=str((directory / "summary.json").relative_to(ROOT))))
source_summaries.append(dict(isa="x86", source=name, scope="architectural_fault_classes",
    backend="real_x86_cpu", forms=1, cases=summary["cpu_cases"], input_classes=summary["input_classes"]))

tokens = []
for arch in ["x86", "arm64"]:
    for op, code in catalogs[arch].items():
        matching = [r for r in observations if r["isa"] == arch and r["operation"] == op]
        ordinary = [r for r in matching if r["scope"] != "explicit_monitor_observation"]
        observed = [r for r in matching if r["scope"] == "explicit_monitor_observation"]
        status = "sampled_three_way" if ordinary else "explicit_monitor_observation" if observed else "replay_pending"
        tokens.append(dict(isa=arch, token=op, numeric_code=hex(code), status=status,
            source_epochs=len(matching),
            supporting_sources=";".join(r["source"] for r in matching),
            catalog_header_sha256=header_identities[arch]))
write_tsv(OUT / "replay-observations.tsv", observations)
write_tsv(OUT / "numeric-token-input.tsv", tokens)
totals = {}
for arch in ["x86", "arm64"]:
    selected = [r for r in tokens if r["isa"] == arch]
    totals[arch] = dict(numeric_tokens=len(selected), width_aliases=len(aliases[arch]),
        sampled_three_way=sum(r["status"] == "sampled_three_way" for r in selected),
        explicit_monitor_observation=sum(r["status"] == "explicit_monitor_observation" for r in selected),
        replay_pending=sum(r["status"] == "replay_pending" for r in selected))
(OUT / "inputs.json").write_text(json.dumps(dict(source_head=HEAD, files=INPUTS,
    aliases=aliases, source_snapshots=source_summaries), indent=2) + "\n")
(OUT / "summary.json").write_text(json.dumps(dict(catalog_totals=totals,
    replay_source_snapshots=len(source_summaries), replay_observation_rows=len(observations),
    domain="Numeric C tokens, plus separately scoped control and architectural observations.",
    integration="Replay inputs for the central formal coverage table maintained by V.",
    scope="Sampled forms and pinned source epochs support generic ISA fidelity evidence."),
    indent=2) + "\n")
print(json.dumps(totals))
print("Replay sources", len(source_summaries), "rows", len(observations), "pinned inputs", len(INPUTS))
