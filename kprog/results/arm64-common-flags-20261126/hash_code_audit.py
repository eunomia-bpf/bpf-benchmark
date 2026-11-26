"""Retain actual ARM hash-helper code and the existing per-CPU postprocess."""
from datetime import datetime, timezone
import json
from pathlib import Path
import subprocess

from elftools.elf.elffile import ELFFile

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
obj = ROOT / 'kinsn/module/arm64/build/bpf_x86_native_lab.o'
command = ['aarch64-linux-gnu-objdump', '-d', '--disassemble=kprog_htab_elem_k4', str(obj)]
result = subprocess.run(command, text=True, capture_output=True, check=True)
(HERE / 'hash-k4.dis').write_text(result.stdout)
with obj.open('rb') as stream:
    elf = ELFFile(stream)
    symbol = next(s for s in elf.get_section_by_name('.symtab').iter_symbols()
                  if s.name == 'kprog_htab_elem_k4')
    section = elf.get_section(symbol['st_shndx'])
    data = section.data()[symbol['st_value']:symbol['st_value'] + symbol['st_size']]
(HERE / 'hash-k4.bin').write_bytes(data)
linker = ROOT / 'kprog/x86/native_lab/native_link/src/main.rs'
text = linker.read_text()
start = text.index('fn build_arm64_lookup_call_postprocess(')
end = text.index('\nfn append_u32(', start)
record = dict(recorded_utc=subprocess.check_output(['date','-u','+%Y-%m-%dT%H:%M:%SZ'],text=True).strip(),
    source_revision=subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip(),
    module_object=str(obj),module_object_bytes=obj.stat().st_size,
    module_object_mtime_utc=datetime.fromtimestamp(obj.stat().st_mtime,timezone.utc).isoformat(),
    symbol='kprog_htab_elem_k4',symbol_bytes=len(data),disassemble_command=command,
    module_compile_record=(obj.parent / '.bpf_x86_native_lab.o.cmd').read_text(),
    postprocess_source=str(linker.relative_to(ROOT)),postprocess_body=text[start:end],
    findings=['Built key4 helper uses ordinary LDR word loads, not byte assembly or acquire loads.',
              'Existing PerCpuHash postprocess emits MRS TPIDR_EL1 and ADD directly, not another helper call.'],
    scope='Source/compiled-code audit only. No PMU/performance measurement, production change, build, image or timing run.')
(HERE / 'hash-code-audit.json').write_text(json.dumps(record,indent=2)+'\n')
print('retained key4 code:',len(data),'bytes; existing postprocess source captured')
