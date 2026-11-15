import Clightdefs
open CC

namespace Arm64Numeric

namespace Info
  def version : String := "3.17"
  def build_number : String := ""
  def build_tag : String := ""
  def build_branch : String := ""
  def arch : String := "x86"
  def model : String := "64"
  def abi : String := "standard"
  def bitsize : Nat := 64
  def big_endian : Bool := false
  def source_file : String := "c/Arm64Numeric.c"
  def normalized : Bool := true
end Info

def ___builtin_ais_annot : Ident := identOfString "__builtin_ais_annot"
def ___builtin_annot : Ident := identOfString "__builtin_annot"
def ___builtin_annot_intval : Ident := identOfString "__builtin_annot_intval"
def ___builtin_bswap : Ident := identOfString "__builtin_bswap"
def ___builtin_bswap16 : Ident := identOfString "__builtin_bswap16"
def ___builtin_bswap32 : Ident := identOfString "__builtin_bswap32"
def ___builtin_bswap64 : Ident := identOfString "__builtin_bswap64"
def ___builtin_clz : Ident := identOfString "__builtin_clz"
def ___builtin_clzl : Ident := identOfString "__builtin_clzl"
def ___builtin_clzll : Ident := identOfString "__builtin_clzll"
def ___builtin_ctz : Ident := identOfString "__builtin_ctz"
def ___builtin_ctzl : Ident := identOfString "__builtin_ctzl"
def ___builtin_ctzll : Ident := identOfString "__builtin_ctzll"
def ___builtin_debug : Ident := identOfString "__builtin_debug"
def ___builtin_expect : Ident := identOfString "__builtin_expect"
def ___builtin_fabs : Ident := identOfString "__builtin_fabs"
def ___builtin_fabsf : Ident := identOfString "__builtin_fabsf"
def ___builtin_fmadd : Ident := identOfString "__builtin_fmadd"
def ___builtin_fmax : Ident := identOfString "__builtin_fmax"
def ___builtin_fmin : Ident := identOfString "__builtin_fmin"
def ___builtin_fmsub : Ident := identOfString "__builtin_fmsub"
def ___builtin_fnmadd : Ident := identOfString "__builtin_fnmadd"
def ___builtin_fnmsub : Ident := identOfString "__builtin_fnmsub"
def ___builtin_fsqrt : Ident := identOfString "__builtin_fsqrt"
def ___builtin_membar : Ident := identOfString "__builtin_membar"
def ___builtin_memcpy_aligned : Ident := identOfString "__builtin_memcpy_aligned"
def ___builtin_read16_reversed : Ident := identOfString "__builtin_read16_reversed"
def ___builtin_read32_reversed : Ident := identOfString "__builtin_read32_reversed"
def ___builtin_sel : Ident := identOfString "__builtin_sel"
def ___builtin_sqrt : Ident := identOfString "__builtin_sqrt"
def ___builtin_unreachable : Ident := identOfString "__builtin_unreachable"
def ___builtin_va_arg : Ident := identOfString "__builtin_va_arg"
def ___builtin_va_copy : Ident := identOfString "__builtin_va_copy"
def ___builtin_va_end : Ident := identOfString "__builtin_va_end"
def ___builtin_va_start : Ident := identOfString "__builtin_va_start"
def ___builtin_write16_reversed : Ident := identOfString "__builtin_write16_reversed"
def ___builtin_write32_reversed : Ident := identOfString "__builtin_write32_reversed"
def ___compcert_i64_dtos : Ident := identOfString "__compcert_i64_dtos"
def ___compcert_i64_dtou : Ident := identOfString "__compcert_i64_dtou"
def ___compcert_i64_sar : Ident := identOfString "__compcert_i64_sar"
def ___compcert_i64_sdiv : Ident := identOfString "__compcert_i64_sdiv"
def ___compcert_i64_shl : Ident := identOfString "__compcert_i64_shl"
def ___compcert_i64_shr : Ident := identOfString "__compcert_i64_shr"
def ___compcert_i64_smod : Ident := identOfString "__compcert_i64_smod"
def ___compcert_i64_smulh : Ident := identOfString "__compcert_i64_smulh"
def ___compcert_i64_stod : Ident := identOfString "__compcert_i64_stod"
def ___compcert_i64_stof : Ident := identOfString "__compcert_i64_stof"
def ___compcert_i64_udiv : Ident := identOfString "__compcert_i64_udiv"
def ___compcert_i64_umod : Ident := identOfString "__compcert_i64_umod"
def ___compcert_i64_umulh : Ident := identOfString "__compcert_i64_umulh"
def ___compcert_i64_utod : Ident := identOfString "__compcert_i64_utod"
def ___compcert_i64_utof : Ident := identOfString "__compcert_i64_utof"
def ___compcert_va_composite : Ident := identOfString "__compcert_va_composite"
def ___compcert_va_float64 : Ident := identOfString "__compcert_va_float64"
def ___compcert_va_int32 : Ident := identOfString "__compcert_va_int32"
def ___compcert_va_int64 : Ident := identOfString "__compcert_va_int64"
def ___kprog_a64_adrp_op : Ident := identOfString "__kprog_a64_adrp_op"
def ___kprog_a64_adrp_tag : Ident := identOfString "__kprog_a64_adrp_tag"
def ___kprog_a64_bf_bits : Ident := identOfString "__kprog_a64_bf_bits"
def ___kprog_a64_bf_dst : Ident := identOfString "__kprog_a64_bf_dst"
def ___kprog_a64_bf_field : Ident := identOfString "__kprog_a64_bf_field"
def ___kprog_a64_bf_kind : Ident := identOfString "__kprog_a64_bf_kind"
def ___kprog_a64_bf_lsb : Ident := identOfString "__kprog_a64_bf_lsb"
def ___kprog_a64_bf_mask : Ident := identOfString "__kprog_a64_bf_mask"
def ___kprog_a64_bf_result : Ident := identOfString "__kprog_a64_bf_result"
def ___kprog_a64_bf_sign : Ident := identOfString "__kprog_a64_bf_sign"
def ___kprog_a64_bf_src : Ident := identOfString "__kprog_a64_bf_src"
def ___kprog_a64_bf_src_l : Ident := identOfString "__kprog_a64_bf_src_l"
def ___kprog_a64_bf_src_r : Ident := identOfString "__kprog_a64_bf_src_r"
def ___kprog_a64_cneg_op : Ident := identOfString "__kprog_a64_cneg_op"
def ___kprog_a64_cneg_result : Ident := identOfString "__kprog_a64_cneg_result"
def ___kprog_a64_cneg_taken : Ident := identOfString "__kprog_a64_cneg_taken"
def ___kprog_a64_cneg_value : Ident := identOfString "__kprog_a64_cneg_value"
def ___kprog_a64_cneg_width : Ident := identOfString "__kprog_a64_cneg_width"
def ___kprog_a64_cneg_wmask : Ident := identOfString "__kprog_a64_cneg_wmask"
def ___kprog_a64_csel_op : Ident := identOfString "__kprog_a64_csel_op"
def ___kprog_a64_csel_result : Ident := identOfString "__kprog_a64_csel_result"
def ___kprog_a64_csel_src : Ident := identOfString "__kprog_a64_csel_src"
def ___kprog_a64_csel_src2 : Ident := identOfString "__kprog_a64_csel_src2"
def ___kprog_a64_csel_taken : Ident := identOfString "__kprog_a64_csel_taken"
def ___kprog_a64_ext_bits : Ident := identOfString "__kprog_a64_ext_bits"
def ___kprog_a64_ext_op : Ident := identOfString "__kprog_a64_ext_op"
def ___kprog_a64_ext_result : Ident := identOfString "__kprog_a64_ext_result"
def ___kprog_a64_ext_shift : Ident := identOfString "__kprog_a64_ext_shift"
def ___kprog_a64_ext_src : Ident := identOfString "__kprog_a64_ext_src"
def ___kprog_a64_ext_src2 : Ident := identOfString "__kprog_a64_ext_src2"
def ___kprog_a64_ext_w32 : Ident := identOfString "__kprog_a64_ext_w32"
def ___kprog_a64_ext_width : Ident := identOfString "__kprog_a64_ext_width"
def ___kprog_a64_fmd_dir : Ident := identOfString "__kprog_a64_fmd_dir"
def ___kprog_a64_fmd_v0 : Ident := identOfString "__kprog_a64_fmd_v0"
def ___kprog_a64_fmov_dir : Ident := identOfString "__kprog_a64_fmov_dir"
def ___kprog_a64_fmov_result : Ident := identOfString "__kprog_a64_fmov_result"
def ___kprog_a64_fmov_src : Ident := identOfString "__kprog_a64_fmov_src"
def ___kprog_a64_fmov_v0 : Ident := identOfString "__kprog_a64_fmov_v0"
def ___kprog_a64_io_operand : Ident := identOfString "__kprog_a64_io_operand"
def ___kprog_a64_mod : Ident := identOfString "__kprog_a64_mod"
def ___kprog_a64_mod_amount : Ident := identOfString "__kprog_a64_mod_amount"
def ___kprog_a64_mod_shift : Ident := identOfString "__kprog_a64_mod_shift"
def ___kprog_a64_mod_value : Ident := identOfString "__kprog_a64_mod_value"
def ___kprog_a64_mod_w32 : Ident := identOfString "__kprog_a64_mod_w32"
def ___kprog_a64_mul_addend : Ident := identOfString "__kprog_a64_mul_addend"
def ___kprog_a64_mul_carry : Ident := identOfString "__kprog_a64_mul_carry"
def ___kprog_a64_mul_hi : Ident := identOfString "__kprog_a64_mul_hi"
def ___kprog_a64_mul_lhs : Ident := identOfString "__kprog_a64_mul_lhs"
def ___kprog_a64_mul_lo : Ident := identOfString "__kprog_a64_mul_lo"
def ___kprog_a64_mul_mid1 : Ident := identOfString "__kprog_a64_mul_mid1"
def ___kprog_a64_mul_mid2 : Ident := identOfString "__kprog_a64_mul_mid2"
def ___kprog_a64_mul_op : Ident := identOfString "__kprog_a64_mul_op"
def ___kprog_a64_mul_result : Ident := identOfString "__kprog_a64_mul_result"
def ___kprog_a64_mul_rhs : Ident := identOfString "__kprog_a64_mul_rhs"
def ___kprog_a64_shift_32 : Ident := identOfString "__kprog_a64_shift_32"
def ___kprog_a64_shift_amount : Ident := identOfString "__kprog_a64_shift_amount"
def ___kprog_a64_shift_k : Ident := identOfString "__kprog_a64_shift_k"
def ___kprog_a64_shift_op : Ident := identOfString "__kprog_a64_shift_op"
def ___kprog_a64_shift_result : Ident := identOfString "__kprog_a64_shift_result"
def ___kprog_a64_shift_value : Ident := identOfString "__kprog_a64_shift_value"
def ___kprog_a64_shift_w32 : Ident := identOfString "__kprog_a64_shift_w32"
def ___kprog_a64_shift_width : Ident := identOfString "__kprog_a64_shift_width"
def ___kprog_a64_shift_wmask : Ident := identOfString "__kprog_a64_shift_wmask"
def ___kprog_a64_un_op : Ident := identOfString "__kprog_a64_un_op"
def ___kprog_a64_un_result : Ident := identOfString "__kprog_a64_un_result"
def ___kprog_a64_un_value : Ident := identOfString "__kprog_a64_un_value"
def ___kprog_a64_un_width : Ident := identOfString "__kprog_a64_un_width"
def ___kprog_a64_un_wmask : Ident := identOfString "__kprog_a64_un_wmask"
def ___kprog_alu64_res : Ident := identOfString "__kprog_alu64_res"
def _addend : Ident := identOfString "addend"
def _amount : Ident := identOfString "amount"
def _arm64_sim_unsupported_opcode : Ident := identOfString "arm64_sim_unsupported_opcode"
def _bits : Ident := identOfString "bits"
def _dir : Ident := identOfString "dir"
def _dst : Ident := identOfString "dst"
def _imm : Ident := identOfString "imm"
def _kind : Ident := identOfString "kind"
def _kprog_arm64_adrp : Ident := identOfString "kprog_arm64_adrp"
def _kprog_arm64_alu_result : Ident := identOfString "kprog_arm64_alu_result"
def _kprog_arm64_bitfield : Ident := identOfString "kprog_arm64_bitfield"
def _kprog_arm64_cneg : Ident := identOfString "kprog_arm64_cneg"
def _kprog_arm64_csel : Ident := identOfString "kprog_arm64_csel"
def _kprog_arm64_extrev : Ident := identOfString "kprog_arm64_extrev"
def _kprog_arm64_fmov : Ident := identOfString "kprog_arm64_fmov"
def _kprog_arm64_fmov_dest : Ident := identOfString "kprog_arm64_fmov_dest"
def _kprog_arm64_imm_operand : Ident := identOfString "kprog_arm64_imm_operand"
def _kprog_arm64_mod : Ident := identOfString "kprog_arm64_mod"
def _kprog_arm64_mul : Ident := identOfString "kprog_arm64_mul"
def _kprog_arm64_shift : Ident := identOfString "kprog_arm64_shift"
def _kprog_arm64_unary : Ident := identOfString "kprog_arm64_unary"
def _lhs : Ident := identOfString "lhs"
def _lsb : Ident := identOfString "lsb"
def _main : Ident := identOfString "main"
def _mod : Ident := identOfString "mod"
def _op : Ident := identOfString "op"
def _reg : Ident := identOfString "reg"
def _result : Ident := identOfString "result"
def _rhs : Ident := identOfString "rhs"
def _shift : Ident := identOfString "shift"
def _src : Ident := identOfString "src"
def _src2 : Ident := identOfString "src2"
def _taken : Ident := identOfString "taken"
def _v0 : Ident := identOfString "v0"
def _value : Ident := identOfString "value"
def _width : Ident := identOfString "width"
def _t'1 : Ident := (Positive.ofNat 128)
def _t'2 : Ident := (Positive.ofNat 129)
def _t'3 : Ident := (Positive.ofNat 130)
def _t'4 : Ident := (Positive.ofNat 131)
def _t'5 : Ident := (Positive.ofNat 132)
def _t'6 : Ident := (Positive.ofNat 133)
def _t'7 : Ident := (Positive.ofNat 134)
def _t'8 : Ident := (Positive.ofNat 135)
def _t'9 : Ident := (Positive.ofNat 136)

def f_kprog_arm64_alu_result : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_op, tulong), (_lhs, tulong), (_rhs, tulong)],
  fn_vars := [],
  fn_temps := [(_result, tulong), (___kprog_alu64_res, tulong)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sset ___kprog_alu64_res
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) tulong))
      (Stmt.Ssequence
        (Stmt.Sswitch (Expr.Etempvar _op tulong)
          (LStmts.LScons (some 0)
            (Stmt.Ssequence
              (Stmt.Sset ___kprog_alu64_res
                (Expr.Ebinop Binop.Oadd (Expr.Etempvar _lhs tulong)
                  (Expr.Etempvar _rhs tulong) tulong))
              Stmt.Sbreak)
            (LStmts.LScons (some 1)
              (Stmt.Ssequence
                (Stmt.Sset ___kprog_alu64_res
                  (Expr.Ebinop Binop.Osub (Expr.Etempvar _lhs tulong)
                    (Expr.Etempvar _rhs tulong) tulong))
                Stmt.Sbreak)
              (LStmts.LScons (some 2)
                (Stmt.Ssequence
                  (Stmt.Sset ___kprog_alu64_res
                    (Expr.Ebinop Binop.Oand (Expr.Etempvar _lhs tulong)
                      (Expr.Etempvar _rhs tulong) tulong))
                  Stmt.Sbreak)
                (LStmts.LScons (some 3)
                  (Stmt.Ssequence
                    (Stmt.Sset ___kprog_alu64_res
                      (Expr.Ebinop Binop.Oand (Expr.Etempvar _lhs tulong)
                        (Expr.Eunop Unop.Onotint (Expr.Etempvar _rhs tulong)
                          tulong) tulong))
                    Stmt.Sbreak)
                  (LStmts.LScons (some 4)
                    (Stmt.Ssequence
                      (Stmt.Sset ___kprog_alu64_res
                        (Expr.Ebinop Binop.Oxor (Expr.Etempvar _lhs tulong)
                          (Expr.Etempvar _rhs tulong) tulong))
                      Stmt.Sbreak)
                    (LStmts.LScons (some 5)
                      (Stmt.Ssequence
                        (Stmt.Sset ___kprog_alu64_res
                          (Expr.Ebinop Binop.Oor (Expr.Etempvar _lhs tulong)
                            (Expr.Etempvar _rhs tulong) tulong))
                        Stmt.Sbreak)
                      (LStmts.LScons none
                        (Stmt.Ssequence
                          (Stmt.Sloop
                            (Stmt.Scall none
                              (Expr.Evar _arm64_sim_unsupported_opcode 
                              (Ty.Tfunction [] tvoid cc_default)) [])
                            Stmt.Sbreak)
                          Stmt.Sbreak)
                        LStmts.LSnil))))))))
        (Stmt.Sset _result (Expr.Etempvar ___kprog_alu64_res tulong))))
    Stmt.Sbreak)
  (Stmt.Sreturn (some (Expr.Etempvar _result tulong))))
}

@[noinline] def s_kprog_arm64_mod_0 : Stmt :=
(Stmt.Sset _t'2
  (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 65535) tulong) tulong))

@[noinline] def s_kprog_arm64_mod_1 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'2
      (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 4294967295) tulong)
        tulong))
    (Stmt.Sset _t'2 (Expr.Ecast (Expr.Etempvar _t'2 tulong) tulong)))
  (Stmt.Sset _t'2 (Expr.Ecast (Expr.Etempvar _t'2 tulong) tulong)))

@[noinline] def s_kprog_arm64_mod_2 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'2
      (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr (-1)) tulong)
        tulong))
    (Stmt.Sset _t'2 (Expr.Ecast (Expr.Etempvar _t'2 tulong) tulong)))
  (Stmt.Sset _t'2 (Expr.Ecast (Expr.Etempvar _t'2 tulong) tulong)))

@[noinline] def s_kprog_arm64_mod_3 : Stmt :=
(Stmt.Sset _t'3
  (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 65535) tulong) tulong))

@[noinline] def s_kprog_arm64_mod_4 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'3
      (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 4294967295) tulong)
        tulong))
    (Stmt.Sset _t'3 (Expr.Ecast (Expr.Etempvar _t'3 tulong) tulong)))
  (Stmt.Sset _t'3 (Expr.Ecast (Expr.Etempvar _t'3 tulong) tulong)))

@[noinline] def s_kprog_arm64_mod_5 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'3
      (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr (-1)) tulong)
        tulong))
    (Stmt.Sset _t'3 (Expr.Ecast (Expr.Etempvar _t'3 tulong) tulong)))
  (Stmt.Sset _t'3 (Expr.Ecast (Expr.Etempvar _t'3 tulong) tulong)))

@[noinline] def s_kprog_arm64_mod_6 : Stmt :=
(Stmt.Sset _t'4
  (Expr.Ecast
    (Expr.Ecast
      (Expr.Ebinop Binop.Oor
        (Expr.Ebinop Binop.Oshr (Expr.Etempvar ___kprog_a64_mod_w32 tuint)
          (Expr.Etempvar ___kprog_a64_mod_amount tuchar) tuint)
        (Expr.Ebinop Binop.Oshl (Expr.Etempvar ___kprog_a64_mod_w32 tuint)
          (Expr.Ebinop Binop.Osub
            (Expr.Econst_int (Integers.Int.repr 32) tuint)
            (Expr.Etempvar ___kprog_a64_mod_amount tuchar) tuint) tuint)
        tuint) tulong) tulong))

@[noinline] def s_kprog_arm64_mod_7 : Stmt :=
(Stmt.Sset _t'4
  (Expr.Ecast (Expr.Ecast (Expr.Etempvar ___kprog_a64_mod_w32 tuint) tulong)
    tulong))

def f_kprog_arm64_mod : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_mod, tulong), (_value, tulong), (_shift, tulong),
                (_width, tulong)],
  fn_vars := [],
  fn_temps := [(_result, tulong), (___kprog_a64_mod_value, tulong),
               (___kprog_a64_mod, tuchar), (___kprog_a64_mod_shift, tuchar),
               (___kprog_a64_mod_amount, tuchar),
               (___kprog_a64_mod_w32, tuint), (_t'4, tulong), (_t'3, tulong),
               (_t'2, tulong), (_t'1, tuint)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sset ___kprog_a64_mod_value (Expr.Etempvar _value tulong))
      (Stmt.Ssequence
        (Stmt.Sset ___kprog_a64_mod
          (Expr.Ecast (Expr.Etempvar _mod tulong) tuchar))
        (Stmt.Ssequence
          (Stmt.Sset ___kprog_a64_mod_shift
            (Expr.Ecast (Expr.Etempvar _shift tulong) tuchar))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar _width tulong)
                                  (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                  tint)
                (Stmt.Sset _t'1
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 31) tuint)
                    tuint))
                (Stmt.Sset _t'1
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 63) tuint)
                    tuint)))
              (Stmt.Sset ___kprog_a64_mod_amount
                (Expr.Ecast
                  (Expr.Ecast
                    (Expr.Ebinop Binop.Oand
                      (Expr.Etempvar ___kprog_a64_mod_shift tuchar)
                      (Expr.Etempvar _t'1 tuint) tuint) tuchar) tuchar)))
            (Stmt.Ssequence
              (Stmt.Sswitch (Expr.Etempvar ___kprog_a64_mod tuchar)
                (LStmts.LScons (some 0)
                  Stmt.Sbreak
                  (LStmts.LScons (some 1)
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Etempvar _width tulong)
                                            (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                            tint)
                          (Stmt.Sset _t'2
                            (Expr.Ecast
                              (Expr.Econst_long (Integers.Int64.repr 255) tulong)
                              tulong))
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Etempvar _width tulong)
                                              (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                              tint)
                            (Stmt.Ssequence
                              s_kprog_arm64_mod_0
                              (Stmt.Sset _t'2
                                (Expr.Ecast (Expr.Etempvar _t'2 tulong)
                                  tulong)))
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                (Expr.Etempvar _width tulong)
                                                (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                                tint)
                              s_kprog_arm64_mod_1
                              s_kprog_arm64_mod_2)))
                        (Stmt.Sset ___kprog_a64_mod_value
                          (Expr.Ebinop Binop.Oand
                            (Expr.Ebinop Binop.Oshl
                              (Expr.Etempvar ___kprog_a64_mod_value tulong)
                              (Expr.Etempvar ___kprog_a64_mod_amount tuchar)
                              tulong) (Expr.Etempvar _t'2 tulong) tulong)))
                      Stmt.Sbreak)
                    (LStmts.LScons (some 2)
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Etempvar _width tulong)
                                              (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                              tint)
                            (Stmt.Sset _t'3
                              (Expr.Ecast
                                (Expr.Econst_long (Integers.Int64.repr 255) tulong)
                                tulong))
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                (Expr.Etempvar _width tulong)
                                                (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                                tint)
                              (Stmt.Ssequence
                                s_kprog_arm64_mod_3
                                (Stmt.Sset _t'3
                                  (Expr.Ecast (Expr.Etempvar _t'3 tulong)
                                    tulong)))
                              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                  (Expr.Etempvar _width tulong)
                                                  (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                                  tint)
                                s_kprog_arm64_mod_4
                                s_kprog_arm64_mod_5)))
                          (Stmt.Sset ___kprog_a64_mod_value
                            (Expr.Ebinop Binop.Oshr
                              (Expr.Ebinop Binop.Oand
                                (Expr.Etempvar ___kprog_a64_mod_value tulong)
                                (Expr.Etempvar _t'3 tulong) tulong)
                              (Expr.Etempvar ___kprog_a64_mod_amount tuchar)
                              tulong)))
                        Stmt.Sbreak)
                      (LStmts.LScons (some 3)
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Etempvar _width tulong)
                                              (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                              tint)
                            (Stmt.Sset ___kprog_a64_mod_value
                              (Expr.Ecast
                                (Expr.Ebinop Binop.Oshr
                                  (Expr.Ecast
                                    (Expr.Etempvar ___kprog_a64_mod_value tulong)
                                    tint)
                                  (Expr.Etempvar ___kprog_a64_mod_amount tuchar)
                                  tint) tulong))
                            (Stmt.Sset ___kprog_a64_mod_value
                              (Expr.Ecast
                                (Expr.Ebinop Binop.Oshr
                                  (Expr.Ecast
                                    (Expr.Etempvar ___kprog_a64_mod_value tulong)
                                    tlong)
                                  (Expr.Etempvar ___kprog_a64_mod_amount tuchar)
                                  tlong) tulong)))
                          Stmt.Sbreak)
                        (LStmts.LScons (some 4)
                          (Stmt.Ssequence
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                (Expr.Etempvar _width tulong)
                                                (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                                tint)
                              (Stmt.Ssequence
                                (Stmt.Sset ___kprog_a64_mod_w32
                                  (Expr.Ecast
                                    (Expr.Etempvar ___kprog_a64_mod_value tulong)
                                    tuint))
                                (Stmt.Ssequence
                                  (Stmt.Sifthenelse (Expr.Etempvar ___kprog_a64_mod_amount tuchar)
                                    s_kprog_arm64_mod_6
                                    s_kprog_arm64_mod_7)
                                  (Stmt.Sset ___kprog_a64_mod_value
                                    (Expr.Etempvar _t'4 tulong))))
                              (Stmt.Sifthenelse (Expr.Etempvar ___kprog_a64_mod_amount tuchar)
                                (Stmt.Sset ___kprog_a64_mod_value
                                  (Expr.Ebinop Binop.Oor
                                    (Expr.Ebinop Binop.Oshr
                                      (Expr.Etempvar ___kprog_a64_mod_value tulong)
                                      (Expr.Etempvar ___kprog_a64_mod_amount tuchar)
                                      tulong)
                                    (Expr.Ebinop Binop.Oshl
                                      (Expr.Etempvar ___kprog_a64_mod_value tulong)
                                      (Expr.Ebinop Binop.Osub
                                        (Expr.Econst_int (Integers.Int.repr 64) tuint)
                                        (Expr.Etempvar ___kprog_a64_mod_amount tuchar)
                                        tuint) tulong) tulong))
                                Stmt.Sskip))
                            Stmt.Sbreak)
                          (LStmts.LScons (some 5)
                            (Stmt.Ssequence
                              (Stmt.Sset ___kprog_a64_mod_value
                                (Expr.Ebinop Binop.Oshl
                                  (Expr.Ecast
                                    (Expr.Ecast
                                      (Expr.Etempvar ___kprog_a64_mod_value tulong)
                                      tuint) tulong)
                                  (Expr.Etempvar ___kprog_a64_mod_shift tuchar)
                                  tulong))
                              Stmt.Sbreak)
                            (LStmts.LScons (some 6)
                              (Stmt.Ssequence
                                (Stmt.Sset ___kprog_a64_mod_value
                                  (Expr.Ebinop Binop.Oshl
                                    (Expr.Ecast
                                      (Expr.Ecast
                                        (Expr.Ecast
                                          (Expr.Etempvar ___kprog_a64_mod_value tulong)
                                          tint) tlong) tulong)
                                    (Expr.Etempvar ___kprog_a64_mod_shift tuchar)
                                    tulong))
                                Stmt.Sbreak)
                              (LStmts.LScons (some 7)
                                (Stmt.Ssequence
                                  (Stmt.Sset ___kprog_a64_mod_value
                                    (Expr.Ebinop Binop.Oshl
                                      (Expr.Ecast
                                        (Expr.Ecast
                                          (Expr.Etempvar ___kprog_a64_mod_value tulong)
                                          tushort) tulong)
                                      (Expr.Etempvar ___kprog_a64_mod_shift tuchar)
                                      tulong))
                                  Stmt.Sbreak)
                                (LStmts.LScons (some 8)
                                  (Stmt.Ssequence
                                    (Stmt.Sset ___kprog_a64_mod_value
                                      (Expr.Ebinop Binop.Oshl
                                        (Expr.Ecast
                                          (Expr.Ecast
                                            (Expr.Ecast
                                              (Expr.Etempvar ___kprog_a64_mod_value tulong)
                                              tshort) tlong) tulong)
                                        (Expr.Etempvar ___kprog_a64_mod_shift tuchar)
                                        tulong))
                                    Stmt.Sbreak)
                                  (LStmts.LScons (some 9)
                                    (Stmt.Ssequence
                                      (Stmt.Sset ___kprog_a64_mod_value
                                        (Expr.Ebinop Binop.Oshl
                                          (Expr.Ecast
                                            (Expr.Ecast
                                              (Expr.Etempvar ___kprog_a64_mod_value tulong)
                                              tuchar) tulong)
                                          (Expr.Etempvar ___kprog_a64_mod_shift tuchar)
                                          tulong))
                                      Stmt.Sbreak)
                                    (LStmts.LScons (some 10)
                                      (Stmt.Ssequence
                                        (Stmt.Sset ___kprog_a64_mod_value
                                          (Expr.Ebinop Binop.Oshl
                                            (Expr.Ecast
                                              (Expr.Ecast
                                                (Expr.Ecast
                                                  (Expr.Etempvar ___kprog_a64_mod_value tulong)
                                                  tschar) tlong) tulong)
                                            (Expr.Etempvar ___kprog_a64_mod_shift tuchar)
                                            tulong))
                                        Stmt.Sbreak)
                                      LStmts.LSnil))))))))))))
              (Stmt.Sset _result
                (Expr.Etempvar ___kprog_a64_mod_value tulong)))))))
    Stmt.Sbreak)
  (Stmt.Sreturn (some (Expr.Etempvar _result tulong))))
}

@[noinline] def s_kprog_arm64_shift_0 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'1
    (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 4294967295) tulong)
      tulong))
  (Stmt.Sset _t'1 (Expr.Ecast (Expr.Etempvar _t'1 tulong) tulong)))

@[noinline] def s_kprog_arm64_shift_1 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'1
    (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr (-1)) tulong) tulong))
  (Stmt.Sset _t'1 (Expr.Ecast (Expr.Etempvar _t'1 tulong) tulong)))

@[noinline] def s_kprog_arm64_shift_2 : Stmt :=
(Stmt.Sset _t'3
  (Expr.Ecast
    (Expr.Ecast
      (Expr.Ebinop Binop.Oshr
        (Expr.Ecast (Expr.Etempvar ___kprog_a64_shift_value tulong) tint)
        (Expr.Etempvar ___kprog_a64_shift_k tulong) tint) tulong) tulong))

@[noinline] def s_kprog_arm64_shift_3 : Stmt :=
(Stmt.Sset _t'3
  (Expr.Ecast
    (Expr.Ecast
      (Expr.Ebinop Binop.Oshr
        (Expr.Ecast (Expr.Etempvar ___kprog_a64_shift_value tulong) tlong)
        (Expr.Etempvar ___kprog_a64_shift_k tulong) tlong) tulong) tulong))

@[noinline] def s_kprog_arm64_shift_4 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___kprog_a64_shift_w32
    (Expr.Ecast (Expr.Etempvar ___kprog_a64_shift_value tulong) tuint))
  (Stmt.Ssequence
    (Stmt.Sifthenelse (Expr.Etempvar ___kprog_a64_shift_k tulong)
      (Stmt.Sset _t'4
        (Expr.Ecast
          (Expr.Ecast
            (Expr.Ebinop Binop.Oor
              (Expr.Ebinop Binop.Oshr
                (Expr.Etempvar ___kprog_a64_shift_w32 tuint)
                (Expr.Etempvar ___kprog_a64_shift_k tulong) tuint)
              (Expr.Ebinop Binop.Oshl
                (Expr.Etempvar ___kprog_a64_shift_w32 tuint)
                (Expr.Ebinop Binop.Osub
                  (Expr.Econst_int (Integers.Int.repr 32) tuint)
                  (Expr.Etempvar ___kprog_a64_shift_k tulong) tulong) tuint)
              tuint) tulong) tulong))
      (Stmt.Sset _t'4
        (Expr.Ecast
          (Expr.Ecast (Expr.Etempvar ___kprog_a64_shift_w32 tuint) tulong)
          tulong)))
    (Stmt.Sset ___kprog_a64_shift_result (Expr.Etempvar _t'4 tulong))))

@[noinline] def s_kprog_arm64_shift_5 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Etempvar ___kprog_a64_shift_k tulong)
    (Stmt.Sset _t'5
      (Expr.Ecast
        (Expr.Ebinop Binop.Oor
          (Expr.Ebinop Binop.Oshr
            (Expr.Etempvar ___kprog_a64_shift_value tulong)
            (Expr.Etempvar ___kprog_a64_shift_k tulong) tulong)
          (Expr.Ebinop Binop.Oshl
            (Expr.Etempvar ___kprog_a64_shift_value tulong)
            (Expr.Ebinop Binop.Osub
              (Expr.Econst_int (Integers.Int.repr 64) tuint)
              (Expr.Etempvar ___kprog_a64_shift_k tulong) tulong) tulong)
          tulong) tulong))
    (Stmt.Sset _t'5
      (Expr.Ecast (Expr.Etempvar ___kprog_a64_shift_value tulong) tulong)))
  (Stmt.Sset ___kprog_a64_shift_result (Expr.Etempvar _t'5 tulong)))

def f_kprog_arm64_shift : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_shift, tulong), (_value, tulong), (_amount, tulong),
                (_width, tulong)],
  fn_vars := [],
  fn_temps := [(_result, tulong), (___kprog_a64_shift_op, tulong),
               (___kprog_a64_shift_value, tulong),
               (___kprog_a64_shift_amount, tulong),
               (___kprog_a64_shift_width, tulong),
               (___kprog_a64_shift_32, tint),
               (___kprog_a64_shift_wmask, tulong),
               (___kprog_a64_shift_k, tulong),
               (___kprog_a64_shift_result, tulong),
               (___kprog_a64_shift_w32, tuint), (_t'5, tulong),
               (_t'4, tulong), (_t'3, tulong), (_t'2, tulong),
               (_t'1, tulong)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sset ___kprog_a64_shift_op (Expr.Etempvar _shift tulong))
      (Stmt.Ssequence
        (Stmt.Sset ___kprog_a64_shift_value (Expr.Etempvar _value tulong))
        (Stmt.Ssequence
          (Stmt.Sset ___kprog_a64_shift_amount
            (Expr.Etempvar _amount tulong))
          (Stmt.Ssequence
            (Stmt.Sset ___kprog_a64_shift_width
              (Expr.Etempvar _width tulong))
            (Stmt.Ssequence
              (Stmt.Sset ___kprog_a64_shift_32
                (Expr.Ebinop Binop.Oeq
                  (Expr.Etempvar ___kprog_a64_shift_width tulong)
                  (Expr.Econst_int (Integers.Int.repr 4) tuint) tint))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar ___kprog_a64_shift_width tulong)
                                      (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                      tint)
                    (Stmt.Sset _t'1
                      (Expr.Ecast
                        (Expr.Econst_long (Integers.Int64.repr 255) tulong)
                        tulong))
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Etempvar ___kprog_a64_shift_width tulong)
                                        (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                        tint)
                      (Stmt.Ssequence
                        (Stmt.Sset _t'1
                          (Expr.Ecast
                            (Expr.Econst_long (Integers.Int64.repr 65535) tulong)
                            tulong))
                        (Stmt.Sset _t'1
                          (Expr.Ecast (Expr.Etempvar _t'1 tulong) tulong)))
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Etempvar ___kprog_a64_shift_width tulong)
                                          (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                          tint)
                        (Stmt.Ssequence
                          s_kprog_arm64_shift_0
                          (Stmt.Sset _t'1
                            (Expr.Ecast (Expr.Etempvar _t'1 tulong) tulong)))
                        (Stmt.Ssequence
                          s_kprog_arm64_shift_1
                          (Stmt.Sset _t'1
                            (Expr.Ecast (Expr.Etempvar _t'1 tulong) tulong))))))
                  (Stmt.Sset ___kprog_a64_shift_wmask
                    (Expr.Etempvar _t'1 tulong)))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Etempvar ___kprog_a64_shift_width tulong)
                                        (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                        tint)
                      (Stmt.Sset _t'2
                        (Expr.Ecast
                          (Expr.Econst_long (Integers.Int64.repr 31) tulong)
                          tulong))
                      (Stmt.Sset _t'2
                        (Expr.Ecast
                          (Expr.Econst_long (Integers.Int64.repr 63) tulong)
                          tulong)))
                    (Stmt.Sset ___kprog_a64_shift_k
                      (Expr.Ebinop Binop.Oand
                        (Expr.Etempvar ___kprog_a64_shift_amount tulong)
                        (Expr.Etempvar _t'2 tulong) tulong)))
                  (Stmt.Ssequence
                    (Stmt.Sset ___kprog_a64_shift_result
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 0) tint) tulong))
                    (Stmt.Ssequence
                      (Stmt.Sswitch (Expr.Etempvar ___kprog_a64_shift_op tulong)
                        (LStmts.LScons (some 0)
                          (Stmt.Ssequence
                            (Stmt.Sset ___kprog_a64_shift_result
                              (Expr.Ebinop Binop.Oand
                                (Expr.Ebinop Binop.Oshl
                                  (Expr.Etempvar ___kprog_a64_shift_value tulong)
                                  (Expr.Etempvar ___kprog_a64_shift_k tulong)
                                  tulong)
                                (Expr.Etempvar ___kprog_a64_shift_wmask tulong)
                                tulong))
                            Stmt.Sbreak)
                          (LStmts.LScons (some 1)
                            (Stmt.Ssequence
                              (Stmt.Sset ___kprog_a64_shift_result
                                (Expr.Ebinop Binop.Oshr
                                  (Expr.Ebinop Binop.Oand
                                    (Expr.Etempvar ___kprog_a64_shift_value tulong)
                                    (Expr.Etempvar ___kprog_a64_shift_wmask tulong)
                                    tulong)
                                  (Expr.Etempvar ___kprog_a64_shift_k tulong)
                                  tulong))
                              Stmt.Sbreak)
                            (LStmts.LScons (some 2)
                              (Stmt.Ssequence
                                (Stmt.Ssequence
                                  (Stmt.Sifthenelse (Expr.Etempvar ___kprog_a64_shift_32 tint)
                                    s_kprog_arm64_shift_2
                                    s_kprog_arm64_shift_3)
                                  (Stmt.Sset ___kprog_a64_shift_result
                                    (Expr.Etempvar _t'3 tulong)))
                                Stmt.Sbreak)
                              (LStmts.LScons (some 3)
                                (Stmt.Ssequence
                                  (Stmt.Sifthenelse (Expr.Etempvar ___kprog_a64_shift_32 tint)
                                    s_kprog_arm64_shift_4
                                    s_kprog_arm64_shift_5)
                                  Stmt.Sbreak)
                                (LStmts.LScons none
                                  (Stmt.Ssequence
                                    (Stmt.Sloop
                                      (Stmt.Scall none
                                        (Expr.Evar _arm64_sim_unsupported_opcode 
                                        (Ty.Tfunction [] tvoid cc_default))
                                        [])
                                      Stmt.Sbreak)
                                    Stmt.Sbreak)
                                  LStmts.LSnil))))))
                      (Stmt.Sset _result
                        (Expr.Etempvar ___kprog_a64_shift_result tulong)))))))))))
    Stmt.Sbreak)
  (Stmt.Sreturn (some (Expr.Etempvar _result tulong))))
}

@[noinline] def s_kprog_arm64_bitfield_0 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                    (Expr.Etempvar ___kprog_a64_bf_bits tuchar)
                    (Expr.Econst_int (Integers.Int.repr 64) tint) tint)
  (Stmt.Sset _t'6
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 63) tuint) tuint))
  (Stmt.Sset _t'6
    (Expr.Ecast
      (Expr.Ebinop Binop.Osub (Expr.Etempvar ___kprog_a64_bf_bits tuchar)
        (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint) tuint)))

@[noinline] def s_kprog_arm64_bitfield_1 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___kprog_a64_bf_result
    (Expr.Ebinop Binop.Oand (Expr.Etempvar ___kprog_a64_bf_src_r tulong)
      (Expr.Etempvar ___kprog_a64_bf_mask tulong) tulong))
  Stmt.Sbreak)

@[noinline] def s_kprog_arm64_bitfield_2 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                        (Expr.Etempvar ___kprog_a64_bf_bits tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tint) tint)
      (Stmt.Sset _t'7
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) tulong))
      (Stmt.Sset _t'7
        (Expr.Ecast
          (Expr.Ebinop Binop.Osub
            (Expr.Ebinop Binop.Oxor
              (Expr.Ebinop Binop.Oand
                (Expr.Etempvar ___kprog_a64_bf_src_r tulong)
                (Expr.Etempvar ___kprog_a64_bf_mask tulong) tulong)
              (Expr.Etempvar ___kprog_a64_bf_sign tulong) tulong)
            (Expr.Etempvar ___kprog_a64_bf_sign tulong) tulong) tulong)))
    (Stmt.Sset ___kprog_a64_bf_result (Expr.Etempvar _t'7 tulong)))
  Stmt.Sbreak)

@[noinline] def s_kprog_arm64_bitfield_3 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___kprog_a64_bf_result
    (Expr.Ebinop Binop.Oand (Expr.Etempvar ___kprog_a64_bf_src_l tulong)
      (Expr.Etempvar ___kprog_a64_bf_field tulong) tulong))
  Stmt.Sbreak)

@[noinline] def s_kprog_arm64_bitfield_4 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___kprog_a64_bf_result
    (Expr.Ebinop Binop.Oor
      (Expr.Ebinop Binop.Oand (Expr.Etempvar ___kprog_a64_bf_dst tulong)
        (Expr.Eunop Unop.Onotint (Expr.Etempvar ___kprog_a64_bf_mask tulong)
          tulong) tulong)
      (Expr.Ebinop Binop.Oand (Expr.Etempvar ___kprog_a64_bf_src_r tulong)
        (Expr.Etempvar ___kprog_a64_bf_mask tulong) tulong) tulong))
  Stmt.Sbreak)

@[noinline] def s_kprog_arm64_bitfield_5 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___kprog_a64_bf_result
    (Expr.Ebinop Binop.Oor
      (Expr.Ebinop Binop.Oand (Expr.Etempvar ___kprog_a64_bf_dst tulong)
        (Expr.Eunop Unop.Onotint (Expr.Etempvar ___kprog_a64_bf_field tulong)
          tulong) tulong)
      (Expr.Ebinop Binop.Oand (Expr.Etempvar ___kprog_a64_bf_src_l tulong)
        (Expr.Etempvar ___kprog_a64_bf_field tulong) tulong) tulong))
  Stmt.Sbreak)

@[noinline] def s_kprog_arm64_bitfield_6 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Scall none
      (Expr.Evar _arm64_sim_unsupported_opcode (Ty.Tfunction [] tvoid
                                                 cc_default)) [])
    Stmt.Sbreak)
  Stmt.Sbreak)

def f_kprog_arm64_bitfield : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_kind, tulong), (_src, tulong), (_dst, tulong),
                (_lsb, tulong), (_bits, tulong)],
  fn_vars := [],
  fn_temps := [(_result, tulong), (___kprog_a64_bf_src, tulong),
               (___kprog_a64_bf_dst, tulong), (___kprog_a64_bf_kind, tuchar),
               (___kprog_a64_bf_lsb, tuchar), (___kprog_a64_bf_bits, tuchar),
               (___kprog_a64_bf_mask, tulong),
               (___kprog_a64_bf_src_r, tulong),
               (___kprog_a64_bf_src_l, tulong),
               (___kprog_a64_bf_field, tulong),
               (___kprog_a64_bf_sign, tulong),
               (___kprog_a64_bf_result, tulong), (_t'7, tulong),
               (_t'6, tuint), (_t'5, tulong), (_t'4, tulong), (_t'3, tulong),
               (_t'2, tulong), (_t'1, tulong)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sset ___kprog_a64_bf_src (Expr.Etempvar _src tulong))
      (Stmt.Ssequence
        (Stmt.Sset ___kprog_a64_bf_dst (Expr.Etempvar _dst tulong))
        (Stmt.Ssequence
          (Stmt.Sset ___kprog_a64_bf_kind
            (Expr.Ecast (Expr.Etempvar _kind tulong) tuchar))
          (Stmt.Ssequence
            (Stmt.Sset ___kprog_a64_bf_lsb
              (Expr.Ecast (Expr.Etempvar _lsb tulong) tuchar))
            (Stmt.Ssequence
              (Stmt.Sset ___kprog_a64_bf_bits
                (Expr.Ecast (Expr.Etempvar _bits tulong) tuchar))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar ___kprog_a64_bf_bits tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 0) tint)
                                      tint)
                    (Stmt.Sset _t'1
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 0) tint) tulong))
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                        (Expr.Etempvar ___kprog_a64_bf_bits tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 64) tint)
                                        tint)
                      (Stmt.Ssequence
                        (Stmt.Sset _t'1
                          (Expr.Ecast
                            (Expr.Econst_long (Integers.Int64.repr (-1)) tulong)
                            tulong))
                        (Stmt.Sset _t'1
                          (Expr.Ecast (Expr.Etempvar _t'1 tulong) tulong)))
                      (Stmt.Ssequence
                        (Stmt.Sset _t'1
                          (Expr.Ecast
                            (Expr.Ebinop Binop.Osub
                              (Expr.Ebinop Binop.Oshl
                                (Expr.Econst_long (Integers.Int64.repr 1) tulong)
                                (Expr.Etempvar ___kprog_a64_bf_bits tuchar)
                                tulong)
                              (Expr.Econst_long (Integers.Int64.repr 1) tulong)
                              tulong) tulong))
                        (Stmt.Sset _t'1
                          (Expr.Ecast (Expr.Etempvar _t'1 tulong) tulong)))))
                  (Stmt.Sset ___kprog_a64_bf_mask
                    (Expr.Etempvar _t'1 tulong)))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                        (Expr.Etempvar ___kprog_a64_bf_lsb tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 64) tint)
                                        tint)
                      (Stmt.Sset _t'2
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                          tulong))
                      (Stmt.Sset _t'2
                        (Expr.Ecast
                          (Expr.Ebinop Binop.Oshr
                            (Expr.Etempvar ___kprog_a64_bf_src tulong)
                            (Expr.Etempvar ___kprog_a64_bf_lsb tuchar)
                            tulong) tulong)))
                    (Stmt.Sset ___kprog_a64_bf_src_r
                      (Expr.Etempvar _t'2 tulong)))
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                          (Expr.Etempvar ___kprog_a64_bf_lsb tuchar)
                                          (Expr.Econst_int (Integers.Int.repr 64) tint)
                                          tint)
                        (Stmt.Sset _t'3
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                            tulong))
                        (Stmt.Sset _t'3
                          (Expr.Ecast
                            (Expr.Ebinop Binop.Oshl
                              (Expr.Etempvar ___kprog_a64_bf_src tulong)
                              (Expr.Etempvar ___kprog_a64_bf_lsb tuchar)
                              tulong) tulong)))
                      (Stmt.Sset ___kprog_a64_bf_src_l
                        (Expr.Etempvar _t'3 tulong)))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                            (Expr.Etempvar ___kprog_a64_bf_lsb tuchar)
                                            (Expr.Econst_int (Integers.Int.repr 64) tint)
                                            tint)
                          (Stmt.Sset _t'4
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 0) tint)
                              tulong))
                          (Stmt.Sset _t'4
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Oshl
                                (Expr.Etempvar ___kprog_a64_bf_mask tulong)
                                (Expr.Etempvar ___kprog_a64_bf_lsb tuchar)
                                tulong) tulong)))
                        (Stmt.Sset ___kprog_a64_bf_field
                          (Expr.Etempvar _t'4 tulong)))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Etempvar ___kprog_a64_bf_bits tuchar)
                                              (Expr.Econst_int (Integers.Int.repr 0) tint)
                                              tint)
                            (Stmt.Sset _t'5
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 0) tint)
                                tulong))
                            (Stmt.Ssequence
                              s_kprog_arm64_bitfield_0
                              (Stmt.Sset _t'5
                                (Expr.Ecast
                                  (Expr.Ebinop Binop.Oshl
                                    (Expr.Econst_long (Integers.Int64.repr 1) tulong)
                                    (Expr.Etempvar _t'6 tuint) tulong)
                                  tulong))))
                          (Stmt.Sset ___kprog_a64_bf_sign
                            (Expr.Etempvar _t'5 tulong)))
                        (Stmt.Ssequence
                          (Stmt.Sset ___kprog_a64_bf_result
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 0) tint)
                              tulong))
                          (Stmt.Ssequence
                            (Stmt.Sswitch (Expr.Etempvar ___kprog_a64_bf_kind tuchar)
                              (LStmts.LScons (some 0)
                                s_kprog_arm64_bitfield_1
                                (LStmts.LScons (some 1)
                                  s_kprog_arm64_bitfield_2
                                  (LStmts.LScons (some 2)
                                    s_kprog_arm64_bitfield_3
                                    (LStmts.LScons (some 3)
                                      s_kprog_arm64_bitfield_4
                                      (LStmts.LScons (some 4)
                                        s_kprog_arm64_bitfield_5
                                        (LStmts.LScons none
                                          s_kprog_arm64_bitfield_6
                                          LStmts.LSnil)))))))
                            (Stmt.Sset _result
                              (Expr.Etempvar ___kprog_a64_bf_result tulong))))))))))))))
    Stmt.Sbreak)
  (Stmt.Sreturn (some (Expr.Etempvar _result tulong))))
}

@[noinline] def s_kprog_arm64_mul_0 : Stmt :=
(Stmt.Sset ___kprog_a64_mul_result
  (Expr.Ebinop Binop.Oadd
    (Expr.Ebinop Binop.Oadd
      (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___kprog_a64_mul_hi tulong)
        (Expr.Ebinop Binop.Oshr (Expr.Etempvar ___kprog_a64_mul_mid1 tulong)
          (Expr.Econst_int (Integers.Int.repr 32) tint) tulong) tulong)
      (Expr.Ebinop Binop.Oshr (Expr.Etempvar ___kprog_a64_mul_mid2 tulong)
        (Expr.Econst_int (Integers.Int.repr 32) tint) tulong) tulong)
    (Expr.Etempvar ___kprog_a64_mul_carry tulong) tulong))

def f_kprog_arm64_mul : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_op, tulong), (_lhs, tulong), (_rhs, tulong),
                (_addend, tulong)],
  fn_vars := [],
  fn_temps := [(_result, tulong), (___kprog_a64_mul_op, tulong),
               (___kprog_a64_mul_lhs, tulong),
               (___kprog_a64_mul_rhs, tulong),
               (___kprog_a64_mul_addend, tulong),
               (___kprog_a64_mul_result, tulong),
               (___kprog_a64_mul_lo, tulong),
               (___kprog_a64_mul_mid1, tulong),
               (___kprog_a64_mul_mid2, tulong),
               (___kprog_a64_mul_hi, tulong),
               (___kprog_a64_mul_carry, tulong), (_t'1, tulong)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sset ___kprog_a64_mul_op (Expr.Etempvar _op tulong))
      (Stmt.Ssequence
        (Stmt.Sset ___kprog_a64_mul_lhs (Expr.Etempvar _lhs tulong))
        (Stmt.Ssequence
          (Stmt.Sset ___kprog_a64_mul_rhs (Expr.Etempvar _rhs tulong))
          (Stmt.Ssequence
            (Stmt.Sset ___kprog_a64_mul_addend
              (Expr.Etempvar _addend tulong))
            (Stmt.Ssequence
              (Stmt.Sset ___kprog_a64_mul_result
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                  tulong))
              (Stmt.Ssequence
                (Stmt.Sswitch (Expr.Etempvar ___kprog_a64_mul_op tulong)
                  (LStmts.LScons (some 10)
                    (Stmt.Ssequence
                      (Stmt.Sset ___kprog_a64_mul_result
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Ebinop Binop.Omul
                            (Expr.Etempvar ___kprog_a64_mul_lhs tulong)
                            (Expr.Etempvar ___kprog_a64_mul_rhs tulong)
                            tulong)
                          (Expr.Etempvar ___kprog_a64_mul_addend tulong)
                          tulong))
                      Stmt.Sbreak)
                    (LStmts.LScons (some 11)
                      (Stmt.Ssequence
                        (Stmt.Sset ___kprog_a64_mul_result
                          (Expr.Ebinop Binop.Osub
                            (Expr.Etempvar ___kprog_a64_mul_addend tulong)
                            (Expr.Ebinop Binop.Omul
                              (Expr.Etempvar ___kprog_a64_mul_lhs tulong)
                              (Expr.Etempvar ___kprog_a64_mul_rhs tulong)
                              tulong) tulong))
                        Stmt.Sbreak)
                      (LStmts.LScons (some 12)
                        (Stmt.Ssequence
                          (Stmt.Sset ___kprog_a64_mul_result
                            (Expr.Ebinop Binop.Omul
                              (Expr.Etempvar ___kprog_a64_mul_lhs tulong)
                              (Expr.Etempvar ___kprog_a64_mul_rhs tulong)
                              tulong))
                          Stmt.Sbreak)
                        (LStmts.LScons (some 13)
                          (Stmt.Ssequence
                            (Stmt.Sset ___kprog_a64_mul_result
                              (Expr.Ebinop Binop.Omul
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Etempvar ___kprog_a64_mul_lhs tulong)
                                    tuint) tulong)
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Etempvar ___kprog_a64_mul_rhs tulong)
                                    tuint) tulong) tulong))
                            Stmt.Sbreak)
                          (LStmts.LScons (some 14)
                            (Stmt.Ssequence
                              (Stmt.Ssequence
                                (Stmt.Sifthenelse (Expr.Etempvar ___kprog_a64_mul_rhs tulong)
                                  (Stmt.Sset _t'1
                                    (Expr.Ecast
                                      (Expr.Ebinop Binop.Odiv
                                        (Expr.Etempvar ___kprog_a64_mul_lhs tulong)
                                        (Expr.Etempvar ___kprog_a64_mul_rhs tulong)
                                        tulong) tulong))
                                  (Stmt.Sset _t'1
                                    (Expr.Ecast
                                      (Expr.Econst_int (Integers.Int.repr 0) tint)
                                      tulong)))
                                (Stmt.Sset ___kprog_a64_mul_result
                                  (Expr.Etempvar _t'1 tulong)))
                              Stmt.Sbreak)
                            (LStmts.LScons (some 46)
                              (Stmt.Ssequence
                                (Stmt.Sset ___kprog_a64_mul_lo
                                  (Expr.Ebinop Binop.Omul
                                    (Expr.Ecast
                                      (Expr.Ecast
                                        (Expr.Etempvar ___kprog_a64_mul_lhs tulong)
                                        tuint) tulong)
                                    (Expr.Ecast
                                      (Expr.Ecast
                                        (Expr.Etempvar ___kprog_a64_mul_rhs tulong)
                                        tuint) tulong) tulong))
                                (Stmt.Ssequence
                                  (Stmt.Sset ___kprog_a64_mul_mid1
                                    (Expr.Ebinop Binop.Omul
                                      (Expr.Ebinop Binop.Oshr
                                        (Expr.Etempvar ___kprog_a64_mul_lhs tulong)
                                        (Expr.Econst_int (Integers.Int.repr 32) tint)
                                        tulong)
                                      (Expr.Ecast
                                        (Expr.Ecast
                                          (Expr.Etempvar ___kprog_a64_mul_rhs tulong)
                                          tuint) tulong) tulong))
                                  (Stmt.Ssequence
                                    (Stmt.Sset ___kprog_a64_mul_mid2
                                      (Expr.Ebinop Binop.Omul
                                        (Expr.Ecast
                                          (Expr.Ecast
                                            (Expr.Etempvar ___kprog_a64_mul_lhs tulong)
                                            tuint) tulong)
                                        (Expr.Ebinop Binop.Oshr
                                          (Expr.Etempvar ___kprog_a64_mul_rhs tulong)
                                          (Expr.Econst_int (Integers.Int.repr 32) tint)
                                          tulong) tulong))
                                    (Stmt.Ssequence
                                      (Stmt.Sset ___kprog_a64_mul_hi
                                        (Expr.Ebinop Binop.Omul
                                          (Expr.Ebinop Binop.Oshr
                                            (Expr.Etempvar ___kprog_a64_mul_lhs tulong)
                                            (Expr.Econst_int (Integers.Int.repr 32) tint)
                                            tulong)
                                          (Expr.Ebinop Binop.Oshr
                                            (Expr.Etempvar ___kprog_a64_mul_rhs tulong)
                                            (Expr.Econst_int (Integers.Int.repr 32) tint)
                                            tulong) tulong))
                                      (Stmt.Ssequence
                                        (Stmt.Sset ___kprog_a64_mul_carry
                                          (Expr.Ebinop Binop.Oshr
                                            (Expr.Ebinop Binop.Oadd
                                              (Expr.Ebinop Binop.Oadd
                                                (Expr.Ebinop Binop.Oshr
                                                  (Expr.Etempvar ___kprog_a64_mul_lo tulong)
                                                  (Expr.Econst_int (Integers.Int.repr 32) tint)
                                                  tulong)
                                                (Expr.Ecast
                                                  (Expr.Ecast
                                                    (Expr.Etempvar ___kprog_a64_mul_mid1 tulong)
                                                    tuint) tulong) tulong)
                                              (Expr.Ecast
                                                (Expr.Ecast
                                                  (Expr.Etempvar ___kprog_a64_mul_mid2 tulong)
                                                  tuint) tulong) tulong)
                                            (Expr.Econst_int (Integers.Int.repr 32) tint)
                                            tulong))
                                        (Stmt.Ssequence
                                          s_kprog_arm64_mul_0
                                          Stmt.Sbreak))))))
                              (LStmts.LScons (some 59)
                                (Stmt.Ssequence
                                  (Stmt.Sset ___kprog_a64_mul_result
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Ebinop Binop.Omul
                                        (Expr.Ecast
                                          (Expr.Ecast
                                            (Expr.Etempvar ___kprog_a64_mul_lhs tulong)
                                            tuint) tulong)
                                        (Expr.Ecast
                                          (Expr.Ecast
                                            (Expr.Etempvar ___kprog_a64_mul_rhs tulong)
                                            tuint) tulong) tulong)
                                      (Expr.Etempvar ___kprog_a64_mul_addend tulong)
                                      tulong))
                                  Stmt.Sbreak)
                                (LStmts.LScons (some 64)
                                  (Stmt.Ssequence
                                    (Stmt.Sset ___kprog_a64_mul_result
                                      (Expr.Ebinop Binop.Oadd
                                        (Expr.Ecast
                                          (Expr.Ebinop Binop.Omul
                                            (Expr.Ecast
                                              (Expr.Ecast
                                                (Expr.Etempvar ___kprog_a64_mul_lhs tulong)
                                                tint) tlong)
                                            (Expr.Ecast
                                              (Expr.Ecast
                                                (Expr.Etempvar ___kprog_a64_mul_rhs tulong)
                                                tint) tlong) tlong) tulong)
                                        (Expr.Etempvar ___kprog_a64_mul_addend tulong)
                                        tulong))
                                    Stmt.Sbreak)
                                  (LStmts.LScons none
                                    (Stmt.Ssequence
                                      (Stmt.Sloop
                                        (Stmt.Scall none
                                          (Expr.Evar _arm64_sim_unsupported_opcode 
                                          (Ty.Tfunction [] tvoid cc_default))
                                          [])
                                        Stmt.Sbreak)
                                      Stmt.Sbreak)
                                    LStmts.LSnil))))))))))
                (Stmt.Sset _result
                  (Expr.Etempvar ___kprog_a64_mul_result tulong))))))))
    Stmt.Sbreak)
  (Stmt.Sreturn (some (Expr.Etempvar _result tulong))))
}

@[noinline] def s_kprog_arm64_extrev_0 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'1
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 32) tuint) tuint))
  (Stmt.Sset _t'1 (Expr.Ecast (Expr.Etempvar _t'1 tuint) tuint)))

@[noinline] def s_kprog_arm64_extrev_1 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'1
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 64) tuint) tuint))
  (Stmt.Sset _t'1 (Expr.Ecast (Expr.Etempvar _t'1 tuint) tuint)))

@[noinline] def s_kprog_arm64_extrev_2 : Stmt :=
(Stmt.Sset _t'2
  (Expr.Ecast
    (Expr.Ebinop Binop.Oshl (Expr.Etempvar ___kprog_a64_ext_src tulong)
      (Expr.Ebinop Binop.Osub (Expr.Etempvar ___kprog_a64_ext_bits tulong)
        (Expr.Etempvar ___kprog_a64_ext_shift tulong) tulong) tulong) tulong))

@[noinline] def s_kprog_arm64_extrev_3 : Stmt :=
(Stmt.Sset _t'2
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) tulong))

@[noinline] def s_kprog_arm64_extrev_4 : Stmt :=
(Stmt.Sset ___kprog_a64_ext_w32
  (Expr.Ecast (Expr.Etempvar ___kprog_a64_ext_src tulong) tuint))

@[noinline] def s_kprog_arm64_extrev_5 : Stmt :=
(Stmt.Sset ___kprog_a64_ext_result
  (Expr.Ebinop Binop.Oor
    (Expr.Ebinop Binop.Oor
      (Expr.Ebinop Binop.Oor
        (Expr.Ebinop Binop.Oshl
          (Expr.Ecast
            (Expr.Ebinop Binop.Oand
              (Expr.Etempvar ___kprog_a64_ext_w32 tuint)
              (Expr.Econst_int (Integers.Int.repr 255) tuint) tuint) tulong)
          (Expr.Econst_int (Integers.Int.repr 24) tint) tulong)
        (Expr.Ebinop Binop.Oshl
          (Expr.Ecast
            (Expr.Ebinop Binop.Oand
              (Expr.Ebinop Binop.Oshr
                (Expr.Etempvar ___kprog_a64_ext_w32 tuint)
                (Expr.Econst_int (Integers.Int.repr 8) tint) tuint)
              (Expr.Econst_int (Integers.Int.repr 255) tuint) tuint) tulong)
          (Expr.Econst_int (Integers.Int.repr 16) tint) tulong) tulong)
      (Expr.Ebinop Binop.Oshl
        (Expr.Ecast
          (Expr.Ebinop Binop.Oand
            (Expr.Ebinop Binop.Oshr
              (Expr.Etempvar ___kprog_a64_ext_w32 tuint)
              (Expr.Econst_int (Integers.Int.repr 16) tint) tuint)
            (Expr.Econst_int (Integers.Int.repr 255) tuint) tuint) tulong)
        (Expr.Econst_int (Integers.Int.repr 8) tint) tulong) tulong)
    (Expr.Ecast
      (Expr.Ebinop Binop.Oand
        (Expr.Ebinop Binop.Oshr (Expr.Etempvar ___kprog_a64_ext_w32 tuint)
          (Expr.Econst_int (Integers.Int.repr 24) tint) tuint)
        (Expr.Econst_int (Integers.Int.repr 255) tuint) tuint) tulong)
    tulong))

def f_kprog_arm64_extrev : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_op, tulong), (_src, tulong), (_src2, tulong),
                (_shift, tulong), (_width, tulong)],
  fn_vars := [],
  fn_temps := [(_result, tulong), (___kprog_a64_ext_op, tulong),
               (___kprog_a64_ext_src, tulong),
               (___kprog_a64_ext_src2, tulong),
               (___kprog_a64_ext_shift, tulong),
               (___kprog_a64_ext_width, tulong),
               (___kprog_a64_ext_bits, tulong),
               (___kprog_a64_ext_result, tulong),
               (___kprog_a64_ext_w32, tuint), (_t'2, tulong), (_t'1, tuint)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sset ___kprog_a64_ext_op (Expr.Etempvar _op tulong))
      (Stmt.Ssequence
        (Stmt.Sset ___kprog_a64_ext_src (Expr.Etempvar _src tulong))
        (Stmt.Ssequence
          (Stmt.Sset ___kprog_a64_ext_src2 (Expr.Etempvar _src2 tulong))
          (Stmt.Ssequence
            (Stmt.Sset ___kprog_a64_ext_shift (Expr.Etempvar _shift tulong))
            (Stmt.Ssequence
              (Stmt.Sset ___kprog_a64_ext_width
                (Expr.Etempvar _width tulong))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar ___kprog_a64_ext_width tulong)
                                      (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                      tint)
                    (Stmt.Sset _t'1
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint))
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Etempvar ___kprog_a64_ext_width tulong)
                                        (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                        tint)
                      (Stmt.Ssequence
                        (Stmt.Sset _t'1
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 16) tuint)
                            tuint))
                        (Stmt.Sset _t'1
                          (Expr.Ecast (Expr.Etempvar _t'1 tuint) tuint)))
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Etempvar ___kprog_a64_ext_width tulong)
                                          (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                          tint)
                        (Stmt.Ssequence
                          s_kprog_arm64_extrev_0
                          (Stmt.Sset _t'1
                            (Expr.Ecast (Expr.Etempvar _t'1 tuint) tuint)))
                        (Stmt.Ssequence
                          s_kprog_arm64_extrev_1
                          (Stmt.Sset _t'1
                            (Expr.Ecast (Expr.Etempvar _t'1 tuint) tuint))))))
                  (Stmt.Sset ___kprog_a64_ext_bits
                    (Expr.Ecast (Expr.Etempvar _t'1 tuint) tulong)))
                (Stmt.Ssequence
                  (Stmt.Sset ___kprog_a64_ext_result
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                      tulong))
                  (Stmt.Ssequence
                    (Stmt.Sswitch (Expr.Etempvar ___kprog_a64_ext_op tulong)
                      (LStmts.LScons (some 17)
                        (Stmt.Ssequence
                          (Stmt.Sset ___kprog_a64_ext_shift
                            (Expr.Ebinop Binop.Oand
                              (Expr.Etempvar ___kprog_a64_ext_shift tulong)
                              (Expr.Ebinop Binop.Osub
                                (Expr.Etempvar ___kprog_a64_ext_bits tulong)
                                (Expr.Econst_int (Integers.Int.repr 1) tint)
                                tulong) tulong))
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Sifthenelse (Expr.Etempvar ___kprog_a64_ext_shift tulong)
                                s_kprog_arm64_extrev_2
                                s_kprog_arm64_extrev_3)
                              (Stmt.Sset ___kprog_a64_ext_result
                                (Expr.Ebinop Binop.Oor
                                  (Expr.Ebinop Binop.Oshr
                                    (Expr.Etempvar ___kprog_a64_ext_src2 tulong)
                                    (Expr.Etempvar ___kprog_a64_ext_shift tulong)
                                    tulong) (Expr.Etempvar _t'2 tulong)
                                  tulong)))
                            Stmt.Sbreak))
                        (LStmts.LScons (some 19)
                          (Stmt.Ssequence
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                (Expr.Etempvar ___kprog_a64_ext_width tulong)
                                                (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                                tint)
                              (Stmt.Ssequence
                                s_kprog_arm64_extrev_4
                                s_kprog_arm64_extrev_5)
                              (Stmt.Sset ___kprog_a64_ext_result
                                (Expr.Ebinop Binop.Oor
                                  (Expr.Ebinop Binop.Oor
                                    (Expr.Ebinop Binop.Oor
                                      (Expr.Ebinop Binop.Oor
                                        (Expr.Ebinop Binop.Oor
                                          (Expr.Ebinop Binop.Oor
                                            (Expr.Ebinop Binop.Oor
                                              (Expr.Ebinop Binop.Oshl
                                                (Expr.Ebinop Binop.Oand
                                                  (Expr.Etempvar ___kprog_a64_ext_src tulong)
                                                  (Expr.Econst_long (Integers.Int64.repr 255) tulong)
                                                  tulong)
                                                (Expr.Econst_int (Integers.Int.repr 56) tint)
                                                tulong)
                                              (Expr.Ebinop Binop.Oshl
                                                (Expr.Ebinop Binop.Oand
                                                  (Expr.Ebinop Binop.Oshr
                                                    (Expr.Etempvar ___kprog_a64_ext_src tulong)
                                                    (Expr.Econst_int (Integers.Int.repr 8) tint)
                                                    tulong)
                                                  (Expr.Econst_long (Integers.Int64.repr 255) tulong)
                                                  tulong)
                                                (Expr.Econst_int (Integers.Int.repr 48) tint)
                                                tulong) tulong)
                                            (Expr.Ebinop Binop.Oshl
                                              (Expr.Ebinop Binop.Oand
                                                (Expr.Ebinop Binop.Oshr
                                                  (Expr.Etempvar ___kprog_a64_ext_src tulong)
                                                  (Expr.Econst_int (Integers.Int.repr 16) tint)
                                                  tulong)
                                                (Expr.Econst_long (Integers.Int64.repr 255) tulong)
                                                tulong)
                                              (Expr.Econst_int (Integers.Int.repr 40) tint)
                                              tulong) tulong)
                                          (Expr.Ebinop Binop.Oshl
                                            (Expr.Ebinop Binop.Oand
                                              (Expr.Ebinop Binop.Oshr
                                                (Expr.Etempvar ___kprog_a64_ext_src tulong)
                                                (Expr.Econst_int (Integers.Int.repr 24) tint)
                                                tulong)
                                              (Expr.Econst_long (Integers.Int64.repr 255) tulong)
                                              tulong)
                                            (Expr.Econst_int (Integers.Int.repr 32) tint)
                                            tulong) tulong)
                                        (Expr.Ebinop Binop.Oshl
                                          (Expr.Ebinop Binop.Oand
                                            (Expr.Ebinop Binop.Oshr
                                              (Expr.Etempvar ___kprog_a64_ext_src tulong)
                                              (Expr.Econst_int (Integers.Int.repr 32) tint)
                                              tulong)
                                            (Expr.Econst_long (Integers.Int64.repr 255) tulong)
                                            tulong)
                                          (Expr.Econst_int (Integers.Int.repr 24) tint)
                                          tulong) tulong)
                                      (Expr.Ebinop Binop.Oshl
                                        (Expr.Ebinop Binop.Oand
                                          (Expr.Ebinop Binop.Oshr
                                            (Expr.Etempvar ___kprog_a64_ext_src tulong)
                                            (Expr.Econst_int (Integers.Int.repr 40) tint)
                                            tulong)
                                          (Expr.Econst_long (Integers.Int64.repr 255) tulong)
                                          tulong)
                                        (Expr.Econst_int (Integers.Int.repr 16) tint)
                                        tulong) tulong)
                                    (Expr.Ebinop Binop.Oshl
                                      (Expr.Ebinop Binop.Oand
                                        (Expr.Ebinop Binop.Oshr
                                          (Expr.Etempvar ___kprog_a64_ext_src tulong)
                                          (Expr.Econst_int (Integers.Int.repr 48) tint)
                                          tulong)
                                        (Expr.Econst_long (Integers.Int64.repr 255) tulong)
                                        tulong)
                                      (Expr.Econst_int (Integers.Int.repr 8) tint)
                                      tulong) tulong)
                                  (Expr.Ebinop Binop.Oand
                                    (Expr.Ebinop Binop.Oshr
                                      (Expr.Etempvar ___kprog_a64_ext_src tulong)
                                      (Expr.Econst_int (Integers.Int.repr 56) tint)
                                      tulong)
                                    (Expr.Econst_long (Integers.Int64.repr 255) tulong)
                                    tulong) tulong)))
                            Stmt.Sbreak)
                          (LStmts.LScons (some 20)
                            (Stmt.Ssequence
                              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                  (Expr.Etempvar ___kprog_a64_ext_width tulong)
                                                  (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                                  tint)
                                (Stmt.Sset ___kprog_a64_ext_result
                                  (Expr.Ebinop Binop.Oor
                                    (Expr.Ebinop Binop.Oshl
                                      (Expr.Ebinop Binop.Oand
                                        (Expr.Etempvar ___kprog_a64_ext_src tulong)
                                        (Expr.Econst_long (Integers.Int64.repr 16711935) tulong)
                                        tulong)
                                      (Expr.Econst_int (Integers.Int.repr 8) tint)
                                      tulong)
                                    (Expr.Ebinop Binop.Oshr
                                      (Expr.Ebinop Binop.Oand
                                        (Expr.Etempvar ___kprog_a64_ext_src tulong)
                                        (Expr.Econst_long (Integers.Int64.repr 4278255360) tulong)
                                        tulong)
                                      (Expr.Econst_int (Integers.Int.repr 8) tint)
                                      tulong) tulong))
                                (Stmt.Sset ___kprog_a64_ext_result
                                  (Expr.Ebinop Binop.Oor
                                    (Expr.Ebinop Binop.Oshl
                                      (Expr.Ebinop Binop.Oand
                                        (Expr.Etempvar ___kprog_a64_ext_src tulong)
                                        (Expr.Econst_long (Integers.Int64.repr 71777214294589695) tulong)
                                        tulong)
                                      (Expr.Econst_int (Integers.Int.repr 8) tint)
                                      tulong)
                                    (Expr.Ebinop Binop.Oshr
                                      (Expr.Ebinop Binop.Oand
                                        (Expr.Etempvar ___kprog_a64_ext_src tulong)
                                        (Expr.Econst_long (Integers.Int64.repr (-71777214294589696)) tulong)
                                        tulong)
                                      (Expr.Econst_int (Integers.Int.repr 8) tint)
                                      tulong) tulong)))
                              Stmt.Sbreak)
                            (LStmts.LScons (some 21)
                              (Stmt.Ssequence
                                (Stmt.Sset ___kprog_a64_ext_result
                                  (Expr.Ebinop Binop.Osub
                                    (Expr.Ebinop Binop.Oxor
                                      (Expr.Ebinop Binop.Oand
                                        (Expr.Etempvar ___kprog_a64_ext_src tulong)
                                        (Expr.Econst_long (Integers.Int64.repr 65535) tulong)
                                        tulong)
                                      (Expr.Econst_long (Integers.Int64.repr 32768) tulong)
                                      tulong)
                                    (Expr.Econst_long (Integers.Int64.repr 32768) tulong)
                                    tulong))
                                Stmt.Sbreak)
                              (LStmts.LScons (some 47)
                                (Stmt.Ssequence
                                  (Stmt.Sset ___kprog_a64_ext_result
                                    (Expr.Ebinop Binop.Osub
                                      (Expr.Ebinop Binop.Oxor
                                        (Expr.Ebinop Binop.Oand
                                          (Expr.Etempvar ___kprog_a64_ext_src tulong)
                                          (Expr.Econst_long (Integers.Int64.repr 4294967295) tulong)
                                          tulong)
                                        (Expr.Econst_long (Integers.Int64.repr 2147483648) tulong)
                                        tulong)
                                      (Expr.Econst_long (Integers.Int64.repr 2147483648) tulong)
                                      tulong))
                                  Stmt.Sbreak)
                                (LStmts.LScons (some 60)
                                  (Stmt.Ssequence
                                    (Stmt.Sset ___kprog_a64_ext_result
                                      (Expr.Ebinop Binop.Osub
                                        (Expr.Ebinop Binop.Oxor
                                          (Expr.Ebinop Binop.Oand
                                            (Expr.Etempvar ___kprog_a64_ext_src tulong)
                                            (Expr.Econst_long (Integers.Int64.repr 255) tulong)
                                            tulong)
                                          (Expr.Econst_long (Integers.Int64.repr 128) tulong)
                                          tulong)
                                        (Expr.Econst_long (Integers.Int64.repr 128) tulong)
                                        tulong))
                                    Stmt.Sbreak)
                                  (LStmts.LScons none
                                    (Stmt.Ssequence
                                      (Stmt.Sloop
                                        (Stmt.Scall none
                                          (Expr.Evar _arm64_sim_unsupported_opcode 
                                          (Ty.Tfunction [] tvoid cc_default))
                                          [])
                                        Stmt.Sbreak)
                                      Stmt.Sbreak)
                                    LStmts.LSnil))))))))
                    (Stmt.Sset _result
                      (Expr.Etempvar ___kprog_a64_ext_result tulong))))))))))
    Stmt.Sbreak)
  (Stmt.Sreturn (some (Expr.Etempvar _result tulong))))
}

def f_kprog_arm64_unary : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_op, tulong), (_value, tulong), (_width, tulong)],
  fn_vars := [],
  fn_temps := [(_result, tulong), (___kprog_a64_un_op, tulong),
               (___kprog_a64_un_value, tulong),
               (___kprog_a64_un_width, tulong),
               (___kprog_a64_un_wmask, tulong),
               (___kprog_a64_un_result, tulong), (_t'1, tulong)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sset ___kprog_a64_un_op (Expr.Etempvar _op tulong))
      (Stmt.Ssequence
        (Stmt.Sset ___kprog_a64_un_value (Expr.Etempvar _value tulong))
        (Stmt.Ssequence
          (Stmt.Sset ___kprog_a64_un_width (Expr.Etempvar _width tulong))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar ___kprog_a64_un_width tulong)
                                  (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                  tint)
                (Stmt.Sset _t'1
                  (Expr.Ecast
                    (Expr.Econst_long (Integers.Int64.repr 255) tulong)
                    tulong))
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Etempvar ___kprog_a64_un_width tulong)
                                    (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                    tint)
                  (Stmt.Ssequence
                    (Stmt.Sset _t'1
                      (Expr.Ecast
                        (Expr.Econst_long (Integers.Int64.repr 65535) tulong)
                        tulong))
                    (Stmt.Sset _t'1
                      (Expr.Ecast (Expr.Etempvar _t'1 tulong) tulong)))
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar ___kprog_a64_un_width tulong)
                                      (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sset _t'1
                          (Expr.Ecast
                            (Expr.Econst_long (Integers.Int64.repr 4294967295) tulong)
                            tulong))
                        (Stmt.Sset _t'1
                          (Expr.Ecast (Expr.Etempvar _t'1 tulong) tulong)))
                      (Stmt.Sset _t'1
                        (Expr.Ecast (Expr.Etempvar _t'1 tulong) tulong)))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sset _t'1
                          (Expr.Ecast
                            (Expr.Econst_long (Integers.Int64.repr (-1)) tulong)
                            tulong))
                        (Stmt.Sset _t'1
                          (Expr.Ecast (Expr.Etempvar _t'1 tulong) tulong)))
                      (Stmt.Sset _t'1
                        (Expr.Ecast (Expr.Etempvar _t'1 tulong) tulong))))))
              (Stmt.Sset ___kprog_a64_un_wmask (Expr.Etempvar _t'1 tulong)))
            (Stmt.Ssequence
              (Stmt.Sset ___kprog_a64_un_result
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                  tulong))
              (Stmt.Ssequence
                (Stmt.Sswitch (Expr.Etempvar ___kprog_a64_un_op tulong)
                  (LStmts.LScons (some 15)
                    (Stmt.Ssequence
                      (Stmt.Sset ___kprog_a64_un_result
                        (Expr.Ebinop Binop.Oand
                          (Expr.Eunop Unop.Onotint
                            (Expr.Etempvar ___kprog_a64_un_value tulong)
                            tulong)
                          (Expr.Etempvar ___kprog_a64_un_wmask tulong)
                          tulong))
                      Stmt.Sbreak)
                    (LStmts.LScons (some 16)
                      (Stmt.Ssequence
                        (Stmt.Sset ___kprog_a64_un_result
                          (Expr.Ebinop Binop.Oand
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Osub
                                (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                                (Expr.Etempvar ___kprog_a64_un_value tulong)
                                tulong) tulong)
                            (Expr.Etempvar ___kprog_a64_un_wmask tulong)
                            tulong))
                        Stmt.Sbreak)
                      (LStmts.LScons none
                        (Stmt.Ssequence
                          (Stmt.Sloop
                            (Stmt.Scall none
                              (Expr.Evar _arm64_sim_unsupported_opcode 
                              (Ty.Tfunction [] tvoid cc_default)) [])
                            Stmt.Sbreak)
                          Stmt.Sbreak)
                        LStmts.LSnil))))
                (Stmt.Sset _result
                  (Expr.Etempvar ___kprog_a64_un_result tulong))))))))
    Stmt.Sbreak)
  (Stmt.Sreturn (some (Expr.Etempvar _result tulong))))
}

def f_kprog_arm64_csel : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_op, tulong), (_src, tulong), (_src2, tulong),
                (_taken, tulong)],
  fn_vars := [],
  fn_temps := [(_result, tulong), (___kprog_a64_csel_op, tulong),
               (___kprog_a64_csel_src, tulong),
               (___kprog_a64_csel_src2, tulong),
               (___kprog_a64_csel_taken, tint),
               (___kprog_a64_csel_result, tulong), (_t'9, tulong),
               (_t'8, tulong), (_t'7, tulong), (_t'6, tulong),
               (_t'5, tulong), (_t'4, tint), (_t'3, tulong), (_t'2, tulong),
               (_t'1, tint)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sset ___kprog_a64_csel_op (Expr.Etempvar _op tulong))
      (Stmt.Ssequence
        (Stmt.Sset ___kprog_a64_csel_src (Expr.Etempvar _src tulong))
        (Stmt.Ssequence
          (Stmt.Sset ___kprog_a64_csel_src2 (Expr.Etempvar _src2 tulong))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Etempvar _taken tulong)
                (Stmt.Sset _t'1
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tint)
                    tint))
                (Stmt.Sset _t'1
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                    tint)))
              (Stmt.Sset ___kprog_a64_csel_taken (Expr.Etempvar _t'1 tint)))
            (Stmt.Ssequence
              (Stmt.Sset ___kprog_a64_csel_result
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                  tulong))
              (Stmt.Ssequence
                (Stmt.Sswitch (Expr.Etempvar ___kprog_a64_csel_op tulong)
                  (LStmts.LScons (some 28)
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Etempvar ___kprog_a64_csel_taken tint)
                          (Stmt.Sset _t'2
                            (Expr.Ecast
                              (Expr.Etempvar ___kprog_a64_csel_src tulong)
                              tulong))
                          (Stmt.Sset _t'2
                            (Expr.Ecast
                              (Expr.Etempvar ___kprog_a64_csel_src2 tulong)
                              tulong)))
                        (Stmt.Sset ___kprog_a64_csel_result
                          (Expr.Etempvar _t'2 tulong)))
                      Stmt.Sbreak)
                    (LStmts.LScons (some 29)
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Etempvar ___kprog_a64_csel_taken tint)
                            (Stmt.Sset _t'3
                              (Expr.Ecast
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Etempvar ___kprog_a64_csel_src tulong)
                                  (Expr.Econst_int (Integers.Int.repr 1) tint)
                                  tulong) tulong))
                            (Stmt.Sset _t'3
                              (Expr.Ecast
                                (Expr.Etempvar ___kprog_a64_csel_src tulong)
                                tulong)))
                          (Stmt.Sset ___kprog_a64_csel_result
                            (Expr.Etempvar _t'3 tulong)))
                        Stmt.Sbreak)
                      (LStmts.LScons (some 30)
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Sifthenelse (Expr.Etempvar ___kprog_a64_csel_taken tint)
                              (Stmt.Sset _t'4
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 1) tint)
                                  tint))
                              (Stmt.Sset _t'4
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 0) tint)
                                  tint)))
                            (Stmt.Sset ___kprog_a64_csel_result
                              (Expr.Ecast (Expr.Etempvar _t'4 tint) tulong)))
                          Stmt.Sbreak)
                        (LStmts.LScons (some 52)
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Sifthenelse (Expr.Etempvar ___kprog_a64_csel_taken tint)
                                (Stmt.Sset _t'5
                                  (Expr.Ecast
                                    (Expr.Eunop Unop.Onotint
                                      (Expr.Etempvar ___kprog_a64_csel_src tulong)
                                      tulong) tulong))
                                (Stmt.Sset _t'5
                                  (Expr.Ecast
                                    (Expr.Etempvar ___kprog_a64_csel_src tulong)
                                    tulong)))
                              (Stmt.Sset ___kprog_a64_csel_result
                                (Expr.Etempvar _t'5 tulong)))
                            Stmt.Sbreak)
                          (LStmts.LScons (some 61)
                            (Stmt.Ssequence
                              (Stmt.Ssequence
                                (Stmt.Sifthenelse (Expr.Etempvar ___kprog_a64_csel_taken tint)
                                  (Stmt.Sset _t'6
                                    (Expr.Ecast
                                      (Expr.Etempvar ___kprog_a64_csel_src tulong)
                                      tulong))
                                  (Stmt.Sset _t'6
                                    (Expr.Ecast
                                      (Expr.Eunop Unop.Onotint
                                        (Expr.Etempvar ___kprog_a64_csel_src2 tulong)
                                        tulong) tulong)))
                                (Stmt.Sset ___kprog_a64_csel_result
                                  (Expr.Etempvar _t'6 tulong)))
                              Stmt.Sbreak)
                            (LStmts.LScons (some 62)
                              (Stmt.Ssequence
                                (Stmt.Ssequence
                                  (Stmt.Sifthenelse (Expr.Etempvar ___kprog_a64_csel_taken tint)
                                    (Stmt.Sset _t'7
                                      (Expr.Ecast
                                        (Expr.Etempvar ___kprog_a64_csel_src tulong)
                                        tulong))
                                    (Stmt.Sset _t'7
                                      (Expr.Ecast
                                        (Expr.Ebinop Binop.Oadd
                                          (Expr.Etempvar ___kprog_a64_csel_src2 tulong)
                                          (Expr.Econst_int (Integers.Int.repr 1) tint)
                                          tulong) tulong)))
                                  (Stmt.Sset ___kprog_a64_csel_result
                                    (Expr.Etempvar _t'7 tulong)))
                                Stmt.Sbreak)
                              (LStmts.LScons (some 68)
                                (Stmt.Ssequence
                                  (Stmt.Ssequence
                                    (Stmt.Sifthenelse (Expr.Etempvar ___kprog_a64_csel_taken tint)
                                      (Stmt.Sset _t'8
                                        (Expr.Ecast
                                          (Expr.Eunop Unop.Onotint
                                            (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                                            tulong) tulong))
                                      (Stmt.Sset _t'8
                                        (Expr.Ecast
                                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                                          tulong)))
                                    (Stmt.Sset ___kprog_a64_csel_result
                                      (Expr.Etempvar _t'8 tulong)))
                                  Stmt.Sbreak)
                                (LStmts.LScons (some 69)
                                  (Stmt.Ssequence
                                    (Stmt.Ssequence
                                      (Stmt.Sifthenelse (Expr.Etempvar ___kprog_a64_csel_taken tint)
                                        (Stmt.Sset _t'9
                                          (Expr.Ecast
                                            (Expr.Etempvar ___kprog_a64_csel_src tulong)
                                            tulong))
                                        (Stmt.Sset _t'9
                                          (Expr.Ecast
                                            (Expr.Eunop Unop.Oneg
                                              (Expr.Etempvar ___kprog_a64_csel_src2 tulong)
                                              tulong) tulong)))
                                      (Stmt.Sset ___kprog_a64_csel_result
                                        (Expr.Etempvar _t'9 tulong)))
                                    Stmt.Sbreak)
                                  (LStmts.LScons none
                                    (Stmt.Ssequence
                                      (Stmt.Sloop
                                        (Stmt.Scall none
                                          (Expr.Evar _arm64_sim_unsupported_opcode 
                                          (Ty.Tfunction [] tvoid cc_default))
                                          [])
                                        Stmt.Sbreak)
                                      Stmt.Sbreak)
                                    LStmts.LSnil))))))))))
                (Stmt.Sset _result
                  (Expr.Etempvar ___kprog_a64_csel_result tulong))))))))
    Stmt.Sbreak)
  (Stmt.Sreturn (some (Expr.Etempvar _result tulong))))
}

@[noinline] def s_kprog_arm64_cneg_0 : Stmt :=
(Stmt.Sset _t'2
  (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 4294967295) tulong)
    tulong))

@[noinline] def s_kprog_arm64_cneg_1 : Stmt :=
(Stmt.Sset _t'2
  (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr (-1)) tulong) tulong))

def f_kprog_arm64_cneg : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_op, tulong), (_value, tulong), (_taken, tulong),
                (_width, tulong)],
  fn_vars := [],
  fn_temps := [(_result, tulong), (___kprog_a64_cneg_op, tulong),
               (___kprog_a64_cneg_value, tulong),
               (___kprog_a64_cneg_taken, tint),
               (___kprog_a64_cneg_width, tulong),
               (___kprog_a64_cneg_wmask, tulong),
               (___kprog_a64_cneg_result, tulong), (_t'3, tulong),
               (_t'2, tulong), (_t'1, tint)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sset ___kprog_a64_cneg_op (Expr.Etempvar _op tulong))
      (Stmt.Ssequence
        (Stmt.Sset ___kprog_a64_cneg_value (Expr.Etempvar _value tulong))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sifthenelse (Expr.Etempvar _taken tulong)
              (Stmt.Sset _t'1
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tint)
                  tint))
              (Stmt.Sset _t'1
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                  tint)))
            (Stmt.Sset ___kprog_a64_cneg_taken (Expr.Etempvar _t'1 tint)))
          (Stmt.Ssequence
            (Stmt.Sset ___kprog_a64_cneg_width (Expr.Etempvar _width tulong))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Etempvar ___kprog_a64_cneg_width tulong)
                                    (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                    tint)
                  (Stmt.Sset _t'2
                    (Expr.Ecast
                      (Expr.Econst_long (Integers.Int64.repr 255) tulong)
                      tulong))
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar ___kprog_a64_cneg_width tulong)
                                      (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Sset _t'2
                        (Expr.Ecast
                          (Expr.Econst_long (Integers.Int64.repr 65535) tulong)
                          tulong))
                      (Stmt.Sset _t'2
                        (Expr.Ecast (Expr.Etempvar _t'2 tulong) tulong)))
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Etempvar ___kprog_a64_cneg_width tulong)
                                        (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                        tint)
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          s_kprog_arm64_cneg_0
                          (Stmt.Sset _t'2
                            (Expr.Ecast (Expr.Etempvar _t'2 tulong) tulong)))
                        (Stmt.Sset _t'2
                          (Expr.Ecast (Expr.Etempvar _t'2 tulong) tulong)))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          s_kprog_arm64_cneg_1
                          (Stmt.Sset _t'2
                            (Expr.Ecast (Expr.Etempvar _t'2 tulong) tulong)))
                        (Stmt.Sset _t'2
                          (Expr.Ecast (Expr.Etempvar _t'2 tulong) tulong))))))
                (Stmt.Sset ___kprog_a64_cneg_wmask
                  (Expr.Etempvar _t'2 tulong)))
              (Stmt.Ssequence
                (Stmt.Sset ___kprog_a64_cneg_result
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                    tulong))
                (Stmt.Ssequence
                  (Stmt.Sswitch (Expr.Etempvar ___kprog_a64_cneg_op tulong)
                    (LStmts.LScons (some 65)
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Etempvar ___kprog_a64_cneg_taken tint)
                            (Stmt.Sset _t'3
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Ebinop Binop.Osub
                                    (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                                    (Expr.Etempvar ___kprog_a64_cneg_value tulong)
                                    tulong) tulong) tulong))
                            (Stmt.Sset _t'3
                              (Expr.Ecast
                                (Expr.Etempvar ___kprog_a64_cneg_value tulong)
                                tulong)))
                          (Stmt.Sset ___kprog_a64_cneg_result
                            (Expr.Ebinop Binop.Oand
                              (Expr.Etempvar _t'3 tulong)
                              (Expr.Etempvar ___kprog_a64_cneg_wmask tulong)
                              tulong)))
                        Stmt.Sbreak)
                      (LStmts.LScons none
                        (Stmt.Ssequence
                          (Stmt.Sloop
                            (Stmt.Scall none
                              (Expr.Evar _arm64_sim_unsupported_opcode 
                              (Ty.Tfunction [] tvoid cc_default)) [])
                            Stmt.Sbreak)
                          Stmt.Sbreak)
                        LStmts.LSnil)))
                  (Stmt.Sset _result
                    (Expr.Etempvar ___kprog_a64_cneg_result tulong)))))))))
    Stmt.Sbreak)
  (Stmt.Sreturn (some (Expr.Etempvar _result tulong))))
}

def f_kprog_arm64_fmov : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_dir, tulong), (_v0, tulong), (_src, tulong)],
  fn_vars := [],
  fn_temps := [(_result, tulong), (___kprog_a64_fmov_dir, tulong),
               (___kprog_a64_fmov_v0, tulong),
               (___kprog_a64_fmov_src, tulong),
               (___kprog_a64_fmov_result, tulong)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sset ___kprog_a64_fmov_dir (Expr.Etempvar _dir tulong))
      (Stmt.Ssequence
        (Stmt.Sset ___kprog_a64_fmov_v0 (Expr.Etempvar _v0 tulong))
        (Stmt.Ssequence
          (Stmt.Sset ___kprog_a64_fmov_src (Expr.Etempvar _src tulong))
          (Stmt.Ssequence
            (Stmt.Sset ___kprog_a64_fmov_result
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                tulong))
            (Stmt.Ssequence
              (Stmt.Sswitch (Expr.Etempvar ___kprog_a64_fmov_dir tulong)
                (LStmts.LScons (some 0)
                  (Stmt.Ssequence
                    (Stmt.Sset ___kprog_a64_fmov_result
                      (Expr.Etempvar ___kprog_a64_fmov_src tulong))
                    Stmt.Sbreak)
                  (LStmts.LScons (some 1)
                    (Stmt.Ssequence
                      (Stmt.Sset ___kprog_a64_fmov_result
                        (Expr.Etempvar ___kprog_a64_fmov_v0 tulong))
                      Stmt.Sbreak)
                    (LStmts.LScons (some 2)
                      (Stmt.Ssequence
                        (Stmt.Sset ___kprog_a64_fmov_result
                          (Expr.Etempvar ___kprog_a64_fmov_src tulong))
                        Stmt.Sbreak)
                      (LStmts.LScons (some 3)
                        (Stmt.Ssequence
                          (Stmt.Sset ___kprog_a64_fmov_result
                            (Expr.Etempvar ___kprog_a64_fmov_v0 tulong))
                          Stmt.Sbreak)
                        (LStmts.LScons none
                          (Stmt.Ssequence
                            (Stmt.Sloop
                              (Stmt.Scall none
                                (Expr.Evar _arm64_sim_unsupported_opcode 
                                (Ty.Tfunction [] tvoid cc_default)) [])
                              Stmt.Sbreak)
                            Stmt.Sbreak)
                          LStmts.LSnil))))))
              (Stmt.Sset _result
                (Expr.Etempvar ___kprog_a64_fmov_result tulong)))))))
    Stmt.Sbreak)
  (Stmt.Sreturn (some (Expr.Etempvar _result tulong))))
}

def f_kprog_arm64_fmov_dest : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_dir, tulong)],
  fn_vars := [],
  fn_temps := [(_result, tulong), (___kprog_a64_fmd_dir, tulong),
               (___kprog_a64_fmd_v0, tulong)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sset ___kprog_a64_fmd_dir (Expr.Etempvar _dir tulong))
      (Stmt.Ssequence
        (Stmt.Sset ___kprog_a64_fmd_v0
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) tulong))
        (Stmt.Ssequence
          (Stmt.Sswitch (Expr.Etempvar ___kprog_a64_fmd_dir tulong)
            (LStmts.LScons (some 0)
              (Stmt.Ssequence
                (Stmt.Sset ___kprog_a64_fmd_v0
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint)
                    tulong))
                Stmt.Sbreak)
              (LStmts.LScons (some 1)
                (Stmt.Ssequence
                  (Stmt.Sset ___kprog_a64_fmd_v0
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                      tulong))
                  Stmt.Sbreak)
                (LStmts.LScons (some 2)
                  (Stmt.Ssequence
                    (Stmt.Sset ___kprog_a64_fmd_v0
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 1) tuint) tulong))
                    Stmt.Sbreak)
                  (LStmts.LScons (some 3)
                    (Stmt.Ssequence
                      (Stmt.Sset ___kprog_a64_fmd_v0
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 0) tuint)
                          tulong))
                      Stmt.Sbreak)
                    (LStmts.LScons none
                      (Stmt.Ssequence
                        (Stmt.Sloop
                          (Stmt.Scall none
                            (Expr.Evar _arm64_sim_unsupported_opcode 
                            (Ty.Tfunction [] tvoid cc_default)) [])
                          Stmt.Sbreak)
                        Stmt.Sbreak)
                      LStmts.LSnil))))))
          (Stmt.Sset _result (Expr.Etempvar ___kprog_a64_fmd_v0 tulong)))))
    Stmt.Sbreak)
  (Stmt.Sreturn (some (Expr.Etempvar _result tulong))))
}

def f_kprog_arm64_imm_operand : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_op, tulong), (_imm, tulong), (_reg, tulong)],
  fn_vars := [],
  fn_temps := [(_result, tulong), (___kprog_a64_io_operand, tulong)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sset ___kprog_a64_io_operand (Expr.Etempvar _reg tulong))
      (Stmt.Ssequence
        (Stmt.Sswitch (Expr.Etempvar _op tulong)
          (LStmts.LScons (some 1)
            (Stmt.Ssequence
              (Stmt.Sset ___kprog_a64_io_operand (Expr.Etempvar _imm tulong))
              Stmt.Sbreak)
            (LStmts.LScons (some 8)
              (Stmt.Ssequence
                (Stmt.Sset ___kprog_a64_io_operand
                  (Expr.Etempvar _imm tulong))
                Stmt.Sbreak)
              (LStmts.LScons none Stmt.Sbreak LStmts.LSnil))))
        (Stmt.Sset _result (Expr.Etempvar ___kprog_a64_io_operand tulong))))
    Stmt.Sbreak)
  (Stmt.Sreturn (some (Expr.Etempvar _result tulong))))
}

def f_kprog_arm64_adrp : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_op, tulong)],
  fn_vars := [],
  fn_temps := [(_result, tuchar), (___kprog_a64_adrp_op, tuchar),
               (___kprog_a64_adrp_tag, tuchar)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sset ___kprog_a64_adrp_op
        (Expr.Ecast (Expr.Etempvar _op tulong) tuchar))
      (Stmt.Ssequence
        (Stmt.Sset ___kprog_a64_adrp_tag
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) tuchar))
        (Stmt.Ssequence
          (Stmt.Sswitch (Expr.Etempvar ___kprog_a64_adrp_op tuchar)
            (LStmts.LScons (some 38)
              (Stmt.Ssequence
                (Stmt.Sset ___kprog_a64_adrp_tag
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 7) tuint)
                    tuchar))
                Stmt.Sbreak)
              (LStmts.LScons (some 39)
                (Stmt.Ssequence
                  (Stmt.Sset ___kprog_a64_adrp_tag
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tuint)
                      tuchar))
                  Stmt.Sbreak)
                (LStmts.LScons none
                  (Stmt.Ssequence
                    (Stmt.Sloop
                      (Stmt.Scall none
                        (Expr.Evar _arm64_sim_unsupported_opcode (Ty.Tfunction
                                                                   [] tvoid
                                                                   cc_default))
                        [])
                      Stmt.Sbreak)
                    Stmt.Sbreak)
                  LStmts.LSnil))))
          (Stmt.Sset _result
            (Expr.Ecast (Expr.Etempvar ___kprog_a64_adrp_tag tuchar) tuchar)))))
    Stmt.Sbreak)
  (Stmt.Sreturn (some (Expr.Etempvar _result tuchar))))
}

def composites : List CompositeDef :=
[]

def global_definitions : List (Ident × GlobDef FunDef Ty) :=
[(___compcert_va_int32,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_runtime "__compcert_va_int32"
                                   (mksignature [XType.Xptr] XType.Xint
                                     cc_default)) [(tptr tvoid)] tuint
     cc_default)),
 (___compcert_va_int64,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_runtime "__compcert_va_int64"
                                   (mksignature [XType.Xptr] XType.Xlong
                                     cc_default)) [(tptr tvoid)] tulong
     cc_default)),
 (___compcert_va_float64,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_runtime "__compcert_va_float64"
                                   (mksignature [XType.Xptr] XType.Xfloat
                                     cc_default)) [(tptr tvoid)] tdouble
     cc_default)),
 (___compcert_va_composite,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_runtime "__compcert_va_composite"
                                   (mksignature [XType.Xptr, XType.Xlong]
                                     XType.Xptr cc_default))
     [(tptr tvoid), tulong] (tptr tvoid) cc_default)),
 (___compcert_i64_dtos,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_runtime "__compcert_i64_dtos"
                                   (mksignature [XType.Xfloat] XType.Xlong
                                     cc_default)) [tdouble] tlong
     cc_default)),
 (___compcert_i64_dtou,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_runtime "__compcert_i64_dtou"
                                   (mksignature [XType.Xfloat] XType.Xlong
                                     cc_default)) [tdouble] tulong
     cc_default)),
 (___compcert_i64_stod,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_runtime "__compcert_i64_stod"
                                   (mksignature [XType.Xlong] XType.Xfloat
                                     cc_default)) [tlong] tdouble
     cc_default)),
 (___compcert_i64_utod,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_runtime "__compcert_i64_utod"
                                   (mksignature [XType.Xlong] XType.Xfloat
                                     cc_default)) [tulong] tdouble
     cc_default)),
 (___compcert_i64_stof,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_runtime "__compcert_i64_stof"
                                   (mksignature [XType.Xlong] XType.Xsingle
                                     cc_default)) [tlong] tfloat cc_default)),
 (___compcert_i64_utof,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_runtime "__compcert_i64_utof"
                                   (mksignature [XType.Xlong] XType.Xsingle
                                     cc_default)) [tulong] tfloat
     cc_default)),
 (___compcert_i64_sdiv,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_runtime "__compcert_i64_sdiv"
                                   (mksignature [XType.Xlong, XType.Xlong]
                                     XType.Xlong cc_default)) [tlong, tlong]
     tlong cc_default)),
 (___compcert_i64_udiv,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_runtime "__compcert_i64_udiv"
                                   (mksignature [XType.Xlong, XType.Xlong]
                                     XType.Xlong cc_default))
     [tulong, tulong] tulong cc_default)),
 (___compcert_i64_smod,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_runtime "__compcert_i64_smod"
                                   (mksignature [XType.Xlong, XType.Xlong]
                                     XType.Xlong cc_default)) [tlong, tlong]
     tlong cc_default)),
 (___compcert_i64_umod,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_runtime "__compcert_i64_umod"
                                   (mksignature [XType.Xlong, XType.Xlong]
                                     XType.Xlong cc_default))
     [tulong, tulong] tulong cc_default)),
 (___compcert_i64_shl,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_runtime "__compcert_i64_shl"
                                   (mksignature [XType.Xlong, XType.Xint]
                                     XType.Xlong cc_default)) [tlong, tint]
     tlong cc_default)),
 (___compcert_i64_shr,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_runtime "__compcert_i64_shr"
                                   (mksignature [XType.Xlong, XType.Xint]
                                     XType.Xlong cc_default)) [tulong, tint]
     tulong cc_default)),
 (___compcert_i64_sar,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_runtime "__compcert_i64_sar"
                                   (mksignature [XType.Xlong, XType.Xint]
                                     XType.Xlong cc_default)) [tlong, tint]
     tlong cc_default)),
 (___compcert_i64_smulh,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_runtime "__compcert_i64_smulh"
                                   (mksignature [XType.Xlong, XType.Xlong]
                                     XType.Xlong cc_default)) [tlong, tlong]
     tlong cc_default)),
 (___compcert_i64_umulh,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_runtime "__compcert_i64_umulh"
                                   (mksignature [XType.Xlong, XType.Xlong]
                                     XType.Xlong cc_default))
     [tulong, tulong] tulong cc_default)),
 (___builtin_ais_annot,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_builtin "__builtin_ais_annot"
                                   (mksignature [XType.Xptr] XType.Xvoid
                                     { cc_vararg := (some 1), cc_unproto := false, cc_structret := false }))
     [(tptr tschar)] tvoid
     { cc_vararg := (some 1), cc_unproto := false, cc_structret := false })),
 (___builtin_bswap64,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_builtin "__builtin_bswap64"
                                   (mksignature [XType.Xlong] XType.Xlong
                                     cc_default)) [tulong] tulong
     cc_default)),
 (___builtin_bswap,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_builtin "__builtin_bswap"
                                   (mksignature [XType.Xint] XType.Xint
                                     cc_default)) [tuint] tuint cc_default)),
 (___builtin_bswap32,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_builtin "__builtin_bswap32"
                                   (mksignature [XType.Xint] XType.Xint
                                     cc_default)) [tuint] tuint cc_default)),
 (___builtin_bswap16,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_builtin "__builtin_bswap16"
                                   (mksignature [XType.Xint16unsigned]
                                     XType.Xint16unsigned cc_default))
     [tushort] tushort cc_default)),
 (___builtin_clz,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_builtin "__builtin_clz"
                                   (mksignature [XType.Xint] XType.Xint
                                     cc_default)) [tuint] tint cc_default)),
 (___builtin_clzl,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_builtin "__builtin_clzl"
                                   (mksignature [XType.Xlong] XType.Xint
                                     cc_default)) [tulong] tint cc_default)),
 (___builtin_clzll,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_builtin "__builtin_clzll"
                                   (mksignature [XType.Xlong] XType.Xint
                                     cc_default)) [tulong] tint cc_default)),
 (___builtin_ctz,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_builtin "__builtin_ctz"
                                   (mksignature [XType.Xint] XType.Xint
                                     cc_default)) [tuint] tint cc_default)),
 (___builtin_ctzl,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_builtin "__builtin_ctzl"
                                   (mksignature [XType.Xlong] XType.Xint
                                     cc_default)) [tulong] tint cc_default)),
 (___builtin_ctzll,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_builtin "__builtin_ctzll"
                                   (mksignature [XType.Xlong] XType.Xint
                                     cc_default)) [tulong] tint cc_default)),
 (___builtin_fabs,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_builtin "__builtin_fabs"
                                   (mksignature [XType.Xfloat] XType.Xfloat
                                     cc_default)) [tdouble] tdouble
     cc_default)),
 (___builtin_fabsf,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_builtin "__builtin_fabsf"
                                   (mksignature [XType.Xsingle] XType.Xsingle
                                     cc_default)) [tfloat] tfloat
     cc_default)),
 (___builtin_fsqrt,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_builtin "__builtin_fsqrt"
                                   (mksignature [XType.Xfloat] XType.Xfloat
                                     cc_default)) [tdouble] tdouble
     cc_default)),
 (___builtin_sqrt,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_builtin "__builtin_sqrt"
                                   (mksignature [XType.Xfloat] XType.Xfloat
                                     cc_default)) [tdouble] tdouble
     cc_default)),
 (___builtin_memcpy_aligned,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_builtin "__builtin_memcpy_aligned"
                                   (mksignature
                                     [XType.Xptr, XType.Xptr, XType.Xlong,
                                      XType.Xlong] XType.Xvoid cc_default))
     [(tptr tvoid), (tptr tvoid), tulong, tulong] tvoid cc_default)),
 (___builtin_sel,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_builtin "__builtin_sel"
                                   (mksignature [XType.Xbool] XType.Xvoid
                                     { cc_vararg := (some 1), cc_unproto := false, cc_structret := false }))
     [tbool] tvoid
     { cc_vararg := (some 1), cc_unproto := false, cc_structret := false })),
 (___builtin_annot,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_builtin "__builtin_annot"
                                   (mksignature [XType.Xptr] XType.Xvoid
                                     { cc_vararg := (some 1), cc_unproto := false, cc_structret := false }))
     [(tptr tschar)] tvoid
     { cc_vararg := (some 1), cc_unproto := false, cc_structret := false })),
 (___builtin_annot_intval,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_builtin "__builtin_annot_intval"
                                   (mksignature [XType.Xptr, XType.Xint]
                                     XType.Xint cc_default))
     [(tptr tschar), tint] tint cc_default)),
 (___builtin_membar,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_builtin "__builtin_membar"
                                   (mksignature [] XType.Xvoid cc_default))
     [] tvoid cc_default)),
 (___builtin_va_start,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_builtin "__builtin_va_start"
                                   (mksignature [XType.Xptr] XType.Xvoid
                                     cc_default)) [(tptr tvoid)] tvoid
     cc_default)),
 (___builtin_va_arg,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_builtin "__builtin_va_arg"
                                   (mksignature [XType.Xptr, XType.Xint]
                                     XType.Xvoid cc_default))
     [(tptr tvoid), tuint] tvoid cc_default)),
 (___builtin_va_copy,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_builtin "__builtin_va_copy"
                                   (mksignature [XType.Xptr, XType.Xptr]
                                     XType.Xvoid cc_default))
     [(tptr tvoid), (tptr tvoid)] tvoid cc_default)),
 (___builtin_va_end,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_builtin "__builtin_va_end"
                                   (mksignature [XType.Xptr] XType.Xvoid
                                     cc_default)) [(tptr tvoid)] tvoid
     cc_default)),
 (___builtin_unreachable,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_builtin "__builtin_unreachable"
                                   (mksignature [] XType.Xvoid cc_default))
     [] tvoid cc_default)),
 (___builtin_expect,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_builtin "__builtin_expect"
                                   (mksignature [XType.Xlong, XType.Xlong]
                                     XType.Xlong cc_default)) [tlong, tlong]
     tlong cc_default)),
 (___builtin_fmax,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_builtin "__builtin_fmax"
                                   (mksignature [XType.Xfloat, XType.Xfloat]
                                     XType.Xfloat cc_default))
     [tdouble, tdouble] tdouble cc_default)),
 (___builtin_fmin,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_builtin "__builtin_fmin"
                                   (mksignature [XType.Xfloat, XType.Xfloat]
                                     XType.Xfloat cc_default))
     [tdouble, tdouble] tdouble cc_default)),
 (___builtin_fmadd,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_builtin "__builtin_fmadd"
                                   (mksignature
                                     [XType.Xfloat, XType.Xfloat,
                                      XType.Xfloat] XType.Xfloat cc_default))
     [tdouble, tdouble, tdouble] tdouble cc_default)),
 (___builtin_fmsub,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_builtin "__builtin_fmsub"
                                   (mksignature
                                     [XType.Xfloat, XType.Xfloat,
                                      XType.Xfloat] XType.Xfloat cc_default))
     [tdouble, tdouble, tdouble] tdouble cc_default)),
 (___builtin_fnmadd,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_builtin "__builtin_fnmadd"
                                   (mksignature
                                     [XType.Xfloat, XType.Xfloat,
                                      XType.Xfloat] XType.Xfloat cc_default))
     [tdouble, tdouble, tdouble] tdouble cc_default)),
 (___builtin_fnmsub,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_builtin "__builtin_fnmsub"
                                   (mksignature
                                     [XType.Xfloat, XType.Xfloat,
                                      XType.Xfloat] XType.Xfloat cc_default))
     [tdouble, tdouble, tdouble] tdouble cc_default)),
 (___builtin_read16_reversed,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_builtin "__builtin_read16_reversed"
                                   (mksignature [XType.Xptr]
                                     XType.Xint16unsigned cc_default))
     [(tptr tushort)] tushort cc_default)),
 (___builtin_read32_reversed,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_builtin "__builtin_read32_reversed"
                                   (mksignature [XType.Xptr] XType.Xint
                                     cc_default)) [(tptr tuint)] tuint
     cc_default)),
 (___builtin_write16_reversed,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_builtin "__builtin_write16_reversed"
                                   (mksignature
                                     [XType.Xptr, XType.Xint16unsigned]
                                     XType.Xvoid cc_default))
     [(tptr tushort), tushort] tvoid cc_default)),
 (___builtin_write32_reversed,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_builtin "__builtin_write32_reversed"
                                   (mksignature [XType.Xptr, XType.Xint]
                                     XType.Xvoid cc_default))
     [(tptr tuint), tuint] tvoid cc_default)),
 (___builtin_debug,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_external "__builtin_debug"
                                   (mksignature [XType.Xint] XType.Xvoid
                                     { cc_vararg := (some 1), cc_unproto := false, cc_structret := false }))
     [tint] tvoid
     { cc_vararg := (some 1), cc_unproto := false, cc_structret := false })),
 (_kprog_arm64_alu_result, GlobDef.Gfun (FunDef.Internal f_kprog_arm64_alu_result)),
 (_kprog_arm64_mod, GlobDef.Gfun (FunDef.Internal f_kprog_arm64_mod)),
 (_kprog_arm64_shift, GlobDef.Gfun (FunDef.Internal f_kprog_arm64_shift)),
 (_kprog_arm64_bitfield, GlobDef.Gfun (FunDef.Internal f_kprog_arm64_bitfield)),
 (_kprog_arm64_mul, GlobDef.Gfun (FunDef.Internal f_kprog_arm64_mul)),
 (_kprog_arm64_extrev, GlobDef.Gfun (FunDef.Internal f_kprog_arm64_extrev)),
 (_kprog_arm64_unary, GlobDef.Gfun (FunDef.Internal f_kprog_arm64_unary)),
 (_kprog_arm64_csel, GlobDef.Gfun (FunDef.Internal f_kprog_arm64_csel)),
 (_kprog_arm64_cneg, GlobDef.Gfun (FunDef.Internal f_kprog_arm64_cneg)),
 (_kprog_arm64_fmov, GlobDef.Gfun (FunDef.Internal f_kprog_arm64_fmov)),
 (_kprog_arm64_fmov_dest, GlobDef.Gfun (FunDef.Internal f_kprog_arm64_fmov_dest)),
 (_kprog_arm64_imm_operand, GlobDef.Gfun (FunDef.Internal f_kprog_arm64_imm_operand)),
 (_arm64_sim_unsupported_opcode,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_external "arm64_sim_unsupported_opcode"
                                   (mksignature [] XType.Xvoid cc_default))
     [] tvoid cc_default)),
 (_kprog_arm64_adrp, GlobDef.Gfun (FunDef.Internal f_kprog_arm64_adrp))]

def public_idents : List Ident :=
[_kprog_arm64_adrp, _arm64_sim_unsupported_opcode, _kprog_arm64_imm_operand,
 _kprog_arm64_fmov_dest, _kprog_arm64_fmov, _kprog_arm64_cneg,
 _kprog_arm64_csel, _kprog_arm64_unary, _kprog_arm64_extrev,
 _kprog_arm64_mul, _kprog_arm64_bitfield, _kprog_arm64_shift,
 _kprog_arm64_mod, _kprog_arm64_alu_result, ___builtin_debug,
 ___builtin_write32_reversed, ___builtin_write16_reversed,
 ___builtin_read32_reversed, ___builtin_read16_reversed, ___builtin_fnmsub,
 ___builtin_fnmadd, ___builtin_fmsub, ___builtin_fmadd, ___builtin_fmin,
 ___builtin_fmax, ___builtin_expect, ___builtin_unreachable,
 ___builtin_va_end, ___builtin_va_copy, ___builtin_va_arg,
 ___builtin_va_start, ___builtin_membar, ___builtin_annot_intval,
 ___builtin_annot, ___builtin_sel, ___builtin_memcpy_aligned,
 ___builtin_sqrt, ___builtin_fsqrt, ___builtin_fabsf, ___builtin_fabs,
 ___builtin_ctzll, ___builtin_ctzl, ___builtin_ctz, ___builtin_clzll,
 ___builtin_clzl, ___builtin_clz, ___builtin_bswap16, ___builtin_bswap32,
 ___builtin_bswap, ___builtin_bswap64, ___builtin_ais_annot,
 ___compcert_i64_umulh, ___compcert_i64_smulh, ___compcert_i64_sar,
 ___compcert_i64_shr, ___compcert_i64_shl, ___compcert_i64_umod,
 ___compcert_i64_smod, ___compcert_i64_udiv, ___compcert_i64_sdiv,
 ___compcert_i64_utof, ___compcert_i64_stof, ___compcert_i64_utod,
 ___compcert_i64_stod, ___compcert_i64_dtou, ___compcert_i64_dtos,
 ___compcert_va_composite, ___compcert_va_float64, ___compcert_va_int64,
 ___compcert_va_int32]

def prog : Program :=
  mkprogram composites global_definitions public_idents _main

end Arm64Numeric

