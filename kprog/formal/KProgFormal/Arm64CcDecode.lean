import KProgFormal.GeneratedArm64CcDecode
import KProgFormal.GeneratedArm64Cond

namespace KProgFormal

/-- Independent enumeration of the encoder's 17 condition mnemonics with the
`ARM64_COND_*` token and numeric code each one denotes, in the order `COND`
spells them. Written out by hand so it shares no structure with the generated
table. The two aliases `hs`/`lo` name the same codes as `cs`/`cc`. -/
def ccArm64MnemonicSpec : List (String × String × Nat) := [
  ("eq", "ARM64_COND_EQ", 0), ("ne", "ARM64_COND_NE", 1),
  ("cs", "ARM64_COND_CS", 2), ("hs", "ARM64_COND_CS", 2),
  ("cc", "ARM64_COND_CC", 3), ("lo", "ARM64_COND_CC", 3),
  ("mi", "ARM64_COND_MI", 4), ("pl", "ARM64_COND_PL", 5),
  ("vs", "ARM64_COND_VS", 6), ("vc", "ARM64_COND_VC", 7),
  ("hi", "ARM64_COND_HI", 8), ("ls", "ARM64_COND_LS", 9),
  ("ge", "ARM64_COND_GE", 10), ("lt", "ARM64_COND_LT", 11),
  ("gt", "ARM64_COND_GT", 12), ("le", "ARM64_COND_LE", 13),
  ("al", "ARM64_COND_AL", 14),
]

/-- Independent enumeration of the shared condition contract's name/code pairs,
in `arm64_cond_spec.json` order. The encoder's canonical mnemonics must name
exactly these conditions. -/
def ccArm64CondSpec : List (String × Nat) := [
  ("eq", 0), ("ne", 1), ("cs", 2), ("cc", 3), ("mi", 4), ("pl", 5),
  ("vs", 6), ("vc", 7), ("hi", 8), ("ls", 9), ("ge", 10), ("lt", 11),
  ("gt", 12), ("le", 13), ("al", 14),
]

/-- The two alias mnemonics, whose condition a canonical mnemonic also names. -/
def ccArm64AliasSpec : List String := ["hs", "lo"]

/-- Constructor enumeration of the generated table, in specification order; the
values still come from the generated `cond`/`mnemonic`/`define`/`code`/
`isAlias` definitions. -/
def allArm64Mnemonics : List GeneratedArm64CcDecode.Mnemonic := [
  .eq, .ne, .cs, .hs, .cc, .lo, .mi, .pl, .vs, .vc, .hi, .ls, .ge, .lt, .gt,
  .le, .al,
]

/-- The generated table, projected to `(mnemonic, token, code)` triples, equals
the independent enumeration. A change to a generated mnemonic, token, or code,
or to the independent list, breaks this equality. -/
theorem arm64_cc_decode_refines :
    ccArm64MnemonicSpec =
      allArm64Mnemonics.map (fun m => (GeneratedArm64CcDecode.mnemonic m,
                                       GeneratedArm64CcDecode.define m,
                                       GeneratedArm64CcDecode.code m)) := by
  native_decide

/-- Every generated code agrees with the shared condition contract's code for
the condition name the mnemonic selects: the encoder's table is a subset of
that contract, not an independent restatement. -/
theorem arm64_cc_decode_code_matches_cond :
    allArm64Mnemonics.all
      (fun m => ccArm64CondSpec.lookup (GeneratedArm64CcDecode.cond m) ==
                some (GeneratedArm64CcDecode.code m)) = true := by
  native_decide

/-- The distinct conditions the encoder reaches are exactly the shared
contract's conditions: seventeen mnemonics cover all fifteen conditions with
the two aliases adding no new one. -/
theorem arm64_cc_decode_conds_exact :
    (allArm64Mnemonics.map GeneratedArm64CcDecode.cond).eraseDups =
      (ccArm64CondSpec.map Prod.fst) := by
  native_decide

/-- The canonical (non-alias) mnemonics name every condition exactly once, in
the contract's order. -/
theorem arm64_cc_decode_canonical_covers :
    (allArm64Mnemonics.filter
        (fun m => !GeneratedArm64CcDecode.isAlias m)).map
          GeneratedArm64CcDecode.cond =
      (ccArm64CondSpec.map Prod.fst) := by
  native_decide

/-- The alias mnemonics are exactly `hs` and `lo`. -/
theorem arm64_cc_decode_aliases_exact :
    (allArm64Mnemonics.filter GeneratedArm64CcDecode.isAlias).map
        GeneratedArm64CcDecode.mnemonic =
      ccArm64AliasSpec := by
  native_decide

/-- Each alias denotes the same condition as its canonical spelling, so `hs`
and `lo` cannot drift onto a different code than `cs` and `cc`. -/
theorem arm64_cc_decode_alias_same_code :
    GeneratedArm64CcDecode.code .hs = GeneratedArm64CcDecode.code .cs ∧
    GeneratedArm64CcDecode.code .lo = GeneratedArm64CcDecode.code .cc := by
  native_decide

/-- An alias mnemonic is never counted among the canonical spellings. -/
theorem arm64_cc_decode_alias_not_canonical (m : GeneratedArm64CcDecode.Mnemonic) :
    GeneratedArm64CcDecode.isAlias m = true →
      m == .hs || m == .lo := by
  cases m <;> decide

end KProgFormal
