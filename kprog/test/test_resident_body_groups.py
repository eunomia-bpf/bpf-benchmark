"""Different relocation/data bytes must not inherit another body's outcome."""
import unittest

from resident_verified_census import group_bodies


class BodyGrouping(unittest.TestCase):
    def test_byte_identity_preserves_all_members_and_priority(self):
        rows = [dict(application="app", source_prog_id=n, native_candidates=[
                    dict(native_object=f"{n}.o", symbol="entry")]) for n in range(5)]
        rows.append(dict(application="app", source_prog_id=5, native_candidates=[]))
        bodies = {("0.o", "entry"): b"text/data/reloc-A",
                  ("1.o", "entry"): b"text/data/reloc-B",
                  ("2.o", "entry"): b"text/data/reloc-A",
                  ("3.o", "entry"): None, ("4.o", "entry"): None}
        groups = group_bodies(rows, bodies)
        self.assertEqual([[r["source_prog_id"] for r in g["members"]] for g in groups],
                         [[0, 2], [1], [3], [4], [5]])
        self.assertEqual([g["representative"]["source_prog_id"] for g in groups],
                         [0, 1, 3, 4, 5])
        self.assertEqual(groups[0]["members"][1], rows[2])


if __name__ == "__main__":
    unittest.main()
