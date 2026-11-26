"""Isolate machine early-if-conversion on existing P bitcode, without IR retuning."""
import gzip
import json
from pathlib import Path
import re
import subprocess
from elftools.elf.elffile import ELFFile

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
BUILD = Path('/var/tmp/kprog-tmp/perf/arm64-codegen-abi')
output = BUILD / 'select-backend.o'
commands, rows = [], []
for app, module in [('bcc', 'vfsstat'), ('katran', 'balancer'), ('cilium', 'bpf_lxc')]:
    obj = ROOT / 'vendor/build/native-bpf/arm64/stage' / app / (module + '.native.o')
    with obj.open('rb') as stream:
        bitcode = ELFFile(stream).get_section_by_name('.llvmbc').data()
    objects = []
    for name, extra in [('default', []), ('without-early-ifcvt',
                         ['-aarch64-enable-early-ifcvt=false'])]:
        command = ['llc-18', '-O3', '-relocation-model=pic', '-filetype=obj',
                   '-o', str(output), '-', *extra]
        result = subprocess.run(command, input=bitcode, capture_output=True)
        commands.append(dict(command=command, input=str(obj.relative_to(ROOT)) + ':.llvmbc',
                             returncode=result.returncode, stderr=result.stderr.decode()))
        (HERE / 'select-backend-commands.json').write_text(json.dumps(commands, indent=2) + '\n')
        result.check_returncode()
        data = output.read_bytes()
        stem = 'select-backend-' + app + '-' + name
        (HERE / (stem + '.o.gz')).write_bytes(gzip.compress(data, mtime=0))
        dis = subprocess.run(['llvm-objdump-18', '-d', str(output)], text=True,
                             capture_output=True, check=True).stdout
        (HERE / (stem + '.dis.gz')).write_bytes(gzip.compress(dis.encode(), mtime=0))
        with output.open('rb') as stream:
            elf = ELFFile(stream)
            code = {s.name: s.data() for s in elf.iter_sections() if s['sh_flags'] & 4}
        counts = {}
        function = None
        for line in dis.splitlines():
            symbol = re.match(r'[0-9a-f]+ <(.+)>:', line)
            if symbol:
                function = symbol[1]
            insn = re.match(r'\s*[0-9a-f]+:\s+[0-9a-f]{8}\s+(\S+)', line)
            if insn and re.fullmatch(r'cs(?:el|inc|inv|neg|et|etm)', insn[1]):
                counts[function] = counts.get(function, 0) + 1
        objects.append(dict(policy=name, code=code, selects_by_function=counts))
        print(app, name, sum(counts.values()), flush=True)
    before, after = objects
    rows.append(dict(app=app, input=str(obj.relative_to(ROOT)),
        code_sections_equal=before['code'] == after['code'],
        default_selects=before['selects_by_function'],
        without_early_ifcvt_selects=after['selects_by_function'],
        default_code_bytes=sum(map(len, before['code'].values())),
        without_early_ifcvt_code_bytes=sum(map(len, after['code'].values()))))
record = dict(recorded_utc=subprocess.check_output(['date', '-u', '+%Y-%m-%dT%H:%M:%SZ'], text=True).strip(),
    revision=subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip(),
    rows=rows,
    scope='Fixed backend-only early-if-conversion control on three current staged modules. Embedded IR attributes retained; llc regenerates both controls. No claim that regenerated default equals original P bytes, no stock/app/semantic/timing result or production policy change.')
(HERE / 'select-backend-result.json').write_text(json.dumps(record, indent=2) + '\n')
print(json.dumps(record, indent=2))
