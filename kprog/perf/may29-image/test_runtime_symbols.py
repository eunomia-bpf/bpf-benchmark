"""Catch anonymous/non-executable paths leaking into symbol evidence."""
import importlib.util
from pathlib import Path
import unittest

SPEC = importlib.util.spec_from_file_location('symbols', Path(__file__).with_name('runtime-symbols.py'))
SYMBOLS = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(SYMBOLS)


class MappedFiles(unittest.TestCase):
    def test_only_real_executable_files_and_no_unrecoverable_deleted_mapping(self):
        text = '''1-2 r--p 0 00:42 1 /usr/lib/data
2-3 r-xp 0 00:42 2 /usr/lib/libc.so
3-4 r-xp 0 00:00 0 [vdso]
4-5 r-xp 0 00:42 3 /a path/program
'''
        self.assertEqual(SYMBOLS.mapped_files(text), {'usr/lib/libc.so', 'a path/program'})
        with self.assertRaisesRegex(ValueError, 'deleted'):
            SYMBOLS.mapped_files('1-2 r-xp 0 00:42 1 /old/program (deleted)')


if __name__ == '__main__':
    unittest.main()
