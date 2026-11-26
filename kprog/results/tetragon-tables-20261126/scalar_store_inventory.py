"""Observe existing ABI scalar constants; do not change cache selection."""
import json
from pathlib import Path
import re
import sys

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path[0] = str(ROOT / 'kprog/x86')
import trusted_specializer as worker
from x86_abi import PointerAlternatives

rows = []
for ident in (39, 12, 38, 9):
    directory = HERE / ('request-' + str(ident))
    metadata = json.loads((directory / 'generation.metadata.json').read_text())
    insns, functions, end, rodata = worker.gen.parse_native_linked_program('trusted_x86', directory)
    sites = {}
    def observe(frame, event, result):
        if event != 'return' or frame.f_code.co_name != 'store' or not frame.f_code.co_filename.endswith('/x86_abi.py'):
            return
        local = frame.f_locals
        parent = frame.f_back.f_locals
        if local['width'] != 64 or local['immediate_store']:
            return
        instruction = parent['insn']
        location = local['location']
        if type(location) is int:
            offsets = {location}
        elif isinstance(location, PointerAlternatives):
            offsets = set(location.offsets)
        elif location is False:
            offsets = set()
        else:
            offsets = {None}
        args = parent['args']
        source = parent['ri'](args[1]) if len(args) > 1 else None
        constant = parent['incoming'].constants[source[0]] if source else None
        scalar = (parent['op'] in {'mov', 'movabs'} and source is not None and constant is not None)
        row = sites.setdefault(instruction.addr, dict(pc=instruction.addr, instruction=instruction.raw,
            offsets=set(), all_constant_scalar=True, constants=set(), has_unknown_constant=False))
        row['offsets'].update(offsets)
        row['all_constant_scalar'] &= scalar
        row['has_unknown_constant'] |= constant is None
        if constant is not None:
            row['constants'].add(constant)
    sys.setprofile(observe)
    try:
        source = worker.gen.render_program('trusted_x86', insns, functions,
            kind=worker.context_kind(metadata['prog_type']), exit_addr=end, rodata16=rodata,
            program_section=metadata['section'], trusted_map_bindings=[
                dict(native_symbol=item['name'], value_offset=item.get('value_offset')) for item in metadata['maps']])
    finally:
        sys.setprofile(None)
    declaration = next(l for l in source.splitlines() if l.startswith('#define X86_SIM_STACK_VALUE_WORDS'))
    stack_bytes = int(re.search(r'#define X86_SIM_STACK_BYTES (\d+)U', source)[1])
    baseline = set(int(w) * 8 - stack_bytes for w in re.findall(r'M\((\d+)\)', declaration))
    constant_offsets = set().union(*(r['offsets'] for r in sites.values() if r['all_constant_scalar']))
    other_offsets = set().union(*(r['offsets'] for r in sites.values() if not r['all_constant_scalar']))
    # None retains every possible destination; it cannot justify pruning.
    removed = set() if None in other_offsets else (constant_offsets - other_offsets) & baseline
    rows.append(dict(request=ident, stack_bytes=stack_bytes, baseline_words=len(baseline),
        exclusively_known_scalar_offsets=sorted(removed),
        observed_store_sites=[dict(r, offsets=sorted(r['offsets'], key=lambda x: (x is None, x or 0)), constants=sorted(r['constants']))
                              for r in sorted(sites.values(), key=lambda x:x['pc'])]))
    print(ident, 'words',len(baseline),'candidate reduction',len(removed),flush=True)
import subprocess
(HERE / 'scalar-store-inventory.json').write_text(json.dumps(dict(
    recorded_utc=subprocess.check_output(['date','-u','+%Y-%m-%dT%H:%M:%SZ'],text=True).strip(),
    rows=rows, scope='Observer of existing full-source ABI pass. Candidate offsets only, not a soundness proof, adopted optimization, frame reduction or stock/app acceptance.'),indent=2)+'\n')
