#!/usr/bin/env python3
"""Build canonical linker artifacts for every selected entry section.

Offline linker execution only: no verifier submission or native installation.
Undefined symbols get synthetic addresses, so a successful roundtrip proves
relocation arithmetic, not that their implementations or resources exist.
"""
import argparse
import json
from pathlib import Path
import subprocess
from elftools.elf.elffile import ELFFile


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--input', type=Path, required=True)
    parser.add_argument('--linker', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--section-prefix', action='append')
    parser.add_argument('--kernel-roundtrip', action='store_true',
                        help='Offline ELF integration with synthetic addresses; never submitted to a kernel')
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    with args.input.open('rb') as stream:
        elf = ELFFile(stream)
        prefixes = args.section_prefix or ['cgroup/']
        entries = [symbol.name for symbol in elf.get_section_by_name('.symtab').iter_symbols()
                   if symbol['st_info']['type'] == 'STT_FUNC' and isinstance(symbol['st_shndx'], int)
                   and any(elf.get_section(symbol['st_shndx']).name.startswith(prefix) for prefix in prefixes)]
        symbols=list(elf.get_section_by_name('.symtab').iter_symbols())
        helpers={symbol.name:0xffffffff81000000+n*256 for n,symbol in enumerate(symbols)
                 if symbol.name and symbol['st_shndx']=='SHN_UNDEF'}
        # Illustrative layout/addresses for byte relocation only; not a kernel ABI check.
        helpers.update(__native_x86_bpf_map_max_entries_offset=68,__native_x86_bpf_array_ptrs_offset=304,
                       __native_x86_bpf_prog_bpf_func_offset=72,__native_x86_tail_call_offset=12,
                       __native_x86_cpu_number=0x1000,__native_x86_this_cpu_off=0x2000)
        plan=dict(version=1,helpers=[dict(name=name,addr=value) for name,value in helpers.items()],
                  maps=[dict(name=symbol.name,addr=0xffff888000000000+n*4096)
                        for n,symbol in enumerate(symbols) if symbol.name and symbol['st_info']['type'] not in ['STT_FUNC','STT_FILE']])
    if not entries:
        raise ValueError('object has no entries in requested sections')
    rows = []
    if args.kernel_roundtrip:
        (args.output/'synthetic-plan.json').write_text(json.dumps(plan,indent=2)+'\n')
        (args.output/'synthetic-external-targets.json').write_text(json.dumps(dict(
            scope='Placeholder addresses only; no function body or runtime resource availability is established.',
            targets=[dict(name=s.name, elf_type=s['st_info']['type'],
                          elf_binding=s['st_info']['bind'], address=helpers[s.name])
                     for s in symbols if s.name and s['st_shndx']=='SHN_UNDEF']),indent=2)+'\n')
    for name in sorted(entries):
        command = [str(args.linker), '--mode', 'proof', '--input', str(args.input),
                   '--symbol', name, '--output', str(args.output/(name+'.proof.o'))]
        if args.kernel_roundtrip: command += ['--link-plan',str(args.output/'synthetic-plan.json')]
        result = subprocess.run(command, capture_output=True, text=True)
        (args.output/(name+'.stdout')).write_text(result.stdout)
        (args.output/(name+'.stderr')).write_text(result.stderr)
        rows.append(dict(symbol=name, command=command, returncode=result.returncode))
        if args.kernel_roundtrip and result.returncode==0:
            kernel=[str(args.linker),'--mode','kernel','--input',str(args.output/(name+'.proof.o')),
                    '--symbol',name,'--link-plan',str(args.output/'synthetic-plan.json'),
                    '--output',str(args.output/(name+'.kernel.bin')),
                    '--output-relocs',str(args.output/(name+'.kernel.relocs')),
                    '--output-map-patches',str(args.output/(name+'.kernel.maps')),
                    '--output-abi',str(args.output/(name+'.kernel.abi'))]
            linked=subprocess.run(kernel,capture_output=True,text=True)
            (args.output/(name+'.kernel.stdout')).write_text(linked.stdout)
            (args.output/(name+'.kernel.stderr')).write_text(linked.stderr)
            rows[-1].update(kernel_command=kernel,kernel_returncode=linked.returncode)
        (args.output/'report.json').write_text(json.dumps(rows, indent=2)+'\n')
    if any(row['returncode'] or row.get('kernel_returncode',0) for row in rows):
        raise SystemExit(1)


if __name__ == '__main__':
    main()
