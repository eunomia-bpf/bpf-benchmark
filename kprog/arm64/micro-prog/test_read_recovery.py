"""Exercise recovery continuations over the generator's read-form families."""
import json
import generate_micro_sim_proofs as gen


def main():
    rows = []
    address_forms = [("[x2]",), ("[x2, #16]",), ("[x2, #16]!",),
                     ("[x2]", "#16"), ("[x2, x3]",), ("[x2, w3, uxtw #2]",)]
    forms = []
    for op, registers in [("ldr", ("x0", "w0", "d0", "q0")),
                          ("ldur", ("x0", "w0", "d0", "q0")),
                          ("ldrb", ("w0",)), ("ldurb", ("w0",)),
                          ("ldrh", ("w0",)), ("ldurh", ("w0",)),
                          ("ldrsb", ("w0", "x0")), ("ldrsh", ("w0", "x0")),
                          ("ldrsw", ("x0",))]:
        for reg in registers:
            for addr in address_forms:
                forms.append((op, (reg, *addr)))
    for op in ("ldxr", "ldaxr"):
        for reg in ("x0", "w0"):
            forms.append((op, (reg, "[x2]")))
    for reg, second in (("x0", "x1"), ("w0", "w1")):
        for addr in address_forms[:4]:
            forms.append(("ldp", (reg, second, *addr)))
    for family in ("ldadd", "ldset", "ldclr"):
        for order in ("", "a", "l", "al"):
            for suffix in ("", "b", "h"):
                for reg, dst in (("x0", "x1"), ("w0", "w1")) if not suffix else (("w0", "w1"),):
                    forms.append((family+order+suffix, (reg, dst, "[x2]")))
        for order in ("", "l"):
            for suffix in ("", "b", "h"):
                forms.append(("st"+family[2:]+order+suffix, ("w0", "[x2]")))
    for op, operands in forms:
        insn = gen.NativeInsn(0x100, op, operands, op+" "+", ".join(operands))
        enc = gen.encode(insn, {}, {})
        lines = []
        gen.append_insn(lines, insn, {0x100, 0x104, 0x900}, 0x900, None, {}, {})
        assert lines[-1] == f"\tgoto {gen.label(0x104)};", lines
        assert sum("ARM64_SIM_RUN_KNOWN_OP3" in line for line in lines) == 1
        rows.append(dict(assembly=insn.raw, operation=enc.op,
                         recovery="SIMD runtime interface" if enc.op in {"ARM64_OP_LOAD_D0", "ARM64_OP_LOAD_Q0"}
                         else "whole-GPR clear before effects; PC+4"))
    print(json.dumps(dict(forms=len(rows), rows=rows), indent=2))


if __name__ == "__main__":
    main()
