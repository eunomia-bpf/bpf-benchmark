"""Catch attribution across code boundaries and misleading mnemonic categories."""
import importlib.util
from pathlib import Path
import unittest

spec = importlib.util.spec_from_file_location('instruction_costs', Path(__file__).with_name('instruction-costs.py'))
profile = importlib.util.module_from_spec(spec)
spec.loader.exec_module(profile)


class InstructionCosts(unittest.TestCase):
    def test_sample_inside_instruction_and_half_open_program_end(self):
        rows = profile.instructions('1000: mov %rax,%rbx\n1003: ret', 0x1000, 4)
        p = dict(start=0x1000, end=0x1004, instructions=rows, addresses=[0x1000,0x1003])
        self.assertEqual(profile.locate([p], 0x1002), (p, 0))
        self.assertEqual(profile.locate([p], 0x1003), (p, 1))
        self.assertIsNone(profile.locate([p], 0xfff))
        self.assertIsNone(profile.locate([p], 0x1004))
        with self.assertRaises(ValueError):
            profile.locate([p, p], 0x1000)

    def test_unordered_or_missing_start_disassembly_is_not_attributed(self):
        for text in ('1001: ret', '1000: nop\n1000: ret', '1001: nop\n1000: ret'):
            with self.assertRaises(ValueError):
                profile.instructions(text, 0x1000, 2)

    def test_address_syntax_distinguishes_frame_and_stack_registers(self):
        for asm, expected in [('call 0x123', 'call'), ('je 0x123', 'control'),
                              ('mov 0x10(%rsp),%eax', 'rsp_address_operand'),
                              ('mov -0x60(%rbp),%ebx', 'rbp_address_operand'),
                              ('lea (%rax,%rbp,1),%eax', 'other'),
                              ('cmp %dx,(%rax)', 'other_memory_operand')]:
            self.assertEqual(profile.category(asm), expected)


if __name__ == '__main__':
    unittest.main()
