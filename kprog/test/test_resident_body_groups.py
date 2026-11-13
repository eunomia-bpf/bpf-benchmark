"""Different relocation/data bytes must not inherit another body's outcome."""
import unittest
import json
from pathlib import Path
import tempfile
from types import SimpleNamespace

from resident_verified_census import group_bodies, replay, replay_programs, resume, resume_programs, retain_request_artifacts, write_replay_guests


class BodyGrouping(unittest.TestCase):
    def test_resume_does_not_repeat_completed_bodies_or_drop_unfinished_requests(self):
        rows = [dict(body_group=n, resource=dict(maps=[n])) for n in range(7)]
        outcomes = [dict(body_group=0, stage="verifier_rejected"),
                    dict(body_group=2, stage="installed"),
                    dict(body_group=2, stage="installed")]
        priority = [rows[2], rows[4], rows[2]]
        selected, pending = resume_programs(rows, outcomes, priority)
        self.assertEqual(pending, 5)
        self.assertEqual([r["body_group"] for r in selected], [2, 4, 1, 3, 5, 6])
        self.assertEqual(selected[-1], rows[-1])
        self.assertEqual(resume_programs(rows, outcomes, [])[0],
                         [rows[n] for n in (1, 3, 4, 5, 6)])

    def test_resume_partitions_all_pending_and_class_bodies_with_complete_resources(self):
        with tempfile.TemporaryDirectory() as work:
            root = Path(work)
            inputs, main, extra, priority = (root / name for name in
                                             ("inputs.json", "main.jsonl", "extra.jsonl", "priority.json"))
            rows = [dict(body_group=n, source_prog_id=n+100, resource=dict(map_inventory=[n]))
                    for n in range(7)]
            source = dict(programs=rows, body_groups=[dict(body_group=n, members=[n, n+20])
                                                      for n in range(7)],
                          applications=[dict(application="app", map_inventory=[7, 8])])
            original = json.dumps(source)
            inputs.write_text(original)
            main.write_text(json.dumps(dict(body_group=0, stage="installed")) + "\n")
            extra.write_text(json.dumps(dict(body_group=1, stage="verifier_rejected")) + "\n")
            priority.write_text(json.dumps(dict(programs=[rows[1], rows[2], rows[1]])))
            output = root / "resume"
            resume(SimpleNamespace(inputs=inputs, completed_journal=main, additional_journal=[extra],
                                   priority_inventory=[priority], guest_count=3, output=output))
            result = json.loads((output / "inventory.json").read_text())
            guests = [json.loads(Path(path).read_text())
                      for path in result["resume"]["guest_inventories"]]
            self.assertEqual([[r["body_group"] for r in g["programs"]] for g in guests],
                             [[1, 4], [2, 5], [3, 6]])
            self.assertEqual(result["resume"]["pending_bodies"], 5)
            self.assertEqual(result["resume"]["additional_replay_bodies"], 1)
            self.assertEqual(sorted(r["body_group"] for g in guests for r in g["programs"]),
                             [1, 2, 3, 4, 5, 6])
            for guest in guests:
                self.assertEqual(guest["applications"], source["applications"])
                self.assertEqual(guest["body_groups"], source["body_groups"])
                for row in guest["programs"]:
                    self.assertEqual(row, rows[row["body_group"]])
            self.assertEqual(inputs.read_text(), original)

    def test_class_replay_includes_independent_guest_observations(self):
        with tempfile.TemporaryDirectory() as work:
            root = Path(work)
            inputs, main, independent = (root / name for name in ("inputs.json", "main.jsonl", "independent.jsonl"))
            source = dict(programs=[], applications=[dict(application="app", map_inventory=[7])],
                          body_groups=[dict(body_group=n, representative=dict(source_prog_id=n,
                                            resource=dict(map_inventory=[7])), members=[n], retained_outcome=None)
                                       for n in (20, 30)])
            inputs.write_text(json.dumps(source))
            bounds = dict(stage="verifier_rejected", diagnostic="invalid access to map value")
            main.write_text(json.dumps(dict(bounds, body_group=30)) + "\n")
            independent.write_text(json.dumps(dict(bounds, body_group=20)) + "\n")
            output = root / "replay"
            replay(SimpleNamespace(inputs=inputs, completed_journal=main,
                                   additional_journal=[independent], output=output,
                                   failure_class=["verifier_map_bounds"]))
            result = json.loads((output / "inventory.json").read_text())
            self.assertEqual([row["body_group"] for row in result["programs"]], [20, 30])
            self.assertEqual(result["replay"]["additional_journals"], [str(independent)])
            self.assertEqual(result["applications"], source["applications"])

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
