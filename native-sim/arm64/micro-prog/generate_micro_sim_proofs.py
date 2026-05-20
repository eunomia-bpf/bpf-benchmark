#!/usr/bin/env python3
from __future__ import annotations

import argparse
import re
import subprocess
from dataclasses import dataclass
from pathlib import Path


SUPPORTED_BENCHES = {"simple": ("simple_xdp", "simple_arm64_sim_xdp", 64, 12345678)}


@dataclass(frozen=True)
class Insn:
    addr: int
    mnemonic: str
    operands: str
    text: str


def _run_objdump(native_so: Path, symbol: str) -> str:
    completed = subprocess.run(
        ["aarch64-linux-gnu-objdump", "-d", f"--disassemble={symbol}", str(native_so)],
        check=False,
        capture_output=True,
        text=True,
    )
    if completed.returncode != 0:
        raise SystemExit(completed.stderr.strip() or completed.stdout.strip())
    return completed.stdout


def _parse_disassembly(text: str) -> list[Insn]:
    out: list[Insn] = []
    pattern = re.compile(r"^\s*([0-9a-f]+):\s+[0-9a-f]{8}\s+\t([a-z0-9.]+)\s*(.*)$")
    for line in text.splitlines():
        match = pattern.match(line)
        if not match:
            continue
        operands = match.group(3).split("//", 1)[0].strip()
        out.append(Insn(int(match.group(1), 16), match.group(2), operands, line.strip()))
    if not out:
        raise SystemExit("no arm64 instructions found in objdump output")
    return out


def _reg_var(reg: str) -> str:
    reg = reg.strip().lower()
    if reg in {"xzr", "wzr"}:
        return "0"
    match = re.fullmatch(r"[xw]([0-9]|[12][0-9]|30)", reg)
    if not match:
        raise SystemExit(f"unsupported register: {reg}")
    return f"__a64_x{match.group(1)}"


def _reg_index(reg: str) -> int:
    reg = reg.strip().lower()
    if reg in {"xzr", "wzr"}:
        return 31
    match = re.fullmatch(r"[xw]([0-9]|[12][0-9]|30)", reg)
    if not match:
        raise SystemExit(f"unsupported register: {reg}")
    return int(match.group(1))


def _is_w(reg: str) -> bool:
    return reg.strip().lower().startswith("w")


def _split_operands(operands: str) -> list[str]:
    parts: list[str] = []
    current: list[str] = []
    bracket_depth = 0
    for ch in operands:
        if ch == "[":
            bracket_depth += 1
        elif ch == "]":
            bracket_depth -= 1
        if ch == "," and bracket_depth == 0:
            parts.append("".join(current).strip())
            current = []
            continue
        current.append(ch)
    if current:
        parts.append("".join(current).strip())
    return parts


def _parse_mem(mem: str) -> tuple[str, int]:
    match = re.fullmatch(r"\[([xw][0-9]+)(?:,\s*#(-?0x[0-9a-f]+|-?[0-9]+))?\]", mem.strip().lower())
    if not match:
        raise SystemExit(f"unsupported memory operand: {mem}")
    off_s = match.group(2)
    offset = int(off_s, 0) if off_s else 0
    return match.group(1), offset


def _parse_imm(imm: str) -> int:
    imm = imm.strip()
    if not imm.startswith("#"):
        raise SystemExit(f"unsupported immediate: {imm}")
    return int(imm[1:], 0)


def _label(addr: int) -> str:
    return f"L_{addr:x}"


def _emit_store_bytes(dst_ptr: str, offset: int, src_expr: str, width: int) -> list[str]:
    return [
        f"\t*((__u8 *){dst_ptr} + {offset + i}) = (__u8)(({src_expr}) >> {8 * i});"
        for i in range(width)
    ]


def _render_instruction(insn: Insn, last_cmp: tuple[str, str] | None) -> tuple[list[str], tuple[str, str] | None]:
    ops = _split_operands(insn.operands)
    lines = [f"\t/* {insn.text} */"]

    if insn.mnemonic == "ldp":
        if len(ops) != 3:
            raise SystemExit(f"unsupported ldp operands: {insn.operands}")
        dst0, dst1, mem = ops
        base, offset = _parse_mem(mem)
        if base != "x0" or offset != 0:
            raise SystemExit(f"only XDP ABI ldp from [x0] is supported: {insn.operands}")
        lines.append(f"\t{_reg_var(dst0)}.ptr = __a64_sim_abi.data;")
        lines.append(f"\t{_reg_var(dst1)}.ptr = __a64_sim_abi.data_end;")
        return lines, last_cmp

    if insn.mnemonic == "mov":
        if len(ops) != 2:
            raise SystemExit(f"unsupported mov operands: {insn.operands}")
        dst, src = ops
        dst_v = _reg_var(dst)
        if src.lower() in {"xzr", "wzr"}:
            lines.append(f"\t{dst_v}.x = 0;")
        elif src.startswith("#"):
            value = _parse_imm(src)
            mask = "0xffffffffULL" if _is_w(dst) else "0xffffffffffffffffULL"
            lines.append(f"\t{dst_v}.x = ({value}ULL & {mask});")
        else:
            src_v = _reg_var(src)
            if _is_w(dst):
                lines.append(f"\t{dst_v}.x = (__u32){src_v}.x;")
            else:
                lines.append(f"\t{dst_v}.x = {src_v}.x;")
        return lines, last_cmp

    if insn.mnemonic == "add":
        if len(ops) != 3 or not ops[2].startswith("#"):
            raise SystemExit(f"only add immediate is supported: {insn.operands}")
        dst, src, imm = ops
        value = _parse_imm(imm)
        dst_v = _reg_var(dst)
        src_v = _reg_var(src)
        if _is_w(dst):
            lines.append(f"\t{dst_v}.x = (__u32)({src_v}.x + {value}ULL);")
        else:
            lines.append(f"\t{dst_v}.ptr = (void *)((__u8 *){src_v}.ptr + {value}ULL);")
        return lines, last_cmp

    if insn.mnemonic == "cmp":
        if len(ops) != 2:
            raise SystemExit(f"unsupported cmp operands: {insn.operands}")
        return lines, (ops[0], ops[1])

    if insn.mnemonic in {"b.ls", "b.hi"}:
        if len(ops) != 1 or last_cmp is None:
            raise SystemExit(f"branch without supported prior cmp: {insn.text}")
        target = int(ops[0].split()[0], 16)
        lhs, rhs = last_cmp
        lhs_v = _reg_var(lhs)
        rhs_v = _reg_var(rhs)
        op = "<=" if insn.mnemonic == "b.ls" else ">"
        lines.append(
            f"\tif ((__u8 *){lhs_v}.ptr {op} (__u8 *){rhs_v}.ptr) "
            f"goto {_label(target)};"
        )
        return lines, last_cmp

    if insn.mnemonic in {"strh", "strb"}:
        if len(ops) != 2:
            raise SystemExit(f"unsupported store operands: {insn.operands}")
        src, mem = ops
        base, offset = _parse_mem(mem)
        width = 2 if insn.mnemonic == "strh" else 1
        src_expr = "0" if _reg_index(src) == 31 else f"{_reg_var(src)}.x"
        lines.extend(_emit_store_bytes(f"{_reg_var(base)}.ptr", offset, src_expr, width))
        return lines, last_cmp

    if insn.mnemonic == "stur":
        if len(ops) != 2:
            raise SystemExit(f"unsupported stur operands: {insn.operands}")
        src, mem = ops
        base, offset = _parse_mem(mem)
        width = 4 if _is_w(src) else 8
        src_expr = "0" if _reg_index(src) == 31 else f"{_reg_var(src)}.x"
        lines.extend(_emit_store_bytes(f"{_reg_var(base)}.ptr", offset, src_expr, width))
        return lines, last_cmp

    if insn.mnemonic == "ret":
        lines.append("\tARM64_SIM_RET();")
        return lines, last_cmp

    raise SystemExit(f"unsupported arm64 instruction: {insn.text}")


def _render_c(insns: list[Insn], program_name: str) -> str:
    lines = [
        "#include \"arm64_sim_local_bpf.h\"",
        "",
        "SEC(\"xdp\")",
        f"int {program_name}(struct xdp_md *ctx)",
        "{",
        "\tARM64_SIM_ENTRY_XDP(ctx);",
    ]
    last_cmp: tuple[str, str] | None = None
    for insn in insns:
        lines.append(f"{_label(insn.addr)}:")
        rendered, last_cmp = _render_instruction(insn, last_cmp)
        lines.extend(rendered)
    lines.extend([
        "\treturn XDP_ABORTED;",
        "}",
        "",
        "ARM64_SIM_LICENSE();",
        "",
    ])
    return "\n".join(lines)


def main() -> int:
    parser = argparse.ArgumentParser(description="Generate arm64 eBPF simulator proof sources for micro programs.")
    parser.add_argument("--bench", required=True, choices=sorted(SUPPORTED_BENCHES))
    parser.add_argument("--native-so", required=True, type=Path)
    parser.add_argument("--output", required=True, type=Path)
    parser.add_argument("--input-output", type=Path)
    args = parser.parse_args()

    symbol, program_name, input_size, _expected = SUPPORTED_BENCHES[args.bench]
    disassembly = _run_objdump(args.native_so, symbol)
    source = _render_c(_parse_disassembly(disassembly), program_name)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(source, encoding="utf-8")
    if args.input_output is not None:
        args.input_output.parent.mkdir(parents=True, exist_ok=True)
        args.input_output.write_bytes(bytes(input_size))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
