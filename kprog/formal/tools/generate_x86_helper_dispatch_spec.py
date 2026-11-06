#!/usr/bin/env python3
"""Generate the sparse Linux helper-ID/body dispatch contract.

IDs are independently checked against vendored libbpf's public declarations;
the live production ladder must match every armed row and the compile-error
default. Unarmed helpers never produce a synthetic return value.
"""
import argparse
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SPEC = ROOT / "contracts/x86_helper_dispatch_spec.json"
HEADER = ROOT.parent / "x86/x86_sim_local_bpf.h"
LEAN = ROOT / "KProgFormal/Generated/GeneratedX86HelperDispatch.lean"
CHEADER = ROOT / "generated/x86_helper_dispatch.h"

# Linux helper identities in numeric order, independent of the production ladder.
_ARMED = [
    ('bpf_map_lookup_elem', 1, 'X86_SIM_BPF_CALL_bpf_map_lookup_elem'),
    ('bpf_map_update_elem', 2, 'X86_SIM_BPF_CALL_bpf_map_update_elem'),
    ('bpf_map_delete_elem', 3, 'X86_SIM_BPF_CALL_bpf_map_delete_elem'),
    ('bpf_probe_read', 4, 'X86_SIM_BPF_CALL_bpf_probe_read'),
    ('bpf_ktime_get_ns', 5, 'X86_SIM_BPF_CALL_bpf_ktime_get_ns'),
    ('bpf_trace_printk', 6, 'X86_SIM_BPF_CALL_bpf_trace_printk'),
    ('bpf_get_prandom_u32', 7, 'X86_SIM_BPF_CALL_bpf_get_prandom_u32'),
    ('bpf_get_smp_processor_id', 8, 'X86_SIM_BPF_CALL_bpf_get_smp_processor_id'),
    ('bpf_skb_store_bytes', 9, 'X86_SIM_BPF_CALL_bpf_skb_store_bytes'),
    ('bpf_l3_csum_replace', 10, 'X86_SIM_BPF_CALL_bpf_l3_csum_replace'),
    ('bpf_l4_csum_replace', 11, 'X86_SIM_BPF_CALL_bpf_l4_csum_replace'),
    ('bpf_tail_call', 12, 'X86_SIM_BPF_CALL_bpf_tail_call'),
    ('bpf_get_current_pid_tgid', 14, 'X86_SIM_BPF_CALL_bpf_get_current_pid_tgid'),
    ('bpf_get_current_uid_gid', 15, 'X86_SIM_BPF_CALL_bpf_get_current_uid_gid'),
    ('bpf_get_current_comm', 16, 'X86_SIM_BPF_CALL_bpf_get_current_comm'),
    ('bpf_skb_get_tunnel_key', 20, 'X86_SIM_BPF_CALL_bpf_skb_get_tunnel_key'),
    ('bpf_skb_set_tunnel_key', 21, 'X86_SIM_BPF_CALL_bpf_skb_set_tunnel_key'),
    ('bpf_redirect', 23, 'X86_SIM_BPF_CALL_bpf_redirect'),
    ('bpf_perf_event_output', 25, 'X86_SIM_BPF_CALL_bpf_perf_event_output'),
    ('bpf_skb_load_bytes', 26, 'X86_SIM_BPF_CALL_bpf_skb_load_bytes'),
    ('bpf_get_stackid', 27, 'X86_SIM_BPF_CALL_bpf_get_stackid'),
    ('bpf_csum_diff', 28, 'X86_SIM_BPF_CALL_bpf_csum_diff'),
    ('bpf_skb_change_type', 32, 'X86_SIM_BPF_CALL_bpf_skb_change_type'),
    ('bpf_get_current_task', 35, 'X86_SIM_BPF_CALL_bpf_get_current_task'),
    ('bpf_probe_write_user', 36, 'X86_SIM_BPF_CALL_bpf_probe_write_user'),
    ('bpf_current_task_under_cgroup', 37, 'X86_SIM_BPF_CALL_bpf_current_task_under_cgroup'),
    ('bpf_skb_change_tail', 38, 'X86_SIM_BPF_CALL_bpf_skb_change_tail'),
    ('bpf_skb_pull_data', 39, 'X86_SIM_BPF_CALL_bpf_skb_pull_data'),
    ('bpf_skb_change_head', 43, 'X86_SIM_BPF_CALL_bpf_skb_change_head'),
    ('bpf_xdp_adjust_head', 44, 'X86_SIM_BPF_CALL_bpf_xdp_adjust_head'),
    ('bpf_probe_read_str', 45, 'X86_SIM_BPF_CALL_bpf_probe_read_str'),
    ('bpf_get_socket_cookie', 46, 'X86_SIM_BPF_CALL_bpf_get_socket_cookie'),
    ('bpf_skb_adjust_room', 50, 'X86_SIM_BPF_CALL_bpf_skb_adjust_room'),
    ('bpf_xdp_adjust_meta', 54, 'X86_SIM_BPF_CALL_bpf_xdp_adjust_meta'),
    ('bpf_override_return', 58, 'X86_SIM_BPF_CALL_bpf_override_return'),
    ('bpf_xdp_adjust_tail', 65, 'X86_SIM_BPF_CALL_bpf_xdp_adjust_tail'),
    ('bpf_get_stack', 67, 'X86_SIM_BPF_CALL_bpf_get_stack'),
    ('bpf_skb_load_bytes_relative', 68, 'X86_SIM_BPF_CALL_bpf_skb_load_bytes_relative'),
    ('bpf_fib_lookup', 69, 'X86_SIM_BPF_CALL_bpf_fib_lookup'),
    ('bpf_get_current_cgroup_id', 80, 'X86_SIM_BPF_CALL_bpf_get_current_cgroup_id'),
    ('bpf_sk_lookup_udp', 85, 'X86_SIM_BPF_CALL_bpf_sk_lookup_udp'),
    ('bpf_sk_release', 86, 'X86_SIM_BPF_CALL_bpf_sk_release'),
    ('bpf_map_push_elem', 87, 'X86_SIM_BPF_CALL_bpf_map_push_elem'),
    ('bpf_map_pop_elem', 88, 'X86_SIM_BPF_CALL_bpf_map_pop_elem'),
    ('bpf_sk_fullsock', 95, 'X86_SIM_BPF_CALL_bpf_sk_fullsock'),
    ('bpf_skc_lookup_tcp', 99, 'X86_SIM_BPF_CALL_bpf_skc_lookup_tcp'),
    ('bpf_send_signal', 109, 'X86_SIM_BPF_CALL_bpf_send_signal'),
    ('bpf_probe_read_user', 112, 'X86_SIM_BPF_CALL_bpf_probe_read_user'),
    ('bpf_probe_read_kernel', 113, 'X86_SIM_BPF_CALL_bpf_probe_read_kernel'),
    ('bpf_probe_read_user_str', 114, 'X86_SIM_BPF_CALL_bpf_probe_read_user_str'),
    ('bpf_probe_read_kernel_str', 115, 'X86_SIM_BPF_CALL_bpf_probe_read_kernel_str'),
    ('bpf_jiffies64', 118, 'X86_SIM_BPF_CALL_bpf_jiffies64'),
    ('bpf_get_netns_cookie', 122, 'X86_SIM_BPF_CALL_bpf_get_netns_cookie'),
    ('bpf_sk_assign', 124, 'X86_SIM_BPF_CALL_bpf_sk_assign'),
    ('bpf_ktime_get_boot_ns', 125, 'X86_SIM_BPF_CALL_bpf_ktime_get_boot_ns'),
    ('bpf_ringbuf_output', 130, 'X86_SIM_BPF_CALL_bpf_ringbuf_output'),
    ('bpf_copy_from_user', 148, 'X86_SIM_BPF_CALL_bpf_copy_from_user'),
    ('bpf_redirect_neigh', 152, 'X86_SIM_BPF_CALL_bpf_redirect_neigh'),
    ('bpf_redirect_peer', 155, 'X86_SIM_BPF_CALL_bpf_redirect_peer'),
    ('bpf_get_current_task_btf', 158, 'X86_SIM_BPF_CALL_bpf_get_current_task_btf'),
    ('bpf_get_attach_cookie', 174, 'X86_SIM_BPF_CALL_bpf_get_attach_cookie'),
    ('bpf_task_pt_regs', 175, 'X86_SIM_BPF_CALL_bpf_task_pt_regs'),
    ('bpf_loop', 181, 'X86_SIM_BPF_CALL_bpf_loop'),
    ('bpf_get_func_ret', 184, 'X86_SIM_BPF_CALL_bpf_get_func_ret'),
    ('bpf_ima_file_hash', 193, 'X86_SIM_BPF_CALL_bpf_ima_file_hash'),
]
EXPECTED = {
    "schema_version": 1,
    "operation": "x86HelperDispatch",
    "id_bits": 64,
    "helper_count": len(_ARMED),
    "default_body": "X86_SIM_L_UNSUPPORTED_HELPER()",
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
# The routed ladder switches on the generated slot selector; each armed arm is
# a `case KPROG_X86_HELPER_SLOT(<id define>):` invoking its body macro.
LADDER_SLOT = re.compile(
    r"switch\s*\(\s*KPROG_X86_HELPER_SLOT\(\s*\(\s*__u64\s*\)\s*\(\s*ID\s*\)"
    r"\s*\)\s*\)")
LADDER_ARM = re.compile(
    r"case\s+KPROG_X86_HELPER_SLOT\(\s*(X86_SIM_HELPER_bpf_[A-Za-z0-9_]+)\s*\)"
    r"\s*:\s*(X86_SIM_BPF_CALL_bpf_[A-Za-z0-9_]+)\s*\(\s*\)\s*;")
LADDER_DEFAULT = re.compile(
    r"default\s*:\s*(X86_SIM_L_UNSUPPORTED_HELPER\s*\(\s*\))\s*;")
# The hand-written inline id comparisons the routed ladder replaces.
LADDER_HAND_TEST = re.compile(
    r"__x86_helper_id\s*==\s*X86_SIM_HELPER_bpf_")


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
    region = ladder_region()
    if not LADDER_SLOT.search(region):
        raise SystemExit(
            "x86 helper ladder does not switch on the generated slot selector")
    if LADDER_HAND_TEST.search(region):
        raise SystemExit(
            "x86 helper ladder restates an inline helper-id comparison")
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
    public = {name: int(number) for name, number in re.findall(
        r"\(\*\s*const\s+(bpf_\w+)\)[^;]*=\s*\(void\s*\*\)\s*(\d+)\s*;",
        (ROOT.parent.parent / "vendor/libbpf/src/bpf_helper_defs.h").read_text())}
    for name, number, _body in _ARMED:
        if public.get(name) != number:
            raise SystemExit(f"Linux helper declaration disagrees: {name}={number}")
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
body macro, in sparse Linux numeric order. -/
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
/* Sparse Linux helper IDs, checked against vendored libbpf declarations.
 * Slots follow numeric ID order. An unarmed ID reaches a compile-time error;
 * no default return value or helper substitution is permitted. */
/* The number of helper ids the ladder dispatches to a body macro. */
#define KPROG_X86_HELPER_COUNT {count}U
/* The ladder slot no armed helper id names. */
#define KPROG_X86_HELPER_SLOT_NONE 0xffU
/*
 * The ladder slot a decoded helper id dispatches to, or
 * `KPROG_X86_HELPER_SLOT_NONE` when the id reaches the default arm. The
 * Slots are distinct from sparse Linux IDs. Arguments must be pure integer
 * expressions because this constant-expression macro is also used in case labels.
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
