"""Reproduce this coverage experiment; each case retains its complete log."""
import concurrent.futures
import json
import gzip
import os
from pathlib import Path
import re
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[3]


def record_path(path):
    if path.exists() or path.suffix=='.gz':
        return path
    compressed=path.with_suffix('.json.gz')
    return compressed if compressed.exists() else path


def returncode(path):
    path=record_path(path)
    with (gzip.open(path,'rt') if path.suffix=='.gz' else path.open()) as stream:
        match = re.search(r'"returncode": (-?\d+)', stream.read(16384))
    if match is None:
        raise ValueError(f"missing command returncode: {path}")
    return int(match[1])


def compile_one(row, directory):
    source = Path(row["source"])
    build = directory / "objects"
    build.mkdir(exist_ok=True)
    command = ["clang", "-O2", *row.get("compiler_flags", []), "-Wno-c23-extensions", "-target", "bpf", "-mllvm", "-bpf-stack-size=4096",
               "-D__TARGET_ARCH_x86", "-I", str(ROOT / "vendor/libbpf/include/uapi"),
               "-I", str(ROOT / "vendor/libbpf/src"), "-I", "/usr/include/x86_64-linux-gnu",
               "-I", str(ROOT / "kprog/x86/micro-prog"), "-c", str(source),
               "-o", str(build / (row["name"] + ".bpf.o"))]
    return execute(row, directory, "compile", command, None)


def execute(row, directory, stage, command, timeout):
    log = directory / stage / (row["name"] + ".json")
    if record_path(log).exists():
        return {"name": row["name"], "returncode": returncode(log)}
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


def link_one(row, directory):
    from elftools.elf.elffile import ELFFile
    original = Path(row['original_object'])
    # OTel's Go loader accepts local entry symbols. libbpf requires global
    # entry symbols, including unused original entries retained by ELF linking.
    # Change only ELF linkage; every original instruction/map/global stays exact.
    with original.open('rb') as stream:
        elf = ELFFile(stream)
        entries = [symbol.name for symbol in elf.get_section_by_name('.symtab').iter_symbols()
                   if symbol['st_info']['type'] == 'STT_FUNC'
                   and isinstance(symbol['st_shndx'], int)
                   and elf.get_section(symbol['st_shndx'])['sh_flags'] & 4
                   and elf.get_section(symbol['st_shndx']).name != '.text']
    # BTF_KIND_FUNC carries the same linkage as the ELF symbol. Patch only
    # those FUNC info words; BTF IDs, type layouts and all other bytes stay exact.
    import struct
    with original.open('rb') as stream:
        elf = ELFFile(stream)
        endian = '<' if elf.little_endian else '>'
        btf = bytearray(elf.get_section_by_name('.BTF').data())
    magic, version, _, header, type_off, type_len, string_off, string_len = struct.unpack_from(endian+'HBBIIIII', btf)
    if magic != 0xeb9f or version != 1:
        raise ValueError('unsupported original BTF header')
    strings = btf[header+string_off:header+string_off+string_len]
    cursor, end = header+type_off, header+type_off+type_len
    remaining = set(entries)
    while cursor < end:
        name_off, info, _ = struct.unpack_from(endian+'III', btf, cursor)
        kind, vlen = (info >> 24) & 31, info & 65535
        if kind == 12:
            name = strings[name_off:strings.index(0, name_off)].decode()
            if name in remaining:
                struct.pack_into(endian+'I', btf, cursor+4, (info & ~65535) | 1)
                remaining.remove(name)
        sizes = {1:4,2:0,3:12,4:12*vlen,5:12*vlen,6:8*vlen,7:0,
                 8:0,9:0,10:0,11:0,12:0,13:8*vlen,14:4,15:12*vlen,
                 16:0,17:4,18:0,19:12*vlen}
        cursor += 12 + sizes[kind]
    if cursor != end or remaining:
        raise ValueError(f'original entry BTF linkage unresolved: {sorted(remaining)}')
    btf_input = original.with_name(original.stem+'.global.btf')
    btf_input.write_bytes(btf)
    link_input = original.with_name(original.stem+'.libbpf.o')
    (directory/'link-input').mkdir(exist_ok=True)
    prepared = execute(row, directory, 'link-input',
                       ['llvm-objcopy', '--update-section', '.BTF='+str(btf_input),
                        *['--globalize-symbol='+name for name in entries],
                        str(original), str(link_input)], None)
    if prepared['returncode'] != 0:
        return prepared
    command = [str(ROOT/'vendor/build/x86/bpftool/bin/bpftool'),
               'gen', 'object', row['simulator_object'],
               str(directory/'objects'/(row['name']+'.bpf.o')),
               str(link_input)]
    return execute(row, directory, 'link', command, None)


def verify_one(row, directory):
    if row.get('program_section'):
        command = [str(ROOT/'corpus/results/kprog_app_coverage_20261106/verify-proof'),
            row.get('simulator_object', str(directory/'objects'/(row['name']+'.bpf.o'))),row['name']+'_x86_sim_xdp',
            str(directory/'verify'/(row['name']+'.verifier.log'))]
        if 'program_type' in row:
            command.append(str(row['program_type']))
        return execute(row,directory,'verify',command,60)
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
        worker, jobs = compile_one, int(os.environ.get("KPROG_COMPILE_WORKERS","6"))
    elif stage in {"link", "verify"}:
        worker, jobs = (link_one, 1) if stage == "link" else (verify_one, 2)
        completed = {p.name.removesuffix('.gz').removesuffix('.json'): returncode(p)
                     for pattern in ('*.json','*.json.gz')
                     for p in (directory / "compile").glob(pattern)}
        print(f"compile pending: {len(rows) - len(completed)}", flush=True)
        rows = [row for row in rows if row["name"] in completed
                and completed[row["name"]] == 0]
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
