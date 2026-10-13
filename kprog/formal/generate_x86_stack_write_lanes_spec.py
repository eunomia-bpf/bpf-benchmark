#!/usr/bin/env python3
"""Generate the shared x86-64 stack byte-ladder per-lane activation contract.

The hand-written stack helpers of `kprog/x86/x86_sim_local_bpf.h`,
`X86_SIM_L_STACK_WRITE` and `X86_SIM_L_STACK_READ`, narrow a resolved access to
the byte arena `b[]` through a little-endian byte ladder: lane 0 is always
touched, lane 1 at width `>= 16`, lanes 2-3 at width `>= 32`, lanes 4-7 at width
`== 64`. Those four hand-written width gates recompute the *same* monotone
activation the byte counts already name: an access of `n` bytes touches exactly
the lanes `0..n-1`. The write ladder carries the gates as nested `>=`/`==` blocks
and the read ladder as the same nested gates assembling each lane back.

The generated table `GeneratedX86StackWriteLanes` exposes that activation as a
per-width active-lane mask (`1`, `3`, `15`, `255`) and a lane predicate, and the
plain-expression C macro `KPROG_X86_STACK_WRITE_LANE_ACTIVE(WIDTH, LANE)` reads a
lane back out of the mask. The activation is the counterpart of the read-side
body selection `KPROG_X86_STACK_ARM` and of the memory-side little-endian ladder
`KPROG_X86_STORE_BYTES`, over the same four closed width codes. The single
predicate is routed through *both* the write and the read ladder, so one contract
covers the whole byte arena access.

The generator is independent of the ladder it describes: it holds its own
literal width/lane enumeration and re-derives the live stack helper text from the
simulator header, then requires both helpers to gate each lane through the
generated predicate and to keep the byte-lane extraction, the byte-arena access,
the width-narrowing value and the little-endian assembly.

`KProgFormal/X86StackWriteLanesShape.lean` proves the generated activation equals
an independent construction from the literals, and ties the lane set to the
`GeneratedX86StackArena` byte extraction, the width codes to the `X86Width`
contract and the byte counts to the memory-access contract.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "x86_stack_write_lanes_spec.json"
HEADER = ROOT.parent / "x86/x86_sim_local_bpf.h"
LEAN = ROOT / "KProgFormal/GeneratedX86StackWriteLanes.lean"
CHEADER = ROOT / "generated/x86_stack_write_lanes.h"

# The independent enumeration of the four architectural access widths the byte
# ladder narrows to, in width-code order: (name, X86_WIDTH_* code, byte count).
# The byte count is the size of the width's active-lane set.
_WIDTHS = [
    ("w8", 1, 1),
    ("w16", 2, 2),
    ("w32", 4, 4),
    ("w64", 8, 8),
]
# The independent enumeration of the eight byte lanes of a 64-bit stack slot, in
# lane order: (name, lane number).
_LANES = [
    ("lane0", 0),
    ("lane1", 1),
    ("lane2", 2),
    ("lane3", 3),
    ("lane4", 4),
    ("lane5", 5),
    ("lane6", 6),
    ("lane7", 7),
]
# The active-lane set of a width is monotone: exactly the lanes below its byte
# count, so the mask's low `bytes` bits are set.
def _mask(bytes_count: int) -> int:
    return (1 << bytes_count) - 1


def _active(bytes_count: int) -> list:
    return [index < bytes_count for _name, index in _LANES]


EXPECTED = {
    "schema_version": 1,
    "operation": "x86StackWriteLanes",
    "selector": "width_mask_low_lanes_active",
    "widths": [{"name": name, "width_code": code, "bytes": bytes_count,
                "mask": _mask(bytes_count)}
               for name, code, bytes_count in _WIDTHS],
    "lanes": [{"name": name, "lane_index": index} for name, index in _LANES],
    "activation": [{"name": name, "active": _active(bytes_count)}
                   for name, _code, bytes_count in _WIDTHS],
}
WIDTH_COLUMNS = ("name", "width_code", "bytes", "mask")
LANE_COLUMNS = ("name", "lane_index")
ACTIVATION_COLUMNS = ("name", "active")

# The live routed stack helpers text, between the write helper's `#define`
# opcode title and the plain stack-pointer wrapper that follows the read helper.
STACK_WRITE_START = "#define X86_SIM_L_STACK_WRITE(OFF, WIDTH, VALUE)"
STACK_WRITE_END = "#define X86_SIM_L_STACK_PTR(OFF)"
LANE_PREDICATE = "KPROG_X86_STACK_WRITE_LANE_ACTIVE("
BYTE_LANE = "KPROG_X86_STACK_BYTE("
BYTE_ARENA = "__x86_stack_mem.b["
APPLY_WIDTH = "x86_width_mask("
READ_ASSEMBLE = "KPROG_X86_STACK_ASSEMBLE("

# The hand-written per-lane width gates the routed helpers must no longer
# contain: the write ladder's lane-1 and lane-2/3 gate widths, the read ladder's
# same two gates, and the two `== X86_WIDTH_64` gate widths only the ladders
# carry (the arm selector spells its 64-bit test through the resolved width, so
# these are safe needles).
HAND_GATE_16 = "__x86_stw_width >= X86_WIDTH_16"
HAND_GATE_32 = "__x86_stw_width >= X86_WIDTH_32"
HAND_GATE_STR_16 = "__x86_str_width >= X86_WIDTH_16"
HAND_GATE_STR_32 = "__x86_str_width >= X86_WIDTH_32"
HAND_GATE_64 = "__x86_stw_width == X86_WIDTH_64"
HAND_GATE_STR_64 = "__x86_str_width == X86_WIDTH_64"


def flat(text):
    """Collapse `\\`-newline continuations so a macro body is one line."""
    return re.sub(r"\\\s*\n", " ", text)


def region_between(start_marker, end_marker):
    text = HEADER.read_text()
    start = text.index(start_marker)
    end = text.index(end_marker, start)
    return re.sub(r"\s+", " ", flat(text[start:end]))


def stack_write_region():
    return region_between(STACK_WRITE_START, STACK_WRITE_END)


def check_region(region):
    """A routed stack helper pair must gate each byte lane through the generated
    activation predicate and still keep the byte-lane extraction, the byte-arena
    access, the width-narrowing value and the little-endian assembly; it must not
    gate by hand."""
    if LANE_PREDICATE not in region:
        raise SystemExit(
            "x86 stack ladder does not gate its lanes through the "
            "generated activation predicate")
    if BYTE_LANE not in region:
        raise SystemExit(
            "x86 stack write ladder does not keep the byte-lane extraction")
    if BYTE_ARENA not in region:
        raise SystemExit(
            "x86 stack ladder does not access the byte arena")
    if APPLY_WIDTH not in region:
        raise SystemExit(
            "x86 stack write ladder does not narrow the value to its width")
    if READ_ASSEMBLE not in region:
        raise SystemExit(
            "x86 stack read ladder does not assemble the byte lanes")
    if (HAND_GATE_16 in region or HAND_GATE_32 in region or
            HAND_GATE_STR_16 in region or HAND_GATE_STR_32 in region or
            HAND_GATE_64 in region or HAND_GATE_STR_64 in region):
        raise SystemExit(
            "x86 stack ladder gates its byte lanes by hand instead of "
            "through the generated activation predicate")


def check_against_header():
    """The live stack helper pair must gate its byte lanes through the generated
    activation predicate."""
    check_region(stack_write_region())


def load() -> dict:
    data = json.loads(SPEC.read_text())
    if set(data) != set(EXPECTED):
        raise SystemExit(f"invalid x86 stack write lanes keys: {sorted(data)}")
    if data != EXPECTED:
        raise SystemExit(
            f"invalid x86 stack write lanes specification: {data!r}")
    for index, column in enumerate(WIDTH_COLUMNS):
        want = [row[column] for row in EXPECTED["widths"]]
        got = [entry[index] for entry in _WIDTHS] if column != "mask" else [
            _mask(entry[2]) for entry in _WIDTHS]
        if want != got:
            raise SystemExit(f"invalid x86 stack write lanes width {column}: "
                             f"{EXPECTED['widths']!r}")
    if [row["bytes"] for row in EXPECTED["widths"]] != [1, 2, 4, 8]:
        raise SystemExit(
            f"invalid x86 stack write lanes counts: {EXPECTED['widths']!r}")
    if [row["mask"] for row in EXPECTED["widths"]] != [1, 3, 15, 255]:
        raise SystemExit(
            f"invalid x86 stack write lanes masks: {EXPECTED['widths']!r}")
    for index, column in enumerate(LANE_COLUMNS):
        want = [row[column] for row in EXPECTED["lanes"]]
        got = [entry[index] for entry in _LANES]
        if want != got:
            raise SystemExit(f"invalid x86 stack write lanes lane {column}: "
                             f"{EXPECTED['lanes']!r}")
    if len(EXPECTED["lanes"]) != 8:
        raise SystemExit("x86 stack write lanes must have exactly 8 lanes")
    for index, column in enumerate(ACTIVATION_COLUMNS):
        want = [row[column] for row in EXPECTED["activation"]]
        got = ([entry[0] for entry in _WIDTHS] if column == "name"
               else [_active(entry[2]) for entry in _WIDTHS])
        if want != got:
            raise SystemExit(
                f"invalid x86 stack write lanes activation {column}: "
                f"{EXPECTED['activation']!r}")
    for row, (_name, _code, bytes_count) in zip(EXPECTED["activation"],
                                                _WIDTHS):
        if len(row["active"]) != len(_LANES):
            raise SystemExit(
                f"invalid x86 stack write lanes activation width: {row!r}")
        if row["active"] != [index < bytes_count for _n, index in _LANES]:
            raise SystemExit(
                f"invalid x86 stack write lanes activation: {row!r}")
    if [sum(row["active"]) for row in EXPECTED["activation"]] != [1, 2, 4, 8]:
        raise SystemExit(
            f"invalid x86 stack write lanes activation size: "
            f"{EXPECTED['activation']!r}")
    check_against_header()
    return EXPECTED


def render_lean(spec: dict) -> str:
    widths = spec["widths"]
    lanes = spec["lanes"]
    codes = "\n".join(
        f"  | .{row['name']} => {row['width_code']}" for row in widths)
    counts = "\n".join(
        f"  | .{row['name']} => {row['bytes']}" for row in widths)
    masks = "\n".join(
        f"  | .{row['name']} => {row['mask']}" for row in widths)
    lane_index = "\n".join(
        f"  | .{row['name']} => {row['lane_index']}" for row in lanes)
    lane_list = ", ".join(f".{row['name']}" for row in lanes)
    return f'''-- Generated by generate_x86_stack_write_lanes_spec.py from x86_stack_write_lanes_spec.json.
import Std
namespace KProgFormal.GeneratedX86StackWriteLanes
/-- The four architectural access widths the stack byte ladder narrows to,
carrying their `X86_WIDTH_*` code, their byte count and their active-lane
mask. -/
inductive Width where
{chr(10).join(f"  | {row['name']}" for row in widths)}
deriving DecidableEq, Repr
/-- The X86_WIDTH_* code of the access width. -/
def widthCode : Width -> Nat
{codes}
/-- The number of bytes a stack access of the width touches: the size of the
width's active-lane set. -/
def byteCount : Width -> Nat
{counts}
/-- The width's active-lane mask: bit `k` set exactly when lane `k` is touched.
The mask's low `byteCount` bits are set and every higher bit is clear. -/
def widthMask : Width -> Nat
{masks}
/-- The eight byte lanes of a 64-bit stack slot. -/
inductive Lane where
{chr(10).join(f"  | {row['name']}" for row in lanes)}
deriving DecidableEq, Repr
/-- The lane number `0..7`. -/
def laneIndex : Lane -> Nat
{lane_index}
/-- Whether a stack access of the width touches the lane: bit `laneIndex` of the
width's active-lane mask. -/
def laneActive (width : Width) (lane : Lane) : Bool :=
  decide ((widthMask width >>> laneIndex lane) &&& 1 = 1)
/-- The lanes a stack access of the width touches, in lane order. -/
def activeLanes (width : Width) : List Lane :=
  [{lane_list}].filter (laneActive width)
/-- Independent statement of the activation: a lane is touched exactly when its
index is below the width's byte count. -/
def laneSpec (width : Width) (lane : Lane) : Bool :=
  decide (laneIndex lane < byteCount width)
/-- The mask-bit activation agrees with the byte-count bound for every width and
lane: the mask's low `byteCount` bits are set and every higher bit is clear. -/
theorem laneActive_refines (width : Width) (lane : Lane) :
    laneActive width lane = laneSpec width lane := by
  cases width <;> cases lane <;> decide
/-- The active-lane set has exactly the width's byte count. -/
theorem activeLanes_length (width : Width) :
    (activeLanes width).length = byteCount width := by
  cases width <;> decide
/-- The mask is the width's low `byteCount` bits set. -/
theorem widthMask_is_low_bits (width : Width) :
    widthMask width = 2 ^ byteCount width - 1 := by
  cases width <;> decide
end KProgFormal.GeneratedX86StackWriteLanes
'''


def render_c(spec: dict) -> str:
    widths = spec["widths"]
    lanes = spec["lanes"]
    codes = "\n".join(
        f"_Static_assert(X86_WIDTH_{row['name'][1:]} == "
        f"{row['width_code']}U, "
        f'"x86 stack write lanes width code drift");'
        for row in widths)
    mask_lines = [
        f"((WIDTH) == X86_WIDTH_{row['name'][1:]} ? "
        f"0x{row['mask']:02x}U :"
        for row in widths[:-1]]
    masks = (" \\\n\t".join(mask_lines)
             + f" \\\n\t 0x{widths[-1]['mask']:02x}U)))")
    lane_defines = "\n".join(
        f'#define KPROG_X86_STACK_WRITE_{row["name"].upper()} '
        f'{row["lane_index"]}U' for row in lanes)
    asserts = []
    for row in widths:
        name = row["name"]
        asserts.append(
            f"_Static_assert(KPROG_X86_STACK_WRITE_MASK(X86_WIDTH_"
            f"{name[1:]}) == 0x{row['mask']:02x}U,\n"
            f'\t       "x86 stack write lanes mask drift");')
        asserts.append(
            f"_Static_assert(KPROG_X86_STACK_WRITE_LANE_COUNT(X86_WIDTH_"
            f"{name[1:]}) == {row['bytes']}U,\n"
            f'\t       "x86 stack write lanes count drift");')
    for row in spec["activation"]:
        name = row["name"]
        for lane, active in zip(lanes, row["active"]):
            asserts.append(
                "_Static_assert(KPROG_X86_STACK_WRITE_LANE_ACTIVE("
                f"X86_WIDTH_{name[1:]}, {lane['lane_index']}) == "
                f"{1 if active else 0}U,\n"
                f'\t       "x86 stack write lanes activation drift");')
    asserts = "\n".join(asserts)
    return f'''/* Generated by generate_x86_stack_write_lanes_spec.py from x86_stack_write_lanes_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_X86_STACK_WRITE_LANES_H
#define KPROG_FORMAL_GENERATED_X86_STACK_WRITE_LANES_H
/*
 * x86-64 stack byte-ladder per-lane activation contract: the stack helpers
 * `X86_SIM_L_STACK_WRITE` and `X86_SIM_L_STACK_READ` narrow a resolved access to
 * the byte arena `b[]` through a little-endian byte ladder. The width set is
 * closed (the four X86_WIDTH_* codes) and the activation is monotone: an access
 * of `n` bytes touches exactly the lanes `0..n-1`, so the width's active-lane
 * mask has its low `n` bits set (`1`, `3`, `15`, `255`). This is the counterpart
 * of the read-side body selection (`KPROG_X86_STACK_ARM`) and of the
 * memory-side ladder (`KPROG_X86_STORE_BYTES`). The one predicate is routed
 * through both the write and the read ladder.
 * `KProgFormal/X86StackWriteLanesShape.lean` proves the generated activation
 * equal to an independent construction from the literals, tied to the
 * `GeneratedX86StackArena` byte extraction, the `X86Width` codes and the
 * memory-access contract.
 * This header is included after the `X86_WIDTH_*` decodes and the
 * `x86_stack_arena.h` extraction, so the drift checks bind the hand-written
 * width codes to the generated activation table.
 */
/* The eight byte lanes of a 64-bit stack slot, in lane order. */
{lane_defines}
/* The number of byte lanes the helpers can touch. */
#define KPROG_X86_STACK_WRITE_LANE_SLOTS 8U
/* The width's active-lane mask: bit `k` set exactly when lane `k` is touched. */
#define KPROG_X86_STACK_WRITE_MASK(WIDTH)                                   \\
\t{masks}
/* The number of byte lanes the width touches: the mask's set-bit count. */
#define KPROG_X86_STACK_WRITE_LANE_COUNT(WIDTH)                             \\
\t((WIDTH) == X86_WIDTH_8 ? 1U :                                    \\
\t ((WIDTH) == X86_WIDTH_16 ? 2U :                                   \\
\t  ((WIDTH) == X86_WIDTH_32 ? 4U : 8U)))
/*
 * Whether a stack access of WIDTH touches LANE: bit LANE of the width's
 * active-lane mask. WIDTH must be a side-effect-free expression (the mask
 * compares it against each width code); LANE is read once and no flags are
 * written.
 */
#define KPROG_X86_STACK_WRITE_LANE_ACTIVE(WIDTH, LANE)                      \\
\t((__u8)((KPROG_X86_STACK_WRITE_MASK(WIDTH) >> (LANE)) & 1U))
{codes}
_Static_assert(KPROG_X86_STACK_WRITE_LANE_SLOTS == 8U,
\t       "x86 stack write lanes slot count drift");
/* The mask must name each width's active-lane set and its size. */
{asserts}
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
                    f"generated x86 stack write lanes contract is stale: "
                    f"{path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
