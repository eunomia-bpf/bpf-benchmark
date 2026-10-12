#!/usr/bin/env python3
"""Generate the shared AArch64 helper-ident table contract.

The AArch64 artifact encoder
(`kprog/arm64/micro-prog/generate_micro_sim_proofs.py`) recognizes BPF
helper calls by kernel id: 61 ids cover the helpers the AArch64 simulator
implements. Five sim-header macros forward to another helper (e.g.
`bpf_map_lookup_percpu_elem` runs `bpf_map_lookup_elem`'s body), so the
forwarding pairs are re-read from the sim header on every run rather than
pinned here; the table, the Lean model, and the C header regenerate
together with it. When a program uses a helper subset, the encoder
renumbers the used names into a compact 1-based `ARM64_SIM_C_<name>` slot
in lexicographic order, so a forwarding target's slot is its 1-based
lexicographic rank over the used names; over the full 61-name table that
rank is what the delegate constants pin.

Three outputs share one source:
  * `generated/arm64_helper_idents.h` — the C row table and its
    `_Static_assert`s, plus the delegate-slot constants
  * `KProgFormal/GeneratedArm64HelperIdents.lean` — the Lean table
  * `kprog/arm64/micro-prog/generated_arm64_helper_idents.py` — the
    encoder's `HELPER_IDENTS`
"""

import argparse
import json
import re
from pathlib import Path


ROOT = Path(__file__).resolve().parent
SPEC = ROOT / "arm64_helper_idents_spec.json"
SIM = ROOT.parent / "arm64/arm64_sim_local_bpf.h"
LEAN = ROOT / "KProgFormal/GeneratedArm64HelperIdents.lean"
C_HEADER = ROOT / "generated/arm64_helper_idents.h"
PYTHON = ROOT.parent / "arm64/micro-prog/generated_arm64_helper_idents.py"

# The encoder's 61 helper ids in the specification's id-sorted order, as the
# encoder's `HELPER_IDENTS` table defines them.
EXPECTED: list[tuple[int, str]] = [
    (1, "bpf_map_lookup_elem"),
    (2, "bpf_map_update_elem"),
    (3, "bpf_map_delete_elem"),
    (4, "bpf_probe_read"),
    (5, "bpf_ktime_get_ns"),
    (6, "bpf_trace_printk"),
    (7, "bpf_get_prandom_u32"),
    (8, "bpf_get_smp_processor_id"),
    (9, "bpf_skb_store_bytes"),
    (10, "bpf_l3_csum_replace"),
    (11, "bpf_l4_csum_replace"),
    (12, "bpf_tail_call"),
    (13, "bpf_clone_redirect"),
    (14, "bpf_get_current_pid_tgid"),
    (15, "bpf_get_current_uid_gid"),
    (16, "bpf_get_current_comm"),
    (21, "bpf_skb_set_tunnel_key"),
    (23, "bpf_redirect"),
    (25, "bpf_perf_event_output"),
    (26, "bpf_skb_load_bytes"),
    (27, "bpf_get_stackid"),
    (28, "bpf_csum_diff"),
    (31, "bpf_skb_change_proto"),
    (32, "bpf_skb_change_type"),
    (33, "bpf_skb_under_cgroup"),
    (35, "bpf_get_current_task"),
    (37, "bpf_current_task_under_cgroup"),
    (38, "bpf_skb_change_tail"),
    (39, "bpf_skb_pull_data"),
    (43, "bpf_skb_change_head"),
    (44, "bpf_xdp_adjust_head"),
    (45, "bpf_probe_read_str"),
    (46, "bpf_get_socket_cookie"),
    (50, "bpf_skb_adjust_room"),
    (65, "bpf_xdp_adjust_tail"),
    (67, "bpf_get_stack"),
    (68, "bpf_skb_load_bytes_relative"),
    (69, "bpf_fib_lookup"),
    (80, "bpf_get_current_cgroup_id"),
    (95, "bpf_sk_fullsock"),
    (112, "bpf_probe_read_user"),
    (113, "bpf_probe_read_kernel"),
    (114, "bpf_probe_read_user_str"),
    (115, "bpf_probe_read_kernel_str"),
    (118, "bpf_jiffies64"),
    (122, "bpf_get_netns_cookie"),
    (125, "bpf_ktime_get_boot_ns"),
    (127, "bpf_seq_write"),
    (148, "bpf_copy_from_user"),
    (152, "bpf_redirect_neigh"),
    (158, "bpf_get_current_task_btf"),
    (161, "bpf_ima_inode_hash"),
    (174, "bpf_get_attach_cookie"),
    (175, "bpf_task_pt_regs"),
    (183, "bpf_get_func_arg"),
    (184, "bpf_get_func_ret"),
    (185, "bpf_get_func_arg_cnt"),
    (186, "bpf_get_retval"),
    (191, "bpf_copy_from_user_task"),
    (193, "bpf_ima_file_hash"),
    (195, "bpf_map_lookup_percpu_elem"),
]

# Every `ARM64_SIM_BPF_CALL_<name>(` macro the sim header defines: body and
# forwarding macros alike.
BODY_MACRO = r"^#define\s+ARM64_SIM_BPF_CALL_(\w+)\("
# A forwarding macro: the source macro's definition line and, on the joined
# (continuation-stripped) text, the target macro call its body expands to.
FORWARDING_PAIR = (
    r"^#define\s+ARM64_SIM_BPF_CALL_(\w+)\([^)]*\)\s*"
    r"ARM64_SIM_BPF_CALL_(\w+)\("
)


def load() -> tuple[list[dict[str, object]], list[tuple[int, str, str]]]:
    data = json.loads(SPEC.read_text())
    if set(data) != {"schema_version", "operation", "rows"}:
        raise SystemExit(f"invalid arm64 helper idents spec: {data!r}")
    if data["schema_version"] != 1:
        raise SystemExit(
            f"unsupported arm64 helper idents spec version: "
            f"{data['schema_version']!r}")
    if data["operation"] != "arm64HelperIdents":
        raise SystemExit(
            f"unknown arm64 helper idents operation: {data['operation']!r}")
    rows = data["rows"]
    if len(rows) != len(EXPECTED):
        raise SystemExit(
            f"arm64 helper idents spec has {len(rows)} rows, want {len(EXPECTED)}")
    for row, expected in zip(rows, EXPECTED, strict=True):
        if set(row) != {"id", "name"} or (row["id"], row["name"]) != expected:
            raise SystemExit(f"non-canonical arm64 helper idents row: {row!r}")
    if len({row["id"] for row in rows}) != len(rows):
        raise SystemExit(f"duplicate kernel id in arm64 helper idents spec: {rows!r}")
    if len({row["name"] for row in rows}) != len(rows):
        raise SystemExit(
            f"duplicate helper name in arm64 helper idents spec: {rows!r}")

    sim = SIM.read_text()
    bodies = set(re.findall(BODY_MACRO, sim, re.M))
    names = {str(row["name"]) for row in rows}
    if bodies != names:
        raise SystemExit(
            "sim header helper macros drift from the arm64 helper idents spec: "
            f"sim-only {sorted(bodies - names)}, spec-only {sorted(names - bodies)}")
    joined = sim.replace("\\\n", " ")
    pairs = re.findall(FORWARDING_PAIR, joined, re.M)
    name_to_id = {str(row["name"]): row["id"] for row in rows}
    delegates: list[tuple[int, str, str]] = []
    for source, target in pairs:
        if source not in name_to_id or target not in name_to_id:
            raise SystemExit(
                f"sim header forwards ARM64_SIM_BPF_CALL_{source} to "
                f"ARM64_SIM_BPF_CALL_{target}, which is not in the spec")
        delegates.append((name_to_id[source], source, target))
    delegates.sort(key=lambda delegate: delegate[0])
    return rows, delegates


def render_lean(rows: list[dict[str, object]]) -> str:
    ctors = "\n".join(f"  | {row['name']}" for row in rows)
    id_rows = "\n".join(f"  | .{row['name']} => {row['id']}" for row in rows)
    name_rows = "\n".join(
        f'  | .{row["name"]} => "{row["name"]}"' for row in rows)
    return f'''-- Generated by generate_arm64_helper_idents_spec.py from arm64_helper_idents_spec.json.
import Std
namespace KProgFormal.GeneratedArm64HelperIdents
inductive Helper
{ctors}
  deriving DecidableEq, Repr
def id : Helper -> Nat
{id_rows}
def name : Helper -> String
{name_rows}
end KProgFormal.GeneratedArm64HelperIdents
'''


def render_c(rows: list[dict[str, object]],
             delegates: list[tuple[int, str, str]]) -> str:
    head = "#define KPROG_ARM64_HELPER_ROW(KERNEL_ID)"
    arms = []
    for index, row in enumerate(rows):
        ordinal = index + 1
        prefix = "\t((KERNEL_ID)" if index == 0 else "\t (KERNEL_ID)"
        arms.append(f"{prefix} == {row['id']} ? {ordinal}U :")
    selector = " \\\n".join(arms)
    selector_block = (
        f"{head}{' ' * (84 - len(head))}\\\n"
        f"{selector} \\\n"
        f"\t 0)")
    per_row = "\n".join(
        f"_Static_assert(KPROG_ARM64_HELPER_ROW({row['id']}) == "
        f"{index + 1}U, \"AArch64 helper idents row selection drift\");"
        for index, row in enumerate(rows))
    sorted_names = sorted(str(row["name"]) for row in rows)
    delegate_rows = "\n".join(
        f"#define KPROG_ARM64_HELPER_DELEGATE_{source.upper()} "
        f"{sorted_names.index(target) + 1}U"
        for _source_id, source, target in delegates)
    return f'''/* Generated by generate_arm64_helper_idents_spec.py from arm64_helper_idents_spec.json. */
#ifndef KPROG_FORMAL_GENERATED_ARM64_HELPER_IDENTS_H
#define KPROG_FORMAL_GENERATED_ARM64_HELPER_IDENTS_H
/*
 * The AArch64 artifact encoder's BPF helper-ident table: the {len(rows)} kernel
 * ids the AArch64 simulator recognizes, in id-sorted order.
 * KPROG_ARM64_HELPER_ROW maps a kernel id to its 1-based position in that
 * order, 0 outside. KPROG_ARM64_HELPER_DELEGATE_* pins the 1-based
 * lexicographic rank of a sim-header forwarding target over the full
 * 61-name table: the compact per-program slot the encoder's renumbering
 * assigns the target when a program uses every helper.
 */
#define KPROG_ARM64_HELPER_IDENTS_COUNT {len(rows)}U
#define KPROG_ARM64_HELPER_DELEGATE_COUNT {len(delegates)}U
/*
 * The 1-based position of a kernel id in the id-sorted table. The input is
 * evaluated once; an id outside the table reaches the 0 default.
 */
{selector_block}
_Static_assert(KPROG_ARM64_HELPER_IDENTS_COUNT == {len(rows)}U,
	       "AArch64 helper idents count drift");
_Static_assert(KPROG_ARM64_HELPER_DELEGATE_COUNT == {len(delegates)}U,
	       "AArch64 helper idents delegate count drift");
{per_row}
/* The selector is total: a kernel id past the table reaches the default. */
_Static_assert(KPROG_ARM64_HELPER_ROW(0x100) == 0U,
	       "AArch64 helper idents out-of-range id must reach the default arm");
/* The compact slots the forwarding targets occupy, by source kernel id. */
{delegate_rows}
#endif
'''


def render_python(rows: list[dict[str, object]]) -> str:
    entries = "\n".join(
        f'    {row["id"]}: "{row["name"]}",' for row in rows)
    return f'''# Generated by generate_arm64_helper_idents_spec.py from arm64_helper_idents_spec.json.
HELPER_IDENTS = {{
{entries}
}}
'''


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    rows, delegates = load()
    outputs = (
        (LEAN, render_lean(rows)),
        (C_HEADER, render_c(rows, delegates)),
        (PYTHON, render_python(rows)),
    )
    for path, expected in outputs:
        if args.check:
            if not path.is_file() or path.read_text() != expected:
                raise SystemExit(
                    f"generated AArch64 helper idents contract is stale: {path}")
        else:
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text(expected)


if __name__ == "__main__":
    main()
