"""Observe actual table-liveness failures without substituting an analysis."""
import json
from pathlib import Path
import sys
import tarfile

root = Path('/workspaces/repository')
sys.path[0] = str(root/'kprog/x86')
import trusted_specializer as adapter

out = Path(sys.argv[1]); out.mkdir(parents=True, exist_ok=True)
archive = Path('/workspaces/kprog-raw/verified/20261119-checked-cilium/service.tar.gz')
rows = []
with tarfile.open(archive) as service:
    for request in (22, 40, 58):
        directory = out/str(request); directory.mkdir(exist_ok=True)
        with tarfile.open(fileobj=service.extractfile(f'service/requests/{request}.success.tar.gz')) as capsule:
            (directory/'trusted_x86.proof.o').write_bytes(capsule.extractfile(
                'request/generated/trusted_x86.proof.o').read())
            metadata = json.load(capsule.extractfile('request/generation.metadata.json'))
            original = json.load(capsule.extractfile('request/simulator-failure.json'))
        instructions, functions, exit_addr, rodata = adapter.gen.parse_native_linked_program(
            'trusted_x86', directory)
        failures = []

        def observe(frame, event, result):
            if event != 'return' or frame.f_code.co_name != 'private_results_dead' or result is not False:
                return
            values = frame.f_locals
            insn = values.get('insn')
            candidate = frame.f_back.f_locals['candidate']
            failures.append(dict(line=frame.f_lineno, scratch=values['scratch'],
                live=values['live'], native_pc=insn.addr if insn else None,
                instruction=insn.raw if insn else None, reads=values.get('reads'),
                writes=values.get('writes'), flags_read=values.get('flags_read'),
                flags_written=values.get('flags_written'), visited=len(values['visited']),
                table=[dict(pc=i.addr, instruction=i.raw) for i in candidate['window']],
                scheduled=[dict(pc=i.addr, instruction=i.raw) for i in candidate['scheduled']],
                choices=candidate['choices']))

        sys.setprofile(observe)
        try:
            adapter.gen.render_program('trusted_x86', instructions, functions, kind='raw',
                exit_addr=exit_addr, rodata16=rodata, program_section=metadata['section'],
                trusted_map_bindings=[dict(native_symbol=m['name'], value_offset=m.get('value_offset'))
                                      for m in metadata['maps']])
        except ValueError as error:
            if str(error) != original['error']:
                raise
            rows.append(dict(request=request, error=str(error), failures=failures))
        else:
            raise AssertionError(f'request{request} no longer reproduces original failure')
        finally:
            sys.setprofile(None)
        (out/'result.json').write_text(json.dumps(dict(source_archive=str(archive), requests=rows,
            scope='Read-only observation of existing production analysis on actual captured proof objects; no lowering, compiler, guest, stock or performance change.'), indent=2)+'\n')
        print(json.dumps(rows[-1]), flush=True)
