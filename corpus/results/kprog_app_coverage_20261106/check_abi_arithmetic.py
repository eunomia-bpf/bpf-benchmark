"""Regress unspecified high bits leaking through arithmetic or flag uses."""
import importlib.util
import json
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[3]
HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(ROOT / 'kprog/x86/micro-prog'))
spec = importlib.util.spec_from_file_location('arithmetic_generator',
    ROOT / 'kprog/x86/micro-prog/generate_micro_sim_proofs.py')
g = importlib.util.module_from_spec(spec)
sys.modules[spec.name] = g
spec.loader.exec_module(g)

rows = []
def check(name, body, error=None):
    insns = [g.NativeInsn(i, op+' '+','.join(args), op, args)
             for i, (op, args) in enumerate(body)]
    try:
        g.render_program(name, insns)
    except ValueError as exc:
        if error is None or error not in str(exc):
            raise
        rows.append(dict(name=name, outcome='rejected', error=str(exc)))
    else:
        assert error is None, f'{name}: unspecified ABI bits became defined'
        rows.append(dict(name=name, outcome='generated'))

low = [('mov', ('dx', 'WORD PTR [rdi]'))]
finish = [('movzx', ('eax', 'dx')), ('ret', ())]
for op in ('add', 'sub', 'adc', 'sbb'):
    carry = [('cmp', ('rdi', 'rdi'))] if op in {'adc', 'sbb'} else []
    body = low + carry + [(op, ('edx', '0x28'))]
    # A low16 packet store/return observes no unspecified upper EDX bits.
    check(op+'_low16', body + finish)
    check(op+'_upper_observed', body + [('mov', ('eax', 'edx')), ('ret', ())],
          'undefined native ABI register eax')
    check(op+'_carry_observed', body + [('jb', (str(len(body)+1),))] + finish,
          'undefined native ABI flags')

check('memory_low16', [('sub', ('rsp', '8')), ('mov', ('WORD PTR [rsp]', '0x1234')),
      ('mov', ('QWORD PTR [rsp]', 'rbx')), ('mov', ('WORD PTR [rsp]', '0x1234')),
      ('add', ('DWORD PTR [rsp]', '0x28')), ('movzx', ('eax', 'WORD PTR [rsp]')),
      ('add', ('rsp', '8')), ('ret', ())])
check('borrow_unknown_low', [('mov', ('dh', '0x12')), ('sub', ('edx', '1')),
      ('movzx', ('eax', 'dh')), ('ret', ())], 'undefined native ABI register eax')
check('adc_unknown_carry', low + [('adc', ('edx', '1'))] + finish,
      'undefined native ABI carry')
check('cmp_discarded', [('cmp', ('rbx', '1')), ('mov', ('eax', '2')), ('ret', ())])
check('cmp_observed', [('cmp', ('rbx', '1')), ('je', ('2',)),
      ('mov', ('eax', '2')), ('ret', ())], 'undefined native ABI flags')
check('cmp_self', [('cmp', ('rbx', 'rbx')), ('je', ('2',)),
      ('mov', ('eax', '2')), ('ret', ())])
check('test_fixed_carry', [('test', ('rbx', 'rbx')), ('jb', ('2',)),
      ('mov', ('eax', '2')), ('ret', ())])
check('test_unknown_zero', [('test', ('rbx', 'rbx')), ('je', ('2',)),
      ('mov', ('eax', '2')), ('ret', ())], 'undefined native ABI flags')
(HERE / 'arithmetic-regression.json').write_text(json.dumps(rows, indent=2)+'\n')
print(json.dumps(rows, indent=2))
