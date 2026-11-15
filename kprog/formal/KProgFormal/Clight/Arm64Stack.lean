import Clightdefs
open CC

namespace Arm64Stack

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
  def source_file : String := "c/Arm64Stack.c"
  def normalized : Bool := true
end Info

def ___a64_loss_i : Ident := identOfString "__a64_loss_i"
def ___a64_loss_off : Ident := identOfString "__a64_loss_off"
def ___a64_loss_value : Ident := identOfString "__a64_loss_value"
def ___a64_loss_width : Ident := identOfString "__a64_loss_width"
def ___a64_observed : Ident := identOfString "__a64_observed"
def ___a64_sp_ptr_index : Ident := identOfString "__a64_sp_ptr_index"
def ___a64_srt_index : Ident := identOfString "__a64_srt_index"
def ___a64_srt_source : Ident := identOfString "__a64_srt_source"
def ___a64_srt_tag : Ident := identOfString "__a64_srt_tag"
def ___a64_srt_width : Ident := identOfString "__a64_srt_width"
def ___a64_str_index : Ident := identOfString "__a64_str_index"
def ___a64_str_value : Ident := identOfString "__a64_str_value"
def ___a64_str_width : Ident := identOfString "__a64_str_width"
def ___a64_stw_action : Ident := identOfString "__a64_stw_action"
def ___a64_stw_action__1 : Ident := identOfString "__a64_stw_action__1"
def ___a64_stw_index : Ident := identOfString "__a64_stw_index"
def ___a64_stw_index__1 : Ident := identOfString "__a64_stw_index__1"
def ___a64_stw_last : Ident := identOfString "__a64_stw_last"
def ___a64_stw_last__1 : Ident := identOfString "__a64_stw_last__1"
def ___a64_stw_payload : Ident := identOfString "__a64_stw_payload"
def ___a64_stw_payload__1 : Ident := identOfString "__a64_stw_payload__1"
def ___a64_stw_value : Ident := identOfString "__a64_stw_value"
def ___a64_stw_value__1 : Ident := identOfString "__a64_stw_value__1"
def ___a64_stw_width : Ident := identOfString "__a64_stw_width"
def ___a64_stw_width__1 : Ident := identOfString "__a64_stw_width__1"
def ___a64_unmat_base : Ident := identOfString "__a64_unmat_base"
def ___a64_unmat_base__1 : Ident := identOfString "__a64_unmat_base__1"
def ___a64_unmat_base__2 : Ident := identOfString "__a64_unmat_base__2"
def ___a64_unmat_base__3 : Ident := identOfString "__a64_unmat_base__3"
def ___a64_unmat_tag : Ident := identOfString "__a64_unmat_tag"
def ___a64_unmat_tag__1 : Ident := identOfString "__a64_unmat_tag__1"
def ___a64_unmat_value : Ident := identOfString "__a64_unmat_value"
def ___a64_unmat_value__1 : Ident := identOfString "__a64_unmat_value__1"
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
def ___kprog_a64_bl_lane : Ident := identOfString "__kprog_a64_bl_lane"
def ___kprog_a64_bl_lane__1 : Ident := identOfString "__kprog_a64_bl_lane__1"
def ___kprog_a64_bl_lane__10 : Ident := identOfString "__kprog_a64_bl_lane__10"
def ___kprog_a64_bl_lane__11 : Ident := identOfString "__kprog_a64_bl_lane__11"
def ___kprog_a64_bl_lane__12 : Ident := identOfString "__kprog_a64_bl_lane__12"
def ___kprog_a64_bl_lane__13 : Ident := identOfString "__kprog_a64_bl_lane__13"
def ___kprog_a64_bl_lane__14 : Ident := identOfString "__kprog_a64_bl_lane__14"
def ___kprog_a64_bl_lane__15 : Ident := identOfString "__kprog_a64_bl_lane__15"
def ___kprog_a64_bl_lane__2 : Ident := identOfString "__kprog_a64_bl_lane__2"
def ___kprog_a64_bl_lane__3 : Ident := identOfString "__kprog_a64_bl_lane__3"
def ___kprog_a64_bl_lane__4 : Ident := identOfString "__kprog_a64_bl_lane__4"
def ___kprog_a64_bl_lane__5 : Ident := identOfString "__kprog_a64_bl_lane__5"
def ___kprog_a64_bl_lane__6 : Ident := identOfString "__kprog_a64_bl_lane__6"
def ___kprog_a64_bl_lane__7 : Ident := identOfString "__kprog_a64_bl_lane__7"
def ___kprog_a64_bl_lane__8 : Ident := identOfString "__kprog_a64_bl_lane__8"
def ___kprog_a64_bl_lane__9 : Ident := identOfString "__kprog_a64_bl_lane__9"
def ___kprog_a64_bl_shift : Ident := identOfString "__kprog_a64_bl_shift"
def ___kprog_a64_bl_shift__1 : Ident := identOfString "__kprog_a64_bl_shift__1"
def ___kprog_a64_bl_shift__10 : Ident := identOfString "__kprog_a64_bl_shift__10"
def ___kprog_a64_bl_shift__11 : Ident := identOfString "__kprog_a64_bl_shift__11"
def ___kprog_a64_bl_shift__12 : Ident := identOfString "__kprog_a64_bl_shift__12"
def ___kprog_a64_bl_shift__13 : Ident := identOfString "__kprog_a64_bl_shift__13"
def ___kprog_a64_bl_shift__14 : Ident := identOfString "__kprog_a64_bl_shift__14"
def ___kprog_a64_bl_shift__15 : Ident := identOfString "__kprog_a64_bl_shift__15"
def ___kprog_a64_bl_shift__2 : Ident := identOfString "__kprog_a64_bl_shift__2"
def ___kprog_a64_bl_shift__3 : Ident := identOfString "__kprog_a64_bl_shift__3"
def ___kprog_a64_bl_shift__4 : Ident := identOfString "__kprog_a64_bl_shift__4"
def ___kprog_a64_bl_shift__5 : Ident := identOfString "__kprog_a64_bl_shift__5"
def ___kprog_a64_bl_shift__6 : Ident := identOfString "__kprog_a64_bl_shift__6"
def ___kprog_a64_bl_shift__7 : Ident := identOfString "__kprog_a64_bl_shift__7"
def ___kprog_a64_bl_shift__8 : Ident := identOfString "__kprog_a64_bl_shift__8"
def ___kprog_a64_bl_shift__9 : Ident := identOfString "__kprog_a64_bl_shift__9"
def ___kprog_a64_bl_value : Ident := identOfString "__kprog_a64_bl_value"
def ___kprog_a64_bl_value__1 : Ident := identOfString "__kprog_a64_bl_value__1"
def ___kprog_a64_bl_value__10 : Ident := identOfString "__kprog_a64_bl_value__10"
def ___kprog_a64_bl_value__11 : Ident := identOfString "__kprog_a64_bl_value__11"
def ___kprog_a64_bl_value__12 : Ident := identOfString "__kprog_a64_bl_value__12"
def ___kprog_a64_bl_value__13 : Ident := identOfString "__kprog_a64_bl_value__13"
def ___kprog_a64_bl_value__14 : Ident := identOfString "__kprog_a64_bl_value__14"
def ___kprog_a64_bl_value__15 : Ident := identOfString "__kprog_a64_bl_value__15"
def ___kprog_a64_bl_value__2 : Ident := identOfString "__kprog_a64_bl_value__2"
def ___kprog_a64_bl_value__3 : Ident := identOfString "__kprog_a64_bl_value__3"
def ___kprog_a64_bl_value__4 : Ident := identOfString "__kprog_a64_bl_value__4"
def ___kprog_a64_bl_value__5 : Ident := identOfString "__kprog_a64_bl_value__5"
def ___kprog_a64_bl_value__6 : Ident := identOfString "__kprog_a64_bl_value__6"
def ___kprog_a64_bl_value__7 : Ident := identOfString "__kprog_a64_bl_value__7"
def ___kprog_a64_bl_value__8 : Ident := identOfString "__kprog_a64_bl_value__8"
def ___kprog_a64_bl_value__9 : Ident := identOfString "__kprog_a64_bl_value__9"
def ___ti : Ident := identOfString "__ti"
def ___ti__1 : Ident := identOfString "__ti__1"
def ___ti__2 : Ident := identOfString "__ti__2"
def ___ti__3 : Ident := identOfString "__ti__3"
def ___ti__4 : Ident := identOfString "__ti__4"
def ___ti__5 : Ident := identOfString "__ti__5"
def ___tp : Ident := identOfString "__tp"
def ___tp__1 : Ident := identOfString "__tp__1"
def ___tp__2 : Ident := identOfString "__tp__2"
def ___tp__3 : Ident := identOfString "__tp__3"
def ___tp__4 : Ident := identOfString "__tp__4"
def ___tp__5 : Ident := identOfString "__tp__5"
def ___ts : Ident := identOfString "__ts"
def ___ts__1 : Ident := identOfString "__ts__1"
def ___ts__2 : Ident := identOfString "__ts__2"
def ___ts__3 : Ident := identOfString "__ts__3"
def ___ts__4 : Ident := identOfString "__ts__4"
def ___ts__5 : Ident := identOfString "__ts__5"
def ___tv : Ident := identOfString "__tv"
def ___tv__1 : Ident := identOfString "__tv__1"
def ___tv__2 : Ident := identOfString "__tv__2"
def ___tv__3 : Ident := identOfString "__tv__3"
def ___tv__4 : Ident := identOfString "__tv__4"
def ___tv__5 : Ident := identOfString "__tv__5"
def _arm64_sim_unsupported_opcode : Ident := identOfString "arm64_sim_unsupported_opcode"
def _b : Ident := identOfString "b"
def _bias : Ident := identOfString "bias"
def _capacity : Ident := identOfString "capacity"
def _coordinates : Ident := identOfString "coordinates"
def _kprog_arm64_coordinates : Ident := identOfString "kprog_arm64_coordinates"
def _kprog_arm64_memory : Ident := identOfString "kprog_arm64_memory"
def _kprog_arm64_stack_pointer : Ident := identOfString "kprog_arm64_stack_pointer"
def _kprog_arm64_stack_read : Ident := identOfString "kprog_arm64_stack_read"
def _kprog_arm64_stack_read_owned : Ident := identOfString "kprog_arm64_stack_read_owned"
def _kprog_arm64_stack_read_tag : Ident := identOfString "kprog_arm64_stack_read_tag"
def _kprog_arm64_stack_write : Ident := identOfString "kprog_arm64_stack_write"
def _kprog_arm64_stack_write_owned : Ident := identOfString "kprog_arm64_stack_write_owned"
def _main : Ident := identOfString "main"
def _memory : Ident := identOfString "memory"
def _native_lab_entry_input : Ident := identOfString "native_lab_entry_input"
def _off : Ident := identOfString "off"
def _payload : Ident := identOfString "payload"
def _q : Ident := identOfString "q"
def _result : Ident := identOfString "result"
def _return_base : Ident := identOfString "return_base"
def _return_valid : Ident := identOfString "return_valid"
def _sp_base : Ident := identOfString "sp_base"
def _sp_valid : Ident := identOfString "sp_valid"
def _stack_offset : Ident := identOfString "stack_offset"
def _tag : Ident := identOfString "tag"
def _tags : Ident := identOfString "tags"
def _value : Ident := identOfString "value"
def _width : Ident := identOfString "width"
def _t'1 : Ident := (Positive.ofNat 128)
def _t'10 : Ident := (Positive.ofNat 137)
def _t'11 : Ident := (Positive.ofNat 138)
def _t'12 : Ident := (Positive.ofNat 139)
def _t'13 : Ident := (Positive.ofNat 140)
def _t'14 : Ident := (Positive.ofNat 141)
def _t'15 : Ident := (Positive.ofNat 142)
def _t'16 : Ident := (Positive.ofNat 143)
def _t'17 : Ident := (Positive.ofNat 144)
def _t'18 : Ident := (Positive.ofNat 145)
def _t'19 : Ident := (Positive.ofNat 146)
def _t'2 : Ident := (Positive.ofNat 129)
def _t'20 : Ident := (Positive.ofNat 147)
def _t'21 : Ident := (Positive.ofNat 148)
def _t'22 : Ident := (Positive.ofNat 149)
def _t'23 : Ident := (Positive.ofNat 150)
def _t'24 : Ident := (Positive.ofNat 151)
def _t'25 : Ident := (Positive.ofNat 152)
def _t'26 : Ident := (Positive.ofNat 153)
def _t'27 : Ident := (Positive.ofNat 154)
def _t'28 : Ident := (Positive.ofNat 155)
def _t'29 : Ident := (Positive.ofNat 156)
def _t'3 : Ident := (Positive.ofNat 130)
def _t'30 : Ident := (Positive.ofNat 157)
def _t'31 : Ident := (Positive.ofNat 158)
def _t'32 : Ident := (Positive.ofNat 159)
def _t'33 : Ident := (Positive.ofNat 160)
def _t'34 : Ident := (Positive.ofNat 161)
def _t'35 : Ident := (Positive.ofNat 162)
def _t'36 : Ident := (Positive.ofNat 163)
def _t'37 : Ident := (Positive.ofNat 164)
def _t'38 : Ident := (Positive.ofNat 165)
def _t'39 : Ident := (Positive.ofNat 166)
def _t'4 : Ident := (Positive.ofNat 131)
def _t'40 : Ident := (Positive.ofNat 167)
def _t'41 : Ident := (Positive.ofNat 168)
def _t'42 : Ident := (Positive.ofNat 169)
def _t'43 : Ident := (Positive.ofNat 170)
def _t'44 : Ident := (Positive.ofNat 171)
def _t'45 : Ident := (Positive.ofNat 172)
def _t'46 : Ident := (Positive.ofNat 173)
def _t'47 : Ident := (Positive.ofNat 174)
def _t'48 : Ident := (Positive.ofNat 175)
def _t'49 : Ident := (Positive.ofNat 176)
def _t'5 : Ident := (Positive.ofNat 132)
def _t'50 : Ident := (Positive.ofNat 177)
def _t'51 : Ident := (Positive.ofNat 178)
def _t'52 : Ident := (Positive.ofNat 179)
def _t'53 : Ident := (Positive.ofNat 180)
def _t'54 : Ident := (Positive.ofNat 181)
def _t'55 : Ident := (Positive.ofNat 182)
def _t'56 : Ident := (Positive.ofNat 183)
def _t'57 : Ident := (Positive.ofNat 184)
def _t'58 : Ident := (Positive.ofNat 185)
def _t'59 : Ident := (Positive.ofNat 186)
def _t'6 : Ident := (Positive.ofNat 133)
def _t'60 : Ident := (Positive.ofNat 187)
def _t'61 : Ident := (Positive.ofNat 188)
def _t'62 : Ident := (Positive.ofNat 189)
def _t'63 : Ident := (Positive.ofNat 190)
def _t'64 : Ident := (Positive.ofNat 191)
def _t'65 : Ident := (Positive.ofNat 192)
def _t'66 : Ident := (Positive.ofNat 193)
def _t'67 : Ident := (Positive.ofNat 194)
def _t'68 : Ident := (Positive.ofNat 195)
def _t'69 : Ident := (Positive.ofNat 196)
def _t'7 : Ident := (Positive.ofNat 134)
def _t'70 : Ident := (Positive.ofNat 197)
def _t'71 : Ident := (Positive.ofNat 198)
def _t'72 : Ident := (Positive.ofNat 199)
def _t'73 : Ident := (Positive.ofNat 200)
def _t'74 : Ident := (Positive.ofNat 201)
def _t'75 : Ident := (Positive.ofNat 202)
def _t'76 : Ident := (Positive.ofNat 203)
def _t'77 : Ident := (Positive.ofNat 204)
def _t'78 : Ident := (Positive.ofNat 205)
def _t'79 : Ident := (Positive.ofNat 206)
def _t'8 : Ident := (Positive.ofNat 135)
def _t'80 : Ident := (Positive.ofNat 207)
def _t'81 : Ident := (Positive.ofNat 208)
def _t'82 : Ident := (Positive.ofNat 209)
def _t'83 : Ident := (Positive.ofNat 210)
def _t'84 : Ident := (Positive.ofNat 211)
def _t'85 : Ident := (Positive.ofNat 212)
def _t'86 : Ident := (Positive.ofNat 213)
def _t'87 : Ident := (Positive.ofNat 214)
def _t'88 : Ident := (Positive.ofNat 215)
def _t'89 : Ident := (Positive.ofNat 216)
def _t'9 : Ident := (Positive.ofNat 136)
def _t'90 : Ident := (Positive.ofNat 217)

@[noinline] def s_kprog_arm64_stack_read_owned_0 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'16
    (Expr.Efield
      (Expr.Ederef
        (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
        (Ty.Tstruct _kprog_arm64_memory noattr)) _b
      (tptr (tvolatile tuchar))))
  (Stmt.Sbuiltin (some _t'5) (ExtFun.EF_vload Chunk.Mint8unsigned)
    [(tptr (tvolatile tuchar))]
    [(Expr.Eaddrof
       (Expr.Ederef
         (Expr.Ebinop Binop.Oadd
           (Expr.Etempvar _t'16 (tptr (tvolatile tuchar)))
           (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___a64_str_index tulong)
             (Expr.Econst_int (Integers.Int.repr 3) tint) tulong)
           (tptr (tvolatile tuchar))) (tvolatile tuchar))
       (tptr (tvolatile tuchar)))]))

@[noinline] def s_kprog_arm64_stack_read_owned_1 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'15
    (Expr.Efield
      (Expr.Ederef
        (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
        (Ty.Tstruct _kprog_arm64_memory noattr)) _b
      (tptr (tvolatile tuchar))))
  (Stmt.Sbuiltin (some _t'6) (ExtFun.EF_vload Chunk.Mint8unsigned)
    [(tptr (tvolatile tuchar))]
    [(Expr.Eaddrof
       (Expr.Ederef
         (Expr.Ebinop Binop.Oadd
           (Expr.Etempvar _t'15 (tptr (tvolatile tuchar)))
           (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___a64_str_index tulong)
             (Expr.Econst_int (Integers.Int.repr 4) tint) tulong)
           (tptr (tvolatile tuchar))) (tvolatile tuchar))
       (tptr (tvolatile tuchar)))]))

@[noinline] def s_kprog_arm64_stack_read_owned_2 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'14
      (Expr.Efield
        (Expr.Ederef
          (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
          (Ty.Tstruct _kprog_arm64_memory noattr)) _b
        (tptr (tvolatile tuchar))))
    (Stmt.Sbuiltin (some _t'7) (ExtFun.EF_vload Chunk.Mint8unsigned)
      [(tptr (tvolatile tuchar))]
      [(Expr.Eaddrof
         (Expr.Ederef
           (Expr.Ebinop Binop.Oadd
             (Expr.Etempvar _t'14 (tptr (tvolatile tuchar)))
             (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___a64_str_index tulong)
               (Expr.Econst_int (Integers.Int.repr 5) tint) tulong)
             (tptr (tvolatile tuchar))) (tvolatile tuchar))
         (tptr (tvolatile tuchar)))]))
  (Stmt.Sset ___a64_str_value
    (Expr.Ebinop Binop.Oor (Expr.Etempvar ___a64_str_value tulong)
      (Expr.Ebinop Binop.Oshl
        (Expr.Ecast (Expr.Etempvar _t'7 (tvolatile tuchar)) tulong)
        (Expr.Econst_int (Integers.Int.repr 40) tint) tulong) tulong)))

@[noinline] def s_kprog_arm64_stack_read_owned_3 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'13
      (Expr.Efield
        (Expr.Ederef
          (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
          (Ty.Tstruct _kprog_arm64_memory noattr)) _b
        (tptr (tvolatile tuchar))))
    (Stmt.Sbuiltin (some _t'8) (ExtFun.EF_vload Chunk.Mint8unsigned)
      [(tptr (tvolatile tuchar))]
      [(Expr.Eaddrof
         (Expr.Ederef
           (Expr.Ebinop Binop.Oadd
             (Expr.Etempvar _t'13 (tptr (tvolatile tuchar)))
             (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___a64_str_index tulong)
               (Expr.Econst_int (Integers.Int.repr 6) tint) tulong)
             (tptr (tvolatile tuchar))) (tvolatile tuchar))
         (tptr (tvolatile tuchar)))]))
  (Stmt.Sset ___a64_str_value
    (Expr.Ebinop Binop.Oor (Expr.Etempvar ___a64_str_value tulong)
      (Expr.Ebinop Binop.Oshl
        (Expr.Ecast (Expr.Etempvar _t'8 (tvolatile tuchar)) tulong)
        (Expr.Econst_int (Integers.Int.repr 48) tint) tulong) tulong)))

@[noinline] def s_kprog_arm64_stack_read_owned_4 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'12
      (Expr.Efield
        (Expr.Ederef
          (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
          (Ty.Tstruct _kprog_arm64_memory noattr)) _b
        (tptr (tvolatile tuchar))))
    (Stmt.Sbuiltin (some _t'9) (ExtFun.EF_vload Chunk.Mint8unsigned)
      [(tptr (tvolatile tuchar))]
      [(Expr.Eaddrof
         (Expr.Ederef
           (Expr.Ebinop Binop.Oadd
             (Expr.Etempvar _t'12 (tptr (tvolatile tuchar)))
             (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___a64_str_index tulong)
               (Expr.Econst_int (Integers.Int.repr 7) tint) tulong)
             (tptr (tvolatile tuchar))) (tvolatile tuchar))
         (tptr (tvolatile tuchar)))]))
  (Stmt.Sset ___a64_str_value
    (Expr.Ebinop Binop.Oor (Expr.Etempvar ___a64_str_value tulong)
      (Expr.Ebinop Binop.Oshl
        (Expr.Ecast (Expr.Etempvar _t'9 (tvolatile tuchar)) tulong)
        (Expr.Econst_int (Integers.Int.repr 56) tint) tulong) tulong)))

def f_kprog_arm64_stack_read_owned : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_memory, (tptr (Ty.Tstruct _kprog_arm64_memory noattr))),
                (_off, tlong), (_width, tuchar)],
  fn_vars := [],
  fn_temps := [(_result, tulong), (___a64_str_index, tulong),
               (___a64_str_width, tuchar), (___a64_str_value, tulong),
               (_t'11, tint), (_t'10, tint), (_t'9, (tvolatile tuchar)),
               (_t'8, (tvolatile tuchar)), (_t'7, (tvolatile tuchar)),
               (_t'6, (tvolatile tuchar)), (_t'5, (tvolatile tuchar)),
               (_t'4, (tvolatile tuchar)), (_t'3, (tvolatile tuchar)),
               (_t'2, (tvolatile tuchar)), (_t'1, (tvolatile tulong)),
               (_t'21, tlong), (_t'20, (tptr (tvolatile tulong))),
               (_t'19, (tptr (tvolatile tuchar))),
               (_t'18, (tptr (tvolatile tuchar))),
               (_t'17, (tptr (tvolatile tuchar))),
               (_t'16, (tptr (tvolatile tuchar))),
               (_t'15, (tptr (tvolatile tuchar))),
               (_t'14, (tptr (tvolatile tuchar))),
               (_t'13, (tptr (tvolatile tuchar))),
               (_t'12, (tptr (tvolatile tuchar)))],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sset _t'21
          (Expr.Efield
            (Expr.Ederef
              (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
              (Ty.Tstruct _kprog_arm64_memory noattr)) _bias tlong))
        (Stmt.Sset ___a64_str_index
          (Expr.Ebinop Binop.Oadd
            (Expr.Ecast (Expr.Etempvar _t'21 tlong) tulong)
            (Expr.Ecast (Expr.Etempvar _off tlong) tulong) tulong)))
      (Stmt.Ssequence
        (Stmt.Sset ___a64_str_width
          (Expr.Ecast (Expr.Etempvar _width tuchar) tuchar))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar ___a64_str_width tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                  tint)
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Ebinop Binop.Oand
                                      (Expr.Ecast
                                        (Expr.Etempvar ___a64_str_index tulong)
                                        tuint)
                                      (Expr.Econst_int (Integers.Int.repr 7) tuint)
                                      tuint)
                                    (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                    tint)
                  (Stmt.Ssequence
                    (Stmt.Sset _t'10
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 1) tint) tint))
                    (Stmt.Sset _t'10
                      (Expr.Ecast (Expr.Etempvar _t'10 tint) tbool)))
                  (Stmt.Ssequence
                    (Stmt.Sset _t'10
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 0) tint) tint))
                    (Stmt.Sset _t'10
                      (Expr.Ecast (Expr.Etempvar _t'10 tint) tbool))))
                (Stmt.Sset _t'10
                  (Expr.Econst_int (Integers.Int.repr 0) tint)))
              (Stmt.Sifthenelse (Expr.Etempvar _t'10 tint)
                (Stmt.Sset _t'11
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tint)
                    tint))
                (Stmt.Sset _t'11
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                    tint))))
            (Stmt.Sifthenelse (Expr.Ecast (Expr.Etempvar _t'11 tint) tuchar)
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sset _t'20
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                        (Ty.Tstruct _kprog_arm64_memory noattr)) _q
                      (tptr (tvolatile tulong))))
                  (Stmt.Sbuiltin (some _t'1) (ExtFun.EF_vload Chunk.Mint64)
                    [(tptr (tvolatile tulong))]
                    [(Expr.Eaddrof
                       (Expr.Ederef
                         (Expr.Ebinop Binop.Oadd
                           (Expr.Etempvar _t'20 (tptr (tvolatile tulong)))
                           (Expr.Ebinop Binop.Oshr
                             (Expr.Ecast
                               (Expr.Etempvar ___a64_str_index tulong)
                               tulong)
                             (Expr.Econst_int (Integers.Int.repr 3) tint)
                             tulong) (tptr (tvolatile tulong)))
                         (tvolatile tulong)) (tptr (tvolatile tulong)))]))
                (Stmt.Sset ___a64_str_value
                  (Expr.Etempvar _t'1 (tvolatile tulong))))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sset _t'19
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                          (Ty.Tstruct _kprog_arm64_memory noattr)) _b
                        (tptr (tvolatile tuchar))))
                    (Stmt.Sbuiltin (some _t'2)
                      (ExtFun.EF_vload Chunk.Mint8unsigned)
                      [(tptr (tvolatile tuchar))]
                      [(Expr.Eaddrof
                         (Expr.Ederef
                           (Expr.Ebinop Binop.Oadd
                             (Expr.Etempvar _t'19 (tptr (tvolatile tuchar)))
                             (Expr.Etempvar ___a64_str_index tulong)
                             (tptr (tvolatile tuchar))) (tvolatile tuchar))
                         (tptr (tvolatile tuchar)))]))
                  (Stmt.Sset ___a64_str_value
                    (Expr.Ecast (Expr.Etempvar _t'2 (tvolatile tuchar))
                      tulong)))
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                      (Expr.Etempvar ___a64_str_width tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sset _t'18
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                              (Ty.Tstruct _kprog_arm64_memory noattr)) _b
                            (tptr (tvolatile tuchar))))
                        (Stmt.Sbuiltin (some _t'3)
                          (ExtFun.EF_vload Chunk.Mint8unsigned)
                          [(tptr (tvolatile tuchar))]
                          [(Expr.Eaddrof
                             (Expr.Ederef
                               (Expr.Ebinop Binop.Oadd
                                 (Expr.Etempvar _t'18 (tptr (tvolatile tuchar)))
                                 (Expr.Ebinop Binop.Oadd
                                   (Expr.Etempvar ___a64_str_index tulong)
                                   (Expr.Econst_int (Integers.Int.repr 1) tint)
                                   tulong) (tptr (tvolatile tuchar)))
                               (tvolatile tuchar)) (tptr (tvolatile tuchar)))]))
                      (Stmt.Sset ___a64_str_value
                        (Expr.Ebinop Binop.Oor
                          (Expr.Etempvar ___a64_str_value tulong)
                          (Expr.Ebinop Binop.Oshl
                            (Expr.Ecast
                              (Expr.Etempvar _t'3 (tvolatile tuchar)) tulong)
                            (Expr.Econst_int (Integers.Int.repr 8) tint)
                            tulong) tulong)))
                    Stmt.Sskip)
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                        (Expr.Etempvar ___a64_str_width tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                        tint)
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sset _t'17
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                                (Ty.Tstruct _kprog_arm64_memory noattr)) _b
                              (tptr (tvolatile tuchar))))
                          (Stmt.Sbuiltin (some _t'4)
                            (ExtFun.EF_vload Chunk.Mint8unsigned)
                            [(tptr (tvolatile tuchar))]
                            [(Expr.Eaddrof
                               (Expr.Ederef
                                 (Expr.Ebinop Binop.Oadd
                                   (Expr.Etempvar _t'17 (tptr (tvolatile tuchar)))
                                   (Expr.Ebinop Binop.Oadd
                                     (Expr.Etempvar ___a64_str_index tulong)
                                     (Expr.Econst_int (Integers.Int.repr 2) tint)
                                     tulong) (tptr (tvolatile tuchar)))
                                 (tvolatile tuchar))
                               (tptr (tvolatile tuchar)))]))
                        (Stmt.Sset ___a64_str_value
                          (Expr.Ebinop Binop.Oor
                            (Expr.Etempvar ___a64_str_value tulong)
                            (Expr.Ebinop Binop.Oshl
                              (Expr.Ecast
                                (Expr.Etempvar _t'4 (tvolatile tuchar))
                                tulong)
                              (Expr.Econst_int (Integers.Int.repr 16) tint)
                              tulong) tulong)))
                      Stmt.Sskip)
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                          (Expr.Etempvar ___a64_str_width tuchar)
                                          (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                          tint)
                        (Stmt.Ssequence
                          s_kprog_arm64_stack_read_owned_0
                          (Stmt.Sset ___a64_str_value
                            (Expr.Ebinop Binop.Oor
                              (Expr.Etempvar ___a64_str_value tulong)
                              (Expr.Ebinop Binop.Oshl
                                (Expr.Ecast
                                  (Expr.Etempvar _t'5 (tvolatile tuchar))
                                  tulong)
                                (Expr.Econst_int (Integers.Int.repr 24) tint)
                                tulong) tulong)))
                        Stmt.Sskip)
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                            (Expr.Etempvar ___a64_str_width tuchar)
                                            (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                            tint)
                          (Stmt.Ssequence
                            s_kprog_arm64_stack_read_owned_1
                            (Stmt.Sset ___a64_str_value
                              (Expr.Ebinop Binop.Oor
                                (Expr.Etempvar ___a64_str_value tulong)
                                (Expr.Ebinop Binop.Oshl
                                  (Expr.Ecast
                                    (Expr.Etempvar _t'6 (tvolatile tuchar))
                                    tulong)
                                  (Expr.Econst_int (Integers.Int.repr 32) tint)
                                  tulong) tulong)))
                          Stmt.Sskip)
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                              (Expr.Etempvar ___a64_str_width tuchar)
                                              (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                              tint)
                            s_kprog_arm64_stack_read_owned_2
                            Stmt.Sskip)
                          (Stmt.Ssequence
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                                (Expr.Etempvar ___a64_str_width tuchar)
                                                (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                                tint)
                              s_kprog_arm64_stack_read_owned_3
                              Stmt.Sskip)
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                                (Expr.Etempvar ___a64_str_width tuchar)
                                                (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                                tint)
                              s_kprog_arm64_stack_read_owned_4
                              Stmt.Sskip))))))))))
          (Stmt.Sset _result (Expr.Etempvar ___a64_str_value tulong)))))
    Stmt.Sbreak)
  (Stmt.Sreturn (some (Expr.Etempvar _result tulong))))
}

@[noinline] def s_kprog_arm64_stack_read_0 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'22
    (Expr.Efield
      (Expr.Ederef
        (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
        (Ty.Tstruct _kprog_arm64_memory noattr)) _b
      (tptr (tvolatile tuchar))))
  (Stmt.Sbuiltin (some _t'3) (ExtFun.EF_vload Chunk.Mint8unsigned)
    [(tptr (tvolatile tuchar))]
    [(Expr.Eaddrof
       (Expr.Ederef
         (Expr.Ebinop Binop.Oadd
           (Expr.Etempvar _t'22 (tptr (tvolatile tuchar)))
           (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___a64_str_index tulong)
             (Expr.Econst_int (Integers.Int.repr 1) tint) tulong)
           (tptr (tvolatile tuchar))) (tvolatile tuchar))
       (tptr (tvolatile tuchar)))]))

@[noinline] def s_kprog_arm64_stack_read_1 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'21
    (Expr.Efield
      (Expr.Ederef
        (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
        (Ty.Tstruct _kprog_arm64_memory noattr)) _b
      (tptr (tvolatile tuchar))))
  (Stmt.Sbuiltin (some _t'4) (ExtFun.EF_vload Chunk.Mint8unsigned)
    [(tptr (tvolatile tuchar))]
    [(Expr.Eaddrof
       (Expr.Ederef
         (Expr.Ebinop Binop.Oadd
           (Expr.Etempvar _t'21 (tptr (tvolatile tuchar)))
           (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___a64_str_index tulong)
             (Expr.Econst_int (Integers.Int.repr 2) tint) tulong)
           (tptr (tvolatile tuchar))) (tvolatile tuchar))
       (tptr (tvolatile tuchar)))]))

@[noinline] def s_kprog_arm64_stack_read_2 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'20
      (Expr.Efield
        (Expr.Ederef
          (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
          (Ty.Tstruct _kprog_arm64_memory noattr)) _b
        (tptr (tvolatile tuchar))))
    (Stmt.Sbuiltin (some _t'5) (ExtFun.EF_vload Chunk.Mint8unsigned)
      [(tptr (tvolatile tuchar))]
      [(Expr.Eaddrof
         (Expr.Ederef
           (Expr.Ebinop Binop.Oadd
             (Expr.Etempvar _t'20 (tptr (tvolatile tuchar)))
             (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___a64_str_index tulong)
               (Expr.Econst_int (Integers.Int.repr 3) tint) tulong)
             (tptr (tvolatile tuchar))) (tvolatile tuchar))
         (tptr (tvolatile tuchar)))]))
  (Stmt.Sset ___a64_str_value
    (Expr.Ebinop Binop.Oor (Expr.Etempvar ___a64_str_value tulong)
      (Expr.Ebinop Binop.Oshl
        (Expr.Ecast (Expr.Etempvar _t'5 (tvolatile tuchar)) tulong)
        (Expr.Econst_int (Integers.Int.repr 24) tint) tulong) tulong)))

@[noinline] def s_kprog_arm64_stack_read_3 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'19
      (Expr.Efield
        (Expr.Ederef
          (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
          (Ty.Tstruct _kprog_arm64_memory noattr)) _b
        (tptr (tvolatile tuchar))))
    (Stmt.Sbuiltin (some _t'6) (ExtFun.EF_vload Chunk.Mint8unsigned)
      [(tptr (tvolatile tuchar))]
      [(Expr.Eaddrof
         (Expr.Ederef
           (Expr.Ebinop Binop.Oadd
             (Expr.Etempvar _t'19 (tptr (tvolatile tuchar)))
             (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___a64_str_index tulong)
               (Expr.Econst_int (Integers.Int.repr 4) tint) tulong)
             (tptr (tvolatile tuchar))) (tvolatile tuchar))
         (tptr (tvolatile tuchar)))]))
  (Stmt.Sset ___a64_str_value
    (Expr.Ebinop Binop.Oor (Expr.Etempvar ___a64_str_value tulong)
      (Expr.Ebinop Binop.Oshl
        (Expr.Ecast (Expr.Etempvar _t'6 (tvolatile tuchar)) tulong)
        (Expr.Econst_int (Integers.Int.repr 32) tint) tulong) tulong)))

@[noinline] def s_kprog_arm64_stack_read_4 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                    (Expr.Etempvar ___a64_str_width tuchar)
                    (Expr.Econst_int (Integers.Int.repr 8) tuint) tint)
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sset _t'18
        (Expr.Efield
          (Expr.Ederef
            (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
            (Ty.Tstruct _kprog_arm64_memory noattr)) _b
          (tptr (tvolatile tuchar))))
      (Stmt.Sbuiltin (some _t'7) (ExtFun.EF_vload Chunk.Mint8unsigned)
        [(tptr (tvolatile tuchar))]
        [(Expr.Eaddrof
           (Expr.Ederef
             (Expr.Ebinop Binop.Oadd
               (Expr.Etempvar _t'18 (tptr (tvolatile tuchar)))
               (Expr.Ebinop Binop.Oadd
                 (Expr.Etempvar ___a64_str_index tulong)
                 (Expr.Econst_int (Integers.Int.repr 5) tint) tulong)
               (tptr (tvolatile tuchar))) (tvolatile tuchar))
           (tptr (tvolatile tuchar)))]))
    (Stmt.Sset ___a64_str_value
      (Expr.Ebinop Binop.Oor (Expr.Etempvar ___a64_str_value tulong)
        (Expr.Ebinop Binop.Oshl
          (Expr.Ecast (Expr.Etempvar _t'7 (tvolatile tuchar)) tulong)
          (Expr.Econst_int (Integers.Int.repr 40) tint) tulong) tulong)))
  Stmt.Sskip)

@[noinline] def s_kprog_arm64_stack_read_5 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                      (Expr.Etempvar ___a64_str_width tuchar)
                      (Expr.Econst_int (Integers.Int.repr 8) tuint) tint)
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sset _t'17
          (Expr.Efield
            (Expr.Ederef
              (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
              (Ty.Tstruct _kprog_arm64_memory noattr)) _b
            (tptr (tvolatile tuchar))))
        (Stmt.Sbuiltin (some _t'8) (ExtFun.EF_vload Chunk.Mint8unsigned)
          [(tptr (tvolatile tuchar))]
          [(Expr.Eaddrof
             (Expr.Ederef
               (Expr.Ebinop Binop.Oadd
                 (Expr.Etempvar _t'17 (tptr (tvolatile tuchar)))
                 (Expr.Ebinop Binop.Oadd
                   (Expr.Etempvar ___a64_str_index tulong)
                   (Expr.Econst_int (Integers.Int.repr 6) tint) tulong)
                 (tptr (tvolatile tuchar))) (tvolatile tuchar))
             (tptr (tvolatile tuchar)))]))
      (Stmt.Sset ___a64_str_value
        (Expr.Ebinop Binop.Oor (Expr.Etempvar ___a64_str_value tulong)
          (Expr.Ebinop Binop.Oshl
            (Expr.Ecast (Expr.Etempvar _t'8 (tvolatile tuchar)) tulong)
            (Expr.Econst_int (Integers.Int.repr 48) tint) tulong) tulong)))
    Stmt.Sskip)
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                      (Expr.Etempvar ___a64_str_width tuchar)
                      (Expr.Econst_int (Integers.Int.repr 8) tuint) tint)
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sset _t'16
          (Expr.Efield
            (Expr.Ederef
              (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
              (Ty.Tstruct _kprog_arm64_memory noattr)) _b
            (tptr (tvolatile tuchar))))
        (Stmt.Sbuiltin (some _t'9) (ExtFun.EF_vload Chunk.Mint8unsigned)
          [(tptr (tvolatile tuchar))]
          [(Expr.Eaddrof
             (Expr.Ederef
               (Expr.Ebinop Binop.Oadd
                 (Expr.Etempvar _t'16 (tptr (tvolatile tuchar)))
                 (Expr.Ebinop Binop.Oadd
                   (Expr.Etempvar ___a64_str_index tulong)
                   (Expr.Econst_int (Integers.Int.repr 7) tint) tulong)
                 (tptr (tvolatile tuchar))) (tvolatile tuchar))
             (tptr (tvolatile tuchar)))]))
      (Stmt.Sset ___a64_str_value
        (Expr.Ebinop Binop.Oor (Expr.Etempvar ___a64_str_value tulong)
          (Expr.Ebinop Binop.Oshl
            (Expr.Ecast (Expr.Etempvar _t'9 (tvolatile tuchar)) tulong)
            (Expr.Econst_int (Integers.Int.repr 56) tint) tulong) tulong)))
    Stmt.Sskip))

@[noinline] def s_kprog_arm64_stack_read_6 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'13
    (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 4294967295) tulong)
      tulong))
  (Stmt.Sset _t'13 (Expr.Ecast (Expr.Etempvar _t'13 tulong) tulong)))

@[noinline] def s_kprog_arm64_stack_read_7 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'13
    (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr (-1)) tulong) tulong))
  (Stmt.Sset _t'13 (Expr.Ecast (Expr.Etempvar _t'13 tulong) tulong)))

def f_kprog_arm64_stack_read : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_memory, (tptr (Ty.Tstruct _kprog_arm64_memory noattr))),
                (_off, tlong), (_width, tuchar)],
  fn_vars := [],
  fn_temps := [(_result, tulong), (___a64_observed, tulong),
               (___a64_str_index, tulong), (___a64_str_width, tuchar),
               (___a64_str_value, tulong), (_t'13, tulong), (_t'12, tulong),
               (_t'11, tint), (_t'10, tint), (_t'9, (tvolatile tuchar)),
               (_t'8, (tvolatile tuchar)), (_t'7, (tvolatile tuchar)),
               (_t'6, (tvolatile tuchar)), (_t'5, (tvolatile tuchar)),
               (_t'4, (tvolatile tuchar)), (_t'3, (tvolatile tuchar)),
               (_t'2, (tvolatile tuchar)), (_t'1, (tvolatile tulong)),
               (_t'25, tlong), (_t'24, (tptr (tvolatile tulong))),
               (_t'23, (tptr (tvolatile tuchar))),
               (_t'22, (tptr (tvolatile tuchar))),
               (_t'21, (tptr (tvolatile tuchar))),
               (_t'20, (tptr (tvolatile tuchar))),
               (_t'19, (tptr (tvolatile tuchar))),
               (_t'18, (tptr (tvolatile tuchar))),
               (_t'17, (tptr (tvolatile tuchar))),
               (_t'16, (tptr (tvolatile tuchar))), (_t'15, tlong),
               (_t'14, (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sloop
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sset _t'25
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                  (Ty.Tstruct _kprog_arm64_memory noattr)) _bias tlong))
            (Stmt.Sset ___a64_str_index
              (Expr.Ebinop Binop.Oadd
                (Expr.Ecast (Expr.Etempvar _t'25 tlong) tulong)
                (Expr.Ecast (Expr.Etempvar _off tlong) tulong) tulong)))
          (Stmt.Ssequence
            (Stmt.Sset ___a64_str_width
              (Expr.Ecast (Expr.Etempvar _width tuchar) tuchar))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar ___a64_str_width tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                      tint)
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Ebinop Binop.Oand
                                          (Expr.Ecast
                                            (Expr.Etempvar ___a64_str_index tulong)
                                            tuint)
                                          (Expr.Econst_int (Integers.Int.repr 7) tuint)
                                          tuint)
                                        (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                        tint)
                      (Stmt.Ssequence
                        (Stmt.Sset _t'10
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 1) tint)
                            tint))
                        (Stmt.Sset _t'10
                          (Expr.Ecast (Expr.Etempvar _t'10 tint) tbool)))
                      (Stmt.Ssequence
                        (Stmt.Sset _t'10
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                            tint))
                        (Stmt.Sset _t'10
                          (Expr.Ecast (Expr.Etempvar _t'10 tint) tbool))))
                    (Stmt.Sset _t'10
                      (Expr.Econst_int (Integers.Int.repr 0) tint)))
                  (Stmt.Sifthenelse (Expr.Etempvar _t'10 tint)
                    (Stmt.Sset _t'11
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 1) tint) tint))
                    (Stmt.Sset _t'11
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 0) tint) tint))))
                (Stmt.Sifthenelse (Expr.Ecast (Expr.Etempvar _t'11 tint)
                                    tuchar)
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sset _t'24
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                            (Ty.Tstruct _kprog_arm64_memory noattr)) _q
                          (tptr (tvolatile tulong))))
                      (Stmt.Sbuiltin (some _t'1)
                        (ExtFun.EF_vload Chunk.Mint64)
                        [(tptr (tvolatile tulong))]
                        [(Expr.Eaddrof
                           (Expr.Ederef
                             (Expr.Ebinop Binop.Oadd
                               (Expr.Etempvar _t'24 (tptr (tvolatile tulong)))
                               (Expr.Ebinop Binop.Oshr
                                 (Expr.Ecast
                                   (Expr.Etempvar ___a64_str_index tulong)
                                   tulong)
                                 (Expr.Econst_int (Integers.Int.repr 3) tint)
                                 tulong) (tptr (tvolatile tulong)))
                             (tvolatile tulong)) (tptr (tvolatile tulong)))]))
                    (Stmt.Sset ___a64_str_value
                      (Expr.Etempvar _t'1 (tvolatile tulong))))
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sset _t'23
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                              (Ty.Tstruct _kprog_arm64_memory noattr)) _b
                            (tptr (tvolatile tuchar))))
                        (Stmt.Sbuiltin (some _t'2)
                          (ExtFun.EF_vload Chunk.Mint8unsigned)
                          [(tptr (tvolatile tuchar))]
                          [(Expr.Eaddrof
                             (Expr.Ederef
                               (Expr.Ebinop Binop.Oadd
                                 (Expr.Etempvar _t'23 (tptr (tvolatile tuchar)))
                                 (Expr.Etempvar ___a64_str_index tulong)
                                 (tptr (tvolatile tuchar)))
                               (tvolatile tuchar)) (tptr (tvolatile tuchar)))]))
                      (Stmt.Sset ___a64_str_value
                        (Expr.Ecast (Expr.Etempvar _t'2 (tvolatile tuchar))
                          tulong)))
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                          (Expr.Etempvar ___a64_str_width tuchar)
                                          (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                          tint)
                        (Stmt.Ssequence
                          s_kprog_arm64_stack_read_0
                          (Stmt.Sset ___a64_str_value
                            (Expr.Ebinop Binop.Oor
                              (Expr.Etempvar ___a64_str_value tulong)
                              (Expr.Ebinop Binop.Oshl
                                (Expr.Ecast
                                  (Expr.Etempvar _t'3 (tvolatile tuchar))
                                  tulong)
                                (Expr.Econst_int (Integers.Int.repr 8) tint)
                                tulong) tulong)))
                        Stmt.Sskip)
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                            (Expr.Etempvar ___a64_str_width tuchar)
                                            (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                            tint)
                          (Stmt.Ssequence
                            s_kprog_arm64_stack_read_1
                            (Stmt.Sset ___a64_str_value
                              (Expr.Ebinop Binop.Oor
                                (Expr.Etempvar ___a64_str_value tulong)
                                (Expr.Ebinop Binop.Oshl
                                  (Expr.Ecast
                                    (Expr.Etempvar _t'4 (tvolatile tuchar))
                                    tulong)
                                  (Expr.Econst_int (Integers.Int.repr 16) tint)
                                  tulong) tulong)))
                          Stmt.Sskip)
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                              (Expr.Etempvar ___a64_str_width tuchar)
                                              (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                              tint)
                            s_kprog_arm64_stack_read_2
                            Stmt.Sskip)
                          (Stmt.Ssequence
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                                (Expr.Etempvar ___a64_str_width tuchar)
                                                (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                                tint)
                              s_kprog_arm64_stack_read_3
                              Stmt.Sskip)
                            (Stmt.Ssequence
                              s_kprog_arm64_stack_read_4
                              s_kprog_arm64_stack_read_5))))))))
              (Stmt.Sset ___a64_observed
                (Expr.Etempvar ___a64_str_value tulong)))))
        Stmt.Sbreak)
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sset _t'14
            (Expr.Efield
              (Expr.Ederef
                (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                (Ty.Tstruct _kprog_arm64_memory noattr)) _coordinates
              (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))))
          (Stmt.Ssequence
            (Stmt.Sset _t'15
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar _t'14 (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                  (Ty.Tstruct _kprog_arm64_coordinates noattr)) _stack_offset
                tlong))
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                (Expr.Ecast (Expr.Etempvar _off tlong) tlong)
                                (Expr.Etempvar _t'15 tlong) tint)
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Scall (some _t'12)
                    (Expr.Evar _native_lab_entry_input (Ty.Tfunction 
                                                         [tuint] tulong
                                                         cc_default))
                    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar _width tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                      tint)
                    (Stmt.Sset _t'13
                      (Expr.Ecast
                        (Expr.Econst_long (Integers.Int64.repr 255) tulong)
                        tulong))
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Etempvar _width tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                        tint)
                      (Stmt.Ssequence
                        (Stmt.Sset _t'13
                          (Expr.Ecast
                            (Expr.Econst_long (Integers.Int64.repr 65535) tulong)
                            tulong))
                        (Stmt.Sset _t'13
                          (Expr.Ecast (Expr.Etempvar _t'13 tulong) tulong)))
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Etempvar _width tuchar)
                                          (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                          tint)
                        (Stmt.Ssequence
                          s_kprog_arm64_stack_read_6
                          (Stmt.Sset _t'13
                            (Expr.Ecast (Expr.Etempvar _t'13 tulong) tulong)))
                        (Stmt.Ssequence
                          s_kprog_arm64_stack_read_7
                          (Stmt.Sset _t'13
                            (Expr.Ecast (Expr.Etempvar _t'13 tulong) tulong)))))))
                (Stmt.Sset ___a64_observed
                  (Expr.Ebinop Binop.Oand (Expr.Etempvar _t'12 tulong)
                    (Expr.Etempvar _t'13 tulong) tulong)))
              Stmt.Sskip)))
        (Stmt.Sset _result (Expr.Etempvar ___a64_observed tulong))))
    Stmt.Sbreak)
  (Stmt.Sreturn (some (Expr.Etempvar _result tulong))))
}

def f_kprog_arm64_stack_read_tag : Function := {
  fn_return := tuchar,
  fn_callconv := cc_default,
  fn_params := [(_memory, (tptr (Ty.Tstruct _kprog_arm64_memory noattr))),
                (_off, tlong), (_width, tuchar)],
  fn_vars := [],
  fn_temps := [(_result, tuchar), (___a64_srt_index, tulong),
               (___a64_srt_width, tuchar), (___a64_srt_source, tuchar),
               (___a64_srt_tag, tuchar), (___ti, tulong), (_t'4, tint),
               (_t'3, (tvolatile tulong)), (_t'2, tuint), (_t'1, tint),
               (_t'8, tlong), (_t'7, tlong),
               (_t'6, (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))),
               (_t'5, (tptr tuchar))],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sset _t'8
          (Expr.Efield
            (Expr.Ederef
              (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
              (Ty.Tstruct _kprog_arm64_memory noattr)) _bias tlong))
        (Stmt.Sset ___a64_srt_index
          (Expr.Ebinop Binop.Oadd
            (Expr.Ecast (Expr.Etempvar _t'8 tlong) tulong)
            (Expr.Ecast (Expr.Etempvar _off tlong) tulong) tulong)))
      (Stmt.Ssequence
        (Stmt.Sset ___a64_srt_width
          (Expr.Ecast (Expr.Etempvar _width tuchar) tuchar))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar ___a64_srt_width tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                  tint)
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Ebinop Binop.Oand
                                      (Expr.Ecast
                                        (Expr.Etempvar ___a64_srt_index tulong)
                                        tuint)
                                      (Expr.Econst_int (Integers.Int.repr 7) tuint)
                                      tuint)
                                    (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                    tint)
                  (Stmt.Ssequence
                    (Stmt.Sset _t'1
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 1) tint) tint))
                    (Stmt.Sset _t'1
                      (Expr.Ecast (Expr.Etempvar _t'1 tint) tbool)))
                  (Stmt.Ssequence
                    (Stmt.Sset _t'1
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 0) tint) tint))
                    (Stmt.Sset _t'1
                      (Expr.Ecast (Expr.Etempvar _t'1 tint) tbool))))
                (Stmt.Sset _t'1 (Expr.Econst_int (Integers.Int.repr 0) tint)))
              (Stmt.Sifthenelse (Expr.Etempvar _t'1 tint)
                (Stmt.Sset _t'2
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                    tuint))
                (Stmt.Sset _t'2
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint)
                    tuint))))
            (Stmt.Sset ___a64_srt_source
              (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'2 tuint) tuchar)
                tuchar)))
          (Stmt.Ssequence
            (Stmt.Sset ___a64_srt_tag
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                tuchar))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sset _t'6
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                        (Ty.Tstruct _kprog_arm64_memory noattr)) _coordinates
                      (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))))
                  (Stmt.Ssequence
                    (Stmt.Sset _t'7
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar _t'6 (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                          (Ty.Tstruct _kprog_arm64_coordinates noattr))
                        _stack_offset tlong))
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                        (Expr.Ecast
                                          (Expr.Etempvar _off tlong) tlong)
                                        (Expr.Etempvar _t'7 tlong) tint)
                      (Stmt.Sset _t'4
                        (Expr.Ecast
                          (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar ___a64_srt_source tuchar)
                            (Expr.Econst_int (Integers.Int.repr 0) tuint)
                            tint) tbool))
                      (Stmt.Sset _t'4
                        (Expr.Econst_int (Integers.Int.repr 0) tint)))))
                (Stmt.Sifthenelse (Expr.Etempvar _t'4 tint)
                  (Stmt.Sloop
                    (Stmt.Ssequence
                      (Stmt.Sset ___ti
                        (Expr.Ebinop Binop.Oshr
                          (Expr.Ecast (Expr.Etempvar ___a64_srt_index tulong)
                            tulong)
                          (Expr.Econst_int (Integers.Int.repr 3) tint)
                          tulong))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sset _t'5
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                                (Ty.Tstruct _kprog_arm64_memory noattr))
                              _tags (tptr tuchar)))
                          (Stmt.Sbuiltin (some _t'3)
                            (ExtFun.EF_vload Chunk.Mint64)
                            [(tptr (tvolatile tulong))]
                            [(Expr.Eaddrof
                               (Expr.Ederef
                                 (Expr.Ecast
                                   (Expr.Ecast
                                     (Expr.Ebinop Binop.Oadd
                                       (Expr.Etempvar _t'5 (tptr tuchar))
                                       (Expr.Ebinop Binop.Oand
                                         (Expr.Ecast
                                           (Expr.Etempvar ___ti tulong)
                                           tulong)
                                         (Expr.Eunop Unop.Onotint
                                           (Expr.Econst_long (Integers.Int64.repr 7) tulong)
                                           tulong) tulong) (tptr tuchar))
                                     (tptr tvoid)) (tptr (tvolatile tulong)))
                                 (tvolatile tulong))
                               (tptr (tvolatile tulong)))]))
                        (Stmt.Sset ___a64_srt_tag
                          (Expr.Ecast
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Oshr
                                (Expr.Etempvar _t'3 (tvolatile tulong))
                                (Expr.Ebinop Binop.Omul
                                  (Expr.Ebinop Binop.Oand
                                    (Expr.Etempvar ___ti tulong)
                                    (Expr.Econst_int (Integers.Int.repr 7) tuint)
                                    tulong)
                                  (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                  tulong) tulong) tuchar) tuchar))))
                    Stmt.Sbreak)
                  Stmt.Sskip))
              (Stmt.Sset _result
                (Expr.Ecast (Expr.Etempvar ___a64_srt_tag tuchar) tuchar)))))))
    Stmt.Sbreak)
  (Stmt.Sreturn (some (Expr.Etempvar _result tuchar))))
}

@[noinline] def s_kprog_arm64_stack_write_owned_0 : Stmt :=
(Stmt.Sset ___a64_unmat_tag (Expr.Ecast (Expr.Etempvar _tag tuchar) tuchar))

@[noinline] def s_kprog_arm64_stack_write_owned_1 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Etempvar ___a64_unmat_tag tuchar)
                      (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
    (Stmt.Ssequence
      (Stmt.Sloop
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sset _t'37
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                  (Ty.Tstruct _kprog_arm64_memory noattr)) _coordinates
                (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))))
            (Stmt.Ssequence
              (Stmt.Sset _t'38
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Etempvar _t'37 (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                    (Ty.Tstruct _kprog_arm64_coordinates noattr)) _sp_valid
                  tuchar))
              (Stmt.Sifthenelse (Expr.Eunop Unop.Onotbool
                                  (Expr.Etempvar _t'38 tuchar) tint)
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Scall (some _t'5)
                      (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                           [tuint] tulong
                                                           cc_default))
                      [(Expr.Econst_int (Integers.Int.repr 1) tint)])
                    (Stmt.Ssequence
                      (Stmt.Sset _t'40
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                            (Ty.Tstruct _kprog_arm64_memory noattr))
                          _coordinates
                          (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))))
                      (Stmt.Sassign
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar _t'40 (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                            (Ty.Tstruct _kprog_arm64_coordinates noattr))
                          _sp_base tulong) (Expr.Etempvar _t'5 tulong))))
                  (Stmt.Ssequence
                    (Stmt.Sset _t'39
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                          (Ty.Tstruct _kprog_arm64_memory noattr))
                        _coordinates
                        (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))))
                    (Stmt.Sassign
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar _t'39 (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                          (Ty.Tstruct _kprog_arm64_coordinates noattr))
                        _sp_valid tuchar)
                      (Expr.Econst_int (Integers.Int.repr 1) tint))))
                Stmt.Sskip)))
          (Stmt.Ssequence
            (Stmt.Sset _t'36
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                  (Ty.Tstruct _kprog_arm64_memory noattr)) _coordinates
                (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))))
            (Stmt.Sset ___a64_unmat_base
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar _t'36 (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                  (Ty.Tstruct _kprog_arm64_coordinates noattr)) _sp_base
                tulong))))
        Stmt.Sbreak)
      (Stmt.Sset ___a64_unmat_value
        (Expr.Ebinop Binop.Osub (Expr.Etempvar ___a64_unmat_value tulong)
          (Expr.Etempvar ___a64_unmat_base tulong) tulong)))
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                        (Expr.Etempvar ___a64_unmat_tag tuchar)
                        (Expr.Econst_int (Integers.Int.repr 10) tuint) tint)
      (Stmt.Ssequence
        (Stmt.Sloop
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sset _t'32
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                    (Ty.Tstruct _kprog_arm64_memory noattr)) _coordinates
                  (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))))
              (Stmt.Ssequence
                (Stmt.Sset _t'33
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Etempvar _t'32 (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                      (Ty.Tstruct _kprog_arm64_coordinates noattr))
                    _return_valid tuchar))
                (Stmt.Sifthenelse (Expr.Eunop Unop.Onotbool
                                    (Expr.Etempvar _t'33 tuchar) tint)
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Scall (some _t'6)
                        (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                             [tuint] tulong
                                                             cc_default))
                        [(Expr.Econst_int (Integers.Int.repr 3) tint)])
                      (Stmt.Ssequence
                        (Stmt.Sset _t'35
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                              (Ty.Tstruct _kprog_arm64_memory noattr))
                            _coordinates
                            (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))))
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar _t'35 (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                              (Ty.Tstruct _kprog_arm64_coordinates noattr))
                            _return_base tulong) (Expr.Etempvar _t'6 tulong))))
                    (Stmt.Ssequence
                      (Stmt.Sset _t'34
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                            (Ty.Tstruct _kprog_arm64_memory noattr))
                          _coordinates
                          (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))))
                      (Stmt.Sassign
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar _t'34 (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                            (Ty.Tstruct _kprog_arm64_coordinates noattr))
                          _return_valid tuchar)
                        (Expr.Econst_int (Integers.Int.repr 1) tint))))
                  Stmt.Sskip)))
            (Stmt.Ssequence
              (Stmt.Sset _t'31
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                    (Ty.Tstruct _kprog_arm64_memory noattr)) _coordinates
                  (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))))
              (Stmt.Sset ___a64_unmat_base__1
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Etempvar _t'31 (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                    (Ty.Tstruct _kprog_arm64_coordinates noattr))
                  _return_base tulong))))
          Stmt.Sbreak)
        (Stmt.Sset ___a64_unmat_value
          (Expr.Ebinop Binop.Osub (Expr.Etempvar ___a64_unmat_value tulong)
            (Expr.Etempvar ___a64_unmat_base__1 tulong) tulong)))
      Stmt.Sskip))
  (Stmt.Sset ___a64_stw_payload (Expr.Etempvar ___a64_unmat_value tulong)))

@[noinline] def s_kprog_arm64_stack_write_owned_2 : Stmt :=
(Stmt.Sbuiltin (some _t'8) (ExtFun.EF_vload Chunk.Mint64)
  [(tptr (tvolatile tulong))]
  [(Expr.Eaddrof
     (Expr.Ederef (Expr.Etempvar ___tp (tptr (tvolatile tulong)))
       (tvolatile tulong)) (tptr (tvolatile tulong)))])

@[noinline] def s_kprog_arm64_stack_write_owned_3 : Stmt :=
(Stmt.Sset _t'10
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint) tuint))

@[noinline] def s_kprog_arm64_stack_write_owned_4 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'10
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 4) tuint) tuint))
    (Stmt.Sset _t'10 (Expr.Ecast (Expr.Etempvar _t'10 tuint) tuint)))
  (Stmt.Sset _t'10 (Expr.Ecast (Expr.Etempvar _t'10 tuint) tuint)))

@[noinline] def s_kprog_arm64_stack_write_owned_5 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'10
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint))
    (Stmt.Sset _t'10 (Expr.Ecast (Expr.Etempvar _t'10 tuint) tuint)))
  (Stmt.Sset _t'10 (Expr.Ecast (Expr.Etempvar _t'10 tuint) tuint)))

@[noinline] def s_kprog_arm64_stack_write_owned_6 : Stmt :=
(Stmt.Sset ___ts__2
  (Expr.Ecast
    (Expr.Ebinop Binop.Omul
      (Expr.Ebinop Binop.Oand (Expr.Etempvar ___ti__2 tulong)
        (Expr.Econst_int (Integers.Int.repr 7) tuint) tulong)
      (Expr.Econst_int (Integers.Int.repr 8) tuint) tulong) tuint))

@[noinline] def s_kprog_arm64_stack_write_owned_7 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'27
      (Expr.Efield
        (Expr.Ederef
          (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
          (Ty.Tstruct _kprog_arm64_memory noattr)) _tags (tptr tuchar)))
    (Stmt.Sset ___tp__2
      (Expr.Ecast
        (Expr.Ecast
          (Expr.Ebinop Binop.Oadd (Expr.Etempvar _t'27 (tptr tuchar))
            (Expr.Ebinop Binop.Oand
              (Expr.Ecast (Expr.Etempvar ___ti__2 tulong) tulong)
              (Expr.Eunop Unop.Onotint
                (Expr.Econst_long (Integers.Int64.repr 7) tulong) tulong)
              tulong) (tptr tuchar)) (tptr tvoid)) (tptr (tvolatile tulong)))))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sbuiltin (some _t'11) (ExtFun.EF_vload Chunk.Mint64)
        [(tptr (tvolatile tulong))]
        [(Expr.Eaddrof
           (Expr.Ederef (Expr.Etempvar ___tp__2 (tptr (tvolatile tulong)))
             (tvolatile tulong)) (tptr (tvolatile tulong)))])
      (Stmt.Sset ___tv__2 (Expr.Etempvar _t'11 (tvolatile tulong))))
    (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
      [(tptr (tvolatile tulong)), (tvolatile tulong)]
      [(Expr.Eaddrof
         (Expr.Ederef (Expr.Etempvar ___tp__2 (tptr (tvolatile tulong)))
           (tvolatile tulong)) (tptr (tvolatile tulong))),
       (Expr.Ebinop Binop.Oor
         (Expr.Ebinop Binop.Oand (Expr.Etempvar ___tv__2 tulong)
           (Expr.Eunop Unop.Onotint
             (Expr.Ebinop Binop.Oshl
               (Expr.Econst_long (Integers.Int64.repr 255) tulong)
               (Expr.Etempvar ___ts__2 tuint) tulong) tulong) tulong)
         (Expr.Ebinop Binop.Oshl
           (Expr.Ecast
             (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
               tuchar) tulong) (Expr.Etempvar ___ts__2 tuint) tulong) tulong)])))

@[noinline] def s_kprog_arm64_stack_write_owned_8 : Stmt :=
(Stmt.Sset ___kprog_a64_bl_shift
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) tulong))

@[noinline] def s_kprog_arm64_stack_write_owned_9 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sswitch (Expr.Etempvar ___kprog_a64_bl_lane tulong)
    (LStmts.LScons (some 0)
      (Stmt.Ssequence
        (Stmt.Sset ___kprog_a64_bl_shift
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) tulong))
        Stmt.Sbreak)
      (LStmts.LScons (some 1)
        (Stmt.Ssequence
          (Stmt.Sset ___kprog_a64_bl_shift
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tint) tulong))
          Stmt.Sbreak)
        (LStmts.LScons (some 2)
          (Stmt.Ssequence
            (Stmt.Sset ___kprog_a64_bl_shift
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 16) tint)
                tulong))
            Stmt.Sbreak)
          (LStmts.LScons (some 3)
            (Stmt.Ssequence
              (Stmt.Sset ___kprog_a64_bl_shift
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 24) tint)
                  tulong))
              Stmt.Sbreak)
            (LStmts.LScons (some 4)
              (Stmt.Ssequence
                (Stmt.Sset ___kprog_a64_bl_shift
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 32) tint)
                    tulong))
                Stmt.Sbreak)
              (LStmts.LScons (some 5)
                (Stmt.Ssequence
                  (Stmt.Sset ___kprog_a64_bl_shift
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 40) tint)
                      tulong))
                  Stmt.Sbreak)
                (LStmts.LScons (some 6)
                  (Stmt.Ssequence
                    (Stmt.Sset ___kprog_a64_bl_shift
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 48) tint) tulong))
                    Stmt.Sbreak)
                  (LStmts.LScons (some 7)
                    (Stmt.Ssequence
                      (Stmt.Sset ___kprog_a64_bl_shift
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 56) tint)
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
                      LStmts.LSnil))))))))))
  (Stmt.Ssequence
    (Stmt.Sset _t'26
      (Expr.Efield
        (Expr.Ederef
          (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
          (Ty.Tstruct _kprog_arm64_memory noattr)) _b
        (tptr (tvolatile tuchar))))
    (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
      [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
      [(Expr.Eaddrof
         (Expr.Ederef
           (Expr.Ebinop Binop.Oadd
             (Expr.Etempvar _t'26 (tptr (tvolatile tuchar)))
             (Expr.Etempvar ___a64_stw_index tulong)
             (tptr (tvolatile tuchar))) (tvolatile tuchar))
         (tptr (tvolatile tuchar))),
       (Expr.Ecast
         (Expr.Ebinop Binop.Oshr (Expr.Etempvar ___kprog_a64_bl_value tulong)
           (Expr.Etempvar ___kprog_a64_bl_shift tulong) tulong) tuchar)])))

@[noinline] def s_kprog_arm64_stack_write_owned_10 : Stmt :=
(Stmt.Sset _t'12
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))

@[noinline] def s_kprog_arm64_stack_write_owned_11 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                    (Expr.Etempvar ___a64_stw_width tuchar)
                    (Expr.Econst_int (Integers.Int.repr 2) tuint) tint)
  (Stmt.Ssequence
    (Stmt.Sset _t'12
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))
    (Stmt.Sset _t'12 (Expr.Ecast (Expr.Etempvar _t'12 tuint) tuint)))
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Etempvar ___a64_stw_width tuchar)
                      (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sset _t'12
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 15) tuint) tuint))
        (Stmt.Sset _t'12 (Expr.Ecast (Expr.Etempvar _t'12 tuint) tuint)))
      (Stmt.Sset _t'12 (Expr.Ecast (Expr.Etempvar _t'12 tuint) tuint)))
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sset _t'12
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 255) tuint) tuint))
        (Stmt.Sset _t'12 (Expr.Ecast (Expr.Etempvar _t'12 tuint) tuint)))
      (Stmt.Sset _t'12 (Expr.Ecast (Expr.Etempvar _t'12 tuint) tuint)))))

@[noinline] def s_kprog_arm64_stack_write_owned_12 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___kprog_a64_bl_lane__1
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tint) tulong))
  (Stmt.Ssequence
    (Stmt.Sset ___kprog_a64_bl_value__1
      (Expr.Etempvar ___a64_stw_value tulong))
    (Stmt.Ssequence
      (Stmt.Sset ___kprog_a64_bl_shift__1
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) tulong))
      (Stmt.Ssequence
        (Stmt.Sswitch (Expr.Etempvar ___kprog_a64_bl_lane__1 tulong)
          (LStmts.LScons (some 0)
            (Stmt.Ssequence
              (Stmt.Sset ___kprog_a64_bl_shift__1
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                  tulong))
              Stmt.Sbreak)
            (LStmts.LScons (some 1)
              (Stmt.Ssequence
                (Stmt.Sset ___kprog_a64_bl_shift__1
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tint)
                    tulong))
                Stmt.Sbreak)
              (LStmts.LScons (some 2)
                (Stmt.Ssequence
                  (Stmt.Sset ___kprog_a64_bl_shift__1
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 16) tint)
                      tulong))
                  Stmt.Sbreak)
                (LStmts.LScons (some 3)
                  (Stmt.Ssequence
                    (Stmt.Sset ___kprog_a64_bl_shift__1
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 24) tint) tulong))
                    Stmt.Sbreak)
                  (LStmts.LScons (some 4)
                    (Stmt.Ssequence
                      (Stmt.Sset ___kprog_a64_bl_shift__1
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 32) tint)
                          tulong))
                      Stmt.Sbreak)
                    (LStmts.LScons (some 5)
                      (Stmt.Ssequence
                        (Stmt.Sset ___kprog_a64_bl_shift__1
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 40) tint)
                            tulong))
                        Stmt.Sbreak)
                      (LStmts.LScons (some 6)
                        (Stmt.Ssequence
                          (Stmt.Sset ___kprog_a64_bl_shift__1
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 48) tint)
                              tulong))
                          Stmt.Sbreak)
                        (LStmts.LScons (some 7)
                          (Stmt.Ssequence
                            (Stmt.Sset ___kprog_a64_bl_shift__1
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 56) tint)
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
                            LStmts.LSnil))))))))))
        (Stmt.Ssequence
          (Stmt.Sset _t'25
            (Expr.Efield
              (Expr.Ederef
                (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                (Ty.Tstruct _kprog_arm64_memory noattr)) _b
              (tptr (tvolatile tuchar))))
          (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
            [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
            [(Expr.Eaddrof
               (Expr.Ederef
                 (Expr.Ebinop Binop.Oadd
                   (Expr.Etempvar _t'25 (tptr (tvolatile tuchar)))
                   (Expr.Ebinop Binop.Oadd
                     (Expr.Etempvar ___a64_stw_index tulong)
                     (Expr.Econst_int (Integers.Int.repr 1) tint) tulong)
                   (tptr (tvolatile tuchar))) (tvolatile tuchar))
               (tptr (tvolatile tuchar))),
             (Expr.Ecast
               (Expr.Ebinop Binop.Oshr
                 (Expr.Etempvar ___kprog_a64_bl_value__1 tulong)
                 (Expr.Etempvar ___kprog_a64_bl_shift__1 tulong) tulong)
               tuchar)]))))))

@[noinline] def s_kprog_arm64_stack_write_owned_13 : Stmt :=
Stmt.Sbreak

@[noinline] def s_kprog_arm64_stack_write_owned_14 : Stmt :=
(Stmt.Sset _t'13
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))

@[noinline] def s_kprog_arm64_stack_write_owned_15 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                    (Expr.Etempvar ___a64_stw_width tuchar)
                    (Expr.Econst_int (Integers.Int.repr 2) tuint) tint)
  (Stmt.Ssequence
    (Stmt.Sset _t'13
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))
    (Stmt.Sset _t'13 (Expr.Ecast (Expr.Etempvar _t'13 tuint) tuint)))
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Etempvar ___a64_stw_width tuchar)
                      (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sset _t'13
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 15) tuint) tuint))
        (Stmt.Sset _t'13 (Expr.Ecast (Expr.Etempvar _t'13 tuint) tuint)))
      (Stmt.Sset _t'13 (Expr.Ecast (Expr.Etempvar _t'13 tuint) tuint)))
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sset _t'13
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 255) tuint) tuint))
        (Stmt.Sset _t'13 (Expr.Ecast (Expr.Etempvar _t'13 tuint) tuint)))
      (Stmt.Sset _t'13 (Expr.Ecast (Expr.Etempvar _t'13 tuint) tuint)))))

@[noinline] def s_kprog_arm64_stack_write_owned_16 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___kprog_a64_bl_lane__2
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tint) tulong))
  (Stmt.Ssequence
    (Stmt.Sset ___kprog_a64_bl_value__2
      (Expr.Etempvar ___a64_stw_value tulong))
    (Stmt.Ssequence
      (Stmt.Sset ___kprog_a64_bl_shift__2
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) tulong))
      (Stmt.Ssequence
        (Stmt.Sswitch (Expr.Etempvar ___kprog_a64_bl_lane__2 tulong)
          (LStmts.LScons (some 0)
            (Stmt.Ssequence
              (Stmt.Sset ___kprog_a64_bl_shift__2
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                  tulong))
              Stmt.Sbreak)
            (LStmts.LScons (some 1)
              (Stmt.Ssequence
                (Stmt.Sset ___kprog_a64_bl_shift__2
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tint)
                    tulong))
                Stmt.Sbreak)
              (LStmts.LScons (some 2)
                (Stmt.Ssequence
                  (Stmt.Sset ___kprog_a64_bl_shift__2
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 16) tint)
                      tulong))
                  Stmt.Sbreak)
                (LStmts.LScons (some 3)
                  (Stmt.Ssequence
                    (Stmt.Sset ___kprog_a64_bl_shift__2
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 24) tint) tulong))
                    Stmt.Sbreak)
                  (LStmts.LScons (some 4)
                    (Stmt.Ssequence
                      (Stmt.Sset ___kprog_a64_bl_shift__2
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 32) tint)
                          tulong))
                      Stmt.Sbreak)
                    (LStmts.LScons (some 5)
                      (Stmt.Ssequence
                        (Stmt.Sset ___kprog_a64_bl_shift__2
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 40) tint)
                            tulong))
                        Stmt.Sbreak)
                      (LStmts.LScons (some 6)
                        (Stmt.Ssequence
                          (Stmt.Sset ___kprog_a64_bl_shift__2
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 48) tint)
                              tulong))
                          Stmt.Sbreak)
                        (LStmts.LScons (some 7)
                          (Stmt.Ssequence
                            (Stmt.Sset ___kprog_a64_bl_shift__2
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 56) tint)
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
                            LStmts.LSnil))))))))))
        (Stmt.Ssequence
          (Stmt.Sset _t'24
            (Expr.Efield
              (Expr.Ederef
                (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                (Ty.Tstruct _kprog_arm64_memory noattr)) _b
              (tptr (tvolatile tuchar))))
          (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
            [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
            [(Expr.Eaddrof
               (Expr.Ederef
                 (Expr.Ebinop Binop.Oadd
                   (Expr.Etempvar _t'24 (tptr (tvolatile tuchar)))
                   (Expr.Ebinop Binop.Oadd
                     (Expr.Etempvar ___a64_stw_index tulong)
                     (Expr.Econst_int (Integers.Int.repr 2) tint) tulong)
                   (tptr (tvolatile tuchar))) (tvolatile tuchar))
               (tptr (tvolatile tuchar))),
             (Expr.Ecast
               (Expr.Ebinop Binop.Oshr
                 (Expr.Etempvar ___kprog_a64_bl_value__2 tulong)
                 (Expr.Etempvar ___kprog_a64_bl_shift__2 tulong) tulong)
               tuchar)]))))))

@[noinline] def s_kprog_arm64_stack_write_owned_17 : Stmt :=
Stmt.Sbreak

@[noinline] def s_kprog_arm64_stack_write_owned_18 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                    (Expr.Etempvar ___a64_stw_width tuchar)
                    (Expr.Econst_int (Integers.Int.repr 1) tuint) tint)
  (Stmt.Sset _t'14
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Etempvar ___a64_stw_width tuchar)
                      (Expr.Econst_int (Integers.Int.repr 2) tuint) tint)
    (Stmt.Ssequence
      (Stmt.Sset _t'14
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))
      (Stmt.Sset _t'14 (Expr.Ecast (Expr.Etempvar _t'14 tuint) tuint)))
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                        (Expr.Etempvar ___a64_stw_width tuchar)
                        (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sset _t'14
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 15) tuint) tuint))
          (Stmt.Sset _t'14 (Expr.Ecast (Expr.Etempvar _t'14 tuint) tuint)))
        (Stmt.Sset _t'14 (Expr.Ecast (Expr.Etempvar _t'14 tuint) tuint)))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sset _t'14
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 255) tuint)
              tuint))
          (Stmt.Sset _t'14 (Expr.Ecast (Expr.Etempvar _t'14 tuint) tuint)))
        (Stmt.Sset _t'14 (Expr.Ecast (Expr.Etempvar _t'14 tuint) tuint))))))

@[noinline] def s_kprog_arm64_stack_write_owned_19 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___kprog_a64_bl_lane__3
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tint) tulong))
  (Stmt.Ssequence
    (Stmt.Sset ___kprog_a64_bl_value__3
      (Expr.Etempvar ___a64_stw_value tulong))
    (Stmt.Ssequence
      (Stmt.Sset ___kprog_a64_bl_shift__3
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) tulong))
      (Stmt.Ssequence
        (Stmt.Sswitch (Expr.Etempvar ___kprog_a64_bl_lane__3 tulong)
          (LStmts.LScons (some 0)
            (Stmt.Ssequence
              (Stmt.Sset ___kprog_a64_bl_shift__3
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                  tulong))
              Stmt.Sbreak)
            (LStmts.LScons (some 1)
              (Stmt.Ssequence
                (Stmt.Sset ___kprog_a64_bl_shift__3
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tint)
                    tulong))
                Stmt.Sbreak)
              (LStmts.LScons (some 2)
                (Stmt.Ssequence
                  (Stmt.Sset ___kprog_a64_bl_shift__3
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 16) tint)
                      tulong))
                  Stmt.Sbreak)
                (LStmts.LScons (some 3)
                  (Stmt.Ssequence
                    (Stmt.Sset ___kprog_a64_bl_shift__3
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 24) tint) tulong))
                    Stmt.Sbreak)
                  (LStmts.LScons (some 4)
                    (Stmt.Ssequence
                      (Stmt.Sset ___kprog_a64_bl_shift__3
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 32) tint)
                          tulong))
                      Stmt.Sbreak)
                    (LStmts.LScons (some 5)
                      (Stmt.Ssequence
                        (Stmt.Sset ___kprog_a64_bl_shift__3
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 40) tint)
                            tulong))
                        Stmt.Sbreak)
                      (LStmts.LScons (some 6)
                        (Stmt.Ssequence
                          (Stmt.Sset ___kprog_a64_bl_shift__3
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 48) tint)
                              tulong))
                          Stmt.Sbreak)
                        (LStmts.LScons (some 7)
                          (Stmt.Ssequence
                            (Stmt.Sset ___kprog_a64_bl_shift__3
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 56) tint)
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
                            LStmts.LSnil))))))))))
        (Stmt.Ssequence
          (Stmt.Sset _t'23
            (Expr.Efield
              (Expr.Ederef
                (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                (Ty.Tstruct _kprog_arm64_memory noattr)) _b
              (tptr (tvolatile tuchar))))
          (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
            [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
            [(Expr.Eaddrof
               (Expr.Ederef
                 (Expr.Ebinop Binop.Oadd
                   (Expr.Etempvar _t'23 (tptr (tvolatile tuchar)))
                   (Expr.Ebinop Binop.Oadd
                     (Expr.Etempvar ___a64_stw_index tulong)
                     (Expr.Econst_int (Integers.Int.repr 3) tint) tulong)
                   (tptr (tvolatile tuchar))) (tvolatile tuchar))
               (tptr (tvolatile tuchar))),
             (Expr.Ecast
               (Expr.Ebinop Binop.Oshr
                 (Expr.Etempvar ___kprog_a64_bl_value__3 tulong)
                 (Expr.Etempvar ___kprog_a64_bl_shift__3 tulong) tulong)
               tuchar)]))))))

@[noinline] def s_kprog_arm64_stack_write_owned_20 : Stmt :=
Stmt.Sbreak

@[noinline] def s_kprog_arm64_stack_write_owned_21 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Etempvar ___a64_stw_width tuchar)
                      (Expr.Econst_int (Integers.Int.repr 1) tuint) tint)
    (Stmt.Sset _t'15
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                        (Expr.Etempvar ___a64_stw_width tuchar)
                        (Expr.Econst_int (Integers.Int.repr 2) tuint) tint)
      (Stmt.Ssequence
        (Stmt.Sset _t'15
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))
        (Stmt.Sset _t'15 (Expr.Ecast (Expr.Etempvar _t'15 tuint) tuint)))
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                          (Expr.Etempvar ___a64_stw_width tuchar)
                          (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sset _t'15
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 15) tuint)
                tuint))
            (Stmt.Sset _t'15 (Expr.Ecast (Expr.Etempvar _t'15 tuint) tuint)))
          (Stmt.Sset _t'15 (Expr.Ecast (Expr.Etempvar _t'15 tuint) tuint)))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sset _t'15
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 255) tuint)
                tuint))
            (Stmt.Sset _t'15 (Expr.Ecast (Expr.Etempvar _t'15 tuint) tuint)))
          (Stmt.Sset _t'15 (Expr.Ecast (Expr.Etempvar _t'15 tuint) tuint))))))
  (Stmt.Sifthenelse (Expr.Ecast
                      (Expr.Ebinop Binop.Oand
                        (Expr.Ebinop Binop.Oshr (Expr.Etempvar _t'15 tuint)
                          (Expr.Econst_int (Integers.Int.repr 4) tint) tuint)
                        (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint)
                      tuchar)
    (Stmt.Sloop
      (Stmt.Ssequence
        (Stmt.Sset ___kprog_a64_bl_lane__4
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 4) tint) tulong))
        (Stmt.Ssequence
          (Stmt.Sset ___kprog_a64_bl_value__4
            (Expr.Etempvar ___a64_stw_value tulong))
          (Stmt.Ssequence
            (Stmt.Sset ___kprog_a64_bl_shift__4
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                tulong))
            (Stmt.Ssequence
              (Stmt.Sswitch (Expr.Etempvar ___kprog_a64_bl_lane__4 tulong)
                (LStmts.LScons (some 0)
                  (Stmt.Ssequence
                    (Stmt.Sset ___kprog_a64_bl_shift__4
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 0) tint) tulong))
                    Stmt.Sbreak)
                  (LStmts.LScons (some 1)
                    (Stmt.Ssequence
                      (Stmt.Sset ___kprog_a64_bl_shift__4
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 8) tint)
                          tulong))
                      Stmt.Sbreak)
                    (LStmts.LScons (some 2)
                      (Stmt.Ssequence
                        (Stmt.Sset ___kprog_a64_bl_shift__4
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 16) tint)
                            tulong))
                        Stmt.Sbreak)
                      (LStmts.LScons (some 3)
                        (Stmt.Ssequence
                          (Stmt.Sset ___kprog_a64_bl_shift__4
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 24) tint)
                              tulong))
                          Stmt.Sbreak)
                        (LStmts.LScons (some 4)
                          (Stmt.Ssequence
                            (Stmt.Sset ___kprog_a64_bl_shift__4
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 32) tint)
                                tulong))
                            Stmt.Sbreak)
                          (LStmts.LScons (some 5)
                            (Stmt.Ssequence
                              (Stmt.Sset ___kprog_a64_bl_shift__4
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 40) tint)
                                  tulong))
                              Stmt.Sbreak)
                            (LStmts.LScons (some 6)
                              (Stmt.Ssequence
                                (Stmt.Sset ___kprog_a64_bl_shift__4
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 48) tint)
                                    tulong))
                                Stmt.Sbreak)
                              (LStmts.LScons (some 7)
                                (Stmt.Ssequence
                                  (Stmt.Sset ___kprog_a64_bl_shift__4
                                    (Expr.Ecast
                                      (Expr.Econst_int (Integers.Int.repr 56) tint)
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
              (Stmt.Ssequence
                (Stmt.Sset _t'22
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                      (Ty.Tstruct _kprog_arm64_memory noattr)) _b
                    (tptr (tvolatile tuchar))))
                (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
                  [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
                  [(Expr.Eaddrof
                     (Expr.Ederef
                       (Expr.Ebinop Binop.Oadd
                         (Expr.Etempvar _t'22 (tptr (tvolatile tuchar)))
                         (Expr.Ebinop Binop.Oadd
                           (Expr.Etempvar ___a64_stw_index tulong)
                           (Expr.Econst_int (Integers.Int.repr 4) tint)
                           tulong) (tptr (tvolatile tuchar)))
                       (tvolatile tuchar)) (tptr (tvolatile tuchar))),
                   (Expr.Ecast
                     (Expr.Ebinop Binop.Oshr
                       (Expr.Etempvar ___kprog_a64_bl_value__4 tulong)
                       (Expr.Etempvar ___kprog_a64_bl_shift__4 tulong)
                       tulong) tuchar)]))))))
      Stmt.Sbreak)
    Stmt.Sskip))

@[noinline] def s_kprog_arm64_stack_write_owned_22 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                        (Expr.Etempvar ___a64_stw_width tuchar)
                        (Expr.Econst_int (Integers.Int.repr 1) tuint) tint)
      (Stmt.Sset _t'16
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                          (Expr.Etempvar ___a64_stw_width tuchar)
                          (Expr.Econst_int (Integers.Int.repr 2) tuint) tint)
        (Stmt.Ssequence
          (Stmt.Sset _t'16
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))
          (Stmt.Sset _t'16 (Expr.Ecast (Expr.Etempvar _t'16 tuint) tuint)))
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar ___a64_stw_width tuchar)
                            (Expr.Econst_int (Integers.Int.repr 4) tuint)
                            tint)
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sset _t'16
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 15) tuint)
                  tuint))
              (Stmt.Sset _t'16
                (Expr.Ecast (Expr.Etempvar _t'16 tuint) tuint)))
            (Stmt.Sset _t'16 (Expr.Ecast (Expr.Etempvar _t'16 tuint) tuint)))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sset _t'16
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 255) tuint)
                  tuint))
              (Stmt.Sset _t'16
                (Expr.Ecast (Expr.Etempvar _t'16 tuint) tuint)))
            (Stmt.Sset _t'16 (Expr.Ecast (Expr.Etempvar _t'16 tuint) tuint))))))
    (Stmt.Sifthenelse (Expr.Ecast
                        (Expr.Ebinop Binop.Oand
                          (Expr.Ebinop Binop.Oshr (Expr.Etempvar _t'16 tuint)
                            (Expr.Econst_int (Integers.Int.repr 5) tint)
                            tuint)
                          (Expr.Econst_int (Integers.Int.repr 1) tuint)
                          tuint) tuchar)
      (Stmt.Sloop
        (Stmt.Ssequence
          (Stmt.Sset ___kprog_a64_bl_lane__5
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 5) tint) tulong))
          (Stmt.Ssequence
            (Stmt.Sset ___kprog_a64_bl_value__5
              (Expr.Etempvar ___a64_stw_value tulong))
            (Stmt.Ssequence
              (Stmt.Sset ___kprog_a64_bl_shift__5
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                  tulong))
              (Stmt.Ssequence
                (Stmt.Sswitch (Expr.Etempvar ___kprog_a64_bl_lane__5 tulong)
                  (LStmts.LScons (some 0)
                    (Stmt.Ssequence
                      (Stmt.Sset ___kprog_a64_bl_shift__5
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                          tulong))
                      Stmt.Sbreak)
                    (LStmts.LScons (some 1)
                      (Stmt.Ssequence
                        (Stmt.Sset ___kprog_a64_bl_shift__5
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 8) tint)
                            tulong))
                        Stmt.Sbreak)
                      (LStmts.LScons (some 2)
                        (Stmt.Ssequence
                          (Stmt.Sset ___kprog_a64_bl_shift__5
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 16) tint)
                              tulong))
                          Stmt.Sbreak)
                        (LStmts.LScons (some 3)
                          (Stmt.Ssequence
                            (Stmt.Sset ___kprog_a64_bl_shift__5
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 24) tint)
                                tulong))
                            Stmt.Sbreak)
                          (LStmts.LScons (some 4)
                            (Stmt.Ssequence
                              (Stmt.Sset ___kprog_a64_bl_shift__5
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 32) tint)
                                  tulong))
                              Stmt.Sbreak)
                            (LStmts.LScons (some 5)
                              (Stmt.Ssequence
                                (Stmt.Sset ___kprog_a64_bl_shift__5
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 40) tint)
                                    tulong))
                                Stmt.Sbreak)
                              (LStmts.LScons (some 6)
                                (Stmt.Ssequence
                                  (Stmt.Sset ___kprog_a64_bl_shift__5
                                    (Expr.Ecast
                                      (Expr.Econst_int (Integers.Int.repr 48) tint)
                                      tulong))
                                  Stmt.Sbreak)
                                (LStmts.LScons (some 7)
                                  (Stmt.Ssequence
                                    (Stmt.Sset ___kprog_a64_bl_shift__5
                                      (Expr.Ecast
                                        (Expr.Econst_int (Integers.Int.repr 56) tint)
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
                (Stmt.Ssequence
                  (Stmt.Sset _t'21
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                        (Ty.Tstruct _kprog_arm64_memory noattr)) _b
                      (tptr (tvolatile tuchar))))
                  (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
                    [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
                    [(Expr.Eaddrof
                       (Expr.Ederef
                         (Expr.Ebinop Binop.Oadd
                           (Expr.Etempvar _t'21 (tptr (tvolatile tuchar)))
                           (Expr.Ebinop Binop.Oadd
                             (Expr.Etempvar ___a64_stw_index tulong)
                             (Expr.Econst_int (Integers.Int.repr 5) tint)
                             tulong) (tptr (tvolatile tuchar)))
                         (tvolatile tuchar)) (tptr (tvolatile tuchar))),
                     (Expr.Ecast
                       (Expr.Ebinop Binop.Oshr
                         (Expr.Etempvar ___kprog_a64_bl_value__5 tulong)
                         (Expr.Etempvar ___kprog_a64_bl_shift__5 tulong)
                         tulong) tuchar)]))))))
        Stmt.Sbreak)
      Stmt.Sskip))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                          (Expr.Etempvar ___a64_stw_width tuchar)
                          (Expr.Econst_int (Integers.Int.repr 1) tuint) tint)
        (Stmt.Sset _t'17
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar ___a64_stw_width tuchar)
                            (Expr.Econst_int (Integers.Int.repr 2) tuint)
                            tint)
          (Stmt.Ssequence
            (Stmt.Sset _t'17
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint)
                tuint))
            (Stmt.Sset _t'17 (Expr.Ecast (Expr.Etempvar _t'17 tuint) tuint)))
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar ___a64_stw_width tuchar)
                              (Expr.Econst_int (Integers.Int.repr 4) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'17
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 15) tuint)
                    tuint))
                (Stmt.Sset _t'17
                  (Expr.Ecast (Expr.Etempvar _t'17 tuint) tuint)))
              (Stmt.Sset _t'17
                (Expr.Ecast (Expr.Etempvar _t'17 tuint) tuint)))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'17
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 255) tuint)
                    tuint))
                (Stmt.Sset _t'17
                  (Expr.Ecast (Expr.Etempvar _t'17 tuint) tuint)))
              (Stmt.Sset _t'17
                (Expr.Ecast (Expr.Etempvar _t'17 tuint) tuint))))))
      (Stmt.Sifthenelse (Expr.Ecast
                          (Expr.Ebinop Binop.Oand
                            (Expr.Ebinop Binop.Oshr
                              (Expr.Etempvar _t'17 tuint)
                              (Expr.Econst_int (Integers.Int.repr 6) tint)
                              tuint)
                            (Expr.Econst_int (Integers.Int.repr 1) tuint)
                            tuint) tuchar)
        (Stmt.Sloop
          (Stmt.Ssequence
            (Stmt.Sset ___kprog_a64_bl_lane__6
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 6) tint)
                tulong))
            (Stmt.Ssequence
              (Stmt.Sset ___kprog_a64_bl_value__6
                (Expr.Etempvar ___a64_stw_value tulong))
              (Stmt.Ssequence
                (Stmt.Sset ___kprog_a64_bl_shift__6
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                    tulong))
                (Stmt.Ssequence
                  (Stmt.Sswitch (Expr.Etempvar ___kprog_a64_bl_lane__6 tulong)
                    (LStmts.LScons (some 0)
                      (Stmt.Ssequence
                        (Stmt.Sset ___kprog_a64_bl_shift__6
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                            tulong))
                        Stmt.Sbreak)
                      (LStmts.LScons (some 1)
                        (Stmt.Ssequence
                          (Stmt.Sset ___kprog_a64_bl_shift__6
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 8) tint)
                              tulong))
                          Stmt.Sbreak)
                        (LStmts.LScons (some 2)
                          (Stmt.Ssequence
                            (Stmt.Sset ___kprog_a64_bl_shift__6
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 16) tint)
                                tulong))
                            Stmt.Sbreak)
                          (LStmts.LScons (some 3)
                            (Stmt.Ssequence
                              (Stmt.Sset ___kprog_a64_bl_shift__6
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 24) tint)
                                  tulong))
                              Stmt.Sbreak)
                            (LStmts.LScons (some 4)
                              (Stmt.Ssequence
                                (Stmt.Sset ___kprog_a64_bl_shift__6
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 32) tint)
                                    tulong))
                                Stmt.Sbreak)
                              (LStmts.LScons (some 5)
                                (Stmt.Ssequence
                                  (Stmt.Sset ___kprog_a64_bl_shift__6
                                    (Expr.Ecast
                                      (Expr.Econst_int (Integers.Int.repr 40) tint)
                                      tulong))
                                  Stmt.Sbreak)
                                (LStmts.LScons (some 6)
                                  (Stmt.Ssequence
                                    (Stmt.Sset ___kprog_a64_bl_shift__6
                                      (Expr.Ecast
                                        (Expr.Econst_int (Integers.Int.repr 48) tint)
                                        tulong))
                                    Stmt.Sbreak)
                                  (LStmts.LScons (some 7)
                                    (Stmt.Ssequence
                                      (Stmt.Sset ___kprog_a64_bl_shift__6
                                        (Expr.Ecast
                                          (Expr.Econst_int (Integers.Int.repr 56) tint)
                                          tulong))
                                      Stmt.Sbreak)
                                    (LStmts.LScons none
                                      (Stmt.Ssequence
                                        (Stmt.Sloop
                                          (Stmt.Scall none
                                            (Expr.Evar _arm64_sim_unsupported_opcode 
                                            (Ty.Tfunction [] tvoid
                                              cc_default)) [])
                                          Stmt.Sbreak)
                                        Stmt.Sbreak)
                                      LStmts.LSnil))))))))))
                  (Stmt.Ssequence
                    (Stmt.Sset _t'20
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                          (Ty.Tstruct _kprog_arm64_memory noattr)) _b
                        (tptr (tvolatile tuchar))))
                    (Stmt.Sbuiltin none
                      (ExtFun.EF_vstore Chunk.Mint8unsigned)
                      [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
                      [(Expr.Eaddrof
                         (Expr.Ederef
                           (Expr.Ebinop Binop.Oadd
                             (Expr.Etempvar _t'20 (tptr (tvolatile tuchar)))
                             (Expr.Ebinop Binop.Oadd
                               (Expr.Etempvar ___a64_stw_index tulong)
                               (Expr.Econst_int (Integers.Int.repr 6) tint)
                               tulong) (tptr (tvolatile tuchar)))
                           (tvolatile tuchar)) (tptr (tvolatile tuchar))),
                       (Expr.Ecast
                         (Expr.Ebinop Binop.Oshr
                           (Expr.Etempvar ___kprog_a64_bl_value__6 tulong)
                           (Expr.Etempvar ___kprog_a64_bl_shift__6 tulong)
                           tulong) tuchar)]))))))
          Stmt.Sbreak)
        Stmt.Sskip))
    (Stmt.Ssequence
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                          (Expr.Etempvar ___a64_stw_width tuchar)
                          (Expr.Econst_int (Integers.Int.repr 1) tuint) tint)
        (Stmt.Sset _t'18
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar ___a64_stw_width tuchar)
                            (Expr.Econst_int (Integers.Int.repr 2) tuint)
                            tint)
          (Stmt.Ssequence
            (Stmt.Sset _t'18
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint)
                tuint))
            (Stmt.Sset _t'18 (Expr.Ecast (Expr.Etempvar _t'18 tuint) tuint)))
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar ___a64_stw_width tuchar)
                              (Expr.Econst_int (Integers.Int.repr 4) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'18
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 15) tuint)
                    tuint))
                (Stmt.Sset _t'18
                  (Expr.Ecast (Expr.Etempvar _t'18 tuint) tuint)))
              (Stmt.Sset _t'18
                (Expr.Ecast (Expr.Etempvar _t'18 tuint) tuint)))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'18
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 255) tuint)
                    tuint))
                (Stmt.Sset _t'18
                  (Expr.Ecast (Expr.Etempvar _t'18 tuint) tuint)))
              (Stmt.Sset _t'18
                (Expr.Ecast (Expr.Etempvar _t'18 tuint) tuint))))))
      (Stmt.Sifthenelse (Expr.Ecast
                          (Expr.Ebinop Binop.Oand
                            (Expr.Ebinop Binop.Oshr
                              (Expr.Etempvar _t'18 tuint)
                              (Expr.Econst_int (Integers.Int.repr 7) tint)
                              tuint)
                            (Expr.Econst_int (Integers.Int.repr 1) tuint)
                            tuint) tuchar)
        (Stmt.Sloop
          (Stmt.Ssequence
            (Stmt.Sset ___kprog_a64_bl_lane__7
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 7) tint)
                tulong))
            (Stmt.Ssequence
              (Stmt.Sset ___kprog_a64_bl_value__7
                (Expr.Etempvar ___a64_stw_value tulong))
              (Stmt.Ssequence
                (Stmt.Sset ___kprog_a64_bl_shift__7
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                    tulong))
                (Stmt.Ssequence
                  (Stmt.Sswitch (Expr.Etempvar ___kprog_a64_bl_lane__7 tulong)
                    (LStmts.LScons (some 0)
                      (Stmt.Ssequence
                        (Stmt.Sset ___kprog_a64_bl_shift__7
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                            tulong))
                        Stmt.Sbreak)
                      (LStmts.LScons (some 1)
                        (Stmt.Ssequence
                          (Stmt.Sset ___kprog_a64_bl_shift__7
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 8) tint)
                              tulong))
                          Stmt.Sbreak)
                        (LStmts.LScons (some 2)
                          (Stmt.Ssequence
                            (Stmt.Sset ___kprog_a64_bl_shift__7
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 16) tint)
                                tulong))
                            Stmt.Sbreak)
                          (LStmts.LScons (some 3)
                            (Stmt.Ssequence
                              (Stmt.Sset ___kprog_a64_bl_shift__7
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 24) tint)
                                  tulong))
                              Stmt.Sbreak)
                            (LStmts.LScons (some 4)
                              (Stmt.Ssequence
                                (Stmt.Sset ___kprog_a64_bl_shift__7
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 32) tint)
                                    tulong))
                                Stmt.Sbreak)
                              (LStmts.LScons (some 5)
                                (Stmt.Ssequence
                                  (Stmt.Sset ___kprog_a64_bl_shift__7
                                    (Expr.Ecast
                                      (Expr.Econst_int (Integers.Int.repr 40) tint)
                                      tulong))
                                  Stmt.Sbreak)
                                (LStmts.LScons (some 6)
                                  (Stmt.Ssequence
                                    (Stmt.Sset ___kprog_a64_bl_shift__7
                                      (Expr.Ecast
                                        (Expr.Econst_int (Integers.Int.repr 48) tint)
                                        tulong))
                                    Stmt.Sbreak)
                                  (LStmts.LScons (some 7)
                                    (Stmt.Ssequence
                                      (Stmt.Sset ___kprog_a64_bl_shift__7
                                        (Expr.Ecast
                                          (Expr.Econst_int (Integers.Int.repr 56) tint)
                                          tulong))
                                      Stmt.Sbreak)
                                    (LStmts.LScons none
                                      (Stmt.Ssequence
                                        (Stmt.Sloop
                                          (Stmt.Scall none
                                            (Expr.Evar _arm64_sim_unsupported_opcode 
                                            (Ty.Tfunction [] tvoid
                                              cc_default)) [])
                                          Stmt.Sbreak)
                                        Stmt.Sbreak)
                                      LStmts.LSnil))))))))))
                  (Stmt.Ssequence
                    (Stmt.Sset _t'19
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                          (Ty.Tstruct _kprog_arm64_memory noattr)) _b
                        (tptr (tvolatile tuchar))))
                    (Stmt.Sbuiltin none
                      (ExtFun.EF_vstore Chunk.Mint8unsigned)
                      [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
                      [(Expr.Eaddrof
                         (Expr.Ederef
                           (Expr.Ebinop Binop.Oadd
                             (Expr.Etempvar _t'19 (tptr (tvolatile tuchar)))
                             (Expr.Ebinop Binop.Oadd
                               (Expr.Etempvar ___a64_stw_index tulong)
                               (Expr.Econst_int (Integers.Int.repr 7) tint)
                               tulong) (tptr (tvolatile tuchar)))
                           (tvolatile tuchar)) (tptr (tvolatile tuchar))),
                       (Expr.Ecast
                         (Expr.Ebinop Binop.Oshr
                           (Expr.Etempvar ___kprog_a64_bl_value__7 tulong)
                           (Expr.Etempvar ___kprog_a64_bl_shift__7 tulong)
                           tulong) tuchar)]))))))
          Stmt.Sbreak)
        Stmt.Sskip))))

def f_kprog_arm64_stack_write_owned : Function := {
  fn_return := tvoid,
  fn_callconv := cc_default,
  fn_params := [(_memory, (tptr (Ty.Tstruct _kprog_arm64_memory noattr))),
                (_off, tlong), (_width, tuchar), (_value, tulong),
                (_tag, tuchar)],
  fn_vars := [],
  fn_temps := [(___a64_stw_index, tulong), (___a64_stw_width, tuchar),
               (___a64_stw_value, tulong), (___a64_stw_action, tuchar),
               (___a64_stw_payload, tulong), (___a64_unmat_value, tulong),
               (___a64_unmat_tag, tuchar), (___a64_unmat_base, tulong),
               (___a64_unmat_base__1, tulong), (___ti, tulong),
               (___ts, tuint), (___tp, (tptr (tvolatile tulong))),
               (___tv, tulong), (___ti__1, tulong), (___ts__1, tuint),
               (___tp__1, (tptr (tvolatile tulong))), (___tv__1, tulong),
               (___a64_stw_last, tulong), (___ti__2, tulong),
               (___ts__2, tuint), (___tp__2, (tptr (tvolatile tulong))),
               (___tv__2, tulong), (___kprog_a64_bl_lane, tulong),
               (___kprog_a64_bl_value, tulong),
               (___kprog_a64_bl_shift, tulong),
               (___kprog_a64_bl_lane__1, tulong),
               (___kprog_a64_bl_value__1, tulong),
               (___kprog_a64_bl_shift__1, tulong),
               (___kprog_a64_bl_lane__2, tulong),
               (___kprog_a64_bl_value__2, tulong),
               (___kprog_a64_bl_shift__2, tulong),
               (___kprog_a64_bl_lane__3, tulong),
               (___kprog_a64_bl_value__3, tulong),
               (___kprog_a64_bl_shift__3, tulong),
               (___kprog_a64_bl_lane__4, tulong),
               (___kprog_a64_bl_value__4, tulong),
               (___kprog_a64_bl_shift__4, tulong),
               (___kprog_a64_bl_lane__5, tulong),
               (___kprog_a64_bl_value__5, tulong),
               (___kprog_a64_bl_shift__5, tulong),
               (___kprog_a64_bl_lane__6, tulong),
               (___kprog_a64_bl_value__6, tulong),
               (___kprog_a64_bl_shift__6, tulong),
               (___kprog_a64_bl_lane__7, tulong),
               (___kprog_a64_bl_value__7, tulong),
               (___kprog_a64_bl_shift__7, tulong), (_t'18, tuint),
               (_t'17, tuint), (_t'16, tuint), (_t'15, tuint),
               (_t'14, tuint), (_t'13, tuint), (_t'12, tuint),
               (_t'11, (tvolatile tulong)), (_t'10, tuint),
               (_t'9, (tvolatile tulong)), (_t'8, (tvolatile tulong)),
               (_t'7, tint), (_t'6, tulong), (_t'5, tulong), (_t'4, tint),
               (_t'3, tuint), (_t'2, tint), (_t'1, tulong), (_t'42, tlong),
               (_t'41, (tptr (tvolatile tulong))),
               (_t'40, (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))),
               (_t'39, (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))),
               (_t'38, tuchar),
               (_t'37, (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))),
               (_t'36, (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))),
               (_t'35, (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))),
               (_t'34, (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))),
               (_t'33, tuchar),
               (_t'32, (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))),
               (_t'31, (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))),
               (_t'30, (tptr tulong)), (_t'29, (tptr tuchar)),
               (_t'28, (tptr tuchar)), (_t'27, (tptr tuchar)),
               (_t'26, (tptr (tvolatile tuchar))),
               (_t'25, (tptr (tvolatile tuchar))),
               (_t'24, (tptr (tvolatile tuchar))),
               (_t'23, (tptr (tvolatile tuchar))),
               (_t'22, (tptr (tvolatile tuchar))),
               (_t'21, (tptr (tvolatile tuchar))),
               (_t'20, (tptr (tvolatile tuchar))),
               (_t'19, (tptr (tvolatile tuchar)))],
  fn_body :=
(Stmt.Sloop
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sset _t'42
        (Expr.Efield
          (Expr.Ederef
            (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
            (Ty.Tstruct _kprog_arm64_memory noattr)) _bias tlong))
      (Stmt.Sset ___a64_stw_index
        (Expr.Ebinop Binop.Oadd
          (Expr.Ecast (Expr.Etempvar _t'42 tlong) tulong)
          (Expr.Ecast (Expr.Etempvar _off tlong) tulong) tulong)))
    (Stmt.Ssequence
      (Stmt.Sset ___a64_stw_width
        (Expr.Ecast (Expr.Etempvar _width tuchar) tuchar))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar ___a64_stw_width tuchar)
                              (Expr.Econst_int (Integers.Int.repr 1) tuint)
                              tint)
            (Stmt.Sset _t'1
              (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 255) tulong)
                tulong))
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Etempvar ___a64_stw_width tuchar)
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
                                  (Expr.Etempvar ___a64_stw_width tuchar)
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
          (Stmt.Sset ___a64_stw_value
            (Expr.Ebinop Binop.Oand (Expr.Etempvar _value tulong)
              (Expr.Etempvar _t'1 tulong) tulong)))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar ___a64_stw_width tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                  tint)
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Ebinop Binop.Oand
                                      (Expr.Ecast
                                        (Expr.Etempvar ___a64_stw_index tulong)
                                        tuint)
                                      (Expr.Econst_int (Integers.Int.repr 7) tuint)
                                      tuint)
                                    (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                    tint)
                  (Stmt.Ssequence
                    (Stmt.Sset _t'2
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 1) tint) tint))
                    (Stmt.Sset _t'2
                      (Expr.Ecast (Expr.Etempvar _t'2 tint) tbool)))
                  (Stmt.Ssequence
                    (Stmt.Sset _t'2
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 0) tint) tint))
                    (Stmt.Sset _t'2
                      (Expr.Ecast (Expr.Etempvar _t'2 tint) tbool))))
                (Stmt.Sset _t'2 (Expr.Econst_int (Integers.Int.repr 0) tint)))
              (Stmt.Sifthenelse (Expr.Etempvar _t'2 tint)
                (Stmt.Sset _t'3
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                    tuint))
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Ebinop Binop.Oand
                                        (Expr.Ecast
                                          (Expr.Etempvar ___a64_stw_index tulong)
                                          tuint)
                                        (Expr.Econst_int (Integers.Int.repr 7) tuint)
                                        tuint)
                                      (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                      tint)
                    (Stmt.Sset _t'4
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 1) tint) tint))
                    (Stmt.Sset _t'4
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 0) tint) tint)))
                  (Stmt.Sifthenelse (Expr.Etempvar _t'4 tint)
                    (Stmt.Ssequence
                      (Stmt.Sset _t'3
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 1) tuint)
                          tuint))
                      (Stmt.Sset _t'3
                        (Expr.Ecast (Expr.Etempvar _t'3 tuint) tuint)))
                    (Stmt.Ssequence
                      (Stmt.Sset _t'3
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 2) tuint)
                          tuint))
                      (Stmt.Sset _t'3
                        (Expr.Ecast (Expr.Etempvar _t'3 tuint) tuint)))))))
            (Stmt.Sset ___a64_stw_action
              (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'3 tuint) tuchar)
                tuchar)))
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar ___a64_stw_action tuchar)
                              (Expr.Econst_int (Integers.Int.repr 0) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'41
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                      (Ty.Tstruct _kprog_arm64_memory noattr)) _q
                    (tptr (tvolatile tulong))))
                (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
                  [(tptr (tvolatile tulong)), (tvolatile tulong)]
                  [(Expr.Eaddrof
                     (Expr.Ederef
                       (Expr.Ebinop Binop.Oadd
                         (Expr.Etempvar _t'41 (tptr (tvolatile tulong)))
                         (Expr.Ebinop Binop.Oshr
                           (Expr.Ecast
                             (Expr.Etempvar ___a64_stw_index tulong) tulong)
                           (Expr.Econst_int (Integers.Int.repr 3) tint)
                           tulong) (tptr (tvolatile tulong)))
                       (tvolatile tulong)) (tptr (tvolatile tulong))),
                   (Expr.Etempvar ___a64_stw_value tulong)]))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar _tag tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                      tint)
                    (Stmt.Sset _t'7
                      (Expr.Econst_int (Integers.Int.repr 1) tint))
                    (Stmt.Sset _t'7
                      (Expr.Ecast
                        (Expr.Ebinop Binop.Oeq (Expr.Etempvar _tag tuchar)
                          (Expr.Econst_int (Integers.Int.repr 10) tuint)
                          tint) tbool)))
                  (Stmt.Sifthenelse (Expr.Etempvar _t'7 tint)
                    (Stmt.Ssequence
                      (Stmt.Sloop
                        (Stmt.Ssequence
                          (Stmt.Sset ___a64_unmat_value
                            (Expr.Etempvar ___a64_stw_value tulong))
                          (Stmt.Ssequence
                            s_kprog_arm64_stack_write_owned_0
                            s_kprog_arm64_stack_write_owned_1))
                        Stmt.Sbreak)
                      (Stmt.Sloop
                        (Stmt.Ssequence
                          (Stmt.Sset _t'30
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                                (Ty.Tstruct _kprog_arm64_memory noattr))
                              _payload (tptr tulong)))
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Etempvar _t'30 (tptr tulong))
                                (Expr.Ebinop Binop.Oshr
                                  (Expr.Ecast
                                    (Expr.Etempvar ___a64_stw_index tulong)
                                    tulong)
                                  (Expr.Econst_int (Integers.Int.repr 3) tint)
                                  tulong) (tptr tulong)) tulong)
                            (Expr.Etempvar ___a64_stw_payload tulong)))
                        Stmt.Sbreak))
                    Stmt.Sskip))
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Sset ___ti
                      (Expr.Ebinop Binop.Oshr
                        (Expr.Ecast (Expr.Etempvar ___a64_stw_index tulong)
                          tulong)
                        (Expr.Econst_int (Integers.Int.repr 3) tint) tulong))
                    (Stmt.Ssequence
                      (Stmt.Sset ___ts
                        (Expr.Ecast
                          (Expr.Ebinop Binop.Omul
                            (Expr.Ebinop Binop.Oand
                              (Expr.Etempvar ___ti tulong)
                              (Expr.Econst_int (Integers.Int.repr 7) tuint)
                              tulong)
                            (Expr.Econst_int (Integers.Int.repr 8) tuint)
                            tulong) tuint))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sset _t'29
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                                (Ty.Tstruct _kprog_arm64_memory noattr))
                              _tags (tptr tuchar)))
                          (Stmt.Sset ___tp
                            (Expr.Ecast
                              (Expr.Ecast
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Etempvar _t'29 (tptr tuchar))
                                  (Expr.Ebinop Binop.Oand
                                    (Expr.Ecast (Expr.Etempvar ___ti tulong)
                                      tulong)
                                    (Expr.Eunop Unop.Onotint
                                      (Expr.Econst_long (Integers.Int64.repr 7) tulong)
                                      tulong) tulong) (tptr tuchar))
                                (tptr tvoid)) (tptr (tvolatile tulong)))))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            s_kprog_arm64_stack_write_owned_2
                            (Stmt.Sset ___tv
                              (Expr.Etempvar _t'8 (tvolatile tulong))))
                          (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
                            [(tptr (tvolatile tulong)), (tvolatile tulong)]
                            [(Expr.Eaddrof
                               (Expr.Ederef
                                 (Expr.Etempvar ___tp (tptr (tvolatile tulong)))
                                 (tvolatile tulong))
                               (tptr (tvolatile tulong))),
                             (Expr.Ebinop Binop.Oor
                               (Expr.Ebinop Binop.Oand
                                 (Expr.Etempvar ___tv tulong)
                                 (Expr.Eunop Unop.Onotint
                                   (Expr.Ebinop Binop.Oshl
                                     (Expr.Econst_long (Integers.Int64.repr 255) tulong)
                                     (Expr.Etempvar ___ts tuint) tulong)
                                   tulong) tulong)
                               (Expr.Ebinop Binop.Oshl
                                 (Expr.Ecast
                                   (Expr.Ecast (Expr.Etempvar _tag tuchar)
                                     tuchar) tulong)
                                 (Expr.Etempvar ___ts tuint) tulong) tulong)])))))
                  Stmt.Sbreak)))
            (Stmt.Ssequence
              (Stmt.Sloop
                (Stmt.Ssequence
                  (Stmt.Sset ___ti__1
                    (Expr.Ebinop Binop.Oshr
                      (Expr.Ecast (Expr.Etempvar ___a64_stw_index tulong)
                        tulong) (Expr.Econst_int (Integers.Int.repr 3) tint)
                      tulong))
                  (Stmt.Ssequence
                    (Stmt.Sset ___ts__1
                      (Expr.Ecast
                        (Expr.Ebinop Binop.Omul
                          (Expr.Ebinop Binop.Oand
                            (Expr.Etempvar ___ti__1 tulong)
                            (Expr.Econst_int (Integers.Int.repr 7) tuint)
                            tulong)
                          (Expr.Econst_int (Integers.Int.repr 8) tuint)
                          tulong) tuint))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sset _t'28
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                              (Ty.Tstruct _kprog_arm64_memory noattr)) _tags
                            (tptr tuchar)))
                        (Stmt.Sset ___tp__1
                          (Expr.Ecast
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Etempvar _t'28 (tptr tuchar))
                                (Expr.Ebinop Binop.Oand
                                  (Expr.Ecast (Expr.Etempvar ___ti__1 tulong)
                                    tulong)
                                  (Expr.Eunop Unop.Onotint
                                    (Expr.Econst_long (Integers.Int64.repr 7) tulong)
                                    tulong) tulong) (tptr tuchar))
                              (tptr tvoid)) (tptr (tvolatile tulong)))))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sbuiltin (some _t'9)
                            (ExtFun.EF_vload Chunk.Mint64)
                            [(tptr (tvolatile tulong))]
                            [(Expr.Eaddrof
                               (Expr.Ederef
                                 (Expr.Etempvar ___tp__1 (tptr (tvolatile tulong)))
                                 (tvolatile tulong))
                               (tptr (tvolatile tulong)))])
                          (Stmt.Sset ___tv__1
                            (Expr.Etempvar _t'9 (tvolatile tulong))))
                        (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
                          [(tptr (tvolatile tulong)), (tvolatile tulong)]
                          [(Expr.Eaddrof
                             (Expr.Ederef
                               (Expr.Etempvar ___tp__1 (tptr (tvolatile tulong)))
                               (tvolatile tulong)) (tptr (tvolatile tulong))),
                           (Expr.Ebinop Binop.Oor
                             (Expr.Ebinop Binop.Oand
                               (Expr.Etempvar ___tv__1 tulong)
                               (Expr.Eunop Unop.Onotint
                                 (Expr.Ebinop Binop.Oshl
                                   (Expr.Econst_long (Integers.Int64.repr 255) tulong)
                                   (Expr.Etempvar ___ts__1 tuint) tulong)
                                 tulong) tulong)
                             (Expr.Ebinop Binop.Oshl
                               (Expr.Ecast
                                 (Expr.Ecast
                                   (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                   tuchar) tulong)
                               (Expr.Etempvar ___ts__1 tuint) tulong) tulong)])))))
                Stmt.Sbreak)
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar ___a64_stw_width tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                      tint)
                    (Stmt.Sset _t'10
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Etempvar ___a64_stw_width tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                        tint)
                      (Stmt.Ssequence
                        s_kprog_arm64_stack_write_owned_3
                        (Stmt.Sset _t'10
                          (Expr.Ecast (Expr.Etempvar _t'10 tuint) tuint)))
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Etempvar ___a64_stw_width tuchar)
                                          (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                          tint)
                        s_kprog_arm64_stack_write_owned_4
                        s_kprog_arm64_stack_write_owned_5)))
                  (Stmt.Sset ___a64_stw_last
                    (Expr.Ebinop Binop.Osub
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar ___a64_stw_index tulong)
                        (Expr.Etempvar _t'10 tuint) tulong)
                      (Expr.Econst_int (Integers.Int.repr 1) tuint) tulong)))
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.One
                                      (Expr.Ebinop Binop.Oshr
                                        (Expr.Ecast
                                          (Expr.Etempvar ___a64_stw_last tulong)
                                          tulong)
                                        (Expr.Econst_int (Integers.Int.repr 3) tint)
                                        tulong)
                                      (Expr.Ebinop Binop.Oshr
                                        (Expr.Ecast
                                          (Expr.Etempvar ___a64_stw_index tulong)
                                          tulong)
                                        (Expr.Econst_int (Integers.Int.repr 3) tint)
                                        tulong) tint)
                    (Stmt.Sloop
                      (Stmt.Ssequence
                        (Stmt.Sset ___ti__2
                          (Expr.Ebinop Binop.Oshr
                            (Expr.Ecast
                              (Expr.Etempvar ___a64_stw_last tulong) tulong)
                            (Expr.Econst_int (Integers.Int.repr 3) tint)
                            tulong))
                        (Stmt.Ssequence
                          s_kprog_arm64_stack_write_owned_6
                          s_kprog_arm64_stack_write_owned_7))
                      Stmt.Sbreak)
                    Stmt.Sskip)
                  (Stmt.Ssequence
                    (Stmt.Sloop
                      (Stmt.Ssequence
                        (Stmt.Sset ___kprog_a64_bl_lane
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                            tulong))
                        (Stmt.Ssequence
                          (Stmt.Sset ___kprog_a64_bl_value
                            (Expr.Etempvar ___a64_stw_value tulong))
                          (Stmt.Ssequence
                            s_kprog_arm64_stack_write_owned_8
                            s_kprog_arm64_stack_write_owned_9)))
                      Stmt.Sbreak)
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Etempvar ___a64_stw_width tuchar)
                                            (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                            tint)
                          s_kprog_arm64_stack_write_owned_10
                          s_kprog_arm64_stack_write_owned_11)
                        (Stmt.Sifthenelse (Expr.Ecast
                                            (Expr.Ebinop Binop.Oand
                                              (Expr.Ebinop Binop.Oshr
                                                (Expr.Etempvar _t'12 tuint)
                                                (Expr.Econst_int (Integers.Int.repr 1) tint)
                                                tuint)
                                              (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                              tuint) tuchar)
                          (Stmt.Sloop
                            s_kprog_arm64_stack_write_owned_12
                            s_kprog_arm64_stack_write_owned_13)
                          Stmt.Sskip))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Etempvar ___a64_stw_width tuchar)
                                              (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                              tint)
                            s_kprog_arm64_stack_write_owned_14
                            s_kprog_arm64_stack_write_owned_15)
                          (Stmt.Sifthenelse (Expr.Ecast
                                              (Expr.Ebinop Binop.Oand
                                                (Expr.Ebinop Binop.Oshr
                                                  (Expr.Etempvar _t'13 tuint)
                                                  (Expr.Econst_int (Integers.Int.repr 2) tint)
                                                  tuint)
                                                (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                                tuint) tuchar)
                            (Stmt.Sloop
                              s_kprog_arm64_stack_write_owned_16
                              s_kprog_arm64_stack_write_owned_17)
                            Stmt.Sskip))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            s_kprog_arm64_stack_write_owned_18
                            (Stmt.Sifthenelse (Expr.Ecast
                                                (Expr.Ebinop Binop.Oand
                                                  (Expr.Ebinop Binop.Oshr
                                                    (Expr.Etempvar _t'14 tuint)
                                                    (Expr.Econst_int (Integers.Int.repr 3) tint)
                                                    tuint)
                                                  (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                                  tuint) tuchar)
                              (Stmt.Sloop
                                s_kprog_arm64_stack_write_owned_19
                                s_kprog_arm64_stack_write_owned_20)
                              Stmt.Sskip))
                          (Stmt.Ssequence
                            s_kprog_arm64_stack_write_owned_21
                            s_kprog_arm64_stack_write_owned_22)))))))))))))
  Stmt.Sbreak)
}

@[noinline] def s_kprog_arm64_stack_write_0 : Stmt :=
(Stmt.Sset _t'1
  (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 65535) tulong) tulong))

@[noinline] def s_kprog_arm64_stack_write_1 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'1
      (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 4294967295) tulong)
        tulong))
    (Stmt.Sset _t'1 (Expr.Ecast (Expr.Etempvar _t'1 tulong) tulong)))
  (Stmt.Sset _t'1 (Expr.Ecast (Expr.Etempvar _t'1 tulong) tulong)))

@[noinline] def s_kprog_arm64_stack_write_2 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'1
      (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr (-1)) tulong)
        tulong))
    (Stmt.Sset _t'1 (Expr.Ecast (Expr.Etempvar _t'1 tulong) tulong)))
  (Stmt.Sset _t'1 (Expr.Ecast (Expr.Etempvar _t'1 tulong) tulong)))

@[noinline] def s_kprog_arm64_stack_write_3 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'2
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tint) tint))
  (Stmt.Sset _t'2 (Expr.Ecast (Expr.Etempvar _t'2 tint) tbool)))

@[noinline] def s_kprog_arm64_stack_write_4 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'2
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) tint))
  (Stmt.Sset _t'2 (Expr.Ecast (Expr.Etempvar _t'2 tint) tbool)))

@[noinline] def s_kprog_arm64_stack_write_5 : Stmt :=
(Stmt.Sset _t'4
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tint) tint))

@[noinline] def s_kprog_arm64_stack_write_6 : Stmt :=
(Stmt.Sset _t'4
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) tint))

@[noinline] def s_kprog_arm64_stack_write_7 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'3
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
  (Stmt.Sset _t'3 (Expr.Ecast (Expr.Etempvar _t'3 tuint) tuint)))

@[noinline] def s_kprog_arm64_stack_write_8 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'3
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint) tuint))
  (Stmt.Sset _t'3 (Expr.Ecast (Expr.Etempvar _t'3 tuint) tuint)))

@[noinline] def s_kprog_arm64_stack_write_9 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _tag tuchar)
                    (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
  (Stmt.Sset _t'7 (Expr.Econst_int (Integers.Int.repr 1) tint))
  (Stmt.Sset _t'7
    (Expr.Ecast
      (Expr.Ebinop Binop.Oeq (Expr.Etempvar _tag tuchar)
        (Expr.Econst_int (Integers.Int.repr 10) tuint) tint) tbool)))

@[noinline] def s_kprog_arm64_stack_write_10 : Stmt :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'6)
    (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                         cc_default))
    [(Expr.Econst_int (Integers.Int.repr 3) tint)])
  (Stmt.Ssequence
    (Stmt.Sset _t'83
      (Expr.Efield
        (Expr.Ederef
          (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
          (Ty.Tstruct _kprog_arm64_memory noattr)) _coordinates
        (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))))
    (Stmt.Sassign
      (Expr.Efield
        (Expr.Ederef
          (Expr.Etempvar _t'83 (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
          (Ty.Tstruct _kprog_arm64_coordinates noattr)) _return_base tulong)
      (Expr.Etempvar _t'6 tulong))))

@[noinline] def s_kprog_arm64_stack_write_11 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'82
    (Expr.Efield
      (Expr.Ederef
        (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
        (Ty.Tstruct _kprog_arm64_memory noattr)) _coordinates
      (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))))
  (Stmt.Sassign
    (Expr.Efield
      (Expr.Ederef
        (Expr.Etempvar _t'82 (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
        (Ty.Tstruct _kprog_arm64_coordinates noattr)) _return_valid tuchar)
    (Expr.Econst_int (Integers.Int.repr 1) tint)))

@[noinline] def s_kprog_arm64_stack_write_12 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sset ___a64_unmat_value (Expr.Etempvar ___a64_stw_value tulong))
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
                    (Stmt.Sset _t'85
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                          (Ty.Tstruct _kprog_arm64_memory noattr))
                        _coordinates
                        (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))))
                    (Stmt.Ssequence
                      (Stmt.Sset _t'86
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar _t'85 (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                            (Ty.Tstruct _kprog_arm64_coordinates noattr))
                          _sp_valid tuchar))
                      (Stmt.Sifthenelse (Expr.Eunop Unop.Onotbool
                                          (Expr.Etempvar _t'86 tuchar) tint)
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Scall (some _t'5)
                              (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                   [tuint]
                                                                   tulong
                                                                   cc_default))
                              [(Expr.Econst_int (Integers.Int.repr 1) tint)])
                            (Stmt.Ssequence
                              (Stmt.Sset _t'88
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                                    (Ty.Tstruct _kprog_arm64_memory noattr))
                                  _coordinates
                                  (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))))
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Etempvar _t'88 (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                                    (Ty.Tstruct _kprog_arm64_coordinates noattr))
                                  _sp_base tulong)
                                (Expr.Etempvar _t'5 tulong))))
                          (Stmt.Ssequence
                            (Stmt.Sset _t'87
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                                  (Ty.Tstruct _kprog_arm64_memory noattr))
                                _coordinates
                                (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))))
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Etempvar _t'87 (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                                  (Ty.Tstruct _kprog_arm64_coordinates noattr))
                                _sp_valid tuchar)
                              (Expr.Econst_int (Integers.Int.repr 1) tint))))
                        Stmt.Sskip)))
                  (Stmt.Ssequence
                    (Stmt.Sset _t'84
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                          (Ty.Tstruct _kprog_arm64_memory noattr))
                        _coordinates
                        (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))))
                    (Stmt.Sset ___a64_unmat_base
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar _t'84 (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                          (Ty.Tstruct _kprog_arm64_coordinates noattr))
                        _sp_base tulong))))
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
                      (Stmt.Sset _t'80
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                            (Ty.Tstruct _kprog_arm64_memory noattr))
                          _coordinates
                          (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))))
                      (Stmt.Ssequence
                        (Stmt.Sset _t'81
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar _t'80 (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                              (Ty.Tstruct _kprog_arm64_coordinates noattr))
                            _return_valid tuchar))
                        (Stmt.Sifthenelse (Expr.Eunop Unop.Onotbool
                                            (Expr.Etempvar _t'81 tuchar)
                                            tint)
                          (Stmt.Ssequence
                            s_kprog_arm64_stack_write_10
                            s_kprog_arm64_stack_write_11)
                          Stmt.Sskip)))
                    (Stmt.Ssequence
                      (Stmt.Sset _t'79
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                            (Ty.Tstruct _kprog_arm64_memory noattr))
                          _coordinates
                          (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))))
                      (Stmt.Sset ___a64_unmat_base__1
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar _t'79 (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                            (Ty.Tstruct _kprog_arm64_coordinates noattr))
                          _return_base tulong))))
                  Stmt.Sbreak)
                (Stmt.Sset ___a64_unmat_value
                  (Expr.Ebinop Binop.Osub
                    (Expr.Etempvar ___a64_unmat_value tulong)
                    (Expr.Etempvar ___a64_unmat_base__1 tulong) tulong)))
              Stmt.Sskip))
          (Stmt.Sset ___a64_stw_payload
            (Expr.Etempvar ___a64_unmat_value tulong)))))
    Stmt.Sbreak)
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sset _t'78
        (Expr.Efield
          (Expr.Ederef
            (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
            (Ty.Tstruct _kprog_arm64_memory noattr)) _payload (tptr tulong)))
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd (Expr.Etempvar _t'78 (tptr tulong))
            (Expr.Ebinop Binop.Oshr
              (Expr.Ecast (Expr.Etempvar ___a64_stw_index tulong) tulong)
              (Expr.Econst_int (Integers.Int.repr 3) tint) tulong)
            (tptr tulong)) tulong) (Expr.Etempvar ___a64_stw_payload tulong)))
    Stmt.Sbreak))

@[noinline] def s_kprog_arm64_stack_write_13 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___ti
    (Expr.Ebinop Binop.Oshr
      (Expr.Ecast (Expr.Etempvar ___a64_stw_index tulong) tulong)
      (Expr.Econst_int (Integers.Int.repr 3) tint) tulong))
  (Stmt.Ssequence
    (Stmt.Sset ___ts
      (Expr.Ecast
        (Expr.Ebinop Binop.Omul
          (Expr.Ebinop Binop.Oand (Expr.Etempvar ___ti tulong)
            (Expr.Econst_int (Integers.Int.repr 7) tuint) tulong)
          (Expr.Econst_int (Integers.Int.repr 8) tuint) tulong) tuint))
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sset _t'77
          (Expr.Efield
            (Expr.Ederef
              (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
              (Ty.Tstruct _kprog_arm64_memory noattr)) _tags (tptr tuchar)))
        (Stmt.Sset ___tp
          (Expr.Ecast
            (Expr.Ecast
              (Expr.Ebinop Binop.Oadd (Expr.Etempvar _t'77 (tptr tuchar))
                (Expr.Ebinop Binop.Oand
                  (Expr.Ecast (Expr.Etempvar ___ti tulong) tulong)
                  (Expr.Eunop Unop.Onotint
                    (Expr.Econst_long (Integers.Int64.repr 7) tulong) tulong)
                  tulong) (tptr tuchar)) (tptr tvoid))
            (tptr (tvolatile tulong)))))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sbuiltin (some _t'8) (ExtFun.EF_vload Chunk.Mint64)
            [(tptr (tvolatile tulong))]
            [(Expr.Eaddrof
               (Expr.Ederef (Expr.Etempvar ___tp (tptr (tvolatile tulong)))
                 (tvolatile tulong)) (tptr (tvolatile tulong)))])
          (Stmt.Sset ___tv (Expr.Etempvar _t'8 (tvolatile tulong))))
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
               (Expr.Ecast (Expr.Ecast (Expr.Etempvar _tag tuchar) tuchar)
                 tulong) (Expr.Etempvar ___ts tuint) tulong) tulong)])))))

@[noinline] def s_kprog_arm64_stack_write_14 : Stmt :=
Stmt.Sbreak

@[noinline] def s_kprog_arm64_stack_write_15 : Stmt :=
(Stmt.Sset ___ti__1
  (Expr.Ebinop Binop.Oshr
    (Expr.Ecast (Expr.Etempvar ___a64_stw_index tulong) tulong)
    (Expr.Econst_int (Integers.Int.repr 3) tint) tulong))

@[noinline] def s_kprog_arm64_stack_write_16 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___ts__1
    (Expr.Ecast
      (Expr.Ebinop Binop.Omul
        (Expr.Ebinop Binop.Oand (Expr.Etempvar ___ti__1 tulong)
          (Expr.Econst_int (Integers.Int.repr 7) tuint) tulong)
        (Expr.Econst_int (Integers.Int.repr 8) tuint) tulong) tuint))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sset _t'76
        (Expr.Efield
          (Expr.Ederef
            (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
            (Ty.Tstruct _kprog_arm64_memory noattr)) _tags (tptr tuchar)))
      (Stmt.Sset ___tp__1
        (Expr.Ecast
          (Expr.Ecast
            (Expr.Ebinop Binop.Oadd (Expr.Etempvar _t'76 (tptr tuchar))
              (Expr.Ebinop Binop.Oand
                (Expr.Ecast (Expr.Etempvar ___ti__1 tulong) tulong)
                (Expr.Eunop Unop.Onotint
                  (Expr.Econst_long (Integers.Int64.repr 7) tulong) tulong)
                tulong) (tptr tuchar)) (tptr tvoid))
          (tptr (tvolatile tulong)))))
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sbuiltin (some _t'9) (ExtFun.EF_vload Chunk.Mint64)
          [(tptr (tvolatile tulong))]
          [(Expr.Eaddrof
             (Expr.Ederef (Expr.Etempvar ___tp__1 (tptr (tvolatile tulong)))
               (tvolatile tulong)) (tptr (tvolatile tulong)))])
        (Stmt.Sset ___tv__1 (Expr.Etempvar _t'9 (tvolatile tulong))))
      (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
        [(tptr (tvolatile tulong)), (tvolatile tulong)]
        [(Expr.Eaddrof
           (Expr.Ederef (Expr.Etempvar ___tp__1 (tptr (tvolatile tulong)))
             (tvolatile tulong)) (tptr (tvolatile tulong))),
         (Expr.Ebinop Binop.Oor
           (Expr.Ebinop Binop.Oand (Expr.Etempvar ___tv__1 tulong)
             (Expr.Eunop Unop.Onotint
               (Expr.Ebinop Binop.Oshl
                 (Expr.Econst_long (Integers.Int64.repr 255) tulong)
                 (Expr.Etempvar ___ts__1 tuint) tulong) tulong) tulong)
           (Expr.Ebinop Binop.Oshl
             (Expr.Ecast
               (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                 tuchar) tulong) (Expr.Etempvar ___ts__1 tuint) tulong)
           tulong)]))))

@[noinline] def s_kprog_arm64_stack_write_17 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                    (Expr.Etempvar ___a64_stw_width tuchar)
                    (Expr.Econst_int (Integers.Int.repr 1) tuint) tint)
  (Stmt.Sset _t'10
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Etempvar ___a64_stw_width tuchar)
                      (Expr.Econst_int (Integers.Int.repr 2) tuint) tint)
    (Stmt.Ssequence
      (Stmt.Sset _t'10
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint) tuint))
      (Stmt.Sset _t'10 (Expr.Ecast (Expr.Etempvar _t'10 tuint) tuint)))
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                        (Expr.Etempvar ___a64_stw_width tuchar)
                        (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sset _t'10
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 4) tuint) tuint))
          (Stmt.Sset _t'10 (Expr.Ecast (Expr.Etempvar _t'10 tuint) tuint)))
        (Stmt.Sset _t'10 (Expr.Ecast (Expr.Etempvar _t'10 tuint) tuint)))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sset _t'10
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint))
          (Stmt.Sset _t'10 (Expr.Ecast (Expr.Etempvar _t'10 tuint) tuint)))
        (Stmt.Sset _t'10 (Expr.Ecast (Expr.Etempvar _t'10 tuint) tuint))))))

@[noinline] def s_kprog_arm64_stack_write_18 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.One
                    (Expr.Ebinop Binop.Oshr
                      (Expr.Ecast (Expr.Etempvar ___a64_stw_last tulong)
                        tulong) (Expr.Econst_int (Integers.Int.repr 3) tint)
                      tulong)
                    (Expr.Ebinop Binop.Oshr
                      (Expr.Ecast (Expr.Etempvar ___a64_stw_index tulong)
                        tulong) (Expr.Econst_int (Integers.Int.repr 3) tint)
                      tulong) tint)
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sset ___ti__2
        (Expr.Ebinop Binop.Oshr
          (Expr.Ecast (Expr.Etempvar ___a64_stw_last tulong) tulong)
          (Expr.Econst_int (Integers.Int.repr 3) tint) tulong))
      (Stmt.Ssequence
        (Stmt.Sset ___ts__2
          (Expr.Ecast
            (Expr.Ebinop Binop.Omul
              (Expr.Ebinop Binop.Oand (Expr.Etempvar ___ti__2 tulong)
                (Expr.Econst_int (Integers.Int.repr 7) tuint) tulong)
              (Expr.Econst_int (Integers.Int.repr 8) tuint) tulong) tuint))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sset _t'75
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                  (Ty.Tstruct _kprog_arm64_memory noattr)) _tags
                (tptr tuchar)))
            (Stmt.Sset ___tp__2
              (Expr.Ecast
                (Expr.Ecast
                  (Expr.Ebinop Binop.Oadd (Expr.Etempvar _t'75 (tptr tuchar))
                    (Expr.Ebinop Binop.Oand
                      (Expr.Ecast (Expr.Etempvar ___ti__2 tulong) tulong)
                      (Expr.Eunop Unop.Onotint
                        (Expr.Econst_long (Integers.Int64.repr 7) tulong)
                        tulong) tulong) (tptr tuchar)) (tptr tvoid))
                (tptr (tvolatile tulong)))))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sbuiltin (some _t'11) (ExtFun.EF_vload Chunk.Mint64)
                [(tptr (tvolatile tulong))]
                [(Expr.Eaddrof
                   (Expr.Ederef
                     (Expr.Etempvar ___tp__2 (tptr (tvolatile tulong)))
                     (tvolatile tulong)) (tptr (tvolatile tulong)))])
              (Stmt.Sset ___tv__2 (Expr.Etempvar _t'11 (tvolatile tulong))))
            (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
              [(tptr (tvolatile tulong)), (tvolatile tulong)]
              [(Expr.Eaddrof
                 (Expr.Ederef
                   (Expr.Etempvar ___tp__2 (tptr (tvolatile tulong)))
                   (tvolatile tulong)) (tptr (tvolatile tulong))),
               (Expr.Ebinop Binop.Oor
                 (Expr.Ebinop Binop.Oand (Expr.Etempvar ___tv__2 tulong)
                   (Expr.Eunop Unop.Onotint
                     (Expr.Ebinop Binop.Oshl
                       (Expr.Econst_long (Integers.Int64.repr 255) tulong)
                       (Expr.Etempvar ___ts__2 tuint) tulong) tulong) tulong)
                 (Expr.Ebinop Binop.Oshl
                   (Expr.Ecast
                     (Expr.Ecast
                       (Expr.Econst_int (Integers.Int.repr 0) tuint) tuchar)
                     tulong) (Expr.Etempvar ___ts__2 tuint) tulong) tulong)])))))
    Stmt.Sbreak)
  Stmt.Sskip)

@[noinline] def s_kprog_arm64_stack_write_19 : Stmt :=
(Stmt.Scall none
  (Expr.Evar _arm64_sim_unsupported_opcode (Ty.Tfunction [] tvoid cc_default))
  [])

@[noinline] def s_kprog_arm64_stack_write_20 : Stmt :=
Stmt.Sbreak

@[noinline] def s_kprog_arm64_stack_write_21 : Stmt :=
(Stmt.Sset ___kprog_a64_bl_shift__6
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) tulong))

@[noinline] def s_kprog_arm64_stack_write_22 : Stmt :=
(Stmt.Sset ___kprog_a64_bl_shift__6
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tint) tulong))

@[noinline] def s_kprog_arm64_stack_write_23 : Stmt :=
(Stmt.Sset ___kprog_a64_bl_shift__6
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 16) tint) tulong))

@[noinline] def s_kprog_arm64_stack_write_24 : Stmt :=
(Stmt.Sset ___kprog_a64_bl_shift__6
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 24) tint) tulong))

@[noinline] def s_kprog_arm64_stack_write_25 : Stmt :=
(Stmt.Sset ___kprog_a64_bl_shift__6
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 32) tint) tulong))

@[noinline] def s_kprog_arm64_stack_write_26 : Stmt :=
(Stmt.Sset ___kprog_a64_bl_shift__6
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 40) tint) tulong))

@[noinline] def s_kprog_arm64_stack_write_27 : Stmt :=
(Stmt.Sset ___kprog_a64_bl_shift__6
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 48) tint) tulong))

@[noinline] def s_kprog_arm64_stack_write_28 : Stmt :=
(Stmt.Sset ___kprog_a64_bl_shift__6
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 56) tint) tulong))

@[noinline] def s_kprog_arm64_stack_write_29 : Stmt :=
(Stmt.Scall none
  (Expr.Evar _arm64_sim_unsupported_opcode (Ty.Tfunction [] tvoid cc_default))
  [])

@[noinline] def s_kprog_arm64_stack_write_30 : Stmt :=
Stmt.Sbreak

@[noinline] def s_kprog_arm64_stack_write_31 : Stmt :=
(Stmt.Sset ___kprog_a64_bl_shift__7
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) tulong))

@[noinline] def s_kprog_arm64_stack_write_32 : Stmt :=
(Stmt.Sset ___kprog_a64_bl_shift__7
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tint) tulong))

@[noinline] def s_kprog_arm64_stack_write_33 : Stmt :=
(Stmt.Sset ___kprog_a64_bl_shift__7
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 16) tint) tulong))

@[noinline] def s_kprog_arm64_stack_write_34 : Stmt :=
(Stmt.Sset ___kprog_a64_bl_shift__7
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 24) tint) tulong))

@[noinline] def s_kprog_arm64_stack_write_35 : Stmt :=
(Stmt.Sset ___kprog_a64_bl_shift__7
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 32) tint) tulong))

@[noinline] def s_kprog_arm64_stack_write_36 : Stmt :=
(Stmt.Sset ___kprog_a64_bl_shift__7
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 40) tint) tulong))

@[noinline] def s_kprog_arm64_stack_write_37 : Stmt :=
(Stmt.Sset ___kprog_a64_bl_shift__7
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 48) tint) tulong))

@[noinline] def s_kprog_arm64_stack_write_38 : Stmt :=
(Stmt.Sset ___kprog_a64_bl_shift__7
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 56) tint) tulong))

@[noinline] def s_kprog_arm64_stack_write_39 : Stmt :=
(Stmt.Scall none
  (Expr.Evar _arm64_sim_unsupported_opcode (Ty.Tfunction [] tvoid cc_default))
  [])

@[noinline] def s_kprog_arm64_stack_write_40 : Stmt :=
Stmt.Sbreak

@[noinline] def s_kprog_arm64_stack_write_41 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sset ___kprog_a64_bl_lane
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) tulong))
      (Stmt.Ssequence
        (Stmt.Sset ___kprog_a64_bl_value
          (Expr.Etempvar ___a64_stw_value tulong))
        (Stmt.Ssequence
          (Stmt.Sset ___kprog_a64_bl_shift
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) tulong))
          (Stmt.Ssequence
            (Stmt.Sswitch (Expr.Etempvar ___kprog_a64_bl_lane tulong)
              (LStmts.LScons (some 0)
                (Stmt.Ssequence
                  (Stmt.Sset ___kprog_a64_bl_shift
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                      tulong))
                  Stmt.Sbreak)
                (LStmts.LScons (some 1)
                  (Stmt.Ssequence
                    (Stmt.Sset ___kprog_a64_bl_shift
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 8) tint) tulong))
                    Stmt.Sbreak)
                  (LStmts.LScons (some 2)
                    (Stmt.Ssequence
                      (Stmt.Sset ___kprog_a64_bl_shift
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 16) tint)
                          tulong))
                      Stmt.Sbreak)
                    (LStmts.LScons (some 3)
                      (Stmt.Ssequence
                        (Stmt.Sset ___kprog_a64_bl_shift
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 24) tint)
                            tulong))
                        Stmt.Sbreak)
                      (LStmts.LScons (some 4)
                        (Stmt.Ssequence
                          (Stmt.Sset ___kprog_a64_bl_shift
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 32) tint)
                              tulong))
                          Stmt.Sbreak)
                        (LStmts.LScons (some 5)
                          (Stmt.Ssequence
                            (Stmt.Sset ___kprog_a64_bl_shift
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 40) tint)
                                tulong))
                            Stmt.Sbreak)
                          (LStmts.LScons (some 6)
                            (Stmt.Ssequence
                              (Stmt.Sset ___kprog_a64_bl_shift
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 48) tint)
                                  tulong))
                              Stmt.Sbreak)
                            (LStmts.LScons (some 7)
                              (Stmt.Ssequence
                                (Stmt.Sset ___kprog_a64_bl_shift
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 56) tint)
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
                                LStmts.LSnil))))))))))
            (Stmt.Ssequence
              (Stmt.Sset _t'74
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                    (Ty.Tstruct _kprog_arm64_memory noattr)) _b
                  (tptr (tvolatile tuchar))))
              (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
                [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
                [(Expr.Eaddrof
                   (Expr.Ederef
                     (Expr.Ebinop Binop.Oadd
                       (Expr.Etempvar _t'74 (tptr (tvolatile tuchar)))
                       (Expr.Etempvar ___a64_stw_index tulong)
                       (tptr (tvolatile tuchar))) (tvolatile tuchar))
                   (tptr (tvolatile tuchar))),
                 (Expr.Ecast
                   (Expr.Ebinop Binop.Oshr
                     (Expr.Etempvar ___kprog_a64_bl_value tulong)
                     (Expr.Etempvar ___kprog_a64_bl_shift tulong) tulong)
                   tuchar)]))))))
    Stmt.Sbreak)
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                          (Expr.Etempvar ___a64_stw_width tuchar)
                          (Expr.Econst_int (Integers.Int.repr 1) tuint) tint)
        (Stmt.Sset _t'12
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar ___a64_stw_width tuchar)
                            (Expr.Econst_int (Integers.Int.repr 2) tuint)
                            tint)
          (Stmt.Ssequence
            (Stmt.Sset _t'12
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint)
                tuint))
            (Stmt.Sset _t'12 (Expr.Ecast (Expr.Etempvar _t'12 tuint) tuint)))
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar ___a64_stw_width tuchar)
                              (Expr.Econst_int (Integers.Int.repr 4) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'12
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 15) tuint)
                    tuint))
                (Stmt.Sset _t'12
                  (Expr.Ecast (Expr.Etempvar _t'12 tuint) tuint)))
              (Stmt.Sset _t'12
                (Expr.Ecast (Expr.Etempvar _t'12 tuint) tuint)))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'12
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 255) tuint)
                    tuint))
                (Stmt.Sset _t'12
                  (Expr.Ecast (Expr.Etempvar _t'12 tuint) tuint)))
              (Stmt.Sset _t'12
                (Expr.Ecast (Expr.Etempvar _t'12 tuint) tuint))))))
      (Stmt.Sifthenelse (Expr.Ecast
                          (Expr.Ebinop Binop.Oand
                            (Expr.Ebinop Binop.Oshr
                              (Expr.Etempvar _t'12 tuint)
                              (Expr.Econst_int (Integers.Int.repr 1) tint)
                              tuint)
                            (Expr.Econst_int (Integers.Int.repr 1) tuint)
                            tuint) tuchar)
        (Stmt.Sloop
          (Stmt.Ssequence
            (Stmt.Sset ___kprog_a64_bl_lane__1
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tint)
                tulong))
            (Stmt.Ssequence
              (Stmt.Sset ___kprog_a64_bl_value__1
                (Expr.Etempvar ___a64_stw_value tulong))
              (Stmt.Ssequence
                (Stmt.Sset ___kprog_a64_bl_shift__1
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                    tulong))
                (Stmt.Ssequence
                  (Stmt.Sswitch (Expr.Etempvar ___kprog_a64_bl_lane__1 tulong)
                    (LStmts.LScons (some 0)
                      (Stmt.Ssequence
                        (Stmt.Sset ___kprog_a64_bl_shift__1
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                            tulong))
                        Stmt.Sbreak)
                      (LStmts.LScons (some 1)
                        (Stmt.Ssequence
                          (Stmt.Sset ___kprog_a64_bl_shift__1
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 8) tint)
                              tulong))
                          Stmt.Sbreak)
                        (LStmts.LScons (some 2)
                          (Stmt.Ssequence
                            (Stmt.Sset ___kprog_a64_bl_shift__1
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 16) tint)
                                tulong))
                            Stmt.Sbreak)
                          (LStmts.LScons (some 3)
                            (Stmt.Ssequence
                              (Stmt.Sset ___kprog_a64_bl_shift__1
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 24) tint)
                                  tulong))
                              Stmt.Sbreak)
                            (LStmts.LScons (some 4)
                              (Stmt.Ssequence
                                (Stmt.Sset ___kprog_a64_bl_shift__1
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 32) tint)
                                    tulong))
                                Stmt.Sbreak)
                              (LStmts.LScons (some 5)
                                (Stmt.Ssequence
                                  (Stmt.Sset ___kprog_a64_bl_shift__1
                                    (Expr.Ecast
                                      (Expr.Econst_int (Integers.Int.repr 40) tint)
                                      tulong))
                                  Stmt.Sbreak)
                                (LStmts.LScons (some 6)
                                  (Stmt.Ssequence
                                    (Stmt.Sset ___kprog_a64_bl_shift__1
                                      (Expr.Ecast
                                        (Expr.Econst_int (Integers.Int.repr 48) tint)
                                        tulong))
                                    Stmt.Sbreak)
                                  (LStmts.LScons (some 7)
                                    (Stmt.Ssequence
                                      (Stmt.Sset ___kprog_a64_bl_shift__1
                                        (Expr.Ecast
                                          (Expr.Econst_int (Integers.Int.repr 56) tint)
                                          tulong))
                                      Stmt.Sbreak)
                                    (LStmts.LScons none
                                      (Stmt.Ssequence
                                        (Stmt.Sloop
                                          (Stmt.Scall none
                                            (Expr.Evar _arm64_sim_unsupported_opcode 
                                            (Ty.Tfunction [] tvoid
                                              cc_default)) [])
                                          Stmt.Sbreak)
                                        Stmt.Sbreak)
                                      LStmts.LSnil))))))))))
                  (Stmt.Ssequence
                    (Stmt.Sset _t'73
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                          (Ty.Tstruct _kprog_arm64_memory noattr)) _b
                        (tptr (tvolatile tuchar))))
                    (Stmt.Sbuiltin none
                      (ExtFun.EF_vstore Chunk.Mint8unsigned)
                      [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
                      [(Expr.Eaddrof
                         (Expr.Ederef
                           (Expr.Ebinop Binop.Oadd
                             (Expr.Etempvar _t'73 (tptr (tvolatile tuchar)))
                             (Expr.Ebinop Binop.Oadd
                               (Expr.Etempvar ___a64_stw_index tulong)
                               (Expr.Econst_int (Integers.Int.repr 1) tint)
                               tulong) (tptr (tvolatile tuchar)))
                           (tvolatile tuchar)) (tptr (tvolatile tuchar))),
                       (Expr.Ecast
                         (Expr.Ebinop Binop.Oshr
                           (Expr.Etempvar ___kprog_a64_bl_value__1 tulong)
                           (Expr.Etempvar ___kprog_a64_bl_shift__1 tulong)
                           tulong) tuchar)]))))))
          Stmt.Sbreak)
        Stmt.Sskip))
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar ___a64_stw_width tuchar)
                            (Expr.Econst_int (Integers.Int.repr 1) tuint)
                            tint)
          (Stmt.Sset _t'13
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar ___a64_stw_width tuchar)
                              (Expr.Econst_int (Integers.Int.repr 2) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Sset _t'13
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint)
                  tuint))
              (Stmt.Sset _t'13
                (Expr.Ecast (Expr.Etempvar _t'13 tuint) tuint)))
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Etempvar ___a64_stw_width tuchar)
                                (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                tint)
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sset _t'13
                    (Expr.Ecast
                      (Expr.Econst_int (Integers.Int.repr 15) tuint) tuint))
                  (Stmt.Sset _t'13
                    (Expr.Ecast (Expr.Etempvar _t'13 tuint) tuint)))
                (Stmt.Sset _t'13
                  (Expr.Ecast (Expr.Etempvar _t'13 tuint) tuint)))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sset _t'13
                    (Expr.Ecast
                      (Expr.Econst_int (Integers.Int.repr 255) tuint) tuint))
                  (Stmt.Sset _t'13
                    (Expr.Ecast (Expr.Etempvar _t'13 tuint) tuint)))
                (Stmt.Sset _t'13
                  (Expr.Ecast (Expr.Etempvar _t'13 tuint) tuint))))))
        (Stmt.Sifthenelse (Expr.Ecast
                            (Expr.Ebinop Binop.Oand
                              (Expr.Ebinop Binop.Oshr
                                (Expr.Etempvar _t'13 tuint)
                                (Expr.Econst_int (Integers.Int.repr 2) tint)
                                tuint)
                              (Expr.Econst_int (Integers.Int.repr 1) tuint)
                              tuint) tuchar)
          (Stmt.Sloop
            (Stmt.Ssequence
              (Stmt.Sset ___kprog_a64_bl_lane__2
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tint)
                  tulong))
              (Stmt.Ssequence
                (Stmt.Sset ___kprog_a64_bl_value__2
                  (Expr.Etempvar ___a64_stw_value tulong))
                (Stmt.Ssequence
                  (Stmt.Sset ___kprog_a64_bl_shift__2
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                      tulong))
                  (Stmt.Ssequence
                    (Stmt.Sswitch (Expr.Etempvar ___kprog_a64_bl_lane__2 tulong)
                      (LStmts.LScons (some 0)
                        (Stmt.Ssequence
                          (Stmt.Sset ___kprog_a64_bl_shift__2
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 0) tint)
                              tulong))
                          Stmt.Sbreak)
                        (LStmts.LScons (some 1)
                          (Stmt.Ssequence
                            (Stmt.Sset ___kprog_a64_bl_shift__2
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 8) tint)
                                tulong))
                            Stmt.Sbreak)
                          (LStmts.LScons (some 2)
                            (Stmt.Ssequence
                              (Stmt.Sset ___kprog_a64_bl_shift__2
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 16) tint)
                                  tulong))
                              Stmt.Sbreak)
                            (LStmts.LScons (some 3)
                              (Stmt.Ssequence
                                (Stmt.Sset ___kprog_a64_bl_shift__2
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 24) tint)
                                    tulong))
                                Stmt.Sbreak)
                              (LStmts.LScons (some 4)
                                (Stmt.Ssequence
                                  (Stmt.Sset ___kprog_a64_bl_shift__2
                                    (Expr.Ecast
                                      (Expr.Econst_int (Integers.Int.repr 32) tint)
                                      tulong))
                                  Stmt.Sbreak)
                                (LStmts.LScons (some 5)
                                  (Stmt.Ssequence
                                    (Stmt.Sset ___kprog_a64_bl_shift__2
                                      (Expr.Ecast
                                        (Expr.Econst_int (Integers.Int.repr 40) tint)
                                        tulong))
                                    Stmt.Sbreak)
                                  (LStmts.LScons (some 6)
                                    (Stmt.Ssequence
                                      (Stmt.Sset ___kprog_a64_bl_shift__2
                                        (Expr.Ecast
                                          (Expr.Econst_int (Integers.Int.repr 48) tint)
                                          tulong))
                                      Stmt.Sbreak)
                                    (LStmts.LScons (some 7)
                                      (Stmt.Ssequence
                                        (Stmt.Sset ___kprog_a64_bl_shift__2
                                          (Expr.Ecast
                                            (Expr.Econst_int (Integers.Int.repr 56) tint)
                                            tulong))
                                        Stmt.Sbreak)
                                      (LStmts.LScons none
                                        (Stmt.Ssequence
                                          (Stmt.Sloop
                                            (Stmt.Scall none
                                              (Expr.Evar _arm64_sim_unsupported_opcode 
                                              (Ty.Tfunction [] tvoid
                                                cc_default)) [])
                                            Stmt.Sbreak)
                                          Stmt.Sbreak)
                                        LStmts.LSnil))))))))))
                    (Stmt.Ssequence
                      (Stmt.Sset _t'72
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                            (Ty.Tstruct _kprog_arm64_memory noattr)) _b
                          (tptr (tvolatile tuchar))))
                      (Stmt.Sbuiltin none
                        (ExtFun.EF_vstore Chunk.Mint8unsigned)
                        [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
                        [(Expr.Eaddrof
                           (Expr.Ederef
                             (Expr.Ebinop Binop.Oadd
                               (Expr.Etempvar _t'72 (tptr (tvolatile tuchar)))
                               (Expr.Ebinop Binop.Oadd
                                 (Expr.Etempvar ___a64_stw_index tulong)
                                 (Expr.Econst_int (Integers.Int.repr 2) tint)
                                 tulong) (tptr (tvolatile tuchar)))
                             (tvolatile tuchar)) (tptr (tvolatile tuchar))),
                         (Expr.Ecast
                           (Expr.Ebinop Binop.Oshr
                             (Expr.Etempvar ___kprog_a64_bl_value__2 tulong)
                             (Expr.Etempvar ___kprog_a64_bl_shift__2 tulong)
                             tulong) tuchar)]))))))
            Stmt.Sbreak)
          Stmt.Sskip))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar ___a64_stw_width tuchar)
                              (Expr.Econst_int (Integers.Int.repr 1) tuint)
                              tint)
            (Stmt.Sset _t'14
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint)
                tuint))
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Etempvar ___a64_stw_width tuchar)
                                (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                tint)
              (Stmt.Ssequence
                (Stmt.Sset _t'14
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint)
                    tuint))
                (Stmt.Sset _t'14
                  (Expr.Ecast (Expr.Etempvar _t'14 tuint) tuint)))
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar ___a64_stw_width tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                  tint)
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sset _t'14
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 15) tuint) tuint))
                    (Stmt.Sset _t'14
                      (Expr.Ecast (Expr.Etempvar _t'14 tuint) tuint)))
                  (Stmt.Sset _t'14
                    (Expr.Ecast (Expr.Etempvar _t'14 tuint) tuint)))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sset _t'14
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 255) tuint)
                        tuint))
                    (Stmt.Sset _t'14
                      (Expr.Ecast (Expr.Etempvar _t'14 tuint) tuint)))
                  (Stmt.Sset _t'14
                    (Expr.Ecast (Expr.Etempvar _t'14 tuint) tuint))))))
          (Stmt.Sifthenelse (Expr.Ecast
                              (Expr.Ebinop Binop.Oand
                                (Expr.Ebinop Binop.Oshr
                                  (Expr.Etempvar _t'14 tuint)
                                  (Expr.Econst_int (Integers.Int.repr 3) tint)
                                  tuint)
                                (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                tuint) tuchar)
            (Stmt.Sloop
              (Stmt.Ssequence
                (Stmt.Sset ___kprog_a64_bl_lane__3
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tint)
                    tulong))
                (Stmt.Ssequence
                  (Stmt.Sset ___kprog_a64_bl_value__3
                    (Expr.Etempvar ___a64_stw_value tulong))
                  (Stmt.Ssequence
                    (Stmt.Sset ___kprog_a64_bl_shift__3
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 0) tint) tulong))
                    (Stmt.Ssequence
                      (Stmt.Sswitch (Expr.Etempvar ___kprog_a64_bl_lane__3 tulong)
                        (LStmts.LScons (some 0)
                          (Stmt.Ssequence
                            (Stmt.Sset ___kprog_a64_bl_shift__3
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 0) tint)
                                tulong))
                            Stmt.Sbreak)
                          (LStmts.LScons (some 1)
                            (Stmt.Ssequence
                              (Stmt.Sset ___kprog_a64_bl_shift__3
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 8) tint)
                                  tulong))
                              Stmt.Sbreak)
                            (LStmts.LScons (some 2)
                              (Stmt.Ssequence
                                (Stmt.Sset ___kprog_a64_bl_shift__3
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 16) tint)
                                    tulong))
                                Stmt.Sbreak)
                              (LStmts.LScons (some 3)
                                (Stmt.Ssequence
                                  (Stmt.Sset ___kprog_a64_bl_shift__3
                                    (Expr.Ecast
                                      (Expr.Econst_int (Integers.Int.repr 24) tint)
                                      tulong))
                                  Stmt.Sbreak)
                                (LStmts.LScons (some 4)
                                  (Stmt.Ssequence
                                    (Stmt.Sset ___kprog_a64_bl_shift__3
                                      (Expr.Ecast
                                        (Expr.Econst_int (Integers.Int.repr 32) tint)
                                        tulong))
                                    Stmt.Sbreak)
                                  (LStmts.LScons (some 5)
                                    (Stmt.Ssequence
                                      (Stmt.Sset ___kprog_a64_bl_shift__3
                                        (Expr.Ecast
                                          (Expr.Econst_int (Integers.Int.repr 40) tint)
                                          tulong))
                                      Stmt.Sbreak)
                                    (LStmts.LScons (some 6)
                                      (Stmt.Ssequence
                                        (Stmt.Sset ___kprog_a64_bl_shift__3
                                          (Expr.Ecast
                                            (Expr.Econst_int (Integers.Int.repr 48) tint)
                                            tulong))
                                        Stmt.Sbreak)
                                      (LStmts.LScons (some 7)
                                        (Stmt.Ssequence
                                          (Stmt.Sset ___kprog_a64_bl_shift__3
                                            (Expr.Ecast
                                              (Expr.Econst_int (Integers.Int.repr 56) tint)
                                              tulong))
                                          Stmt.Sbreak)
                                        (LStmts.LScons none
                                          (Stmt.Ssequence
                                            (Stmt.Sloop
                                              (Stmt.Scall none
                                                (Expr.Evar _arm64_sim_unsupported_opcode 
                                                (Ty.Tfunction [] tvoid
                                                  cc_default)) [])
                                              Stmt.Sbreak)
                                            Stmt.Sbreak)
                                          LStmts.LSnil))))))))))
                      (Stmt.Ssequence
                        (Stmt.Sset _t'71
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                              (Ty.Tstruct _kprog_arm64_memory noattr)) _b
                            (tptr (tvolatile tuchar))))
                        (Stmt.Sbuiltin none
                          (ExtFun.EF_vstore Chunk.Mint8unsigned)
                          [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
                          [(Expr.Eaddrof
                             (Expr.Ederef
                               (Expr.Ebinop Binop.Oadd
                                 (Expr.Etempvar _t'71 (tptr (tvolatile tuchar)))
                                 (Expr.Ebinop Binop.Oadd
                                   (Expr.Etempvar ___a64_stw_index tulong)
                                   (Expr.Econst_int (Integers.Int.repr 3) tint)
                                   tulong) (tptr (tvolatile tuchar)))
                               (tvolatile tuchar)) (tptr (tvolatile tuchar))),
                           (Expr.Ecast
                             (Expr.Ebinop Binop.Oshr
                               (Expr.Etempvar ___kprog_a64_bl_value__3 tulong)
                               (Expr.Etempvar ___kprog_a64_bl_shift__3 tulong)
                               tulong) tuchar)]))))))
              Stmt.Sbreak)
            Stmt.Sskip))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Etempvar ___a64_stw_width tuchar)
                                (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                tint)
              (Stmt.Sset _t'15
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint)
                  tuint))
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar ___a64_stw_width tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                  tint)
                (Stmt.Ssequence
                  (Stmt.Sset _t'15
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint)
                      tuint))
                  (Stmt.Sset _t'15
                    (Expr.Ecast (Expr.Etempvar _t'15 tuint) tuint)))
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Etempvar ___a64_stw_width tuchar)
                                    (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                    tint)
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sset _t'15
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 15) tuint)
                          tuint))
                      (Stmt.Sset _t'15
                        (Expr.Ecast (Expr.Etempvar _t'15 tuint) tuint)))
                    (Stmt.Sset _t'15
                      (Expr.Ecast (Expr.Etempvar _t'15 tuint) tuint)))
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sset _t'15
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 255) tuint)
                          tuint))
                      (Stmt.Sset _t'15
                        (Expr.Ecast (Expr.Etempvar _t'15 tuint) tuint)))
                    (Stmt.Sset _t'15
                      (Expr.Ecast (Expr.Etempvar _t'15 tuint) tuint))))))
            (Stmt.Sifthenelse (Expr.Ecast
                                (Expr.Ebinop Binop.Oand
                                  (Expr.Ebinop Binop.Oshr
                                    (Expr.Etempvar _t'15 tuint)
                                    (Expr.Econst_int (Integers.Int.repr 4) tint)
                                    tuint)
                                  (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                  tuint) tuchar)
              (Stmt.Sloop
                (Stmt.Ssequence
                  (Stmt.Sset ___kprog_a64_bl_lane__4
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 4) tint)
                      tulong))
                  (Stmt.Ssequence
                    (Stmt.Sset ___kprog_a64_bl_value__4
                      (Expr.Etempvar ___a64_stw_value tulong))
                    (Stmt.Ssequence
                      (Stmt.Sset ___kprog_a64_bl_shift__4
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                          tulong))
                      (Stmt.Ssequence
                        (Stmt.Sswitch (Expr.Etempvar ___kprog_a64_bl_lane__4 tulong)
                          (LStmts.LScons (some 0)
                            (Stmt.Ssequence
                              (Stmt.Sset ___kprog_a64_bl_shift__4
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 0) tint)
                                  tulong))
                              Stmt.Sbreak)
                            (LStmts.LScons (some 1)
                              (Stmt.Ssequence
                                (Stmt.Sset ___kprog_a64_bl_shift__4
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 8) tint)
                                    tulong))
                                Stmt.Sbreak)
                              (LStmts.LScons (some 2)
                                (Stmt.Ssequence
                                  (Stmt.Sset ___kprog_a64_bl_shift__4
                                    (Expr.Ecast
                                      (Expr.Econst_int (Integers.Int.repr 16) tint)
                                      tulong))
                                  Stmt.Sbreak)
                                (LStmts.LScons (some 3)
                                  (Stmt.Ssequence
                                    (Stmt.Sset ___kprog_a64_bl_shift__4
                                      (Expr.Ecast
                                        (Expr.Econst_int (Integers.Int.repr 24) tint)
                                        tulong))
                                    Stmt.Sbreak)
                                  (LStmts.LScons (some 4)
                                    (Stmt.Ssequence
                                      (Stmt.Sset ___kprog_a64_bl_shift__4
                                        (Expr.Ecast
                                          (Expr.Econst_int (Integers.Int.repr 32) tint)
                                          tulong))
                                      Stmt.Sbreak)
                                    (LStmts.LScons (some 5)
                                      (Stmt.Ssequence
                                        (Stmt.Sset ___kprog_a64_bl_shift__4
                                          (Expr.Ecast
                                            (Expr.Econst_int (Integers.Int.repr 40) tint)
                                            tulong))
                                        Stmt.Sbreak)
                                      (LStmts.LScons (some 6)
                                        (Stmt.Ssequence
                                          (Stmt.Sset ___kprog_a64_bl_shift__4
                                            (Expr.Ecast
                                              (Expr.Econst_int (Integers.Int.repr 48) tint)
                                              tulong))
                                          Stmt.Sbreak)
                                        (LStmts.LScons (some 7)
                                          (Stmt.Ssequence
                                            (Stmt.Sset ___kprog_a64_bl_shift__4
                                              (Expr.Ecast
                                                (Expr.Econst_int (Integers.Int.repr 56) tint)
                                                tulong))
                                            Stmt.Sbreak)
                                          (LStmts.LScons none
                                            (Stmt.Ssequence
                                              (Stmt.Sloop
                                                (Stmt.Scall none
                                                  (Expr.Evar _arm64_sim_unsupported_opcode 
                                                  (Ty.Tfunction [] tvoid
                                                    cc_default)) [])
                                                Stmt.Sbreak)
                                              Stmt.Sbreak)
                                            LStmts.LSnil))))))))))
                        (Stmt.Ssequence
                          (Stmt.Sset _t'70
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                                (Ty.Tstruct _kprog_arm64_memory noattr)) _b
                              (tptr (tvolatile tuchar))))
                          (Stmt.Sbuiltin none
                            (ExtFun.EF_vstore Chunk.Mint8unsigned)
                            [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
                            [(Expr.Eaddrof
                               (Expr.Ederef
                                 (Expr.Ebinop Binop.Oadd
                                   (Expr.Etempvar _t'70 (tptr (tvolatile tuchar)))
                                   (Expr.Ebinop Binop.Oadd
                                     (Expr.Etempvar ___a64_stw_index tulong)
                                     (Expr.Econst_int (Integers.Int.repr 4) tint)
                                     tulong) (tptr (tvolatile tuchar)))
                                 (tvolatile tuchar))
                               (tptr (tvolatile tuchar))),
                             (Expr.Ecast
                               (Expr.Ebinop Binop.Oshr
                                 (Expr.Etempvar ___kprog_a64_bl_value__4 tulong)
                                 (Expr.Etempvar ___kprog_a64_bl_shift__4 tulong)
                                 tulong) tuchar)]))))))
                Stmt.Sbreak)
              Stmt.Sskip))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar ___a64_stw_width tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                  tint)
                (Stmt.Sset _t'16
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint)
                    tuint))
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Etempvar ___a64_stw_width tuchar)
                                    (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                    tint)
                  (Stmt.Ssequence
                    (Stmt.Sset _t'16
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))
                    (Stmt.Sset _t'16
                      (Expr.Ecast (Expr.Etempvar _t'16 tuint) tuint)))
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar ___a64_stw_width tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sset _t'16
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 15) tuint)
                            tuint))
                        (Stmt.Sset _t'16
                          (Expr.Ecast (Expr.Etempvar _t'16 tuint) tuint)))
                      (Stmt.Sset _t'16
                        (Expr.Ecast (Expr.Etempvar _t'16 tuint) tuint)))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sset _t'16
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 255) tuint)
                            tuint))
                        (Stmt.Sset _t'16
                          (Expr.Ecast (Expr.Etempvar _t'16 tuint) tuint)))
                      (Stmt.Sset _t'16
                        (Expr.Ecast (Expr.Etempvar _t'16 tuint) tuint))))))
              (Stmt.Sifthenelse (Expr.Ecast
                                  (Expr.Ebinop Binop.Oand
                                    (Expr.Ebinop Binop.Oshr
                                      (Expr.Etempvar _t'16 tuint)
                                      (Expr.Econst_int (Integers.Int.repr 5) tint)
                                      tuint)
                                    (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                    tuint) tuchar)
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Sset ___kprog_a64_bl_lane__5
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 5) tint) tulong))
                    (Stmt.Ssequence
                      (Stmt.Sset ___kprog_a64_bl_value__5
                        (Expr.Etempvar ___a64_stw_value tulong))
                      (Stmt.Ssequence
                        (Stmt.Sset ___kprog_a64_bl_shift__5
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                            tulong))
                        (Stmt.Ssequence
                          (Stmt.Sswitch (Expr.Etempvar ___kprog_a64_bl_lane__5 tulong)
                            (LStmts.LScons (some 0)
                              (Stmt.Ssequence
                                (Stmt.Sset ___kprog_a64_bl_shift__5
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 0) tint)
                                    tulong))
                                Stmt.Sbreak)
                              (LStmts.LScons (some 1)
                                (Stmt.Ssequence
                                  (Stmt.Sset ___kprog_a64_bl_shift__5
                                    (Expr.Ecast
                                      (Expr.Econst_int (Integers.Int.repr 8) tint)
                                      tulong))
                                  Stmt.Sbreak)
                                (LStmts.LScons (some 2)
                                  (Stmt.Ssequence
                                    (Stmt.Sset ___kprog_a64_bl_shift__5
                                      (Expr.Ecast
                                        (Expr.Econst_int (Integers.Int.repr 16) tint)
                                        tulong))
                                    Stmt.Sbreak)
                                  (LStmts.LScons (some 3)
                                    (Stmt.Ssequence
                                      (Stmt.Sset ___kprog_a64_bl_shift__5
                                        (Expr.Ecast
                                          (Expr.Econst_int (Integers.Int.repr 24) tint)
                                          tulong))
                                      Stmt.Sbreak)
                                    (LStmts.LScons (some 4)
                                      (Stmt.Ssequence
                                        (Stmt.Sset ___kprog_a64_bl_shift__5
                                          (Expr.Ecast
                                            (Expr.Econst_int (Integers.Int.repr 32) tint)
                                            tulong))
                                        Stmt.Sbreak)
                                      (LStmts.LScons (some 5)
                                        (Stmt.Ssequence
                                          (Stmt.Sset ___kprog_a64_bl_shift__5
                                            (Expr.Ecast
                                              (Expr.Econst_int (Integers.Int.repr 40) tint)
                                              tulong))
                                          Stmt.Sbreak)
                                        (LStmts.LScons (some 6)
                                          (Stmt.Ssequence
                                            (Stmt.Sset ___kprog_a64_bl_shift__5
                                              (Expr.Ecast
                                                (Expr.Econst_int (Integers.Int.repr 48) tint)
                                                tulong))
                                            Stmt.Sbreak)
                                          (LStmts.LScons (some 7)
                                            (Stmt.Ssequence
                                              (Stmt.Sset ___kprog_a64_bl_shift__5
                                                (Expr.Ecast
                                                  (Expr.Econst_int (Integers.Int.repr 56) tint)
                                                  tulong))
                                              Stmt.Sbreak)
                                            (LStmts.LScons none
                                              (Stmt.Ssequence
                                                (Stmt.Sloop
                                                  s_kprog_arm64_stack_write_19
                                                  s_kprog_arm64_stack_write_20)
                                                Stmt.Sbreak)
                                              LStmts.LSnil))))))))))
                          (Stmt.Ssequence
                            (Stmt.Sset _t'69
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                                  (Ty.Tstruct _kprog_arm64_memory noattr)) _b
                                (tptr (tvolatile tuchar))))
                            (Stmt.Sbuiltin none
                              (ExtFun.EF_vstore Chunk.Mint8unsigned)
                              [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
                              [(Expr.Eaddrof
                                 (Expr.Ederef
                                   (Expr.Ebinop Binop.Oadd
                                     (Expr.Etempvar _t'69 (tptr (tvolatile tuchar)))
                                     (Expr.Ebinop Binop.Oadd
                                       (Expr.Etempvar ___a64_stw_index tulong)
                                       (Expr.Econst_int (Integers.Int.repr 5) tint)
                                       tulong) (tptr (tvolatile tuchar)))
                                   (tvolatile tuchar))
                                 (tptr (tvolatile tuchar))),
                               (Expr.Ecast
                                 (Expr.Ebinop Binop.Oshr
                                   (Expr.Etempvar ___kprog_a64_bl_value__5 tulong)
                                   (Expr.Etempvar ___kprog_a64_bl_shift__5 tulong)
                                   tulong) tuchar)]))))))
                  Stmt.Sbreak)
                Stmt.Sskip))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Etempvar ___a64_stw_width tuchar)
                                    (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                    tint)
                  (Stmt.Sset _t'17
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint)
                      tuint))
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar ___a64_stw_width tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Sset _t'17
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 3) tuint)
                          tuint))
                      (Stmt.Sset _t'17
                        (Expr.Ecast (Expr.Etempvar _t'17 tuint) tuint)))
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Etempvar ___a64_stw_width tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                        tint)
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sset _t'17
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 15) tuint)
                              tuint))
                          (Stmt.Sset _t'17
                            (Expr.Ecast (Expr.Etempvar _t'17 tuint) tuint)))
                        (Stmt.Sset _t'17
                          (Expr.Ecast (Expr.Etempvar _t'17 tuint) tuint)))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sset _t'17
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 255) tuint)
                              tuint))
                          (Stmt.Sset _t'17
                            (Expr.Ecast (Expr.Etempvar _t'17 tuint) tuint)))
                        (Stmt.Sset _t'17
                          (Expr.Ecast (Expr.Etempvar _t'17 tuint) tuint))))))
                (Stmt.Sifthenelse (Expr.Ecast
                                    (Expr.Ebinop Binop.Oand
                                      (Expr.Ebinop Binop.Oshr
                                        (Expr.Etempvar _t'17 tuint)
                                        (Expr.Econst_int (Integers.Int.repr 6) tint)
                                        tuint)
                                      (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                      tuint) tuchar)
                  (Stmt.Sloop
                    (Stmt.Ssequence
                      (Stmt.Sset ___kprog_a64_bl_lane__6
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 6) tint)
                          tulong))
                      (Stmt.Ssequence
                        (Stmt.Sset ___kprog_a64_bl_value__6
                          (Expr.Etempvar ___a64_stw_value tulong))
                        (Stmt.Ssequence
                          (Stmt.Sset ___kprog_a64_bl_shift__6
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 0) tint)
                              tulong))
                          (Stmt.Ssequence
                            (Stmt.Sswitch (Expr.Etempvar ___kprog_a64_bl_lane__6 tulong)
                              (LStmts.LScons (some 0)
                                (Stmt.Ssequence
                                  s_kprog_arm64_stack_write_21
                                  Stmt.Sbreak)
                                (LStmts.LScons (some 1)
                                  (Stmt.Ssequence
                                    s_kprog_arm64_stack_write_22
                                    Stmt.Sbreak)
                                  (LStmts.LScons (some 2)
                                    (Stmt.Ssequence
                                      s_kprog_arm64_stack_write_23
                                      Stmt.Sbreak)
                                    (LStmts.LScons (some 3)
                                      (Stmt.Ssequence
                                        s_kprog_arm64_stack_write_24
                                        Stmt.Sbreak)
                                      (LStmts.LScons (some 4)
                                        (Stmt.Ssequence
                                          s_kprog_arm64_stack_write_25
                                          Stmt.Sbreak)
                                        (LStmts.LScons (some 5)
                                          (Stmt.Ssequence
                                            s_kprog_arm64_stack_write_26
                                            Stmt.Sbreak)
                                          (LStmts.LScons (some 6)
                                            (Stmt.Ssequence
                                              s_kprog_arm64_stack_write_27
                                              Stmt.Sbreak)
                                            (LStmts.LScons (some 7)
                                              (Stmt.Ssequence
                                                s_kprog_arm64_stack_write_28
                                                Stmt.Sbreak)
                                              (LStmts.LScons none
                                                (Stmt.Ssequence
                                                  (Stmt.Sloop
                                                    s_kprog_arm64_stack_write_29
                                                    s_kprog_arm64_stack_write_30)
                                                  Stmt.Sbreak)
                                                LStmts.LSnil))))))))))
                            (Stmt.Ssequence
                              (Stmt.Sset _t'68
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                                    (Ty.Tstruct _kprog_arm64_memory noattr))
                                  _b (tptr (tvolatile tuchar))))
                              (Stmt.Sbuiltin none
                                (ExtFun.EF_vstore Chunk.Mint8unsigned)
                                [(tptr (tvolatile tuchar)),
                                 (tvolatile tuchar)]
                                [(Expr.Eaddrof
                                   (Expr.Ederef
                                     (Expr.Ebinop Binop.Oadd
                                       (Expr.Etempvar _t'68 (tptr (tvolatile tuchar)))
                                       (Expr.Ebinop Binop.Oadd
                                         (Expr.Etempvar ___a64_stw_index tulong)
                                         (Expr.Econst_int (Integers.Int.repr 6) tint)
                                         tulong) (tptr (tvolatile tuchar)))
                                     (tvolatile tuchar))
                                   (tptr (tvolatile tuchar))),
                                 (Expr.Ecast
                                   (Expr.Ebinop Binop.Oshr
                                     (Expr.Etempvar ___kprog_a64_bl_value__6 tulong)
                                     (Expr.Etempvar ___kprog_a64_bl_shift__6 tulong)
                                     tulong) tuchar)]))))))
                    Stmt.Sbreak)
                  Stmt.Sskip))
              (Stmt.Ssequence
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Etempvar ___a64_stw_width tuchar)
                                    (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                    tint)
                  (Stmt.Sset _t'18
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint)
                      tuint))
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar ___a64_stw_width tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Sset _t'18
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 3) tuint)
                          tuint))
                      (Stmt.Sset _t'18
                        (Expr.Ecast (Expr.Etempvar _t'18 tuint) tuint)))
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Etempvar ___a64_stw_width tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                        tint)
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sset _t'18
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 15) tuint)
                              tuint))
                          (Stmt.Sset _t'18
                            (Expr.Ecast (Expr.Etempvar _t'18 tuint) tuint)))
                        (Stmt.Sset _t'18
                          (Expr.Ecast (Expr.Etempvar _t'18 tuint) tuint)))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sset _t'18
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 255) tuint)
                              tuint))
                          (Stmt.Sset _t'18
                            (Expr.Ecast (Expr.Etempvar _t'18 tuint) tuint)))
                        (Stmt.Sset _t'18
                          (Expr.Ecast (Expr.Etempvar _t'18 tuint) tuint))))))
                (Stmt.Sifthenelse (Expr.Ecast
                                    (Expr.Ebinop Binop.Oand
                                      (Expr.Ebinop Binop.Oshr
                                        (Expr.Etempvar _t'18 tuint)
                                        (Expr.Econst_int (Integers.Int.repr 7) tint)
                                        tuint)
                                      (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                      tuint) tuchar)
                  (Stmt.Sloop
                    (Stmt.Ssequence
                      (Stmt.Sset ___kprog_a64_bl_lane__7
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 7) tint)
                          tulong))
                      (Stmt.Ssequence
                        (Stmt.Sset ___kprog_a64_bl_value__7
                          (Expr.Etempvar ___a64_stw_value tulong))
                        (Stmt.Ssequence
                          (Stmt.Sset ___kprog_a64_bl_shift__7
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 0) tint)
                              tulong))
                          (Stmt.Ssequence
                            (Stmt.Sswitch (Expr.Etempvar ___kprog_a64_bl_lane__7 tulong)
                              (LStmts.LScons (some 0)
                                (Stmt.Ssequence
                                  s_kprog_arm64_stack_write_31
                                  Stmt.Sbreak)
                                (LStmts.LScons (some 1)
                                  (Stmt.Ssequence
                                    s_kprog_arm64_stack_write_32
                                    Stmt.Sbreak)
                                  (LStmts.LScons (some 2)
                                    (Stmt.Ssequence
                                      s_kprog_arm64_stack_write_33
                                      Stmt.Sbreak)
                                    (LStmts.LScons (some 3)
                                      (Stmt.Ssequence
                                        s_kprog_arm64_stack_write_34
                                        Stmt.Sbreak)
                                      (LStmts.LScons (some 4)
                                        (Stmt.Ssequence
                                          s_kprog_arm64_stack_write_35
                                          Stmt.Sbreak)
                                        (LStmts.LScons (some 5)
                                          (Stmt.Ssequence
                                            s_kprog_arm64_stack_write_36
                                            Stmt.Sbreak)
                                          (LStmts.LScons (some 6)
                                            (Stmt.Ssequence
                                              s_kprog_arm64_stack_write_37
                                              Stmt.Sbreak)
                                            (LStmts.LScons (some 7)
                                              (Stmt.Ssequence
                                                s_kprog_arm64_stack_write_38
                                                Stmt.Sbreak)
                                              (LStmts.LScons none
                                                (Stmt.Ssequence
                                                  (Stmt.Sloop
                                                    s_kprog_arm64_stack_write_39
                                                    s_kprog_arm64_stack_write_40)
                                                  Stmt.Sbreak)
                                                LStmts.LSnil))))))))))
                            (Stmt.Ssequence
                              (Stmt.Sset _t'67
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                                    (Ty.Tstruct _kprog_arm64_memory noattr))
                                  _b (tptr (tvolatile tuchar))))
                              (Stmt.Sbuiltin none
                                (ExtFun.EF_vstore Chunk.Mint8unsigned)
                                [(tptr (tvolatile tuchar)),
                                 (tvolatile tuchar)]
                                [(Expr.Eaddrof
                                   (Expr.Ederef
                                     (Expr.Ebinop Binop.Oadd
                                       (Expr.Etempvar _t'67 (tptr (tvolatile tuchar)))
                                       (Expr.Ebinop Binop.Oadd
                                         (Expr.Etempvar ___a64_stw_index tulong)
                                         (Expr.Econst_int (Integers.Int.repr 7) tint)
                                         tulong) (tptr (tvolatile tuchar)))
                                     (tvolatile tuchar))
                                   (tptr (tvolatile tuchar))),
                                 (Expr.Ecast
                                   (Expr.Ebinop Binop.Oshr
                                     (Expr.Etempvar ___kprog_a64_bl_value__7 tulong)
                                     (Expr.Etempvar ___kprog_a64_bl_shift__7 tulong)
                                     tulong) tuchar)]))))))
                    Stmt.Sbreak)
                  Stmt.Sskip)))))))))

@[noinline] def s_kprog_arm64_stack_write_42 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'65
    (Expr.Efield
      (Expr.Ederef
        (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
        (Ty.Tstruct _kprog_arm64_memory noattr)) _coordinates
      (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))))
  (Stmt.Ssequence
    (Stmt.Sset _t'66
      (Expr.Efield
        (Expr.Ederef
          (Expr.Etempvar _t'65 (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
          (Ty.Tstruct _kprog_arm64_coordinates noattr)) _stack_offset tlong))
    (Stmt.Sset _t'38
      (Expr.Ecast
        (Expr.Ebinop Binop.Olt
          (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___a64_loss_off tlong)
            (Expr.Etempvar ___a64_loss_i tuint) tlong)
          (Expr.Etempvar _t'66 tlong) tint) tbool))))

@[noinline] def s_kprog_arm64_stack_write_43 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'64
    (Expr.Efield
      (Expr.Ederef
        (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
        (Ty.Tstruct _kprog_arm64_memory noattr)) _bias tlong))
  (Stmt.Sset ___a64_stw_index__1
    (Expr.Ebinop Binop.Oadd (Expr.Ecast (Expr.Etempvar _t'64 tlong) tulong)
      (Expr.Ecast
        (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___a64_loss_off tlong)
          (Expr.Etempvar ___a64_loss_i tuint) tlong) tulong) tulong)))

@[noinline] def s_kprog_arm64_stack_write_44 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sset _t'59
          (Expr.Efield
            (Expr.Ederef
              (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
              (Ty.Tstruct _kprog_arm64_memory noattr)) _coordinates
            (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))))
        (Stmt.Ssequence
          (Stmt.Sset _t'60
            (Expr.Efield
              (Expr.Ederef
                (Expr.Etempvar _t'59 (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                (Ty.Tstruct _kprog_arm64_coordinates noattr)) _sp_valid
              tuchar))
          (Stmt.Sifthenelse (Expr.Eunop Unop.Onotbool
                              (Expr.Etempvar _t'60 tuchar) tint)
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Scall (some _t'24)
                  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                       tulong cc_default))
                  [(Expr.Econst_int (Integers.Int.repr 1) tint)])
                (Stmt.Ssequence
                  (Stmt.Sset _t'62
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                        (Ty.Tstruct _kprog_arm64_memory noattr)) _coordinates
                      (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))))
                  (Stmt.Sassign
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar _t'62 (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                        (Ty.Tstruct _kprog_arm64_coordinates noattr))
                      _sp_base tulong) (Expr.Etempvar _t'24 tulong))))
              (Stmt.Ssequence
                (Stmt.Sset _t'61
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                      (Ty.Tstruct _kprog_arm64_memory noattr)) _coordinates
                    (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))))
                (Stmt.Sassign
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Etempvar _t'61 (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                      (Ty.Tstruct _kprog_arm64_coordinates noattr)) _sp_valid
                    tuchar) (Expr.Econst_int (Integers.Int.repr 1) tint))))
            Stmt.Sskip)))
      (Stmt.Ssequence
        (Stmt.Sset _t'58
          (Expr.Efield
            (Expr.Ederef
              (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
              (Ty.Tstruct _kprog_arm64_memory noattr)) _coordinates
            (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))))
        (Stmt.Sset ___a64_unmat_base__2
          (Expr.Efield
            (Expr.Ederef
              (Expr.Etempvar _t'58 (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
              (Ty.Tstruct _kprog_arm64_coordinates noattr)) _sp_base tulong))))
    Stmt.Sbreak)
  (Stmt.Sset ___a64_unmat_value__1
    (Expr.Ebinop Binop.Osub (Expr.Etempvar ___a64_unmat_value__1 tulong)
      (Expr.Etempvar ___a64_unmat_base__2 tulong) tulong)))

@[noinline] def s_kprog_arm64_stack_write_45 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                    (Expr.Etempvar ___a64_unmat_tag__1 tuchar)
                    (Expr.Econst_int (Integers.Int.repr 10) tuint) tint)
  (Stmt.Ssequence
    (Stmt.Sloop
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sset _t'54
            (Expr.Efield
              (Expr.Ederef
                (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                (Ty.Tstruct _kprog_arm64_memory noattr)) _coordinates
              (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))))
          (Stmt.Ssequence
            (Stmt.Sset _t'55
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar _t'54 (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                  (Ty.Tstruct _kprog_arm64_coordinates noattr)) _return_valid
                tuchar))
            (Stmt.Sifthenelse (Expr.Eunop Unop.Onotbool
                                (Expr.Etempvar _t'55 tuchar) tint)
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Scall (some _t'25)
                    (Expr.Evar _native_lab_entry_input (Ty.Tfunction 
                                                         [tuint] tulong
                                                         cc_default))
                    [(Expr.Econst_int (Integers.Int.repr 3) tint)])
                  (Stmt.Ssequence
                    (Stmt.Sset _t'57
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                          (Ty.Tstruct _kprog_arm64_memory noattr))
                        _coordinates
                        (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))))
                    (Stmt.Sassign
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar _t'57 (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                          (Ty.Tstruct _kprog_arm64_coordinates noattr))
                        _return_base tulong) (Expr.Etempvar _t'25 tulong))))
                (Stmt.Ssequence
                  (Stmt.Sset _t'56
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                        (Ty.Tstruct _kprog_arm64_memory noattr)) _coordinates
                      (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))))
                  (Stmt.Sassign
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar _t'56 (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                        (Ty.Tstruct _kprog_arm64_coordinates noattr))
                      _return_valid tuchar)
                    (Expr.Econst_int (Integers.Int.repr 1) tint))))
              Stmt.Sskip)))
        (Stmt.Ssequence
          (Stmt.Sset _t'53
            (Expr.Efield
              (Expr.Ederef
                (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                (Ty.Tstruct _kprog_arm64_memory noattr)) _coordinates
              (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))))
          (Stmt.Sset ___a64_unmat_base__3
            (Expr.Efield
              (Expr.Ederef
                (Expr.Etempvar _t'53 (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                (Ty.Tstruct _kprog_arm64_coordinates noattr)) _return_base
              tulong))))
      Stmt.Sbreak)
    (Stmt.Sset ___a64_unmat_value__1
      (Expr.Ebinop Binop.Osub (Expr.Etempvar ___a64_unmat_value__1 tulong)
        (Expr.Etempvar ___a64_unmat_base__3 tulong) tulong)))
  Stmt.Sskip)

@[noinline] def s_kprog_arm64_stack_write_46 : Stmt :=
(Stmt.Sset _t'29
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 4) tuint) tuint))

@[noinline] def s_kprog_arm64_stack_write_47 : Stmt :=
(Stmt.Sset _t'29
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint))

@[noinline] def s_kprog_arm64_stack_write_48 : Stmt :=
(Stmt.Sbuiltin (some _t'30) (ExtFun.EF_vload Chunk.Mint64)
  [(tptr (tvolatile tulong))]
  [(Expr.Eaddrof
     (Expr.Ederef (Expr.Etempvar ___tp__5 (tptr (tvolatile tulong)))
       (tvolatile tulong)) (tptr (tvolatile tulong)))])

@[noinline] def s_kprog_arm64_stack_write_49 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___kprog_a64_bl_shift__8
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) tulong))
  Stmt.Sbreak)

@[noinline] def s_kprog_arm64_stack_write_50 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___kprog_a64_bl_shift__8
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tint) tulong))
  Stmt.Sbreak)

@[noinline] def s_kprog_arm64_stack_write_51 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___kprog_a64_bl_shift__8
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 16) tint) tulong))
  Stmt.Sbreak)

@[noinline] def s_kprog_arm64_stack_write_52 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___kprog_a64_bl_shift__8
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 24) tint) tulong))
  Stmt.Sbreak)

@[noinline] def s_kprog_arm64_stack_write_53 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___kprog_a64_bl_shift__8
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 32) tint) tulong))
  Stmt.Sbreak)

@[noinline] def s_kprog_arm64_stack_write_54 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___kprog_a64_bl_shift__8
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 40) tint) tulong))
  Stmt.Sbreak)

@[noinline] def s_kprog_arm64_stack_write_55 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___kprog_a64_bl_shift__8
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 48) tint) tulong))
  Stmt.Sbreak)

@[noinline] def s_kprog_arm64_stack_write_56 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___kprog_a64_bl_shift__8
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 56) tint) tulong))
  Stmt.Sbreak)

@[noinline] def s_kprog_arm64_stack_write_57 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Scall none
      (Expr.Evar _arm64_sim_unsupported_opcode (Ty.Tfunction [] tvoid
                                                 cc_default)) [])
    Stmt.Sbreak)
  Stmt.Sbreak)

@[noinline] def s_kprog_arm64_stack_write_58 : Stmt :=
(Stmt.Sset _t'31
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))

@[noinline] def s_kprog_arm64_stack_write_59 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'31
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 15) tuint) tuint))
    (Stmt.Sset _t'31 (Expr.Ecast (Expr.Etempvar _t'31 tuint) tuint)))
  (Stmt.Sset _t'31 (Expr.Ecast (Expr.Etempvar _t'31 tuint) tuint)))

@[noinline] def s_kprog_arm64_stack_write_60 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'31
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 255) tuint) tuint))
    (Stmt.Sset _t'31 (Expr.Ecast (Expr.Etempvar _t'31 tuint) tuint)))
  (Stmt.Sset _t'31 (Expr.Ecast (Expr.Etempvar _t'31 tuint) tuint)))

@[noinline] def s_kprog_arm64_stack_write_61 : Stmt :=
(Stmt.Sset ___kprog_a64_bl_shift__9
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) tulong))

@[noinline] def s_kprog_arm64_stack_write_62 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sswitch (Expr.Etempvar ___kprog_a64_bl_lane__9 tulong)
    (LStmts.LScons (some 0)
      (Stmt.Ssequence
        (Stmt.Sset ___kprog_a64_bl_shift__9
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) tulong))
        Stmt.Sbreak)
      (LStmts.LScons (some 1)
        (Stmt.Ssequence
          (Stmt.Sset ___kprog_a64_bl_shift__9
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tint) tulong))
          Stmt.Sbreak)
        (LStmts.LScons (some 2)
          (Stmt.Ssequence
            (Stmt.Sset ___kprog_a64_bl_shift__9
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 16) tint)
                tulong))
            Stmt.Sbreak)
          (LStmts.LScons (some 3)
            (Stmt.Ssequence
              (Stmt.Sset ___kprog_a64_bl_shift__9
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 24) tint)
                  tulong))
              Stmt.Sbreak)
            (LStmts.LScons (some 4)
              (Stmt.Ssequence
                (Stmt.Sset ___kprog_a64_bl_shift__9
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 32) tint)
                    tulong))
                Stmt.Sbreak)
              (LStmts.LScons (some 5)
                (Stmt.Ssequence
                  (Stmt.Sset ___kprog_a64_bl_shift__9
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 40) tint)
                      tulong))
                  Stmt.Sbreak)
                (LStmts.LScons (some 6)
                  (Stmt.Ssequence
                    (Stmt.Sset ___kprog_a64_bl_shift__9
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 48) tint) tulong))
                    Stmt.Sbreak)
                  (LStmts.LScons (some 7)
                    (Stmt.Ssequence
                      (Stmt.Sset ___kprog_a64_bl_shift__9
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 56) tint)
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
                      LStmts.LSnil))))))))))
  (Stmt.Ssequence
    (Stmt.Sset _t'47
      (Expr.Efield
        (Expr.Ederef
          (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
          (Ty.Tstruct _kprog_arm64_memory noattr)) _b
        (tptr (tvolatile tuchar))))
    (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
      [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
      [(Expr.Eaddrof
         (Expr.Ederef
           (Expr.Ebinop Binop.Oadd
             (Expr.Etempvar _t'47 (tptr (tvolatile tuchar)))
             (Expr.Ebinop Binop.Oadd
               (Expr.Etempvar ___a64_stw_index__1 tulong)
               (Expr.Econst_int (Integers.Int.repr 1) tint) tulong)
             (tptr (tvolatile tuchar))) (tvolatile tuchar))
         (tptr (tvolatile tuchar))),
       (Expr.Ecast
         (Expr.Ebinop Binop.Oshr
           (Expr.Etempvar ___kprog_a64_bl_value__9 tulong)
           (Expr.Etempvar ___kprog_a64_bl_shift__9 tulong) tulong) tuchar)])))

@[noinline] def s_kprog_arm64_stack_write_63 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'32
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))
  (Stmt.Sset _t'32 (Expr.Ecast (Expr.Etempvar _t'32 tuint) tuint)))

@[noinline] def s_kprog_arm64_stack_write_64 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                    (Expr.Etempvar ___a64_stw_width__1 tuchar)
                    (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sset _t'32
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 15) tuint) tuint))
      (Stmt.Sset _t'32 (Expr.Ecast (Expr.Etempvar _t'32 tuint) tuint)))
    (Stmt.Sset _t'32 (Expr.Ecast (Expr.Etempvar _t'32 tuint) tuint)))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sset _t'32
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 255) tuint) tuint))
      (Stmt.Sset _t'32 (Expr.Ecast (Expr.Etempvar _t'32 tuint) tuint)))
    (Stmt.Sset _t'32 (Expr.Ecast (Expr.Etempvar _t'32 tuint) tuint))))

@[noinline] def s_kprog_arm64_stack_write_65 : Stmt :=
(Stmt.Sset ___kprog_a64_bl_value__10
  (Expr.Etempvar ___a64_stw_value__1 tulong))

@[noinline] def s_kprog_arm64_stack_write_66 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___kprog_a64_bl_shift__10
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) tulong))
  (Stmt.Ssequence
    (Stmt.Sswitch (Expr.Etempvar ___kprog_a64_bl_lane__10 tulong)
      (LStmts.LScons (some 0)
        (Stmt.Ssequence
          (Stmt.Sset ___kprog_a64_bl_shift__10
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) tulong))
          Stmt.Sbreak)
        (LStmts.LScons (some 1)
          (Stmt.Ssequence
            (Stmt.Sset ___kprog_a64_bl_shift__10
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tint)
                tulong))
            Stmt.Sbreak)
          (LStmts.LScons (some 2)
            (Stmt.Ssequence
              (Stmt.Sset ___kprog_a64_bl_shift__10
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 16) tint)
                  tulong))
              Stmt.Sbreak)
            (LStmts.LScons (some 3)
              (Stmt.Ssequence
                (Stmt.Sset ___kprog_a64_bl_shift__10
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 24) tint)
                    tulong))
                Stmt.Sbreak)
              (LStmts.LScons (some 4)
                (Stmt.Ssequence
                  (Stmt.Sset ___kprog_a64_bl_shift__10
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 32) tint)
                      tulong))
                  Stmt.Sbreak)
                (LStmts.LScons (some 5)
                  (Stmt.Ssequence
                    (Stmt.Sset ___kprog_a64_bl_shift__10
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 40) tint) tulong))
                    Stmt.Sbreak)
                  (LStmts.LScons (some 6)
                    (Stmt.Ssequence
                      (Stmt.Sset ___kprog_a64_bl_shift__10
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 48) tint)
                          tulong))
                      Stmt.Sbreak)
                    (LStmts.LScons (some 7)
                      (Stmt.Ssequence
                        (Stmt.Sset ___kprog_a64_bl_shift__10
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 56) tint)
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
                        LStmts.LSnil))))))))))
    (Stmt.Ssequence
      (Stmt.Sset _t'46
        (Expr.Efield
          (Expr.Ederef
            (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
            (Ty.Tstruct _kprog_arm64_memory noattr)) _b
          (tptr (tvolatile tuchar))))
      (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
        [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
        [(Expr.Eaddrof
           (Expr.Ederef
             (Expr.Ebinop Binop.Oadd
               (Expr.Etempvar _t'46 (tptr (tvolatile tuchar)))
               (Expr.Ebinop Binop.Oadd
                 (Expr.Etempvar ___a64_stw_index__1 tulong)
                 (Expr.Econst_int (Integers.Int.repr 2) tint) tulong)
               (tptr (tvolatile tuchar))) (tvolatile tuchar))
           (tptr (tvolatile tuchar))),
         (Expr.Ecast
           (Expr.Ebinop Binop.Oshr
             (Expr.Etempvar ___kprog_a64_bl_value__10 tulong)
             (Expr.Etempvar ___kprog_a64_bl_shift__10 tulong) tulong) tuchar)]))))

@[noinline] def s_kprog_arm64_stack_write_67 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'33
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))
  (Stmt.Sset _t'33 (Expr.Ecast (Expr.Etempvar _t'33 tuint) tuint)))

@[noinline] def s_kprog_arm64_stack_write_68 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                    (Expr.Etempvar ___a64_stw_width__1 tuchar)
                    (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sset _t'33
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 15) tuint) tuint))
      (Stmt.Sset _t'33 (Expr.Ecast (Expr.Etempvar _t'33 tuint) tuint)))
    (Stmt.Sset _t'33 (Expr.Ecast (Expr.Etempvar _t'33 tuint) tuint)))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sset _t'33
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 255) tuint) tuint))
      (Stmt.Sset _t'33 (Expr.Ecast (Expr.Etempvar _t'33 tuint) tuint)))
    (Stmt.Sset _t'33 (Expr.Ecast (Expr.Etempvar _t'33 tuint) tuint))))

@[noinline] def s_kprog_arm64_stack_write_69 : Stmt :=
(Stmt.Sset ___kprog_a64_bl_lane__11
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tint) tulong))

@[noinline] def s_kprog_arm64_stack_write_70 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___kprog_a64_bl_value__11
    (Expr.Etempvar ___a64_stw_value__1 tulong))
  (Stmt.Ssequence
    (Stmt.Sset ___kprog_a64_bl_shift__11
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) tulong))
    (Stmt.Ssequence
      (Stmt.Sswitch (Expr.Etempvar ___kprog_a64_bl_lane__11 tulong)
        (LStmts.LScons (some 0)
          (Stmt.Ssequence
            (Stmt.Sset ___kprog_a64_bl_shift__11
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                tulong))
            Stmt.Sbreak)
          (LStmts.LScons (some 1)
            (Stmt.Ssequence
              (Stmt.Sset ___kprog_a64_bl_shift__11
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tint)
                  tulong))
              Stmt.Sbreak)
            (LStmts.LScons (some 2)
              (Stmt.Ssequence
                (Stmt.Sset ___kprog_a64_bl_shift__11
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 16) tint)
                    tulong))
                Stmt.Sbreak)
              (LStmts.LScons (some 3)
                (Stmt.Ssequence
                  (Stmt.Sset ___kprog_a64_bl_shift__11
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 24) tint)
                      tulong))
                  Stmt.Sbreak)
                (LStmts.LScons (some 4)
                  (Stmt.Ssequence
                    (Stmt.Sset ___kprog_a64_bl_shift__11
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 32) tint) tulong))
                    Stmt.Sbreak)
                  (LStmts.LScons (some 5)
                    (Stmt.Ssequence
                      (Stmt.Sset ___kprog_a64_bl_shift__11
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 40) tint)
                          tulong))
                      Stmt.Sbreak)
                    (LStmts.LScons (some 6)
                      (Stmt.Ssequence
                        (Stmt.Sset ___kprog_a64_bl_shift__11
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 48) tint)
                            tulong))
                        Stmt.Sbreak)
                      (LStmts.LScons (some 7)
                        (Stmt.Ssequence
                          (Stmt.Sset ___kprog_a64_bl_shift__11
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 56) tint)
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
                          LStmts.LSnil))))))))))
      (Stmt.Ssequence
        (Stmt.Sset _t'45
          (Expr.Efield
            (Expr.Ederef
              (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
              (Ty.Tstruct _kprog_arm64_memory noattr)) _b
            (tptr (tvolatile tuchar))))
        (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
          [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
          [(Expr.Eaddrof
             (Expr.Ederef
               (Expr.Ebinop Binop.Oadd
                 (Expr.Etempvar _t'45 (tptr (tvolatile tuchar)))
                 (Expr.Ebinop Binop.Oadd
                   (Expr.Etempvar ___a64_stw_index__1 tulong)
                   (Expr.Econst_int (Integers.Int.repr 3) tint) tulong)
                 (tptr (tvolatile tuchar))) (tvolatile tuchar))
             (tptr (tvolatile tuchar))),
           (Expr.Ecast
             (Expr.Ebinop Binop.Oshr
               (Expr.Etempvar ___kprog_a64_bl_value__11 tulong)
               (Expr.Etempvar ___kprog_a64_bl_shift__11 tulong) tulong)
             tuchar)])))))

@[noinline] def s_kprog_arm64_stack_write_71 : Stmt :=
(Stmt.Sset _t'34
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))

@[noinline] def s_kprog_arm64_stack_write_72 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                    (Expr.Etempvar ___a64_stw_width__1 tuchar)
                    (Expr.Econst_int (Integers.Int.repr 2) tuint) tint)
  (Stmt.Ssequence
    (Stmt.Sset _t'34
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))
    (Stmt.Sset _t'34 (Expr.Ecast (Expr.Etempvar _t'34 tuint) tuint)))
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Etempvar ___a64_stw_width__1 tuchar)
                      (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sset _t'34
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 15) tuint) tuint))
        (Stmt.Sset _t'34 (Expr.Ecast (Expr.Etempvar _t'34 tuint) tuint)))
      (Stmt.Sset _t'34 (Expr.Ecast (Expr.Etempvar _t'34 tuint) tuint)))
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sset _t'34
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 255) tuint) tuint))
        (Stmt.Sset _t'34 (Expr.Ecast (Expr.Etempvar _t'34 tuint) tuint)))
      (Stmt.Sset _t'34 (Expr.Ecast (Expr.Etempvar _t'34 tuint) tuint)))))

@[noinline] def s_kprog_arm64_stack_write_73 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___kprog_a64_bl_lane__12
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 4) tint) tulong))
  (Stmt.Ssequence
    (Stmt.Sset ___kprog_a64_bl_value__12
      (Expr.Etempvar ___a64_stw_value__1 tulong))
    (Stmt.Ssequence
      (Stmt.Sset ___kprog_a64_bl_shift__12
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) tulong))
      (Stmt.Ssequence
        (Stmt.Sswitch (Expr.Etempvar ___kprog_a64_bl_lane__12 tulong)
          (LStmts.LScons (some 0)
            (Stmt.Ssequence
              (Stmt.Sset ___kprog_a64_bl_shift__12
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                  tulong))
              Stmt.Sbreak)
            (LStmts.LScons (some 1)
              (Stmt.Ssequence
                (Stmt.Sset ___kprog_a64_bl_shift__12
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tint)
                    tulong))
                Stmt.Sbreak)
              (LStmts.LScons (some 2)
                (Stmt.Ssequence
                  (Stmt.Sset ___kprog_a64_bl_shift__12
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 16) tint)
                      tulong))
                  Stmt.Sbreak)
                (LStmts.LScons (some 3)
                  (Stmt.Ssequence
                    (Stmt.Sset ___kprog_a64_bl_shift__12
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 24) tint) tulong))
                    Stmt.Sbreak)
                  (LStmts.LScons (some 4)
                    (Stmt.Ssequence
                      (Stmt.Sset ___kprog_a64_bl_shift__12
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 32) tint)
                          tulong))
                      Stmt.Sbreak)
                    (LStmts.LScons (some 5)
                      (Stmt.Ssequence
                        (Stmt.Sset ___kprog_a64_bl_shift__12
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 40) tint)
                            tulong))
                        Stmt.Sbreak)
                      (LStmts.LScons (some 6)
                        (Stmt.Ssequence
                          (Stmt.Sset ___kprog_a64_bl_shift__12
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 48) tint)
                              tulong))
                          Stmt.Sbreak)
                        (LStmts.LScons (some 7)
                          (Stmt.Ssequence
                            (Stmt.Sset ___kprog_a64_bl_shift__12
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 56) tint)
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
                            LStmts.LSnil))))))))))
        (Stmt.Ssequence
          (Stmt.Sset _t'44
            (Expr.Efield
              (Expr.Ederef
                (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                (Ty.Tstruct _kprog_arm64_memory noattr)) _b
              (tptr (tvolatile tuchar))))
          (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
            [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
            [(Expr.Eaddrof
               (Expr.Ederef
                 (Expr.Ebinop Binop.Oadd
                   (Expr.Etempvar _t'44 (tptr (tvolatile tuchar)))
                   (Expr.Ebinop Binop.Oadd
                     (Expr.Etempvar ___a64_stw_index__1 tulong)
                     (Expr.Econst_int (Integers.Int.repr 4) tint) tulong)
                   (tptr (tvolatile tuchar))) (tvolatile tuchar))
               (tptr (tvolatile tuchar))),
             (Expr.Ecast
               (Expr.Ebinop Binop.Oshr
                 (Expr.Etempvar ___kprog_a64_bl_value__12 tulong)
                 (Expr.Etempvar ___kprog_a64_bl_shift__12 tulong) tulong)
               tuchar)]))))))

@[noinline] def s_kprog_arm64_stack_write_74 : Stmt :=
Stmt.Sbreak

@[noinline] def s_kprog_arm64_stack_write_75 : Stmt :=
(Stmt.Sset _t'35
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))

@[noinline] def s_kprog_arm64_stack_write_76 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                    (Expr.Etempvar ___a64_stw_width__1 tuchar)
                    (Expr.Econst_int (Integers.Int.repr 2) tuint) tint)
  (Stmt.Ssequence
    (Stmt.Sset _t'35
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))
    (Stmt.Sset _t'35 (Expr.Ecast (Expr.Etempvar _t'35 tuint) tuint)))
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Etempvar ___a64_stw_width__1 tuchar)
                      (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sset _t'35
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 15) tuint) tuint))
        (Stmt.Sset _t'35 (Expr.Ecast (Expr.Etempvar _t'35 tuint) tuint)))
      (Stmt.Sset _t'35 (Expr.Ecast (Expr.Etempvar _t'35 tuint) tuint)))
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sset _t'35
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 255) tuint) tuint))
        (Stmt.Sset _t'35 (Expr.Ecast (Expr.Etempvar _t'35 tuint) tuint)))
      (Stmt.Sset _t'35 (Expr.Ecast (Expr.Etempvar _t'35 tuint) tuint)))))

@[noinline] def s_kprog_arm64_stack_write_77 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___kprog_a64_bl_lane__13
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 5) tint) tulong))
  (Stmt.Ssequence
    (Stmt.Sset ___kprog_a64_bl_value__13
      (Expr.Etempvar ___a64_stw_value__1 tulong))
    (Stmt.Ssequence
      (Stmt.Sset ___kprog_a64_bl_shift__13
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) tulong))
      (Stmt.Ssequence
        (Stmt.Sswitch (Expr.Etempvar ___kprog_a64_bl_lane__13 tulong)
          (LStmts.LScons (some 0)
            (Stmt.Ssequence
              (Stmt.Sset ___kprog_a64_bl_shift__13
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                  tulong))
              Stmt.Sbreak)
            (LStmts.LScons (some 1)
              (Stmt.Ssequence
                (Stmt.Sset ___kprog_a64_bl_shift__13
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tint)
                    tulong))
                Stmt.Sbreak)
              (LStmts.LScons (some 2)
                (Stmt.Ssequence
                  (Stmt.Sset ___kprog_a64_bl_shift__13
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 16) tint)
                      tulong))
                  Stmt.Sbreak)
                (LStmts.LScons (some 3)
                  (Stmt.Ssequence
                    (Stmt.Sset ___kprog_a64_bl_shift__13
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 24) tint) tulong))
                    Stmt.Sbreak)
                  (LStmts.LScons (some 4)
                    (Stmt.Ssequence
                      (Stmt.Sset ___kprog_a64_bl_shift__13
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 32) tint)
                          tulong))
                      Stmt.Sbreak)
                    (LStmts.LScons (some 5)
                      (Stmt.Ssequence
                        (Stmt.Sset ___kprog_a64_bl_shift__13
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 40) tint)
                            tulong))
                        Stmt.Sbreak)
                      (LStmts.LScons (some 6)
                        (Stmt.Ssequence
                          (Stmt.Sset ___kprog_a64_bl_shift__13
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 48) tint)
                              tulong))
                          Stmt.Sbreak)
                        (LStmts.LScons (some 7)
                          (Stmt.Ssequence
                            (Stmt.Sset ___kprog_a64_bl_shift__13
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 56) tint)
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
                            LStmts.LSnil))))))))))
        (Stmt.Ssequence
          (Stmt.Sset _t'43
            (Expr.Efield
              (Expr.Ederef
                (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                (Ty.Tstruct _kprog_arm64_memory noattr)) _b
              (tptr (tvolatile tuchar))))
          (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
            [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
            [(Expr.Eaddrof
               (Expr.Ederef
                 (Expr.Ebinop Binop.Oadd
                   (Expr.Etempvar _t'43 (tptr (tvolatile tuchar)))
                   (Expr.Ebinop Binop.Oadd
                     (Expr.Etempvar ___a64_stw_index__1 tulong)
                     (Expr.Econst_int (Integers.Int.repr 5) tint) tulong)
                   (tptr (tvolatile tuchar))) (tvolatile tuchar))
               (tptr (tvolatile tuchar))),
             (Expr.Ecast
               (Expr.Ebinop Binop.Oshr
                 (Expr.Etempvar ___kprog_a64_bl_value__13 tulong)
                 (Expr.Etempvar ___kprog_a64_bl_shift__13 tulong) tulong)
               tuchar)]))))))

@[noinline] def s_kprog_arm64_stack_write_78 : Stmt :=
Stmt.Sbreak

@[noinline] def s_kprog_arm64_stack_write_79 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                    (Expr.Etempvar ___a64_stw_width__1 tuchar)
                    (Expr.Econst_int (Integers.Int.repr 1) tuint) tint)
  (Stmt.Sset _t'36
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Etempvar ___a64_stw_width__1 tuchar)
                      (Expr.Econst_int (Integers.Int.repr 2) tuint) tint)
    (Stmt.Ssequence
      (Stmt.Sset _t'36
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))
      (Stmt.Sset _t'36 (Expr.Ecast (Expr.Etempvar _t'36 tuint) tuint)))
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                        (Expr.Etempvar ___a64_stw_width__1 tuchar)
                        (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sset _t'36
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 15) tuint) tuint))
          (Stmt.Sset _t'36 (Expr.Ecast (Expr.Etempvar _t'36 tuint) tuint)))
        (Stmt.Sset _t'36 (Expr.Ecast (Expr.Etempvar _t'36 tuint) tuint)))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sset _t'36
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 255) tuint)
              tuint))
          (Stmt.Sset _t'36 (Expr.Ecast (Expr.Etempvar _t'36 tuint) tuint)))
        (Stmt.Sset _t'36 (Expr.Ecast (Expr.Etempvar _t'36 tuint) tuint))))))

@[noinline] def s_kprog_arm64_stack_write_80 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___kprog_a64_bl_lane__14
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 6) tint) tulong))
  (Stmt.Ssequence
    (Stmt.Sset ___kprog_a64_bl_value__14
      (Expr.Etempvar ___a64_stw_value__1 tulong))
    (Stmt.Ssequence
      (Stmt.Sset ___kprog_a64_bl_shift__14
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) tulong))
      (Stmt.Ssequence
        (Stmt.Sswitch (Expr.Etempvar ___kprog_a64_bl_lane__14 tulong)
          (LStmts.LScons (some 0)
            (Stmt.Ssequence
              (Stmt.Sset ___kprog_a64_bl_shift__14
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                  tulong))
              Stmt.Sbreak)
            (LStmts.LScons (some 1)
              (Stmt.Ssequence
                (Stmt.Sset ___kprog_a64_bl_shift__14
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tint)
                    tulong))
                Stmt.Sbreak)
              (LStmts.LScons (some 2)
                (Stmt.Ssequence
                  (Stmt.Sset ___kprog_a64_bl_shift__14
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 16) tint)
                      tulong))
                  Stmt.Sbreak)
                (LStmts.LScons (some 3)
                  (Stmt.Ssequence
                    (Stmt.Sset ___kprog_a64_bl_shift__14
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 24) tint) tulong))
                    Stmt.Sbreak)
                  (LStmts.LScons (some 4)
                    (Stmt.Ssequence
                      (Stmt.Sset ___kprog_a64_bl_shift__14
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 32) tint)
                          tulong))
                      Stmt.Sbreak)
                    (LStmts.LScons (some 5)
                      (Stmt.Ssequence
                        (Stmt.Sset ___kprog_a64_bl_shift__14
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 40) tint)
                            tulong))
                        Stmt.Sbreak)
                      (LStmts.LScons (some 6)
                        (Stmt.Ssequence
                          (Stmt.Sset ___kprog_a64_bl_shift__14
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 48) tint)
                              tulong))
                          Stmt.Sbreak)
                        (LStmts.LScons (some 7)
                          (Stmt.Ssequence
                            (Stmt.Sset ___kprog_a64_bl_shift__14
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 56) tint)
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
                            LStmts.LSnil))))))))))
        (Stmt.Ssequence
          (Stmt.Sset _t'42
            (Expr.Efield
              (Expr.Ederef
                (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                (Ty.Tstruct _kprog_arm64_memory noattr)) _b
              (tptr (tvolatile tuchar))))
          (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
            [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
            [(Expr.Eaddrof
               (Expr.Ederef
                 (Expr.Ebinop Binop.Oadd
                   (Expr.Etempvar _t'42 (tptr (tvolatile tuchar)))
                   (Expr.Ebinop Binop.Oadd
                     (Expr.Etempvar ___a64_stw_index__1 tulong)
                     (Expr.Econst_int (Integers.Int.repr 6) tint) tulong)
                   (tptr (tvolatile tuchar))) (tvolatile tuchar))
               (tptr (tvolatile tuchar))),
             (Expr.Ecast
               (Expr.Ebinop Binop.Oshr
                 (Expr.Etempvar ___kprog_a64_bl_value__14 tulong)
                 (Expr.Etempvar ___kprog_a64_bl_shift__14 tulong) tulong)
               tuchar)]))))))

@[noinline] def s_kprog_arm64_stack_write_81 : Stmt :=
Stmt.Sbreak

@[noinline] def s_kprog_arm64_stack_write_82 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                    (Expr.Etempvar ___a64_stw_width__1 tuchar)
                    (Expr.Econst_int (Integers.Int.repr 1) tuint) tint)
  (Stmt.Sset _t'37
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Etempvar ___a64_stw_width__1 tuchar)
                      (Expr.Econst_int (Integers.Int.repr 2) tuint) tint)
    (Stmt.Ssequence
      (Stmt.Sset _t'37
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))
      (Stmt.Sset _t'37 (Expr.Ecast (Expr.Etempvar _t'37 tuint) tuint)))
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                        (Expr.Etempvar ___a64_stw_width__1 tuchar)
                        (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sset _t'37
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 15) tuint) tuint))
          (Stmt.Sset _t'37 (Expr.Ecast (Expr.Etempvar _t'37 tuint) tuint)))
        (Stmt.Sset _t'37 (Expr.Ecast (Expr.Etempvar _t'37 tuint) tuint)))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sset _t'37
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 255) tuint)
              tuint))
          (Stmt.Sset _t'37 (Expr.Ecast (Expr.Etempvar _t'37 tuint) tuint)))
        (Stmt.Sset _t'37 (Expr.Ecast (Expr.Etempvar _t'37 tuint) tuint))))))

@[noinline] def s_kprog_arm64_stack_write_83 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___kprog_a64_bl_lane__15
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 7) tint) tulong))
  (Stmt.Ssequence
    (Stmt.Sset ___kprog_a64_bl_value__15
      (Expr.Etempvar ___a64_stw_value__1 tulong))
    (Stmt.Ssequence
      (Stmt.Sset ___kprog_a64_bl_shift__15
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) tulong))
      (Stmt.Ssequence
        (Stmt.Sswitch (Expr.Etempvar ___kprog_a64_bl_lane__15 tulong)
          (LStmts.LScons (some 0)
            (Stmt.Ssequence
              (Stmt.Sset ___kprog_a64_bl_shift__15
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                  tulong))
              Stmt.Sbreak)
            (LStmts.LScons (some 1)
              (Stmt.Ssequence
                (Stmt.Sset ___kprog_a64_bl_shift__15
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tint)
                    tulong))
                Stmt.Sbreak)
              (LStmts.LScons (some 2)
                (Stmt.Ssequence
                  (Stmt.Sset ___kprog_a64_bl_shift__15
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 16) tint)
                      tulong))
                  Stmt.Sbreak)
                (LStmts.LScons (some 3)
                  (Stmt.Ssequence
                    (Stmt.Sset ___kprog_a64_bl_shift__15
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 24) tint) tulong))
                    Stmt.Sbreak)
                  (LStmts.LScons (some 4)
                    (Stmt.Ssequence
                      (Stmt.Sset ___kprog_a64_bl_shift__15
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 32) tint)
                          tulong))
                      Stmt.Sbreak)
                    (LStmts.LScons (some 5)
                      (Stmt.Ssequence
                        (Stmt.Sset ___kprog_a64_bl_shift__15
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 40) tint)
                            tulong))
                        Stmt.Sbreak)
                      (LStmts.LScons (some 6)
                        (Stmt.Ssequence
                          (Stmt.Sset ___kprog_a64_bl_shift__15
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 48) tint)
                              tulong))
                          Stmt.Sbreak)
                        (LStmts.LScons (some 7)
                          (Stmt.Ssequence
                            (Stmt.Sset ___kprog_a64_bl_shift__15
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 56) tint)
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
                            LStmts.LSnil))))))))))
        (Stmt.Ssequence
          (Stmt.Sset _t'41
            (Expr.Efield
              (Expr.Ederef
                (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                (Ty.Tstruct _kprog_arm64_memory noattr)) _b
              (tptr (tvolatile tuchar))))
          (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
            [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
            [(Expr.Eaddrof
               (Expr.Ederef
                 (Expr.Ebinop Binop.Oadd
                   (Expr.Etempvar _t'41 (tptr (tvolatile tuchar)))
                   (Expr.Ebinop Binop.Oadd
                     (Expr.Etempvar ___a64_stw_index__1 tulong)
                     (Expr.Econst_int (Integers.Int.repr 7) tint) tulong)
                   (tptr (tvolatile tuchar))) (tvolatile tuchar))
               (tptr (tvolatile tuchar))),
             (Expr.Ecast
               (Expr.Ebinop Binop.Oshr
                 (Expr.Etempvar ___kprog_a64_bl_value__15 tulong)
                 (Expr.Etempvar ___kprog_a64_bl_shift__15 tulong) tulong)
               tuchar)]))))))

@[noinline] def s_kprog_arm64_stack_write_84 : Stmt :=
Stmt.Sbreak

@[noinline] def s_kprog_arm64_stack_write_85 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___a64_stw_width__1
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuchar))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Scall (some _t'19)
          (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                               cc_default))
          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar ___a64_stw_width__1 tuchar)
                            (Expr.Econst_int (Integers.Int.repr 1) tuint)
                            tint)
          (Stmt.Sset _t'20
            (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 255) tulong)
              tulong))
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar ___a64_stw_width__1 tuchar)
                              (Expr.Econst_int (Integers.Int.repr 2) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Sset _t'20
                (Expr.Ecast
                  (Expr.Econst_long (Integers.Int64.repr 65535) tulong)
                  tulong))
              (Stmt.Sset _t'20
                (Expr.Ecast (Expr.Etempvar _t'20 tulong) tulong)))
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Etempvar ___a64_stw_width__1 tuchar)
                                (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                tint)
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sset _t'20
                    (Expr.Ecast
                      (Expr.Econst_long (Integers.Int64.repr 4294967295) tulong)
                      tulong))
                  (Stmt.Sset _t'20
                    (Expr.Ecast (Expr.Etempvar _t'20 tulong) tulong)))
                (Stmt.Sset _t'20
                  (Expr.Ecast (Expr.Etempvar _t'20 tulong) tulong)))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sset _t'20
                    (Expr.Ecast
                      (Expr.Econst_long (Integers.Int64.repr (-1)) tulong)
                      tulong))
                  (Stmt.Sset _t'20
                    (Expr.Ecast (Expr.Etempvar _t'20 tulong) tulong)))
                (Stmt.Sset _t'20
                  (Expr.Ecast (Expr.Etempvar _t'20 tulong) tulong)))))))
      (Stmt.Sset ___a64_stw_value__1
        (Expr.Ebinop Binop.Oand (Expr.Etempvar _t'19 tulong)
          (Expr.Etempvar _t'20 tulong) tulong)))
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar ___a64_stw_width__1 tuchar)
                              (Expr.Econst_int (Integers.Int.repr 8) tuint)
                              tint)
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Ebinop Binop.Oand
                                  (Expr.Ecast
                                    (Expr.Etempvar ___a64_stw_index__1 tulong)
                                    tuint)
                                  (Expr.Econst_int (Integers.Int.repr 7) tuint)
                                  tuint)
                                (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                tint)
              (Stmt.Ssequence
                (Stmt.Sset _t'21
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tint)
                    tint))
                (Stmt.Sset _t'21
                  (Expr.Ecast (Expr.Etempvar _t'21 tint) tbool)))
              (Stmt.Ssequence
                (Stmt.Sset _t'21
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                    tint))
                (Stmt.Sset _t'21
                  (Expr.Ecast (Expr.Etempvar _t'21 tint) tbool))))
            (Stmt.Sset _t'21 (Expr.Econst_int (Integers.Int.repr 0) tint)))
          (Stmt.Sifthenelse (Expr.Etempvar _t'21 tint)
            (Stmt.Sset _t'22
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                tuint))
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Ebinop Binop.Oand
                                    (Expr.Ecast
                                      (Expr.Etempvar ___a64_stw_index__1 tulong)
                                      tuint)
                                    (Expr.Econst_int (Integers.Int.repr 7) tuint)
                                    tuint)
                                  (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                  tint)
                (Stmt.Sset _t'23
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tint)
                    tint))
                (Stmt.Sset _t'23
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                    tint)))
              (Stmt.Sifthenelse (Expr.Etempvar _t'23 tint)
                (Stmt.Ssequence
                  (Stmt.Sset _t'22
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint)
                      tuint))
                  (Stmt.Sset _t'22
                    (Expr.Ecast (Expr.Etempvar _t'22 tuint) tuint)))
                (Stmt.Ssequence
                  (Stmt.Sset _t'22
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint)
                      tuint))
                  (Stmt.Sset _t'22
                    (Expr.Ecast (Expr.Etempvar _t'22 tuint) tuint)))))))
        (Stmt.Sset ___a64_stw_action__1
          (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'22 tuint) tuchar) tuchar)))
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                          (Expr.Etempvar ___a64_stw_action__1 tuchar)
                          (Expr.Econst_int (Integers.Int.repr 0) tuint) tint)
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sset _t'63
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                  (Ty.Tstruct _kprog_arm64_memory noattr)) _q
                (tptr (tvolatile tulong))))
            (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
              [(tptr (tvolatile tulong)), (tvolatile tulong)]
              [(Expr.Eaddrof
                 (Expr.Ederef
                   (Expr.Ebinop Binop.Oadd
                     (Expr.Etempvar _t'63 (tptr (tvolatile tulong)))
                     (Expr.Ebinop Binop.Oshr
                       (Expr.Ecast (Expr.Etempvar ___a64_stw_index__1 tulong)
                         tulong) (Expr.Econst_int (Integers.Int.repr 3) tint)
                       tulong) (tptr (tvolatile tulong))) (tvolatile tulong))
                 (tptr (tvolatile tulong))),
               (Expr.Etempvar ___a64_stw_value__1 tulong)]))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                  (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                  tint)
                (Stmt.Sset _t'26
                  (Expr.Econst_int (Integers.Int.repr 1) tint))
                (Stmt.Sset _t'26
                  (Expr.Ecast
                    (Expr.Ebinop Binop.Oeq
                      (Expr.Econst_int (Integers.Int.repr 0) tuint)
                      (Expr.Econst_int (Integers.Int.repr 10) tuint) tint)
                    tbool)))
              (Stmt.Sifthenelse (Expr.Etempvar _t'26 tint)
                (Stmt.Ssequence
                  (Stmt.Sloop
                    (Stmt.Ssequence
                      (Stmt.Sset ___a64_unmat_value__1
                        (Expr.Etempvar ___a64_stw_value__1 tulong))
                      (Stmt.Ssequence
                        (Stmt.Sset ___a64_unmat_tag__1
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tuint)
                            tuchar))
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Etempvar ___a64_unmat_tag__1 tuchar)
                                              (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                              tint)
                            s_kprog_arm64_stack_write_44
                            s_kprog_arm64_stack_write_45)
                          (Stmt.Sset ___a64_stw_payload__1
                            (Expr.Etempvar ___a64_unmat_value__1 tulong)))))
                    Stmt.Sbreak)
                  (Stmt.Sloop
                    (Stmt.Ssequence
                      (Stmt.Sset _t'52
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                            (Ty.Tstruct _kprog_arm64_memory noattr)) _payload
                          (tptr tulong)))
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar _t'52 (tptr tulong))
                            (Expr.Ebinop Binop.Oshr
                              (Expr.Ecast
                                (Expr.Etempvar ___a64_stw_index__1 tulong)
                                tulong)
                              (Expr.Econst_int (Integers.Int.repr 3) tint)
                              tulong) (tptr tulong)) tulong)
                        (Expr.Etempvar ___a64_stw_payload__1 tulong)))
                    Stmt.Sbreak))
                Stmt.Sskip))
            (Stmt.Sloop
              (Stmt.Ssequence
                (Stmt.Sset ___ti__3
                  (Expr.Ebinop Binop.Oshr
                    (Expr.Ecast (Expr.Etempvar ___a64_stw_index__1 tulong)
                      tulong) (Expr.Econst_int (Integers.Int.repr 3) tint)
                    tulong))
                (Stmt.Ssequence
                  (Stmt.Sset ___ts__3
                    (Expr.Ecast
                      (Expr.Ebinop Binop.Omul
                        (Expr.Ebinop Binop.Oand
                          (Expr.Etempvar ___ti__3 tulong)
                          (Expr.Econst_int (Integers.Int.repr 7) tuint)
                          tulong)
                        (Expr.Econst_int (Integers.Int.repr 8) tuint) tulong)
                      tuint))
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sset _t'51
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                            (Ty.Tstruct _kprog_arm64_memory noattr)) _tags
                          (tptr tuchar)))
                      (Stmt.Sset ___tp__3
                        (Expr.Ecast
                          (Expr.Ecast
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar _t'51 (tptr tuchar))
                              (Expr.Ebinop Binop.Oand
                                (Expr.Ecast (Expr.Etempvar ___ti__3 tulong)
                                  tulong)
                                (Expr.Eunop Unop.Onotint
                                  (Expr.Econst_long (Integers.Int64.repr 7) tulong)
                                  tulong) tulong) (tptr tuchar))
                            (tptr tvoid)) (tptr (tvolatile tulong)))))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sbuiltin (some _t'27)
                          (ExtFun.EF_vload Chunk.Mint64)
                          [(tptr (tvolatile tulong))]
                          [(Expr.Eaddrof
                             (Expr.Ederef
                               (Expr.Etempvar ___tp__3 (tptr (tvolatile tulong)))
                               (tvolatile tulong)) (tptr (tvolatile tulong)))])
                        (Stmt.Sset ___tv__3
                          (Expr.Etempvar _t'27 (tvolatile tulong))))
                      (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
                        [(tptr (tvolatile tulong)), (tvolatile tulong)]
                        [(Expr.Eaddrof
                           (Expr.Ederef
                             (Expr.Etempvar ___tp__3 (tptr (tvolatile tulong)))
                             (tvolatile tulong)) (tptr (tvolatile tulong))),
                         (Expr.Ebinop Binop.Oor
                           (Expr.Ebinop Binop.Oand
                             (Expr.Etempvar ___tv__3 tulong)
                             (Expr.Eunop Unop.Onotint
                               (Expr.Ebinop Binop.Oshl
                                 (Expr.Econst_long (Integers.Int64.repr 255) tulong)
                                 (Expr.Etempvar ___ts__3 tuint) tulong)
                               tulong) tulong)
                           (Expr.Ebinop Binop.Oshl
                             (Expr.Ecast
                               (Expr.Ecast
                                 (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                 tuchar) tulong)
                             (Expr.Etempvar ___ts__3 tuint) tulong) tulong)])))))
              Stmt.Sbreak)))
        (Stmt.Ssequence
          (Stmt.Sloop
            (Stmt.Ssequence
              (Stmt.Sset ___ti__4
                (Expr.Ebinop Binop.Oshr
                  (Expr.Ecast (Expr.Etempvar ___a64_stw_index__1 tulong)
                    tulong) (Expr.Econst_int (Integers.Int.repr 3) tint)
                  tulong))
              (Stmt.Ssequence
                (Stmt.Sset ___ts__4
                  (Expr.Ecast
                    (Expr.Ebinop Binop.Omul
                      (Expr.Ebinop Binop.Oand (Expr.Etempvar ___ti__4 tulong)
                        (Expr.Econst_int (Integers.Int.repr 7) tuint) tulong)
                      (Expr.Econst_int (Integers.Int.repr 8) tuint) tulong)
                    tuint))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sset _t'50
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                          (Ty.Tstruct _kprog_arm64_memory noattr)) _tags
                        (tptr tuchar)))
                    (Stmt.Sset ___tp__4
                      (Expr.Ecast
                        (Expr.Ecast
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar _t'50 (tptr tuchar))
                            (Expr.Ebinop Binop.Oand
                              (Expr.Ecast (Expr.Etempvar ___ti__4 tulong)
                                tulong)
                              (Expr.Eunop Unop.Onotint
                                (Expr.Econst_long (Integers.Int64.repr 7) tulong)
                                tulong) tulong) (tptr tuchar)) (tptr tvoid))
                        (tptr (tvolatile tulong)))))
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sbuiltin (some _t'28)
                        (ExtFun.EF_vload Chunk.Mint64)
                        [(tptr (tvolatile tulong))]
                        [(Expr.Eaddrof
                           (Expr.Ederef
                             (Expr.Etempvar ___tp__4 (tptr (tvolatile tulong)))
                             (tvolatile tulong)) (tptr (tvolatile tulong)))])
                      (Stmt.Sset ___tv__4
                        (Expr.Etempvar _t'28 (tvolatile tulong))))
                    (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
                      [(tptr (tvolatile tulong)), (tvolatile tulong)]
                      [(Expr.Eaddrof
                         (Expr.Ederef
                           (Expr.Etempvar ___tp__4 (tptr (tvolatile tulong)))
                           (tvolatile tulong)) (tptr (tvolatile tulong))),
                       (Expr.Ebinop Binop.Oor
                         (Expr.Ebinop Binop.Oand
                           (Expr.Etempvar ___tv__4 tulong)
                           (Expr.Eunop Unop.Onotint
                             (Expr.Ebinop Binop.Oshl
                               (Expr.Econst_long (Integers.Int64.repr 255) tulong)
                               (Expr.Etempvar ___ts__4 tuint) tulong) tulong)
                           tulong)
                         (Expr.Ebinop Binop.Oshl
                           (Expr.Ecast
                             (Expr.Ecast
                               (Expr.Econst_int (Integers.Int.repr 0) tuint)
                               tuchar) tulong) (Expr.Etempvar ___ts__4 tuint)
                           tulong) tulong)])))))
            Stmt.Sbreak)
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar ___a64_stw_width__1 tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                  tint)
                (Stmt.Sset _t'29
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint)
                    tuint))
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Etempvar ___a64_stw_width__1 tuchar)
                                    (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                    tint)
                  (Stmt.Ssequence
                    (Stmt.Sset _t'29
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 2) tuint) tuint))
                    (Stmt.Sset _t'29
                      (Expr.Ecast (Expr.Etempvar _t'29 tuint) tuint)))
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar ___a64_stw_width__1 tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        s_kprog_arm64_stack_write_46
                        (Stmt.Sset _t'29
                          (Expr.Ecast (Expr.Etempvar _t'29 tuint) tuint)))
                      (Stmt.Sset _t'29
                        (Expr.Ecast (Expr.Etempvar _t'29 tuint) tuint)))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        s_kprog_arm64_stack_write_47
                        (Stmt.Sset _t'29
                          (Expr.Ecast (Expr.Etempvar _t'29 tuint) tuint)))
                      (Stmt.Sset _t'29
                        (Expr.Ecast (Expr.Etempvar _t'29 tuint) tuint))))))
              (Stmt.Sset ___a64_stw_last__1
                (Expr.Ebinop Binop.Osub
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Etempvar ___a64_stw_index__1 tulong)
                    (Expr.Etempvar _t'29 tuint) tulong)
                  (Expr.Econst_int (Integers.Int.repr 1) tuint) tulong)))
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.One
                                  (Expr.Ebinop Binop.Oshr
                                    (Expr.Ecast
                                      (Expr.Etempvar ___a64_stw_last__1 tulong)
                                      tulong)
                                    (Expr.Econst_int (Integers.Int.repr 3) tint)
                                    tulong)
                                  (Expr.Ebinop Binop.Oshr
                                    (Expr.Ecast
                                      (Expr.Etempvar ___a64_stw_index__1 tulong)
                                      tulong)
                                    (Expr.Econst_int (Integers.Int.repr 3) tint)
                                    tulong) tint)
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Sset ___ti__5
                      (Expr.Ebinop Binop.Oshr
                        (Expr.Ecast (Expr.Etempvar ___a64_stw_last__1 tulong)
                          tulong)
                        (Expr.Econst_int (Integers.Int.repr 3) tint) tulong))
                    (Stmt.Ssequence
                      (Stmt.Sset ___ts__5
                        (Expr.Ecast
                          (Expr.Ebinop Binop.Omul
                            (Expr.Ebinop Binop.Oand
                              (Expr.Etempvar ___ti__5 tulong)
                              (Expr.Econst_int (Integers.Int.repr 7) tuint)
                              tulong)
                            (Expr.Econst_int (Integers.Int.repr 8) tuint)
                            tulong) tuint))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sset _t'49
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                                (Ty.Tstruct _kprog_arm64_memory noattr))
                              _tags (tptr tuchar)))
                          (Stmt.Sset ___tp__5
                            (Expr.Ecast
                              (Expr.Ecast
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Etempvar _t'49 (tptr tuchar))
                                  (Expr.Ebinop Binop.Oand
                                    (Expr.Ecast
                                      (Expr.Etempvar ___ti__5 tulong) tulong)
                                    (Expr.Eunop Unop.Onotint
                                      (Expr.Econst_long (Integers.Int64.repr 7) tulong)
                                      tulong) tulong) (tptr tuchar))
                                (tptr tvoid)) (tptr (tvolatile tulong)))))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            s_kprog_arm64_stack_write_48
                            (Stmt.Sset ___tv__5
                              (Expr.Etempvar _t'30 (tvolatile tulong))))
                          (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
                            [(tptr (tvolatile tulong)), (tvolatile tulong)]
                            [(Expr.Eaddrof
                               (Expr.Ederef
                                 (Expr.Etempvar ___tp__5 (tptr (tvolatile tulong)))
                                 (tvolatile tulong))
                               (tptr (tvolatile tulong))),
                             (Expr.Ebinop Binop.Oor
                               (Expr.Ebinop Binop.Oand
                                 (Expr.Etempvar ___tv__5 tulong)
                                 (Expr.Eunop Unop.Onotint
                                   (Expr.Ebinop Binop.Oshl
                                     (Expr.Econst_long (Integers.Int64.repr 255) tulong)
                                     (Expr.Etempvar ___ts__5 tuint) tulong)
                                   tulong) tulong)
                               (Expr.Ebinop Binop.Oshl
                                 (Expr.Ecast
                                   (Expr.Ecast
                                     (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                     tuchar) tulong)
                                 (Expr.Etempvar ___ts__5 tuint) tulong)
                               tulong)])))))
                  Stmt.Sbreak)
                Stmt.Sskip)
              (Stmt.Ssequence
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Sset ___kprog_a64_bl_lane__8
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 0) tint) tulong))
                    (Stmt.Ssequence
                      (Stmt.Sset ___kprog_a64_bl_value__8
                        (Expr.Etempvar ___a64_stw_value__1 tulong))
                      (Stmt.Ssequence
                        (Stmt.Sset ___kprog_a64_bl_shift__8
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                            tulong))
                        (Stmt.Ssequence
                          (Stmt.Sswitch (Expr.Etempvar ___kprog_a64_bl_lane__8 tulong)
                            (LStmts.LScons (some 0)
                              s_kprog_arm64_stack_write_49
                              (LStmts.LScons (some 1)
                                s_kprog_arm64_stack_write_50
                                (LStmts.LScons (some 2)
                                  s_kprog_arm64_stack_write_51
                                  (LStmts.LScons (some 3)
                                    s_kprog_arm64_stack_write_52
                                    (LStmts.LScons (some 4)
                                      s_kprog_arm64_stack_write_53
                                      (LStmts.LScons (some 5)
                                        s_kprog_arm64_stack_write_54
                                        (LStmts.LScons (some 6)
                                          s_kprog_arm64_stack_write_55
                                          (LStmts.LScons (some 7)
                                            s_kprog_arm64_stack_write_56
                                            (LStmts.LScons none
                                              s_kprog_arm64_stack_write_57
                                              LStmts.LSnil))))))))))
                          (Stmt.Ssequence
                            (Stmt.Sset _t'48
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                                  (Ty.Tstruct _kprog_arm64_memory noattr)) _b
                                (tptr (tvolatile tuchar))))
                            (Stmt.Sbuiltin none
                              (ExtFun.EF_vstore Chunk.Mint8unsigned)
                              [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
                              [(Expr.Eaddrof
                                 (Expr.Ederef
                                   (Expr.Ebinop Binop.Oadd
                                     (Expr.Etempvar _t'48 (tptr (tvolatile tuchar)))
                                     (Expr.Etempvar ___a64_stw_index__1 tulong)
                                     (tptr (tvolatile tuchar)))
                                   (tvolatile tuchar))
                                 (tptr (tvolatile tuchar))),
                               (Expr.Ecast
                                 (Expr.Ebinop Binop.Oshr
                                   (Expr.Etempvar ___kprog_a64_bl_value__8 tulong)
                                   (Expr.Etempvar ___kprog_a64_bl_shift__8 tulong)
                                   tulong) tuchar)]))))))
                  Stmt.Sbreak)
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Etempvar ___a64_stw_width__1 tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                        tint)
                      (Stmt.Sset _t'31
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 1) tuint)
                          tuint))
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Etempvar ___a64_stw_width__1 tuchar)
                                          (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                          tint)
                        (Stmt.Ssequence
                          s_kprog_arm64_stack_write_58
                          (Stmt.Sset _t'31
                            (Expr.Ecast (Expr.Etempvar _t'31 tuint) tuint)))
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Etempvar ___a64_stw_width__1 tuchar)
                                            (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                            tint)
                          s_kprog_arm64_stack_write_59
                          s_kprog_arm64_stack_write_60)))
                    (Stmt.Sifthenelse (Expr.Ecast
                                        (Expr.Ebinop Binop.Oand
                                          (Expr.Ebinop Binop.Oshr
                                            (Expr.Etempvar _t'31 tuint)
                                            (Expr.Econst_int (Integers.Int.repr 1) tint)
                                            tuint)
                                          (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                          tuint) tuchar)
                      (Stmt.Sloop
                        (Stmt.Ssequence
                          (Stmt.Sset ___kprog_a64_bl_lane__9
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 1) tint)
                              tulong))
                          (Stmt.Ssequence
                            (Stmt.Sset ___kprog_a64_bl_value__9
                              (Expr.Etempvar ___a64_stw_value__1 tulong))
                            (Stmt.Ssequence
                              s_kprog_arm64_stack_write_61
                              s_kprog_arm64_stack_write_62)))
                        Stmt.Sbreak)
                      Stmt.Sskip))
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Etempvar ___a64_stw_width__1 tuchar)
                                          (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                          tint)
                        (Stmt.Sset _t'32
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 1) tuint)
                            tuint))
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Etempvar ___a64_stw_width__1 tuchar)
                                            (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                            tint)
                          s_kprog_arm64_stack_write_63
                          s_kprog_arm64_stack_write_64))
                      (Stmt.Sifthenelse (Expr.Ecast
                                          (Expr.Ebinop Binop.Oand
                                            (Expr.Ebinop Binop.Oshr
                                              (Expr.Etempvar _t'32 tuint)
                                              (Expr.Econst_int (Integers.Int.repr 2) tint)
                                              tuint)
                                            (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                            tuint) tuchar)
                        (Stmt.Sloop
                          (Stmt.Ssequence
                            (Stmt.Sset ___kprog_a64_bl_lane__10
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 2) tint)
                                tulong))
                            (Stmt.Ssequence
                              s_kprog_arm64_stack_write_65
                              s_kprog_arm64_stack_write_66))
                          Stmt.Sbreak)
                        Stmt.Sskip))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Etempvar ___a64_stw_width__1 tuchar)
                                            (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                            tint)
                          (Stmt.Sset _t'33
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 1) tuint)
                              tuint))
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Etempvar ___a64_stw_width__1 tuchar)
                                              (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                              tint)
                            s_kprog_arm64_stack_write_67
                            s_kprog_arm64_stack_write_68))
                        (Stmt.Sifthenelse (Expr.Ecast
                                            (Expr.Ebinop Binop.Oand
                                              (Expr.Ebinop Binop.Oshr
                                                (Expr.Etempvar _t'33 tuint)
                                                (Expr.Econst_int (Integers.Int.repr 3) tint)
                                                tuint)
                                              (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                              tuint) tuchar)
                          (Stmt.Sloop
                            (Stmt.Ssequence
                              s_kprog_arm64_stack_write_69
                              s_kprog_arm64_stack_write_70)
                            Stmt.Sbreak)
                          Stmt.Sskip))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Etempvar ___a64_stw_width__1 tuchar)
                                              (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                              tint)
                            s_kprog_arm64_stack_write_71
                            s_kprog_arm64_stack_write_72)
                          (Stmt.Sifthenelse (Expr.Ecast
                                              (Expr.Ebinop Binop.Oand
                                                (Expr.Ebinop Binop.Oshr
                                                  (Expr.Etempvar _t'34 tuint)
                                                  (Expr.Econst_int (Integers.Int.repr 4) tint)
                                                  tuint)
                                                (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                                tuint) tuchar)
                            (Stmt.Sloop
                              s_kprog_arm64_stack_write_73
                              s_kprog_arm64_stack_write_74)
                            Stmt.Sskip))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                (Expr.Etempvar ___a64_stw_width__1 tuchar)
                                                (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                                tint)
                              s_kprog_arm64_stack_write_75
                              s_kprog_arm64_stack_write_76)
                            (Stmt.Sifthenelse (Expr.Ecast
                                                (Expr.Ebinop Binop.Oand
                                                  (Expr.Ebinop Binop.Oshr
                                                    (Expr.Etempvar _t'35 tuint)
                                                    (Expr.Econst_int (Integers.Int.repr 5) tint)
                                                    tuint)
                                                  (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                                  tuint) tuchar)
                              (Stmt.Sloop
                                s_kprog_arm64_stack_write_77
                                s_kprog_arm64_stack_write_78)
                              Stmt.Sskip))
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              s_kprog_arm64_stack_write_79
                              (Stmt.Sifthenelse (Expr.Ecast
                                                  (Expr.Ebinop Binop.Oand
                                                    (Expr.Ebinop Binop.Oshr
                                                      (Expr.Etempvar _t'36 tuint)
                                                      (Expr.Econst_int (Integers.Int.repr 6) tint)
                                                      tuint)
                                                    (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                                    tuint) tuchar)
                                (Stmt.Sloop
                                  s_kprog_arm64_stack_write_80
                                  s_kprog_arm64_stack_write_81)
                                Stmt.Sskip))
                            (Stmt.Ssequence
                              s_kprog_arm64_stack_write_82
                              (Stmt.Sifthenelse (Expr.Ecast
                                                  (Expr.Ebinop Binop.Oand
                                                    (Expr.Ebinop Binop.Oshr
                                                      (Expr.Etempvar _t'37 tuint)
                                                      (Expr.Econst_int (Integers.Int.repr 7) tint)
                                                      tuint)
                                                    (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                                    tuint) tuchar)
                                (Stmt.Sloop
                                  s_kprog_arm64_stack_write_83
                                  s_kprog_arm64_stack_write_84)
                                Stmt.Sskip))))))))))))))))

@[noinline] def l_kprog_arm64_stack_write_temps_0 : List (Ident × Ty) :=
[(___a64_loss_off, tlong), (___a64_loss_width, tuchar),
 (___a64_loss_value, tulong), (___a64_stw_index, tulong),
 (___a64_stw_width, tuchar), (___a64_stw_value, tulong),
 (___a64_stw_action, tuchar), (___a64_stw_payload, tulong),
 (___a64_unmat_value, tulong), (___a64_unmat_tag, tuchar),
 (___a64_unmat_base, tulong), (___a64_unmat_base__1, tulong),
 (___ti, tulong), (___ts, tuint), (___tp, (tptr (tvolatile tulong))),
 (___tv, tulong), (___ti__1, tulong), (___ts__1, tuint),
 (___tp__1, (tptr (tvolatile tulong))), (___tv__1, tulong),
 (___a64_stw_last, tulong), (___ti__2, tulong), (___ts__2, tuint),
 (___tp__2, (tptr (tvolatile tulong))), (___tv__2, tulong),
 (___kprog_a64_bl_lane, tulong), (___kprog_a64_bl_value, tulong),
 (___kprog_a64_bl_shift, tulong), (___kprog_a64_bl_lane__1, tulong),
 (___kprog_a64_bl_value__1, tulong), (___kprog_a64_bl_shift__1, tulong),
 (___kprog_a64_bl_lane__2, tulong), (___kprog_a64_bl_value__2, tulong),
 (___kprog_a64_bl_shift__2, tulong), (___kprog_a64_bl_lane__3, tulong),
 (___kprog_a64_bl_value__3, tulong), (___kprog_a64_bl_shift__3, tulong),
 (___kprog_a64_bl_lane__4, tulong), (___kprog_a64_bl_value__4, tulong),
 (___kprog_a64_bl_shift__4, tulong), (___kprog_a64_bl_lane__5, tulong),
 (___kprog_a64_bl_value__5, tulong), (___kprog_a64_bl_shift__5, tulong),
 (___kprog_a64_bl_lane__6, tulong), (___kprog_a64_bl_value__6, tulong),
 (___kprog_a64_bl_shift__6, tulong), (___kprog_a64_bl_lane__7, tulong),
 (___kprog_a64_bl_value__7, tulong), (___kprog_a64_bl_shift__7, tulong),
 (___a64_loss_i, tuint), (___a64_stw_index__1, tulong),
 (___a64_stw_width__1, tuchar), (___a64_stw_value__1, tulong),
 (___a64_stw_action__1, tuchar), (___a64_stw_payload__1, tulong),
 (___a64_unmat_value__1, tulong), (___a64_unmat_tag__1, tuchar),
 (___a64_unmat_base__2, tulong), (___a64_unmat_base__3, tulong),
 (___ti__3, tulong), (___ts__3, tuint),
 (___tp__3, (tptr (tvolatile tulong))), (___tv__3, tulong),
 (___ti__4, tulong), (___ts__4, tuint),
 (___tp__4, (tptr (tvolatile tulong))), (___tv__4, tulong),
 (___a64_stw_last__1, tulong), (___ti__5, tulong), (___ts__5, tuint),
 (___tp__5, (tptr (tvolatile tulong))), (___tv__5, tulong),
 (___kprog_a64_bl_lane__8, tulong), (___kprog_a64_bl_value__8, tulong),
 (___kprog_a64_bl_shift__8, tulong), (___kprog_a64_bl_lane__9, tulong),
 (___kprog_a64_bl_value__9, tulong), (___kprog_a64_bl_shift__9, tulong),
 (___kprog_a64_bl_lane__10, tulong), (___kprog_a64_bl_value__10, tulong),
 (___kprog_a64_bl_shift__10, tulong), (___kprog_a64_bl_lane__11, tulong),
 (___kprog_a64_bl_value__11, tulong), (___kprog_a64_bl_shift__11, tulong),
 (___kprog_a64_bl_lane__12, tulong), (___kprog_a64_bl_value__12, tulong),
 (___kprog_a64_bl_shift__12, tulong), (___kprog_a64_bl_lane__13, tulong),
 (___kprog_a64_bl_value__13, tulong), (___kprog_a64_bl_shift__13, tulong),
 (___kprog_a64_bl_lane__14, tulong), (___kprog_a64_bl_value__14, tulong),
 (___kprog_a64_bl_shift__14, tulong)]

@[noinline] def l_kprog_arm64_stack_write_temps_1 : List (Ident × Ty) :=
[(___kprog_a64_bl_lane__15, tulong), (___kprog_a64_bl_value__15, tulong),
 (___kprog_a64_bl_shift__15, tulong), (_t'38, tint), (_t'37, tuint),
 (_t'36, tuint), (_t'35, tuint), (_t'34, tuint), (_t'33, tuint),
 (_t'32, tuint), (_t'31, tuint), (_t'30, (tvolatile tulong)), (_t'29, tuint),
 (_t'28, (tvolatile tulong)), (_t'27, (tvolatile tulong)), (_t'26, tint),
 (_t'25, tulong), (_t'24, tulong), (_t'23, tint), (_t'22, tuint),
 (_t'21, tint), (_t'20, tulong), (_t'19, tulong), (_t'18, tuint),
 (_t'17, tuint), (_t'16, tuint), (_t'15, tuint), (_t'14, tuint),
 (_t'13, tuint), (_t'12, tuint), (_t'11, (tvolatile tulong)), (_t'10, tuint),
 (_t'9, (tvolatile tulong)), (_t'8, (tvolatile tulong)), (_t'7, tint),
 (_t'6, tulong), (_t'5, tulong), (_t'4, tint), (_t'3, tuint), (_t'2, tint),
 (_t'1, tulong), (_t'90, tlong), (_t'89, (tptr (tvolatile tulong))),
 (_t'88, (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))),
 (_t'87, (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))),
 (_t'86, tuchar),
 (_t'85, (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))),
 (_t'84, (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))),
 (_t'83, (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))),
 (_t'82, (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))),
 (_t'81, tuchar),
 (_t'80, (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))),
 (_t'79, (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))),
 (_t'78, (tptr tulong)), (_t'77, (tptr tuchar)), (_t'76, (tptr tuchar)),
 (_t'75, (tptr tuchar)), (_t'74, (tptr (tvolatile tuchar))),
 (_t'73, (tptr (tvolatile tuchar))), (_t'72, (tptr (tvolatile tuchar))),
 (_t'71, (tptr (tvolatile tuchar))), (_t'70, (tptr (tvolatile tuchar))),
 (_t'69, (tptr (tvolatile tuchar))), (_t'68, (tptr (tvolatile tuchar))),
 (_t'67, (tptr (tvolatile tuchar))), (_t'66, tlong),
 (_t'65, (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))),
 (_t'64, tlong), (_t'63, (tptr (tvolatile tulong))),
 (_t'62, (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))),
 (_t'61, (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))),
 (_t'60, tuchar),
 (_t'59, (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))),
 (_t'58, (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))),
 (_t'57, (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))),
 (_t'56, (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))),
 (_t'55, tuchar),
 (_t'54, (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))),
 (_t'53, (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))),
 (_t'52, (tptr tulong)), (_t'51, (tptr tuchar)), (_t'50, (tptr tuchar)),
 (_t'49, (tptr tuchar)), (_t'48, (tptr (tvolatile tuchar))),
 (_t'47, (tptr (tvolatile tuchar))), (_t'46, (tptr (tvolatile tuchar))),
 (_t'45, (tptr (tvolatile tuchar))), (_t'44, (tptr (tvolatile tuchar))),
 (_t'43, (tptr (tvolatile tuchar))), (_t'42, (tptr (tvolatile tuchar))),
 (_t'41, (tptr (tvolatile tuchar))), (_t'40, tlong),
 (_t'39, (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))]

def f_kprog_arm64_stack_write : Function := {
  fn_return := tvoid,
  fn_callconv := cc_default,
  fn_params := [(_memory, (tptr (Ty.Tstruct _kprog_arm64_memory noattr))),
                (_off, tlong), (_width, tuchar), (_value, tulong),
                (_tag, tuchar)],
  fn_vars := [],
  fn_temps := (l_kprog_arm64_stack_write_temps_0 ++ l_kprog_arm64_stack_write_temps_1),
  fn_body :=
(Stmt.Sloop
  (Stmt.Ssequence
    (Stmt.Sset ___a64_loss_off (Expr.Etempvar _off tlong))
    (Stmt.Ssequence
      (Stmt.Sset ___a64_loss_width
        (Expr.Ecast (Expr.Etempvar _width tuchar) tuchar))
      (Stmt.Ssequence
        (Stmt.Sset ___a64_loss_value (Expr.Etempvar _value tulong))
        (Stmt.Ssequence
          (Stmt.Sloop
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'90
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                      (Ty.Tstruct _kprog_arm64_memory noattr)) _bias tlong))
                (Stmt.Sset ___a64_stw_index
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Ecast (Expr.Etempvar _t'90 tlong) tulong)
                    (Expr.Ecast (Expr.Etempvar ___a64_loss_off tlong) tulong)
                    tulong)))
              (Stmt.Ssequence
                (Stmt.Sset ___a64_stw_width
                  (Expr.Ecast (Expr.Etempvar ___a64_loss_width tuchar)
                    tuchar))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Etempvar ___a64_stw_width tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                        tint)
                      (Stmt.Sset _t'1
                        (Expr.Ecast
                          (Expr.Econst_long (Integers.Int64.repr 255) tulong)
                          tulong))
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Etempvar ___a64_stw_width tuchar)
                                          (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                          tint)
                        (Stmt.Ssequence
                          s_kprog_arm64_stack_write_0
                          (Stmt.Sset _t'1
                            (Expr.Ecast (Expr.Etempvar _t'1 tulong) tulong)))
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Etempvar ___a64_stw_width tuchar)
                                            (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                            tint)
                          s_kprog_arm64_stack_write_1
                          s_kprog_arm64_stack_write_2)))
                    (Stmt.Sset ___a64_stw_value
                      (Expr.Ebinop Binop.Oand
                        (Expr.Etempvar ___a64_loss_value tulong)
                        (Expr.Etempvar _t'1 tulong) tulong)))
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Etempvar ___a64_stw_width tuchar)
                                            (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                            tint)
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Ebinop Binop.Oand
                                                (Expr.Ecast
                                                  (Expr.Etempvar ___a64_stw_index tulong)
                                                  tuint)
                                                (Expr.Econst_int (Integers.Int.repr 7) tuint)
                                                tuint)
                                              (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                              tint)
                            s_kprog_arm64_stack_write_3
                            s_kprog_arm64_stack_write_4)
                          (Stmt.Sset _t'2
                            (Expr.Econst_int (Integers.Int.repr 0) tint)))
                        (Stmt.Sifthenelse (Expr.Etempvar _t'2 tint)
                          (Stmt.Sset _t'3
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 0) tuint)
                              tuint))
                          (Stmt.Ssequence
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                (Expr.Ebinop Binop.Oand
                                                  (Expr.Ecast
                                                    (Expr.Etempvar ___a64_stw_index tulong)
                                                    tuint)
                                                  (Expr.Econst_int (Integers.Int.repr 7) tuint)
                                                  tuint)
                                                (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                                tint)
                              s_kprog_arm64_stack_write_5
                              s_kprog_arm64_stack_write_6)
                            (Stmt.Sifthenelse (Expr.Etempvar _t'4 tint)
                              s_kprog_arm64_stack_write_7
                              s_kprog_arm64_stack_write_8))))
                      (Stmt.Sset ___a64_stw_action
                        (Expr.Ecast
                          (Expr.Ecast (Expr.Etempvar _t'3 tuint) tuchar)
                          tuchar)))
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Etempvar ___a64_stw_action tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                        tint)
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sset _t'89
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                                (Ty.Tstruct _kprog_arm64_memory noattr)) _q
                              (tptr (tvolatile tulong))))
                          (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
                            [(tptr (tvolatile tulong)), (tvolatile tulong)]
                            [(Expr.Eaddrof
                               (Expr.Ederef
                                 (Expr.Ebinop Binop.Oadd
                                   (Expr.Etempvar _t'89 (tptr (tvolatile tulong)))
                                   (Expr.Ebinop Binop.Oshr
                                     (Expr.Ecast
                                       (Expr.Etempvar ___a64_stw_index tulong)
                                       tulong)
                                     (Expr.Econst_int (Integers.Int.repr 3) tint)
                                     tulong) (tptr (tvolatile tulong)))
                                 (tvolatile tulong))
                               (tptr (tvolatile tulong))),
                             (Expr.Etempvar ___a64_stw_value tulong)]))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            s_kprog_arm64_stack_write_9
                            (Stmt.Sifthenelse (Expr.Etempvar _t'7 tint)
                              s_kprog_arm64_stack_write_12
                              Stmt.Sskip))
                          (Stmt.Sloop
                            s_kprog_arm64_stack_write_13
                            s_kprog_arm64_stack_write_14)))
                      (Stmt.Ssequence
                        (Stmt.Sloop
                          (Stmt.Ssequence
                            s_kprog_arm64_stack_write_15
                            s_kprog_arm64_stack_write_16)
                          Stmt.Sbreak)
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            s_kprog_arm64_stack_write_17
                            (Stmt.Sset ___a64_stw_last
                              (Expr.Ebinop Binop.Osub
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Etempvar ___a64_stw_index tulong)
                                  (Expr.Etempvar _t'10 tuint) tulong)
                                (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                tulong)))
                          (Stmt.Ssequence
                            s_kprog_arm64_stack_write_18
                            s_kprog_arm64_stack_write_41))))))))
            Stmt.Sbreak)
          (Stmt.Ssequence
            (Stmt.Sset _t'39
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
                  (Ty.Tstruct _kprog_arm64_memory noattr)) _coordinates
                (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))))
            (Stmt.Ssequence
              (Stmt.Sset _t'40
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Etempvar _t'39 (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr)))
                    (Ty.Tstruct _kprog_arm64_coordinates noattr))
                  _stack_offset tlong))
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                  (Expr.Etempvar ___a64_loss_off tlong)
                                  (Expr.Etempvar _t'40 tlong) tint)
                (Stmt.Ssequence
                  (Stmt.Sset ___a64_loss_i
                    (Expr.Econst_int (Integers.Int.repr 0) tint))
                  (Stmt.Sloop
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                          (Expr.Etempvar ___a64_loss_i tuint)
                                          (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                          tint)
                        Stmt.Sskip
                        Stmt.Sbreak)
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                            (Expr.Etempvar ___a64_loss_i tuint)
                                            (Expr.Etempvar ___a64_loss_width tuchar)
                                            tint)
                          s_kprog_arm64_stack_write_42
                          (Stmt.Sset _t'38
                            (Expr.Econst_int (Integers.Int.repr 0) tint)))
                        (Stmt.Sifthenelse (Expr.Etempvar _t'38 tint)
                          (Stmt.Sloop
                            (Stmt.Ssequence
                              s_kprog_arm64_stack_write_43
                              s_kprog_arm64_stack_write_85)
                            Stmt.Sbreak)
                          Stmt.Sskip)))
                    (Stmt.Sset ___a64_loss_i
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar ___a64_loss_i tuint)
                        (Expr.Econst_int (Integers.Int.repr 1) tint) tuint))))
                Stmt.Sskip)))))))
  Stmt.Sbreak)
}

def f_kprog_arm64_stack_pointer : Function := {
  fn_return := (tptr tvoid),
  fn_callconv := cc_default,
  fn_params := [(_memory, (tptr (Ty.Tstruct _kprog_arm64_memory noattr))),
                (_off, tlong)],
  fn_vars := [],
  fn_temps := [(_result, (tptr tvoid)), (___a64_sp_ptr_index, tlong),
               (_t'2, tlong), (_t'1, (tptr (tvolatile tuchar)))],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sset _t'2
          (Expr.Efield
            (Expr.Ederef
              (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
              (Ty.Tstruct _kprog_arm64_memory noattr)) _bias tlong))
        (Stmt.Sset ___a64_sp_ptr_index
          (Expr.Ecast
            (Expr.Ebinop Binop.Oadd
              (Expr.Ecast (Expr.Etempvar _t'2 tlong) tulong)
              (Expr.Ecast (Expr.Etempvar _off tlong) tulong) tulong) tlong)))
      (Stmt.Ssequence
        (Stmt.Sset _t'1
          (Expr.Efield
            (Expr.Ederef
              (Expr.Etempvar _memory (tptr (Ty.Tstruct _kprog_arm64_memory noattr)))
              (Ty.Tstruct _kprog_arm64_memory noattr)) _b
            (tptr (tvolatile tuchar))))
        (Stmt.Sset _result
          (Expr.Ecast
            (Expr.Ebinop Binop.Oadd
              (Expr.Etempvar _t'1 (tptr (tvolatile tuchar)))
              (Expr.Etempvar ___a64_sp_ptr_index tlong)
              (tptr (tvolatile tuchar))) (tptr tvoid)))))
    Stmt.Sbreak)
  (Stmt.Sreturn (some (Expr.Etempvar _result (tptr tvoid)))))
}

def composites : List CompositeDef :=
[(CompositeDef.Composite _kprog_arm64_coordinates SU.Struct
   [(Member.Member_plain _sp_base tulong),
    (Member.Member_plain _return_base tulong),
    (Member.Member_plain _stack_offset tlong),
    (Member.Member_plain _sp_valid tuchar),
    (Member.Member_plain _return_valid tuchar)]
   noattr),
 (CompositeDef.Composite _kprog_arm64_memory SU.Struct
   [(Member.Member_plain _coordinates
      (tptr (Ty.Tstruct _kprog_arm64_coordinates noattr))),
    (Member.Member_plain _b (tptr (tvolatile tuchar))),
    (Member.Member_plain _q (tptr (tvolatile tulong))),
    (Member.Member_plain _tags (tptr tuchar)),
    (Member.Member_plain _payload (tptr tulong)),
    (Member.Member_plain _capacity tuint), (Member.Member_plain _bias tlong)]
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
 (_kprog_arm64_stack_read_owned, GlobDef.Gfun (FunDef.Internal f_kprog_arm64_stack_read_owned)),
 (_kprog_arm64_stack_read, GlobDef.Gfun (FunDef.Internal f_kprog_arm64_stack_read)),
 (_kprog_arm64_stack_read_tag, GlobDef.Gfun (FunDef.Internal f_kprog_arm64_stack_read_tag)),
 (_kprog_arm64_stack_write_owned, GlobDef.Gfun (FunDef.Internal f_kprog_arm64_stack_write_owned)),
 (_arm64_sim_unsupported_opcode,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_external "arm64_sim_unsupported_opcode"
                                   (mksignature [] XType.Xvoid cc_default))
     [] tvoid cc_default)),
 (_kprog_arm64_stack_write, GlobDef.Gfun (FunDef.Internal f_kprog_arm64_stack_write)),
 (_kprog_arm64_stack_pointer, GlobDef.Gfun (FunDef.Internal f_kprog_arm64_stack_pointer))]

def public_idents : List Ident :=
[_kprog_arm64_stack_pointer, _kprog_arm64_stack_write,
 _arm64_sim_unsupported_opcode, _kprog_arm64_stack_write_owned,
 _kprog_arm64_stack_read_tag, _kprog_arm64_stack_read,
 _kprog_arm64_stack_read_owned, _native_lab_entry_input, ___builtin_debug,
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

end Arm64Stack

