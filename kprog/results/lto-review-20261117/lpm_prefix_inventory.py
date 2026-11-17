#!/usr/bin/env python3
"""Record retained prefix arithmetic and all possible nonzero-BSR results."""
import json
from pathlib import Path
import subprocess

here = Path(__file__).resolve().parent
evidence = json.loads((here / 'evidence.json').read_text())['typed_unwinder']
blob = Path(evidence['blob'])
kernel = Path('/workspaces/.agent-state/kprog-ck/build-x86/vmlinux')
native = subprocess.check_output([
    'objdump', '-D', '-b', 'binary', '-m', 'i386:x86-64', '-M', 'intel',
    '--no-show-raw-insn', '--start-address=' + str(0x761e),
    '--stop-address=' + str(0x7678), str(blob)], text=True)
kernel_assembly = subprocess.check_output([
    'objdump', '-d', '-M', 'intel', '--no-show-raw-insn',
    '--disassemble=trie_lookup_elem', str(kernel)], text=True)
domains = []
for width, constant in [(64, 63), (32, 95)]:
    values = [dict(bsr_result=x, old_prefix=constant-x, xor_prefix=x ^ constant)
              for x in range(width)]
    domains.append(dict(input_width=width, nonzero_bsr_results=width,
                        constant=constant, values=values,
                        agreeing_results=sum(v['old_prefix'] == v['xor_prefix'] for v in values)))
result = dict(
    recorded_utc=subprocess.check_output(['date', '-u', '+%FT%TZ'], text=True).strip(),
    scope='Source/retained-byte and finite-domain arithmetic review only. No candidate byte sequence assembled/emitted/executed; no runtime check/feature/dispatch change. Applies only after the existing nonzero guards in the generated 12-byte LPM path.',
    retained_blob=str(blob), retained_native_disassembly=native,
    kernel_image=str(kernel), kernel_trie_disassembly=kernel_assembly,
    domains=domains,
    changes=dict(first=['BSR RCX,RAX; NEG ECX; ADD ECX,63', 'BSR RCX,RAX; XOR ECX,63'],
                 second=['BSR ECX,EAX; NEG ECX; ADD ECX,95', 'BSR ECX,EAX; XOR ECX,95'],
                 instructions_removed_per_taken_bsr_case=1,
                 local_bytes_removed_per_case=2,
                 total_local_routine_bytes_removed=4),
    flags='Both result paths jump to CMP ECX,R9D before any flag-dependent consumer. Preserve zero handling, limit clamp and branch targets.')
(here / 'lpm-prefix.json').write_text(json.dumps(result, indent=2) + '\n')
print([(d['input_width'], d['agreeing_results']) for d in domains])
