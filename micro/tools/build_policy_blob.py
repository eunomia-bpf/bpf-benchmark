#!/usr/bin/env python3
"""
Build a v4 JIT policy blob for BPF_PROG_JIT_RECOMPILE.

Usage:
    python3 build_policy_blob.py <program.bpf.o> [--output <path>] [--rules <rules_json>]
                                 [--cmov-all] [--wide-all] [--program-name <name>]

The script loads a BPF ELF, extracts instructions, scans for rewrite-eligible
sites, and emits a binary policy blob.

Policy blob format (v4):
  - Header: bpf_jit_policy_hdr (32 bytes)
  - Rules:  bpf_jit_rewrite_rule[] (16 bytes each)
"""

import argparse
import hashlib
import struct
import subprocess
import sys
import os
import json

# Constants from include/uapi/linux/bpf.h
BPF_JIT_POLICY_MAGIC = 0x4A495450  # "JITP"
BPF_JIT_POLICY_VERSION = 1
BPF_JIT_ARCH_X86_64 = 1

# Rule kinds
BPF_JIT_RK_COND_SELECT = 1
BPF_JIT_RK_WIDE_MEM = 2

# Native choices
BPF_JIT_SEL_CMOVCC = 1
BPF_JIT_SEL_BRANCH = 2
BPF_JIT_WMEM_WIDE_LOAD = 1
BPF_JIT_WMEM_BYTE_LOADS = 2

# BPF instruction encoding
BPF_CLASS_MASK = 0x07
BPF_JMP = 0x05
BPF_JMP32 = 0x06
BPF_ALU = 0x04
BPF_ALU64 = 0x07
BPF_LDX = 0x61  # BPF_LDX|BPF_MEM|BPF_W ... varies
BPF_OP_MASK = 0xf0
BPF_SRC_MASK = 0x08
BPF_MOV = 0xb0
BPF_JA = 0x00
BPF_JEQ = 0x10
BPF_JNE = 0x50
BPF_JGT = 0x20
BPF_JLT = 0xa0
BPF_JGE = 0x30
BPF_JLE = 0xb0
BPF_JSGT = 0x60
BPF_JSLT = 0xc0
BPF_JSGE = 0x70
BPF_JSLE = 0xd0
BPF_LSH = 0x60
BPF_OR = 0x40
BPF_K = 0x00
BPF_X = 0x08

COND_JUMP_OPS = {BPF_JEQ, BPF_JNE, BPF_JGT, BPF_JLT, BPF_JGE, BPF_JLE,
                 BPF_JSGT, BPF_JSLT, BPF_JSGE, BPF_JSLE}


def parse_bpf_insn(data, offset):
    """Parse a single 8-byte BPF instruction."""
    code, regs, off, imm = struct.unpack_from('<BBhI', data, offset)
    dst_reg = regs & 0x0f
    src_reg = (regs >> 4) & 0x0f
    return {
        'code': code,
        'dst_reg': dst_reg,
        'src_reg': src_reg,
        'off': off,
        'imm': imm,
    }


def load_bpf_insns_from_elf(elf_path, program_name=None):
    """Load BPF instructions from an ELF file using llvm-objdump or readelf."""
    # Try to read the .text or xdp section directly
    import subprocess

    # Use readelf to find sections
    try:
        result = subprocess.run(
            ['llvm-readelf', '-S', elf_path],
            capture_output=True, text=True, timeout=10
        )
        sections = result.stdout
    except (FileNotFoundError, subprocess.TimeoutExpired):
        try:
            result = subprocess.run(
                ['readelf', '-S', elf_path],
                capture_output=True, text=True, timeout=10
            )
            sections = result.stdout
        except (FileNotFoundError, subprocess.TimeoutExpired):
            print("Error: neither llvm-readelf nor readelf found", file=sys.stderr)
            sys.exit(1)

    # Read the ELF binary directly
    with open(elf_path, 'rb') as f:
        elf_data = f.read()

    # Parse ELF header
    if elf_data[:4] != b'\x7fELF':
        print("Error: not an ELF file", file=sys.stderr)
        sys.exit(1)

    # 64-bit ELF
    ei_class = elf_data[4]
    if ei_class != 2:
        print("Error: not a 64-bit ELF", file=sys.stderr)
        sys.exit(1)

    # Little endian
    ei_data = elf_data[5]
    if ei_data != 1:
        print("Error: not little-endian ELF", file=sys.stderr)
        sys.exit(1)

    # Parse ELF64 header
    e_shoff = struct.unpack_from('<Q', elf_data, 40)[0]
    e_shentsize = struct.unpack_from('<H', elf_data, 58)[0]
    e_shnum = struct.unpack_from('<H', elf_data, 60)[0]
    e_shstrndx = struct.unpack_from('<H', elf_data, 62)[0]

    # Read section header string table
    shstrtab_off = struct.unpack_from('<Q', elf_data, e_shoff + e_shstrndx * e_shentsize + 24)[0]
    shstrtab_size = struct.unpack_from('<Q', elf_data, e_shoff + e_shstrndx * e_shentsize + 32)[0]
    shstrtab = elf_data[shstrtab_off:shstrtab_off + shstrtab_size]

    def get_section_name(name_offset):
        end = shstrtab.index(b'\x00', name_offset)
        return shstrtab[name_offset:end].decode('ascii')

    # Find the program section
    target_sections = ['xdp', '.text']
    if program_name:
        target_sections = [f'xdp/{program_name}', f'xdp_{program_name}',
                          program_name, 'xdp', '.text']

    for sec_idx in range(e_shnum):
        sec_off = e_shoff + sec_idx * e_shentsize
        sh_name = struct.unpack_from('<I', elf_data, sec_off)[0]
        sh_type = struct.unpack_from('<I', elf_data, sec_off + 4)[0]
        sh_offset = struct.unpack_from('<Q', elf_data, sec_off + 24)[0]
        sh_size = struct.unpack_from('<Q', elf_data, sec_off + 32)[0]

        name = get_section_name(sh_name)
        if sh_type == 1 and sh_size > 0 and name in target_sections:  # SHT_PROGBITS
            section_data = elf_data[sh_offset:sh_offset + sh_size]
            insns = []
            for i in range(0, len(section_data), 8):
                insns.append(parse_bpf_insn(section_data, i))
            return insns, section_data

    # Fallback: find first PROGBITS section that's not .rodata/.data/.bss
    for sec_idx in range(e_shnum):
        sec_off = e_shoff + sec_idx * e_shentsize
        sh_name = struct.unpack_from('<I', elf_data, sec_off)[0]
        sh_type = struct.unpack_from('<I', elf_data, sec_off + 4)[0]
        sh_flags = struct.unpack_from('<Q', elf_data, sec_off + 8)[0]
        sh_offset = struct.unpack_from('<Q', elf_data, sec_off + 24)[0]
        sh_size = struct.unpack_from('<Q', elf_data, sec_off + 32)[0]

        name = get_section_name(sh_name)
        if (sh_type == 1 and sh_flags & 0x4 and  # SHT_PROGBITS + SHF_EXECINSTR
                name not in ['.rodata', '.data', '.bss', '', '.BTF', '.BTF.ext']):
            section_data = elf_data[sh_offset:sh_offset + sh_size]
            insns = []
            for i in range(0, len(section_data), 8):
                insns.append(parse_bpf_insn(section_data, i))
            return insns, section_data

    print("Error: no suitable BPF program section found", file=sys.stderr)
    sys.exit(1)


def is_cond_jump(insn):
    cls = insn['code'] & BPF_CLASS_MASK
    if cls not in (BPF_JMP, BPF_JMP32):
        return False
    op = insn['code'] & BPF_OP_MASK
    return op in COND_JUMP_OPS


def is_simple_mov(insn):
    cls = insn['code'] & BPF_CLASS_MASK
    if cls not in (BPF_ALU, BPF_ALU64):
        return False
    if (insn['code'] & BPF_OP_MASK) != BPF_MOV:
        return False
    if insn['off'] != 0:
        return False
    src = insn['code'] & BPF_SRC_MASK
    if src == BPF_X:
        return insn['imm'] == 0
    elif src == BPF_K:
        return insn['src_reg'] == 0
    return False


def find_cond_select_sites(insns):
    """Find diamond and compact cmov-select patterns."""
    sites = []
    n = len(insns)
    idx = 0
    while idx < n:
        # Diamond: jcc+2, mov, ja+1, mov
        if (idx + 3 < n and
                is_cond_jump(insns[idx]) and insns[idx]['off'] == 2 and
                is_simple_mov(insns[idx + 1]) and
                is_simple_mov(insns[idx + 3]) and
                insns[idx + 2]['code'] == (BPF_JMP | BPF_JA) and
                insns[idx + 2]['off'] == 1 and
                insns[idx + 1]['dst_reg'] == insns[idx + 3]['dst_reg']):
            sites.append({
                'site_start': idx,
                'site_len': 4,
                'rule_kind': BPF_JIT_RK_COND_SELECT,
                'native_choice': BPF_JIT_SEL_CMOVCC,
                'shape': 'diamond',
            })
            idx += 4
            continue

        # Compact: mov, jcc+1, mov
        if (idx > 0 and idx + 1 < n and
                is_simple_mov(insns[idx - 1]) and
                is_cond_jump(insns[idx]) and insns[idx]['off'] == 1 and
                is_simple_mov(insns[idx + 1]) and
                insns[idx - 1]['dst_reg'] == insns[idx + 1]['dst_reg']):
            sites.append({
                'site_start': idx - 1,
                'site_len': 3,
                'rule_kind': BPF_JIT_RK_COND_SELECT,
                'native_choice': BPF_JIT_SEL_CMOVCC,
                'shape': 'compact',
            })
            idx += 2
            continue

        idx += 1
    return sites


def find_wide_mem_sites(insns):
    """Find byte-load ladder patterns suitable for wide_mem optimization."""
    sites = []
    n = len(insns)
    idx = 0

    while idx < n:
        insn = insns[idx]
        # Look for BPF_LDX | BPF_MEM | BPF_B = 0x71
        if insn['code'] != 0x71:
            idx += 1
            continue

        base_reg = insn['src_reg']
        dst_reg = insn['dst_reg']
        base_off = insn['off']

        # Try to find consecutive byte loads
        # Pattern: ldxb, (ldxb, lsh, or) * (width-1)
        # For width N: 1 + (N-1)*3 = 3N-2 insns
        best_width = 1
        for width in [2, 4, 8]:
            total_insns = 3 * width - 2
            if idx + total_insns > n:
                break

            valid = True
            for byte_idx in range(1, width):
                group_base = idx + 1 + (byte_idx - 1) * 3
                load_insn = insns[group_base]
                shift_insn = insns[group_base + 1]
                or_insn = insns[group_base + 2]

                # Check ldxb from same base at contiguous offset
                if load_insn['code'] != 0x71:
                    valid = False
                    break
                if load_insn['src_reg'] != base_reg:
                    valid = False
                    break
                if load_insn['off'] != base_off + byte_idx:
                    valid = False
                    break

                # Check lsh64 by byte_idx*8
                if shift_insn['code'] != (BPF_ALU64 | BPF_LSH | BPF_K):
                    valid = False
                    break
                if shift_insn['imm'] != byte_idx * 8:
                    valid = False
                    break
                if shift_insn['dst_reg'] != load_insn['dst_reg']:
                    valid = False
                    break

                # Check or64
                if or_insn['code'] != (BPF_ALU64 | BPF_OR | BPF_X):
                    valid = False
                    break
                if or_insn['dst_reg'] != dst_reg:
                    valid = False
                    break
                if or_insn['src_reg'] != load_insn['dst_reg']:
                    valid = False
                    break

            if valid:
                best_width = width

        if best_width >= 2:
            total_insns = 3 * best_width - 2
            sites.append({
                'site_start': idx,
                'site_len': total_insns,
                'rule_kind': BPF_JIT_RK_WIDE_MEM,
                'native_choice': BPF_JIT_WMEM_WIDE_LOAD,
                'width': best_width,
                'base_reg': base_reg,
                'base_off': base_off,
            })
            idx += total_insns
            continue

        idx += 1

    return sites


def compute_prog_tag(insn_data):
    """Compute BPF prog_tag approximation.

    NOTE: The kernel computes prog_tag as SHA-256 of the xlated program
    with map FD imm values zeroed. This function provides a placeholder.
    For actual use, the runner patches the tag at load time using
    BPF_OBJ_GET_INFO_BY_FD to get the real prog_tag.
    """
    # Zero out map FD references (BPF_LD | BPF_IMM | BPF_DW with PSEUDO_MAP_FD)
    data = bytearray(insn_data)
    i = 0
    while i < len(data):
        if i + 8 > len(data):
            break
        code = data[i]
        regs = data[i + 1]
        src_reg = (regs >> 4) & 0x0f
        # BPF_LD | BPF_IMM | BPF_DW = 0x18, PSEUDO_MAP_FD = 1, PSEUDO_MAP_VALUE = 2
        if code == 0x18 and src_reg in (1, 2):
            # Zero imm of this and next instruction
            data[i + 4:i + 8] = b'\x00\x00\x00\x00'
            if i + 16 <= len(data):
                data[i + 12:i + 16] = b'\x00\x00\x00\x00'
            i += 16
            continue
        i += 8
    sha = hashlib.sha256(bytes(data)).digest()
    return sha[:8]


def build_policy_blob(insns, insn_data, rules, arch_id=BPF_JIT_ARCH_X86_64):
    """Build a binary v4 policy blob."""
    prog_tag = compute_prog_tag(insn_data)
    insn_cnt = len(insns)

    # Header: 32 bytes
    hdr = struct.pack('<IHHIIB7sHH',
                      BPF_JIT_POLICY_MAGIC,   # magic
                      BPF_JIT_POLICY_VERSION,  # version
                      32,                       # hdr_len
                      0,                        # total_len (filled later)
                      len(rules),               # rule_cnt
                      insn_cnt,                 # insn_cnt
                      prog_tag,                 # prog_tag (8 bytes, split as 1+7)
                      arch_id,                  # arch_id
                      0)                        # flags

    # Actually, the header struct is:
    # __u32 magic, __u16 version, __u16 hdr_len, __u32 total_len,
    # __u32 rule_cnt, __u32 insn_cnt, __u8 prog_tag[8], __u16 arch_id, __u16 flags
    # Total = 4+2+2+4+4+4+8+2+2 = 32 bytes
    hdr = struct.pack('<I H H I I I 8s H H',
                      BPF_JIT_POLICY_MAGIC,
                      BPF_JIT_POLICY_VERSION,
                      32,  # hdr_len
                      0,   # total_len (placeholder)
                      len(rules),
                      insn_cnt,
                      prog_tag,
                      arch_id,
                      0)   # flags

    # Rules: 16 bytes each
    # __u32 site_start, __u16 site_len, __u16 rule_kind,
    # __u16 native_choice, __u16 priority, __u32 reserved
    rule_data = b''
    for rule in rules:
        rule_data += struct.pack('<I H H H H I',
                                 rule['site_start'],
                                 rule['site_len'],
                                 rule['rule_kind'],
                                 rule['native_choice'],
                                 rule.get('priority', 0),
                                 0)  # reserved

    total_len = len(hdr) + len(rule_data)

    # Patch total_len in header
    hdr = hdr[:8] + struct.pack('<I', total_len) + hdr[12:]

    return hdr + rule_data


def main():
    parser = argparse.ArgumentParser(description='Build v4 JIT policy blob')
    parser.add_argument('program', help='BPF ELF object file')
    parser.add_argument('--output', '-o', help='Output blob path')
    parser.add_argument('--program-name', help='BPF program name in ELF')
    parser.add_argument('--cmov-all', action='store_true',
                       help='Apply cmov to all eligible sites')
    parser.add_argument('--wide-all', action='store_true',
                       help='Apply wide-load to all eligible sites')
    parser.add_argument('--rules', help='JSON file with explicit rules')
    parser.add_argument('--verbose', '-v', action='store_true')
    args = parser.parse_args()

    if not args.output:
        args.output = args.program + '.policy.bin'

    insns, insn_data = load_bpf_insns_from_elf(args.program, args.program_name)

    if args.verbose:
        print(f"Loaded {len(insns)} BPF instructions from {args.program}",
              file=sys.stderr)
        print(f"prog_tag: {compute_prog_tag(insn_data).hex()}", file=sys.stderr)

    rules = []

    if args.rules:
        with open(args.rules) as f:
            rules = json.load(f)
    else:
        if args.cmov_all or (not args.wide_all):
            cmov_sites = find_cond_select_sites(insns)
            rules.extend(cmov_sites)
            if args.verbose:
                print(f"Found {len(cmov_sites)} COND_SELECT sites",
                      file=sys.stderr)
                for site in cmov_sites:
                    print(f"  [{site['site_start']}..{site['site_start']+site['site_len']-1}] "
                          f"{site['shape']}", file=sys.stderr)

        if args.wide_all:
            wide_sites = find_wide_mem_sites(insns)
            rules.extend(wide_sites)
            if args.verbose:
                print(f"Found {len(wide_sites)} WIDE_MEM sites",
                      file=sys.stderr)
                for site in wide_sites:
                    print(f"  [{site['site_start']}..{site['site_start']+site['site_len']-1}] "
                          f"width={site['width']}", file=sys.stderr)

    if not rules:
        print("No rewrite sites found", file=sys.stderr)
        sys.exit(1)

    blob = build_policy_blob(insns, insn_data, rules)

    with open(args.output, 'wb') as f:
        f.write(blob)

    print(f"{args.output} {len(rules)} rules {len(blob)} bytes")


if __name__ == '__main__':
    main()
