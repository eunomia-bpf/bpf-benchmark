import Clightdefs
open CC

namespace X86Numeric

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
  def source_file : String := "c/X86Numeric.c"
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
def ___kprog_x86_alu_res : Ident := identOfString "__kprog_x86_alu_res"
def _alu : Ident := identOfString "alu"
def _bits : Ident := identOfString "bits"
def _count : Ident := identOfString "count"
def _kprog_x86_alu_result : Ident := identOfString "kprog_x86_alu_result"
def _kprog_x86_rol_result : Ident := identOfString "kprog_x86_rol_result"
def _kprog_x86_sar_result : Ident := identOfString "kprog_x86_sar_result"
def _kprog_x86_shl_result : Ident := identOfString "kprog_x86_shl_result"
def _kprog_x86_shr_result : Ident := identOfString "kprog_x86_shr_result"
def _lhs : Ident := identOfString "lhs"
def _main : Ident := identOfString "main"
def _mask : Ident := identOfString "mask"
def _narrowed : Ident := identOfString "narrowed"
def _operation : Ident := identOfString "operation"
def _result : Ident := identOfString "result"
def _rhs : Ident := identOfString "rhs"
def _shifted : Ident := identOfString "shifted"
def _value : Ident := identOfString "value"
def _width : Ident := identOfString "width"
def _x86_alu_result : Ident := identOfString "x86_alu_result"
def _t'1 : Ident := (Positive.ofNat 128)
def _t'2 : Ident := (Positive.ofNat 129)
def _t'3 : Ident := (Positive.ofNat 130)
def _t'4 : Ident := (Positive.ofNat 131)

def f_kprog_x86_shl_result : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_value, tulong), (_rhs, tulong), (_width, tuchar)],
  fn_vars := [],
  fn_temps := [(_count, tuchar), (_mask, tulong), (_narrowed, tulong),
               (_t'2, tulong), (_t'1, tuint)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _width tuchar)
                        (Expr.Econst_int (Integers.Int.repr 8) tuint) tint)
      (Stmt.Sset _t'1
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 63) tuint) tuint))
      (Stmt.Sset _t'1
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 31) tuint) tuint)))
    (Stmt.Sset _count
      (Expr.Ecast
        (Expr.Ebinop Binop.Oand (Expr.Etempvar _rhs tulong)
          (Expr.Etempvar _t'1 tuint) tulong) tuchar)))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _width tuchar)
                          (Expr.Econst_int (Integers.Int.repr 1) tuint) tint)
        (Stmt.Sset _t'2
          (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 255) tulong)
            tulong))
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar _width tuchar)
                            (Expr.Econst_int (Integers.Int.repr 2) tuint)
                            tint)
          (Stmt.Ssequence
            (Stmt.Sset _t'2
              (Expr.Ecast
                (Expr.Econst_long (Integers.Int64.repr 65535) tulong) tulong))
            (Stmt.Sset _t'2 (Expr.Ecast (Expr.Etempvar _t'2 tulong) tulong)))
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar _width tuchar)
                              (Expr.Econst_int (Integers.Int.repr 4) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'2
                  (Expr.Ecast
                    (Expr.Econst_long (Integers.Int64.repr 4294967295) tulong)
                    tulong))
                (Stmt.Sset _t'2
                  (Expr.Ecast (Expr.Etempvar _t'2 tulong) tulong)))
              (Stmt.Sset _t'2
                (Expr.Ecast (Expr.Etempvar _t'2 tulong) tulong)))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'2
                  (Expr.Ecast
                    (Expr.Econst_long (Integers.Int64.repr (-1)) tulong)
                    tulong))
                (Stmt.Sset _t'2
                  (Expr.Ecast (Expr.Etempvar _t'2 tulong) tulong)))
              (Stmt.Sset _t'2
                (Expr.Ecast (Expr.Etempvar _t'2 tulong) tulong))))))
      (Stmt.Sset _mask (Expr.Etempvar _t'2 tulong)))
    (Stmt.Ssequence
      (Stmt.Sset _narrowed
        (Expr.Ebinop Binop.Oand (Expr.Etempvar _value tulong)
          (Expr.Etempvar _mask tulong) tulong))
      (Stmt.Sreturn (some (Expr.Ebinop Binop.Oand
                            (Expr.Ebinop Binop.Oshl
                              (Expr.Etempvar _narrowed tulong)
                              (Expr.Etempvar _count tuchar) tulong)
                            (Expr.Etempvar _mask tulong) tulong))))))
}

def f_kprog_x86_shr_result : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_value, tulong), (_rhs, tulong), (_width, tuchar)],
  fn_vars := [],
  fn_temps := [(_count, tuchar), (_narrowed, tulong), (_t'2, tulong),
               (_t'1, tuint)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _width tuchar)
                        (Expr.Econst_int (Integers.Int.repr 8) tuint) tint)
      (Stmt.Sset _t'1
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 63) tuint) tuint))
      (Stmt.Sset _t'1
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 31) tuint) tuint)))
    (Stmt.Sset _count
      (Expr.Ecast
        (Expr.Ebinop Binop.Oand (Expr.Etempvar _rhs tulong)
          (Expr.Etempvar _t'1 tuint) tulong) tuchar)))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _width tuchar)
                          (Expr.Econst_int (Integers.Int.repr 1) tuint) tint)
        (Stmt.Sset _t'2
          (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 255) tulong)
            tulong))
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar _width tuchar)
                            (Expr.Econst_int (Integers.Int.repr 2) tuint)
                            tint)
          (Stmt.Ssequence
            (Stmt.Sset _t'2
              (Expr.Ecast
                (Expr.Econst_long (Integers.Int64.repr 65535) tulong) tulong))
            (Stmt.Sset _t'2 (Expr.Ecast (Expr.Etempvar _t'2 tulong) tulong)))
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar _width tuchar)
                              (Expr.Econst_int (Integers.Int.repr 4) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'2
                  (Expr.Ecast
                    (Expr.Econst_long (Integers.Int64.repr 4294967295) tulong)
                    tulong))
                (Stmt.Sset _t'2
                  (Expr.Ecast (Expr.Etempvar _t'2 tulong) tulong)))
              (Stmt.Sset _t'2
                (Expr.Ecast (Expr.Etempvar _t'2 tulong) tulong)))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'2
                  (Expr.Ecast
                    (Expr.Econst_long (Integers.Int64.repr (-1)) tulong)
                    tulong))
                (Stmt.Sset _t'2
                  (Expr.Ecast (Expr.Etempvar _t'2 tulong) tulong)))
              (Stmt.Sset _t'2
                (Expr.Ecast (Expr.Etempvar _t'2 tulong) tulong))))))
      (Stmt.Sset _narrowed
        (Expr.Ebinop Binop.Oand (Expr.Etempvar _value tulong)
          (Expr.Etempvar _t'2 tulong) tulong)))
    (Stmt.Sreturn (some (Expr.Ebinop Binop.Oshr
                          (Expr.Etempvar _narrowed tulong)
                          (Expr.Etempvar _count tuchar) tulong)))))
}

def f_kprog_x86_sar_result : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_value, tulong), (_rhs, tulong), (_width, tuchar)],
  fn_vars := [],
  fn_temps := [(_count, tuchar), (_mask, tulong), (_narrowed, tulong),
               (_shifted, tulong), (_t'3, tulong), (_t'2, tulong),
               (_t'1, tuint)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _width tuchar)
                        (Expr.Econst_int (Integers.Int.repr 8) tuint) tint)
      (Stmt.Sset _t'1
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 63) tuint) tuint))
      (Stmt.Sset _t'1
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 31) tuint) tuint)))
    (Stmt.Sset _count
      (Expr.Ecast
        (Expr.Ebinop Binop.Oand (Expr.Etempvar _rhs tulong)
          (Expr.Etempvar _t'1 tuint) tulong) tuchar)))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _width tuchar)
                          (Expr.Econst_int (Integers.Int.repr 1) tuint) tint)
        (Stmt.Sset _t'2
          (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 255) tulong)
            tulong))
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar _width tuchar)
                            (Expr.Econst_int (Integers.Int.repr 2) tuint)
                            tint)
          (Stmt.Ssequence
            (Stmt.Sset _t'2
              (Expr.Ecast
                (Expr.Econst_long (Integers.Int64.repr 65535) tulong) tulong))
            (Stmt.Sset _t'2 (Expr.Ecast (Expr.Etempvar _t'2 tulong) tulong)))
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar _width tuchar)
                              (Expr.Econst_int (Integers.Int.repr 4) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'2
                  (Expr.Ecast
                    (Expr.Econst_long (Integers.Int64.repr 4294967295) tulong)
                    tulong))
                (Stmt.Sset _t'2
                  (Expr.Ecast (Expr.Etempvar _t'2 tulong) tulong)))
              (Stmt.Sset _t'2
                (Expr.Ecast (Expr.Etempvar _t'2 tulong) tulong)))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'2
                  (Expr.Ecast
                    (Expr.Econst_long (Integers.Int64.repr (-1)) tulong)
                    tulong))
                (Stmt.Sset _t'2
                  (Expr.Ecast (Expr.Etempvar _t'2 tulong) tulong)))
              (Stmt.Sset _t'2
                (Expr.Ecast (Expr.Etempvar _t'2 tulong) tulong))))))
      (Stmt.Sset _mask (Expr.Etempvar _t'2 tulong)))
    (Stmt.Ssequence
      (Stmt.Sset _narrowed
        (Expr.Ebinop Binop.Oand (Expr.Etempvar _value tulong)
          (Expr.Etempvar _mask tulong) tulong))
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar _count tuchar)
                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                            tint)
          (Stmt.Sreturn (some (Expr.Etempvar _narrowed tulong)))
          Stmt.Sskip)
        (Stmt.Ssequence
          (Stmt.Sset _shifted
            (Expr.Ebinop Binop.Oshr (Expr.Etempvar _narrowed tulong)
              (Expr.Etempvar _count tuchar) tulong))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar _width tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                  tint)
                (Stmt.Sset _t'3
                  (Expr.Ecast
                    (Expr.Econst_long (Integers.Int64.repr 128) tulong)
                    tulong))
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Etempvar _width tuchar)
                                    (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                    tint)
                  (Stmt.Ssequence
                    (Stmt.Sset _t'3
                      (Expr.Ecast
                        (Expr.Econst_long (Integers.Int64.repr 32768) tulong)
                        tulong))
                    (Stmt.Sset _t'3
                      (Expr.Ecast (Expr.Etempvar _t'3 tulong) tulong)))
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar _width tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sset _t'3
                          (Expr.Ecast
                            (Expr.Econst_long (Integers.Int64.repr 2147483648) tulong)
                            tulong))
                        (Stmt.Sset _t'3
                          (Expr.Ecast (Expr.Etempvar _t'3 tulong) tulong)))
                      (Stmt.Sset _t'3
                        (Expr.Ecast (Expr.Etempvar _t'3 tulong) tulong)))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sset _t'3
                          (Expr.Ecast
                            (Expr.Econst_long (Integers.Int64.repr (-9223372036854775808)) tulong)
                            tulong))
                        (Stmt.Sset _t'3
                          (Expr.Ecast (Expr.Etempvar _t'3 tulong) tulong)))
                      (Stmt.Sset _t'3
                        (Expr.Ecast (Expr.Etempvar _t'3 tulong) tulong))))))
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oand
                                  (Expr.Etempvar _narrowed tulong)
                                  (Expr.Etempvar _t'3 tulong) tulong)
                (Stmt.Sset _shifted
                  (Expr.Ebinop Binop.Oor (Expr.Etempvar _shifted tulong)
                    (Expr.Ebinop Binop.Oxor (Expr.Etempvar _mask tulong)
                      (Expr.Ebinop Binop.Oshr (Expr.Etempvar _mask tulong)
                        (Expr.Etempvar _count tuchar) tulong) tulong) tulong))
                Stmt.Sskip))
            (Stmt.Sreturn (some (Expr.Etempvar _shifted tulong)))))))))
}

def f_kprog_x86_rol_result : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_value, tulong), (_rhs, tulong), (_width, tuchar)],
  fn_vars := [],
  fn_temps := [(_bits, tuint), (_mask, tulong), (_count, tulong),
               (_narrowed, tulong), (_t'3, tuint), (_t'2, tulong),
               (_t'1, tuint)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _width tuchar)
                        (Expr.Econst_int (Integers.Int.repr 1) tuint) tint)
      (Stmt.Sset _t'1
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint))
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _width tuchar)
                          (Expr.Econst_int (Integers.Int.repr 2) tuint) tint)
        (Stmt.Ssequence
          (Stmt.Sset _t'1
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 16) tuint) tuint))
          (Stmt.Sset _t'1 (Expr.Ecast (Expr.Etempvar _t'1 tuint) tuint)))
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar _width tuchar)
                            (Expr.Econst_int (Integers.Int.repr 4) tuint)
                            tint)
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sset _t'1
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 32) tuint)
                  tuint))
              (Stmt.Sset _t'1 (Expr.Ecast (Expr.Etempvar _t'1 tuint) tuint)))
            (Stmt.Sset _t'1 (Expr.Ecast (Expr.Etempvar _t'1 tuint) tuint)))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sset _t'1
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 64) tuint)
                  tuint))
              (Stmt.Sset _t'1 (Expr.Ecast (Expr.Etempvar _t'1 tuint) tuint)))
            (Stmt.Sset _t'1 (Expr.Ecast (Expr.Etempvar _t'1 tuint) tuint))))))
    (Stmt.Sset _bits (Expr.Etempvar _t'1 tuint)))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _width tuchar)
                          (Expr.Econst_int (Integers.Int.repr 1) tuint) tint)
        (Stmt.Sset _t'2
          (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 255) tulong)
            tulong))
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar _width tuchar)
                            (Expr.Econst_int (Integers.Int.repr 2) tuint)
                            tint)
          (Stmt.Ssequence
            (Stmt.Sset _t'2
              (Expr.Ecast
                (Expr.Econst_long (Integers.Int64.repr 65535) tulong) tulong))
            (Stmt.Sset _t'2 (Expr.Ecast (Expr.Etempvar _t'2 tulong) tulong)))
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar _width tuchar)
                              (Expr.Econst_int (Integers.Int.repr 4) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'2
                  (Expr.Ecast
                    (Expr.Econst_long (Integers.Int64.repr 4294967295) tulong)
                    tulong))
                (Stmt.Sset _t'2
                  (Expr.Ecast (Expr.Etempvar _t'2 tulong) tulong)))
              (Stmt.Sset _t'2
                (Expr.Ecast (Expr.Etempvar _t'2 tulong) tulong)))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'2
                  (Expr.Ecast
                    (Expr.Econst_long (Integers.Int64.repr (-1)) tulong)
                    tulong))
                (Stmt.Sset _t'2
                  (Expr.Ecast (Expr.Etempvar _t'2 tulong) tulong)))
              (Stmt.Sset _t'2
                (Expr.Ecast (Expr.Etempvar _t'2 tulong) tulong))))))
      (Stmt.Sset _mask (Expr.Etempvar _t'2 tulong)))
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar _width tuchar)
                            (Expr.Econst_int (Integers.Int.repr 8) tuint)
                            tint)
          (Stmt.Sset _t'3
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 63) tuint) tuint))
          (Stmt.Sset _t'3
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 31) tuint) tuint)))
        (Stmt.Sset _count
          (Expr.Ebinop Binop.Oand
            (Expr.Ebinop Binop.Oand (Expr.Etempvar _rhs tulong)
              (Expr.Etempvar _t'3 tuint) tulong)
            (Expr.Ebinop Binop.Osub (Expr.Etempvar _bits tuint)
              (Expr.Econst_int (Integers.Int.repr 1) tint) tuint) tulong)))
      (Stmt.Ssequence
        (Stmt.Sset _narrowed
          (Expr.Ebinop Binop.Oand (Expr.Etempvar _value tulong)
            (Expr.Etempvar _mask tulong) tulong))
        (Stmt.Ssequence
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar _count tulong)
                              (Expr.Econst_int (Integers.Int.repr 0) tint)
                              tint)
            (Stmt.Sreturn (some (Expr.Etempvar _narrowed tulong)))
            Stmt.Sskip)
          (Stmt.Sreturn (some (Expr.Ebinop Binop.Oand
                                (Expr.Ebinop Binop.Oor
                                  (Expr.Ebinop Binop.Oshl
                                    (Expr.Etempvar _narrowed tulong)
                                    (Expr.Etempvar _count tulong) tulong)
                                  (Expr.Ebinop Binop.Oshr
                                    (Expr.Etempvar _narrowed tulong)
                                    (Expr.Ebinop Binop.Osub
                                      (Expr.Etempvar _bits tuint)
                                      (Expr.Etempvar _count tulong) tulong)
                                    tulong) tulong)
                                (Expr.Etempvar _mask tulong) tulong))))))))
}

def f_x86_alu_result : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_lhs, tulong), (_rhs, tulong), (_alu, tuint),
                (_width, tuchar)],
  fn_vars := [],
  fn_temps := [(_result, tulong), (___kprog_x86_alu_res, tulong),
               (_t'4, tulong), (_t'3, tulong), (_t'2, tulong),
               (_t'1, tulong)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sset ___kprog_x86_alu_res (Expr.Etempvar _lhs tulong))
      (Stmt.Ssequence
        (Stmt.Sswitch (Expr.Etempvar _alu tuint)
          (LStmts.LScons (some 0)
            (Stmt.Ssequence
              (Stmt.Sset ___kprog_x86_alu_res
                (Expr.Ebinop Binop.Oadd
                  (Expr.Ebinop Binop.Oadd (Expr.Etempvar _lhs tulong)
                    (Expr.Etempvar _rhs tulong) tulong)
                  (Expr.Eunop Unop.Onotbool
                    (Expr.Eunop Unop.Onotbool
                      (Expr.Econst_int (Integers.Int.repr 0) tint) tint)
                    tint) tulong))
              Stmt.Sbreak)
            (LStmts.LScons (some 1)
              (Stmt.Ssequence
                (Stmt.Sset ___kprog_x86_alu_res
                  (Expr.Ebinop Binop.Osub
                    (Expr.Ebinop Binop.Osub (Expr.Etempvar _lhs tulong)
                      (Expr.Etempvar _rhs tulong) tulong)
                    (Expr.Eunop Unop.Onotbool
                      (Expr.Eunop Unop.Onotbool
                        (Expr.Econst_int (Integers.Int.repr 0) tint) tint)
                      tint) tulong))
                Stmt.Sbreak)
              (LStmts.LScons (some 2)
                (Stmt.Ssequence
                  (Stmt.Sset ___kprog_x86_alu_res
                    (Expr.Ebinop Binop.Oxor (Expr.Etempvar _lhs tulong)
                      (Expr.Etempvar _rhs tulong) tulong))
                  Stmt.Sbreak)
                (LStmts.LScons (some 3)
                  (Stmt.Ssequence
                    (Stmt.Sset ___kprog_x86_alu_res
                      (Expr.Ebinop Binop.Oor (Expr.Etempvar _lhs tulong)
                        (Expr.Etempvar _rhs tulong) tulong))
                    Stmt.Sbreak)
                  (LStmts.LScons (some 4)
                    (Stmt.Ssequence
                      (Stmt.Sset ___kprog_x86_alu_res
                        (Expr.Ebinop Binop.Oand (Expr.Etempvar _lhs tulong)
                          (Expr.Etempvar _rhs tulong) tulong))
                      Stmt.Sbreak)
                    (LStmts.LScons (some 5)
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'1)
                            (Expr.Evar _kprog_x86_shl_result (Ty.Tfunction
                                                               [tulong,
                                                                tulong,
                                                                tuchar]
                                                               tulong
                                                               cc_default))
                            [(Expr.Etempvar _lhs tulong),
                             (Expr.Etempvar _rhs tulong),
                             (Expr.Etempvar _width tuchar)])
                          (Stmt.Sset ___kprog_x86_alu_res
                            (Expr.Etempvar _t'1 tulong)))
                        Stmt.Sbreak)
                      (LStmts.LScons (some 6)
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Scall (some _t'2)
                              (Expr.Evar _kprog_x86_shr_result (Ty.Tfunction
                                                                 [tulong,
                                                                  tulong,
                                                                  tuchar]
                                                                 tulong
                                                                 cc_default))
                              [(Expr.Etempvar _lhs tulong),
                               (Expr.Etempvar _rhs tulong),
                               (Expr.Etempvar _width tuchar)])
                            (Stmt.Sset ___kprog_x86_alu_res
                              (Expr.Etempvar _t'2 tulong)))
                          Stmt.Sbreak)
                        (LStmts.LScons (some 7)
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Scall (some _t'3)
                                (Expr.Evar _kprog_x86_sar_result (Ty.Tfunction
                                                                   [tulong,
                                                                    tulong,
                                                                    tuchar]
                                                                   tulong
                                                                   cc_default))
                                [(Expr.Etempvar _lhs tulong),
                                 (Expr.Etempvar _rhs tulong),
                                 (Expr.Etempvar _width tuchar)])
                              (Stmt.Sset ___kprog_x86_alu_res
                                (Expr.Etempvar _t'3 tulong)))
                            Stmt.Sbreak)
                          (LStmts.LScons (some 8)
                            (Stmt.Ssequence
                              (Stmt.Ssequence
                                (Stmt.Scall (some _t'4)
                                  (Expr.Evar _kprog_x86_rol_result (Ty.Tfunction
                                                                    [tulong,
                                                                    tulong,
                                                                    tuchar]
                                                                    tulong
                                                                    cc_default))
                                  [(Expr.Etempvar _lhs tulong),
                                   (Expr.Etempvar _rhs tulong),
                                   (Expr.Etempvar _width tuchar)])
                                (Stmt.Sset ___kprog_x86_alu_res
                                  (Expr.Etempvar _t'4 tulong)))
                              Stmt.Sbreak)
                            (LStmts.LScons (some 9)
                              (Stmt.Ssequence
                                (Stmt.Sset ___kprog_x86_alu_res
                                  (Expr.Ebinop Binop.Omul
                                    (Expr.Etempvar _lhs tulong)
                                    (Expr.Etempvar _rhs tulong) tulong))
                                Stmt.Sbreak)
                              (LStmts.LScons (some 10)
                                (Stmt.Ssequence
                                  (Stmt.Sset ___kprog_x86_alu_res
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Ebinop Binop.Oadd
                                        (Expr.Etempvar _lhs tulong)
                                        (Expr.Econst_int (Integers.Int.repr 1) tint)
                                        tulong)
                                      (Expr.Eunop Unop.Onotbool
                                        (Expr.Eunop Unop.Onotbool
                                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                                          tint) tint) tulong))
                                  Stmt.Sbreak)
                                (LStmts.LScons (some 11)
                                  (Stmt.Ssequence
                                    (Stmt.Sset ___kprog_x86_alu_res
                                      (Expr.Eunop Unop.Onotint
                                        (Expr.Etempvar _lhs tulong) tulong))
                                    Stmt.Sbreak)
                                  (LStmts.LScons (some 12)
                                    (Stmt.Ssequence
                                      (Stmt.Sset ___kprog_x86_alu_res
                                        (Expr.Ebinop Binop.Osub
                                          (Expr.Ebinop Binop.Osub
                                            (Expr.Etempvar _lhs tulong)
                                            (Expr.Etempvar _rhs tulong)
                                            tulong)
                                          (Expr.Eunop Unop.Onotbool
                                            (Expr.Eunop Unop.Onotbool
                                              (Expr.Econst_int (Integers.Int.repr 0) tint)
                                              tint) tint) tulong))
                                      Stmt.Sbreak)
                                    (LStmts.LScons (some 13)
                                      (Stmt.Ssequence
                                        (Stmt.Sset ___kprog_x86_alu_res
                                          (Expr.Ebinop Binop.Osub
                                            (Expr.Ebinop Binop.Osub
                                              (Expr.Etempvar _lhs tulong)
                                              (Expr.Econst_int (Integers.Int.repr 1) tint)
                                              tulong)
                                            (Expr.Eunop Unop.Onotbool
                                              (Expr.Eunop Unop.Onotbool
                                                (Expr.Econst_int (Integers.Int.repr 0) tint)
                                                tint) tint) tulong))
                                        Stmt.Sbreak)
                                      (LStmts.LScons (some 14)
                                        (Stmt.Ssequence
                                          (Stmt.Sset ___kprog_x86_alu_res
                                            (Expr.Ebinop Binop.Osub
                                              (Expr.Ebinop Binop.Osub
                                                (Expr.Econst_int (Integers.Int.repr 0) tint)
                                                (Expr.Etempvar _lhs tulong)
                                                tulong)
                                              (Expr.Eunop Unop.Onotbool
                                                (Expr.Eunop Unop.Onotbool
                                                  (Expr.Econst_int (Integers.Int.repr 0) tint)
                                                  tint) tint) tulong))
                                          Stmt.Sbreak)
                                        (LStmts.LScons (some 15)
                                          (Stmt.Ssequence
                                            (Stmt.Sset ___kprog_x86_alu_res
                                              (Expr.Ebinop Binop.Oadd
                                                (Expr.Ebinop Binop.Oadd
                                                  (Expr.Etempvar _lhs tulong)
                                                  (Expr.Etempvar _rhs tulong)
                                                  tulong)
                                                (Expr.Eunop Unop.Onotbool
                                                  (Expr.Eunop Unop.Onotbool
                                                    (Expr.Econst_int (Integers.Int.repr 0) tint)
                                                    tint) tint) tulong))
                                            Stmt.Sbreak)
                                          (LStmts.LScons none
                                            Stmt.Sbreak
                                            LStmts.LSnil))))))))))))))))))
        (Stmt.Sset _result (Expr.Etempvar ___kprog_x86_alu_res tulong))))
    Stmt.Sbreak)
  (Stmt.Sreturn (some (Expr.Etempvar _result tulong))))
}

def f_kprog_x86_alu_result : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_lhs, tulong), (_rhs, tulong), (_operation, tuint),
                (_width, tuchar)],
  fn_vars := [],
  fn_temps := [(_t'1, tulong)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'1)
    (Expr.Evar _x86_alu_result (Ty.Tfunction [tulong, tulong, tuint, tuchar]
                                 tulong cc_default))
    [(Expr.Etempvar _lhs tulong), (Expr.Etempvar _rhs tulong),
     (Expr.Etempvar _operation tuint), (Expr.Etempvar _width tuchar)])
  (Stmt.Sreturn (some (Expr.Etempvar _t'1 tulong))))
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
 (_kprog_x86_shl_result, GlobDef.Gfun (FunDef.Internal f_kprog_x86_shl_result)),
 (_kprog_x86_shr_result, GlobDef.Gfun (FunDef.Internal f_kprog_x86_shr_result)),
 (_kprog_x86_sar_result, GlobDef.Gfun (FunDef.Internal f_kprog_x86_sar_result)),
 (_kprog_x86_rol_result, GlobDef.Gfun (FunDef.Internal f_kprog_x86_rol_result)),
 (_x86_alu_result, GlobDef.Gfun (FunDef.Internal f_x86_alu_result)),
 (_kprog_x86_alu_result, GlobDef.Gfun (FunDef.Internal f_kprog_x86_alu_result))]

def public_idents : List Ident :=
[_kprog_x86_alu_result, ___builtin_debug, ___builtin_write32_reversed,
 ___builtin_write16_reversed, ___builtin_read32_reversed,
 ___builtin_read16_reversed, ___builtin_fnmsub, ___builtin_fnmadd,
 ___builtin_fmsub, ___builtin_fmadd, ___builtin_fmin, ___builtin_fmax,
 ___builtin_expect, ___builtin_unreachable, ___builtin_va_end,
 ___builtin_va_copy, ___builtin_va_arg, ___builtin_va_start,
 ___builtin_membar, ___builtin_annot_intval, ___builtin_annot,
 ___builtin_sel, ___builtin_memcpy_aligned, ___builtin_sqrt,
 ___builtin_fsqrt, ___builtin_fabsf, ___builtin_fabs, ___builtin_ctzll,
 ___builtin_ctzl, ___builtin_ctz, ___builtin_clzll, ___builtin_clzl,
 ___builtin_clz, ___builtin_bswap16, ___builtin_bswap32, ___builtin_bswap,
 ___builtin_bswap64, ___builtin_ais_annot, ___compcert_i64_umulh,
 ___compcert_i64_smulh, ___compcert_i64_sar, ___compcert_i64_shr,
 ___compcert_i64_shl, ___compcert_i64_umod, ___compcert_i64_smod,
 ___compcert_i64_udiv, ___compcert_i64_sdiv, ___compcert_i64_utof,
 ___compcert_i64_stof, ___compcert_i64_utod, ___compcert_i64_stod,
 ___compcert_i64_dtou, ___compcert_i64_dtos, ___compcert_va_composite,
 ___compcert_va_float64, ___compcert_va_int64, ___compcert_va_int32]

def prog : Program :=
  mkprogram composites global_definitions public_idents _main

end X86Numeric

