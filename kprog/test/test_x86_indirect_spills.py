"""Finite dispatch must follow real spill definitions and forget clobbered ones."""
from pathlib import Path
import sys
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'x86/micro-prog'))
import generate_micro_sim_proofs as gen


def instruction(address, text, **facts):
    op, _, operands = text.partition(' ')
    return gen.NativeInsn(address, text, op, gen.split_operands(operands), **facts)


def program(middle):
    code = [instruction(0, 'lea rax, [rip]', reloc_target=0x80)]
    code += [instruction(i, text) for i, text in enumerate(middle, 1)]
    call = len(code)
    code += [instruction(call, 'call rax'), instruction(call + 1, 'jmp 0x70'),
             instruction(0x80, 'ret')]
    return code, call


class IndirectSpills(unittest.TestCase):
    def targets(self, code):
        return gen.indirect_targets(code, exit_addr=0x70, function_starts={0, 0x80})

    def test_volatile_spill_reload_and_nonoverlapping_store(self):
        code, call = program(['mov QWORD PTR [rsp+8], rax',
                              'mov DWORD PTR [rsp+16], 7',
                              'mov rax, QWORD PTR [rsp+8]'])
        self.assertEqual(self.targets(code)[call], frozenset({('code', 0x80)}))

    def test_stack_join_keeps_both_reaching_code_targets(self):
        code = [instruction(0, 'test edi, edi'), instruction(1, 'je 0x5'),
                instruction(2, 'lea rax, [rip]', reloc_target=0x80),
                instruction(3, 'mov QWORD PTR [rsp+8], rax'), instruction(4, 'jmp 0x7'),
                instruction(5, 'lea rax, [rip]', reloc_target=0x90),
                instruction(6, 'mov QWORD PTR [rsp+8], rax'),
                instruction(7, 'mov rax, QWORD PTR [rsp+8]'),
                instruction(8, 'call rax'), instruction(9, 'jmp 0x70'),
                instruction(0x80, 'ret'), instruction(0x90, 'ret')]
        targets = gen.indirect_targets(code, exit_addr=0x70, function_starts={0, 0x80, 0x90})
        self.assertEqual(targets[8], frozenset({('code', 0x80), ('code', 0x90)}))

    def test_unknown_join_path_cannot_inherit_another_paths_spill(self):
        code, call = program(['test edi, edi', 'je 0x4',
                              'mov QWORD PTR [rsp+8], rax',
                              'mov rax, QWORD PTR [rsp+8]'])
        with self.assertRaisesRegex(ValueError, 'unresolved finite indirect target'):
            self.targets(code)

    def test_partial_loads_and_overlapping_stores_lose_the_target(self):
        for middle in [
            ['mov rax, DWORD PTR [rsp+8]'],
            ['mov BYTE PTR [rsp+15], 0', 'mov rax, QWORD PTR [rsp+8]'],
            ['mov QWORD PTR [rsp+4], rcx', 'mov rax, QWORD PTR [rsp+8]'],
            ['mov DWORD PTR [rsp+8], eax', 'mov rax, QWORD PTR [rsp+8]'],
        ]:
            with self.subTest(middle=middle):
                code, call = program(['mov QWORD PTR [rsp+8], rax', *middle])
                with self.assertRaisesRegex(ValueError, 'unresolved finite indirect target'):
                    self.targets(code)

    def test_alias_writes_and_stack_changes_forget_old_slots(self):
        for clobber in ['mov QWORD PTR [rdi], rcx', 'xchg rdx, QWORD PTR [rdi]',
                        'inc QWORD PTR [rsp+8]', 'add rsp, 8', 'push rcx',
                        'pop rcx', 'xchg rdx, rsp',
                        'mov QWORD PTR fs:[rsp+8], rcx',
                        'mov QWORD PTR [esp+8], rcx',
                        'mov QWORD PTR [rsp+rcx], rdx']:
            with self.subTest(clobber=clobber):
                code, call = program(['mov QWORD PTR [rsp+8], rax', clobber,
                                      'mov rax, QWORD PTR [rsp+8]'])
                with self.assertRaisesRegex(ValueError, 'unresolved finite indirect target'):
                    self.targets(code)

    def test_calls_do_not_share_rsp_relative_spills_across_frames(self):
        code, call = program(['mov QWORD PTR [rsp+8], rax', 'call 0x80',
                              'mov rax, QWORD PTR [rsp+8]'])
        with self.assertRaisesRegex(ValueError, 'unresolved finite indirect target'):
            self.targets(code)

    def test_helper_relocation_keeps_its_id_before_memory_operand_handling(self):
        number, name = next(iter(gen.helper_idents().items()))
        code, call = program([])
        code[0] = instruction(0, 'mov rax, QWORD PTR [rip]', reloc_symbol=name)
        self.assertEqual(self.targets(code)[call], frozenset({('scalar', number)}))


if __name__ == '__main__':
    unittest.main()
