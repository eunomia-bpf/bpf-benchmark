"""Replay two retained Tetragon generation refusals at the table-lowering boundary."""
import json
from pathlib import Path
import sys
import tarfile

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[2]
sys.path.insert(0, str(ROOT / 'kprog/x86'))
import trusted_specializer as worker
from x86_relative_tables import lower_relative_tables

ARCHIVES = Path('/workspaces/kprog-raw/verified/omp-five-20261120/tetragon/state/session-6f0mwwi2/requests')
results = []
for ident in tuple(map(int, sys.argv[1:])) if len(sys.argv) > 1 else (12, 9):
    out = HERE / ('request-' + str(ident))
    out.mkdir(exist_ok=True)
    archive = ARCHIVES / (str(ident) + '.success.tar.gz')
    with tarfile.open(archive) as source:
        for member, name in [('request/generated/trusted_x86.proof.o', 'trusted_x86.proof.o'),
                             ('request/generation.metadata.json', 'generation.metadata.json'),
                             ('request/simulator-failure.json', 'historical-failure.json')]:
            with source.extractfile(member) as stream:
                (out / name).write_bytes(stream.read())
    historical = json.loads((out / 'historical-failure.json').read_text())
    row = dict(request_id=ident, archive=str(archive), historical_error=historical['error'])
    instructions, functions, exit_addr, rodata = worker.gen.parse_native_linked_program('trusted_x86', out)
    all_insns = [*instructions, *(insn for body in functions.values() for insn in body)]
    starts = {instructions[0].addr, *(body[0].addr for body in functions.values() if body)}
    witnesses = []

    def trace(frame, event, value):
        if event == 'return' and frame.f_code.co_name == 'private_results_dead' and value is False:
            state = frame.f_locals
            insn = state.get('insn')
            witnesses.append(dict(line=frame.f_lineno, instruction=insn.raw if insn else None,
                address=insn.addr if insn else None, scratch=list(state['scratch']),
                private_masks=list(state['live']), flags_read=state.get('flags_read'),
                register_reads=state.get('reads'), observes_return=state.get('observes_return'),
                relocation=insn.reloc_symbol if insn else None,
                local_target=insn.reloc_target if insn else None))
        return trace

    sys.setprofile(trace)
    try:
        lowered = lower_relative_tables(all_insns, rodata, worker.gen, exit_addr, starts)
        row.update(status='lowered', input_instructions=len(all_insns), output_instructions=len(lowered))
    except ValueError as error:
        row.update(status='refused', error=str(error), input_instructions=len(all_insns))
    finally:
        sys.setprofile(None)
    row['liveness_witnesses'] = witnesses
    row['indirect_jump_context'] = [dict(address=insn.addr, instruction=insn.raw)
        for index, insn in enumerate(all_insns) if insn.addr == 0x3580
        for insn in all_insns[max(0, index - 6):index + 2]] if ident == 9 else []
    results.append(row)
(HERE / 'reproduction.json').write_text(json.dumps(results, indent=2) + '\n')
for row in results:
    print(row['request_id'], row['status'], row.get('error', ''), flush=True)
