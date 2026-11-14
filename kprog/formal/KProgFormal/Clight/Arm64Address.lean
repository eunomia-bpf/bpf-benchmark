import Clightdefs
open CC

namespace Arm64Address

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
  def source_file : String := "c/Arm64Address.c"
  def normalized : Bool := true
end Info

def __2844 : Ident := identOfString "_2844"
def __2873 : Ident := identOfString "_2873"
def __2908 : Ident := identOfString "_2908"
def ___a64_adrp_tag : Ident := identOfString "__a64_adrp_tag"
def ___a64_cells : Ident := identOfString "__a64_cells"
def ___a64_l_next : Ident := identOfString "__a64_l_next"
def ___a64_l_next_ptr : Ident := identOfString "__a64_l_next_ptr"
def ___a64_l_next_tag : Ident := identOfString "__a64_l_next_tag"
def ___a64_l_reg : Ident := identOfString "__a64_l_reg"
def ___a64_l_reg__1 : Ident := identOfString "__a64_l_reg__1"
def ___a64_mat_base : Ident := identOfString "__a64_mat_base"
def ___a64_mat_base__1 : Ident := identOfString "__a64_mat_base__1"
def ___a64_mat_tag : Ident := identOfString "__a64_mat_tag"
def ___a64_mat_value : Ident := identOfString "__a64_mat_value"
def ___a64_read_tag : Ident := identOfString "__a64_read_tag"
def ___a64_read_value : Ident := identOfString "__a64_read_value"
def ___a64_release_i : Ident := identOfString "__a64_release_i"
def ___a64_release_new : Ident := identOfString "__a64_release_new"
def ___a64_release_off : Ident := identOfString "__a64_release_off"
def ___a64_release_old : Ident := identOfString "__a64_release_old"
def ___a64_release_w : Ident := identOfString "__a64_release_w"
def ___a64_stack : Ident := identOfString "__a64_stack"
def ___a64_tag_cells : Ident := identOfString "__a64_tag_cells"
def ___a64_unmat_base : Ident := identOfString "__a64_unmat_base"
def ___a64_unmat_base__1 : Ident := identOfString "__a64_unmat_base__1"
def ___a64_unmat_tag : Ident := identOfString "__a64_unmat_tag"
def ___a64_unmat_value : Ident := identOfString "__a64_unmat_value"
def ___a64_write_base : Ident := identOfString "__a64_write_base"
def ___a64_write_old_sp : Ident := identOfString "__a64_write_old_sp"
def ___a64_write_value : Ident := identOfString "__a64_write_value"
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
def ___ti : Ident := identOfString "__ti"
def ___tp : Ident := identOfString "__tp"
def ___ts : Ident := identOfString "__ts"
def ___tv : Ident := identOfString "__tv"
def _arm64_sim_gpr : Ident := identOfString "arm64_sim_gpr"
def _arm64_sim_unsupported_opcode : Ident := identOfString "arm64_sim_unsupported_opcode"
def _b : Ident := identOfString "b"
def _bias : Ident := identOfString "bias"
def _capacity : Ident := identOfString "capacity"
def _coordinates : Ident := identOfString "coordinates"
def _dst : Ident := identOfString "dst"
def _imm : Ident := identOfString "imm"
def _kprog_arm64_coordinates : Ident := identOfString "kprog_arm64_coordinates"
def _kprog_arm64_exec_adrp : Ident := identOfString "kprog_arm64_exec_adrp"
def _kprog_arm64_materialize : Ident := identOfString "kprog_arm64_materialize"
def _kprog_arm64_read_reg : Ident := identOfString "kprog_arm64_read_reg"
def _kprog_arm64_return_base : Ident := identOfString "kprog_arm64_return_base"
def _kprog_arm64_stack_base : Ident := identOfString "kprog_arm64_stack_base"
def _kprog_arm64_unmaterialize : Ident := identOfString "kprog_arm64_unmaterialize"
def _kprog_arm64_write_ptr : Ident := identOfString "kprog_arm64_write_ptr"
def _kprog_arm64_write_reg : Ident := identOfString "kprog_arm64_write_reg"
def _main : Ident := identOfString "main"
def _native_lab_entry_input : Ident := identOfString "native_lab_entry_input"
def _op : Ident := identOfString "op"
def _ptr : Ident := identOfString "ptr"
def _reg : Ident := identOfString "reg"
def _registers : Ident := identOfString "registers"
def _result : Ident := identOfString "result"
def _return_base : Ident := identOfString "return_base"
def _return_valid : Ident := identOfString "return_valid"
def _sp_base : Ident := identOfString "sp_base"
def _sp_valid : Ident := identOfString "sp_valid"
def _stack_bytes : Ident := identOfString "stack_bytes"
def _stack_offset : Ident := identOfString "stack_offset"
def _stack_tags : Ident := identOfString "stack_tags"
def _tag : Ident := identOfString "tag"
def _tags : Ident := identOfString "tags"
def _value : Ident := identOfString "value"
def _w : Ident := identOfString "w"
def _width : Ident := identOfString "width"
def _x : Ident := identOfString "x"
def _t'1 : Ident := (Positive.ofNat 128)
def _t'10 : Ident := (Positive.ofNat 137)
def _t'11 : Ident := (Positive.ofNat 138)
def _t'12 : Ident := (Positive.ofNat 139)
def _t'13 : Ident := (Positive.ofNat 140)
def _t'14 : Ident := (Positive.ofNat 141)
def _t'15 : Ident := (Positive.ofNat 142)
def _t'16 : Ident := (Positive.ofNat 143)
def _t'2 : Ident := (Positive.ofNat 129)
def _t'3 : Ident := (Positive.ofNat 130)
def _t'4 : Ident := (Positive.ofNat 131)
def _t'5 : Ident := (Positive.ofNat 132)
def _t'6 : Ident := (Positive.ofNat 133)
def _t'7 : Ident := (Positive.ofNat 134)
def _t'8 : Ident := (Positive.ofNat 135)
def _t'9 : Ident := (Positive.ofNat 136)

def f_kprog_arm64_stack_base : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_coordinates,
                 (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))],
  fn_vars := [],
  fn_temps := [(_result, tulong), (_t'1, tulong), (_t'2, tuchar)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sset _t'2
          (Expr.Efield
            (Expr.Ederef
              (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
              (Ty.Tstruct _kprog_arm64_coordinates noattr)) _sp_valid tuchar))
        (Stmt.Sifthenelse (Expr.Eunop Unop.Onotbool
                            (Expr.Etempvar _t'2 tuchar) tint)
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Scall (some _t'1)
                (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                     tulong cc_default))
                [(Expr.Econst_int (Integers.Int.repr 1) tint)])
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                    (Ty.Tstruct _kprog_arm64_coordinates noattr)) _sp_base
                  tulong) (Expr.Etempvar _t'1 tulong)))
            (Stmt.Sassign
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                  (Ty.Tstruct _kprog_arm64_coordinates noattr)) _sp_valid
                tuchar) (Expr.Econst_int (Integers.Int.repr 1) tint)))
          Stmt.Sskip))
      (Stmt.Sset _result
        (Expr.Efield
          (Expr.Ederef
            (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
            (Ty.Tstruct _kprog_arm64_coordinates noattr)) _sp_base tulong)))
    Stmt.Sbreak)
  (Stmt.Sreturn (some (Expr.Etempvar _result tulong))))
}

def f_kprog_arm64_return_base : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_coordinates,
                 (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))],
  fn_vars := [],
  fn_temps := [(_result, tulong), (_t'1, tulong), (_t'2, tuchar)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sset _t'2
          (Expr.Efield
            (Expr.Ederef
              (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
              (Ty.Tstruct _kprog_arm64_coordinates noattr)) _return_valid
            tuchar))
        (Stmt.Sifthenelse (Expr.Eunop Unop.Onotbool
                            (Expr.Etempvar _t'2 tuchar) tint)
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Scall (some _t'1)
                (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                     tulong cc_default))
                [(Expr.Econst_int (Integers.Int.repr 3) tint)])
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                    (Ty.Tstruct _kprog_arm64_coordinates noattr))
                  _return_base tulong) (Expr.Etempvar _t'1 tulong)))
            (Stmt.Sassign
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                  (Ty.Tstruct _kprog_arm64_coordinates noattr)) _return_valid
                tuchar) (Expr.Econst_int (Integers.Int.repr 1) tint)))
          Stmt.Sskip))
      (Stmt.Sset _result
        (Expr.Efield
          (Expr.Ederef
            (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
            (Ty.Tstruct _kprog_arm64_coordinates noattr)) _return_base
          tulong)))
    Stmt.Sbreak)
  (Stmt.Sreturn (some (Expr.Etempvar _result tulong))))
}

def s_kprog_arm64_materialize_0 : Stmt :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'2)
    (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                         cc_default))
    [(Expr.Econst_int (Integers.Int.repr 3) tint)])
  (Stmt.Sassign
    (Expr.Efield
      (Expr.Ederef
        (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
        (Ty.Tstruct _kprog_arm64_coordinates noattr)) _return_base tulong)
    (Expr.Etempvar _t'2 tulong)))

def s_kprog_arm64_materialize_1 : Stmt :=
(Stmt.Sassign
  (Expr.Efield
    (Expr.Ederef
      (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
      (Ty.Tstruct _kprog_arm64_coordinates noattr)) _return_valid tuchar)
  (Expr.Econst_int (Integers.Int.repr 1) tint))

def f_kprog_arm64_materialize : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_coordinates,
                 (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))),
                (_value, tulong), (_tag, tuchar)],
  fn_vars := [],
  fn_temps := [(_result, tulong), (___a64_mat_value, tulong),
               (___a64_mat_tag, tuchar), (___a64_mat_base, tulong),
               (___a64_mat_base__1, tulong), (_t'2, tulong), (_t'1, tulong),
               (_t'4, tuchar), (_t'3, tuchar)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sset ___a64_mat_value (Expr.Etempvar _value tulong))
      (Stmt.Ssequence
        (Stmt.Sset ___a64_mat_tag
          (Expr.Ecast (Expr.Etempvar _tag tuchar) tuchar))
        (Stmt.Ssequence
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar ___a64_mat_tag tuchar)
                              (Expr.Econst_int (Integers.Int.repr 4) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Sloop
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sset _t'4
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                          (Ty.Tstruct _kprog_arm64_coordinates noattr))
                        _sp_valid tuchar))
                    (Stmt.Sifthenelse (Expr.Eunop Unop.Onotbool
                                        (Expr.Etempvar _t'4 tuchar) tint)
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'1)
                            (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                 [tuint]
                                                                 tulong
                                                                 cc_default))
                            [(Expr.Econst_int (Integers.Int.repr 1) tint)])
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                                (Ty.Tstruct _kprog_arm64_coordinates noattr))
                              _sp_base tulong) (Expr.Etempvar _t'1 tulong)))
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                              (Ty.Tstruct _kprog_arm64_coordinates noattr))
                            _sp_valid tuchar)
                          (Expr.Econst_int (Integers.Int.repr 1) tint)))
                      Stmt.Sskip))
                  (Stmt.Sset ___a64_mat_base
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                        (Ty.Tstruct _kprog_arm64_coordinates noattr))
                      _sp_base tulong)))
                Stmt.Sbreak)
              (Stmt.Sset ___a64_mat_value
                (Expr.Ebinop Binop.Oadd
                  (Expr.Etempvar ___a64_mat_value tulong)
                  (Expr.Etempvar ___a64_mat_base tulong) tulong)))
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Etempvar ___a64_mat_tag tuchar)
                                (Expr.Econst_int (Integers.Int.repr 10) tuint)
                                tint)
              (Stmt.Ssequence
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sset _t'3
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                            (Ty.Tstruct _kprog_arm64_coordinates noattr))
                          _return_valid tuchar))
                      (Stmt.Sifthenelse (Expr.Eunop Unop.Onotbool
                                          (Expr.Etempvar _t'3 tuchar) tint)
                        (Stmt.Ssequence
                          s_kprog_arm64_materialize_0
                          s_kprog_arm64_materialize_1)
                        Stmt.Sskip))
                    (Stmt.Sset ___a64_mat_base__1
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                          (Ty.Tstruct _kprog_arm64_coordinates noattr))
                        _return_base tulong)))
                  Stmt.Sbreak)
                (Stmt.Sset ___a64_mat_value
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Etempvar ___a64_mat_value tulong)
                    (Expr.Etempvar ___a64_mat_base__1 tulong) tulong)))
              Stmt.Sskip))
          (Stmt.Sset _result (Expr.Etempvar ___a64_mat_value tulong)))))
    Stmt.Sbreak)
  (Stmt.Sreturn (some (Expr.Etempvar _result tulong))))
}

def s_kprog_arm64_unmaterialize_0 : Stmt :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'2)
    (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                         cc_default))
    [(Expr.Econst_int (Integers.Int.repr 3) tint)])
  (Stmt.Sassign
    (Expr.Efield
      (Expr.Ederef
        (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
        (Ty.Tstruct _kprog_arm64_coordinates noattr)) _return_base tulong)
    (Expr.Etempvar _t'2 tulong)))

def s_kprog_arm64_unmaterialize_1 : Stmt :=
(Stmt.Sassign
  (Expr.Efield
    (Expr.Ederef
      (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
      (Ty.Tstruct _kprog_arm64_coordinates noattr)) _return_valid tuchar)
  (Expr.Econst_int (Integers.Int.repr 1) tint))

def f_kprog_arm64_unmaterialize : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_coordinates,
                 (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))),
                (_value, tulong), (_tag, tuchar)],
  fn_vars := [],
  fn_temps := [(_result, tulong), (___a64_unmat_value, tulong),
               (___a64_unmat_tag, tuchar), (___a64_unmat_base, tulong),
               (___a64_unmat_base__1, tulong), (_t'2, tulong),
               (_t'1, tulong), (_t'4, tuchar), (_t'3, tuchar)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sset ___a64_unmat_value (Expr.Etempvar _value tulong))
      (Stmt.Ssequence
        (Stmt.Sset ___a64_unmat_tag
          (Expr.Ecast (Expr.Etempvar _tag tuchar) tuchar))
        (Stmt.Ssequence
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar ___a64_unmat_tag tuchar)
                              (Expr.Econst_int (Integers.Int.repr 4) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Sloop
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sset _t'4
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                          (Ty.Tstruct _kprog_arm64_coordinates noattr))
                        _sp_valid tuchar))
                    (Stmt.Sifthenelse (Expr.Eunop Unop.Onotbool
                                        (Expr.Etempvar _t'4 tuchar) tint)
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'1)
                            (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                 [tuint]
                                                                 tulong
                                                                 cc_default))
                            [(Expr.Econst_int (Integers.Int.repr 1) tint)])
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                                (Ty.Tstruct _kprog_arm64_coordinates noattr))
                              _sp_base tulong) (Expr.Etempvar _t'1 tulong)))
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                              (Ty.Tstruct _kprog_arm64_coordinates noattr))
                            _sp_valid tuchar)
                          (Expr.Econst_int (Integers.Int.repr 1) tint)))
                      Stmt.Sskip))
                  (Stmt.Sset ___a64_unmat_base
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                        (Ty.Tstruct _kprog_arm64_coordinates noattr))
                      _sp_base tulong)))
                Stmt.Sbreak)
              (Stmt.Sset ___a64_unmat_value
                (Expr.Ebinop Binop.Osub
                  (Expr.Etempvar ___a64_unmat_value tulong)
                  (Expr.Etempvar ___a64_unmat_base tulong) tulong)))
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Etempvar ___a64_unmat_tag tuchar)
                                (Expr.Econst_int (Integers.Int.repr 10) tuint)
                                tint)
              (Stmt.Ssequence
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sset _t'3
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                            (Ty.Tstruct _kprog_arm64_coordinates noattr))
                          _return_valid tuchar))
                      (Stmt.Sifthenelse (Expr.Eunop Unop.Onotbool
                                          (Expr.Etempvar _t'3 tuchar) tint)
                        (Stmt.Ssequence
                          s_kprog_arm64_unmaterialize_0
                          s_kprog_arm64_unmaterialize_1)
                        Stmt.Sskip))
                    (Stmt.Sset ___a64_unmat_base__1
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                          (Ty.Tstruct _kprog_arm64_coordinates noattr))
                        _return_base tulong)))
                  Stmt.Sbreak)
                (Stmt.Sset ___a64_unmat_value
                  (Expr.Ebinop Binop.Osub
                    (Expr.Etempvar ___a64_unmat_value tulong)
                    (Expr.Etempvar ___a64_unmat_base__1 tulong) tulong)))
              Stmt.Sskip))
          (Stmt.Sset _result (Expr.Etempvar ___a64_unmat_value tulong)))))
    Stmt.Sbreak)
  (Stmt.Sreturn (some (Expr.Etempvar _result tulong))))
}

def s_kprog_arm64_read_reg_0 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
      (Expr.Econst_int (Integers.Int.repr 15) tint)
      (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
    (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
  (Expr.Ebinop Binop.Oadd
    (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 15) tuint) tuchar)
    (tptr (Ty.Tunion _arm64_sim_gpr noattr))))

def s_kprog_arm64_read_reg_1 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
      (Expr.Econst_int (Integers.Int.repr 1) tint) (tptr (tptr tuchar)))
    (tptr tuchar))
  (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuchar)
    (tptr tuchar)))

def s_kprog_arm64_read_reg_2 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
      (Expr.Econst_int (Integers.Int.repr 18) tint) (tptr (tptr tuchar)))
    (tptr tuchar))
  (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 18) tuint) tuchar)
    (tptr tuchar)))

def s_kprog_arm64_read_reg_3 : Stmt :=
(Stmt.Sset ___a64_l_reg (Expr.Etempvar _reg tulong))

def s_kprog_arm64_read_reg_4 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Etempvar ___a64_l_reg tulong)
                      (Expr.Econst_int (Integers.Int.repr 32) tuint) tint)
    (Stmt.Ssequence
      (Stmt.Sset _t'11
        (Expr.Efield
          (Expr.Ederef
            (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
            (Ty.Tstruct _kprog_arm64_coordinates noattr)) _stack_offset
          tlong))
      (Stmt.Sset _t'1
        (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'11 tlong) tulong) tulong)))
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                        (Expr.Etempvar ___a64_l_reg tulong)
                        (Expr.Econst_int (Integers.Int.repr 31) tuint) tint)
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sset _t'9
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                (Expr.Ecast (Expr.Etempvar ___a64_l_reg tulong) tuchar)
                (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
              (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
          (Stmt.Ssequence
            (Stmt.Sset _t'10
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar _t'9 (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                  (Ty.Tunion _arm64_sim_gpr noattr)) _x tulong))
            (Stmt.Sset _t'1 (Expr.Ecast (Expr.Etempvar _t'10 tulong) tulong))))
        (Stmt.Sset _t'1 (Expr.Ecast (Expr.Etempvar _t'1 tulong) tulong)))
      (Stmt.Ssequence
        (Stmt.Sset _t'1
          (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong)
            tulong))
        (Stmt.Sset _t'1 (Expr.Ecast (Expr.Etempvar _t'1 tulong) tulong)))))
  (Stmt.Sset ___a64_read_value (Expr.Etempvar _t'1 tulong)))

def s_kprog_arm64_read_reg_5 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___a64_l_reg__1 (Expr.Etempvar _reg tulong))
  (Stmt.Ssequence
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                        (Expr.Etempvar ___a64_l_reg__1 tulong)
                        (Expr.Econst_int (Integers.Int.repr 32) tuint) tint)
      (Stmt.Sset _t'2
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 4) tuint) tuint))
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                          (Expr.Etempvar ___a64_l_reg__1 tulong)
                          (Expr.Econst_int (Integers.Int.repr 31) tuint)
                          tint)
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sset _t'7
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                  (Expr.Ecast (Expr.Etempvar ___a64_l_reg__1 tulong) tuchar)
                  (tptr (tptr tuchar))) (tptr tuchar)))
            (Stmt.Ssequence
              (Stmt.Sset _t'8
                (Expr.Ederef (Expr.Etempvar _t'7 (tptr tuchar)) tuchar))
              (Stmt.Sset _t'2 (Expr.Ecast (Expr.Etempvar _t'8 tuchar) tuint))))
          (Stmt.Sset _t'2 (Expr.Ecast (Expr.Etempvar _t'2 tuint) tuint)))
        (Stmt.Ssequence
          (Stmt.Sset _t'2
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuint))
          (Stmt.Sset _t'2 (Expr.Ecast (Expr.Etempvar _t'2 tuint) tuint)))))
    (Stmt.Sset ___a64_read_tag
      (Expr.Ecast (Expr.Etempvar _t'2 tuint) tuchar))))

def s_kprog_arm64_read_reg_6 : Stmt :=
Stmt.Sbreak

def s_kprog_arm64_read_reg_7 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___a64_mat_value (Expr.Etempvar ___a64_read_value tulong))
  (Stmt.Ssequence
    (Stmt.Sset ___a64_mat_tag
      (Expr.Ecast (Expr.Etempvar ___a64_read_tag tuchar) tuchar))
    (Stmt.Ssequence
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                          (Expr.Etempvar ___a64_mat_tag tuchar)
                          (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
        (Stmt.Ssequence
          (Stmt.Sloop
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'6
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                      (Ty.Tstruct _kprog_arm64_coordinates noattr)) _sp_valid
                    tuchar))
                (Stmt.Sifthenelse (Expr.Eunop Unop.Onotbool
                                    (Expr.Etempvar _t'6 tuchar) tint)
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Scall (some _t'3)
                        (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                             [tuint] tulong
                                                             cc_default))
                        [(Expr.Econst_int (Integers.Int.repr 1) tint)])
                      (Stmt.Sassign
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                            (Ty.Tstruct _kprog_arm64_coordinates noattr))
                          _sp_base tulong) (Expr.Etempvar _t'3 tulong)))
                    (Stmt.Sassign
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                          (Ty.Tstruct _kprog_arm64_coordinates noattr))
                        _sp_valid tuchar)
                      (Expr.Econst_int (Integers.Int.repr 1) tint)))
                  Stmt.Sskip))
              (Stmt.Sset ___a64_mat_base
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                    (Ty.Tstruct _kprog_arm64_coordinates noattr)) _sp_base
                  tulong)))
            Stmt.Sbreak)
          (Stmt.Sset ___a64_mat_value
            (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___a64_mat_value tulong)
              (Expr.Etempvar ___a64_mat_base tulong) tulong)))
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar ___a64_mat_tag tuchar)
                            (Expr.Econst_int (Integers.Int.repr 10) tuint)
                            tint)
          (Stmt.Ssequence
            (Stmt.Sloop
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sset _t'5
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                        (Ty.Tstruct _kprog_arm64_coordinates noattr))
                      _return_valid tuchar))
                  (Stmt.Sifthenelse (Expr.Eunop Unop.Onotbool
                                      (Expr.Etempvar _t'5 tuchar) tint)
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Scall (some _t'4)
                          (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                               [tuint] tulong
                                                               cc_default))
                          [(Expr.Econst_int (Integers.Int.repr 3) tint)])
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                              (Ty.Tstruct _kprog_arm64_coordinates noattr))
                            _return_base tulong) (Expr.Etempvar _t'4 tulong)))
                      (Stmt.Sassign
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                            (Ty.Tstruct _kprog_arm64_coordinates noattr))
                          _return_valid tuchar)
                        (Expr.Econst_int (Integers.Int.repr 1) tint)))
                    Stmt.Sskip))
                (Stmt.Sset ___a64_mat_base__1
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                      (Ty.Tstruct _kprog_arm64_coordinates noattr))
                    _return_base tulong)))
              Stmt.Sbreak)
            (Stmt.Sset ___a64_mat_value
              (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___a64_mat_value tulong)
                (Expr.Etempvar ___a64_mat_base__1 tulong) tulong)))
          Stmt.Sskip))
      (Stmt.Sset _result (Expr.Etempvar ___a64_mat_value tulong)))))

def s_kprog_arm64_read_reg_8 : Stmt :=
Stmt.Sbreak

def s_kprog_arm64_read_reg_9 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
        (Expr.Econst_int (Integers.Int.repr 19) tint) (tptr (tptr tuchar)))
      (tptr tuchar))
    (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 19) tuint) tuchar)
      (tptr tuchar)))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
          (Expr.Econst_int (Integers.Int.repr 20) tint) (tptr (tptr tuchar)))
        (tptr tuchar))
      (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 20) tuint) tuchar)
        (tptr tuchar)))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
            (Expr.Econst_int (Integers.Int.repr 21) tint)
            (tptr (tptr tuchar))) (tptr tuchar))
        (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 21) tuint) tuchar)
          (tptr tuchar)))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
              (Expr.Econst_int (Integers.Int.repr 22) tint)
              (tptr (tptr tuchar))) (tptr tuchar))
          (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 22) tuint)
              tuchar) (tptr tuchar)))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                (Expr.Econst_int (Integers.Int.repr 23) tint)
                (tptr (tptr tuchar))) (tptr tuchar))
            (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 23) tuint)
                tuchar) (tptr tuchar)))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                  (Expr.Econst_int (Integers.Int.repr 24) tint)
                  (tptr (tptr tuchar))) (tptr tuchar))
              (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 24) tuint)
                  tuchar) (tptr tuchar)))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                    (Expr.Econst_int (Integers.Int.repr 25) tint)
                    (tptr (tptr tuchar))) (tptr tuchar))
                (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 25) tuint)
                    tuchar) (tptr tuchar)))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                      (Expr.Econst_int (Integers.Int.repr 26) tint)
                      (tptr (tptr tuchar))) (tptr tuchar))
                  (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
                    (Expr.Ecast
                      (Expr.Econst_int (Integers.Int.repr 26) tuint) tuchar)
                    (tptr tuchar)))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                        (Expr.Econst_int (Integers.Int.repr 27) tint)
                        (tptr (tptr tuchar))) (tptr tuchar))
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Etempvar _tags (tptr tuchar))
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 27) tuint)
                        tuchar) (tptr tuchar)))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                          (Expr.Econst_int (Integers.Int.repr 28) tint)
                          (tptr (tptr tuchar))) (tptr tuchar))
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar _tags (tptr tuchar))
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 28) tuint)
                          tuchar) (tptr tuchar)))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                            (Expr.Econst_int (Integers.Int.repr 29) tint)
                            (tptr (tptr tuchar))) (tptr tuchar))
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Etempvar _tags (tptr tuchar))
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 29) tuint)
                            tuchar) (tptr tuchar)))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                              (Expr.Econst_int (Integers.Int.repr 30) tint)
                              (tptr (tptr tuchar))) (tptr tuchar))
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar _tags (tptr tuchar))
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 30) tuint)
                              tuchar) (tptr tuchar)))
                        (Stmt.Ssequence
                          (Stmt.Sloop
                            (Stmt.Ssequence
                              (Stmt.Sloop
                                (Stmt.Ssequence
                                  s_kprog_arm64_read_reg_3
                                  s_kprog_arm64_read_reg_4)
                                Stmt.Sbreak)
                              (Stmt.Ssequence
                                (Stmt.Sloop
                                  s_kprog_arm64_read_reg_5
                                  s_kprog_arm64_read_reg_6)
                                (Stmt.Sloop
                                  s_kprog_arm64_read_reg_7
                                  s_kprog_arm64_read_reg_8)))
                            Stmt.Sbreak)
                          (Stmt.Sreturn (some (Expr.Etempvar _result tulong))))))))))))))))

def s_kprog_arm64_read_reg_10 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
        (Expr.Econst_int (Integers.Int.repr 2) tint) (tptr (tptr tuchar)))
      (tptr tuchar))
    (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint) tuchar)
      (tptr tuchar)))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
          (Expr.Econst_int (Integers.Int.repr 3) tint) (tptr (tptr tuchar)))
        (tptr tuchar))
      (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuchar)
        (tptr tuchar)))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
            (Expr.Econst_int (Integers.Int.repr 4) tint)
            (tptr (tptr tuchar))) (tptr tuchar))
        (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 4) tuint) tuchar)
          (tptr tuchar)))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
              (Expr.Econst_int (Integers.Int.repr 5) tint)
              (tptr (tptr tuchar))) (tptr tuchar))
          (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 5) tuint) tuchar)
            (tptr tuchar)))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                (Expr.Econst_int (Integers.Int.repr 6) tint)
                (tptr (tptr tuchar))) (tptr tuchar))
            (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 6) tuint)
                tuchar) (tptr tuchar)))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                  (Expr.Econst_int (Integers.Int.repr 7) tint)
                  (tptr (tptr tuchar))) (tptr tuchar))
              (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 7) tuint)
                  tuchar) (tptr tuchar)))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                    (Expr.Econst_int (Integers.Int.repr 8) tint)
                    (tptr (tptr tuchar))) (tptr tuchar))
                (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tuint)
                    tuchar) (tptr tuchar)))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                      (Expr.Econst_int (Integers.Int.repr 9) tint)
                      (tptr (tptr tuchar))) (tptr tuchar))
                  (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 9) tuint)
                      tuchar) (tptr tuchar)))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                        (Expr.Econst_int (Integers.Int.repr 10) tint)
                        (tptr (tptr tuchar))) (tptr tuchar))
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Etempvar _tags (tptr tuchar))
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 10) tuint)
                        tuchar) (tptr tuchar)))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                          (Expr.Econst_int (Integers.Int.repr 11) tint)
                          (tptr (tptr tuchar))) (tptr tuchar))
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar _tags (tptr tuchar))
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 11) tuint)
                          tuchar) (tptr tuchar)))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                            (Expr.Econst_int (Integers.Int.repr 12) tint)
                            (tptr (tptr tuchar))) (tptr tuchar))
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Etempvar _tags (tptr tuchar))
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 12) tuint)
                            tuchar) (tptr tuchar)))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                              (Expr.Econst_int (Integers.Int.repr 13) tint)
                              (tptr (tptr tuchar))) (tptr tuchar))
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar _tags (tptr tuchar))
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 13) tuint)
                              tuchar) (tptr tuchar)))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                (Expr.Econst_int (Integers.Int.repr 14) tint)
                                (tptr (tptr tuchar))) (tptr tuchar))
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar _tags (tptr tuchar))
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 14) tuint)
                                tuchar) (tptr tuchar)))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                  (Expr.Econst_int (Integers.Int.repr 15) tint)
                                  (tptr (tptr tuchar))) (tptr tuchar))
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Etempvar _tags (tptr tuchar))
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 15) tuint)
                                  tuchar) (tptr tuchar)))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                    (Expr.Econst_int (Integers.Int.repr 16) tint)
                                    (tptr (tptr tuchar))) (tptr tuchar))
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Etempvar _tags (tptr tuchar))
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                    tuchar) (tptr tuchar)))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                      (Expr.Econst_int (Integers.Int.repr 17) tint)
                                      (tptr (tptr tuchar))) (tptr tuchar))
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Etempvar _tags (tptr tuchar))
                                    (Expr.Ecast
                                      (Expr.Econst_int (Integers.Int.repr 17) tuint)
                                      tuchar) (tptr tuchar)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_read_reg_2
                                  s_kprog_arm64_read_reg_9)))))))))))))))))

def s_kprog_arm64_read_reg_11 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
        (Expr.Econst_int (Integers.Int.repr 16) tint)
        (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
      (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
    (Expr.Ebinop Binop.Oadd
      (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 16) tuint) tuchar)
      (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
          (Expr.Econst_int (Integers.Int.repr 17) tint)
          (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
        (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
      (Expr.Ebinop Binop.Oadd
        (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 17) tuint) tuchar)
        (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
            (Expr.Econst_int (Integers.Int.repr 18) tint)
            (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
          (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
        (Expr.Ebinop Binop.Oadd
          (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 18) tuint) tuchar)
          (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
              (Expr.Econst_int (Integers.Int.repr 19) tint)
              (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
            (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
          (Expr.Ebinop Binop.Oadd
            (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 19) tuint)
              tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                (Expr.Econst_int (Integers.Int.repr 20) tint)
                (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
              (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
            (Expr.Ebinop Binop.Oadd
              (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 20) tuint)
                tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                  (Expr.Econst_int (Integers.Int.repr 21) tint)
                  (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
              (Expr.Ebinop Binop.Oadd
                (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 21) tuint)
                  tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                    (Expr.Econst_int (Integers.Int.repr 22) tint)
                    (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                  (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                (Expr.Ebinop Binop.Oadd
                  (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 22) tuint)
                    tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                      (Expr.Econst_int (Integers.Int.repr 23) tint)
                      (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                    (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                    (Expr.Ecast
                      (Expr.Econst_int (Integers.Int.repr 23) tuint) tuchar)
                    (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                        (Expr.Econst_int (Integers.Int.repr 24) tint)
                        (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                      (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 24) tuint)
                        tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                          (Expr.Econst_int (Integers.Int.repr 25) tint)
                          (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                        (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 25) tuint)
                          tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                            (Expr.Econst_int (Integers.Int.repr 26) tint)
                            (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                          (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 26) tuint)
                            tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                              (Expr.Econst_int (Integers.Int.repr 27) tint)
                              (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                            (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 27) tuint)
                              tuchar)
                            (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                (Expr.Econst_int (Integers.Int.repr 28) tint)
                                (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                              (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 28) tuint)
                                tuchar)
                              (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                  (Expr.Econst_int (Integers.Int.repr 29) tint)
                                  (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 29) tuint)
                                  tuchar)
                                (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                    (Expr.Econst_int (Integers.Int.repr 30) tint)
                                    (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                  (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                    tuchar)
                                  (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                      (Expr.Econst_int (Integers.Int.repr 0) tint)
                                      (tptr (tptr tuchar))) (tptr tuchar))
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Etempvar _tags (tptr tuchar))
                                    (Expr.Ecast
                                      (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                      tuchar) (tptr tuchar)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_read_reg_1
                                  s_kprog_arm64_read_reg_10)))))))))))))))))

def f_kprog_arm64_read_reg : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_coordinates,
                 (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))),
                (_registers, (tptr (Ty.Tunion _arm64_sim_gpr noattr))),
                (_tags, (tptr tuchar)), (_reg, tulong)],
  fn_vars := [(___a64_cells,
               (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31)),
              (___a64_tag_cells, (tarray (tptr tuchar) 31))],
  fn_temps := [(_result, tulong), (___a64_read_value, tulong),
               (___a64_read_tag, tuchar), (___a64_l_reg, tulong),
               (___a64_l_reg__1, tulong), (___a64_mat_value, tulong),
               (___a64_mat_tag, tuchar), (___a64_mat_base, tulong),
               (___a64_mat_base__1, tulong), (_t'4, tulong), (_t'3, tulong),
               (_t'2, tuint), (_t'1, tulong), (_t'11, tlong),
               (_t'10, tulong),
               (_t'9, (tptr (Ty.Tunion _arm64_sim_gpr noattr))),
               (_t'8, tuchar), (_t'7, (tptr tuchar)), (_t'6, tuchar),
               (_t'5, tuchar)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
        (Expr.Econst_int (Integers.Int.repr 0) tint)
        (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
      (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
    (Expr.Ebinop Binop.Oadd
      (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuchar)
      (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
          (Expr.Econst_int (Integers.Int.repr 1) tint)
          (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
        (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
      (Expr.Ebinop Binop.Oadd
        (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuchar)
        (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
            (Expr.Econst_int (Integers.Int.repr 2) tint)
            (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
          (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
        (Expr.Ebinop Binop.Oadd
          (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint) tuchar)
          (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
              (Expr.Econst_int (Integers.Int.repr 3) tint)
              (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
            (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
          (Expr.Ebinop Binop.Oadd
            (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuchar)
            (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                (Expr.Econst_int (Integers.Int.repr 4) tint)
                (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
              (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
            (Expr.Ebinop Binop.Oadd
              (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 4) tuint)
                tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                  (Expr.Econst_int (Integers.Int.repr 5) tint)
                  (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
              (Expr.Ebinop Binop.Oadd
                (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 5) tuint)
                  tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                    (Expr.Econst_int (Integers.Int.repr 6) tint)
                    (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                  (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                (Expr.Ebinop Binop.Oadd
                  (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 6) tuint)
                    tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                      (Expr.Econst_int (Integers.Int.repr 7) tint)
                      (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                    (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 7) tuint)
                      tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                        (Expr.Econst_int (Integers.Int.repr 8) tint)
                        (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                      (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 8) tuint) tuchar)
                      (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                          (Expr.Econst_int (Integers.Int.repr 9) tint)
                          (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                        (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 9) tuint)
                          tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                            (Expr.Econst_int (Integers.Int.repr 10) tint)
                            (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                          (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 10) tuint)
                            tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                              (Expr.Econst_int (Integers.Int.repr 11) tint)
                              (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                            (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 11) tuint)
                              tuchar)
                            (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                (Expr.Econst_int (Integers.Int.repr 12) tint)
                                (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                              (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 12) tuint)
                                tuchar)
                              (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                  (Expr.Econst_int (Integers.Int.repr 13) tint)
                                  (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 13) tuint)
                                  tuchar)
                                (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                    (Expr.Econst_int (Integers.Int.repr 14) tint)
                                    (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                  (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 14) tuint)
                                    tuchar)
                                  (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                              (Stmt.Ssequence
                                s_kprog_arm64_read_reg_0
                                s_kprog_arm64_read_reg_11))))))))))))))))
}

def s_kprog_arm64_write_reg_0 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
      (Expr.Econst_int (Integers.Int.repr 15) tint)
      (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
    (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
  (Expr.Ebinop Binop.Oadd
    (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 15) tuint) tuchar)
    (tptr (Ty.Tunion _arm64_sim_gpr noattr))))

def s_kprog_arm64_write_reg_1 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
      (Expr.Econst_int (Integers.Int.repr 1) tint) (tptr (tptr tuchar)))
    (tptr tuchar))
  (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuchar)
    (tptr tuchar)))

def s_kprog_arm64_write_reg_2 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
      (Expr.Econst_int (Integers.Int.repr 18) tint) (tptr (tptr tuchar)))
    (tptr tuchar))
  (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 18) tuint) tuchar)
    (tptr tuchar)))

def s_kprog_arm64_write_reg_3 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _width tuchar)
                      (Expr.Econst_int (Integers.Int.repr 1) tuint) tint)
    (Stmt.Sset _t'1
      (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 255) tulong) tulong))
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _width tuchar)
                        (Expr.Econst_int (Integers.Int.repr 2) tuint) tint)
      (Stmt.Ssequence
        (Stmt.Sset _t'1
          (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 65535) tulong)
            tulong))
        (Stmt.Sset _t'1 (Expr.Ecast (Expr.Etempvar _t'1 tulong) tulong)))
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _width tuchar)
                          (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sset _t'1
              (Expr.Ecast
                (Expr.Econst_long (Integers.Int64.repr 4294967295) tulong)
                tulong))
            (Stmt.Sset _t'1 (Expr.Ecast (Expr.Etempvar _t'1 tulong) tulong)))
          (Stmt.Sset _t'1 (Expr.Ecast (Expr.Etempvar _t'1 tulong) tulong)))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sset _t'1
              (Expr.Ecast
                (Expr.Econst_long (Integers.Int64.repr (-1)) tulong) tulong))
            (Stmt.Sset _t'1 (Expr.Ecast (Expr.Etempvar _t'1 tulong) tulong)))
          (Stmt.Sset _t'1 (Expr.Ecast (Expr.Etempvar _t'1 tulong) tulong))))))
  (Stmt.Sset ___a64_l_next
    (Expr.Ebinop Binop.Oand (Expr.Etempvar _value tulong)
      (Expr.Etempvar _t'1 tulong) tulong)))

def s_kprog_arm64_write_reg_4 : Stmt :=
(Stmt.Sset ___ts
  (Expr.Ecast
    (Expr.Ebinop Binop.Omul
      (Expr.Ebinop Binop.Oand (Expr.Etempvar ___ti tulong)
        (Expr.Econst_int (Integers.Int.repr 7) tuint) tulong)
      (Expr.Econst_int (Integers.Int.repr 8) tuint) tulong) tuint))

def s_kprog_arm64_write_reg_5 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___tp
    (Expr.Ecast
      (Expr.Ecast
        (Expr.Ebinop Binop.Oadd (Expr.Etempvar _stack_tags (tptr tuchar))
          (Expr.Ebinop Binop.Oand
            (Expr.Ecast (Expr.Etempvar ___ti tulong) tulong)
            (Expr.Eunop Unop.Onotint
              (Expr.Econst_long (Integers.Int64.repr 7) tulong) tulong)
            tulong) (tptr tuchar)) (tptr tvoid)) (tptr (tvolatile tulong))))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sbuiltin (some _t'9) (ExtFun.EF_vload Chunk.Mint64)
        [(tptr (tvolatile tulong))]
        [(Expr.Eaddrof
           (Expr.Ederef (Expr.Etempvar ___tp (tptr (tvolatile tulong)))
             (tvolatile tulong)) (tptr (tvolatile tulong)))])
      (Stmt.Sset ___tv (Expr.Etempvar _t'9 (tvolatile tulong))))
    (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
      [(tptr (tvolatile tulong)), (tvolatile tulong)]
      [(Expr.Eaddrof
         (Expr.Ederef (Expr.Etempvar ___tp (tptr (tvolatile tulong)))
           (tvolatile tulong)) (tptr (tvolatile tulong))),
       (Expr.Ebinop Binop.Oor
         (Expr.Ebinop Binop.Oand (Expr.Etempvar ___tv tulong)
           (Expr.Eunop Unop.Onotint
             (Expr.Ebinop Binop.Oshl
               (Expr.Econst_long (Integers.Int64.repr 255) tulong)
               (Expr.Etempvar ___ts tuint) tulong) tulong) tulong)
         (Expr.Ebinop Binop.Oshl
           (Expr.Ecast
             (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
               tuchar) tulong) (Expr.Etempvar ___ts tuint) tulong) tulong)])))

def s_kprog_arm64_write_reg_6 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Etempvar ___a64_l_reg tulong)
                      (Expr.Econst_int (Integers.Int.repr 32) tuint) tint)
    (Stmt.Ssequence
      (Stmt.Sloop
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sset _t'15
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                  (Ty.Tstruct _kprog_arm64_coordinates noattr)) _sp_valid
                tuchar))
            (Stmt.Sifthenelse (Expr.Eunop Unop.Onotbool
                                (Expr.Etempvar _t'15 tuchar) tint)
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Scall (some _t'2)
                    (Expr.Evar _native_lab_entry_input (Ty.Tfunction 
                                                         [tuint] tulong
                                                         cc_default))
                    [(Expr.Econst_int (Integers.Int.repr 1) tint)])
                  (Stmt.Sassign
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                        (Ty.Tstruct _kprog_arm64_coordinates noattr))
                      _sp_base tulong) (Expr.Etempvar _t'2 tulong)))
                (Stmt.Sassign
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                      (Ty.Tstruct _kprog_arm64_coordinates noattr)) _sp_valid
                    tuchar) (Expr.Econst_int (Integers.Int.repr 1) tint)))
              Stmt.Sskip))
          (Stmt.Sset ___a64_write_base
            (Expr.Efield
              (Expr.Ederef
                (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                (Ty.Tstruct _kprog_arm64_coordinates noattr)) _sp_base
              tulong)))
        Stmt.Sbreak)
      (Stmt.Sassign
        (Expr.Efield
          (Expr.Ederef
            (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
            (Ty.Tstruct _kprog_arm64_coordinates noattr)) _stack_offset
          tlong)
        (Expr.Ecast
          (Expr.Ebinop Binop.Osub (Expr.Etempvar ___a64_l_next tulong)
            (Expr.Etempvar ___a64_write_base tulong) tulong) tlong)))
    (Stmt.Ssequence
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                          (Expr.Etempvar ___a64_l_reg tulong)
                          (Expr.Econst_int (Integers.Int.repr 31) tuint)
                          tint)
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sifthenelse (Expr.Ebinop Binop.One
                                (Expr.Etempvar ___a64_l_reg tulong)
                                (Expr.Econst_int (Integers.Int.repr 31) tuint)
                                tint)
              (Stmt.Sset _t'5
                (Expr.Ecast
                  (Expr.Ebinop Binop.One (Expr.Etempvar ___a64_l_reg tulong)
                    (Expr.Econst_int (Integers.Int.repr 255) tuint) tint)
                  tbool))
              (Stmt.Sset _t'5 (Expr.Econst_int (Integers.Int.repr 0) tint)))
            (Stmt.Sifthenelse (Expr.Etempvar _t'5 tint)
              (Stmt.Sset _t'6
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tint)
                  tint))
              (Stmt.Sset _t'6
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                  tint))))
          (Stmt.Sset _t'4
            (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'6 tint) tuchar) tbool)))
        (Stmt.Sset _t'4 (Expr.Econst_int (Integers.Int.repr 0) tint)))
      (Stmt.Sifthenelse (Expr.Etempvar _t'4 tint)
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Etempvar _width tuchar)
                                (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                tint)
              (Stmt.Sset _t'3
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint)
                  tuint))
              (Stmt.Sset _t'3
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                  tuint)))
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Ecast (Expr.Etempvar _t'3 tuint)
                                  tuchar)
                                (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                tint)
              (Stmt.Ssequence
                (Stmt.Sset _t'14
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                      (Expr.Ecast (Expr.Etempvar ___a64_l_reg tulong) tuchar)
                      (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                    (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                (Stmt.Sassign
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Etempvar _t'14 (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                      (Ty.Tunion _arm64_sim_gpr noattr)) _x tulong)
                  (Expr.Ecast (Expr.Etempvar ___a64_l_next tulong) tuint)))
              (Stmt.Ssequence
                (Stmt.Sset _t'13
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                      (Expr.Ecast (Expr.Etempvar ___a64_l_reg tulong) tuchar)
                      (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                    (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                (Stmt.Sassign
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Etempvar _t'13 (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                      (Ty.Tunion _arm64_sim_gpr noattr)) _x tulong)
                  (Expr.Etempvar ___a64_l_next tulong)))))
          (Stmt.Ssequence
            (Stmt.Sset _t'12
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                  (Expr.Ecast (Expr.Etempvar ___a64_l_reg tulong) tuchar)
                  (tptr (tptr tuchar))) (tptr tuchar)))
            (Stmt.Sassign
              (Expr.Ederef (Expr.Etempvar _t'12 (tptr tuchar)) tuchar)
              (Expr.Econst_int (Integers.Int.repr 0) tuint))))
        Stmt.Sskip)))
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _reg tulong)
                      (Expr.Econst_int (Integers.Int.repr 32) tuint) tint)
    (Stmt.Sloop
      (Stmt.Ssequence
        (Stmt.Sset ___a64_release_old
          (Expr.Etempvar ___a64_write_old_sp tlong))
        (Stmt.Ssequence
          (Stmt.Sset ___a64_release_new
            (Expr.Efield
              (Expr.Ederef
                (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                (Ty.Tstruct _kprog_arm64_coordinates noattr)) _stack_offset
              tlong))
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Ogt
                              (Expr.Etempvar ___a64_release_new tlong)
                              (Expr.Etempvar ___a64_release_old tlong) tint)
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset ___a64_release_i
                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                        (Expr.Etempvar ___a64_release_i tuint)
                                        (Expr.Etempvar _capacity tuint) tint)
                      Stmt.Sskip
                      Stmt.Sbreak)
                    (Stmt.Ssequence
                      (Stmt.Sset ___a64_release_off
                        (Expr.Ebinop Binop.Osub
                          (Expr.Ecast (Expr.Etempvar ___a64_release_i tuint)
                            tlong)
                          (Expr.Ecast (Expr.Etempvar _bias tlong) tlong)
                          tlong))
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                            (Expr.Etempvar ___a64_release_off tlong)
                                            (Expr.Etempvar ___a64_release_old tlong)
                                            tint)
                          (Stmt.Sset _t'8
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Olt
                                (Expr.Etempvar ___a64_release_off tlong)
                                (Expr.Etempvar ___a64_release_new tlong)
                                tint) tbool))
                          (Stmt.Sset _t'8
                            (Expr.Econst_int (Integers.Int.repr 0) tint)))
                        (Stmt.Sifthenelse (Expr.Etempvar _t'8 tint)
                          (Stmt.Ssequence
                            (Stmt.Scall (some _t'7)
                              (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                   [tuint]
                                                                   tulong
                                                                   cc_default))
                              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                            (Stmt.Ssequence
                              (Stmt.Sset _t'11
                                (Expr.Efield
                                  (Expr.Evar ___a64_stack (Ty.Tstruct __2844 noattr))
                                  _b (tptr (tvolatile tuchar))))
                              (Stmt.Sbuiltin none
                                (ExtFun.EF_vstore Chunk.Mint8unsigned)
                                [(tptr (tvolatile tuchar)),
                                 (tvolatile tuchar)]
                                [(Expr.Eaddrof
                                   (Expr.Ederef
                                     (Expr.Ebinop Binop.Oadd
                                       (Expr.Etempvar _t'11 (tptr (tvolatile tuchar)))
                                       (Expr.Etempvar ___a64_release_i tuint)
                                       (tptr (tvolatile tuchar)))
                                     (tvolatile tuchar))
                                   (tptr (tvolatile tuchar))),
                                 (Expr.Ecast (Expr.Etempvar _t'7 tulong)
                                   tuchar)])))
                          Stmt.Sskip))))
                  (Stmt.Sset ___a64_release_i
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Etempvar ___a64_release_i tuint)
                      (Expr.Econst_int (Integers.Int.repr 1) tint) tuint))))
              (Stmt.Ssequence
                (Stmt.Sset ___a64_release_w
                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                        (Expr.Etempvar ___a64_release_w tuint)
                                        (Expr.Ebinop Binop.Odiv
                                          (Expr.Ebinop Binop.Oadd
                                            (Expr.Ecast
                                              (Expr.Etempvar _capacity tuint)
                                              tuint)
                                            (Expr.Econst_int (Integers.Int.repr 7) tuint)
                                            tuint)
                                          (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                          tuint) tint)
                      Stmt.Sskip
                      Stmt.Sbreak)
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                          (Expr.Ebinop Binop.Osub
                                            (Expr.Ecast
                                              (Expr.Ebinop Binop.Omul
                                                (Expr.Etempvar ___a64_release_w tuint)
                                                (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                                tuint) tlong)
                                            (Expr.Ecast
                                              (Expr.Etempvar _bias tlong)
                                              tlong) tlong)
                                          (Expr.Etempvar ___a64_release_new tlong)
                                          tint)
                        (Stmt.Sset _t'10
                          (Expr.Ecast
                            (Expr.Ebinop Binop.Ogt
                              (Expr.Ebinop Binop.Osub
                                (Expr.Ecast
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Ebinop Binop.Omul
                                      (Expr.Etempvar ___a64_release_w tuint)
                                      (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                      tuint)
                                    (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                    tuint) tlong)
                                (Expr.Ecast (Expr.Etempvar _bias tlong)
                                  tlong) tlong)
                              (Expr.Etempvar ___a64_release_old tlong) tint)
                            tbool))
                        (Stmt.Sset _t'10
                          (Expr.Econst_int (Integers.Int.repr 0) tint)))
                      (Stmt.Sifthenelse (Expr.Etempvar _t'10 tint)
                        (Stmt.Sloop
                          (Stmt.Ssequence
                            (Stmt.Sset ___ti
                              (Expr.Ecast
                                (Expr.Etempvar ___a64_release_w tuint)
                                tulong))
                            (Stmt.Ssequence
                              s_kprog_arm64_write_reg_4
                              s_kprog_arm64_write_reg_5))
                          Stmt.Sbreak)
                        Stmt.Sskip)))
                  (Stmt.Sset ___a64_release_w
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Etempvar ___a64_release_w tuint)
                      (Expr.Econst_int (Integers.Int.repr 1) tint) tuint)))))
            Stmt.Sskip)))
      Stmt.Sbreak)
    Stmt.Sskip))

def s_kprog_arm64_write_reg_7 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
        (Expr.Econst_int (Integers.Int.repr 19) tint) (tptr (tptr tuchar)))
      (tptr tuchar))
    (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 19) tuint) tuchar)
      (tptr tuchar)))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
          (Expr.Econst_int (Integers.Int.repr 20) tint) (tptr (tptr tuchar)))
        (tptr tuchar))
      (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 20) tuint) tuchar)
        (tptr tuchar)))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
            (Expr.Econst_int (Integers.Int.repr 21) tint)
            (tptr (tptr tuchar))) (tptr tuchar))
        (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 21) tuint) tuchar)
          (tptr tuchar)))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
              (Expr.Econst_int (Integers.Int.repr 22) tint)
              (tptr (tptr tuchar))) (tptr tuchar))
          (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 22) tuint)
              tuchar) (tptr tuchar)))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                (Expr.Econst_int (Integers.Int.repr 23) tint)
                (tptr (tptr tuchar))) (tptr tuchar))
            (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 23) tuint)
                tuchar) (tptr tuchar)))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                  (Expr.Econst_int (Integers.Int.repr 24) tint)
                  (tptr (tptr tuchar))) (tptr tuchar))
              (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 24) tuint)
                  tuchar) (tptr tuchar)))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                    (Expr.Econst_int (Integers.Int.repr 25) tint)
                    (tptr (tptr tuchar))) (tptr tuchar))
                (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 25) tuint)
                    tuchar) (tptr tuchar)))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                      (Expr.Econst_int (Integers.Int.repr 26) tint)
                      (tptr (tptr tuchar))) (tptr tuchar))
                  (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
                    (Expr.Ecast
                      (Expr.Econst_int (Integers.Int.repr 26) tuint) tuchar)
                    (tptr tuchar)))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                        (Expr.Econst_int (Integers.Int.repr 27) tint)
                        (tptr (tptr tuchar))) (tptr tuchar))
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Etempvar _tags (tptr tuchar))
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 27) tuint)
                        tuchar) (tptr tuchar)))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                          (Expr.Econst_int (Integers.Int.repr 28) tint)
                          (tptr (tptr tuchar))) (tptr tuchar))
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar _tags (tptr tuchar))
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 28) tuint)
                          tuchar) (tptr tuchar)))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                            (Expr.Econst_int (Integers.Int.repr 29) tint)
                            (tptr (tptr tuchar))) (tptr tuchar))
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Etempvar _tags (tptr tuchar))
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 29) tuint)
                            tuchar) (tptr tuchar)))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                              (Expr.Econst_int (Integers.Int.repr 30) tint)
                              (tptr (tptr tuchar))) (tptr tuchar))
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar _tags (tptr tuchar))
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 30) tuint)
                              tuchar) (tptr tuchar)))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Evar ___a64_stack (Ty.Tstruct __2844 noattr))
                              _b (tptr (tvolatile tuchar)))
                            (Expr.Etempvar _stack_bytes (tptr (tvolatile tuchar))))
                          (Stmt.Sloop
                            (Stmt.Ssequence
                              (Stmt.Sset ___a64_write_old_sp
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                                    (Ty.Tstruct _kprog_arm64_coordinates noattr))
                                  _stack_offset tlong))
                              (Stmt.Ssequence
                                (Stmt.Sset ___a64_l_reg
                                  (Expr.Etempvar _reg tulong))
                                (Stmt.Ssequence
                                  s_kprog_arm64_write_reg_3
                                  s_kprog_arm64_write_reg_6)))
                            Stmt.Sbreak))))))))))))))

def s_kprog_arm64_write_reg_8 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
        (Expr.Econst_int (Integers.Int.repr 2) tint) (tptr (tptr tuchar)))
      (tptr tuchar))
    (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint) tuchar)
      (tptr tuchar)))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
          (Expr.Econst_int (Integers.Int.repr 3) tint) (tptr (tptr tuchar)))
        (tptr tuchar))
      (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuchar)
        (tptr tuchar)))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
            (Expr.Econst_int (Integers.Int.repr 4) tint)
            (tptr (tptr tuchar))) (tptr tuchar))
        (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 4) tuint) tuchar)
          (tptr tuchar)))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
              (Expr.Econst_int (Integers.Int.repr 5) tint)
              (tptr (tptr tuchar))) (tptr tuchar))
          (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 5) tuint) tuchar)
            (tptr tuchar)))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                (Expr.Econst_int (Integers.Int.repr 6) tint)
                (tptr (tptr tuchar))) (tptr tuchar))
            (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 6) tuint)
                tuchar) (tptr tuchar)))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                  (Expr.Econst_int (Integers.Int.repr 7) tint)
                  (tptr (tptr tuchar))) (tptr tuchar))
              (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 7) tuint)
                  tuchar) (tptr tuchar)))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                    (Expr.Econst_int (Integers.Int.repr 8) tint)
                    (tptr (tptr tuchar))) (tptr tuchar))
                (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tuint)
                    tuchar) (tptr tuchar)))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                      (Expr.Econst_int (Integers.Int.repr 9) tint)
                      (tptr (tptr tuchar))) (tptr tuchar))
                  (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 9) tuint)
                      tuchar) (tptr tuchar)))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                        (Expr.Econst_int (Integers.Int.repr 10) tint)
                        (tptr (tptr tuchar))) (tptr tuchar))
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Etempvar _tags (tptr tuchar))
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 10) tuint)
                        tuchar) (tptr tuchar)))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                          (Expr.Econst_int (Integers.Int.repr 11) tint)
                          (tptr (tptr tuchar))) (tptr tuchar))
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar _tags (tptr tuchar))
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 11) tuint)
                          tuchar) (tptr tuchar)))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                            (Expr.Econst_int (Integers.Int.repr 12) tint)
                            (tptr (tptr tuchar))) (tptr tuchar))
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Etempvar _tags (tptr tuchar))
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 12) tuint)
                            tuchar) (tptr tuchar)))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                              (Expr.Econst_int (Integers.Int.repr 13) tint)
                              (tptr (tptr tuchar))) (tptr tuchar))
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar _tags (tptr tuchar))
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 13) tuint)
                              tuchar) (tptr tuchar)))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                (Expr.Econst_int (Integers.Int.repr 14) tint)
                                (tptr (tptr tuchar))) (tptr tuchar))
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar _tags (tptr tuchar))
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 14) tuint)
                                tuchar) (tptr tuchar)))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                  (Expr.Econst_int (Integers.Int.repr 15) tint)
                                  (tptr (tptr tuchar))) (tptr tuchar))
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Etempvar _tags (tptr tuchar))
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 15) tuint)
                                  tuchar) (tptr tuchar)))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                    (Expr.Econst_int (Integers.Int.repr 16) tint)
                                    (tptr (tptr tuchar))) (tptr tuchar))
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Etempvar _tags (tptr tuchar))
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                    tuchar) (tptr tuchar)))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                      (Expr.Econst_int (Integers.Int.repr 17) tint)
                                      (tptr (tptr tuchar))) (tptr tuchar))
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Etempvar _tags (tptr tuchar))
                                    (Expr.Ecast
                                      (Expr.Econst_int (Integers.Int.repr 17) tuint)
                                      tuchar) (tptr tuchar)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_write_reg_2
                                  s_kprog_arm64_write_reg_7)))))))))))))))))

def s_kprog_arm64_write_reg_9 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
        (Expr.Econst_int (Integers.Int.repr 16) tint)
        (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
      (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
    (Expr.Ebinop Binop.Oadd
      (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 16) tuint) tuchar)
      (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
          (Expr.Econst_int (Integers.Int.repr 17) tint)
          (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
        (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
      (Expr.Ebinop Binop.Oadd
        (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 17) tuint) tuchar)
        (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
            (Expr.Econst_int (Integers.Int.repr 18) tint)
            (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
          (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
        (Expr.Ebinop Binop.Oadd
          (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 18) tuint) tuchar)
          (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
              (Expr.Econst_int (Integers.Int.repr 19) tint)
              (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
            (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
          (Expr.Ebinop Binop.Oadd
            (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 19) tuint)
              tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                (Expr.Econst_int (Integers.Int.repr 20) tint)
                (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
              (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
            (Expr.Ebinop Binop.Oadd
              (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 20) tuint)
                tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                  (Expr.Econst_int (Integers.Int.repr 21) tint)
                  (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
              (Expr.Ebinop Binop.Oadd
                (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 21) tuint)
                  tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                    (Expr.Econst_int (Integers.Int.repr 22) tint)
                    (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                  (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                (Expr.Ebinop Binop.Oadd
                  (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 22) tuint)
                    tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                      (Expr.Econst_int (Integers.Int.repr 23) tint)
                      (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                    (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                    (Expr.Ecast
                      (Expr.Econst_int (Integers.Int.repr 23) tuint) tuchar)
                    (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                        (Expr.Econst_int (Integers.Int.repr 24) tint)
                        (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                      (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 24) tuint)
                        tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                          (Expr.Econst_int (Integers.Int.repr 25) tint)
                          (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                        (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 25) tuint)
                          tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                            (Expr.Econst_int (Integers.Int.repr 26) tint)
                            (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                          (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 26) tuint)
                            tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                              (Expr.Econst_int (Integers.Int.repr 27) tint)
                              (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                            (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 27) tuint)
                              tuchar)
                            (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                (Expr.Econst_int (Integers.Int.repr 28) tint)
                                (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                              (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 28) tuint)
                                tuchar)
                              (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                  (Expr.Econst_int (Integers.Int.repr 29) tint)
                                  (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 29) tuint)
                                  tuchar)
                                (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                    (Expr.Econst_int (Integers.Int.repr 30) tint)
                                    (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                  (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                    tuchar)
                                  (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                      (Expr.Econst_int (Integers.Int.repr 0) tint)
                                      (tptr (tptr tuchar))) (tptr tuchar))
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Etempvar _tags (tptr tuchar))
                                    (Expr.Ecast
                                      (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                      tuchar) (tptr tuchar)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_write_reg_1
                                  s_kprog_arm64_write_reg_8)))))))))))))))))

def f_kprog_arm64_write_reg : Function := {
  fn_return := tvoid,
  fn_callconv := cc_default,
  fn_params := [(_coordinates,
                 (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))),
                (_registers, (tptr (Ty.Tunion _arm64_sim_gpr noattr))),
                (_tags, (tptr tuchar)),
                (_stack_bytes, (tptr (tvolatile tuchar))),
                (_stack_tags, (tptr tuchar)), (_capacity, tuint),
                (_bias, tlong), (_reg, tulong), (_value, tulong),
                (_width, tuchar)],
  fn_vars := [(___a64_cells,
               (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31)),
              (___a64_tag_cells, (tarray (tptr tuchar) 31)),
              (___a64_stack, (Ty.Tstruct __2844 noattr))],
  fn_temps := [(___a64_write_old_sp, tlong), (___a64_l_reg, tulong),
               (___a64_l_next, tulong), (___a64_write_base, tulong),
               (___a64_release_old, tlong), (___a64_release_new, tlong),
               (___a64_release_i, tuint), (___a64_release_off, tlong),
               (___a64_release_w, tuint), (___ti, tulong), (___ts, tuint),
               (___tp, (tptr (tvolatile tulong))), (___tv, tulong),
               (_t'10, tint), (_t'9, (tvolatile tulong)), (_t'8, tint),
               (_t'7, tulong), (_t'6, tint), (_t'5, tint), (_t'4, tint),
               (_t'3, tuint), (_t'2, tulong), (_t'1, tulong),
               (_t'15, tuchar),
               (_t'14, (tptr (Ty.Tunion _arm64_sim_gpr noattr))),
               (_t'13, (tptr (Ty.Tunion _arm64_sim_gpr noattr))),
               (_t'12, (tptr tuchar)), (_t'11, (tptr (tvolatile tuchar)))],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
        (Expr.Econst_int (Integers.Int.repr 0) tint)
        (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
      (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
    (Expr.Ebinop Binop.Oadd
      (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuchar)
      (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
          (Expr.Econst_int (Integers.Int.repr 1) tint)
          (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
        (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
      (Expr.Ebinop Binop.Oadd
        (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuchar)
        (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
            (Expr.Econst_int (Integers.Int.repr 2) tint)
            (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
          (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
        (Expr.Ebinop Binop.Oadd
          (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint) tuchar)
          (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
              (Expr.Econst_int (Integers.Int.repr 3) tint)
              (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
            (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
          (Expr.Ebinop Binop.Oadd
            (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuchar)
            (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                (Expr.Econst_int (Integers.Int.repr 4) tint)
                (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
              (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
            (Expr.Ebinop Binop.Oadd
              (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 4) tuint)
                tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                  (Expr.Econst_int (Integers.Int.repr 5) tint)
                  (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
              (Expr.Ebinop Binop.Oadd
                (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 5) tuint)
                  tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                    (Expr.Econst_int (Integers.Int.repr 6) tint)
                    (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                  (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                (Expr.Ebinop Binop.Oadd
                  (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 6) tuint)
                    tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                      (Expr.Econst_int (Integers.Int.repr 7) tint)
                      (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                    (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 7) tuint)
                      tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                        (Expr.Econst_int (Integers.Int.repr 8) tint)
                        (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                      (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 8) tuint) tuchar)
                      (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                          (Expr.Econst_int (Integers.Int.repr 9) tint)
                          (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                        (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 9) tuint)
                          tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                            (Expr.Econst_int (Integers.Int.repr 10) tint)
                            (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                          (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 10) tuint)
                            tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                              (Expr.Econst_int (Integers.Int.repr 11) tint)
                              (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                            (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 11) tuint)
                              tuchar)
                            (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                (Expr.Econst_int (Integers.Int.repr 12) tint)
                                (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                              (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 12) tuint)
                                tuchar)
                              (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                  (Expr.Econst_int (Integers.Int.repr 13) tint)
                                  (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 13) tuint)
                                  tuchar)
                                (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                    (Expr.Econst_int (Integers.Int.repr 14) tint)
                                    (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                  (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 14) tuint)
                                    tuchar)
                                  (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                              (Stmt.Ssequence
                                s_kprog_arm64_write_reg_0
                                s_kprog_arm64_write_reg_9))))))))))))))))
}

def s_kprog_arm64_write_ptr_0 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
      (Expr.Econst_int (Integers.Int.repr 15) tint)
      (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
    (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
  (Expr.Ebinop Binop.Oadd
    (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 15) tuint) tuchar)
    (tptr (Ty.Tunion _arm64_sim_gpr noattr))))

def s_kprog_arm64_write_ptr_1 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
      (Expr.Econst_int (Integers.Int.repr 1) tint) (tptr (tptr tuchar)))
    (tptr tuchar))
  (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuchar)
    (tptr tuchar)))

def s_kprog_arm64_write_ptr_2 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
      (Expr.Econst_int (Integers.Int.repr 18) tint) (tptr (tptr tuchar)))
    (tptr tuchar))
  (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 18) tuint) tuchar)
    (tptr tuchar)))

def s_kprog_arm64_write_ptr_3 : Stmt :=
(Stmt.Sset ___a64_l_next_ptr
  (Expr.Ecast (Expr.Etempvar _value (tptr tvoid)) (tptr tvoid)))

def s_kprog_arm64_write_ptr_4 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'16
    (Expr.Efield
      (Expr.Ederef
        (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
        (Ty.Tstruct _kprog_arm64_coordinates noattr)) _sp_valid tuchar))
  (Stmt.Sifthenelse (Expr.Eunop Unop.Onotbool (Expr.Etempvar _t'16 tuchar)
                      tint)
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Scall (some _t'1)
          (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                               cc_default))
          [(Expr.Econst_int (Integers.Int.repr 1) tint)])
        (Stmt.Sassign
          (Expr.Efield
            (Expr.Ederef
              (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
              (Ty.Tstruct _kprog_arm64_coordinates noattr)) _sp_base tulong)
          (Expr.Etempvar _t'1 tulong)))
      (Stmt.Sassign
        (Expr.Efield
          (Expr.Ederef
            (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
            (Ty.Tstruct _kprog_arm64_coordinates noattr)) _sp_valid tuchar)
        (Expr.Econst_int (Integers.Int.repr 1) tint)))
    Stmt.Sskip))

def s_kprog_arm64_write_ptr_5 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'15
      (Expr.Efield
        (Expr.Ederef
          (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
          (Ty.Tstruct _kprog_arm64_coordinates noattr)) _return_valid tuchar))
    (Stmt.Sifthenelse (Expr.Eunop Unop.Onotbool (Expr.Etempvar _t'15 tuchar)
                        tint)
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Scall (some _t'2)
            (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                 cc_default))
            [(Expr.Econst_int (Integers.Int.repr 3) tint)])
          (Stmt.Sassign
            (Expr.Efield
              (Expr.Ederef
                (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                (Ty.Tstruct _kprog_arm64_coordinates noattr)) _return_base
              tulong) (Expr.Etempvar _t'2 tulong)))
        (Stmt.Sassign
          (Expr.Efield
            (Expr.Ederef
              (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
              (Ty.Tstruct _kprog_arm64_coordinates noattr)) _return_valid
            tuchar) (Expr.Econst_int (Integers.Int.repr 1) tint)))
      Stmt.Sskip))
  (Stmt.Sset ___a64_mat_base__1
    (Expr.Efield
      (Expr.Ederef
        (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
        (Ty.Tstruct _kprog_arm64_coordinates noattr)) _return_base tulong)))

def s_kprog_arm64_write_ptr_6 : Stmt :=
Stmt.Sbreak

def s_kprog_arm64_write_ptr_7 : Stmt :=
(Stmt.Sset _t'8
  (Expr.Ecast
    (Expr.Ebinop Binop.Olt (Expr.Etempvar ___a64_release_off tlong)
      (Expr.Etempvar ___a64_release_new tlong) tint) tbool))

def s_kprog_arm64_write_ptr_8 : Stmt :=
(Stmt.Scall (some _t'7)
  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong cc_default))
  [(Expr.Econst_int (Integers.Int.repr 6) tint)])

def s_kprog_arm64_write_ptr_9 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'11
    (Expr.Efield (Expr.Evar ___a64_stack (Ty.Tstruct __2873 noattr)) _b
      (tptr (tvolatile tuchar))))
  (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
    [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
    [(Expr.Eaddrof
       (Expr.Ederef
         (Expr.Ebinop Binop.Oadd
           (Expr.Etempvar _t'11 (tptr (tvolatile tuchar)))
           (Expr.Etempvar ___a64_release_i tuint) (tptr (tvolatile tuchar)))
         (tvolatile tuchar)) (tptr (tvolatile tuchar))),
     (Expr.Ecast (Expr.Etempvar _t'7 tulong) tuchar)]))

def s_kprog_arm64_write_ptr_10 : Stmt :=
(Stmt.Sset ___ti (Expr.Ecast (Expr.Etempvar ___a64_release_w tuint) tulong))

def s_kprog_arm64_write_ptr_11 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___ts
    (Expr.Ecast
      (Expr.Ebinop Binop.Omul
        (Expr.Ebinop Binop.Oand (Expr.Etempvar ___ti tulong)
          (Expr.Econst_int (Integers.Int.repr 7) tuint) tulong)
        (Expr.Econst_int (Integers.Int.repr 8) tuint) tulong) tuint))
  (Stmt.Ssequence
    (Stmt.Sset ___tp
      (Expr.Ecast
        (Expr.Ecast
          (Expr.Ebinop Binop.Oadd (Expr.Etempvar _stack_tags (tptr tuchar))
            (Expr.Ebinop Binop.Oand
              (Expr.Ecast (Expr.Etempvar ___ti tulong) tulong)
              (Expr.Eunop Unop.Onotint
                (Expr.Econst_long (Integers.Int64.repr 7) tulong) tulong)
              tulong) (tptr tuchar)) (tptr tvoid)) (tptr (tvolatile tulong))))
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sbuiltin (some _t'9) (ExtFun.EF_vload Chunk.Mint64)
          [(tptr (tvolatile tulong))]
          [(Expr.Eaddrof
             (Expr.Ederef (Expr.Etempvar ___tp (tptr (tvolatile tulong)))
               (tvolatile tulong)) (tptr (tvolatile tulong)))])
        (Stmt.Sset ___tv (Expr.Etempvar _t'9 (tvolatile tulong))))
      (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
        [(tptr (tvolatile tulong)), (tvolatile tulong)]
        [(Expr.Eaddrof
           (Expr.Ederef (Expr.Etempvar ___tp (tptr (tvolatile tulong)))
             (tvolatile tulong)) (tptr (tvolatile tulong))),
         (Expr.Ebinop Binop.Oor
           (Expr.Ebinop Binop.Oand (Expr.Etempvar ___tv tulong)
             (Expr.Eunop Unop.Onotint
               (Expr.Ebinop Binop.Oshl
                 (Expr.Econst_long (Integers.Int64.repr 255) tulong)
                 (Expr.Etempvar ___ts tuint) tulong) tulong) tulong)
           (Expr.Ebinop Binop.Oshl
             (Expr.Ecast
               (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                 tuchar) tulong) (Expr.Etempvar ___ts tuint) tulong) tulong)]))))

def s_kprog_arm64_write_ptr_12 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___a64_l_next_tag
    (Expr.Ecast (Expr.Etempvar _tag tuchar) tuchar))
  (Stmt.Ssequence
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                        (Expr.Etempvar ___a64_l_reg tulong)
                        (Expr.Econst_int (Integers.Int.repr 32) tuint) tint)
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                          (Expr.Etempvar ___a64_l_next_tag tuchar)
                          (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
        (Stmt.Sassign
          (Expr.Efield
            (Expr.Ederef
              (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
              (Ty.Tstruct _kprog_arm64_coordinates noattr)) _stack_offset
            tlong)
          (Expr.Ecast
            (Expr.Ecast (Expr.Etempvar ___a64_l_next_ptr (tptr tvoid)) tlong)
            tlong))
        (Stmt.Ssequence
          (Stmt.Sloop
            (Stmt.Ssequence
              (Stmt.Sset ___a64_mat_value
                (Expr.Ecast
                  (Expr.Ecast (Expr.Etempvar ___a64_l_next_ptr (tptr tvoid))
                    tlong) tulong))
              (Stmt.Ssequence
                (Stmt.Sset ___a64_mat_tag
                  (Expr.Ecast (Expr.Etempvar ___a64_l_next_tag tuchar)
                    tuchar))
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar ___a64_mat_tag tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Sloop
                        (Stmt.Ssequence
                          s_kprog_arm64_write_ptr_4
                          (Stmt.Sset ___a64_mat_base
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                                (Ty.Tstruct _kprog_arm64_coordinates noattr))
                              _sp_base tulong)))
                        Stmt.Sbreak)
                      (Stmt.Sset ___a64_mat_value
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Etempvar ___a64_mat_value tulong)
                          (Expr.Etempvar ___a64_mat_base tulong) tulong)))
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Etempvar ___a64_mat_tag tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 10) tuint)
                                        tint)
                      (Stmt.Ssequence
                        (Stmt.Sloop
                          s_kprog_arm64_write_ptr_5
                          s_kprog_arm64_write_ptr_6)
                        (Stmt.Sset ___a64_mat_value
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar ___a64_mat_value tulong)
                            (Expr.Etempvar ___a64_mat_base__1 tulong) tulong)))
                      Stmt.Sskip))
                  (Stmt.Sset ___a64_write_value
                    (Expr.Etempvar ___a64_mat_value tulong)))))
            Stmt.Sbreak)
          (Stmt.Ssequence
            (Stmt.Sloop
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sset _t'14
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                        (Ty.Tstruct _kprog_arm64_coordinates noattr))
                      _sp_valid tuchar))
                  (Stmt.Sifthenelse (Expr.Eunop Unop.Onotbool
                                      (Expr.Etempvar _t'14 tuchar) tint)
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Scall (some _t'3)
                          (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                               [tuint] tulong
                                                               cc_default))
                          [(Expr.Econst_int (Integers.Int.repr 1) tint)])
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                              (Ty.Tstruct _kprog_arm64_coordinates noattr))
                            _sp_base tulong) (Expr.Etempvar _t'3 tulong)))
                      (Stmt.Sassign
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                            (Ty.Tstruct _kprog_arm64_coordinates noattr))
                          _sp_valid tuchar)
                        (Expr.Econst_int (Integers.Int.repr 1) tint)))
                    Stmt.Sskip))
                (Stmt.Sset ___a64_write_base
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                      (Ty.Tstruct _kprog_arm64_coordinates noattr)) _sp_base
                    tulong)))
              Stmt.Sbreak)
            (Stmt.Sassign
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                  (Ty.Tstruct _kprog_arm64_coordinates noattr)) _stack_offset
                tlong)
              (Expr.Ecast
                (Expr.Ebinop Binop.Osub
                  (Expr.Etempvar ___a64_write_value tulong)
                  (Expr.Etempvar ___a64_write_base tulong) tulong) tlong)))))
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                            (Expr.Etempvar ___a64_l_reg tulong)
                            (Expr.Econst_int (Integers.Int.repr 31) tuint)
                            tint)
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.One
                                  (Expr.Etempvar ___a64_l_reg tulong)
                                  (Expr.Econst_int (Integers.Int.repr 31) tuint)
                                  tint)
                (Stmt.Sset _t'5
                  (Expr.Ecast
                    (Expr.Ebinop Binop.One
                      (Expr.Etempvar ___a64_l_reg tulong)
                      (Expr.Econst_int (Integers.Int.repr 255) tuint) tint)
                    tbool))
                (Stmt.Sset _t'5 (Expr.Econst_int (Integers.Int.repr 0) tint)))
              (Stmt.Sifthenelse (Expr.Etempvar _t'5 tint)
                (Stmt.Sset _t'6
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tint)
                    tint))
                (Stmt.Sset _t'6
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                    tint))))
            (Stmt.Sset _t'4
              (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'6 tint) tuchar)
                tbool)))
          (Stmt.Sset _t'4 (Expr.Econst_int (Integers.Int.repr 0) tint)))
        (Stmt.Sifthenelse (Expr.Etempvar _t'4 tint)
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sset _t'13
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                    (Expr.Ecast (Expr.Etempvar ___a64_l_reg tulong) tuchar)
                    (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                  (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Etempvar _t'13 (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                    (Ty.Tunion _arm64_sim_gpr noattr)) _ptr (tptr tvoid))
                (Expr.Etempvar ___a64_l_next_ptr (tptr tvoid))))
            (Stmt.Ssequence
              (Stmt.Sset _t'12
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                    (Expr.Ecast (Expr.Etempvar ___a64_l_reg tulong) tuchar)
                    (tptr (tptr tuchar))) (tptr tuchar)))
              (Stmt.Sassign
                (Expr.Ederef (Expr.Etempvar _t'12 (tptr tuchar)) tuchar)
                (Expr.Etempvar ___a64_l_next_tag tuchar))))
          Stmt.Sskip)))
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _reg tulong)
                        (Expr.Econst_int (Integers.Int.repr 32) tuint) tint)
      (Stmt.Sloop
        (Stmt.Ssequence
          (Stmt.Sset ___a64_release_old
            (Expr.Etempvar ___a64_write_old_sp tlong))
          (Stmt.Ssequence
            (Stmt.Sset ___a64_release_new
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                  (Ty.Tstruct _kprog_arm64_coordinates noattr)) _stack_offset
                tlong))
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Ogt
                                (Expr.Etempvar ___a64_release_new tlong)
                                (Expr.Etempvar ___a64_release_old tlong)
                                tint)
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sset ___a64_release_i
                    (Expr.Econst_int (Integers.Int.repr 0) tint))
                  (Stmt.Sloop
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                          (Expr.Etempvar ___a64_release_i tuint)
                                          (Expr.Etempvar _capacity tuint)
                                          tint)
                        Stmt.Sskip
                        Stmt.Sbreak)
                      (Stmt.Ssequence
                        (Stmt.Sset ___a64_release_off
                          (Expr.Ebinop Binop.Osub
                            (Expr.Ecast
                              (Expr.Etempvar ___a64_release_i tuint) tlong)
                            (Expr.Ecast (Expr.Etempvar _bias tlong) tlong)
                            tlong))
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                              (Expr.Etempvar ___a64_release_off tlong)
                                              (Expr.Etempvar ___a64_release_old tlong)
                                              tint)
                            s_kprog_arm64_write_ptr_7
                            (Stmt.Sset _t'8
                              (Expr.Econst_int (Integers.Int.repr 0) tint)))
                          (Stmt.Sifthenelse (Expr.Etempvar _t'8 tint)
                            (Stmt.Ssequence
                              s_kprog_arm64_write_ptr_8
                              s_kprog_arm64_write_ptr_9)
                            Stmt.Sskip))))
                    (Stmt.Sset ___a64_release_i
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar ___a64_release_i tuint)
                        (Expr.Econst_int (Integers.Int.repr 1) tint) tuint))))
                (Stmt.Ssequence
                  (Stmt.Sset ___a64_release_w
                    (Expr.Econst_int (Integers.Int.repr 0) tint))
                  (Stmt.Sloop
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                          (Expr.Etempvar ___a64_release_w tuint)
                                          (Expr.Ebinop Binop.Odiv
                                            (Expr.Ebinop Binop.Oadd
                                              (Expr.Ecast
                                                (Expr.Etempvar _capacity tuint)
                                                tuint)
                                              (Expr.Econst_int (Integers.Int.repr 7) tuint)
                                              tuint)
                                            (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                            tuint) tint)
                        Stmt.Sskip
                        Stmt.Sbreak)
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                            (Expr.Ebinop Binop.Osub
                                              (Expr.Ecast
                                                (Expr.Ebinop Binop.Omul
                                                  (Expr.Etempvar ___a64_release_w tuint)
                                                  (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                                  tuint) tlong)
                                              (Expr.Ecast
                                                (Expr.Etempvar _bias tlong)
                                                tlong) tlong)
                                            (Expr.Etempvar ___a64_release_new tlong)
                                            tint)
                          (Stmt.Sset _t'10
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Ogt
                                (Expr.Ebinop Binop.Osub
                                  (Expr.Ecast
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Ebinop Binop.Omul
                                        (Expr.Etempvar ___a64_release_w tuint)
                                        (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                        tuint)
                                      (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                      tuint) tlong)
                                  (Expr.Ecast (Expr.Etempvar _bias tlong)
                                    tlong) tlong)
                                (Expr.Etempvar ___a64_release_old tlong)
                                tint) tbool))
                          (Stmt.Sset _t'10
                            (Expr.Econst_int (Integers.Int.repr 0) tint)))
                        (Stmt.Sifthenelse (Expr.Etempvar _t'10 tint)
                          (Stmt.Sloop
                            (Stmt.Ssequence
                              s_kprog_arm64_write_ptr_10
                              s_kprog_arm64_write_ptr_11)
                            Stmt.Sbreak)
                          Stmt.Sskip)))
                    (Stmt.Sset ___a64_release_w
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar ___a64_release_w tuint)
                        (Expr.Econst_int (Integers.Int.repr 1) tint) tuint)))))
              Stmt.Sskip)))
        Stmt.Sbreak)
      Stmt.Sskip)))

def s_kprog_arm64_write_ptr_13 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
        (Expr.Econst_int (Integers.Int.repr 19) tint) (tptr (tptr tuchar)))
      (tptr tuchar))
    (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 19) tuint) tuchar)
      (tptr tuchar)))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
          (Expr.Econst_int (Integers.Int.repr 20) tint) (tptr (tptr tuchar)))
        (tptr tuchar))
      (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 20) tuint) tuchar)
        (tptr tuchar)))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
            (Expr.Econst_int (Integers.Int.repr 21) tint)
            (tptr (tptr tuchar))) (tptr tuchar))
        (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 21) tuint) tuchar)
          (tptr tuchar)))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
              (Expr.Econst_int (Integers.Int.repr 22) tint)
              (tptr (tptr tuchar))) (tptr tuchar))
          (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 22) tuint)
              tuchar) (tptr tuchar)))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                (Expr.Econst_int (Integers.Int.repr 23) tint)
                (tptr (tptr tuchar))) (tptr tuchar))
            (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 23) tuint)
                tuchar) (tptr tuchar)))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                  (Expr.Econst_int (Integers.Int.repr 24) tint)
                  (tptr (tptr tuchar))) (tptr tuchar))
              (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 24) tuint)
                  tuchar) (tptr tuchar)))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                    (Expr.Econst_int (Integers.Int.repr 25) tint)
                    (tptr (tptr tuchar))) (tptr tuchar))
                (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 25) tuint)
                    tuchar) (tptr tuchar)))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                      (Expr.Econst_int (Integers.Int.repr 26) tint)
                      (tptr (tptr tuchar))) (tptr tuchar))
                  (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
                    (Expr.Ecast
                      (Expr.Econst_int (Integers.Int.repr 26) tuint) tuchar)
                    (tptr tuchar)))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                        (Expr.Econst_int (Integers.Int.repr 27) tint)
                        (tptr (tptr tuchar))) (tptr tuchar))
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Etempvar _tags (tptr tuchar))
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 27) tuint)
                        tuchar) (tptr tuchar)))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                          (Expr.Econst_int (Integers.Int.repr 28) tint)
                          (tptr (tptr tuchar))) (tptr tuchar))
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar _tags (tptr tuchar))
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 28) tuint)
                          tuchar) (tptr tuchar)))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                            (Expr.Econst_int (Integers.Int.repr 29) tint)
                            (tptr (tptr tuchar))) (tptr tuchar))
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Etempvar _tags (tptr tuchar))
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 29) tuint)
                            tuchar) (tptr tuchar)))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                              (Expr.Econst_int (Integers.Int.repr 30) tint)
                              (tptr (tptr tuchar))) (tptr tuchar))
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar _tags (tptr tuchar))
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 30) tuint)
                              tuchar) (tptr tuchar)))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Evar ___a64_stack (Ty.Tstruct __2873 noattr))
                              _b (tptr (tvolatile tuchar)))
                            (Expr.Etempvar _stack_bytes (tptr (tvolatile tuchar))))
                          (Stmt.Sloop
                            (Stmt.Ssequence
                              (Stmt.Sset ___a64_write_old_sp
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                                    (Ty.Tstruct _kprog_arm64_coordinates noattr))
                                  _stack_offset tlong))
                              (Stmt.Ssequence
                                (Stmt.Sset ___a64_l_reg
                                  (Expr.Etempvar _reg tulong))
                                (Stmt.Ssequence
                                  s_kprog_arm64_write_ptr_3
                                  s_kprog_arm64_write_ptr_12)))
                            Stmt.Sbreak))))))))))))))

def s_kprog_arm64_write_ptr_14 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
        (Expr.Econst_int (Integers.Int.repr 2) tint) (tptr (tptr tuchar)))
      (tptr tuchar))
    (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint) tuchar)
      (tptr tuchar)))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
          (Expr.Econst_int (Integers.Int.repr 3) tint) (tptr (tptr tuchar)))
        (tptr tuchar))
      (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuchar)
        (tptr tuchar)))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
            (Expr.Econst_int (Integers.Int.repr 4) tint)
            (tptr (tptr tuchar))) (tptr tuchar))
        (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 4) tuint) tuchar)
          (tptr tuchar)))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
              (Expr.Econst_int (Integers.Int.repr 5) tint)
              (tptr (tptr tuchar))) (tptr tuchar))
          (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 5) tuint) tuchar)
            (tptr tuchar)))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                (Expr.Econst_int (Integers.Int.repr 6) tint)
                (tptr (tptr tuchar))) (tptr tuchar))
            (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 6) tuint)
                tuchar) (tptr tuchar)))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                  (Expr.Econst_int (Integers.Int.repr 7) tint)
                  (tptr (tptr tuchar))) (tptr tuchar))
              (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 7) tuint)
                  tuchar) (tptr tuchar)))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                    (Expr.Econst_int (Integers.Int.repr 8) tint)
                    (tptr (tptr tuchar))) (tptr tuchar))
                (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tuint)
                    tuchar) (tptr tuchar)))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                      (Expr.Econst_int (Integers.Int.repr 9) tint)
                      (tptr (tptr tuchar))) (tptr tuchar))
                  (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 9) tuint)
                      tuchar) (tptr tuchar)))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                        (Expr.Econst_int (Integers.Int.repr 10) tint)
                        (tptr (tptr tuchar))) (tptr tuchar))
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Etempvar _tags (tptr tuchar))
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 10) tuint)
                        tuchar) (tptr tuchar)))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                          (Expr.Econst_int (Integers.Int.repr 11) tint)
                          (tptr (tptr tuchar))) (tptr tuchar))
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar _tags (tptr tuchar))
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 11) tuint)
                          tuchar) (tptr tuchar)))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                            (Expr.Econst_int (Integers.Int.repr 12) tint)
                            (tptr (tptr tuchar))) (tptr tuchar))
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Etempvar _tags (tptr tuchar))
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 12) tuint)
                            tuchar) (tptr tuchar)))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                              (Expr.Econst_int (Integers.Int.repr 13) tint)
                              (tptr (tptr tuchar))) (tptr tuchar))
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar _tags (tptr tuchar))
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 13) tuint)
                              tuchar) (tptr tuchar)))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                (Expr.Econst_int (Integers.Int.repr 14) tint)
                                (tptr (tptr tuchar))) (tptr tuchar))
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar _tags (tptr tuchar))
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 14) tuint)
                                tuchar) (tptr tuchar)))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                  (Expr.Econst_int (Integers.Int.repr 15) tint)
                                  (tptr (tptr tuchar))) (tptr tuchar))
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Etempvar _tags (tptr tuchar))
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 15) tuint)
                                  tuchar) (tptr tuchar)))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                    (Expr.Econst_int (Integers.Int.repr 16) tint)
                                    (tptr (tptr tuchar))) (tptr tuchar))
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Etempvar _tags (tptr tuchar))
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                    tuchar) (tptr tuchar)))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                      (Expr.Econst_int (Integers.Int.repr 17) tint)
                                      (tptr (tptr tuchar))) (tptr tuchar))
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Etempvar _tags (tptr tuchar))
                                    (Expr.Ecast
                                      (Expr.Econst_int (Integers.Int.repr 17) tuint)
                                      tuchar) (tptr tuchar)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_write_ptr_2
                                  s_kprog_arm64_write_ptr_13)))))))))))))))))

def s_kprog_arm64_write_ptr_15 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
        (Expr.Econst_int (Integers.Int.repr 16) tint)
        (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
      (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
    (Expr.Ebinop Binop.Oadd
      (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 16) tuint) tuchar)
      (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
          (Expr.Econst_int (Integers.Int.repr 17) tint)
          (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
        (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
      (Expr.Ebinop Binop.Oadd
        (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 17) tuint) tuchar)
        (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
            (Expr.Econst_int (Integers.Int.repr 18) tint)
            (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
          (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
        (Expr.Ebinop Binop.Oadd
          (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 18) tuint) tuchar)
          (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
              (Expr.Econst_int (Integers.Int.repr 19) tint)
              (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
            (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
          (Expr.Ebinop Binop.Oadd
            (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 19) tuint)
              tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                (Expr.Econst_int (Integers.Int.repr 20) tint)
                (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
              (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
            (Expr.Ebinop Binop.Oadd
              (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 20) tuint)
                tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                  (Expr.Econst_int (Integers.Int.repr 21) tint)
                  (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
              (Expr.Ebinop Binop.Oadd
                (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 21) tuint)
                  tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                    (Expr.Econst_int (Integers.Int.repr 22) tint)
                    (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                  (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                (Expr.Ebinop Binop.Oadd
                  (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 22) tuint)
                    tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                      (Expr.Econst_int (Integers.Int.repr 23) tint)
                      (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                    (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                    (Expr.Ecast
                      (Expr.Econst_int (Integers.Int.repr 23) tuint) tuchar)
                    (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                        (Expr.Econst_int (Integers.Int.repr 24) tint)
                        (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                      (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 24) tuint)
                        tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                          (Expr.Econst_int (Integers.Int.repr 25) tint)
                          (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                        (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 25) tuint)
                          tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                            (Expr.Econst_int (Integers.Int.repr 26) tint)
                            (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                          (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 26) tuint)
                            tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                              (Expr.Econst_int (Integers.Int.repr 27) tint)
                              (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                            (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 27) tuint)
                              tuchar)
                            (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                (Expr.Econst_int (Integers.Int.repr 28) tint)
                                (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                              (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 28) tuint)
                                tuchar)
                              (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                  (Expr.Econst_int (Integers.Int.repr 29) tint)
                                  (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 29) tuint)
                                  tuchar)
                                (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                    (Expr.Econst_int (Integers.Int.repr 30) tint)
                                    (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                  (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                    tuchar)
                                  (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                      (Expr.Econst_int (Integers.Int.repr 0) tint)
                                      (tptr (tptr tuchar))) (tptr tuchar))
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Etempvar _tags (tptr tuchar))
                                    (Expr.Ecast
                                      (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                      tuchar) (tptr tuchar)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_write_ptr_1
                                  s_kprog_arm64_write_ptr_14)))))))))))))))))

def f_kprog_arm64_write_ptr : Function := {
  fn_return := tvoid,
  fn_callconv := cc_default,
  fn_params := [(_coordinates,
                 (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))),
                (_registers, (tptr (Ty.Tunion _arm64_sim_gpr noattr))),
                (_tags, (tptr tuchar)),
                (_stack_bytes, (tptr (tvolatile tuchar))),
                (_stack_tags, (tptr tuchar)), (_capacity, tuint),
                (_bias, tlong), (_reg, tulong), (_value, (tptr tvoid)),
                (_tag, tuchar)],
  fn_vars := [(___a64_cells,
               (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31)),
              (___a64_tag_cells, (tarray (tptr tuchar) 31)),
              (___a64_stack, (Ty.Tstruct __2873 noattr))],
  fn_temps := [(___a64_write_old_sp, tlong), (___a64_l_reg, tulong),
               (___a64_l_next_ptr, (tptr tvoid)),
               (___a64_l_next_tag, tuchar), (___a64_write_value, tulong),
               (___a64_write_base, tulong), (___a64_mat_value, tulong),
               (___a64_mat_tag, tuchar), (___a64_mat_base, tulong),
               (___a64_mat_base__1, tulong), (___a64_release_old, tlong),
               (___a64_release_new, tlong), (___a64_release_i, tuint),
               (___a64_release_off, tlong), (___a64_release_w, tuint),
               (___ti, tulong), (___ts, tuint),
               (___tp, (tptr (tvolatile tulong))), (___tv, tulong),
               (_t'10, tint), (_t'9, (tvolatile tulong)), (_t'8, tint),
               (_t'7, tulong), (_t'6, tint), (_t'5, tint), (_t'4, tint),
               (_t'3, tulong), (_t'2, tulong), (_t'1, tulong),
               (_t'16, tuchar), (_t'15, tuchar), (_t'14, tuchar),
               (_t'13, (tptr (Ty.Tunion _arm64_sim_gpr noattr))),
               (_t'12, (tptr tuchar)), (_t'11, (tptr (tvolatile tuchar)))],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
        (Expr.Econst_int (Integers.Int.repr 0) tint)
        (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
      (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
    (Expr.Ebinop Binop.Oadd
      (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuchar)
      (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
          (Expr.Econst_int (Integers.Int.repr 1) tint)
          (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
        (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
      (Expr.Ebinop Binop.Oadd
        (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuchar)
        (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
            (Expr.Econst_int (Integers.Int.repr 2) tint)
            (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
          (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
        (Expr.Ebinop Binop.Oadd
          (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint) tuchar)
          (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
              (Expr.Econst_int (Integers.Int.repr 3) tint)
              (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
            (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
          (Expr.Ebinop Binop.Oadd
            (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuchar)
            (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                (Expr.Econst_int (Integers.Int.repr 4) tint)
                (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
              (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
            (Expr.Ebinop Binop.Oadd
              (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 4) tuint)
                tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                  (Expr.Econst_int (Integers.Int.repr 5) tint)
                  (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
              (Expr.Ebinop Binop.Oadd
                (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 5) tuint)
                  tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                    (Expr.Econst_int (Integers.Int.repr 6) tint)
                    (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                  (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                (Expr.Ebinop Binop.Oadd
                  (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 6) tuint)
                    tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                      (Expr.Econst_int (Integers.Int.repr 7) tint)
                      (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                    (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 7) tuint)
                      tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                        (Expr.Econst_int (Integers.Int.repr 8) tint)
                        (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                      (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 8) tuint) tuchar)
                      (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                          (Expr.Econst_int (Integers.Int.repr 9) tint)
                          (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                        (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 9) tuint)
                          tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                            (Expr.Econst_int (Integers.Int.repr 10) tint)
                            (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                          (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 10) tuint)
                            tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                              (Expr.Econst_int (Integers.Int.repr 11) tint)
                              (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                            (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 11) tuint)
                              tuchar)
                            (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                (Expr.Econst_int (Integers.Int.repr 12) tint)
                                (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                              (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 12) tuint)
                                tuchar)
                              (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                  (Expr.Econst_int (Integers.Int.repr 13) tint)
                                  (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 13) tuint)
                                  tuchar)
                                (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                    (Expr.Econst_int (Integers.Int.repr 14) tint)
                                    (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                  (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 14) tuint)
                                    tuchar)
                                  (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                              (Stmt.Ssequence
                                s_kprog_arm64_write_ptr_0
                                s_kprog_arm64_write_ptr_15))))))))))))))))
}

def s_kprog_arm64_exec_adrp_0 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
      (Expr.Econst_int (Integers.Int.repr 15) tint)
      (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
    (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
  (Expr.Ebinop Binop.Oadd
    (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 15) tuint) tuchar)
    (tptr (Ty.Tunion _arm64_sim_gpr noattr))))

def s_kprog_arm64_exec_adrp_1 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
      (Expr.Econst_int (Integers.Int.repr 1) tint) (tptr (tptr tuchar)))
    (tptr tuchar))
  (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuchar)
    (tptr tuchar)))

def s_kprog_arm64_exec_adrp_2 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
      (Expr.Econst_int (Integers.Int.repr 18) tint) (tptr (tptr tuchar)))
    (tptr tuchar))
  (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 18) tuint) tuchar)
    (tptr tuchar)))

def s_kprog_arm64_exec_adrp_3 : Stmt :=
(Stmt.Sset ___kprog_a64_adrp_op
  (Expr.Ecast (Expr.Etempvar _op tulong) tuchar))

def s_kprog_arm64_exec_adrp_4 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___kprog_a64_adrp_tag
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) tuchar))
  (Stmt.Ssequence
    (Stmt.Sswitch (Expr.Etempvar ___kprog_a64_adrp_op tuchar)
      (LStmts.LScons (some 38)
        (Stmt.Ssequence
          (Stmt.Sset ___kprog_a64_adrp_tag
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 7) tuint) tuchar))
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
                  (Expr.Evar _arm64_sim_unsupported_opcode (Ty.Tfunction []
                                                             tvoid
                                                             cc_default)) [])
                Stmt.Sbreak)
              Stmt.Sbreak)
            LStmts.LSnil))))
    (Stmt.Sset ___a64_adrp_tag
      (Expr.Ecast (Expr.Etempvar ___kprog_a64_adrp_tag tuchar) tuchar))))

def s_kprog_arm64_exec_adrp_5 : Stmt :=
(Stmt.Sset ___a64_write_old_sp
  (Expr.Efield
    (Expr.Ederef
      (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
      (Ty.Tstruct _kprog_arm64_coordinates noattr)) _stack_offset tlong))

def s_kprog_arm64_exec_adrp_6 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'16
      (Expr.Efield
        (Expr.Ederef
          (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
          (Ty.Tstruct _kprog_arm64_coordinates noattr)) _sp_valid tuchar))
    (Stmt.Sifthenelse (Expr.Eunop Unop.Onotbool (Expr.Etempvar _t'16 tuchar)
                        tint)
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Scall (some _t'1)
            (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                 cc_default))
            [(Expr.Econst_int (Integers.Int.repr 1) tint)])
          (Stmt.Sassign
            (Expr.Efield
              (Expr.Ederef
                (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                (Ty.Tstruct _kprog_arm64_coordinates noattr)) _sp_base
              tulong) (Expr.Etempvar _t'1 tulong)))
        (Stmt.Sassign
          (Expr.Efield
            (Expr.Ederef
              (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
              (Ty.Tstruct _kprog_arm64_coordinates noattr)) _sp_valid tuchar)
          (Expr.Econst_int (Integers.Int.repr 1) tint)))
      Stmt.Sskip))
  (Stmt.Sset ___a64_mat_base
    (Expr.Efield
      (Expr.Ederef
        (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
        (Ty.Tstruct _kprog_arm64_coordinates noattr)) _sp_base tulong)))

def s_kprog_arm64_exec_adrp_7 : Stmt :=
Stmt.Sbreak

def s_kprog_arm64_exec_adrp_8 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sset _t'15
          (Expr.Efield
            (Expr.Ederef
              (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
              (Ty.Tstruct _kprog_arm64_coordinates noattr)) _return_valid
            tuchar))
        (Stmt.Sifthenelse (Expr.Eunop Unop.Onotbool
                            (Expr.Etempvar _t'15 tuchar) tint)
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Scall (some _t'2)
                (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                     tulong cc_default))
                [(Expr.Econst_int (Integers.Int.repr 3) tint)])
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                    (Ty.Tstruct _kprog_arm64_coordinates noattr))
                  _return_base tulong) (Expr.Etempvar _t'2 tulong)))
            (Stmt.Sassign
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                  (Ty.Tstruct _kprog_arm64_coordinates noattr)) _return_valid
                tuchar) (Expr.Econst_int (Integers.Int.repr 1) tint)))
          Stmt.Sskip))
      (Stmt.Sset ___a64_mat_base__1
        (Expr.Efield
          (Expr.Ederef
            (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
            (Ty.Tstruct _kprog_arm64_coordinates noattr)) _return_base
          tulong)))
    Stmt.Sbreak)
  (Stmt.Sset ___a64_mat_value
    (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___a64_mat_value tulong)
      (Expr.Etempvar ___a64_mat_base__1 tulong) tulong)))

def s_kprog_arm64_exec_adrp_9 : Stmt :=
(Stmt.Scall (some _t'3)
  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong cc_default))
  [(Expr.Econst_int (Integers.Int.repr 1) tint)])

def s_kprog_arm64_exec_adrp_10 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                    (Expr.Etempvar ___a64_release_off tlong)
                    (Expr.Etempvar ___a64_release_old tlong) tint)
  (Stmt.Sset _t'8
    (Expr.Ecast
      (Expr.Ebinop Binop.Olt (Expr.Etempvar ___a64_release_off tlong)
        (Expr.Etempvar ___a64_release_new tlong) tint) tbool))
  (Stmt.Sset _t'8 (Expr.Econst_int (Integers.Int.repr 0) tint)))

def s_kprog_arm64_exec_adrp_11 : Stmt :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'7)
    (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                         cc_default))
    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
  (Stmt.Ssequence
    (Stmt.Sset _t'11
      (Expr.Efield (Expr.Evar ___a64_stack (Ty.Tstruct __2908 noattr)) _b
        (tptr (tvolatile tuchar))))
    (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
      [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
      [(Expr.Eaddrof
         (Expr.Ederef
           (Expr.Ebinop Binop.Oadd
             (Expr.Etempvar _t'11 (tptr (tvolatile tuchar)))
             (Expr.Etempvar ___a64_release_i tuint)
             (tptr (tvolatile tuchar))) (tvolatile tuchar))
         (tptr (tvolatile tuchar))),
       (Expr.Ecast (Expr.Etempvar _t'7 tulong) tuchar)])))

def s_kprog_arm64_exec_adrp_12 : Stmt :=
(Stmt.Sset _t'10
  (Expr.Ecast
    (Expr.Ebinop Binop.Ogt
      (Expr.Ebinop Binop.Osub
        (Expr.Ecast
          (Expr.Ebinop Binop.Oadd
            (Expr.Ebinop Binop.Omul (Expr.Etempvar ___a64_release_w tuint)
              (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint)
            (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint) tlong)
        (Expr.Ecast (Expr.Etempvar _bias tlong) tlong) tlong)
      (Expr.Etempvar ___a64_release_old tlong) tint) tbool))

def s_kprog_arm64_exec_adrp_13 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___ti
    (Expr.Ecast (Expr.Etempvar ___a64_release_w tuint) tulong))
  (Stmt.Ssequence
    (Stmt.Sset ___ts
      (Expr.Ecast
        (Expr.Ebinop Binop.Omul
          (Expr.Ebinop Binop.Oand (Expr.Etempvar ___ti tulong)
            (Expr.Econst_int (Integers.Int.repr 7) tuint) tulong)
          (Expr.Econst_int (Integers.Int.repr 8) tuint) tulong) tuint))
    (Stmt.Ssequence
      (Stmt.Sset ___tp
        (Expr.Ecast
          (Expr.Ecast
            (Expr.Ebinop Binop.Oadd (Expr.Etempvar _stack_tags (tptr tuchar))
              (Expr.Ebinop Binop.Oand
                (Expr.Ecast (Expr.Etempvar ___ti tulong) tulong)
                (Expr.Eunop Unop.Onotint
                  (Expr.Econst_long (Integers.Int64.repr 7) tulong) tulong)
                tulong) (tptr tuchar)) (tptr tvoid))
          (tptr (tvolatile tulong))))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sbuiltin (some _t'9) (ExtFun.EF_vload Chunk.Mint64)
            [(tptr (tvolatile tulong))]
            [(Expr.Eaddrof
               (Expr.Ederef (Expr.Etempvar ___tp (tptr (tvolatile tulong)))
                 (tvolatile tulong)) (tptr (tvolatile tulong)))])
          (Stmt.Sset ___tv (Expr.Etempvar _t'9 (tvolatile tulong))))
        (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
          [(tptr (tvolatile tulong)), (tvolatile tulong)]
          [(Expr.Eaddrof
             (Expr.Ederef (Expr.Etempvar ___tp (tptr (tvolatile tulong)))
               (tvolatile tulong)) (tptr (tvolatile tulong))),
           (Expr.Ebinop Binop.Oor
             (Expr.Ebinop Binop.Oand (Expr.Etempvar ___tv tulong)
               (Expr.Eunop Unop.Onotint
                 (Expr.Ebinop Binop.Oshl
                   (Expr.Econst_long (Integers.Int64.repr 255) tulong)
                   (Expr.Etempvar ___ts tuint) tulong) tulong) tulong)
             (Expr.Ebinop Binop.Oshl
               (Expr.Ecast
                 (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                   tuchar) tulong) (Expr.Etempvar ___ts tuint) tulong)
             tulong)])))))

def s_kprog_arm64_exec_adrp_14 : Stmt :=
Stmt.Sbreak

def s_kprog_arm64_exec_adrp_15 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___a64_l_reg (Expr.Etempvar _dst tulong))
  (Stmt.Ssequence
    (Stmt.Sset ___a64_l_next_ptr
      (Expr.Ecast
        (Expr.Ecast (Expr.Ecast (Expr.Etempvar _imm tulong) tlong)
          (tptr tvoid)) (tptr tvoid)))
    (Stmt.Ssequence
      (Stmt.Sset ___a64_l_next_tag
        (Expr.Ecast (Expr.Etempvar ___a64_adrp_tag tuchar) tuchar))
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar ___a64_l_reg tulong)
                            (Expr.Econst_int (Integers.Int.repr 32) tuint)
                            tint)
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar ___a64_l_next_tag tuchar)
                              (Expr.Econst_int (Integers.Int.repr 4) tuint)
                              tint)
            (Stmt.Sassign
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                  (Ty.Tstruct _kprog_arm64_coordinates noattr)) _stack_offset
                tlong)
              (Expr.Ecast
                (Expr.Ecast (Expr.Etempvar ___a64_l_next_ptr (tptr tvoid))
                  tlong) tlong))
            (Stmt.Ssequence
              (Stmt.Sloop
                (Stmt.Ssequence
                  (Stmt.Sset ___a64_mat_value
                    (Expr.Ecast
                      (Expr.Ecast
                        (Expr.Etempvar ___a64_l_next_ptr (tptr tvoid)) tlong)
                      tulong))
                  (Stmt.Ssequence
                    (Stmt.Sset ___a64_mat_tag
                      (Expr.Ecast (Expr.Etempvar ___a64_l_next_tag tuchar)
                        tuchar))
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Etempvar ___a64_mat_tag tuchar)
                                          (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                          tint)
                        (Stmt.Ssequence
                          (Stmt.Sloop
                            s_kprog_arm64_exec_adrp_6
                            s_kprog_arm64_exec_adrp_7)
                          (Stmt.Sset ___a64_mat_value
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar ___a64_mat_value tulong)
                              (Expr.Etempvar ___a64_mat_base tulong) tulong)))
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Etempvar ___a64_mat_tag tuchar)
                                            (Expr.Econst_int (Integers.Int.repr 10) tuint)
                                            tint)
                          s_kprog_arm64_exec_adrp_8
                          Stmt.Sskip))
                      (Stmt.Sset ___a64_write_value
                        (Expr.Etempvar ___a64_mat_value tulong)))))
                Stmt.Sbreak)
              (Stmt.Ssequence
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sset _t'14
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                            (Ty.Tstruct _kprog_arm64_coordinates noattr))
                          _sp_valid tuchar))
                      (Stmt.Sifthenelse (Expr.Eunop Unop.Onotbool
                                          (Expr.Etempvar _t'14 tuchar) tint)
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            s_kprog_arm64_exec_adrp_9
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                                  (Ty.Tstruct _kprog_arm64_coordinates noattr))
                                _sp_base tulong) (Expr.Etempvar _t'3 tulong)))
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                                (Ty.Tstruct _kprog_arm64_coordinates noattr))
                              _sp_valid tuchar)
                            (Expr.Econst_int (Integers.Int.repr 1) tint)))
                        Stmt.Sskip))
                    (Stmt.Sset ___a64_write_base
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                          (Ty.Tstruct _kprog_arm64_coordinates noattr))
                        _sp_base tulong)))
                  Stmt.Sbreak)
                (Stmt.Sassign
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                      (Ty.Tstruct _kprog_arm64_coordinates noattr))
                    _stack_offset tlong)
                  (Expr.Ecast
                    (Expr.Ebinop Binop.Osub
                      (Expr.Etempvar ___a64_write_value tulong)
                      (Expr.Etempvar ___a64_write_base tulong) tulong) tlong)))))
          (Stmt.Ssequence
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                (Expr.Etempvar ___a64_l_reg tulong)
                                (Expr.Econst_int (Integers.Int.repr 31) tuint)
                                tint)
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.One
                                      (Expr.Etempvar ___a64_l_reg tulong)
                                      (Expr.Econst_int (Integers.Int.repr 31) tuint)
                                      tint)
                    (Stmt.Sset _t'5
                      (Expr.Ecast
                        (Expr.Ebinop Binop.One
                          (Expr.Etempvar ___a64_l_reg tulong)
                          (Expr.Econst_int (Integers.Int.repr 255) tuint)
                          tint) tbool))
                    (Stmt.Sset _t'5
                      (Expr.Econst_int (Integers.Int.repr 0) tint)))
                  (Stmt.Sifthenelse (Expr.Etempvar _t'5 tint)
                    (Stmt.Sset _t'6
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 1) tint) tint))
                    (Stmt.Sset _t'6
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 0) tint) tint))))
                (Stmt.Sset _t'4
                  (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'6 tint) tuchar)
                    tbool)))
              (Stmt.Sset _t'4 (Expr.Econst_int (Integers.Int.repr 0) tint)))
            (Stmt.Sifthenelse (Expr.Etempvar _t'4 tint)
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sset _t'13
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                        (Expr.Ecast (Expr.Etempvar ___a64_l_reg tulong)
                          tuchar)
                        (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                      (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                  (Stmt.Sassign
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar _t'13 (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                        (Ty.Tunion _arm64_sim_gpr noattr)) _ptr (tptr tvoid))
                    (Expr.Etempvar ___a64_l_next_ptr (tptr tvoid))))
                (Stmt.Ssequence
                  (Stmt.Sset _t'12
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                        (Expr.Ecast (Expr.Etempvar ___a64_l_reg tulong)
                          tuchar) (tptr (tptr tuchar))) (tptr tuchar)))
                  (Stmt.Sassign
                    (Expr.Ederef (Expr.Etempvar _t'12 (tptr tuchar)) tuchar)
                    (Expr.Etempvar ___a64_l_next_tag tuchar))))
              Stmt.Sskip)))
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _dst tulong)
                            (Expr.Econst_int (Integers.Int.repr 32) tuint)
                            tint)
          (Stmt.Sloop
            (Stmt.Ssequence
              (Stmt.Sset ___a64_release_old
                (Expr.Etempvar ___a64_write_old_sp tlong))
              (Stmt.Ssequence
                (Stmt.Sset ___a64_release_new
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Etempvar _coordinates (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                      (Ty.Tstruct _kprog_arm64_coordinates noattr))
                    _stack_offset tlong))
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Ogt
                                    (Expr.Etempvar ___a64_release_new tlong)
                                    (Expr.Etempvar ___a64_release_old tlong)
                                    tint)
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sset ___a64_release_i
                        (Expr.Econst_int (Integers.Int.repr 0) tint))
                      (Stmt.Sloop
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                              (Expr.Etempvar ___a64_release_i tuint)
                                              (Expr.Etempvar _capacity tuint)
                                              tint)
                            Stmt.Sskip
                            Stmt.Sbreak)
                          (Stmt.Ssequence
                            (Stmt.Sset ___a64_release_off
                              (Expr.Ebinop Binop.Osub
                                (Expr.Ecast
                                  (Expr.Etempvar ___a64_release_i tuint)
                                  tlong)
                                (Expr.Ecast (Expr.Etempvar _bias tlong)
                                  tlong) tlong))
                            (Stmt.Ssequence
                              s_kprog_arm64_exec_adrp_10
                              (Stmt.Sifthenelse (Expr.Etempvar _t'8 tint)
                                s_kprog_arm64_exec_adrp_11
                                Stmt.Sskip))))
                        (Stmt.Sset ___a64_release_i
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar ___a64_release_i tuint)
                            (Expr.Econst_int (Integers.Int.repr 1) tint)
                            tuint))))
                    (Stmt.Ssequence
                      (Stmt.Sset ___a64_release_w
                        (Expr.Econst_int (Integers.Int.repr 0) tint))
                      (Stmt.Sloop
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                              (Expr.Etempvar ___a64_release_w tuint)
                                              (Expr.Ebinop Binop.Odiv
                                                (Expr.Ebinop Binop.Oadd
                                                  (Expr.Ecast
                                                    (Expr.Etempvar _capacity tuint)
                                                    tuint)
                                                  (Expr.Econst_int (Integers.Int.repr 7) tuint)
                                                  tuint)
                                                (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                                tuint) tint)
                            Stmt.Sskip
                            Stmt.Sbreak)
                          (Stmt.Ssequence
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                                (Expr.Ebinop Binop.Osub
                                                  (Expr.Ecast
                                                    (Expr.Ebinop Binop.Omul
                                                      (Expr.Etempvar ___a64_release_w tuint)
                                                      (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                                      tuint) tlong)
                                                  (Expr.Ecast
                                                    (Expr.Etempvar _bias tlong)
                                                    tlong) tlong)
                                                (Expr.Etempvar ___a64_release_new tlong)
                                                tint)
                              s_kprog_arm64_exec_adrp_12
                              (Stmt.Sset _t'10
                                (Expr.Econst_int (Integers.Int.repr 0) tint)))
                            (Stmt.Sifthenelse (Expr.Etempvar _t'10 tint)
                              (Stmt.Sloop
                                s_kprog_arm64_exec_adrp_13
                                s_kprog_arm64_exec_adrp_14)
                              Stmt.Sskip)))
                        (Stmt.Sset ___a64_release_w
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar ___a64_release_w tuint)
                            (Expr.Econst_int (Integers.Int.repr 1) tint)
                            tuint)))))
                  Stmt.Sskip)))
            Stmt.Sbreak)
          Stmt.Sskip)))))

def s_kprog_arm64_exec_adrp_16 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
        (Expr.Econst_int (Integers.Int.repr 19) tint) (tptr (tptr tuchar)))
      (tptr tuchar))
    (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 19) tuint) tuchar)
      (tptr tuchar)))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
          (Expr.Econst_int (Integers.Int.repr 20) tint) (tptr (tptr tuchar)))
        (tptr tuchar))
      (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 20) tuint) tuchar)
        (tptr tuchar)))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
            (Expr.Econst_int (Integers.Int.repr 21) tint)
            (tptr (tptr tuchar))) (tptr tuchar))
        (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 21) tuint) tuchar)
          (tptr tuchar)))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
              (Expr.Econst_int (Integers.Int.repr 22) tint)
              (tptr (tptr tuchar))) (tptr tuchar))
          (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 22) tuint)
              tuchar) (tptr tuchar)))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                (Expr.Econst_int (Integers.Int.repr 23) tint)
                (tptr (tptr tuchar))) (tptr tuchar))
            (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 23) tuint)
                tuchar) (tptr tuchar)))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                  (Expr.Econst_int (Integers.Int.repr 24) tint)
                  (tptr (tptr tuchar))) (tptr tuchar))
              (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 24) tuint)
                  tuchar) (tptr tuchar)))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                    (Expr.Econst_int (Integers.Int.repr 25) tint)
                    (tptr (tptr tuchar))) (tptr tuchar))
                (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 25) tuint)
                    tuchar) (tptr tuchar)))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                      (Expr.Econst_int (Integers.Int.repr 26) tint)
                      (tptr (tptr tuchar))) (tptr tuchar))
                  (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
                    (Expr.Ecast
                      (Expr.Econst_int (Integers.Int.repr 26) tuint) tuchar)
                    (tptr tuchar)))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                        (Expr.Econst_int (Integers.Int.repr 27) tint)
                        (tptr (tptr tuchar))) (tptr tuchar))
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Etempvar _tags (tptr tuchar))
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 27) tuint)
                        tuchar) (tptr tuchar)))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                          (Expr.Econst_int (Integers.Int.repr 28) tint)
                          (tptr (tptr tuchar))) (tptr tuchar))
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar _tags (tptr tuchar))
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 28) tuint)
                          tuchar) (tptr tuchar)))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                            (Expr.Econst_int (Integers.Int.repr 29) tint)
                            (tptr (tptr tuchar))) (tptr tuchar))
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Etempvar _tags (tptr tuchar))
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 29) tuint)
                            tuchar) (tptr tuchar)))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                              (Expr.Econst_int (Integers.Int.repr 30) tint)
                              (tptr (tptr tuchar))) (tptr tuchar))
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar _tags (tptr tuchar))
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 30) tuint)
                              tuchar) (tptr tuchar)))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Evar ___a64_stack (Ty.Tstruct __2908 noattr))
                              _b (tptr (tvolatile tuchar)))
                            (Expr.Etempvar _stack_bytes (tptr (tvolatile tuchar))))
                          (Stmt.Sloop
                            (Stmt.Ssequence
                              (Stmt.Sloop
                                (Stmt.Ssequence
                                  s_kprog_arm64_exec_adrp_3
                                  s_kprog_arm64_exec_adrp_4)
                                Stmt.Sbreak)
                              (Stmt.Sloop
                                (Stmt.Ssequence
                                  s_kprog_arm64_exec_adrp_5
                                  s_kprog_arm64_exec_adrp_15)
                                Stmt.Sbreak))
                            Stmt.Sbreak))))))))))))))

def s_kprog_arm64_exec_adrp_17 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
        (Expr.Econst_int (Integers.Int.repr 2) tint) (tptr (tptr tuchar)))
      (tptr tuchar))
    (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint) tuchar)
      (tptr tuchar)))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
          (Expr.Econst_int (Integers.Int.repr 3) tint) (tptr (tptr tuchar)))
        (tptr tuchar))
      (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuchar)
        (tptr tuchar)))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
            (Expr.Econst_int (Integers.Int.repr 4) tint)
            (tptr (tptr tuchar))) (tptr tuchar))
        (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 4) tuint) tuchar)
          (tptr tuchar)))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
              (Expr.Econst_int (Integers.Int.repr 5) tint)
              (tptr (tptr tuchar))) (tptr tuchar))
          (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 5) tuint) tuchar)
            (tptr tuchar)))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                (Expr.Econst_int (Integers.Int.repr 6) tint)
                (tptr (tptr tuchar))) (tptr tuchar))
            (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 6) tuint)
                tuchar) (tptr tuchar)))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                  (Expr.Econst_int (Integers.Int.repr 7) tint)
                  (tptr (tptr tuchar))) (tptr tuchar))
              (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 7) tuint)
                  tuchar) (tptr tuchar)))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                    (Expr.Econst_int (Integers.Int.repr 8) tint)
                    (tptr (tptr tuchar))) (tptr tuchar))
                (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tuint)
                    tuchar) (tptr tuchar)))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                      (Expr.Econst_int (Integers.Int.repr 9) tint)
                      (tptr (tptr tuchar))) (tptr tuchar))
                  (Expr.Ebinop Binop.Oadd (Expr.Etempvar _tags (tptr tuchar))
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 9) tuint)
                      tuchar) (tptr tuchar)))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                        (Expr.Econst_int (Integers.Int.repr 10) tint)
                        (tptr (tptr tuchar))) (tptr tuchar))
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Etempvar _tags (tptr tuchar))
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 10) tuint)
                        tuchar) (tptr tuchar)))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                          (Expr.Econst_int (Integers.Int.repr 11) tint)
                          (tptr (tptr tuchar))) (tptr tuchar))
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar _tags (tptr tuchar))
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 11) tuint)
                          tuchar) (tptr tuchar)))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                            (Expr.Econst_int (Integers.Int.repr 12) tint)
                            (tptr (tptr tuchar))) (tptr tuchar))
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Etempvar _tags (tptr tuchar))
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 12) tuint)
                            tuchar) (tptr tuchar)))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                              (Expr.Econst_int (Integers.Int.repr 13) tint)
                              (tptr (tptr tuchar))) (tptr tuchar))
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar _tags (tptr tuchar))
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 13) tuint)
                              tuchar) (tptr tuchar)))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                (Expr.Econst_int (Integers.Int.repr 14) tint)
                                (tptr (tptr tuchar))) (tptr tuchar))
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar _tags (tptr tuchar))
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 14) tuint)
                                tuchar) (tptr tuchar)))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                  (Expr.Econst_int (Integers.Int.repr 15) tint)
                                  (tptr (tptr tuchar))) (tptr tuchar))
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Etempvar _tags (tptr tuchar))
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 15) tuint)
                                  tuchar) (tptr tuchar)))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                    (Expr.Econst_int (Integers.Int.repr 16) tint)
                                    (tptr (tptr tuchar))) (tptr tuchar))
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Etempvar _tags (tptr tuchar))
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                    tuchar) (tptr tuchar)))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                      (Expr.Econst_int (Integers.Int.repr 17) tint)
                                      (tptr (tptr tuchar))) (tptr tuchar))
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Etempvar _tags (tptr tuchar))
                                    (Expr.Ecast
                                      (Expr.Econst_int (Integers.Int.repr 17) tuint)
                                      tuchar) (tptr tuchar)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_exec_adrp_2
                                  s_kprog_arm64_exec_adrp_16)))))))))))))))))

def s_kprog_arm64_exec_adrp_18 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
        (Expr.Econst_int (Integers.Int.repr 16) tint)
        (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
      (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
    (Expr.Ebinop Binop.Oadd
      (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 16) tuint) tuchar)
      (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
          (Expr.Econst_int (Integers.Int.repr 17) tint)
          (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
        (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
      (Expr.Ebinop Binop.Oadd
        (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 17) tuint) tuchar)
        (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
            (Expr.Econst_int (Integers.Int.repr 18) tint)
            (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
          (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
        (Expr.Ebinop Binop.Oadd
          (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 18) tuint) tuchar)
          (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
              (Expr.Econst_int (Integers.Int.repr 19) tint)
              (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
            (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
          (Expr.Ebinop Binop.Oadd
            (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 19) tuint)
              tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                (Expr.Econst_int (Integers.Int.repr 20) tint)
                (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
              (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
            (Expr.Ebinop Binop.Oadd
              (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 20) tuint)
                tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                  (Expr.Econst_int (Integers.Int.repr 21) tint)
                  (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
              (Expr.Ebinop Binop.Oadd
                (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 21) tuint)
                  tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                    (Expr.Econst_int (Integers.Int.repr 22) tint)
                    (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                  (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                (Expr.Ebinop Binop.Oadd
                  (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 22) tuint)
                    tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                      (Expr.Econst_int (Integers.Int.repr 23) tint)
                      (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                    (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                    (Expr.Ecast
                      (Expr.Econst_int (Integers.Int.repr 23) tuint) tuchar)
                    (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                        (Expr.Econst_int (Integers.Int.repr 24) tint)
                        (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                      (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 24) tuint)
                        tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                          (Expr.Econst_int (Integers.Int.repr 25) tint)
                          (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                        (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 25) tuint)
                          tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                            (Expr.Econst_int (Integers.Int.repr 26) tint)
                            (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                          (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 26) tuint)
                            tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                              (Expr.Econst_int (Integers.Int.repr 27) tint)
                              (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                            (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 27) tuint)
                              tuchar)
                            (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                (Expr.Econst_int (Integers.Int.repr 28) tint)
                                (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                              (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 28) tuint)
                                tuchar)
                              (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                  (Expr.Econst_int (Integers.Int.repr 29) tint)
                                  (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 29) tuint)
                                  tuchar)
                                (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                    (Expr.Econst_int (Integers.Int.repr 30) tint)
                                    (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                  (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                    tuchar)
                                  (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                      (Expr.Econst_int (Integers.Int.repr 0) tint)
                                      (tptr (tptr tuchar))) (tptr tuchar))
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Etempvar _tags (tptr tuchar))
                                    (Expr.Ecast
                                      (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                      tuchar) (tptr tuchar)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_exec_adrp_1
                                  s_kprog_arm64_exec_adrp_17)))))))))))))))))

def f_kprog_arm64_exec_adrp : Function := {
  fn_return := tvoid,
  fn_callconv := cc_default,
  fn_params := [(_coordinates,
                 (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))),
                (_registers, (tptr (Ty.Tunion _arm64_sim_gpr noattr))),
                (_tags, (tptr tuchar)),
                (_stack_bytes, (tptr (tvolatile tuchar))),
                (_stack_tags, (tptr tuchar)), (_capacity, tuint),
                (_bias, tlong), (_op, tulong), (_dst, tulong),
                (_imm, tulong)],
  fn_vars := [(___a64_cells,
               (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31)),
              (___a64_tag_cells, (tarray (tptr tuchar) 31)),
              (___a64_stack, (Ty.Tstruct __2908 noattr))],
  fn_temps := [(___a64_adrp_tag, tuchar), (___kprog_a64_adrp_op, tuchar),
               (___kprog_a64_adrp_tag, tuchar), (___a64_write_old_sp, tlong),
               (___a64_l_reg, tulong), (___a64_l_next_ptr, (tptr tvoid)),
               (___a64_l_next_tag, tuchar), (___a64_write_value, tulong),
               (___a64_write_base, tulong), (___a64_mat_value, tulong),
               (___a64_mat_tag, tuchar), (___a64_mat_base, tulong),
               (___a64_mat_base__1, tulong), (___a64_release_old, tlong),
               (___a64_release_new, tlong), (___a64_release_i, tuint),
               (___a64_release_off, tlong), (___a64_release_w, tuint),
               (___ti, tulong), (___ts, tuint),
               (___tp, (tptr (tvolatile tulong))), (___tv, tulong),
               (_t'10, tint), (_t'9, (tvolatile tulong)), (_t'8, tint),
               (_t'7, tulong), (_t'6, tint), (_t'5, tint), (_t'4, tint),
               (_t'3, tulong), (_t'2, tulong), (_t'1, tulong),
               (_t'16, tuchar), (_t'15, tuchar), (_t'14, tuchar),
               (_t'13, (tptr (Ty.Tunion _arm64_sim_gpr noattr))),
               (_t'12, (tptr tuchar)), (_t'11, (tptr (tvolatile tuchar)))],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
        (Expr.Econst_int (Integers.Int.repr 0) tint)
        (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
      (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
    (Expr.Ebinop Binop.Oadd
      (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuchar)
      (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
          (Expr.Econst_int (Integers.Int.repr 1) tint)
          (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
        (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
      (Expr.Ebinop Binop.Oadd
        (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuchar)
        (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
            (Expr.Econst_int (Integers.Int.repr 2) tint)
            (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
          (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
        (Expr.Ebinop Binop.Oadd
          (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint) tuchar)
          (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
              (Expr.Econst_int (Integers.Int.repr 3) tint)
              (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
            (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
          (Expr.Ebinop Binop.Oadd
            (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuchar)
            (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                (Expr.Econst_int (Integers.Int.repr 4) tint)
                (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
              (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
            (Expr.Ebinop Binop.Oadd
              (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 4) tuint)
                tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                  (Expr.Econst_int (Integers.Int.repr 5) tint)
                  (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
              (Expr.Ebinop Binop.Oadd
                (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 5) tuint)
                  tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                    (Expr.Econst_int (Integers.Int.repr 6) tint)
                    (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                  (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                (Expr.Ebinop Binop.Oadd
                  (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 6) tuint)
                    tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                      (Expr.Econst_int (Integers.Int.repr 7) tint)
                      (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                    (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 7) tuint)
                      tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                        (Expr.Econst_int (Integers.Int.repr 8) tint)
                        (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                      (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 8) tuint) tuchar)
                      (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                          (Expr.Econst_int (Integers.Int.repr 9) tint)
                          (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                        (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 9) tuint)
                          tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                            (Expr.Econst_int (Integers.Int.repr 10) tint)
                            (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                          (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 10) tuint)
                            tuchar) (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                              (Expr.Econst_int (Integers.Int.repr 11) tint)
                              (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                            (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 11) tuint)
                              tuchar)
                            (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                (Expr.Econst_int (Integers.Int.repr 12) tint)
                                (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                              (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 12) tuint)
                                tuchar)
                              (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                  (Expr.Econst_int (Integers.Int.repr 13) tint)
                                  (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 13) tuint)
                                  tuchar)
                                (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                    (Expr.Econst_int (Integers.Int.repr 14) tint)
                                    (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                  (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Etempvar _registers (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 14) tuint)
                                    tuchar)
                                  (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                              (Stmt.Ssequence
                                s_kprog_arm64_exec_adrp_0
                                s_kprog_arm64_exec_adrp_18))))))))))))))))
}

def composites : List CompositeDef :=
[(CompositeDef.Composite _arm64_sim_gpr SU.Union
   [(Member.Member_plain _ptr (tptr tvoid)), (Member.Member_plain _x tulong),
    (Member.Member_plain _w tuint)]
   noattr),
 (CompositeDef.Composite _kprog_arm64_coordinates SU.Struct
   [(Member.Member_plain _sp_base tulong),
    (Member.Member_plain _return_base tulong),
    (Member.Member_plain _stack_offset tlong),
    (Member.Member_plain _sp_valid tuchar),
    (Member.Member_plain _return_valid tuchar)]
   noattr),
 (CompositeDef.Composite __2844 SU.Struct
   [(Member.Member_plain _b (tptr (tvolatile tuchar)))]
   noattr),
 (CompositeDef.Composite __2873 SU.Struct
   [(Member.Member_plain _b (tptr (tvolatile tuchar)))]
   noattr),
 (CompositeDef.Composite __2908 SU.Struct
   [(Member.Member_plain _b (tptr (tvolatile tuchar)))]
   noattr)]

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
 (_native_lab_entry_input,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_external "native_lab_entry_input"
                                   (mksignature [XType.Xint] XType.Xlong
                                     cc_default)) [tuint] tulong cc_default)),
 (_kprog_arm64_stack_base, GlobDef.Gfun (FunDef.Internal f_kprog_arm64_stack_base)),
 (_kprog_arm64_return_base, GlobDef.Gfun (FunDef.Internal f_kprog_arm64_return_base)),
 (_kprog_arm64_materialize, GlobDef.Gfun (FunDef.Internal f_kprog_arm64_materialize)),
 (_kprog_arm64_unmaterialize, GlobDef.Gfun (FunDef.Internal f_kprog_arm64_unmaterialize)),
 (_kprog_arm64_read_reg, GlobDef.Gfun (FunDef.Internal f_kprog_arm64_read_reg)),
 (_kprog_arm64_write_reg, GlobDef.Gfun (FunDef.Internal f_kprog_arm64_write_reg)),
 (_kprog_arm64_write_ptr, GlobDef.Gfun (FunDef.Internal f_kprog_arm64_write_ptr)),
 (_arm64_sim_unsupported_opcode,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_external "arm64_sim_unsupported_opcode"
                                   (mksignature [] XType.Xvoid cc_default))
     [] tvoid cc_default)),
 (_kprog_arm64_exec_adrp, GlobDef.Gfun (FunDef.Internal f_kprog_arm64_exec_adrp))]

def public_idents : List Ident :=
[_kprog_arm64_exec_adrp, _arm64_sim_unsupported_opcode,
 _kprog_arm64_write_ptr, _kprog_arm64_write_reg, _kprog_arm64_read_reg,
 _kprog_arm64_unmaterialize, _kprog_arm64_materialize,
 _kprog_arm64_return_base, _kprog_arm64_stack_base, _native_lab_entry_input,
 ___builtin_debug, ___builtin_write32_reversed, ___builtin_write16_reversed,
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

end Arm64Address

