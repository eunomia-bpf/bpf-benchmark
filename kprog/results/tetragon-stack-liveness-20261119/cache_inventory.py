"""Observe the existing ABI analysis; do not implement a second interpreter."""
import json
from pathlib import Path
import re
import sys
import tarfile

root = Path('/workspaces/repository')
# This result directory's inspect.py is not Python's standard inspect module.
sys.path[0] = str(root/'kprog/x86')
import trusted_specializer as adapter
from x86_abi import PointerAlternatives

out = Path(sys.argv[1])
out.mkdir(parents=True, exist_ok=True)
retained = Path('/workspaces/kprog-raw/perf/b-analysis-flags-20261119/'
                'production-20261119T063707Z-211523/tetragon6')
capsule = Path('/workspaces/kprog-raw/verified/20261118-checked-hot/'
               'tetragon-c/state/session-4u0ra04z/requests/6.success.tar.gz')
with tarfile.open(capsule) as archive:
    metadata = json.load(archive.extractfile('request/generation.metadata.json'))
instructions, functions, exit_addr, rodata = adapter.gen.parse_native_linked_program(
    'trusted_x86', retained)

stores, summary = {}, {}
abi_file = str(root/'kprog/x86/micro-prog/x86_abi.py')

def observe(frame, event, result):
    if event != 'return' or frame.f_code.co_filename != abi_file:
        return
    values = frame.f_locals
    if frame.f_code.co_name == 'store' and values['width'] == 64:
        caller = frame.f_back.f_locals
        instruction = caller['insn']
        location = values['location']
        if type(location) is int:
            offsets, unknown, external = {location}, False, False
        elif location is False:
            offsets, unknown, external = set(), False, True
        elif isinstance(location, PointerAlternatives):
            offsets = set(location.offsets)
            unknown, external = False, location.external
        else:
            offsets, unknown, external = set(), True, True
        row = stores.setdefault(instruction.addr, dict(native_pc=instruction.addr,
            instruction=instruction.raw, offsets=set(), unknown=False, external=False))
        row['offsets'].update(offsets)
        row['unknown'] |= unknown
        row['external'] |= external
    elif frame.f_code.co_name == 'check_definedness':
        states = values['states']
        summary.update(stack_bytes=result, analysis_states=len(states),
            call_contexts=len({context for context, _ in states}),
            pointer_dictionary_offsets=sorted({offset for state in states.values()
                                              for offset in state.pointers}),
            unknown_rsp_states=sum(type(state.aliases[values['rsp']]) is not int
                                   for state in states.values()))

sys.setprofile(observe)
try:
    generated = adapter.gen.render_program('trusted_x86', instructions, functions,
        kind='raw', exit_addr=exit_addr, rodata16=rodata,
        program_section=metadata['section'],
        trusted_map_bindings=[dict(native_symbol=m['name'],
            value_offset=m.get('value_offset')) for m in metadata['maps']])
finally:
    sys.setprofile(None)

summary['generated_arena_bytes'] = int(re.search(
    r'#define X86_SIM_STACK_BYTES (\d+)U', generated)[1])
summary['full_width_store_sites'] = [dict(row, offsets=sorted(row['offsets']))
                                    for row in sorted(stores.values(), key=lambda r:r['native_pc'])]
summary.update(retained_proof=str(retained/'trusted_x86.proof.o'),
    metadata_capsule=str(capsule), pruning_proven=False,
    scope='Read-only observation of the existing ABI CFG analysis. The alias '
          'False includes both scalar and external pointers. Unknown stores, '
          'push/pop/call frames and helper copies need conservative treatment; '
          'this inventory does not establish dead ghost cells, B acceptance or speed.')
(out/'inventory.json').write_text(json.dumps(summary, indent=2)+'\n')
print(json.dumps({key:value for key,value in summary.items()
                  if key not in {'full_width_store_sites','pointer_dictionary_offsets'}}), flush=True)
