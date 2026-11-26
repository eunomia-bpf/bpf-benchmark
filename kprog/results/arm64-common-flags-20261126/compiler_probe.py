"""Check installed compiler support for the actual Spark core's tuning model."""
import json
from pathlib import Path
import subprocess

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
source = 'unsigned long probe(const unsigned long *p, unsigned n) { unsigned long a=0; for(unsigned i=0;i<n;i++) a=(a<<7)^(a>>3)^p[i]; return a; }\n'
version = subprocess.run(['clang-18', '--version'], text=True, capture_output=True, check=True)
commands = []
for cpu in ['neoverse-n1', 'cortex-x925']:
    command = ['clang-18', '--target=aarch64-linux-gnu', '-O3', '-g', '-fPIC',
        '-fomit-frame-pointer', '-mgeneral-regs-only', '-mno-outline-atomics', '-ffixed-x26',
        '-fno-stack-protector', '-mtune=' + cpu, '-x', 'c', '-c', '-', '-o', '/dev/null']
    result = subprocess.run(command, input=source, text=True, capture_output=True)
    commands.append(dict(cpu=cpu,command=command,returncode=result.returncode,
                         stdout=result.stdout,stderr=result.stderr))
record = dict(recorded_utc=subprocess.check_output(['date','-u','+%Y-%m-%dT%H:%M:%SZ'],text=True).strip(),
    source_revision=subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip(),
    compiler=version.stdout,source=source,commands=commands,
    scope='Compiler capability only. Native P flags/builds/image unchanged, no performance claim or timing run. Actual Spark run8 timing CPUs15-19 are Cortex-X925.')
(HERE / 'compiler-probe.json').write_text(json.dumps(record,indent=2)+'\n')
print(json.dumps(record,indent=2))
if commands[0]['returncode']:
    raise SystemExit(commands[0]['returncode'])
