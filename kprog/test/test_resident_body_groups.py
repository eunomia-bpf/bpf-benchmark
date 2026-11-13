"""Different relocation/data bytes must not inherit another body's outcome."""
import unittest
import json
from pathlib import Path
import tempfile

from resident_verified_census import group_bodies, replay_programs, retain_request_artifacts, write_replay_guests


class BodyGrouping(unittest.TestCase):
    def test_parallel_guest_inputs_preserve_the_entire_class_and_resources(self):
        source = dict(programs=[dict(body_group=n, source_prog_id=n+20,
                                    resource=dict(map_inventory=[n])) for n in [3,7,11]],
                      applications=[dict(application="app", map_inventory=[4,5])])
        with tempfile.TemporaryDirectory() as work:
            paths = write_replay_guests(source, Path(work))
            guests = [json.loads(Path(path).read_text()) for path in paths]
        self.assertEqual([g["programs"][0] for g in guests], source["programs"])
        self.assertEqual([len(g["programs"]) for g in guests], [1,1,1])
        for guest in guests:
            self.assertEqual(guest["applications"], source["applications"])
            self.assertEqual(guest["execution_partition"]["body_group"],
                             guest["programs"][0]["body_group"])

    def test_journal_archive_survives_service_session_cleanup(self):
        with tempfile.TemporaryDirectory() as work:
            retained = Path(work) / "retained"
            with tempfile.TemporaryDirectory(dir=work) as session:
                original = Path(session) / "1.failure.tar.gz"
                original.write_bytes(b"complete request evidence")
                row = dict(submission=dict(service=dict(failure_archive=str(original))))
                retain_request_artifacts(row, retained)
            target = Path(row["submission"]["service"]["failure_archive"])
            self.assertEqual(target, retained / original.name)
            self.assertEqual(target.read_bytes(), b"complete request evidence")

    def test_class_replay_keeps_every_body_once_after_later_success(self):
        failure = dict(stage="verifier_rejected", diagnostic="invalid mem access 'scalar'")
        groups = [dict(body_group=n, representative=dict(source_prog_id=n, resource={"maps": n}),
                       members=[n, n + 10], retained_outcome=failure if n == 0 else None)
                  for n in range(3)]
        outcomes = [dict(failure, body_group=1), dict(failure, body_group=1),
                    dict(stage="installed", body_group=0)]
        selected = replay_programs(groups, outcomes, {"verifier_scalar_memory_access"})
        self.assertEqual([r["body_group"] for r in selected], [0, 1])
        self.assertEqual(selected[1]["resource"], {"maps": 1})
        self.assertEqual(groups[0]["members"], [0, 10])
        self.assertEqual(replay_programs(groups, outcomes, {"compiler_stack_storage"}), [])

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
