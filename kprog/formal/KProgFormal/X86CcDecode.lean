import KProgFormal.GeneratedX86CcDecode
import KProgFormal.GeneratedX86Cond

namespace KProgFormal

/-- Independent enumeration of the encoder's 36 condition mnemonics with the
`X86_CC_*` token and numeric code each one denotes, in the order `CC_AUX`
spells them. Written out by hand so it shares no structure with the generated
tables. -/
def ccMnemonicSpec : List (String × String × Nat) := [
  ("ja", "X86_CC_A", 7), ("jae", "X86_CC_AE", 3), ("jb", "X86_CC_B", 2),
  ("jbe", "X86_CC_BE", 6), ("je", "X86_CC_E", 4), ("jne", "X86_CC_NE", 5),
  ("jg", "X86_CC_G", 15), ("jge", "X86_CC_GE", 13), ("jl", "X86_CC_L", 12),
  ("jle", "X86_CC_LE", 14), ("js", "X86_CC_S", 8), ("jns", "X86_CC_NS", 9),
  ("cmova", "X86_CC_A", 7), ("cmovb", "X86_CC_B", 2), ("cmovbe", "X86_CC_BE", 6),
  ("cmove", "X86_CC_E", 4), ("cmovg", "X86_CC_G", 15), ("cmovge", "X86_CC_GE", 13),
  ("cmovae", "X86_CC_AE", 3), ("cmovl", "X86_CC_L", 12), ("cmovle", "X86_CC_LE", 14),
  ("cmovne", "X86_CC_NE", 5), ("cmovns", "X86_CC_NS", 9), ("cmovs", "X86_CC_S", 8),
  ("seta", "X86_CC_A", 7), ("setae", "X86_CC_AE", 3), ("setb", "X86_CC_B", 2),
  ("setbe", "X86_CC_BE", 6), ("sete", "X86_CC_E", 4), ("setg", "X86_CC_G", 15),
  ("setge", "X86_CC_GE", 13), ("setl", "X86_CC_L", 12), ("setle", "X86_CC_LE", 14),
  ("setne", "X86_CC_NE", 5), ("setns", "X86_CC_NS", 9), ("sets", "X86_CC_S", 8),
]

/-- Independent enumeration of the shared condition contract's name/code pairs,
in `x86_cond_spec.json` order. The encoder's suffixes must be exactly the
non-parity subset of these names. -/
def ccCondSpec : List (String × Nat) := [
  ("o", 0), ("no", 1), ("b", 2), ("ae", 3), ("e", 4), ("ne", 5), ("be", 6),
  ("a", 7), ("s", 8), ("ns", 9), ("l", 12), ("ge", 13), ("le", 14), ("g", 15),
]

/-- The condition names the encoder reaches, in the order its suffix table
lists them. These are the shared contract's names minus the parity pair. -/
def ccSuffixSpec : List String :=
  ["a", "ae", "b", "be", "e", "ne", "g", "ge", "l", "le", "s", "ns"]

/-- Constructor enumeration of the generated table, in specification order; the
values still come from the generated `family`/`suffix`/`mnemonic`/`define`/
`code` definitions. -/
def allMnemonics : List GeneratedX86CcDecode.Mnemonic := [
  .ja, .jae, .jb, .jbe, .je, .jne, .jg, .jge, .jl, .jle, .js, .jns,
  .cmova, .cmovb, .cmovbe, .cmove, .cmovg, .cmovge, .cmovae, .cmovl, .cmovle,
  .cmovne, .cmovns, .cmovs,
  .seta, .setae, .setb, .setbe, .sete, .setg, .setge, .setl, .setle, .setne,
  .setns, .sets,
]

/-- The generated table, projected to `(mnemonic, token, code)` triples, equals
the independent enumeration. A change to a generated mnemonic, token, or code,
or to the independent list, breaks this equality. -/
theorem x86_cc_decode_refines :
    ccMnemonicSpec =
      allMnemonics.map (fun m => (GeneratedX86CcDecode.mnemonic m,
                                  GeneratedX86CcDecode.define m,
                                  GeneratedX86CcDecode.code m)) := by
  native_decide

/-- Every generated code agrees with the shared condition contract's code for
the same condition name: the encoder's table is a subset of that contract, not
an independent restatement. -/
theorem x86_cc_decode_code_matches_cond :
    allMnemonics.all
      (fun m => ccCondSpec.lookup (GeneratedX86CcDecode.suffix m) ==
                some (GeneratedX86CcDecode.code m)) = true := by
  native_decide

/-- The distinct condition names the encoder reaches, in table order, are
exactly the independent suffix list — the shared contract's names minus the
parity pair `o`/`no`. -/
theorem x86_cc_decode_suffixes_exact :
    (allMnemonics.map GeneratedX86CcDecode.suffix).eraseDups = ccSuffixSpec := by
  native_decide

/-- Every mnemonic is exactly its family prefix followed by its condition
suffix, so a parser that splits a token into prefix and suffix recovers the
same condition the table names. -/
theorem x86_cc_decode_mnemonic_composition (m : GeneratedX86CcDecode.Mnemonic) :
    GeneratedX86CcDecode.familyText (GeneratedX86CcDecode.family m) ++
      GeneratedX86CcDecode.suffix m = GeneratedX86CcDecode.mnemonic m := by
  cases m <;> rfl

/-- The parity condition codes 10 and 11 are named by no mnemonic, matching the
encoder table, which omits `jp`/`jnp`. -/
theorem x86_cc_decode_parity_absent :
    allMnemonics.all
      (fun m => GeneratedX86CcDecode.code m != 10 &&
                GeneratedX86CcDecode.code m != 11) = true := by
  native_decide

/-- The distinct codes the encoder reaches are exactly the shared contract's
non-parity codes, so dispatch on a code cannot confuse two encoder mnemonics
with different conditions. -/
theorem x86_cc_decode_codes_exact :
    (allMnemonics.map GeneratedX86CcDecode.code).eraseDups =
      ccSuffixSpec.map (fun s => ccCondSpec.lookup s |>.getD 0) := by
  native_decide

/-- Each family reaches all 12 conditions: the three families are the same
suffix set under different prefixes, so a mnemonic's condition depends only on
its suffix. -/
theorem x86_cc_decode_families_uniform :
    (allMnemonics.filter (fun m => GeneratedX86CcDecode.family m == .j)).length = 12 ∧
    (allMnemonics.filter (fun m => GeneratedX86CcDecode.family m == .cmov)).length = 12 ∧
    (allMnemonics.filter (fun m => GeneratedX86CcDecode.family m == .set)).length = 12 := by
  refine ⟨by native_decide, by native_decide, by native_decide⟩

end KProgFormal
