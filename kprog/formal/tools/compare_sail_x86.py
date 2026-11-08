#!/usr/bin/env python3
"""Compare per-instruction register/flag/PC observations with the upstream Sail x86 model."""
from pathlib import Path
import struct, subprocess, json, re, gzip, hashlib, argparse

def main():
    ROOT = Path(__file__).resolve().parent.parent
    parser = argparse.ArgumentParser(description='Compare native instruction units in Lean and the ACL2-derived Sail x86 model')
    parser.add_argument('--model', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--reference', type=Path, default=ROOT / '.lake/build/bin/reference')
    args = parser.parse_args()
    out = args.output.resolve()
    out.mkdir(parents=True, exist_ok=True)
    model = args.model.resolve()
    ref = args.reference.resolve()
    names = ['rax', 'rcx', 'rdx', 'rbx', 'rsp', 'rbp', 'rsi', 'rdi'] + ['r' + str(i) for i in range(8, 16)]
    forms = []

    def add(op, asm):
        forms.append((op, asm))
    add('NOP', 'nop')
    for w, a, b in [(8, 'al', 'bl'), (16, 'ax', 'bx'), (32, 'eax', 'ebx'), (64, 'rax', 'rbx')]:
        for op, asm in [('MOV_IMM', f'mov {a},7'), ('MOV_REG', f'mov {a},{b}'), ('ADD_IMM', f'add {a},7'), ('ADD_REG', f'add {a},{b}'), ('XOR_REG', f'xor {a},{b}'), ('CMP_IMM', f'cmp {a},7'), ('CMP_REG', f'cmp {a},{b}'), ('TEST_IMM', f'test {a},7'), ('TEST_REG', f'test {a},{b}'), ('XCHG', f'xchg {a},{b}'), ('DIV', f'div {b}')]:
            add(op, asm)
        for insn in ['adc', 'sub', 'sbb', 'and', 'or', 'xor']:
            add('ALU_IMM', f'{insn} {a},7')
            add('ALU_REG', f'{insn} {a},{b}')
        if w >= 16:
            for op, asm in [('CMOV', f'cmovb {a},{b}'), ('POPCNT', f'popcnt {a},{b}'), ('SHLD_IMM', f'shld {a},{b},7'), ('SHRD_IMM', f'shrd {a},{b},7'), ('BT', f'bt {a},{b}'), ('BT_IMM', f'bt {a},7'), ('IMUL_IMM', f'imul {a},{b},7'), ('ROR', f'ror {a},7')]:
                add(op, asm)
        if w >= 32:
            add('BSWAP', f'bswap {a}')
            count = 'ecx' if w == 32 else 'rcx'
            for insn in ['shlx', 'shrx', 'sarx']:
                add('SHIFTX', f'{insn} {a},{b},{count}')
            add('RORX', f'rorx {a},{b},7')
            add('BZHI', f'bzhi {a},{b},{count}')
            add('ANDN', f'andn {a},{b},{count}')
            add('MULX', f'mulx {a},{count},{b}')
    for op, asm in [('MOVZX_REG', 'movzx eax,bl'), ('MOVZX_REG', 'movzx eax,bx'), ('MOVSX_REG', 'movsx rax,bl'), ('MOVSX_REG', 'movsx rax,bx'), ('MOVSX_REG', 'movsxd rax,ebx'), ('SETCC', 'setb al'), ('SETCC', 'setl al'), ('LEA', 'lea rax,[rbx+rcx*4+17]')]:
        add(op, asm)
    vectors = [(0, 1), (1, 3), ((1 << 64) - 1, 1), ((1 << 63) - 1, 1), (1 << 63, (1 << 64) - 1), (1311768467139281697, 18364758545390235393)]
    results = []
    base = 4096
    for n, (op, asm) in enumerate(forms):
        source = out / f'form-{n}.s'
        source.write_text('.intel_syntax noprefix\n.text\n.global _start\n_start:\n' + asm + '\n')
        obj = source.with_suffix('.o')
        raw = source.with_suffix('.bin')
        subprocess.run(['as', '--64', str(source), '-o', str(obj)], check=True, stdout=subprocess.DEVNULL, stderr=subprocess.PIPE)
        subprocess.run(['objcopy', '-O', 'binary', '-j', '.text', str(obj), str(raw)], check=True)
        code = raw.read_bytes()
        header = struct.pack('<16sHHIQQQIHHHHHH', b'\x7fELF' + bytes([2, 1, 1]) + bytes(9), 2, 62, 1, base, 64, 0, 0, 64, 56, 1, 0, 0, 0)
        ph = struct.pack('<IIQQQQQQ', 1, 5, 4096, base, base, len(code), len(code), 4096)
        elf = header + ph
        elf += bytes(4096 - len(elf)) + code
        binary = source.with_suffix('.elf')
        binary.write_bytes(elf)
        for variant, (left, right) in enumerate(vectors):
            for cf in [0, 1]:
                registers = [left, 3, 0, right, 12288, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]
                if op == 'DIV':
                    registers[0] = left % 128
                    registers[3] = right | 1
                if op == 'MULX':
                    registers[2] = left
                request = dict(isa='x86_64', native_bytes=list(code), state=dict(registers=registers, flags=2 | cf, pc=base, xmm0=0, fs_base=0, gs_base=0, memory=[]))
                cmd = [str(model), '-e', str(binary)]
                for k, val in [('rip', base), ('ha', base + len(code)), ('rflags', 2 | cf), ('cr4', 512), ('set64bit', 1), ('app_view', 1), *zip(names, registers)]:
                    cmd += ['-C', k + '=' + hex(val)]
                modelrun = subprocess.run(cmd, text=True, capture_output=True)
                leanrun = subprocess.run([str(ref)], input=json.dumps(request) + '\n', text=True, capture_output=True)
                logname = f'form-{n}-{variant}-{cf}.log.gz'
                (out / logname).write_bytes(gzip.compress((modelrun.stdout + modelrun.stderr).encode(), mtime=0))
                values = {k: int(h, 16) for k, h in re.findall('^(\\w+) = 0x([0-9a-fA-F]+)$', modelrun.stdout, re.M)}
                row = dict(operation='X86_OP_' + op, assembly=asm, native_bytes=list(code), variant=variant, carry=cf, request=request, model_exit=modelrun.returncode, lean_exit=leanrun.returncode, model_log=logname, lean_stdout=leanrun.stdout, lean_stderr=leanrun.stderr)
                if leanrun.returncode:
                    row.update(status='lean-domain', error=leanrun.stderr)
                elif modelrun.returncode or not all((k in values for k in names + ['rflags', 'rip'])) or (not re.search('^Steps = 1$', modelrun.stdout, re.M)):
                    row.update(status='model-stopped', error=(modelrun.stdout + modelrun.stderr)[-1000:])
                else:
                    expected = json.loads(leanrun.stdout)
                    actual = dict(registers=[values[k] for k in names], flags=values['rflags'], pc=values['rip'])
                    masks = expected.get('defined_registers', [(1 << 64) - 1] * 16)
                    good = expected['fault'] is None and actual['pc'] == expected['pc'] and all(((a ^ b) & mask == 0 for a, b, mask in zip(actual['registers'], expected['registers'], masks))) and ((actual['flags'] ^ expected['flags']) & expected['defined_flags'] == 0)
                    row.update(status='agree' if good else 'difference', model=actual, lean=expected)
                results.append(row)
        with (out / 'cases.jsonl').open('w') as f:
            for row in results:
                f.write(json.dumps(row, sort_keys=True) + '\n')
        print(n, op, asm, results[-1]['status'], flush=True)
    summary = {s: sum((x['status'] == s for x in results)) for s in sorted({x['status'] for x in results})}
    (out / 'summary.json').write_text(json.dumps(dict(forms=len(forms), cases=len(results), statuses=summary, model_sha256=hashlib.sha256(model.read_bytes()).hexdigest(), lean_sha256=hashlib.sha256(ref.read_bytes()).hexdigest()), indent=2) + '\n')
    print('COMPARISON COMPLETE', summary, flush=True)
    raise SystemExit(0 if all((row['status'] == 'agree' for row in results)) else 1)
if __name__ == '__main__':
    main()
