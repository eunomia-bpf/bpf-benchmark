"""SIMD and FP instructions use the scalar generator's missing-handler path."""
import importlib.util
from pathlib import Path
import sys
import unittest

ROOT = Path(__file__).resolve().parents[2]


def generator(arch):
    directory = ROOT / 'kprog' / arch / 'micro-prog'
    sys.path.insert(0, str(directory))
    spec = importlib.util.spec_from_file_location('scalar_' + arch,
                                                 directory / 'generate_micro_sim_proofs.py')
    module = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = module
    spec.loader.exec_module(module)
    return module


class ScalarNativeGeneration(unittest.TestCase):
    def test_x86_simd_and_fp_have_generation_errors(self):
        gen = generator('x86')
        for text in ('movaps xmm0, XMMWORD PTR [rax]', 'movups XMMWORD PTR [rax], xmm0',
                     'movaps xmm1, XMMWORD PTR [rax]', 'pxor xmm0, xmm0',
                     'vpxor ymm0, ymm0, ymm0', 'movq mm0, rax', 'fldz', 'emms'):
            op, _, operands = text.partition(' ')
            with self.subTest(text=text), self.assertRaises(ValueError):
                gen.encode(gen.NativeInsn(0, text, op, gen.split_operands(operands)), {})
        insn = gen.NativeInsn(0, 'mov eax, 2', 'mov', ('eax', '2'))
        self.assertEqual(gen.encode(insn, {}).op, 'X86_OP_MOV_IMM')

    def test_arm64_simd_and_fp_have_generation_errors(self):
        gen = generator('arm64')
        for op, operands in (
            ('ldr', ('q0', '[x0]')), ('ldur', ('d0', '[x0]')),
            ('str', ('q0', '[x0]')), ('stur', ('d0', '[x0]')),
            ('ldr', ('s31', '[x0]')), ('ldp', ('q0', 'q1', '[x0]')),
            ('fmov', ('d0', 'x0')), ('fmov', ('x0', 'd0')),
            ('fmov', ('s31', 'w0')), ('fmov', ('w0', 's31')),
            ('cnt', ('v0.8b', 'v0.8b')), ('cnt', ('v0.16b', 'v0.16b')),
            ('uaddlv', ('h0', 'v0.8b')), ('uaddlv', ('h0', 'v0.16b')),
            ('fadd', ('d0', 'd1', 'd2')), ('mrs', ('x0', 'fpcr')),
        ):
            with self.subTest(op=op, operands=operands), self.assertRaises(ValueError):
                gen.encode(gen.NativeInsn(0, op, operands, op), {}, {})
        insn = gen.NativeInsn(0, 'mov', ('w0', '#2'), 'mov w0, #2')
        self.assertEqual(gen.encode(insn, {}, {}).op, 'ARM64_OP_MOV_IMM')


if __name__ == '__main__':
    unittest.main()
