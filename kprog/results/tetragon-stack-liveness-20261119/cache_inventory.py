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

stores, returns, summary = {}, {}, {}
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
            instruction=instruction.raw, offsets=set(), unknown=False, external=False,
            source_constants=set(), source_unknown=False))
        row['offsets'].update(offsets)
        row['unknown'] |= unknown
        row['external'] |= external
        operands = instruction.operands
        source = caller['ri'](operands[1]) if len(operands) > 1 else None
        constant = caller['incoming'].constants[source[0]] if source else (
            adapter.gen.parse_int(operands[1]) if len(operands) > 1 and adapter.gen.is_int(operands[1]) else None)
        if constant is None:
            row['source_unknown'] = True
        else:
            row['source_constants'].add(constant)
    elif frame.f_code.co_name == 'return_from':
        pc=frame.f_back.f_locals['addr']
        row=returns.setdefault(pc,dict(native_pc=pc,targets=set(),unknown=False,outer=False))
        destinations=values['destinations']
        if isinstance(destinations,frozenset):
            row['targets'].update(d.target for d in destinations if d.target is not None)
            row['outer'] |= any(d.target is None for d in destinations)
        else:
            row['unknown']=True
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
summary['generated_cache_words'] = [int(word) for word in re.findall(r'M\((\d+)\)', next(
    line for line in generated.splitlines() if line.startswith('#define X86_SIM_STACK_VALUE_WORDS')))]
summary['full_width_store_sites'] = [dict(row, offsets=sorted(row['offsets']),
                                        source_constants=sorted(row['source_constants']))
                                    for row in sorted(stores.values(), key=lambda r:r['native_pc'])]
summary['return_sites'] = [dict(row,targets=sorted(row['targets']))
                           for row in sorted(returns.values(),key=lambda r:r['native_pc'])]
dispatches = {label: [int(v, 16) for v in re.findall(r'case 0x([0-9a-f]+)ULL:', body)]
    for label, body in re.findall(r'(x86_sim_ret_dispatch_[0-9a-f]+):\n\tswitch \(__x86_sim_ret_addr\) \{(.*?)\n\t}', generated, re.S)}
dispatch_sites = []
for pc, body in re.findall(r'^x86_l_([0-9a-f]+):\n(.*?)(?=^x86_l_|\Z)', generated, re.S | re.M):
    for label in re.findall(r'X86_SIM_X86_SUB_RET\((x86_sim_ret_dispatch_[0-9a-f]+)\)', body):
        observed = dispatches[label]
        row = returns[int(pc, 16)]
        if not row['unknown'] and not row['outer']:
            assert observed == sorted(row['targets']), (pc, observed, row)
        dispatch_sites.append(dict(native_pc=int(pc, 16), label=label, targets=observed))
summary['generated_return_dispatch_sites'] = dispatch_sites
summary['generated_return_dispatch_edges'] = sum(len(row['targets']) for row in dispatch_sites)
(out/'generated.bpf.c').write_text(generated)
summary.update(retained_proof=str(retained/'trusted_x86.proof.o'),
    metadata_capsule=str(capsule), pruning_proven=False,
    scope='Read-only observation of the existing ABI CFG analysis. The alias '
          'False includes both scalar and external pointers. Unknown stores, '
          'push/pop/call frames and helper copies need conservative treatment; '
          'this inventory does not establish dead ghost cells, B acceptance or speed.')
(out/'inventory.json').write_text(json.dumps(summary, indent=2)+'\n')
print(json.dumps({key:value for key,value in summary.items()
                  if key not in {'full_width_store_sites','pointer_dictionary_offsets'}}), flush=True)
