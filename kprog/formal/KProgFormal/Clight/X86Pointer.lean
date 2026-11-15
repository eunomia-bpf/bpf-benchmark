import Clightdefs
open CC

namespace X86Pointer

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
  def source_file : String := "c/X86Pointer.c"
  def normalized : Bool := true
end Info

def __150 : Ident := identOfString "_150"
def __151 : Ident := identOfString "_151"
def __3115 : Ident := identOfString "_3115"
def __3116 : Ident := identOfString "_3116"
def __3283 : Ident := identOfString "_3283"
def __3289 : Ident := identOfString "_3289"
def __3354 : Ident := identOfString "_3354"
def __3360 : Ident := identOfString "_3360"
def __3396 : Ident := identOfString "_3396"
def __3402 : Ident := identOfString "_3402"
def __3461 : Ident := identOfString "_3461"
def __3467 : Ident := identOfString "_3467"
def __3527 : Ident := identOfString "_3527"
def __3533 : Ident := identOfString "_3533"
def __3578 : Ident := identOfString "_3578"
def __3584 : Ident := identOfString "_3584"
def __3634 : Ident := identOfString "_3634"
def __3640 : Ident := identOfString "_3640"
def __3737 : Ident := identOfString "_3737"
def __3743 : Ident := identOfString "_3743"
def __3780 : Ident := identOfString "_3780"
def __3786 : Ident := identOfString "_3786"
def __3825 : Ident := identOfString "_3825"
def __3831 : Ident := identOfString "_3831"
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
def ___kprog_padding_flow_keys : Ident := identOfString "__kprog_padding_flow_keys"
def ___kprog_padding_sk : Ident := identOfString "__kprog_padding_sk"
def ___kprog_reserved : Ident := identOfString "__kprog_reserved"
def ___kprog_x86_bits : Ident := identOfString "__kprog_x86_bits"
def ___kprog_x86_bits__1 : Ident := identOfString "__kprog_x86_bits__1"
def ___kprog_x86_bits__2 : Ident := identOfString "__kprog_x86_bits__2"
def ___kprog_x86_bits__3 : Ident := identOfString "__kprog_x86_bits__3"
def ___kprog_x86_bits__4 : Ident := identOfString "__kprog_x86_bits__4"
def ___kprog_x86_bits__5 : Ident := identOfString "__kprog_x86_bits__5"
def ___kprog_x86_lane : Ident := identOfString "__kprog_x86_lane"
def ___kprog_x86_lane__1 : Ident := identOfString "__kprog_x86_lane__1"
def ___kprog_x86_lane__2 : Ident := identOfString "__kprog_x86_lane__2"
def ___kprog_x86_lane__3 : Ident := identOfString "__kprog_x86_lane__3"
def ___kprog_x86_lane__4 : Ident := identOfString "__kprog_x86_lane__4"
def ___kprog_x86_lane__5 : Ident := identOfString "__kprog_x86_lane__5"
def ___kprog_x86_ml_arm : Ident := identOfString "__kprog_x86_ml_arm"
def ___kprog_x86_ml_mem : Ident := identOfString "__kprog_x86_ml_mem"
def ___kprog_x86_ml_write : Ident := identOfString "__kprog_x86_ml_write"
def ___kprog_x86_mo_disp : Ident := identOfString "__kprog_x86_mo_disp"
def ___kprog_x86_mo_has_index : Ident := identOfString "__kprog_x86_mo_has_index"
def ___kprog_x86_mo_index : Ident := identOfString "__kprog_x86_mo_index"
def ___kprog_x86_mo_result : Ident := identOfString "__kprog_x86_mo_result"
def ___kprog_x86_mo_scale : Ident := identOfString "__kprog_x86_mo_scale"
def ___kprog_x86_partial : Ident := identOfString "__kprog_x86_partial"
def ___kprog_x86_partial__1 : Ident := identOfString "__kprog_x86_partial__1"
def ___kprog_x86_partial__2 : Ident := identOfString "__kprog_x86_partial__2"
def ___kprog_x86_partial__3 : Ident := identOfString "__kprog_x86_partial__3"
def ___kprog_x86_partial__4 : Ident := identOfString "__kprog_x86_partial__4"
def ___kprog_x86_partial__5 : Ident := identOfString "__kprog_x86_partial__5"
def ___kprog_x86_pw_tag : Ident := identOfString "__kprog_x86_pw_tag"
def ___kprog_x86_source_tag : Ident := identOfString "__kprog_x86_source_tag"
def ___sk_buff : Ident := identOfString "__sk_buff"
def ___x86_alias_delta : Ident := identOfString "__x86_alias_delta"
def ___x86_alias_delta__1 : Ident := identOfString "__x86_alias_delta__1"
def ___x86_alias_observed : Ident := identOfString "__x86_alias_observed"
def ___x86_alias_offset : Ident := identOfString "__x86_alias_offset"
def ___x86_data_observed : Ident := identOfString "__x86_data_observed"
def ___x86_data_offset : Ident := identOfString "__x86_data_offset"
def ___x86_l_lane32 : Ident := identOfString "__x86_l_lane32"
def ___x86_l_pw_tag : Ident := identOfString "__x86_l_pw_tag"
def ___x86_l_shape : Ident := identOfString "__x86_l_shape"
def ___x86_l_src_width : Ident := identOfString "__x86_l_src_width"
def ___x86_l_value : Ident := identOfString "__x86_l_value"
def ___x86_l_width : Ident := identOfString "__x86_l_width"
def ___x86_mov_numeric : Ident := identOfString "__x86_mov_numeric"
def ___x86_mov_numeric__1 : Ident := identOfString "__x86_mov_numeric__1"
def ___x86_mov_source_tag : Ident := identOfString "__x86_mov_source_tag"
def ___x86_mov_stack_offset : Ident := identOfString "__x86_mov_stack_offset"
def ___x86_mov_stack_offset__1 : Ident := identOfString "__x86_mov_stack_offset__1"
def ___x86_rd_ptr : Ident := identOfString "__x86_rd_ptr"
def ___x86_rd_ptr__1 : Ident := identOfString "__x86_rd_ptr__1"
def ___x86_rd_ptr__2 : Ident := identOfString "__x86_rd_ptr__2"
def ___x86_rd_raw_width : Ident := identOfString "__x86_rd_raw_width"
def ___x86_rd_raw_width__1 : Ident := identOfString "__x86_rd_raw_width__1"
def ___x86_rd_raw_width__2 : Ident := identOfString "__x86_rd_raw_width__2"
def ___x86_rd_reg : Ident := identOfString "__x86_rd_reg"
def ___x86_rd_reg__1 : Ident := identOfString "__x86_rd_reg__1"
def ___x86_rd_reg__2 : Ident := identOfString "__x86_rd_reg__2"
def ___x86_rd_shift : Ident := identOfString "__x86_rd_shift"
def ___x86_rd_shift__1 : Ident := identOfString "__x86_rd_shift__1"
def ___x86_rd_shift__2 : Ident := identOfString "__x86_rd_shift__2"
def ___x86_rd_tag : Ident := identOfString "__x86_rd_tag"
def ___x86_rd_tag__1 : Ident := identOfString "__x86_rd_tag__1"
def ___x86_rd_tag__2 : Ident := identOfString "__x86_rd_tag__2"
def ___x86_rd_value : Ident := identOfString "__x86_rd_value"
def ___x86_rd_value__1 : Ident := identOfString "__x86_rd_value__1"
def ___x86_rd_value__2 : Ident := identOfString "__x86_rd_value__2"
def ___x86_rd_width : Ident := identOfString "__x86_rd_width"
def ___x86_rd_width__1 : Ident := identOfString "__x86_rd_width__1"
def ___x86_rd_width__2 : Ident := identOfString "__x86_rd_width__2"
def ___x86_read_recovered : Ident := identOfString "__x86_read_recovered"
def ___x86_read_tag : Ident := identOfString "__x86_read_tag"
def ___x86_release_i : Ident := identOfString "__x86_release_i"
def ___x86_release_i__1 : Ident := identOfString "__x86_release_i__1"
def ___x86_release_i__2 : Ident := identOfString "__x86_release_i__2"
def ___x86_release_i__3 : Ident := identOfString "__x86_release_i__3"
def ___x86_release_i__4 : Ident := identOfString "__x86_release_i__4"
def ___x86_release_i__5 : Ident := identOfString "__x86_release_i__5"
def ___x86_release_i__6 : Ident := identOfString "__x86_release_i__6"
def ___x86_release_lane : Ident := identOfString "__x86_release_lane"
def ___x86_release_lane__1 : Ident := identOfString "__x86_release_lane__1"
def ___x86_release_lane__2 : Ident := identOfString "__x86_release_lane__2"
def ___x86_release_lane__3 : Ident := identOfString "__x86_release_lane__3"
def ___x86_release_lane__4 : Ident := identOfString "__x86_release_lane__4"
def ___x86_release_lane__5 : Ident := identOfString "__x86_release_lane__5"
def ___x86_release_lane__6 : Ident := identOfString "__x86_release_lane__6"
def ___x86_release_new : Ident := identOfString "__x86_release_new"
def ___x86_release_new__1 : Ident := identOfString "__x86_release_new__1"
def ___x86_release_new__2 : Ident := identOfString "__x86_release_new__2"
def ___x86_release_new__3 : Ident := identOfString "__x86_release_new__3"
def ___x86_release_new__4 : Ident := identOfString "__x86_release_new__4"
def ___x86_release_new__5 : Ident := identOfString "__x86_release_new__5"
def ___x86_release_new__6 : Ident := identOfString "__x86_release_new__6"
def ___x86_release_off : Ident := identOfString "__x86_release_off"
def ___x86_release_off__1 : Ident := identOfString "__x86_release_off__1"
def ___x86_release_off__2 : Ident := identOfString "__x86_release_off__2"
def ___x86_release_off__3 : Ident := identOfString "__x86_release_off__3"
def ___x86_release_off__4 : Ident := identOfString "__x86_release_off__4"
def ___x86_release_off__5 : Ident := identOfString "__x86_release_off__5"
def ___x86_release_off__6 : Ident := identOfString "__x86_release_off__6"
def ___x86_release_old : Ident := identOfString "__x86_release_old"
def ___x86_release_old__1 : Ident := identOfString "__x86_release_old__1"
def ___x86_release_old__2 : Ident := identOfString "__x86_release_old__2"
def ___x86_release_old__3 : Ident := identOfString "__x86_release_old__3"
def ___x86_release_old__4 : Ident := identOfString "__x86_release_old__4"
def ___x86_release_old__5 : Ident := identOfString "__x86_release_old__5"
def ___x86_release_old__6 : Ident := identOfString "__x86_release_old__6"
def ___x86_stack_delta : Ident := identOfString "__x86_stack_delta"
def ___x86_stack_delta__1 : Ident := identOfString "__x86_stack_delta__1"
def ___x86_stack_delta__2 : Ident := identOfString "__x86_stack_delta__2"
def ___x86_stack_delta__3 : Ident := identOfString "__x86_stack_delta__3"
def ___x86_stack_delta__4 : Ident := identOfString "__x86_stack_delta__4"
def ___x86_stack_delta__5 : Ident := identOfString "__x86_stack_delta__5"
def ___x86_stack_delta__6 : Ident := identOfString "__x86_stack_delta__6"
def ___x86_stack_delta__7 : Ident := identOfString "__x86_stack_delta__7"
def ___x86_stack_delta__8 : Ident := identOfString "__x86_stack_delta__8"
def ___x86_state : Ident := identOfString "__x86_state"
def ___x86_store_reg : Ident := identOfString "__x86_store_reg"
def ___x86_store_reg__1 : Ident := identOfString "__x86_store_reg__1"
def ___x86_store_reg__2 : Ident := identOfString "__x86_store_reg__2"
def ___x86_store_reg__3 : Ident := identOfString "__x86_store_reg__3"
def ___x86_store_reg__4 : Ident := identOfString "__x86_store_reg__4"
def ___x86_store_reg__5 : Ident := identOfString "__x86_store_reg__5"
def ___x86_store_reg__6 : Ident := identOfString "__x86_store_reg__6"
def ___x86_sv_i : Ident := identOfString "__x86_sv_i"
def ___x86_sv_i__1 : Ident := identOfString "__x86_sv_i__1"
def ___x86_sv_i__2 : Ident := identOfString "__x86_sv_i__2"
def ___x86_sv_i__3 : Ident := identOfString "__x86_sv_i__3"
def ___x86_sv_i__4 : Ident := identOfString "__x86_sv_i__4"
def ___x86_sv_i__5 : Ident := identOfString "__x86_sv_i__5"
def ___x86_sv_i__6 : Ident := identOfString "__x86_sv_i__6"
def ___x86_sv_sp : Ident := identOfString "__x86_sv_sp"
def ___x86_sv_sp__1 : Ident := identOfString "__x86_sv_sp__1"
def ___x86_sv_sp__2 : Ident := identOfString "__x86_sv_sp__2"
def ___x86_sv_sp__3 : Ident := identOfString "__x86_sv_sp__3"
def ___x86_sv_sp__4 : Ident := identOfString "__x86_sv_sp__4"
def ___x86_sv_sp__5 : Ident := identOfString "__x86_sv_sp__5"
def ___x86_sv_sp__6 : Ident := identOfString "__x86_sv_sp__6"
def ___x86_tag_reg : Ident := identOfString "__x86_tag_reg"
def ___x86_tag_reg__1 : Ident := identOfString "__x86_tag_reg__1"
def ___x86_tag_reg__2 : Ident := identOfString "__x86_tag_reg__2"
def ___x86_tag_reg__3 : Ident := identOfString "__x86_tag_reg__3"
def ___x86_tag_reg__4 : Ident := identOfString "__x86_tag_reg__4"
def ___x86_tag_reg__5 : Ident := identOfString "__x86_tag_reg__5"
def ___x86_tag_reg__6 : Ident := identOfString "__x86_tag_reg__6"
def ___x86_wr_cell : Ident := identOfString "__x86_wr_cell"
def ___x86_wr_cell__1 : Ident := identOfString "__x86_wr_cell__1"
def ___x86_wr_cell__2 : Ident := identOfString "__x86_wr_cell__2"
def ___x86_wr_cell_tag : Ident := identOfString "__x86_wr_cell_tag"
def ___x86_wr_cell_tag__1 : Ident := identOfString "__x86_wr_cell_tag__1"
def ___x86_wr_cell_tag__2 : Ident := identOfString "__x86_wr_cell_tag__2"
def ___x86_wr_next : Ident := identOfString "__x86_wr_next"
def ___x86_wr_next__1 : Ident := identOfString "__x86_wr_next__1"
def ___x86_wr_next__2 : Ident := identOfString "__x86_wr_next__2"
def ___x86_wr_next_ptr : Ident := identOfString "__x86_wr_next_ptr"
def ___x86_wr_next_ptr__1 : Ident := identOfString "__x86_wr_next_ptr__1"
def ___x86_wr_next_ptr__2 : Ident := identOfString "__x86_wr_next_ptr__2"
def ___x86_wr_next_ptr__3 : Ident := identOfString "__x86_wr_next_ptr__3"
def ___x86_wr_next_ptr__4 : Ident := identOfString "__x86_wr_next_ptr__4"
def ___x86_wr_next_ptr__5 : Ident := identOfString "__x86_wr_next_ptr__5"
def ___x86_wr_next_ptr__6 : Ident := identOfString "__x86_wr_next_ptr__6"
def ___x86_wr_next_tag : Ident := identOfString "__x86_wr_next_tag"
def ___x86_wr_next_tag__1 : Ident := identOfString "__x86_wr_next_tag__1"
def ___x86_wr_next_tag__2 : Ident := identOfString "__x86_wr_next_tag__2"
def ___x86_wr_next_tag__3 : Ident := identOfString "__x86_wr_next_tag__3"
def ___x86_wr_next_tag__4 : Ident := identOfString "__x86_wr_next_tag__4"
def ___x86_wr_next_tag__5 : Ident := identOfString "__x86_wr_next_tag__5"
def ___x86_wr_next_tag__6 : Ident := identOfString "__x86_wr_next_tag__6"
def ___x86_wr_raw_width : Ident := identOfString "__x86_wr_raw_width"
def ___x86_wr_raw_width__1 : Ident := identOfString "__x86_wr_raw_width__1"
def ___x86_wr_raw_width__2 : Ident := identOfString "__x86_wr_raw_width__2"
def ___x86_wr_shift : Ident := identOfString "__x86_wr_shift"
def ___x86_wr_shift__1 : Ident := identOfString "__x86_wr_shift__1"
def ___x86_wr_shift__2 : Ident := identOfString "__x86_wr_shift__2"
def ___x86_wr_stack_bits : Ident := identOfString "__x86_wr_stack_bits"
def ___x86_wr_stack_bits__1 : Ident := identOfString "__x86_wr_stack_bits__1"
def ___x86_wr_stack_bits__2 : Ident := identOfString "__x86_wr_stack_bits__2"
def ___x86_wr_stack_bits__3 : Ident := identOfString "__x86_wr_stack_bits__3"
def ___x86_wr_stack_bits__4 : Ident := identOfString "__x86_wr_stack_bits__4"
def ___x86_wr_stack_bits__5 : Ident := identOfString "__x86_wr_stack_bits__5"
def ___x86_wr_width : Ident := identOfString "__x86_wr_width"
def ___x86_wr_width__1 : Ident := identOfString "__x86_wr_width__1"
def ___x86_wr_width__2 : Ident := identOfString "__x86_wr_width__2"
def ___x86_write_old_sp : Ident := identOfString "__x86_write_old_sp"
def ___x86_write_old_sp__1 : Ident := identOfString "__x86_write_old_sp__1"
def ___x86_write_old_sp__2 : Ident := identOfString "__x86_write_old_sp__2"
def ___x86_write_old_sp__3 : Ident := identOfString "__x86_write_old_sp__3"
def ___x86_write_old_sp__4 : Ident := identOfString "__x86_write_old_sp__4"
def ___x86_write_old_sp__5 : Ident := identOfString "__x86_write_old_sp__5"
def ___x86_write_old_sp__6 : Ident := identOfString "__x86_write_old_sp__6"
def _abi_kind : Ident := identOfString "abi_kind"
def _address : Ident := identOfString "address"
def _af : Ident := identOfString "af"
def _arena : Ident := identOfString "arena"
def _arm : Ident := identOfString "arm"
def _aux : Ident := identOfString "aux"
def _b : Ident := identOfString "b"
def _base : Ident := identOfString "base"
def _bpf_flow_keys : Ident := identOfString "bpf_flow_keys"
def _bpf_sock : Ident := identOfString "bpf_sock"
def _call_depth : Ident := identOfString "call_depth"
def _capacity : Ident := identOfString "capacity"
def _cb : Ident := identOfString "cb"
def _cf : Ident := identOfString "cf"
def _code : Ident := identOfString "code"
def _data : Ident := identOfString "data"
def _data_end : Ident := identOfString "data_end"
def _data_meta : Ident := identOfString "data_meta"
def _displacement : Ident := identOfString "displacement"
def _dst : Ident := identOfString "dst"
def _facts : Ident := identOfString "facts"
def _family : Ident := identOfString "family"
def _flags : Ident := identOfString "flags"
def _flow_keys : Ident := identOfString "flow_keys"
def _gpr_cells : Ident := identOfString "gpr_cells"
def _gso_segs : Ident := identOfString "gso_segs"
def _gso_size : Ident := identOfString "gso_size"
def _hash : Ident := identOfString "hash"
def _helper_abi_base : Ident := identOfString "helper_abi_base"
def _helper_ctx : Ident := identOfString "helper_ctx"
def _hwtstamp : Ident := identOfString "hwtstamp"
def _ifindex : Ident := identOfString "ifindex"
def _imm : Ident := identOfString "imm"
def _index : Ident := identOfString "index"
def _ingress_ifindex : Ident := identOfString "ingress_ifindex"
def _is_xdp : Ident := identOfString "is_xdp"
def _kprog_c_trap : Ident := identOfString "kprog_c_trap"
def _kprog_x86_arena : Ident := identOfString "kprog_x86_arena"
def _kprog_x86_load_tagged : Ident := identOfString "kprog_x86_load_tagged"
def _kprog_x86_mem_load : Ident := identOfString "kprog_x86_mem_load"
def _kprog_x86_mem_offset : Ident := identOfString "kprog_x86_mem_offset"
def _kprog_x86_mem_offset_indexed : Ident := identOfString "kprog_x86_mem_offset_indexed"
def _kprog_x86_mov_imm : Ident := identOfString "kprog_x86_mov_imm"
def _kprog_x86_mov_load_arm : Ident := identOfString "kprog_x86_mov_load_arm"
def _kprog_x86_mov_load_mem_width : Ident := identOfString "kprog_x86_mov_load_mem_width"
def _kprog_x86_mov_load_write_width : Ident := identOfString "kprog_x86_mov_load_write_width"
def _kprog_x86_mov_reg : Ident := identOfString "kprog_x86_mov_reg"
def _kprog_x86_movx_reg : Ident := identOfString "kprog_x86_movx_reg"
def _kprog_x86_native_load_tagged : Ident := identOfString "kprog_x86_native_load_tagged"
def _kprog_x86_ptr_load : Ident := identOfString "kprog_x86_ptr_load"
def _kprog_x86_read_recovery : Ident := identOfString "kprog_x86_read_recovery"
def _kprog_x86_read_recovery_at : Ident := identOfString "kprog_x86_read_recovery_at"
def _kprog_x86_read_recovery_mem : Ident := identOfString "kprog_x86_read_recovery_mem"
def _kprog_x86_read_reg : Ident := identOfString "kprog_x86_read_reg"
def _kprog_x86_sign_extend_value : Ident := identOfString "kprog_x86_sign_extend_value"
def _kprog_x86_stack_alias : Ident := identOfString "kprog_x86_stack_alias"
def _kprog_x86_stack_fact : Ident := identOfString "kprog_x86_stack_fact"
def _kprog_x86_write_reg : Ident := identOfString "kprog_x86_write_reg"
def _len : Ident := identOfString "len"
def _local_ip4 : Ident := identOfString "local_ip4"
def _local_ip6 : Ident := identOfString "local_ip6"
def _local_port : Ident := identOfString "local_port"
def _main : Ident := identOfString "main"
def _mark : Ident := identOfString "mark"
def _memory : Ident := identOfString "memory"
def _napi_id : Ident := identOfString "napi_id"
def _native_lab_entry_input : Ident := identOfString "native_lab_entry_input"
def _native_stack_base : Ident := identOfString "native_stack_base"
def _observed : Ident := identOfString "observed"
def _observed__1 : Ident := identOfString "observed__1"
def _observed__2 : Ident := identOfString "observed__2"
def _observed__3 : Ident := identOfString "observed__3"
def _of : Ident := identOfString "of"
def _offset : Ident := identOfString "offset"
def _op : Ident := identOfString "op"
def _pad0 : Ident := identOfString "pad0"
def _pad1 : Ident := identOfString "pad1"
def _pad2 : Ident := identOfString "pad2"
def _pf : Ident := identOfString "pf"
def _pkt_type : Ident := identOfString "pkt_type"
def _plain : Ident := identOfString "plain"
def _pointer : Ident := identOfString "pointer"
def _present : Ident := identOfString "present"
def _priority : Ident := identOfString "priority"
def _protocol : Ident := identOfString "protocol"
def _ptr : Ident := identOfString "ptr"
def _q : Ident := identOfString "q"
def _queue_mapping : Ident := identOfString "queue_mapping"
def _r10 : Ident := identOfString "r10"
def _r10_tag : Ident := identOfString "r10_tag"
def _r11 : Ident := identOfString "r11"
def _r11_tag : Ident := identOfString "r11_tag"
def _r12 : Ident := identOfString "r12"
def _r12_tag : Ident := identOfString "r12_tag"
def _r13 : Ident := identOfString "r13"
def _r13_tag : Ident := identOfString "r13_tag"
def _r14 : Ident := identOfString "r14"
def _r14_tag : Ident := identOfString "r14_tag"
def _r15 : Ident := identOfString "r15"
def _r15_tag : Ident := identOfString "r15_tag"
def _r8 : Ident := identOfString "r8"
def _r8_tag : Ident := identOfString "r8_tag"
def _r9 : Ident := identOfString "r9"
def _r9_tag : Ident := identOfString "r9_tag"
def _rax : Ident := identOfString "rax"
def _rax_tag : Ident := identOfString "rax_tag"
def _rbp : Ident := identOfString "rbp"
def _rbp_tag : Ident := identOfString "rbp_tag"
def _rbx : Ident := identOfString "rbx"
def _rbx_tag : Ident := identOfString "rbx_tag"
def _rcx : Ident := identOfString "rcx"
def _rcx_tag : Ident := identOfString "rcx_tag"
def _rdi : Ident := identOfString "rdi"
def _rdi_tag : Ident := identOfString "rdi_tag"
def _rdx : Ident := identOfString "rdx"
def _rdx_tag : Ident := identOfString "rdx_tag"
def _recovered : Ident := identOfString "recovered"
def _reg : Ident := identOfString "reg"
def _remote_ip4 : Ident := identOfString "remote_ip4"
def _remote_ip6 : Ident := identOfString "remote_ip6"
def _remote_port : Ident := identOfString "remote_port"
def _result : Ident := identOfString "result"
def _ret_addr : Ident := identOfString "ret_addr"
def _rsi : Ident := identOfString "rsi"
def _rsi_tag : Ident := identOfString "rsi_tag"
def _rsp : Ident := identOfString "rsp"
def _rsp_tag : Ident := identOfString "rsp_tag"
def _sf : Ident := identOfString "sf"
def _shift : Ident := identOfString "shift"
def _sk : Ident := identOfString "sk"
def _skb_abi : Ident := identOfString "skb_abi"
def _skb_ctx : Ident := identOfString "skb_ctx"
def _src : Ident := identOfString "src"
def _stack : Ident := identOfString "stack"
def _state : Ident := identOfString "state"
def _tag : Ident := identOfString "tag"
def _tc_classid : Ident := identOfString "tc_classid"
def _tc_index : Ident := identOfString "tc_index"
def _tstamp : Ident := identOfString "tstamp"
def _tstamp_type : Ident := identOfString "tstamp_type"
def _value : Ident := identOfString "value"
def _vlan_present : Ident := identOfString "vlan_present"
def _vlan_proto : Ident := identOfString "vlan_proto"
def _vlan_tci : Ident := identOfString "vlan_tci"
def _w : Ident := identOfString "w"
def _width : Ident := identOfString "width"
def _wire_len : Ident := identOfString "wire_len"
def _write : Ident := identOfString "write"
def _x86_apply_width : Ident := identOfString "x86_apply_width"
def _x86_sign_extend : Ident := identOfString "x86_sign_extend"
def _x86_sim_gpr : Ident := identOfString "x86_sim_gpr"
def _x86_sim_gpr_cell : Ident := identOfString "x86_sim_gpr_cell"
def _x86_sim_register_state : Ident := identOfString "x86_sim_register_state"
def _x86_sim_skb_abi : Ident := identOfString "x86_sim_skb_abi"
def _x86_sim_xdp_abi : Ident := identOfString "x86_sim_xdp_abi"
def _x86_width_effective : Ident := identOfString "x86_width_effective"
def _xdp_abi : Ident := identOfString "xdp_abi"
def _xmm0_hi : Ident := identOfString "xmm0_hi"
def _xmm0_lo : Ident := identOfString "xmm0_lo"
def _zf : Ident := identOfString "zf"
def _t'1 : Ident := (Positive.ofNat 128)
def _t'10 : Ident := (Positive.ofNat 137)
def _t'100 : Ident := (Positive.ofNat 227)
def _t'101 : Ident := (Positive.ofNat 228)
def _t'102 : Ident := (Positive.ofNat 229)
def _t'103 : Ident := (Positive.ofNat 230)
def _t'104 : Ident := (Positive.ofNat 231)
def _t'105 : Ident := (Positive.ofNat 232)
def _t'106 : Ident := (Positive.ofNat 233)
def _t'107 : Ident := (Positive.ofNat 234)
def _t'108 : Ident := (Positive.ofNat 235)
def _t'109 : Ident := (Positive.ofNat 236)
def _t'11 : Ident := (Positive.ofNat 138)
def _t'110 : Ident := (Positive.ofNat 237)
def _t'111 : Ident := (Positive.ofNat 238)
def _t'112 : Ident := (Positive.ofNat 239)
def _t'113 : Ident := (Positive.ofNat 240)
def _t'114 : Ident := (Positive.ofNat 241)
def _t'115 : Ident := (Positive.ofNat 242)
def _t'116 : Ident := (Positive.ofNat 243)
def _t'117 : Ident := (Positive.ofNat 244)
def _t'118 : Ident := (Positive.ofNat 245)
def _t'119 : Ident := (Positive.ofNat 246)
def _t'12 : Ident := (Positive.ofNat 139)
def _t'120 : Ident := (Positive.ofNat 247)
def _t'121 : Ident := (Positive.ofNat 248)
def _t'122 : Ident := (Positive.ofNat 249)
def _t'123 : Ident := (Positive.ofNat 250)
def _t'124 : Ident := (Positive.ofNat 251)
def _t'125 : Ident := (Positive.ofNat 252)
def _t'126 : Ident := (Positive.ofNat 253)
def _t'127 : Ident := (Positive.ofNat 254)
def _t'128 : Ident := (Positive.ofNat 255)
def _t'129 : Ident := (Positive.ofNat 256)
def _t'13 : Ident := (Positive.ofNat 140)
def _t'130 : Ident := (Positive.ofNat 257)
def _t'131 : Ident := (Positive.ofNat 258)
def _t'132 : Ident := (Positive.ofNat 259)
def _t'133 : Ident := (Positive.ofNat 260)
def _t'134 : Ident := (Positive.ofNat 261)
def _t'135 : Ident := (Positive.ofNat 262)
def _t'136 : Ident := (Positive.ofNat 263)
def _t'137 : Ident := (Positive.ofNat 264)
def _t'138 : Ident := (Positive.ofNat 265)
def _t'139 : Ident := (Positive.ofNat 266)
def _t'14 : Ident := (Positive.ofNat 141)
def _t'140 : Ident := (Positive.ofNat 267)
def _t'141 : Ident := (Positive.ofNat 268)
def _t'142 : Ident := (Positive.ofNat 269)
def _t'143 : Ident := (Positive.ofNat 270)
def _t'144 : Ident := (Positive.ofNat 271)
def _t'145 : Ident := (Positive.ofNat 272)
def _t'146 : Ident := (Positive.ofNat 273)
def _t'147 : Ident := (Positive.ofNat 274)
def _t'148 : Ident := (Positive.ofNat 275)
def _t'149 : Ident := (Positive.ofNat 276)
def _t'15 : Ident := (Positive.ofNat 142)
def _t'150 : Ident := (Positive.ofNat 277)
def _t'151 : Ident := (Positive.ofNat 278)
def _t'152 : Ident := (Positive.ofNat 279)
def _t'153 : Ident := (Positive.ofNat 280)
def _t'154 : Ident := (Positive.ofNat 281)
def _t'155 : Ident := (Positive.ofNat 282)
def _t'156 : Ident := (Positive.ofNat 283)
def _t'157 : Ident := (Positive.ofNat 284)
def _t'158 : Ident := (Positive.ofNat 285)
def _t'159 : Ident := (Positive.ofNat 286)
def _t'16 : Ident := (Positive.ofNat 143)
def _t'160 : Ident := (Positive.ofNat 287)
def _t'161 : Ident := (Positive.ofNat 288)
def _t'162 : Ident := (Positive.ofNat 289)
def _t'163 : Ident := (Positive.ofNat 290)
def _t'164 : Ident := (Positive.ofNat 291)
def _t'165 : Ident := (Positive.ofNat 292)
def _t'166 : Ident := (Positive.ofNat 293)
def _t'167 : Ident := (Positive.ofNat 294)
def _t'168 : Ident := (Positive.ofNat 295)
def _t'169 : Ident := (Positive.ofNat 296)
def _t'17 : Ident := (Positive.ofNat 144)
def _t'170 : Ident := (Positive.ofNat 297)
def _t'171 : Ident := (Positive.ofNat 298)
def _t'172 : Ident := (Positive.ofNat 299)
def _t'173 : Ident := (Positive.ofNat 300)
def _t'174 : Ident := (Positive.ofNat 301)
def _t'175 : Ident := (Positive.ofNat 302)
def _t'176 : Ident := (Positive.ofNat 303)
def _t'177 : Ident := (Positive.ofNat 304)
def _t'178 : Ident := (Positive.ofNat 305)
def _t'179 : Ident := (Positive.ofNat 306)
def _t'18 : Ident := (Positive.ofNat 145)
def _t'180 : Ident := (Positive.ofNat 307)
def _t'181 : Ident := (Positive.ofNat 308)
def _t'182 : Ident := (Positive.ofNat 309)
def _t'183 : Ident := (Positive.ofNat 310)
def _t'184 : Ident := (Positive.ofNat 311)
def _t'185 : Ident := (Positive.ofNat 312)
def _t'186 : Ident := (Positive.ofNat 313)
def _t'187 : Ident := (Positive.ofNat 314)
def _t'188 : Ident := (Positive.ofNat 315)
def _t'189 : Ident := (Positive.ofNat 316)
def _t'19 : Ident := (Positive.ofNat 146)
def _t'190 : Ident := (Positive.ofNat 317)
def _t'191 : Ident := (Positive.ofNat 318)
def _t'192 : Ident := (Positive.ofNat 319)
def _t'193 : Ident := (Positive.ofNat 320)
def _t'194 : Ident := (Positive.ofNat 321)
def _t'195 : Ident := (Positive.ofNat 322)
def _t'196 : Ident := (Positive.ofNat 323)
def _t'197 : Ident := (Positive.ofNat 324)
def _t'198 : Ident := (Positive.ofNat 325)
def _t'199 : Ident := (Positive.ofNat 326)
def _t'2 : Ident := (Positive.ofNat 129)
def _t'20 : Ident := (Positive.ofNat 147)
def _t'200 : Ident := (Positive.ofNat 327)
def _t'201 : Ident := (Positive.ofNat 328)
def _t'202 : Ident := (Positive.ofNat 329)
def _t'203 : Ident := (Positive.ofNat 330)
def _t'204 : Ident := (Positive.ofNat 331)
def _t'205 : Ident := (Positive.ofNat 332)
def _t'206 : Ident := (Positive.ofNat 333)
def _t'207 : Ident := (Positive.ofNat 334)
def _t'208 : Ident := (Positive.ofNat 335)
def _t'209 : Ident := (Positive.ofNat 336)
def _t'21 : Ident := (Positive.ofNat 148)
def _t'210 : Ident := (Positive.ofNat 337)
def _t'211 : Ident := (Positive.ofNat 338)
def _t'212 : Ident := (Positive.ofNat 339)
def _t'213 : Ident := (Positive.ofNat 340)
def _t'214 : Ident := (Positive.ofNat 341)
def _t'215 : Ident := (Positive.ofNat 342)
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
def _t'91 : Ident := (Positive.ofNat 218)
def _t'92 : Ident := (Positive.ofNat 219)
def _t'93 : Ident := (Positive.ofNat 220)
def _t'94 : Ident := (Positive.ofNat 221)
def _t'95 : Ident := (Positive.ofNat 222)
def _t'96 : Ident := (Positive.ofNat 223)
def _t'97 : Ident := (Positive.ofNat 224)
def _t'98 : Ident := (Positive.ofNat 225)
def _t'99 : Ident := (Positive.ofNat 226)

def f_kprog_x86_sign_extend_value : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_value, tulong), (_width, tuchar)],
  fn_vars := [],
  fn_temps := [],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _width tuchar)
                      (Expr.Econst_int (Integers.Int.repr 1) tuint) tint)
    (Stmt.Sreturn (some (Expr.Ecast
                          (Expr.Ecast
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Oand
                                (Expr.Etempvar _value tulong)
                                (Expr.Econst_long (Integers.Int64.repr 255) tulong)
                                tulong) tschar) tlong) tulong)))
    Stmt.Sskip)
  (Stmt.Ssequence
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _width tuchar)
                        (Expr.Econst_int (Integers.Int.repr 2) tuint) tint)
      (Stmt.Sreturn (some (Expr.Ecast
                            (Expr.Ecast
                              (Expr.Ecast
                                (Expr.Ebinop Binop.Oand
                                  (Expr.Etempvar _value tulong)
                                  (Expr.Econst_long (Integers.Int64.repr 65535) tulong)
                                  tulong) tshort) tlong) tulong)))
      Stmt.Sskip)
    (Stmt.Ssequence
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _width tuchar)
                          (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
        (Stmt.Sreturn (some (Expr.Ecast
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Ebinop Binop.Oand
                                    (Expr.Etempvar _value tulong)
                                    (Expr.Econst_long (Integers.Int64.repr 4294967295) tulong)
                                    tulong) tint) tlong) tulong)))
        Stmt.Sskip)
      (Stmt.Sreturn (some (Expr.Etempvar _value tulong))))))
}

def f_x86_apply_width : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_value, tulong), (_width, tuchar)],
  fn_vars := [],
  fn_temps := [(_t'1, tulong)],
  fn_body :=
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
  (Stmt.Sreturn (some (Expr.Ebinop Binop.Oand (Expr.Etempvar _value tulong)
                        (Expr.Etempvar _t'1 tulong) tulong))))
}

def f_x86_width_effective : Function := {
  fn_return := tuchar,
  fn_callconv := cc_default,
  fn_params := [(_code, tuchar)],
  fn_vars := [],
  fn_temps := [(_t'1, tuint)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.One (Expr.Etempvar _code tuchar)
                      (Expr.Econst_int (Integers.Int.repr 0) tuint) tint)
    (Stmt.Sset _t'1 (Expr.Ecast (Expr.Etempvar _code tuchar) tuint))
    (Stmt.Sset _t'1
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint)))
  (Stmt.Sreturn (some (Expr.Etempvar _t'1 tuint))))
}

def f_x86_sign_extend : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_value, tulong), (_width, tuchar)],
  fn_vars := [],
  fn_temps := [(_t'1, tulong)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'1)
    (Expr.Evar _kprog_x86_sign_extend_value (Ty.Tfunction [tulong, tuchar]
                                              tulong cc_default))
    [(Expr.Etempvar _value tulong), (Expr.Etempvar _width tuchar)])
  (Stmt.Sreturn (some (Expr.Etempvar _t'1 tulong))))
}

def f_kprog_x86_mem_load : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_address, (tptr tvoid)), (_width, tuchar)],
  fn_vars := [(_observed, (tvolatile tuchar)),
              (_observed__1, (tvolatile tushort)),
              (_observed__2, (tvolatile tuint)),
              (_observed__3, (tvolatile tulong))],
  fn_temps := [(_t'5, (tvolatile tulong)), (_t'4, (tvolatile tuint)),
               (_t'3, (tvolatile tushort)), (_t'2, (tvolatile tuchar)),
               (_t'1, tuint)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Etempvar _width tuchar)
    (Stmt.Sset _t'1 (Expr.Ecast (Expr.Etempvar _width tuchar) tuint))
    (Stmt.Sset _t'1
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint)))
  (Stmt.Sswitch (Expr.Etempvar _t'1 tuint)
    (LStmts.LScons (some 1)
      (Stmt.Sloop
        (Stmt.Ssequence
          (Stmt.Sbuiltin none (ExtFun.EF_memcpy 1 1)
            [(tptr tvoid), (tptr tvoid)]
            [(Expr.Ecast
               (Expr.Eaddrof (Expr.Evar _observed (tvolatile tuchar))
                 (tptr (tvolatile tuchar))) (tptr tvoid)),
             (Expr.Etempvar _address (tptr tvoid))])
          (Stmt.Ssequence
            (Stmt.Sbuiltin (some _t'2) (ExtFun.EF_vload Chunk.Mint8unsigned)
              [(tptr (tvolatile tuchar))]
              [(Expr.Eaddrof (Expr.Evar _observed (tvolatile tuchar))
                 (tptr (tvolatile tuchar)))])
            (Stmt.Sreturn (some (Expr.Etempvar _t'2 (tvolatile tuchar))))))
        Stmt.Sbreak)
      (LStmts.LScons (some 2)
        (Stmt.Sloop
          (Stmt.Ssequence
            (Stmt.Sbuiltin none (ExtFun.EF_memcpy 2 1)
              [(tptr tvoid), (tptr tvoid)]
              [(Expr.Ecast
                 (Expr.Eaddrof (Expr.Evar _observed__1 (tvolatile tushort))
                   (tptr (tvolatile tushort))) (tptr tvoid)),
               (Expr.Etempvar _address (tptr tvoid))])
            (Stmt.Ssequence
              (Stmt.Sbuiltin (some _t'3)
                (ExtFun.EF_vload Chunk.Mint16unsigned)
                [(tptr (tvolatile tushort))]
                [(Expr.Eaddrof (Expr.Evar _observed__1 (tvolatile tushort))
                   (tptr (tvolatile tushort)))])
              (Stmt.Sreturn (some (Expr.Etempvar _t'3 (tvolatile tushort))))))
          Stmt.Sbreak)
        (LStmts.LScons (some 4)
          (Stmt.Sloop
            (Stmt.Ssequence
              (Stmt.Sbuiltin none (ExtFun.EF_memcpy 4 1)
                [(tptr tvoid), (tptr tvoid)]
                [(Expr.Ecast
                   (Expr.Eaddrof (Expr.Evar _observed__2 (tvolatile tuint))
                     (tptr (tvolatile tuint))) (tptr tvoid)),
                 (Expr.Etempvar _address (tptr tvoid))])
              (Stmt.Ssequence
                (Stmt.Sbuiltin (some _t'4) (ExtFun.EF_vload Chunk.Mint32)
                  [(tptr (tvolatile tuint))]
                  [(Expr.Eaddrof (Expr.Evar _observed__2 (tvolatile tuint))
                     (tptr (tvolatile tuint)))])
                (Stmt.Sreturn (some (Expr.Etempvar _t'4 (tvolatile tuint))))))
            Stmt.Sbreak)
          (LStmts.LScons (some 8)
            (Stmt.Sloop
              (Stmt.Ssequence
                (Stmt.Sbuiltin none (ExtFun.EF_memcpy 8 1)
                  [(tptr tvoid), (tptr tvoid)]
                  [(Expr.Ecast
                     (Expr.Eaddrof
                       (Expr.Evar _observed__3 (tvolatile tulong))
                       (tptr (tvolatile tulong))) (tptr tvoid)),
                   (Expr.Etempvar _address (tptr tvoid))])
                (Stmt.Ssequence
                  (Stmt.Sbuiltin (some _t'5) (ExtFun.EF_vload Chunk.Mint64)
                    [(tptr (tvolatile tulong))]
                    [(Expr.Eaddrof
                       (Expr.Evar _observed__3 (tvolatile tulong))
                       (tptr (tvolatile tulong)))])
                  (Stmt.Sreturn (some (Expr.Etempvar _t'5 (tvolatile tulong))))))
              Stmt.Sbreak)
            (LStmts.LScons none
              (Stmt.Scall none
                (Expr.Evar _kprog_c_trap (Ty.Tfunction [] tvoid cc_default))
                [])
              LStmts.LSnil)))))))
}

def s_kprog_x86_ptr_load_0 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'52
    (Expr.Efield
      (Expr.Efield
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                  (Ty.Tstruct _x86_sim_register_state noattr))
                (Positive.ofNat 18727075383868559167)
                (Ty.Tunion __3115 noattr)) _gpr_cells
              (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
            (Expr.Ecast (Expr.Etempvar _dst tuchar) tuchar)
            (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
          (Ty.Tstruct _x86_sim_gpr_cell noattr)) _value
        (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
  (Stmt.Sset _t'3
    (Expr.Ecast (Expr.Etempvar _t'52 (tptr tvoid)) (tptr tvoid))))

def s_kprog_x86_ptr_load_1 : Stmt :=
(Stmt.Sset _t'3
  (Expr.Ecast
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid))
    (tptr tvoid)))

def s_kprog_x86_ptr_load_2 : Stmt :=
(Stmt.Sset ___x86_tag_reg (Expr.Ecast (Expr.Etempvar _dst tuchar) tulong))

def s_kprog_x86_ptr_load_3 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                      (Expr.Etempvar ___x86_tag_reg tulong)
                      (Expr.Econst_int (Integers.Int.repr 16) tuint) tint)
    (Stmt.Ssequence
      (Stmt.Sset _t'51
        (Expr.Efield
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                    (Ty.Tstruct _x86_sim_register_state noattr))
                  (Positive.ofNat 18727075383868559167)
                  (Ty.Tunion __3115 noattr)) _gpr_cells
                (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
              (Expr.Ecast (Expr.Etempvar ___x86_tag_reg tulong) tuchar)
              (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
            (Ty.Tstruct _x86_sim_gpr_cell noattr)) _tag tuchar))
      (Stmt.Sset _t'4 (Expr.Ecast (Expr.Etempvar _t'51 tuchar) tuint)))
    (Stmt.Sset _t'4
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuint)))
  (Stmt.Sset ___x86_wr_cell_tag
    (Expr.Ecast (Expr.Etempvar _t'4 tuint) tuchar)))

def s_kprog_x86_ptr_load_4 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                    (Expr.Ecast (Expr.Etempvar ___x86_wr_width tuchar)
                      tuchar) (Expr.Econst_int (Integers.Int.repr 1) tuint)
                    tint)
  (Stmt.Sset _t'9
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuint))
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Ecast (Expr.Etempvar ___x86_wr_width tuchar)
                        tuchar) (Expr.Econst_int (Integers.Int.repr 2) tuint)
                      tint)
    (Stmt.Ssequence
      (Stmt.Sset _t'9
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
      (Stmt.Sset _t'9 (Expr.Ecast (Expr.Etempvar _t'9 tuint) tuint)))
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                        (Expr.Ecast (Expr.Etempvar ___x86_wr_width tuchar)
                          tuchar)
                        (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sset _t'9
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint) tuint))
          (Stmt.Sset _t'9 (Expr.Ecast (Expr.Etempvar _t'9 tuint) tuint)))
        (Stmt.Sset _t'9 (Expr.Ecast (Expr.Etempvar _t'9 tuint) tuint)))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sset _t'9
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))
          (Stmt.Sset _t'9 (Expr.Ecast (Expr.Etempvar _t'9 tuint) tuint)))
        (Stmt.Sset _t'9 (Expr.Ecast (Expr.Etempvar _t'9 tuint) tuint))))))

def s_kprog_x86_ptr_load_5 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _dst tuchar)
                      (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
    (Stmt.Ssequence
      (Stmt.Sset _t'49
        (Expr.Efield
          (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr)) _ptr
          (tptr tvoid)))
      (Stmt.Ssequence
        (Stmt.Sset _t'50
          (Expr.Efield
            (Expr.Ederef
              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
              (Ty.Tstruct _x86_sim_register_state noattr)) _native_stack_base
            tulong))
        (Stmt.Sassign
          (Expr.Efield
            (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr)) _ptr
            (tptr tvoid))
          (Expr.Ecast
            (Expr.Ecast
              (Expr.Ebinop Binop.Oadd
                (Expr.Ecast
                  (Expr.Ecast (Expr.Etempvar _t'49 (tptr tvoid)) tlong)
                  tulong) (Expr.Etempvar _t'50 tulong) tulong) tlong)
            (tptr tvoid)))))
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                        (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                        (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
      (Stmt.Ssequence
        (Stmt.Sloop
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sset _t'47
                (Expr.Efield
                  (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                  _ptr (tptr tvoid)))
              (Stmt.Ssequence
                (Stmt.Sset _t'48
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                      (Ty.Tstruct _kprog_x86_arena noattr)) _b
                    (tptr (tvolatile tuchar))))
                (Stmt.Sset ___x86_stack_delta
                  (Expr.Ebinop Binop.Osub
                    (Expr.Ecast
                      (Expr.Ecast (Expr.Etempvar _t'47 (tptr tvoid)) tlong)
                      tulong)
                    (Expr.Ecast
                      (Expr.Ecast
                        (Expr.Ecast
                          (Expr.Ecast
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Etempvar _t'48 (tptr (tvolatile tuchar)))
                                      (Expr.Econst_int (Integers.Int.repr 0) tint)
                                      (tptr (tvolatile tuchar))) tulong)
                                  tulong)
                                (Expr.Ecast
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Ecast
                                      (Expr.Econst_int (Integers.Int.repr 0) tint)
                                      tulong)
                                    (Expr.Ecast
                                      (Expr.Etempvar _capacity tuint) tulong)
                                    tulong) tulong) tulong) tulong)
                            (tptr tuchar)) (tptr tvoid)) tlong) tulong)
                    tulong))))
            (Stmt.Ssequence
              (Stmt.Sset _t'46
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                    (Ty.Tstruct _x86_sim_register_state noattr))
                  _native_stack_base tulong))
              (Stmt.Sset ___x86_wr_stack_bits
                (Expr.Ebinop Binop.Oadd
                  (Expr.Etempvar ___x86_stack_delta tulong)
                  (Expr.Etempvar _t'46 tulong) tulong))))
          Stmt.Sbreak)
        (Stmt.Sassign
          (Expr.Efield
            (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr)) _ptr
            (tptr tvoid))
          (Expr.Ecast
            (Expr.Ecast (Expr.Etempvar ___x86_wr_stack_bits tulong) tlong)
            (tptr tvoid))))
      Stmt.Sskip))
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sset ___kprog_x86_lane
        (Expr.Ecast (Expr.Etempvar ___x86_wr_next tulong) tuchar))
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                            (Expr.Econst_int (Integers.Int.repr 0) tuint)
                            tint)
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar ___x86_wr_shift tuchar)
                              (Expr.Econst_int (Integers.Int.repr 8) tuint)
                              tint)
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                    _b (tarray tuchar 8))
                  (Expr.Econst_int (Integers.Int.repr 1) tint) (tptr tuchar))
                tuchar) (Expr.Etempvar ___kprog_x86_lane tuchar))
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                    _b (tarray tuchar 8))
                  (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tuchar))
                tuchar) (Expr.Etempvar ___kprog_x86_lane tuchar)))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sset _t'45
                (Expr.Efield
                  (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                  _ptr (tptr tvoid)))
              (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
                [(tptr (tvolatile (tptr tvoid))), (tvolatile (tptr tvoid))]
                [(Expr.Eaddrof
                   (Expr.Efield
                     (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3283 noattr)))
                     _ptr (tvolatile (tptr tvoid)))
                   (tptr (tvolatile (tptr tvoid)))),
                 (Expr.Etempvar _t'45 (tptr tvoid))]))
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar ___x86_wr_shift tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                  tint)
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3283 noattr)))
                        _b (tvolatile (tarray tuchar 8)))
                      (Expr.Econst_int (Integers.Int.repr 1) tint)
                      (tptr tuchar)) tuchar)
                  (Expr.Etempvar ___kprog_x86_lane tuchar))
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3283 noattr)))
                        _b (tvolatile (tarray tuchar 8)))
                      (Expr.Econst_int (Integers.Int.repr 0) tint)
                      (tptr tuchar)) tuchar)
                  (Expr.Etempvar ___kprog_x86_lane tuchar)))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sbuiltin (some _t'5) (ExtFun.EF_vload Chunk.Mint64)
                    [(tptr (tvolatile (tptr tvoid)))]
                    [(Expr.Eaddrof
                       (Expr.Efield
                         (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3283 noattr)))
                         _ptr (tvolatile (tptr tvoid)))
                       (tptr (tvolatile (tptr tvoid))))])
                  (Stmt.Sset ___kprog_x86_bits
                    (Expr.Ecast
                      (Expr.Ecast
                        (Expr.Etempvar _t'5 (tvolatile (tptr tvoid))) tlong)
                      tulong)))
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar ___x86_wr_shift tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                      tint)
                    (Stmt.Sset ___kprog_x86_bits
                      (Expr.Ebinop Binop.Oor
                        (Expr.Ebinop Binop.Oand
                          (Expr.Etempvar ___kprog_x86_bits tulong)
                          (Expr.Eunop Unop.Onotint
                            (Expr.Econst_long (Integers.Int64.repr 65280) tulong)
                            tulong) tulong)
                        (Expr.Ebinop Binop.Oshl
                          (Expr.Ecast
                            (Expr.Etempvar ___kprog_x86_lane tuchar) tulong)
                          (Expr.Econst_int (Integers.Int.repr 8) tint)
                          tulong) tulong))
                    (Stmt.Sset ___kprog_x86_bits
                      (Expr.Ebinop Binop.Oor
                        (Expr.Ebinop Binop.Oand
                          (Expr.Etempvar ___kprog_x86_bits tulong)
                          (Expr.Eunop Unop.Onotint
                            (Expr.Econst_long (Integers.Int64.repr 255) tulong)
                            tulong) tulong)
                        (Expr.Etempvar ___kprog_x86_lane tuchar) tulong)))
                  (Stmt.Sassign
                    (Expr.Efield
                      (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                      _ptr (tptr tvoid))
                    (Expr.Ecast
                      (Expr.Ecast (Expr.Etempvar ___kprog_x86_bits tulong)
                        tlong) (tptr tvoid))))))))
        (Stmt.Sset ___x86_wr_cell_tag
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuchar))))
    Stmt.Sbreak))

def s_kprog_x86_ptr_load_6 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Ecast (Expr.Etempvar ___x86_wr_width tuchar)
                        tuchar) (Expr.Econst_int (Integers.Int.repr 1) tuint)
                      tint)
    (Stmt.Sset _t'8
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuint))
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                        (Expr.Ecast (Expr.Etempvar ___x86_wr_width tuchar)
                          tuchar)
                        (Expr.Econst_int (Integers.Int.repr 2) tuint) tint)
      (Stmt.Ssequence
        (Stmt.Sset _t'8
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
        (Stmt.Sset _t'8 (Expr.Ecast (Expr.Etempvar _t'8 tuint) tuint)))
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                          (Expr.Ecast (Expr.Etempvar ___x86_wr_width tuchar)
                            tuchar)
                          (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sset _t'8
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint)
                tuint))
            (Stmt.Sset _t'8 (Expr.Ecast (Expr.Etempvar _t'8 tuint) tuint)))
          (Stmt.Sset _t'8 (Expr.Ecast (Expr.Etempvar _t'8 tuint) tuint)))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sset _t'8
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint)
                tuint))
            (Stmt.Sset _t'8 (Expr.Ecast (Expr.Etempvar _t'8 tuint) tuint)))
          (Stmt.Sset _t'8 (Expr.Ecast (Expr.Etempvar _t'8 tuint) tuint))))))
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _t'8 tuint)
                      (Expr.Econst_int (Integers.Int.repr 1) tuint) tint)
    (Stmt.Ssequence
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _dst tuchar)
                          (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
        (Stmt.Ssequence
          (Stmt.Sset _t'43
            (Expr.Efield
              (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr)) _ptr
              (tptr tvoid)))
          (Stmt.Ssequence
            (Stmt.Sset _t'44
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                  (Ty.Tstruct _x86_sim_register_state noattr))
                _native_stack_base tulong))
            (Stmt.Sassign
              (Expr.Efield
                (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                _ptr (tptr tvoid))
              (Expr.Ecast
                (Expr.Ecast
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Ecast
                      (Expr.Ecast (Expr.Etempvar _t'43 (tptr tvoid)) tlong)
                      tulong) (Expr.Etempvar _t'44 tulong) tulong) tlong)
                (tptr tvoid)))))
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                            (Expr.Econst_int (Integers.Int.repr 4) tuint)
                            tint)
          (Stmt.Ssequence
            (Stmt.Sloop
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sset _t'41
                    (Expr.Efield
                      (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                      _ptr (tptr tvoid)))
                  (Stmt.Ssequence
                    (Stmt.Sset _t'42
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                          (Ty.Tstruct _kprog_x86_arena noattr)) _b
                        (tptr (tvolatile tuchar))))
                    (Stmt.Sset ___x86_stack_delta__1
                      (Expr.Ebinop Binop.Osub
                        (Expr.Ecast
                          (Expr.Ecast (Expr.Etempvar _t'41 (tptr tvoid))
                            tlong) tulong)
                        (Expr.Ecast
                          (Expr.Ecast
                            (Expr.Ecast
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Ecast
                                      (Expr.Ecast
                                        (Expr.Ebinop Binop.Oadd
                                          (Expr.Etempvar _t'42 (tptr (tvolatile tuchar)))
                                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                                          (tptr (tvolatile tuchar))) tulong)
                                      tulong)
                                    (Expr.Ecast
                                      (Expr.Ebinop Binop.Oadd
                                        (Expr.Ecast
                                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                                          tulong)
                                        (Expr.Ecast
                                          (Expr.Etempvar _capacity tuint)
                                          tulong) tulong) tulong) tulong)
                                  tulong) (tptr tuchar)) (tptr tvoid)) tlong)
                          tulong) tulong))))
                (Stmt.Ssequence
                  (Stmt.Sset _t'40
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                        (Ty.Tstruct _x86_sim_register_state noattr))
                      _native_stack_base tulong))
                  (Stmt.Sset ___x86_wr_stack_bits__1
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Etempvar ___x86_stack_delta__1 tulong)
                      (Expr.Etempvar _t'40 tulong) tulong))))
              Stmt.Sbreak)
            (Stmt.Sassign
              (Expr.Efield
                (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                _ptr (tptr tvoid))
              (Expr.Ecast
                (Expr.Ecast (Expr.Etempvar ___x86_wr_stack_bits__1 tulong)
                  tlong) (tptr tvoid))))
          Stmt.Sskip))
      (Stmt.Sloop
        (Stmt.Ssequence
          (Stmt.Sset ___kprog_x86_lane__1
            (Expr.Ecast (Expr.Etempvar ___x86_wr_next tulong) tushort))
          (Stmt.Ssequence
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                                (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                tint)
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                  _w tushort) (Expr.Etempvar ___kprog_x86_lane__1 tushort))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sset _t'39
                    (Expr.Efield
                      (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                      _ptr (tptr tvoid)))
                  (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
                    [(tptr (tvolatile (tptr tvoid))),
                     (tvolatile (tptr tvoid))]
                    [(Expr.Eaddrof
                       (Expr.Efield
                         (Expr.Evar ___kprog_x86_partial__1 (tvolatile (Ty.Tunion __3289 noattr)))
                         _ptr (tvolatile (tptr tvoid)))
                       (tptr (tvolatile (tptr tvoid)))),
                     (Expr.Etempvar _t'39 (tptr tvoid))]))
                (Stmt.Ssequence
                  (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint16unsigned)
                    [(tptr (tvolatile tushort)), (tvolatile tushort)]
                    [(Expr.Eaddrof
                       (Expr.Efield
                         (Expr.Evar ___kprog_x86_partial__1 (tvolatile (Ty.Tunion __3289 noattr)))
                         _w (tvolatile tushort)) (tptr (tvolatile tushort))),
                     (Expr.Etempvar ___kprog_x86_lane__1 tushort)])
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sbuiltin (some _t'6)
                        (ExtFun.EF_vload Chunk.Mint64)
                        [(tptr (tvolatile (tptr tvoid)))]
                        [(Expr.Eaddrof
                           (Expr.Efield
                             (Expr.Evar ___kprog_x86_partial__1 (tvolatile (Ty.Tunion __3289 noattr)))
                             _ptr (tvolatile (tptr tvoid)))
                           (tptr (tvolatile (tptr tvoid))))])
                      (Stmt.Sset ___kprog_x86_bits__1
                        (Expr.Ecast
                          (Expr.Ecast
                            (Expr.Etempvar _t'6 (tvolatile (tptr tvoid)))
                            tlong) tulong)))
                    (Stmt.Sassign
                      (Expr.Efield
                        (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                        _ptr (tptr tvoid))
                      (Expr.Ecast
                        (Expr.Ecast
                          (Expr.Ebinop Binop.Oor
                            (Expr.Ebinop Binop.Oand
                              (Expr.Etempvar ___kprog_x86_bits__1 tulong)
                              (Expr.Eunop Unop.Onotint
                                (Expr.Econst_long (Integers.Int64.repr 65535) tulong)
                                tulong) tulong)
                            (Expr.Etempvar ___kprog_x86_lane__1 tushort)
                            tulong) tlong) (tptr tvoid)))))))
            (Stmt.Sset ___x86_wr_cell_tag
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                tuchar))))
        Stmt.Sbreak))
    (Stmt.Ssequence
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                          (Expr.Ecast (Expr.Etempvar ___x86_wr_width tuchar)
                            tuchar)
                          (Expr.Econst_int (Integers.Int.repr 1) tuint) tint)
        (Stmt.Sset _t'7
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuint))
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Ecast
                              (Expr.Etempvar ___x86_wr_width tuchar) tuchar)
                            (Expr.Econst_int (Integers.Int.repr 2) tuint)
                            tint)
          (Stmt.Ssequence
            (Stmt.Sset _t'7
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint)
                tuint))
            (Stmt.Sset _t'7 (Expr.Ecast (Expr.Etempvar _t'7 tuint) tuint)))
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Ecast
                                (Expr.Etempvar ___x86_wr_width tuchar)
                                tuchar)
                              (Expr.Econst_int (Integers.Int.repr 4) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'7
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint)
                    tuint))
                (Stmt.Sset _t'7
                  (Expr.Ecast (Expr.Etempvar _t'7 tuint) tuint)))
              (Stmt.Sset _t'7 (Expr.Ecast (Expr.Etempvar _t'7 tuint) tuint)))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'7
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint)
                    tuint))
                (Stmt.Sset _t'7
                  (Expr.Ecast (Expr.Etempvar _t'7 tuint) tuint)))
              (Stmt.Sset _t'7 (Expr.Ecast (Expr.Etempvar _t'7 tuint) tuint))))))
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _t'7 tuint)
                          (Expr.Econst_int (Integers.Int.repr 2) tuint) tint)
        (Stmt.Ssequence
          (Stmt.Sset ___x86_wr_next
            (Expr.Ecast
              (Expr.Ecast (Expr.Etempvar ___x86_wr_next tulong) tuint)
              tulong))
          (Stmt.Sloop
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                  _ptr (tptr tvoid))
                (Expr.Ecast
                  (Expr.Ecast
                    (Expr.Ecast (Expr.Etempvar ___x86_wr_next tulong) tuint)
                    tlong) (tptr tvoid)))
              (Stmt.Sset ___x86_wr_cell_tag
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                  tuchar)))
            Stmt.Sbreak))
        (Stmt.Sloop
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Efield
                (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                _ptr (tptr tvoid))
              (Expr.Ecast
                (Expr.Ecast
                  (Expr.Ecast (Expr.Etempvar ___x86_wr_next tulong) tulong)
                  tlong) (tptr tvoid)))
            (Stmt.Sset ___x86_wr_cell_tag
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                tuchar)))
          Stmt.Sbreak)))))

def s_kprog_x86_ptr_load_7 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _dst tuchar)
                    (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
  (Stmt.Ssequence
    (Stmt.Sset _t'37
      (Expr.Efield (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
        _ptr (tptr tvoid)))
    (Stmt.Ssequence
      (Stmt.Sset _t'38
        (Expr.Efield
          (Expr.Ederef
            (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
            (Ty.Tstruct _x86_sim_register_state noattr)) _native_stack_base
          tulong))
      (Stmt.Sassign
        (Expr.Efield
          (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr)) _ptr
          (tptr tvoid))
        (Expr.Ecast
          (Expr.Ecast
            (Expr.Ebinop Binop.Osub
              (Expr.Ecast
                (Expr.Ecast (Expr.Etempvar _t'37 (tptr tvoid)) tlong) tulong)
              (Expr.Etempvar _t'38 tulong) tulong) tlong) (tptr tvoid)))))
  Stmt.Sskip)

def s_kprog_x86_ptr_load_8 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Ole
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Etempvar ___x86_release_i tuint)
                      (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint)
                    (Expr.Etempvar _capacity tuint) tint)
  (Stmt.Sset _t'14
    (Expr.Ecast
      (Expr.Ebinop Binop.Oge (Expr.Etempvar ___x86_release_off tlong)
        (Expr.Etempvar ___x86_release_old tlong) tint) tbool))
  (Stmt.Sset _t'14 (Expr.Econst_int (Integers.Int.repr 0) tint)))

def s_kprog_x86_ptr_load_9 : Stmt :=
(Stmt.Sset _t'15
  (Expr.Ecast
    (Expr.Ebinop Binop.Ole
      (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_release_off tlong)
        (Expr.Econst_int (Integers.Int.repr 8) tint) tlong)
      (Expr.Etempvar ___x86_release_new tlong) tint) tbool))

def s_kprog_x86_ptr_load_10 : Stmt :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'10)
    (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                         cc_default))
    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
  (Stmt.Ssequence
    (Stmt.Sset _t'35
      (Expr.Efield
        (Expr.Ederef
          (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
          (Ty.Tstruct _kprog_x86_arena noattr)) _q (tptr (tvolatile tulong))))
    (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
      [(tptr (tvolatile tulong)), (tvolatile tulong)]
      [(Expr.Eaddrof
         (Expr.Ederef
           (Expr.Ebinop Binop.Oadd
             (Expr.Etempvar _t'35 (tptr (tvolatile tulong)))
             (Expr.Ebinop Binop.Odiv (Expr.Etempvar ___x86_release_i tuint)
               (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint)
             (tptr (tvolatile tulong))) (tvolatile tulong))
         (tptr (tvolatile tulong))), (Expr.Etempvar _t'10 tulong)])))

def s_kprog_x86_ptr_load_11 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_release_lane
    (Expr.Econst_int (Integers.Int.repr 0) tint))
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                          (Expr.Etempvar ___x86_release_lane tuint)
                          (Expr.Econst_int (Integers.Int.repr 8) tuint) tint)
        Stmt.Sskip
        Stmt.Sbreak)
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Etempvar ___x86_release_i tuint)
                                (Expr.Etempvar ___x86_release_lane tuint)
                                tuint) (Expr.Etempvar _capacity tuint) tint)
            (Stmt.Sset _t'12
              (Expr.Ecast
                (Expr.Ebinop Binop.Oge
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Etempvar ___x86_release_off tlong)
                    (Expr.Etempvar ___x86_release_lane tuint) tlong)
                  (Expr.Etempvar ___x86_release_old tlong) tint) tbool))
            (Stmt.Sset _t'12 (Expr.Econst_int (Integers.Int.repr 0) tint)))
          (Stmt.Sifthenelse (Expr.Etempvar _t'12 tint)
            (Stmt.Sset _t'13
              (Expr.Ecast
                (Expr.Ebinop Binop.Olt
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Etempvar ___x86_release_off tlong)
                    (Expr.Etempvar ___x86_release_lane tuint) tlong)
                  (Expr.Etempvar ___x86_release_new tlong) tint) tbool))
            (Stmt.Sset _t'13 (Expr.Econst_int (Integers.Int.repr 0) tint))))
        (Stmt.Sifthenelse (Expr.Etempvar _t'13 tint)
          (Stmt.Ssequence
            (Stmt.Scall (some _t'11)
              (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                   cc_default))
              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
            (Stmt.Ssequence
              (Stmt.Sset _t'34
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                    (Ty.Tstruct _kprog_x86_arena noattr)) _b
                  (tptr (tvolatile tuchar))))
              (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
                [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
                [(Expr.Eaddrof
                   (Expr.Ederef
                     (Expr.Ebinop Binop.Oadd
                       (Expr.Etempvar _t'34 (tptr (tvolatile tuchar)))
                       (Expr.Ebinop Binop.Oadd
                         (Expr.Etempvar ___x86_release_i tuint)
                         (Expr.Etempvar ___x86_release_lane tuint) tuint)
                       (tptr (tvolatile tuchar))) (tvolatile tuchar))
                   (tptr (tvolatile tuchar))),
                 (Expr.Ecast (Expr.Etempvar _t'11 tulong) tuchar)])))
          Stmt.Sskip)))
    (Stmt.Sset ___x86_release_lane
      (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_release_lane tuint)
        (Expr.Econst_int (Integers.Int.repr 1) tint) tuint))))

def s_kprog_x86_ptr_load_12 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                    (Expr.Ebinop Binop.Osub
                      (Expr.Ecast
                        (Expr.Ebinop Binop.Omul
                          (Expr.Ecast (Expr.Etempvar ___x86_sv_i tuint)
                            tulong)
                          (Expr.Econst_int (Integers.Int.repr 8) tuint)
                          tulong) tlong)
                      (Expr.Ecast (Expr.Etempvar _capacity tuint) tlong)
                      tlong) (Expr.Etempvar ___x86_sv_sp tlong) tint)
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sset _t'32
          (Expr.Efield
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                (Expr.Etempvar ___x86_sv_i tuint)
                (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
              (Ty.Tstruct _kprog_x86_stack_fact noattr)) _tag (tptr tuchar)))
        (Stmt.Sassign
          (Expr.Ederef (Expr.Etempvar _t'32 (tptr tuchar)) tuchar)
          (Expr.Econst_int (Integers.Int.repr 0) tuint)))
      (Stmt.Ssequence
        (Stmt.Sset _t'31
          (Expr.Efield
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                (Expr.Etempvar ___x86_sv_i tuint)
                (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
              (Ty.Tstruct _kprog_x86_stack_fact noattr)) _pointer
            (tptr (tptr tvoid))))
        (Stmt.Sassign
          (Expr.Ederef (Expr.Etempvar _t'31 (tptr (tptr tvoid)))
            (tptr tvoid)) (Expr.Econst_int (Integers.Int.repr 0) tint))))
    Stmt.Sbreak)
  Stmt.Sskip)

def s_kprog_x86_ptr_load_13 : Stmt :=
Stmt.Sbreak

def s_kprog_x86_ptr_load_14 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_wr_next_ptr
    (Expr.Efield (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
      _ptr (tptr tvoid)))
  (Stmt.Ssequence
    (Stmt.Sset ___x86_wr_next_tag
      (Expr.Ecast (Expr.Etempvar ___x86_wr_cell_tag tuchar) tuchar))
    (Stmt.Ssequence
      (Stmt.Sloop
        (Stmt.Ssequence
          (Stmt.Sset ___x86_store_reg
            (Expr.Ecast (Expr.Etempvar _dst tuchar) tulong))
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                              (Expr.Etempvar ___x86_store_reg tulong)
                              (Expr.Econst_int (Integers.Int.repr 16) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                              (Ty.Tstruct _x86_sim_register_state noattr))
                            (Positive.ofNat 18727075383868559167)
                            (Ty.Tunion __3115 noattr)) _gpr_cells
                          (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                        (Expr.Ecast (Expr.Etempvar ___x86_store_reg tulong)
                          tuchar)
                        (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                      (Ty.Tstruct _x86_sim_gpr_cell noattr)) _value
                    (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid))
                (Expr.Etempvar ___x86_wr_next_ptr (tptr tvoid)))
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                            (Ty.Tstruct _x86_sim_register_state noattr))
                          (Positive.ofNat 18727075383868559167)
                          (Ty.Tunion __3115 noattr)) _gpr_cells
                        (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                      (Expr.Ecast (Expr.Etempvar ___x86_store_reg tulong)
                        tuchar) (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                    (Ty.Tstruct _x86_sim_gpr_cell noattr)) _tag tuchar)
                (Expr.Etempvar ___x86_wr_next_tag tuchar)))
            Stmt.Sskip))
        Stmt.Sbreak)
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _dst tuchar)
                          (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
        (Stmt.Sloop
          (Stmt.Ssequence
            (Stmt.Sset ___x86_release_old
              (Expr.Etempvar ___x86_write_old_sp tlong))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'36
                  (Expr.Efield
                    (Expr.Efield
                      (Expr.Efield
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                            (Ty.Tstruct _x86_sim_register_state noattr))
                          (Positive.ofNat 18727075383868559167)
                          (Ty.Tunion __3115 noattr))
                        (Positive.ofNat 18727075383868559167)
                        (Ty.Tstruct __3116 noattr)) _rsp
                      (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
                (Stmt.Sset ___x86_release_new
                  (Expr.Ecast
                    (Expr.Ecast (Expr.Etempvar _t'36 (tptr tvoid)) tlong)
                    tlong)))
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Ogt
                                  (Expr.Etempvar ___x86_release_new tlong)
                                  (Expr.Etempvar ___x86_release_old tlong)
                                  tint)
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sset ___x86_release_i
                      (Expr.Econst_int (Integers.Int.repr 0) tint))
                    (Stmt.Sloop
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                            (Expr.Etempvar ___x86_release_i tuint)
                                            (Expr.Etempvar _capacity tuint)
                                            tint)
                          Stmt.Sskip
                          Stmt.Sbreak)
                        (Stmt.Ssequence
                          (Stmt.Sset ___x86_release_off
                            (Expr.Ebinop Binop.Osub
                              (Expr.Ecast
                                (Expr.Etempvar ___x86_release_i tuint) tlong)
                              (Expr.Ecast (Expr.Etempvar _capacity tuint)
                                tlong) tlong))
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              s_kprog_x86_ptr_load_8
                              (Stmt.Sifthenelse (Expr.Etempvar _t'14 tint)
                                s_kprog_x86_ptr_load_9
                                (Stmt.Sset _t'15
                                  (Expr.Econst_int (Integers.Int.repr 0) tint))))
                            (Stmt.Sifthenelse (Expr.Etempvar _t'15 tint)
                              s_kprog_x86_ptr_load_10
                              s_kprog_x86_ptr_load_11))))
                      (Stmt.Sset ___x86_release_i
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Etempvar ___x86_release_i tuint)
                          (Expr.Econst_int (Integers.Int.repr 8) tuint)
                          tuint))))
                  (Stmt.Sloop
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sset _t'33
                          (Expr.Efield
                            (Expr.Efield
                              (Expr.Efield
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                    (Ty.Tstruct _x86_sim_register_state noattr))
                                  (Positive.ofNat 18727075383868559167)
                                  (Ty.Tunion __3115 noattr))
                                (Positive.ofNat 18727075383868559167)
                                (Ty.Tstruct __3116 noattr)) _rsp
                              (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                            (tptr tvoid)))
                        (Stmt.Sset ___x86_sv_sp
                          (Expr.Ecast
                            (Expr.Ecast (Expr.Etempvar _t'33 (tptr tvoid))
                              tlong) tlong)))
                      (Stmt.Ssequence
                        (Stmt.Sset ___x86_sv_i
                          (Expr.Econst_int (Integers.Int.repr 0) tint))
                        (Stmt.Sloop
                          (Stmt.Ssequence
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                                (Expr.Etempvar ___x86_sv_i tuint)
                                                (Expr.Ebinop Binop.Odiv
                                                  (Expr.Ebinop Binop.Oadd
                                                    (Expr.Ecast
                                                      (Expr.Etempvar _capacity tuint)
                                                      tulong)
                                                    (Expr.Econst_int (Integers.Int.repr 7) tuint)
                                                    tulong)
                                                  (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                                  tulong) tint)
                              Stmt.Sskip
                              Stmt.Sbreak)
                            (Stmt.Sloop
                              s_kprog_x86_ptr_load_12
                              s_kprog_x86_ptr_load_13))
                          (Stmt.Sset ___x86_sv_i
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar ___x86_sv_i tuint)
                              (Expr.Econst_int (Integers.Int.repr 1) tint)
                              tuint)))))
                    Stmt.Sbreak))
                Stmt.Sskip)))
          Stmt.Sbreak)
        Stmt.Sskip))))

def s_kprog_x86_ptr_load_15 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset ___x86_release_i__1
      (Expr.Econst_int (Integers.Int.repr 0) tint))
    (Stmt.Sloop
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                            (Expr.Etempvar ___x86_release_i__1 tuint)
                            (Expr.Etempvar _capacity tuint) tint)
          Stmt.Sskip
          Stmt.Sbreak)
        (Stmt.Ssequence
          (Stmt.Sset ___x86_release_off__1
            (Expr.Ebinop Binop.Osub
              (Expr.Ecast (Expr.Etempvar ___x86_release_i__1 tuint) tlong)
              (Expr.Ecast (Expr.Etempvar _capacity tuint) tlong) tlong))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Ole
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Etempvar ___x86_release_i__1 tuint)
                                    (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                    tuint) (Expr.Etempvar _capacity tuint)
                                  tint)
                (Stmt.Sset _t'21
                  (Expr.Ecast
                    (Expr.Ebinop Binop.Oge
                      (Expr.Etempvar ___x86_release_off__1 tlong)
                      (Expr.Etempvar ___x86_release_old__1 tlong) tint)
                    tbool))
                (Stmt.Sset _t'21
                  (Expr.Econst_int (Integers.Int.repr 0) tint)))
              (Stmt.Sifthenelse (Expr.Etempvar _t'21 tint)
                (Stmt.Sset _t'22
                  (Expr.Ecast
                    (Expr.Ebinop Binop.Ole
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar ___x86_release_off__1 tlong)
                        (Expr.Econst_int (Integers.Int.repr 8) tint) tlong)
                      (Expr.Etempvar ___x86_release_new__1 tlong) tint)
                    tbool))
                (Stmt.Sset _t'22
                  (Expr.Econst_int (Integers.Int.repr 0) tint))))
            (Stmt.Sifthenelse (Expr.Etempvar _t'22 tint)
              (Stmt.Ssequence
                (Stmt.Scall (some _t'17)
                  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                       tulong cc_default))
                  [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                (Stmt.Ssequence
                  (Stmt.Sset _t'27
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                        (Ty.Tstruct _kprog_x86_arena noattr)) _q
                      (tptr (tvolatile tulong))))
                  (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
                    [(tptr (tvolatile tulong)), (tvolatile tulong)]
                    [(Expr.Eaddrof
                       (Expr.Ederef
                         (Expr.Ebinop Binop.Oadd
                           (Expr.Etempvar _t'27 (tptr (tvolatile tulong)))
                           (Expr.Ebinop Binop.Odiv
                             (Expr.Etempvar ___x86_release_i__1 tuint)
                             (Expr.Econst_int (Integers.Int.repr 8) tuint)
                             tuint) (tptr (tvolatile tulong)))
                         (tvolatile tulong)) (tptr (tvolatile tulong))),
                     (Expr.Etempvar _t'17 tulong)])))
              (Stmt.Ssequence
                (Stmt.Sset ___x86_release_lane__1
                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                        (Expr.Etempvar ___x86_release_lane__1 tuint)
                                        (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                        tint)
                      Stmt.Sskip
                      Stmt.Sbreak)
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                            (Expr.Ebinop Binop.Oadd
                                              (Expr.Etempvar ___x86_release_i__1 tuint)
                                              (Expr.Etempvar ___x86_release_lane__1 tuint)
                                              tuint)
                                            (Expr.Etempvar _capacity tuint)
                                            tint)
                          (Stmt.Sset _t'19
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Oge
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Etempvar ___x86_release_off__1 tlong)
                                  (Expr.Etempvar ___x86_release_lane__1 tuint)
                                  tlong)
                                (Expr.Etempvar ___x86_release_old__1 tlong)
                                tint) tbool))
                          (Stmt.Sset _t'19
                            (Expr.Econst_int (Integers.Int.repr 0) tint)))
                        (Stmt.Sifthenelse (Expr.Etempvar _t'19 tint)
                          (Stmt.Sset _t'20
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Olt
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Etempvar ___x86_release_off__1 tlong)
                                  (Expr.Etempvar ___x86_release_lane__1 tuint)
                                  tlong)
                                (Expr.Etempvar ___x86_release_new__1 tlong)
                                tint) tbool))
                          (Stmt.Sset _t'20
                            (Expr.Econst_int (Integers.Int.repr 0) tint))))
                      (Stmt.Sifthenelse (Expr.Etempvar _t'20 tint)
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'18)
                            (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                 [tuint]
                                                                 tulong
                                                                 cc_default))
                            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                          (Stmt.Ssequence
                            (Stmt.Sset _t'26
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                                  (Ty.Tstruct _kprog_x86_arena noattr)) _b
                                (tptr (tvolatile tuchar))))
                            (Stmt.Sbuiltin none
                              (ExtFun.EF_vstore Chunk.Mint8unsigned)
                              [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
                              [(Expr.Eaddrof
                                 (Expr.Ederef
                                   (Expr.Ebinop Binop.Oadd
                                     (Expr.Etempvar _t'26 (tptr (tvolatile tuchar)))
                                     (Expr.Ebinop Binop.Oadd
                                       (Expr.Etempvar ___x86_release_i__1 tuint)
                                       (Expr.Etempvar ___x86_release_lane__1 tuint)
                                       tuint) (tptr (tvolatile tuchar)))
                                   (tvolatile tuchar))
                                 (tptr (tvolatile tuchar))),
                               (Expr.Ecast (Expr.Etempvar _t'18 tulong)
                                 tuchar)])))
                        Stmt.Sskip)))
                  (Stmt.Sset ___x86_release_lane__1
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Etempvar ___x86_release_lane__1 tuint)
                      (Expr.Econst_int (Integers.Int.repr 1) tint) tuint))))))))
      (Stmt.Sset ___x86_release_i__1
        (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_release_i__1 tuint)
          (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint))))
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sset _t'25
          (Expr.Efield
            (Expr.Efield
              (Expr.Efield
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                    (Ty.Tstruct _x86_sim_register_state noattr))
                  (Positive.ofNat 18727075383868559167)
                  (Ty.Tunion __3115 noattr))
                (Positive.ofNat 18727075383868559167)
                (Ty.Tstruct __3116 noattr)) _rsp
              (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
        (Stmt.Sset ___x86_sv_sp__1
          (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'25 (tptr tvoid)) tlong)
            tlong)))
      (Stmt.Ssequence
        (Stmt.Sset ___x86_sv_i__1
          (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Sloop
          (Stmt.Ssequence
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                (Expr.Etempvar ___x86_sv_i__1 tuint)
                                (Expr.Ebinop Binop.Odiv
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Ecast
                                      (Expr.Etempvar _capacity tuint) tulong)
                                    (Expr.Econst_int (Integers.Int.repr 7) tuint)
                                    tulong)
                                  (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                  tulong) tint)
              Stmt.Sskip
              Stmt.Sbreak)
            (Stmt.Sloop
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                  (Expr.Ebinop Binop.Osub
                                    (Expr.Ecast
                                      (Expr.Ebinop Binop.Omul
                                        (Expr.Ecast
                                          (Expr.Etempvar ___x86_sv_i__1 tuint)
                                          tulong)
                                        (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                        tulong) tlong)
                                    (Expr.Ecast
                                      (Expr.Etempvar _capacity tuint) tlong)
                                    tlong)
                                  (Expr.Etempvar ___x86_sv_sp__1 tlong) tint)
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sset _t'24
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                              (Expr.Etempvar ___x86_sv_i__1 tuint)
                              (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                            (Ty.Tstruct _kprog_x86_stack_fact noattr)) _tag
                          (tptr tuchar)))
                      (Stmt.Sassign
                        (Expr.Ederef (Expr.Etempvar _t'24 (tptr tuchar))
                          tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tuint)))
                    (Stmt.Ssequence
                      (Stmt.Sset _t'23
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                              (Expr.Etempvar ___x86_sv_i__1 tuint)
                              (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                            (Ty.Tstruct _kprog_x86_stack_fact noattr))
                          _pointer (tptr (tptr tvoid))))
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Etempvar _t'23 (tptr (tptr tvoid)))
                          (tptr tvoid))
                        (Expr.Econst_int (Integers.Int.repr 0) tint))))
                  Stmt.Sbreak)
                Stmt.Sskip)
              Stmt.Sbreak))
          (Stmt.Sset ___x86_sv_i__1
            (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_sv_i__1 tuint)
              (Expr.Econst_int (Integers.Int.repr 1) tint) tuint)))))
    Stmt.Sbreak))

def f_kprog_x86_ptr_load : Function := {
  fn_return := tvoid,
  fn_callconv := cc_default,
  fn_params := [(_state, (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
                (_arena, (tptr (Ty.Tstruct _kprog_x86_arena noattr))),
                (_facts, (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr))),
                (_capacity, tuint), (_op, tuchar), (_dst, tuchar),
                (_aux, tuint), (_imm, tulong)],
  fn_vars := [(___x86_wr_cell, (Ty.Tunion _x86_sim_gpr noattr)),
              (___kprog_x86_partial, (tvolatile (Ty.Tunion __3283 noattr))),
              (___kprog_x86_partial__1,
               (tvolatile (Ty.Tunion __3289 noattr)))],
  fn_temps := [(___x86_state,
                (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
               (___x86_l_pw_tag, tuchar), (___kprog_x86_source_tag, tuchar),
               (___kprog_x86_pw_tag, tuchar), (___x86_write_old_sp, tlong),
               (___x86_wr_raw_width, tuchar), (___x86_wr_width, tuchar),
               (___x86_wr_shift, tuchar), (___x86_wr_next, tulong),
               (___x86_wr_cell_tag, tuchar), (___x86_tag_reg, tulong),
               (___x86_wr_stack_bits, tulong), (___x86_stack_delta, tulong),
               (___kprog_x86_lane, tuchar), (___kprog_x86_bits, tulong),
               (___x86_wr_stack_bits__1, tulong),
               (___x86_stack_delta__1, tulong),
               (___kprog_x86_lane__1, tushort),
               (___kprog_x86_bits__1, tulong),
               (___x86_wr_next_ptr, (tptr tvoid)),
               (___x86_wr_next_tag, tuchar), (___x86_store_reg, tulong),
               (___x86_release_old, tlong), (___x86_release_new, tlong),
               (___x86_release_i, tuint), (___x86_release_off, tlong),
               (___x86_release_lane, tuint), (___x86_sv_sp, tlong),
               (___x86_sv_i, tuint), (___x86_write_old_sp__1, tlong),
               (___x86_wr_next_ptr__1, (tptr tvoid)),
               (___x86_wr_next_tag__1, tuchar),
               (___x86_store_reg__1, tulong), (___x86_release_old__1, tlong),
               (___x86_release_new__1, tlong), (___x86_release_i__1, tuint),
               (___x86_release_off__1, tlong),
               (___x86_release_lane__1, tuint), (___x86_sv_sp__1, tlong),
               (___x86_sv_i__1, tuint), (_t'22, tint), (_t'21, tint),
               (_t'20, tint), (_t'19, tint), (_t'18, tulong),
               (_t'17, tulong), (_t'16, tulong), (_t'15, tint),
               (_t'14, tint), (_t'13, tint), (_t'12, tint), (_t'11, tulong),
               (_t'10, tulong), (_t'9, tuint), (_t'8, tuint), (_t'7, tuint),
               (_t'6, (tvolatile (tptr tvoid))),
               (_t'5, (tvolatile (tptr tvoid))), (_t'4, tuint),
               (_t'3, (tptr tvoid)), (_t'2, tuchar), (_t'1, tint),
               (_t'53, (tptr tvoid)), (_t'52, (tptr tvoid)), (_t'51, tuchar),
               (_t'50, tulong), (_t'49, (tptr tvoid)),
               (_t'48, (tptr (tvolatile tuchar))), (_t'47, (tptr tvoid)),
               (_t'46, tulong), (_t'45, (tptr tvoid)), (_t'44, tulong),
               (_t'43, (tptr tvoid)), (_t'42, (tptr (tvolatile tuchar))),
               (_t'41, (tptr tvoid)), (_t'40, tulong), (_t'39, (tptr tvoid)),
               (_t'38, tulong), (_t'37, (tptr tvoid)), (_t'36, (tptr tvoid)),
               (_t'35, (tptr (tvolatile tulong))),
               (_t'34, (tptr (tvolatile tuchar))), (_t'33, (tptr tvoid)),
               (_t'32, (tptr tuchar)), (_t'31, (tptr (tptr tvoid))),
               (_t'30, (tptr tvoid)), (_t'29, tulong), (_t'28, (tptr tvoid)),
               (_t'27, (tptr (tvolatile tulong))),
               (_t'26, (tptr (tvolatile tuchar))), (_t'25, (tptr tvoid)),
               (_t'24, (tptr tuchar)), (_t'23, (tptr (tptr tvoid)))],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_state
    (Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))))
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sloop
        (Stmt.Ssequence
          (Stmt.Sloop
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar _op tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 44) tuint)
                                  tint)
                (Stmt.Sset ___kprog_x86_pw_tag
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 5) tuint)
                    tuchar))
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Etempvar _op tuchar)
                                    (Expr.Econst_int (Integers.Int.repr 45) tuint)
                                    tint)
                  (Stmt.Sset ___kprog_x86_pw_tag
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 7) tuint)
                      tuchar))
                  (Stmt.Sset ___kprog_x86_pw_tag
                    (Expr.Ecast
                      (Expr.Econst_int (Integers.Int.repr 255) tuint) tuchar))))
              (Stmt.Sset ___kprog_x86_source_tag
                (Expr.Ecast (Expr.Etempvar ___kprog_x86_pw_tag tuchar)
                  tuchar)))
            Stmt.Sbreak)
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar ___kprog_x86_source_tag tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 5) tuint)
                                  tint)
                (Stmt.Sset _t'1
                  (Expr.Ecast
                    (Expr.Ebinop Binop.Oand (Expr.Etempvar _aux tuint)
                      (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint)
                    tbool))
                (Stmt.Sset _t'1 (Expr.Econst_int (Integers.Int.repr 0) tint)))
              (Stmt.Sifthenelse (Expr.Etempvar _t'1 tint)
                (Stmt.Sset ___kprog_x86_source_tag
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 6) tuint)
                    tuchar))
                Stmt.Sskip))
            (Stmt.Sset ___x86_l_pw_tag
              (Expr.Ecast (Expr.Etempvar ___kprog_x86_source_tag tuchar)
                tuchar))))
        Stmt.Sbreak)
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar ___x86_l_pw_tag tuchar)
                            (Expr.Econst_int (Integers.Int.repr 7) tuint)
                            tint)
          (Stmt.Sloop
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'53
                  (Expr.Efield
                    (Expr.Efield
                      (Expr.Efield
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                            (Ty.Tstruct _x86_sim_register_state noattr))
                          (Positive.ofNat 18727075383868559167)
                          (Ty.Tunion __3115 noattr))
                        (Positive.ofNat 18727075383868559167)
                        (Ty.Tstruct __3116 noattr)) _rsp
                      (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
                (Stmt.Sset ___x86_write_old_sp
                  (Expr.Ecast
                    (Expr.Ecast (Expr.Etempvar _t'53 (tptr tvoid)) tlong)
                    tlong)))
              (Stmt.Ssequence
                (Stmt.Sset ___x86_wr_raw_width
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tuint)
                    tuchar))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Scall (some _t'2)
                      (Expr.Evar _x86_width_effective (Ty.Tfunction [tuchar]
                                                        tuchar cc_default))
                      [(Expr.Etempvar ___x86_wr_raw_width tuchar)])
                    (Stmt.Sset ___x86_wr_width
                      (Expr.Ecast (Expr.Etempvar _t'2 tuchar) tuchar)))
                  (Stmt.Ssequence
                    (Stmt.Sset ___x86_wr_shift
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 0) tuint) tuchar))
                    (Stmt.Ssequence
                      (Stmt.Sset ___x86_wr_next (Expr.Etempvar _imm tulong))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                              (Expr.Ecast
                                                (Expr.Etempvar _dst tuchar)
                                                tulong)
                                              (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                              tint)
                            s_kprog_x86_ptr_load_0
                            s_kprog_x86_ptr_load_1)
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                              _ptr (tptr tvoid))
                            (Expr.Etempvar _t'3 (tptr tvoid))))
                        (Stmt.Ssequence
                          (Stmt.Sloop
                            (Stmt.Ssequence
                              s_kprog_x86_ptr_load_2
                              s_kprog_x86_ptr_load_3)
                            Stmt.Sbreak)
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              s_kprog_x86_ptr_load_4
                              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                  (Expr.Etempvar _t'9 tuint)
                                                  (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                                  tint)
                                s_kprog_x86_ptr_load_5
                                s_kprog_x86_ptr_load_6))
                            (Stmt.Ssequence
                              s_kprog_x86_ptr_load_7
                              s_kprog_x86_ptr_load_14)))))))))
            Stmt.Sbreak)
          Stmt.Sskip)
        (Stmt.Sloop
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sset _t'30
                (Expr.Efield
                  (Expr.Efield
                    (Expr.Efield
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                          (Ty.Tstruct _x86_sim_register_state noattr))
                        (Positive.ofNat 18727075383868559167)
                        (Ty.Tunion __3115 noattr))
                      (Positive.ofNat 18727075383868559167)
                      (Ty.Tstruct __3116 noattr)) _rsp
                    (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
              (Stmt.Sset ___x86_write_old_sp__1
                (Expr.Ecast
                  (Expr.Ecast (Expr.Etempvar _t'30 (tptr tvoid)) tlong)
                  tlong)))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Etempvar _dst tuchar)
                                    (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                    tint)
                  (Stmt.Ssequence
                    (Stmt.Sset _t'29
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                          (Ty.Tstruct _x86_sim_register_state noattr))
                        _native_stack_base tulong))
                    (Stmt.Sset _t'16
                      (Expr.Ecast (Expr.Etempvar _t'29 tulong) tulong)))
                  (Stmt.Sset _t'16
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                      tulong)))
                (Stmt.Sset ___x86_wr_next_ptr__1
                  (Expr.Ecast
                    (Expr.Ecast
                      (Expr.Ecast
                        (Expr.Ebinop Binop.Osub
                          (Expr.Ecast (Expr.Etempvar _imm tulong) tulong)
                          (Expr.Etempvar _t'16 tulong) tulong) tlong)
                      (tptr tvoid)) (tptr tvoid))))
              (Stmt.Ssequence
                (Stmt.Sset ___x86_wr_next_tag__1
                  (Expr.Ecast (Expr.Etempvar ___x86_l_pw_tag tuchar) tuchar))
                (Stmt.Ssequence
                  (Stmt.Sloop
                    (Stmt.Ssequence
                      (Stmt.Sset ___x86_store_reg__1
                        (Expr.Ecast (Expr.Etempvar _dst tuchar) tulong))
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                          (Expr.Etempvar ___x86_store_reg__1 tulong)
                                          (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                          tint)
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Efield
                                        (Expr.Ederef
                                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                          (Ty.Tstruct _x86_sim_register_state noattr))
                                        (Positive.ofNat 18727075383868559167)
                                        (Ty.Tunion __3115 noattr)) _gpr_cells
                                      (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                                    (Expr.Ecast
                                      (Expr.Etempvar ___x86_store_reg__1 tulong)
                                      tuchar)
                                    (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                                  (Ty.Tstruct _x86_sim_gpr_cell noattr))
                                _value (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                              (tptr tvoid))
                            (Expr.Etempvar ___x86_wr_next_ptr__1 (tptr tvoid)))
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Efield
                                      (Expr.Ederef
                                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                        (Ty.Tstruct _x86_sim_register_state noattr))
                                      (Positive.ofNat 18727075383868559167)
                                      (Ty.Tunion __3115 noattr)) _gpr_cells
                                    (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                                  (Expr.Ecast
                                    (Expr.Etempvar ___x86_store_reg__1 tulong)
                                    tuchar)
                                  (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                                (Ty.Tstruct _x86_sim_gpr_cell noattr)) _tag
                              tuchar)
                            (Expr.Etempvar ___x86_wr_next_tag__1 tuchar)))
                        Stmt.Sskip))
                    Stmt.Sbreak)
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar _dst tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                      tint)
                    (Stmt.Sloop
                      (Stmt.Ssequence
                        (Stmt.Sset ___x86_release_old__1
                          (Expr.Etempvar ___x86_write_old_sp__1 tlong))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Sset _t'28
                              (Expr.Efield
                                (Expr.Efield
                                  (Expr.Efield
                                    (Expr.Efield
                                      (Expr.Ederef
                                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                        (Ty.Tstruct _x86_sim_register_state noattr))
                                      (Positive.ofNat 18727075383868559167)
                                      (Ty.Tunion __3115 noattr))
                                    (Positive.ofNat 18727075383868559167)
                                    (Ty.Tstruct __3116 noattr)) _rsp
                                  (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                                (tptr tvoid)))
                            (Stmt.Sset ___x86_release_new__1
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Etempvar _t'28 (tptr tvoid)) tlong)
                                tlong)))
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Ogt
                                              (Expr.Etempvar ___x86_release_new__1 tlong)
                                              (Expr.Etempvar ___x86_release_old__1 tlong)
                                              tint)
                            s_kprog_x86_ptr_load_15
                            Stmt.Sskip)))
                      Stmt.Sbreak)
                    Stmt.Sskip)))))
          Stmt.Sbreak)))
    Stmt.Sbreak))
}

def s_kprog_x86_read_reg_0 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                    (Expr.Etempvar ___x86_tag_reg tulong)
                    (Expr.Econst_int (Integers.Int.repr 16) tuint) tint)
  (Stmt.Ssequence
    (Stmt.Sset _t'8
      (Expr.Efield
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                  (Ty.Tstruct _x86_sim_register_state noattr))
                (Positive.ofNat 18727075383868559167)
                (Ty.Tunion __3115 noattr)) _gpr_cells
              (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
            (Expr.Ecast (Expr.Etempvar ___x86_tag_reg tulong) tuchar)
            (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
          (Ty.Tstruct _x86_sim_gpr_cell noattr)) _tag tuchar))
    (Stmt.Sset _t'3 (Expr.Ecast (Expr.Etempvar _t'8 tuchar) tuint)))
  (Stmt.Sset _t'3
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuint)))

def s_kprog_x86_read_reg_1 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'7
      (Expr.Efield
        (Expr.Ederef
          (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
          (Ty.Tstruct _kprog_x86_arena noattr)) _b (tptr (tvolatile tuchar))))
    (Stmt.Sset ___x86_stack_delta
      (Expr.Ebinop Binop.Osub
        (Expr.Ecast
          (Expr.Ecast (Expr.Etempvar ___x86_rd_ptr (tptr tvoid)) tlong)
          tulong)
        (Expr.Ecast
          (Expr.Ecast
            (Expr.Ecast
              (Expr.Ecast
                (Expr.Ecast
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Ecast
                      (Expr.Ecast
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Etempvar _t'7 (tptr (tvolatile tuchar)))
                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                          (tptr (tvolatile tuchar))) tulong) tulong)
                    (Expr.Ecast
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                          tulong)
                        (Expr.Ecast (Expr.Etempvar _capacity tuint) tulong)
                        tulong) tulong) tulong) tulong) (tptr tuchar))
              (tptr tvoid)) tlong) tulong) tulong)))
  (Stmt.Ssequence
    (Stmt.Sset _t'6
      (Expr.Efield
        (Expr.Ederef
          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
          (Ty.Tstruct _x86_sim_register_state noattr)) _native_stack_base
        tulong))
    (Stmt.Sset ___x86_rd_value
      (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_stack_delta tulong)
        (Expr.Etempvar _t'6 tulong) tulong))))

def s_kprog_x86_read_reg_2 : Stmt :=
Stmt.Sbreak

def s_kprog_x86_read_reg_3 : Stmt :=
(Stmt.Sset _t'5
  (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 65535) tulong) tulong))

def s_kprog_x86_read_reg_4 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'5
      (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 4294967295) tulong)
        tulong))
    (Stmt.Sset _t'5 (Expr.Ecast (Expr.Etempvar _t'5 tulong) tulong)))
  (Stmt.Sset _t'5 (Expr.Ecast (Expr.Etempvar _t'5 tulong) tulong)))

def s_kprog_x86_read_reg_5 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'5
      (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr (-1)) tulong)
        tulong))
    (Stmt.Sset _t'5 (Expr.Ecast (Expr.Etempvar _t'5 tulong) tulong)))
  (Stmt.Sset _t'5 (Expr.Ecast (Expr.Etempvar _t'5 tulong) tulong)))

def f_kprog_x86_read_reg : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_state, (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
                (_arena, (tptr (Ty.Tstruct _kprog_x86_arena noattr))),
                (_capacity, tuint), (_reg, tuchar), (_width, tuchar),
                (_shift, tuchar)],
  fn_vars := [],
  fn_temps := [(___x86_state,
                (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
               (_result, tulong), (___x86_rd_reg, tuchar),
               (___x86_rd_raw_width, tuchar), (___x86_rd_width, tuchar),
               (___x86_rd_shift, tuchar), (___x86_rd_ptr, (tptr tvoid)),
               (___x86_rd_value, tulong), (___x86_rd_tag, tuchar),
               (___x86_tag_reg, tulong), (___x86_stack_delta, tulong),
               (_t'5, tulong), (_t'4, tuint), (_t'3, tuint),
               (_t'2, (tptr tvoid)), (_t'1, tuchar), (_t'10, (tptr tvoid)),
               (_t'9, tulong), (_t'8, tuchar),
               (_t'7, (tptr (tvolatile tuchar))), (_t'6, tulong)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_state
    (Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))))
  (Stmt.Ssequence
    (Stmt.Sloop
      (Stmt.Ssequence
        (Stmt.Sset ___x86_rd_reg
          (Expr.Ecast (Expr.Etempvar _reg tuchar) tuchar))
        (Stmt.Ssequence
          (Stmt.Sset ___x86_rd_raw_width
            (Expr.Ecast (Expr.Etempvar _width tuchar) tuchar))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Scall (some _t'1)
                (Expr.Evar _x86_width_effective (Ty.Tfunction [tuchar] tuchar
                                                  cc_default))
                [(Expr.Etempvar ___x86_rd_raw_width tuchar)])
              (Stmt.Sset ___x86_rd_width
                (Expr.Ecast (Expr.Etempvar _t'1 tuchar) tuchar)))
            (Stmt.Ssequence
              (Stmt.Sset ___x86_rd_shift
                (Expr.Ecast (Expr.Etempvar _shift tuchar) tuchar))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                      (Expr.Ecast
                                        (Expr.Etempvar ___x86_rd_reg tuchar)
                                        tulong)
                                      (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Sset _t'10
                        (Expr.Efield
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Efield
                                    (Expr.Ederef
                                      (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                      (Ty.Tstruct _x86_sim_register_state noattr))
                                    (Positive.ofNat 18727075383868559167)
                                    (Ty.Tunion __3115 noattr)) _gpr_cells
                                  (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                                (Expr.Ecast
                                  (Expr.Etempvar ___x86_rd_reg tuchar)
                                  tuchar)
                                (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                              (Ty.Tstruct _x86_sim_gpr_cell noattr)) _value
                            (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                          (tptr tvoid)))
                      (Stmt.Sset _t'2
                        (Expr.Ecast (Expr.Etempvar _t'10 (tptr tvoid))
                          (tptr tvoid))))
                    (Stmt.Sset _t'2
                      (Expr.Ecast
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                          (tptr tvoid)) (tptr tvoid))))
                  (Stmt.Sset ___x86_rd_ptr (Expr.Etempvar _t'2 (tptr tvoid))))
                (Stmt.Ssequence
                  (Stmt.Sset ___x86_rd_value
                    (Expr.Ecast
                      (Expr.Ecast (Expr.Etempvar ___x86_rd_ptr (tptr tvoid))
                        tlong) tulong))
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Etempvar ___x86_rd_reg tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                        tint)
                      (Stmt.Ssequence
                        (Stmt.Sset _t'9
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                              (Ty.Tstruct _x86_sim_register_state noattr))
                            _native_stack_base tulong))
                        (Stmt.Sset ___x86_rd_value
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar ___x86_rd_value tulong)
                            (Expr.Etempvar _t'9 tulong) tulong)))
                      (Stmt.Ssequence
                        (Stmt.Sloop
                          (Stmt.Ssequence
                            (Stmt.Sset ___x86_tag_reg
                              (Expr.Ecast
                                (Expr.Etempvar ___x86_rd_reg tuchar) tulong))
                            (Stmt.Ssequence
                              s_kprog_x86_read_reg_0
                              (Stmt.Sset ___x86_rd_tag
                                (Expr.Ecast (Expr.Etempvar _t'3 tuint)
                                  tuchar))))
                          Stmt.Sbreak)
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Etempvar ___x86_rd_tag tuchar)
                                            (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                            tint)
                          (Stmt.Sloop
                            s_kprog_x86_read_reg_1
                            s_kprog_x86_read_reg_2)
                          Stmt.Sskip)))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Etempvar ___x86_rd_width tuchar)
                                            (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                            tint)
                          (Stmt.Sset _t'4
                            (Expr.Ecast
                              (Expr.Etempvar ___x86_rd_shift tuchar) tuint))
                          (Stmt.Sset _t'4
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 0) tuint)
                              tuint)))
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Etempvar ___x86_rd_width tuchar)
                                            (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                            tint)
                          (Stmt.Sset _t'5
                            (Expr.Ecast
                              (Expr.Econst_long (Integers.Int64.repr 255) tulong)
                              tulong))
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Etempvar ___x86_rd_width tuchar)
                                              (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                              tint)
                            (Stmt.Ssequence
                              s_kprog_x86_read_reg_3
                              (Stmt.Sset _t'5
                                (Expr.Ecast (Expr.Etempvar _t'5 tulong)
                                  tulong)))
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                (Expr.Etempvar ___x86_rd_width tuchar)
                                                (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                                tint)
                              s_kprog_x86_read_reg_4
                              s_kprog_x86_read_reg_5))))
                      (Stmt.Sset _result
                        (Expr.Ebinop Binop.Oand
                          (Expr.Ebinop Binop.Oshr
                            (Expr.Etempvar ___x86_rd_value tulong)
                            (Expr.Etempvar _t'4 tuint) tulong)
                          (Expr.Etempvar _t'5 tulong) tulong))))))))))
      Stmt.Sbreak)
    (Stmt.Sreturn (some (Expr.Etempvar _result tulong)))))
}

def s_kprog_x86_write_reg_0 : Stmt :=
(Stmt.Sset _t'8
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))

def s_kprog_x86_write_reg_1 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'8
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint) tuint))
    (Stmt.Sset _t'8 (Expr.Ecast (Expr.Etempvar _t'8 tuint) tuint)))
  (Stmt.Sset _t'8 (Expr.Ecast (Expr.Etempvar _t'8 tuint) tuint)))

def s_kprog_x86_write_reg_2 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'8
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))
    (Stmt.Sset _t'8 (Expr.Ecast (Expr.Etempvar _t'8 tuint) tuint)))
  (Stmt.Sset _t'8 (Expr.Ecast (Expr.Etempvar _t'8 tuint) tuint)))

def s_kprog_x86_write_reg_3 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'33
    (Expr.Efield (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
      _ptr (tptr tvoid)))
  (Stmt.Ssequence
    (Stmt.Sset _t'34
      (Expr.Efield
        (Expr.Ederef
          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
          (Ty.Tstruct _x86_sim_register_state noattr)) _native_stack_base
        tulong))
    (Stmt.Sassign
      (Expr.Efield (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
        _ptr (tptr tvoid))
      (Expr.Ecast
        (Expr.Ecast
          (Expr.Ebinop Binop.Oadd
            (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'33 (tptr tvoid)) tlong)
              tulong) (Expr.Etempvar _t'34 tulong) tulong) tlong)
        (tptr tvoid)))))

def s_kprog_x86_write_reg_4 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sset _t'31
          (Expr.Efield
            (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr)) _ptr
            (tptr tvoid)))
        (Stmt.Ssequence
          (Stmt.Sset _t'32
            (Expr.Efield
              (Expr.Ederef
                (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                (Ty.Tstruct _kprog_x86_arena noattr)) _b
              (tptr (tvolatile tuchar))))
          (Stmt.Sset ___x86_stack_delta
            (Expr.Ebinop Binop.Osub
              (Expr.Ecast
                (Expr.Ecast (Expr.Etempvar _t'31 (tptr tvoid)) tlong) tulong)
              (Expr.Ecast
                (Expr.Ecast
                  (Expr.Ecast
                    (Expr.Ecast
                      (Expr.Ecast
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Ecast
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Etempvar _t'32 (tptr (tvolatile tuchar)))
                                (Expr.Econst_int (Integers.Int.repr 0) tint)
                                (tptr (tvolatile tuchar))) tulong) tulong)
                          (Expr.Ecast
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 0) tint)
                                tulong)
                              (Expr.Ecast (Expr.Etempvar _capacity tuint)
                                tulong) tulong) tulong) tulong) tulong)
                      (tptr tuchar)) (tptr tvoid)) tlong) tulong) tulong))))
      (Stmt.Ssequence
        (Stmt.Sset _t'30
          (Expr.Efield
            (Expr.Ederef
              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
              (Ty.Tstruct _x86_sim_register_state noattr)) _native_stack_base
            tulong))
        (Stmt.Sset ___x86_wr_stack_bits
          (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_stack_delta tulong)
            (Expr.Etempvar _t'30 tulong) tulong))))
    Stmt.Sbreak)
  (Stmt.Sassign
    (Expr.Efield (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
      _ptr (tptr tvoid))
    (Expr.Ecast
      (Expr.Ecast (Expr.Etempvar ___x86_wr_stack_bits tulong) tlong)
      (tptr tvoid))))

def s_kprog_x86_write_reg_5 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                    (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                    (Expr.Econst_int (Integers.Int.repr 0) tuint) tint)
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Etempvar ___x86_wr_shift tuchar)
                      (Expr.Econst_int (Integers.Int.repr 8) tuint) tint)
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Efield
            (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr)) _b
            (tarray tuchar 8)) (Expr.Econst_int (Integers.Int.repr 1) tint)
          (tptr tuchar)) tuchar) (Expr.Etempvar ___kprog_x86_lane tuchar))
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Efield
            (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr)) _b
            (tarray tuchar 8)) (Expr.Econst_int (Integers.Int.repr 0) tint)
          (tptr tuchar)) tuchar) (Expr.Etempvar ___kprog_x86_lane tuchar)))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sset _t'29
        (Expr.Efield
          (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr)) _ptr
          (tptr tvoid)))
      (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
        [(tptr (tvolatile (tptr tvoid))), (tvolatile (tptr tvoid))]
        [(Expr.Eaddrof
           (Expr.Efield
             (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3354 noattr)))
             _ptr (tvolatile (tptr tvoid))) (tptr (tvolatile (tptr tvoid)))),
         (Expr.Etempvar _t'29 (tptr tvoid))]))
    (Stmt.Ssequence
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                          (Expr.Etempvar ___x86_wr_shift tuchar)
                          (Expr.Econst_int (Integers.Int.repr 8) tuint) tint)
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3354 noattr)))
                _b (tvolatile (tarray tuchar 8)))
              (Expr.Econst_int (Integers.Int.repr 1) tint) (tptr tuchar))
            tuchar) (Expr.Etempvar ___kprog_x86_lane tuchar))
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3354 noattr)))
                _b (tvolatile (tarray tuchar 8)))
              (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tuchar))
            tuchar) (Expr.Etempvar ___kprog_x86_lane tuchar)))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sbuiltin (some _t'4) (ExtFun.EF_vload Chunk.Mint64)
            [(tptr (tvolatile (tptr tvoid)))]
            [(Expr.Eaddrof
               (Expr.Efield
                 (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3354 noattr)))
                 _ptr (tvolatile (tptr tvoid)))
               (tptr (tvolatile (tptr tvoid))))])
          (Stmt.Sset ___kprog_x86_bits
            (Expr.Ecast
              (Expr.Ecast (Expr.Etempvar _t'4 (tvolatile (tptr tvoid)))
                tlong) tulong)))
        (Stmt.Ssequence
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar ___x86_wr_shift tuchar)
                              (Expr.Econst_int (Integers.Int.repr 8) tuint)
                              tint)
            (Stmt.Sset ___kprog_x86_bits
              (Expr.Ebinop Binop.Oor
                (Expr.Ebinop Binop.Oand
                  (Expr.Etempvar ___kprog_x86_bits tulong)
                  (Expr.Eunop Unop.Onotint
                    (Expr.Econst_long (Integers.Int64.repr 65280) tulong)
                    tulong) tulong)
                (Expr.Ebinop Binop.Oshl
                  (Expr.Ecast (Expr.Etempvar ___kprog_x86_lane tuchar)
                    tulong) (Expr.Econst_int (Integers.Int.repr 8) tint)
                  tulong) tulong))
            (Stmt.Sset ___kprog_x86_bits
              (Expr.Ebinop Binop.Oor
                (Expr.Ebinop Binop.Oand
                  (Expr.Etempvar ___kprog_x86_bits tulong)
                  (Expr.Eunop Unop.Onotint
                    (Expr.Econst_long (Integers.Int64.repr 255) tulong)
                    tulong) tulong) (Expr.Etempvar ___kprog_x86_lane tuchar)
                tulong)))
          (Stmt.Sassign
            (Expr.Efield
              (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr)) _ptr
              (tptr tvoid))
            (Expr.Ecast
              (Expr.Ecast (Expr.Etempvar ___kprog_x86_bits tulong) tlong)
              (tptr tvoid))))))))

def s_kprog_x86_write_reg_6 : Stmt :=
(Stmt.Sset ___x86_wr_cell_tag
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuchar))

def s_kprog_x86_write_reg_7 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'7
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
  (Stmt.Sset _t'7 (Expr.Ecast (Expr.Etempvar _t'7 tuint) tuint)))

def s_kprog_x86_write_reg_8 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                    (Expr.Ecast (Expr.Etempvar ___x86_wr_width tuchar)
                      tuchar) (Expr.Econst_int (Integers.Int.repr 4) tuint)
                    tint)
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sset _t'7
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint) tuint))
      (Stmt.Sset _t'7 (Expr.Ecast (Expr.Etempvar _t'7 tuint) tuint)))
    (Stmt.Sset _t'7 (Expr.Ecast (Expr.Etempvar _t'7 tuint) tuint)))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sset _t'7
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))
      (Stmt.Sset _t'7 (Expr.Ecast (Expr.Etempvar _t'7 tuint) tuint)))
    (Stmt.Sset _t'7 (Expr.Ecast (Expr.Etempvar _t'7 tuint) tuint))))

def s_kprog_x86_write_reg_9 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'27
    (Expr.Efield (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
      _ptr (tptr tvoid)))
  (Stmt.Ssequence
    (Stmt.Sset _t'28
      (Expr.Efield
        (Expr.Ederef
          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
          (Ty.Tstruct _x86_sim_register_state noattr)) _native_stack_base
        tulong))
    (Stmt.Sassign
      (Expr.Efield (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
        _ptr (tptr tvoid))
      (Expr.Ecast
        (Expr.Ecast
          (Expr.Ebinop Binop.Oadd
            (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'27 (tptr tvoid)) tlong)
              tulong) (Expr.Etempvar _t'28 tulong) tulong) tlong)
        (tptr tvoid)))))

def s_kprog_x86_write_reg_10 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                    (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                    (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
  (Stmt.Ssequence
    (Stmt.Sloop
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sset _t'25
            (Expr.Efield
              (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr)) _ptr
              (tptr tvoid)))
          (Stmt.Ssequence
            (Stmt.Sset _t'26
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                  (Ty.Tstruct _kprog_x86_arena noattr)) _b
                (tptr (tvolatile tuchar))))
            (Stmt.Sset ___x86_stack_delta__1
              (Expr.Ebinop Binop.Osub
                (Expr.Ecast
                  (Expr.Ecast (Expr.Etempvar _t'25 (tptr tvoid)) tlong)
                  tulong)
                (Expr.Ecast
                  (Expr.Ecast
                    (Expr.Ecast
                      (Expr.Ecast
                        (Expr.Ecast
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Ecast
                              (Expr.Ecast
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Etempvar _t'26 (tptr (tvolatile tuchar)))
                                  (Expr.Econst_int (Integers.Int.repr 0) tint)
                                  (tptr (tvolatile tuchar))) tulong) tulong)
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 0) tint)
                                  tulong)
                                (Expr.Ecast (Expr.Etempvar _capacity tuint)
                                  tulong) tulong) tulong) tulong) tulong)
                        (tptr tuchar)) (tptr tvoid)) tlong) tulong) tulong))))
        (Stmt.Ssequence
          (Stmt.Sset _t'24
            (Expr.Efield
              (Expr.Ederef
                (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                (Ty.Tstruct _x86_sim_register_state noattr))
              _native_stack_base tulong))
          (Stmt.Sset ___x86_wr_stack_bits__1
            (Expr.Ebinop Binop.Oadd
              (Expr.Etempvar ___x86_stack_delta__1 tulong)
              (Expr.Etempvar _t'24 tulong) tulong))))
      Stmt.Sbreak)
    (Stmt.Sassign
      (Expr.Efield (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
        _ptr (tptr tvoid))
      (Expr.Ecast
        (Expr.Ecast (Expr.Etempvar ___x86_wr_stack_bits__1 tulong) tlong)
        (tptr tvoid))))
  Stmt.Sskip)

def s_kprog_x86_write_reg_11 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___kprog_x86_lane__1
    (Expr.Ecast (Expr.Etempvar ___x86_wr_next tulong) tushort))
  (Stmt.Ssequence
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                        (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tuint) tint)
      (Stmt.Sassign
        (Expr.Efield
          (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr)) _w
          tushort) (Expr.Etempvar ___kprog_x86_lane__1 tushort))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sset _t'23
            (Expr.Efield
              (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr)) _ptr
              (tptr tvoid)))
          (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
            [(tptr (tvolatile (tptr tvoid))), (tvolatile (tptr tvoid))]
            [(Expr.Eaddrof
               (Expr.Efield
                 (Expr.Evar ___kprog_x86_partial__1 (tvolatile (Ty.Tunion __3360 noattr)))
                 _ptr (tvolatile (tptr tvoid)))
               (tptr (tvolatile (tptr tvoid)))),
             (Expr.Etempvar _t'23 (tptr tvoid))]))
        (Stmt.Ssequence
          (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint16unsigned)
            [(tptr (tvolatile tushort)), (tvolatile tushort)]
            [(Expr.Eaddrof
               (Expr.Efield
                 (Expr.Evar ___kprog_x86_partial__1 (tvolatile (Ty.Tunion __3360 noattr)))
                 _w (tvolatile tushort)) (tptr (tvolatile tushort))),
             (Expr.Etempvar ___kprog_x86_lane__1 tushort)])
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sbuiltin (some _t'5) (ExtFun.EF_vload Chunk.Mint64)
                [(tptr (tvolatile (tptr tvoid)))]
                [(Expr.Eaddrof
                   (Expr.Efield
                     (Expr.Evar ___kprog_x86_partial__1 (tvolatile (Ty.Tunion __3360 noattr)))
                     _ptr (tvolatile (tptr tvoid)))
                   (tptr (tvolatile (tptr tvoid))))])
              (Stmt.Sset ___kprog_x86_bits__1
                (Expr.Ecast
                  (Expr.Ecast (Expr.Etempvar _t'5 (tvolatile (tptr tvoid)))
                    tlong) tulong)))
            (Stmt.Sassign
              (Expr.Efield
                (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                _ptr (tptr tvoid))
              (Expr.Ecast
                (Expr.Ecast
                  (Expr.Ebinop Binop.Oor
                    (Expr.Ebinop Binop.Oand
                      (Expr.Etempvar ___kprog_x86_bits__1 tulong)
                      (Expr.Eunop Unop.Onotint
                        (Expr.Econst_long (Integers.Int64.repr 65535) tulong)
                        tulong) tulong)
                    (Expr.Etempvar ___kprog_x86_lane__1 tushort) tulong)
                  tlong) (tptr tvoid)))))))
    (Stmt.Sset ___x86_wr_cell_tag
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuchar))))

def s_kprog_x86_write_reg_12 : Stmt :=
Stmt.Sbreak

def s_kprog_x86_write_reg_13 : Stmt :=
(Stmt.Sset _t'6
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuint))

def s_kprog_x86_write_reg_14 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                    (Expr.Ecast (Expr.Etempvar ___x86_wr_width tuchar)
                      tuchar) (Expr.Econst_int (Integers.Int.repr 2) tuint)
                    tint)
  (Stmt.Ssequence
    (Stmt.Sset _t'6
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
    (Stmt.Sset _t'6 (Expr.Ecast (Expr.Etempvar _t'6 tuint) tuint)))
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Ecast (Expr.Etempvar ___x86_wr_width tuchar)
                        tuchar) (Expr.Econst_int (Integers.Int.repr 4) tuint)
                      tint)
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sset _t'6
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint) tuint))
        (Stmt.Sset _t'6 (Expr.Ecast (Expr.Etempvar _t'6 tuint) tuint)))
      (Stmt.Sset _t'6 (Expr.Ecast (Expr.Etempvar _t'6 tuint) tuint)))
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sset _t'6
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))
        (Stmt.Sset _t'6 (Expr.Ecast (Expr.Etempvar _t'6 tuint) tuint)))
      (Stmt.Sset _t'6 (Expr.Ecast (Expr.Etempvar _t'6 tuint) tuint)))))

def s_kprog_x86_write_reg_15 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_wr_next
    (Expr.Ecast (Expr.Ecast (Expr.Etempvar ___x86_wr_next tulong) tuint)
      tulong))
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Efield
          (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr)) _ptr
          (tptr tvoid))
        (Expr.Ecast
          (Expr.Ecast
            (Expr.Ecast (Expr.Etempvar ___x86_wr_next tulong) tuint) tlong)
          (tptr tvoid)))
      (Stmt.Sset ___x86_wr_cell_tag
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuchar)))
    Stmt.Sbreak))

def s_kprog_x86_write_reg_16 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Efield (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
      _ptr (tptr tvoid))
    (Expr.Ecast
      (Expr.Ecast (Expr.Ecast (Expr.Etempvar ___x86_wr_next tulong) tulong)
        tlong) (tptr tvoid)))
  (Stmt.Sset ___x86_wr_cell_tag
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuchar)))

def s_kprog_x86_write_reg_17 : Stmt :=
Stmt.Sbreak

def s_kprog_x86_write_reg_18 : Stmt :=
(Stmt.Sset ___x86_store_reg (Expr.Ecast (Expr.Etempvar _reg tuchar) tulong))

def s_kprog_x86_write_reg_19 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                    (Expr.Etempvar ___x86_store_reg tulong)
                    (Expr.Econst_int (Integers.Int.repr 16) tuint) tint)
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Efield
        (Expr.Efield
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                    (Ty.Tstruct _x86_sim_register_state noattr))
                  (Positive.ofNat 18727075383868559167)
                  (Ty.Tunion __3115 noattr)) _gpr_cells
                (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
              (Expr.Ecast (Expr.Etempvar ___x86_store_reg tulong) tuchar)
              (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
            (Ty.Tstruct _x86_sim_gpr_cell noattr)) _value
          (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid))
      (Expr.Etempvar ___x86_wr_next_ptr (tptr tvoid)))
    (Stmt.Sassign
      (Expr.Efield
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                  (Ty.Tstruct _x86_sim_register_state noattr))
                (Positive.ofNat 18727075383868559167)
                (Ty.Tunion __3115 noattr)) _gpr_cells
              (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
            (Expr.Ecast (Expr.Etempvar ___x86_store_reg tulong) tuchar)
            (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
          (Ty.Tstruct _x86_sim_gpr_cell noattr)) _tag tuchar)
      (Expr.Etempvar ___x86_wr_next_tag tuchar)))
  Stmt.Sskip)

def s_kprog_x86_write_reg_20 : Stmt :=
(Stmt.Sset _t'11
  (Expr.Ecast
    (Expr.Ebinop Binop.Oge
      (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_release_off tlong)
        (Expr.Etempvar ___x86_release_lane tuint) tlong)
      (Expr.Etempvar ___x86_release_old tlong) tint) tbool))

def s_kprog_x86_write_reg_21 : Stmt :=
(Stmt.Sset _t'12
  (Expr.Ecast
    (Expr.Ebinop Binop.Olt
      (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_release_off tlong)
        (Expr.Etempvar ___x86_release_lane tuint) tlong)
      (Expr.Etempvar ___x86_release_new tlong) tint) tbool))

def s_kprog_x86_write_reg_22 : Stmt :=
(Stmt.Scall (some _t'10)
  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong cc_default))
  [(Expr.Econst_int (Integers.Int.repr 6) tint)])

def s_kprog_x86_write_reg_23 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'18
    (Expr.Efield
      (Expr.Ederef
        (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
        (Ty.Tstruct _kprog_x86_arena noattr)) _b (tptr (tvolatile tuchar))))
  (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
    [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
    [(Expr.Eaddrof
       (Expr.Ederef
         (Expr.Ebinop Binop.Oadd
           (Expr.Etempvar _t'18 (tptr (tvolatile tuchar)))
           (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_release_i tuint)
             (Expr.Etempvar ___x86_release_lane tuint) tuint)
           (tptr (tvolatile tuchar))) (tvolatile tuchar))
       (tptr (tvolatile tuchar))),
     (Expr.Ecast (Expr.Etempvar _t'10 tulong) tuchar)]))

def s_kprog_x86_write_reg_24 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_release_old (Expr.Etempvar ___x86_write_old_sp tlong))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sset _t'20
        (Expr.Efield
          (Expr.Efield
            (Expr.Efield
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                  (Ty.Tstruct _x86_sim_register_state noattr))
                (Positive.ofNat 18727075383868559167)
                (Ty.Tunion __3115 noattr))
              (Positive.ofNat 18727075383868559167)
              (Ty.Tstruct __3116 noattr)) _rsp
            (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
      (Stmt.Sset ___x86_release_new
        (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'20 (tptr tvoid)) tlong)
          tlong)))
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Ogt
                        (Expr.Etempvar ___x86_release_new tlong)
                        (Expr.Etempvar ___x86_release_old tlong) tint)
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sset ___x86_release_i
            (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Sloop
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                  (Expr.Etempvar ___x86_release_i tuint)
                                  (Expr.Etempvar _capacity tuint) tint)
                Stmt.Sskip
                Stmt.Sbreak)
              (Stmt.Ssequence
                (Stmt.Sset ___x86_release_off
                  (Expr.Ebinop Binop.Osub
                    (Expr.Ecast (Expr.Etempvar ___x86_release_i tuint) tlong)
                    (Expr.Ecast (Expr.Etempvar _capacity tuint) tlong) tlong))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Ole
                                        (Expr.Ebinop Binop.Oadd
                                          (Expr.Etempvar ___x86_release_i tuint)
                                          (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                          tuint)
                                        (Expr.Etempvar _capacity tuint) tint)
                      (Stmt.Sset _t'13
                        (Expr.Ecast
                          (Expr.Ebinop Binop.Oge
                            (Expr.Etempvar ___x86_release_off tlong)
                            (Expr.Etempvar ___x86_release_old tlong) tint)
                          tbool))
                      (Stmt.Sset _t'13
                        (Expr.Econst_int (Integers.Int.repr 0) tint)))
                    (Stmt.Sifthenelse (Expr.Etempvar _t'13 tint)
                      (Stmt.Sset _t'14
                        (Expr.Ecast
                          (Expr.Ebinop Binop.Ole
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar ___x86_release_off tlong)
                              (Expr.Econst_int (Integers.Int.repr 8) tint)
                              tlong) (Expr.Etempvar ___x86_release_new tlong)
                            tint) tbool))
                      (Stmt.Sset _t'14
                        (Expr.Econst_int (Integers.Int.repr 0) tint))))
                  (Stmt.Sifthenelse (Expr.Etempvar _t'14 tint)
                    (Stmt.Ssequence
                      (Stmt.Scall (some _t'9)
                        (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                             [tuint] tulong
                                                             cc_default))
                        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                      (Stmt.Ssequence
                        (Stmt.Sset _t'19
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                              (Ty.Tstruct _kprog_x86_arena noattr)) _q
                            (tptr (tvolatile tulong))))
                        (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
                          [(tptr (tvolatile tulong)), (tvolatile tulong)]
                          [(Expr.Eaddrof
                             (Expr.Ederef
                               (Expr.Ebinop Binop.Oadd
                                 (Expr.Etempvar _t'19 (tptr (tvolatile tulong)))
                                 (Expr.Ebinop Binop.Odiv
                                   (Expr.Etempvar ___x86_release_i tuint)
                                   (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                   tuint) (tptr (tvolatile tulong)))
                               (tvolatile tulong)) (tptr (tvolatile tulong))),
                           (Expr.Etempvar _t'9 tulong)])))
                    (Stmt.Ssequence
                      (Stmt.Sset ___x86_release_lane
                        (Expr.Econst_int (Integers.Int.repr 0) tint))
                      (Stmt.Sloop
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                              (Expr.Etempvar ___x86_release_lane tuint)
                                              (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                              tint)
                            Stmt.Sskip
                            Stmt.Sbreak)
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                                  (Expr.Ebinop Binop.Oadd
                                                    (Expr.Etempvar ___x86_release_i tuint)
                                                    (Expr.Etempvar ___x86_release_lane tuint)
                                                    tuint)
                                                  (Expr.Etempvar _capacity tuint)
                                                  tint)
                                s_kprog_x86_write_reg_20
                                (Stmt.Sset _t'11
                                  (Expr.Econst_int (Integers.Int.repr 0) tint)))
                              (Stmt.Sifthenelse (Expr.Etempvar _t'11 tint)
                                s_kprog_x86_write_reg_21
                                (Stmt.Sset _t'12
                                  (Expr.Econst_int (Integers.Int.repr 0) tint))))
                            (Stmt.Sifthenelse (Expr.Etempvar _t'12 tint)
                              (Stmt.Ssequence
                                s_kprog_x86_write_reg_22
                                s_kprog_x86_write_reg_23)
                              Stmt.Sskip)))
                        (Stmt.Sset ___x86_release_lane
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar ___x86_release_lane tuint)
                            (Expr.Econst_int (Integers.Int.repr 1) tint)
                            tuint))))))))
            (Stmt.Sset ___x86_release_i
              (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_release_i tuint)
                (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint))))
        (Stmt.Sloop
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sset _t'17
                (Expr.Efield
                  (Expr.Efield
                    (Expr.Efield
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                          (Ty.Tstruct _x86_sim_register_state noattr))
                        (Positive.ofNat 18727075383868559167)
                        (Ty.Tunion __3115 noattr))
                      (Positive.ofNat 18727075383868559167)
                      (Ty.Tstruct __3116 noattr)) _rsp
                    (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
              (Stmt.Sset ___x86_sv_sp
                (Expr.Ecast
                  (Expr.Ecast (Expr.Etempvar _t'17 (tptr tvoid)) tlong)
                  tlong)))
            (Stmt.Ssequence
              (Stmt.Sset ___x86_sv_i
                (Expr.Econst_int (Integers.Int.repr 0) tint))
              (Stmt.Sloop
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                      (Expr.Etempvar ___x86_sv_i tuint)
                                      (Expr.Ebinop Binop.Odiv
                                        (Expr.Ebinop Binop.Oadd
                                          (Expr.Ecast
                                            (Expr.Etempvar _capacity tuint)
                                            tulong)
                                          (Expr.Econst_int (Integers.Int.repr 7) tuint)
                                          tulong)
                                        (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                        tulong) tint)
                    Stmt.Sskip
                    Stmt.Sbreak)
                  (Stmt.Sloop
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                        (Expr.Ebinop Binop.Osub
                                          (Expr.Ecast
                                            (Expr.Ebinop Binop.Omul
                                              (Expr.Ecast
                                                (Expr.Etempvar ___x86_sv_i tuint)
                                                tulong)
                                              (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                              tulong) tlong)
                                          (Expr.Ecast
                                            (Expr.Etempvar _capacity tuint)
                                            tlong) tlong)
                                        (Expr.Etempvar ___x86_sv_sp tlong)
                                        tint)
                      (Stmt.Sloop
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Sset _t'16
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                                    (Expr.Etempvar ___x86_sv_i tuint)
                                    (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                                  (Ty.Tstruct _kprog_x86_stack_fact noattr))
                                _tag (tptr tuchar)))
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Etempvar _t'16 (tptr tuchar)) tuchar)
                              (Expr.Econst_int (Integers.Int.repr 0) tuint)))
                          (Stmt.Ssequence
                            (Stmt.Sset _t'15
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                                    (Expr.Etempvar ___x86_sv_i tuint)
                                    (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                                  (Ty.Tstruct _kprog_x86_stack_fact noattr))
                                _pointer (tptr (tptr tvoid))))
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Etempvar _t'15 (tptr (tptr tvoid)))
                                (tptr tvoid))
                              (Expr.Econst_int (Integers.Int.repr 0) tint))))
                        Stmt.Sbreak)
                      Stmt.Sskip)
                    Stmt.Sbreak))
                (Stmt.Sset ___x86_sv_i
                  (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_sv_i tuint)
                    (Expr.Econst_int (Integers.Int.repr 1) tint) tuint)))))
          Stmt.Sbreak))
      Stmt.Sskip)))

def s_kprog_x86_write_reg_25 : Stmt :=
Stmt.Sbreak

def f_kprog_x86_write_reg : Function := {
  fn_return := tvoid,
  fn_callconv := cc_default,
  fn_params := [(_state, (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
                (_arena, (tptr (Ty.Tstruct _kprog_x86_arena noattr))),
                (_facts, (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr))),
                (_capacity, tuint), (_reg, tuchar), (_value, tulong),
                (_width, tuchar), (_shift, tuchar)],
  fn_vars := [(___x86_wr_cell, (Ty.Tunion _x86_sim_gpr noattr)),
              (___kprog_x86_partial, (tvolatile (Ty.Tunion __3354 noattr))),
              (___kprog_x86_partial__1,
               (tvolatile (Ty.Tunion __3360 noattr)))],
  fn_temps := [(___x86_state,
                (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
               (___x86_write_old_sp, tlong), (___x86_wr_raw_width, tuchar),
               (___x86_wr_width, tuchar), (___x86_wr_shift, tuchar),
               (___x86_wr_next, tulong), (___x86_wr_cell_tag, tuchar),
               (___x86_tag_reg, tulong), (___x86_wr_stack_bits, tulong),
               (___x86_stack_delta, tulong), (___kprog_x86_lane, tuchar),
               (___kprog_x86_bits, tulong),
               (___x86_wr_stack_bits__1, tulong),
               (___x86_stack_delta__1, tulong),
               (___kprog_x86_lane__1, tushort),
               (___kprog_x86_bits__1, tulong),
               (___x86_wr_next_ptr, (tptr tvoid)),
               (___x86_wr_next_tag, tuchar), (___x86_store_reg, tulong),
               (___x86_release_old, tlong), (___x86_release_new, tlong),
               (___x86_release_i, tuint), (___x86_release_off, tlong),
               (___x86_release_lane, tuint), (___x86_sv_sp, tlong),
               (___x86_sv_i, tuint), (_t'14, tint), (_t'13, tint),
               (_t'12, tint), (_t'11, tint), (_t'10, tulong), (_t'9, tulong),
               (_t'8, tuint), (_t'7, tuint), (_t'6, tuint),
               (_t'5, (tvolatile (tptr tvoid))),
               (_t'4, (tvolatile (tptr tvoid))), (_t'3, tuint),
               (_t'2, (tptr tvoid)), (_t'1, tuchar), (_t'37, (tptr tvoid)),
               (_t'36, (tptr tvoid)), (_t'35, tuchar), (_t'34, tulong),
               (_t'33, (tptr tvoid)), (_t'32, (tptr (tvolatile tuchar))),
               (_t'31, (tptr tvoid)), (_t'30, tulong), (_t'29, (tptr tvoid)),
               (_t'28, tulong), (_t'27, (tptr tvoid)),
               (_t'26, (tptr (tvolatile tuchar))), (_t'25, (tptr tvoid)),
               (_t'24, tulong), (_t'23, (tptr tvoid)), (_t'22, tulong),
               (_t'21, (tptr tvoid)), (_t'20, (tptr tvoid)),
               (_t'19, (tptr (tvolatile tulong))),
               (_t'18, (tptr (tvolatile tuchar))), (_t'17, (tptr tvoid)),
               (_t'16, (tptr tuchar)), (_t'15, (tptr (tptr tvoid)))],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_state
    (Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))))
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sset _t'37
          (Expr.Efield
            (Expr.Efield
              (Expr.Efield
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                    (Ty.Tstruct _x86_sim_register_state noattr))
                  (Positive.ofNat 18727075383868559167)
                  (Ty.Tunion __3115 noattr))
                (Positive.ofNat 18727075383868559167)
                (Ty.Tstruct __3116 noattr)) _rsp
              (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
        (Stmt.Sset ___x86_write_old_sp
          (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'37 (tptr tvoid)) tlong)
            tlong)))
      (Stmt.Ssequence
        (Stmt.Sset ___x86_wr_raw_width
          (Expr.Ecast (Expr.Etempvar _width tuchar) tuchar))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Scall (some _t'1)
              (Expr.Evar _x86_width_effective (Ty.Tfunction [tuchar] tuchar
                                                cc_default))
              [(Expr.Etempvar ___x86_wr_raw_width tuchar)])
            (Stmt.Sset ___x86_wr_width
              (Expr.Ecast (Expr.Etempvar _t'1 tuchar) tuchar)))
          (Stmt.Ssequence
            (Stmt.Sset ___x86_wr_shift
              (Expr.Ecast (Expr.Etempvar _shift tuchar) tuchar))
            (Stmt.Ssequence
              (Stmt.Sset ___x86_wr_next (Expr.Etempvar _value tulong))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                      (Expr.Ecast (Expr.Etempvar _reg tuchar)
                                        tulong)
                                      (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Sset _t'36
                        (Expr.Efield
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Efield
                                    (Expr.Ederef
                                      (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                      (Ty.Tstruct _x86_sim_register_state noattr))
                                    (Positive.ofNat 18727075383868559167)
                                    (Ty.Tunion __3115 noattr)) _gpr_cells
                                  (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                                (Expr.Ecast (Expr.Etempvar _reg tuchar)
                                  tuchar)
                                (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                              (Ty.Tstruct _x86_sim_gpr_cell noattr)) _value
                            (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                          (tptr tvoid)))
                      (Stmt.Sset _t'2
                        (Expr.Ecast (Expr.Etempvar _t'36 (tptr tvoid))
                          (tptr tvoid))))
                    (Stmt.Sset _t'2
                      (Expr.Ecast
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                          (tptr tvoid)) (tptr tvoid))))
                  (Stmt.Sassign
                    (Expr.Efield
                      (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                      _ptr (tptr tvoid)) (Expr.Etempvar _t'2 (tptr tvoid))))
                (Stmt.Ssequence
                  (Stmt.Sloop
                    (Stmt.Ssequence
                      (Stmt.Sset ___x86_tag_reg
                        (Expr.Ecast (Expr.Etempvar _reg tuchar) tulong))
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                            (Expr.Etempvar ___x86_tag_reg tulong)
                                            (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                            tint)
                          (Stmt.Ssequence
                            (Stmt.Sset _t'35
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Efield
                                        (Expr.Ederef
                                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                          (Ty.Tstruct _x86_sim_register_state noattr))
                                        (Positive.ofNat 18727075383868559167)
                                        (Ty.Tunion __3115 noattr)) _gpr_cells
                                      (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                                    (Expr.Ecast
                                      (Expr.Etempvar ___x86_tag_reg tulong)
                                      tuchar)
                                    (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                                  (Ty.Tstruct _x86_sim_gpr_cell noattr)) _tag
                                tuchar))
                            (Stmt.Sset _t'3
                              (Expr.Ecast (Expr.Etempvar _t'35 tuchar) tuint)))
                          (Stmt.Sset _t'3
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 0) tuint)
                              tuint)))
                        (Stmt.Sset ___x86_wr_cell_tag
                          (Expr.Ecast (Expr.Etempvar _t'3 tuint) tuchar))))
                    Stmt.Sbreak)
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Ecast
                                            (Expr.Etempvar ___x86_wr_width tuchar)
                                            tuchar)
                                          (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                          tint)
                        (Stmt.Sset _t'8
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tuint)
                            tuint))
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Ecast
                                              (Expr.Etempvar ___x86_wr_width tuchar)
                                              tuchar)
                                            (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                            tint)
                          (Stmt.Ssequence
                            s_kprog_x86_write_reg_0
                            (Stmt.Sset _t'8
                              (Expr.Ecast (Expr.Etempvar _t'8 tuint) tuint)))
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Ecast
                                                (Expr.Etempvar ___x86_wr_width tuchar)
                                                tuchar)
                                              (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                              tint)
                            s_kprog_x86_write_reg_1
                            s_kprog_x86_write_reg_2)))
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Etempvar _t'8 tuint)
                                          (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                          tint)
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Etempvar _reg tuchar)
                                              (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                              tint)
                            s_kprog_x86_write_reg_3
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                                                (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                                tint)
                              s_kprog_x86_write_reg_4
                              Stmt.Sskip))
                          (Stmt.Sloop
                            (Stmt.Ssequence
                              (Stmt.Sset ___kprog_x86_lane
                                (Expr.Ecast
                                  (Expr.Etempvar ___x86_wr_next tulong)
                                  tuchar))
                              (Stmt.Ssequence
                                s_kprog_x86_write_reg_5
                                s_kprog_x86_write_reg_6))
                            Stmt.Sbreak))
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Ecast
                                                (Expr.Etempvar ___x86_wr_width tuchar)
                                                tuchar)
                                              (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                              tint)
                            (Stmt.Sset _t'7
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                tuint))
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                (Expr.Ecast
                                                  (Expr.Etempvar ___x86_wr_width tuchar)
                                                  tuchar)
                                                (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                                tint)
                              s_kprog_x86_write_reg_7
                              s_kprog_x86_write_reg_8))
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Etempvar _t'7 tuint)
                                              (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                              tint)
                            (Stmt.Ssequence
                              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                  (Expr.Etempvar _reg tuchar)
                                                  (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                                  tint)
                                s_kprog_x86_write_reg_9
                                s_kprog_x86_write_reg_10)
                              (Stmt.Sloop
                                s_kprog_x86_write_reg_11
                                s_kprog_x86_write_reg_12))
                            (Stmt.Ssequence
                              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                  (Expr.Ecast
                                                    (Expr.Etempvar ___x86_wr_width tuchar)
                                                    tuchar)
                                                  (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                                  tint)
                                s_kprog_x86_write_reg_13
                                s_kprog_x86_write_reg_14)
                              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                  (Expr.Etempvar _t'6 tuint)
                                                  (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                                  tint)
                                s_kprog_x86_write_reg_15
                                (Stmt.Sloop
                                  s_kprog_x86_write_reg_16
                                  s_kprog_x86_write_reg_17)))))))
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Etempvar _reg tuchar)
                                          (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                          tint)
                        (Stmt.Ssequence
                          (Stmt.Sset _t'21
                            (Expr.Efield
                              (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                              _ptr (tptr tvoid)))
                          (Stmt.Ssequence
                            (Stmt.Sset _t'22
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                  (Ty.Tstruct _x86_sim_register_state noattr))
                                _native_stack_base tulong))
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                                _ptr (tptr tvoid))
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Ebinop Binop.Osub
                                    (Expr.Ecast
                                      (Expr.Ecast
                                        (Expr.Etempvar _t'21 (tptr tvoid))
                                        tlong) tulong)
                                    (Expr.Etempvar _t'22 tulong) tulong)
                                  tlong) (tptr tvoid)))))
                        Stmt.Sskip)
                      (Stmt.Ssequence
                        (Stmt.Sset ___x86_wr_next_ptr
                          (Expr.Efield
                            (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                            _ptr (tptr tvoid)))
                        (Stmt.Ssequence
                          (Stmt.Sset ___x86_wr_next_tag
                            (Expr.Ecast
                              (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                              tuchar))
                          (Stmt.Ssequence
                            (Stmt.Sloop
                              (Stmt.Ssequence
                                s_kprog_x86_write_reg_18
                                s_kprog_x86_write_reg_19)
                              Stmt.Sbreak)
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                (Expr.Etempvar _reg tuchar)
                                                (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                                tint)
                              (Stmt.Sloop
                                s_kprog_x86_write_reg_24
                                s_kprog_x86_write_reg_25)
                              Stmt.Sskip)))))))))))))
    Stmt.Sbreak))
}

def s_kprog_x86_mov_imm_0 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'36
    (Expr.Efield
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Efield
            (Expr.Efield
              (Expr.Ederef
                (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                (Ty.Tstruct _x86_sim_register_state noattr))
              (Positive.ofNat 18727075383868559167)
              (Ty.Tunion __3115 noattr)) _gpr_cells
            (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
          (Expr.Ecast (Expr.Etempvar ___x86_tag_reg tulong) tuchar)
          (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
        (Ty.Tstruct _x86_sim_gpr_cell noattr)) _tag tuchar))
  (Stmt.Sset _t'4 (Expr.Ecast (Expr.Etempvar _t'36 tuchar) tuint)))

def s_kprog_x86_mov_imm_1 : Stmt :=
(Stmt.Sset _t'4
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuint))

def s_kprog_x86_mov_imm_2 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'9
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
  (Stmt.Sset _t'9 (Expr.Ecast (Expr.Etempvar _t'9 tuint) tuint)))

def s_kprog_x86_mov_imm_3 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                    (Expr.Ecast (Expr.Etempvar ___x86_wr_width tuchar)
                      tuchar) (Expr.Econst_int (Integers.Int.repr 4) tuint)
                    tint)
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sset _t'9
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint) tuint))
      (Stmt.Sset _t'9 (Expr.Ecast (Expr.Etempvar _t'9 tuint) tuint)))
    (Stmt.Sset _t'9 (Expr.Ecast (Expr.Etempvar _t'9 tuint) tuint)))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sset _t'9
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))
      (Stmt.Sset _t'9 (Expr.Ecast (Expr.Etempvar _t'9 tuint) tuint)))
    (Stmt.Sset _t'9 (Expr.Ecast (Expr.Etempvar _t'9 tuint) tuint))))

def s_kprog_x86_mov_imm_4 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'34
    (Expr.Efield (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
      _ptr (tptr tvoid)))
  (Stmt.Ssequence
    (Stmt.Sset _t'35
      (Expr.Efield
        (Expr.Ederef
          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
          (Ty.Tstruct _x86_sim_register_state noattr)) _native_stack_base
        tulong))
    (Stmt.Sassign
      (Expr.Efield (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
        _ptr (tptr tvoid))
      (Expr.Ecast
        (Expr.Ecast
          (Expr.Ebinop Binop.Oadd
            (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'34 (tptr tvoid)) tlong)
              tulong) (Expr.Etempvar _t'35 tulong) tulong) tlong)
        (tptr tvoid)))))

def s_kprog_x86_mov_imm_5 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                    (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                    (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
  (Stmt.Ssequence
    (Stmt.Sloop
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sset _t'32
            (Expr.Efield
              (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr)) _ptr
              (tptr tvoid)))
          (Stmt.Ssequence
            (Stmt.Sset _t'33
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                  (Ty.Tstruct _kprog_x86_arena noattr)) _b
                (tptr (tvolatile tuchar))))
            (Stmt.Sset ___x86_stack_delta
              (Expr.Ebinop Binop.Osub
                (Expr.Ecast
                  (Expr.Ecast (Expr.Etempvar _t'32 (tptr tvoid)) tlong)
                  tulong)
                (Expr.Ecast
                  (Expr.Ecast
                    (Expr.Ecast
                      (Expr.Ecast
                        (Expr.Ecast
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Ecast
                              (Expr.Ecast
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Etempvar _t'33 (tptr (tvolatile tuchar)))
                                  (Expr.Econst_int (Integers.Int.repr 0) tint)
                                  (tptr (tvolatile tuchar))) tulong) tulong)
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 0) tint)
                                  tulong)
                                (Expr.Ecast (Expr.Etempvar _capacity tuint)
                                  tulong) tulong) tulong) tulong) tulong)
                        (tptr tuchar)) (tptr tvoid)) tlong) tulong) tulong))))
        (Stmt.Ssequence
          (Stmt.Sset _t'31
            (Expr.Efield
              (Expr.Ederef
                (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                (Ty.Tstruct _x86_sim_register_state noattr))
              _native_stack_base tulong))
          (Stmt.Sset ___x86_wr_stack_bits
            (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_stack_delta tulong)
              (Expr.Etempvar _t'31 tulong) tulong))))
      Stmt.Sbreak)
    (Stmt.Sassign
      (Expr.Efield (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
        _ptr (tptr tvoid))
      (Expr.Ecast
        (Expr.Ecast (Expr.Etempvar ___x86_wr_stack_bits tulong) tlong)
        (tptr tvoid))))
  Stmt.Sskip)

def s_kprog_x86_mov_imm_6 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___kprog_x86_lane
    (Expr.Ecast (Expr.Etempvar ___x86_wr_next tulong) tuchar))
  (Stmt.Ssequence
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                        (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tuint) tint)
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                          (Expr.Etempvar ___x86_wr_shift tuchar)
                          (Expr.Econst_int (Integers.Int.repr 8) tuint) tint)
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr)) _b
                (tarray tuchar 8))
              (Expr.Econst_int (Integers.Int.repr 1) tint) (tptr tuchar))
            tuchar) (Expr.Etempvar ___kprog_x86_lane tuchar))
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr)) _b
                (tarray tuchar 8))
              (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tuchar))
            tuchar) (Expr.Etempvar ___kprog_x86_lane tuchar)))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sset _t'30
            (Expr.Efield
              (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr)) _ptr
              (tptr tvoid)))
          (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
            [(tptr (tvolatile (tptr tvoid))), (tvolatile (tptr tvoid))]
            [(Expr.Eaddrof
               (Expr.Efield
                 (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3396 noattr)))
                 _ptr (tvolatile (tptr tvoid)))
               (tptr (tvolatile (tptr tvoid)))),
             (Expr.Etempvar _t'30 (tptr tvoid))]))
        (Stmt.Ssequence
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar ___x86_wr_shift tuchar)
                              (Expr.Econst_int (Integers.Int.repr 8) tuint)
                              tint)
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3396 noattr)))
                    _b (tvolatile (tarray tuchar 8)))
                  (Expr.Econst_int (Integers.Int.repr 1) tint) (tptr tuchar))
                tuchar) (Expr.Etempvar ___kprog_x86_lane tuchar))
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3396 noattr)))
                    _b (tvolatile (tarray tuchar 8)))
                  (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tuchar))
                tuchar) (Expr.Etempvar ___kprog_x86_lane tuchar)))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sbuiltin (some _t'5) (ExtFun.EF_vload Chunk.Mint64)
                [(tptr (tvolatile (tptr tvoid)))]
                [(Expr.Eaddrof
                   (Expr.Efield
                     (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3396 noattr)))
                     _ptr (tvolatile (tptr tvoid)))
                   (tptr (tvolatile (tptr tvoid))))])
              (Stmt.Sset ___kprog_x86_bits
                (Expr.Ecast
                  (Expr.Ecast (Expr.Etempvar _t'5 (tvolatile (tptr tvoid)))
                    tlong) tulong)))
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar ___x86_wr_shift tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                  tint)
                (Stmt.Sset ___kprog_x86_bits
                  (Expr.Ebinop Binop.Oor
                    (Expr.Ebinop Binop.Oand
                      (Expr.Etempvar ___kprog_x86_bits tulong)
                      (Expr.Eunop Unop.Onotint
                        (Expr.Econst_long (Integers.Int64.repr 65280) tulong)
                        tulong) tulong)
                    (Expr.Ebinop Binop.Oshl
                      (Expr.Ecast (Expr.Etempvar ___kprog_x86_lane tuchar)
                        tulong) (Expr.Econst_int (Integers.Int.repr 8) tint)
                      tulong) tulong))
                (Stmt.Sset ___kprog_x86_bits
                  (Expr.Ebinop Binop.Oor
                    (Expr.Ebinop Binop.Oand
                      (Expr.Etempvar ___kprog_x86_bits tulong)
                      (Expr.Eunop Unop.Onotint
                        (Expr.Econst_long (Integers.Int64.repr 255) tulong)
                        tulong) tulong)
                    (Expr.Etempvar ___kprog_x86_lane tuchar) tulong)))
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                  _ptr (tptr tvoid))
                (Expr.Ecast
                  (Expr.Ecast (Expr.Etempvar ___kprog_x86_bits tulong) tlong)
                  (tptr tvoid))))))))
    (Stmt.Sset ___x86_wr_cell_tag
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuchar))))

def s_kprog_x86_mov_imm_7 : Stmt :=
Stmt.Sbreak

def s_kprog_x86_mov_imm_8 : Stmt :=
(Stmt.Sset _t'8
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuint))

def s_kprog_x86_mov_imm_9 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                    (Expr.Ecast (Expr.Etempvar ___x86_wr_width tuchar)
                      tuchar) (Expr.Econst_int (Integers.Int.repr 2) tuint)
                    tint)
  (Stmt.Ssequence
    (Stmt.Sset _t'8
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
    (Stmt.Sset _t'8 (Expr.Ecast (Expr.Etempvar _t'8 tuint) tuint)))
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Ecast (Expr.Etempvar ___x86_wr_width tuchar)
                        tuchar) (Expr.Econst_int (Integers.Int.repr 4) tuint)
                      tint)
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sset _t'8
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint) tuint))
        (Stmt.Sset _t'8 (Expr.Ecast (Expr.Etempvar _t'8 tuint) tuint)))
      (Stmt.Sset _t'8 (Expr.Ecast (Expr.Etempvar _t'8 tuint) tuint)))
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sset _t'8
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))
        (Stmt.Sset _t'8 (Expr.Ecast (Expr.Etempvar _t'8 tuint) tuint)))
      (Stmt.Sset _t'8 (Expr.Ecast (Expr.Etempvar _t'8 tuint) tuint)))))

def s_kprog_x86_mov_imm_10 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _dst tuchar)
                      (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
    (Stmt.Ssequence
      (Stmt.Sset _t'28
        (Expr.Efield
          (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr)) _ptr
          (tptr tvoid)))
      (Stmt.Ssequence
        (Stmt.Sset _t'29
          (Expr.Efield
            (Expr.Ederef
              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
              (Ty.Tstruct _x86_sim_register_state noattr)) _native_stack_base
            tulong))
        (Stmt.Sassign
          (Expr.Efield
            (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr)) _ptr
            (tptr tvoid))
          (Expr.Ecast
            (Expr.Ecast
              (Expr.Ebinop Binop.Oadd
                (Expr.Ecast
                  (Expr.Ecast (Expr.Etempvar _t'28 (tptr tvoid)) tlong)
                  tulong) (Expr.Etempvar _t'29 tulong) tulong) tlong)
            (tptr tvoid)))))
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                        (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                        (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
      (Stmt.Ssequence
        (Stmt.Sloop
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sset _t'26
                (Expr.Efield
                  (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                  _ptr (tptr tvoid)))
              (Stmt.Ssequence
                (Stmt.Sset _t'27
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                      (Ty.Tstruct _kprog_x86_arena noattr)) _b
                    (tptr (tvolatile tuchar))))
                (Stmt.Sset ___x86_stack_delta__1
                  (Expr.Ebinop Binop.Osub
                    (Expr.Ecast
                      (Expr.Ecast (Expr.Etempvar _t'26 (tptr tvoid)) tlong)
                      tulong)
                    (Expr.Ecast
                      (Expr.Ecast
                        (Expr.Ecast
                          (Expr.Ecast
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Etempvar _t'27 (tptr (tvolatile tuchar)))
                                      (Expr.Econst_int (Integers.Int.repr 0) tint)
                                      (tptr (tvolatile tuchar))) tulong)
                                  tulong)
                                (Expr.Ecast
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Ecast
                                      (Expr.Econst_int (Integers.Int.repr 0) tint)
                                      tulong)
                                    (Expr.Ecast
                                      (Expr.Etempvar _capacity tuint) tulong)
                                    tulong) tulong) tulong) tulong)
                            (tptr tuchar)) (tptr tvoid)) tlong) tulong)
                    tulong))))
            (Stmt.Ssequence
              (Stmt.Sset _t'25
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                    (Ty.Tstruct _x86_sim_register_state noattr))
                  _native_stack_base tulong))
              (Stmt.Sset ___x86_wr_stack_bits__1
                (Expr.Ebinop Binop.Oadd
                  (Expr.Etempvar ___x86_stack_delta__1 tulong)
                  (Expr.Etempvar _t'25 tulong) tulong))))
          Stmt.Sbreak)
        (Stmt.Sassign
          (Expr.Efield
            (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr)) _ptr
            (tptr tvoid))
          (Expr.Ecast
            (Expr.Ecast (Expr.Etempvar ___x86_wr_stack_bits__1 tulong) tlong)
            (tptr tvoid))))
      Stmt.Sskip))
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sset ___kprog_x86_lane__1
        (Expr.Ecast (Expr.Etempvar ___x86_wr_next tulong) tushort))
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                            (Expr.Econst_int (Integers.Int.repr 0) tuint)
                            tint)
          (Stmt.Sassign
            (Expr.Efield
              (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr)) _w
              tushort) (Expr.Etempvar ___kprog_x86_lane__1 tushort))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sset _t'24
                (Expr.Efield
                  (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                  _ptr (tptr tvoid)))
              (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
                [(tptr (tvolatile (tptr tvoid))), (tvolatile (tptr tvoid))]
                [(Expr.Eaddrof
                   (Expr.Efield
                     (Expr.Evar ___kprog_x86_partial__1 (tvolatile (Ty.Tunion __3402 noattr)))
                     _ptr (tvolatile (tptr tvoid)))
                   (tptr (tvolatile (tptr tvoid)))),
                 (Expr.Etempvar _t'24 (tptr tvoid))]))
            (Stmt.Ssequence
              (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint16unsigned)
                [(tptr (tvolatile tushort)), (tvolatile tushort)]
                [(Expr.Eaddrof
                   (Expr.Efield
                     (Expr.Evar ___kprog_x86_partial__1 (tvolatile (Ty.Tunion __3402 noattr)))
                     _w (tvolatile tushort)) (tptr (tvolatile tushort))),
                 (Expr.Etempvar ___kprog_x86_lane__1 tushort)])
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sbuiltin (some _t'6) (ExtFun.EF_vload Chunk.Mint64)
                    [(tptr (tvolatile (tptr tvoid)))]
                    [(Expr.Eaddrof
                       (Expr.Efield
                         (Expr.Evar ___kprog_x86_partial__1 (tvolatile (Ty.Tunion __3402 noattr)))
                         _ptr (tvolatile (tptr tvoid)))
                       (tptr (tvolatile (tptr tvoid))))])
                  (Stmt.Sset ___kprog_x86_bits__1
                    (Expr.Ecast
                      (Expr.Ecast
                        (Expr.Etempvar _t'6 (tvolatile (tptr tvoid))) tlong)
                      tulong)))
                (Stmt.Sassign
                  (Expr.Efield
                    (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                    _ptr (tptr tvoid))
                  (Expr.Ecast
                    (Expr.Ecast
                      (Expr.Ebinop Binop.Oor
                        (Expr.Ebinop Binop.Oand
                          (Expr.Etempvar ___kprog_x86_bits__1 tulong)
                          (Expr.Eunop Unop.Onotint
                            (Expr.Econst_long (Integers.Int64.repr 65535) tulong)
                            tulong) tulong)
                        (Expr.Etempvar ___kprog_x86_lane__1 tushort) tulong)
                      tlong) (tptr tvoid)))))))
        (Stmt.Sset ___x86_wr_cell_tag
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuchar))))
    Stmt.Sbreak))

def s_kprog_x86_mov_imm_11 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Ecast (Expr.Etempvar ___x86_wr_width tuchar)
                        tuchar) (Expr.Econst_int (Integers.Int.repr 1) tuint)
                      tint)
    (Stmt.Sset _t'7
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuint))
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                        (Expr.Ecast (Expr.Etempvar ___x86_wr_width tuchar)
                          tuchar)
                        (Expr.Econst_int (Integers.Int.repr 2) tuint) tint)
      (Stmt.Ssequence
        (Stmt.Sset _t'7
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
        (Stmt.Sset _t'7 (Expr.Ecast (Expr.Etempvar _t'7 tuint) tuint)))
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                          (Expr.Ecast (Expr.Etempvar ___x86_wr_width tuchar)
                            tuchar)
                          (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sset _t'7
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint)
                tuint))
            (Stmt.Sset _t'7 (Expr.Ecast (Expr.Etempvar _t'7 tuint) tuint)))
          (Stmt.Sset _t'7 (Expr.Ecast (Expr.Etempvar _t'7 tuint) tuint)))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sset _t'7
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint)
                tuint))
            (Stmt.Sset _t'7 (Expr.Ecast (Expr.Etempvar _t'7 tuint) tuint)))
          (Stmt.Sset _t'7 (Expr.Ecast (Expr.Etempvar _t'7 tuint) tuint))))))
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _t'7 tuint)
                      (Expr.Econst_int (Integers.Int.repr 2) tuint) tint)
    (Stmt.Ssequence
      (Stmt.Sset ___x86_wr_next
        (Expr.Ecast (Expr.Ecast (Expr.Etempvar ___x86_wr_next tulong) tuint)
          tulong))
      (Stmt.Sloop
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Efield
              (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr)) _ptr
              (tptr tvoid))
            (Expr.Ecast
              (Expr.Ecast
                (Expr.Ecast (Expr.Etempvar ___x86_wr_next tulong) tuint)
                tlong) (tptr tvoid)))
          (Stmt.Sset ___x86_wr_cell_tag
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuchar)))
        Stmt.Sbreak))
    (Stmt.Sloop
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Efield
            (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr)) _ptr
            (tptr tvoid))
          (Expr.Ecast
            (Expr.Ecast
              (Expr.Ecast (Expr.Etempvar ___x86_wr_next tulong) tulong)
              tlong) (tptr tvoid)))
        (Stmt.Sset ___x86_wr_cell_tag
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuchar)))
      Stmt.Sbreak)))

def s_kprog_x86_mov_imm_12 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'22
    (Expr.Efield (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
      _ptr (tptr tvoid)))
  (Stmt.Ssequence
    (Stmt.Sset _t'23
      (Expr.Efield
        (Expr.Ederef
          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
          (Ty.Tstruct _x86_sim_register_state noattr)) _native_stack_base
        tulong))
    (Stmt.Sassign
      (Expr.Efield (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
        _ptr (tptr tvoid))
      (Expr.Ecast
        (Expr.Ecast
          (Expr.Ebinop Binop.Osub
            (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'22 (tptr tvoid)) tlong)
              tulong) (Expr.Etempvar _t'23 tulong) tulong) tlong)
        (tptr tvoid)))))

def s_kprog_x86_mov_imm_13 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_store_reg
    (Expr.Ecast (Expr.Etempvar _dst tuchar) tulong))
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                      (Expr.Etempvar ___x86_store_reg tulong)
                      (Expr.Econst_int (Integers.Int.repr 16) tuint) tint)
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Efield
          (Expr.Efield
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                      (Ty.Tstruct _x86_sim_register_state noattr))
                    (Positive.ofNat 18727075383868559167)
                    (Ty.Tunion __3115 noattr)) _gpr_cells
                  (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                (Expr.Ecast (Expr.Etempvar ___x86_store_reg tulong) tuchar)
                (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
              (Ty.Tstruct _x86_sim_gpr_cell noattr)) _value
            (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid))
        (Expr.Etempvar ___x86_wr_next_ptr (tptr tvoid)))
      (Stmt.Sassign
        (Expr.Efield
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                    (Ty.Tstruct _x86_sim_register_state noattr))
                  (Positive.ofNat 18727075383868559167)
                  (Ty.Tunion __3115 noattr)) _gpr_cells
                (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
              (Expr.Ecast (Expr.Etempvar ___x86_store_reg tulong) tuchar)
              (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
            (Ty.Tstruct _x86_sim_gpr_cell noattr)) _tag tuchar)
        (Expr.Etempvar ___x86_wr_next_tag tuchar)))
    Stmt.Sskip))

def s_kprog_x86_mov_imm_14 : Stmt :=
Stmt.Sbreak

def s_kprog_x86_mov_imm_15 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                    (Expr.Etempvar ___x86_release_lane tuint)
                    (Expr.Econst_int (Integers.Int.repr 8) tuint) tint)
  Stmt.Sskip
  Stmt.Sbreak)

def s_kprog_x86_mov_imm_16 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Etempvar ___x86_release_i tuint)
                          (Expr.Etempvar ___x86_release_lane tuint) tuint)
                        (Expr.Etempvar _capacity tuint) tint)
      (Stmt.Sset _t'12
        (Expr.Ecast
          (Expr.Ebinop Binop.Oge
            (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_release_off tlong)
              (Expr.Etempvar ___x86_release_lane tuint) tlong)
            (Expr.Etempvar ___x86_release_old tlong) tint) tbool))
      (Stmt.Sset _t'12 (Expr.Econst_int (Integers.Int.repr 0) tint)))
    (Stmt.Sifthenelse (Expr.Etempvar _t'12 tint)
      (Stmt.Sset _t'13
        (Expr.Ecast
          (Expr.Ebinop Binop.Olt
            (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_release_off tlong)
              (Expr.Etempvar ___x86_release_lane tuint) tlong)
            (Expr.Etempvar ___x86_release_new tlong) tint) tbool))
      (Stmt.Sset _t'13 (Expr.Econst_int (Integers.Int.repr 0) tint))))
  (Stmt.Sifthenelse (Expr.Etempvar _t'13 tint)
    (Stmt.Ssequence
      (Stmt.Scall (some _t'11)
        (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                             cc_default))
        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
      (Stmt.Ssequence
        (Stmt.Sset _t'19
          (Expr.Efield
            (Expr.Ederef
              (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
              (Ty.Tstruct _kprog_x86_arena noattr)) _b
            (tptr (tvolatile tuchar))))
        (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
          [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
          [(Expr.Eaddrof
             (Expr.Ederef
               (Expr.Ebinop Binop.Oadd
                 (Expr.Etempvar _t'19 (tptr (tvolatile tuchar)))
                 (Expr.Ebinop Binop.Oadd
                   (Expr.Etempvar ___x86_release_i tuint)
                   (Expr.Etempvar ___x86_release_lane tuint) tuint)
                 (tptr (tvolatile tuchar))) (tvolatile tuchar))
             (tptr (tvolatile tuchar))),
           (Expr.Ecast (Expr.Etempvar _t'11 tulong) tuchar)])))
    Stmt.Sskip))

def s_kprog_x86_mov_imm_17 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'17
      (Expr.Efield
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
            (Expr.Etempvar ___x86_sv_i tuint)
            (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
          (Ty.Tstruct _kprog_x86_stack_fact noattr)) _tag (tptr tuchar)))
    (Stmt.Sassign (Expr.Ederef (Expr.Etempvar _t'17 (tptr tuchar)) tuchar)
      (Expr.Econst_int (Integers.Int.repr 0) tuint)))
  (Stmt.Ssequence
    (Stmt.Sset _t'16
      (Expr.Efield
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
            (Expr.Etempvar ___x86_sv_i tuint)
            (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
          (Ty.Tstruct _kprog_x86_stack_fact noattr)) _pointer
        (tptr (tptr tvoid))))
    (Stmt.Sassign
      (Expr.Ederef (Expr.Etempvar _t'16 (tptr (tptr tvoid))) (tptr tvoid))
      (Expr.Econst_int (Integers.Int.repr 0) tint))))

def s_kprog_x86_mov_imm_18 : Stmt :=
Stmt.Sbreak

def s_kprog_x86_mov_imm_19 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _dst tuchar)
                    (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sset ___x86_release_old
        (Expr.Etempvar ___x86_write_old_sp tlong))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sset _t'21
            (Expr.Efield
              (Expr.Efield
                (Expr.Efield
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                      (Ty.Tstruct _x86_sim_register_state noattr))
                    (Positive.ofNat 18727075383868559167)
                    (Ty.Tunion __3115 noattr))
                  (Positive.ofNat 18727075383868559167)
                  (Ty.Tstruct __3116 noattr)) _rsp
                (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
          (Stmt.Sset ___x86_release_new
            (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'21 (tptr tvoid)) tlong)
              tlong)))
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Ogt
                            (Expr.Etempvar ___x86_release_new tlong)
                            (Expr.Etempvar ___x86_release_old tlong) tint)
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sset ___x86_release_i
                (Expr.Econst_int (Integers.Int.repr 0) tint))
              (Stmt.Sloop
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                      (Expr.Etempvar ___x86_release_i tuint)
                                      (Expr.Etempvar _capacity tuint) tint)
                    Stmt.Sskip
                    Stmt.Sbreak)
                  (Stmt.Ssequence
                    (Stmt.Sset ___x86_release_off
                      (Expr.Ebinop Binop.Osub
                        (Expr.Ecast (Expr.Etempvar ___x86_release_i tuint)
                          tlong)
                        (Expr.Ecast (Expr.Etempvar _capacity tuint) tlong)
                        tlong))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Ole
                                            (Expr.Ebinop Binop.Oadd
                                              (Expr.Etempvar ___x86_release_i tuint)
                                              (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                              tuint)
                                            (Expr.Etempvar _capacity tuint)
                                            tint)
                          (Stmt.Sset _t'14
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Oge
                                (Expr.Etempvar ___x86_release_off tlong)
                                (Expr.Etempvar ___x86_release_old tlong)
                                tint) tbool))
                          (Stmt.Sset _t'14
                            (Expr.Econst_int (Integers.Int.repr 0) tint)))
                        (Stmt.Sifthenelse (Expr.Etempvar _t'14 tint)
                          (Stmt.Sset _t'15
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Ole
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Etempvar ___x86_release_off tlong)
                                  (Expr.Econst_int (Integers.Int.repr 8) tint)
                                  tlong)
                                (Expr.Etempvar ___x86_release_new tlong)
                                tint) tbool))
                          (Stmt.Sset _t'15
                            (Expr.Econst_int (Integers.Int.repr 0) tint))))
                      (Stmt.Sifthenelse (Expr.Etempvar _t'15 tint)
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'10)
                            (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                 [tuint]
                                                                 tulong
                                                                 cc_default))
                            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                          (Stmt.Ssequence
                            (Stmt.Sset _t'20
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                                  (Ty.Tstruct _kprog_x86_arena noattr)) _q
                                (tptr (tvolatile tulong))))
                            (Stmt.Sbuiltin none
                              (ExtFun.EF_vstore Chunk.Mint64)
                              [(tptr (tvolatile tulong)), (tvolatile tulong)]
                              [(Expr.Eaddrof
                                 (Expr.Ederef
                                   (Expr.Ebinop Binop.Oadd
                                     (Expr.Etempvar _t'20 (tptr (tvolatile tulong)))
                                     (Expr.Ebinop Binop.Odiv
                                       (Expr.Etempvar ___x86_release_i tuint)
                                       (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                       tuint) (tptr (tvolatile tulong)))
                                   (tvolatile tulong))
                                 (tptr (tvolatile tulong))),
                               (Expr.Etempvar _t'10 tulong)])))
                        (Stmt.Ssequence
                          (Stmt.Sset ___x86_release_lane
                            (Expr.Econst_int (Integers.Int.repr 0) tint))
                          (Stmt.Sloop
                            (Stmt.Ssequence
                              s_kprog_x86_mov_imm_15
                              s_kprog_x86_mov_imm_16)
                            (Stmt.Sset ___x86_release_lane
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Etempvar ___x86_release_lane tuint)
                                (Expr.Econst_int (Integers.Int.repr 1) tint)
                                tuint))))))))
                (Stmt.Sset ___x86_release_i
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Etempvar ___x86_release_i tuint)
                    (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint))))
            (Stmt.Sloop
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sset _t'18
                    (Expr.Efield
                      (Expr.Efield
                        (Expr.Efield
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                              (Ty.Tstruct _x86_sim_register_state noattr))
                            (Positive.ofNat 18727075383868559167)
                            (Ty.Tunion __3115 noattr))
                          (Positive.ofNat 18727075383868559167)
                          (Ty.Tstruct __3116 noattr)) _rsp
                        (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
                  (Stmt.Sset ___x86_sv_sp
                    (Expr.Ecast
                      (Expr.Ecast (Expr.Etempvar _t'18 (tptr tvoid)) tlong)
                      tlong)))
                (Stmt.Ssequence
                  (Stmt.Sset ___x86_sv_i
                    (Expr.Econst_int (Integers.Int.repr 0) tint))
                  (Stmt.Sloop
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                          (Expr.Etempvar ___x86_sv_i tuint)
                                          (Expr.Ebinop Binop.Odiv
                                            (Expr.Ebinop Binop.Oadd
                                              (Expr.Ecast
                                                (Expr.Etempvar _capacity tuint)
                                                tulong)
                                              (Expr.Econst_int (Integers.Int.repr 7) tuint)
                                              tulong)
                                            (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                            tulong) tint)
                        Stmt.Sskip
                        Stmt.Sbreak)
                      (Stmt.Sloop
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                            (Expr.Ebinop Binop.Osub
                                              (Expr.Ecast
                                                (Expr.Ebinop Binop.Omul
                                                  (Expr.Ecast
                                                    (Expr.Etempvar ___x86_sv_i tuint)
                                                    tulong)
                                                  (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                                  tulong) tlong)
                                              (Expr.Ecast
                                                (Expr.Etempvar _capacity tuint)
                                                tlong) tlong)
                                            (Expr.Etempvar ___x86_sv_sp tlong)
                                            tint)
                          (Stmt.Sloop
                            s_kprog_x86_mov_imm_17
                            s_kprog_x86_mov_imm_18)
                          Stmt.Sskip)
                        Stmt.Sbreak))
                    (Stmt.Sset ___x86_sv_i
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar ___x86_sv_i tuint)
                        (Expr.Econst_int (Integers.Int.repr 1) tint) tuint)))))
              Stmt.Sbreak))
          Stmt.Sskip)))
    Stmt.Sbreak)
  Stmt.Sskip)

def f_kprog_x86_mov_imm : Function := {
  fn_return := tvoid,
  fn_callconv := cc_default,
  fn_params := [(_state, (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
                (_arena, (tptr (Ty.Tstruct _kprog_x86_arena noattr))),
                (_facts, (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr))),
                (_capacity, tuint), (_dst, tuchar), (_flags, tuchar),
                (_aux, tuint), (_imm, tulong)],
  fn_vars := [(___x86_wr_cell, (Ty.Tunion _x86_sim_gpr noattr)),
              (___kprog_x86_partial, (tvolatile (Ty.Tunion __3396 noattr))),
              (___kprog_x86_partial__1,
               (tvolatile (Ty.Tunion __3402 noattr)))],
  fn_temps := [(___x86_state,
                (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
               (___x86_l_width, tuchar), (___x86_write_old_sp, tlong),
               (___x86_wr_raw_width, tuchar), (___x86_wr_width, tuchar),
               (___x86_wr_shift, tuchar), (___x86_wr_next, tulong),
               (___x86_wr_cell_tag, tuchar), (___x86_tag_reg, tulong),
               (___x86_wr_stack_bits, tulong), (___x86_stack_delta, tulong),
               (___kprog_x86_lane, tuchar), (___kprog_x86_bits, tulong),
               (___x86_wr_stack_bits__1, tulong),
               (___x86_stack_delta__1, tulong),
               (___kprog_x86_lane__1, tushort),
               (___kprog_x86_bits__1, tulong),
               (___x86_wr_next_ptr, (tptr tvoid)),
               (___x86_wr_next_tag, tuchar), (___x86_store_reg, tulong),
               (___x86_release_old, tlong), (___x86_release_new, tlong),
               (___x86_release_i, tuint), (___x86_release_off, tlong),
               (___x86_release_lane, tuint), (___x86_sv_sp, tlong),
               (___x86_sv_i, tuint), (_t'15, tint), (_t'14, tint),
               (_t'13, tint), (_t'12, tint), (_t'11, tulong),
               (_t'10, tulong), (_t'9, tuint), (_t'8, tuint), (_t'7, tuint),
               (_t'6, (tvolatile (tptr tvoid))),
               (_t'5, (tvolatile (tptr tvoid))), (_t'4, tuint),
               (_t'3, (tptr tvoid)), (_t'2, tuchar), (_t'1, tuchar),
               (_t'38, (tptr tvoid)), (_t'37, (tptr tvoid)), (_t'36, tuchar),
               (_t'35, tulong), (_t'34, (tptr tvoid)),
               (_t'33, (tptr (tvolatile tuchar))), (_t'32, (tptr tvoid)),
               (_t'31, tulong), (_t'30, (tptr tvoid)), (_t'29, tulong),
               (_t'28, (tptr tvoid)), (_t'27, (tptr (tvolatile tuchar))),
               (_t'26, (tptr tvoid)), (_t'25, tulong), (_t'24, (tptr tvoid)),
               (_t'23, tulong), (_t'22, (tptr tvoid)), (_t'21, (tptr tvoid)),
               (_t'20, (tptr (tvolatile tulong))),
               (_t'19, (tptr (tvolatile tuchar))), (_t'18, (tptr tvoid)),
               (_t'17, (tptr tuchar)), (_t'16, (tptr (tptr tvoid)))],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_state
    (Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))))
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Scall (some _t'1)
          (Expr.Evar _x86_width_effective (Ty.Tfunction [tuchar] tuchar
                                            cc_default))
          [(Expr.Etempvar _flags tuchar)])
        (Stmt.Sset ___x86_l_width
          (Expr.Ecast (Expr.Etempvar _t'1 tuchar) tuchar)))
      (Stmt.Sloop
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sset _t'38
              (Expr.Efield
                (Expr.Efield
                  (Expr.Efield
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                        (Ty.Tstruct _x86_sim_register_state noattr))
                      (Positive.ofNat 18727075383868559167)
                      (Ty.Tunion __3115 noattr))
                    (Positive.ofNat 18727075383868559167)
                    (Ty.Tstruct __3116 noattr)) _rsp
                  (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
            (Stmt.Sset ___x86_write_old_sp
              (Expr.Ecast
                (Expr.Ecast (Expr.Etempvar _t'38 (tptr tvoid)) tlong) tlong)))
          (Stmt.Ssequence
            (Stmt.Sset ___x86_wr_raw_width
              (Expr.Ecast (Expr.Etempvar ___x86_l_width tuchar) tuchar))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Scall (some _t'2)
                  (Expr.Evar _x86_width_effective (Ty.Tfunction [tuchar]
                                                    tuchar cc_default))
                  [(Expr.Etempvar ___x86_wr_raw_width tuchar)])
                (Stmt.Sset ___x86_wr_width
                  (Expr.Ecast (Expr.Etempvar _t'2 tuchar) tuchar)))
              (Stmt.Ssequence
                (Stmt.Sset ___x86_wr_shift
                  (Expr.Ecast
                    (Expr.Ecast
                      (Expr.Ebinop Binop.Oand
                        (Expr.Ebinop Binop.Oshr (Expr.Etempvar _aux tuint)
                          (Expr.Econst_int (Integers.Int.repr 8) tint) tuint)
                        (Expr.Econst_int (Integers.Int.repr 255) tuint)
                        tuint) tuchar) tuchar))
                (Stmt.Ssequence
                  (Stmt.Sset ___x86_wr_next (Expr.Etempvar _imm tulong))
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                          (Expr.Ecast
                                            (Expr.Etempvar _dst tuchar)
                                            tulong)
                                          (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                          tint)
                        (Stmt.Ssequence
                          (Stmt.Sset _t'37
                            (Expr.Efield
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Efield
                                        (Expr.Ederef
                                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                          (Ty.Tstruct _x86_sim_register_state noattr))
                                        (Positive.ofNat 18727075383868559167)
                                        (Ty.Tunion __3115 noattr)) _gpr_cells
                                      (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                                    (Expr.Ecast (Expr.Etempvar _dst tuchar)
                                      tuchar)
                                    (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                                  (Ty.Tstruct _x86_sim_gpr_cell noattr))
                                _value (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                              (tptr tvoid)))
                          (Stmt.Sset _t'3
                            (Expr.Ecast (Expr.Etempvar _t'37 (tptr tvoid))
                              (tptr tvoid))))
                        (Stmt.Sset _t'3
                          (Expr.Ecast
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 0) tint)
                              (tptr tvoid)) (tptr tvoid))))
                      (Stmt.Sassign
                        (Expr.Efield
                          (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                          _ptr (tptr tvoid))
                        (Expr.Etempvar _t'3 (tptr tvoid))))
                    (Stmt.Ssequence
                      (Stmt.Sloop
                        (Stmt.Ssequence
                          (Stmt.Sset ___x86_tag_reg
                            (Expr.Ecast (Expr.Etempvar _dst tuchar) tulong))
                          (Stmt.Ssequence
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                                (Expr.Etempvar ___x86_tag_reg tulong)
                                                (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                                tint)
                              s_kprog_x86_mov_imm_0
                              s_kprog_x86_mov_imm_1)
                            (Stmt.Sset ___x86_wr_cell_tag
                              (Expr.Ecast (Expr.Etempvar _t'4 tuint) tuchar))))
                        Stmt.Sbreak)
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Ecast
                                                (Expr.Etempvar ___x86_wr_width tuchar)
                                                tuchar)
                                              (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                              tint)
                            (Stmt.Sset _t'9
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                tuint))
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                (Expr.Ecast
                                                  (Expr.Etempvar ___x86_wr_width tuchar)
                                                  tuchar)
                                                (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                                tint)
                              s_kprog_x86_mov_imm_2
                              s_kprog_x86_mov_imm_3))
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Etempvar _t'9 tuint)
                                              (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                              tint)
                            (Stmt.Ssequence
                              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                  (Expr.Etempvar _dst tuchar)
                                                  (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                                  tint)
                                s_kprog_x86_mov_imm_4
                                s_kprog_x86_mov_imm_5)
                              (Stmt.Sloop
                                s_kprog_x86_mov_imm_6
                                s_kprog_x86_mov_imm_7))
                            (Stmt.Ssequence
                              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                  (Expr.Ecast
                                                    (Expr.Etempvar ___x86_wr_width tuchar)
                                                    tuchar)
                                                  (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                                  tint)
                                s_kprog_x86_mov_imm_8
                                s_kprog_x86_mov_imm_9)
                              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                  (Expr.Etempvar _t'8 tuint)
                                                  (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                                  tint)
                                s_kprog_x86_mov_imm_10
                                s_kprog_x86_mov_imm_11))))
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Etempvar _dst tuchar)
                                              (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                              tint)
                            s_kprog_x86_mov_imm_12
                            Stmt.Sskip)
                          (Stmt.Ssequence
                            (Stmt.Sset ___x86_wr_next_ptr
                              (Expr.Efield
                                (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                                _ptr (tptr tvoid)))
                            (Stmt.Ssequence
                              (Stmt.Sset ___x86_wr_next_tag
                                (Expr.Ecast
                                  (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                                  tuchar))
                              (Stmt.Ssequence
                                (Stmt.Sloop
                                  s_kprog_x86_mov_imm_13
                                  s_kprog_x86_mov_imm_14)
                                s_kprog_x86_mov_imm_19))))))))))))
        Stmt.Sbreak))
    Stmt.Sbreak))
}

def s_kprog_x86_mov_reg_0 : Stmt :=
(Stmt.Sset ___x86_store_reg (Expr.Ecast (Expr.Etempvar _dst tuchar) tulong))

def s_kprog_x86_mov_reg_1 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                    (Expr.Etempvar ___x86_store_reg tulong)
                    (Expr.Econst_int (Integers.Int.repr 16) tuint) tint)
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Efield
        (Expr.Efield
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                    (Ty.Tstruct _x86_sim_register_state noattr))
                  (Positive.ofNat 18727075383868559167)
                  (Ty.Tunion __3115 noattr)) _gpr_cells
                (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
              (Expr.Ecast (Expr.Etempvar ___x86_store_reg tulong) tuchar)
              (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
            (Ty.Tstruct _x86_sim_gpr_cell noattr)) _value
          (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid))
      (Expr.Etempvar ___x86_wr_next_ptr (tptr tvoid)))
    (Stmt.Sassign
      (Expr.Efield
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                  (Ty.Tstruct _x86_sim_register_state noattr))
                (Positive.ofNat 18727075383868559167)
                (Ty.Tunion __3115 noattr)) _gpr_cells
              (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
            (Expr.Ecast (Expr.Etempvar ___x86_store_reg tulong) tuchar)
            (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
          (Ty.Tstruct _x86_sim_gpr_cell noattr)) _tag tuchar)
      (Expr.Etempvar ___x86_wr_next_tag tuchar)))
  Stmt.Sskip)

def s_kprog_x86_mov_reg_2 : Stmt :=
(Stmt.Sset _t'5
  (Expr.Ecast
    (Expr.Ebinop Binop.Oge
      (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_release_off tlong)
        (Expr.Etempvar ___x86_release_lane tuint) tlong)
      (Expr.Etempvar ___x86_release_old tlong) tint) tbool))

def s_kprog_x86_mov_reg_3 : Stmt :=
(Stmt.Sset _t'6
  (Expr.Ecast
    (Expr.Ebinop Binop.Olt
      (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_release_off tlong)
        (Expr.Etempvar ___x86_release_lane tuint) tlong)
      (Expr.Etempvar ___x86_release_new tlong) tint) tbool))

def s_kprog_x86_mov_reg_4 : Stmt :=
(Stmt.Scall (some _t'4)
  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong cc_default))
  [(Expr.Econst_int (Integers.Int.repr 6) tint)])

def s_kprog_x86_mov_reg_5 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'209
    (Expr.Efield
      (Expr.Ederef
        (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
        (Ty.Tstruct _kprog_x86_arena noattr)) _b (tptr (tvolatile tuchar))))
  (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
    [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
    [(Expr.Eaddrof
       (Expr.Ederef
         (Expr.Ebinop Binop.Oadd
           (Expr.Etempvar _t'209 (tptr (tvolatile tuchar)))
           (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_release_i tuint)
             (Expr.Etempvar ___x86_release_lane tuint) tuint)
           (tptr (tvolatile tuchar))) (tvolatile tuchar))
       (tptr (tvolatile tuchar))),
     (Expr.Ecast (Expr.Etempvar _t'4 tulong) tuchar)]))

def s_kprog_x86_mov_reg_6 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_release_old (Expr.Etempvar ___x86_write_old_sp tlong))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sset _t'211
        (Expr.Efield
          (Expr.Efield
            (Expr.Efield
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                  (Ty.Tstruct _x86_sim_register_state noattr))
                (Positive.ofNat 18727075383868559167)
                (Ty.Tunion __3115 noattr))
              (Positive.ofNat 18727075383868559167)
              (Ty.Tstruct __3116 noattr)) _rsp
            (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
      (Stmt.Sset ___x86_release_new
        (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'211 (tptr tvoid)) tlong)
          tlong)))
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Ogt
                        (Expr.Etempvar ___x86_release_new tlong)
                        (Expr.Etempvar ___x86_release_old tlong) tint)
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sset ___x86_release_i
            (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Sloop
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                  (Expr.Etempvar ___x86_release_i tuint)
                                  (Expr.Etempvar _capacity tuint) tint)
                Stmt.Sskip
                Stmt.Sbreak)
              (Stmt.Ssequence
                (Stmt.Sset ___x86_release_off
                  (Expr.Ebinop Binop.Osub
                    (Expr.Ecast (Expr.Etempvar ___x86_release_i tuint) tlong)
                    (Expr.Ecast (Expr.Etempvar _capacity tuint) tlong) tlong))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Ole
                                        (Expr.Ebinop Binop.Oadd
                                          (Expr.Etempvar ___x86_release_i tuint)
                                          (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                          tuint)
                                        (Expr.Etempvar _capacity tuint) tint)
                      (Stmt.Sset _t'7
                        (Expr.Ecast
                          (Expr.Ebinop Binop.Oge
                            (Expr.Etempvar ___x86_release_off tlong)
                            (Expr.Etempvar ___x86_release_old tlong) tint)
                          tbool))
                      (Stmt.Sset _t'7
                        (Expr.Econst_int (Integers.Int.repr 0) tint)))
                    (Stmt.Sifthenelse (Expr.Etempvar _t'7 tint)
                      (Stmt.Sset _t'8
                        (Expr.Ecast
                          (Expr.Ebinop Binop.Ole
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar ___x86_release_off tlong)
                              (Expr.Econst_int (Integers.Int.repr 8) tint)
                              tlong) (Expr.Etempvar ___x86_release_new tlong)
                            tint) tbool))
                      (Stmt.Sset _t'8
                        (Expr.Econst_int (Integers.Int.repr 0) tint))))
                  (Stmt.Sifthenelse (Expr.Etempvar _t'8 tint)
                    (Stmt.Ssequence
                      (Stmt.Scall (some _t'3)
                        (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                             [tuint] tulong
                                                             cc_default))
                        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                      (Stmt.Ssequence
                        (Stmt.Sset _t'210
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                              (Ty.Tstruct _kprog_x86_arena noattr)) _q
                            (tptr (tvolatile tulong))))
                        (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
                          [(tptr (tvolatile tulong)), (tvolatile tulong)]
                          [(Expr.Eaddrof
                             (Expr.Ederef
                               (Expr.Ebinop Binop.Oadd
                                 (Expr.Etempvar _t'210 (tptr (tvolatile tulong)))
                                 (Expr.Ebinop Binop.Odiv
                                   (Expr.Etempvar ___x86_release_i tuint)
                                   (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                   tuint) (tptr (tvolatile tulong)))
                               (tvolatile tulong)) (tptr (tvolatile tulong))),
                           (Expr.Etempvar _t'3 tulong)])))
                    (Stmt.Ssequence
                      (Stmt.Sset ___x86_release_lane
                        (Expr.Econst_int (Integers.Int.repr 0) tint))
                      (Stmt.Sloop
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                              (Expr.Etempvar ___x86_release_lane tuint)
                                              (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                              tint)
                            Stmt.Sskip
                            Stmt.Sbreak)
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                                  (Expr.Ebinop Binop.Oadd
                                                    (Expr.Etempvar ___x86_release_i tuint)
                                                    (Expr.Etempvar ___x86_release_lane tuint)
                                                    tuint)
                                                  (Expr.Etempvar _capacity tuint)
                                                  tint)
                                s_kprog_x86_mov_reg_2
                                (Stmt.Sset _t'5
                                  (Expr.Econst_int (Integers.Int.repr 0) tint)))
                              (Stmt.Sifthenelse (Expr.Etempvar _t'5 tint)
                                s_kprog_x86_mov_reg_3
                                (Stmt.Sset _t'6
                                  (Expr.Econst_int (Integers.Int.repr 0) tint))))
                            (Stmt.Sifthenelse (Expr.Etempvar _t'6 tint)
                              (Stmt.Ssequence
                                s_kprog_x86_mov_reg_4
                                s_kprog_x86_mov_reg_5)
                              Stmt.Sskip)))
                        (Stmt.Sset ___x86_release_lane
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar ___x86_release_lane tuint)
                            (Expr.Econst_int (Integers.Int.repr 1) tint)
                            tuint))))))))
            (Stmt.Sset ___x86_release_i
              (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_release_i tuint)
                (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint))))
        (Stmt.Sloop
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sset _t'208
                (Expr.Efield
                  (Expr.Efield
                    (Expr.Efield
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                          (Ty.Tstruct _x86_sim_register_state noattr))
                        (Positive.ofNat 18727075383868559167)
                        (Ty.Tunion __3115 noattr))
                      (Positive.ofNat 18727075383868559167)
                      (Ty.Tstruct __3116 noattr)) _rsp
                    (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
              (Stmt.Sset ___x86_sv_sp
                (Expr.Ecast
                  (Expr.Ecast (Expr.Etempvar _t'208 (tptr tvoid)) tlong)
                  tlong)))
            (Stmt.Ssequence
              (Stmt.Sset ___x86_sv_i
                (Expr.Econst_int (Integers.Int.repr 0) tint))
              (Stmt.Sloop
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                      (Expr.Etempvar ___x86_sv_i tuint)
                                      (Expr.Ebinop Binop.Odiv
                                        (Expr.Ebinop Binop.Oadd
                                          (Expr.Ecast
                                            (Expr.Etempvar _capacity tuint)
                                            tulong)
                                          (Expr.Econst_int (Integers.Int.repr 7) tuint)
                                          tulong)
                                        (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                        tulong) tint)
                    Stmt.Sskip
                    Stmt.Sbreak)
                  (Stmt.Sloop
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                        (Expr.Ebinop Binop.Osub
                                          (Expr.Ecast
                                            (Expr.Ebinop Binop.Omul
                                              (Expr.Ecast
                                                (Expr.Etempvar ___x86_sv_i tuint)
                                                tulong)
                                              (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                              tulong) tlong)
                                          (Expr.Ecast
                                            (Expr.Etempvar _capacity tuint)
                                            tlong) tlong)
                                        (Expr.Etempvar ___x86_sv_sp tlong)
                                        tint)
                      (Stmt.Sloop
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Sset _t'207
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                                    (Expr.Etempvar ___x86_sv_i tuint)
                                    (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                                  (Ty.Tstruct _kprog_x86_stack_fact noattr))
                                _tag (tptr tuchar)))
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Etempvar _t'207 (tptr tuchar)) tuchar)
                              (Expr.Econst_int (Integers.Int.repr 0) tuint)))
                          (Stmt.Ssequence
                            (Stmt.Sset _t'206
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                                    (Expr.Etempvar ___x86_sv_i tuint)
                                    (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                                  (Ty.Tstruct _kprog_x86_stack_fact noattr))
                                _pointer (tptr (tptr tvoid))))
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Etempvar _t'206 (tptr (tptr tvoid)))
                                (tptr tvoid))
                              (Expr.Econst_int (Integers.Int.repr 0) tint))))
                        Stmt.Sbreak)
                      Stmt.Sskip)
                    Stmt.Sbreak))
                (Stmt.Sset ___x86_sv_i
                  (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_sv_i tuint)
                    (Expr.Econst_int (Integers.Int.repr 1) tint) tuint)))))
          Stmt.Sbreak))
      Stmt.Sskip)))

def s_kprog_x86_mov_reg_7 : Stmt :=
Stmt.Sbreak

def s_kprog_x86_mov_reg_8 : Stmt :=
(Stmt.Scall (some _t'9)
  (Expr.Evar _x86_width_effective (Ty.Tfunction [tuchar] tuchar cc_default))
  [(Expr.Etempvar ___x86_rd_raw_width tuchar)])

def s_kprog_x86_mov_reg_9 : Stmt :=
(Stmt.Sset ___x86_rd_shift
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuchar))

def s_kprog_x86_mov_reg_10 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                        (Expr.Ecast (Expr.Etempvar ___x86_rd_reg tuchar)
                          tulong)
                        (Expr.Econst_int (Integers.Int.repr 16) tuint) tint)
      (Stmt.Ssequence
        (Stmt.Sset _t'205
          (Expr.Efield
            (Expr.Efield
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                        (Ty.Tstruct _x86_sim_register_state noattr))
                      (Positive.ofNat 18727075383868559167)
                      (Ty.Tunion __3115 noattr)) _gpr_cells
                    (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                  (Expr.Ecast (Expr.Etempvar ___x86_rd_reg tuchar) tuchar)
                  (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                (Ty.Tstruct _x86_sim_gpr_cell noattr)) _value
              (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
        (Stmt.Sset _t'10
          (Expr.Ecast (Expr.Etempvar _t'205 (tptr tvoid)) (tptr tvoid))))
      (Stmt.Sset _t'10
        (Expr.Ecast
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
            (tptr tvoid)) (tptr tvoid))))
    (Stmt.Sset ___x86_rd_ptr (Expr.Etempvar _t'10 (tptr tvoid))))
  (Stmt.Ssequence
    (Stmt.Sset ___x86_rd_value
      (Expr.Ecast
        (Expr.Ecast (Expr.Etempvar ___x86_rd_ptr (tptr tvoid)) tlong) tulong))
    (Stmt.Ssequence
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                          (Expr.Etempvar ___x86_rd_reg tuchar)
                          (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
        (Stmt.Ssequence
          (Stmt.Sset _t'204
            (Expr.Efield
              (Expr.Ederef
                (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                (Ty.Tstruct _x86_sim_register_state noattr))
              _native_stack_base tulong))
          (Stmt.Sset ___x86_rd_value
            (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_rd_value tulong)
              (Expr.Etempvar _t'204 tulong) tulong)))
        (Stmt.Ssequence
          (Stmt.Sloop
            (Stmt.Ssequence
              (Stmt.Sset ___x86_tag_reg
                (Expr.Ecast (Expr.Etempvar ___x86_rd_reg tuchar) tulong))
              (Stmt.Ssequence
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                    (Expr.Etempvar ___x86_tag_reg tulong)
                                    (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                    tint)
                  (Stmt.Ssequence
                    (Stmt.Sset _t'203
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                  (Ty.Tstruct _x86_sim_register_state noattr))
                                (Positive.ofNat 18727075383868559167)
                                (Ty.Tunion __3115 noattr)) _gpr_cells
                              (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                            (Expr.Ecast (Expr.Etempvar ___x86_tag_reg tulong)
                              tuchar)
                            (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                          (Ty.Tstruct _x86_sim_gpr_cell noattr)) _tag tuchar))
                    (Stmt.Sset _t'11
                      (Expr.Ecast (Expr.Etempvar _t'203 tuchar) tuint)))
                  (Stmt.Sset _t'11
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                      tuint)))
                (Stmt.Sset ___x86_rd_tag
                  (Expr.Ecast (Expr.Etempvar _t'11 tuint) tuchar))))
            Stmt.Sbreak)
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar ___x86_rd_tag tuchar)
                              (Expr.Econst_int (Integers.Int.repr 4) tuint)
                              tint)
            (Stmt.Sloop
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sset _t'202
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                        (Ty.Tstruct _kprog_x86_arena noattr)) _b
                      (tptr (tvolatile tuchar))))
                  (Stmt.Sset ___x86_stack_delta
                    (Expr.Ebinop Binop.Osub
                      (Expr.Ecast
                        (Expr.Ecast
                          (Expr.Etempvar ___x86_rd_ptr (tptr tvoid)) tlong)
                        tulong)
                      (Expr.Ecast
                        (Expr.Ecast
                          (Expr.Ecast
                            (Expr.Ecast
                              (Expr.Ecast
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Ecast
                                    (Expr.Ecast
                                      (Expr.Ebinop Binop.Oadd
                                        (Expr.Etempvar _t'202 (tptr (tvolatile tuchar)))
                                        (Expr.Econst_int (Integers.Int.repr 0) tint)
                                        (tptr (tvolatile tuchar))) tulong)
                                    tulong)
                                  (Expr.Ecast
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Ecast
                                        (Expr.Econst_int (Integers.Int.repr 0) tint)
                                        tulong)
                                      (Expr.Ecast
                                        (Expr.Etempvar _capacity tuint)
                                        tulong) tulong) tulong) tulong)
                                tulong) (tptr tuchar)) (tptr tvoid)) tlong)
                        tulong) tulong)))
                (Stmt.Ssequence
                  (Stmt.Sset _t'201
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                        (Ty.Tstruct _x86_sim_register_state noattr))
                      _native_stack_base tulong))
                  (Stmt.Sset ___x86_rd_value
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Etempvar ___x86_stack_delta tulong)
                      (Expr.Etempvar _t'201 tulong) tulong))))
              Stmt.Sbreak)
            Stmt.Sskip)))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar ___x86_rd_width tuchar)
                              (Expr.Econst_int (Integers.Int.repr 1) tuint)
                              tint)
            (Stmt.Sset _t'12
              (Expr.Ecast (Expr.Etempvar ___x86_rd_shift tuchar) tuint))
            (Stmt.Sset _t'12
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                tuint)))
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar ___x86_rd_width tuchar)
                              (Expr.Econst_int (Integers.Int.repr 1) tuint)
                              tint)
            (Stmt.Sset _t'13
              (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 255) tulong)
                tulong))
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Etempvar ___x86_rd_width tuchar)
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
                                  (Expr.Etempvar ___x86_rd_width tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                  tint)
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sset _t'13
                      (Expr.Ecast
                        (Expr.Econst_long (Integers.Int64.repr 4294967295) tulong)
                        tulong))
                    (Stmt.Sset _t'13
                      (Expr.Ecast (Expr.Etempvar _t'13 tulong) tulong)))
                  (Stmt.Sset _t'13
                    (Expr.Ecast (Expr.Etempvar _t'13 tulong) tulong)))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sset _t'13
                      (Expr.Ecast
                        (Expr.Econst_long (Integers.Int64.repr (-1)) tulong)
                        tulong))
                    (Stmt.Sset _t'13
                      (Expr.Ecast (Expr.Etempvar _t'13 tulong) tulong)))
                  (Stmt.Sset _t'13
                    (Expr.Ecast (Expr.Etempvar _t'13 tulong) tulong)))))))
        (Stmt.Sset ___x86_mov_numeric
          (Expr.Ebinop Binop.Oand
            (Expr.Ebinop Binop.Oshr (Expr.Etempvar ___x86_rd_value tulong)
              (Expr.Etempvar _t'12 tuint) tulong)
            (Expr.Etempvar _t'13 tulong) tulong))))))

def s_kprog_x86_mov_reg_11 : Stmt :=
(Stmt.Scall (some _t'14)
  (Expr.Evar _x86_width_effective (Ty.Tfunction [tuchar] tuchar cc_default))
  [(Expr.Etempvar ___x86_wr_raw_width tuchar)])

def s_kprog_x86_mov_reg_12 : Stmt :=
(Stmt.Sset ___x86_wr_shift
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuchar))

def s_kprog_x86_mov_reg_13 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                    (Expr.Etempvar ___x86_wr_shift tuchar)
                    (Expr.Econst_int (Integers.Int.repr 8) tuint) tint)
  (Stmt.Sset ___kprog_x86_bits
    (Expr.Ebinop Binop.Oor
      (Expr.Ebinop Binop.Oand (Expr.Etempvar ___kprog_x86_bits tulong)
        (Expr.Eunop Unop.Onotint
          (Expr.Econst_long (Integers.Int64.repr 65280) tulong) tulong)
        tulong)
      (Expr.Ebinop Binop.Oshl
        (Expr.Ecast (Expr.Etempvar ___kprog_x86_lane tuchar) tulong)
        (Expr.Econst_int (Integers.Int.repr 8) tint) tulong) tulong))
  (Stmt.Sset ___kprog_x86_bits
    (Expr.Ebinop Binop.Oor
      (Expr.Ebinop Binop.Oand (Expr.Etempvar ___kprog_x86_bits tulong)
        (Expr.Eunop Unop.Onotint
          (Expr.Econst_long (Integers.Int64.repr 255) tulong) tulong) tulong)
      (Expr.Etempvar ___kprog_x86_lane tuchar) tulong)))

def s_kprog_x86_mov_reg_14 : Stmt :=
(Stmt.Sassign
  (Expr.Efield (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
    _ptr (tptr tvoid))
  (Expr.Ecast (Expr.Ecast (Expr.Etempvar ___kprog_x86_bits tulong) tlong)
    (tptr tvoid)))

def s_kprog_x86_mov_reg_15 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'188
    (Expr.Efield (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
      _ptr (tptr tvoid)))
  (Stmt.Ssequence
    (Stmt.Sset _t'189
      (Expr.Efield
        (Expr.Ederef
          (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
          (Ty.Tstruct _kprog_x86_arena noattr)) _b (tptr (tvolatile tuchar))))
    (Stmt.Sset ___x86_stack_delta__2
      (Expr.Ebinop Binop.Osub
        (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'188 (tptr tvoid)) tlong)
          tulong)
        (Expr.Ecast
          (Expr.Ecast
            (Expr.Ecast
              (Expr.Ecast
                (Expr.Ecast
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Ecast
                      (Expr.Ecast
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Etempvar _t'189 (tptr (tvolatile tuchar)))
                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                          (tptr (tvolatile tuchar))) tulong) tulong)
                    (Expr.Ecast
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                          tulong)
                        (Expr.Ecast (Expr.Etempvar _capacity tuint) tulong)
                        tulong) tulong) tulong) tulong) (tptr tuchar))
              (tptr tvoid)) tlong) tulong) tulong))))

def s_kprog_x86_mov_reg_16 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'187
    (Expr.Efield
      (Expr.Ederef
        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
        (Ty.Tstruct _x86_sim_register_state noattr)) _native_stack_base
      tulong))
  (Stmt.Sset ___x86_wr_stack_bits__1
    (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_stack_delta__2 tulong)
      (Expr.Etempvar _t'187 tulong) tulong)))

def s_kprog_x86_mov_reg_17 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sbuiltin (some _t'18) (ExtFun.EF_vload Chunk.Mint64)
    [(tptr (tvolatile (tptr tvoid)))]
    [(Expr.Eaddrof
       (Expr.Efield
         (Expr.Evar ___kprog_x86_partial__1 (tvolatile (Ty.Tunion __3467 noattr)))
         _ptr (tvolatile (tptr tvoid))) (tptr (tvolatile (tptr tvoid))))])
  (Stmt.Sset ___kprog_x86_bits__1
    (Expr.Ecast
      (Expr.Ecast (Expr.Etempvar _t'18 (tvolatile (tptr tvoid))) tlong)
      tulong)))

def s_kprog_x86_mov_reg_18 : Stmt :=
(Stmt.Sassign
  (Expr.Efield (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
    _ptr (tptr tvoid))
  (Expr.Ecast
    (Expr.Ecast
      (Expr.Ebinop Binop.Oor
        (Expr.Ebinop Binop.Oand (Expr.Etempvar ___kprog_x86_bits__1 tulong)
          (Expr.Eunop Unop.Onotint
            (Expr.Econst_long (Integers.Int64.repr 65535) tulong) tulong)
          tulong) (Expr.Etempvar ___kprog_x86_lane__1 tushort) tulong) tlong)
    (tptr tvoid)))

def s_kprog_x86_mov_reg_19 : Stmt :=
(Stmt.Sset _t'19
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint) tuint))

def s_kprog_x86_mov_reg_20 : Stmt :=
(Stmt.Sset _t'19
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))

def s_kprog_x86_mov_reg_21 : Stmt :=
(Stmt.Sset ___x86_release_i__1 (Expr.Econst_int (Integers.Int.repr 0) tint))

def s_kprog_x86_mov_reg_22 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                      (Expr.Etempvar ___x86_release_i__1 tuint)
                      (Expr.Etempvar _capacity tuint) tint)
    Stmt.Sskip
    Stmt.Sbreak)
  (Stmt.Ssequence
    (Stmt.Sset ___x86_release_off__1
      (Expr.Ebinop Binop.Osub
        (Expr.Ecast (Expr.Etempvar ___x86_release_i__1 tuint) tlong)
        (Expr.Ecast (Expr.Etempvar _capacity tuint) tlong) tlong))
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Ole
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar ___x86_release_i__1 tuint)
                              (Expr.Econst_int (Integers.Int.repr 8) tuint)
                              tuint) (Expr.Etempvar _capacity tuint) tint)
          (Stmt.Sset _t'26
            (Expr.Ecast
              (Expr.Ebinop Binop.Oge
                (Expr.Etempvar ___x86_release_off__1 tlong)
                (Expr.Etempvar ___x86_release_old__1 tlong) tint) tbool))
          (Stmt.Sset _t'26 (Expr.Econst_int (Integers.Int.repr 0) tint)))
        (Stmt.Sifthenelse (Expr.Etempvar _t'26 tint)
          (Stmt.Sset _t'27
            (Expr.Ecast
              (Expr.Ebinop Binop.Ole
                (Expr.Ebinop Binop.Oadd
                  (Expr.Etempvar ___x86_release_off__1 tlong)
                  (Expr.Econst_int (Integers.Int.repr 8) tint) tlong)
                (Expr.Etempvar ___x86_release_new__1 tlong) tint) tbool))
          (Stmt.Sset _t'27 (Expr.Econst_int (Integers.Int.repr 0) tint))))
      (Stmt.Sifthenelse (Expr.Etempvar _t'27 tint)
        (Stmt.Ssequence
          (Stmt.Scall (some _t'22)
            (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                 cc_default))
            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
          (Stmt.Ssequence
            (Stmt.Sset _t'182
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                  (Ty.Tstruct _kprog_x86_arena noattr)) _q
                (tptr (tvolatile tulong))))
            (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
              [(tptr (tvolatile tulong)), (tvolatile tulong)]
              [(Expr.Eaddrof
                 (Expr.Ederef
                   (Expr.Ebinop Binop.Oadd
                     (Expr.Etempvar _t'182 (tptr (tvolatile tulong)))
                     (Expr.Ebinop Binop.Odiv
                       (Expr.Etempvar ___x86_release_i__1 tuint)
                       (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint)
                     (tptr (tvolatile tulong))) (tvolatile tulong))
                 (tptr (tvolatile tulong))), (Expr.Etempvar _t'22 tulong)])))
        (Stmt.Ssequence
          (Stmt.Sset ___x86_release_lane__1
            (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Sloop
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                  (Expr.Etempvar ___x86_release_lane__1 tuint)
                                  (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                  tint)
                Stmt.Sskip
                Stmt.Sbreak)
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                      (Expr.Ebinop Binop.Oadd
                                        (Expr.Etempvar ___x86_release_i__1 tuint)
                                        (Expr.Etempvar ___x86_release_lane__1 tuint)
                                        tuint)
                                      (Expr.Etempvar _capacity tuint) tint)
                    (Stmt.Sset _t'24
                      (Expr.Ecast
                        (Expr.Ebinop Binop.Oge
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar ___x86_release_off__1 tlong)
                            (Expr.Etempvar ___x86_release_lane__1 tuint)
                            tlong)
                          (Expr.Etempvar ___x86_release_old__1 tlong) tint)
                        tbool))
                    (Stmt.Sset _t'24
                      (Expr.Econst_int (Integers.Int.repr 0) tint)))
                  (Stmt.Sifthenelse (Expr.Etempvar _t'24 tint)
                    (Stmt.Sset _t'25
                      (Expr.Ecast
                        (Expr.Ebinop Binop.Olt
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar ___x86_release_off__1 tlong)
                            (Expr.Etempvar ___x86_release_lane__1 tuint)
                            tlong)
                          (Expr.Etempvar ___x86_release_new__1 tlong) tint)
                        tbool))
                    (Stmt.Sset _t'25
                      (Expr.Econst_int (Integers.Int.repr 0) tint))))
                (Stmt.Sifthenelse (Expr.Etempvar _t'25 tint)
                  (Stmt.Ssequence
                    (Stmt.Scall (some _t'23)
                      (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                           [tuint] tulong
                                                           cc_default))
                      [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                    (Stmt.Ssequence
                      (Stmt.Sset _t'181
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                            (Ty.Tstruct _kprog_x86_arena noattr)) _b
                          (tptr (tvolatile tuchar))))
                      (Stmt.Sbuiltin none
                        (ExtFun.EF_vstore Chunk.Mint8unsigned)
                        [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
                        [(Expr.Eaddrof
                           (Expr.Ederef
                             (Expr.Ebinop Binop.Oadd
                               (Expr.Etempvar _t'181 (tptr (tvolatile tuchar)))
                               (Expr.Ebinop Binop.Oadd
                                 (Expr.Etempvar ___x86_release_i__1 tuint)
                                 (Expr.Etempvar ___x86_release_lane__1 tuint)
                                 tuint) (tptr (tvolatile tuchar)))
                             (tvolatile tuchar)) (tptr (tvolatile tuchar))),
                         (Expr.Ecast (Expr.Etempvar _t'23 tulong) tuchar)])))
                  Stmt.Sskip)))
            (Stmt.Sset ___x86_release_lane__1
              (Expr.Ebinop Binop.Oadd
                (Expr.Etempvar ___x86_release_lane__1 tuint)
                (Expr.Econst_int (Integers.Int.repr 1) tint) tuint))))))))

def s_kprog_x86_mov_reg_23 : Stmt :=
(Stmt.Sset ___x86_release_i__1
  (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_release_i__1 tuint)
    (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint))

def s_kprog_x86_mov_reg_24 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'180
      (Expr.Efield
        (Expr.Efield
          (Expr.Efield
            (Expr.Efield
              (Expr.Ederef
                (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                (Ty.Tstruct _x86_sim_register_state noattr))
              (Positive.ofNat 18727075383868559167)
              (Ty.Tunion __3115 noattr))
            (Positive.ofNat 18727075383868559167) (Ty.Tstruct __3116 noattr))
          _rsp (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
    (Stmt.Sset ___x86_sv_sp__1
      (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'180 (tptr tvoid)) tlong)
        tlong)))
  (Stmt.Ssequence
    (Stmt.Sset ___x86_sv_i__1 (Expr.Econst_int (Integers.Int.repr 0) tint))
    (Stmt.Sloop
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                            (Expr.Etempvar ___x86_sv_i__1 tuint)
                            (Expr.Ebinop Binop.Odiv
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Ecast (Expr.Etempvar _capacity tuint)
                                  tulong)
                                (Expr.Econst_int (Integers.Int.repr 7) tuint)
                                tulong)
                              (Expr.Econst_int (Integers.Int.repr 8) tuint)
                              tulong) tint)
          Stmt.Sskip
          Stmt.Sbreak)
        (Stmt.Sloop
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                              (Expr.Ebinop Binop.Osub
                                (Expr.Ecast
                                  (Expr.Ebinop Binop.Omul
                                    (Expr.Ecast
                                      (Expr.Etempvar ___x86_sv_i__1 tuint)
                                      tulong)
                                    (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                    tulong) tlong)
                                (Expr.Ecast (Expr.Etempvar _capacity tuint)
                                  tlong) tlong)
                              (Expr.Etempvar ___x86_sv_sp__1 tlong) tint)
            (Stmt.Sloop
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sset _t'179
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                          (Expr.Etempvar ___x86_sv_i__1 tuint)
                          (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                        (Ty.Tstruct _kprog_x86_stack_fact noattr)) _tag
                      (tptr tuchar)))
                  (Stmt.Sassign
                    (Expr.Ederef (Expr.Etempvar _t'179 (tptr tuchar)) tuchar)
                    (Expr.Econst_int (Integers.Int.repr 0) tuint)))
                (Stmt.Ssequence
                  (Stmt.Sset _t'178
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                          (Expr.Etempvar ___x86_sv_i__1 tuint)
                          (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                        (Ty.Tstruct _kprog_x86_stack_fact noattr)) _pointer
                      (tptr (tptr tvoid))))
                  (Stmt.Sassign
                    (Expr.Ederef (Expr.Etempvar _t'178 (tptr (tptr tvoid)))
                      (tptr tvoid))
                    (Expr.Econst_int (Integers.Int.repr 0) tint))))
              Stmt.Sbreak)
            Stmt.Sskip)
          Stmt.Sbreak))
      (Stmt.Sset ___x86_sv_i__1
        (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_sv_i__1 tuint)
          (Expr.Econst_int (Integers.Int.repr 1) tint) tuint)))))

def s_kprog_x86_mov_reg_25 : Stmt :=
Stmt.Sbreak

def s_kprog_x86_mov_reg_26 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_wr_next (Expr.Etempvar ___x86_mov_numeric tulong))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                          (Expr.Ecast (Expr.Etempvar _dst tuchar) tulong)
                          (Expr.Econst_int (Integers.Int.repr 16) tuint)
                          tint)
        (Stmt.Ssequence
          (Stmt.Sset _t'199
            (Expr.Efield
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Efield
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                          (Ty.Tstruct _x86_sim_register_state noattr))
                        (Positive.ofNat 18727075383868559167)
                        (Ty.Tunion __3115 noattr)) _gpr_cells
                      (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                    (Expr.Ecast (Expr.Etempvar _dst tuchar) tuchar)
                    (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                  (Ty.Tstruct _x86_sim_gpr_cell noattr)) _value
                (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
          (Stmt.Sset _t'15
            (Expr.Ecast (Expr.Etempvar _t'199 (tptr tvoid)) (tptr tvoid))))
        (Stmt.Sset _t'15
          (Expr.Ecast
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
              (tptr tvoid)) (tptr tvoid))))
      (Stmt.Sassign
        (Expr.Efield
          (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr)) _ptr
          (tptr tvoid)) (Expr.Etempvar _t'15 (tptr tvoid))))
    (Stmt.Ssequence
      (Stmt.Sloop
        (Stmt.Ssequence
          (Stmt.Sset ___x86_tag_reg__1
            (Expr.Ecast (Expr.Etempvar _dst tuchar) tulong))
          (Stmt.Ssequence
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                (Expr.Etempvar ___x86_tag_reg__1 tulong)
                                (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                tint)
              (Stmt.Ssequence
                (Stmt.Sset _t'198
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                              (Ty.Tstruct _x86_sim_register_state noattr))
                            (Positive.ofNat 18727075383868559167)
                            (Ty.Tunion __3115 noattr)) _gpr_cells
                          (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                        (Expr.Ecast (Expr.Etempvar ___x86_tag_reg__1 tulong)
                          tuchar)
                        (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                      (Ty.Tstruct _x86_sim_gpr_cell noattr)) _tag tuchar))
                (Stmt.Sset _t'16
                  (Expr.Ecast (Expr.Etempvar _t'198 tuchar) tuint)))
              (Stmt.Sset _t'16
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                  tuint)))
            (Stmt.Sset ___x86_wr_cell_tag
              (Expr.Ecast (Expr.Etempvar _t'16 tuint) tuchar))))
        Stmt.Sbreak)
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Ecast
                                (Expr.Etempvar ___x86_wr_width tuchar)
                                tuchar)
                              (Expr.Econst_int (Integers.Int.repr 1) tuint)
                              tint)
            (Stmt.Sset _t'21
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                tuint))
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Ecast
                                  (Expr.Etempvar ___x86_wr_width tuchar)
                                  tuchar)
                                (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                tint)
              (Stmt.Ssequence
                (Stmt.Sset _t'21
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint)
                    tuint))
                (Stmt.Sset _t'21
                  (Expr.Ecast (Expr.Etempvar _t'21 tuint) tuint)))
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Ecast
                                    (Expr.Etempvar ___x86_wr_width tuchar)
                                    tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                  tint)
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sset _t'21
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 2) tuint) tuint))
                    (Stmt.Sset _t'21
                      (Expr.Ecast (Expr.Etempvar _t'21 tuint) tuint)))
                  (Stmt.Sset _t'21
                    (Expr.Ecast (Expr.Etempvar _t'21 tuint) tuint)))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sset _t'21
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))
                    (Stmt.Sset _t'21
                      (Expr.Ecast (Expr.Etempvar _t'21 tuint) tuint)))
                  (Stmt.Sset _t'21
                    (Expr.Ecast (Expr.Etempvar _t'21 tuint) tuint))))))
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar _t'21 tuint)
                              (Expr.Econst_int (Integers.Int.repr 0) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar _dst tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                  tint)
                (Stmt.Ssequence
                  (Stmt.Sset _t'196
                    (Expr.Efield
                      (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                      _ptr (tptr tvoid)))
                  (Stmt.Ssequence
                    (Stmt.Sset _t'197
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                          (Ty.Tstruct _x86_sim_register_state noattr))
                        _native_stack_base tulong))
                    (Stmt.Sassign
                      (Expr.Efield
                        (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                        _ptr (tptr tvoid))
                      (Expr.Ecast
                        (Expr.Ecast
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Ecast
                              (Expr.Ecast (Expr.Etempvar _t'196 (tptr tvoid))
                                tlong) tulong) (Expr.Etempvar _t'197 tulong)
                            tulong) tlong) (tptr tvoid)))))
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                                    (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                    tint)
                  (Stmt.Ssequence
                    (Stmt.Sloop
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sset _t'194
                            (Expr.Efield
                              (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                              _ptr (tptr tvoid)))
                          (Stmt.Ssequence
                            (Stmt.Sset _t'195
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                                  (Ty.Tstruct _kprog_x86_arena noattr)) _b
                                (tptr (tvolatile tuchar))))
                            (Stmt.Sset ___x86_stack_delta__1
                              (Expr.Ebinop Binop.Osub
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Etempvar _t'194 (tptr tvoid))
                                    tlong) tulong)
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Ecast
                                      (Expr.Ecast
                                        (Expr.Ecast
                                          (Expr.Ebinop Binop.Oadd
                                            (Expr.Ecast
                                              (Expr.Ecast
                                                (Expr.Ebinop Binop.Oadd
                                                  (Expr.Etempvar _t'195 (tptr (tvolatile tuchar)))
                                                  (Expr.Econst_int (Integers.Int.repr 0) tint)
                                                  (tptr (tvolatile tuchar)))
                                                tulong) tulong)
                                            (Expr.Ecast
                                              (Expr.Ebinop Binop.Oadd
                                                (Expr.Ecast
                                                  (Expr.Econst_int (Integers.Int.repr 0) tint)
                                                  tulong)
                                                (Expr.Ecast
                                                  (Expr.Etempvar _capacity tuint)
                                                  tulong) tulong) tulong)
                                            tulong) tulong) (tptr tuchar))
                                      (tptr tvoid)) tlong) tulong) tulong))))
                        (Stmt.Ssequence
                          (Stmt.Sset _t'193
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                (Ty.Tstruct _x86_sim_register_state noattr))
                              _native_stack_base tulong))
                          (Stmt.Sset ___x86_wr_stack_bits
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar ___x86_stack_delta__1 tulong)
                              (Expr.Etempvar _t'193 tulong) tulong))))
                      Stmt.Sbreak)
                    (Stmt.Sassign
                      (Expr.Efield
                        (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                        _ptr (tptr tvoid))
                      (Expr.Ecast
                        (Expr.Ecast
                          (Expr.Etempvar ___x86_wr_stack_bits tulong) tlong)
                        (tptr tvoid))))
                  Stmt.Sskip))
              (Stmt.Sloop
                (Stmt.Ssequence
                  (Stmt.Sset ___kprog_x86_lane
                    (Expr.Ecast (Expr.Etempvar ___x86_wr_next tulong) tuchar))
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                        tint)
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Etempvar ___x86_wr_shift tuchar)
                                          (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                          tint)
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                                _b (tarray tuchar 8))
                              (Expr.Econst_int (Integers.Int.repr 1) tint)
                              (tptr tuchar)) tuchar)
                          (Expr.Etempvar ___kprog_x86_lane tuchar))
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                                _b (tarray tuchar 8))
                              (Expr.Econst_int (Integers.Int.repr 0) tint)
                              (tptr tuchar)) tuchar)
                          (Expr.Etempvar ___kprog_x86_lane tuchar)))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sset _t'192
                            (Expr.Efield
                              (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                              _ptr (tptr tvoid)))
                          (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
                            [(tptr (tvolatile (tptr tvoid))),
                             (tvolatile (tptr tvoid))]
                            [(Expr.Eaddrof
                               (Expr.Efield
                                 (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3461 noattr)))
                                 _ptr (tvolatile (tptr tvoid)))
                               (tptr (tvolatile (tptr tvoid)))),
                             (Expr.Etempvar _t'192 (tptr tvoid))]))
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Etempvar ___x86_wr_shift tuchar)
                                              (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                              tint)
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3461 noattr)))
                                    _b (tvolatile (tarray tuchar 8)))
                                  (Expr.Econst_int (Integers.Int.repr 1) tint)
                                  (tptr tuchar)) tuchar)
                              (Expr.Etempvar ___kprog_x86_lane tuchar))
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3461 noattr)))
                                    _b (tvolatile (tarray tuchar 8)))
                                  (Expr.Econst_int (Integers.Int.repr 0) tint)
                                  (tptr tuchar)) tuchar)
                              (Expr.Etempvar ___kprog_x86_lane tuchar)))
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Sbuiltin (some _t'17)
                                (ExtFun.EF_vload Chunk.Mint64)
                                [(tptr (tvolatile (tptr tvoid)))]
                                [(Expr.Eaddrof
                                   (Expr.Efield
                                     (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3461 noattr)))
                                     _ptr (tvolatile (tptr tvoid)))
                                   (tptr (tvolatile (tptr tvoid))))])
                              (Stmt.Sset ___kprog_x86_bits
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Etempvar _t'17 (tvolatile (tptr tvoid)))
                                    tlong) tulong)))
                            (Stmt.Ssequence
                              s_kprog_x86_mov_reg_13
                              s_kprog_x86_mov_reg_14)))))
                    (Stmt.Sset ___x86_wr_cell_tag
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 0) tuint) tuchar))))
                Stmt.Sbreak))
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Ecast
                                    (Expr.Etempvar ___x86_wr_width tuchar)
                                    tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                  tint)
                (Stmt.Sset _t'20
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                    tuint))
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Ecast
                                      (Expr.Etempvar ___x86_wr_width tuchar)
                                      tuchar)
                                    (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                    tint)
                  (Stmt.Ssequence
                    (Stmt.Sset _t'20
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
                    (Stmt.Sset _t'20
                      (Expr.Ecast (Expr.Etempvar _t'20 tuint) tuint)))
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Ecast
                                        (Expr.Etempvar ___x86_wr_width tuchar)
                                        tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sset _t'20
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 2) tuint)
                            tuint))
                        (Stmt.Sset _t'20
                          (Expr.Ecast (Expr.Etempvar _t'20 tuint) tuint)))
                      (Stmt.Sset _t'20
                        (Expr.Ecast (Expr.Etempvar _t'20 tuint) tuint)))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sset _t'20
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 3) tuint)
                            tuint))
                        (Stmt.Sset _t'20
                          (Expr.Ecast (Expr.Etempvar _t'20 tuint) tuint)))
                      (Stmt.Sset _t'20
                        (Expr.Ecast (Expr.Etempvar _t'20 tuint) tuint))))))
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar _t'20 tuint)
                                  (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                  tint)
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar _dst tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Sset _t'190
                        (Expr.Efield
                          (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                          _ptr (tptr tvoid)))
                      (Stmt.Ssequence
                        (Stmt.Sset _t'191
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                              (Ty.Tstruct _x86_sim_register_state noattr))
                            _native_stack_base tulong))
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                            _ptr (tptr tvoid))
                          (Expr.Ecast
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Etempvar _t'190 (tptr tvoid))
                                    tlong) tulong)
                                (Expr.Etempvar _t'191 tulong) tulong) tlong)
                            (tptr tvoid)))))
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                        tint)
                      (Stmt.Ssequence
                        (Stmt.Sloop
                          (Stmt.Ssequence
                            s_kprog_x86_mov_reg_15
                            s_kprog_x86_mov_reg_16)
                          Stmt.Sbreak)
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                            _ptr (tptr tvoid))
                          (Expr.Ecast
                            (Expr.Ecast
                              (Expr.Etempvar ___x86_wr_stack_bits__1 tulong)
                              tlong) (tptr tvoid))))
                      Stmt.Sskip))
                  (Stmt.Sloop
                    (Stmt.Ssequence
                      (Stmt.Sset ___kprog_x86_lane__1
                        (Expr.Ecast (Expr.Etempvar ___x86_wr_next tulong)
                          tushort))
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                                            (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                            tint)
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                              _w tushort)
                            (Expr.Etempvar ___kprog_x86_lane__1 tushort))
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Sset _t'186
                                (Expr.Efield
                                  (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                                  _ptr (tptr tvoid)))
                              (Stmt.Sbuiltin none
                                (ExtFun.EF_vstore Chunk.Mint64)
                                [(tptr (tvolatile (tptr tvoid))),
                                 (tvolatile (tptr tvoid))]
                                [(Expr.Eaddrof
                                   (Expr.Efield
                                     (Expr.Evar ___kprog_x86_partial__1 (tvolatile (Ty.Tunion __3467 noattr)))
                                     _ptr (tvolatile (tptr tvoid)))
                                   (tptr (tvolatile (tptr tvoid)))),
                                 (Expr.Etempvar _t'186 (tptr tvoid))]))
                            (Stmt.Ssequence
                              (Stmt.Sbuiltin none
                                (ExtFun.EF_vstore Chunk.Mint16unsigned)
                                [(tptr (tvolatile tushort)),
                                 (tvolatile tushort)]
                                [(Expr.Eaddrof
                                   (Expr.Efield
                                     (Expr.Evar ___kprog_x86_partial__1 (tvolatile (Ty.Tunion __3467 noattr)))
                                     _w (tvolatile tushort))
                                   (tptr (tvolatile tushort))),
                                 (Expr.Etempvar ___kprog_x86_lane__1 tushort)])
                              (Stmt.Ssequence
                                s_kprog_x86_mov_reg_17
                                s_kprog_x86_mov_reg_18))))
                        (Stmt.Sset ___x86_wr_cell_tag
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tuint)
                            tuchar))))
                    Stmt.Sbreak))
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Ecast
                                        (Expr.Etempvar ___x86_wr_width tuchar)
                                        tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                      tint)
                    (Stmt.Sset _t'19
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 0) tuint) tuint))
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Ecast
                                          (Expr.Etempvar ___x86_wr_width tuchar)
                                          tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                        tint)
                      (Stmt.Ssequence
                        (Stmt.Sset _t'19
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 1) tuint)
                            tuint))
                        (Stmt.Sset _t'19
                          (Expr.Ecast (Expr.Etempvar _t'19 tuint) tuint)))
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Ecast
                                            (Expr.Etempvar ___x86_wr_width tuchar)
                                            tuchar)
                                          (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                          tint)
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            s_kprog_x86_mov_reg_19
                            (Stmt.Sset _t'19
                              (Expr.Ecast (Expr.Etempvar _t'19 tuint) tuint)))
                          (Stmt.Sset _t'19
                            (Expr.Ecast (Expr.Etempvar _t'19 tuint) tuint)))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            s_kprog_x86_mov_reg_20
                            (Stmt.Sset _t'19
                              (Expr.Ecast (Expr.Etempvar _t'19 tuint) tuint)))
                          (Stmt.Sset _t'19
                            (Expr.Ecast (Expr.Etempvar _t'19 tuint) tuint))))))
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar _t'19 tuint)
                                      (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Sset ___x86_wr_next
                        (Expr.Ecast
                          (Expr.Ecast (Expr.Etempvar ___x86_wr_next tulong)
                            tuint) tulong))
                      (Stmt.Sloop
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                              _ptr (tptr tvoid))
                            (Expr.Ecast
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Etempvar ___x86_wr_next tulong)
                                  tuint) tlong) (tptr tvoid)))
                          (Stmt.Sset ___x86_wr_cell_tag
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 0) tuint)
                              tuchar)))
                        Stmt.Sbreak))
                    (Stmt.Sloop
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                            _ptr (tptr tvoid))
                          (Expr.Ecast
                            (Expr.Ecast
                              (Expr.Ecast
                                (Expr.Etempvar ___x86_wr_next tulong) tulong)
                              tlong) (tptr tvoid)))
                        (Stmt.Sset ___x86_wr_cell_tag
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tuint)
                            tuchar)))
                      Stmt.Sbreak)))))))
        (Stmt.Ssequence
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar _dst tuchar)
                              (Expr.Econst_int (Integers.Int.repr 4) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Sset _t'184
                (Expr.Efield
                  (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                  _ptr (tptr tvoid)))
              (Stmt.Ssequence
                (Stmt.Sset _t'185
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                      (Ty.Tstruct _x86_sim_register_state noattr))
                    _native_stack_base tulong))
                (Stmt.Sassign
                  (Expr.Efield
                    (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                    _ptr (tptr tvoid))
                  (Expr.Ecast
                    (Expr.Ecast
                      (Expr.Ebinop Binop.Osub
                        (Expr.Ecast
                          (Expr.Ecast (Expr.Etempvar _t'184 (tptr tvoid))
                            tlong) tulong) (Expr.Etempvar _t'185 tulong)
                        tulong) tlong) (tptr tvoid)))))
            Stmt.Sskip)
          (Stmt.Ssequence
            (Stmt.Sset ___x86_wr_next_ptr__1
              (Expr.Efield
                (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                _ptr (tptr tvoid)))
            (Stmt.Ssequence
              (Stmt.Sset ___x86_wr_next_tag__1
                (Expr.Ecast (Expr.Etempvar ___x86_wr_cell_tag tuchar) tuchar))
              (Stmt.Ssequence
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Sset ___x86_store_reg__1
                      (Expr.Ecast (Expr.Etempvar _dst tuchar) tulong))
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                        (Expr.Etempvar ___x86_store_reg__1 tulong)
                                        (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                        tint)
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Efield
                                      (Expr.Ederef
                                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                        (Ty.Tstruct _x86_sim_register_state noattr))
                                      (Positive.ofNat 18727075383868559167)
                                      (Ty.Tunion __3115 noattr)) _gpr_cells
                                    (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                                  (Expr.Ecast
                                    (Expr.Etempvar ___x86_store_reg__1 tulong)
                                    tuchar)
                                  (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                                (Ty.Tstruct _x86_sim_gpr_cell noattr)) _value
                              (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                            (tptr tvoid))
                          (Expr.Etempvar ___x86_wr_next_ptr__1 (tptr tvoid)))
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Efield
                                    (Expr.Ederef
                                      (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                      (Ty.Tstruct _x86_sim_register_state noattr))
                                    (Positive.ofNat 18727075383868559167)
                                    (Ty.Tunion __3115 noattr)) _gpr_cells
                                  (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                                (Expr.Ecast
                                  (Expr.Etempvar ___x86_store_reg__1 tulong)
                                  tuchar)
                                (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                              (Ty.Tstruct _x86_sim_gpr_cell noattr)) _tag
                            tuchar)
                          (Expr.Etempvar ___x86_wr_next_tag__1 tuchar)))
                      Stmt.Sskip))
                  Stmt.Sbreak)
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Etempvar _dst tuchar)
                                    (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                    tint)
                  (Stmt.Sloop
                    (Stmt.Ssequence
                      (Stmt.Sset ___x86_release_old__1
                        (Expr.Etempvar ___x86_write_old_sp__1 tlong))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sset _t'183
                            (Expr.Efield
                              (Expr.Efield
                                (Expr.Efield
                                  (Expr.Efield
                                    (Expr.Ederef
                                      (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                      (Ty.Tstruct _x86_sim_register_state noattr))
                                    (Positive.ofNat 18727075383868559167)
                                    (Ty.Tunion __3115 noattr))
                                  (Positive.ofNat 18727075383868559167)
                                  (Ty.Tstruct __3116 noattr)) _rsp
                                (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                              (tptr tvoid)))
                          (Stmt.Sset ___x86_release_new__1
                            (Expr.Ecast
                              (Expr.Ecast (Expr.Etempvar _t'183 (tptr tvoid))
                                tlong) tlong)))
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Ogt
                                            (Expr.Etempvar ___x86_release_new__1 tlong)
                                            (Expr.Etempvar ___x86_release_old__1 tlong)
                                            tint)
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              s_kprog_x86_mov_reg_21
                              (Stmt.Sloop
                                s_kprog_x86_mov_reg_22
                                s_kprog_x86_mov_reg_23))
                            (Stmt.Sloop
                              s_kprog_x86_mov_reg_24
                              s_kprog_x86_mov_reg_25))
                          Stmt.Sskip)))
                    Stmt.Sbreak)
                  Stmt.Sskip)))))))))

def s_kprog_x86_mov_reg_27 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'176
    (Expr.Efield
      (Expr.Efield
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                  (Ty.Tstruct _x86_sim_register_state noattr))
                (Positive.ofNat 18727075383868559167)
                (Ty.Tunion __3115 noattr)) _gpr_cells
              (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
            (Expr.Ecast (Expr.Etempvar _src tuchar) tuchar)
            (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
          (Ty.Tstruct _x86_sim_gpr_cell noattr)) _value
        (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
  (Stmt.Sset _t'28
    (Expr.Ecast (Expr.Etempvar _t'176 (tptr tvoid)) (tptr tvoid))))

def s_kprog_x86_mov_reg_28 : Stmt :=
(Stmt.Sset _t'28
  (Expr.Ecast
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid))
    (tptr tvoid)))

def s_kprog_x86_mov_reg_29 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_store_reg__2
    (Expr.Ecast (Expr.Etempvar _dst tuchar) tulong))
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                      (Expr.Etempvar ___x86_store_reg__2 tulong)
                      (Expr.Econst_int (Integers.Int.repr 16) tuint) tint)
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Efield
          (Expr.Efield
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                      (Ty.Tstruct _x86_sim_register_state noattr))
                    (Positive.ofNat 18727075383868559167)
                    (Ty.Tunion __3115 noattr)) _gpr_cells
                  (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                (Expr.Ecast (Expr.Etempvar ___x86_store_reg__2 tulong)
                  tuchar) (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
              (Ty.Tstruct _x86_sim_gpr_cell noattr)) _value
            (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid))
        (Expr.Etempvar ___x86_wr_next_ptr__2 (tptr tvoid)))
      (Stmt.Sassign
        (Expr.Efield
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                    (Ty.Tstruct _x86_sim_register_state noattr))
                  (Positive.ofNat 18727075383868559167)
                  (Ty.Tunion __3115 noattr)) _gpr_cells
                (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
              (Expr.Ecast (Expr.Etempvar ___x86_store_reg__2 tulong) tuchar)
              (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
            (Ty.Tstruct _x86_sim_gpr_cell noattr)) _tag tuchar)
        (Expr.Etempvar ___x86_wr_next_tag__2 tuchar)))
    Stmt.Sskip))

def s_kprog_x86_mov_reg_30 : Stmt :=
Stmt.Sbreak

def s_kprog_x86_mov_reg_31 : Stmt :=
(Stmt.Sset _t'31
  (Expr.Ecast
    (Expr.Ebinop Binop.Oge
      (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_release_off__2 tlong)
        (Expr.Etempvar ___x86_release_lane__2 tuint) tlong)
      (Expr.Etempvar ___x86_release_old__2 tlong) tint) tbool))

def s_kprog_x86_mov_reg_32 : Stmt :=
(Stmt.Sset _t'32
  (Expr.Ecast
    (Expr.Ebinop Binop.Olt
      (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_release_off__2 tlong)
        (Expr.Etempvar ___x86_release_lane__2 tuint) tlong)
      (Expr.Etempvar ___x86_release_new__2 tlong) tint) tbool))

def s_kprog_x86_mov_reg_33 : Stmt :=
(Stmt.Scall (some _t'30)
  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong cc_default))
  [(Expr.Econst_int (Integers.Int.repr 6) tint)])

def s_kprog_x86_mov_reg_34 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'172
    (Expr.Efield
      (Expr.Ederef
        (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
        (Ty.Tstruct _kprog_x86_arena noattr)) _b (tptr (tvolatile tuchar))))
  (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
    [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
    [(Expr.Eaddrof
       (Expr.Ederef
         (Expr.Ebinop Binop.Oadd
           (Expr.Etempvar _t'172 (tptr (tvolatile tuchar)))
           (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_release_i__2 tuint)
             (Expr.Etempvar ___x86_release_lane__2 tuint) tuint)
           (tptr (tvolatile tuchar))) (tvolatile tuchar))
       (tptr (tvolatile tuchar))),
     (Expr.Ecast (Expr.Etempvar _t'30 tulong) tuchar)]))

def s_kprog_x86_mov_reg_35 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_release_old__2
    (Expr.Etempvar ___x86_write_old_sp__2 tlong))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sset _t'174
        (Expr.Efield
          (Expr.Efield
            (Expr.Efield
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                  (Ty.Tstruct _x86_sim_register_state noattr))
                (Positive.ofNat 18727075383868559167)
                (Ty.Tunion __3115 noattr))
              (Positive.ofNat 18727075383868559167)
              (Ty.Tstruct __3116 noattr)) _rsp
            (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
      (Stmt.Sset ___x86_release_new__2
        (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'174 (tptr tvoid)) tlong)
          tlong)))
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Ogt
                        (Expr.Etempvar ___x86_release_new__2 tlong)
                        (Expr.Etempvar ___x86_release_old__2 tlong) tint)
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sset ___x86_release_i__2
            (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Sloop
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                  (Expr.Etempvar ___x86_release_i__2 tuint)
                                  (Expr.Etempvar _capacity tuint) tint)
                Stmt.Sskip
                Stmt.Sbreak)
              (Stmt.Ssequence
                (Stmt.Sset ___x86_release_off__2
                  (Expr.Ebinop Binop.Osub
                    (Expr.Ecast (Expr.Etempvar ___x86_release_i__2 tuint)
                      tlong)
                    (Expr.Ecast (Expr.Etempvar _capacity tuint) tlong) tlong))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Ole
                                        (Expr.Ebinop Binop.Oadd
                                          (Expr.Etempvar ___x86_release_i__2 tuint)
                                          (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                          tuint)
                                        (Expr.Etempvar _capacity tuint) tint)
                      (Stmt.Sset _t'33
                        (Expr.Ecast
                          (Expr.Ebinop Binop.Oge
                            (Expr.Etempvar ___x86_release_off__2 tlong)
                            (Expr.Etempvar ___x86_release_old__2 tlong) tint)
                          tbool))
                      (Stmt.Sset _t'33
                        (Expr.Econst_int (Integers.Int.repr 0) tint)))
                    (Stmt.Sifthenelse (Expr.Etempvar _t'33 tint)
                      (Stmt.Sset _t'34
                        (Expr.Ecast
                          (Expr.Ebinop Binop.Ole
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar ___x86_release_off__2 tlong)
                              (Expr.Econst_int (Integers.Int.repr 8) tint)
                              tlong)
                            (Expr.Etempvar ___x86_release_new__2 tlong) tint)
                          tbool))
                      (Stmt.Sset _t'34
                        (Expr.Econst_int (Integers.Int.repr 0) tint))))
                  (Stmt.Sifthenelse (Expr.Etempvar _t'34 tint)
                    (Stmt.Ssequence
                      (Stmt.Scall (some _t'29)
                        (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                             [tuint] tulong
                                                             cc_default))
                        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                      (Stmt.Ssequence
                        (Stmt.Sset _t'173
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                              (Ty.Tstruct _kprog_x86_arena noattr)) _q
                            (tptr (tvolatile tulong))))
                        (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
                          [(tptr (tvolatile tulong)), (tvolatile tulong)]
                          [(Expr.Eaddrof
                             (Expr.Ederef
                               (Expr.Ebinop Binop.Oadd
                                 (Expr.Etempvar _t'173 (tptr (tvolatile tulong)))
                                 (Expr.Ebinop Binop.Odiv
                                   (Expr.Etempvar ___x86_release_i__2 tuint)
                                   (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                   tuint) (tptr (tvolatile tulong)))
                               (tvolatile tulong)) (tptr (tvolatile tulong))),
                           (Expr.Etempvar _t'29 tulong)])))
                    (Stmt.Ssequence
                      (Stmt.Sset ___x86_release_lane__2
                        (Expr.Econst_int (Integers.Int.repr 0) tint))
                      (Stmt.Sloop
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                              (Expr.Etempvar ___x86_release_lane__2 tuint)
                                              (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                              tint)
                            Stmt.Sskip
                            Stmt.Sbreak)
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                                  (Expr.Ebinop Binop.Oadd
                                                    (Expr.Etempvar ___x86_release_i__2 tuint)
                                                    (Expr.Etempvar ___x86_release_lane__2 tuint)
                                                    tuint)
                                                  (Expr.Etempvar _capacity tuint)
                                                  tint)
                                s_kprog_x86_mov_reg_31
                                (Stmt.Sset _t'31
                                  (Expr.Econst_int (Integers.Int.repr 0) tint)))
                              (Stmt.Sifthenelse (Expr.Etempvar _t'31 tint)
                                s_kprog_x86_mov_reg_32
                                (Stmt.Sset _t'32
                                  (Expr.Econst_int (Integers.Int.repr 0) tint))))
                            (Stmt.Sifthenelse (Expr.Etempvar _t'32 tint)
                              (Stmt.Ssequence
                                s_kprog_x86_mov_reg_33
                                s_kprog_x86_mov_reg_34)
                              Stmt.Sskip)))
                        (Stmt.Sset ___x86_release_lane__2
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar ___x86_release_lane__2 tuint)
                            (Expr.Econst_int (Integers.Int.repr 1) tint)
                            tuint))))))))
            (Stmt.Sset ___x86_release_i__2
              (Expr.Ebinop Binop.Oadd
                (Expr.Etempvar ___x86_release_i__2 tuint)
                (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint))))
        (Stmt.Sloop
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sset _t'171
                (Expr.Efield
                  (Expr.Efield
                    (Expr.Efield
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                          (Ty.Tstruct _x86_sim_register_state noattr))
                        (Positive.ofNat 18727075383868559167)
                        (Ty.Tunion __3115 noattr))
                      (Positive.ofNat 18727075383868559167)
                      (Ty.Tstruct __3116 noattr)) _rsp
                    (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
              (Stmt.Sset ___x86_sv_sp__2
                (Expr.Ecast
                  (Expr.Ecast (Expr.Etempvar _t'171 (tptr tvoid)) tlong)
                  tlong)))
            (Stmt.Ssequence
              (Stmt.Sset ___x86_sv_i__2
                (Expr.Econst_int (Integers.Int.repr 0) tint))
              (Stmt.Sloop
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                      (Expr.Etempvar ___x86_sv_i__2 tuint)
                                      (Expr.Ebinop Binop.Odiv
                                        (Expr.Ebinop Binop.Oadd
                                          (Expr.Ecast
                                            (Expr.Etempvar _capacity tuint)
                                            tulong)
                                          (Expr.Econst_int (Integers.Int.repr 7) tuint)
                                          tulong)
                                        (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                        tulong) tint)
                    Stmt.Sskip
                    Stmt.Sbreak)
                  (Stmt.Sloop
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                        (Expr.Ebinop Binop.Osub
                                          (Expr.Ecast
                                            (Expr.Ebinop Binop.Omul
                                              (Expr.Ecast
                                                (Expr.Etempvar ___x86_sv_i__2 tuint)
                                                tulong)
                                              (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                              tulong) tlong)
                                          (Expr.Ecast
                                            (Expr.Etempvar _capacity tuint)
                                            tlong) tlong)
                                        (Expr.Etempvar ___x86_sv_sp__2 tlong)
                                        tint)
                      (Stmt.Sloop
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Sset _t'170
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                                    (Expr.Etempvar ___x86_sv_i__2 tuint)
                                    (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                                  (Ty.Tstruct _kprog_x86_stack_fact noattr))
                                _tag (tptr tuchar)))
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Etempvar _t'170 (tptr tuchar)) tuchar)
                              (Expr.Econst_int (Integers.Int.repr 0) tuint)))
                          (Stmt.Ssequence
                            (Stmt.Sset _t'169
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                                    (Expr.Etempvar ___x86_sv_i__2 tuint)
                                    (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                                  (Ty.Tstruct _kprog_x86_stack_fact noattr))
                                _pointer (tptr (tptr tvoid))))
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Etempvar _t'169 (tptr (tptr tvoid)))
                                (tptr tvoid))
                              (Expr.Econst_int (Integers.Int.repr 0) tint))))
                        Stmt.Sbreak)
                      Stmt.Sskip)
                    Stmt.Sbreak))
                (Stmt.Sset ___x86_sv_i__2
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Etempvar ___x86_sv_i__2 tuint)
                    (Expr.Econst_int (Integers.Int.repr 1) tint) tuint)))))
          Stmt.Sbreak))
      Stmt.Sskip)))

def s_kprog_x86_mov_reg_36 : Stmt :=
Stmt.Sbreak

def s_kprog_x86_mov_reg_37 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'167
    (Expr.Efield
      (Expr.Efield
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                  (Ty.Tstruct _x86_sim_register_state noattr))
                (Positive.ofNat 18727075383868559167)
                (Ty.Tunion __3115 noattr)) _gpr_cells
              (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
            (Expr.Ecast (Expr.Etempvar _src tuchar) tuchar)
            (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
          (Ty.Tstruct _x86_sim_gpr_cell noattr)) _value
        (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
  (Stmt.Sset _t'38
    (Expr.Ecast (Expr.Etempvar _t'167 (tptr tvoid)) (tptr tvoid))))

def s_kprog_x86_mov_reg_38 : Stmt :=
(Stmt.Sset _t'38
  (Expr.Ecast
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid))
    (tptr tvoid)))

def s_kprog_x86_mov_reg_39 : Stmt :=
(Stmt.Sset ___x86_wr_next_tag__3
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuchar))

def s_kprog_x86_mov_reg_40 : Stmt :=
(Stmt.Sset _t'43
  (Expr.Ecast
    (Expr.Ebinop Binop.Oge (Expr.Etempvar ___x86_release_off__3 tlong)
      (Expr.Etempvar ___x86_release_old__3 tlong) tint) tbool))

def s_kprog_x86_mov_reg_41 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                      (Expr.Etempvar ___x86_release_lane__3 tuint)
                      (Expr.Econst_int (Integers.Int.repr 8) tuint) tint)
    Stmt.Sskip
    Stmt.Sbreak)
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar ___x86_release_i__3 tuint)
                            (Expr.Etempvar ___x86_release_lane__3 tuint)
                            tuint) (Expr.Etempvar _capacity tuint) tint)
        (Stmt.Sset _t'41
          (Expr.Ecast
            (Expr.Ebinop Binop.Oge
              (Expr.Ebinop Binop.Oadd
                (Expr.Etempvar ___x86_release_off__3 tlong)
                (Expr.Etempvar ___x86_release_lane__3 tuint) tlong)
              (Expr.Etempvar ___x86_release_old__3 tlong) tint) tbool))
        (Stmt.Sset _t'41 (Expr.Econst_int (Integers.Int.repr 0) tint)))
      (Stmt.Sifthenelse (Expr.Etempvar _t'41 tint)
        (Stmt.Sset _t'42
          (Expr.Ecast
            (Expr.Ebinop Binop.Olt
              (Expr.Ebinop Binop.Oadd
                (Expr.Etempvar ___x86_release_off__3 tlong)
                (Expr.Etempvar ___x86_release_lane__3 tuint) tlong)
              (Expr.Etempvar ___x86_release_new__3 tlong) tint) tbool))
        (Stmt.Sset _t'42 (Expr.Econst_int (Integers.Int.repr 0) tint))))
    (Stmt.Sifthenelse (Expr.Etempvar _t'42 tint)
      (Stmt.Ssequence
        (Stmt.Scall (some _t'40)
          (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                               cc_default))
          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
        (Stmt.Ssequence
          (Stmt.Sset _t'162
            (Expr.Efield
              (Expr.Ederef
                (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                (Ty.Tstruct _kprog_x86_arena noattr)) _b
              (tptr (tvolatile tuchar))))
          (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
            [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
            [(Expr.Eaddrof
               (Expr.Ederef
                 (Expr.Ebinop Binop.Oadd
                   (Expr.Etempvar _t'162 (tptr (tvolatile tuchar)))
                   (Expr.Ebinop Binop.Oadd
                     (Expr.Etempvar ___x86_release_i__3 tuint)
                     (Expr.Etempvar ___x86_release_lane__3 tuint) tuint)
                   (tptr (tvolatile tuchar))) (tvolatile tuchar))
               (tptr (tvolatile tuchar))),
             (Expr.Ecast (Expr.Etempvar _t'40 tulong) tuchar)])))
      Stmt.Sskip)))

def s_kprog_x86_mov_reg_42 : Stmt :=
(Stmt.Sset ___x86_release_lane__3
  (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_release_lane__3 tuint)
    (Expr.Econst_int (Integers.Int.repr 1) tint) tuint))

def s_kprog_x86_mov_reg_43 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'160
      (Expr.Efield
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
            (Expr.Etempvar ___x86_sv_i__3 tuint)
            (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
          (Ty.Tstruct _kprog_x86_stack_fact noattr)) _tag (tptr tuchar)))
    (Stmt.Sassign (Expr.Ederef (Expr.Etempvar _t'160 (tptr tuchar)) tuchar)
      (Expr.Econst_int (Integers.Int.repr 0) tuint)))
  (Stmt.Ssequence
    (Stmt.Sset _t'159
      (Expr.Efield
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
            (Expr.Etempvar ___x86_sv_i__3 tuint)
            (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
          (Ty.Tstruct _kprog_x86_stack_fact noattr)) _pointer
        (tptr (tptr tvoid))))
    (Stmt.Sassign
      (Expr.Ederef (Expr.Etempvar _t'159 (tptr (tptr tvoid))) (tptr tvoid))
      (Expr.Econst_int (Integers.Int.repr 0) tint))))

def s_kprog_x86_mov_reg_44 : Stmt :=
Stmt.Sbreak

def s_kprog_x86_mov_reg_45 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sset ___x86_store_reg__3
        (Expr.Ecast (Expr.Etempvar _dst tuchar) tulong))
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                          (Expr.Etempvar ___x86_store_reg__3 tulong)
                          (Expr.Econst_int (Integers.Int.repr 16) tuint)
                          tint)
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Efield
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Efield
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                          (Ty.Tstruct _x86_sim_register_state noattr))
                        (Positive.ofNat 18727075383868559167)
                        (Ty.Tunion __3115 noattr)) _gpr_cells
                      (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                    (Expr.Ecast (Expr.Etempvar ___x86_store_reg__3 tulong)
                      tuchar) (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                  (Ty.Tstruct _x86_sim_gpr_cell noattr)) _value
                (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid))
            (Expr.Etempvar ___x86_wr_next_ptr__3 (tptr tvoid)))
          (Stmt.Sassign
            (Expr.Efield
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                        (Ty.Tstruct _x86_sim_register_state noattr))
                      (Positive.ofNat 18727075383868559167)
                      (Ty.Tunion __3115 noattr)) _gpr_cells
                    (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                  (Expr.Ecast (Expr.Etempvar ___x86_store_reg__3 tulong)
                    tuchar) (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                (Ty.Tstruct _x86_sim_gpr_cell noattr)) _tag tuchar)
            (Expr.Etempvar ___x86_wr_next_tag__3 tuchar)))
        Stmt.Sskip))
    Stmt.Sbreak)
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _dst tuchar)
                      (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
    (Stmt.Sloop
      (Stmt.Ssequence
        (Stmt.Sset ___x86_release_old__3
          (Expr.Etempvar ___x86_write_old_sp__3 tlong))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sset _t'164
              (Expr.Efield
                (Expr.Efield
                  (Expr.Efield
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                        (Ty.Tstruct _x86_sim_register_state noattr))
                      (Positive.ofNat 18727075383868559167)
                      (Ty.Tunion __3115 noattr))
                    (Positive.ofNat 18727075383868559167)
                    (Ty.Tstruct __3116 noattr)) _rsp
                  (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
            (Stmt.Sset ___x86_release_new__3
              (Expr.Ecast
                (Expr.Ecast (Expr.Etempvar _t'164 (tptr tvoid)) tlong) tlong)))
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Ogt
                              (Expr.Etempvar ___x86_release_new__3 tlong)
                              (Expr.Etempvar ___x86_release_old__3 tlong)
                              tint)
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset ___x86_release_i__3
                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                        (Expr.Etempvar ___x86_release_i__3 tuint)
                                        (Expr.Etempvar _capacity tuint) tint)
                      Stmt.Sskip
                      Stmt.Sbreak)
                    (Stmt.Ssequence
                      (Stmt.Sset ___x86_release_off__3
                        (Expr.Ebinop Binop.Osub
                          (Expr.Ecast
                            (Expr.Etempvar ___x86_release_i__3 tuint) tlong)
                          (Expr.Ecast (Expr.Etempvar _capacity tuint) tlong)
                          tlong))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Ole
                                              (Expr.Ebinop Binop.Oadd
                                                (Expr.Etempvar ___x86_release_i__3 tuint)
                                                (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                                tuint)
                                              (Expr.Etempvar _capacity tuint)
                                              tint)
                            s_kprog_x86_mov_reg_40
                            (Stmt.Sset _t'43
                              (Expr.Econst_int (Integers.Int.repr 0) tint)))
                          (Stmt.Sifthenelse (Expr.Etempvar _t'43 tint)
                            (Stmt.Sset _t'44
                              (Expr.Ecast
                                (Expr.Ebinop Binop.Ole
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Etempvar ___x86_release_off__3 tlong)
                                    (Expr.Econst_int (Integers.Int.repr 8) tint)
                                    tlong)
                                  (Expr.Etempvar ___x86_release_new__3 tlong)
                                  tint) tbool))
                            (Stmt.Sset _t'44
                              (Expr.Econst_int (Integers.Int.repr 0) tint))))
                        (Stmt.Sifthenelse (Expr.Etempvar _t'44 tint)
                          (Stmt.Ssequence
                            (Stmt.Scall (some _t'39)
                              (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                   [tuint]
                                                                   tulong
                                                                   cc_default))
                              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                            (Stmt.Ssequence
                              (Stmt.Sset _t'163
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                                    (Ty.Tstruct _kprog_x86_arena noattr)) _q
                                  (tptr (tvolatile tulong))))
                              (Stmt.Sbuiltin none
                                (ExtFun.EF_vstore Chunk.Mint64)
                                [(tptr (tvolatile tulong)),
                                 (tvolatile tulong)]
                                [(Expr.Eaddrof
                                   (Expr.Ederef
                                     (Expr.Ebinop Binop.Oadd
                                       (Expr.Etempvar _t'163 (tptr (tvolatile tulong)))
                                       (Expr.Ebinop Binop.Odiv
                                         (Expr.Etempvar ___x86_release_i__3 tuint)
                                         (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                         tuint) (tptr (tvolatile tulong)))
                                     (tvolatile tulong))
                                   (tptr (tvolatile tulong))),
                                 (Expr.Etempvar _t'39 tulong)])))
                          (Stmt.Ssequence
                            (Stmt.Sset ___x86_release_lane__3
                              (Expr.Econst_int (Integers.Int.repr 0) tint))
                            (Stmt.Sloop
                              s_kprog_x86_mov_reg_41
                              s_kprog_x86_mov_reg_42))))))
                  (Stmt.Sset ___x86_release_i__3
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Etempvar ___x86_release_i__3 tuint)
                      (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint))))
              (Stmt.Sloop
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sset _t'161
                      (Expr.Efield
                        (Expr.Efield
                          (Expr.Efield
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                (Ty.Tstruct _x86_sim_register_state noattr))
                              (Positive.ofNat 18727075383868559167)
                              (Ty.Tunion __3115 noattr))
                            (Positive.ofNat 18727075383868559167)
                            (Ty.Tstruct __3116 noattr)) _rsp
                          (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
                    (Stmt.Sset ___x86_sv_sp__3
                      (Expr.Ecast
                        (Expr.Ecast (Expr.Etempvar _t'161 (tptr tvoid))
                          tlong) tlong)))
                  (Stmt.Ssequence
                    (Stmt.Sset ___x86_sv_i__3
                      (Expr.Econst_int (Integers.Int.repr 0) tint))
                    (Stmt.Sloop
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                            (Expr.Etempvar ___x86_sv_i__3 tuint)
                                            (Expr.Ebinop Binop.Odiv
                                              (Expr.Ebinop Binop.Oadd
                                                (Expr.Ecast
                                                  (Expr.Etempvar _capacity tuint)
                                                  tulong)
                                                (Expr.Econst_int (Integers.Int.repr 7) tuint)
                                                tulong)
                                              (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                              tulong) tint)
                          Stmt.Sskip
                          Stmt.Sbreak)
                        (Stmt.Sloop
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                              (Expr.Ebinop Binop.Osub
                                                (Expr.Ecast
                                                  (Expr.Ebinop Binop.Omul
                                                    (Expr.Ecast
                                                      (Expr.Etempvar ___x86_sv_i__3 tuint)
                                                      tulong)
                                                    (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                                    tulong) tlong)
                                                (Expr.Ecast
                                                  (Expr.Etempvar _capacity tuint)
                                                  tlong) tlong)
                                              (Expr.Etempvar ___x86_sv_sp__3 tlong)
                                              tint)
                            (Stmt.Sloop
                              s_kprog_x86_mov_reg_43
                              s_kprog_x86_mov_reg_44)
                            Stmt.Sskip)
                          Stmt.Sbreak))
                      (Stmt.Sset ___x86_sv_i__3
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Etempvar ___x86_sv_i__3 tuint)
                          (Expr.Econst_int (Integers.Int.repr 1) tint) tuint)))))
                Stmt.Sbreak))
            Stmt.Sskip)))
      Stmt.Sbreak)
    Stmt.Sskip))

def s_kprog_x86_mov_reg_46 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'71
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuint))
  (Stmt.Sset _t'71 (Expr.Ecast (Expr.Etempvar _t'71 tuint) tuint)))

def s_kprog_x86_mov_reg_47 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'71
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
  (Stmt.Sset _t'71 (Expr.Ecast (Expr.Etempvar _t'71 tuint) tuint)))

def s_kprog_x86_mov_reg_48 : Stmt :=
(Stmt.Sset ___x86_rd_reg__1 (Expr.Ecast (Expr.Etempvar _src tuchar) tuchar))

def s_kprog_x86_mov_reg_49 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_rd_raw_width__1
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tuint) tuchar))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Scall (some _t'45)
        (Expr.Evar _x86_width_effective (Ty.Tfunction [tuchar] tuchar
                                          cc_default))
        [(Expr.Etempvar ___x86_rd_raw_width__1 tuchar)])
      (Stmt.Sset ___x86_rd_width__1
        (Expr.Ecast (Expr.Etempvar _t'45 tuchar) tuchar)))
    (Stmt.Ssequence
      (Stmt.Sset ___x86_rd_shift__1
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuchar))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                              (Expr.Ecast
                                (Expr.Etempvar ___x86_rd_reg__1 tuchar)
                                tulong)
                              (Expr.Econst_int (Integers.Int.repr 16) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Sset _t'158
                (Expr.Efield
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                              (Ty.Tstruct _x86_sim_register_state noattr))
                            (Positive.ofNat 18727075383868559167)
                            (Ty.Tunion __3115 noattr)) _gpr_cells
                          (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                        (Expr.Ecast (Expr.Etempvar ___x86_rd_reg__1 tuchar)
                          tuchar)
                        (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                      (Ty.Tstruct _x86_sim_gpr_cell noattr)) _value
                    (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
              (Stmt.Sset _t'46
                (Expr.Ecast (Expr.Etempvar _t'158 (tptr tvoid)) (tptr tvoid))))
            (Stmt.Sset _t'46
              (Expr.Ecast
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                  (tptr tvoid)) (tptr tvoid))))
          (Stmt.Sset ___x86_rd_ptr__1 (Expr.Etempvar _t'46 (tptr tvoid))))
        (Stmt.Ssequence
          (Stmt.Sset ___x86_rd_value__1
            (Expr.Ecast
              (Expr.Ecast (Expr.Etempvar ___x86_rd_ptr__1 (tptr tvoid))
                tlong) tulong))
          (Stmt.Ssequence
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Etempvar ___x86_rd_reg__1 tuchar)
                                (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                tint)
              (Stmt.Ssequence
                (Stmt.Sset _t'157
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                      (Ty.Tstruct _x86_sim_register_state noattr))
                    _native_stack_base tulong))
                (Stmt.Sset ___x86_rd_value__1
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Etempvar ___x86_rd_value__1 tulong)
                    (Expr.Etempvar _t'157 tulong) tulong)))
              (Stmt.Ssequence
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Sset ___x86_tag_reg__3
                      (Expr.Ecast (Expr.Etempvar ___x86_rd_reg__1 tuchar)
                        tulong))
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                          (Expr.Etempvar ___x86_tag_reg__3 tulong)
                                          (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                          tint)
                        (Stmt.Ssequence
                          (Stmt.Sset _t'156
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Efield
                                      (Expr.Ederef
                                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                        (Ty.Tstruct _x86_sim_register_state noattr))
                                      (Positive.ofNat 18727075383868559167)
                                      (Ty.Tunion __3115 noattr)) _gpr_cells
                                    (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                                  (Expr.Ecast
                                    (Expr.Etempvar ___x86_tag_reg__3 tulong)
                                    tuchar)
                                  (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                                (Ty.Tstruct _x86_sim_gpr_cell noattr)) _tag
                              tuchar))
                          (Stmt.Sset _t'47
                            (Expr.Ecast (Expr.Etempvar _t'156 tuchar) tuint)))
                        (Stmt.Sset _t'47
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tuint)
                            tuint)))
                      (Stmt.Sset ___x86_rd_tag__1
                        (Expr.Ecast (Expr.Etempvar _t'47 tuint) tuchar))))
                  Stmt.Sbreak)
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Etempvar ___x86_rd_tag__1 tuchar)
                                    (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                    tint)
                  (Stmt.Sloop
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sset _t'155
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                              (Ty.Tstruct _kprog_x86_arena noattr)) _b
                            (tptr (tvolatile tuchar))))
                        (Stmt.Sset ___x86_stack_delta__3
                          (Expr.Ebinop Binop.Osub
                            (Expr.Ecast
                              (Expr.Ecast
                                (Expr.Etempvar ___x86_rd_ptr__1 (tptr tvoid))
                                tlong) tulong)
                            (Expr.Ecast
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Ecast
                                      (Expr.Ebinop Binop.Oadd
                                        (Expr.Ecast
                                          (Expr.Ecast
                                            (Expr.Ebinop Binop.Oadd
                                              (Expr.Etempvar _t'155 (tptr (tvolatile tuchar)))
                                              (Expr.Econst_int (Integers.Int.repr 0) tint)
                                              (tptr (tvolatile tuchar)))
                                            tulong) tulong)
                                        (Expr.Ecast
                                          (Expr.Ebinop Binop.Oadd
                                            (Expr.Ecast
                                              (Expr.Econst_int (Integers.Int.repr 0) tint)
                                              tulong)
                                            (Expr.Ecast
                                              (Expr.Etempvar _capacity tuint)
                                              tulong) tulong) tulong) tulong)
                                      tulong) (tptr tuchar)) (tptr tvoid))
                                tlong) tulong) tulong)))
                      (Stmt.Ssequence
                        (Stmt.Sset _t'154
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                              (Ty.Tstruct _x86_sim_register_state noattr))
                            _native_stack_base tulong))
                        (Stmt.Sset ___x86_rd_value__1
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar ___x86_stack_delta__3 tulong)
                            (Expr.Etempvar _t'154 tulong) tulong))))
                    Stmt.Sbreak)
                  Stmt.Sskip)))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Etempvar ___x86_rd_width__1 tuchar)
                                    (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                    tint)
                  (Stmt.Sset _t'48
                    (Expr.Ecast (Expr.Etempvar ___x86_rd_shift__1 tuchar)
                      tuint))
                  (Stmt.Sset _t'48
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                      tuint)))
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Etempvar ___x86_rd_width__1 tuchar)
                                    (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                    tint)
                  (Stmt.Sset _t'49
                    (Expr.Ecast
                      (Expr.Econst_long (Integers.Int64.repr 255) tulong)
                      tulong))
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar ___x86_rd_width__1 tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Sset _t'49
                        (Expr.Ecast
                          (Expr.Econst_long (Integers.Int64.repr 65535) tulong)
                          tulong))
                      (Stmt.Sset _t'49
                        (Expr.Ecast (Expr.Etempvar _t'49 tulong) tulong)))
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Etempvar ___x86_rd_width__1 tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                        tint)
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sset _t'49
                            (Expr.Ecast
                              (Expr.Econst_long (Integers.Int64.repr 4294967295) tulong)
                              tulong))
                          (Stmt.Sset _t'49
                            (Expr.Ecast (Expr.Etempvar _t'49 tulong) tulong)))
                        (Stmt.Sset _t'49
                          (Expr.Ecast (Expr.Etempvar _t'49 tulong) tulong)))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sset _t'49
                            (Expr.Ecast
                              (Expr.Econst_long (Integers.Int64.repr (-1)) tulong)
                              tulong))
                          (Stmt.Sset _t'49
                            (Expr.Ecast (Expr.Etempvar _t'49 tulong) tulong)))
                        (Stmt.Sset _t'49
                          (Expr.Ecast (Expr.Etempvar _t'49 tulong) tulong)))))))
              (Stmt.Sset ___x86_mov_numeric__1
                (Expr.Ebinop Binop.Oand
                  (Expr.Ebinop Binop.Oshr
                    (Expr.Etempvar ___x86_rd_value__1 tulong)
                    (Expr.Etempvar _t'48 tuint) tulong)
                  (Expr.Etempvar _t'49 tulong) tulong)))))))))

def s_kprog_x86_mov_reg_50 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'153
    (Expr.Efield
      (Expr.Efield
        (Expr.Efield
          (Expr.Efield
            (Expr.Ederef
              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
              (Ty.Tstruct _x86_sim_register_state noattr))
            (Positive.ofNat 18727075383868559167) (Ty.Tunion __3115 noattr))
          (Positive.ofNat 18727075383868559167) (Ty.Tstruct __3116 noattr))
        _rsp (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
  (Stmt.Sset ___x86_write_old_sp__4
    (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'153 (tptr tvoid)) tlong) tlong)))

def s_kprog_x86_mov_reg_51 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'147
    (Expr.Efield
      (Expr.Evar ___x86_wr_cell__1 (Ty.Tunion _x86_sim_gpr noattr)) _ptr
      (tptr tvoid)))
  (Stmt.Ssequence
    (Stmt.Sset _t'148
      (Expr.Efield
        (Expr.Ederef
          (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
          (Ty.Tstruct _kprog_x86_arena noattr)) _b (tptr (tvolatile tuchar))))
    (Stmt.Sset ___x86_stack_delta__4
      (Expr.Ebinop Binop.Osub
        (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'147 (tptr tvoid)) tlong)
          tulong)
        (Expr.Ecast
          (Expr.Ecast
            (Expr.Ecast
              (Expr.Ecast
                (Expr.Ecast
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Ecast
                      (Expr.Ecast
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Etempvar _t'148 (tptr (tvolatile tuchar)))
                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                          (tptr (tvolatile tuchar))) tulong) tulong)
                    (Expr.Ecast
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                          tulong)
                        (Expr.Ecast (Expr.Etempvar _capacity tuint) tulong)
                        tulong) tulong) tulong) tulong) (tptr tuchar))
              (tptr tvoid)) tlong) tulong) tulong))))

def s_kprog_x86_mov_reg_52 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'146
    (Expr.Efield
      (Expr.Ederef
        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
        (Ty.Tstruct _x86_sim_register_state noattr)) _native_stack_base
      tulong))
  (Stmt.Sset ___x86_wr_stack_bits__2
    (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_stack_delta__4 tulong)
      (Expr.Etempvar _t'146 tulong) tulong)))

def s_kprog_x86_mov_reg_53 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield
        (Expr.Evar ___x86_wr_cell__1 (Ty.Tunion _x86_sim_gpr noattr)) _b
        (tarray tuchar 8)) (Expr.Econst_int (Integers.Int.repr 1) tint)
      (tptr tuchar)) tuchar) (Expr.Etempvar ___kprog_x86_lane__2 tuchar))

def s_kprog_x86_mov_reg_54 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield
        (Expr.Evar ___x86_wr_cell__1 (Ty.Tunion _x86_sim_gpr noattr)) _b
        (tarray tuchar 8)) (Expr.Econst_int (Integers.Int.repr 0) tint)
      (tptr tuchar)) tuchar) (Expr.Etempvar ___kprog_x86_lane__2 tuchar))

def s_kprog_x86_mov_reg_55 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'145
    (Expr.Efield
      (Expr.Evar ___x86_wr_cell__1 (Ty.Tunion _x86_sim_gpr noattr)) _ptr
      (tptr tvoid)))
  (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
    [(tptr (tvolatile (tptr tvoid))), (tvolatile (tptr tvoid))]
    [(Expr.Eaddrof
       (Expr.Efield
         (Expr.Evar ___kprog_x86_partial__2 (tvolatile (Ty.Tunion __3527 noattr)))
         _ptr (tvolatile (tptr tvoid))) (tptr (tvolatile (tptr tvoid)))),
     (Expr.Etempvar _t'145 (tptr tvoid))]))

def s_kprog_x86_mov_reg_56 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                    (Expr.Etempvar ___x86_wr_shift__1 tuchar)
                    (Expr.Econst_int (Integers.Int.repr 8) tuint) tint)
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Efield
          (Expr.Evar ___kprog_x86_partial__2 (tvolatile (Ty.Tunion __3527 noattr)))
          _b (tvolatile (tarray tuchar 8)))
        (Expr.Econst_int (Integers.Int.repr 1) tint) (tptr tuchar)) tuchar)
    (Expr.Etempvar ___kprog_x86_lane__2 tuchar))
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Efield
          (Expr.Evar ___kprog_x86_partial__2 (tvolatile (Ty.Tunion __3527 noattr)))
          _b (tvolatile (tarray tuchar 8)))
        (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tuchar)) tuchar)
    (Expr.Etempvar ___kprog_x86_lane__2 tuchar)))

def s_kprog_x86_mov_reg_57 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sbuiltin (some _t'53) (ExtFun.EF_vload Chunk.Mint64)
      [(tptr (tvolatile (tptr tvoid)))]
      [(Expr.Eaddrof
         (Expr.Efield
           (Expr.Evar ___kprog_x86_partial__2 (tvolatile (Ty.Tunion __3527 noattr)))
           _ptr (tvolatile (tptr tvoid))) (tptr (tvolatile (tptr tvoid))))])
    (Stmt.Sset ___kprog_x86_bits__2
      (Expr.Ecast
        (Expr.Ecast (Expr.Etempvar _t'53 (tvolatile (tptr tvoid))) tlong)
        tulong)))
  (Stmt.Ssequence
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                        (Expr.Etempvar ___x86_wr_shift__1 tuchar)
                        (Expr.Econst_int (Integers.Int.repr 8) tuint) tint)
      (Stmt.Sset ___kprog_x86_bits__2
        (Expr.Ebinop Binop.Oor
          (Expr.Ebinop Binop.Oand (Expr.Etempvar ___kprog_x86_bits__2 tulong)
            (Expr.Eunop Unop.Onotint
              (Expr.Econst_long (Integers.Int64.repr 65280) tulong) tulong)
            tulong)
          (Expr.Ebinop Binop.Oshl
            (Expr.Ecast (Expr.Etempvar ___kprog_x86_lane__2 tuchar) tulong)
            (Expr.Econst_int (Integers.Int.repr 8) tint) tulong) tulong))
      (Stmt.Sset ___kprog_x86_bits__2
        (Expr.Ebinop Binop.Oor
          (Expr.Ebinop Binop.Oand (Expr.Etempvar ___kprog_x86_bits__2 tulong)
            (Expr.Eunop Unop.Onotint
              (Expr.Econst_long (Integers.Int64.repr 255) tulong) tulong)
            tulong) (Expr.Etempvar ___kprog_x86_lane__2 tuchar) tulong)))
    (Stmt.Sassign
      (Expr.Efield
        (Expr.Evar ___x86_wr_cell__1 (Ty.Tunion _x86_sim_gpr noattr)) _ptr
        (tptr tvoid))
      (Expr.Ecast
        (Expr.Ecast (Expr.Etempvar ___kprog_x86_bits__2 tulong) tlong)
        (tptr tvoid)))))

def s_kprog_x86_mov_reg_58 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'56
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint) tuint))
  (Stmt.Sset _t'56 (Expr.Ecast (Expr.Etempvar _t'56 tuint) tuint)))

def s_kprog_x86_mov_reg_59 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'56
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))
  (Stmt.Sset _t'56 (Expr.Ecast (Expr.Etempvar _t'56 tuint) tuint)))

def s_kprog_x86_mov_reg_60 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'141
      (Expr.Efield
        (Expr.Evar ___x86_wr_cell__1 (Ty.Tunion _x86_sim_gpr noattr)) _ptr
        (tptr tvoid)))
    (Stmt.Ssequence
      (Stmt.Sset _t'142
        (Expr.Efield
          (Expr.Ederef
            (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
            (Ty.Tstruct _kprog_x86_arena noattr)) _b
          (tptr (tvolatile tuchar))))
      (Stmt.Sset ___x86_stack_delta__5
        (Expr.Ebinop Binop.Osub
          (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'141 (tptr tvoid)) tlong)
            tulong)
          (Expr.Ecast
            (Expr.Ecast
              (Expr.Ecast
                (Expr.Ecast
                  (Expr.Ecast
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Ecast
                        (Expr.Ecast
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar _t'142 (tptr (tvolatile tuchar)))
                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                            (tptr (tvolatile tuchar))) tulong) tulong)
                      (Expr.Ecast
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                            tulong)
                          (Expr.Ecast (Expr.Etempvar _capacity tuint) tulong)
                          tulong) tulong) tulong) tulong) (tptr tuchar))
                (tptr tvoid)) tlong) tulong) tulong))))
  (Stmt.Ssequence
    (Stmt.Sset _t'140
      (Expr.Efield
        (Expr.Ederef
          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
          (Ty.Tstruct _x86_sim_register_state noattr)) _native_stack_base
        tulong))
    (Stmt.Sset ___x86_wr_stack_bits__3
      (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_stack_delta__5 tulong)
        (Expr.Etempvar _t'140 tulong) tulong))))

def s_kprog_x86_mov_reg_61 : Stmt :=
Stmt.Sbreak

def s_kprog_x86_mov_reg_62 : Stmt :=
(Stmt.Sassign
  (Expr.Efield (Expr.Evar ___x86_wr_cell__1 (Ty.Tunion _x86_sim_gpr noattr))
    _ptr (tptr tvoid))
  (Expr.Ecast
    (Expr.Ecast (Expr.Etempvar ___x86_wr_stack_bits__3 tulong) tlong)
    (tptr tvoid)))

def s_kprog_x86_mov_reg_63 : Stmt :=
(Stmt.Sassign
  (Expr.Efield (Expr.Evar ___x86_wr_cell__1 (Ty.Tunion _x86_sim_gpr noattr))
    _w tushort) (Expr.Etempvar ___kprog_x86_lane__3 tushort))

def s_kprog_x86_mov_reg_64 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'139
      (Expr.Efield
        (Expr.Evar ___x86_wr_cell__1 (Ty.Tunion _x86_sim_gpr noattr)) _ptr
        (tptr tvoid)))
    (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
      [(tptr (tvolatile (tptr tvoid))), (tvolatile (tptr tvoid))]
      [(Expr.Eaddrof
         (Expr.Efield
           (Expr.Evar ___kprog_x86_partial__3 (tvolatile (Ty.Tunion __3533 noattr)))
           _ptr (tvolatile (tptr tvoid))) (tptr (tvolatile (tptr tvoid)))),
       (Expr.Etempvar _t'139 (tptr tvoid))]))
  (Stmt.Ssequence
    (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint16unsigned)
      [(tptr (tvolatile tushort)), (tvolatile tushort)]
      [(Expr.Eaddrof
         (Expr.Efield
           (Expr.Evar ___kprog_x86_partial__3 (tvolatile (Ty.Tunion __3533 noattr)))
           _w (tvolatile tushort)) (tptr (tvolatile tushort))),
       (Expr.Etempvar ___kprog_x86_lane__3 tushort)])
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sbuiltin (some _t'54) (ExtFun.EF_vload Chunk.Mint64)
          [(tptr (tvolatile (tptr tvoid)))]
          [(Expr.Eaddrof
             (Expr.Efield
               (Expr.Evar ___kprog_x86_partial__3 (tvolatile (Ty.Tunion __3533 noattr)))
               _ptr (tvolatile (tptr tvoid)))
             (tptr (tvolatile (tptr tvoid))))])
        (Stmt.Sset ___kprog_x86_bits__3
          (Expr.Ecast
            (Expr.Ecast (Expr.Etempvar _t'54 (tvolatile (tptr tvoid))) tlong)
            tulong)))
      (Stmt.Sassign
        (Expr.Efield
          (Expr.Evar ___x86_wr_cell__1 (Ty.Tunion _x86_sim_gpr noattr)) _ptr
          (tptr tvoid))
        (Expr.Ecast
          (Expr.Ecast
            (Expr.Ebinop Binop.Oor
              (Expr.Ebinop Binop.Oand
                (Expr.Etempvar ___kprog_x86_bits__3 tulong)
                (Expr.Eunop Unop.Onotint
                  (Expr.Econst_long (Integers.Int64.repr 65535) tulong)
                  tulong) tulong)
              (Expr.Etempvar ___kprog_x86_lane__3 tushort) tulong) tlong)
          (tptr tvoid))))))

def s_kprog_x86_mov_reg_65 : Stmt :=
(Stmt.Sset _t'55
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))

def s_kprog_x86_mov_reg_66 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'55
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint) tuint))
    (Stmt.Sset _t'55 (Expr.Ecast (Expr.Etempvar _t'55 tuint) tuint)))
  (Stmt.Sset _t'55 (Expr.Ecast (Expr.Etempvar _t'55 tuint) tuint)))

def s_kprog_x86_mov_reg_67 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'55
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))
    (Stmt.Sset _t'55 (Expr.Ecast (Expr.Etempvar _t'55 tuint) tuint)))
  (Stmt.Sset _t'55 (Expr.Ecast (Expr.Etempvar _t'55 tuint) tuint)))

def s_kprog_x86_mov_reg_68 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'136
    (Expr.Efield
      (Expr.Efield
        (Expr.Efield
          (Expr.Efield
            (Expr.Ederef
              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
              (Ty.Tstruct _x86_sim_register_state noattr))
            (Positive.ofNat 18727075383868559167) (Ty.Tunion __3115 noattr))
          (Positive.ofNat 18727075383868559167) (Ty.Tstruct __3116 noattr))
        _rsp (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
  (Stmt.Sset ___x86_release_new__4
    (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'136 (tptr tvoid)) tlong) tlong)))

def s_kprog_x86_mov_reg_69 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset ___x86_release_i__4
      (Expr.Econst_int (Integers.Int.repr 0) tint))
    (Stmt.Sloop
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                            (Expr.Etempvar ___x86_release_i__4 tuint)
                            (Expr.Etempvar _capacity tuint) tint)
          Stmt.Sskip
          Stmt.Sbreak)
        (Stmt.Ssequence
          (Stmt.Sset ___x86_release_off__4
            (Expr.Ebinop Binop.Osub
              (Expr.Ecast (Expr.Etempvar ___x86_release_i__4 tuint) tlong)
              (Expr.Ecast (Expr.Etempvar _capacity tuint) tlong) tlong))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Ole
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Etempvar ___x86_release_i__4 tuint)
                                    (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                    tuint) (Expr.Etempvar _capacity tuint)
                                  tint)
                (Stmt.Sset _t'62
                  (Expr.Ecast
                    (Expr.Ebinop Binop.Oge
                      (Expr.Etempvar ___x86_release_off__4 tlong)
                      (Expr.Etempvar ___x86_release_old__4 tlong) tint)
                    tbool))
                (Stmt.Sset _t'62
                  (Expr.Econst_int (Integers.Int.repr 0) tint)))
              (Stmt.Sifthenelse (Expr.Etempvar _t'62 tint)
                (Stmt.Sset _t'63
                  (Expr.Ecast
                    (Expr.Ebinop Binop.Ole
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar ___x86_release_off__4 tlong)
                        (Expr.Econst_int (Integers.Int.repr 8) tint) tlong)
                      (Expr.Etempvar ___x86_release_new__4 tlong) tint)
                    tbool))
                (Stmt.Sset _t'63
                  (Expr.Econst_int (Integers.Int.repr 0) tint))))
            (Stmt.Sifthenelse (Expr.Etempvar _t'63 tint)
              (Stmt.Ssequence
                (Stmt.Scall (some _t'58)
                  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                       tulong cc_default))
                  [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                (Stmt.Ssequence
                  (Stmt.Sset _t'135
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                        (Ty.Tstruct _kprog_x86_arena noattr)) _q
                      (tptr (tvolatile tulong))))
                  (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
                    [(tptr (tvolatile tulong)), (tvolatile tulong)]
                    [(Expr.Eaddrof
                       (Expr.Ederef
                         (Expr.Ebinop Binop.Oadd
                           (Expr.Etempvar _t'135 (tptr (tvolatile tulong)))
                           (Expr.Ebinop Binop.Odiv
                             (Expr.Etempvar ___x86_release_i__4 tuint)
                             (Expr.Econst_int (Integers.Int.repr 8) tuint)
                             tuint) (tptr (tvolatile tulong)))
                         (tvolatile tulong)) (tptr (tvolatile tulong))),
                     (Expr.Etempvar _t'58 tulong)])))
              (Stmt.Ssequence
                (Stmt.Sset ___x86_release_lane__4
                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                        (Expr.Etempvar ___x86_release_lane__4 tuint)
                                        (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                        tint)
                      Stmt.Sskip
                      Stmt.Sbreak)
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                            (Expr.Ebinop Binop.Oadd
                                              (Expr.Etempvar ___x86_release_i__4 tuint)
                                              (Expr.Etempvar ___x86_release_lane__4 tuint)
                                              tuint)
                                            (Expr.Etempvar _capacity tuint)
                                            tint)
                          (Stmt.Sset _t'60
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Oge
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Etempvar ___x86_release_off__4 tlong)
                                  (Expr.Etempvar ___x86_release_lane__4 tuint)
                                  tlong)
                                (Expr.Etempvar ___x86_release_old__4 tlong)
                                tint) tbool))
                          (Stmt.Sset _t'60
                            (Expr.Econst_int (Integers.Int.repr 0) tint)))
                        (Stmt.Sifthenelse (Expr.Etempvar _t'60 tint)
                          (Stmt.Sset _t'61
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Olt
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Etempvar ___x86_release_off__4 tlong)
                                  (Expr.Etempvar ___x86_release_lane__4 tuint)
                                  tlong)
                                (Expr.Etempvar ___x86_release_new__4 tlong)
                                tint) tbool))
                          (Stmt.Sset _t'61
                            (Expr.Econst_int (Integers.Int.repr 0) tint))))
                      (Stmt.Sifthenelse (Expr.Etempvar _t'61 tint)
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'59)
                            (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                 [tuint]
                                                                 tulong
                                                                 cc_default))
                            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                          (Stmt.Ssequence
                            (Stmt.Sset _t'134
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                                  (Ty.Tstruct _kprog_x86_arena noattr)) _b
                                (tptr (tvolatile tuchar))))
                            (Stmt.Sbuiltin none
                              (ExtFun.EF_vstore Chunk.Mint8unsigned)
                              [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
                              [(Expr.Eaddrof
                                 (Expr.Ederef
                                   (Expr.Ebinop Binop.Oadd
                                     (Expr.Etempvar _t'134 (tptr (tvolatile tuchar)))
                                     (Expr.Ebinop Binop.Oadd
                                       (Expr.Etempvar ___x86_release_i__4 tuint)
                                       (Expr.Etempvar ___x86_release_lane__4 tuint)
                                       tuint) (tptr (tvolatile tuchar)))
                                   (tvolatile tuchar))
                                 (tptr (tvolatile tuchar))),
                               (Expr.Ecast (Expr.Etempvar _t'59 tulong)
                                 tuchar)])))
                        Stmt.Sskip)))
                  (Stmt.Sset ___x86_release_lane__4
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Etempvar ___x86_release_lane__4 tuint)
                      (Expr.Econst_int (Integers.Int.repr 1) tint) tuint))))))))
      (Stmt.Sset ___x86_release_i__4
        (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_release_i__4 tuint)
          (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint))))
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sset _t'133
          (Expr.Efield
            (Expr.Efield
              (Expr.Efield
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                    (Ty.Tstruct _x86_sim_register_state noattr))
                  (Positive.ofNat 18727075383868559167)
                  (Ty.Tunion __3115 noattr))
                (Positive.ofNat 18727075383868559167)
                (Ty.Tstruct __3116 noattr)) _rsp
              (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
        (Stmt.Sset ___x86_sv_sp__4
          (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'133 (tptr tvoid)) tlong)
            tlong)))
      (Stmt.Ssequence
        (Stmt.Sset ___x86_sv_i__4
          (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Sloop
          (Stmt.Ssequence
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                (Expr.Etempvar ___x86_sv_i__4 tuint)
                                (Expr.Ebinop Binop.Odiv
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Ecast
                                      (Expr.Etempvar _capacity tuint) tulong)
                                    (Expr.Econst_int (Integers.Int.repr 7) tuint)
                                    tulong)
                                  (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                  tulong) tint)
              Stmt.Sskip
              Stmt.Sbreak)
            (Stmt.Sloop
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                  (Expr.Ebinop Binop.Osub
                                    (Expr.Ecast
                                      (Expr.Ebinop Binop.Omul
                                        (Expr.Ecast
                                          (Expr.Etempvar ___x86_sv_i__4 tuint)
                                          tulong)
                                        (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                        tulong) tlong)
                                    (Expr.Ecast
                                      (Expr.Etempvar _capacity tuint) tlong)
                                    tlong)
                                  (Expr.Etempvar ___x86_sv_sp__4 tlong) tint)
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sset _t'132
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                              (Expr.Etempvar ___x86_sv_i__4 tuint)
                              (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                            (Ty.Tstruct _kprog_x86_stack_fact noattr)) _tag
                          (tptr tuchar)))
                      (Stmt.Sassign
                        (Expr.Ederef (Expr.Etempvar _t'132 (tptr tuchar))
                          tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tuint)))
                    (Stmt.Ssequence
                      (Stmt.Sset _t'131
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                              (Expr.Etempvar ___x86_sv_i__4 tuint)
                              (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                            (Ty.Tstruct _kprog_x86_stack_fact noattr))
                          _pointer (tptr (tptr tvoid))))
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Etempvar _t'131 (tptr (tptr tvoid)))
                          (tptr tvoid))
                        (Expr.Econst_int (Integers.Int.repr 0) tint))))
                  Stmt.Sbreak)
                Stmt.Sskip)
              Stmt.Sbreak))
          (Stmt.Sset ___x86_sv_i__4
            (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_sv_i__4 tuint)
              (Expr.Econst_int (Integers.Int.repr 1) tint) tuint)))))
    Stmt.Sbreak))

def s_kprog_x86_mov_reg_70 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_wr_raw_width__1
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tuint) tuchar))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Scall (some _t'50)
        (Expr.Evar _x86_width_effective (Ty.Tfunction [tuchar] tuchar
                                          cc_default))
        [(Expr.Etempvar ___x86_wr_raw_width__1 tuchar)])
      (Stmt.Sset ___x86_wr_width__1
        (Expr.Ecast (Expr.Etempvar _t'50 tuchar) tuchar)))
    (Stmt.Ssequence
      (Stmt.Sset ___x86_wr_shift__1
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuchar))
      (Stmt.Ssequence
        (Stmt.Sset ___x86_wr_next__1
          (Expr.Etempvar ___x86_mov_numeric__1 tulong))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                (Expr.Ecast (Expr.Etempvar _dst tuchar)
                                  tulong)
                                (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                tint)
              (Stmt.Ssequence
                (Stmt.Sset _t'152
                  (Expr.Efield
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Efield
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                (Ty.Tstruct _x86_sim_register_state noattr))
                              (Positive.ofNat 18727075383868559167)
                              (Ty.Tunion __3115 noattr)) _gpr_cells
                            (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                          (Expr.Ecast (Expr.Etempvar _dst tuchar) tuchar)
                          (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                        (Ty.Tstruct _x86_sim_gpr_cell noattr)) _value
                      (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
                (Stmt.Sset _t'51
                  (Expr.Ecast (Expr.Etempvar _t'152 (tptr tvoid))
                    (tptr tvoid))))
              (Stmt.Sset _t'51
                (Expr.Ecast
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                    (tptr tvoid)) (tptr tvoid))))
            (Stmt.Sassign
              (Expr.Efield
                (Expr.Evar ___x86_wr_cell__1 (Ty.Tunion _x86_sim_gpr noattr))
                _ptr (tptr tvoid)) (Expr.Etempvar _t'51 (tptr tvoid))))
          (Stmt.Ssequence
            (Stmt.Sloop
              (Stmt.Ssequence
                (Stmt.Sset ___x86_tag_reg__4
                  (Expr.Ecast (Expr.Etempvar _dst tuchar) tulong))
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                      (Expr.Etempvar ___x86_tag_reg__4 tulong)
                                      (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Sset _t'151
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                    (Ty.Tstruct _x86_sim_register_state noattr))
                                  (Positive.ofNat 18727075383868559167)
                                  (Ty.Tunion __3115 noattr)) _gpr_cells
                                (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                              (Expr.Ecast
                                (Expr.Etempvar ___x86_tag_reg__4 tulong)
                                tuchar)
                              (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                            (Ty.Tstruct _x86_sim_gpr_cell noattr)) _tag
                          tuchar))
                      (Stmt.Sset _t'52
                        (Expr.Ecast (Expr.Etempvar _t'151 tuchar) tuint)))
                    (Stmt.Sset _t'52
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 0) tuint) tuint)))
                  (Stmt.Sset ___x86_wr_cell_tag__1
                    (Expr.Ecast (Expr.Etempvar _t'52 tuint) tuchar))))
              Stmt.Sbreak)
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Ecast
                                      (Expr.Etempvar ___x86_wr_width__1 tuchar)
                                      tuchar)
                                    (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                    tint)
                  (Stmt.Sset _t'57
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                      tuint))
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Ecast
                                        (Expr.Etempvar ___x86_wr_width__1 tuchar)
                                        tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Sset _t'57
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 1) tuint)
                          tuint))
                      (Stmt.Sset _t'57
                        (Expr.Ecast (Expr.Etempvar _t'57 tuint) tuint)))
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Ecast
                                          (Expr.Etempvar ___x86_wr_width__1 tuchar)
                                          tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                        tint)
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sset _t'57
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 2) tuint)
                              tuint))
                          (Stmt.Sset _t'57
                            (Expr.Ecast (Expr.Etempvar _t'57 tuint) tuint)))
                        (Stmt.Sset _t'57
                          (Expr.Ecast (Expr.Etempvar _t'57 tuint) tuint)))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sset _t'57
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 3) tuint)
                              tuint))
                          (Stmt.Sset _t'57
                            (Expr.Ecast (Expr.Etempvar _t'57 tuint) tuint)))
                        (Stmt.Sset _t'57
                          (Expr.Ecast (Expr.Etempvar _t'57 tuint) tuint))))))
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Etempvar _t'57 tuint)
                                    (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                    tint)
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Etempvar _dst tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                        tint)
                      (Stmt.Ssequence
                        (Stmt.Sset _t'149
                          (Expr.Efield
                            (Expr.Evar ___x86_wr_cell__1 (Ty.Tunion _x86_sim_gpr noattr))
                            _ptr (tptr tvoid)))
                        (Stmt.Ssequence
                          (Stmt.Sset _t'150
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                (Ty.Tstruct _x86_sim_register_state noattr))
                              _native_stack_base tulong))
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Evar ___x86_wr_cell__1 (Ty.Tunion _x86_sim_gpr noattr))
                              _ptr (tptr tvoid))
                            (Expr.Ecast
                              (Expr.Ecast
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Ecast
                                    (Expr.Ecast
                                      (Expr.Etempvar _t'149 (tptr tvoid))
                                      tlong) tulong)
                                  (Expr.Etempvar _t'150 tulong) tulong)
                                tlong) (tptr tvoid)))))
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Etempvar ___x86_wr_cell_tag__1 tuchar)
                                          (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                          tint)
                        (Stmt.Ssequence
                          (Stmt.Sloop
                            (Stmt.Ssequence
                              s_kprog_x86_mov_reg_51
                              s_kprog_x86_mov_reg_52)
                            Stmt.Sbreak)
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Evar ___x86_wr_cell__1 (Ty.Tunion _x86_sim_gpr noattr))
                              _ptr (tptr tvoid))
                            (Expr.Ecast
                              (Expr.Ecast
                                (Expr.Etempvar ___x86_wr_stack_bits__2 tulong)
                                tlong) (tptr tvoid))))
                        Stmt.Sskip))
                    (Stmt.Sloop
                      (Stmt.Ssequence
                        (Stmt.Sset ___kprog_x86_lane__2
                          (Expr.Ecast
                            (Expr.Etempvar ___x86_wr_next__1 tulong) tuchar))
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Etempvar ___x86_wr_cell_tag__1 tuchar)
                                              (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                              tint)
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                (Expr.Etempvar ___x86_wr_shift__1 tuchar)
                                                (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                                tint)
                              s_kprog_x86_mov_reg_53
                              s_kprog_x86_mov_reg_54)
                            (Stmt.Ssequence
                              s_kprog_x86_mov_reg_55
                              (Stmt.Ssequence
                                s_kprog_x86_mov_reg_56
                                s_kprog_x86_mov_reg_57)))
                          (Stmt.Sset ___x86_wr_cell_tag__1
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 0) tuint)
                              tuchar))))
                      Stmt.Sbreak))
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Ecast
                                          (Expr.Etempvar ___x86_wr_width__1 tuchar)
                                          tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                        tint)
                      (Stmt.Sset _t'56
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 0) tuint)
                          tuint))
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Ecast
                                            (Expr.Etempvar ___x86_wr_width__1 tuchar)
                                            tuchar)
                                          (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                          tint)
                        (Stmt.Ssequence
                          (Stmt.Sset _t'56
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 1) tuint)
                              tuint))
                          (Stmt.Sset _t'56
                            (Expr.Ecast (Expr.Etempvar _t'56 tuint) tuint)))
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Ecast
                                              (Expr.Etempvar ___x86_wr_width__1 tuchar)
                                              tuchar)
                                            (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                            tint)
                          (Stmt.Ssequence
                            s_kprog_x86_mov_reg_58
                            (Stmt.Sset _t'56
                              (Expr.Ecast (Expr.Etempvar _t'56 tuint) tuint)))
                          (Stmt.Ssequence
                            s_kprog_x86_mov_reg_59
                            (Stmt.Sset _t'56
                              (Expr.Ecast (Expr.Etempvar _t'56 tuint) tuint))))))
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Etempvar _t'56 tuint)
                                        (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                        tint)
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Etempvar _dst tuchar)
                                            (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                            tint)
                          (Stmt.Ssequence
                            (Stmt.Sset _t'143
                              (Expr.Efield
                                (Expr.Evar ___x86_wr_cell__1 (Ty.Tunion _x86_sim_gpr noattr))
                                _ptr (tptr tvoid)))
                            (Stmt.Ssequence
                              (Stmt.Sset _t'144
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                    (Ty.Tstruct _x86_sim_register_state noattr))
                                  _native_stack_base tulong))
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Evar ___x86_wr_cell__1 (Ty.Tunion _x86_sim_gpr noattr))
                                  _ptr (tptr tvoid))
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Ecast
                                        (Expr.Ecast
                                          (Expr.Etempvar _t'143 (tptr tvoid))
                                          tlong) tulong)
                                      (Expr.Etempvar _t'144 tulong) tulong)
                                    tlong) (tptr tvoid)))))
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Etempvar ___x86_wr_cell_tag__1 tuchar)
                                              (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                              tint)
                            (Stmt.Ssequence
                              (Stmt.Sloop
                                s_kprog_x86_mov_reg_60
                                s_kprog_x86_mov_reg_61)
                              s_kprog_x86_mov_reg_62)
                            Stmt.Sskip))
                        (Stmt.Sloop
                          (Stmt.Ssequence
                            (Stmt.Sset ___kprog_x86_lane__3
                              (Expr.Ecast
                                (Expr.Etempvar ___x86_wr_next__1 tulong)
                                tushort))
                            (Stmt.Ssequence
                              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                  (Expr.Etempvar ___x86_wr_cell_tag__1 tuchar)
                                                  (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                                  tint)
                                s_kprog_x86_mov_reg_63
                                s_kprog_x86_mov_reg_64)
                              (Stmt.Sset ___x86_wr_cell_tag__1
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                  tuchar))))
                          Stmt.Sbreak))
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Ecast
                                              (Expr.Etempvar ___x86_wr_width__1 tuchar)
                                              tuchar)
                                            (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                            tint)
                          (Stmt.Sset _t'55
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 0) tuint)
                              tuint))
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Ecast
                                                (Expr.Etempvar ___x86_wr_width__1 tuchar)
                                                tuchar)
                                              (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                              tint)
                            (Stmt.Ssequence
                              s_kprog_x86_mov_reg_65
                              (Stmt.Sset _t'55
                                (Expr.Ecast (Expr.Etempvar _t'55 tuint)
                                  tuint)))
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                (Expr.Ecast
                                                  (Expr.Etempvar ___x86_wr_width__1 tuchar)
                                                  tuchar)
                                                (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                                tint)
                              s_kprog_x86_mov_reg_66
                              s_kprog_x86_mov_reg_67)))
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Etempvar _t'55 tuint)
                                            (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                            tint)
                          (Stmt.Ssequence
                            (Stmt.Sset ___x86_wr_next__1
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Etempvar ___x86_wr_next__1 tulong)
                                  tuint) tulong))
                            (Stmt.Sloop
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Efield
                                    (Expr.Evar ___x86_wr_cell__1 (Ty.Tunion _x86_sim_gpr noattr))
                                    _ptr (tptr tvoid))
                                  (Expr.Ecast
                                    (Expr.Ecast
                                      (Expr.Ecast
                                        (Expr.Etempvar ___x86_wr_next__1 tulong)
                                        tuint) tlong) (tptr tvoid)))
                                (Stmt.Sset ___x86_wr_cell_tag__1
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                    tuchar)))
                              Stmt.Sbreak))
                          (Stmt.Sloop
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Evar ___x86_wr_cell__1 (Ty.Tunion _x86_sim_gpr noattr))
                                  _ptr (tptr tvoid))
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Ecast
                                      (Expr.Etempvar ___x86_wr_next__1 tulong)
                                      tulong) tlong) (tptr tvoid)))
                              (Stmt.Sset ___x86_wr_cell_tag__1
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                  tuchar)))
                            Stmt.Sbreak)))))))
              (Stmt.Ssequence
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Etempvar _dst tuchar)
                                    (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                    tint)
                  (Stmt.Ssequence
                    (Stmt.Sset _t'137
                      (Expr.Efield
                        (Expr.Evar ___x86_wr_cell__1 (Ty.Tunion _x86_sim_gpr noattr))
                        _ptr (tptr tvoid)))
                    (Stmt.Ssequence
                      (Stmt.Sset _t'138
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                            (Ty.Tstruct _x86_sim_register_state noattr))
                          _native_stack_base tulong))
                      (Stmt.Sassign
                        (Expr.Efield
                          (Expr.Evar ___x86_wr_cell__1 (Ty.Tunion _x86_sim_gpr noattr))
                          _ptr (tptr tvoid))
                        (Expr.Ecast
                          (Expr.Ecast
                            (Expr.Ebinop Binop.Osub
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Etempvar _t'137 (tptr tvoid)) tlong)
                                tulong) (Expr.Etempvar _t'138 tulong) tulong)
                            tlong) (tptr tvoid)))))
                  Stmt.Sskip)
                (Stmt.Ssequence
                  (Stmt.Sset ___x86_wr_next_ptr__4
                    (Expr.Efield
                      (Expr.Evar ___x86_wr_cell__1 (Ty.Tunion _x86_sim_gpr noattr))
                      _ptr (tptr tvoid)))
                  (Stmt.Ssequence
                    (Stmt.Sset ___x86_wr_next_tag__4
                      (Expr.Ecast
                        (Expr.Etempvar ___x86_wr_cell_tag__1 tuchar) tuchar))
                    (Stmt.Ssequence
                      (Stmt.Sloop
                        (Stmt.Ssequence
                          (Stmt.Sset ___x86_store_reg__4
                            (Expr.Ecast (Expr.Etempvar _dst tuchar) tulong))
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                              (Expr.Etempvar ___x86_store_reg__4 tulong)
                                              (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                              tint)
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Efield
                                    (Expr.Ederef
                                      (Expr.Ebinop Binop.Oadd
                                        (Expr.Efield
                                          (Expr.Efield
                                            (Expr.Ederef
                                              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                              (Ty.Tstruct _x86_sim_register_state noattr))
                                            (Positive.ofNat 18727075383868559167)
                                            (Ty.Tunion __3115 noattr))
                                          _gpr_cells
                                          (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                                        (Expr.Ecast
                                          (Expr.Etempvar ___x86_store_reg__4 tulong)
                                          tuchar)
                                        (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                                      (Ty.Tstruct _x86_sim_gpr_cell noattr))
                                    _value (Ty.Tunion _x86_sim_gpr noattr))
                                  _ptr (tptr tvoid))
                                (Expr.Etempvar ___x86_wr_next_ptr__4 (tptr tvoid)))
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Efield
                                        (Expr.Efield
                                          (Expr.Ederef
                                            (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                            (Ty.Tstruct _x86_sim_register_state noattr))
                                          (Positive.ofNat 18727075383868559167)
                                          (Ty.Tunion __3115 noattr))
                                        _gpr_cells
                                        (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                                      (Expr.Ecast
                                        (Expr.Etempvar ___x86_store_reg__4 tulong)
                                        tuchar)
                                      (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                                    (Ty.Tstruct _x86_sim_gpr_cell noattr))
                                  _tag tuchar)
                                (Expr.Etempvar ___x86_wr_next_tag__4 tuchar)))
                            Stmt.Sskip))
                        Stmt.Sbreak)
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Etempvar _dst tuchar)
                                          (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                          tint)
                        (Stmt.Sloop
                          (Stmt.Ssequence
                            (Stmt.Sset ___x86_release_old__4
                              (Expr.Etempvar ___x86_write_old_sp__4 tlong))
                            (Stmt.Ssequence
                              s_kprog_x86_mov_reg_68
                              (Stmt.Sifthenelse (Expr.Ebinop Binop.Ogt
                                                  (Expr.Etempvar ___x86_release_new__4 tlong)
                                                  (Expr.Etempvar ___x86_release_old__4 tlong)
                                                  tint)
                                s_kprog_x86_mov_reg_69
                                Stmt.Sskip)))
                          Stmt.Sbreak)
                        Stmt.Sskip))))))))))))

def s_kprog_x86_mov_reg_71 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'130
    (Expr.Efield
      (Expr.Efield
        (Expr.Efield
          (Expr.Efield
            (Expr.Ederef
              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
              (Ty.Tstruct _x86_sim_register_state noattr))
            (Positive.ofNat 18727075383868559167) (Ty.Tunion __3115 noattr))
          (Positive.ofNat 18727075383868559167) (Ty.Tstruct __3116 noattr))
        _rsp (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
  (Stmt.Sset ___x86_write_old_sp__5
    (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'130 (tptr tvoid)) tlong) tlong)))

def s_kprog_x86_mov_reg_72 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                      (Expr.Ecast (Expr.Etempvar _src tuchar) tulong)
                      (Expr.Econst_int (Integers.Int.repr 16) tuint) tint)
    (Stmt.Ssequence
      (Stmt.Sset _t'129
        (Expr.Efield
          (Expr.Efield
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                      (Ty.Tstruct _x86_sim_register_state noattr))
                    (Positive.ofNat 18727075383868559167)
                    (Ty.Tunion __3115 noattr)) _gpr_cells
                  (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                (Expr.Ecast (Expr.Etempvar _src tuchar) tuchar)
                (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
              (Ty.Tstruct _x86_sim_gpr_cell noattr)) _value
            (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
      (Stmt.Sset _t'64
        (Expr.Ecast (Expr.Etempvar _t'129 (tptr tvoid)) (tptr tvoid))))
    (Stmt.Sset _t'64
      (Expr.Ecast
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
          (tptr tvoid)) (tptr tvoid))))
  (Stmt.Sset ___x86_wr_next_ptr__5
    (Expr.Ecast (Expr.Etempvar _t'64 (tptr tvoid)) (tptr tvoid))))

def s_kprog_x86_mov_reg_73 : Stmt :=
(Stmt.Sset _t'69
  (Expr.Ecast
    (Expr.Ebinop Binop.Oge (Expr.Etempvar ___x86_release_off__5 tlong)
      (Expr.Etempvar ___x86_release_old__5 tlong) tint) tbool))

def s_kprog_x86_mov_reg_74 : Stmt :=
(Stmt.Sset _t'70
  (Expr.Ecast
    (Expr.Ebinop Binop.Ole
      (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_release_off__5 tlong)
        (Expr.Econst_int (Integers.Int.repr 8) tint) tlong)
      (Expr.Etempvar ___x86_release_new__5 tlong) tint) tbool))

def s_kprog_x86_mov_reg_75 : Stmt :=
(Stmt.Scall (some _t'65)
  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong cc_default))
  [(Expr.Econst_int (Integers.Int.repr 6) tint)])

def s_kprog_x86_mov_reg_76 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'127
    (Expr.Efield
      (Expr.Ederef
        (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
        (Ty.Tstruct _kprog_x86_arena noattr)) _q (tptr (tvolatile tulong))))
  (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
    [(tptr (tvolatile tulong)), (tvolatile tulong)]
    [(Expr.Eaddrof
       (Expr.Ederef
         (Expr.Ebinop Binop.Oadd
           (Expr.Etempvar _t'127 (tptr (tvolatile tulong)))
           (Expr.Ebinop Binop.Odiv (Expr.Etempvar ___x86_release_i__5 tuint)
             (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint)
           (tptr (tvolatile tulong))) (tvolatile tulong))
       (tptr (tvolatile tulong))), (Expr.Etempvar _t'65 tulong)]))

def s_kprog_x86_mov_reg_77 : Stmt :=
(Stmt.Sset ___x86_release_lane__5
  (Expr.Econst_int (Integers.Int.repr 0) tint))

def s_kprog_x86_mov_reg_78 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                      (Expr.Etempvar ___x86_release_lane__5 tuint)
                      (Expr.Econst_int (Integers.Int.repr 8) tuint) tint)
    Stmt.Sskip
    Stmt.Sbreak)
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar ___x86_release_i__5 tuint)
                            (Expr.Etempvar ___x86_release_lane__5 tuint)
                            tuint) (Expr.Etempvar _capacity tuint) tint)
        (Stmt.Sset _t'67
          (Expr.Ecast
            (Expr.Ebinop Binop.Oge
              (Expr.Ebinop Binop.Oadd
                (Expr.Etempvar ___x86_release_off__5 tlong)
                (Expr.Etempvar ___x86_release_lane__5 tuint) tlong)
              (Expr.Etempvar ___x86_release_old__5 tlong) tint) tbool))
        (Stmt.Sset _t'67 (Expr.Econst_int (Integers.Int.repr 0) tint)))
      (Stmt.Sifthenelse (Expr.Etempvar _t'67 tint)
        (Stmt.Sset _t'68
          (Expr.Ecast
            (Expr.Ebinop Binop.Olt
              (Expr.Ebinop Binop.Oadd
                (Expr.Etempvar ___x86_release_off__5 tlong)
                (Expr.Etempvar ___x86_release_lane__5 tuint) tlong)
              (Expr.Etempvar ___x86_release_new__5 tlong) tint) tbool))
        (Stmt.Sset _t'68 (Expr.Econst_int (Integers.Int.repr 0) tint))))
    (Stmt.Sifthenelse (Expr.Etempvar _t'68 tint)
      (Stmt.Ssequence
        (Stmt.Scall (some _t'66)
          (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                               cc_default))
          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
        (Stmt.Ssequence
          (Stmt.Sset _t'126
            (Expr.Efield
              (Expr.Ederef
                (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                (Ty.Tstruct _kprog_x86_arena noattr)) _b
              (tptr (tvolatile tuchar))))
          (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
            [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
            [(Expr.Eaddrof
               (Expr.Ederef
                 (Expr.Ebinop Binop.Oadd
                   (Expr.Etempvar _t'126 (tptr (tvolatile tuchar)))
                   (Expr.Ebinop Binop.Oadd
                     (Expr.Etempvar ___x86_release_i__5 tuint)
                     (Expr.Etempvar ___x86_release_lane__5 tuint) tuint)
                   (tptr (tvolatile tuchar))) (tvolatile tuchar))
               (tptr (tvolatile tuchar))),
             (Expr.Ecast (Expr.Etempvar _t'66 tulong) tuchar)])))
      Stmt.Sskip)))

def s_kprog_x86_mov_reg_79 : Stmt :=
(Stmt.Sset ___x86_release_lane__5
  (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_release_lane__5 tuint)
    (Expr.Econst_int (Integers.Int.repr 1) tint) tuint))

def s_kprog_x86_mov_reg_80 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'124
      (Expr.Efield
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
            (Expr.Etempvar ___x86_sv_i__5 tuint)
            (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
          (Ty.Tstruct _kprog_x86_stack_fact noattr)) _tag (tptr tuchar)))
    (Stmt.Sassign (Expr.Ederef (Expr.Etempvar _t'124 (tptr tuchar)) tuchar)
      (Expr.Econst_int (Integers.Int.repr 0) tuint)))
  (Stmt.Ssequence
    (Stmt.Sset _t'123
      (Expr.Efield
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
            (Expr.Etempvar ___x86_sv_i__5 tuint)
            (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
          (Ty.Tstruct _kprog_x86_stack_fact noattr)) _pointer
        (tptr (tptr tvoid))))
    (Stmt.Sassign
      (Expr.Ederef (Expr.Etempvar _t'123 (tptr (tptr tvoid))) (tptr tvoid))
      (Expr.Econst_int (Integers.Int.repr 0) tint))))

def s_kprog_x86_mov_reg_81 : Stmt :=
Stmt.Sbreak

def s_kprog_x86_mov_reg_82 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_wr_next_tag__5
    (Expr.Ecast (Expr.Etempvar ___x86_mov_source_tag tuchar) tuchar))
  (Stmt.Ssequence
    (Stmt.Sloop
      (Stmt.Ssequence
        (Stmt.Sset ___x86_store_reg__5
          (Expr.Ecast (Expr.Etempvar _dst tuchar) tulong))
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                            (Expr.Etempvar ___x86_store_reg__5 tulong)
                            (Expr.Econst_int (Integers.Int.repr 16) tuint)
                            tint)
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Efield
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                            (Ty.Tstruct _x86_sim_register_state noattr))
                          (Positive.ofNat 18727075383868559167)
                          (Ty.Tunion __3115 noattr)) _gpr_cells
                        (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                      (Expr.Ecast (Expr.Etempvar ___x86_store_reg__5 tulong)
                        tuchar) (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                    (Ty.Tstruct _x86_sim_gpr_cell noattr)) _value
                  (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid))
              (Expr.Etempvar ___x86_wr_next_ptr__5 (tptr tvoid)))
            (Stmt.Sassign
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Efield
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                          (Ty.Tstruct _x86_sim_register_state noattr))
                        (Positive.ofNat 18727075383868559167)
                        (Ty.Tunion __3115 noattr)) _gpr_cells
                      (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                    (Expr.Ecast (Expr.Etempvar ___x86_store_reg__5 tulong)
                      tuchar) (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                  (Ty.Tstruct _x86_sim_gpr_cell noattr)) _tag tuchar)
              (Expr.Etempvar ___x86_wr_next_tag__5 tuchar)))
          Stmt.Sskip))
      Stmt.Sbreak)
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _dst tuchar)
                        (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
      (Stmt.Sloop
        (Stmt.Ssequence
          (Stmt.Sset ___x86_release_old__5
            (Expr.Etempvar ___x86_write_old_sp__5 tlong))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sset _t'128
                (Expr.Efield
                  (Expr.Efield
                    (Expr.Efield
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                          (Ty.Tstruct _x86_sim_register_state noattr))
                        (Positive.ofNat 18727075383868559167)
                        (Ty.Tunion __3115 noattr))
                      (Positive.ofNat 18727075383868559167)
                      (Ty.Tstruct __3116 noattr)) _rsp
                    (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
              (Stmt.Sset ___x86_release_new__5
                (Expr.Ecast
                  (Expr.Ecast (Expr.Etempvar _t'128 (tptr tvoid)) tlong)
                  tlong)))
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Ogt
                                (Expr.Etempvar ___x86_release_new__5 tlong)
                                (Expr.Etempvar ___x86_release_old__5 tlong)
                                tint)
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sset ___x86_release_i__5
                    (Expr.Econst_int (Integers.Int.repr 0) tint))
                  (Stmt.Sloop
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                          (Expr.Etempvar ___x86_release_i__5 tuint)
                                          (Expr.Etempvar _capacity tuint)
                                          tint)
                        Stmt.Sskip
                        Stmt.Sbreak)
                      (Stmt.Ssequence
                        (Stmt.Sset ___x86_release_off__5
                          (Expr.Ebinop Binop.Osub
                            (Expr.Ecast
                              (Expr.Etempvar ___x86_release_i__5 tuint)
                              tlong)
                            (Expr.Ecast (Expr.Etempvar _capacity tuint)
                              tlong) tlong))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Ole
                                                (Expr.Ebinop Binop.Oadd
                                                  (Expr.Etempvar ___x86_release_i__5 tuint)
                                                  (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                                  tuint)
                                                (Expr.Etempvar _capacity tuint)
                                                tint)
                              s_kprog_x86_mov_reg_73
                              (Stmt.Sset _t'69
                                (Expr.Econst_int (Integers.Int.repr 0) tint)))
                            (Stmt.Sifthenelse (Expr.Etempvar _t'69 tint)
                              s_kprog_x86_mov_reg_74
                              (Stmt.Sset _t'70
                                (Expr.Econst_int (Integers.Int.repr 0) tint))))
                          (Stmt.Sifthenelse (Expr.Etempvar _t'70 tint)
                            (Stmt.Ssequence
                              s_kprog_x86_mov_reg_75
                              s_kprog_x86_mov_reg_76)
                            (Stmt.Ssequence
                              s_kprog_x86_mov_reg_77
                              (Stmt.Sloop
                                s_kprog_x86_mov_reg_78
                                s_kprog_x86_mov_reg_79))))))
                    (Stmt.Sset ___x86_release_i__5
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar ___x86_release_i__5 tuint)
                        (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint))))
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sset _t'125
                        (Expr.Efield
                          (Expr.Efield
                            (Expr.Efield
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                  (Ty.Tstruct _x86_sim_register_state noattr))
                                (Positive.ofNat 18727075383868559167)
                                (Ty.Tunion __3115 noattr))
                              (Positive.ofNat 18727075383868559167)
                              (Ty.Tstruct __3116 noattr)) _rsp
                            (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                          (tptr tvoid)))
                      (Stmt.Sset ___x86_sv_sp__5
                        (Expr.Ecast
                          (Expr.Ecast (Expr.Etempvar _t'125 (tptr tvoid))
                            tlong) tlong)))
                    (Stmt.Ssequence
                      (Stmt.Sset ___x86_sv_i__5
                        (Expr.Econst_int (Integers.Int.repr 0) tint))
                      (Stmt.Sloop
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                              (Expr.Etempvar ___x86_sv_i__5 tuint)
                                              (Expr.Ebinop Binop.Odiv
                                                (Expr.Ebinop Binop.Oadd
                                                  (Expr.Ecast
                                                    (Expr.Etempvar _capacity tuint)
                                                    tulong)
                                                  (Expr.Econst_int (Integers.Int.repr 7) tuint)
                                                  tulong)
                                                (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                                tulong) tint)
                            Stmt.Sskip
                            Stmt.Sbreak)
                          (Stmt.Sloop
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                                (Expr.Ebinop Binop.Osub
                                                  (Expr.Ecast
                                                    (Expr.Ebinop Binop.Omul
                                                      (Expr.Ecast
                                                        (Expr.Etempvar ___x86_sv_i__5 tuint)
                                                        tulong)
                                                      (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                                      tulong) tlong)
                                                  (Expr.Ecast
                                                    (Expr.Etempvar _capacity tuint)
                                                    tlong) tlong)
                                                (Expr.Etempvar ___x86_sv_sp__5 tlong)
                                                tint)
                              (Stmt.Sloop
                                s_kprog_x86_mov_reg_80
                                s_kprog_x86_mov_reg_81)
                              Stmt.Sskip)
                            Stmt.Sbreak))
                        (Stmt.Sset ___x86_sv_i__5
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar ___x86_sv_i__5 tuint)
                            (Expr.Econst_int (Integers.Int.repr 1) tint)
                            tuint)))))
                  Stmt.Sbreak))
              Stmt.Sskip)))
        Stmt.Sbreak)
      Stmt.Sskip)))

def s_kprog_x86_mov_reg_83 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                      (Expr.Ecast (Expr.Etempvar ___x86_rd_reg__2 tuchar)
                        tulong)
                      (Expr.Econst_int (Integers.Int.repr 16) tuint) tint)
    (Stmt.Ssequence
      (Stmt.Sset _t'122
        (Expr.Efield
          (Expr.Efield
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                      (Ty.Tstruct _x86_sim_register_state noattr))
                    (Positive.ofNat 18727075383868559167)
                    (Ty.Tunion __3115 noattr)) _gpr_cells
                  (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                (Expr.Ecast (Expr.Etempvar ___x86_rd_reg__2 tuchar) tuchar)
                (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
              (Ty.Tstruct _x86_sim_gpr_cell noattr)) _value
            (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
      (Stmt.Sset _t'74
        (Expr.Ecast (Expr.Etempvar _t'122 (tptr tvoid)) (tptr tvoid))))
    (Stmt.Sset _t'74
      (Expr.Ecast
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
          (tptr tvoid)) (tptr tvoid))))
  (Stmt.Sset ___x86_rd_ptr__2 (Expr.Etempvar _t'74 (tptr tvoid))))

def s_kprog_x86_mov_reg_84 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_rd_value__2
    (Expr.Ecast
      (Expr.Ecast (Expr.Etempvar ___x86_rd_ptr__2 (tptr tvoid)) tlong)
      tulong))
  (Stmt.Ssequence
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                        (Expr.Etempvar ___x86_rd_reg__2 tuchar)
                        (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
      (Stmt.Ssequence
        (Stmt.Sset _t'121
          (Expr.Efield
            (Expr.Ederef
              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
              (Ty.Tstruct _x86_sim_register_state noattr)) _native_stack_base
            tulong))
        (Stmt.Sset ___x86_rd_value__2
          (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_rd_value__2 tulong)
            (Expr.Etempvar _t'121 tulong) tulong)))
      (Stmt.Ssequence
        (Stmt.Sloop
          (Stmt.Ssequence
            (Stmt.Sset ___x86_tag_reg__5
              (Expr.Ecast (Expr.Etempvar ___x86_rd_reg__2 tuchar) tulong))
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                  (Expr.Etempvar ___x86_tag_reg__5 tulong)
                                  (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                  tint)
                (Stmt.Ssequence
                  (Stmt.Sset _t'120
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Efield
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                (Ty.Tstruct _x86_sim_register_state noattr))
                              (Positive.ofNat 18727075383868559167)
                              (Ty.Tunion __3115 noattr)) _gpr_cells
                            (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                          (Expr.Ecast
                            (Expr.Etempvar ___x86_tag_reg__5 tulong) tuchar)
                          (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                        (Ty.Tstruct _x86_sim_gpr_cell noattr)) _tag tuchar))
                  (Stmt.Sset _t'75
                    (Expr.Ecast (Expr.Etempvar _t'120 tuchar) tuint)))
                (Stmt.Sset _t'75
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                    tuint)))
              (Stmt.Sset ___x86_rd_tag__2
                (Expr.Ecast (Expr.Etempvar _t'75 tuint) tuchar))))
          Stmt.Sbreak)
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar ___x86_rd_tag__2 tuchar)
                            (Expr.Econst_int (Integers.Int.repr 4) tuint)
                            tint)
          (Stmt.Sloop
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'119
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                      (Ty.Tstruct _kprog_x86_arena noattr)) _b
                    (tptr (tvolatile tuchar))))
                (Stmt.Sset ___x86_stack_delta__6
                  (Expr.Ebinop Binop.Osub
                    (Expr.Ecast
                      (Expr.Ecast
                        (Expr.Etempvar ___x86_rd_ptr__2 (tptr tvoid)) tlong)
                      tulong)
                    (Expr.Ecast
                      (Expr.Ecast
                        (Expr.Ecast
                          (Expr.Ecast
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Etempvar _t'119 (tptr (tvolatile tuchar)))
                                      (Expr.Econst_int (Integers.Int.repr 0) tint)
                                      (tptr (tvolatile tuchar))) tulong)
                                  tulong)
                                (Expr.Ecast
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Ecast
                                      (Expr.Econst_int (Integers.Int.repr 0) tint)
                                      tulong)
                                    (Expr.Ecast
                                      (Expr.Etempvar _capacity tuint) tulong)
                                    tulong) tulong) tulong) tulong)
                            (tptr tuchar)) (tptr tvoid)) tlong) tulong)
                    tulong)))
              (Stmt.Ssequence
                (Stmt.Sset _t'118
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                      (Ty.Tstruct _x86_sim_register_state noattr))
                    _native_stack_base tulong))
                (Stmt.Sset ___x86_rd_value__2
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Etempvar ___x86_stack_delta__6 tulong)
                    (Expr.Etempvar _t'118 tulong) tulong))))
            Stmt.Sbreak)
          Stmt.Sskip)))
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar ___x86_rd_width__2 tuchar)
                            (Expr.Econst_int (Integers.Int.repr 1) tuint)
                            tint)
          (Stmt.Sset _t'76
            (Expr.Ecast (Expr.Etempvar ___x86_rd_shift__2 tuchar) tuint))
          (Stmt.Sset _t'76
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuint)))
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar ___x86_rd_width__2 tuchar)
                            (Expr.Econst_int (Integers.Int.repr 1) tuint)
                            tint)
          (Stmt.Sset _t'77
            (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 255) tulong)
              tulong))
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar ___x86_rd_width__2 tuchar)
                              (Expr.Econst_int (Integers.Int.repr 2) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Sset _t'77
                (Expr.Ecast
                  (Expr.Econst_long (Integers.Int64.repr 65535) tulong)
                  tulong))
              (Stmt.Sset _t'77
                (Expr.Ecast (Expr.Etempvar _t'77 tulong) tulong)))
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Etempvar ___x86_rd_width__2 tuchar)
                                (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                tint)
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sset _t'77
                    (Expr.Ecast
                      (Expr.Econst_long (Integers.Int64.repr 4294967295) tulong)
                      tulong))
                  (Stmt.Sset _t'77
                    (Expr.Ecast (Expr.Etempvar _t'77 tulong) tulong)))
                (Stmt.Sset _t'77
                  (Expr.Ecast (Expr.Etempvar _t'77 tulong) tulong)))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sset _t'77
                    (Expr.Ecast
                      (Expr.Econst_long (Integers.Int64.repr (-1)) tulong)
                      tulong))
                  (Stmt.Sset _t'77
                    (Expr.Ecast (Expr.Etempvar _t'77 tulong) tulong)))
                (Stmt.Sset _t'77
                  (Expr.Ecast (Expr.Etempvar _t'77 tulong) tulong)))))))
      (Stmt.Sset ___x86_l_value
        (Expr.Ebinop Binop.Oand
          (Expr.Ebinop Binop.Oshr (Expr.Etempvar ___x86_rd_value__2 tulong)
            (Expr.Etempvar _t'76 tuint) tulong) (Expr.Etempvar _t'77 tulong)
          tulong)))))

def s_kprog_x86_mov_reg_85 : Stmt :=
(Stmt.Sset ___x86_wr_next__2 (Expr.Etempvar ___x86_l_value tulong))

def s_kprog_x86_mov_reg_86 : Stmt :=
(Stmt.Sset ___kprog_x86_bits__4
  (Expr.Ebinop Binop.Oor
    (Expr.Ebinop Binop.Oand (Expr.Etempvar ___kprog_x86_bits__4 tulong)
      (Expr.Eunop Unop.Onotint
        (Expr.Econst_long (Integers.Int64.repr 65280) tulong) tulong) tulong)
    (Expr.Ebinop Binop.Oshl
      (Expr.Ecast (Expr.Etempvar ___kprog_x86_lane__4 tuchar) tulong)
      (Expr.Econst_int (Integers.Int.repr 8) tint) tulong) tulong))

def s_kprog_x86_mov_reg_87 : Stmt :=
(Stmt.Sset ___kprog_x86_bits__4
  (Expr.Ebinop Binop.Oor
    (Expr.Ebinop Binop.Oand (Expr.Etempvar ___kprog_x86_bits__4 tulong)
      (Expr.Eunop Unop.Onotint
        (Expr.Econst_long (Integers.Int64.repr 255) tulong) tulong) tulong)
    (Expr.Etempvar ___kprog_x86_lane__4 tuchar) tulong))

def s_kprog_x86_mov_reg_88 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'106
    (Expr.Efield
      (Expr.Ederef
        (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
        (Ty.Tstruct _kprog_x86_arena noattr)) _b (tptr (tvolatile tuchar))))
  (Stmt.Sset ___x86_stack_delta__8
    (Expr.Ebinop Binop.Osub
      (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'105 (tptr tvoid)) tlong)
        tulong)
      (Expr.Ecast
        (Expr.Ecast
          (Expr.Ecast
            (Expr.Ecast
              (Expr.Ecast
                (Expr.Ebinop Binop.Oadd
                  (Expr.Ecast
                    (Expr.Ecast
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar _t'106 (tptr (tvolatile tuchar)))
                        (Expr.Econst_int (Integers.Int.repr 0) tint)
                        (tptr (tvolatile tuchar))) tulong) tulong)
                  (Expr.Ecast
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 0) tint) tulong)
                      (Expr.Ecast (Expr.Etempvar _capacity tuint) tulong)
                      tulong) tulong) tulong) tulong) (tptr tuchar))
            (tptr tvoid)) tlong) tulong) tulong)))

def s_kprog_x86_mov_reg_89 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'104
    (Expr.Efield
      (Expr.Ederef
        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
        (Ty.Tstruct _x86_sim_register_state noattr)) _native_stack_base
      tulong))
  (Stmt.Sset ___x86_wr_stack_bits__5
    (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_stack_delta__8 tulong)
      (Expr.Etempvar _t'104 tulong) tulong)))

def s_kprog_x86_mov_reg_90 : Stmt :=
(Stmt.Sbuiltin (some _t'82) (ExtFun.EF_vload Chunk.Mint64)
  [(tptr (tvolatile (tptr tvoid)))]
  [(Expr.Eaddrof
     (Expr.Efield
       (Expr.Evar ___kprog_x86_partial__5 (tvolatile (Ty.Tunion __3584 noattr)))
       _ptr (tvolatile (tptr tvoid))) (tptr (tvolatile (tptr tvoid))))])

def s_kprog_x86_mov_reg_91 : Stmt :=
(Stmt.Sassign
  (Expr.Efield (Expr.Evar ___x86_wr_cell__2 (Ty.Tunion _x86_sim_gpr noattr))
    _ptr (tptr tvoid))
  (Expr.Ecast
    (Expr.Ecast
      (Expr.Ebinop Binop.Oor
        (Expr.Ebinop Binop.Oand (Expr.Etempvar ___kprog_x86_bits__5 tulong)
          (Expr.Eunop Unop.Onotint
            (Expr.Econst_long (Integers.Int64.repr 65535) tulong) tulong)
          tulong) (Expr.Etempvar ___kprog_x86_lane__5 tushort) tulong) tlong)
    (tptr tvoid)))

def s_kprog_x86_mov_reg_92 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                      (Expr.Etempvar ___x86_release_i__6 tuint)
                      (Expr.Etempvar _capacity tuint) tint)
    Stmt.Sskip
    Stmt.Sbreak)
  (Stmt.Ssequence
    (Stmt.Sset ___x86_release_off__6
      (Expr.Ebinop Binop.Osub
        (Expr.Ecast (Expr.Etempvar ___x86_release_i__6 tuint) tlong)
        (Expr.Ecast (Expr.Etempvar _capacity tuint) tlong) tlong))
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Ole
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar ___x86_release_i__6 tuint)
                              (Expr.Econst_int (Integers.Int.repr 8) tuint)
                              tuint) (Expr.Etempvar _capacity tuint) tint)
          (Stmt.Sset _t'90
            (Expr.Ecast
              (Expr.Ebinop Binop.Oge
                (Expr.Etempvar ___x86_release_off__6 tlong)
                (Expr.Etempvar ___x86_release_old__6 tlong) tint) tbool))
          (Stmt.Sset _t'90 (Expr.Econst_int (Integers.Int.repr 0) tint)))
        (Stmt.Sifthenelse (Expr.Etempvar _t'90 tint)
          (Stmt.Sset _t'91
            (Expr.Ecast
              (Expr.Ebinop Binop.Ole
                (Expr.Ebinop Binop.Oadd
                  (Expr.Etempvar ___x86_release_off__6 tlong)
                  (Expr.Econst_int (Integers.Int.repr 8) tint) tlong)
                (Expr.Etempvar ___x86_release_new__6 tlong) tint) tbool))
          (Stmt.Sset _t'91 (Expr.Econst_int (Integers.Int.repr 0) tint))))
      (Stmt.Sifthenelse (Expr.Etempvar _t'91 tint)
        (Stmt.Ssequence
          (Stmt.Scall (some _t'86)
            (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                 cc_default))
            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
          (Stmt.Ssequence
            (Stmt.Sset _t'99
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                  (Ty.Tstruct _kprog_x86_arena noattr)) _q
                (tptr (tvolatile tulong))))
            (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
              [(tptr (tvolatile tulong)), (tvolatile tulong)]
              [(Expr.Eaddrof
                 (Expr.Ederef
                   (Expr.Ebinop Binop.Oadd
                     (Expr.Etempvar _t'99 (tptr (tvolatile tulong)))
                     (Expr.Ebinop Binop.Odiv
                       (Expr.Etempvar ___x86_release_i__6 tuint)
                       (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint)
                     (tptr (tvolatile tulong))) (tvolatile tulong))
                 (tptr (tvolatile tulong))), (Expr.Etempvar _t'86 tulong)])))
        (Stmt.Ssequence
          (Stmt.Sset ___x86_release_lane__6
            (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Sloop
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                  (Expr.Etempvar ___x86_release_lane__6 tuint)
                                  (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                  tint)
                Stmt.Sskip
                Stmt.Sbreak)
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                      (Expr.Ebinop Binop.Oadd
                                        (Expr.Etempvar ___x86_release_i__6 tuint)
                                        (Expr.Etempvar ___x86_release_lane__6 tuint)
                                        tuint)
                                      (Expr.Etempvar _capacity tuint) tint)
                    (Stmt.Sset _t'88
                      (Expr.Ecast
                        (Expr.Ebinop Binop.Oge
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar ___x86_release_off__6 tlong)
                            (Expr.Etempvar ___x86_release_lane__6 tuint)
                            tlong)
                          (Expr.Etempvar ___x86_release_old__6 tlong) tint)
                        tbool))
                    (Stmt.Sset _t'88
                      (Expr.Econst_int (Integers.Int.repr 0) tint)))
                  (Stmt.Sifthenelse (Expr.Etempvar _t'88 tint)
                    (Stmt.Sset _t'89
                      (Expr.Ecast
                        (Expr.Ebinop Binop.Olt
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar ___x86_release_off__6 tlong)
                            (Expr.Etempvar ___x86_release_lane__6 tuint)
                            tlong)
                          (Expr.Etempvar ___x86_release_new__6 tlong) tint)
                        tbool))
                    (Stmt.Sset _t'89
                      (Expr.Econst_int (Integers.Int.repr 0) tint))))
                (Stmt.Sifthenelse (Expr.Etempvar _t'89 tint)
                  (Stmt.Ssequence
                    (Stmt.Scall (some _t'87)
                      (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                           [tuint] tulong
                                                           cc_default))
                      [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                    (Stmt.Ssequence
                      (Stmt.Sset _t'98
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                            (Ty.Tstruct _kprog_x86_arena noattr)) _b
                          (tptr (tvolatile tuchar))))
                      (Stmt.Sbuiltin none
                        (ExtFun.EF_vstore Chunk.Mint8unsigned)
                        [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
                        [(Expr.Eaddrof
                           (Expr.Ederef
                             (Expr.Ebinop Binop.Oadd
                               (Expr.Etempvar _t'98 (tptr (tvolatile tuchar)))
                               (Expr.Ebinop Binop.Oadd
                                 (Expr.Etempvar ___x86_release_i__6 tuint)
                                 (Expr.Etempvar ___x86_release_lane__6 tuint)
                                 tuint) (tptr (tvolatile tuchar)))
                             (tvolatile tuchar)) (tptr (tvolatile tuchar))),
                         (Expr.Ecast (Expr.Etempvar _t'87 tulong) tuchar)])))
                  Stmt.Sskip)))
            (Stmt.Sset ___x86_release_lane__6
              (Expr.Ebinop Binop.Oadd
                (Expr.Etempvar ___x86_release_lane__6 tuint)
                (Expr.Econst_int (Integers.Int.repr 1) tint) tuint))))))))

def s_kprog_x86_mov_reg_93 : Stmt :=
(Stmt.Sset ___x86_release_i__6
  (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_release_i__6 tuint)
    (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint))

def s_kprog_x86_mov_reg_94 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'97
    (Expr.Efield
      (Expr.Efield
        (Expr.Efield
          (Expr.Efield
            (Expr.Ederef
              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
              (Ty.Tstruct _x86_sim_register_state noattr))
            (Positive.ofNat 18727075383868559167) (Ty.Tunion __3115 noattr))
          (Positive.ofNat 18727075383868559167) (Ty.Tstruct __3116 noattr))
        _rsp (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
  (Stmt.Sset ___x86_sv_sp__6
    (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'97 (tptr tvoid)) tlong) tlong)))

def s_kprog_x86_mov_reg_95 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_sv_i__6 (Expr.Econst_int (Integers.Int.repr 0) tint))
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                          (Expr.Etempvar ___x86_sv_i__6 tuint)
                          (Expr.Ebinop Binop.Odiv
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Ecast (Expr.Etempvar _capacity tuint)
                                tulong)
                              (Expr.Econst_int (Integers.Int.repr 7) tuint)
                              tulong)
                            (Expr.Econst_int (Integers.Int.repr 8) tuint)
                            tulong) tint)
        Stmt.Sskip
        Stmt.Sbreak)
      (Stmt.Sloop
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                            (Expr.Ebinop Binop.Osub
                              (Expr.Ecast
                                (Expr.Ebinop Binop.Omul
                                  (Expr.Ecast
                                    (Expr.Etempvar ___x86_sv_i__6 tuint)
                                    tulong)
                                  (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                  tulong) tlong)
                              (Expr.Ecast (Expr.Etempvar _capacity tuint)
                                tlong) tlong)
                            (Expr.Etempvar ___x86_sv_sp__6 tlong) tint)
          (Stmt.Sloop
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'96
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                        (Expr.Etempvar ___x86_sv_i__6 tuint)
                        (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                      (Ty.Tstruct _kprog_x86_stack_fact noattr)) _tag
                    (tptr tuchar)))
                (Stmt.Sassign
                  (Expr.Ederef (Expr.Etempvar _t'96 (tptr tuchar)) tuchar)
                  (Expr.Econst_int (Integers.Int.repr 0) tuint)))
              (Stmt.Ssequence
                (Stmt.Sset _t'95
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                        (Expr.Etempvar ___x86_sv_i__6 tuint)
                        (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                      (Ty.Tstruct _kprog_x86_stack_fact noattr)) _pointer
                    (tptr (tptr tvoid))))
                (Stmt.Sassign
                  (Expr.Ederef (Expr.Etempvar _t'95 (tptr (tptr tvoid)))
                    (tptr tvoid))
                  (Expr.Econst_int (Integers.Int.repr 0) tint))))
            Stmt.Sbreak)
          Stmt.Sskip)
        Stmt.Sbreak))
    (Stmt.Sset ___x86_sv_i__6
      (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_sv_i__6 tuint)
        (Expr.Econst_int (Integers.Int.repr 1) tint) tuint))))

def s_kprog_x86_mov_reg_96 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                        (Expr.Ecast (Expr.Etempvar _dst tuchar) tulong)
                        (Expr.Econst_int (Integers.Int.repr 16) tuint) tint)
      (Stmt.Ssequence
        (Stmt.Sset _t'116
          (Expr.Efield
            (Expr.Efield
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                        (Ty.Tstruct _x86_sim_register_state noattr))
                      (Positive.ofNat 18727075383868559167)
                      (Ty.Tunion __3115 noattr)) _gpr_cells
                    (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                  (Expr.Ecast (Expr.Etempvar _dst tuchar) tuchar)
                  (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                (Ty.Tstruct _x86_sim_gpr_cell noattr)) _value
              (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
        (Stmt.Sset _t'79
          (Expr.Ecast (Expr.Etempvar _t'116 (tptr tvoid)) (tptr tvoid))))
      (Stmt.Sset _t'79
        (Expr.Ecast
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
            (tptr tvoid)) (tptr tvoid))))
    (Stmt.Sassign
      (Expr.Efield
        (Expr.Evar ___x86_wr_cell__2 (Ty.Tunion _x86_sim_gpr noattr)) _ptr
        (tptr tvoid)) (Expr.Etempvar _t'79 (tptr tvoid))))
  (Stmt.Ssequence
    (Stmt.Sloop
      (Stmt.Ssequence
        (Stmt.Sset ___x86_tag_reg__6
          (Expr.Ecast (Expr.Etempvar _dst tuchar) tulong))
        (Stmt.Ssequence
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                              (Expr.Etempvar ___x86_tag_reg__6 tulong)
                              (Expr.Econst_int (Integers.Int.repr 16) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Sset _t'115
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                            (Ty.Tstruct _x86_sim_register_state noattr))
                          (Positive.ofNat 18727075383868559167)
                          (Ty.Tunion __3115 noattr)) _gpr_cells
                        (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                      (Expr.Ecast (Expr.Etempvar ___x86_tag_reg__6 tulong)
                        tuchar) (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                    (Ty.Tstruct _x86_sim_gpr_cell noattr)) _tag tuchar))
              (Stmt.Sset _t'80
                (Expr.Ecast (Expr.Etempvar _t'115 tuchar) tuint)))
            (Stmt.Sset _t'80
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                tuint)))
          (Stmt.Sset ___x86_wr_cell_tag__2
            (Expr.Ecast (Expr.Etempvar _t'80 tuint) tuchar))))
      Stmt.Sbreak)
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Ecast
                              (Expr.Etempvar ___x86_wr_width__2 tuchar)
                              tuchar)
                            (Expr.Econst_int (Integers.Int.repr 1) tuint)
                            tint)
          (Stmt.Sset _t'85
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuint))
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Ecast
                                (Expr.Etempvar ___x86_wr_width__2 tuchar)
                                tuchar)
                              (Expr.Econst_int (Integers.Int.repr 2) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Sset _t'85
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint)
                  tuint))
              (Stmt.Sset _t'85
                (Expr.Ecast (Expr.Etempvar _t'85 tuint) tuint)))
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Ecast
                                  (Expr.Etempvar ___x86_wr_width__2 tuchar)
                                  tuchar)
                                (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                tint)
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sset _t'85
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint)
                      tuint))
                  (Stmt.Sset _t'85
                    (Expr.Ecast (Expr.Etempvar _t'85 tuint) tuint)))
                (Stmt.Sset _t'85
                  (Expr.Ecast (Expr.Etempvar _t'85 tuint) tuint)))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sset _t'85
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint)
                      tuint))
                  (Stmt.Sset _t'85
                    (Expr.Ecast (Expr.Etempvar _t'85 tuint) tuint)))
                (Stmt.Sset _t'85
                  (Expr.Ecast (Expr.Etempvar _t'85 tuint) tuint))))))
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _t'85 tuint)
                            (Expr.Econst_int (Integers.Int.repr 0) tuint)
                            tint)
          (Stmt.Ssequence
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Etempvar _dst tuchar)
                                (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                tint)
              (Stmt.Ssequence
                (Stmt.Sset _t'113
                  (Expr.Efield
                    (Expr.Evar ___x86_wr_cell__2 (Ty.Tunion _x86_sim_gpr noattr))
                    _ptr (tptr tvoid)))
                (Stmt.Ssequence
                  (Stmt.Sset _t'114
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                        (Ty.Tstruct _x86_sim_register_state noattr))
                      _native_stack_base tulong))
                  (Stmt.Sassign
                    (Expr.Efield
                      (Expr.Evar ___x86_wr_cell__2 (Ty.Tunion _x86_sim_gpr noattr))
                      _ptr (tptr tvoid))
                    (Expr.Ecast
                      (Expr.Ecast
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Ecast
                            (Expr.Ecast (Expr.Etempvar _t'113 (tptr tvoid))
                              tlong) tulong) (Expr.Etempvar _t'114 tulong)
                          tulong) tlong) (tptr tvoid)))))
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar ___x86_wr_cell_tag__2 tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                  tint)
                (Stmt.Ssequence
                  (Stmt.Sloop
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sset _t'111
                          (Expr.Efield
                            (Expr.Evar ___x86_wr_cell__2 (Ty.Tunion _x86_sim_gpr noattr))
                            _ptr (tptr tvoid)))
                        (Stmt.Ssequence
                          (Stmt.Sset _t'112
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                                (Ty.Tstruct _kprog_x86_arena noattr)) _b
                              (tptr (tvolatile tuchar))))
                          (Stmt.Sset ___x86_stack_delta__7
                            (Expr.Ebinop Binop.Osub
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Etempvar _t'111 (tptr tvoid)) tlong)
                                tulong)
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Ecast
                                      (Expr.Ecast
                                        (Expr.Ebinop Binop.Oadd
                                          (Expr.Ecast
                                            (Expr.Ecast
                                              (Expr.Ebinop Binop.Oadd
                                                (Expr.Etempvar _t'112 (tptr (tvolatile tuchar)))
                                                (Expr.Econst_int (Integers.Int.repr 0) tint)
                                                (tptr (tvolatile tuchar)))
                                              tulong) tulong)
                                          (Expr.Ecast
                                            (Expr.Ebinop Binop.Oadd
                                              (Expr.Ecast
                                                (Expr.Econst_int (Integers.Int.repr 0) tint)
                                                tulong)
                                              (Expr.Ecast
                                                (Expr.Etempvar _capacity tuint)
                                                tulong) tulong) tulong)
                                          tulong) tulong) (tptr tuchar))
                                    (tptr tvoid)) tlong) tulong) tulong))))
                      (Stmt.Ssequence
                        (Stmt.Sset _t'110
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                              (Ty.Tstruct _x86_sim_register_state noattr))
                            _native_stack_base tulong))
                        (Stmt.Sset ___x86_wr_stack_bits__4
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar ___x86_stack_delta__7 tulong)
                            (Expr.Etempvar _t'110 tulong) tulong))))
                    Stmt.Sbreak)
                  (Stmt.Sassign
                    (Expr.Efield
                      (Expr.Evar ___x86_wr_cell__2 (Ty.Tunion _x86_sim_gpr noattr))
                      _ptr (tptr tvoid))
                    (Expr.Ecast
                      (Expr.Ecast
                        (Expr.Etempvar ___x86_wr_stack_bits__4 tulong) tlong)
                      (tptr tvoid))))
                Stmt.Sskip))
            (Stmt.Sloop
              (Stmt.Ssequence
                (Stmt.Sset ___kprog_x86_lane__4
                  (Expr.Ecast (Expr.Etempvar ___x86_wr_next__2 tulong)
                    tuchar))
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar ___x86_wr_cell_tag__2 tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                      tint)
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Etempvar ___x86_wr_shift__2 tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                        tint)
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar ___x86_wr_cell__2 (Ty.Tunion _x86_sim_gpr noattr))
                              _b (tarray tuchar 8))
                            (Expr.Econst_int (Integers.Int.repr 1) tint)
                            (tptr tuchar)) tuchar)
                        (Expr.Etempvar ___kprog_x86_lane__4 tuchar))
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar ___x86_wr_cell__2 (Ty.Tunion _x86_sim_gpr noattr))
                              _b (tarray tuchar 8))
                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                            (tptr tuchar)) tuchar)
                        (Expr.Etempvar ___kprog_x86_lane__4 tuchar)))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sset _t'109
                          (Expr.Efield
                            (Expr.Evar ___x86_wr_cell__2 (Ty.Tunion _x86_sim_gpr noattr))
                            _ptr (tptr tvoid)))
                        (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
                          [(tptr (tvolatile (tptr tvoid))),
                           (tvolatile (tptr tvoid))]
                          [(Expr.Eaddrof
                             (Expr.Efield
                               (Expr.Evar ___kprog_x86_partial__4 (tvolatile (Ty.Tunion __3578 noattr)))
                               _ptr (tvolatile (tptr tvoid)))
                             (tptr (tvolatile (tptr tvoid)))),
                           (Expr.Etempvar _t'109 (tptr tvoid))]))
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Etempvar ___x86_wr_shift__2 tuchar)
                                            (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                            tint)
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Evar ___kprog_x86_partial__4 (tvolatile (Ty.Tunion __3578 noattr)))
                                  _b (tvolatile (tarray tuchar 8)))
                                (Expr.Econst_int (Integers.Int.repr 1) tint)
                                (tptr tuchar)) tuchar)
                            (Expr.Etempvar ___kprog_x86_lane__4 tuchar))
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Evar ___kprog_x86_partial__4 (tvolatile (Ty.Tunion __3578 noattr)))
                                  _b (tvolatile (tarray tuchar 8)))
                                (Expr.Econst_int (Integers.Int.repr 0) tint)
                                (tptr tuchar)) tuchar)
                            (Expr.Etempvar ___kprog_x86_lane__4 tuchar)))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Sbuiltin (some _t'81)
                              (ExtFun.EF_vload Chunk.Mint64)
                              [(tptr (tvolatile (tptr tvoid)))]
                              [(Expr.Eaddrof
                                 (Expr.Efield
                                   (Expr.Evar ___kprog_x86_partial__4 (tvolatile (Ty.Tunion __3578 noattr)))
                                   _ptr (tvolatile (tptr tvoid)))
                                 (tptr (tvolatile (tptr tvoid))))])
                            (Stmt.Sset ___kprog_x86_bits__4
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Etempvar _t'81 (tvolatile (tptr tvoid)))
                                  tlong) tulong)))
                          (Stmt.Ssequence
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                (Expr.Etempvar ___x86_wr_shift__2 tuchar)
                                                (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                                tint)
                              s_kprog_x86_mov_reg_86
                              s_kprog_x86_mov_reg_87)
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Evar ___x86_wr_cell__2 (Ty.Tunion _x86_sim_gpr noattr))
                                _ptr (tptr tvoid))
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Etempvar ___kprog_x86_bits__4 tulong)
                                  tlong) (tptr tvoid))))))))
                  (Stmt.Sset ___x86_wr_cell_tag__2
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                      tuchar))))
              Stmt.Sbreak))
          (Stmt.Ssequence
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Ecast
                                  (Expr.Etempvar ___x86_wr_width__2 tuchar)
                                  tuchar)
                                (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                tint)
              (Stmt.Sset _t'84
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                  tuint))
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Ecast
                                    (Expr.Etempvar ___x86_wr_width__2 tuchar)
                                    tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                  tint)
                (Stmt.Ssequence
                  (Stmt.Sset _t'84
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint)
                      tuint))
                  (Stmt.Sset _t'84
                    (Expr.Ecast (Expr.Etempvar _t'84 tuint) tuint)))
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Ecast
                                      (Expr.Etempvar ___x86_wr_width__2 tuchar)
                                      tuchar)
                                    (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                    tint)
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sset _t'84
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 2) tuint)
                          tuint))
                      (Stmt.Sset _t'84
                        (Expr.Ecast (Expr.Etempvar _t'84 tuint) tuint)))
                    (Stmt.Sset _t'84
                      (Expr.Ecast (Expr.Etempvar _t'84 tuint) tuint)))
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sset _t'84
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 3) tuint)
                          tuint))
                      (Stmt.Sset _t'84
                        (Expr.Ecast (Expr.Etempvar _t'84 tuint) tuint)))
                    (Stmt.Sset _t'84
                      (Expr.Ecast (Expr.Etempvar _t'84 tuint) tuint))))))
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Etempvar _t'84 tuint)
                                (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                tint)
              (Stmt.Ssequence
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Etempvar _dst tuchar)
                                    (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                    tint)
                  (Stmt.Ssequence
                    (Stmt.Sset _t'107
                      (Expr.Efield
                        (Expr.Evar ___x86_wr_cell__2 (Ty.Tunion _x86_sim_gpr noattr))
                        _ptr (tptr tvoid)))
                    (Stmt.Ssequence
                      (Stmt.Sset _t'108
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                            (Ty.Tstruct _x86_sim_register_state noattr))
                          _native_stack_base tulong))
                      (Stmt.Sassign
                        (Expr.Efield
                          (Expr.Evar ___x86_wr_cell__2 (Ty.Tunion _x86_sim_gpr noattr))
                          _ptr (tptr tvoid))
                        (Expr.Ecast
                          (Expr.Ecast
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Etempvar _t'107 (tptr tvoid)) tlong)
                                tulong) (Expr.Etempvar _t'108 tulong) tulong)
                            tlong) (tptr tvoid)))))
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar ___x86_wr_cell_tag__2 tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Sloop
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Sset _t'105
                              (Expr.Efield
                                (Expr.Evar ___x86_wr_cell__2 (Ty.Tunion _x86_sim_gpr noattr))
                                _ptr (tptr tvoid)))
                            s_kprog_x86_mov_reg_88)
                          s_kprog_x86_mov_reg_89)
                        Stmt.Sbreak)
                      (Stmt.Sassign
                        (Expr.Efield
                          (Expr.Evar ___x86_wr_cell__2 (Ty.Tunion _x86_sim_gpr noattr))
                          _ptr (tptr tvoid))
                        (Expr.Ecast
                          (Expr.Ecast
                            (Expr.Etempvar ___x86_wr_stack_bits__5 tulong)
                            tlong) (tptr tvoid))))
                    Stmt.Sskip))
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Sset ___kprog_x86_lane__5
                      (Expr.Ecast (Expr.Etempvar ___x86_wr_next__2 tulong)
                        tushort))
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Etempvar ___x86_wr_cell_tag__2 tuchar)
                                          (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                          tint)
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Evar ___x86_wr_cell__2 (Ty.Tunion _x86_sim_gpr noattr))
                            _w tushort)
                          (Expr.Etempvar ___kprog_x86_lane__5 tushort))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Sset _t'103
                              (Expr.Efield
                                (Expr.Evar ___x86_wr_cell__2 (Ty.Tunion _x86_sim_gpr noattr))
                                _ptr (tptr tvoid)))
                            (Stmt.Sbuiltin none
                              (ExtFun.EF_vstore Chunk.Mint64)
                              [(tptr (tvolatile (tptr tvoid))),
                               (tvolatile (tptr tvoid))]
                              [(Expr.Eaddrof
                                 (Expr.Efield
                                   (Expr.Evar ___kprog_x86_partial__5 (tvolatile (Ty.Tunion __3584 noattr)))
                                   _ptr (tvolatile (tptr tvoid)))
                                 (tptr (tvolatile (tptr tvoid)))),
                               (Expr.Etempvar _t'103 (tptr tvoid))]))
                          (Stmt.Ssequence
                            (Stmt.Sbuiltin none
                              (ExtFun.EF_vstore Chunk.Mint16unsigned)
                              [(tptr (tvolatile tushort)),
                               (tvolatile tushort)]
                              [(Expr.Eaddrof
                                 (Expr.Efield
                                   (Expr.Evar ___kprog_x86_partial__5 (tvolatile (Ty.Tunion __3584 noattr)))
                                   _w (tvolatile tushort))
                                 (tptr (tvolatile tushort))),
                               (Expr.Etempvar ___kprog_x86_lane__5 tushort)])
                            (Stmt.Ssequence
                              (Stmt.Ssequence
                                s_kprog_x86_mov_reg_90
                                (Stmt.Sset ___kprog_x86_bits__5
                                  (Expr.Ecast
                                    (Expr.Ecast
                                      (Expr.Etempvar _t'82 (tvolatile (tptr tvoid)))
                                      tlong) tulong)))
                              s_kprog_x86_mov_reg_91))))
                      (Stmt.Sset ___x86_wr_cell_tag__2
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 0) tuint)
                          tuchar))))
                  Stmt.Sbreak))
              (Stmt.Ssequence
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Ecast
                                      (Expr.Etempvar ___x86_wr_width__2 tuchar)
                                      tuchar)
                                    (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                    tint)
                  (Stmt.Sset _t'83
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                      tuint))
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Ecast
                                        (Expr.Etempvar ___x86_wr_width__2 tuchar)
                                        tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Sset _t'83
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 1) tuint)
                          tuint))
                      (Stmt.Sset _t'83
                        (Expr.Ecast (Expr.Etempvar _t'83 tuint) tuint)))
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Ecast
                                          (Expr.Etempvar ___x86_wr_width__2 tuchar)
                                          tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                        tint)
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sset _t'83
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 2) tuint)
                              tuint))
                          (Stmt.Sset _t'83
                            (Expr.Ecast (Expr.Etempvar _t'83 tuint) tuint)))
                        (Stmt.Sset _t'83
                          (Expr.Ecast (Expr.Etempvar _t'83 tuint) tuint)))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sset _t'83
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 3) tuint)
                              tuint))
                          (Stmt.Sset _t'83
                            (Expr.Ecast (Expr.Etempvar _t'83 tuint) tuint)))
                        (Stmt.Sset _t'83
                          (Expr.Ecast (Expr.Etempvar _t'83 tuint) tuint))))))
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Etempvar _t'83 tuint)
                                    (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                    tint)
                  (Stmt.Ssequence
                    (Stmt.Sset ___x86_wr_next__2
                      (Expr.Ecast
                        (Expr.Ecast (Expr.Etempvar ___x86_wr_next__2 tulong)
                          tuint) tulong))
                    (Stmt.Sloop
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Evar ___x86_wr_cell__2 (Ty.Tunion _x86_sim_gpr noattr))
                            _ptr (tptr tvoid))
                          (Expr.Ecast
                            (Expr.Ecast
                              (Expr.Ecast
                                (Expr.Etempvar ___x86_wr_next__2 tulong)
                                tuint) tlong) (tptr tvoid)))
                        (Stmt.Sset ___x86_wr_cell_tag__2
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tuint)
                            tuchar)))
                      Stmt.Sbreak))
                  (Stmt.Sloop
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Efield
                          (Expr.Evar ___x86_wr_cell__2 (Ty.Tunion _x86_sim_gpr noattr))
                          _ptr (tptr tvoid))
                        (Expr.Ecast
                          (Expr.Ecast
                            (Expr.Ecast
                              (Expr.Etempvar ___x86_wr_next__2 tulong)
                              tulong) tlong) (tptr tvoid)))
                      (Stmt.Sset ___x86_wr_cell_tag__2
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 0) tuint)
                          tuchar)))
                    Stmt.Sbreak)))))))
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _dst tuchar)
                            (Expr.Econst_int (Integers.Int.repr 4) tuint)
                            tint)
          (Stmt.Ssequence
            (Stmt.Sset _t'101
              (Expr.Efield
                (Expr.Evar ___x86_wr_cell__2 (Ty.Tunion _x86_sim_gpr noattr))
                _ptr (tptr tvoid)))
            (Stmt.Ssequence
              (Stmt.Sset _t'102
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                    (Ty.Tstruct _x86_sim_register_state noattr))
                  _native_stack_base tulong))
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Evar ___x86_wr_cell__2 (Ty.Tunion _x86_sim_gpr noattr))
                  _ptr (tptr tvoid))
                (Expr.Ecast
                  (Expr.Ecast
                    (Expr.Ebinop Binop.Osub
                      (Expr.Ecast
                        (Expr.Ecast (Expr.Etempvar _t'101 (tptr tvoid))
                          tlong) tulong) (Expr.Etempvar _t'102 tulong)
                      tulong) tlong) (tptr tvoid)))))
          Stmt.Sskip)
        (Stmt.Ssequence
          (Stmt.Sset ___x86_wr_next_ptr__6
            (Expr.Efield
              (Expr.Evar ___x86_wr_cell__2 (Ty.Tunion _x86_sim_gpr noattr))
              _ptr (tptr tvoid)))
          (Stmt.Ssequence
            (Stmt.Sset ___x86_wr_next_tag__6
              (Expr.Ecast (Expr.Etempvar ___x86_wr_cell_tag__2 tuchar)
                tuchar))
            (Stmt.Ssequence
              (Stmt.Sloop
                (Stmt.Ssequence
                  (Stmt.Sset ___x86_store_reg__6
                    (Expr.Ecast (Expr.Etempvar _dst tuchar) tulong))
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                      (Expr.Etempvar ___x86_store_reg__6 tulong)
                                      (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Efield
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Efield
                                    (Expr.Ederef
                                      (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                      (Ty.Tstruct _x86_sim_register_state noattr))
                                    (Positive.ofNat 18727075383868559167)
                                    (Ty.Tunion __3115 noattr)) _gpr_cells
                                  (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                                (Expr.Ecast
                                  (Expr.Etempvar ___x86_store_reg__6 tulong)
                                  tuchar)
                                (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                              (Ty.Tstruct _x86_sim_gpr_cell noattr)) _value
                            (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                          (tptr tvoid))
                        (Expr.Etempvar ___x86_wr_next_ptr__6 (tptr tvoid)))
                      (Stmt.Sassign
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                    (Ty.Tstruct _x86_sim_register_state noattr))
                                  (Positive.ofNat 18727075383868559167)
                                  (Ty.Tunion __3115 noattr)) _gpr_cells
                                (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                              (Expr.Ecast
                                (Expr.Etempvar ___x86_store_reg__6 tulong)
                                tuchar)
                              (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                            (Ty.Tstruct _x86_sim_gpr_cell noattr)) _tag
                          tuchar)
                        (Expr.Etempvar ___x86_wr_next_tag__6 tuchar)))
                    Stmt.Sskip))
                Stmt.Sbreak)
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar _dst tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                  tint)
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Sset ___x86_release_old__6
                      (Expr.Etempvar ___x86_write_old_sp__6 tlong))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sset _t'100
                          (Expr.Efield
                            (Expr.Efield
                              (Expr.Efield
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                    (Ty.Tstruct _x86_sim_register_state noattr))
                                  (Positive.ofNat 18727075383868559167)
                                  (Ty.Tunion __3115 noattr))
                                (Positive.ofNat 18727075383868559167)
                                (Ty.Tstruct __3116 noattr)) _rsp
                              (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                            (tptr tvoid)))
                        (Stmt.Sset ___x86_release_new__6
                          (Expr.Ecast
                            (Expr.Ecast (Expr.Etempvar _t'100 (tptr tvoid))
                              tlong) tlong)))
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Ogt
                                          (Expr.Etempvar ___x86_release_new__6 tlong)
                                          (Expr.Etempvar ___x86_release_old__6 tlong)
                                          tint)
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Sset ___x86_release_i__6
                              (Expr.Econst_int (Integers.Int.repr 0) tint))
                            (Stmt.Sloop
                              s_kprog_x86_mov_reg_92
                              s_kprog_x86_mov_reg_93))
                          (Stmt.Sloop
                            (Stmt.Ssequence
                              s_kprog_x86_mov_reg_94
                              s_kprog_x86_mov_reg_95)
                            Stmt.Sbreak))
                        Stmt.Sskip)))
                  Stmt.Sbreak)
                Stmt.Sskip))))))))

def f_kprog_x86_mov_reg : Function := {
  fn_return := tvoid,
  fn_callconv := cc_default,
  fn_params := [(_state, (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
                (_arena, (tptr (Ty.Tstruct _kprog_x86_arena noattr))),
                (_facts, (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr))),
                (_capacity, tuint), (_dst, tuchar), (_src, tuchar),
                (_flags, tuchar), (_aux, tuint)],
  fn_vars := [(___x86_wr_cell, (Ty.Tunion _x86_sim_gpr noattr)),
              (___kprog_x86_partial, (tvolatile (Ty.Tunion __3461 noattr))),
              (___kprog_x86_partial__1,
               (tvolatile (Ty.Tunion __3467 noattr))),
              (___x86_wr_cell__1, (Ty.Tunion _x86_sim_gpr noattr)),
              (___kprog_x86_partial__2,
               (tvolatile (Ty.Tunion __3527 noattr))),
              (___kprog_x86_partial__3,
               (tvolatile (Ty.Tunion __3533 noattr))),
              (___x86_wr_cell__2, (Ty.Tunion _x86_sim_gpr noattr)),
              (___kprog_x86_partial__4,
               (tvolatile (Ty.Tunion __3578 noattr))),
              (___kprog_x86_partial__5,
               (tvolatile (Ty.Tunion __3584 noattr)))],
  fn_temps := [(___x86_state,
                (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
               (___x86_l_width, tuchar), (___x86_mov_stack_offset, tlong),
               (___x86_alias_delta, tulong), (___x86_write_old_sp, tlong),
               (___x86_wr_next_ptr, (tptr tvoid)),
               (___x86_wr_next_tag, tuchar), (___x86_store_reg, tulong),
               (___x86_release_old, tlong), (___x86_release_new, tlong),
               (___x86_release_i, tuint), (___x86_release_off, tlong),
               (___x86_release_lane, tuint), (___x86_sv_sp, tlong),
               (___x86_sv_i, tuint), (___x86_mov_numeric, tulong),
               (___x86_rd_reg, tuchar), (___x86_rd_raw_width, tuchar),
               (___x86_rd_width, tuchar), (___x86_rd_shift, tuchar),
               (___x86_rd_ptr, (tptr tvoid)), (___x86_rd_value, tulong),
               (___x86_rd_tag, tuchar), (___x86_tag_reg, tulong),
               (___x86_stack_delta, tulong), (___x86_write_old_sp__1, tlong),
               (___x86_wr_raw_width, tuchar), (___x86_wr_width, tuchar),
               (___x86_wr_shift, tuchar), (___x86_wr_next, tulong),
               (___x86_wr_cell_tag, tuchar), (___x86_tag_reg__1, tulong),
               (___x86_wr_stack_bits, tulong),
               (___x86_stack_delta__1, tulong), (___kprog_x86_lane, tuchar),
               (___kprog_x86_bits, tulong),
               (___x86_wr_stack_bits__1, tulong),
               (___x86_stack_delta__2, tulong),
               (___kprog_x86_lane__1, tushort),
               (___kprog_x86_bits__1, tulong),
               (___x86_wr_next_ptr__1, (tptr tvoid)),
               (___x86_wr_next_tag__1, tuchar),
               (___x86_store_reg__1, tulong), (___x86_release_old__1, tlong),
               (___x86_release_new__1, tlong), (___x86_release_i__1, tuint),
               (___x86_release_off__1, tlong),
               (___x86_release_lane__1, tuint), (___x86_sv_sp__1, tlong),
               (___x86_sv_i__1, tuint), (___x86_write_old_sp__2, tlong),
               (___x86_wr_next_ptr__2, (tptr tvoid)),
               (___x86_wr_next_tag__2, tuchar),
               (___x86_store_reg__2, tulong), (___x86_release_old__2, tlong),
               (___x86_release_new__2, tlong), (___x86_release_i__2, tuint),
               (___x86_release_off__2, tlong),
               (___x86_release_lane__2, tuint), (___x86_sv_sp__2, tlong),
               (___x86_sv_i__2, tuint), (___x86_mov_source_tag, tuchar),
               (___x86_tag_reg__2, tulong),
               (___x86_mov_stack_offset__1, tlong),
               (___x86_alias_delta__1, tulong),
               (___x86_write_old_sp__3, tlong),
               (___x86_wr_next_ptr__3, (tptr tvoid)),
               (___x86_wr_next_tag__3, tuchar),
               (___x86_store_reg__3, tulong), (___x86_release_old__3, tlong),
               (___x86_release_new__3, tlong), (___x86_release_i__3, tuint),
               (___x86_release_off__3, tlong),
               (___x86_release_lane__3, tuint), (___x86_sv_sp__3, tlong),
               (___x86_sv_i__3, tuint), (___x86_mov_numeric__1, tulong),
               (___x86_rd_reg__1, tuchar), (___x86_rd_raw_width__1, tuchar),
               (___x86_rd_width__1, tuchar), (___x86_rd_shift__1, tuchar),
               (___x86_rd_ptr__1, (tptr tvoid)),
               (___x86_rd_value__1, tulong), (___x86_rd_tag__1, tuchar),
               (___x86_tag_reg__3, tulong), (___x86_stack_delta__3, tulong),
               (___x86_write_old_sp__4, tlong),
               (___x86_wr_raw_width__1, tuchar),
               (___x86_wr_width__1, tuchar), (___x86_wr_shift__1, tuchar),
               (___x86_wr_next__1, tulong), (___x86_wr_cell_tag__1, tuchar),
               (___x86_tag_reg__4, tulong),
               (___x86_wr_stack_bits__2, tulong),
               (___x86_stack_delta__4, tulong),
               (___kprog_x86_lane__2, tuchar),
               (___kprog_x86_bits__2, tulong),
               (___x86_wr_stack_bits__3, tulong),
               (___x86_stack_delta__5, tulong),
               (___kprog_x86_lane__3, tushort),
               (___kprog_x86_bits__3, tulong),
               (___x86_wr_next_ptr__4, (tptr tvoid)),
               (___x86_wr_next_tag__4, tuchar),
               (___x86_store_reg__4, tulong), (___x86_release_old__4, tlong),
               (___x86_release_new__4, tlong), (___x86_release_i__4, tuint),
               (___x86_release_off__4, tlong),
               (___x86_release_lane__4, tuint), (___x86_sv_sp__4, tlong),
               (___x86_sv_i__4, tuint), (___x86_write_old_sp__5, tlong),
               (___x86_wr_next_ptr__5, (tptr tvoid)),
               (___x86_wr_next_tag__5, tuchar),
               (___x86_store_reg__5, tulong), (___x86_release_old__5, tlong),
               (___x86_release_new__5, tlong), (___x86_release_i__5, tuint),
               (___x86_release_off__5, tlong),
               (___x86_release_lane__5, tuint), (___x86_sv_sp__5, tlong),
               (___x86_sv_i__5, tuint), (___x86_l_value, tulong),
               (___x86_rd_reg__2, tuchar), (___x86_rd_raw_width__2, tuchar),
               (___x86_rd_width__2, tuchar), (___x86_rd_shift__2, tuchar),
               (___x86_rd_ptr__2, (tptr tvoid)),
               (___x86_rd_value__2, tulong), (___x86_rd_tag__2, tuchar),
               (___x86_tag_reg__5, tulong), (___x86_stack_delta__6, tulong),
               (___x86_write_old_sp__6, tlong),
               (___x86_wr_raw_width__2, tuchar),
               (___x86_wr_width__2, tuchar), (___x86_wr_shift__2, tuchar),
               (___x86_wr_next__2, tulong), (___x86_wr_cell_tag__2, tuchar),
               (___x86_tag_reg__6, tulong),
               (___x86_wr_stack_bits__4, tulong),
               (___x86_stack_delta__7, tulong),
               (___kprog_x86_lane__4, tuchar),
               (___kprog_x86_bits__4, tulong),
               (___x86_wr_stack_bits__5, tulong),
               (___x86_stack_delta__8, tulong),
               (___kprog_x86_lane__5, tushort),
               (___kprog_x86_bits__5, tulong),
               (___x86_wr_next_ptr__6, (tptr tvoid)),
               (___x86_wr_next_tag__6, tuchar),
               (___x86_store_reg__6, tulong), (___x86_release_old__6, tlong),
               (___x86_release_new__6, tlong), (___x86_release_i__6, tuint),
               (___x86_release_off__6, tlong),
               (___x86_release_lane__6, tuint), (___x86_sv_sp__6, tlong),
               (___x86_sv_i__6, tuint), (_t'94, tuint), (_t'93, tuint),
               (_t'92, tuint), (_t'91, tint), (_t'90, tint), (_t'89, tint),
               (_t'88, tint), (_t'87, tulong), (_t'86, tulong),
               (_t'85, tuint), (_t'84, tuint), (_t'83, tuint),
               (_t'82, (tvolatile (tptr tvoid))),
               (_t'81, (tvolatile (tptr tvoid))), (_t'80, tuint),
               (_t'79, (tptr tvoid)), (_t'78, tuchar), (_t'77, tulong),
               (_t'76, tuint), (_t'75, tuint), (_t'74, (tptr tvoid)),
               (_t'73, tuchar), (_t'72, tint), (_t'71, tuint), (_t'70, tint),
               (_t'69, tint), (_t'68, tint), (_t'67, tint), (_t'66, tulong),
               (_t'65, tulong), (_t'64, (tptr tvoid)), (_t'63, tint),
               (_t'62, tint), (_t'61, tint), (_t'60, tint), (_t'59, tulong),
               (_t'58, tulong), (_t'57, tuint), (_t'56, tuint),
               (_t'55, tuint), (_t'54, (tvolatile (tptr tvoid))),
               (_t'53, (tvolatile (tptr tvoid))), (_t'52, tuint),
               (_t'51, (tptr tvoid)), (_t'50, tuchar), (_t'49, tulong),
               (_t'48, tuint), (_t'47, tuint), (_t'46, (tptr tvoid)),
               (_t'45, tuchar), (_t'44, tint), (_t'43, tint), (_t'42, tint),
               (_t'41, tint), (_t'40, tulong), (_t'39, tulong),
               (_t'38, (tptr tvoid)), (_t'37, tuint), (_t'36, tint),
               (_t'35, tuint), (_t'34, tint), (_t'33, tint), (_t'32, tint),
               (_t'31, tint), (_t'30, tulong), (_t'29, tulong),
               (_t'28, (tptr tvoid)), (_t'27, tint), (_t'26, tint),
               (_t'25, tint), (_t'24, tint), (_t'23, tulong),
               (_t'22, tulong), (_t'21, tuint), (_t'20, tuint),
               (_t'19, tuint), (_t'18, (tvolatile (tptr tvoid))),
               (_t'17, (tvolatile (tptr tvoid))), (_t'16, tuint),
               (_t'15, (tptr tvoid)), (_t'14, tuchar), (_t'13, tulong),
               (_t'12, tuint), (_t'11, tuint), (_t'10, (tptr tvoid)),
               (_t'9, tuchar), (_t'8, tint), (_t'7, tint), (_t'6, tint),
               (_t'5, tint), (_t'4, tulong), (_t'3, tulong),
               (_t'2, (tptr tvoid)), (_t'1, tuchar), (_t'215, (tptr tvoid)),
               (_t'214, (tptr (tvolatile tuchar))),
               (_t'213, (tptr (tvolatile tuchar))), (_t'212, (tptr tvoid)),
               (_t'211, (tptr tvoid)), (_t'210, (tptr (tvolatile tulong))),
               (_t'209, (tptr (tvolatile tuchar))), (_t'208, (tptr tvoid)),
               (_t'207, (tptr tuchar)), (_t'206, (tptr (tptr tvoid))),
               (_t'205, (tptr tvoid)), (_t'204, tulong), (_t'203, tuchar),
               (_t'202, (tptr (tvolatile tuchar))), (_t'201, tulong),
               (_t'200, (tptr tvoid)), (_t'199, (tptr tvoid)),
               (_t'198, tuchar), (_t'197, tulong), (_t'196, (tptr tvoid)),
               (_t'195, (tptr (tvolatile tuchar))), (_t'194, (tptr tvoid)),
               (_t'193, tulong), (_t'192, (tptr tvoid)), (_t'191, tulong),
               (_t'190, (tptr tvoid)), (_t'189, (tptr (tvolatile tuchar))),
               (_t'188, (tptr tvoid)), (_t'187, tulong),
               (_t'186, (tptr tvoid)), (_t'185, tulong),
               (_t'184, (tptr tvoid)), (_t'183, (tptr tvoid)),
               (_t'182, (tptr (tvolatile tulong))),
               (_t'181, (tptr (tvolatile tuchar))), (_t'180, (tptr tvoid)),
               (_t'179, (tptr tuchar)), (_t'178, (tptr (tptr tvoid))),
               (_t'177, (tptr tvoid)), (_t'176, (tptr tvoid)),
               (_t'175, (tptr (tvolatile tuchar))), (_t'174, (tptr tvoid)),
               (_t'173, (tptr (tvolatile tulong))),
               (_t'172, (tptr (tvolatile tuchar))), (_t'171, (tptr tvoid)),
               (_t'170, (tptr tuchar)), (_t'169, (tptr (tptr tvoid))),
               (_t'168, tuchar), (_t'167, (tptr tvoid)),
               (_t'166, (tptr (tvolatile tuchar))), (_t'165, (tptr tvoid)),
               (_t'164, (tptr tvoid)), (_t'163, (tptr (tvolatile tulong))),
               (_t'162, (tptr (tvolatile tuchar))), (_t'161, (tptr tvoid)),
               (_t'160, (tptr tuchar)), (_t'159, (tptr (tptr tvoid))),
               (_t'158, (tptr tvoid)), (_t'157, tulong), (_t'156, tuchar),
               (_t'155, (tptr (tvolatile tuchar))), (_t'154, tulong),
               (_t'153, (tptr tvoid)), (_t'152, (tptr tvoid)),
               (_t'151, tuchar), (_t'150, tulong), (_t'149, (tptr tvoid)),
               (_t'148, (tptr (tvolatile tuchar))), (_t'147, (tptr tvoid)),
               (_t'146, tulong), (_t'145, (tptr tvoid)), (_t'144, tulong),
               (_t'143, (tptr tvoid)), (_t'142, (tptr (tvolatile tuchar))),
               (_t'141, (tptr tvoid)), (_t'140, tulong),
               (_t'139, (tptr tvoid)), (_t'138, tulong),
               (_t'137, (tptr tvoid)), (_t'136, (tptr tvoid)),
               (_t'135, (tptr (tvolatile tulong))),
               (_t'134, (tptr (tvolatile tuchar))), (_t'133, (tptr tvoid)),
               (_t'132, (tptr tuchar)), (_t'131, (tptr (tptr tvoid))),
               (_t'130, (tptr tvoid)), (_t'129, (tptr tvoid)),
               (_t'128, (tptr tvoid)), (_t'127, (tptr (tvolatile tulong))),
               (_t'126, (tptr (tvolatile tuchar))), (_t'125, (tptr tvoid)),
               (_t'124, (tptr tuchar)), (_t'123, (tptr (tptr tvoid))),
               (_t'122, (tptr tvoid)), (_t'121, tulong), (_t'120, tuchar),
               (_t'119, (tptr (tvolatile tuchar))), (_t'118, tulong),
               (_t'117, (tptr tvoid)), (_t'116, (tptr tvoid)),
               (_t'115, tuchar), (_t'114, tulong), (_t'113, (tptr tvoid)),
               (_t'112, (tptr (tvolatile tuchar))), (_t'111, (tptr tvoid)),
               (_t'110, tulong), (_t'109, (tptr tvoid)), (_t'108, tulong),
               (_t'107, (tptr tvoid)), (_t'106, (tptr (tvolatile tuchar))),
               (_t'105, (tptr tvoid)), (_t'104, tulong),
               (_t'103, (tptr tvoid)), (_t'102, tulong),
               (_t'101, (tptr tvoid)), (_t'100, (tptr tvoid)),
               (_t'99, (tptr (tvolatile tulong))),
               (_t'98, (tptr (tvolatile tuchar))), (_t'97, (tptr tvoid)),
               (_t'96, (tptr tuchar)), (_t'95, (tptr (tptr tvoid)))],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_state
    (Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))))
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Scall (some _t'1)
          (Expr.Evar _x86_width_effective (Ty.Tfunction [tuchar] tuchar
                                            cc_default))
          [(Expr.Etempvar _flags tuchar)])
        (Stmt.Sset ___x86_l_width
          (Expr.Ecast (Expr.Etempvar _t'1 tuchar) tuchar)))
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Ecast (Expr.Etempvar ___x86_l_width tuchar)
                              tuchar)
                            (Expr.Econst_int (Integers.Int.repr 8) tuint)
                            tint)
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Ecast (Expr.Etempvar _src tuchar) tuchar)
                              (Expr.Econst_int (Integers.Int.repr 4) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Sset _t'94
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                  tuint))
              (Stmt.Sset _t'94
                (Expr.Ecast (Expr.Etempvar _t'94 tuint) tuint)))
            (Stmt.Ssequence
              (Stmt.Sset _t'94
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint)
                  tuint))
              (Stmt.Sset _t'94
                (Expr.Ecast (Expr.Etempvar _t'94 tuint) tuint))))
          (Stmt.Sset _t'94
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint) tuint)))
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _t'94 tuint)
                            (Expr.Econst_int (Integers.Int.repr 0) tuint)
                            tint)
          (Stmt.Sloop
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar _dst tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                  tint)
                (Stmt.Sset _t'36
                  (Expr.Ecast
                    (Expr.Ebinop Binop.Oeq
                      (Expr.Econst_int (Integers.Int.repr 4) tuint)
                      (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
                    tbool))
                (Stmt.Sset _t'36
                  (Expr.Econst_int (Integers.Int.repr 0) tint)))
              (Stmt.Sifthenelse (Expr.Etempvar _t'36 tint)
                (Stmt.Ssequence
                  (Stmt.Sloop
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                            (Expr.Ecast
                                              (Expr.Etempvar _src tuchar)
                                              tulong)
                                            (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                            tint)
                          (Stmt.Ssequence
                            (Stmt.Sset _t'215
                              (Expr.Efield
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Efield
                                        (Expr.Efield
                                          (Expr.Ederef
                                            (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                            (Ty.Tstruct _x86_sim_register_state noattr))
                                          (Positive.ofNat 18727075383868559167)
                                          (Ty.Tunion __3115 noattr))
                                        _gpr_cells
                                        (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                                      (Expr.Ecast (Expr.Etempvar _src tuchar)
                                        tuchar)
                                      (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                                    (Ty.Tstruct _x86_sim_gpr_cell noattr))
                                  _value (Ty.Tunion _x86_sim_gpr noattr))
                                _ptr (tptr tvoid)))
                            (Stmt.Sset _t'2
                              (Expr.Ecast (Expr.Etempvar _t'215 (tptr tvoid))
                                (tptr tvoid))))
                          (Stmt.Sset _t'2
                            (Expr.Ecast
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 0) tint)
                                (tptr tvoid)) (tptr tvoid))))
                        (Stmt.Ssequence
                          (Stmt.Sset _t'213
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                                (Ty.Tstruct _kprog_x86_arena noattr)) _b
                              (tptr (tvolatile tuchar))))
                          (Stmt.Ssequence
                            (Stmt.Sset _t'214
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                                  (Ty.Tstruct _kprog_x86_arena noattr)) _b
                                (tptr (tvolatile tuchar))))
                            (Stmt.Sset ___x86_alias_delta
                              (Expr.Ebinop Binop.Osub
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Ecast
                                      (Expr.Ecast
                                        (Expr.Ecast
                                          (Expr.Ebinop Binop.Oadd
                                            (Expr.Ecast
                                              (Expr.Ecast
                                                (Expr.Ebinop Binop.Oadd
                                                  (Expr.Etempvar _t'213 (tptr (tvolatile tuchar)))
                                                  (Expr.Econst_int (Integers.Int.repr 0) tint)
                                                  (tptr (tvolatile tuchar)))
                                                tulong) tulong)
                                            (Expr.Ecast
                                              (Expr.Ebinop Binop.Oadd
                                                (Expr.Ecast
                                                  (Expr.Ecast
                                                    (Expr.Ecast
                                                      (Expr.Etempvar _t'2 (tptr tvoid))
                                                      tlong) tlong) tulong)
                                                (Expr.Ecast
                                                  (Expr.Etempvar _capacity tuint)
                                                  tulong) tulong) tulong)
                                            tulong) tulong) (tptr tuchar))
                                      (tptr tvoid)) tlong) tulong)
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Ecast
                                      (Expr.Ecast
                                        (Expr.Ecast
                                          (Expr.Ebinop Binop.Oadd
                                            (Expr.Ecast
                                              (Expr.Ecast
                                                (Expr.Ebinop Binop.Oadd
                                                  (Expr.Etempvar _t'214 (tptr (tvolatile tuchar)))
                                                  (Expr.Econst_int (Integers.Int.repr 0) tint)
                                                  (tptr (tvolatile tuchar)))
                                                tulong) tulong)
                                            (Expr.Ecast
                                              (Expr.Ebinop Binop.Oadd
                                                (Expr.Ecast
                                                  (Expr.Econst_int (Integers.Int.repr 0) tint)
                                                  tulong)
                                                (Expr.Ecast
                                                  (Expr.Etempvar _capacity tuint)
                                                  tulong) tulong) tulong)
                                            tulong) tulong) (tptr tuchar))
                                      (tptr tvoid)) tlong) tulong) tulong)))))
                      (Stmt.Sset ___x86_mov_stack_offset
                        (Expr.Ecast (Expr.Etempvar ___x86_alias_delta tulong)
                          tlong)))
                    Stmt.Sbreak)
                  (Stmt.Sloop
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sset _t'212
                          (Expr.Efield
                            (Expr.Efield
                              (Expr.Efield
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                    (Ty.Tstruct _x86_sim_register_state noattr))
                                  (Positive.ofNat 18727075383868559167)
                                  (Ty.Tunion __3115 noattr))
                                (Positive.ofNat 18727075383868559167)
                                (Ty.Tstruct __3116 noattr)) _rsp
                              (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                            (tptr tvoid)))
                        (Stmt.Sset ___x86_write_old_sp
                          (Expr.Ecast
                            (Expr.Ecast (Expr.Etempvar _t'212 (tptr tvoid))
                              tlong) tlong)))
                      (Stmt.Ssequence
                        (Stmt.Sset ___x86_wr_next_ptr
                          (Expr.Ecast
                            (Expr.Ecast
                              (Expr.Ecast
                                (Expr.Etempvar ___x86_mov_stack_offset tlong)
                                tlong) (tptr tvoid)) (tptr tvoid)))
                        (Stmt.Ssequence
                          (Stmt.Sset ___x86_wr_next_tag
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 0) tuint)
                              tuchar))
                          (Stmt.Ssequence
                            (Stmt.Sloop
                              (Stmt.Ssequence
                                s_kprog_x86_mov_reg_0
                                s_kprog_x86_mov_reg_1)
                              Stmt.Sbreak)
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                (Expr.Etempvar _dst tuchar)
                                                (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                                tint)
                              (Stmt.Sloop
                                s_kprog_x86_mov_reg_6
                                s_kprog_x86_mov_reg_7)
                              Stmt.Sskip)))))
                    Stmt.Sbreak))
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Ecast
                                        (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                        tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                      tint)
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Ecast
                                          (Expr.Etempvar _dst tuchar) tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                        tint)
                      (Stmt.Ssequence
                        (Stmt.Sset _t'35
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tuint)
                            tuint))
                        (Stmt.Sset _t'35
                          (Expr.Ecast (Expr.Etempvar _t'35 tuint) tuint)))
                      (Stmt.Ssequence
                        (Stmt.Sset _t'35
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 1) tuint)
                            tuint))
                        (Stmt.Sset _t'35
                          (Expr.Ecast (Expr.Etempvar _t'35 tuint) tuint))))
                    (Stmt.Sset _t'35
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 2) tuint) tuint)))
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar _t'35 tuint)
                                      (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Sloop
                        (Stmt.Ssequence
                          (Stmt.Sset ___x86_rd_reg
                            (Expr.Ecast (Expr.Etempvar _src tuchar) tuchar))
                          (Stmt.Ssequence
                            (Stmt.Sset ___x86_rd_raw_width
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                tuchar))
                            (Stmt.Ssequence
                              (Stmt.Ssequence
                                s_kprog_x86_mov_reg_8
                                (Stmt.Sset ___x86_rd_width
                                  (Expr.Ecast (Expr.Etempvar _t'9 tuchar)
                                    tuchar)))
                              (Stmt.Ssequence
                                s_kprog_x86_mov_reg_9
                                s_kprog_x86_mov_reg_10))))
                        Stmt.Sbreak)
                      (Stmt.Sloop
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Sset _t'200
                              (Expr.Efield
                                (Expr.Efield
                                  (Expr.Efield
                                    (Expr.Efield
                                      (Expr.Ederef
                                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                        (Ty.Tstruct _x86_sim_register_state noattr))
                                      (Positive.ofNat 18727075383868559167)
                                      (Ty.Tunion __3115 noattr))
                                    (Positive.ofNat 18727075383868559167)
                                    (Ty.Tstruct __3116 noattr)) _rsp
                                  (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                                (tptr tvoid)))
                            (Stmt.Sset ___x86_write_old_sp__1
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Etempvar _t'200 (tptr tvoid)) tlong)
                                tlong)))
                          (Stmt.Ssequence
                            (Stmt.Sset ___x86_wr_raw_width
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                tuchar))
                            (Stmt.Ssequence
                              (Stmt.Ssequence
                                s_kprog_x86_mov_reg_11
                                (Stmt.Sset ___x86_wr_width
                                  (Expr.Ecast (Expr.Etempvar _t'14 tuchar)
                                    tuchar)))
                              (Stmt.Ssequence
                                s_kprog_x86_mov_reg_12
                                s_kprog_x86_mov_reg_26))))
                        Stmt.Sbreak))
                    (Stmt.Sloop
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sset _t'177
                            (Expr.Efield
                              (Expr.Efield
                                (Expr.Efield
                                  (Expr.Efield
                                    (Expr.Ederef
                                      (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                      (Ty.Tstruct _x86_sim_register_state noattr))
                                    (Positive.ofNat 18727075383868559167)
                                    (Ty.Tunion __3115 noattr))
                                  (Positive.ofNat 18727075383868559167)
                                  (Ty.Tstruct __3116 noattr)) _rsp
                                (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                              (tptr tvoid)))
                          (Stmt.Sset ___x86_write_old_sp__2
                            (Expr.Ecast
                              (Expr.Ecast (Expr.Etempvar _t'177 (tptr tvoid))
                                tlong) tlong)))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                                (Expr.Ecast
                                                  (Expr.Etempvar _src tuchar)
                                                  tulong)
                                                (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                                tint)
                              s_kprog_x86_mov_reg_27
                              s_kprog_x86_mov_reg_28)
                            (Stmt.Ssequence
                              (Stmt.Sset _t'175
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                                    (Ty.Tstruct _kprog_x86_arena noattr)) _b
                                  (tptr (tvolatile tuchar))))
                              (Stmt.Sset ___x86_wr_next_ptr__2
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Ecast
                                      (Expr.Ecast
                                        (Expr.Ebinop Binop.Oadd
                                          (Expr.Ecast
                                            (Expr.Ecast
                                              (Expr.Ebinop Binop.Oadd
                                                (Expr.Etempvar _t'175 (tptr (tvolatile tuchar)))
                                                (Expr.Econst_int (Integers.Int.repr 0) tint)
                                                (tptr (tvolatile tuchar)))
                                              tulong) tulong)
                                          (Expr.Ecast
                                            (Expr.Ebinop Binop.Oadd
                                              (Expr.Ecast
                                                (Expr.Ecast
                                                  (Expr.Ecast
                                                    (Expr.Etempvar _t'28 (tptr tvoid))
                                                    tlong) tlong) tulong)
                                              (Expr.Ecast
                                                (Expr.Etempvar _capacity tuint)
                                                tulong) tulong) tulong)
                                          tulong) tulong) (tptr tuchar))
                                    (tptr tvoid)) (tptr tvoid)))))
                          (Stmt.Ssequence
                            (Stmt.Sset ___x86_wr_next_tag__2
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                tuchar))
                            (Stmt.Ssequence
                              (Stmt.Sloop
                                s_kprog_x86_mov_reg_29
                                s_kprog_x86_mov_reg_30)
                              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                  (Expr.Etempvar _dst tuchar)
                                                  (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                                  tint)
                                (Stmt.Sloop
                                  s_kprog_x86_mov_reg_35
                                  s_kprog_x86_mov_reg_36)
                                Stmt.Sskip)))))
                      Stmt.Sbreak)))))
            Stmt.Sbreak)
          (Stmt.Ssequence
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Ecast
                                  (Expr.Etempvar ___x86_l_width tuchar)
                                  tuchar)
                                (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                tint)
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Ecast (Expr.Etempvar _src tuchar)
                                    tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                  tint)
                (Stmt.Ssequence
                  (Stmt.Sset _t'93
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                      tuint))
                  (Stmt.Sset _t'93
                    (Expr.Ecast (Expr.Etempvar _t'93 tuint) tuint)))
                (Stmt.Ssequence
                  (Stmt.Sset _t'93
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint)
                      tuint))
                  (Stmt.Sset _t'93
                    (Expr.Ecast (Expr.Etempvar _t'93 tuint) tuint))))
              (Stmt.Sset _t'93
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint)
                  tuint)))
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Etempvar _t'93 tuint)
                                (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                tint)
              (Stmt.Ssequence
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Sset ___x86_tag_reg__2
                      (Expr.Ecast (Expr.Etempvar _src tuchar) tulong))
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                          (Expr.Etempvar ___x86_tag_reg__2 tulong)
                                          (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                          tint)
                        (Stmt.Ssequence
                          (Stmt.Sset _t'168
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Efield
                                      (Expr.Ederef
                                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                        (Ty.Tstruct _x86_sim_register_state noattr))
                                      (Positive.ofNat 18727075383868559167)
                                      (Ty.Tunion __3115 noattr)) _gpr_cells
                                    (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                                  (Expr.Ecast
                                    (Expr.Etempvar ___x86_tag_reg__2 tulong)
                                    tuchar)
                                  (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                                (Ty.Tstruct _x86_sim_gpr_cell noattr)) _tag
                              tuchar))
                          (Stmt.Sset _t'37
                            (Expr.Ecast (Expr.Etempvar _t'168 tuchar) tuint)))
                        (Stmt.Sset _t'37
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tuint)
                            tuint)))
                      (Stmt.Sset ___x86_mov_source_tag
                        (Expr.Ecast (Expr.Etempvar _t'37 tuint) tuchar))))
                  Stmt.Sbreak)
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Etempvar _dst tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                        tint)
                      (Stmt.Sset _t'72
                        (Expr.Ecast
                          (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar ___x86_mov_source_tag tuchar)
                            (Expr.Econst_int (Integers.Int.repr 4) tuint)
                            tint) tbool))
                      (Stmt.Sset _t'72
                        (Expr.Econst_int (Integers.Int.repr 0) tint)))
                    (Stmt.Sifthenelse (Expr.Etempvar _t'72 tint)
                      (Stmt.Ssequence
                        (Stmt.Sloop
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                                  (Expr.Ecast
                                                    (Expr.Etempvar _src tuchar)
                                                    tulong)
                                                  (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                                  tint)
                                s_kprog_x86_mov_reg_37
                                s_kprog_x86_mov_reg_38)
                              (Stmt.Ssequence
                                (Stmt.Sset _t'166
                                  (Expr.Efield
                                    (Expr.Ederef
                                      (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                                      (Ty.Tstruct _kprog_x86_arena noattr))
                                    _b (tptr (tvolatile tuchar))))
                                (Stmt.Sset ___x86_alias_delta__1
                                  (Expr.Ebinop Binop.Osub
                                    (Expr.Ecast
                                      (Expr.Ecast
                                        (Expr.Etempvar _t'38 (tptr tvoid))
                                        tlong) tulong)
                                    (Expr.Ecast
                                      (Expr.Ecast
                                        (Expr.Ecast
                                          (Expr.Ecast
                                            (Expr.Ecast
                                              (Expr.Ebinop Binop.Oadd
                                                (Expr.Ecast
                                                  (Expr.Ecast
                                                    (Expr.Ebinop Binop.Oadd
                                                      (Expr.Etempvar _t'166 (tptr (tvolatile tuchar)))
                                                      (Expr.Econst_int (Integers.Int.repr 0) tint)
                                                      (tptr (tvolatile tuchar)))
                                                    tulong) tulong)
                                                (Expr.Ecast
                                                  (Expr.Ebinop Binop.Oadd
                                                    (Expr.Ecast
                                                      (Expr.Econst_int (Integers.Int.repr 0) tint)
                                                      tulong)
                                                    (Expr.Ecast
                                                      (Expr.Etempvar _capacity tuint)
                                                      tulong) tulong) tulong)
                                                tulong) tulong)
                                            (tptr tuchar)) (tptr tvoid))
                                        tlong) tulong) tulong))))
                            (Stmt.Sset ___x86_mov_stack_offset__1
                              (Expr.Ecast
                                (Expr.Etempvar ___x86_alias_delta__1 tulong)
                                tlong)))
                          Stmt.Sbreak)
                        (Stmt.Sloop
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Sset _t'165
                                (Expr.Efield
                                  (Expr.Efield
                                    (Expr.Efield
                                      (Expr.Efield
                                        (Expr.Ederef
                                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                          (Ty.Tstruct _x86_sim_register_state noattr))
                                        (Positive.ofNat 18727075383868559167)
                                        (Ty.Tunion __3115 noattr))
                                      (Positive.ofNat 18727075383868559167)
                                      (Ty.Tstruct __3116 noattr)) _rsp
                                    (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                                  (tptr tvoid)))
                              (Stmt.Sset ___x86_write_old_sp__3
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Etempvar _t'165 (tptr tvoid))
                                    tlong) tlong)))
                            (Stmt.Ssequence
                              (Stmt.Sset ___x86_wr_next_ptr__3
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Ecast
                                      (Expr.Etempvar ___x86_mov_stack_offset__1 tlong)
                                      tlong) (tptr tvoid)) (tptr tvoid)))
                              (Stmt.Ssequence
                                s_kprog_x86_mov_reg_39
                                s_kprog_x86_mov_reg_45)))
                          Stmt.Sbreak))
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Ecast
                                              (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                              tuchar)
                                            (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                            tint)
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Ecast
                                                (Expr.Etempvar _dst tuchar)
                                                tuchar)
                                              (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                              tint)
                            s_kprog_x86_mov_reg_46
                            s_kprog_x86_mov_reg_47)
                          (Stmt.Sset _t'71
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 2) tuint)
                              tuint)))
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Etempvar _t'71 tuint)
                                            (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                            tint)
                          (Stmt.Ssequence
                            (Stmt.Sloop
                              (Stmt.Ssequence
                                s_kprog_x86_mov_reg_48
                                s_kprog_x86_mov_reg_49)
                              Stmt.Sbreak)
                            (Stmt.Sloop
                              (Stmt.Ssequence
                                s_kprog_x86_mov_reg_50
                                s_kprog_x86_mov_reg_70)
                              Stmt.Sbreak))
                          (Stmt.Sloop
                            (Stmt.Ssequence
                              s_kprog_x86_mov_reg_71
                              (Stmt.Ssequence
                                s_kprog_x86_mov_reg_72
                                s_kprog_x86_mov_reg_82))
                            Stmt.Sbreak)))))
                  Stmt.Sbreak))
              (Stmt.Ssequence
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Ecast
                                      (Expr.Etempvar ___x86_l_width tuchar)
                                      tuchar)
                                    (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                    tint)
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Ecast (Expr.Etempvar _src tuchar)
                                        tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Sset _t'92
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 0) tuint)
                          tuint))
                      (Stmt.Sset _t'92
                        (Expr.Ecast (Expr.Etempvar _t'92 tuint) tuint)))
                    (Stmt.Ssequence
                      (Stmt.Sset _t'92
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 1) tuint)
                          tuint))
                      (Stmt.Sset _t'92
                        (Expr.Ecast (Expr.Etempvar _t'92 tuint) tuint))))
                  (Stmt.Sset _t'92
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint)
                      tuint)))
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Etempvar _t'92 tuint)
                                    (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                    tint)
                  (Stmt.Ssequence
                    (Stmt.Sloop
                      (Stmt.Ssequence
                        (Stmt.Sset ___x86_rd_reg__2
                          (Expr.Ecast (Expr.Etempvar _src tuchar) tuchar))
                        (Stmt.Ssequence
                          (Stmt.Sset ___x86_rd_raw_width__2
                            (Expr.Ecast (Expr.Etempvar ___x86_l_width tuchar)
                              tuchar))
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Scall (some _t'73)
                                (Expr.Evar _x86_width_effective (Ty.Tfunction
                                                                  [tuchar]
                                                                  tuchar
                                                                  cc_default))
                                [(Expr.Etempvar ___x86_rd_raw_width__2 tuchar)])
                              (Stmt.Sset ___x86_rd_width__2
                                (Expr.Ecast (Expr.Etempvar _t'73 tuchar)
                                  tuchar)))
                            (Stmt.Ssequence
                              (Stmt.Sset ___x86_rd_shift__2
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Ebinop Binop.Oand
                                      (Expr.Ebinop Binop.Oshr
                                        (Expr.Etempvar _aux tuint)
                                        (Expr.Econst_int (Integers.Int.repr 16) tint)
                                        tuint)
                                      (Expr.Econst_int (Integers.Int.repr 255) tuint)
                                      tuint) tuchar) tuchar))
                              (Stmt.Ssequence
                                s_kprog_x86_mov_reg_83
                                s_kprog_x86_mov_reg_84)))))
                      Stmt.Sbreak)
                    (Stmt.Sloop
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sset _t'117
                            (Expr.Efield
                              (Expr.Efield
                                (Expr.Efield
                                  (Expr.Efield
                                    (Expr.Ederef
                                      (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                      (Ty.Tstruct _x86_sim_register_state noattr))
                                    (Positive.ofNat 18727075383868559167)
                                    (Ty.Tunion __3115 noattr))
                                  (Positive.ofNat 18727075383868559167)
                                  (Ty.Tstruct __3116 noattr)) _rsp
                                (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                              (tptr tvoid)))
                          (Stmt.Sset ___x86_write_old_sp__6
                            (Expr.Ecast
                              (Expr.Ecast (Expr.Etempvar _t'117 (tptr tvoid))
                                tlong) tlong)))
                        (Stmt.Ssequence
                          (Stmt.Sset ___x86_wr_raw_width__2
                            (Expr.Ecast (Expr.Etempvar ___x86_l_width tuchar)
                              tuchar))
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Scall (some _t'78)
                                (Expr.Evar _x86_width_effective (Ty.Tfunction
                                                                  [tuchar]
                                                                  tuchar
                                                                  cc_default))
                                [(Expr.Etempvar ___x86_wr_raw_width__2 tuchar)])
                              (Stmt.Sset ___x86_wr_width__2
                                (Expr.Ecast (Expr.Etempvar _t'78 tuchar)
                                  tuchar)))
                            (Stmt.Ssequence
                              (Stmt.Sset ___x86_wr_shift__2
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Ebinop Binop.Oand
                                      (Expr.Ebinop Binop.Oshr
                                        (Expr.Etempvar _aux tuint)
                                        (Expr.Econst_int (Integers.Int.repr 8) tint)
                                        tuint)
                                      (Expr.Econst_int (Integers.Int.repr 255) tuint)
                                      tuint) tuchar) tuchar))
                              (Stmt.Ssequence
                                s_kprog_x86_mov_reg_85
                                s_kprog_x86_mov_reg_96)))))
                      Stmt.Sbreak))
                  Stmt.Sskip)))))))
    Stmt.Sbreak))
}

def s_kprog_x86_movx_reg_0 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'56
    (Expr.Efield
      (Expr.Efield
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                  (Ty.Tstruct _x86_sim_register_state noattr))
                (Positive.ofNat 18727075383868559167)
                (Ty.Tunion __3115 noattr)) _gpr_cells
              (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
            (Expr.Ecast (Expr.Etempvar ___x86_rd_reg tuchar) tuchar)
            (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
          (Ty.Tstruct _x86_sim_gpr_cell noattr)) _value
        (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
  (Stmt.Sset _t'9
    (Expr.Ecast (Expr.Etempvar _t'56 (tptr tvoid)) (tptr tvoid))))

def s_kprog_x86_movx_reg_1 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'55
    (Expr.Efield
      (Expr.Ederef
        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
        (Ty.Tstruct _x86_sim_register_state noattr)) _native_stack_base
      tulong))
  (Stmt.Sset ___x86_rd_value
    (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_rd_value tulong)
      (Expr.Etempvar _t'55 tulong) tulong)))

def s_kprog_x86_movx_reg_2 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sset ___x86_tag_reg
        (Expr.Ecast (Expr.Etempvar ___x86_rd_reg tuchar) tulong))
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                            (Expr.Etempvar ___x86_tag_reg tulong)
                            (Expr.Econst_int (Integers.Int.repr 16) tuint)
                            tint)
          (Stmt.Ssequence
            (Stmt.Sset _t'54
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Efield
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                          (Ty.Tstruct _x86_sim_register_state noattr))
                        (Positive.ofNat 18727075383868559167)
                        (Ty.Tunion __3115 noattr)) _gpr_cells
                      (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                    (Expr.Ecast (Expr.Etempvar ___x86_tag_reg tulong) tuchar)
                    (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                  (Ty.Tstruct _x86_sim_gpr_cell noattr)) _tag tuchar))
            (Stmt.Sset _t'10 (Expr.Ecast (Expr.Etempvar _t'54 tuchar) tuint)))
          (Stmt.Sset _t'10
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuint)))
        (Stmt.Sset ___x86_rd_tag
          (Expr.Ecast (Expr.Etempvar _t'10 tuint) tuchar))))
    Stmt.Sbreak)
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Etempvar ___x86_rd_tag tuchar)
                      (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
    (Stmt.Sloop
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sset _t'53
            (Expr.Efield
              (Expr.Ederef
                (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                (Ty.Tstruct _kprog_x86_arena noattr)) _b
              (tptr (tvolatile tuchar))))
          (Stmt.Sset ___x86_stack_delta
            (Expr.Ebinop Binop.Osub
              (Expr.Ecast
                (Expr.Ecast (Expr.Etempvar ___x86_rd_ptr (tptr tvoid)) tlong)
                tulong)
              (Expr.Ecast
                (Expr.Ecast
                  (Expr.Ecast
                    (Expr.Ecast
                      (Expr.Ecast
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Ecast
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Etempvar _t'53 (tptr (tvolatile tuchar)))
                                (Expr.Econst_int (Integers.Int.repr 0) tint)
                                (tptr (tvolatile tuchar))) tulong) tulong)
                          (Expr.Ecast
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 0) tint)
                                tulong)
                              (Expr.Ecast (Expr.Etempvar _capacity tuint)
                                tulong) tulong) tulong) tulong) tulong)
                      (tptr tuchar)) (tptr tvoid)) tlong) tulong) tulong)))
        (Stmt.Ssequence
          (Stmt.Sset _t'52
            (Expr.Efield
              (Expr.Ederef
                (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                (Ty.Tstruct _x86_sim_register_state noattr))
              _native_stack_base tulong))
          (Stmt.Sset ___x86_rd_value
            (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_stack_delta tulong)
              (Expr.Etempvar _t'52 tulong) tulong))))
      Stmt.Sbreak)
    Stmt.Sskip))

def s_kprog_x86_movx_reg_3 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                    (Expr.Etempvar ___x86_rd_width tuchar)
                    (Expr.Econst_int (Integers.Int.repr 1) tuint) tint)
  (Stmt.Sset _t'11 (Expr.Ecast (Expr.Etempvar ___x86_rd_shift tuchar) tuint))
  (Stmt.Sset _t'11
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuint)))

def s_kprog_x86_movx_reg_4 : Stmt :=
(Stmt.Sset _t'12
  (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 255) tulong) tulong))

def s_kprog_x86_movx_reg_5 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                    (Expr.Etempvar ___x86_rd_width tuchar)
                    (Expr.Econst_int (Integers.Int.repr 2) tuint) tint)
  (Stmt.Ssequence
    (Stmt.Sset _t'12
      (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 65535) tulong)
        tulong))
    (Stmt.Sset _t'12 (Expr.Ecast (Expr.Etempvar _t'12 tulong) tulong)))
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Etempvar ___x86_rd_width tuchar)
                      (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sset _t'12
          (Expr.Ecast
            (Expr.Econst_long (Integers.Int64.repr 4294967295) tulong)
            tulong))
        (Stmt.Sset _t'12 (Expr.Ecast (Expr.Etempvar _t'12 tulong) tulong)))
      (Stmt.Sset _t'12 (Expr.Ecast (Expr.Etempvar _t'12 tulong) tulong)))
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sset _t'12
          (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr (-1)) tulong)
            tulong))
        (Stmt.Sset _t'12 (Expr.Ecast (Expr.Etempvar _t'12 tulong) tulong)))
      (Stmt.Sset _t'12 (Expr.Ecast (Expr.Etempvar _t'12 tulong) tulong)))))

def s_kprog_x86_movx_reg_6 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                    (Expr.Ecast (Expr.Etempvar _dst tuchar) tulong)
                    (Expr.Econst_int (Integers.Int.repr 16) tuint) tint)
  (Stmt.Ssequence
    (Stmt.Sset _t'50
      (Expr.Efield
        (Expr.Efield
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                    (Ty.Tstruct _x86_sim_register_state noattr))
                  (Positive.ofNat 18727075383868559167)
                  (Ty.Tunion __3115 noattr)) _gpr_cells
                (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
              (Expr.Ecast (Expr.Etempvar _dst tuchar) tuchar)
              (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
            (Ty.Tstruct _x86_sim_gpr_cell noattr)) _value
          (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
    (Stmt.Sset _t'16
      (Expr.Ecast (Expr.Etempvar _t'50 (tptr tvoid)) (tptr tvoid))))
  (Stmt.Sset _t'16
    (Expr.Ecast
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid))
      (tptr tvoid))))

def s_kprog_x86_movx_reg_7 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_tag_reg__1
    (Expr.Ecast (Expr.Etempvar _dst tuchar) tulong))
  (Stmt.Ssequence
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                        (Expr.Etempvar ___x86_tag_reg__1 tulong)
                        (Expr.Econst_int (Integers.Int.repr 16) tuint) tint)
      (Stmt.Ssequence
        (Stmt.Sset _t'49
          (Expr.Efield
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                      (Ty.Tstruct _x86_sim_register_state noattr))
                    (Positive.ofNat 18727075383868559167)
                    (Ty.Tunion __3115 noattr)) _gpr_cells
                  (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                (Expr.Ecast (Expr.Etempvar ___x86_tag_reg__1 tulong) tuchar)
                (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
              (Ty.Tstruct _x86_sim_gpr_cell noattr)) _tag tuchar))
        (Stmt.Sset _t'17 (Expr.Ecast (Expr.Etempvar _t'49 tuchar) tuint)))
      (Stmt.Sset _t'17
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuint)))
    (Stmt.Sset ___x86_wr_cell_tag
      (Expr.Ecast (Expr.Etempvar _t'17 tuint) tuchar))))

def s_kprog_x86_movx_reg_8 : Stmt :=
Stmt.Sbreak

def s_kprog_x86_movx_reg_9 : Stmt :=
(Stmt.Sset ___x86_release_off
  (Expr.Ebinop Binop.Osub
    (Expr.Ecast (Expr.Etempvar ___x86_release_i tuint) tlong)
    (Expr.Ecast (Expr.Etempvar _capacity tuint) tlong) tlong))

def s_kprog_x86_movx_reg_10 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Ole
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Etempvar ___x86_release_i tuint)
                          (Expr.Econst_int (Integers.Int.repr 8) tuint)
                          tuint) (Expr.Etempvar _capacity tuint) tint)
      (Stmt.Sset _t'27
        (Expr.Ecast
          (Expr.Ebinop Binop.Oge (Expr.Etempvar ___x86_release_off tlong)
            (Expr.Etempvar ___x86_release_old tlong) tint) tbool))
      (Stmt.Sset _t'27 (Expr.Econst_int (Integers.Int.repr 0) tint)))
    (Stmt.Sifthenelse (Expr.Etempvar _t'27 tint)
      (Stmt.Sset _t'28
        (Expr.Ecast
          (Expr.Ebinop Binop.Ole
            (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_release_off tlong)
              (Expr.Econst_int (Integers.Int.repr 8) tint) tlong)
            (Expr.Etempvar ___x86_release_new tlong) tint) tbool))
      (Stmt.Sset _t'28 (Expr.Econst_int (Integers.Int.repr 0) tint))))
  (Stmt.Sifthenelse (Expr.Etempvar _t'28 tint)
    (Stmt.Ssequence
      (Stmt.Scall (some _t'23)
        (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                             cc_default))
        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
      (Stmt.Ssequence
        (Stmt.Sset _t'33
          (Expr.Efield
            (Expr.Ederef
              (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
              (Ty.Tstruct _kprog_x86_arena noattr)) _q
            (tptr (tvolatile tulong))))
        (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
          [(tptr (tvolatile tulong)), (tvolatile tulong)]
          [(Expr.Eaddrof
             (Expr.Ederef
               (Expr.Ebinop Binop.Oadd
                 (Expr.Etempvar _t'33 (tptr (tvolatile tulong)))
                 (Expr.Ebinop Binop.Odiv
                   (Expr.Etempvar ___x86_release_i tuint)
                   (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint)
                 (tptr (tvolatile tulong))) (tvolatile tulong))
             (tptr (tvolatile tulong))), (Expr.Etempvar _t'23 tulong)])))
    (Stmt.Ssequence
      (Stmt.Sset ___x86_release_lane
        (Expr.Econst_int (Integers.Int.repr 0) tint))
      (Stmt.Sloop
        (Stmt.Ssequence
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                              (Expr.Etempvar ___x86_release_lane tuint)
                              (Expr.Econst_int (Integers.Int.repr 8) tuint)
                              tint)
            Stmt.Sskip
            Stmt.Sbreak)
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Etempvar ___x86_release_i tuint)
                                    (Expr.Etempvar ___x86_release_lane tuint)
                                    tuint) (Expr.Etempvar _capacity tuint)
                                  tint)
                (Stmt.Sset _t'25
                  (Expr.Ecast
                    (Expr.Ebinop Binop.Oge
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar ___x86_release_off tlong)
                        (Expr.Etempvar ___x86_release_lane tuint) tlong)
                      (Expr.Etempvar ___x86_release_old tlong) tint) tbool))
                (Stmt.Sset _t'25
                  (Expr.Econst_int (Integers.Int.repr 0) tint)))
              (Stmt.Sifthenelse (Expr.Etempvar _t'25 tint)
                (Stmt.Sset _t'26
                  (Expr.Ecast
                    (Expr.Ebinop Binop.Olt
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar ___x86_release_off tlong)
                        (Expr.Etempvar ___x86_release_lane tuint) tlong)
                      (Expr.Etempvar ___x86_release_new tlong) tint) tbool))
                (Stmt.Sset _t'26
                  (Expr.Econst_int (Integers.Int.repr 0) tint))))
            (Stmt.Sifthenelse (Expr.Etempvar _t'26 tint)
              (Stmt.Ssequence
                (Stmt.Scall (some _t'24)
                  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                       tulong cc_default))
                  [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                (Stmt.Ssequence
                  (Stmt.Sset _t'32
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                        (Ty.Tstruct _kprog_x86_arena noattr)) _b
                      (tptr (tvolatile tuchar))))
                  (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
                    [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
                    [(Expr.Eaddrof
                       (Expr.Ederef
                         (Expr.Ebinop Binop.Oadd
                           (Expr.Etempvar _t'32 (tptr (tvolatile tuchar)))
                           (Expr.Ebinop Binop.Oadd
                             (Expr.Etempvar ___x86_release_i tuint)
                             (Expr.Etempvar ___x86_release_lane tuint) tuint)
                           (tptr (tvolatile tuchar))) (tvolatile tuchar))
                       (tptr (tvolatile tuchar))),
                     (Expr.Ecast (Expr.Etempvar _t'24 tulong) tuchar)])))
              Stmt.Sskip)))
        (Stmt.Sset ___x86_release_lane
          (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_release_lane tuint)
            (Expr.Econst_int (Integers.Int.repr 1) tint) tuint))))))

def s_kprog_x86_movx_reg_11 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt (Expr.Etempvar ___x86_sv_i tuint)
                      (Expr.Ebinop Binop.Odiv
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Ecast (Expr.Etempvar _capacity tuint) tulong)
                          (Expr.Econst_int (Integers.Int.repr 7) tuint)
                          tulong)
                        (Expr.Econst_int (Integers.Int.repr 8) tuint) tulong)
                      tint)
    Stmt.Sskip
    Stmt.Sbreak)
  (Stmt.Sloop
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                        (Expr.Ebinop Binop.Osub
                          (Expr.Ecast
                            (Expr.Ebinop Binop.Omul
                              (Expr.Ecast (Expr.Etempvar ___x86_sv_i tuint)
                                tulong)
                              (Expr.Econst_int (Integers.Int.repr 8) tuint)
                              tulong) tlong)
                          (Expr.Ecast (Expr.Etempvar _capacity tuint) tlong)
                          tlong) (Expr.Etempvar ___x86_sv_sp tlong) tint)
      (Stmt.Sloop
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sset _t'30
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                    (Expr.Etempvar ___x86_sv_i tuint)
                    (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                  (Ty.Tstruct _kprog_x86_stack_fact noattr)) _tag
                (tptr tuchar)))
            (Stmt.Sassign
              (Expr.Ederef (Expr.Etempvar _t'30 (tptr tuchar)) tuchar)
              (Expr.Econst_int (Integers.Int.repr 0) tuint)))
          (Stmt.Ssequence
            (Stmt.Sset _t'29
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                    (Expr.Etempvar ___x86_sv_i tuint)
                    (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                  (Ty.Tstruct _kprog_x86_stack_fact noattr)) _pointer
                (tptr (tptr tvoid))))
            (Stmt.Sassign
              (Expr.Ederef (Expr.Etempvar _t'29 (tptr (tptr tvoid)))
                (tptr tvoid)) (Expr.Econst_int (Integers.Int.repr 0) tint))))
        Stmt.Sbreak)
      Stmt.Sskip)
    Stmt.Sbreak))

def s_kprog_x86_movx_reg_12 : Stmt :=
(Stmt.Sset ___x86_sv_i
  (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_sv_i tuint)
    (Expr.Econst_int (Integers.Int.repr 1) tint) tuint))

def s_kprog_x86_movx_reg_13 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                        (Expr.Ecast (Expr.Etempvar ___x86_wr_width tuchar)
                          tuchar)
                        (Expr.Econst_int (Integers.Int.repr 1) tuint) tint)
      (Stmt.Sset _t'22
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuint))
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                          (Expr.Ecast (Expr.Etempvar ___x86_wr_width tuchar)
                            tuchar)
                          (Expr.Econst_int (Integers.Int.repr 2) tuint) tint)
        (Stmt.Ssequence
          (Stmt.Sset _t'22
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
          (Stmt.Sset _t'22 (Expr.Ecast (Expr.Etempvar _t'22 tuint) tuint)))
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Ecast
                              (Expr.Etempvar ___x86_wr_width tuchar) tuchar)
                            (Expr.Econst_int (Integers.Int.repr 4) tuint)
                            tint)
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sset _t'22
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint)
                  tuint))
              (Stmt.Sset _t'22
                (Expr.Ecast (Expr.Etempvar _t'22 tuint) tuint)))
            (Stmt.Sset _t'22 (Expr.Ecast (Expr.Etempvar _t'22 tuint) tuint)))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sset _t'22
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint)
                  tuint))
              (Stmt.Sset _t'22
                (Expr.Ecast (Expr.Etempvar _t'22 tuint) tuint)))
            (Stmt.Sset _t'22 (Expr.Ecast (Expr.Etempvar _t'22 tuint) tuint))))))
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _t'22 tuint)
                        (Expr.Econst_int (Integers.Int.repr 0) tuint) tint)
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _dst tuchar)
                            (Expr.Econst_int (Integers.Int.repr 4) tuint)
                            tint)
          (Stmt.Ssequence
            (Stmt.Sset _t'47
              (Expr.Efield
                (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                _ptr (tptr tvoid)))
            (Stmt.Ssequence
              (Stmt.Sset _t'48
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                    (Ty.Tstruct _x86_sim_register_state noattr))
                  _native_stack_base tulong))
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                  _ptr (tptr tvoid))
                (Expr.Ecast
                  (Expr.Ecast
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Ecast
                        (Expr.Ecast (Expr.Etempvar _t'47 (tptr tvoid)) tlong)
                        tulong) (Expr.Etempvar _t'48 tulong) tulong) tlong)
                  (tptr tvoid)))))
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                              (Expr.Econst_int (Integers.Int.repr 4) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Sloop
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sset _t'45
                      (Expr.Efield
                        (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                        _ptr (tptr tvoid)))
                    (Stmt.Ssequence
                      (Stmt.Sset _t'46
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                            (Ty.Tstruct _kprog_x86_arena noattr)) _b
                          (tptr (tvolatile tuchar))))
                      (Stmt.Sset ___x86_stack_delta__1
                        (Expr.Ebinop Binop.Osub
                          (Expr.Ecast
                            (Expr.Ecast (Expr.Etempvar _t'45 (tptr tvoid))
                              tlong) tulong)
                          (Expr.Ecast
                            (Expr.Ecast
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Ecast
                                        (Expr.Ecast
                                          (Expr.Ebinop Binop.Oadd
                                            (Expr.Etempvar _t'46 (tptr (tvolatile tuchar)))
                                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                                            (tptr (tvolatile tuchar)))
                                          tulong) tulong)
                                      (Expr.Ecast
                                        (Expr.Ebinop Binop.Oadd
                                          (Expr.Ecast
                                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                                            tulong)
                                          (Expr.Ecast
                                            (Expr.Etempvar _capacity tuint)
                                            tulong) tulong) tulong) tulong)
                                    tulong) (tptr tuchar)) (tptr tvoid))
                              tlong) tulong) tulong))))
                  (Stmt.Ssequence
                    (Stmt.Sset _t'44
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                          (Ty.Tstruct _x86_sim_register_state noattr))
                        _native_stack_base tulong))
                    (Stmt.Sset ___x86_wr_stack_bits
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar ___x86_stack_delta__1 tulong)
                        (Expr.Etempvar _t'44 tulong) tulong))))
                Stmt.Sbreak)
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                  _ptr (tptr tvoid))
                (Expr.Ecast
                  (Expr.Ecast (Expr.Etempvar ___x86_wr_stack_bits tulong)
                    tlong) (tptr tvoid))))
            Stmt.Sskip))
        (Stmt.Sloop
          (Stmt.Ssequence
            (Stmt.Sset ___kprog_x86_lane
              (Expr.Ecast (Expr.Etempvar ___x86_wr_next tulong) tuchar))
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                  tint)
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Etempvar ___x86_wr_shift tuchar)
                                    (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                    tint)
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                          _b (tarray tuchar 8))
                        (Expr.Econst_int (Integers.Int.repr 1) tint)
                        (tptr tuchar)) tuchar)
                    (Expr.Etempvar ___kprog_x86_lane tuchar))
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                          _b (tarray tuchar 8))
                        (Expr.Econst_int (Integers.Int.repr 0) tint)
                        (tptr tuchar)) tuchar)
                    (Expr.Etempvar ___kprog_x86_lane tuchar)))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sset _t'43
                      (Expr.Efield
                        (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                        _ptr (tptr tvoid)))
                    (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
                      [(tptr (tvolatile (tptr tvoid))),
                       (tvolatile (tptr tvoid))]
                      [(Expr.Eaddrof
                         (Expr.Efield
                           (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3634 noattr)))
                           _ptr (tvolatile (tptr tvoid)))
                         (tptr (tvolatile (tptr tvoid)))),
                       (Expr.Etempvar _t'43 (tptr tvoid))]))
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Etempvar ___x86_wr_shift tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                        tint)
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3634 noattr)))
                              _b (tvolatile (tarray tuchar 8)))
                            (Expr.Econst_int (Integers.Int.repr 1) tint)
                            (tptr tuchar)) tuchar)
                        (Expr.Etempvar ___kprog_x86_lane tuchar))
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3634 noattr)))
                              _b (tvolatile (tarray tuchar 8)))
                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                            (tptr tuchar)) tuchar)
                        (Expr.Etempvar ___kprog_x86_lane tuchar)))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sbuiltin (some _t'18)
                          (ExtFun.EF_vload Chunk.Mint64)
                          [(tptr (tvolatile (tptr tvoid)))]
                          [(Expr.Eaddrof
                             (Expr.Efield
                               (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3634 noattr)))
                               _ptr (tvolatile (tptr tvoid)))
                             (tptr (tvolatile (tptr tvoid))))])
                        (Stmt.Sset ___kprog_x86_bits
                          (Expr.Ecast
                            (Expr.Ecast
                              (Expr.Etempvar _t'18 (tvolatile (tptr tvoid)))
                              tlong) tulong)))
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Etempvar ___x86_wr_shift tuchar)
                                            (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                            tint)
                          (Stmt.Sset ___kprog_x86_bits
                            (Expr.Ebinop Binop.Oor
                              (Expr.Ebinop Binop.Oand
                                (Expr.Etempvar ___kprog_x86_bits tulong)
                                (Expr.Eunop Unop.Onotint
                                  (Expr.Econst_long (Integers.Int64.repr 65280) tulong)
                                  tulong) tulong)
                              (Expr.Ebinop Binop.Oshl
                                (Expr.Ecast
                                  (Expr.Etempvar ___kprog_x86_lane tuchar)
                                  tulong)
                                (Expr.Econst_int (Integers.Int.repr 8) tint)
                                tulong) tulong))
                          (Stmt.Sset ___kprog_x86_bits
                            (Expr.Ebinop Binop.Oor
                              (Expr.Ebinop Binop.Oand
                                (Expr.Etempvar ___kprog_x86_bits tulong)
                                (Expr.Eunop Unop.Onotint
                                  (Expr.Econst_long (Integers.Int64.repr 255) tulong)
                                  tulong) tulong)
                              (Expr.Etempvar ___kprog_x86_lane tuchar)
                              tulong)))
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                            _ptr (tptr tvoid))
                          (Expr.Ecast
                            (Expr.Ecast
                              (Expr.Etempvar ___kprog_x86_bits tulong) tlong)
                            (tptr tvoid))))))))
              (Stmt.Sset ___x86_wr_cell_tag
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                  tuchar))))
          Stmt.Sbreak))
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Ecast
                              (Expr.Etempvar ___x86_wr_width tuchar) tuchar)
                            (Expr.Econst_int (Integers.Int.repr 1) tuint)
                            tint)
          (Stmt.Sset _t'21
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuint))
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Ecast
                                (Expr.Etempvar ___x86_wr_width tuchar)
                                tuchar)
                              (Expr.Econst_int (Integers.Int.repr 2) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Sset _t'21
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint)
                  tuint))
              (Stmt.Sset _t'21
                (Expr.Ecast (Expr.Etempvar _t'21 tuint) tuint)))
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Ecast
                                  (Expr.Etempvar ___x86_wr_width tuchar)
                                  tuchar)
                                (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                tint)
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sset _t'21
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint)
                      tuint))
                  (Stmt.Sset _t'21
                    (Expr.Ecast (Expr.Etempvar _t'21 tuint) tuint)))
                (Stmt.Sset _t'21
                  (Expr.Ecast (Expr.Etempvar _t'21 tuint) tuint)))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sset _t'21
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint)
                      tuint))
                  (Stmt.Sset _t'21
                    (Expr.Ecast (Expr.Etempvar _t'21 tuint) tuint)))
                (Stmt.Sset _t'21
                  (Expr.Ecast (Expr.Etempvar _t'21 tuint) tuint))))))
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _t'21 tuint)
                            (Expr.Econst_int (Integers.Int.repr 1) tuint)
                            tint)
          (Stmt.Ssequence
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Etempvar _dst tuchar)
                                (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                tint)
              (Stmt.Ssequence
                (Stmt.Sset _t'41
                  (Expr.Efield
                    (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                    _ptr (tptr tvoid)))
                (Stmt.Ssequence
                  (Stmt.Sset _t'42
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                        (Ty.Tstruct _x86_sim_register_state noattr))
                      _native_stack_base tulong))
                  (Stmt.Sassign
                    (Expr.Efield
                      (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                      _ptr (tptr tvoid))
                    (Expr.Ecast
                      (Expr.Ecast
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Ecast
                            (Expr.Ecast (Expr.Etempvar _t'41 (tptr tvoid))
                              tlong) tulong) (Expr.Etempvar _t'42 tulong)
                          tulong) tlong) (tptr tvoid)))))
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                  tint)
                (Stmt.Ssequence
                  (Stmt.Sloop
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sset _t'39
                          (Expr.Efield
                            (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                            _ptr (tptr tvoid)))
                        (Stmt.Ssequence
                          (Stmt.Sset _t'40
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                                (Ty.Tstruct _kprog_x86_arena noattr)) _b
                              (tptr (tvolatile tuchar))))
                          (Stmt.Sset ___x86_stack_delta__2
                            (Expr.Ebinop Binop.Osub
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Etempvar _t'39 (tptr tvoid)) tlong)
                                tulong)
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Ecast
                                      (Expr.Ecast
                                        (Expr.Ebinop Binop.Oadd
                                          (Expr.Ecast
                                            (Expr.Ecast
                                              (Expr.Ebinop Binop.Oadd
                                                (Expr.Etempvar _t'40 (tptr (tvolatile tuchar)))
                                                (Expr.Econst_int (Integers.Int.repr 0) tint)
                                                (tptr (tvolatile tuchar)))
                                              tulong) tulong)
                                          (Expr.Ecast
                                            (Expr.Ebinop Binop.Oadd
                                              (Expr.Ecast
                                                (Expr.Econst_int (Integers.Int.repr 0) tint)
                                                tulong)
                                              (Expr.Ecast
                                                (Expr.Etempvar _capacity tuint)
                                                tulong) tulong) tulong)
                                          tulong) tulong) (tptr tuchar))
                                    (tptr tvoid)) tlong) tulong) tulong))))
                      (Stmt.Ssequence
                        (Stmt.Sset _t'38
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                              (Ty.Tstruct _x86_sim_register_state noattr))
                            _native_stack_base tulong))
                        (Stmt.Sset ___x86_wr_stack_bits__1
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar ___x86_stack_delta__2 tulong)
                            (Expr.Etempvar _t'38 tulong) tulong))))
                    Stmt.Sbreak)
                  (Stmt.Sassign
                    (Expr.Efield
                      (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                      _ptr (tptr tvoid))
                    (Expr.Ecast
                      (Expr.Ecast
                        (Expr.Etempvar ___x86_wr_stack_bits__1 tulong) tlong)
                      (tptr tvoid))))
                Stmt.Sskip))
            (Stmt.Sloop
              (Stmt.Ssequence
                (Stmt.Sset ___kprog_x86_lane__1
                  (Expr.Ecast (Expr.Etempvar ___x86_wr_next tulong) tushort))
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                      tint)
                    (Stmt.Sassign
                      (Expr.Efield
                        (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                        _w tushort)
                      (Expr.Etempvar ___kprog_x86_lane__1 tushort))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sset _t'37
                          (Expr.Efield
                            (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                            _ptr (tptr tvoid)))
                        (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
                          [(tptr (tvolatile (tptr tvoid))),
                           (tvolatile (tptr tvoid))]
                          [(Expr.Eaddrof
                             (Expr.Efield
                               (Expr.Evar ___kprog_x86_partial__1 (tvolatile (Ty.Tunion __3640 noattr)))
                               _ptr (tvolatile (tptr tvoid)))
                             (tptr (tvolatile (tptr tvoid)))),
                           (Expr.Etempvar _t'37 (tptr tvoid))]))
                      (Stmt.Ssequence
                        (Stmt.Sbuiltin none
                          (ExtFun.EF_vstore Chunk.Mint16unsigned)
                          [(tptr (tvolatile tushort)), (tvolatile tushort)]
                          [(Expr.Eaddrof
                             (Expr.Efield
                               (Expr.Evar ___kprog_x86_partial__1 (tvolatile (Ty.Tunion __3640 noattr)))
                               _w (tvolatile tushort))
                             (tptr (tvolatile tushort))),
                           (Expr.Etempvar ___kprog_x86_lane__1 tushort)])
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Sbuiltin (some _t'19)
                              (ExtFun.EF_vload Chunk.Mint64)
                              [(tptr (tvolatile (tptr tvoid)))]
                              [(Expr.Eaddrof
                                 (Expr.Efield
                                   (Expr.Evar ___kprog_x86_partial__1 (tvolatile (Ty.Tunion __3640 noattr)))
                                   _ptr (tvolatile (tptr tvoid)))
                                 (tptr (tvolatile (tptr tvoid))))])
                            (Stmt.Sset ___kprog_x86_bits__1
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Etempvar _t'19 (tvolatile (tptr tvoid)))
                                  tlong) tulong)))
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                              _ptr (tptr tvoid))
                            (Expr.Ecast
                              (Expr.Ecast
                                (Expr.Ebinop Binop.Oor
                                  (Expr.Ebinop Binop.Oand
                                    (Expr.Etempvar ___kprog_x86_bits__1 tulong)
                                    (Expr.Eunop Unop.Onotint
                                      (Expr.Econst_long (Integers.Int64.repr 65535) tulong)
                                      tulong) tulong)
                                  (Expr.Etempvar ___kprog_x86_lane__1 tushort)
                                  tulong) tlong) (tptr tvoid)))))))
                  (Stmt.Sset ___x86_wr_cell_tag
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                      tuchar))))
              Stmt.Sbreak))
          (Stmt.Ssequence
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Ecast
                                  (Expr.Etempvar ___x86_wr_width tuchar)
                                  tuchar)
                                (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                tint)
              (Stmt.Sset _t'20
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                  tuint))
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Ecast
                                    (Expr.Etempvar ___x86_wr_width tuchar)
                                    tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                  tint)
                (Stmt.Ssequence
                  (Stmt.Sset _t'20
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint)
                      tuint))
                  (Stmt.Sset _t'20
                    (Expr.Ecast (Expr.Etempvar _t'20 tuint) tuint)))
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Ecast
                                      (Expr.Etempvar ___x86_wr_width tuchar)
                                      tuchar)
                                    (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                    tint)
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sset _t'20
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 2) tuint)
                          tuint))
                      (Stmt.Sset _t'20
                        (Expr.Ecast (Expr.Etempvar _t'20 tuint) tuint)))
                    (Stmt.Sset _t'20
                      (Expr.Ecast (Expr.Etempvar _t'20 tuint) tuint)))
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sset _t'20
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 3) tuint)
                          tuint))
                      (Stmt.Sset _t'20
                        (Expr.Ecast (Expr.Etempvar _t'20 tuint) tuint)))
                    (Stmt.Sset _t'20
                      (Expr.Ecast (Expr.Etempvar _t'20 tuint) tuint))))))
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Etempvar _t'20 tuint)
                                (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                tint)
              (Stmt.Ssequence
                (Stmt.Sset ___x86_wr_next
                  (Expr.Ecast
                    (Expr.Ecast (Expr.Etempvar ___x86_wr_next tulong) tuint)
                    tulong))
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Efield
                        (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                        _ptr (tptr tvoid))
                      (Expr.Ecast
                        (Expr.Ecast
                          (Expr.Ecast (Expr.Etempvar ___x86_wr_next tulong)
                            tuint) tlong) (tptr tvoid)))
                    (Stmt.Sset ___x86_wr_cell_tag
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 0) tuint) tuchar)))
                  Stmt.Sbreak))
              (Stmt.Sloop
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Efield
                      (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                      _ptr (tptr tvoid))
                    (Expr.Ecast
                      (Expr.Ecast
                        (Expr.Ecast (Expr.Etempvar ___x86_wr_next tulong)
                          tulong) tlong) (tptr tvoid)))
                  (Stmt.Sset ___x86_wr_cell_tag
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                      tuchar)))
                Stmt.Sbreak)))))))
  (Stmt.Ssequence
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _dst tuchar)
                        (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
      (Stmt.Ssequence
        (Stmt.Sset _t'35
          (Expr.Efield
            (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr)) _ptr
            (tptr tvoid)))
        (Stmt.Ssequence
          (Stmt.Sset _t'36
            (Expr.Efield
              (Expr.Ederef
                (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                (Ty.Tstruct _x86_sim_register_state noattr))
              _native_stack_base tulong))
          (Stmt.Sassign
            (Expr.Efield
              (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr)) _ptr
              (tptr tvoid))
            (Expr.Ecast
              (Expr.Ecast
                (Expr.Ebinop Binop.Osub
                  (Expr.Ecast
                    (Expr.Ecast (Expr.Etempvar _t'35 (tptr tvoid)) tlong)
                    tulong) (Expr.Etempvar _t'36 tulong) tulong) tlong)
              (tptr tvoid)))))
      Stmt.Sskip)
    (Stmt.Ssequence
      (Stmt.Sset ___x86_wr_next_ptr
        (Expr.Efield
          (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr)) _ptr
          (tptr tvoid)))
      (Stmt.Ssequence
        (Stmt.Sset ___x86_wr_next_tag
          (Expr.Ecast (Expr.Etempvar ___x86_wr_cell_tag tuchar) tuchar))
        (Stmt.Ssequence
          (Stmt.Sloop
            (Stmt.Ssequence
              (Stmt.Sset ___x86_store_reg
                (Expr.Ecast (Expr.Etempvar _dst tuchar) tulong))
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                  (Expr.Etempvar ___x86_store_reg tulong)
                                  (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                  tint)
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Efield
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                  (Ty.Tstruct _x86_sim_register_state noattr))
                                (Positive.ofNat 18727075383868559167)
                                (Ty.Tunion __3115 noattr)) _gpr_cells
                              (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                            (Expr.Ecast
                              (Expr.Etempvar ___x86_store_reg tulong) tuchar)
                            (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                          (Ty.Tstruct _x86_sim_gpr_cell noattr)) _value
                        (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid))
                    (Expr.Etempvar ___x86_wr_next_ptr (tptr tvoid)))
                  (Stmt.Sassign
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Efield
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                (Ty.Tstruct _x86_sim_register_state noattr))
                              (Positive.ofNat 18727075383868559167)
                              (Ty.Tunion __3115 noattr)) _gpr_cells
                            (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                          (Expr.Ecast (Expr.Etempvar ___x86_store_reg tulong)
                            tuchar)
                          (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                        (Ty.Tstruct _x86_sim_gpr_cell noattr)) _tag tuchar)
                    (Expr.Etempvar ___x86_wr_next_tag tuchar)))
                Stmt.Sskip))
            Stmt.Sbreak)
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar _dst tuchar)
                              (Expr.Econst_int (Integers.Int.repr 4) tuint)
                              tint)
            (Stmt.Sloop
              (Stmt.Ssequence
                (Stmt.Sset ___x86_release_old
                  (Expr.Etempvar ___x86_write_old_sp tlong))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sset _t'34
                      (Expr.Efield
                        (Expr.Efield
                          (Expr.Efield
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                (Ty.Tstruct _x86_sim_register_state noattr))
                              (Positive.ofNat 18727075383868559167)
                              (Ty.Tunion __3115 noattr))
                            (Positive.ofNat 18727075383868559167)
                            (Ty.Tstruct __3116 noattr)) _rsp
                          (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
                    (Stmt.Sset ___x86_release_new
                      (Expr.Ecast
                        (Expr.Ecast (Expr.Etempvar _t'34 (tptr tvoid)) tlong)
                        tlong)))
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Ogt
                                      (Expr.Etempvar ___x86_release_new tlong)
                                      (Expr.Etempvar ___x86_release_old tlong)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sset ___x86_release_i
                          (Expr.Econst_int (Integers.Int.repr 0) tint))
                        (Stmt.Sloop
                          (Stmt.Ssequence
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                                (Expr.Etempvar ___x86_release_i tuint)
                                                (Expr.Etempvar _capacity tuint)
                                                tint)
                              Stmt.Sskip
                              Stmt.Sbreak)
                            (Stmt.Ssequence
                              s_kprog_x86_movx_reg_9
                              s_kprog_x86_movx_reg_10))
                          (Stmt.Sset ___x86_release_i
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar ___x86_release_i tuint)
                              (Expr.Econst_int (Integers.Int.repr 8) tuint)
                              tuint))))
                      (Stmt.Sloop
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Sset _t'31
                              (Expr.Efield
                                (Expr.Efield
                                  (Expr.Efield
                                    (Expr.Efield
                                      (Expr.Ederef
                                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                        (Ty.Tstruct _x86_sim_register_state noattr))
                                      (Positive.ofNat 18727075383868559167)
                                      (Ty.Tunion __3115 noattr))
                                    (Positive.ofNat 18727075383868559167)
                                    (Ty.Tstruct __3116 noattr)) _rsp
                                  (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                                (tptr tvoid)))
                            (Stmt.Sset ___x86_sv_sp
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Etempvar _t'31 (tptr tvoid)) tlong)
                                tlong)))
                          (Stmt.Ssequence
                            (Stmt.Sset ___x86_sv_i
                              (Expr.Econst_int (Integers.Int.repr 0) tint))
                            (Stmt.Sloop
                              s_kprog_x86_movx_reg_11
                              s_kprog_x86_movx_reg_12)))
                        Stmt.Sbreak))
                    Stmt.Sskip)))
              Stmt.Sbreak)
            Stmt.Sskip))))))

def f_kprog_x86_movx_reg : Function := {
  fn_return := tvoid,
  fn_callconv := cc_default,
  fn_params := [(_state, (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
                (_arena, (tptr (Ty.Tstruct _kprog_x86_arena noattr))),
                (_facts, (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr))),
                (_capacity, tuint), (_op, tuchar), (_dst, tuchar),
                (_src, tuchar), (_flags, tuchar), (_aux, tuint)],
  fn_vars := [(___x86_wr_cell, (Ty.Tunion _x86_sim_gpr noattr)),
              (___kprog_x86_partial, (tvolatile (Ty.Tunion __3634 noattr))),
              (___kprog_x86_partial__1,
               (tvolatile (Ty.Tunion __3640 noattr)))],
  fn_temps := [(___x86_state,
                (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
               (___x86_l_width, tuchar), (___x86_l_src_width, tuchar),
               (___x86_l_shape, tuchar), (___x86_l_value, tulong),
               (___x86_rd_reg, tuchar), (___x86_rd_raw_width, tuchar),
               (___x86_rd_width, tuchar), (___x86_rd_shift, tuchar),
               (___x86_rd_ptr, (tptr tvoid)), (___x86_rd_value, tulong),
               (___x86_rd_tag, tuchar), (___x86_tag_reg, tulong),
               (___x86_stack_delta, tulong), (___x86_l_lane32, tuint),
               (___x86_write_old_sp, tlong), (___x86_wr_raw_width, tuchar),
               (___x86_wr_width, tuchar), (___x86_wr_shift, tuchar),
               (___x86_wr_next, tulong), (___x86_wr_cell_tag, tuchar),
               (___x86_tag_reg__1, tulong), (___x86_wr_stack_bits, tulong),
               (___x86_stack_delta__1, tulong), (___kprog_x86_lane, tuchar),
               (___kprog_x86_bits, tulong),
               (___x86_wr_stack_bits__1, tulong),
               (___x86_stack_delta__2, tulong),
               (___kprog_x86_lane__1, tushort),
               (___kprog_x86_bits__1, tulong),
               (___x86_wr_next_ptr, (tptr tvoid)),
               (___x86_wr_next_tag, tuchar), (___x86_store_reg, tulong),
               (___x86_release_old, tlong), (___x86_release_new, tlong),
               (___x86_release_i, tuint), (___x86_release_off, tlong),
               (___x86_release_lane, tuint), (___x86_sv_sp, tlong),
               (___x86_sv_i, tuint), (_t'28, tint), (_t'27, tint),
               (_t'26, tint), (_t'25, tint), (_t'24, tulong),
               (_t'23, tulong), (_t'22, tuint), (_t'21, tuint),
               (_t'20, tuint), (_t'19, (tvolatile (tptr tvoid))),
               (_t'18, (tvolatile (tptr tvoid))), (_t'17, tuint),
               (_t'16, (tptr tvoid)), (_t'15, tuchar), (_t'14, tulong),
               (_t'13, tulong), (_t'12, tulong), (_t'11, tuint),
               (_t'10, tuint), (_t'9, (tptr tvoid)), (_t'8, tuint),
               (_t'7, tint), (_t'6, tuchar), (_t'5, tuint), (_t'4, tint),
               (_t'3, tuint), (_t'2, tint), (_t'1, tuchar),
               (_t'56, (tptr tvoid)), (_t'55, tulong), (_t'54, tuchar),
               (_t'53, (tptr (tvolatile tuchar))), (_t'52, tulong),
               (_t'51, (tptr tvoid)), (_t'50, (tptr tvoid)), (_t'49, tuchar),
               (_t'48, tulong), (_t'47, (tptr tvoid)),
               (_t'46, (tptr (tvolatile tuchar))), (_t'45, (tptr tvoid)),
               (_t'44, tulong), (_t'43, (tptr tvoid)), (_t'42, tulong),
               (_t'41, (tptr tvoid)), (_t'40, (tptr (tvolatile tuchar))),
               (_t'39, (tptr tvoid)), (_t'38, tulong), (_t'37, (tptr tvoid)),
               (_t'36, tulong), (_t'35, (tptr tvoid)), (_t'34, (tptr tvoid)),
               (_t'33, (tptr (tvolatile tulong))),
               (_t'32, (tptr (tvolatile tuchar))), (_t'31, (tptr tvoid)),
               (_t'30, (tptr tuchar)), (_t'29, (tptr (tptr tvoid)))],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_state
    (Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))))
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Scall (some _t'1)
          (Expr.Evar _x86_width_effective (Ty.Tfunction [tuchar] tuchar
                                            cc_default))
          [(Expr.Etempvar _flags tuchar)])
        (Stmt.Sset ___x86_l_width
          (Expr.Ecast (Expr.Etempvar _t'1 tuchar) tuchar)))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Ecast (Expr.Etempvar _aux tuint) tuchar)
                              (Expr.Econst_int (Integers.Int.repr 0) tuint)
                              tint)
            (Stmt.Sset _t'2
              (Expr.Ecast
                (Expr.Ecast (Expr.Etempvar ___x86_l_width tuchar) tuchar)
                tint))
            (Stmt.Sset _t'2
              (Expr.Ecast (Expr.Ecast (Expr.Etempvar _aux tuint) tuchar)
                tint)))
          (Stmt.Sset ___x86_l_src_width
            (Expr.Ecast (Expr.Etempvar _t'2 tint) tuchar)))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Ecast (Expr.Etempvar _op tuchar)
                                  tuchar)
                                (Expr.Econst_int (Integers.Int.repr 33) tuint)
                                tint)
              (Stmt.Sset _t'3
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                  tuint))
              (Stmt.Sset _t'3
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint)
                  tuint)))
            (Stmt.Sset ___x86_l_shape
              (Expr.Ecast (Expr.Etempvar _t'3 tuint) tuchar)))
          (Stmt.Ssequence
            (Stmt.Sloop
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                        (Expr.Ecast
                                          (Expr.Etempvar _src tuchar) tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 128) tuint)
                                        tint)
                      (Stmt.Sset _t'4
                        (Expr.Ecast
                          (Expr.Ebinop Binop.Olt
                            (Expr.Ecast (Expr.Etempvar _src tuchar) tuchar)
                            (Expr.Econst_int (Integers.Int.repr 132) tuint)
                            tint) tbool))
                      (Stmt.Sset _t'4
                        (Expr.Econst_int (Integers.Int.repr 0) tint)))
                    (Stmt.Sifthenelse (Expr.Etempvar _t'4 tint)
                      (Stmt.Sset _t'5
                        (Expr.Ecast
                          (Expr.Ebinop Binop.Osub
                            (Expr.Ecast (Expr.Etempvar _src tuchar) tuchar)
                            (Expr.Econst_int (Integers.Int.repr 128) tuint)
                            tuint) tuint))
                      (Stmt.Sset _t'5
                        (Expr.Ecast
                          (Expr.Ecast (Expr.Etempvar _src tuchar) tuchar)
                          tuint))))
                  (Stmt.Sset ___x86_rd_reg
                    (Expr.Ecast (Expr.Etempvar _t'5 tuint) tuchar)))
                (Stmt.Ssequence
                  (Stmt.Sset ___x86_rd_raw_width
                    (Expr.Ecast (Expr.Etempvar ___x86_l_src_width tuchar)
                      tuchar))
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Scall (some _t'6)
                        (Expr.Evar _x86_width_effective (Ty.Tfunction
                                                          [tuchar] tuchar
                                                          cc_default))
                        [(Expr.Etempvar ___x86_rd_raw_width tuchar)])
                      (Stmt.Sset ___x86_rd_width
                        (Expr.Ecast (Expr.Etempvar _t'6 tuchar) tuchar)))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                              (Expr.Ecast
                                                (Expr.Etempvar _src tuchar)
                                                tuchar)
                                              (Expr.Econst_int (Integers.Int.repr 128) tuint)
                                              tint)
                            (Stmt.Sset _t'7
                              (Expr.Ecast
                                (Expr.Ebinop Binop.Olt
                                  (Expr.Ecast (Expr.Etempvar _src tuchar)
                                    tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 132) tuint)
                                  tint) tbool))
                            (Stmt.Sset _t'7
                              (Expr.Econst_int (Integers.Int.repr 0) tint)))
                          (Stmt.Sifthenelse (Expr.Etempvar _t'7 tint)
                            (Stmt.Sset _t'8
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                tuint))
                            (Stmt.Sset _t'8
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                tuint))))
                        (Stmt.Sset ___x86_rd_shift
                          (Expr.Ecast (Expr.Etempvar _t'8 tuint) tuchar)))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                              (Expr.Ecast
                                                (Expr.Etempvar ___x86_rd_reg tuchar)
                                                tulong)
                                              (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                              tint)
                            s_kprog_x86_movx_reg_0
                            (Stmt.Sset _t'9
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 0) tint)
                                  (tptr tvoid)) (tptr tvoid))))
                          (Stmt.Sset ___x86_rd_ptr
                            (Expr.Etempvar _t'9 (tptr tvoid))))
                        (Stmt.Ssequence
                          (Stmt.Sset ___x86_rd_value
                            (Expr.Ecast
                              (Expr.Ecast
                                (Expr.Etempvar ___x86_rd_ptr (tptr tvoid))
                                tlong) tulong))
                          (Stmt.Ssequence
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                (Expr.Etempvar ___x86_rd_reg tuchar)
                                                (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                                tint)
                              s_kprog_x86_movx_reg_1
                              s_kprog_x86_movx_reg_2)
                            (Stmt.Ssequence
                              (Stmt.Ssequence
                                s_kprog_x86_movx_reg_3
                                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                    (Expr.Etempvar ___x86_rd_width tuchar)
                                                    (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                                    tint)
                                  s_kprog_x86_movx_reg_4
                                  s_kprog_x86_movx_reg_5))
                              (Stmt.Sset ___x86_l_value
                                (Expr.Ebinop Binop.Oand
                                  (Expr.Ebinop Binop.Oshr
                                    (Expr.Etempvar ___x86_rd_value tulong)
                                    (Expr.Etempvar _t'11 tuint) tulong)
                                  (Expr.Etempvar _t'12 tulong) tulong))))))))))
              Stmt.Sbreak)
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar ___x86_l_shape tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                  tint)
                (Stmt.Ssequence
                  (Stmt.Scall (some _t'13)
                    (Expr.Evar _x86_sign_extend (Ty.Tfunction
                                                  [tulong, tuchar] tulong
                                                  cc_default))
                    [(Expr.Etempvar ___x86_l_value tulong),
                     (Expr.Etempvar ___x86_l_src_width tuchar)])
                  (Stmt.Sset ___x86_l_value (Expr.Etempvar _t'13 tulong)))
                (Stmt.Ssequence
                  (Stmt.Scall (some _t'14)
                    (Expr.Evar _x86_apply_width (Ty.Tfunction
                                                  [tulong, tuchar] tulong
                                                  cc_default))
                    [(Expr.Etempvar ___x86_l_value tulong),
                     (Expr.Etempvar ___x86_l_src_width tuchar)])
                  (Stmt.Sset ___x86_l_value (Expr.Etempvar _t'14 tulong))))
              (Stmt.Ssequence
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Etempvar ___x86_l_width tuchar)
                                    (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                    tint)
                  (Stmt.Ssequence
                    (Stmt.Sset ___x86_l_lane32
                      (Expr.Ecast (Expr.Etempvar ___x86_l_value tulong)
                        tuint))
                    (Stmt.Sset ___x86_l_value
                      (Expr.Ecast (Expr.Etempvar ___x86_l_lane32 tuint)
                        tulong)))
                  Stmt.Sskip)
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sset _t'51
                        (Expr.Efield
                          (Expr.Efield
                            (Expr.Efield
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                  (Ty.Tstruct _x86_sim_register_state noattr))
                                (Positive.ofNat 18727075383868559167)
                                (Ty.Tunion __3115 noattr))
                              (Positive.ofNat 18727075383868559167)
                              (Ty.Tstruct __3116 noattr)) _rsp
                            (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                          (tptr tvoid)))
                      (Stmt.Sset ___x86_write_old_sp
                        (Expr.Ecast
                          (Expr.Ecast (Expr.Etempvar _t'51 (tptr tvoid))
                            tlong) tlong)))
                    (Stmt.Ssequence
                      (Stmt.Sset ___x86_wr_raw_width
                        (Expr.Ecast (Expr.Etempvar ___x86_l_width tuchar)
                          tuchar))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'15)
                            (Expr.Evar _x86_width_effective (Ty.Tfunction
                                                              [tuchar] tuchar
                                                              cc_default))
                            [(Expr.Etempvar ___x86_wr_raw_width tuchar)])
                          (Stmt.Sset ___x86_wr_width
                            (Expr.Ecast (Expr.Etempvar _t'15 tuchar) tuchar)))
                        (Stmt.Ssequence
                          (Stmt.Sset ___x86_wr_shift
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 0) tuint)
                              tuchar))
                          (Stmt.Ssequence
                            (Stmt.Sset ___x86_wr_next
                              (Expr.Etempvar ___x86_l_value tulong))
                            (Stmt.Ssequence
                              (Stmt.Ssequence
                                s_kprog_x86_movx_reg_6
                                (Stmt.Sassign
                                  (Expr.Efield
                                    (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                                    _ptr (tptr tvoid))
                                  (Expr.Etempvar _t'16 (tptr tvoid))))
                              (Stmt.Ssequence
                                (Stmt.Sloop
                                  s_kprog_x86_movx_reg_7
                                  s_kprog_x86_movx_reg_8)
                                s_kprog_x86_movx_reg_13)))))))
                  Stmt.Sbreak)))))))
    Stmt.Sbreak))
}

def f_kprog_x86_stack_alias : Function := {
  fn_return := tlong,
  fn_callconv := cc_default,
  fn_params := [(_arena, (tptr (Ty.Tstruct _kprog_x86_arena noattr))),
                (_capacity, tuint), (_address, (tptr tvoid))],
  fn_vars := [],
  fn_temps := [(_result, tlong), (___x86_alias_delta, tulong),
               (_t'1, (tptr (tvolatile tuchar)))],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sset _t'1
          (Expr.Efield
            (Expr.Ederef
              (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
              (Ty.Tstruct _kprog_x86_arena noattr)) _b
            (tptr (tvolatile tuchar))))
        (Stmt.Sset ___x86_alias_delta
          (Expr.Ebinop Binop.Osub
            (Expr.Ecast
              (Expr.Ecast (Expr.Etempvar _address (tptr tvoid)) tlong)
              tulong)
            (Expr.Ecast
              (Expr.Ecast
                (Expr.Ecast
                  (Expr.Ecast
                    (Expr.Ecast
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Ecast
                          (Expr.Ecast
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar _t'1 (tptr (tvolatile tuchar)))
                              (Expr.Econst_int (Integers.Int.repr 0) tint)
                              (tptr (tvolatile tuchar))) tulong) tulong)
                        (Expr.Ecast
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 0) tint)
                              tulong)
                            (Expr.Ecast (Expr.Etempvar _capacity tuint)
                              tulong) tulong) tulong) tulong) tulong)
                    (tptr tuchar)) (tptr tvoid)) tlong) tulong) tulong)))
      (Stmt.Sset _result
        (Expr.Ecast (Expr.Etempvar ___x86_alias_delta tulong) tlong)))
    Stmt.Sbreak)
  (Stmt.Sreturn (some (Expr.Etempvar _result tlong))))
}

def f_kprog_x86_load_tagged : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_state, (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
                (_arena, (tptr (Ty.Tstruct _kprog_x86_arena noattr))),
                (_capacity, tuint), (_address, (tptr tvoid)),
                (_width, tulong), (_tag, tulong)],
  fn_vars := [],
  fn_temps := [(___x86_state,
                (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
               (_result, tulong), (___x86_alias_observed, tulong),
               (___x86_alias_offset, tlong), (___x86_alias_delta, tulong),
               (_t'4, tulong), (_t'3, tuchar), (_t'2, tulong),
               (_t'1, tulong), (_t'6, (tptr (tvolatile tuchar))),
               (_t'5, (tptr tvoid))],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_state
    (Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))))
  (Stmt.Ssequence
    (Stmt.Sloop
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Scall (some _t'1)
            (Expr.Evar _kprog_x86_mem_load (Ty.Tfunction
                                             [(tptr tvoid), tuchar] tulong
                                             cc_default))
            [(Expr.Etempvar _address (tptr tvoid)),
             (Expr.Etempvar _width tulong)])
          (Stmt.Sset ___x86_alias_observed (Expr.Etempvar _t'1 tulong)))
        (Stmt.Ssequence
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar _tag tulong)
                              (Expr.Econst_int (Integers.Int.repr 4) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Sloop
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sset _t'6
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                          (Ty.Tstruct _kprog_x86_arena noattr)) _b
                        (tptr (tvolatile tuchar))))
                    (Stmt.Sset ___x86_alias_delta
                      (Expr.Ebinop Binop.Osub
                        (Expr.Ecast
                          (Expr.Ecast (Expr.Etempvar _address (tptr tvoid))
                            tlong) tulong)
                        (Expr.Ecast
                          (Expr.Ecast
                            (Expr.Ecast
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Ecast
                                      (Expr.Ecast
                                        (Expr.Ebinop Binop.Oadd
                                          (Expr.Etempvar _t'6 (tptr (tvolatile tuchar)))
                                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                                          (tptr (tvolatile tuchar))) tulong)
                                      tulong)
                                    (Expr.Ecast
                                      (Expr.Ebinop Binop.Oadd
                                        (Expr.Ecast
                                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                                          tulong)
                                        (Expr.Ecast
                                          (Expr.Etempvar _capacity tuint)
                                          tulong) tulong) tulong) tulong)
                                  tulong) (tptr tuchar)) (tptr tvoid)) tlong)
                          tulong) tulong)))
                  (Stmt.Sset ___x86_alias_offset
                    (Expr.Ecast (Expr.Etempvar ___x86_alias_delta tulong)
                      tlong)))
                Stmt.Sbreak)
              (Stmt.Ssequence
                (Stmt.Sset _t'5
                  (Expr.Efield
                    (Expr.Efield
                      (Expr.Efield
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                            (Ty.Tstruct _x86_sim_register_state noattr))
                          (Positive.ofNat 18727075383868559167)
                          (Ty.Tunion __3115 noattr))
                        (Positive.ofNat 18727075383868559167)
                        (Ty.Tstruct __3116 noattr)) _rsp
                      (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                    (Expr.Etempvar ___x86_alias_offset tlong)
                                    (Expr.Ecast
                                      (Expr.Ecast
                                        (Expr.Etempvar _t'5 (tptr tvoid))
                                        tlong) tlong) tint)
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Scall (some _t'2)
                          (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                               [tuint] tulong
                                                               cc_default))
                          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                        (Stmt.Scall (some _t'3)
                          (Expr.Evar _x86_width_effective (Ty.Tfunction
                                                            [tuchar] tuchar
                                                            cc_default))
                          [(Expr.Etempvar _width tulong)]))
                      (Stmt.Scall (some _t'4)
                        (Expr.Evar _x86_apply_width (Ty.Tfunction
                                                      [tulong, tuchar] tulong
                                                      cc_default))
                        [(Expr.Etempvar _t'2 tulong),
                         (Expr.Etempvar _t'3 tuchar)]))
                    (Stmt.Sset ___x86_alias_observed
                      (Expr.Etempvar _t'4 tulong)))
                  Stmt.Sskip)))
            Stmt.Sskip)
          (Stmt.Sset _result (Expr.Etempvar ___x86_alias_observed tulong))))
      Stmt.Sbreak)
    (Stmt.Sreturn (some (Expr.Etempvar _result tulong)))))
}

def f_kprog_x86_native_load_tagged : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_state, (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
                (_arena, (tptr (Ty.Tstruct _kprog_x86_arena noattr))),
                (_capacity, tuint), (_base, (tptr tvoid)), (_offset, tlong),
                (_width, tulong), (_tag, tulong)],
  fn_vars := [],
  fn_temps := [(___x86_state,
                (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
               (_result, tulong), (___x86_data_observed, tulong),
               (___x86_data_offset, tlong), (___x86_alias_delta, tulong),
               (_t'4, tulong), (_t'3, tuchar), (_t'2, tulong),
               (_t'1, tulong), (_t'6, (tptr (tvolatile tuchar))),
               (_t'5, (tptr tvoid))],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_state
    (Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))))
  (Stmt.Ssequence
    (Stmt.Sloop
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Scall (some _t'1)
            (Expr.Evar _kprog_x86_mem_load (Ty.Tfunction
                                             [(tptr tvoid), tuchar] tulong
                                             cc_default))
            [(Expr.Ecast
               (Expr.Ecast
                 (Expr.Ebinop Binop.Oadd
                   (Expr.Ecast
                     (Expr.Ecast (Expr.Etempvar _base (tptr tvoid)) tulong)
                     tulong)
                   (Expr.Ecast (Expr.Etempvar _offset tlong) tulong) tulong)
                 tulong) (tptr tuchar)), (Expr.Etempvar _width tulong)])
          (Stmt.Sset ___x86_data_observed (Expr.Etempvar _t'1 tulong)))
        (Stmt.Ssequence
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar _tag tulong)
                              (Expr.Econst_int (Integers.Int.repr 4) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Sloop
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sset _t'6
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                          (Ty.Tstruct _kprog_x86_arena noattr)) _b
                        (tptr (tvolatile tuchar))))
                    (Stmt.Sset ___x86_alias_delta
                      (Expr.Ebinop Binop.Osub
                        (Expr.Ecast
                          (Expr.Ecast
                            (Expr.Ecast
                              (Expr.Ecast
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Ecast
                                    (Expr.Ecast
                                      (Expr.Etempvar _base (tptr tvoid))
                                      tulong) tulong)
                                  (Expr.Ecast (Expr.Etempvar _offset tlong)
                                    tulong) tulong) tulong) (tptr tuchar))
                            tlong) tulong)
                        (Expr.Ecast
                          (Expr.Ecast
                            (Expr.Ecast
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Ecast
                                      (Expr.Ecast
                                        (Expr.Ebinop Binop.Oadd
                                          (Expr.Etempvar _t'6 (tptr (tvolatile tuchar)))
                                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                                          (tptr (tvolatile tuchar))) tulong)
                                      tulong)
                                    (Expr.Ecast
                                      (Expr.Ebinop Binop.Oadd
                                        (Expr.Ecast
                                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                                          tulong)
                                        (Expr.Ecast
                                          (Expr.Etempvar _capacity tuint)
                                          tulong) tulong) tulong) tulong)
                                  tulong) (tptr tuchar)) (tptr tvoid)) tlong)
                          tulong) tulong)))
                  (Stmt.Sset ___x86_data_offset
                    (Expr.Ecast (Expr.Etempvar ___x86_alias_delta tulong)
                      tlong)))
                Stmt.Sbreak)
              (Stmt.Ssequence
                (Stmt.Sset _t'5
                  (Expr.Efield
                    (Expr.Efield
                      (Expr.Efield
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                            (Ty.Tstruct _x86_sim_register_state noattr))
                          (Positive.ofNat 18727075383868559167)
                          (Ty.Tunion __3115 noattr))
                        (Positive.ofNat 18727075383868559167)
                        (Ty.Tstruct __3116 noattr)) _rsp
                      (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                    (Expr.Etempvar ___x86_data_offset tlong)
                                    (Expr.Ecast
                                      (Expr.Ecast
                                        (Expr.Etempvar _t'5 (tptr tvoid))
                                        tlong) tlong) tint)
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Scall (some _t'2)
                          (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                               [tuint] tulong
                                                               cc_default))
                          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                        (Stmt.Scall (some _t'3)
                          (Expr.Evar _x86_width_effective (Ty.Tfunction
                                                            [tuchar] tuchar
                                                            cc_default))
                          [(Expr.Etempvar _width tulong)]))
                      (Stmt.Scall (some _t'4)
                        (Expr.Evar _x86_apply_width (Ty.Tfunction
                                                      [tulong, tuchar] tulong
                                                      cc_default))
                        [(Expr.Etempvar _t'2 tulong),
                         (Expr.Etempvar _t'3 tuchar)]))
                    (Stmt.Sset ___x86_data_observed
                      (Expr.Etempvar _t'4 tulong)))
                  Stmt.Sskip)))
            Stmt.Sskip)
          (Stmt.Sset _result (Expr.Etempvar ___x86_data_observed tulong))))
      Stmt.Sbreak)
    (Stmt.Sreturn (some (Expr.Etempvar _result tulong)))))
}

def f_kprog_x86_mem_offset_indexed : Function := {
  fn_return := tlong,
  fn_callconv := cc_default,
  fn_params := [(_aux, tulong), (_displacement, tlong), (_index, tulong),
                (_present, tint)],
  fn_vars := [],
  fn_temps := [(_offset, tlong), (___kprog_x86_mo_disp, tlong),
               (___kprog_x86_mo_has_index, tint),
               (___kprog_x86_mo_result, tulong),
               (___kprog_x86_mo_scale, tuchar),
               (___kprog_x86_mo_index, tulong), (_t'2, tulong), (_t'1, tint)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sset ___kprog_x86_mo_disp (Expr.Etempvar _displacement tlong))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sifthenelse (Expr.Etempvar _present tint)
            (Stmt.Sset _t'1
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tint) tint))
            (Stmt.Sset _t'1
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) tint)))
          (Stmt.Sset ___kprog_x86_mo_has_index (Expr.Etempvar _t'1 tint)))
        (Stmt.Ssequence
          (Stmt.Sset ___kprog_x86_mo_result
            (Expr.Ecast (Expr.Etempvar ___kprog_x86_mo_disp tlong) tulong))
          (Stmt.Ssequence
            (Stmt.Sifthenelse (Expr.Etempvar ___kprog_x86_mo_has_index tint)
              (Stmt.Ssequence
                (Stmt.Sset ___kprog_x86_mo_scale
                  (Expr.Ecast
                    (Expr.Ecast
                      (Expr.Ebinop Binop.Oand
                        (Expr.Ebinop Binop.Oshr (Expr.Etempvar _aux tulong)
                          (Expr.Econst_int (Integers.Int.repr 8) tint)
                          tulong)
                        (Expr.Econst_int (Integers.Int.repr 255) tuint)
                        tulong) tuchar) tuchar))
                (Stmt.Ssequence
                  (Stmt.Sset ___kprog_x86_mo_index
                    (Expr.Etempvar _index tulong))
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                        (Expr.Etempvar ___kprog_x86_mo_scale tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 64) tuint)
                                        tint)
                      (Stmt.Sset _t'2
                        (Expr.Ecast
                          (Expr.Ebinop Binop.Oshl
                            (Expr.Etempvar ___kprog_x86_mo_index tulong)
                            (Expr.Etempvar ___kprog_x86_mo_scale tuchar)
                            tulong) tulong))
                      (Stmt.Sset _t'2
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                          tulong)))
                    (Stmt.Sset ___kprog_x86_mo_result
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar ___kprog_x86_mo_result tulong)
                        (Expr.Etempvar _t'2 tulong) tulong)))))
              Stmt.Sskip)
            (Stmt.Sset _offset
              (Expr.Ecast (Expr.Etempvar ___kprog_x86_mo_result tulong)
                tlong))))))
    Stmt.Sbreak)
  (Stmt.Sreturn (some (Expr.Etempvar _offset tlong))))
}

def f_kprog_x86_mem_offset : Function := {
  fn_return := tlong,
  fn_callconv := cc_default,
  fn_params := [(_state, (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
                (_arena, (tptr (Ty.Tstruct _kprog_x86_arena noattr))),
                (_capacity, tuint), (_aux, tulong), (_displacement, tlong)],
  fn_vars := [],
  fn_temps := [(_offset, tlong), (___kprog_x86_mo_disp, tlong),
               (___kprog_x86_mo_has_index, tint),
               (___kprog_x86_mo_result, tulong),
               (___kprog_x86_mo_scale, tuchar),
               (___kprog_x86_mo_index, tulong), (_t'6, tulong),
               (_t'5, tulong), (_t'4, tulong), (_t'3, tint), (_t'2, tint),
               (_t'1, tint)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sset ___kprog_x86_mo_disp (Expr.Etempvar _displacement tlong))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sifthenelse (Expr.Ebinop Binop.One
                                (Expr.Ecast
                                  (Expr.Ebinop Binop.Oand
                                    (Expr.Etempvar _aux tulong)
                                    (Expr.Econst_int (Integers.Int.repr 255) tuint)
                                    tulong) tuchar)
                                (Expr.Econst_int (Integers.Int.repr 255) tuint)
                                tint)
              (Stmt.Sset _t'1
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tint)
                  tint))
              (Stmt.Sset _t'1
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                  tint)))
            (Stmt.Sifthenelse (Expr.Ecast (Expr.Etempvar _t'1 tint) tuchar)
              (Stmt.Sset _t'2
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tint)
                  tint))
              (Stmt.Sset _t'2
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                  tint))))
          (Stmt.Sset ___kprog_x86_mo_has_index (Expr.Etempvar _t'2 tint)))
        (Stmt.Ssequence
          (Stmt.Sset ___kprog_x86_mo_result
            (Expr.Ecast (Expr.Etempvar ___kprog_x86_mo_disp tlong) tulong))
          (Stmt.Ssequence
            (Stmt.Sifthenelse (Expr.Etempvar ___kprog_x86_mo_has_index tint)
              (Stmt.Ssequence
                (Stmt.Sset ___kprog_x86_mo_scale
                  (Expr.Ecast
                    (Expr.Ecast
                      (Expr.Ebinop Binop.Oand
                        (Expr.Ebinop Binop.Oshr (Expr.Etempvar _aux tulong)
                          (Expr.Econst_int (Integers.Int.repr 8) tint)
                          tulong)
                        (Expr.Econst_int (Integers.Int.repr 255) tuint)
                        tulong) tuchar) tuchar))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.One
                                          (Expr.Ecast
                                            (Expr.Ebinop Binop.Oand
                                              (Expr.Etempvar _aux tulong)
                                              (Expr.Econst_int (Integers.Int.repr 255) tuint)
                                              tulong) tuchar)
                                          (Expr.Econst_int (Integers.Int.repr 255) tuint)
                                          tint)
                        (Stmt.Sset _t'3
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 1) tint)
                            tint))
                        (Stmt.Sset _t'3
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                            tint)))
                      (Stmt.Sifthenelse (Expr.Ecast (Expr.Etempvar _t'3 tint)
                                          tuchar)
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'5)
                            (Expr.Evar _kprog_x86_read_reg (Ty.Tfunction
                                                             [(tptr (Ty.Tstruct _x86_sim_register_state noattr)),
                                                              (tptr (Ty.Tstruct _kprog_x86_arena noattr)),
                                                              tuint, tuchar,
                                                              tuchar, tuchar]
                                                             tulong
                                                             cc_default))
                            [(Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
                             (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr))),
                             (Expr.Etempvar _capacity tuint),
                             (Expr.Ecast
                               (Expr.Ebinop Binop.Oand
                                 (Expr.Etempvar _aux tulong)
                                 (Expr.Econst_int (Integers.Int.repr 255) tuint)
                                 tulong) tuchar),
                             (Expr.Econst_int (Integers.Int.repr 8) tuint),
                             (Expr.Econst_int (Integers.Int.repr 0) tuint)])
                          (Stmt.Sset _t'4
                            (Expr.Ecast (Expr.Etempvar _t'5 tulong) tulong)))
                        (Stmt.Sset _t'4
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                            tulong))))
                    (Stmt.Sset ___kprog_x86_mo_index
                      (Expr.Etempvar _t'4 tulong)))
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                        (Expr.Etempvar ___kprog_x86_mo_scale tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 64) tuint)
                                        tint)
                      (Stmt.Sset _t'6
                        (Expr.Ecast
                          (Expr.Ebinop Binop.Oshl
                            (Expr.Etempvar ___kprog_x86_mo_index tulong)
                            (Expr.Etempvar ___kprog_x86_mo_scale tuchar)
                            tulong) tulong))
                      (Stmt.Sset _t'6
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                          tulong)))
                    (Stmt.Sset ___kprog_x86_mo_result
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar ___kprog_x86_mo_result tulong)
                        (Expr.Etempvar _t'6 tulong) tulong)))))
              Stmt.Sskip)
            (Stmt.Sset _offset
              (Expr.Ecast (Expr.Etempvar ___kprog_x86_mo_result tulong)
                tlong))))))
    Stmt.Sbreak)
  (Stmt.Sreturn (some (Expr.Etempvar _offset tlong))))
}

def s_kprog_x86_read_recovery_at_0 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'42
    (Expr.Efield
      (Expr.Efield
        (Expr.Efield
          (Expr.Efield
            (Expr.Ederef
              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
              (Ty.Tstruct _x86_sim_register_state noattr))
            (Positive.ofNat 18727075383868559167) (Ty.Tunion __3115 noattr))
          (Positive.ofNat 18727075383868559167) (Ty.Tstruct __3116 noattr))
        _rsp (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
  (Stmt.Sset ___x86_write_old_sp
    (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'42 (tptr tvoid)) tlong) tlong)))

def s_kprog_x86_read_recovery_at_1 : Stmt :=
(Stmt.Sset ___x86_wr_raw_width
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tuint) tuchar))

def s_kprog_x86_read_recovery_at_2 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'36
    (Expr.Efield (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
      _ptr (tptr tvoid)))
  (Stmt.Ssequence
    (Stmt.Sset _t'37
      (Expr.Efield
        (Expr.Ederef
          (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
          (Ty.Tstruct _kprog_x86_arena noattr)) _b (tptr (tvolatile tuchar))))
    (Stmt.Sset ___x86_stack_delta
      (Expr.Ebinop Binop.Osub
        (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'36 (tptr tvoid)) tlong)
          tulong)
        (Expr.Ecast
          (Expr.Ecast
            (Expr.Ecast
              (Expr.Ecast
                (Expr.Ecast
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Ecast
                      (Expr.Ecast
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Etempvar _t'37 (tptr (tvolatile tuchar)))
                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                          (tptr (tvolatile tuchar))) tulong) tulong)
                    (Expr.Ecast
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                          tulong)
                        (Expr.Ecast (Expr.Etempvar _capacity tuint) tulong)
                        tulong) tulong) tulong) tulong) (tptr tuchar))
              (tptr tvoid)) tlong) tulong) tulong))))

def s_kprog_x86_read_recovery_at_3 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'35
    (Expr.Efield
      (Expr.Ederef
        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
        (Ty.Tstruct _x86_sim_register_state noattr)) _native_stack_base
      tulong))
  (Stmt.Sset ___x86_wr_stack_bits
    (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_stack_delta tulong)
      (Expr.Etempvar _t'35 tulong) tulong)))

def s_kprog_x86_read_recovery_at_4 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield
        (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3737 noattr)))
        _b (tvolatile (tarray tuchar 8)))
      (Expr.Econst_int (Integers.Int.repr 1) tint) (tptr tuchar)) tuchar)
  (Expr.Etempvar ___kprog_x86_lane tuchar))

def s_kprog_x86_read_recovery_at_5 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield
        (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3737 noattr)))
        _b (tvolatile (tarray tuchar 8)))
      (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tuchar)) tuchar)
  (Expr.Etempvar ___kprog_x86_lane tuchar))

def s_kprog_x86_read_recovery_at_6 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sbuiltin (some _t'5) (ExtFun.EF_vload Chunk.Mint64)
    [(tptr (tvolatile (tptr tvoid)))]
    [(Expr.Eaddrof
       (Expr.Efield
         (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3737 noattr)))
         _ptr (tvolatile (tptr tvoid))) (tptr (tvolatile (tptr tvoid))))])
  (Stmt.Sset ___kprog_x86_bits
    (Expr.Ecast
      (Expr.Ecast (Expr.Etempvar _t'5 (tvolatile (tptr tvoid))) tlong)
      tulong)))

def s_kprog_x86_read_recovery_at_7 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Etempvar ___x86_wr_shift tuchar)
                      (Expr.Econst_int (Integers.Int.repr 8) tuint) tint)
    (Stmt.Sset ___kprog_x86_bits
      (Expr.Ebinop Binop.Oor
        (Expr.Ebinop Binop.Oand (Expr.Etempvar ___kprog_x86_bits tulong)
          (Expr.Eunop Unop.Onotint
            (Expr.Econst_long (Integers.Int64.repr 65280) tulong) tulong)
          tulong)
        (Expr.Ebinop Binop.Oshl
          (Expr.Ecast (Expr.Etempvar ___kprog_x86_lane tuchar) tulong)
          (Expr.Econst_int (Integers.Int.repr 8) tint) tulong) tulong))
    (Stmt.Sset ___kprog_x86_bits
      (Expr.Ebinop Binop.Oor
        (Expr.Ebinop Binop.Oand (Expr.Etempvar ___kprog_x86_bits tulong)
          (Expr.Eunop Unop.Onotint
            (Expr.Econst_long (Integers.Int64.repr 255) tulong) tulong)
          tulong) (Expr.Etempvar ___kprog_x86_lane tuchar) tulong)))
  (Stmt.Sassign
    (Expr.Efield (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
      _ptr (tptr tvoid))
    (Expr.Ecast (Expr.Ecast (Expr.Etempvar ___kprog_x86_bits tulong) tlong)
      (tptr tvoid))))

def s_kprog_x86_read_recovery_at_8 : Stmt :=
(Stmt.Sset _t'8
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint) tuint))

def s_kprog_x86_read_recovery_at_9 : Stmt :=
(Stmt.Sset _t'8
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))

def s_kprog_x86_read_recovery_at_10 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'30
      (Expr.Efield (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
        _ptr (tptr tvoid)))
    (Stmt.Ssequence
      (Stmt.Sset _t'31
        (Expr.Efield
          (Expr.Ederef
            (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
            (Ty.Tstruct _kprog_x86_arena noattr)) _b
          (tptr (tvolatile tuchar))))
      (Stmt.Sset ___x86_stack_delta__1
        (Expr.Ebinop Binop.Osub
          (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'30 (tptr tvoid)) tlong)
            tulong)
          (Expr.Ecast
            (Expr.Ecast
              (Expr.Ecast
                (Expr.Ecast
                  (Expr.Ecast
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Ecast
                        (Expr.Ecast
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar _t'31 (tptr (tvolatile tuchar)))
                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                            (tptr (tvolatile tuchar))) tulong) tulong)
                      (Expr.Ecast
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                            tulong)
                          (Expr.Ecast (Expr.Etempvar _capacity tuint) tulong)
                          tulong) tulong) tulong) tulong) (tptr tuchar))
                (tptr tvoid)) tlong) tulong) tulong))))
  (Stmt.Ssequence
    (Stmt.Sset _t'29
      (Expr.Efield
        (Expr.Ederef
          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
          (Ty.Tstruct _x86_sim_register_state noattr)) _native_stack_base
        tulong))
    (Stmt.Sset ___x86_wr_stack_bits__1
      (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_stack_delta__1 tulong)
        (Expr.Etempvar _t'29 tulong) tulong))))

def s_kprog_x86_read_recovery_at_11 : Stmt :=
Stmt.Sbreak

def s_kprog_x86_read_recovery_at_12 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'28
    (Expr.Efield (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
      _ptr (tptr tvoid)))
  (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
    [(tptr (tvolatile (tptr tvoid))), (tvolatile (tptr tvoid))]
    [(Expr.Eaddrof
       (Expr.Efield
         (Expr.Evar ___kprog_x86_partial__1 (tvolatile (Ty.Tunion __3743 noattr)))
         _ptr (tvolatile (tptr tvoid))) (tptr (tvolatile (tptr tvoid)))),
     (Expr.Etempvar _t'28 (tptr tvoid))]))

def s_kprog_x86_read_recovery_at_13 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint16unsigned)
    [(tptr (tvolatile tushort)), (tvolatile tushort)]
    [(Expr.Eaddrof
       (Expr.Efield
         (Expr.Evar ___kprog_x86_partial__1 (tvolatile (Ty.Tunion __3743 noattr)))
         _w (tvolatile tushort)) (tptr (tvolatile tushort))),
     (Expr.Etempvar ___kprog_x86_lane__1 tushort)])
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sbuiltin (some _t'6) (ExtFun.EF_vload Chunk.Mint64)
        [(tptr (tvolatile (tptr tvoid)))]
        [(Expr.Eaddrof
           (Expr.Efield
             (Expr.Evar ___kprog_x86_partial__1 (tvolatile (Ty.Tunion __3743 noattr)))
             _ptr (tvolatile (tptr tvoid))) (tptr (tvolatile (tptr tvoid))))])
      (Stmt.Sset ___kprog_x86_bits__1
        (Expr.Ecast
          (Expr.Ecast (Expr.Etempvar _t'6 (tvolatile (tptr tvoid))) tlong)
          tulong)))
    (Stmt.Sassign
      (Expr.Efield (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
        _ptr (tptr tvoid))
      (Expr.Ecast
        (Expr.Ecast
          (Expr.Ebinop Binop.Oor
            (Expr.Ebinop Binop.Oand
              (Expr.Etempvar ___kprog_x86_bits__1 tulong)
              (Expr.Eunop Unop.Onotint
                (Expr.Econst_long (Integers.Int64.repr 65535) tulong) tulong)
              tulong) (Expr.Etempvar ___kprog_x86_lane__1 tushort) tulong)
          tlong) (tptr tvoid)))))

def s_kprog_x86_read_recovery_at_14 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'7
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint) tuint))
    (Stmt.Sset _t'7 (Expr.Ecast (Expr.Etempvar _t'7 tuint) tuint)))
  (Stmt.Sset _t'7 (Expr.Ecast (Expr.Etempvar _t'7 tuint) tuint)))

def s_kprog_x86_read_recovery_at_15 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'7
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))
    (Stmt.Sset _t'7 (Expr.Ecast (Expr.Etempvar _t'7 tuint) tuint)))
  (Stmt.Sset _t'7 (Expr.Ecast (Expr.Etempvar _t'7 tuint) tuint)))

def s_kprog_x86_read_recovery_at_16 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset ___x86_release_i (Expr.Econst_int (Integers.Int.repr 0) tint))
    (Stmt.Sloop
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                            (Expr.Etempvar ___x86_release_i tuint)
                            (Expr.Etempvar _capacity tuint) tint)
          Stmt.Sskip
          Stmt.Sbreak)
        (Stmt.Ssequence
          (Stmt.Sset ___x86_release_off
            (Expr.Ebinop Binop.Osub
              (Expr.Ecast (Expr.Etempvar ___x86_release_i tuint) tlong)
              (Expr.Ecast (Expr.Etempvar _capacity tuint) tlong) tlong))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Ole
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Etempvar ___x86_release_i tuint)
                                    (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                    tuint) (Expr.Etempvar _capacity tuint)
                                  tint)
                (Stmt.Sset _t'14
                  (Expr.Ecast
                    (Expr.Ebinop Binop.Oge
                      (Expr.Etempvar ___x86_release_off tlong)
                      (Expr.Etempvar ___x86_release_old tlong) tint) tbool))
                (Stmt.Sset _t'14
                  (Expr.Econst_int (Integers.Int.repr 0) tint)))
              (Stmt.Sifthenelse (Expr.Etempvar _t'14 tint)
                (Stmt.Sset _t'15
                  (Expr.Ecast
                    (Expr.Ebinop Binop.Ole
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar ___x86_release_off tlong)
                        (Expr.Econst_int (Integers.Int.repr 8) tint) tlong)
                      (Expr.Etempvar ___x86_release_new tlong) tint) tbool))
                (Stmt.Sset _t'15
                  (Expr.Econst_int (Integers.Int.repr 0) tint))))
            (Stmt.Sifthenelse (Expr.Etempvar _t'15 tint)
              (Stmt.Ssequence
                (Stmt.Scall (some _t'10)
                  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                       tulong cc_default))
                  [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                (Stmt.Ssequence
                  (Stmt.Sset _t'24
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                        (Ty.Tstruct _kprog_x86_arena noattr)) _q
                      (tptr (tvolatile tulong))))
                  (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
                    [(tptr (tvolatile tulong)), (tvolatile tulong)]
                    [(Expr.Eaddrof
                       (Expr.Ederef
                         (Expr.Ebinop Binop.Oadd
                           (Expr.Etempvar _t'24 (tptr (tvolatile tulong)))
                           (Expr.Ebinop Binop.Odiv
                             (Expr.Etempvar ___x86_release_i tuint)
                             (Expr.Econst_int (Integers.Int.repr 8) tuint)
                             tuint) (tptr (tvolatile tulong)))
                         (tvolatile tulong)) (tptr (tvolatile tulong))),
                     (Expr.Etempvar _t'10 tulong)])))
              (Stmt.Ssequence
                (Stmt.Sset ___x86_release_lane
                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                        (Expr.Etempvar ___x86_release_lane tuint)
                                        (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                        tint)
                      Stmt.Sskip
                      Stmt.Sbreak)
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                            (Expr.Ebinop Binop.Oadd
                                              (Expr.Etempvar ___x86_release_i tuint)
                                              (Expr.Etempvar ___x86_release_lane tuint)
                                              tuint)
                                            (Expr.Etempvar _capacity tuint)
                                            tint)
                          (Stmt.Sset _t'12
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Oge
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Etempvar ___x86_release_off tlong)
                                  (Expr.Etempvar ___x86_release_lane tuint)
                                  tlong)
                                (Expr.Etempvar ___x86_release_old tlong)
                                tint) tbool))
                          (Stmt.Sset _t'12
                            (Expr.Econst_int (Integers.Int.repr 0) tint)))
                        (Stmt.Sifthenelse (Expr.Etempvar _t'12 tint)
                          (Stmt.Sset _t'13
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Olt
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Etempvar ___x86_release_off tlong)
                                  (Expr.Etempvar ___x86_release_lane tuint)
                                  tlong)
                                (Expr.Etempvar ___x86_release_new tlong)
                                tint) tbool))
                          (Stmt.Sset _t'13
                            (Expr.Econst_int (Integers.Int.repr 0) tint))))
                      (Stmt.Sifthenelse (Expr.Etempvar _t'13 tint)
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'11)
                            (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                 [tuint]
                                                                 tulong
                                                                 cc_default))
                            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                          (Stmt.Ssequence
                            (Stmt.Sset _t'23
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                                  (Ty.Tstruct _kprog_x86_arena noattr)) _b
                                (tptr (tvolatile tuchar))))
                            (Stmt.Sbuiltin none
                              (ExtFun.EF_vstore Chunk.Mint8unsigned)
                              [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
                              [(Expr.Eaddrof
                                 (Expr.Ederef
                                   (Expr.Ebinop Binop.Oadd
                                     (Expr.Etempvar _t'23 (tptr (tvolatile tuchar)))
                                     (Expr.Ebinop Binop.Oadd
                                       (Expr.Etempvar ___x86_release_i tuint)
                                       (Expr.Etempvar ___x86_release_lane tuint)
                                       tuint) (tptr (tvolatile tuchar)))
                                   (tvolatile tuchar))
                                 (tptr (tvolatile tuchar))),
                               (Expr.Ecast (Expr.Etempvar _t'11 tulong)
                                 tuchar)])))
                        Stmt.Sskip)))
                  (Stmt.Sset ___x86_release_lane
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Etempvar ___x86_release_lane tuint)
                      (Expr.Econst_int (Integers.Int.repr 1) tint) tuint))))))))
      (Stmt.Sset ___x86_release_i
        (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_release_i tuint)
          (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint))))
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sset _t'22
          (Expr.Efield
            (Expr.Efield
              (Expr.Efield
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                    (Ty.Tstruct _x86_sim_register_state noattr))
                  (Positive.ofNat 18727075383868559167)
                  (Ty.Tunion __3115 noattr))
                (Positive.ofNat 18727075383868559167)
                (Ty.Tstruct __3116 noattr)) _rsp
              (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
        (Stmt.Sset ___x86_sv_sp
          (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'22 (tptr tvoid)) tlong)
            tlong)))
      (Stmt.Ssequence
        (Stmt.Sset ___x86_sv_i (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Sloop
          (Stmt.Ssequence
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                (Expr.Etempvar ___x86_sv_i tuint)
                                (Expr.Ebinop Binop.Odiv
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Ecast
                                      (Expr.Etempvar _capacity tuint) tulong)
                                    (Expr.Econst_int (Integers.Int.repr 7) tuint)
                                    tulong)
                                  (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                  tulong) tint)
              Stmt.Sskip
              Stmt.Sbreak)
            (Stmt.Sloop
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                  (Expr.Ebinop Binop.Osub
                                    (Expr.Ecast
                                      (Expr.Ebinop Binop.Omul
                                        (Expr.Ecast
                                          (Expr.Etempvar ___x86_sv_i tuint)
                                          tulong)
                                        (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                        tulong) tlong)
                                    (Expr.Ecast
                                      (Expr.Etempvar _capacity tuint) tlong)
                                    tlong) (Expr.Etempvar ___x86_sv_sp tlong)
                                  tint)
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sset _t'21
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                              (Expr.Etempvar ___x86_sv_i tuint)
                              (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                            (Ty.Tstruct _kprog_x86_stack_fact noattr)) _tag
                          (tptr tuchar)))
                      (Stmt.Sassign
                        (Expr.Ederef (Expr.Etempvar _t'21 (tptr tuchar))
                          tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tuint)))
                    (Stmt.Ssequence
                      (Stmt.Sset _t'20
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                              (Expr.Etempvar ___x86_sv_i tuint)
                              (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                            (Ty.Tstruct _kprog_x86_stack_fact noattr))
                          _pointer (tptr (tptr tvoid))))
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Etempvar _t'20 (tptr (tptr tvoid)))
                          (tptr tvoid))
                        (Expr.Econst_int (Integers.Int.repr 0) tint))))
                  Stmt.Sbreak)
                Stmt.Sskip)
              Stmt.Sbreak))
          (Stmt.Sset ___x86_sv_i
            (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_sv_i tuint)
              (Expr.Econst_int (Integers.Int.repr 1) tint) tuint)))))
    Stmt.Sbreak))

def s_kprog_x86_read_recovery_at_17 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Scall (some _t'2)
      (Expr.Evar _x86_width_effective (Ty.Tfunction [tuchar] tuchar
                                        cc_default))
      [(Expr.Etempvar ___x86_wr_raw_width tuchar)])
    (Stmt.Sset ___x86_wr_width
      (Expr.Ecast (Expr.Etempvar _t'2 tuchar) tuchar)))
  (Stmt.Ssequence
    (Stmt.Sset ___x86_wr_shift
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuchar))
    (Stmt.Ssequence
      (Stmt.Sset ___x86_wr_next
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) tulong))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                              (Expr.Ecast (Expr.Etempvar _dst tulong) tulong)
                              (Expr.Econst_int (Integers.Int.repr 16) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Sset _t'41
                (Expr.Efield
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                              (Ty.Tstruct _x86_sim_register_state noattr))
                            (Positive.ofNat 18727075383868559167)
                            (Ty.Tunion __3115 noattr)) _gpr_cells
                          (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                        (Expr.Ecast (Expr.Etempvar _dst tulong) tuchar)
                        (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                      (Ty.Tstruct _x86_sim_gpr_cell noattr)) _value
                    (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
              (Stmt.Sset _t'3
                (Expr.Ecast (Expr.Etempvar _t'41 (tptr tvoid)) (tptr tvoid))))
            (Stmt.Sset _t'3
              (Expr.Ecast
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                  (tptr tvoid)) (tptr tvoid))))
          (Stmt.Sassign
            (Expr.Efield
              (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr)) _ptr
              (tptr tvoid)) (Expr.Etempvar _t'3 (tptr tvoid))))
        (Stmt.Ssequence
          (Stmt.Sloop
            (Stmt.Ssequence
              (Stmt.Sset ___x86_tag_reg__1 (Expr.Etempvar _dst tulong))
              (Stmt.Ssequence
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                    (Expr.Etempvar ___x86_tag_reg__1 tulong)
                                    (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                    tint)
                  (Stmt.Ssequence
                    (Stmt.Sset _t'40
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                  (Ty.Tstruct _x86_sim_register_state noattr))
                                (Positive.ofNat 18727075383868559167)
                                (Ty.Tunion __3115 noattr)) _gpr_cells
                              (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                            (Expr.Ecast
                              (Expr.Etempvar ___x86_tag_reg__1 tulong)
                              tuchar)
                            (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                          (Ty.Tstruct _x86_sim_gpr_cell noattr)) _tag tuchar))
                    (Stmt.Sset _t'4
                      (Expr.Ecast (Expr.Etempvar _t'40 tuchar) tuint)))
                  (Stmt.Sset _t'4
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                      tuint)))
                (Stmt.Sset ___x86_wr_cell_tag
                  (Expr.Ecast (Expr.Etempvar _t'4 tuint) tuchar))))
            Stmt.Sbreak)
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Ecast
                                    (Expr.Etempvar ___x86_wr_width tuchar)
                                    tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                  tint)
                (Stmt.Sset _t'9
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                    tuint))
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Ecast
                                      (Expr.Etempvar ___x86_wr_width tuchar)
                                      tuchar)
                                    (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                    tint)
                  (Stmt.Ssequence
                    (Stmt.Sset _t'9
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
                    (Stmt.Sset _t'9
                      (Expr.Ecast (Expr.Etempvar _t'9 tuint) tuint)))
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Ecast
                                        (Expr.Etempvar ___x86_wr_width tuchar)
                                        tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sset _t'9
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 2) tuint)
                            tuint))
                        (Stmt.Sset _t'9
                          (Expr.Ecast (Expr.Etempvar _t'9 tuint) tuint)))
                      (Stmt.Sset _t'9
                        (Expr.Ecast (Expr.Etempvar _t'9 tuint) tuint)))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sset _t'9
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 3) tuint)
                            tuint))
                        (Stmt.Sset _t'9
                          (Expr.Ecast (Expr.Etempvar _t'9 tuint) tuint)))
                      (Stmt.Sset _t'9
                        (Expr.Ecast (Expr.Etempvar _t'9 tuint) tuint))))))
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar _t'9 tuint)
                                  (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                  tint)
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar _dst tulong)
                                      (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Sset _t'38
                        (Expr.Efield
                          (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                          _ptr (tptr tvoid)))
                      (Stmt.Ssequence
                        (Stmt.Sset _t'39
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                              (Ty.Tstruct _x86_sim_register_state noattr))
                            _native_stack_base tulong))
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                            _ptr (tptr tvoid))
                          (Expr.Ecast
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Etempvar _t'38 (tptr tvoid)) tlong)
                                  tulong) (Expr.Etempvar _t'39 tulong)
                                tulong) tlong) (tptr tvoid)))))
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                        tint)
                      (Stmt.Ssequence
                        (Stmt.Sloop
                          (Stmt.Ssequence
                            s_kprog_x86_read_recovery_at_2
                            s_kprog_x86_read_recovery_at_3)
                          Stmt.Sbreak)
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                            _ptr (tptr tvoid))
                          (Expr.Ecast
                            (Expr.Ecast
                              (Expr.Etempvar ___x86_wr_stack_bits tulong)
                              tlong) (tptr tvoid))))
                      Stmt.Sskip))
                  (Stmt.Sloop
                    (Stmt.Ssequence
                      (Stmt.Sset ___kprog_x86_lane
                        (Expr.Ecast (Expr.Etempvar ___x86_wr_next tulong)
                          tuchar))
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                                            (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                            tint)
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Etempvar ___x86_wr_shift tuchar)
                                              (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                              tint)
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                                    _b (tarray tuchar 8))
                                  (Expr.Econst_int (Integers.Int.repr 1) tint)
                                  (tptr tuchar)) tuchar)
                              (Expr.Etempvar ___kprog_x86_lane tuchar))
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                                    _b (tarray tuchar 8))
                                  (Expr.Econst_int (Integers.Int.repr 0) tint)
                                  (tptr tuchar)) tuchar)
                              (Expr.Etempvar ___kprog_x86_lane tuchar)))
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Sset _t'34
                                (Expr.Efield
                                  (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                                  _ptr (tptr tvoid)))
                              (Stmt.Sbuiltin none
                                (ExtFun.EF_vstore Chunk.Mint64)
                                [(tptr (tvolatile (tptr tvoid))),
                                 (tvolatile (tptr tvoid))]
                                [(Expr.Eaddrof
                                   (Expr.Efield
                                     (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3737 noattr)))
                                     _ptr (tvolatile (tptr tvoid)))
                                   (tptr (tvolatile (tptr tvoid)))),
                                 (Expr.Etempvar _t'34 (tptr tvoid))]))
                            (Stmt.Ssequence
                              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                  (Expr.Etempvar ___x86_wr_shift tuchar)
                                                  (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                                  tint)
                                s_kprog_x86_read_recovery_at_4
                                s_kprog_x86_read_recovery_at_5)
                              (Stmt.Ssequence
                                s_kprog_x86_read_recovery_at_6
                                s_kprog_x86_read_recovery_at_7))))
                        (Stmt.Sset ___x86_wr_cell_tag
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tuint)
                            tuchar))))
                    Stmt.Sbreak))
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Ecast
                                        (Expr.Etempvar ___x86_wr_width tuchar)
                                        tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                      tint)
                    (Stmt.Sset _t'8
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 0) tuint) tuint))
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Ecast
                                          (Expr.Etempvar ___x86_wr_width tuchar)
                                          tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                        tint)
                      (Stmt.Ssequence
                        (Stmt.Sset _t'8
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 1) tuint)
                            tuint))
                        (Stmt.Sset _t'8
                          (Expr.Ecast (Expr.Etempvar _t'8 tuint) tuint)))
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Ecast
                                            (Expr.Etempvar ___x86_wr_width tuchar)
                                            tuchar)
                                          (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                          tint)
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            s_kprog_x86_read_recovery_at_8
                            (Stmt.Sset _t'8
                              (Expr.Ecast (Expr.Etempvar _t'8 tuint) tuint)))
                          (Stmt.Sset _t'8
                            (Expr.Ecast (Expr.Etempvar _t'8 tuint) tuint)))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            s_kprog_x86_read_recovery_at_9
                            (Stmt.Sset _t'8
                              (Expr.Ecast (Expr.Etempvar _t'8 tuint) tuint)))
                          (Stmt.Sset _t'8
                            (Expr.Ecast (Expr.Etempvar _t'8 tuint) tuint))))))
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar _t'8 tuint)
                                      (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Etempvar _dst tulong)
                                          (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                          tint)
                        (Stmt.Ssequence
                          (Stmt.Sset _t'32
                            (Expr.Efield
                              (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                              _ptr (tptr tvoid)))
                          (Stmt.Ssequence
                            (Stmt.Sset _t'33
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                  (Ty.Tstruct _x86_sim_register_state noattr))
                                _native_stack_base tulong))
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                                _ptr (tptr tvoid))
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Ecast
                                      (Expr.Ecast
                                        (Expr.Etempvar _t'32 (tptr tvoid))
                                        tlong) tulong)
                                    (Expr.Etempvar _t'33 tulong) tulong)
                                  tlong) (tptr tvoid)))))
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                                            (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                            tint)
                          (Stmt.Ssequence
                            (Stmt.Sloop
                              s_kprog_x86_read_recovery_at_10
                              s_kprog_x86_read_recovery_at_11)
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                                _ptr (tptr tvoid))
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Etempvar ___x86_wr_stack_bits__1 tulong)
                                  tlong) (tptr tvoid))))
                          Stmt.Sskip))
                      (Stmt.Sloop
                        (Stmt.Ssequence
                          (Stmt.Sset ___kprog_x86_lane__1
                            (Expr.Ecast (Expr.Etempvar ___x86_wr_next tulong)
                              tushort))
                          (Stmt.Ssequence
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                                                (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                                tint)
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                                  _w tushort)
                                (Expr.Etempvar ___kprog_x86_lane__1 tushort))
                              (Stmt.Ssequence
                                s_kprog_x86_read_recovery_at_12
                                s_kprog_x86_read_recovery_at_13))
                            (Stmt.Sset ___x86_wr_cell_tag
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                tuchar))))
                        Stmt.Sbreak))
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Ecast
                                            (Expr.Etempvar ___x86_wr_width tuchar)
                                            tuchar)
                                          (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                          tint)
                        (Stmt.Sset _t'7
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tuint)
                            tuint))
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Ecast
                                              (Expr.Etempvar ___x86_wr_width tuchar)
                                              tuchar)
                                            (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                            tint)
                          (Stmt.Ssequence
                            (Stmt.Sset _t'7
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                tuint))
                            (Stmt.Sset _t'7
                              (Expr.Ecast (Expr.Etempvar _t'7 tuint) tuint)))
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Ecast
                                                (Expr.Etempvar ___x86_wr_width tuchar)
                                                tuchar)
                                              (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                              tint)
                            s_kprog_x86_read_recovery_at_14
                            s_kprog_x86_read_recovery_at_15)))
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Etempvar _t'7 tuint)
                                          (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                          tint)
                        (Stmt.Ssequence
                          (Stmt.Sset ___x86_wr_next
                            (Expr.Ecast
                              (Expr.Ecast
                                (Expr.Etempvar ___x86_wr_next tulong) tuint)
                              tulong))
                          (Stmt.Sloop
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                                  _ptr (tptr tvoid))
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Ecast
                                      (Expr.Etempvar ___x86_wr_next tulong)
                                      tuint) tlong) (tptr tvoid)))
                              (Stmt.Sset ___x86_wr_cell_tag
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                  tuchar)))
                            Stmt.Sbreak))
                        (Stmt.Sloop
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                                _ptr (tptr tvoid))
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Etempvar ___x86_wr_next tulong)
                                    tulong) tlong) (tptr tvoid)))
                            (Stmt.Sset ___x86_wr_cell_tag
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                tuchar)))
                          Stmt.Sbreak)))))))
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar _dst tulong)
                                  (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                  tint)
                (Stmt.Ssequence
                  (Stmt.Sset _t'26
                    (Expr.Efield
                      (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                      _ptr (tptr tvoid)))
                  (Stmt.Ssequence
                    (Stmt.Sset _t'27
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                          (Ty.Tstruct _x86_sim_register_state noattr))
                        _native_stack_base tulong))
                    (Stmt.Sassign
                      (Expr.Efield
                        (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                        _ptr (tptr tvoid))
                      (Expr.Ecast
                        (Expr.Ecast
                          (Expr.Ebinop Binop.Osub
                            (Expr.Ecast
                              (Expr.Ecast (Expr.Etempvar _t'26 (tptr tvoid))
                                tlong) tulong) (Expr.Etempvar _t'27 tulong)
                            tulong) tlong) (tptr tvoid)))))
                Stmt.Sskip)
              (Stmt.Ssequence
                (Stmt.Sset ___x86_wr_next_ptr
                  (Expr.Efield
                    (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                    _ptr (tptr tvoid)))
                (Stmt.Ssequence
                  (Stmt.Sset ___x86_wr_next_tag
                    (Expr.Ecast (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                      tuchar))
                  (Stmt.Ssequence
                    (Stmt.Sloop
                      (Stmt.Ssequence
                        (Stmt.Sset ___x86_store_reg
                          (Expr.Etempvar _dst tulong))
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                            (Expr.Etempvar ___x86_store_reg tulong)
                                            (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                            tint)
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Efield
                                        (Expr.Efield
                                          (Expr.Ederef
                                            (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                            (Ty.Tstruct _x86_sim_register_state noattr))
                                          (Positive.ofNat 18727075383868559167)
                                          (Ty.Tunion __3115 noattr))
                                        _gpr_cells
                                        (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                                      (Expr.Ecast
                                        (Expr.Etempvar ___x86_store_reg tulong)
                                        tuchar)
                                      (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                                    (Ty.Tstruct _x86_sim_gpr_cell noattr))
                                  _value (Ty.Tunion _x86_sim_gpr noattr))
                                _ptr (tptr tvoid))
                              (Expr.Etempvar ___x86_wr_next_ptr (tptr tvoid)))
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Efield
                                        (Expr.Ederef
                                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                          (Ty.Tstruct _x86_sim_register_state noattr))
                                        (Positive.ofNat 18727075383868559167)
                                        (Ty.Tunion __3115 noattr)) _gpr_cells
                                      (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                                    (Expr.Ecast
                                      (Expr.Etempvar ___x86_store_reg tulong)
                                      tuchar)
                                    (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                                  (Ty.Tstruct _x86_sim_gpr_cell noattr)) _tag
                                tuchar)
                              (Expr.Etempvar ___x86_wr_next_tag tuchar)))
                          Stmt.Sskip))
                      Stmt.Sbreak)
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Etempvar _dst tulong)
                                        (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                        tint)
                      (Stmt.Sloop
                        (Stmt.Ssequence
                          (Stmt.Sset ___x86_release_old
                            (Expr.Etempvar ___x86_write_old_sp tlong))
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Sset _t'25
                                (Expr.Efield
                                  (Expr.Efield
                                    (Expr.Efield
                                      (Expr.Efield
                                        (Expr.Ederef
                                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                          (Ty.Tstruct _x86_sim_register_state noattr))
                                        (Positive.ofNat 18727075383868559167)
                                        (Ty.Tunion __3115 noattr))
                                      (Positive.ofNat 18727075383868559167)
                                      (Ty.Tstruct __3116 noattr)) _rsp
                                    (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                                  (tptr tvoid)))
                              (Stmt.Sset ___x86_release_new
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Etempvar _t'25 (tptr tvoid)) tlong)
                                  tlong)))
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Ogt
                                                (Expr.Etempvar ___x86_release_new tlong)
                                                (Expr.Etempvar ___x86_release_old tlong)
                                                tint)
                              s_kprog_x86_read_recovery_at_16
                              Stmt.Sskip)))
                        Stmt.Sbreak)
                      Stmt.Sskip)))))))))))

def f_kprog_x86_read_recovery_at : Function := {
  fn_return := tint,
  fn_callconv := cc_default,
  fn_params := [(_state, (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
                (_arena, (tptr (Ty.Tstruct _kprog_x86_arena noattr))),
                (_facts, (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr))),
                (_capacity, tuint), (_base, tulong), (_dst, tulong),
                (_address, tulong)],
  fn_vars := [(___x86_wr_cell, (Ty.Tunion _x86_sim_gpr noattr)),
              (___kprog_x86_partial, (tvolatile (Ty.Tunion __3737 noattr))),
              (___kprog_x86_partial__1,
               (tvolatile (Ty.Tunion __3743 noattr)))],
  fn_temps := [(___x86_state,
                (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
               (_recovered, tint), (___x86_read_recovered, tint),
               (___x86_read_tag, tuchar), (___x86_tag_reg, tulong),
               (___x86_write_old_sp, tlong), (___x86_wr_raw_width, tuchar),
               (___x86_wr_width, tuchar), (___x86_wr_shift, tuchar),
               (___x86_wr_next, tulong), (___x86_wr_cell_tag, tuchar),
               (___x86_tag_reg__1, tulong), (___x86_wr_stack_bits, tulong),
               (___x86_stack_delta, tulong), (___kprog_x86_lane, tuchar),
               (___kprog_x86_bits, tulong),
               (___x86_wr_stack_bits__1, tulong),
               (___x86_stack_delta__1, tulong),
               (___kprog_x86_lane__1, tushort),
               (___kprog_x86_bits__1, tulong),
               (___x86_wr_next_ptr, (tptr tvoid)),
               (___x86_wr_next_tag, tuchar), (___x86_store_reg, tulong),
               (___x86_release_old, tlong), (___x86_release_new, tlong),
               (___x86_release_i, tuint), (___x86_release_off, tlong),
               (___x86_release_lane, tuint), (___x86_sv_sp, tlong),
               (___x86_sv_i, tuint), (_t'19, tint), (_t'18, tint),
               (_t'17, tulong), (_t'16, tint), (_t'15, tint), (_t'14, tint),
               (_t'13, tint), (_t'12, tint), (_t'11, tulong),
               (_t'10, tulong), (_t'9, tuint), (_t'8, tuint), (_t'7, tuint),
               (_t'6, (tvolatile (tptr tvoid))),
               (_t'5, (tvolatile (tptr tvoid))), (_t'4, tuint),
               (_t'3, (tptr tvoid)), (_t'2, tuchar), (_t'1, tuint),
               (_t'43, tuchar), (_t'42, (tptr tvoid)), (_t'41, (tptr tvoid)),
               (_t'40, tuchar), (_t'39, tulong), (_t'38, (tptr tvoid)),
               (_t'37, (tptr (tvolatile tuchar))), (_t'36, (tptr tvoid)),
               (_t'35, tulong), (_t'34, (tptr tvoid)), (_t'33, tulong),
               (_t'32, (tptr tvoid)), (_t'31, (tptr (tvolatile tuchar))),
               (_t'30, (tptr tvoid)), (_t'29, tulong), (_t'28, (tptr tvoid)),
               (_t'27, tulong), (_t'26, (tptr tvoid)), (_t'25, (tptr tvoid)),
               (_t'24, (tptr (tvolatile tulong))),
               (_t'23, (tptr (tvolatile tuchar))), (_t'22, (tptr tvoid)),
               (_t'21, (tptr tuchar)), (_t'20, (tptr (tptr tvoid)))],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_state
    (Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))))
  (Stmt.Ssequence
    (Stmt.Sloop
      (Stmt.Ssequence
        (Stmt.Sset ___x86_read_recovered
          (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.One
                                  (Expr.Etempvar _base tulong)
                                  (Expr.Econst_int (Integers.Int.repr 255) tuint)
                                  tint)
                (Stmt.Sset _t'18
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tint)
                    tint))
                (Stmt.Sset _t'18
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                    tint)))
              (Stmt.Sifthenelse (Expr.Ecast (Expr.Etempvar _t'18 tint)
                                  tuchar)
                (Stmt.Sset _t'19
                  (Expr.Ecast
                    (Expr.Ebinop Binop.One (Expr.Etempvar _base tulong)
                      (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
                    tbool))
                (Stmt.Sset _t'19
                  (Expr.Econst_int (Integers.Int.repr 0) tint))))
            (Stmt.Sifthenelse (Expr.Etempvar _t'19 tint)
              (Stmt.Ssequence
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Sset ___x86_tag_reg (Expr.Etempvar _base tulong))
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                          (Expr.Etempvar ___x86_tag_reg tulong)
                                          (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                          tint)
                        (Stmt.Ssequence
                          (Stmt.Sset _t'43
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Efield
                                      (Expr.Ederef
                                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                        (Ty.Tstruct _x86_sim_register_state noattr))
                                      (Positive.ofNat 18727075383868559167)
                                      (Ty.Tunion __3115 noattr)) _gpr_cells
                                    (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                                  (Expr.Ecast
                                    (Expr.Etempvar ___x86_tag_reg tulong)
                                    tuchar)
                                  (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                                (Ty.Tstruct _x86_sim_gpr_cell noattr)) _tag
                              tuchar))
                          (Stmt.Sset _t'1
                            (Expr.Ecast (Expr.Etempvar _t'43 tuchar) tuint)))
                        (Stmt.Sset _t'1
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tuint)
                            tuint)))
                      (Stmt.Sset ___x86_read_tag
                        (Expr.Ecast (Expr.Etempvar _t'1 tuint) tuchar))))
                  Stmt.Sbreak)
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar ___x86_read_tag tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                      tint)
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                        (Expr.Ecast
                                          (Expr.Etempvar _address tulong)
                                          tulong)
                                        (Expr.Econst_int (Integers.Int.repr 4096) tuint)
                                        tint)
                      (Stmt.Sset _t'16
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 1) tint) tbool))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'17)
                            (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                 [tuint]
                                                                 tulong
                                                                 cc_default))
                            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                          (Stmt.Sset _t'16
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Oand
                                (Expr.Etempvar _t'17 tulong)
                                (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                tulong) tbool)))
                        (Stmt.Sset _t'16
                          (Expr.Ecast (Expr.Etempvar _t'16 tint) tbool))))
                    (Stmt.Sset _t'16
                      (Expr.Econst_int (Integers.Int.repr 0) tint)))
                  (Stmt.Sifthenelse (Expr.Etempvar _t'16 tint)
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Etempvar _dst tulong)
                                          (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                          tint)
                        (Stmt.Scall none
                          (Expr.Evar _kprog_c_trap (Ty.Tfunction [] tvoid
                                                     cc_default)) [])
                        (Stmt.Sloop
                          (Stmt.Ssequence
                            s_kprog_x86_read_recovery_at_0
                            (Stmt.Ssequence
                              s_kprog_x86_read_recovery_at_1
                              s_kprog_x86_read_recovery_at_17))
                          Stmt.Sbreak))
                      (Stmt.Sset ___x86_read_recovered
                        (Expr.Econst_int (Integers.Int.repr 1) tint)))
                    Stmt.Sskip)))
              Stmt.Sskip))
          (Stmt.Sset _recovered (Expr.Etempvar ___x86_read_recovered tint))))
      Stmt.Sbreak)
    (Stmt.Sreturn (some (Expr.Etempvar _recovered tint)))))
}

def s_kprog_x86_read_recovery_0 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'43
    (Expr.Efield
      (Expr.Efield
        (Expr.Efield
          (Expr.Efield
            (Expr.Ederef
              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
              (Ty.Tstruct _x86_sim_register_state noattr))
            (Positive.ofNat 18727075383868559167) (Ty.Tunion __3115 noattr))
          (Positive.ofNat 18727075383868559167) (Ty.Tstruct __3116 noattr))
        _rsp (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
  (Stmt.Sset ___x86_write_old_sp
    (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'43 (tptr tvoid)) tlong) tlong)))

def s_kprog_x86_read_recovery_1 : Stmt :=
(Stmt.Sset ___x86_wr_raw_width
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tuint) tuchar))

def s_kprog_x86_read_recovery_2 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'37
    (Expr.Efield (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
      _ptr (tptr tvoid)))
  (Stmt.Ssequence
    (Stmt.Sset _t'38
      (Expr.Efield
        (Expr.Ederef
          (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
          (Ty.Tstruct _kprog_x86_arena noattr)) _b (tptr (tvolatile tuchar))))
    (Stmt.Sset ___x86_stack_delta
      (Expr.Ebinop Binop.Osub
        (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'37 (tptr tvoid)) tlong)
          tulong)
        (Expr.Ecast
          (Expr.Ecast
            (Expr.Ecast
              (Expr.Ecast
                (Expr.Ecast
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Ecast
                      (Expr.Ecast
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Etempvar _t'38 (tptr (tvolatile tuchar)))
                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                          (tptr (tvolatile tuchar))) tulong) tulong)
                    (Expr.Ecast
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                          tulong)
                        (Expr.Ecast (Expr.Etempvar _capacity tuint) tulong)
                        tulong) tulong) tulong) tulong) (tptr tuchar))
              (tptr tvoid)) tlong) tulong) tulong))))

def s_kprog_x86_read_recovery_3 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'36
    (Expr.Efield
      (Expr.Ederef
        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
        (Ty.Tstruct _x86_sim_register_state noattr)) _native_stack_base
      tulong))
  (Stmt.Sset ___x86_wr_stack_bits
    (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_stack_delta tulong)
      (Expr.Etempvar _t'36 tulong) tulong)))

def s_kprog_x86_read_recovery_4 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield
        (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3780 noattr)))
        _b (tvolatile (tarray tuchar 8)))
      (Expr.Econst_int (Integers.Int.repr 1) tint) (tptr tuchar)) tuchar)
  (Expr.Etempvar ___kprog_x86_lane tuchar))

def s_kprog_x86_read_recovery_5 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield
        (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3780 noattr)))
        _b (tvolatile (tarray tuchar 8)))
      (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tuchar)) tuchar)
  (Expr.Etempvar ___kprog_x86_lane tuchar))

def s_kprog_x86_read_recovery_6 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sbuiltin (some _t'5) (ExtFun.EF_vload Chunk.Mint64)
    [(tptr (tvolatile (tptr tvoid)))]
    [(Expr.Eaddrof
       (Expr.Efield
         (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3780 noattr)))
         _ptr (tvolatile (tptr tvoid))) (tptr (tvolatile (tptr tvoid))))])
  (Stmt.Sset ___kprog_x86_bits
    (Expr.Ecast
      (Expr.Ecast (Expr.Etempvar _t'5 (tvolatile (tptr tvoid))) tlong)
      tulong)))

def s_kprog_x86_read_recovery_7 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Etempvar ___x86_wr_shift tuchar)
                      (Expr.Econst_int (Integers.Int.repr 8) tuint) tint)
    (Stmt.Sset ___kprog_x86_bits
      (Expr.Ebinop Binop.Oor
        (Expr.Ebinop Binop.Oand (Expr.Etempvar ___kprog_x86_bits tulong)
          (Expr.Eunop Unop.Onotint
            (Expr.Econst_long (Integers.Int64.repr 65280) tulong) tulong)
          tulong)
        (Expr.Ebinop Binop.Oshl
          (Expr.Ecast (Expr.Etempvar ___kprog_x86_lane tuchar) tulong)
          (Expr.Econst_int (Integers.Int.repr 8) tint) tulong) tulong))
    (Stmt.Sset ___kprog_x86_bits
      (Expr.Ebinop Binop.Oor
        (Expr.Ebinop Binop.Oand (Expr.Etempvar ___kprog_x86_bits tulong)
          (Expr.Eunop Unop.Onotint
            (Expr.Econst_long (Integers.Int64.repr 255) tulong) tulong)
          tulong) (Expr.Etempvar ___kprog_x86_lane tuchar) tulong)))
  (Stmt.Sassign
    (Expr.Efield (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
      _ptr (tptr tvoid))
    (Expr.Ecast (Expr.Ecast (Expr.Etempvar ___kprog_x86_bits tulong) tlong)
      (tptr tvoid))))

def s_kprog_x86_read_recovery_8 : Stmt :=
(Stmt.Sset _t'8
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint) tuint))

def s_kprog_x86_read_recovery_9 : Stmt :=
(Stmt.Sset _t'8
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))

def s_kprog_x86_read_recovery_10 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'31
      (Expr.Efield (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
        _ptr (tptr tvoid)))
    (Stmt.Ssequence
      (Stmt.Sset _t'32
        (Expr.Efield
          (Expr.Ederef
            (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
            (Ty.Tstruct _kprog_x86_arena noattr)) _b
          (tptr (tvolatile tuchar))))
      (Stmt.Sset ___x86_stack_delta__1
        (Expr.Ebinop Binop.Osub
          (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'31 (tptr tvoid)) tlong)
            tulong)
          (Expr.Ecast
            (Expr.Ecast
              (Expr.Ecast
                (Expr.Ecast
                  (Expr.Ecast
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Ecast
                        (Expr.Ecast
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar _t'32 (tptr (tvolatile tuchar)))
                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                            (tptr (tvolatile tuchar))) tulong) tulong)
                      (Expr.Ecast
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                            tulong)
                          (Expr.Ecast (Expr.Etempvar _capacity tuint) tulong)
                          tulong) tulong) tulong) tulong) (tptr tuchar))
                (tptr tvoid)) tlong) tulong) tulong))))
  (Stmt.Ssequence
    (Stmt.Sset _t'30
      (Expr.Efield
        (Expr.Ederef
          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
          (Ty.Tstruct _x86_sim_register_state noattr)) _native_stack_base
        tulong))
    (Stmt.Sset ___x86_wr_stack_bits__1
      (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_stack_delta__1 tulong)
        (Expr.Etempvar _t'30 tulong) tulong))))

def s_kprog_x86_read_recovery_11 : Stmt :=
Stmt.Sbreak

def s_kprog_x86_read_recovery_12 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'29
    (Expr.Efield (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
      _ptr (tptr tvoid)))
  (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
    [(tptr (tvolatile (tptr tvoid))), (tvolatile (tptr tvoid))]
    [(Expr.Eaddrof
       (Expr.Efield
         (Expr.Evar ___kprog_x86_partial__1 (tvolatile (Ty.Tunion __3786 noattr)))
         _ptr (tvolatile (tptr tvoid))) (tptr (tvolatile (tptr tvoid)))),
     (Expr.Etempvar _t'29 (tptr tvoid))]))

def s_kprog_x86_read_recovery_13 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint16unsigned)
    [(tptr (tvolatile tushort)), (tvolatile tushort)]
    [(Expr.Eaddrof
       (Expr.Efield
         (Expr.Evar ___kprog_x86_partial__1 (tvolatile (Ty.Tunion __3786 noattr)))
         _w (tvolatile tushort)) (tptr (tvolatile tushort))),
     (Expr.Etempvar ___kprog_x86_lane__1 tushort)])
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sbuiltin (some _t'6) (ExtFun.EF_vload Chunk.Mint64)
        [(tptr (tvolatile (tptr tvoid)))]
        [(Expr.Eaddrof
           (Expr.Efield
             (Expr.Evar ___kprog_x86_partial__1 (tvolatile (Ty.Tunion __3786 noattr)))
             _ptr (tvolatile (tptr tvoid))) (tptr (tvolatile (tptr tvoid))))])
      (Stmt.Sset ___kprog_x86_bits__1
        (Expr.Ecast
          (Expr.Ecast (Expr.Etempvar _t'6 (tvolatile (tptr tvoid))) tlong)
          tulong)))
    (Stmt.Sassign
      (Expr.Efield (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
        _ptr (tptr tvoid))
      (Expr.Ecast
        (Expr.Ecast
          (Expr.Ebinop Binop.Oor
            (Expr.Ebinop Binop.Oand
              (Expr.Etempvar ___kprog_x86_bits__1 tulong)
              (Expr.Eunop Unop.Onotint
                (Expr.Econst_long (Integers.Int64.repr 65535) tulong) tulong)
              tulong) (Expr.Etempvar ___kprog_x86_lane__1 tushort) tulong)
          tlong) (tptr tvoid)))))

def s_kprog_x86_read_recovery_14 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'7
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint) tuint))
    (Stmt.Sset _t'7 (Expr.Ecast (Expr.Etempvar _t'7 tuint) tuint)))
  (Stmt.Sset _t'7 (Expr.Ecast (Expr.Etempvar _t'7 tuint) tuint)))

def s_kprog_x86_read_recovery_15 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'7
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))
    (Stmt.Sset _t'7 (Expr.Ecast (Expr.Etempvar _t'7 tuint) tuint)))
  (Stmt.Sset _t'7 (Expr.Ecast (Expr.Etempvar _t'7 tuint) tuint)))

def s_kprog_x86_read_recovery_16 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset ___x86_release_i (Expr.Econst_int (Integers.Int.repr 0) tint))
    (Stmt.Sloop
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                            (Expr.Etempvar ___x86_release_i tuint)
                            (Expr.Etempvar _capacity tuint) tint)
          Stmt.Sskip
          Stmt.Sbreak)
        (Stmt.Ssequence
          (Stmt.Sset ___x86_release_off
            (Expr.Ebinop Binop.Osub
              (Expr.Ecast (Expr.Etempvar ___x86_release_i tuint) tlong)
              (Expr.Ecast (Expr.Etempvar _capacity tuint) tlong) tlong))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Ole
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Etempvar ___x86_release_i tuint)
                                    (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                    tuint) (Expr.Etempvar _capacity tuint)
                                  tint)
                (Stmt.Sset _t'14
                  (Expr.Ecast
                    (Expr.Ebinop Binop.Oge
                      (Expr.Etempvar ___x86_release_off tlong)
                      (Expr.Etempvar ___x86_release_old tlong) tint) tbool))
                (Stmt.Sset _t'14
                  (Expr.Econst_int (Integers.Int.repr 0) tint)))
              (Stmt.Sifthenelse (Expr.Etempvar _t'14 tint)
                (Stmt.Sset _t'15
                  (Expr.Ecast
                    (Expr.Ebinop Binop.Ole
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar ___x86_release_off tlong)
                        (Expr.Econst_int (Integers.Int.repr 8) tint) tlong)
                      (Expr.Etempvar ___x86_release_new tlong) tint) tbool))
                (Stmt.Sset _t'15
                  (Expr.Econst_int (Integers.Int.repr 0) tint))))
            (Stmt.Sifthenelse (Expr.Etempvar _t'15 tint)
              (Stmt.Ssequence
                (Stmt.Scall (some _t'10)
                  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                       tulong cc_default))
                  [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                (Stmt.Ssequence
                  (Stmt.Sset _t'25
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                        (Ty.Tstruct _kprog_x86_arena noattr)) _q
                      (tptr (tvolatile tulong))))
                  (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
                    [(tptr (tvolatile tulong)), (tvolatile tulong)]
                    [(Expr.Eaddrof
                       (Expr.Ederef
                         (Expr.Ebinop Binop.Oadd
                           (Expr.Etempvar _t'25 (tptr (tvolatile tulong)))
                           (Expr.Ebinop Binop.Odiv
                             (Expr.Etempvar ___x86_release_i tuint)
                             (Expr.Econst_int (Integers.Int.repr 8) tuint)
                             tuint) (tptr (tvolatile tulong)))
                         (tvolatile tulong)) (tptr (tvolatile tulong))),
                     (Expr.Etempvar _t'10 tulong)])))
              (Stmt.Ssequence
                (Stmt.Sset ___x86_release_lane
                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                        (Expr.Etempvar ___x86_release_lane tuint)
                                        (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                        tint)
                      Stmt.Sskip
                      Stmt.Sbreak)
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                            (Expr.Ebinop Binop.Oadd
                                              (Expr.Etempvar ___x86_release_i tuint)
                                              (Expr.Etempvar ___x86_release_lane tuint)
                                              tuint)
                                            (Expr.Etempvar _capacity tuint)
                                            tint)
                          (Stmt.Sset _t'12
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Oge
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Etempvar ___x86_release_off tlong)
                                  (Expr.Etempvar ___x86_release_lane tuint)
                                  tlong)
                                (Expr.Etempvar ___x86_release_old tlong)
                                tint) tbool))
                          (Stmt.Sset _t'12
                            (Expr.Econst_int (Integers.Int.repr 0) tint)))
                        (Stmt.Sifthenelse (Expr.Etempvar _t'12 tint)
                          (Stmt.Sset _t'13
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Olt
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Etempvar ___x86_release_off tlong)
                                  (Expr.Etempvar ___x86_release_lane tuint)
                                  tlong)
                                (Expr.Etempvar ___x86_release_new tlong)
                                tint) tbool))
                          (Stmt.Sset _t'13
                            (Expr.Econst_int (Integers.Int.repr 0) tint))))
                      (Stmt.Sifthenelse (Expr.Etempvar _t'13 tint)
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'11)
                            (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                 [tuint]
                                                                 tulong
                                                                 cc_default))
                            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                          (Stmt.Ssequence
                            (Stmt.Sset _t'24
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                                  (Ty.Tstruct _kprog_x86_arena noattr)) _b
                                (tptr (tvolatile tuchar))))
                            (Stmt.Sbuiltin none
                              (ExtFun.EF_vstore Chunk.Mint8unsigned)
                              [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
                              [(Expr.Eaddrof
                                 (Expr.Ederef
                                   (Expr.Ebinop Binop.Oadd
                                     (Expr.Etempvar _t'24 (tptr (tvolatile tuchar)))
                                     (Expr.Ebinop Binop.Oadd
                                       (Expr.Etempvar ___x86_release_i tuint)
                                       (Expr.Etempvar ___x86_release_lane tuint)
                                       tuint) (tptr (tvolatile tuchar)))
                                   (tvolatile tuchar))
                                 (tptr (tvolatile tuchar))),
                               (Expr.Ecast (Expr.Etempvar _t'11 tulong)
                                 tuchar)])))
                        Stmt.Sskip)))
                  (Stmt.Sset ___x86_release_lane
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Etempvar ___x86_release_lane tuint)
                      (Expr.Econst_int (Integers.Int.repr 1) tint) tuint))))))))
      (Stmt.Sset ___x86_release_i
        (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_release_i tuint)
          (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint))))
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sset _t'23
          (Expr.Efield
            (Expr.Efield
              (Expr.Efield
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                    (Ty.Tstruct _x86_sim_register_state noattr))
                  (Positive.ofNat 18727075383868559167)
                  (Ty.Tunion __3115 noattr))
                (Positive.ofNat 18727075383868559167)
                (Ty.Tstruct __3116 noattr)) _rsp
              (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
        (Stmt.Sset ___x86_sv_sp
          (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'23 (tptr tvoid)) tlong)
            tlong)))
      (Stmt.Ssequence
        (Stmt.Sset ___x86_sv_i (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Sloop
          (Stmt.Ssequence
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                (Expr.Etempvar ___x86_sv_i tuint)
                                (Expr.Ebinop Binop.Odiv
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Ecast
                                      (Expr.Etempvar _capacity tuint) tulong)
                                    (Expr.Econst_int (Integers.Int.repr 7) tuint)
                                    tulong)
                                  (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                  tulong) tint)
              Stmt.Sskip
              Stmt.Sbreak)
            (Stmt.Sloop
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                  (Expr.Ebinop Binop.Osub
                                    (Expr.Ecast
                                      (Expr.Ebinop Binop.Omul
                                        (Expr.Ecast
                                          (Expr.Etempvar ___x86_sv_i tuint)
                                          tulong)
                                        (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                        tulong) tlong)
                                    (Expr.Ecast
                                      (Expr.Etempvar _capacity tuint) tlong)
                                    tlong) (Expr.Etempvar ___x86_sv_sp tlong)
                                  tint)
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sset _t'22
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                              (Expr.Etempvar ___x86_sv_i tuint)
                              (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                            (Ty.Tstruct _kprog_x86_stack_fact noattr)) _tag
                          (tptr tuchar)))
                      (Stmt.Sassign
                        (Expr.Ederef (Expr.Etempvar _t'22 (tptr tuchar))
                          tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tuint)))
                    (Stmt.Ssequence
                      (Stmt.Sset _t'21
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                              (Expr.Etempvar ___x86_sv_i tuint)
                              (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                            (Ty.Tstruct _kprog_x86_stack_fact noattr))
                          _pointer (tptr (tptr tvoid))))
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Etempvar _t'21 (tptr (tptr tvoid)))
                          (tptr tvoid))
                        (Expr.Econst_int (Integers.Int.repr 0) tint))))
                  Stmt.Sbreak)
                Stmt.Sskip)
              Stmt.Sbreak))
          (Stmt.Sset ___x86_sv_i
            (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_sv_i tuint)
              (Expr.Econst_int (Integers.Int.repr 1) tint) tuint)))))
    Stmt.Sbreak))

def s_kprog_x86_read_recovery_17 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Scall (some _t'2)
      (Expr.Evar _x86_width_effective (Ty.Tfunction [tuchar] tuchar
                                        cc_default))
      [(Expr.Etempvar ___x86_wr_raw_width tuchar)])
    (Stmt.Sset ___x86_wr_width
      (Expr.Ecast (Expr.Etempvar _t'2 tuchar) tuchar)))
  (Stmt.Ssequence
    (Stmt.Sset ___x86_wr_shift
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuchar))
    (Stmt.Ssequence
      (Stmt.Sset ___x86_wr_next
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) tulong))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                              (Expr.Ecast (Expr.Etempvar _dst tulong) tulong)
                              (Expr.Econst_int (Integers.Int.repr 16) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Sset _t'42
                (Expr.Efield
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                              (Ty.Tstruct _x86_sim_register_state noattr))
                            (Positive.ofNat 18727075383868559167)
                            (Ty.Tunion __3115 noattr)) _gpr_cells
                          (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                        (Expr.Ecast (Expr.Etempvar _dst tulong) tuchar)
                        (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                      (Ty.Tstruct _x86_sim_gpr_cell noattr)) _value
                    (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
              (Stmt.Sset _t'3
                (Expr.Ecast (Expr.Etempvar _t'42 (tptr tvoid)) (tptr tvoid))))
            (Stmt.Sset _t'3
              (Expr.Ecast
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                  (tptr tvoid)) (tptr tvoid))))
          (Stmt.Sassign
            (Expr.Efield
              (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr)) _ptr
              (tptr tvoid)) (Expr.Etempvar _t'3 (tptr tvoid))))
        (Stmt.Ssequence
          (Stmt.Sloop
            (Stmt.Ssequence
              (Stmt.Sset ___x86_tag_reg__1 (Expr.Etempvar _dst tulong))
              (Stmt.Ssequence
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                    (Expr.Etempvar ___x86_tag_reg__1 tulong)
                                    (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                    tint)
                  (Stmt.Ssequence
                    (Stmt.Sset _t'41
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                  (Ty.Tstruct _x86_sim_register_state noattr))
                                (Positive.ofNat 18727075383868559167)
                                (Ty.Tunion __3115 noattr)) _gpr_cells
                              (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                            (Expr.Ecast
                              (Expr.Etempvar ___x86_tag_reg__1 tulong)
                              tuchar)
                            (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                          (Ty.Tstruct _x86_sim_gpr_cell noattr)) _tag tuchar))
                    (Stmt.Sset _t'4
                      (Expr.Ecast (Expr.Etempvar _t'41 tuchar) tuint)))
                  (Stmt.Sset _t'4
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                      tuint)))
                (Stmt.Sset ___x86_wr_cell_tag
                  (Expr.Ecast (Expr.Etempvar _t'4 tuint) tuchar))))
            Stmt.Sbreak)
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Ecast
                                    (Expr.Etempvar ___x86_wr_width tuchar)
                                    tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                  tint)
                (Stmt.Sset _t'9
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                    tuint))
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Ecast
                                      (Expr.Etempvar ___x86_wr_width tuchar)
                                      tuchar)
                                    (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                    tint)
                  (Stmt.Ssequence
                    (Stmt.Sset _t'9
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
                    (Stmt.Sset _t'9
                      (Expr.Ecast (Expr.Etempvar _t'9 tuint) tuint)))
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Ecast
                                        (Expr.Etempvar ___x86_wr_width tuchar)
                                        tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sset _t'9
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 2) tuint)
                            tuint))
                        (Stmt.Sset _t'9
                          (Expr.Ecast (Expr.Etempvar _t'9 tuint) tuint)))
                      (Stmt.Sset _t'9
                        (Expr.Ecast (Expr.Etempvar _t'9 tuint) tuint)))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sset _t'9
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 3) tuint)
                            tuint))
                        (Stmt.Sset _t'9
                          (Expr.Ecast (Expr.Etempvar _t'9 tuint) tuint)))
                      (Stmt.Sset _t'9
                        (Expr.Ecast (Expr.Etempvar _t'9 tuint) tuint))))))
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar _t'9 tuint)
                                  (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                  tint)
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar _dst tulong)
                                      (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Sset _t'39
                        (Expr.Efield
                          (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                          _ptr (tptr tvoid)))
                      (Stmt.Ssequence
                        (Stmt.Sset _t'40
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                              (Ty.Tstruct _x86_sim_register_state noattr))
                            _native_stack_base tulong))
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                            _ptr (tptr tvoid))
                          (Expr.Ecast
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Etempvar _t'39 (tptr tvoid)) tlong)
                                  tulong) (Expr.Etempvar _t'40 tulong)
                                tulong) tlong) (tptr tvoid)))))
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                        tint)
                      (Stmt.Ssequence
                        (Stmt.Sloop
                          (Stmt.Ssequence
                            s_kprog_x86_read_recovery_2
                            s_kprog_x86_read_recovery_3)
                          Stmt.Sbreak)
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                            _ptr (tptr tvoid))
                          (Expr.Ecast
                            (Expr.Ecast
                              (Expr.Etempvar ___x86_wr_stack_bits tulong)
                              tlong) (tptr tvoid))))
                      Stmt.Sskip))
                  (Stmt.Sloop
                    (Stmt.Ssequence
                      (Stmt.Sset ___kprog_x86_lane
                        (Expr.Ecast (Expr.Etempvar ___x86_wr_next tulong)
                          tuchar))
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                                            (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                            tint)
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Etempvar ___x86_wr_shift tuchar)
                                              (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                              tint)
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                                    _b (tarray tuchar 8))
                                  (Expr.Econst_int (Integers.Int.repr 1) tint)
                                  (tptr tuchar)) tuchar)
                              (Expr.Etempvar ___kprog_x86_lane tuchar))
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                                    _b (tarray tuchar 8))
                                  (Expr.Econst_int (Integers.Int.repr 0) tint)
                                  (tptr tuchar)) tuchar)
                              (Expr.Etempvar ___kprog_x86_lane tuchar)))
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Sset _t'35
                                (Expr.Efield
                                  (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                                  _ptr (tptr tvoid)))
                              (Stmt.Sbuiltin none
                                (ExtFun.EF_vstore Chunk.Mint64)
                                [(tptr (tvolatile (tptr tvoid))),
                                 (tvolatile (tptr tvoid))]
                                [(Expr.Eaddrof
                                   (Expr.Efield
                                     (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3780 noattr)))
                                     _ptr (tvolatile (tptr tvoid)))
                                   (tptr (tvolatile (tptr tvoid)))),
                                 (Expr.Etempvar _t'35 (tptr tvoid))]))
                            (Stmt.Ssequence
                              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                  (Expr.Etempvar ___x86_wr_shift tuchar)
                                                  (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                                  tint)
                                s_kprog_x86_read_recovery_4
                                s_kprog_x86_read_recovery_5)
                              (Stmt.Ssequence
                                s_kprog_x86_read_recovery_6
                                s_kprog_x86_read_recovery_7))))
                        (Stmt.Sset ___x86_wr_cell_tag
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tuint)
                            tuchar))))
                    Stmt.Sbreak))
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Ecast
                                        (Expr.Etempvar ___x86_wr_width tuchar)
                                        tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                      tint)
                    (Stmt.Sset _t'8
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 0) tuint) tuint))
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Ecast
                                          (Expr.Etempvar ___x86_wr_width tuchar)
                                          tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                        tint)
                      (Stmt.Ssequence
                        (Stmt.Sset _t'8
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 1) tuint)
                            tuint))
                        (Stmt.Sset _t'8
                          (Expr.Ecast (Expr.Etempvar _t'8 tuint) tuint)))
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Ecast
                                            (Expr.Etempvar ___x86_wr_width tuchar)
                                            tuchar)
                                          (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                          tint)
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            s_kprog_x86_read_recovery_8
                            (Stmt.Sset _t'8
                              (Expr.Ecast (Expr.Etempvar _t'8 tuint) tuint)))
                          (Stmt.Sset _t'8
                            (Expr.Ecast (Expr.Etempvar _t'8 tuint) tuint)))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            s_kprog_x86_read_recovery_9
                            (Stmt.Sset _t'8
                              (Expr.Ecast (Expr.Etempvar _t'8 tuint) tuint)))
                          (Stmt.Sset _t'8
                            (Expr.Ecast (Expr.Etempvar _t'8 tuint) tuint))))))
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar _t'8 tuint)
                                      (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Etempvar _dst tulong)
                                          (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                          tint)
                        (Stmt.Ssequence
                          (Stmt.Sset _t'33
                            (Expr.Efield
                              (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                              _ptr (tptr tvoid)))
                          (Stmt.Ssequence
                            (Stmt.Sset _t'34
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                  (Ty.Tstruct _x86_sim_register_state noattr))
                                _native_stack_base tulong))
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                                _ptr (tptr tvoid))
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Ecast
                                      (Expr.Ecast
                                        (Expr.Etempvar _t'33 (tptr tvoid))
                                        tlong) tulong)
                                    (Expr.Etempvar _t'34 tulong) tulong)
                                  tlong) (tptr tvoid)))))
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                                            (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                            tint)
                          (Stmt.Ssequence
                            (Stmt.Sloop
                              s_kprog_x86_read_recovery_10
                              s_kprog_x86_read_recovery_11)
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                                _ptr (tptr tvoid))
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Etempvar ___x86_wr_stack_bits__1 tulong)
                                  tlong) (tptr tvoid))))
                          Stmt.Sskip))
                      (Stmt.Sloop
                        (Stmt.Ssequence
                          (Stmt.Sset ___kprog_x86_lane__1
                            (Expr.Ecast (Expr.Etempvar ___x86_wr_next tulong)
                              tushort))
                          (Stmt.Ssequence
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                                                (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                                tint)
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                                  _w tushort)
                                (Expr.Etempvar ___kprog_x86_lane__1 tushort))
                              (Stmt.Ssequence
                                s_kprog_x86_read_recovery_12
                                s_kprog_x86_read_recovery_13))
                            (Stmt.Sset ___x86_wr_cell_tag
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                tuchar))))
                        Stmt.Sbreak))
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Ecast
                                            (Expr.Etempvar ___x86_wr_width tuchar)
                                            tuchar)
                                          (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                          tint)
                        (Stmt.Sset _t'7
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tuint)
                            tuint))
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Ecast
                                              (Expr.Etempvar ___x86_wr_width tuchar)
                                              tuchar)
                                            (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                            tint)
                          (Stmt.Ssequence
                            (Stmt.Sset _t'7
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                tuint))
                            (Stmt.Sset _t'7
                              (Expr.Ecast (Expr.Etempvar _t'7 tuint) tuint)))
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Ecast
                                                (Expr.Etempvar ___x86_wr_width tuchar)
                                                tuchar)
                                              (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                              tint)
                            s_kprog_x86_read_recovery_14
                            s_kprog_x86_read_recovery_15)))
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Etempvar _t'7 tuint)
                                          (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                          tint)
                        (Stmt.Ssequence
                          (Stmt.Sset ___x86_wr_next
                            (Expr.Ecast
                              (Expr.Ecast
                                (Expr.Etempvar ___x86_wr_next tulong) tuint)
                              tulong))
                          (Stmt.Sloop
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                                  _ptr (tptr tvoid))
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Ecast
                                      (Expr.Etempvar ___x86_wr_next tulong)
                                      tuint) tlong) (tptr tvoid)))
                              (Stmt.Sset ___x86_wr_cell_tag
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                  tuchar)))
                            Stmt.Sbreak))
                        (Stmt.Sloop
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                                _ptr (tptr tvoid))
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Etempvar ___x86_wr_next tulong)
                                    tulong) tlong) (tptr tvoid)))
                            (Stmt.Sset ___x86_wr_cell_tag
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                tuchar)))
                          Stmt.Sbreak)))))))
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar _dst tulong)
                                  (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                  tint)
                (Stmt.Ssequence
                  (Stmt.Sset _t'27
                    (Expr.Efield
                      (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                      _ptr (tptr tvoid)))
                  (Stmt.Ssequence
                    (Stmt.Sset _t'28
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                          (Ty.Tstruct _x86_sim_register_state noattr))
                        _native_stack_base tulong))
                    (Stmt.Sassign
                      (Expr.Efield
                        (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                        _ptr (tptr tvoid))
                      (Expr.Ecast
                        (Expr.Ecast
                          (Expr.Ebinop Binop.Osub
                            (Expr.Ecast
                              (Expr.Ecast (Expr.Etempvar _t'27 (tptr tvoid))
                                tlong) tulong) (Expr.Etempvar _t'28 tulong)
                            tulong) tlong) (tptr tvoid)))))
                Stmt.Sskip)
              (Stmt.Ssequence
                (Stmt.Sset ___x86_wr_next_ptr
                  (Expr.Efield
                    (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                    _ptr (tptr tvoid)))
                (Stmt.Ssequence
                  (Stmt.Sset ___x86_wr_next_tag
                    (Expr.Ecast (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                      tuchar))
                  (Stmt.Ssequence
                    (Stmt.Sloop
                      (Stmt.Ssequence
                        (Stmt.Sset ___x86_store_reg
                          (Expr.Etempvar _dst tulong))
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                            (Expr.Etempvar ___x86_store_reg tulong)
                                            (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                            tint)
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Efield
                                        (Expr.Efield
                                          (Expr.Ederef
                                            (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                            (Ty.Tstruct _x86_sim_register_state noattr))
                                          (Positive.ofNat 18727075383868559167)
                                          (Ty.Tunion __3115 noattr))
                                        _gpr_cells
                                        (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                                      (Expr.Ecast
                                        (Expr.Etempvar ___x86_store_reg tulong)
                                        tuchar)
                                      (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                                    (Ty.Tstruct _x86_sim_gpr_cell noattr))
                                  _value (Ty.Tunion _x86_sim_gpr noattr))
                                _ptr (tptr tvoid))
                              (Expr.Etempvar ___x86_wr_next_ptr (tptr tvoid)))
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Efield
                                        (Expr.Ederef
                                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                          (Ty.Tstruct _x86_sim_register_state noattr))
                                        (Positive.ofNat 18727075383868559167)
                                        (Ty.Tunion __3115 noattr)) _gpr_cells
                                      (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                                    (Expr.Ecast
                                      (Expr.Etempvar ___x86_store_reg tulong)
                                      tuchar)
                                    (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                                  (Ty.Tstruct _x86_sim_gpr_cell noattr)) _tag
                                tuchar)
                              (Expr.Etempvar ___x86_wr_next_tag tuchar)))
                          Stmt.Sskip))
                      Stmt.Sbreak)
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Etempvar _dst tulong)
                                        (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                        tint)
                      (Stmt.Sloop
                        (Stmt.Ssequence
                          (Stmt.Sset ___x86_release_old
                            (Expr.Etempvar ___x86_write_old_sp tlong))
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Sset _t'26
                                (Expr.Efield
                                  (Expr.Efield
                                    (Expr.Efield
                                      (Expr.Efield
                                        (Expr.Ederef
                                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                          (Ty.Tstruct _x86_sim_register_state noattr))
                                        (Positive.ofNat 18727075383868559167)
                                        (Ty.Tunion __3115 noattr))
                                      (Positive.ofNat 18727075383868559167)
                                      (Ty.Tstruct __3116 noattr)) _rsp
                                    (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                                  (tptr tvoid)))
                              (Stmt.Sset ___x86_release_new
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Etempvar _t'26 (tptr tvoid)) tlong)
                                  tlong)))
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Ogt
                                                (Expr.Etempvar ___x86_release_new tlong)
                                                (Expr.Etempvar ___x86_release_old tlong)
                                                tint)
                              s_kprog_x86_read_recovery_16
                              Stmt.Sskip)))
                        Stmt.Sbreak)
                      Stmt.Sskip)))))))))))

def f_kprog_x86_read_recovery : Function := {
  fn_return := tint,
  fn_callconv := cc_default,
  fn_params := [(_state, (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
                (_arena, (tptr (Ty.Tstruct _kprog_x86_arena noattr))),
                (_facts, (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr))),
                (_capacity, tuint), (_base, tulong), (_dst, tulong)],
  fn_vars := [(___x86_wr_cell, (Ty.Tunion _x86_sim_gpr noattr)),
              (___kprog_x86_partial, (tvolatile (Ty.Tunion __3780 noattr))),
              (___kprog_x86_partial__1,
               (tvolatile (Ty.Tunion __3786 noattr)))],
  fn_temps := [(___x86_state,
                (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
               (_recovered, tint), (___x86_read_recovered, tint),
               (___x86_read_tag, tuchar), (___x86_tag_reg, tulong),
               (___x86_write_old_sp, tlong), (___x86_wr_raw_width, tuchar),
               (___x86_wr_width, tuchar), (___x86_wr_shift, tuchar),
               (___x86_wr_next, tulong), (___x86_wr_cell_tag, tuchar),
               (___x86_tag_reg__1, tulong), (___x86_wr_stack_bits, tulong),
               (___x86_stack_delta, tulong), (___kprog_x86_lane, tuchar),
               (___kprog_x86_bits, tulong),
               (___x86_wr_stack_bits__1, tulong),
               (___x86_stack_delta__1, tulong),
               (___kprog_x86_lane__1, tushort),
               (___kprog_x86_bits__1, tulong),
               (___x86_wr_next_ptr, (tptr tvoid)),
               (___x86_wr_next_tag, tuchar), (___x86_store_reg, tulong),
               (___x86_release_old, tlong), (___x86_release_new, tlong),
               (___x86_release_i, tuint), (___x86_release_off, tlong),
               (___x86_release_lane, tuint), (___x86_sv_sp, tlong),
               (___x86_sv_i, tuint), (_t'20, tint), (_t'19, tint),
               (_t'18, tulong), (_t'17, tulong), (_t'16, tint),
               (_t'15, tint), (_t'14, tint), (_t'13, tint), (_t'12, tint),
               (_t'11, tulong), (_t'10, tulong), (_t'9, tuint),
               (_t'8, tuint), (_t'7, tuint),
               (_t'6, (tvolatile (tptr tvoid))),
               (_t'5, (tvolatile (tptr tvoid))), (_t'4, tuint),
               (_t'3, (tptr tvoid)), (_t'2, tuchar), (_t'1, tuint),
               (_t'44, tuchar), (_t'43, (tptr tvoid)), (_t'42, (tptr tvoid)),
               (_t'41, tuchar), (_t'40, tulong), (_t'39, (tptr tvoid)),
               (_t'38, (tptr (tvolatile tuchar))), (_t'37, (tptr tvoid)),
               (_t'36, tulong), (_t'35, (tptr tvoid)), (_t'34, tulong),
               (_t'33, (tptr tvoid)), (_t'32, (tptr (tvolatile tuchar))),
               (_t'31, (tptr tvoid)), (_t'30, tulong), (_t'29, (tptr tvoid)),
               (_t'28, tulong), (_t'27, (tptr tvoid)), (_t'26, (tptr tvoid)),
               (_t'25, (tptr (tvolatile tulong))),
               (_t'24, (tptr (tvolatile tuchar))), (_t'23, (tptr tvoid)),
               (_t'22, (tptr tuchar)), (_t'21, (tptr (tptr tvoid)))],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_state
    (Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))))
  (Stmt.Ssequence
    (Stmt.Sloop
      (Stmt.Ssequence
        (Stmt.Sset ___x86_read_recovered
          (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.One
                                  (Expr.Etempvar _base tulong)
                                  (Expr.Econst_int (Integers.Int.repr 255) tuint)
                                  tint)
                (Stmt.Sset _t'19
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tint)
                    tint))
                (Stmt.Sset _t'19
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                    tint)))
              (Stmt.Sifthenelse (Expr.Ecast (Expr.Etempvar _t'19 tint)
                                  tuchar)
                (Stmt.Sset _t'20
                  (Expr.Ecast
                    (Expr.Ebinop Binop.One (Expr.Etempvar _base tulong)
                      (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
                    tbool))
                (Stmt.Sset _t'20
                  (Expr.Econst_int (Integers.Int.repr 0) tint))))
            (Stmt.Sifthenelse (Expr.Etempvar _t'20 tint)
              (Stmt.Ssequence
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Sset ___x86_tag_reg (Expr.Etempvar _base tulong))
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                          (Expr.Etempvar ___x86_tag_reg tulong)
                                          (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                          tint)
                        (Stmt.Ssequence
                          (Stmt.Sset _t'44
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Efield
                                      (Expr.Ederef
                                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                        (Ty.Tstruct _x86_sim_register_state noattr))
                                      (Positive.ofNat 18727075383868559167)
                                      (Ty.Tunion __3115 noattr)) _gpr_cells
                                    (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                                  (Expr.Ecast
                                    (Expr.Etempvar ___x86_tag_reg tulong)
                                    tuchar)
                                  (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                                (Ty.Tstruct _x86_sim_gpr_cell noattr)) _tag
                              tuchar))
                          (Stmt.Sset _t'1
                            (Expr.Ecast (Expr.Etempvar _t'44 tuchar) tuint)))
                        (Stmt.Sset _t'1
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tuint)
                            tuint)))
                      (Stmt.Sset ___x86_read_tag
                        (Expr.Ecast (Expr.Etempvar _t'1 tuint) tuchar))))
                  Stmt.Sbreak)
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar ___x86_read_tag tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Scall (some _t'17)
                        (Expr.Evar _kprog_x86_read_reg (Ty.Tfunction
                                                         [(tptr (Ty.Tstruct _x86_sim_register_state noattr)),
                                                          (tptr (Ty.Tstruct _kprog_x86_arena noattr)),
                                                          tuint, tuchar,
                                                          tuchar, tuchar]
                                                         tulong cc_default))
                        [(Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
                         (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr))),
                         (Expr.Etempvar _capacity tuint),
                         (Expr.Etempvar _base tulong),
                         (Expr.Econst_int (Integers.Int.repr 8) tuint),
                         (Expr.Econst_int (Integers.Int.repr 0) tuint)])
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                          (Expr.Ecast
                                            (Expr.Etempvar _t'17 tulong)
                                            tulong)
                                          (Expr.Econst_int (Integers.Int.repr 4096) tuint)
                                          tint)
                        (Stmt.Sset _t'16
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 1) tint)
                            tbool))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Scall (some _t'18)
                              (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                   [tuint]
                                                                   tulong
                                                                   cc_default))
                              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                            (Stmt.Sset _t'16
                              (Expr.Ecast
                                (Expr.Ebinop Binop.Oand
                                  (Expr.Etempvar _t'18 tulong)
                                  (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                  tulong) tbool)))
                          (Stmt.Sset _t'16
                            (Expr.Ecast (Expr.Etempvar _t'16 tint) tbool)))))
                    (Stmt.Sset _t'16
                      (Expr.Econst_int (Integers.Int.repr 0) tint)))
                  (Stmt.Sifthenelse (Expr.Etempvar _t'16 tint)
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Etempvar _dst tulong)
                                          (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                          tint)
                        (Stmt.Scall none
                          (Expr.Evar _kprog_c_trap (Ty.Tfunction [] tvoid
                                                     cc_default)) [])
                        (Stmt.Sloop
                          (Stmt.Ssequence
                            s_kprog_x86_read_recovery_0
                            (Stmt.Ssequence
                              s_kprog_x86_read_recovery_1
                              s_kprog_x86_read_recovery_17))
                          Stmt.Sbreak))
                      (Stmt.Sset ___x86_read_recovered
                        (Expr.Econst_int (Integers.Int.repr 1) tint)))
                    Stmt.Sskip)))
              Stmt.Sskip))
          (Stmt.Sset _recovered (Expr.Etempvar ___x86_read_recovered tint))))
      Stmt.Sbreak)
    (Stmt.Sreturn (some (Expr.Etempvar _recovered tint)))))
}

def s_kprog_x86_read_recovery_mem_0 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'44
    (Expr.Efield
      (Expr.Efield
        (Expr.Efield
          (Expr.Efield
            (Expr.Ederef
              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
              (Ty.Tstruct _x86_sim_register_state noattr))
            (Positive.ofNat 18727075383868559167) (Ty.Tunion __3115 noattr))
          (Positive.ofNat 18727075383868559167) (Ty.Tstruct __3116 noattr))
        _rsp (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
  (Stmt.Sset ___x86_write_old_sp
    (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'44 (tptr tvoid)) tlong) tlong)))

def s_kprog_x86_read_recovery_mem_1 : Stmt :=
(Stmt.Sset ___x86_wr_raw_width
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tuint) tuchar))

def s_kprog_x86_read_recovery_mem_2 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'38
    (Expr.Efield (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
      _ptr (tptr tvoid)))
  (Stmt.Ssequence
    (Stmt.Sset _t'39
      (Expr.Efield
        (Expr.Ederef
          (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
          (Ty.Tstruct _kprog_x86_arena noattr)) _b (tptr (tvolatile tuchar))))
    (Stmt.Sset ___x86_stack_delta
      (Expr.Ebinop Binop.Osub
        (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'38 (tptr tvoid)) tlong)
          tulong)
        (Expr.Ecast
          (Expr.Ecast
            (Expr.Ecast
              (Expr.Ecast
                (Expr.Ecast
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Ecast
                      (Expr.Ecast
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Etempvar _t'39 (tptr (tvolatile tuchar)))
                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                          (tptr (tvolatile tuchar))) tulong) tulong)
                    (Expr.Ecast
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                          tulong)
                        (Expr.Ecast (Expr.Etempvar _capacity tuint) tulong)
                        tulong) tulong) tulong) tulong) (tptr tuchar))
              (tptr tvoid)) tlong) tulong) tulong))))

def s_kprog_x86_read_recovery_mem_3 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'37
    (Expr.Efield
      (Expr.Ederef
        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
        (Ty.Tstruct _x86_sim_register_state noattr)) _native_stack_base
      tulong))
  (Stmt.Sset ___x86_wr_stack_bits
    (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_stack_delta tulong)
      (Expr.Etempvar _t'37 tulong) tulong)))

def s_kprog_x86_read_recovery_mem_4 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield
        (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3825 noattr)))
        _b (tvolatile (tarray tuchar 8)))
      (Expr.Econst_int (Integers.Int.repr 1) tint) (tptr tuchar)) tuchar)
  (Expr.Etempvar ___kprog_x86_lane tuchar))

def s_kprog_x86_read_recovery_mem_5 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield
        (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3825 noattr)))
        _b (tvolatile (tarray tuchar 8)))
      (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tuchar)) tuchar)
  (Expr.Etempvar ___kprog_x86_lane tuchar))

def s_kprog_x86_read_recovery_mem_6 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sbuiltin (some _t'5) (ExtFun.EF_vload Chunk.Mint64)
    [(tptr (tvolatile (tptr tvoid)))]
    [(Expr.Eaddrof
       (Expr.Efield
         (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3825 noattr)))
         _ptr (tvolatile (tptr tvoid))) (tptr (tvolatile (tptr tvoid))))])
  (Stmt.Sset ___kprog_x86_bits
    (Expr.Ecast
      (Expr.Ecast (Expr.Etempvar _t'5 (tvolatile (tptr tvoid))) tlong)
      tulong)))

def s_kprog_x86_read_recovery_mem_7 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Etempvar ___x86_wr_shift tuchar)
                      (Expr.Econst_int (Integers.Int.repr 8) tuint) tint)
    (Stmt.Sset ___kprog_x86_bits
      (Expr.Ebinop Binop.Oor
        (Expr.Ebinop Binop.Oand (Expr.Etempvar ___kprog_x86_bits tulong)
          (Expr.Eunop Unop.Onotint
            (Expr.Econst_long (Integers.Int64.repr 65280) tulong) tulong)
          tulong)
        (Expr.Ebinop Binop.Oshl
          (Expr.Ecast (Expr.Etempvar ___kprog_x86_lane tuchar) tulong)
          (Expr.Econst_int (Integers.Int.repr 8) tint) tulong) tulong))
    (Stmt.Sset ___kprog_x86_bits
      (Expr.Ebinop Binop.Oor
        (Expr.Ebinop Binop.Oand (Expr.Etempvar ___kprog_x86_bits tulong)
          (Expr.Eunop Unop.Onotint
            (Expr.Econst_long (Integers.Int64.repr 255) tulong) tulong)
          tulong) (Expr.Etempvar ___kprog_x86_lane tuchar) tulong)))
  (Stmt.Sassign
    (Expr.Efield (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
      _ptr (tptr tvoid))
    (Expr.Ecast (Expr.Ecast (Expr.Etempvar ___kprog_x86_bits tulong) tlong)
      (tptr tvoid))))

def s_kprog_x86_read_recovery_mem_8 : Stmt :=
(Stmt.Sset _t'8
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint) tuint))

def s_kprog_x86_read_recovery_mem_9 : Stmt :=
(Stmt.Sset _t'8
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))

def s_kprog_x86_read_recovery_mem_10 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'32
      (Expr.Efield (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
        _ptr (tptr tvoid)))
    (Stmt.Ssequence
      (Stmt.Sset _t'33
        (Expr.Efield
          (Expr.Ederef
            (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
            (Ty.Tstruct _kprog_x86_arena noattr)) _b
          (tptr (tvolatile tuchar))))
      (Stmt.Sset ___x86_stack_delta__1
        (Expr.Ebinop Binop.Osub
          (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'32 (tptr tvoid)) tlong)
            tulong)
          (Expr.Ecast
            (Expr.Ecast
              (Expr.Ecast
                (Expr.Ecast
                  (Expr.Ecast
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Ecast
                        (Expr.Ecast
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar _t'33 (tptr (tvolatile tuchar)))
                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                            (tptr (tvolatile tuchar))) tulong) tulong)
                      (Expr.Ecast
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                            tulong)
                          (Expr.Ecast (Expr.Etempvar _capacity tuint) tulong)
                          tulong) tulong) tulong) tulong) (tptr tuchar))
                (tptr tvoid)) tlong) tulong) tulong))))
  (Stmt.Ssequence
    (Stmt.Sset _t'31
      (Expr.Efield
        (Expr.Ederef
          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
          (Ty.Tstruct _x86_sim_register_state noattr)) _native_stack_base
        tulong))
    (Stmt.Sset ___x86_wr_stack_bits__1
      (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_stack_delta__1 tulong)
        (Expr.Etempvar _t'31 tulong) tulong))))

def s_kprog_x86_read_recovery_mem_11 : Stmt :=
Stmt.Sbreak

def s_kprog_x86_read_recovery_mem_12 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'30
    (Expr.Efield (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
      _ptr (tptr tvoid)))
  (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
    [(tptr (tvolatile (tptr tvoid))), (tvolatile (tptr tvoid))]
    [(Expr.Eaddrof
       (Expr.Efield
         (Expr.Evar ___kprog_x86_partial__1 (tvolatile (Ty.Tunion __3831 noattr)))
         _ptr (tvolatile (tptr tvoid))) (tptr (tvolatile (tptr tvoid)))),
     (Expr.Etempvar _t'30 (tptr tvoid))]))

def s_kprog_x86_read_recovery_mem_13 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint16unsigned)
    [(tptr (tvolatile tushort)), (tvolatile tushort)]
    [(Expr.Eaddrof
       (Expr.Efield
         (Expr.Evar ___kprog_x86_partial__1 (tvolatile (Ty.Tunion __3831 noattr)))
         _w (tvolatile tushort)) (tptr (tvolatile tushort))),
     (Expr.Etempvar ___kprog_x86_lane__1 tushort)])
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sbuiltin (some _t'6) (ExtFun.EF_vload Chunk.Mint64)
        [(tptr (tvolatile (tptr tvoid)))]
        [(Expr.Eaddrof
           (Expr.Efield
             (Expr.Evar ___kprog_x86_partial__1 (tvolatile (Ty.Tunion __3831 noattr)))
             _ptr (tvolatile (tptr tvoid))) (tptr (tvolatile (tptr tvoid))))])
      (Stmt.Sset ___kprog_x86_bits__1
        (Expr.Ecast
          (Expr.Ecast (Expr.Etempvar _t'6 (tvolatile (tptr tvoid))) tlong)
          tulong)))
    (Stmt.Sassign
      (Expr.Efield (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
        _ptr (tptr tvoid))
      (Expr.Ecast
        (Expr.Ecast
          (Expr.Ebinop Binop.Oor
            (Expr.Ebinop Binop.Oand
              (Expr.Etempvar ___kprog_x86_bits__1 tulong)
              (Expr.Eunop Unop.Onotint
                (Expr.Econst_long (Integers.Int64.repr 65535) tulong) tulong)
              tulong) (Expr.Etempvar ___kprog_x86_lane__1 tushort) tulong)
          tlong) (tptr tvoid)))))

def s_kprog_x86_read_recovery_mem_14 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'7
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint) tuint))
    (Stmt.Sset _t'7 (Expr.Ecast (Expr.Etempvar _t'7 tuint) tuint)))
  (Stmt.Sset _t'7 (Expr.Ecast (Expr.Etempvar _t'7 tuint) tuint)))

def s_kprog_x86_read_recovery_mem_15 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'7
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))
    (Stmt.Sset _t'7 (Expr.Ecast (Expr.Etempvar _t'7 tuint) tuint)))
  (Stmt.Sset _t'7 (Expr.Ecast (Expr.Etempvar _t'7 tuint) tuint)))

def s_kprog_x86_read_recovery_mem_16 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset ___x86_release_i (Expr.Econst_int (Integers.Int.repr 0) tint))
    (Stmt.Sloop
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                            (Expr.Etempvar ___x86_release_i tuint)
                            (Expr.Etempvar _capacity tuint) tint)
          Stmt.Sskip
          Stmt.Sbreak)
        (Stmt.Ssequence
          (Stmt.Sset ___x86_release_off
            (Expr.Ebinop Binop.Osub
              (Expr.Ecast (Expr.Etempvar ___x86_release_i tuint) tlong)
              (Expr.Ecast (Expr.Etempvar _capacity tuint) tlong) tlong))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Ole
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Etempvar ___x86_release_i tuint)
                                    (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                    tuint) (Expr.Etempvar _capacity tuint)
                                  tint)
                (Stmt.Sset _t'14
                  (Expr.Ecast
                    (Expr.Ebinop Binop.Oge
                      (Expr.Etempvar ___x86_release_off tlong)
                      (Expr.Etempvar ___x86_release_old tlong) tint) tbool))
                (Stmt.Sset _t'14
                  (Expr.Econst_int (Integers.Int.repr 0) tint)))
              (Stmt.Sifthenelse (Expr.Etempvar _t'14 tint)
                (Stmt.Sset _t'15
                  (Expr.Ecast
                    (Expr.Ebinop Binop.Ole
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar ___x86_release_off tlong)
                        (Expr.Econst_int (Integers.Int.repr 8) tint) tlong)
                      (Expr.Etempvar ___x86_release_new tlong) tint) tbool))
                (Stmt.Sset _t'15
                  (Expr.Econst_int (Integers.Int.repr 0) tint))))
            (Stmt.Sifthenelse (Expr.Etempvar _t'15 tint)
              (Stmt.Ssequence
                (Stmt.Scall (some _t'10)
                  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                       tulong cc_default))
                  [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                (Stmt.Ssequence
                  (Stmt.Sset _t'26
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                        (Ty.Tstruct _kprog_x86_arena noattr)) _q
                      (tptr (tvolatile tulong))))
                  (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
                    [(tptr (tvolatile tulong)), (tvolatile tulong)]
                    [(Expr.Eaddrof
                       (Expr.Ederef
                         (Expr.Ebinop Binop.Oadd
                           (Expr.Etempvar _t'26 (tptr (tvolatile tulong)))
                           (Expr.Ebinop Binop.Odiv
                             (Expr.Etempvar ___x86_release_i tuint)
                             (Expr.Econst_int (Integers.Int.repr 8) tuint)
                             tuint) (tptr (tvolatile tulong)))
                         (tvolatile tulong)) (tptr (tvolatile tulong))),
                     (Expr.Etempvar _t'10 tulong)])))
              (Stmt.Ssequence
                (Stmt.Sset ___x86_release_lane
                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                        (Expr.Etempvar ___x86_release_lane tuint)
                                        (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                        tint)
                      Stmt.Sskip
                      Stmt.Sbreak)
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                            (Expr.Ebinop Binop.Oadd
                                              (Expr.Etempvar ___x86_release_i tuint)
                                              (Expr.Etempvar ___x86_release_lane tuint)
                                              tuint)
                                            (Expr.Etempvar _capacity tuint)
                                            tint)
                          (Stmt.Sset _t'12
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Oge
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Etempvar ___x86_release_off tlong)
                                  (Expr.Etempvar ___x86_release_lane tuint)
                                  tlong)
                                (Expr.Etempvar ___x86_release_old tlong)
                                tint) tbool))
                          (Stmt.Sset _t'12
                            (Expr.Econst_int (Integers.Int.repr 0) tint)))
                        (Stmt.Sifthenelse (Expr.Etempvar _t'12 tint)
                          (Stmt.Sset _t'13
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Olt
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Etempvar ___x86_release_off tlong)
                                  (Expr.Etempvar ___x86_release_lane tuint)
                                  tlong)
                                (Expr.Etempvar ___x86_release_new tlong)
                                tint) tbool))
                          (Stmt.Sset _t'13
                            (Expr.Econst_int (Integers.Int.repr 0) tint))))
                      (Stmt.Sifthenelse (Expr.Etempvar _t'13 tint)
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'11)
                            (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                 [tuint]
                                                                 tulong
                                                                 cc_default))
                            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                          (Stmt.Ssequence
                            (Stmt.Sset _t'25
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                                  (Ty.Tstruct _kprog_x86_arena noattr)) _b
                                (tptr (tvolatile tuchar))))
                            (Stmt.Sbuiltin none
                              (ExtFun.EF_vstore Chunk.Mint8unsigned)
                              [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
                              [(Expr.Eaddrof
                                 (Expr.Ederef
                                   (Expr.Ebinop Binop.Oadd
                                     (Expr.Etempvar _t'25 (tptr (tvolatile tuchar)))
                                     (Expr.Ebinop Binop.Oadd
                                       (Expr.Etempvar ___x86_release_i tuint)
                                       (Expr.Etempvar ___x86_release_lane tuint)
                                       tuint) (tptr (tvolatile tuchar)))
                                   (tvolatile tuchar))
                                 (tptr (tvolatile tuchar))),
                               (Expr.Ecast (Expr.Etempvar _t'11 tulong)
                                 tuchar)])))
                        Stmt.Sskip)))
                  (Stmt.Sset ___x86_release_lane
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Etempvar ___x86_release_lane tuint)
                      (Expr.Econst_int (Integers.Int.repr 1) tint) tuint))))))))
      (Stmt.Sset ___x86_release_i
        (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_release_i tuint)
          (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint))))
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sset _t'24
          (Expr.Efield
            (Expr.Efield
              (Expr.Efield
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                    (Ty.Tstruct _x86_sim_register_state noattr))
                  (Positive.ofNat 18727075383868559167)
                  (Ty.Tunion __3115 noattr))
                (Positive.ofNat 18727075383868559167)
                (Ty.Tstruct __3116 noattr)) _rsp
              (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
        (Stmt.Sset ___x86_sv_sp
          (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'24 (tptr tvoid)) tlong)
            tlong)))
      (Stmt.Ssequence
        (Stmt.Sset ___x86_sv_i (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Sloop
          (Stmt.Ssequence
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                (Expr.Etempvar ___x86_sv_i tuint)
                                (Expr.Ebinop Binop.Odiv
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Ecast
                                      (Expr.Etempvar _capacity tuint) tulong)
                                    (Expr.Econst_int (Integers.Int.repr 7) tuint)
                                    tulong)
                                  (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                  tulong) tint)
              Stmt.Sskip
              Stmt.Sbreak)
            (Stmt.Sloop
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                  (Expr.Ebinop Binop.Osub
                                    (Expr.Ecast
                                      (Expr.Ebinop Binop.Omul
                                        (Expr.Ecast
                                          (Expr.Etempvar ___x86_sv_i tuint)
                                          tulong)
                                        (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                        tulong) tlong)
                                    (Expr.Ecast
                                      (Expr.Etempvar _capacity tuint) tlong)
                                    tlong) (Expr.Etempvar ___x86_sv_sp tlong)
                                  tint)
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sset _t'23
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                              (Expr.Etempvar ___x86_sv_i tuint)
                              (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                            (Ty.Tstruct _kprog_x86_stack_fact noattr)) _tag
                          (tptr tuchar)))
                      (Stmt.Sassign
                        (Expr.Ederef (Expr.Etempvar _t'23 (tptr tuchar))
                          tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tuint)))
                    (Stmt.Ssequence
                      (Stmt.Sset _t'22
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                              (Expr.Etempvar ___x86_sv_i tuint)
                              (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                            (Ty.Tstruct _kprog_x86_stack_fact noattr))
                          _pointer (tptr (tptr tvoid))))
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Etempvar _t'22 (tptr (tptr tvoid)))
                          (tptr tvoid))
                        (Expr.Econst_int (Integers.Int.repr 0) tint))))
                  Stmt.Sbreak)
                Stmt.Sskip)
              Stmt.Sbreak))
          (Stmt.Sset ___x86_sv_i
            (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_sv_i tuint)
              (Expr.Econst_int (Integers.Int.repr 1) tint) tuint)))))
    Stmt.Sbreak))

def s_kprog_x86_read_recovery_mem_17 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Scall (some _t'2)
      (Expr.Evar _x86_width_effective (Ty.Tfunction [tuchar] tuchar
                                        cc_default))
      [(Expr.Etempvar ___x86_wr_raw_width tuchar)])
    (Stmt.Sset ___x86_wr_width
      (Expr.Ecast (Expr.Etempvar _t'2 tuchar) tuchar)))
  (Stmt.Ssequence
    (Stmt.Sset ___x86_wr_shift
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuchar))
    (Stmt.Ssequence
      (Stmt.Sset ___x86_wr_next
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) tulong))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                              (Expr.Ecast (Expr.Etempvar _dst tulong) tulong)
                              (Expr.Econst_int (Integers.Int.repr 16) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Sset _t'43
                (Expr.Efield
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                              (Ty.Tstruct _x86_sim_register_state noattr))
                            (Positive.ofNat 18727075383868559167)
                            (Ty.Tunion __3115 noattr)) _gpr_cells
                          (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                        (Expr.Ecast (Expr.Etempvar _dst tulong) tuchar)
                        (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                      (Ty.Tstruct _x86_sim_gpr_cell noattr)) _value
                    (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
              (Stmt.Sset _t'3
                (Expr.Ecast (Expr.Etempvar _t'43 (tptr tvoid)) (tptr tvoid))))
            (Stmt.Sset _t'3
              (Expr.Ecast
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                  (tptr tvoid)) (tptr tvoid))))
          (Stmt.Sassign
            (Expr.Efield
              (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr)) _ptr
              (tptr tvoid)) (Expr.Etempvar _t'3 (tptr tvoid))))
        (Stmt.Ssequence
          (Stmt.Sloop
            (Stmt.Ssequence
              (Stmt.Sset ___x86_tag_reg__1 (Expr.Etempvar _dst tulong))
              (Stmt.Ssequence
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                    (Expr.Etempvar ___x86_tag_reg__1 tulong)
                                    (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                    tint)
                  (Stmt.Ssequence
                    (Stmt.Sset _t'42
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                  (Ty.Tstruct _x86_sim_register_state noattr))
                                (Positive.ofNat 18727075383868559167)
                                (Ty.Tunion __3115 noattr)) _gpr_cells
                              (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                            (Expr.Ecast
                              (Expr.Etempvar ___x86_tag_reg__1 tulong)
                              tuchar)
                            (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                          (Ty.Tstruct _x86_sim_gpr_cell noattr)) _tag tuchar))
                    (Stmt.Sset _t'4
                      (Expr.Ecast (Expr.Etempvar _t'42 tuchar) tuint)))
                  (Stmt.Sset _t'4
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                      tuint)))
                (Stmt.Sset ___x86_wr_cell_tag
                  (Expr.Ecast (Expr.Etempvar _t'4 tuint) tuchar))))
            Stmt.Sbreak)
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Ecast
                                    (Expr.Etempvar ___x86_wr_width tuchar)
                                    tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                  tint)
                (Stmt.Sset _t'9
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                    tuint))
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Ecast
                                      (Expr.Etempvar ___x86_wr_width tuchar)
                                      tuchar)
                                    (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                    tint)
                  (Stmt.Ssequence
                    (Stmt.Sset _t'9
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
                    (Stmt.Sset _t'9
                      (Expr.Ecast (Expr.Etempvar _t'9 tuint) tuint)))
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Ecast
                                        (Expr.Etempvar ___x86_wr_width tuchar)
                                        tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sset _t'9
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 2) tuint)
                            tuint))
                        (Stmt.Sset _t'9
                          (Expr.Ecast (Expr.Etempvar _t'9 tuint) tuint)))
                      (Stmt.Sset _t'9
                        (Expr.Ecast (Expr.Etempvar _t'9 tuint) tuint)))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sset _t'9
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 3) tuint)
                            tuint))
                        (Stmt.Sset _t'9
                          (Expr.Ecast (Expr.Etempvar _t'9 tuint) tuint)))
                      (Stmt.Sset _t'9
                        (Expr.Ecast (Expr.Etempvar _t'9 tuint) tuint))))))
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar _t'9 tuint)
                                  (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                  tint)
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar _dst tulong)
                                      (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Sset _t'40
                        (Expr.Efield
                          (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                          _ptr (tptr tvoid)))
                      (Stmt.Ssequence
                        (Stmt.Sset _t'41
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                              (Ty.Tstruct _x86_sim_register_state noattr))
                            _native_stack_base tulong))
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                            _ptr (tptr tvoid))
                          (Expr.Ecast
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Etempvar _t'40 (tptr tvoid)) tlong)
                                  tulong) (Expr.Etempvar _t'41 tulong)
                                tulong) tlong) (tptr tvoid)))))
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                        tint)
                      (Stmt.Ssequence
                        (Stmt.Sloop
                          (Stmt.Ssequence
                            s_kprog_x86_read_recovery_mem_2
                            s_kprog_x86_read_recovery_mem_3)
                          Stmt.Sbreak)
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                            _ptr (tptr tvoid))
                          (Expr.Ecast
                            (Expr.Ecast
                              (Expr.Etempvar ___x86_wr_stack_bits tulong)
                              tlong) (tptr tvoid))))
                      Stmt.Sskip))
                  (Stmt.Sloop
                    (Stmt.Ssequence
                      (Stmt.Sset ___kprog_x86_lane
                        (Expr.Ecast (Expr.Etempvar ___x86_wr_next tulong)
                          tuchar))
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                                            (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                            tint)
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Etempvar ___x86_wr_shift tuchar)
                                              (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                              tint)
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                                    _b (tarray tuchar 8))
                                  (Expr.Econst_int (Integers.Int.repr 1) tint)
                                  (tptr tuchar)) tuchar)
                              (Expr.Etempvar ___kprog_x86_lane tuchar))
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                                    _b (tarray tuchar 8))
                                  (Expr.Econst_int (Integers.Int.repr 0) tint)
                                  (tptr tuchar)) tuchar)
                              (Expr.Etempvar ___kprog_x86_lane tuchar)))
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Sset _t'36
                                (Expr.Efield
                                  (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                                  _ptr (tptr tvoid)))
                              (Stmt.Sbuiltin none
                                (ExtFun.EF_vstore Chunk.Mint64)
                                [(tptr (tvolatile (tptr tvoid))),
                                 (tvolatile (tptr tvoid))]
                                [(Expr.Eaddrof
                                   (Expr.Efield
                                     (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3825 noattr)))
                                     _ptr (tvolatile (tptr tvoid)))
                                   (tptr (tvolatile (tptr tvoid)))),
                                 (Expr.Etempvar _t'36 (tptr tvoid))]))
                            (Stmt.Ssequence
                              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                  (Expr.Etempvar ___x86_wr_shift tuchar)
                                                  (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                                  tint)
                                s_kprog_x86_read_recovery_mem_4
                                s_kprog_x86_read_recovery_mem_5)
                              (Stmt.Ssequence
                                s_kprog_x86_read_recovery_mem_6
                                s_kprog_x86_read_recovery_mem_7))))
                        (Stmt.Sset ___x86_wr_cell_tag
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tuint)
                            tuchar))))
                    Stmt.Sbreak))
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Ecast
                                        (Expr.Etempvar ___x86_wr_width tuchar)
                                        tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                      tint)
                    (Stmt.Sset _t'8
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 0) tuint) tuint))
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Ecast
                                          (Expr.Etempvar ___x86_wr_width tuchar)
                                          tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                        tint)
                      (Stmt.Ssequence
                        (Stmt.Sset _t'8
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 1) tuint)
                            tuint))
                        (Stmt.Sset _t'8
                          (Expr.Ecast (Expr.Etempvar _t'8 tuint) tuint)))
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Ecast
                                            (Expr.Etempvar ___x86_wr_width tuchar)
                                            tuchar)
                                          (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                          tint)
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            s_kprog_x86_read_recovery_mem_8
                            (Stmt.Sset _t'8
                              (Expr.Ecast (Expr.Etempvar _t'8 tuint) tuint)))
                          (Stmt.Sset _t'8
                            (Expr.Ecast (Expr.Etempvar _t'8 tuint) tuint)))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            s_kprog_x86_read_recovery_mem_9
                            (Stmt.Sset _t'8
                              (Expr.Ecast (Expr.Etempvar _t'8 tuint) tuint)))
                          (Stmt.Sset _t'8
                            (Expr.Ecast (Expr.Etempvar _t'8 tuint) tuint))))))
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar _t'8 tuint)
                                      (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Etempvar _dst tulong)
                                          (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                          tint)
                        (Stmt.Ssequence
                          (Stmt.Sset _t'34
                            (Expr.Efield
                              (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                              _ptr (tptr tvoid)))
                          (Stmt.Ssequence
                            (Stmt.Sset _t'35
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                  (Ty.Tstruct _x86_sim_register_state noattr))
                                _native_stack_base tulong))
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                                _ptr (tptr tvoid))
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Ecast
                                      (Expr.Ecast
                                        (Expr.Etempvar _t'34 (tptr tvoid))
                                        tlong) tulong)
                                    (Expr.Etempvar _t'35 tulong) tulong)
                                  tlong) (tptr tvoid)))))
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                                            (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                            tint)
                          (Stmt.Ssequence
                            (Stmt.Sloop
                              s_kprog_x86_read_recovery_mem_10
                              s_kprog_x86_read_recovery_mem_11)
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                                _ptr (tptr tvoid))
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Etempvar ___x86_wr_stack_bits__1 tulong)
                                  tlong) (tptr tvoid))))
                          Stmt.Sskip))
                      (Stmt.Sloop
                        (Stmt.Ssequence
                          (Stmt.Sset ___kprog_x86_lane__1
                            (Expr.Ecast (Expr.Etempvar ___x86_wr_next tulong)
                              tushort))
                          (Stmt.Ssequence
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                                                (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                                tint)
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                                  _w tushort)
                                (Expr.Etempvar ___kprog_x86_lane__1 tushort))
                              (Stmt.Ssequence
                                s_kprog_x86_read_recovery_mem_12
                                s_kprog_x86_read_recovery_mem_13))
                            (Stmt.Sset ___x86_wr_cell_tag
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                tuchar))))
                        Stmt.Sbreak))
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Ecast
                                            (Expr.Etempvar ___x86_wr_width tuchar)
                                            tuchar)
                                          (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                          tint)
                        (Stmt.Sset _t'7
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tuint)
                            tuint))
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Ecast
                                              (Expr.Etempvar ___x86_wr_width tuchar)
                                              tuchar)
                                            (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                            tint)
                          (Stmt.Ssequence
                            (Stmt.Sset _t'7
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                tuint))
                            (Stmt.Sset _t'7
                              (Expr.Ecast (Expr.Etempvar _t'7 tuint) tuint)))
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Ecast
                                                (Expr.Etempvar ___x86_wr_width tuchar)
                                                tuchar)
                                              (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                              tint)
                            s_kprog_x86_read_recovery_mem_14
                            s_kprog_x86_read_recovery_mem_15)))
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Etempvar _t'7 tuint)
                                          (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                          tint)
                        (Stmt.Ssequence
                          (Stmt.Sset ___x86_wr_next
                            (Expr.Ecast
                              (Expr.Ecast
                                (Expr.Etempvar ___x86_wr_next tulong) tuint)
                              tulong))
                          (Stmt.Sloop
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                                  _ptr (tptr tvoid))
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Ecast
                                      (Expr.Etempvar ___x86_wr_next tulong)
                                      tuint) tlong) (tptr tvoid)))
                              (Stmt.Sset ___x86_wr_cell_tag
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                  tuchar)))
                            Stmt.Sbreak))
                        (Stmt.Sloop
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                                _ptr (tptr tvoid))
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Etempvar ___x86_wr_next tulong)
                                    tulong) tlong) (tptr tvoid)))
                            (Stmt.Sset ___x86_wr_cell_tag
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                tuchar)))
                          Stmt.Sbreak)))))))
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar _dst tulong)
                                  (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                  tint)
                (Stmt.Ssequence
                  (Stmt.Sset _t'28
                    (Expr.Efield
                      (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                      _ptr (tptr tvoid)))
                  (Stmt.Ssequence
                    (Stmt.Sset _t'29
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                          (Ty.Tstruct _x86_sim_register_state noattr))
                        _native_stack_base tulong))
                    (Stmt.Sassign
                      (Expr.Efield
                        (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                        _ptr (tptr tvoid))
                      (Expr.Ecast
                        (Expr.Ecast
                          (Expr.Ebinop Binop.Osub
                            (Expr.Ecast
                              (Expr.Ecast (Expr.Etempvar _t'28 (tptr tvoid))
                                tlong) tulong) (Expr.Etempvar _t'29 tulong)
                            tulong) tlong) (tptr tvoid)))))
                Stmt.Sskip)
              (Stmt.Ssequence
                (Stmt.Sset ___x86_wr_next_ptr
                  (Expr.Efield
                    (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                    _ptr (tptr tvoid)))
                (Stmt.Ssequence
                  (Stmt.Sset ___x86_wr_next_tag
                    (Expr.Ecast (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                      tuchar))
                  (Stmt.Ssequence
                    (Stmt.Sloop
                      (Stmt.Ssequence
                        (Stmt.Sset ___x86_store_reg
                          (Expr.Etempvar _dst tulong))
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                            (Expr.Etempvar ___x86_store_reg tulong)
                                            (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                            tint)
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Efield
                                        (Expr.Efield
                                          (Expr.Ederef
                                            (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                            (Ty.Tstruct _x86_sim_register_state noattr))
                                          (Positive.ofNat 18727075383868559167)
                                          (Ty.Tunion __3115 noattr))
                                        _gpr_cells
                                        (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                                      (Expr.Ecast
                                        (Expr.Etempvar ___x86_store_reg tulong)
                                        tuchar)
                                      (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                                    (Ty.Tstruct _x86_sim_gpr_cell noattr))
                                  _value (Ty.Tunion _x86_sim_gpr noattr))
                                _ptr (tptr tvoid))
                              (Expr.Etempvar ___x86_wr_next_ptr (tptr tvoid)))
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Efield
                                        (Expr.Ederef
                                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                          (Ty.Tstruct _x86_sim_register_state noattr))
                                        (Positive.ofNat 18727075383868559167)
                                        (Ty.Tunion __3115 noattr)) _gpr_cells
                                      (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                                    (Expr.Ecast
                                      (Expr.Etempvar ___x86_store_reg tulong)
                                      tuchar)
                                    (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                                  (Ty.Tstruct _x86_sim_gpr_cell noattr)) _tag
                                tuchar)
                              (Expr.Etempvar ___x86_wr_next_tag tuchar)))
                          Stmt.Sskip))
                      Stmt.Sbreak)
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Etempvar _dst tulong)
                                        (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                        tint)
                      (Stmt.Sloop
                        (Stmt.Ssequence
                          (Stmt.Sset ___x86_release_old
                            (Expr.Etempvar ___x86_write_old_sp tlong))
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Sset _t'27
                                (Expr.Efield
                                  (Expr.Efield
                                    (Expr.Efield
                                      (Expr.Efield
                                        (Expr.Ederef
                                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                          (Ty.Tstruct _x86_sim_register_state noattr))
                                        (Positive.ofNat 18727075383868559167)
                                        (Ty.Tunion __3115 noattr))
                                      (Positive.ofNat 18727075383868559167)
                                      (Ty.Tstruct __3116 noattr)) _rsp
                                    (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                                  (tptr tvoid)))
                              (Stmt.Sset ___x86_release_new
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Etempvar _t'27 (tptr tvoid)) tlong)
                                  tlong)))
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Ogt
                                                (Expr.Etempvar ___x86_release_new tlong)
                                                (Expr.Etempvar ___x86_release_old tlong)
                                                tint)
                              s_kprog_x86_read_recovery_mem_16
                              Stmt.Sskip)))
                        Stmt.Sbreak)
                      Stmt.Sskip)))))))))))

def f_kprog_x86_read_recovery_mem : Function := {
  fn_return := tint,
  fn_callconv := cc_default,
  fn_params := [(_state, (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
                (_arena, (tptr (Ty.Tstruct _kprog_x86_arena noattr))),
                (_facts, (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr))),
                (_capacity, tuint), (_base, tulong), (_dst, tulong),
                (_aux, tulong), (_displacement, tlong)],
  fn_vars := [(___x86_wr_cell, (Ty.Tunion _x86_sim_gpr noattr)),
              (___kprog_x86_partial, (tvolatile (Ty.Tunion __3825 noattr))),
              (___kprog_x86_partial__1,
               (tvolatile (Ty.Tunion __3831 noattr)))],
  fn_temps := [(___x86_state,
                (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
               (_recovered, tint), (___x86_read_recovered, tint),
               (___x86_read_tag, tuchar), (___x86_tag_reg, tulong),
               (___x86_write_old_sp, tlong), (___x86_wr_raw_width, tuchar),
               (___x86_wr_width, tuchar), (___x86_wr_shift, tuchar),
               (___x86_wr_next, tulong), (___x86_wr_cell_tag, tuchar),
               (___x86_tag_reg__1, tulong), (___x86_wr_stack_bits, tulong),
               (___x86_stack_delta, tulong), (___kprog_x86_lane, tuchar),
               (___kprog_x86_bits, tulong),
               (___x86_wr_stack_bits__1, tulong),
               (___x86_stack_delta__1, tulong),
               (___kprog_x86_lane__1, tushort),
               (___kprog_x86_bits__1, tulong),
               (___x86_wr_next_ptr, (tptr tvoid)),
               (___x86_wr_next_tag, tuchar), (___x86_store_reg, tulong),
               (___x86_release_old, tlong), (___x86_release_new, tlong),
               (___x86_release_i, tuint), (___x86_release_off, tlong),
               (___x86_release_lane, tuint), (___x86_sv_sp, tlong),
               (___x86_sv_i, tuint), (_t'21, tint), (_t'20, tint),
               (_t'19, tulong), (_t'18, tlong), (_t'17, tulong),
               (_t'16, tint), (_t'15, tint), (_t'14, tint), (_t'13, tint),
               (_t'12, tint), (_t'11, tulong), (_t'10, tulong),
               (_t'9, tuint), (_t'8, tuint), (_t'7, tuint),
               (_t'6, (tvolatile (tptr tvoid))),
               (_t'5, (tvolatile (tptr tvoid))), (_t'4, tuint),
               (_t'3, (tptr tvoid)), (_t'2, tuchar), (_t'1, tuint),
               (_t'45, tuchar), (_t'44, (tptr tvoid)), (_t'43, (tptr tvoid)),
               (_t'42, tuchar), (_t'41, tulong), (_t'40, (tptr tvoid)),
               (_t'39, (tptr (tvolatile tuchar))), (_t'38, (tptr tvoid)),
               (_t'37, tulong), (_t'36, (tptr tvoid)), (_t'35, tulong),
               (_t'34, (tptr tvoid)), (_t'33, (tptr (tvolatile tuchar))),
               (_t'32, (tptr tvoid)), (_t'31, tulong), (_t'30, (tptr tvoid)),
               (_t'29, tulong), (_t'28, (tptr tvoid)), (_t'27, (tptr tvoid)),
               (_t'26, (tptr (tvolatile tulong))),
               (_t'25, (tptr (tvolatile tuchar))), (_t'24, (tptr tvoid)),
               (_t'23, (tptr tuchar)), (_t'22, (tptr (tptr tvoid)))],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_state
    (Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))))
  (Stmt.Ssequence
    (Stmt.Sloop
      (Stmt.Ssequence
        (Stmt.Sset ___x86_read_recovered
          (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.One
                                  (Expr.Etempvar _base tulong)
                                  (Expr.Econst_int (Integers.Int.repr 255) tuint)
                                  tint)
                (Stmt.Sset _t'20
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tint)
                    tint))
                (Stmt.Sset _t'20
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                    tint)))
              (Stmt.Sifthenelse (Expr.Ecast (Expr.Etempvar _t'20 tint)
                                  tuchar)
                (Stmt.Sset _t'21
                  (Expr.Ecast
                    (Expr.Ebinop Binop.One (Expr.Etempvar _base tulong)
                      (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
                    tbool))
                (Stmt.Sset _t'21
                  (Expr.Econst_int (Integers.Int.repr 0) tint))))
            (Stmt.Sifthenelse (Expr.Etempvar _t'21 tint)
              (Stmt.Ssequence
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Sset ___x86_tag_reg (Expr.Etempvar _base tulong))
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                          (Expr.Etempvar ___x86_tag_reg tulong)
                                          (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                          tint)
                        (Stmt.Ssequence
                          (Stmt.Sset _t'45
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Efield
                                      (Expr.Ederef
                                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                        (Ty.Tstruct _x86_sim_register_state noattr))
                                      (Positive.ofNat 18727075383868559167)
                                      (Ty.Tunion __3115 noattr)) _gpr_cells
                                    (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                                  (Expr.Ecast
                                    (Expr.Etempvar ___x86_tag_reg tulong)
                                    tuchar)
                                  (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                                (Ty.Tstruct _x86_sim_gpr_cell noattr)) _tag
                              tuchar))
                          (Stmt.Sset _t'1
                            (Expr.Ecast (Expr.Etempvar _t'45 tuchar) tuint)))
                        (Stmt.Sset _t'1
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tuint)
                            tuint)))
                      (Stmt.Sset ___x86_read_tag
                        (Expr.Ecast (Expr.Etempvar _t'1 tuint) tuchar))))
                  Stmt.Sbreak)
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar ___x86_read_tag tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Scall (some _t'17)
                          (Expr.Evar _kprog_x86_read_reg (Ty.Tfunction
                                                           [(tptr (Ty.Tstruct _x86_sim_register_state noattr)),
                                                            (tptr (Ty.Tstruct _kprog_x86_arena noattr)),
                                                            tuint, tuchar,
                                                            tuchar, tuchar]
                                                           tulong cc_default))
                          [(Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
                           (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr))),
                           (Expr.Etempvar _capacity tuint),
                           (Expr.Etempvar _base tulong),
                           (Expr.Econst_int (Integers.Int.repr 8) tuint),
                           (Expr.Econst_int (Integers.Int.repr 0) tuint)])
                        (Stmt.Scall (some _t'18)
                          (Expr.Evar _kprog_x86_mem_offset (Ty.Tfunction
                                                             [(tptr (Ty.Tstruct _x86_sim_register_state noattr)),
                                                              (tptr (Ty.Tstruct _kprog_x86_arena noattr)),
                                                              tuint, tulong,
                                                              tlong] tlong
                                                             cc_default))
                          [(Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
                           (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr))),
                           (Expr.Etempvar _capacity tuint),
                           (Expr.Etempvar _aux tulong),
                           (Expr.Etempvar _displacement tlong)]))
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                          (Expr.Ecast
                                            (Expr.Ebinop Binop.Oadd
                                              (Expr.Etempvar _t'17 tulong)
                                              (Expr.Ecast
                                                (Expr.Etempvar _t'18 tlong)
                                                tulong) tulong) tulong)
                                          (Expr.Econst_int (Integers.Int.repr 4096) tuint)
                                          tint)
                        (Stmt.Sset _t'16
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 1) tint)
                            tbool))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Scall (some _t'19)
                              (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                   [tuint]
                                                                   tulong
                                                                   cc_default))
                              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                            (Stmt.Sset _t'16
                              (Expr.Ecast
                                (Expr.Ebinop Binop.Oand
                                  (Expr.Etempvar _t'19 tulong)
                                  (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                  tulong) tbool)))
                          (Stmt.Sset _t'16
                            (Expr.Ecast (Expr.Etempvar _t'16 tint) tbool)))))
                    (Stmt.Sset _t'16
                      (Expr.Econst_int (Integers.Int.repr 0) tint)))
                  (Stmt.Sifthenelse (Expr.Etempvar _t'16 tint)
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Etempvar _dst tulong)
                                          (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                          tint)
                        (Stmt.Scall none
                          (Expr.Evar _kprog_c_trap (Ty.Tfunction [] tvoid
                                                     cc_default)) [])
                        (Stmt.Sloop
                          (Stmt.Ssequence
                            s_kprog_x86_read_recovery_mem_0
                            (Stmt.Ssequence
                              s_kprog_x86_read_recovery_mem_1
                              s_kprog_x86_read_recovery_mem_17))
                          Stmt.Sbreak))
                      (Stmt.Sset ___x86_read_recovered
                        (Expr.Econst_int (Integers.Int.repr 1) tint)))
                    Stmt.Sskip)))
              Stmt.Sskip))
          (Stmt.Sset _recovered (Expr.Etempvar ___x86_read_recovered tint))))
      Stmt.Sbreak)
    (Stmt.Sreturn (some (Expr.Etempvar _recovered tint)))))
}

def f_kprog_x86_mov_load_write_width : Function := {
  fn_return := tuchar,
  fn_callconv := cc_default,
  fn_params := [(_flags, tulong)],
  fn_vars := [],
  fn_temps := [(_width, tuchar), (___kprog_x86_ml_write, tuchar),
               (_t'1, tulong)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Etempvar _flags tulong)
          (Stmt.Sset _t'1 (Expr.Ecast (Expr.Etempvar _flags tulong) tulong))
          (Stmt.Sset _t'1
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tuint) tulong)))
        (Stmt.Sset ___kprog_x86_ml_write
          (Expr.Ecast (Expr.Etempvar _t'1 tulong) tuchar)))
      (Stmt.Sset _width
        (Expr.Ecast (Expr.Etempvar ___kprog_x86_ml_write tuchar) tuchar)))
    Stmt.Sbreak)
  (Stmt.Sreturn (some (Expr.Etempvar _width tuchar))))
}

def f_kprog_x86_mov_load_mem_width : Function := {
  fn_return := tuchar,
  fn_callconv := cc_default,
  fn_params := [(_flags, tulong), (_aux, tulong)],
  fn_vars := [],
  fn_temps := [(_width, tuchar), (___kprog_x86_ml_mem, tuchar),
               (___kprog_x86_ml_write, tuchar), (_t'1, tulong)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sset ___kprog_x86_ml_mem
        (Expr.Ecast
          (Expr.Ecast
            (Expr.Ebinop Binop.Oand
              (Expr.Ebinop Binop.Oshr (Expr.Etempvar _aux tulong)
                (Expr.Econst_int (Integers.Int.repr 16) tint) tulong)
              (Expr.Econst_int (Integers.Int.repr 255) tuint) tulong) tuchar)
          tuchar))
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Eunop Unop.Onotbool
                            (Expr.Etempvar ___kprog_x86_ml_mem tuchar) tint)
          (Stmt.Sloop
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sifthenelse (Expr.Etempvar _flags tulong)
                  (Stmt.Sset _t'1
                    (Expr.Ecast (Expr.Etempvar _flags tulong) tulong))
                  (Stmt.Sset _t'1
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tuint)
                      tulong)))
                (Stmt.Sset ___kprog_x86_ml_write
                  (Expr.Ecast (Expr.Etempvar _t'1 tulong) tuchar)))
              (Stmt.Sset ___kprog_x86_ml_mem
                (Expr.Ecast (Expr.Etempvar ___kprog_x86_ml_write tuchar)
                  tuchar)))
            Stmt.Sbreak)
          Stmt.Sskip)
        (Stmt.Sset _width
          (Expr.Ecast (Expr.Etempvar ___kprog_x86_ml_mem tuchar) tuchar))))
    Stmt.Sbreak)
  (Stmt.Sreturn (some (Expr.Etempvar _width tuchar))))
}

def f_kprog_x86_mov_load_arm : Function := {
  fn_return := tuchar,
  fn_callconv := cc_default,
  fn_params := [(_stack, tulong), (_plain, tulong), (_memory, tulong),
                (_write, tulong), (_tag, tulong)],
  fn_vars := [],
  fn_temps := [(_arm, tuchar), (___kprog_x86_ml_arm, tuchar), (_t'3, tint),
               (_t'2, tint), (_t'1, tint)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sifthenelse (Expr.Etempvar _stack tulong)
        (Stmt.Sset ___kprog_x86_ml_arm
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuchar))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Etempvar _plain tulong)
                (Stmt.Sset _t'1
                  (Expr.Ecast
                    (Expr.Ebinop Binop.Oeq (Expr.Etempvar _memory tulong)
                      (Expr.Econst_int (Integers.Int.repr 8) tuint) tint)
                    tbool))
                (Stmt.Sset _t'1 (Expr.Econst_int (Integers.Int.repr 0) tint)))
              (Stmt.Sifthenelse (Expr.Etempvar _t'1 tint)
                (Stmt.Sset _t'2
                  (Expr.Ecast
                    (Expr.Ebinop Binop.Oeq (Expr.Etempvar _write tulong)
                      (Expr.Econst_int (Integers.Int.repr 8) tuint) tint)
                    tbool))
                (Stmt.Sset _t'2 (Expr.Econst_int (Integers.Int.repr 0) tint))))
            (Stmt.Sifthenelse (Expr.Etempvar _t'2 tint)
              (Stmt.Sset _t'3
                (Expr.Ecast
                  (Expr.Ebinop Binop.Oeq (Expr.Etempvar _tag tulong)
                    (Expr.Econst_int (Integers.Int.repr 1) tuint) tint)
                  tbool))
              (Stmt.Sset _t'3 (Expr.Econst_int (Integers.Int.repr 0) tint))))
          (Stmt.Sifthenelse (Expr.Etempvar _t'3 tint)
            (Stmt.Sset ___kprog_x86_ml_arm
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint)
                tuchar))
            (Stmt.Sset ___kprog_x86_ml_arm
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint)
                tuchar)))))
      (Stmt.Sset _arm
        (Expr.Ecast (Expr.Etempvar ___kprog_x86_ml_arm tuchar) tuchar)))
    Stmt.Sbreak)
  (Stmt.Sreturn (some (Expr.Etempvar _arm tuchar))))
}

def composites : List CompositeDef :=
[(CompositeDef.Composite __150 SU.Union
   [(Member.Member_plain _flow_keys
      (tptr (Ty.Tstruct _bpf_flow_keys noattr))),
    (Member.Member_plain ___kprog_padding_flow_keys tulong)]
   { attr_volatile := false, attr_alignas := (some 3) }),
 (CompositeDef.Composite __151 SU.Union
   [(Member.Member_plain _sk (tptr (Ty.Tstruct _bpf_sock noattr))),
    (Member.Member_plain ___kprog_padding_sk tulong)]
   { attr_volatile := false, attr_alignas := (some 3) }),
 (CompositeDef.Composite ___sk_buff SU.Struct
   [(Member.Member_plain _len tuint), (Member.Member_plain _pkt_type tuint),
    (Member.Member_plain _mark tuint),
    (Member.Member_plain _queue_mapping tuint),
    (Member.Member_plain _protocol tuint),
    (Member.Member_plain _vlan_present tuint),
    (Member.Member_plain _vlan_tci tuint),
    (Member.Member_plain _vlan_proto tuint),
    (Member.Member_plain _priority tuint),
    (Member.Member_plain _ingress_ifindex tuint),
    (Member.Member_plain _ifindex tuint),
    (Member.Member_plain _tc_index tuint),
    (Member.Member_plain _cb (tarray tuint 5)),
    (Member.Member_plain _hash tuint),
    (Member.Member_plain _tc_classid tuint),
    (Member.Member_plain _data tuint), (Member.Member_plain _data_end tuint),
    (Member.Member_plain _napi_id tuint),
    (Member.Member_plain _family tuint),
    (Member.Member_plain _remote_ip4 tuint),
    (Member.Member_plain _local_ip4 tuint),
    (Member.Member_plain _remote_ip6 (tarray tuint 4)),
    (Member.Member_plain _local_ip6 (tarray tuint 4)),
    (Member.Member_plain _remote_port tuint),
    (Member.Member_plain _local_port tuint),
    (Member.Member_plain _data_meta tuint),
    (Member.Member_plain (Positive.ofNat 18727075383868559167)
      (Ty.Tunion __150 noattr)), (Member.Member_plain _tstamp tulong),
    (Member.Member_plain _wire_len tuint),
    (Member.Member_plain _gso_segs tuint),
    (Member.Member_plain (Positive.ofNat 19015305760020270911)
      (Ty.Tunion __151 noattr)), (Member.Member_plain _gso_size tuint),
    (Member.Member_plain _tstamp_type tuchar),
    (Member.Member_plain ___kprog_reserved (tarray tuchar 3)),
    (Member.Member_plain _hwtstamp tulong)]
   noattr),
 (CompositeDef.Composite _x86_sim_xdp_abi SU.Struct
   [(Member.Member_plain _data (tptr tvoid)),
    (Member.Member_plain _data_end (tptr tvoid)),
    (Member.Member_plain _cb (tarray tuint 5))]
   noattr),
 (CompositeDef.Composite _x86_sim_skb_abi SU.Struct
   [(Member.Member_plain _pad0 (tarray tuchar 48)),
    (Member.Member_plain _cb (tarray tuint 5)),
    (Member.Member_plain _pad1 (tarray tuchar 12)),
    (Member.Member_plain _data_end (tptr tvoid)),
    (Member.Member_plain _pad2 (tarray tuchar 120)),
    (Member.Member_plain _data (tptr tvoid))]
   noattr),
 (CompositeDef.Composite _x86_sim_gpr SU.Union
   [(Member.Member_plain _ptr (tptr tvoid)),
    (Member.Member_plain _w tushort),
    (Member.Member_plain _b (tarray tuchar 8))]
   noattr),
 (CompositeDef.Composite _x86_sim_gpr_cell SU.Struct
   [(Member.Member_plain _value (Ty.Tunion _x86_sim_gpr noattr)),
    (Member.Member_plain _tag tuchar)]
   noattr),
 (CompositeDef.Composite __3116 SU.Struct
   [(Member.Member_plain _rax (Ty.Tunion _x86_sim_gpr noattr)),
    (Member.Member_plain _rax_tag tuchar),
    (Member.Member_plain _rcx (Ty.Tunion _x86_sim_gpr noattr)),
    (Member.Member_plain _rcx_tag tuchar),
    (Member.Member_plain _rdx (Ty.Tunion _x86_sim_gpr noattr)),
    (Member.Member_plain _rdx_tag tuchar),
    (Member.Member_plain _rbx (Ty.Tunion _x86_sim_gpr noattr)),
    (Member.Member_plain _rbx_tag tuchar),
    (Member.Member_plain _rsp (Ty.Tunion _x86_sim_gpr noattr)),
    (Member.Member_plain _rsp_tag tuchar),
    (Member.Member_plain _rbp (Ty.Tunion _x86_sim_gpr noattr)),
    (Member.Member_plain _rbp_tag tuchar),
    (Member.Member_plain _rsi (Ty.Tunion _x86_sim_gpr noattr)),
    (Member.Member_plain _rsi_tag tuchar),
    (Member.Member_plain _rdi (Ty.Tunion _x86_sim_gpr noattr)),
    (Member.Member_plain _rdi_tag tuchar),
    (Member.Member_plain _r8 (Ty.Tunion _x86_sim_gpr noattr)),
    (Member.Member_plain _r8_tag tuchar),
    (Member.Member_plain _r9 (Ty.Tunion _x86_sim_gpr noattr)),
    (Member.Member_plain _r9_tag tuchar),
    (Member.Member_plain _r10 (Ty.Tunion _x86_sim_gpr noattr)),
    (Member.Member_plain _r10_tag tuchar),
    (Member.Member_plain _r11 (Ty.Tunion _x86_sim_gpr noattr)),
    (Member.Member_plain _r11_tag tuchar),
    (Member.Member_plain _r12 (Ty.Tunion _x86_sim_gpr noattr)),
    (Member.Member_plain _r12_tag tuchar),
    (Member.Member_plain _r13 (Ty.Tunion _x86_sim_gpr noattr)),
    (Member.Member_plain _r13_tag tuchar),
    (Member.Member_plain _r14 (Ty.Tunion _x86_sim_gpr noattr)),
    (Member.Member_plain _r14_tag tuchar),
    (Member.Member_plain _r15 (Ty.Tunion _x86_sim_gpr noattr)),
    (Member.Member_plain _r15_tag tuchar)]
   noattr),
 (CompositeDef.Composite __3115 SU.Union
   [(Member.Member_plain (Positive.ofNat 18727075383868559167)
      (Ty.Tstruct __3116 noattr)),
    (Member.Member_plain _gpr_cells
      (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))]
   noattr),
 (CompositeDef.Composite _x86_sim_register_state SU.Struct
   [(Member.Member_plain (Positive.ofNat 18727075383868559167)
      (Ty.Tunion __3115 noattr)),
    (Member.Member_plain _native_stack_base tulong),
    (Member.Member_plain _cf tuchar), (Member.Member_plain _zf tuchar),
    (Member.Member_plain _sf tuchar), (Member.Member_plain _of tuchar),
    (Member.Member_plain _pf tuchar), (Member.Member_plain _af tuchar),
    (Member.Member_plain _xmm0_lo tulong),
    (Member.Member_plain _xmm0_hi tulong),
    (Member.Member_plain _ret_addr tulong),
    (Member.Member_plain _call_depth tuint),
    (Member.Member_plain _xdp_abi (Ty.Tstruct _x86_sim_xdp_abi noattr)),
    (Member.Member_plain _skb_abi (Ty.Tstruct _x86_sim_skb_abi noattr)),
    (Member.Member_plain _skb_ctx (tptr (Ty.Tstruct ___sk_buff noattr))),
    (Member.Member_plain _helper_ctx (tptr tvoid)),
    (Member.Member_plain _is_xdp tuchar),
    (Member.Member_plain _helper_abi_base (tptr tvoid)),
    (Member.Member_plain _abi_kind tuchar)]
   noattr),
 (CompositeDef.Composite _kprog_x86_arena SU.Struct
   [(Member.Member_plain _b (tptr (tvolatile tuchar))),
    (Member.Member_plain _q (tptr (tvolatile tulong)))]
   noattr),
 (CompositeDef.Composite _kprog_x86_stack_fact SU.Struct
   [(Member.Member_plain _tag (tptr tuchar)),
    (Member.Member_plain _pointer (tptr (tptr tvoid)))]
   noattr),
 (CompositeDef.Composite __3283 SU.Union
   [(Member.Member_plain _ptr (tptr tvoid)),
    (Member.Member_plain _w tushort),
    (Member.Member_plain _b (tarray tuchar 8))]
   noattr),
 (CompositeDef.Composite __3289 SU.Union
   [(Member.Member_plain _ptr (tptr tvoid)),
    (Member.Member_plain _w tushort),
    (Member.Member_plain _b (tarray tuchar 8))]
   noattr),
 (CompositeDef.Composite __3354 SU.Union
   [(Member.Member_plain _ptr (tptr tvoid)),
    (Member.Member_plain _w tushort),
    (Member.Member_plain _b (tarray tuchar 8))]
   noattr),
 (CompositeDef.Composite __3360 SU.Union
   [(Member.Member_plain _ptr (tptr tvoid)),
    (Member.Member_plain _w tushort),
    (Member.Member_plain _b (tarray tuchar 8))]
   noattr),
 (CompositeDef.Composite __3396 SU.Union
   [(Member.Member_plain _ptr (tptr tvoid)),
    (Member.Member_plain _w tushort),
    (Member.Member_plain _b (tarray tuchar 8))]
   noattr),
 (CompositeDef.Composite __3402 SU.Union
   [(Member.Member_plain _ptr (tptr tvoid)),
    (Member.Member_plain _w tushort),
    (Member.Member_plain _b (tarray tuchar 8))]
   noattr),
 (CompositeDef.Composite __3461 SU.Union
   [(Member.Member_plain _ptr (tptr tvoid)),
    (Member.Member_plain _w tushort),
    (Member.Member_plain _b (tarray tuchar 8))]
   noattr),
 (CompositeDef.Composite __3467 SU.Union
   [(Member.Member_plain _ptr (tptr tvoid)),
    (Member.Member_plain _w tushort),
    (Member.Member_plain _b (tarray tuchar 8))]
   noattr),
 (CompositeDef.Composite __3527 SU.Union
   [(Member.Member_plain _ptr (tptr tvoid)),
    (Member.Member_plain _w tushort),
    (Member.Member_plain _b (tarray tuchar 8))]
   noattr),
 (CompositeDef.Composite __3533 SU.Union
   [(Member.Member_plain _ptr (tptr tvoid)),
    (Member.Member_plain _w tushort),
    (Member.Member_plain _b (tarray tuchar 8))]
   noattr),
 (CompositeDef.Composite __3578 SU.Union
   [(Member.Member_plain _ptr (tptr tvoid)),
    (Member.Member_plain _w tushort),
    (Member.Member_plain _b (tarray tuchar 8))]
   noattr),
 (CompositeDef.Composite __3584 SU.Union
   [(Member.Member_plain _ptr (tptr tvoid)),
    (Member.Member_plain _w tushort),
    (Member.Member_plain _b (tarray tuchar 8))]
   noattr),
 (CompositeDef.Composite __3634 SU.Union
   [(Member.Member_plain _ptr (tptr tvoid)),
    (Member.Member_plain _w tushort),
    (Member.Member_plain _b (tarray tuchar 8))]
   noattr),
 (CompositeDef.Composite __3640 SU.Union
   [(Member.Member_plain _ptr (tptr tvoid)),
    (Member.Member_plain _w tushort),
    (Member.Member_plain _b (tarray tuchar 8))]
   noattr),
 (CompositeDef.Composite __3737 SU.Union
   [(Member.Member_plain _ptr (tptr tvoid)),
    (Member.Member_plain _w tushort),
    (Member.Member_plain _b (tarray tuchar 8))]
   noattr),
 (CompositeDef.Composite __3743 SU.Union
   [(Member.Member_plain _ptr (tptr tvoid)),
    (Member.Member_plain _w tushort),
    (Member.Member_plain _b (tarray tuchar 8))]
   noattr),
 (CompositeDef.Composite __3780 SU.Union
   [(Member.Member_plain _ptr (tptr tvoid)),
    (Member.Member_plain _w tushort),
    (Member.Member_plain _b (tarray tuchar 8))]
   noattr),
 (CompositeDef.Composite __3786 SU.Union
   [(Member.Member_plain _ptr (tptr tvoid)),
    (Member.Member_plain _w tushort),
    (Member.Member_plain _b (tarray tuchar 8))]
   noattr),
 (CompositeDef.Composite __3825 SU.Union
   [(Member.Member_plain _ptr (tptr tvoid)),
    (Member.Member_plain _w tushort),
    (Member.Member_plain _b (tarray tuchar 8))]
   noattr),
 (CompositeDef.Composite __3831 SU.Union
   [(Member.Member_plain _ptr (tptr tvoid)),
    (Member.Member_plain _w tushort),
    (Member.Member_plain _b (tarray tuchar 8))]
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
 (_kprog_c_trap,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_external "kprog_c_trap"
                                   (mksignature [] XType.Xvoid cc_default))
     [] tvoid cc_default)),
 (_kprog_x86_sign_extend_value, GlobDef.Gfun (FunDef.Internal f_kprog_x86_sign_extend_value)),
 (_x86_apply_width, GlobDef.Gfun (FunDef.Internal f_x86_apply_width)),
 (_x86_width_effective, GlobDef.Gfun (FunDef.Internal f_x86_width_effective)),
 (_x86_sign_extend, GlobDef.Gfun (FunDef.Internal f_x86_sign_extend)),
 (_native_lab_entry_input,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_external "native_lab_entry_input"
                                   (mksignature [XType.Xint] XType.Xlong
                                     cc_default)) [tuint] tulong cc_default)),
 (_kprog_x86_mem_load, GlobDef.Gfun (FunDef.Internal f_kprog_x86_mem_load)),
 (_kprog_x86_ptr_load, GlobDef.Gfun (FunDef.Internal f_kprog_x86_ptr_load)),
 (_kprog_x86_read_reg, GlobDef.Gfun (FunDef.Internal f_kprog_x86_read_reg)),
 (_kprog_x86_write_reg, GlobDef.Gfun (FunDef.Internal f_kprog_x86_write_reg)),
 (_kprog_x86_mov_imm, GlobDef.Gfun (FunDef.Internal f_kprog_x86_mov_imm)),
 (_kprog_x86_mov_reg, GlobDef.Gfun (FunDef.Internal f_kprog_x86_mov_reg)),
 (_kprog_x86_movx_reg, GlobDef.Gfun (FunDef.Internal f_kprog_x86_movx_reg)),
 (_kprog_x86_stack_alias, GlobDef.Gfun (FunDef.Internal f_kprog_x86_stack_alias)),
 (_kprog_x86_load_tagged, GlobDef.Gfun (FunDef.Internal f_kprog_x86_load_tagged)),
 (_kprog_x86_native_load_tagged, GlobDef.Gfun (FunDef.Internal f_kprog_x86_native_load_tagged)),
 (_kprog_x86_mem_offset_indexed, GlobDef.Gfun (FunDef.Internal f_kprog_x86_mem_offset_indexed)),
 (_kprog_x86_mem_offset, GlobDef.Gfun (FunDef.Internal f_kprog_x86_mem_offset)),
 (_kprog_x86_read_recovery_at, GlobDef.Gfun (FunDef.Internal f_kprog_x86_read_recovery_at)),
 (_kprog_x86_read_recovery, GlobDef.Gfun (FunDef.Internal f_kprog_x86_read_recovery)),
 (_kprog_x86_read_recovery_mem, GlobDef.Gfun (FunDef.Internal f_kprog_x86_read_recovery_mem)),
 (_kprog_x86_mov_load_write_width, GlobDef.Gfun (FunDef.Internal f_kprog_x86_mov_load_write_width)),
 (_kprog_x86_mov_load_mem_width, GlobDef.Gfun (FunDef.Internal f_kprog_x86_mov_load_mem_width)),
 (_kprog_x86_mov_load_arm, GlobDef.Gfun (FunDef.Internal f_kprog_x86_mov_load_arm))]

def public_idents : List Ident :=
[_kprog_x86_mov_load_arm, _kprog_x86_mov_load_mem_width,
 _kprog_x86_mov_load_write_width, _kprog_x86_read_recovery_mem,
 _kprog_x86_read_recovery, _kprog_x86_read_recovery_at,
 _kprog_x86_mem_offset, _kprog_x86_mem_offset_indexed,
 _kprog_x86_native_load_tagged, _kprog_x86_load_tagged,
 _kprog_x86_stack_alias, _kprog_x86_movx_reg, _kprog_x86_mov_reg,
 _kprog_x86_mov_imm, _kprog_x86_write_reg, _kprog_x86_read_reg,
 _kprog_x86_ptr_load, _native_lab_entry_input, _kprog_c_trap,
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

end X86Pointer

