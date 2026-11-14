#!/usr/bin/env python3
"""Offline real-object default-byte parity and local-memory proof inspection.

Synthetic address plans compare linker output only. They are never submitted to
a kernel and never count as application execution or workload measurements.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import subprocess
from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parents[2]
STAGE = ROOT / 'vendor/build/native-bpf/x86/stage'


def details(path):
    with path.open('rb') as stream:
        elf = ELFFile(stream)
        symbols = elf.get_section_by_name('.symtab')
        return dict(text=elf.get_section_by_name('.text').data(),
                    symbols=[dict(name=s.name, size=s['st_size'], offset=s['st_value'],
                                  undefined=s['st_shndx'] == 'SHN_UNDEF', kind=s['st_info']['type'])
                             for s in symbols.iter_symbols() if s.name])


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--candidate', required=True, type=Path)
    parser.add_argument('--reference', required=True, type=Path)
    parser.add_argument('--output', required=True, type=Path)
    parser.add_argument('--runtime-map-lookups', action='store_true')
    parser.add_argument('--tracee-object', type=Path,
                        default=Path('/var/tmp/kprog-tmp/perf/memory-flags/tracee.plain.o'))
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=True)
    cases = [('bcc', STAGE/'bcc/syscount.native.o', 'sys_enter'),
             ('cilium', STAGE/'cilium/bpf_lxc.native.o', 'cil_from_container'),
             ('katran', STAGE/'katran/balancer.native.o', 'balancer_ingress'),
             ('otel', STAGE/'otelcol-ebpf-profiler/otelcol-ebpf-profiler.native.o', 'native_tracer_entry'),
             ('tetragon', STAGE/'tetragon/bpf_generic_kprobe_v61.native.o', 'generic_kprobe_event'),
             ('tetragon-execve', STAGE/'tetragon/bpf_execve_event_v61.native.o', 'event_execve'),
             ('bcc-biosnoop', STAGE/'bcc/biosnoop.native.o', 'block_rq_insert')]
    plain = args.tracee_object
    cases += [('tracee-'+s, plain, s) for s in ['trace_sys_enter', 'trace_sys_exit', 'sys_enter_submit', 'trace_ret_vfs_read_tail']]
    helpers = set(re.findall(r'Some\("(bpf_[^"]+)"\)',
        (ROOT/'kprog/x86/native_lab/native_link/src/x86.rs').read_text()))
    rows = []
    for label, source, symbol in cases:
        original = source
        content = source.read_bytes()
        digest = hashlib.sha256(content).hexdigest()
        source = args.output/'inputs'/(digest+'.native.o')
        source.parent.mkdir(exist_ok=True)
        source.write_bytes(content)
        directory = args.output/label
        directory.mkdir(exist_ok=True)
        data = details(source)
        names = helpers | {'memset', 'memcpy', 'memmove'} | {
            s['name'] for s in data['symbols'] if s['undefined'] and s['kind'] == 'STT_FUNC'}
        targets = {name: 0xffffffff81000000 + n*256 for n, name in enumerate(sorted(names))}
        targets.update(__native_x86_bpf_map_max_entries_offset=68, __native_x86_bpf_array_ptrs_offset=304,
                       __native_x86_bpf_prog_bpf_func_offset=72, __native_x86_tail_call_offset=12,
                       __native_x86_cpu_number=0x1000, __native_x86_this_cpu_off=0x2000)
        plan = dict(version=1, helpers=[dict(name=k, addr=v) for k,v in targets.items()],
                    maps=[dict(name=s['name'], addr=0xffff888000000000+n*4096)
                          for n,s in enumerate(data['symbols']) if s['kind'] != 'STT_FUNC' and s['kind'] != 'STT_FILE'])
        plan_path = directory/'synthetic-plan.json'
        plan_path.write_text(json.dumps(plan, indent=2)+'\n')

        def run(binary, name, mode, input_path, enabled=False):
            output = directory/(name+('.proof.o' if mode == 'proof' else '.bin'))
            command = [str(binary), '--mode', mode, '--input', str(input_path), '--symbol', symbol,
                       '--link-plan', str(plan_path), '--output', str(output)]
            if enabled: command += ['--local-memory-routines']
            if args.runtime_map_lookups: command += ['--runtime-map-lookups']
            if mode == 'kernel': command += ['--output-relocs', str(output)+'.relocs',
                '--output-map-patches', str(output)+'.maps', '--output-abi', str(output)+'.abi']
            with (directory/(name+'.log')).open('w') as log:
                print(subprocess.list2cmdline(command), file=log, flush=True)
                subprocess.run(command, check=True, stdout=log, stderr=subprocess.STDOUT)
            return output

        reference = run(args.reference, 'reference', 'proof', source)
        candidate = run(args.candidate, 'default', 'proof', source)
        proof_equal = reference.read_bytes() == candidate.read_bytes()
        old_kernel = run(args.reference, 'reference-kernel', 'kernel', reference)
        new_kernel = run(args.candidate, 'default-kernel', 'kernel', reference)
        kernel_equal = all(Path(str(old_kernel)+suffix).read_bytes() == Path(str(new_kernel)+suffix).read_bytes()
                           for suffix in ['', '.relocs', '.maps', '.abi'])
        if not proof_equal or not kernel_equal:
            raise ValueError(f'default-byte mismatch in {label}')
        enabled = run(args.candidate, 'local', 'proof', source, True)
        run(args.candidate, 'local-kernel', 'kernel', enabled, True)
        local = details(enabled)
        if any(s['undefined'] and s['name'] in ['memset','memcpy'] for s in local['symbols']):
            raise ValueError(f'unbound memory symbol in {label}')
        rows.append(dict(label=label, input=str(source), original_input=str(original), symbol=symbol,
                         input_sha256=digest,
                         default_proof_full_elf_equal=proof_equal, default_proof_text_equal=proof_equal, default_kernel_and_metadata_equal=kernel_equal,
                         proof_bytes_before=len(details(reference)['text']), proof_bytes_after=len(local['text']),
                         local_routines=[s for s in local['symbols'] if s['name'].startswith('__native_link_local_')]))
    (args.output/'report.json').write_text(json.dumps(dict(cases=rows,
        reference=str(args.reference), candidate=str(args.candidate),
        limits=['Synthetic address plans are offline parity inputs, never kernel execution.',
                'Vendor stage is current build data; Tracee uses the original-source plain flag experiment object.',
                'Host executable/guard-page fixtures cover runtime memory semantics separately.']),indent=2)+'\n')


if __name__ == '__main__':
    main()
