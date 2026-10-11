#!/usr/bin/env python3
"""Generate the shared AArch64 stack byte-ladder per-lane activation contract.

The hand-written stack *write* helper of `kprog/arm64/arm64_sim_local_bpf.h`,
`ARM64_SIM_L_STACK_WRITE_TAG`, narrows a resolved access to the byte arena `b[]`
through a little-endian byte ladder: lane 0 is always written, lane 1 at width
`>= 16`, lanes 2-3 at width `>= 32`, lanes 4-7 at width `== 64`. Those four
hand-written width gates recompute the *same* monotone activation the byte
counts already name: an access of `n` bytes writes exactly the lanes `0..n-1`.

The generated table `GeneratedArm64StackWriteLanes` exposes that activation as a
per-width active-lane mask (`1`, `3`, `15`, `255`) and a lane predicate, and the
plain-expression C macro `KPROG_ARM64_STACK_WRITE_LANE_ACTIVE(WIDTH, LANE)`
reads a lane back out of the mask. The activation is the counterpart of the
read-side body selection `KPROG_ARM64_STACK_ARM` and of the memory-side
little-endian ladder `KPROG_ARM64_STORE_BYTES`, over the same four closed width
codes.

The generator is independent of the ladder it describes: it holds its own
literal width/lane enumeration and re-derives the live stack-write helper text
from the simulator header, then requires the helper to gate each lane through
the generated predicate and to keep the byte-lane extraction and the
width-narrowing value.

`KProgFormal/Arm64StackWriteLanesShape.lean` proves the generated activation
equals an independent construction from the literals, and ties the lane set to
the `Arm64ByteLane` extraction, the width codes to the `Arm64Width` contract and
the byte counts to the store-bytes contract.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "arm64_stack_write_lanes_spec.json"
HEADER = ROOT.parent / "arm64/arm64_sim_local_bpf.h"
LEAN = ROOT / "KProgFormal/GeneratedArm64StackWriteLanes.lean"
CHEADER = ROOT / "generated/arm64_stack_write_lanes.h"

# The independent enumeration of the four architectural access widths the byte
# ladder narrows to, in width-code order: (name, ARM64_WIDTH_* code, byte
# count). The byte count is the size of the width's active-lane set.
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
    "operation": "arm64StackWriteLanes",
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

# The live routed stack-write helper text, between the write helper's `#define`
# opcode title and the plain write wrapper that follows it.
STACK_WRITE_START = "#define ARM64_SIM_L_STACK_WRITE_TAG(OFF, WIDTH, VALUE, TAG)"
STACK_WRITE_END = "#define ARM64_SIM_L_STACK_WRITE(OFF, WIDTH, VALUE)"
LANE_PREDICATE = "KPROG_ARM64_STACK_WRITE_LANE_ACTIVE("
BYTE_LANE = "KPROG_ARM64_BYTE_AT("
BYTE_ARENA = "__a64_stack.b["
APPLY_WIDTH = "KPROG_ARM64_APPLY_WIDTH("

# The hand-written per-lane width gates the routed helper must no longer
# contain: the lane-1 and lane-2/3 gate widths. The helper legitimately keeps
# the `== ARM64_WIDTH_64` test inside the slot-tag predicate's argument, so only
# the two `>=` gates (which only the byte ladder carries) are safe needles.
HAND_GATE_16 = "__a64_stw_width >= ARM64_WIDTH_16"
HAND_GATE_32 = "__a64_stw_width >= ARM64_WIDTH_32"


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
    """A routed stack-write helper must gate each byte lane through the
    generated activation predicate and still keep the byte-lane extraction and
    the width-narrowing value; it must not gate by hand."""
    if LANE_PREDICATE not in region:
        raise SystemExit(
            "arm64 stack write helper does not gate its lanes through the "
            "generated activation predicate")
    if BYTE_LANE not in region:
        raise SystemExit(
            "arm64 stack write helper does not keep the byte-lane extraction")
    if BYTE_ARENA not in region:
        raise SystemExit(
            "arm64 stack write helper does not write the byte arena")
    if APPLY_WIDTH not in region:
        raise SystemExit(
            "arm64 stack write helper does not narrow the value to its width")
    if HAND_GATE_16 in region or HAND_GATE_32 in region:
        raise SystemExit(
            "arm64 stack write helper gates its byte lanes by hand instead of "
            "through the generated activation predicate")


def check_against_header():
    """The live stack-write helper must gate its byte lanes through the
    generated activation predicate."""
    check_region(stack_write_region())


def load() -> dict:
    data = json.loads(SPEC.read_text())
    if set(data) != set(EXPECTED):
        raise SystemExit(f"invalid arm64 stack write lanes keys: {sorted(data)}")
    if data != EXPECTED:
        raise SystemExit(
            f"invalid arm64 stack write lanes specification: {data!r}")
    for index, column in enumerate(WIDTH_COLUMNS):
        want = [row[column] for row in EXPECTED["widths"]]
        got = [entry[index] for entry in _WIDTHS] if column != "mask" else [
            _mask(entry[2]) for entry in _WIDTHS]
        if want != got:
            raise SystemExit(f"invalid arm64 stack write lanes width {column}: "
                             f"{EXPECTED['widths']!r}")
    if [row["bytes"] for row in EXPECTED["widths"]] != [1, 2, 4, 8]:
        raise SystemExit(
            f"invalid arm64 stack write lanes counts: {EXPECTED['widths']!r}")
    if [row["mask"] for row in EXPECTED["widths"]] != [1, 3, 15, 255]:
        raise SystemExit(
            f"invalid arm64 stack write lanes masks: {EXPECTED['widths']!r}")
    for index, column in enumerate(LANE_COLUMNS):
        want = [row[column] for row in EXPECTED["lanes"]]
        got = [entry[index] for entry in _LANES]
        if want != got:
            raise SystemExit(f"invalid arm64 stack write lanes lane {column}: "
                             f"{EXPECTED['lanes']!r}")
    if len(EXPECTED["lanes"]) != 8:
        raise SystemExit("arm64 stack write lanes must have exactly 8 lanes")
    for index, column in enumerate(ACTIVATION_COLUMNS):
        want = [row[column] for row in EXPECTED["activation"]]
        got = ([entry[0] for entry in _WIDTHS] if column == "name"
               else [_active(entry[2]) for entry in _WIDTHS])
        if want != got:
            raise SystemExit(
                f"invalid arm64 stack write lanes activation {column}: "
                f"{EXPECTED['activation']!r}")
    for row, (_name, _code, bytes_count) in zip(EXPECTED["activation"],
                                                _WIDTHS):
        if len(row["active"]) != len(_LANES):
            raise SystemExit(
                f"invalid arm64 stack write lanes activation width: {row!r}")
        if row["active"] != [index < bytes_count for _n, index in _LANES]:
            raise SystemExit(
                f"invalid arm64 stack write lanes activation: {row!r}")
    if [sum(row["active"]) for row in EXPECTED["activation"]] != [1, 2, 4, 8]:
        raise SystemExit(
            f"invalid arm64 stack write lanes activation size: "
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
    return f'''-- Generated by generate_arm64_stack_write_lanes_spec.py from arm64_stack_write_lanes_spec.json.
import Std
namespace KProgFormal.GeneratedArm64StackWriteLanes
/-- The four architectural access widths the stack byte ladder narrows to,
carrying their `ARM64_WIDTH_*` code, their byte count and their active-lane
mask. -/
inductive Width where
{chr(10).join(f"  | {row['name']}" for row in widths)}
deriving DecidableEq, Repr
/-- The ARM64_WIDTH_* code of the access width. -/
def widthCode : Width -> Nat
{codes}
/-- The number of bytes a stack access of the width writes: the size of the
width's active-lane set. -/
def byteCount : Width -> Nat
{counts}
/-- The width's active-lane mask: bit `k` set exactly when lane `k` is written.
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
/-- Whether a stack access of the width writes the lane: bit `laneIndex` of the
width's active-lane mask. -/
def laneActive (width : Width) (lane : Lane) : Bool :=
  decide ((widthMask width >>> laneIndex lane) &&& 1 = 1)
/-- The lanes a stack access of the width writes, in lane order. -/
def activeLanes (width : Width) : List Lane :=
  [{lane_list}].filter (laneActive width)
/-- Independent statement of the activation: a lane is written exactly when its
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
end KProgFormal.GeneratedArm64StackWriteLanes
'''


def render_c(spec: dict) -> str:
    widths = spec["widths"]
    lanes = spec["lanes"]
    codes = "\n".join(
        f"_Static_assert(ARM64_WIDTH_{row['name'][1:]} == "
        f"{row['width_code']}U, "
        f'"arm64 stack write lanes width code drift");'
        for row in widths)
    mask_lines = [
        f"((WIDTH) == ARM64_WIDTH_{row['name'][1:]} ? "
        f"0x{row['mask']:02x}U :"
        for row in widths[:-1]]
    masks = (" \\\n\t".join(mask_lines)
             + f" \\\n\t 0x{widths[-1]['mask']:02x}U)))")
    lane_defines = "\n".join(
        f'#define KPROG_ARM64_STACK_WRITE_{row["name"].upper()} '
        f'{row["lane_index"]}U' for row in lanes)
    asserts = []
    for row in widths:
        name = row["name"]
        asserts.append(
            f"_Static_assert(KPROG_ARM64_STACK_WRITE_MASK(ARM64_WIDTH_"
            f"{name[1:]}) == 0x{row['mask']:02x}U,\n"
            f'\t       "arm64 stack write lanes mask drift");')
        asserts.append(
            f"_Static_assert(KPROG_ARM64_STACK_WRITE_LANE_COUNT(ARM64_WIDTH_"
            f"{name[1:]}) == {row['bytes']}U,\n"
            f'\t       "arm64 stack write lanes count drift");')
    for row in spec["activation"]:
        name = row["name"]
        for lane, active in zip(lanes, row["active"]):
            asserts.append(
                "_Static_assert(KPROG_ARM64_STACK_WRITE_LANE_ACTIVE("
                f"ARM64_WIDTH_{name[1:]}, {lane['lane_index']}) == "
                f"{1 if active else 0}U,\n"
                f'\t       "arm64 stack write lanes activation drift");')
    asserts = "\n".join(asserts)
    return f'''/* Generated by generate_arm64_stack_write_lanes_spec.py from arm64_stack_write_lanes_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_ARM64_STACK_WRITE_LANES_H
#define KPROG_FORMAL_GENERATED_ARM64_STACK_WRITE_LANES_H
/*
 * AArch64 stack byte-ladder per-lane activation contract: the stack write
 * helper `ARM64_SIM_L_STACK_WRITE_TAG` narrows a resolved access to the byte
 * arena `b[]` through a little-endian byte ladder. The width set is closed (the
 * four ARM64_WIDTH_* codes) and the activation is monotone: an access of `n`
 * bytes writes exactly the lanes `0..n-1`, so the width's active-lane mask has
 * its low `n` bits set (`1`, `3`, `15`, `255`). This is the counterpart of the
 * read-side body selection (`KPROG_ARM64_STACK_ARM`) and of the memory-side
 * ladder (`KPROG_ARM64_STORE_BYTES`).
 * `KProgFormal/Arm64StackWriteLanesShape.lean` proves the generated activation
 * equal to an independent construction from the literals, tied to the
 * `Arm64ByteLane` extraction, the `Arm64Width` codes and the store-bytes
 * contract.
 * This header is included after the `ARM64_WIDTH_*` decodes and the
 * `arm64_byte_lane.h` extraction, so the drift checks bind the hand-written
 * width codes to the generated activation table.
 */
/* The eight byte lanes of a 64-bit stack slot, in lane order. */
{lane_defines}
/* The number of byte lanes the helper can write. */
#define KPROG_ARM64_STACK_WRITE_LANE_SLOTS 8U
/* The width's active-lane mask: bit `k` set exactly when lane `k` is written. */
#define KPROG_ARM64_STACK_WRITE_MASK(WIDTH)                                 \\
\t{masks}
/* The number of byte lanes the width writes: the mask's set-bit count. */
#define KPROG_ARM64_STACK_WRITE_LANE_COUNT(WIDTH)                           \\
\t((WIDTH) == ARM64_WIDTH_8 ? 1U :                                  \\
\t ((WIDTH) == ARM64_WIDTH_16 ? 2U :                                 \\
\t  ((WIDTH) == ARM64_WIDTH_32 ? 4U : 8U)))
/*
 * Whether a stack access of WIDTH writes LANE: bit LANE of the width's
 * active-lane mask. WIDTH must be a side-effect-free expression (the mask
 * compares it against each width code); LANE is read once and no NZCV is
 * written.
 */
#define KPROG_ARM64_STACK_WRITE_LANE_ACTIVE(WIDTH, LANE)                    \
	((__u8)((KPROG_ARM64_STACK_WRITE_MASK(WIDTH) >> (LANE)) & 1U))
{codes}
_Static_assert(KPROG_ARM64_STACK_WRITE_LANE_SLOTS == 8U,
\t       "arm64 stack write lanes slot count drift");
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
                    f"generated arm64 stack write lanes contract is stale: "
                    f"{path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
