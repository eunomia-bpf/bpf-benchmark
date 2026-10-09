#!/usr/bin/env python3
"""Generate the shared x86-64 helper-id -> helper-body dispatch contract.

The hand-written `X86_SIM_BPF_CALL_ID(ID)` ladder in
`kprog/x86/x86_sim_local_bpf.h` binds a 64-bit BPF helper id to one of seven
`X86_SIM_BPF_CALL_bpf_*()` body macros, with a default arm that zeroes RAX:

  * the seven armed helpers are `bpf_map_lookup_elem .. bpf_ktime_get_ns`, the
    helper ids `1 .. 7` in that ladder order;
  * every other id the simulator names -- `bpf_current_task_under_cgroup`
    (8) .. `bpf_get_current_task` (21) and every id that names no helper at all
    -- falls into the default zero-write arm, because those ids have no
    `X86_SIM_BPF_CALL_bpf_*` body macro.

The generated Lean tables `GeneratedX86HelperDispatch.helperIds` /
`helperNames` / `helperBodies` and the C macros `KPROG_X86_HELPER_SLOT` /
`KPROG_X86_HELPER_COUNT` bind each helper id to the ladder slot the hand-written
ladder dispatches it to. The generated header's
`_Static_assert(X86_SIM_HELPER_bpf_<name> == <id>ULL, ...)` drift checks pin the
helper-id defines to the generated table, and `KProgFormal/X86HelperDispatch.lean`
proves the generated tables equal an independent literal construction, that
`slotOf` names exactly the seven armed helper ids, and that ids `8 .. 21` reach
the default arm.

The generator is independent of the ladder it describes: it holds its own
literal enumeration and re-derives the live `X86_SIM_BPF_CALL_ID` ladder text
from the simulator header, then requires the two to agree.

The generated header is included by `x86_sim_local_bpf.h` after the
`X86_SIM_HELPER_bpf_*` id defines, exactly as the register-dispatch mirror.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "x86_helper_dispatch_spec.json"
HEADER = ROOT.parent / "x86/x86_sim_local_bpf.h"
LEAN = ROOT / "KProgFormal/GeneratedX86HelperDispatch.lean"
CHEADER = ROOT / "generated/x86_helper_dispatch.h"

# The independent enumeration of the seven armed ladder arms, in ladder order:
# (name, helper id, body macro).
_ARMED = [
    ("bpf_map_lookup_elem", 1, "X86_SIM_BPF_CALL_bpf_map_lookup_elem"),
    ("bpf_map_update_elem", 2, "X86_SIM_BPF_CALL_bpf_map_update_elem"),
    ("bpf_map_delete_elem", 3, "X86_SIM_BPF_CALL_bpf_map_delete_elem"),
    ("bpf_get_current_uid_gid", 4, "X86_SIM_BPF_CALL_bpf_get_current_uid_gid"),
    ("bpf_get_current_pid_tgid", 5, "X86_SIM_BPF_CALL_bpf_get_current_pid_tgid"),
    ("bpf_get_smp_processor_id", 6, "X86_SIM_BPF_CALL_bpf_get_smp_processor_id"),
    ("bpf_ktime_get_ns", 7, "X86_SIM_BPF_CALL_bpf_ktime_get_ns"),
]
EXPECTED = {
    "schema_version": 1,
    "operation": "x86HelperDispatch",
    "id_bits": 64,
    "helper_count": len(_ARMED),
    "default_body": "X86_SIM_L_WRITE_REG_WIDTH(X86_RAX, 0, X86_WIDTH_64)",
    "helpers": [{"name": name, "define": "X86_SIM_HELPER_" + name,
                 "id": number, "body": body}
                for name, number, body in _ARMED],
}
COLUMNS = ("name", "define", "id", "body")

# The live helper-id defines, `#define X86_SIM_HELPER_bpf_<name> <n>ULL`, in
# header order (the whole id space the simulator names, armed or not).
HELPER_DEFINE = re.compile(
    r"^#define\s+(X86_SIM_HELPER_bpf_[A-Za-z0-9_]+)\s+([0-9]+)ULL\s*$", re.M)
LADDER_START = "#define X86_SIM_BPF_CALL_ID(ID)"
LADDER_END = "#define X86_SIM_BPF_CALL_REG(REG)"
LADDER_ARM = re.compile(
    r"if\s*\(\s*__x86_helper_id\s*==\s*(X86_SIM_HELPER_bpf_[A-Za-z0-9_]+)\s*\)"
    r"\s*\{\s*(X86_SIM_BPF_CALL_bpf_[A-Za-z0-9_]+)\s*\(\s*\)\s*;")
LADDER_DEFAULT = re.compile(
    r"else\s*\{\s*(X86_SIM_L_WRITE_REG_WIDTH\s*\([^;]*?\))\s*;")


def flat(text):
    """Collapse `\\`-newline continuations so a macro body is one line."""
    return re.sub(r"\\\s*\n", " ", text)


def helper_id_space():
    """The whole named id space as `{name: id}` (armed and unarmed)."""
    return {define[len("X86_SIM_HELPER_"):]: int(number)
            for define, number in HELPER_DEFINE.findall(HEADER.read_text())}


def ladder_region():
    text = HEADER.read_text()
    start = text.index(LADDER_START)
    end = text.index(LADDER_END, start)
    return flat(text[start:end])


def ladder_arms():
    """`[(name, body_macro, id)]` for each armed arm, in ladder order."""
    space = helper_id_space()
    arms = []
    for define, body in LADDER_ARM.findall(ladder_region()):
        name = define[len("X86_SIM_HELPER_"):]
        if name not in space:
            raise SystemExit(f"ladder arm names no helper id: {define}")
        arms.append((name, body, space[name]))
    return arms


def ladder_default():
    matches = LADDER_DEFAULT.findall(ladder_region())
    if len(matches) != 1:
        raise SystemExit(f"expected one ladder default arm, got {matches!r}")
    return re.sub(r"\s+", " ", matches[0]).strip()


def check_against_header():
    """The live ladder must equal the independent enumeration, arm for arm."""
    arms = ladder_arms()
    if [name for name, _b, _i in arms] != [name for name, _i, _b in _ARMED]:
        raise SystemExit(f"ladder arm order disagrees: {arms!r}")
    if [(b, i) for _n, b, i in arms] != [(b, i) for _n, i, b in _ARMED]:
        raise SystemExit(f"ladder arm bodies/dispatch disagree: {arms!r}")
    if ladder_default() != EXPECTED["default_body"]:
        raise SystemExit(
            f"ladder default arm disagrees: {ladder_default()!r}")
    space = helper_id_space()
    for name, number, _body in _ARMED:
        if space.get(name) != number:
            raise SystemExit(
                f"helper id define disagrees for {name}: {space.get(name)!r}")
    unarmed = sorted(set(space) - {name for name, _n, _b in _ARMED})
    if len(unarmed) != len(space) - len(_ARMED):
        raise SystemExit(f"unarmed helper ids are not distinct: {unarmed!r}")
    for name in unarmed:
        body = "X86_SIM_BPF_CALL_" + name
        if body in HEADER.read_text():
            raise SystemExit(f"unarmed helper id has a body macro: {name}")


def load() -> dict:
    data = json.loads(SPEC.read_text())
    if set(data) != set(EXPECTED):
        raise SystemExit(f"invalid x86 helper-dispatch keys: {sorted(data)}")
    if data != EXPECTED:
        raise SystemExit(f"invalid x86 helper-dispatch specification: {data!r}")
    helpers = EXPECTED["helpers"]
    if [row["name"] for row in helpers] != [n for n, _i, _b in _ARMED]:
        raise SystemExit(f"invalid x86 helper-dispatch names: {helpers!r}")
    if [row["id"] for row in helpers] != [i for _n, i, _b in _ARMED]:
        raise SystemExit(f"invalid x86 helper-dispatch ids: {helpers!r}")
    if [row["body"] for row in helpers] != [b for _n, _i, b in _ARMED]:
        raise SystemExit(f"invalid x86 helper-dispatch bodies: {helpers!r}")
    if len(helpers) != EXPECTED["helper_count"]:
        raise SystemExit("x86 helper count disagrees with helper list length")
    check_against_header()
    return EXPECTED


def render_lean(spec: dict) -> str:
    helpers = spec["helpers"]
    bits = spec["id_bits"]
    count = spec["helper_count"]
    ids = ", ".join(str(row["id"]) for row in helpers)
    names = ", ".join(f'"{row["name"]}"' for row in helpers)
    bodies = ", ".join(f'"{row["body"]}"' for row in helpers)
    return f'''-- Generated by generate_x86_helper_dispatch_spec.py from x86_helper_dispatch_spec.json.
import Std
namespace KProgFormal.GeneratedX86HelperDispatch
/-- The number of helper ids the `X86_SIM_BPF_CALL_ID` ladder dispatches to a
body macro (`bpf_map_lookup_elem .. bpf_ktime_get_ns`). -/
def helperCount : Nat := {count}
/-- The width in bits of a decoded BPF helper id. -/
def idBits : Nat := {bits}
/-- The helper id of each armed ladder arm, in `X86_SIM_BPF_CALL_ID` order:
arm `i` dispatches helper id `helperIds[i]`. -/
def helperIds : List Nat := [{ids}]
/-- The helper name of each armed ladder arm, in `X86_SIM_BPF_CALL_ID`
order. -/
def helperNames : List String := [{names}]
/-- The body macro each armed ladder arm invokes, in `X86_SIM_BPF_CALL_ID`
order. -/
def helperBodies : List String := [{bodies}]
/-- The default arm body, run for every helper id the ladder does not arm. -/
def defaultBody : String := "{spec["default_body"]}"
/-- The ladder slot a decoded helper id dispatches to, or `none` when the id
names no armed helper and so reaches the default arm. -/
def slotOf (id : BitVec {bits}) : Option Nat :=
  (helperIds.zip (List.range helperCount)).lookup id.toNat
/-- The helper id a ladder slot dispatches, in `X86_SIM_BPF_CALL_ID` order. -/
def idOfSlot (slot : Nat) : Option Nat := helperIds[slot]?
/-- The helper name a ladder slot dispatches, in `X86_SIM_BPF_CALL_ID`
order. -/
def nameOfSlot (slot : Nat) : Option String := helperNames[slot]?
/-- The ladder slot a helper name dispatches to, in `X86_SIM_BPF_CALL_ID`
order. -/
def slotOfName (name : String) : Option Nat :=
  (helperNames.zip (List.range helperCount)).lookup name
end KProgFormal.GeneratedX86HelperDispatch
'''


def render_c(spec: dict) -> str:
    helpers = spec["helpers"]
    count = spec["helper_count"]
    last = count - 1
    id_drift = "\n".join(
        f'_Static_assert({row["define"]} == {row["id"]}ULL, '
        f'"x86 helper id drift");'
        for row in helpers)
    slot_drift = "\n".join(
        f'_Static_assert(KPROG_X86_HELPER_SLOT({row["define"]}) == {index}U, '
        f'"x86 helper dispatch slot drift");'
        for index, row in enumerate(helpers))
    slot = " : \\\n\t".join(
        f'((__u64)((ID)) == {row["define"]} ? {index}U'
        for index, row in enumerate(helpers))
    closers = ")" * len(helpers)
    return f'''/* Generated by generate_x86_helper_dispatch_spec.py from x86_helper_dispatch_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_X86_HELPER_DISPATCH_H
#define KPROG_FORMAL_GENERATED_X86_HELPER_DISPATCH_H
/*
 * x86-64 helper-id -> helper-body binding: the `X86_SIM_BPF_CALL_ID` ladder
 * dispatches the helper ids `{helpers[0]["id"]} .. {helpers[-1]["id"]}`, in
 * `bpf_map_lookup_elem .. bpf_ktime_get_ns` order, to the body macros
 * `X86_SIM_BPF_CALL_bpf_*`, so the ladder slot index equals `helper id - 1`
 * for exactly those ids. Every other id the simulator names
 * (`bpf_current_task_under_cgroup` (8) .. `bpf_get_current_task` (21)) and
 * every id that names no helper reaches the default zero-write arm.
 * `KProgFormal/X86HelperDispatch.lean` proves the generated `helperIds` /
 * `helperNames` / `helperBodies` tables equal an independent literal
 * construction and that `slotOf` names exactly the armed helper ids.
 * This header is included after the `X86_SIM_HELPER_bpf_*` id defines, so the
 * drift checks bind the hand-written defines to the generated table.
 */
/* The number of helper ids the ladder dispatches to a body macro. */
#define KPROG_X86_HELPER_COUNT {count}U
/* The ladder slot no armed helper id names. */
#define KPROG_X86_HELPER_SLOT_NONE 0xffU
/*
 * The ladder slot a decoded helper id dispatches to, or
 * `KPROG_X86_HELPER_SLOT_NONE` when the id reaches the default arm. The
 * `X86_SIM_BPF_CALL_ID` order makes the slot index `helper id - 1`; evaluated
 * once.
 */
#define KPROG_X86_HELPER_SLOT(ID) \\
\t{slot} : \\
\tKPROG_X86_HELPER_SLOT_NONE{closers}
/* The hand-written helper-id defines must equal the generated table. */
{id_drift}
_Static_assert(KPROG_X86_HELPER_COUNT == {count}U,
\t       "x86 helper dispatch count drift");
/* The generated selector must roll the armed ids up to `0 .. {last}` in the
 * same order as the hand-written ladder arms, and name nothing else. */
{slot_drift}
_Static_assert(KPROG_X86_HELPER_SLOT({helpers[0]["id"] - 1}U) ==
\t       KPROG_X86_HELPER_SLOT_NONE,
\t       "x86 helper dispatch none drift");
#endif
'''


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    spec = load()
    for path, expected in ((LEAN, render_lean(spec)),
                           (CHEADER, render_c(spec))):
        if args.check:
            if not path.is_file() or path.read_text() != expected:
                raise SystemExit(
                    f"generated x86 helper-dispatch contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
