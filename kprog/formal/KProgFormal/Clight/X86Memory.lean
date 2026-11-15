import Clightdefs
open CC

namespace X86Memory

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
  def source_file : String := "c/X86Memory.c"
  def normalized : Bool := true
end Info

def __150 : Ident := identOfString "_150"
def __151 : Ident := identOfString "_151"
def __3119 : Ident := identOfString "_3119"
def __3120 : Ident := identOfString "_3120"
def __3440 : Ident := identOfString "_3440"
def __3446 : Ident := identOfString "_3446"
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
def ___kprog_c_store_value : Ident := identOfString "__kprog_c_store_value"
def ___kprog_c_store_value__1 : Ident := identOfString "__kprog_c_store_value__1"
def ___kprog_c_store_value__2 : Ident := identOfString "__kprog_c_store_value__2"
def ___kprog_c_store_value__3 : Ident := identOfString "__kprog_c_store_value__3"
def ___kprog_padding_flow_keys : Ident := identOfString "__kprog_padding_flow_keys"
def ___kprog_padding_sk : Ident := identOfString "__kprog_padding_sk"
def ___kprog_reserved : Ident := identOfString "__kprog_reserved"
def ___kprog_x86_bits : Ident := identOfString "__kprog_x86_bits"
def ___kprog_x86_bits__1 : Ident := identOfString "__kprog_x86_bits__1"
def ___kprog_x86_lane : Ident := identOfString "__kprog_x86_lane"
def ___kprog_x86_lane__1 : Ident := identOfString "__kprog_x86_lane__1"
def ___kprog_x86_mb_arm : Ident := identOfString "__kprog_x86_mb_arm"
def ___kprog_x86_mb_width : Ident := identOfString "__kprog_x86_mb_width"
def ___kprog_x86_md_src : Ident := identOfString "__kprog_x86_md_src"
def ___kprog_x86_partial : Ident := identOfString "__kprog_x86_partial"
def ___kprog_x86_partial__1 : Ident := identOfString "__kprog_x86_partial__1"
def ___sk_buff : Ident := identOfString "__sk_buff"
def ___x86_alias_delta : Ident := identOfString "__x86_alias_delta"
def ___x86_alias_delta__1 : Ident := identOfString "__x86_alias_delta__1"
def ___x86_alias_observed : Ident := identOfString "__x86_alias_observed"
def ___x86_alias_observed__1 : Ident := identOfString "__x86_alias_observed__1"
def ___x86_alias_offset : Ident := identOfString "__x86_alias_offset"
def ___x86_alias_offset__1 : Ident := identOfString "__x86_alias_offset__1"
def ___x86_captured_xdp_value : Ident := identOfString "__x86_captured_xdp_value"
def ___x86_cbr_addr : Ident := identOfString "__x86_cbr_addr"
def ___x86_cbr_value : Ident := identOfString "__x86_cbr_value"
def ___x86_data_observed : Ident := identOfString "__x86_data_observed"
def ___x86_data_offset : Ident := identOfString "__x86_data_offset"
def ___x86_l_addr : Ident := identOfString "__x86_l_addr"
def ___x86_l_arm : Ident := identOfString "__x86_l_arm"
def ___x86_l_base_form : Ident := identOfString "__x86_l_base_form"
def ___x86_l_base_none : Ident := identOfString "__x86_l_base_none"
def ___x86_l_base_ptr : Ident := identOfString "__x86_l_base_ptr"
def ___x86_l_base_ptr__1 : Ident := identOfString "__x86_l_base_ptr__1"
def ___x86_l_disp : Ident := identOfString "__x86_l_disp"
def ___x86_l_read_mem_width : Ident := identOfString "__x86_l_read_mem_width"
def ___x86_l_value : Ident := identOfString "__x86_l_value"
def ___x86_l_width : Ident := identOfString "__x86_l_width"
def ___x86_loss_i : Ident := identOfString "__x86_loss_i"
def ___x86_loss_i__1 : Ident := identOfString "__x86_loss_i__1"
def ___x86_loss_off : Ident := identOfString "__x86_loss_off"
def ___x86_loss_off__1 : Ident := identOfString "__x86_loss_off__1"
def ___x86_loss_value : Ident := identOfString "__x86_loss_value"
def ___x86_loss_value__1 : Ident := identOfString "__x86_loss_value__1"
def ___x86_loss_width : Ident := identOfString "__x86_loss_width"
def ___x86_loss_width__1 : Ident := identOfString "__x86_loss_width__1"
def ___x86_release_i : Ident := identOfString "__x86_release_i"
def ___x86_release_lane : Ident := identOfString "__x86_release_lane"
def ___x86_release_new : Ident := identOfString "__x86_release_new"
def ___x86_release_off : Ident := identOfString "__x86_release_off"
def ___x86_release_old : Ident := identOfString "__x86_release_old"
def ___x86_sr_ctx : Ident := identOfString "__x86_sr_ctx"
def ___x86_sr_lane : Ident := identOfString "__x86_sr_lane"
def ___x86_sr_off : Ident := identOfString "__x86_sr_off"
def ___x86_sr_value : Ident := identOfString "__x86_sr_value"
def ___x86_sr_width : Ident := identOfString "__x86_sr_width"
def ___x86_st_addr : Ident := identOfString "__x86_st_addr"
def ___x86_st_addr__1 : Ident := identOfString "__x86_st_addr__1"
def ___x86_st_i : Ident := identOfString "__x86_st_i"
def ___x86_st_i__1 : Ident := identOfString "__x86_st_i__1"
def ___x86_st_off : Ident := identOfString "__x86_st_off"
def ___x86_st_off__1 : Ident := identOfString "__x86_st_off__1"
def ___x86_st_tag : Ident := identOfString "__x86_st_tag"
def ___x86_st_tag__1 : Ident := identOfString "__x86_st_tag__1"
def ___x86_st_value : Ident := identOfString "__x86_st_value"
def ___x86_st_value__1 : Ident := identOfString "__x86_st_value__1"
def ___x86_st_width : Ident := identOfString "__x86_st_width"
def ___x86_st_width__1 : Ident := identOfString "__x86_st_width__1"
def ___x86_stack_delta : Ident := identOfString "__x86_stack_delta"
def ___x86_stack_delta__1 : Ident := identOfString "__x86_stack_delta__1"
def ___x86_state : Ident := identOfString "__x86_state"
def ___x86_store_reg : Ident := identOfString "__x86_store_reg"
def ___x86_stw_bytes : Ident := identOfString "__x86_stw_bytes"
def ___x86_stw_bytes__1 : Ident := identOfString "__x86_stw_bytes__1"
def ___x86_stw_bytes__2 : Ident := identOfString "__x86_stw_bytes__2"
def ___x86_stw_bytes__3 : Ident := identOfString "__x86_stw_bytes__3"
def ___x86_stw_index : Ident := identOfString "__x86_stw_index"
def ___x86_stw_index__1 : Ident := identOfString "__x86_stw_index__1"
def ___x86_stw_index__2 : Ident := identOfString "__x86_stw_index__2"
def ___x86_stw_index__3 : Ident := identOfString "__x86_stw_index__3"
def ___x86_stw_narrowed : Ident := identOfString "__x86_stw_narrowed"
def ___x86_stw_narrowed__1 : Ident := identOfString "__x86_stw_narrowed__1"
def ___x86_stw_narrowed__2 : Ident := identOfString "__x86_stw_narrowed__2"
def ___x86_stw_narrowed__3 : Ident := identOfString "__x86_stw_narrowed__3"
def ___x86_stw_width : Ident := identOfString "__x86_stw_width"
def ___x86_stw_width__1 : Ident := identOfString "__x86_stw_width__1"
def ___x86_stw_width__2 : Ident := identOfString "__x86_stw_width__2"
def ___x86_stw_width__3 : Ident := identOfString "__x86_stw_width__3"
def ___x86_sv_i : Ident := identOfString "__x86_sv_i"
def ___x86_sv_i__1 : Ident := identOfString "__x86_sv_i__1"
def ___x86_sv_i__2 : Ident := identOfString "__x86_sv_i__2"
def ___x86_sv_i__3 : Ident := identOfString "__x86_sv_i__3"
def ___x86_sv_i__4 : Ident := identOfString "__x86_sv_i__4"
def ___x86_sv_i__5 : Ident := identOfString "__x86_sv_i__5"
def ___x86_sv_index : Ident := identOfString "__x86_sv_index"
def ___x86_sv_index__1 : Ident := identOfString "__x86_sv_index__1"
def ___x86_sv_index__2 : Ident := identOfString "__x86_sv_index__2"
def ___x86_sv_index__3 : Ident := identOfString "__x86_sv_index__3"
def ___x86_sv_sp : Ident := identOfString "__x86_sv_sp"
def ___x86_sv_start : Ident := identOfString "__x86_sv_start"
def ___x86_sv_start__1 : Ident := identOfString "__x86_sv_start__1"
def ___x86_sv_start__2 : Ident := identOfString "__x86_sv_start__2"
def ___x86_sv_start__3 : Ident := identOfString "__x86_sv_start__3"
def ___x86_sv_width : Ident := identOfString "__x86_sv_width"
def ___x86_sv_width__1 : Ident := identOfString "__x86_sv_width__1"
def ___x86_sv_width__2 : Ident := identOfString "__x86_sv_width__2"
def ___x86_sv_width__3 : Ident := identOfString "__x86_sv_width__3"
def ___x86_tag_reg : Ident := identOfString "__x86_tag_reg"
def ___x86_wr_cell : Ident := identOfString "__x86_wr_cell"
def ___x86_wr_cell_tag : Ident := identOfString "__x86_wr_cell_tag"
def ___x86_wr_next : Ident := identOfString "__x86_wr_next"
def ___x86_wr_next_ptr : Ident := identOfString "__x86_wr_next_ptr"
def ___x86_wr_next_tag : Ident := identOfString "__x86_wr_next_tag"
def ___x86_wr_raw_width : Ident := identOfString "__x86_wr_raw_width"
def ___x86_wr_shift : Ident := identOfString "__x86_wr_shift"
def ___x86_wr_stack_bits : Ident := identOfString "__x86_wr_stack_bits"
def ___x86_wr_stack_bits__1 : Ident := identOfString "__x86_wr_stack_bits__1"
def ___x86_wr_width : Ident := identOfString "__x86_wr_width"
def ___x86_write_old_sp : Ident := identOfString "__x86_write_old_sp"
def ___x86_xdp_ctx : Ident := identOfString "__x86_xdp_ctx"
def ___x86_xdp_off : Ident := identOfString "__x86_xdp_off"
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
def _d : Ident := identOfString "d"
def _data : Ident := identOfString "data"
def _data_end : Ident := identOfString "data_end"
def _data_meta : Ident := identOfString "data_meta"
def _displacement : Ident := identOfString "displacement"
def _dst : Ident := identOfString "dst"
def _egress_ifindex : Ident := identOfString "egress_ifindex"
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
def _ingress_ifindex : Ident := identOfString "ingress_ifindex"
def _is_xdp : Ident := identOfString "is_xdp"
def _kprog_c_context_pointer : Ident := identOfString "kprog_c_context_pointer"
def _kprog_c_pointer_bits : Ident := identOfString "kprog_c_pointer_bits"
def _kprog_c_trap : Ident := identOfString "kprog_c_trap"
def _kprog_x86_arena : Ident := identOfString "kprog_x86_arena"
def _kprog_x86_bswap_value : Ident := identOfString "kprog_x86_bswap_value"
def _kprog_x86_load_xmm0 : Ident := identOfString "kprog_x86_load_xmm0"
def _kprog_x86_mem_load : Ident := identOfString "kprog_x86_mem_load"
def _kprog_x86_mem_load_fixed : Ident := identOfString "kprog_x86_mem_load_fixed"
def _kprog_x86_mem_offset : Ident := identOfString "kprog_x86_mem_offset"
def _kprog_x86_mem_store : Ident := identOfString "kprog_x86_mem_store"
def _kprog_x86_movbe_arm : Ident := identOfString "kprog_x86_movbe_arm"
def _kprog_x86_movbe_load : Ident := identOfString "kprog_x86_movbe_load"
def _kprog_x86_movbe_width : Ident := identOfString "kprog_x86_movbe_width"
def _kprog_x86_read_mem_value : Ident := identOfString "kprog_x86_read_mem_value"
def _kprog_x86_read_recovery_mem : Ident := identOfString "kprog_x86_read_recovery_mem"
def _kprog_x86_stack_fact : Ident := identOfString "kprog_x86_stack_fact"
def _kprog_x86_stack_read : Ident := identOfString "kprog_x86_stack_read"
def _kprog_x86_store_memory : Ident := identOfString "kprog_x86_store_memory"
def _kprog_x86_store_xmm0 : Ident := identOfString "kprog_x86_store_xmm0"
def _kprog_x86_xmm0_arm : Ident := identOfString "kprog_x86_xmm0_arm"
def _len : Ident := identOfString "len"
def _local_ip4 : Ident := identOfString "local_ip4"
def _local_ip6 : Ident := identOfString "local_ip6"
def _local_port : Ident := identOfString "local_port"
def _main : Ident := identOfString "main"
def _mark : Ident := identOfString "mark"
def _napi_id : Ident := identOfString "napi_id"
def _native_lab_entry_input : Ident := identOfString "native_lab_entry_input"
def _native_stack_base : Ident := identOfString "native_stack_base"
def _observed : Ident := identOfString "observed"
def _observed__1 : Ident := identOfString "observed__1"
def _observed__2 : Ident := identOfString "observed__2"
def _observed__3 : Ident := identOfString "observed__3"
def _of : Ident := identOfString "of"
def _pad0 : Ident := identOfString "pad0"
def _pad1 : Ident := identOfString "pad1"
def _pad2 : Ident := identOfString "pad2"
def _pf : Ident := identOfString "pf"
def _pkt_type : Ident := identOfString "pkt_type"
def _pointer : Ident := identOfString "pointer"
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
def _reg : Ident := identOfString "reg"
def _remote_ip4 : Ident := identOfString "remote_ip4"
def _remote_ip6 : Ident := identOfString "remote_ip6"
def _remote_port : Ident := identOfString "remote_port"
def _ret_addr : Ident := identOfString "ret_addr"
def _rsi : Ident := identOfString "rsi"
def _rsi_tag : Ident := identOfString "rsi_tag"
def _rsp : Ident := identOfString "rsp"
def _rsp_tag : Ident := identOfString "rsp_tag"
def _rx_queue_index : Ident := identOfString "rx_queue_index"
def _sf : Ident := identOfString "sf"
def _sk : Ident := identOfString "sk"
def _skb_abi : Ident := identOfString "skb_abi"
def _skb_ctx : Ident := identOfString "skb_ctx"
def _source : Ident := identOfString "source"
def _source_of : Ident := identOfString "source_of"
def _src : Ident := identOfString "src"
def _stack : Ident := identOfString "stack"
def _state : Ident := identOfString "state"
def _store_disp : Ident := identOfString "store_disp"
def _swapped : Ident := identOfString "swapped"
def _tag : Ident := identOfString "tag"
def _tag_of : Ident := identOfString "tag_of"
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
def _x86_apply_width : Ident := identOfString "x86_apply_width"
def _x86_bswap : Ident := identOfString "x86_bswap"
def _x86_sim_clight_load_pointer : Ident := identOfString "x86_sim_clight_load_pointer"
def _x86_sim_gpr : Ident := identOfString "x86_sim_gpr"
def _x86_sim_gpr_cell : Ident := identOfString "x86_sim_gpr_cell"
def _x86_sim_register_state : Ident := identOfString "x86_sim_register_state"
def _x86_sim_skb_abi : Ident := identOfString "x86_sim_skb_abi"
def _x86_sim_xdp_abi : Ident := identOfString "x86_sim_xdp_abi"
def _x86_simm : Ident := identOfString "x86_simm"
def _x86_store_imm_disp : Ident := identOfString "x86_store_imm_disp"
def _x86_width_effective : Ident := identOfString "x86_width_effective"
def _x86_width_mask : Ident := identOfString "x86_width_mask"
def _xdp_abi : Ident := identOfString "xdp_abi"
def _xdp_md : Ident := identOfString "xdp_md"
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
def _t'91 : Ident := (Positive.ofNat 218)
def _t'92 : Ident := (Positive.ofNat 219)
def _t'93 : Ident := (Positive.ofNat 220)
def _t'94 : Ident := (Positive.ofNat 221)
def _t'95 : Ident := (Positive.ofNat 222)
def _t'96 : Ident := (Positive.ofNat 223)
def _t'97 : Ident := (Positive.ofNat 224)
def _t'98 : Ident := (Positive.ofNat 225)
def _t'99 : Ident := (Positive.ofNat 226)

def f_kprog_x86_bswap_value : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_value, tulong), (_width, tuchar)],
  fn_vars := [],
  fn_temps := [(_swapped, tulong)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _width tuchar)
                      (Expr.Econst_int (Integers.Int.repr 1) tuint) tint)
    (Stmt.Sreturn (some (Expr.Ebinop Binop.Oand (Expr.Etempvar _value tulong)
                          (Expr.Econst_long (Integers.Int64.repr 255) tulong)
                          tulong)))
    Stmt.Sskip)
  (Stmt.Ssequence
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _width tuchar)
                        (Expr.Econst_int (Integers.Int.repr 2) tuint) tint)
      (Stmt.Sreturn (some (Expr.Ebinop Binop.Oor
                            (Expr.Ebinop Binop.Oshl
                              (Expr.Ebinop Binop.Oand
                                (Expr.Etempvar _value tulong)
                                (Expr.Econst_long (Integers.Int64.repr 255) tulong)
                                tulong)
                              (Expr.Econst_int (Integers.Int.repr 8) tint)
                              tulong)
                            (Expr.Ebinop Binop.Oshr
                              (Expr.Ebinop Binop.Oand
                                (Expr.Etempvar _value tulong)
                                (Expr.Econst_long (Integers.Int64.repr 65280) tulong)
                                tulong)
                              (Expr.Econst_int (Integers.Int.repr 8) tint)
                              tulong) tulong)))
      Stmt.Sskip)
    (Stmt.Ssequence
      (Stmt.Sset _swapped
        (Expr.Ebinop Binop.Oor
          (Expr.Ebinop Binop.Oor
            (Expr.Ebinop Binop.Oor
              (Expr.Ebinop Binop.Oor
                (Expr.Ebinop Binop.Oor
                  (Expr.Ebinop Binop.Oor
                    (Expr.Ebinop Binop.Oor
                      (Expr.Ebinop Binop.Oshl
                        (Expr.Ebinop Binop.Oand (Expr.Etempvar _value tulong)
                          (Expr.Econst_long (Integers.Int64.repr 255) tulong)
                          tulong)
                        (Expr.Econst_int (Integers.Int.repr 56) tint) tulong)
                      (Expr.Ebinop Binop.Oshl
                        (Expr.Ebinop Binop.Oand (Expr.Etempvar _value tulong)
                          (Expr.Econst_long (Integers.Int64.repr 65280) tulong)
                          tulong)
                        (Expr.Econst_int (Integers.Int.repr 40) tint) tulong)
                      tulong)
                    (Expr.Ebinop Binop.Oshl
                      (Expr.Ebinop Binop.Oand (Expr.Etempvar _value tulong)
                        (Expr.Econst_long (Integers.Int64.repr 16711680) tulong)
                        tulong) (Expr.Econst_int (Integers.Int.repr 24) tint)
                      tulong) tulong)
                  (Expr.Ebinop Binop.Oshl
                    (Expr.Ebinop Binop.Oand (Expr.Etempvar _value tulong)
                      (Expr.Econst_long (Integers.Int64.repr 4278190080) tulong)
                      tulong) (Expr.Econst_int (Integers.Int.repr 8) tint)
                    tulong) tulong)
                (Expr.Ebinop Binop.Oshr
                  (Expr.Ebinop Binop.Oand (Expr.Etempvar _value tulong)
                    (Expr.Econst_long (Integers.Int64.repr 1095216660480) tulong)
                    tulong) (Expr.Econst_int (Integers.Int.repr 8) tint)
                  tulong) tulong)
              (Expr.Ebinop Binop.Oshr
                (Expr.Ebinop Binop.Oand (Expr.Etempvar _value tulong)
                  (Expr.Econst_long (Integers.Int64.repr 280375465082880) tulong)
                  tulong) (Expr.Econst_int (Integers.Int.repr 24) tint)
                tulong) tulong)
            (Expr.Ebinop Binop.Oshr
              (Expr.Ebinop Binop.Oand (Expr.Etempvar _value tulong)
                (Expr.Econst_long (Integers.Int64.repr 71776119061217280) tulong)
                tulong) (Expr.Econst_int (Integers.Int.repr 40) tint) tulong)
            tulong)
          (Expr.Ebinop Binop.Oshr
            (Expr.Ebinop Binop.Oand (Expr.Etempvar _value tulong)
              (Expr.Econst_long (Integers.Int64.repr (-72057594037927936)) tulong)
              tulong) (Expr.Econst_int (Integers.Int.repr 56) tint) tulong)
          tulong))
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar _width tuchar)
                            (Expr.Econst_int (Integers.Int.repr 4) tuint)
                            tint)
          (Stmt.Sreturn (some (Expr.Ebinop Binop.Oshr
                                (Expr.Etempvar _swapped tulong)
                                (Expr.Econst_int (Integers.Int.repr 32) tint)
                                tulong)))
          Stmt.Sskip)
        (Stmt.Sreturn (some (Expr.Etempvar _swapped tulong)))))))
}

def f_x86_width_mask : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_width, tuchar)],
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
  (Stmt.Sreturn (some (Expr.Etempvar _t'1 tulong))))
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

def f_x86_bswap : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_value, tulong), (_width, tuchar)],
  fn_vars := [],
  fn_temps := [(_t'1, tulong)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'1)
    (Expr.Evar _kprog_x86_bswap_value (Ty.Tfunction [tulong, tuchar] tulong
                                        cc_default))
    [(Expr.Etempvar _value tulong), (Expr.Etempvar _width tuchar)])
  (Stmt.Sreturn (some (Expr.Etempvar _t'1 tulong))))
}

def f_x86_simm : Function := {
  fn_return := tlong,
  fn_callconv := cc_default,
  fn_params := [(_value, tulong)],
  fn_vars := [],
  fn_temps := [],
  fn_body :=
(Stmt.Sreturn (some (Expr.Ecast (Expr.Etempvar _value tulong) tlong)))
}

def f_x86_store_imm_disp : Function := {
  fn_return := tint,
  fn_callconv := cc_default,
  fn_params := [(_value, tulong)],
  fn_vars := [],
  fn_temps := [],
  fn_body :=
(Stmt.Sreturn (some (Expr.Ecast
                      (Expr.Ebinop Binop.Oshr (Expr.Etempvar _value tulong)
                        (Expr.Econst_int (Integers.Int.repr 32) tint) tulong)
                      tint)))
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

def f_kprog_x86_mem_load_fixed : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_base, (tptr tvoid)), (_displacement, tlong),
                (_width, tuchar)],
  fn_vars := [],
  fn_temps := [(_t'1, tulong)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'1)
    (Expr.Evar _kprog_x86_mem_load (Ty.Tfunction [(tptr tvoid), tuchar]
                                     tulong cc_default))
    [(Expr.Ebinop Binop.Oadd
       (Expr.Ecast (Expr.Etempvar _base (tptr tvoid)) (tptr tuchar))
       (Expr.Etempvar _displacement tlong) (tptr tuchar)),
     (Expr.Etempvar _width tuchar)])
  (Stmt.Sreturn (some (Expr.Etempvar _t'1 tulong))))
}

def f_kprog_x86_mem_store : Function := {
  fn_return := tvoid,
  fn_callconv := cc_default,
  fn_params := [(_address, (tptr tvoid)), (_width, tuchar), (_value, tulong)],
  fn_vars := [(___kprog_c_store_value, tuchar),
              (___kprog_c_store_value__1, tushort),
              (___kprog_c_store_value__2, tuint),
              (___kprog_c_store_value__3, tulong)],
  fn_temps := [(_t'1, tuint)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Etempvar _width tuchar)
    (Stmt.Sset _t'1 (Expr.Ecast (Expr.Etempvar _width tuchar) tuint))
    (Stmt.Sset _t'1
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint)))
  (Stmt.Sswitch (Expr.Etempvar _t'1 tuint)
    (LStmts.LScons (some 1)
      (Stmt.Ssequence
        (Stmt.Sloop
          (Stmt.Ssequence
            (Stmt.Sassign (Expr.Evar ___kprog_c_store_value tuchar)
              (Expr.Ecast (Expr.Etempvar _value tulong) tuchar))
            (Stmt.Sbuiltin none (ExtFun.EF_memcpy 1 1)
              [(tptr tvoid), (tptr tuchar)]
              [(Expr.Ecast (Expr.Etempvar _address (tptr tvoid))
                 (tptr tvoid)),
               (Expr.Eaddrof (Expr.Evar ___kprog_c_store_value tuchar)
                 (tptr tuchar))]))
          Stmt.Sbreak)
        (Stmt.Sreturn none))
      (LStmts.LScons (some 2)
        (Stmt.Ssequence
          (Stmt.Sloop
            (Stmt.Ssequence
              (Stmt.Sassign (Expr.Evar ___kprog_c_store_value__1 tushort)
                (Expr.Ecast (Expr.Etempvar _value tulong) tushort))
              (Stmt.Sbuiltin none (ExtFun.EF_memcpy 2 1)
                [(tptr tvoid), (tptr tushort)]
                [(Expr.Ecast (Expr.Etempvar _address (tptr tvoid))
                   (tptr tvoid)),
                 (Expr.Eaddrof (Expr.Evar ___kprog_c_store_value__1 tushort)
                   (tptr tushort))]))
            Stmt.Sbreak)
          (Stmt.Sreturn none))
        (LStmts.LScons (some 4)
          (Stmt.Ssequence
            (Stmt.Sloop
              (Stmt.Ssequence
                (Stmt.Sassign (Expr.Evar ___kprog_c_store_value__2 tuint)
                  (Expr.Ecast (Expr.Etempvar _value tulong) tuint))
                (Stmt.Sbuiltin none (ExtFun.EF_memcpy 4 1)
                  [(tptr tvoid), (tptr tuint)]
                  [(Expr.Ecast (Expr.Etempvar _address (tptr tvoid))
                     (tptr tvoid)),
                   (Expr.Eaddrof (Expr.Evar ___kprog_c_store_value__2 tuint)
                     (tptr tuint))]))
              Stmt.Sbreak)
            (Stmt.Sreturn none))
          (LStmts.LScons (some 8)
            (Stmt.Ssequence
              (Stmt.Sloop
                (Stmt.Ssequence
                  (Stmt.Sassign (Expr.Evar ___kprog_c_store_value__3 tulong)
                    (Expr.Ecast (Expr.Etempvar _value tulong) tulong))
                  (Stmt.Sbuiltin none (ExtFun.EF_memcpy 8 1)
                    [(tptr tvoid), (tptr tulong)]
                    [(Expr.Ecast (Expr.Etempvar _address (tptr tvoid))
                       (tptr tvoid)),
                     (Expr.Eaddrof
                       (Expr.Evar ___kprog_c_store_value__3 tulong)
                       (tptr tulong))]))
                Stmt.Sbreak)
              (Stmt.Sreturn none))
            (LStmts.LScons none
              (Stmt.Scall none
                (Expr.Evar _kprog_c_trap (Ty.Tfunction [] tvoid cc_default))
                [])
              LStmts.LSnil)))))))
}

def f_x86_sim_clight_load_pointer : Function := {
  fn_return := (tptr tvoid),
  fn_callconv := cc_default,
  fn_params := [(_address, (tptr tvoid))],
  fn_vars := [(_observed, (tvolatile (tptr tvoid)))],
  fn_temps := [(_t'1, (tvolatile (tptr tvoid)))],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sbuiltin none (ExtFun.EF_memcpy 8 1) [(tptr tvoid), (tptr tvoid)]
    [(Expr.Ecast
       (Expr.Eaddrof (Expr.Evar _observed (tvolatile (tptr tvoid)))
         (tptr (tvolatile (tptr tvoid)))) (tptr tvoid)),
     (Expr.Etempvar _address (tptr tvoid))])
  (Stmt.Ssequence
    (Stmt.Sbuiltin (some _t'1) (ExtFun.EF_vload Chunk.Mint64)
      [(tptr (tvolatile (tptr tvoid)))]
      [(Expr.Eaddrof (Expr.Evar _observed (tvolatile (tptr tvoid)))
         (tptr (tvolatile (tptr tvoid))))])
    (Stmt.Sreturn (some (Expr.Etempvar _t'1 (tvolatile (tptr tvoid)))))))
}

def f_tag_of : Function := {
  fn_return := tuchar,
  fn_callconv := cc_default,
  fn_params := [(_state, (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
                (_reg, tulong)],
  fn_vars := [],
  fn_temps := [(___x86_state,
                (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
               (_tag, tuchar), (___x86_tag_reg, tulong), (_t'1, tuint),
               (_t'2, tuchar)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_state
    (Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))))
  (Stmt.Ssequence
    (Stmt.Sloop
      (Stmt.Ssequence
        (Stmt.Sset ___x86_tag_reg (Expr.Etempvar _reg tulong))
        (Stmt.Ssequence
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                              (Expr.Etempvar ___x86_tag_reg tulong)
                              (Expr.Econst_int (Integers.Int.repr 16) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Sset _t'2
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                            (Ty.Tstruct _x86_sim_register_state noattr))
                          (Positive.ofNat 18727075383868559167)
                          (Ty.Tunion __3119 noattr)) _gpr_cells
                        (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                      (Expr.Ecast (Expr.Etempvar ___x86_tag_reg tulong)
                        tuchar) (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                    (Ty.Tstruct _x86_sim_gpr_cell noattr)) _tag tuchar))
              (Stmt.Sset _t'1 (Expr.Ecast (Expr.Etempvar _t'2 tuchar) tuint)))
            (Stmt.Sset _t'1
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                tuint)))
          (Stmt.Sset _tag (Expr.Ecast (Expr.Etempvar _t'1 tuint) tuchar))))
      Stmt.Sbreak)
    (Stmt.Sreturn (some (Expr.Etempvar _tag tuchar)))))
}

def f_source_of : Function := {
  fn_return := tuchar,
  fn_callconv := cc_default,
  fn_params := [(_state, (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
                (_base, tulong), (_width, tulong)],
  fn_vars := [],
  fn_temps := [(_source, tuchar), (___kprog_x86_md_src, tuchar),
               (_t'2, tint), (_t'1, tuchar)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _base tulong)
                          (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
        (Stmt.Sset ___kprog_x86_md_src
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuchar))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Scall (some _t'1)
              (Expr.Evar _tag_of (Ty.Tfunction
                                   [(tptr (Ty.Tstruct _x86_sim_register_state noattr)),
                                    tulong] tuchar cc_default))
              [(Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
               (Expr.Etempvar _base tulong)])
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Etempvar _t'1 tuchar)
                                (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                tint)
              (Stmt.Sset _t'2
                (Expr.Ecast
                  (Expr.Ebinop Binop.Oeq (Expr.Etempvar _width tulong)
                    (Expr.Econst_int (Integers.Int.repr 8) tuint) tint)
                  tbool))
              (Stmt.Sset _t'2 (Expr.Econst_int (Integers.Int.repr 0) tint))))
          (Stmt.Sifthenelse (Expr.Etempvar _t'2 tint)
            (Stmt.Sset ___kprog_x86_md_src
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint)
                tuchar))
            (Stmt.Sset ___kprog_x86_md_src
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint)
                tuchar)))))
      (Stmt.Sset _source
        (Expr.Ecast (Expr.Etempvar ___kprog_x86_md_src tuchar) tuchar)))
    Stmt.Sbreak)
  (Stmt.Sreturn (some (Expr.Etempvar _source tuchar))))
}

def f_kprog_x86_movbe_width : Function := {
  fn_return := tuchar,
  fn_callconv := cc_default,
  fn_params := [(_flags, tulong)],
  fn_vars := [],
  fn_temps := [(_width, tuchar), (___kprog_x86_mb_width, tuchar),
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
        (Stmt.Sset ___kprog_x86_mb_width
          (Expr.Ecast (Expr.Etempvar _t'1 tulong) tuchar)))
      (Stmt.Sset _width
        (Expr.Ecast (Expr.Etempvar ___kprog_x86_mb_width tuchar) tuchar)))
    Stmt.Sbreak)
  (Stmt.Sreturn (some (Expr.Etempvar _width tuchar))))
}

def f_kprog_x86_movbe_arm : Function := {
  fn_return := tuchar,
  fn_callconv := cc_default,
  fn_params := [(_stack, tulong)],
  fn_vars := [],
  fn_temps := [(_arm, tuchar), (___kprog_x86_mb_arm, tuchar)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sifthenelse (Expr.Etempvar _stack tulong)
        (Stmt.Sset ___kprog_x86_mb_arm
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuchar))
        (Stmt.Sset ___kprog_x86_mb_arm
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuchar)))
      (Stmt.Sset _arm
        (Expr.Ecast (Expr.Etempvar ___kprog_x86_mb_arm tuchar) tuchar)))
    Stmt.Sbreak)
  (Stmt.Sreturn (some (Expr.Etempvar _arm tuchar))))
}

def s_kprog_x86_read_mem_value_0 : Stmt :=
(Stmt.Scall (some _t'61)
  (Expr.Evar _tag_of (Ty.Tfunction
                       [(tptr (Ty.Tstruct _x86_sim_register_state noattr)),
                        tulong] tuchar cc_default))
  [(Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
   (Expr.Etempvar _base tulong)])

def s_kprog_x86_read_mem_value_1 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'71
    (Expr.Efield
      (Expr.Ederef
        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
        (Ty.Tstruct _x86_sim_register_state noattr)) _helper_abi_base
      (tptr tvoid)))
  (Stmt.Sset ___x86_xdp_off
    (Expr.Ecast
      (Expr.Ebinop Binop.Oadd
        (Expr.Ebinop Binop.Osub
          (Expr.Ecast
            (Expr.Ecast (Expr.Etempvar ___x86_l_base_ptr (tptr tvoid)) tlong)
            tulong)
          (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'71 (tptr tvoid)) tlong)
            tulong) tulong)
        (Expr.Ecast (Expr.Etempvar ___x86_l_disp tlong) tulong) tulong)
      tlong)))

def s_kprog_x86_read_mem_value_2 : Stmt :=
(Stmt.Sset ___x86_xdp_ctx
  (Expr.Efield
    (Expr.Ederef
      (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
      (Ty.Tstruct _x86_sim_register_state noattr)) _helper_ctx (tptr tvoid)))

def s_kprog_x86_read_mem_value_3 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_captured_xdp_value
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) tulong))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                          (Expr.Etempvar ___x86_l_read_mem_width tuchar)
                          (Expr.Econst_int (Integers.Int.repr 8) tuint) tint)
        (Stmt.Sset _t'17
          (Expr.Ecast
            (Expr.Ebinop Binop.Oeq (Expr.Etempvar ___x86_xdp_off tlong)
              (Expr.Econst_long (Integers.Int64.repr 0) tlong) tint) tbool))
        (Stmt.Sset _t'17 (Expr.Econst_int (Integers.Int.repr 0) tint)))
      (Stmt.Sifthenelse (Expr.Etempvar _t'17 tint)
        (Stmt.Ssequence
          (Stmt.Scall (some _t'11)
            (Expr.Evar _kprog_c_context_pointer (Ty.Tfunction
                                                  [(tptr tvoid), tuchar,
                                                   tuint] (tptr tvoid)
                                                  cc_default))
            [(Expr.Etempvar ___x86_xdp_ctx (tptr (tvolatile (Ty.Tstruct _xdp_md noattr)))),
             (Expr.Econst_int (Integers.Int.repr 0) tuint),
             (Expr.Econst_long (Integers.Int64.repr 0) tulong)])
          (Stmt.Sset ___x86_captured_xdp_value
            (Expr.Ecast
              (Expr.Ecast (Expr.Etempvar _t'11 (tptr tvoid)) tulong) tulong)))
        (Stmt.Ssequence
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar ___x86_l_read_mem_width tuchar)
                              (Expr.Econst_int (Integers.Int.repr 8) tuint)
                              tint)
            (Stmt.Sset _t'16
              (Expr.Ecast
                (Expr.Ebinop Binop.Oeq (Expr.Etempvar ___x86_xdp_off tlong)
                  (Expr.Econst_long (Integers.Int64.repr 8) tlong) tint)
                tbool))
            (Stmt.Sset _t'16 (Expr.Econst_int (Integers.Int.repr 0) tint)))
          (Stmt.Sifthenelse (Expr.Etempvar _t'16 tint)
            (Stmt.Ssequence
              (Stmt.Scall (some _t'12)
                (Expr.Evar _kprog_c_context_pointer (Ty.Tfunction
                                                      [(tptr tvoid), tuchar,
                                                       tuint] (tptr tvoid)
                                                      cc_default))
                [(Expr.Etempvar ___x86_xdp_ctx (tptr (tvolatile (Ty.Tstruct _xdp_md noattr)))),
                 (Expr.Econst_int (Integers.Int.repr 0) tuint),
                 (Expr.Econst_long (Integers.Int64.repr 4) tulong)])
              (Stmt.Sset ___x86_captured_xdp_value
                (Expr.Ecast
                  (Expr.Ecast (Expr.Etempvar _t'12 (tptr tvoid)) tulong)
                  tulong)))
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar ___x86_l_read_mem_width tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                  tint)
                (Stmt.Sset _t'15
                  (Expr.Ecast
                    (Expr.Ebinop Binop.Oeq
                      (Expr.Etempvar ___x86_xdp_off tlong)
                      (Expr.Econst_int (Integers.Int.repr 16) tint) tint)
                    tbool))
                (Stmt.Sset _t'15
                  (Expr.Econst_int (Integers.Int.repr 0) tint)))
              (Stmt.Sifthenelse (Expr.Etempvar _t'15 tint)
                (Stmt.Ssequence
                  (Stmt.Scall (some _t'13)
                    (Expr.Evar _kprog_c_context_pointer (Ty.Tfunction
                                                          [(tptr tvoid),
                                                           tuchar, tuint]
                                                          (tptr tvoid)
                                                          cc_default))
                    [(Expr.Etempvar ___x86_xdp_ctx (tptr (tvolatile (Ty.Tstruct _xdp_md noattr)))),
                     (Expr.Econst_int (Integers.Int.repr 0) tuint),
                     (Expr.Econst_long (Integers.Int64.repr 8) tulong)])
                  (Stmt.Sset ___x86_captured_xdp_value
                    (Expr.Ecast
                      (Expr.Ecast (Expr.Etempvar _t'13 (tptr tvoid)) tulong)
                      tulong)))
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Scall (some _t'14)
                      (Expr.Evar _kprog_x86_mem_load (Ty.Tfunction
                                                       [(tptr tvoid), tuchar]
                                                       tulong cc_default))
                      [(Expr.Ecast
                         (Expr.Ecast
                           (Expr.Ebinop Binop.Oadd
                             (Expr.Ecast
                               (Expr.Ecast
                                 (Expr.Etempvar ___x86_l_base_ptr (tptr tvoid))
                                 tulong) tulong)
                             (Expr.Ecast (Expr.Etempvar ___x86_l_disp tlong)
                               tulong) tulong) tulong) (tptr tuchar)),
                       (Expr.Etempvar ___x86_l_read_mem_width tuchar)])
                    (Stmt.Sset ___x86_captured_xdp_value
                      (Expr.Etempvar _t'14 tulong)))
                  Stmt.Sbreak)))))))
    (Stmt.Sset ___x86_l_value
      (Expr.Etempvar ___x86_captured_xdp_value tulong))))

def s_kprog_x86_read_mem_value_4 : Stmt :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'59)
    (Expr.Evar _tag_of (Ty.Tfunction
                         [(tptr (Ty.Tstruct _x86_sim_register_state noattr)),
                          tulong] tuchar cc_default))
    [(Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
     (Expr.Etempvar _base tulong)])
  (Stmt.Sset _t'58
    (Expr.Ecast
      (Expr.Ebinop Binop.Oeq (Expr.Etempvar _t'59 tuchar)
        (Expr.Econst_int (Integers.Int.repr 1) tuint) tint) tbool)))

def s_kprog_x86_read_mem_value_5 : Stmt :=
(Stmt.Sbuiltin (some _t'26) (ExtFun.EF_vload Chunk.Mint8unsigned)
  [(tptr (tvolatile tuchar))]
  [(Expr.Eaddrof
     (Expr.Ederef
       (Expr.Ebinop Binop.Oadd
         (Expr.Etempvar ___x86_cbr_addr (tptr (tvolatile tuchar)))
         (Expr.Econst_int (Integers.Int.repr 3) tint)
         (tptr (tvolatile tuchar))) (tvolatile tuchar))
     (tptr (tvolatile tuchar)))])

def s_kprog_x86_read_mem_value_6 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sbuiltin (some _t'27) (ExtFun.EF_vload Chunk.Mint8unsigned)
    [(tptr (tvolatile tuchar))]
    [(Expr.Eaddrof
       (Expr.Ederef
         (Expr.Ebinop Binop.Oadd
           (Expr.Etempvar ___x86_cbr_addr (tptr (tvolatile tuchar)))
           (Expr.Econst_int (Integers.Int.repr 4) tint)
           (tptr (tvolatile tuchar))) (tvolatile tuchar))
       (tptr (tvolatile tuchar)))])
  (Stmt.Sset ___x86_cbr_value
    (Expr.Ebinop Binop.Oor (Expr.Etempvar ___x86_cbr_value tulong)
      (Expr.Ebinop Binop.Oshl
        (Expr.Ecast (Expr.Etempvar _t'27 (tvolatile tuchar)) tulong)
        (Expr.Econst_int (Integers.Int.repr 32) tint) tulong) tulong)))

def s_kprog_x86_read_mem_value_7 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sbuiltin (some _t'28) (ExtFun.EF_vload Chunk.Mint8unsigned)
    [(tptr (tvolatile tuchar))]
    [(Expr.Eaddrof
       (Expr.Ederef
         (Expr.Ebinop Binop.Oadd
           (Expr.Etempvar ___x86_cbr_addr (tptr (tvolatile tuchar)))
           (Expr.Econst_int (Integers.Int.repr 5) tint)
           (tptr (tvolatile tuchar))) (tvolatile tuchar))
       (tptr (tvolatile tuchar)))])
  (Stmt.Sset ___x86_cbr_value
    (Expr.Ebinop Binop.Oor (Expr.Etempvar ___x86_cbr_value tulong)
      (Expr.Ebinop Binop.Oshl
        (Expr.Ecast (Expr.Etempvar _t'28 (tvolatile tuchar)) tulong)
        (Expr.Econst_int (Integers.Int.repr 40) tint) tulong) tulong)))

def s_kprog_x86_read_mem_value_8 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                    (Expr.Etempvar ___x86_l_read_mem_width tuchar)
                    (Expr.Econst_int (Integers.Int.repr 8) tuint) tint)
  (Stmt.Ssequence
    (Stmt.Sbuiltin (some _t'29) (ExtFun.EF_vload Chunk.Mint8unsigned)
      [(tptr (tvolatile tuchar))]
      [(Expr.Eaddrof
         (Expr.Ederef
           (Expr.Ebinop Binop.Oadd
             (Expr.Etempvar ___x86_cbr_addr (tptr (tvolatile tuchar)))
             (Expr.Econst_int (Integers.Int.repr 6) tint)
             (tptr (tvolatile tuchar))) (tvolatile tuchar))
         (tptr (tvolatile tuchar)))])
    (Stmt.Sset ___x86_cbr_value
      (Expr.Ebinop Binop.Oor (Expr.Etempvar ___x86_cbr_value tulong)
        (Expr.Ebinop Binop.Oshl
          (Expr.Ecast (Expr.Etempvar _t'29 (tvolatile tuchar)) tulong)
          (Expr.Econst_int (Integers.Int.repr 48) tint) tulong) tulong)))
  Stmt.Sskip)

def s_kprog_x86_read_mem_value_9 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                      (Expr.Etempvar ___x86_l_read_mem_width tuchar)
                      (Expr.Econst_int (Integers.Int.repr 8) tuint) tint)
    (Stmt.Ssequence
      (Stmt.Sbuiltin (some _t'30) (ExtFun.EF_vload Chunk.Mint8unsigned)
        [(tptr (tvolatile tuchar))]
        [(Expr.Eaddrof
           (Expr.Ederef
             (Expr.Ebinop Binop.Oadd
               (Expr.Etempvar ___x86_cbr_addr (tptr (tvolatile tuchar)))
               (Expr.Econst_int (Integers.Int.repr 7) tint)
               (tptr (tvolatile tuchar))) (tvolatile tuchar))
           (tptr (tvolatile tuchar)))])
      (Stmt.Sset ___x86_cbr_value
        (Expr.Ebinop Binop.Oor (Expr.Etempvar ___x86_cbr_value tulong)
          (Expr.Ebinop Binop.Oshl
            (Expr.Ecast (Expr.Etempvar _t'30 (tvolatile tuchar)) tulong)
            (Expr.Econst_int (Integers.Int.repr 56) tint) tulong) tulong)))
    Stmt.Sskip)
  (Stmt.Sset ___x86_sr_value (Expr.Etempvar ___x86_cbr_value tulong)))

def s_kprog_x86_read_mem_value_10 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                    (Expr.Ecast (Expr.Etempvar _base tulong) tulong)
                    (Expr.Econst_int (Integers.Int.repr 16) tuint) tint)
  (Stmt.Ssequence
    (Stmt.Sset _t'64
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
                  (Ty.Tunion __3119 noattr)) _gpr_cells
                (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
              (Expr.Ecast (Expr.Etempvar _base tulong) tuchar)
              (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
            (Ty.Tstruct _x86_sim_gpr_cell noattr)) _value
          (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
    (Stmt.Sset _t'34
      (Expr.Ecast (Expr.Etempvar _t'64 (tptr tvoid)) (tptr tvoid))))
  (Stmt.Sset _t'34
    (Expr.Ecast
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid))
      (tptr tvoid))))

def s_kprog_x86_read_mem_value_11 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_sr_width
    (Expr.Ecast (Expr.Etempvar ___x86_l_read_mem_width tuchar) tuchar))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                          (Expr.Ecast (Expr.Etempvar _base tulong) tulong)
                          (Expr.Econst_int (Integers.Int.repr 16) tuint)
                          tint)
        (Stmt.Ssequence
          (Stmt.Sset _t'69
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
                        (Ty.Tunion __3119 noattr)) _gpr_cells
                      (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                    (Expr.Ecast (Expr.Etempvar _base tulong) tuchar)
                    (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                  (Ty.Tstruct _x86_sim_gpr_cell noattr)) _value
                (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
          (Stmt.Sset _t'18
            (Expr.Ecast (Expr.Etempvar _t'69 (tptr tvoid)) (tptr tvoid))))
        (Stmt.Sset _t'18
          (Expr.Ecast
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
              (tptr tvoid)) (tptr tvoid))))
      (Stmt.Ssequence
        (Stmt.Sset _t'68
          (Expr.Efield
            (Expr.Ederef
              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
              (Ty.Tstruct _x86_sim_register_state noattr)) _helper_abi_base
            (tptr tvoid)))
        (Stmt.Sset ___x86_sr_off
          (Expr.Ecast
            (Expr.Ebinop Binop.Oadd
              (Expr.Ebinop Binop.Osub
                (Expr.Ecast
                  (Expr.Ecast (Expr.Etempvar _t'18 (tptr tvoid)) tlong)
                  tulong)
                (Expr.Ecast
                  (Expr.Ecast (Expr.Etempvar _t'68 (tptr tvoid)) tlong)
                  tulong) tulong)
              (Expr.Ecast (Expr.Etempvar ___x86_l_disp tlong) tulong) tulong)
            tlong))))
    (Stmt.Ssequence
      (Stmt.Sset ___x86_sr_ctx
        (Expr.Efield
          (Expr.Ederef
            (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
            (Ty.Tstruct _x86_sim_register_state noattr)) _helper_ctx
          (tptr tvoid)))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                (Expr.Etempvar ___x86_sr_off tlong)
                                (Expr.Econst_long (Integers.Int64.repr 208) tlong)
                                tint)
              (Stmt.Sset _t'40
                (Expr.Ecast
                  (Expr.Ebinop Binop.Ole (Expr.Etempvar ___x86_sr_off tlong)
                    (Expr.Ebinop Binop.Osub
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Econst_long (Integers.Int64.repr 208) tlong)
                        (Expr.Econst_int (Integers.Int.repr 8) tint) tlong)
                      (Expr.Etempvar ___x86_l_read_mem_width tuchar) tlong)
                    tint) tbool))
              (Stmt.Sset _t'40 (Expr.Econst_int (Integers.Int.repr 0) tint)))
            (Stmt.Sifthenelse (Expr.Etempvar _t'40 tint)
              (Stmt.Sset _t'41 (Expr.Econst_int (Integers.Int.repr 1) tint))
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                  (Expr.Etempvar ___x86_sr_off tlong)
                                  (Expr.Econst_long (Integers.Int64.repr 80) tlong)
                                  tint)
                (Stmt.Ssequence
                  (Stmt.Sset _t'41
                    (Expr.Ecast
                      (Expr.Ebinop Binop.Ole
                        (Expr.Etempvar ___x86_sr_off tlong)
                        (Expr.Ebinop Binop.Osub
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Econst_long (Integers.Int64.repr 80) tlong)
                            (Expr.Econst_int (Integers.Int.repr 8) tint)
                            tlong)
                          (Expr.Etempvar ___x86_l_read_mem_width tuchar)
                          tlong) tint) tbool))
                  (Stmt.Sset _t'41
                    (Expr.Ecast (Expr.Etempvar _t'41 tint) tbool)))
                (Stmt.Sset _t'41
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                    tbool)))))
          (Stmt.Sifthenelse (Expr.Etempvar _t'41 tint)
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                  (Expr.Etempvar ___x86_sr_off tlong)
                                  (Expr.Econst_long (Integers.Int64.repr 208) tlong)
                                  tint)
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Scall (some _t'19)
                      (Expr.Evar _kprog_c_context_pointer (Ty.Tfunction
                                                            [(tptr tvoid),
                                                             tuchar, tuint]
                                                            (tptr tvoid)
                                                            cc_default))
                      [(Expr.Etempvar ___x86_sr_ctx (tptr (Ty.Tstruct ___sk_buff noattr))),
                       (Expr.Econst_int (Integers.Int.repr 1) tuint),
                       (Expr.Econst_long (Integers.Int64.repr 76) tulong)])
                    (Stmt.Sset ___x86_sr_value
                      (Expr.Ecast
                        (Expr.Ecast (Expr.Etempvar _t'19 (tptr tvoid))
                          tulong) tulong)))
                  (Stmt.Sset ___x86_sr_lane
                    (Expr.Ebinop Binop.Osub
                      (Expr.Etempvar ___x86_sr_off tlong)
                      (Expr.Econst_long (Integers.Int64.repr 208) tlong)
                      tlong)))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Scall (some _t'20)
                      (Expr.Evar _kprog_c_context_pointer (Ty.Tfunction
                                                            [(tptr tvoid),
                                                             tuchar, tuint]
                                                            (tptr tvoid)
                                                            cc_default))
                      [(Expr.Etempvar ___x86_sr_ctx (tptr (Ty.Tstruct ___sk_buff noattr))),
                       (Expr.Econst_int (Integers.Int.repr 1) tuint),
                       (Expr.Econst_long (Integers.Int64.repr 80) tulong)])
                    (Stmt.Sset ___x86_sr_value
                      (Expr.Ecast
                        (Expr.Ecast (Expr.Etempvar _t'20 (tptr tvoid))
                          tulong) tulong)))
                  (Stmt.Sset ___x86_sr_lane
                    (Expr.Ebinop Binop.Osub
                      (Expr.Etempvar ___x86_sr_off tlong)
                      (Expr.Econst_long (Integers.Int64.repr 80) tlong)
                      tlong))))
              (Stmt.Sifthenelse (Expr.Ebinop Binop.One
                                  (Expr.Etempvar ___x86_l_read_mem_width tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                  tint)
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Scall (some _t'21)
                      (Expr.Evar _kprog_c_pointer_bits (Ty.Tfunction
                                                         [(tptr tvoid)]
                                                         tulong cc_default))
                      [(Expr.Ecast
                         (Expr.Ecast (Expr.Etempvar ___x86_sr_value tulong)
                           tulong) (tptr tvoid))])
                    (Stmt.Scall (some _t'22)
                      (Expr.Evar _x86_apply_width (Ty.Tfunction
                                                    [tulong, tuchar] tulong
                                                    cc_default))
                      [(Expr.Ebinop Binop.Oshr (Expr.Etempvar _t'21 tulong)
                         (Expr.Ebinop Binop.Omul
                           (Expr.Etempvar ___x86_sr_lane tlong)
                           (Expr.Econst_int (Integers.Int.repr 8) tint)
                           tlong) tulong),
                       (Expr.Etempvar ___x86_l_read_mem_width tuchar)]))
                  (Stmt.Sset ___x86_sr_value (Expr.Etempvar _t'22 tulong)))
                Stmt.Sskip))
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                  (Expr.Etempvar ___x86_sr_off tlong)
                                  (Expr.Econst_long (Integers.Int64.repr 48) tlong)
                                  tint)
                (Stmt.Sset _t'39
                  (Expr.Ecast
                    (Expr.Ebinop Binop.Ole
                      (Expr.Etempvar ___x86_sr_off tlong)
                      (Expr.Ebinop Binop.Osub
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Econst_long (Integers.Int64.repr 48) tlong)
                          (Expr.Econst_int (Integers.Int.repr 20) tint)
                          tlong)
                        (Expr.Etempvar ___x86_l_read_mem_width tuchar) tlong)
                      tint) tbool))
                (Stmt.Sset _t'39
                  (Expr.Econst_int (Integers.Int.repr 0) tint)))
              (Stmt.Sifthenelse (Expr.Etempvar _t'39 tint)
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Sset ___x86_cbr_addr
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Ecast
                          (Expr.Etempvar ___x86_sr_ctx (tptr (Ty.Tstruct ___sk_buff noattr)))
                          (tptr (tvolatile tuchar)))
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Ebinop Binop.Osub
                            (Expr.Etempvar ___x86_sr_off tlong)
                            (Expr.Econst_long (Integers.Int64.repr 48) tlong)
                            tlong)
                          (Expr.Ecast
                            (Expr.Econst_long (Integers.Int64.repr 48) tulong)
                            tlong) tlong) (tptr (tvolatile tuchar))))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sbuiltin (some _t'23)
                          (ExtFun.EF_vload Chunk.Mint8unsigned)
                          [(tptr (tvolatile tuchar))]
                          [(Expr.Eaddrof
                             (Expr.Ederef
                               (Expr.Ebinop Binop.Oadd
                                 (Expr.Etempvar ___x86_cbr_addr (tptr (tvolatile tuchar)))
                                 (Expr.Econst_int (Integers.Int.repr 0) tint)
                                 (tptr (tvolatile tuchar)))
                               (tvolatile tuchar)) (tptr (tvolatile tuchar)))])
                        (Stmt.Sset ___x86_cbr_value
                          (Expr.Ecast
                            (Expr.Etempvar _t'23 (tvolatile tuchar)) tulong)))
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                            (Expr.Etempvar ___x86_l_read_mem_width tuchar)
                                            (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                            tint)
                          (Stmt.Ssequence
                            (Stmt.Sbuiltin (some _t'24)
                              (ExtFun.EF_vload Chunk.Mint8unsigned)
                              [(tptr (tvolatile tuchar))]
                              [(Expr.Eaddrof
                                 (Expr.Ederef
                                   (Expr.Ebinop Binop.Oadd
                                     (Expr.Etempvar ___x86_cbr_addr (tptr (tvolatile tuchar)))
                                     (Expr.Econst_int (Integers.Int.repr 1) tint)
                                     (tptr (tvolatile tuchar)))
                                   (tvolatile tuchar))
                                 (tptr (tvolatile tuchar)))])
                            (Stmt.Sset ___x86_cbr_value
                              (Expr.Ebinop Binop.Oor
                                (Expr.Etempvar ___x86_cbr_value tulong)
                                (Expr.Ebinop Binop.Oshl
                                  (Expr.Ecast
                                    (Expr.Etempvar _t'24 (tvolatile tuchar))
                                    tulong)
                                  (Expr.Econst_int (Integers.Int.repr 8) tint)
                                  tulong) tulong)))
                          Stmt.Sskip)
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                              (Expr.Etempvar ___x86_l_read_mem_width tuchar)
                                              (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                              tint)
                            (Stmt.Ssequence
                              (Stmt.Sbuiltin (some _t'25)
                                (ExtFun.EF_vload Chunk.Mint8unsigned)
                                [(tptr (tvolatile tuchar))]
                                [(Expr.Eaddrof
                                   (Expr.Ederef
                                     (Expr.Ebinop Binop.Oadd
                                       (Expr.Etempvar ___x86_cbr_addr (tptr (tvolatile tuchar)))
                                       (Expr.Econst_int (Integers.Int.repr 2) tint)
                                       (tptr (tvolatile tuchar)))
                                     (tvolatile tuchar))
                                   (tptr (tvolatile tuchar)))])
                              (Stmt.Sset ___x86_cbr_value
                                (Expr.Ebinop Binop.Oor
                                  (Expr.Etempvar ___x86_cbr_value tulong)
                                  (Expr.Ebinop Binop.Oshl
                                    (Expr.Ecast
                                      (Expr.Etempvar _t'25 (tvolatile tuchar))
                                      tulong)
                                    (Expr.Econst_int (Integers.Int.repr 16) tint)
                                    tulong) tulong)))
                            Stmt.Sskip)
                          (Stmt.Ssequence
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                                (Expr.Etempvar ___x86_l_read_mem_width tuchar)
                                                (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                                tint)
                              (Stmt.Ssequence
                                s_kprog_x86_read_mem_value_5
                                (Stmt.Sset ___x86_cbr_value
                                  (Expr.Ebinop Binop.Oor
                                    (Expr.Etempvar ___x86_cbr_value tulong)
                                    (Expr.Ebinop Binop.Oshl
                                      (Expr.Ecast
                                        (Expr.Etempvar _t'26 (tvolatile tuchar))
                                        tulong)
                                      (Expr.Econst_int (Integers.Int.repr 24) tint)
                                      tulong) tulong)))
                              Stmt.Sskip)
                            (Stmt.Ssequence
                              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                                  (Expr.Etempvar ___x86_l_read_mem_width tuchar)
                                                  (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                                  tint)
                                s_kprog_x86_read_mem_value_6
                                Stmt.Sskip)
                              (Stmt.Ssequence
                                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                                    (Expr.Etempvar ___x86_l_read_mem_width tuchar)
                                                    (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                                    tint)
                                  s_kprog_x86_read_mem_value_7
                                  Stmt.Sskip)
                                (Stmt.Ssequence
                                  s_kprog_x86_read_mem_value_8
                                  s_kprog_x86_read_mem_value_9))))))))
                  Stmt.Sbreak)
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                      (Expr.Etempvar ___x86_sr_off tlong)
                                      (Expr.Econst_int (Integers.Int.repr 134) tint)
                                      tint)
                    (Stmt.Sset _t'38
                      (Expr.Ecast
                        (Expr.Ebinop Binop.Ole
                          (Expr.Etempvar ___x86_sr_off tlong)
                          (Expr.Ebinop Binop.Osub
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Econst_int (Integers.Int.repr 134) tint)
                              (Expr.Econst_int (Integers.Int.repr 2) tint)
                              tint) (Expr.Etempvar ___x86_sr_width tuchar)
                            tint) tint) tbool))
                    (Stmt.Sset _t'38
                      (Expr.Econst_int (Integers.Int.repr 0) tint)))
                  (Stmt.Sifthenelse (Expr.Etempvar _t'38 tint)
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sset _t'67
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar ___x86_sr_ctx (tptr (Ty.Tstruct ___sk_buff noattr)))
                              (Ty.Tstruct ___sk_buff noattr)) _tc_index
                            tuint))
                        (Stmt.Scall (some _t'31)
                          (Expr.Evar _x86_apply_width (Ty.Tfunction
                                                        [tulong, tuchar]
                                                        tulong cc_default))
                          [(Expr.Ebinop Binop.Oshr
                             (Expr.Ecast (Expr.Etempvar _t'67 tuint) tulong)
                             (Expr.Ebinop Binop.Omul
                               (Expr.Ebinop Binop.Osub
                                 (Expr.Etempvar ___x86_sr_off tlong)
                                 (Expr.Econst_int (Integers.Int.repr 134) tint)
                                 tlong)
                               (Expr.Econst_int (Integers.Int.repr 8) tint)
                               tlong) tulong),
                           (Expr.Etempvar ___x86_sr_width tuchar)]))
                      (Stmt.Sset ___x86_sr_value
                        (Expr.Etempvar _t'31 tulong)))
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                          (Expr.Etempvar ___x86_sr_off tlong)
                                          (Expr.Econst_int (Integers.Int.repr 144) tint)
                                          tint)
                        (Stmt.Sset _t'37
                          (Expr.Ecast
                            (Expr.Ebinop Binop.Ole
                              (Expr.Etempvar ___x86_sr_off tlong)
                              (Expr.Ebinop Binop.Osub
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Econst_int (Integers.Int.repr 144) tint)
                                  (Expr.Econst_int (Integers.Int.repr 4) tint)
                                  tint)
                                (Expr.Etempvar ___x86_sr_width tuchar) tint)
                              tint) tbool))
                        (Stmt.Sset _t'37
                          (Expr.Econst_int (Integers.Int.repr 0) tint)))
                      (Stmt.Sifthenelse (Expr.Etempvar _t'37 tint)
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Sset _t'66
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Etempvar ___x86_sr_ctx (tptr (Ty.Tstruct ___sk_buff noattr)))
                                  (Ty.Tstruct ___sk_buff noattr)) _priority
                                tuint))
                            (Stmt.Scall (some _t'32)
                              (Expr.Evar _x86_apply_width (Ty.Tfunction
                                                            [tulong, tuchar]
                                                            tulong
                                                            cc_default))
                              [(Expr.Ebinop Binop.Oshr
                                 (Expr.Ecast (Expr.Etempvar _t'66 tuint)
                                   tulong)
                                 (Expr.Ebinop Binop.Omul
                                   (Expr.Ebinop Binop.Osub
                                     (Expr.Etempvar ___x86_sr_off tlong)
                                     (Expr.Econst_int (Integers.Int.repr 144) tint)
                                     tlong)
                                   (Expr.Econst_int (Integers.Int.repr 8) tint)
                                   tlong) tulong),
                               (Expr.Etempvar ___x86_sr_width tuchar)]))
                          (Stmt.Sset ___x86_sr_value
                            (Expr.Etempvar _t'32 tulong)))
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                              (Expr.Etempvar ___x86_sr_off tlong)
                                              (Expr.Econst_int (Integers.Int.repr 168) tint)
                                              tint)
                            (Stmt.Sset _t'36
                              (Expr.Ecast
                                (Expr.Ebinop Binop.Ole
                                  (Expr.Etempvar ___x86_sr_off tlong)
                                  (Expr.Ebinop Binop.Osub
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Econst_int (Integers.Int.repr 168) tint)
                                      (Expr.Econst_int (Integers.Int.repr 4) tint)
                                      tint)
                                    (Expr.Etempvar ___x86_sr_width tuchar)
                                    tint) tint) tbool))
                            (Stmt.Sset _t'36
                              (Expr.Econst_int (Integers.Int.repr 0) tint)))
                          (Stmt.Sifthenelse (Expr.Etempvar _t'36 tint)
                            (Stmt.Ssequence
                              (Stmt.Ssequence
                                (Stmt.Sset _t'65
                                  (Expr.Efield
                                    (Expr.Ederef
                                      (Expr.Etempvar ___x86_sr_ctx (tptr (Ty.Tstruct ___sk_buff noattr)))
                                      (Ty.Tstruct ___sk_buff noattr)) _mark
                                    tuint))
                                (Stmt.Scall (some _t'33)
                                  (Expr.Evar _x86_apply_width (Ty.Tfunction
                                                                [tulong,
                                                                 tuchar]
                                                                tulong
                                                                cc_default))
                                  [(Expr.Ebinop Binop.Oshr
                                     (Expr.Ecast (Expr.Etempvar _t'65 tuint)
                                       tulong)
                                     (Expr.Ebinop Binop.Omul
                                       (Expr.Ebinop Binop.Osub
                                         (Expr.Etempvar ___x86_sr_off tlong)
                                         (Expr.Econst_int (Integers.Int.repr 168) tint)
                                         tlong)
                                       (Expr.Econst_int (Integers.Int.repr 8) tint)
                                       tlong) tulong),
                                   (Expr.Etempvar ___x86_sr_width tuchar)]))
                              (Stmt.Sset ___x86_sr_value
                                (Expr.Etempvar _t'33 tulong)))
                            (Stmt.Sloop
                              (Stmt.Ssequence
                                (Stmt.Ssequence
                                  s_kprog_x86_read_mem_value_10
                                  (Stmt.Scall (some _t'35)
                                    (Expr.Evar _kprog_x86_mem_load (Ty.Tfunction
                                                                    [(tptr tvoid),
                                                                    tuchar]
                                                                    tulong
                                                                    cc_default))
                                    [(Expr.Ecast
                                       (Expr.Ecast
                                         (Expr.Ebinop Binop.Oadd
                                           (Expr.Ecast
                                             (Expr.Ecast
                                               (Expr.Etempvar _t'34 (tptr tvoid))
                                               tulong) tulong)
                                           (Expr.Ecast
                                             (Expr.Etempvar ___x86_l_disp tlong)
                                             tulong) tulong) tulong)
                                       (tptr tuchar)),
                                     (Expr.Etempvar ___x86_l_read_mem_width tuchar)]))
                                (Stmt.Sset ___x86_sr_value
                                  (Expr.Etempvar _t'35 tulong)))
                              Stmt.Sbreak)))))))))))
        (Stmt.Sset ___x86_l_value (Expr.Etempvar ___x86_sr_value tulong))))))

def s_kprog_x86_read_mem_value_12 : Stmt :=
Stmt.Sbreak

def s_kprog_x86_read_mem_value_13 : Stmt :=
(Stmt.Scall (some _t'42)
  (Expr.Evar _source_of (Ty.Tfunction
                          [(tptr (Ty.Tstruct _x86_sim_register_state noattr)),
                           tulong, tulong] tuchar cc_default))
  [(Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
   (Expr.Etempvar _base tulong),
   (Expr.Etempvar ___x86_l_read_mem_width tuchar)])

def s_kprog_x86_read_mem_value_14 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Scall (some _t'43)
      (Expr.Evar _kprog_x86_stack_read (Ty.Tfunction
                                         [(tptr (Ty.Tstruct _x86_sim_register_state noattr)),
                                          (tptr (Ty.Tstruct _kprog_x86_arena noattr)),
                                          tuint, tlong, tulong] tulong
                                         cc_default))
      [(Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
       (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr))),
       (Expr.Etempvar _capacity tuint),
       (Expr.Ebinop Binop.Oadd
         (Expr.Ecast
           (Expr.Ecast (Expr.Etempvar ___x86_l_base_ptr (tptr tvoid)) tlong)
           tlong) (Expr.Etempvar ___x86_l_disp tlong) tlong),
       (Expr.Etempvar ___x86_l_read_mem_width tuchar)])
    (Stmt.Sset ___x86_l_value (Expr.Etempvar _t'43 tulong)))
  Stmt.Sbreak)

def s_kprog_x86_read_mem_value_15 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Ecast
                        (Expr.Ebinop Binop.Oand (Expr.Etempvar _aux tulong)
                          (Expr.Econst_int (Integers.Int.repr 255) tuint)
                          tulong) tuchar)
                      (Expr.Econst_int (Integers.Int.repr 255) tuint) tint)
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Etempvar _store_disp tulong)
          (Stmt.Ssequence
            (Stmt.Scall (some _t'45)
              (Expr.Evar _x86_store_imm_disp (Ty.Tfunction [tulong] tint
                                               cc_default))
              [(Expr.Etempvar _imm tulong)])
            (Stmt.Sset _t'44 (Expr.Ecast (Expr.Etempvar _t'45 tint) tlong)))
          (Stmt.Ssequence
            (Stmt.Scall (some _t'46)
              (Expr.Evar _x86_simm (Ty.Tfunction [tulong] tlong cc_default))
              [(Expr.Etempvar _imm tulong)])
            (Stmt.Sset _t'44 (Expr.Ecast (Expr.Etempvar _t'46 tlong) tlong))))
        (Stmt.Scall (some _t'47)
          (Expr.Evar _kprog_x86_mem_load_fixed (Ty.Tfunction
                                                 [(tptr tvoid), tlong,
                                                  tuchar] tulong cc_default))
          [(Expr.Etempvar ___x86_l_base_ptr (tptr tvoid)),
           (Expr.Etempvar _t'44 tlong),
           (Expr.Etempvar ___x86_l_read_mem_width tuchar)]))
      (Stmt.Sset ___x86_l_value (Expr.Etempvar _t'47 tulong)))
    (Stmt.Ssequence
      (Stmt.Scall (some _t'48)
        (Expr.Evar _x86_sim_clight_load_pointer (Ty.Tfunction [(tptr tvoid)]
                                                  (tptr tvoid) cc_default))
        [(Expr.Etempvar ___x86_l_addr (tptr tvoid))])
      (Stmt.Sset ___x86_l_value
        (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'48 (tptr tvoid)) tlong)
          tulong))))
  Stmt.Sbreak)

def s_kprog_x86_read_mem_value_16 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Ecast
                        (Expr.Ebinop Binop.Oand (Expr.Etempvar _aux tulong)
                          (Expr.Econst_int (Integers.Int.repr 255) tuint)
                          tulong) tuchar)
                      (Expr.Econst_int (Integers.Int.repr 255) tuint) tint)
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Etempvar _store_disp tulong)
          (Stmt.Ssequence
            (Stmt.Scall (some _t'50)
              (Expr.Evar _x86_store_imm_disp (Ty.Tfunction [tulong] tint
                                               cc_default))
              [(Expr.Etempvar _imm tulong)])
            (Stmt.Sset _t'49 (Expr.Ecast (Expr.Etempvar _t'50 tint) tlong)))
          (Stmt.Ssequence
            (Stmt.Scall (some _t'51)
              (Expr.Evar _x86_simm (Ty.Tfunction [tulong] tlong cc_default))
              [(Expr.Etempvar _imm tulong)])
            (Stmt.Sset _t'49 (Expr.Ecast (Expr.Etempvar _t'51 tlong) tlong))))
        (Stmt.Scall (some _t'52)
          (Expr.Evar _kprog_x86_mem_load_fixed (Ty.Tfunction
                                                 [(tptr tvoid), tlong,
                                                  tuchar] tulong cc_default))
          [(Expr.Etempvar ___x86_l_base_ptr (tptr tvoid)),
           (Expr.Etempvar _t'49 tlong),
           (Expr.Etempvar ___x86_l_read_mem_width tuchar)]))
      (Stmt.Sset ___x86_l_value (Expr.Etempvar _t'52 tulong)))
    (Stmt.Sloop
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Scall (some _t'53)
            (Expr.Evar _kprog_x86_mem_load (Ty.Tfunction
                                             [(tptr tvoid), tuchar] tulong
                                             cc_default))
            [(Expr.Ecast
               (Expr.Ecast
                 (Expr.Ebinop Binop.Oadd
                   (Expr.Ecast
                     (Expr.Ecast
                       (Expr.Etempvar ___x86_l_base_ptr (tptr tvoid)) tulong)
                     tulong)
                   (Expr.Ecast (Expr.Etempvar ___x86_l_disp tlong) tulong)
                   tulong) tulong) (tptr tuchar)),
             (Expr.Etempvar ___x86_l_read_mem_width tuchar)])
          (Stmt.Sset ___x86_data_observed (Expr.Etempvar _t'53 tulong)))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Scall (some _t'57)
              (Expr.Evar _tag_of (Ty.Tfunction
                                   [(tptr (Ty.Tstruct _x86_sim_register_state noattr)),
                                    tulong] tuchar cc_default))
              [(Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
               (Expr.Etempvar _base tulong)])
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Etempvar _t'57 tuchar)
                                (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                tint)
              (Stmt.Ssequence
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sset _t'63
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
                                        (Expr.Etempvar ___x86_l_base_ptr (tptr tvoid))
                                        tulong) tulong)
                                    (Expr.Ecast
                                      (Expr.Etempvar ___x86_l_disp tlong)
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
                                            (Expr.Etempvar _t'63 (tptr (tvolatile tuchar)))
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
                    (Stmt.Sset ___x86_data_offset
                      (Expr.Ecast (Expr.Etempvar ___x86_alias_delta tulong)
                        tlong)))
                  Stmt.Sbreak)
                (Stmt.Ssequence
                  (Stmt.Sset _t'62
                    (Expr.Efield
                      (Expr.Efield
                        (Expr.Efield
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                              (Ty.Tstruct _x86_sim_register_state noattr))
                            (Positive.ofNat 18727075383868559167)
                            (Ty.Tunion __3119 noattr))
                          (Positive.ofNat 18727075383868559167)
                          (Ty.Tstruct __3120 noattr)) _rsp
                        (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                      (Expr.Etempvar ___x86_data_offset tlong)
                                      (Expr.Ecast
                                        (Expr.Ecast
                                          (Expr.Etempvar _t'62 (tptr tvoid))
                                          tlong) tlong) tint)
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'54)
                            (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                 [tuint]
                                                                 tulong
                                                                 cc_default))
                            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                          (Stmt.Scall (some _t'55)
                            (Expr.Evar _x86_width_effective (Ty.Tfunction
                                                              [tuchar] tuchar
                                                              cc_default))
                            [(Expr.Etempvar ___x86_l_read_mem_width tuchar)]))
                        (Stmt.Scall (some _t'56)
                          (Expr.Evar _x86_apply_width (Ty.Tfunction
                                                        [tulong, tuchar]
                                                        tulong cc_default))
                          [(Expr.Etempvar _t'54 tulong),
                           (Expr.Etempvar _t'55 tuchar)]))
                      (Stmt.Sset ___x86_data_observed
                        (Expr.Etempvar _t'56 tulong)))
                    Stmt.Sskip)))
              Stmt.Sskip))
          (Stmt.Sset ___x86_l_value
            (Expr.Etempvar ___x86_data_observed tulong))))
      Stmt.Sbreak))
  Stmt.Sbreak)

def f_kprog_x86_read_mem_value : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_state, (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
                (_arena, (tptr (Ty.Tstruct _kprog_x86_arena noattr))),
                (_capacity, tuint), (_base, tulong), (_aux, tulong),
                (_imm, tulong), (_width, tulong), (_store_disp, tulong)],
  fn_vars := [],
  fn_temps := [(___x86_state,
                (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
               (_value, tulong), (___x86_l_base_ptr, (tptr tvoid)),
               (___x86_l_read_mem_width, tuchar), (___x86_l_disp, tlong),
               (___x86_l_value, tulong), (___x86_l_addr, (tptr tvoid)),
               (___x86_xdp_off, tlong),
               (___x86_xdp_ctx,
                (tptr (tvolatile (Ty.Tstruct _xdp_md noattr)))),
               (___x86_captured_xdp_value, tulong),
               (___x86_sr_width, tuchar), (___x86_sr_off, tlong),
               (___x86_sr_ctx, (tptr (Ty.Tstruct ___sk_buff noattr))),
               (___x86_sr_value, tulong), (___x86_sr_lane, tlong),
               (___x86_cbr_addr, (tptr (tvolatile tuchar))),
               (___x86_cbr_value, tulong), (___x86_data_observed, tulong),
               (___x86_data_offset, tlong), (___x86_alias_delta, tulong),
               (_t'61, tuchar), (_t'60, tint), (_t'59, tuchar),
               (_t'58, tint), (_t'57, tuchar), (_t'56, tulong),
               (_t'55, tuchar), (_t'54, tulong), (_t'53, tulong),
               (_t'52, tulong), (_t'51, tlong), (_t'50, tint),
               (_t'49, tlong), (_t'48, (tptr tvoid)), (_t'47, tulong),
               (_t'46, tlong), (_t'45, tint), (_t'44, tlong),
               (_t'43, tulong), (_t'42, tuchar), (_t'41, tint),
               (_t'40, tint), (_t'39, tint), (_t'38, tint), (_t'37, tint),
               (_t'36, tint), (_t'35, tulong), (_t'34, (tptr tvoid)),
               (_t'33, tulong), (_t'32, tulong), (_t'31, tulong),
               (_t'30, (tvolatile tuchar)), (_t'29, (tvolatile tuchar)),
               (_t'28, (tvolatile tuchar)), (_t'27, (tvolatile tuchar)),
               (_t'26, (tvolatile tuchar)), (_t'25, (tvolatile tuchar)),
               (_t'24, (tvolatile tuchar)), (_t'23, (tvolatile tuchar)),
               (_t'22, tulong), (_t'21, tulong), (_t'20, (tptr tvoid)),
               (_t'19, (tptr tvoid)), (_t'18, (tptr tvoid)), (_t'17, tint),
               (_t'16, tint), (_t'15, tint), (_t'14, tulong),
               (_t'13, (tptr tvoid)), (_t'12, (tptr tvoid)),
               (_t'11, (tptr tvoid)), (_t'10, (tptr tvoid)), (_t'9, tint),
               (_t'8, tint), (_t'7, (tptr tvoid)), (_t'6, tuchar),
               (_t'5, tlong), (_t'4, tlong), (_t'3, tint), (_t'2, tlong),
               (_t'1, tuchar), (_t'73, (tptr tvoid)), (_t'72, tuchar),
               (_t'71, (tptr tvoid)), (_t'70, tuchar), (_t'69, (tptr tvoid)),
               (_t'68, (tptr tvoid)), (_t'67, tuint), (_t'66, tuint),
               (_t'65, tuint), (_t'64, (tptr tvoid)),
               (_t'63, (tptr (tvolatile tuchar))), (_t'62, (tptr tvoid))],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_state
    (Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))))
  (Stmt.Ssequence
    (Stmt.Sloop
      (Stmt.Ssequence
        (Stmt.Sset ___x86_l_base_ptr
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
            (tptr tvoid)))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Scall (some _t'1)
              (Expr.Evar _x86_width_effective (Ty.Tfunction [tuchar] tuchar
                                                cc_default))
              [(Expr.Etempvar _width tulong)])
            (Stmt.Sset ___x86_l_read_mem_width
              (Expr.Ecast (Expr.Etempvar _t'1 tuchar) tuchar)))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Etempvar _store_disp tulong)
                (Stmt.Ssequence
                  (Stmt.Scall (some _t'3)
                    (Expr.Evar _x86_store_imm_disp (Ty.Tfunction [tulong]
                                                     tint cc_default))
                    [(Expr.Etempvar _imm tulong)])
                  (Stmt.Sset _t'2
                    (Expr.Ecast (Expr.Etempvar _t'3 tint) tlong)))
                (Stmt.Ssequence
                  (Stmt.Scall (some _t'4)
                    (Expr.Evar _x86_simm (Ty.Tfunction [tulong] tlong
                                           cc_default))
                    [(Expr.Etempvar _imm tulong)])
                  (Stmt.Sset _t'2
                    (Expr.Ecast (Expr.Etempvar _t'4 tlong) tlong))))
              (Stmt.Sset ___x86_l_disp (Expr.Etempvar _t'2 tlong)))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Scall (some _t'5)
                  (Expr.Evar _kprog_x86_mem_offset (Ty.Tfunction
                                                     [(tptr (Ty.Tstruct _x86_sim_register_state noattr)),
                                                      (tptr (Ty.Tstruct _kprog_x86_arena noattr)),
                                                      tuint, tulong, tlong]
                                                     tlong cc_default))
                  [(Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
                   (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr))),
                   (Expr.Etempvar _capacity tuint),
                   (Expr.Etempvar _aux tulong),
                   (Expr.Etempvar ___x86_l_disp tlong)])
                (Stmt.Sset ___x86_l_disp (Expr.Etempvar _t'5 tlong)))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Scall (some _t'6)
                    (Expr.Evar _tag_of (Ty.Tfunction
                                         [(tptr (Ty.Tstruct _x86_sim_register_state noattr)),
                                          tulong] tuchar cc_default))
                    [(Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
                     (Expr.Etempvar _base tulong)])
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.One
                                      (Expr.Etempvar _t'6 tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                      tint)
                    Stmt.Sskip
                    Stmt.Sskip))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.One
                                        (Expr.Etempvar _base tulong)
                                        (Expr.Econst_int (Integers.Int.repr 255) tuint)
                                        tint)
                      (Stmt.Sset _t'8
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 1) tint) tint))
                      (Stmt.Sset _t'8
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 0) tint) tint)))
                    (Stmt.Sifthenelse (Expr.Ecast (Expr.Etempvar _t'8 tint)
                                        tuchar)
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                            (Expr.Ecast
                                              (Expr.Etempvar _base tulong)
                                              tulong)
                                            (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                            tint)
                          (Stmt.Ssequence
                            (Stmt.Sset _t'73
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
                                          (Ty.Tunion __3119 noattr))
                                        _gpr_cells
                                        (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                                      (Expr.Ecast
                                        (Expr.Etempvar _base tulong) tuchar)
                                      (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                                    (Ty.Tstruct _x86_sim_gpr_cell noattr))
                                  _value (Ty.Tunion _x86_sim_gpr noattr))
                                _ptr (tptr tvoid)))
                            (Stmt.Sset _t'7
                              (Expr.Ecast (Expr.Etempvar _t'73 (tptr tvoid))
                                (tptr tvoid))))
                          (Stmt.Sset _t'7
                            (Expr.Ecast
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 0) tint)
                                (tptr tvoid)) (tptr tvoid))))
                        (Stmt.Sset ___x86_l_base_ptr
                          (Expr.Etempvar _t'7 (tptr tvoid))))
                      Stmt.Sskip))
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.One
                                            (Expr.Etempvar _base tulong)
                                            (Expr.Econst_int (Integers.Int.repr 255) tuint)
                                            tint)
                          (Stmt.Sset _t'9
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 1) tint)
                              tint))
                          (Stmt.Sset _t'9
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 0) tint)
                              tint)))
                        (Stmt.Sifthenelse (Expr.Ecast
                                            (Expr.Etempvar _t'9 tint) tuchar)
                          (Stmt.Sset _t'10
                            (Expr.Ecast
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Ecast
                                      (Expr.Ecast
                                        (Expr.Etempvar ___x86_l_base_ptr (tptr tvoid))
                                        tulong) tulong)
                                    (Expr.Ecast
                                      (Expr.Etempvar ___x86_l_disp tlong)
                                      tulong) tulong) tulong) (tptr tuchar))
                              (tptr tvoid)))
                          (Stmt.Sset _t'10
                            (Expr.Ecast
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Etempvar ___x86_l_disp tlong) tulong)
                                (tptr tvoid)) (tptr tvoid)))))
                      (Stmt.Sset ___x86_l_addr
                        (Expr.Etempvar _t'10 (tptr tvoid))))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sset _t'72
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                (Ty.Tstruct _x86_sim_register_state noattr))
                              _is_xdp tuchar))
                          (Stmt.Sifthenelse (Expr.Etempvar _t'72 tuchar)
                            (Stmt.Ssequence
                              s_kprog_x86_read_mem_value_0
                              (Stmt.Sset _t'60
                                (Expr.Ecast
                                  (Expr.Ebinop Binop.Oeq
                                    (Expr.Etempvar _t'61 tuchar)
                                    (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                    tint) tbool)))
                            (Stmt.Sset _t'60
                              (Expr.Econst_int (Integers.Int.repr 0) tint))))
                        (Stmt.Sifthenelse (Expr.Etempvar _t'60 tint)
                          (Stmt.Sloop
                            (Stmt.Ssequence
                              s_kprog_x86_read_mem_value_1
                              (Stmt.Ssequence
                                s_kprog_x86_read_mem_value_2
                                s_kprog_x86_read_mem_value_3))
                            Stmt.Sbreak)
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Sset _t'70
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                    (Ty.Tstruct _x86_sim_register_state noattr))
                                  _abi_kind tuchar))
                              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                  (Expr.Etempvar _t'70 tuchar)
                                                  (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                                  tint)
                                s_kprog_x86_read_mem_value_4
                                (Stmt.Sset _t'58
                                  (Expr.Econst_int (Integers.Int.repr 0) tint))))
                            (Stmt.Sifthenelse (Expr.Etempvar _t'58 tint)
                              (Stmt.Sloop
                                s_kprog_x86_read_mem_value_11
                                s_kprog_x86_read_mem_value_12)
                              (Stmt.Ssequence
                                s_kprog_x86_read_mem_value_13
                                (Stmt.Sswitch (Expr.Etempvar _t'42 tuchar)
                                  (LStmts.LScons (some 0)
                                    s_kprog_x86_read_mem_value_14
                                    (LStmts.LScons (some 1)
                                      s_kprog_x86_read_mem_value_15
                                      (LStmts.LScons none
                                        s_kprog_x86_read_mem_value_16
                                        LStmts.LSnil)))))))))
                      (Stmt.Sset _value
                        (Expr.Etempvar ___x86_l_value tulong))))))))))
      Stmt.Sbreak)
    (Stmt.Sreturn (some (Expr.Etempvar _value tulong)))))
}

def s_kprog_x86_movbe_load_0 : Stmt :=
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
                (Ty.Tunion __3119 noattr)) _gpr_cells
              (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
            (Expr.Ecast (Expr.Etempvar _dst tulong) tuchar)
            (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
          (Ty.Tstruct _x86_sim_gpr_cell noattr)) _value
        (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
  (Stmt.Sset _t'7
    (Expr.Ecast (Expr.Etempvar _t'41 (tptr tvoid)) (tptr tvoid))))

def s_kprog_x86_movbe_load_1 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                    (Expr.Etempvar ___x86_tag_reg tulong)
                    (Expr.Econst_int (Integers.Int.repr 16) tuint) tint)
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
                (Ty.Tunion __3119 noattr)) _gpr_cells
              (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
            (Expr.Ecast (Expr.Etempvar ___x86_tag_reg tulong) tuchar)
            (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
          (Ty.Tstruct _x86_sim_gpr_cell noattr)) _tag tuchar))
    (Stmt.Sset _t'8 (Expr.Ecast (Expr.Etempvar _t'40 tuchar) tuint)))
  (Stmt.Sset _t'8
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuint)))

def s_kprog_x86_movbe_load_2 : Stmt :=
(Stmt.Sset _t'13
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuint))

def s_kprog_x86_movbe_load_3 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                    (Expr.Ecast (Expr.Etempvar ___x86_wr_width tuchar)
                      tuchar) (Expr.Econst_int (Integers.Int.repr 2) tuint)
                    tint)
  (Stmt.Ssequence
    (Stmt.Sset _t'13
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
    (Stmt.Sset _t'13 (Expr.Ecast (Expr.Etempvar _t'13 tuint) tuint)))
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Ecast (Expr.Etempvar ___x86_wr_width tuchar)
                        tuchar) (Expr.Econst_int (Integers.Int.repr 4) tuint)
                      tint)
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sset _t'13
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint) tuint))
        (Stmt.Sset _t'13 (Expr.Ecast (Expr.Etempvar _t'13 tuint) tuint)))
      (Stmt.Sset _t'13 (Expr.Ecast (Expr.Etempvar _t'13 tuint) tuint)))
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sset _t'13
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))
        (Stmt.Sset _t'13 (Expr.Ecast (Expr.Etempvar _t'13 tuint) tuint)))
      (Stmt.Sset _t'13 (Expr.Ecast (Expr.Etempvar _t'13 tuint) tuint)))))

def s_kprog_x86_movbe_load_4 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _dst tulong)
                      (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
    (Stmt.Ssequence
      (Stmt.Sset _t'38
        (Expr.Efield
          (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr)) _ptr
          (tptr tvoid)))
      (Stmt.Ssequence
        (Stmt.Sset _t'39
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
                  (Expr.Ecast (Expr.Etempvar _t'38 (tptr tvoid)) tlong)
                  tulong) (Expr.Etempvar _t'39 tulong) tulong) tlong)
            (tptr tvoid)))))
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                        (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                        (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
      (Stmt.Ssequence
        (Stmt.Sloop
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sset _t'36
                (Expr.Efield
                  (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                  _ptr (tptr tvoid)))
              (Stmt.Ssequence
                (Stmt.Sset _t'37
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                      (Ty.Tstruct _kprog_x86_arena noattr)) _b
                    (tptr (tvolatile tuchar))))
                (Stmt.Sset ___x86_stack_delta
                  (Expr.Ebinop Binop.Osub
                    (Expr.Ecast
                      (Expr.Ecast (Expr.Etempvar _t'36 (tptr tvoid)) tlong)
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
              (Stmt.Sset _t'35
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                    (Ty.Tstruct _x86_sim_register_state noattr))
                  _native_stack_base tulong))
              (Stmt.Sset ___x86_wr_stack_bits
                (Expr.Ebinop Binop.Oadd
                  (Expr.Etempvar ___x86_stack_delta tulong)
                  (Expr.Etempvar _t'35 tulong) tulong))))
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
              (Stmt.Sset _t'34
                (Expr.Efield
                  (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                  _ptr (tptr tvoid)))
              (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
                [(tptr (tvolatile (tptr tvoid))), (tvolatile (tptr tvoid))]
                [(Expr.Eaddrof
                   (Expr.Efield
                     (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3440 noattr)))
                     _ptr (tvolatile (tptr tvoid)))
                   (tptr (tvolatile (tptr tvoid)))),
                 (Expr.Etempvar _t'34 (tptr tvoid))]))
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar ___x86_wr_shift tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                  tint)
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3440 noattr)))
                        _b (tvolatile (tarray tuchar 8)))
                      (Expr.Econst_int (Integers.Int.repr 1) tint)
                      (tptr tuchar)) tuchar)
                  (Expr.Etempvar ___kprog_x86_lane tuchar))
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3440 noattr)))
                        _b (tvolatile (tarray tuchar 8)))
                      (Expr.Econst_int (Integers.Int.repr 0) tint)
                      (tptr tuchar)) tuchar)
                  (Expr.Etempvar ___kprog_x86_lane tuchar)))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sbuiltin (some _t'9) (ExtFun.EF_vload Chunk.Mint64)
                    [(tptr (tvolatile (tptr tvoid)))]
                    [(Expr.Eaddrof
                       (Expr.Efield
                         (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3440 noattr)))
                         _ptr (tvolatile (tptr tvoid)))
                       (tptr (tvolatile (tptr tvoid))))])
                  (Stmt.Sset ___kprog_x86_bits
                    (Expr.Ecast
                      (Expr.Ecast
                        (Expr.Etempvar _t'9 (tvolatile (tptr tvoid))) tlong)
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

def s_kprog_x86_movbe_load_5 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Ecast (Expr.Etempvar ___x86_wr_width tuchar)
                        tuchar) (Expr.Econst_int (Integers.Int.repr 1) tuint)
                      tint)
    (Stmt.Sset _t'12
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuint))
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                        (Expr.Ecast (Expr.Etempvar ___x86_wr_width tuchar)
                          tuchar)
                        (Expr.Econst_int (Integers.Int.repr 2) tuint) tint)
      (Stmt.Ssequence
        (Stmt.Sset _t'12
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
        (Stmt.Sset _t'12 (Expr.Ecast (Expr.Etempvar _t'12 tuint) tuint)))
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                          (Expr.Ecast (Expr.Etempvar ___x86_wr_width tuchar)
                            tuchar)
                          (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sset _t'12
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint)
                tuint))
            (Stmt.Sset _t'12 (Expr.Ecast (Expr.Etempvar _t'12 tuint) tuint)))
          (Stmt.Sset _t'12 (Expr.Ecast (Expr.Etempvar _t'12 tuint) tuint)))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sset _t'12
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint)
                tuint))
            (Stmt.Sset _t'12 (Expr.Ecast (Expr.Etempvar _t'12 tuint) tuint)))
          (Stmt.Sset _t'12 (Expr.Ecast (Expr.Etempvar _t'12 tuint) tuint))))))
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _t'12 tuint)
                      (Expr.Econst_int (Integers.Int.repr 1) tuint) tint)
    (Stmt.Ssequence
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _dst tulong)
                          (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
        (Stmt.Ssequence
          (Stmt.Sset _t'32
            (Expr.Efield
              (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr)) _ptr
              (tptr tvoid)))
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
                      (Expr.Ecast (Expr.Etempvar _t'32 (tptr tvoid)) tlong)
                      tulong) (Expr.Etempvar _t'33 tulong) tulong) tlong)
                (tptr tvoid)))))
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                            (Expr.Econst_int (Integers.Int.repr 4) tuint)
                            tint)
          (Stmt.Ssequence
            (Stmt.Sloop
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sset _t'30
                    (Expr.Efield
                      (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
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
                        (Expr.Ecast
                          (Expr.Ecast (Expr.Etempvar _t'30 (tptr tvoid))
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
                                          (Expr.Etempvar _t'31 (tptr (tvolatile tuchar)))
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
                  (Stmt.Sset _t'29
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                        (Ty.Tstruct _x86_sim_register_state noattr))
                      _native_stack_base tulong))
                  (Stmt.Sset ___x86_wr_stack_bits__1
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Etempvar ___x86_stack_delta__1 tulong)
                      (Expr.Etempvar _t'29 tulong) tulong))))
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
                  (Stmt.Sset _t'28
                    (Expr.Efield
                      (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                      _ptr (tptr tvoid)))
                  (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
                    [(tptr (tvolatile (tptr tvoid))),
                     (tvolatile (tptr tvoid))]
                    [(Expr.Eaddrof
                       (Expr.Efield
                         (Expr.Evar ___kprog_x86_partial__1 (tvolatile (Ty.Tunion __3446 noattr)))
                         _ptr (tvolatile (tptr tvoid)))
                       (tptr (tvolatile (tptr tvoid)))),
                     (Expr.Etempvar _t'28 (tptr tvoid))]))
                (Stmt.Ssequence
                  (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint16unsigned)
                    [(tptr (tvolatile tushort)), (tvolatile tushort)]
                    [(Expr.Eaddrof
                       (Expr.Efield
                         (Expr.Evar ___kprog_x86_partial__1 (tvolatile (Ty.Tunion __3446 noattr)))
                         _w (tvolatile tushort)) (tptr (tvolatile tushort))),
                     (Expr.Etempvar ___kprog_x86_lane__1 tushort)])
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sbuiltin (some _t'10)
                        (ExtFun.EF_vload Chunk.Mint64)
                        [(tptr (tvolatile (tptr tvoid)))]
                        [(Expr.Eaddrof
                           (Expr.Efield
                             (Expr.Evar ___kprog_x86_partial__1 (tvolatile (Ty.Tunion __3446 noattr)))
                             _ptr (tvolatile (tptr tvoid)))
                           (tptr (tvolatile (tptr tvoid))))])
                      (Stmt.Sset ___kprog_x86_bits__1
                        (Expr.Ecast
                          (Expr.Ecast
                            (Expr.Etempvar _t'10 (tvolatile (tptr tvoid)))
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
        (Stmt.Sset _t'11
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuint))
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Ecast
                              (Expr.Etempvar ___x86_wr_width tuchar) tuchar)
                            (Expr.Econst_int (Integers.Int.repr 2) tuint)
                            tint)
          (Stmt.Ssequence
            (Stmt.Sset _t'11
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint)
                tuint))
            (Stmt.Sset _t'11 (Expr.Ecast (Expr.Etempvar _t'11 tuint) tuint)))
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Ecast
                                (Expr.Etempvar ___x86_wr_width tuchar)
                                tuchar)
                              (Expr.Econst_int (Integers.Int.repr 4) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'11
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint)
                    tuint))
                (Stmt.Sset _t'11
                  (Expr.Ecast (Expr.Etempvar _t'11 tuint) tuint)))
              (Stmt.Sset _t'11
                (Expr.Ecast (Expr.Etempvar _t'11 tuint) tuint)))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'11
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint)
                    tuint))
                (Stmt.Sset _t'11
                  (Expr.Ecast (Expr.Etempvar _t'11 tuint) tuint)))
              (Stmt.Sset _t'11
                (Expr.Ecast (Expr.Etempvar _t'11 tuint) tuint))))))
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _t'11 tuint)
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

def s_kprog_x86_movbe_load_6 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'26
    (Expr.Efield (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
      _ptr (tptr tvoid)))
  (Stmt.Ssequence
    (Stmt.Sset _t'27
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
            (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'26 (tptr tvoid)) tlong)
              tulong) (Expr.Etempvar _t'27 tulong) tulong) tlong)
        (tptr tvoid)))))

def s_kprog_x86_movbe_load_7 : Stmt :=
(Stmt.Sset ___x86_wr_next_ptr
  (Expr.Efield (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
    _ptr (tptr tvoid)))

def s_kprog_x86_movbe_load_8 : Stmt :=
(Stmt.Sset _t'18
  (Expr.Ecast
    (Expr.Ebinop Binop.Oge (Expr.Etempvar ___x86_release_off tlong)
      (Expr.Etempvar ___x86_release_old tlong) tint) tbool))

def s_kprog_x86_movbe_load_9 : Stmt :=
(Stmt.Sset _t'19
  (Expr.Ecast
    (Expr.Ebinop Binop.Ole
      (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_release_off tlong)
        (Expr.Econst_int (Integers.Int.repr 8) tint) tlong)
      (Expr.Etempvar ___x86_release_new tlong) tint) tbool))

def s_kprog_x86_movbe_load_10 : Stmt :=
(Stmt.Scall (some _t'14)
  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong cc_default))
  [(Expr.Econst_int (Integers.Int.repr 6) tint)])

def s_kprog_x86_movbe_load_11 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'24
    (Expr.Efield
      (Expr.Ederef
        (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
        (Ty.Tstruct _kprog_x86_arena noattr)) _q (tptr (tvolatile tulong))))
  (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
    [(tptr (tvolatile tulong)), (tvolatile tulong)]
    [(Expr.Eaddrof
       (Expr.Ederef
         (Expr.Ebinop Binop.Oadd
           (Expr.Etempvar _t'24 (tptr (tvolatile tulong)))
           (Expr.Ebinop Binop.Odiv (Expr.Etempvar ___x86_release_i tuint)
             (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint)
           (tptr (tvolatile tulong))) (tvolatile tulong))
       (tptr (tvolatile tulong))), (Expr.Etempvar _t'14 tulong)]))

def s_kprog_x86_movbe_load_12 : Stmt :=
(Stmt.Sset ___x86_release_lane (Expr.Econst_int (Integers.Int.repr 0) tint))

def s_kprog_x86_movbe_load_13 : Stmt :=
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
                            (Expr.Etempvar ___x86_release_lane tuint) tuint)
                          (Expr.Etempvar _capacity tuint) tint)
        (Stmt.Sset _t'16
          (Expr.Ecast
            (Expr.Ebinop Binop.Oge
              (Expr.Ebinop Binop.Oadd
                (Expr.Etempvar ___x86_release_off tlong)
                (Expr.Etempvar ___x86_release_lane tuint) tlong)
              (Expr.Etempvar ___x86_release_old tlong) tint) tbool))
        (Stmt.Sset _t'16 (Expr.Econst_int (Integers.Int.repr 0) tint)))
      (Stmt.Sifthenelse (Expr.Etempvar _t'16 tint)
        (Stmt.Sset _t'17
          (Expr.Ecast
            (Expr.Ebinop Binop.Olt
              (Expr.Ebinop Binop.Oadd
                (Expr.Etempvar ___x86_release_off tlong)
                (Expr.Etempvar ___x86_release_lane tuint) tlong)
              (Expr.Etempvar ___x86_release_new tlong) tint) tbool))
        (Stmt.Sset _t'17 (Expr.Econst_int (Integers.Int.repr 0) tint))))
    (Stmt.Sifthenelse (Expr.Etempvar _t'17 tint)
      (Stmt.Ssequence
        (Stmt.Scall (some _t'15)
          (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                               cc_default))
          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
        (Stmt.Ssequence
          (Stmt.Sset _t'23
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
                   (Expr.Etempvar _t'23 (tptr (tvolatile tuchar)))
                   (Expr.Ebinop Binop.Oadd
                     (Expr.Etempvar ___x86_release_i tuint)
                     (Expr.Etempvar ___x86_release_lane tuint) tuint)
                   (tptr (tvolatile tuchar))) (tvolatile tuchar))
               (tptr (tvolatile tuchar))),
             (Expr.Ecast (Expr.Etempvar _t'15 tulong) tuchar)])))
      Stmt.Sskip)))

def s_kprog_x86_movbe_load_14 : Stmt :=
(Stmt.Sset ___x86_release_lane
  (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_release_lane tuint)
    (Expr.Econst_int (Integers.Int.repr 1) tint) tuint))

def s_kprog_x86_movbe_load_15 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'21
      (Expr.Efield
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
            (Expr.Etempvar ___x86_sv_i tuint)
            (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
          (Ty.Tstruct _kprog_x86_stack_fact noattr)) _tag (tptr tuchar)))
    (Stmt.Sassign (Expr.Ederef (Expr.Etempvar _t'21 (tptr tuchar)) tuchar)
      (Expr.Econst_int (Integers.Int.repr 0) tuint)))
  (Stmt.Ssequence
    (Stmt.Sset _t'20
      (Expr.Efield
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
            (Expr.Etempvar ___x86_sv_i tuint)
            (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
          (Ty.Tstruct _kprog_x86_stack_fact noattr)) _pointer
        (tptr (tptr tvoid))))
    (Stmt.Sassign
      (Expr.Ederef (Expr.Etempvar _t'20 (tptr (tptr tvoid))) (tptr tvoid))
      (Expr.Econst_int (Integers.Int.repr 0) tint))))

def s_kprog_x86_movbe_load_16 : Stmt :=
Stmt.Sbreak

def s_kprog_x86_movbe_load_17 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_wr_next_tag
    (Expr.Ecast (Expr.Etempvar ___x86_wr_cell_tag tuchar) tuchar))
  (Stmt.Ssequence
    (Stmt.Sloop
      (Stmt.Ssequence
        (Stmt.Sset ___x86_store_reg (Expr.Etempvar _dst tulong))
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
                          (Ty.Tunion __3119 noattr)) _gpr_cells
                        (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                      (Expr.Ecast (Expr.Etempvar ___x86_store_reg tulong)
                        tuchar) (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
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
                        (Ty.Tunion __3119 noattr)) _gpr_cells
                      (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                    (Expr.Ecast (Expr.Etempvar ___x86_store_reg tulong)
                      tuchar) (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                  (Ty.Tstruct _x86_sim_gpr_cell noattr)) _tag tuchar)
              (Expr.Etempvar ___x86_wr_next_tag tuchar)))
          Stmt.Sskip))
      Stmt.Sbreak)
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _dst tulong)
                        (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
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
                        (Ty.Tunion __3119 noattr))
                      (Positive.ofNat 18727075383868559167)
                      (Ty.Tstruct __3120 noattr)) _rsp
                    (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
              (Stmt.Sset ___x86_release_new
                (Expr.Ecast
                  (Expr.Ecast (Expr.Etempvar _t'25 (tptr tvoid)) tlong)
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
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Ole
                                                (Expr.Ebinop Binop.Oadd
                                                  (Expr.Etempvar ___x86_release_i tuint)
                                                  (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                                  tuint)
                                                (Expr.Etempvar _capacity tuint)
                                                tint)
                              s_kprog_x86_movbe_load_8
                              (Stmt.Sset _t'18
                                (Expr.Econst_int (Integers.Int.repr 0) tint)))
                            (Stmt.Sifthenelse (Expr.Etempvar _t'18 tint)
                              s_kprog_x86_movbe_load_9
                              (Stmt.Sset _t'19
                                (Expr.Econst_int (Integers.Int.repr 0) tint))))
                          (Stmt.Sifthenelse (Expr.Etempvar _t'19 tint)
                            (Stmt.Ssequence
                              s_kprog_x86_movbe_load_10
                              s_kprog_x86_movbe_load_11)
                            (Stmt.Ssequence
                              s_kprog_x86_movbe_load_12
                              (Stmt.Sloop
                                s_kprog_x86_movbe_load_13
                                s_kprog_x86_movbe_load_14))))))
                    (Stmt.Sset ___x86_release_i
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar ___x86_release_i tuint)
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
                                (Ty.Tunion __3119 noattr))
                              (Positive.ofNat 18727075383868559167)
                              (Ty.Tstruct __3120 noattr)) _rsp
                            (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                          (tptr tvoid)))
                      (Stmt.Sset ___x86_sv_sp
                        (Expr.Ecast
                          (Expr.Ecast (Expr.Etempvar _t'22 (tptr tvoid))
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
                                s_kprog_x86_movbe_load_15
                                s_kprog_x86_movbe_load_16)
                              Stmt.Sskip)
                            Stmt.Sbreak))
                        (Stmt.Sset ___x86_sv_i
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar ___x86_sv_i tuint)
                            (Expr.Econst_int (Integers.Int.repr 1) tint)
                            tuint)))))
                  Stmt.Sbreak))
              Stmt.Sskip)))
        Stmt.Sbreak)
      Stmt.Sskip)))

def f_kprog_x86_movbe_load : Function := {
  fn_return := tvoid,
  fn_callconv := cc_default,
  fn_params := [(_state, (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
                (_arena, (tptr (Ty.Tstruct _kprog_x86_arena noattr))),
                (_facts, (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr))),
                (_capacity, tuint), (_dst, tulong), (_src, tulong),
                (_flags, tulong), (_aux, tulong), (_imm, tulong)],
  fn_vars := [(___x86_wr_cell, (Ty.Tunion _x86_sim_gpr noattr)),
              (___kprog_x86_partial, (tvolatile (Ty.Tunion __3440 noattr))),
              (___kprog_x86_partial__1,
               (tvolatile (Ty.Tunion __3446 noattr)))],
  fn_temps := [(___x86_state,
                (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
               (___x86_l_width, tuchar), (___x86_l_value, tulong),
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
               (___x86_sv_i, tuint), (_t'19, tint), (_t'18, tint),
               (_t'17, tint), (_t'16, tint), (_t'15, tulong),
               (_t'14, tulong), (_t'13, tuint), (_t'12, tuint),
               (_t'11, tuint), (_t'10, (tvolatile (tptr tvoid))),
               (_t'9, (tvolatile (tptr tvoid))), (_t'8, tuint),
               (_t'7, (tptr tvoid)), (_t'6, tulong), (_t'5, tuchar),
               (_t'4, tulong), (_t'3, tuchar), (_t'2, tint), (_t'1, tlong),
               (_t'42, (tptr tvoid)), (_t'41, (tptr tvoid)), (_t'40, tuchar),
               (_t'39, tulong), (_t'38, (tptr tvoid)),
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
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Scall (some _t'1)
            (Expr.Evar _x86_simm (Ty.Tfunction [tulong] tlong cc_default))
            [(Expr.Etempvar _imm tulong)])
          (Stmt.Scall (some _t'2)
            (Expr.Evar _kprog_x86_read_recovery_mem (Ty.Tfunction
                                                      [(tptr (Ty.Tstruct _x86_sim_register_state noattr)),
                                                       (tptr (Ty.Tstruct _kprog_x86_arena noattr)),
                                                       (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)),
                                                       tuint, tulong, tulong,
                                                       tulong, tlong] tint
                                                      cc_default))
            [(Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
             (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr))),
             (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr))),
             (Expr.Etempvar _capacity tuint), (Expr.Etempvar _src tulong),
             (Expr.Etempvar _dst tulong), (Expr.Etempvar _aux tulong),
             (Expr.Etempvar _t'1 tlong)]))
        (Stmt.Sifthenelse (Expr.Etempvar _t'2 tint) Stmt.Sbreak Stmt.Sskip))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Scall (some _t'3)
            (Expr.Evar _kprog_x86_movbe_width (Ty.Tfunction [tulong] tuchar
                                                cc_default))
            [(Expr.Etempvar _flags tulong)])
          (Stmt.Sset ___x86_l_width
            (Expr.Ecast (Expr.Etempvar _t'3 tuchar) tuchar)))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Scall (some _t'4)
              (Expr.Evar _kprog_x86_read_mem_value (Ty.Tfunction
                                                     [(tptr (Ty.Tstruct _x86_sim_register_state noattr)),
                                                      (tptr (Ty.Tstruct _kprog_x86_arena noattr)),
                                                      tuint, tulong, tulong,
                                                      tulong, tulong, tulong]
                                                     tulong cc_default))
              [(Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
               (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr))),
               (Expr.Etempvar _capacity tuint), (Expr.Etempvar _src tulong),
               (Expr.Etempvar _aux tulong), (Expr.Etempvar _imm tulong),
               (Expr.Etempvar ___x86_l_width tuchar),
               (Expr.Econst_int (Integers.Int.repr 0) tint)])
            (Stmt.Sset ___x86_l_value (Expr.Etempvar _t'4 tulong)))
          (Stmt.Sloop
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'42
                  (Expr.Efield
                    (Expr.Efield
                      (Expr.Efield
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                            (Ty.Tstruct _x86_sim_register_state noattr))
                          (Positive.ofNat 18727075383868559167)
                          (Ty.Tunion __3119 noattr))
                        (Positive.ofNat 18727075383868559167)
                        (Ty.Tstruct __3120 noattr)) _rsp
                      (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
                (Stmt.Sset ___x86_write_old_sp
                  (Expr.Ecast
                    (Expr.Ecast (Expr.Etempvar _t'42 (tptr tvoid)) tlong)
                    tlong)))
              (Stmt.Ssequence
                (Stmt.Sset ___x86_wr_raw_width
                  (Expr.Ecast (Expr.Etempvar ___x86_l_width tuchar) tuchar))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Scall (some _t'5)
                      (Expr.Evar _x86_width_effective (Ty.Tfunction [tuchar]
                                                        tuchar cc_default))
                      [(Expr.Etempvar ___x86_wr_raw_width tuchar)])
                    (Stmt.Sset ___x86_wr_width
                      (Expr.Ecast (Expr.Etempvar _t'5 tuchar) tuchar)))
                  (Stmt.Ssequence
                    (Stmt.Sset ___x86_wr_shift
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 0) tuint) tuchar))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Scall (some _t'6)
                          (Expr.Evar _x86_bswap (Ty.Tfunction
                                                  [tulong, tuchar] tulong
                                                  cc_default))
                          [(Expr.Etempvar ___x86_l_value tulong),
                           (Expr.Etempvar ___x86_l_width tuchar)])
                        (Stmt.Sset ___x86_wr_next
                          (Expr.Etempvar _t'6 tulong)))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                              (Expr.Ecast
                                                (Expr.Etempvar _dst tulong)
                                                tulong)
                                              (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                              tint)
                            s_kprog_x86_movbe_load_0
                            (Stmt.Sset _t'7
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 0) tint)
                                  (tptr tvoid)) (tptr tvoid))))
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                              _ptr (tptr tvoid))
                            (Expr.Etempvar _t'7 (tptr tvoid))))
                        (Stmt.Ssequence
                          (Stmt.Sloop
                            (Stmt.Ssequence
                              (Stmt.Sset ___x86_tag_reg
                                (Expr.Etempvar _dst tulong))
                              (Stmt.Ssequence
                                s_kprog_x86_movbe_load_1
                                (Stmt.Sset ___x86_wr_cell_tag
                                  (Expr.Ecast (Expr.Etempvar _t'8 tuint)
                                    tuchar))))
                            Stmt.Sbreak)
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                  (Expr.Ecast
                                                    (Expr.Etempvar ___x86_wr_width tuchar)
                                                    tuchar)
                                                  (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                                  tint)
                                s_kprog_x86_movbe_load_2
                                s_kprog_x86_movbe_load_3)
                              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                  (Expr.Etempvar _t'13 tuint)
                                                  (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                                  tint)
                                s_kprog_x86_movbe_load_4
                                s_kprog_x86_movbe_load_5))
                            (Stmt.Ssequence
                              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                  (Expr.Etempvar _dst tulong)
                                                  (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                                  tint)
                                s_kprog_x86_movbe_load_6
                                Stmt.Sskip)
                              (Stmt.Ssequence
                                s_kprog_x86_movbe_load_7
                                s_kprog_x86_movbe_load_17))))))))))
            Stmt.Sbreak))))
    Stmt.Sbreak))
}

def f_kprog_x86_store_memory : Function := {
  fn_return := tvoid,
  fn_callconv := cc_default,
  fn_params := [(_address, (tptr tvoid)), (_width, tulong), (_value, tulong)],
  fn_vars := [],
  fn_temps := [],
  fn_body :=
(Stmt.Scall none
  (Expr.Evar _kprog_x86_mem_store (Ty.Tfunction
                                    [(tptr tvoid), tuchar, tulong] tvoid
                                    cc_default))
  [(Expr.Etempvar _address (tptr tvoid)), (Expr.Etempvar _width tulong),
   (Expr.Etempvar _value tulong)])
}

def s_kprog_x86_load_xmm0_0 : Stmt :=
(Stmt.Sset _t'10
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuint))

def s_kprog_x86_load_xmm0_1 : Stmt :=
(Stmt.Sset _t'10
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint))

def s_kprog_x86_load_xmm0_2 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Scall (some _t'13)
      (Expr.Evar _kprog_x86_mem_offset (Ty.Tfunction
                                         [(tptr (Ty.Tstruct _x86_sim_register_state noattr)),
                                          (tptr (Ty.Tstruct _kprog_x86_arena noattr)),
                                          tuint, tulong, tlong] tlong
                                         cc_default))
      [(Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
       (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr))),
       (Expr.Etempvar _capacity tuint), (Expr.Etempvar _aux tulong),
       (Expr.Econst_int (Integers.Int.repr 0) tint)])
    (Stmt.Sset _t'12
      (Expr.Ecast
        (Expr.Ecast
          (Expr.Ecast
            (Expr.Ebinop Binop.Oadd
              (Expr.Ecast (Expr.Etempvar _imm tulong) tulong)
              (Expr.Ecast (Expr.Etempvar _t'13 tlong) tulong) tulong) tlong)
          (tptr tvoid)) (tptr tvoid))))
  (Stmt.Sset _t'12
    (Expr.Ecast (Expr.Etempvar _t'12 (tptr tvoid)) (tptr tvoid))))

def s_kprog_x86_load_xmm0_3 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'12
    (Expr.Ecast
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid))
      (tptr tvoid)))
  (Stmt.Sset _t'12
    (Expr.Ecast (Expr.Etempvar _t'12 (tptr tvoid)) (tptr tvoid))))

def s_kprog_x86_load_xmm0_4 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'33
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
                (Ty.Tunion __3119 noattr)) _gpr_cells
              (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
            (Expr.Ecast (Expr.Etempvar _src tulong) tuchar)
            (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
          (Ty.Tstruct _x86_sim_gpr_cell noattr)) _value
        (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
  (Stmt.Sset _t'14
    (Expr.Ecast (Expr.Etempvar _t'33 (tptr tvoid)) (tptr tvoid))))

def s_kprog_x86_load_xmm0_5 : Stmt :=
(Stmt.Sset _t'14
  (Expr.Ecast
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid))
    (tptr tvoid)))

def s_kprog_x86_load_xmm0_6 : Stmt :=
(Stmt.Sset _t'15
  (Expr.Ecast
    (Expr.Eunop Unop.Onotbool (Expr.Etempvar ___x86_l_base_none tuchar) tint)
    tuint))

def s_kprog_x86_load_xmm0_7 : Stmt :=
(Stmt.Sset _t'15
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))

def s_kprog_x86_load_xmm0_8 : Stmt :=
(Stmt.Scall (some _t'17)
  (Expr.Evar _kprog_x86_mem_load (Ty.Tfunction [(tptr tvoid), tuchar] tulong
                                   cc_default))
  [(Expr.Etempvar ___x86_l_addr (tptr tvoid)),
   (Expr.Econst_int (Integers.Int.repr 8) tuint)])

def s_kprog_x86_load_xmm0_9 : Stmt :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'21)
    (Expr.Evar _tag_of (Ty.Tfunction
                         [(tptr (Ty.Tstruct _x86_sim_register_state noattr)),
                          tulong] tuchar cc_default))
    [(Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
     (Expr.Etempvar _src tulong)])
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _t'21 tuchar)
                      (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
    (Stmt.Ssequence
      (Stmt.Sloop
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sset _t'32
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                  (Ty.Tstruct _kprog_x86_arena noattr)) _b
                (tptr (tvolatile tuchar))))
            (Stmt.Sset ___x86_alias_delta
              (Expr.Ebinop Binop.Osub
                (Expr.Ecast
                  (Expr.Ecast (Expr.Etempvar ___x86_l_addr (tptr tvoid))
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
                        (tptr tuchar)) (tptr tvoid)) tlong) tulong) tulong)))
          (Stmt.Sset ___x86_alias_offset
            (Expr.Ecast (Expr.Etempvar ___x86_alias_delta tulong) tlong)))
        Stmt.Sbreak)
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
                  (Ty.Tunion __3119 noattr))
                (Positive.ofNat 18727075383868559167)
                (Ty.Tstruct __3120 noattr)) _rsp
              (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                            (Expr.Etempvar ___x86_alias_offset tlong)
                            (Expr.Ecast
                              (Expr.Ecast (Expr.Etempvar _t'31 (tptr tvoid))
                                tlong) tlong) tint)
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Scall (some _t'18)
                  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                       tulong cc_default))
                  [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                (Stmt.Scall (some _t'19)
                  (Expr.Evar _x86_width_effective (Ty.Tfunction [tuchar]
                                                    tuchar cc_default))
                  [(Expr.Econst_int (Integers.Int.repr 8) tuint)]))
              (Stmt.Scall (some _t'20)
                (Expr.Evar _x86_apply_width (Ty.Tfunction [tulong, tuchar]
                                              tulong cc_default))
                [(Expr.Etempvar _t'18 tulong), (Expr.Etempvar _t'19 tuchar)]))
            (Stmt.Sset ___x86_alias_observed (Expr.Etempvar _t'20 tulong)))
          Stmt.Sskip)))
    Stmt.Sskip))

def s_kprog_x86_load_xmm0_10 : Stmt :=
(Stmt.Sassign
  (Expr.Efield
    (Expr.Ederef
      (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
      (Ty.Tstruct _x86_sim_register_state noattr)) _xmm0_lo tulong)
  (Expr.Etempvar ___x86_alias_observed tulong))

def s_kprog_x86_load_xmm0_11 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                        (Expr.Econst_int (Integers.Int.repr 1) tint)
                        (Expr.Econst_int (Integers.Int.repr 0) tuint) tint)
      (Stmt.Sset _t'22
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuint))
      (Stmt.Sset _t'22
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint)))
    (Stmt.Scall (some _t'23)
      (Expr.Evar _kprog_x86_mem_load (Ty.Tfunction [(tptr tvoid), tuchar]
                                       tulong cc_default))
      [(Expr.Ecast
         (Expr.Ecast
           (Expr.Ebinop Binop.Oadd
             (Expr.Ecast
               (Expr.Ecast (Expr.Etempvar ___x86_l_addr (tptr tvoid)) tulong)
               tulong) (Expr.Ecast (Expr.Etempvar _t'22 tuint) tulong)
             tulong) tulong) (tptr tuchar)),
       (Expr.Econst_int (Integers.Int.repr 8) tuint)]))
  (Stmt.Sset ___x86_alias_observed__1 (Expr.Etempvar _t'23 tulong)))

def s_kprog_x86_load_xmm0_12 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Scall (some _t'28)
      (Expr.Evar _tag_of (Ty.Tfunction
                           [(tptr (Ty.Tstruct _x86_sim_register_state noattr)),
                            tulong] tuchar cc_default))
      [(Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
       (Expr.Etempvar _src tulong)])
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _t'28 tuchar)
                        (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
      (Stmt.Ssequence
        (Stmt.Sloop
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Econst_int (Integers.Int.repr 1) tint)
                                  (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                  tint)
                (Stmt.Sset _t'24
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                    tuint))
                (Stmt.Sset _t'24
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tuint)
                    tuint)))
              (Stmt.Ssequence
                (Stmt.Sset _t'30
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                      (Ty.Tstruct _kprog_x86_arena noattr)) _b
                    (tptr (tvolatile tuchar))))
                (Stmt.Sset ___x86_alias_delta__1
                  (Expr.Ebinop Binop.Osub
                    (Expr.Ecast
                      (Expr.Ecast
                        (Expr.Ecast
                          (Expr.Ecast
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Etempvar ___x86_l_addr (tptr tvoid))
                                  tulong) tulong)
                              (Expr.Ecast (Expr.Etempvar _t'24 tuint) tulong)
                              tulong) tulong) (tptr tuchar)) tlong) tulong)
                    (Expr.Ecast
                      (Expr.Ecast
                        (Expr.Ecast
                          (Expr.Ecast
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Etempvar _t'30 (tptr (tvolatile tuchar)))
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
            (Stmt.Sset ___x86_alias_offset__1
              (Expr.Ecast (Expr.Etempvar ___x86_alias_delta__1 tulong) tlong)))
          Stmt.Sbreak)
        (Stmt.Ssequence
          (Stmt.Sset _t'29
            (Expr.Efield
              (Expr.Efield
                (Expr.Efield
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                      (Ty.Tstruct _x86_sim_register_state noattr))
                    (Positive.ofNat 18727075383868559167)
                    (Ty.Tunion __3119 noattr))
                  (Positive.ofNat 18727075383868559167)
                  (Ty.Tstruct __3120 noattr)) _rsp
                (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                              (Expr.Etempvar ___x86_alias_offset__1 tlong)
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Etempvar _t'29 (tptr tvoid)) tlong)
                                tlong) tint)
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Scall (some _t'25)
                    (Expr.Evar _native_lab_entry_input (Ty.Tfunction 
                                                         [tuint] tulong
                                                         cc_default))
                    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                  (Stmt.Scall (some _t'26)
                    (Expr.Evar _x86_width_effective (Ty.Tfunction [tuchar]
                                                      tuchar cc_default))
                    [(Expr.Econst_int (Integers.Int.repr 8) tuint)]))
                (Stmt.Scall (some _t'27)
                  (Expr.Evar _x86_apply_width (Ty.Tfunction [tulong, tuchar]
                                                tulong cc_default))
                  [(Expr.Etempvar _t'25 tulong),
                   (Expr.Etempvar _t'26 tuchar)]))
              (Stmt.Sset ___x86_alias_observed__1
                (Expr.Etempvar _t'27 tulong)))
            Stmt.Sskip)))
      Stmt.Sskip))
  (Stmt.Sassign
    (Expr.Efield
      (Expr.Ederef
        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
        (Ty.Tstruct _x86_sim_register_state noattr)) _xmm0_hi tulong)
    (Expr.Etempvar ___x86_alias_observed__1 tulong)))

def f_kprog_x86_load_xmm0 : Function := {
  fn_return := tvoid,
  fn_callconv := cc_default,
  fn_params := [(_state, (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
                (_arena, (tptr (Ty.Tstruct _kprog_x86_arena noattr))),
                (_facts, (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr))),
                (_capacity, tuint), (_src, tulong), (_aux, tulong),
                (_imm, tulong)],
  fn_vars := [],
  fn_temps := [(___x86_state,
                (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
               (___x86_l_disp, tlong), (___x86_l_arm, tuchar),
               (___x86_l_base_none, tuchar), (___x86_l_base_form, tuchar),
               (___x86_l_base_ptr, (tptr tvoid)),
               (___x86_l_base_ptr__1, (tptr tvoid)),
               (___x86_l_addr, (tptr tvoid)),
               (___x86_alias_observed, tulong), (___x86_alias_offset, tlong),
               (___x86_alias_delta, tulong),
               (___x86_alias_observed__1, tulong),
               (___x86_alias_offset__1, tlong),
               (___x86_alias_delta__1, tulong), (_t'28, tuchar),
               (_t'27, tulong), (_t'26, tuchar), (_t'25, tulong),
               (_t'24, tuint), (_t'23, tulong), (_t'22, tuint),
               (_t'21, tuchar), (_t'20, tulong), (_t'19, tuchar),
               (_t'18, tulong), (_t'17, tulong), (_t'16, (tptr tvoid)),
               (_t'15, tuint), (_t'14, (tptr tvoid)), (_t'13, tlong),
               (_t'12, (tptr tvoid)), (_t'11, tulong), (_t'10, tuint),
               (_t'9, tulong), (_t'8, (tptr tvoid)), (_t'7, tuint),
               (_t'6, tint), (_t'5, tuchar), (_t'4, tlong), (_t'3, tlong),
               (_t'2, tint), (_t'1, tlong), (_t'34, (tptr tvoid)),
               (_t'33, (tptr tvoid)), (_t'32, (tptr (tvolatile tuchar))),
               (_t'31, (tptr tvoid)), (_t'30, (tptr (tvolatile tuchar))),
               (_t'29, (tptr tvoid))],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_state
    (Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))))
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Scall (some _t'1)
            (Expr.Evar _x86_simm (Ty.Tfunction [tulong] tlong cc_default))
            [(Expr.Etempvar _imm tulong)])
          (Stmt.Scall (some _t'2)
            (Expr.Evar _kprog_x86_read_recovery_mem (Ty.Tfunction
                                                      [(tptr (Ty.Tstruct _x86_sim_register_state noattr)),
                                                       (tptr (Ty.Tstruct _kprog_x86_arena noattr)),
                                                       (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)),
                                                       tuint, tulong, tulong,
                                                       tulong, tlong] tint
                                                      cc_default))
            [(Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
             (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr))),
             (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr))),
             (Expr.Etempvar _capacity tuint), (Expr.Etempvar _src tulong),
             (Expr.Econst_int (Integers.Int.repr 255) tuint),
             (Expr.Etempvar _aux tulong), (Expr.Etempvar _t'1 tlong)]))
        (Stmt.Sifthenelse (Expr.Etempvar _t'2 tint) Stmt.Sbreak Stmt.Sskip))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Scall (some _t'3)
              (Expr.Evar _x86_simm (Ty.Tfunction [tulong] tlong cc_default))
              [(Expr.Etempvar _imm tulong)])
            (Stmt.Scall (some _t'4)
              (Expr.Evar _kprog_x86_mem_offset (Ty.Tfunction
                                                 [(tptr (Ty.Tstruct _x86_sim_register_state noattr)),
                                                  (tptr (Ty.Tstruct _kprog_x86_arena noattr)),
                                                  tuint, tulong, tlong] tlong
                                                 cc_default))
              [(Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
               (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr))),
               (Expr.Etempvar _capacity tuint), (Expr.Etempvar _aux tulong),
               (Expr.Etempvar _t'3 tlong)]))
          (Stmt.Sset ___x86_l_disp (Expr.Etempvar _t'4 tlong)))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Scall (some _t'5)
              (Expr.Evar _kprog_x86_xmm0_arm (Ty.Tfunction [tulong] tuchar
                                               cc_default))
              [(Expr.Ebinop Binop.Oeq (Expr.Etempvar _src tulong)
                 (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)])
            (Stmt.Sset ___x86_l_arm
              (Expr.Ecast (Expr.Etempvar _t'5 tuchar) tuchar)))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar _src tulong)
                                  (Expr.Econst_int (Integers.Int.repr 255) tuint)
                                  tint)
                (Stmt.Sset _t'6
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tint)
                    tint))
                (Stmt.Sset _t'6
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                    tint)))
              (Stmt.Sset ___x86_l_base_none
                (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'6 tint) tuchar)
                  tuchar)))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'7
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint)
                    tuint))
                (Stmt.Sset ___x86_l_base_form
                  (Expr.Ecast (Expr.Etempvar _t'7 tuint) tuchar)))
              (Stmt.Sswitch (Expr.Etempvar ___x86_l_arm tuchar)
                (LStmts.LScons (some 0)
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                          (Expr.Ecast
                                            (Expr.Etempvar _src tulong)
                                            tulong)
                                          (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                          tint)
                        (Stmt.Ssequence
                          (Stmt.Sset _t'34
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
                                        (Ty.Tunion __3119 noattr)) _gpr_cells
                                      (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                                    (Expr.Ecast (Expr.Etempvar _src tulong)
                                      tuchar)
                                    (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                                  (Ty.Tstruct _x86_sim_gpr_cell noattr))
                                _value (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                              (tptr tvoid)))
                          (Stmt.Sset _t'8
                            (Expr.Ecast (Expr.Etempvar _t'34 (tptr tvoid))
                              (tptr tvoid))))
                        (Stmt.Sset _t'8
                          (Expr.Ecast
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 0) tint)
                              (tptr tvoid)) (tptr tvoid))))
                      (Stmt.Sset ___x86_l_base_ptr
                        (Expr.Etempvar _t'8 (tptr tvoid))))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Scall (some _t'9)
                          (Expr.Evar _kprog_x86_stack_read (Ty.Tfunction
                                                             [(tptr (Ty.Tstruct _x86_sim_register_state noattr)),
                                                              (tptr (Ty.Tstruct _kprog_x86_arena noattr)),
                                                              tuint, tlong,
                                                              tulong] tulong
                                                             cc_default))
                          [(Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
                           (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr))),
                           (Expr.Etempvar _capacity tuint),
                           (Expr.Ebinop Binop.Oadd
                             (Expr.Ecast
                               (Expr.Ecast
                                 (Expr.Etempvar ___x86_l_base_ptr (tptr tvoid))
                                 tlong) tlong)
                             (Expr.Etempvar ___x86_l_disp tlong) tlong),
                           (Expr.Econst_int (Integers.Int.repr 8) tuint)])
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                              (Ty.Tstruct _x86_sim_register_state noattr))
                            _xmm0_lo tulong) (Expr.Etempvar _t'9 tulong)))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                (Expr.Econst_int (Integers.Int.repr 1) tint)
                                                (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                                tint)
                              s_kprog_x86_load_xmm0_0
                              s_kprog_x86_load_xmm0_1)
                            (Stmt.Scall (some _t'11)
                              (Expr.Evar _kprog_x86_stack_read (Ty.Tfunction
                                                                 [(tptr (Ty.Tstruct _x86_sim_register_state noattr)),
                                                                  (tptr (Ty.Tstruct _kprog_x86_arena noattr)),
                                                                  tuint,
                                                                  tlong,
                                                                  tulong]
                                                                 tulong
                                                                 cc_default))
                              [(Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
                               (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr))),
                               (Expr.Etempvar _capacity tuint),
                               (Expr.Ebinop Binop.Oadd
                                 (Expr.Ebinop Binop.Oadd
                                   (Expr.Ecast
                                     (Expr.Ecast
                                       (Expr.Etempvar ___x86_l_base_ptr (tptr tvoid))
                                       tlong) tlong)
                                   (Expr.Etempvar ___x86_l_disp tlong) tlong)
                                 (Expr.Etempvar _t'10 tuint) tlong),
                               (Expr.Econst_int (Integers.Int.repr 8) tuint)]))
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                (Ty.Tstruct _x86_sim_register_state noattr))
                              _xmm0_hi tulong) (Expr.Etempvar _t'11 tulong)))
                        Stmt.Sbreak)))
                  (LStmts.LScons none
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Etempvar ___x86_l_base_none tuchar)
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Etempvar ___x86_l_base_form tuchar)
                                              (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                              tint)
                            s_kprog_x86_load_xmm0_2
                            s_kprog_x86_load_xmm0_3)
                          (Stmt.Ssequence
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                                (Expr.Ecast
                                                  (Expr.Etempvar _src tulong)
                                                  tulong)
                                                (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                                tint)
                              s_kprog_x86_load_xmm0_4
                              s_kprog_x86_load_xmm0_5)
                            (Stmt.Sset _t'12
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Etempvar _t'14 (tptr tvoid))
                                  (tptr tvoid)) (tptr tvoid)))))
                        (Stmt.Sset ___x86_l_base_ptr__1
                          (Expr.Etempvar _t'12 (tptr tvoid))))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                (Expr.Etempvar ___x86_l_base_form tuchar)
                                                (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                                tint)
                              s_kprog_x86_load_xmm0_6
                              s_kprog_x86_load_xmm0_7)
                            (Stmt.Sifthenelse (Expr.Etempvar _t'15 tuint)
                              (Stmt.Sset _t'16
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Ecast
                                      (Expr.Ebinop Binop.Oadd
                                        (Expr.Ecast
                                          (Expr.Ecast
                                            (Expr.Etempvar ___x86_l_base_ptr__1 (tptr tvoid))
                                            tulong) tulong)
                                        (Expr.Ecast
                                          (Expr.Etempvar ___x86_l_disp tlong)
                                          tulong) tulong) tulong)
                                    (tptr tuchar)) (tptr tvoid)))
                              (Stmt.Sset _t'16
                                (Expr.Ecast
                                  (Expr.Etempvar ___x86_l_base_ptr__1 (tptr tvoid))
                                  (tptr tvoid)))))
                          (Stmt.Sset ___x86_l_addr
                            (Expr.Etempvar _t'16 (tptr tvoid))))
                        (Stmt.Ssequence
                          (Stmt.Sloop
                            (Stmt.Ssequence
                              (Stmt.Ssequence
                                s_kprog_x86_load_xmm0_8
                                (Stmt.Sset ___x86_alias_observed
                                  (Expr.Etempvar _t'17 tulong)))
                              (Stmt.Ssequence
                                s_kprog_x86_load_xmm0_9
                                s_kprog_x86_load_xmm0_10))
                            Stmt.Sbreak)
                          (Stmt.Ssequence
                            (Stmt.Sloop
                              (Stmt.Ssequence
                                s_kprog_x86_load_xmm0_11
                                s_kprog_x86_load_xmm0_12)
                              Stmt.Sbreak)
                            Stmt.Sbreak))))
                    LStmts.LSnil))))))))
    Stmt.Sbreak))
}

def s_kprog_x86_store_xmm0_0 : Stmt :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'8)
    (Expr.Evar _x86_width_effective (Ty.Tfunction [tuchar] tuchar cc_default))
    [(Expr.Econst_int (Integers.Int.repr 8) tuint)])
  (Stmt.Sset ___x86_sv_width (Expr.Ecast (Expr.Etempvar _t'8 tuchar) tulong)))

def s_kprog_x86_store_xmm0_1 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_sv_i (Expr.Econst_int (Integers.Int.repr 0) tint))
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                          (Expr.Etempvar ___x86_sv_i tuint)
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
        (Stmt.Ssequence
          (Stmt.Sset ___x86_sv_start
            (Expr.Ebinop Binop.Omul
              (Expr.Ecast (Expr.Etempvar ___x86_sv_i tuint) tulong)
              (Expr.Econst_int (Integers.Int.repr 8) tuint) tulong))
          (Stmt.Ssequence
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                (Expr.Ebinop Binop.Osub
                                  (Expr.Etempvar ___x86_sv_index tulong)
                                  (Expr.Etempvar ___x86_sv_start tulong)
                                  tulong)
                                (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                tint)
              (Stmt.Sset _t'9 (Expr.Econst_int (Integers.Int.repr 1) tint))
              (Stmt.Sset _t'9
                (Expr.Ecast
                  (Expr.Ebinop Binop.Olt
                    (Expr.Ebinop Binop.Osub
                      (Expr.Etempvar ___x86_sv_start tulong)
                      (Expr.Etempvar ___x86_sv_index tulong) tulong)
                    (Expr.Etempvar ___x86_sv_width tulong) tint) tbool)))
            (Stmt.Sifthenelse (Expr.Etempvar _t'9 tint)
              (Stmt.Sloop
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sset _t'144
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                            (Expr.Etempvar ___x86_sv_i tuint)
                            (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                          (Ty.Tstruct _kprog_x86_stack_fact noattr)) _tag
                        (tptr tuchar)))
                    (Stmt.Sassign
                      (Expr.Ederef (Expr.Etempvar _t'144 (tptr tuchar))
                        tuchar)
                      (Expr.Econst_int (Integers.Int.repr 0) tuint)))
                  (Stmt.Ssequence
                    (Stmt.Sset _t'143
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                            (Expr.Etempvar ___x86_sv_i tuint)
                            (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                          (Ty.Tstruct _kprog_x86_stack_fact noattr)) _pointer
                        (tptr (tptr tvoid))))
                    (Stmt.Sassign
                      (Expr.Ederef (Expr.Etempvar _t'143 (tptr (tptr tvoid)))
                        (tptr tvoid))
                      (Expr.Econst_int (Integers.Int.repr 0) tint))))
                Stmt.Sbreak)
              Stmt.Sskip)))
        Stmt.Sbreak))
    (Stmt.Sset ___x86_sv_i
      (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_sv_i tuint)
        (Expr.Econst_int (Integers.Int.repr 1) tint) tuint))))

def s_kprog_x86_store_xmm0_2 : Stmt :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'10)
    (Expr.Evar _x86_width_effective (Ty.Tfunction [tuchar] tuchar cc_default))
    [(Expr.Econst_int (Integers.Int.repr 8) tuint)])
  (Stmt.Sset ___x86_loss_width
    (Expr.Ecast (Expr.Etempvar _t'10 tuchar) tuchar)))

def s_kprog_x86_store_xmm0_3 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                    (Expr.Etempvar ___x86_stw_width tuchar)
                    (Expr.Econst_int (Integers.Int.repr 1) tuint) tint)
  (Stmt.Sset _t'13
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Etempvar ___x86_stw_width tuchar)
                      (Expr.Econst_int (Integers.Int.repr 2) tuint) tint)
    (Stmt.Ssequence
      (Stmt.Sset _t'13
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))
      (Stmt.Sset _t'13 (Expr.Ecast (Expr.Etempvar _t'13 tuint) tuint)))
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                        (Expr.Etempvar ___x86_stw_width tuchar)
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
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 255) tuint)
              tuint))
          (Stmt.Sset _t'13 (Expr.Ecast (Expr.Etempvar _t'13 tuint) tuint)))
        (Stmt.Sset _t'13 (Expr.Ecast (Expr.Etempvar _t'13 tuint) tuint))))))

def s_kprog_x86_store_xmm0_4 : Stmt :=
(Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
  [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
  [(Expr.Eaddrof
     (Expr.Ederef
       (Expr.Ebinop Binop.Oadd
         (Expr.Etempvar ___x86_stw_bytes (tptr (tvolatile tuchar)))
         (Expr.Econst_int (Integers.Int.repr 1) tint)
         (tptr (tvolatile tuchar))) (tvolatile tuchar))
     (tptr (tvolatile tuchar))),
   (Expr.Ecast
     (Expr.Ebinop Binop.Oshr
       (Expr.Ecast (Expr.Etempvar ___x86_stw_narrowed tulong) tulong)
       (Expr.Ebinop Binop.Omul (Expr.Econst_int (Integers.Int.repr 8) tuint)
         (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tint) tuint)
         tuint) tulong) tuchar)])

def s_kprog_x86_store_xmm0_5 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Etempvar ___x86_stw_width tuchar)
                      (Expr.Econst_int (Integers.Int.repr 1) tuint) tint)
    (Stmt.Sset _t'14
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                        (Expr.Etempvar ___x86_stw_width tuchar)
                        (Expr.Econst_int (Integers.Int.repr 2) tuint) tint)
      (Stmt.Ssequence
        (Stmt.Sset _t'14
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))
        (Stmt.Sset _t'14 (Expr.Ecast (Expr.Etempvar _t'14 tuint) tuint)))
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                          (Expr.Etempvar ___x86_stw_width tuchar)
                          (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sset _t'14
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 15) tuint)
                tuint))
            (Stmt.Sset _t'14 (Expr.Ecast (Expr.Etempvar _t'14 tuint) tuint)))
          (Stmt.Sset _t'14 (Expr.Ecast (Expr.Etempvar _t'14 tuint) tuint)))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sset _t'14
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 255) tuint)
                tuint))
            (Stmt.Sset _t'14 (Expr.Ecast (Expr.Etempvar _t'14 tuint) tuint)))
          (Stmt.Sset _t'14 (Expr.Ecast (Expr.Etempvar _t'14 tuint) tuint))))))
  (Stmt.Sifthenelse (Expr.Ecast
                      (Expr.Ebinop Binop.Oand
                        (Expr.Ebinop Binop.Oshr (Expr.Etempvar _t'14 tuint)
                          (Expr.Econst_int (Integers.Int.repr 2) tint) tuint)
                        (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint)
                      tuchar)
    (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
      [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
      [(Expr.Eaddrof
         (Expr.Ederef
           (Expr.Ebinop Binop.Oadd
             (Expr.Etempvar ___x86_stw_bytes (tptr (tvolatile tuchar)))
             (Expr.Econst_int (Integers.Int.repr 2) tint)
             (tptr (tvolatile tuchar))) (tvolatile tuchar))
         (tptr (tvolatile tuchar))),
       (Expr.Ecast
         (Expr.Ebinop Binop.Oshr
           (Expr.Ecast (Expr.Etempvar ___x86_stw_narrowed tulong) tulong)
           (Expr.Ebinop Binop.Omul
             (Expr.Econst_int (Integers.Int.repr 8) tuint)
             (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tint) tuint)
             tuint) tulong) tuchar)])
    Stmt.Sskip))

def s_kprog_x86_store_xmm0_6 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                        (Expr.Etempvar ___x86_stw_width tuchar)
                        (Expr.Econst_int (Integers.Int.repr 1) tuint) tint)
      (Stmt.Sset _t'15
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                          (Expr.Etempvar ___x86_stw_width tuchar)
                          (Expr.Econst_int (Integers.Int.repr 2) tuint) tint)
        (Stmt.Ssequence
          (Stmt.Sset _t'15
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))
          (Stmt.Sset _t'15 (Expr.Ecast (Expr.Etempvar _t'15 tuint) tuint)))
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar ___x86_stw_width tuchar)
                            (Expr.Econst_int (Integers.Int.repr 4) tuint)
                            tint)
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sset _t'15
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 15) tuint)
                  tuint))
              (Stmt.Sset _t'15
                (Expr.Ecast (Expr.Etempvar _t'15 tuint) tuint)))
            (Stmt.Sset _t'15 (Expr.Ecast (Expr.Etempvar _t'15 tuint) tuint)))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sset _t'15
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 255) tuint)
                  tuint))
              (Stmt.Sset _t'15
                (Expr.Ecast (Expr.Etempvar _t'15 tuint) tuint)))
            (Stmt.Sset _t'15 (Expr.Ecast (Expr.Etempvar _t'15 tuint) tuint))))))
    (Stmt.Sifthenelse (Expr.Ecast
                        (Expr.Ebinop Binop.Oand
                          (Expr.Ebinop Binop.Oshr (Expr.Etempvar _t'15 tuint)
                            (Expr.Econst_int (Integers.Int.repr 3) tint)
                            tuint)
                          (Expr.Econst_int (Integers.Int.repr 1) tuint)
                          tuint) tuchar)
      (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
        [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
        [(Expr.Eaddrof
           (Expr.Ederef
             (Expr.Ebinop Binop.Oadd
               (Expr.Etempvar ___x86_stw_bytes (tptr (tvolatile tuchar)))
               (Expr.Econst_int (Integers.Int.repr 3) tint)
               (tptr (tvolatile tuchar))) (tvolatile tuchar))
           (tptr (tvolatile tuchar))),
         (Expr.Ecast
           (Expr.Ebinop Binop.Oshr
             (Expr.Ecast (Expr.Etempvar ___x86_stw_narrowed tulong) tulong)
             (Expr.Ebinop Binop.Omul
               (Expr.Econst_int (Integers.Int.repr 8) tuint)
               (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tint)
                 tuint) tuint) tulong) tuchar)])
      Stmt.Sskip))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                          (Expr.Etempvar ___x86_stw_width tuchar)
                          (Expr.Econst_int (Integers.Int.repr 1) tuint) tint)
        (Stmt.Sset _t'16
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar ___x86_stw_width tuchar)
                            (Expr.Econst_int (Integers.Int.repr 2) tuint)
                            tint)
          (Stmt.Ssequence
            (Stmt.Sset _t'16
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint)
                tuint))
            (Stmt.Sset _t'16 (Expr.Ecast (Expr.Etempvar _t'16 tuint) tuint)))
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar ___x86_stw_width tuchar)
                              (Expr.Econst_int (Integers.Int.repr 4) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'16
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 15) tuint)
                    tuint))
                (Stmt.Sset _t'16
                  (Expr.Ecast (Expr.Etempvar _t'16 tuint) tuint)))
              (Stmt.Sset _t'16
                (Expr.Ecast (Expr.Etempvar _t'16 tuint) tuint)))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'16
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 255) tuint)
                    tuint))
                (Stmt.Sset _t'16
                  (Expr.Ecast (Expr.Etempvar _t'16 tuint) tuint)))
              (Stmt.Sset _t'16
                (Expr.Ecast (Expr.Etempvar _t'16 tuint) tuint))))))
      (Stmt.Sifthenelse (Expr.Ecast
                          (Expr.Ebinop Binop.Oand
                            (Expr.Ebinop Binop.Oshr
                              (Expr.Etempvar _t'16 tuint)
                              (Expr.Econst_int (Integers.Int.repr 4) tint)
                              tuint)
                            (Expr.Econst_int (Integers.Int.repr 1) tuint)
                            tuint) tuchar)
        (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
          [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
          [(Expr.Eaddrof
             (Expr.Ederef
               (Expr.Ebinop Binop.Oadd
                 (Expr.Etempvar ___x86_stw_bytes (tptr (tvolatile tuchar)))
                 (Expr.Econst_int (Integers.Int.repr 4) tint)
                 (tptr (tvolatile tuchar))) (tvolatile tuchar))
             (tptr (tvolatile tuchar))),
           (Expr.Ecast
             (Expr.Ebinop Binop.Oshr
               (Expr.Ecast (Expr.Etempvar ___x86_stw_narrowed tulong) tulong)
               (Expr.Ebinop Binop.Omul
                 (Expr.Econst_int (Integers.Int.repr 8) tuint)
                 (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 4) tint)
                   tuint) tuint) tulong) tuchar)])
        Stmt.Sskip))
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar ___x86_stw_width tuchar)
                            (Expr.Econst_int (Integers.Int.repr 1) tuint)
                            tint)
          (Stmt.Sset _t'17
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar ___x86_stw_width tuchar)
                              (Expr.Econst_int (Integers.Int.repr 2) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Sset _t'17
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint)
                  tuint))
              (Stmt.Sset _t'17
                (Expr.Ecast (Expr.Etempvar _t'17 tuint) tuint)))
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Etempvar ___x86_stw_width tuchar)
                                (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                tint)
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sset _t'17
                    (Expr.Ecast
                      (Expr.Econst_int (Integers.Int.repr 15) tuint) tuint))
                  (Stmt.Sset _t'17
                    (Expr.Ecast (Expr.Etempvar _t'17 tuint) tuint)))
                (Stmt.Sset _t'17
                  (Expr.Ecast (Expr.Etempvar _t'17 tuint) tuint)))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sset _t'17
                    (Expr.Ecast
                      (Expr.Econst_int (Integers.Int.repr 255) tuint) tuint))
                  (Stmt.Sset _t'17
                    (Expr.Ecast (Expr.Etempvar _t'17 tuint) tuint)))
                (Stmt.Sset _t'17
                  (Expr.Ecast (Expr.Etempvar _t'17 tuint) tuint))))))
        (Stmt.Sifthenelse (Expr.Ecast
                            (Expr.Ebinop Binop.Oand
                              (Expr.Ebinop Binop.Oshr
                                (Expr.Etempvar _t'17 tuint)
                                (Expr.Econst_int (Integers.Int.repr 5) tint)
                                tuint)
                              (Expr.Econst_int (Integers.Int.repr 1) tuint)
                              tuint) tuchar)
          (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
            [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
            [(Expr.Eaddrof
               (Expr.Ederef
                 (Expr.Ebinop Binop.Oadd
                   (Expr.Etempvar ___x86_stw_bytes (tptr (tvolatile tuchar)))
                   (Expr.Econst_int (Integers.Int.repr 5) tint)
                   (tptr (tvolatile tuchar))) (tvolatile tuchar))
               (tptr (tvolatile tuchar))),
             (Expr.Ecast
               (Expr.Ebinop Binop.Oshr
                 (Expr.Ecast (Expr.Etempvar ___x86_stw_narrowed tulong)
                   tulong)
                 (Expr.Ebinop Binop.Omul
                   (Expr.Econst_int (Integers.Int.repr 8) tuint)
                   (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 5) tint)
                     tuint) tuint) tulong) tuchar)])
          Stmt.Sskip))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar ___x86_stw_width tuchar)
                              (Expr.Econst_int (Integers.Int.repr 1) tuint)
                              tint)
            (Stmt.Sset _t'18
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint)
                tuint))
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Etempvar ___x86_stw_width tuchar)
                                (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                tint)
              (Stmt.Ssequence
                (Stmt.Sset _t'18
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint)
                    tuint))
                (Stmt.Sset _t'18
                  (Expr.Ecast (Expr.Etempvar _t'18 tuint) tuint)))
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar ___x86_stw_width tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                  tint)
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sset _t'18
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 15) tuint) tuint))
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
                                  (Expr.Econst_int (Integers.Int.repr 6) tint)
                                  tuint)
                                (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                tuint) tuchar)
            (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
              [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
              [(Expr.Eaddrof
                 (Expr.Ederef
                   (Expr.Ebinop Binop.Oadd
                     (Expr.Etempvar ___x86_stw_bytes (tptr (tvolatile tuchar)))
                     (Expr.Econst_int (Integers.Int.repr 6) tint)
                     (tptr (tvolatile tuchar))) (tvolatile tuchar))
                 (tptr (tvolatile tuchar))),
               (Expr.Ecast
                 (Expr.Ebinop Binop.Oshr
                   (Expr.Ecast (Expr.Etempvar ___x86_stw_narrowed tulong)
                     tulong)
                   (Expr.Ebinop Binop.Omul
                     (Expr.Econst_int (Integers.Int.repr 8) tuint)
                     (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 6) tint)
                       tuint) tuint) tulong) tuchar)])
            Stmt.Sskip))
        (Stmt.Ssequence
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar ___x86_stw_width tuchar)
                              (Expr.Econst_int (Integers.Int.repr 1) tuint)
                              tint)
            (Stmt.Sset _t'19
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint)
                tuint))
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Etempvar ___x86_stw_width tuchar)
                                (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                tint)
              (Stmt.Ssequence
                (Stmt.Sset _t'19
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint)
                    tuint))
                (Stmt.Sset _t'19
                  (Expr.Ecast (Expr.Etempvar _t'19 tuint) tuint)))
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar ___x86_stw_width tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                  tint)
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sset _t'19
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 15) tuint) tuint))
                    (Stmt.Sset _t'19
                      (Expr.Ecast (Expr.Etempvar _t'19 tuint) tuint)))
                  (Stmt.Sset _t'19
                    (Expr.Ecast (Expr.Etempvar _t'19 tuint) tuint)))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sset _t'19
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 255) tuint)
                        tuint))
                    (Stmt.Sset _t'19
                      (Expr.Ecast (Expr.Etempvar _t'19 tuint) tuint)))
                  (Stmt.Sset _t'19
                    (Expr.Ecast (Expr.Etempvar _t'19 tuint) tuint))))))
          (Stmt.Sifthenelse (Expr.Ecast
                              (Expr.Ebinop Binop.Oand
                                (Expr.Ebinop Binop.Oshr
                                  (Expr.Etempvar _t'19 tuint)
                                  (Expr.Econst_int (Integers.Int.repr 7) tint)
                                  tuint)
                                (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                tuint) tuchar)
            (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
              [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
              [(Expr.Eaddrof
                 (Expr.Ederef
                   (Expr.Ebinop Binop.Oadd
                     (Expr.Etempvar ___x86_stw_bytes (tptr (tvolatile tuchar)))
                     (Expr.Econst_int (Integers.Int.repr 7) tint)
                     (tptr (tvolatile tuchar))) (tvolatile tuchar))
                 (tptr (tvolatile tuchar))),
               (Expr.Ecast
                 (Expr.Ebinop Binop.Oshr
                   (Expr.Ecast (Expr.Etempvar ___x86_stw_narrowed tulong)
                     tulong)
                   (Expr.Ebinop Binop.Omul
                     (Expr.Econst_int (Integers.Int.repr 8) tuint)
                     (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 7) tint)
                       tuint) tuint) tulong) tuchar)])
            Stmt.Sskip))))))

def s_kprog_x86_store_xmm0_7 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'45
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tint) tint))
  (Stmt.Sset _t'45 (Expr.Ecast (Expr.Etempvar _t'45 tint) tbool)))

def s_kprog_x86_store_xmm0_8 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'45
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) tint))
  (Stmt.Sset _t'45 (Expr.Ecast (Expr.Etempvar _t'45 tint) tbool)))

def s_kprog_x86_store_xmm0_9 : Stmt :=
(Stmt.Sset _t'43
  (Expr.Ecast
    (Expr.Ebinop Binop.Oeq
      (Expr.Ebinop Binop.Oand (Expr.Etempvar ___x86_stw_index__1 tulong)
        (Expr.Econst_int (Integers.Int.repr 3) tuint) tulong)
      (Expr.Econst_int (Integers.Int.repr 0) tint) tint) tbool))

def s_kprog_x86_store_xmm0_10 : Stmt :=
(Stmt.Scall (some _t'28)
  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong cc_default))
  [(Expr.Econst_int (Integers.Int.repr 6) tint)])

def s_kprog_x86_store_xmm0_11 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'136
    (Expr.Efield
      (Expr.Ederef
        (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
        (Ty.Tstruct _kprog_x86_arena noattr)) _d (tptr (tvolatile tuint))))
  (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint32)
    [(tptr (tvolatile tuint)), (tvolatile tuint)]
    [(Expr.Eaddrof
       (Expr.Ederef
         (Expr.Ebinop Binop.Oadd
           (Expr.Etempvar _t'136 (tptr (tvolatile tuint)))
           (Expr.Ebinop Binop.Odiv (Expr.Etempvar ___x86_stw_index__1 tulong)
             (Expr.Econst_int (Integers.Int.repr 4) tuint) tulong)
           (tptr (tvolatile tuint))) (tvolatile tuint))
       (tptr (tvolatile tuint))), (Expr.Etempvar _t'28 tulong)]))

def s_kprog_x86_store_xmm0_12 : Stmt :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'40)
    (Expr.Evar _x86_width_effective (Ty.Tfunction [tuchar] tuchar cc_default))
    [(Expr.Econst_int (Integers.Int.repr 1) tuint)])
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _t'40 tuchar)
                      (Expr.Econst_int (Integers.Int.repr 2) tuint) tint)
    (Stmt.Sset _t'41
      (Expr.Ecast
        (Expr.Ebinop Binop.Oeq
          (Expr.Ebinop Binop.Oand (Expr.Etempvar ___x86_stw_index__1 tulong)
            (Expr.Econst_int (Integers.Int.repr 1) tuint) tulong)
          (Expr.Econst_int (Integers.Int.repr 0) tint) tint) tbool))
    (Stmt.Sset _t'41 (Expr.Econst_int (Integers.Int.repr 0) tint))))

def s_kprog_x86_store_xmm0_13 : Stmt :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'29)
    (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                         cc_default))
    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
  (Stmt.Ssequence
    (Stmt.Sset _t'135
      (Expr.Efield
        (Expr.Ederef
          (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
          (Ty.Tstruct _kprog_x86_arena noattr)) _w
        (tptr (tvolatile tushort))))
    (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint16unsigned)
      [(tptr (tvolatile tushort)), (tvolatile tushort)]
      [(Expr.Eaddrof
         (Expr.Ederef
           (Expr.Ebinop Binop.Oadd
             (Expr.Etempvar _t'135 (tptr (tvolatile tushort)))
             (Expr.Ebinop Binop.Odiv
               (Expr.Etempvar ___x86_stw_index__1 tulong)
               (Expr.Econst_int (Integers.Int.repr 2) tuint) tulong)
             (tptr (tvolatile tushort))) (tvolatile tushort))
         (tptr (tvolatile tushort))), (Expr.Etempvar _t'29 tulong)])))

def s_kprog_x86_store_xmm0_14 : Stmt :=
(Stmt.Sset _t'36
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 15) tuint) tuint))

def s_kprog_x86_store_xmm0_15 : Stmt :=
(Stmt.Sset _t'36
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 255) tuint) tuint))

def s_kprog_x86_store_xmm0_16 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'37
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 15) tuint) tuint))
  (Stmt.Sset _t'37 (Expr.Ecast (Expr.Etempvar _t'37 tuint) tuint)))

def s_kprog_x86_store_xmm0_17 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'37
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 255) tuint) tuint))
  (Stmt.Sset _t'37 (Expr.Ecast (Expr.Etempvar _t'37 tuint) tuint)))

def s_kprog_x86_store_xmm0_18 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'38
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 15) tuint) tuint))
    (Stmt.Sset _t'38 (Expr.Ecast (Expr.Etempvar _t'38 tuint) tuint)))
  (Stmt.Sset _t'38 (Expr.Ecast (Expr.Etempvar _t'38 tuint) tuint)))

def s_kprog_x86_store_xmm0_19 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'38
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 255) tuint) tuint))
    (Stmt.Sset _t'38 (Expr.Ecast (Expr.Etempvar _t'38 tuint) tuint)))
  (Stmt.Sset _t'38 (Expr.Ecast (Expr.Etempvar _t'38 tuint) tuint)))

def s_kprog_x86_store_xmm0_20 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'39
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 15) tuint) tuint))
    (Stmt.Sset _t'39 (Expr.Ecast (Expr.Etempvar _t'39 tuint) tuint)))
  (Stmt.Sset _t'39 (Expr.Ecast (Expr.Etempvar _t'39 tuint) tuint)))

def s_kprog_x86_store_xmm0_21 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'39
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 255) tuint) tuint))
    (Stmt.Sset _t'39 (Expr.Ecast (Expr.Etempvar _t'39 tuint) tuint)))
  (Stmt.Sset _t'39 (Expr.Ecast (Expr.Etempvar _t'39 tuint) tuint)))

def s_kprog_x86_store_xmm0_22 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'134
      (Expr.Efield
        (Expr.Ederef
          (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
          (Ty.Tstruct _kprog_x86_arena noattr)) _b (tptr (tvolatile tuchar))))
    (Stmt.Sset ___x86_stw_bytes__1
      (Expr.Ebinop Binop.Oadd
        (Expr.Etempvar _t'134 (tptr (tvolatile tuchar)))
        (Expr.Etempvar ___x86_stw_index__1 tulong) (tptr (tvolatile tuchar)))))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Scall (some _t'30)
        (Expr.Evar _x86_width_effective (Ty.Tfunction [tuchar] tuchar
                                          cc_default))
        [(Expr.Econst_int (Integers.Int.repr 1) tuint)])
      (Stmt.Sset ___x86_stw_width__1
        (Expr.Ecast (Expr.Etempvar _t'30 tuchar) tuchar)))
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Scall (some _t'31)
            (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                 cc_default))
            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
          (Stmt.Scall (some _t'32)
            (Expr.Evar _x86_width_mask (Ty.Tfunction [tuchar] tulong
                                         cc_default))
            [(Expr.Etempvar ___x86_stw_width__1 tuchar)]))
        (Stmt.Sset ___x86_stw_narrowed__1
          (Expr.Ebinop Binop.Oand (Expr.Etempvar _t'31 tulong)
            (Expr.Etempvar _t'32 tulong) tulong)))
      (Stmt.Ssequence
        (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
          [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
          [(Expr.Eaddrof
             (Expr.Ederef
               (Expr.Ebinop Binop.Oadd
                 (Expr.Etempvar ___x86_stw_bytes__1 (tptr (tvolatile tuchar)))
                 (Expr.Econst_int (Integers.Int.repr 0) tint)
                 (tptr (tvolatile tuchar))) (tvolatile tuchar))
             (tptr (tvolatile tuchar))),
           (Expr.Ecast
             (Expr.Ebinop Binop.Oshr
               (Expr.Ecast (Expr.Etempvar ___x86_stw_narrowed__1 tulong)
                 tulong)
               (Expr.Ebinop Binop.Omul
                 (Expr.Econst_int (Integers.Int.repr 8) tuint)
                 (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                   tuint) tuint) tulong) tuchar)])
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Etempvar ___x86_stw_width__1 tuchar)
                                (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                tint)
              (Stmt.Sset _t'33
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint)
                  tuint))
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar ___x86_stw_width__1 tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                  tint)
                (Stmt.Ssequence
                  (Stmt.Sset _t'33
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint)
                      tuint))
                  (Stmt.Sset _t'33
                    (Expr.Ecast (Expr.Etempvar _t'33 tuint) tuint)))
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Etempvar ___x86_stw_width__1 tuchar)
                                    (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                    tint)
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sset _t'33
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 15) tuint)
                          tuint))
                      (Stmt.Sset _t'33
                        (Expr.Ecast (Expr.Etempvar _t'33 tuint) tuint)))
                    (Stmt.Sset _t'33
                      (Expr.Ecast (Expr.Etempvar _t'33 tuint) tuint)))
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sset _t'33
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 255) tuint)
                          tuint))
                      (Stmt.Sset _t'33
                        (Expr.Ecast (Expr.Etempvar _t'33 tuint) tuint)))
                    (Stmt.Sset _t'33
                      (Expr.Ecast (Expr.Etempvar _t'33 tuint) tuint))))))
            (Stmt.Sifthenelse (Expr.Ecast
                                (Expr.Ebinop Binop.Oand
                                  (Expr.Ebinop Binop.Oshr
                                    (Expr.Etempvar _t'33 tuint)
                                    (Expr.Econst_int (Integers.Int.repr 1) tint)
                                    tuint)
                                  (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                  tuint) tuchar)
              (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
                [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
                [(Expr.Eaddrof
                   (Expr.Ederef
                     (Expr.Ebinop Binop.Oadd
                       (Expr.Etempvar ___x86_stw_bytes__1 (tptr (tvolatile tuchar)))
                       (Expr.Econst_int (Integers.Int.repr 1) tint)
                       (tptr (tvolatile tuchar))) (tvolatile tuchar))
                   (tptr (tvolatile tuchar))),
                 (Expr.Ecast
                   (Expr.Ebinop Binop.Oshr
                     (Expr.Ecast
                       (Expr.Etempvar ___x86_stw_narrowed__1 tulong) tulong)
                     (Expr.Ebinop Binop.Omul
                       (Expr.Econst_int (Integers.Int.repr 8) tuint)
                       (Expr.Ecast
                         (Expr.Econst_int (Integers.Int.repr 1) tint) tuint)
                       tuint) tulong) tuchar)])
              Stmt.Sskip))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar ___x86_stw_width__1 tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                  tint)
                (Stmt.Sset _t'34
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint)
                    tuint))
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Etempvar ___x86_stw_width__1 tuchar)
                                    (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                    tint)
                  (Stmt.Ssequence
                    (Stmt.Sset _t'34
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))
                    (Stmt.Sset _t'34
                      (Expr.Ecast (Expr.Etempvar _t'34 tuint) tuint)))
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar ___x86_stw_width__1 tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sset _t'34
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 15) tuint)
                            tuint))
                        (Stmt.Sset _t'34
                          (Expr.Ecast (Expr.Etempvar _t'34 tuint) tuint)))
                      (Stmt.Sset _t'34
                        (Expr.Ecast (Expr.Etempvar _t'34 tuint) tuint)))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sset _t'34
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 255) tuint)
                            tuint))
                        (Stmt.Sset _t'34
                          (Expr.Ecast (Expr.Etempvar _t'34 tuint) tuint)))
                      (Stmt.Sset _t'34
                        (Expr.Ecast (Expr.Etempvar _t'34 tuint) tuint))))))
              (Stmt.Sifthenelse (Expr.Ecast
                                  (Expr.Ebinop Binop.Oand
                                    (Expr.Ebinop Binop.Oshr
                                      (Expr.Etempvar _t'34 tuint)
                                      (Expr.Econst_int (Integers.Int.repr 2) tint)
                                      tuint)
                                    (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                    tuint) tuchar)
                (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
                  [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
                  [(Expr.Eaddrof
                     (Expr.Ederef
                       (Expr.Ebinop Binop.Oadd
                         (Expr.Etempvar ___x86_stw_bytes__1 (tptr (tvolatile tuchar)))
                         (Expr.Econst_int (Integers.Int.repr 2) tint)
                         (tptr (tvolatile tuchar))) (tvolatile tuchar))
                     (tptr (tvolatile tuchar))),
                   (Expr.Ecast
                     (Expr.Ebinop Binop.Oshr
                       (Expr.Ecast
                         (Expr.Etempvar ___x86_stw_narrowed__1 tulong)
                         tulong)
                       (Expr.Ebinop Binop.Omul
                         (Expr.Econst_int (Integers.Int.repr 8) tuint)
                         (Expr.Ecast
                           (Expr.Econst_int (Integers.Int.repr 2) tint)
                           tuint) tuint) tulong) tuchar)])
                Stmt.Sskip))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Etempvar ___x86_stw_width__1 tuchar)
                                    (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                    tint)
                  (Stmt.Sset _t'35
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint)
                      tuint))
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar ___x86_stw_width__1 tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Sset _t'35
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 3) tuint)
                          tuint))
                      (Stmt.Sset _t'35
                        (Expr.Ecast (Expr.Etempvar _t'35 tuint) tuint)))
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Etempvar ___x86_stw_width__1 tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                        tint)
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sset _t'35
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 15) tuint)
                              tuint))
                          (Stmt.Sset _t'35
                            (Expr.Ecast (Expr.Etempvar _t'35 tuint) tuint)))
                        (Stmt.Sset _t'35
                          (Expr.Ecast (Expr.Etempvar _t'35 tuint) tuint)))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sset _t'35
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 255) tuint)
                              tuint))
                          (Stmt.Sset _t'35
                            (Expr.Ecast (Expr.Etempvar _t'35 tuint) tuint)))
                        (Stmt.Sset _t'35
                          (Expr.Ecast (Expr.Etempvar _t'35 tuint) tuint))))))
                (Stmt.Sifthenelse (Expr.Ecast
                                    (Expr.Ebinop Binop.Oand
                                      (Expr.Ebinop Binop.Oshr
                                        (Expr.Etempvar _t'35 tuint)
                                        (Expr.Econst_int (Integers.Int.repr 3) tint)
                                        tuint)
                                      (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                      tuint) tuchar)
                  (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
                    [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
                    [(Expr.Eaddrof
                       (Expr.Ederef
                         (Expr.Ebinop Binop.Oadd
                           (Expr.Etempvar ___x86_stw_bytes__1 (tptr (tvolatile tuchar)))
                           (Expr.Econst_int (Integers.Int.repr 3) tint)
                           (tptr (tvolatile tuchar))) (tvolatile tuchar))
                       (tptr (tvolatile tuchar))),
                     (Expr.Ecast
                       (Expr.Ebinop Binop.Oshr
                         (Expr.Ecast
                           (Expr.Etempvar ___x86_stw_narrowed__1 tulong)
                           tulong)
                         (Expr.Ebinop Binop.Omul
                           (Expr.Econst_int (Integers.Int.repr 8) tuint)
                           (Expr.Ecast
                             (Expr.Econst_int (Integers.Int.repr 3) tint)
                             tuint) tuint) tulong) tuchar)])
                  Stmt.Sskip))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar ___x86_stw_width__1 tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                      tint)
                    (Stmt.Sset _t'36
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Etempvar ___x86_stw_width__1 tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                        tint)
                      (Stmt.Ssequence
                        (Stmt.Sset _t'36
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 3) tuint)
                            tuint))
                        (Stmt.Sset _t'36
                          (Expr.Ecast (Expr.Etempvar _t'36 tuint) tuint)))
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Etempvar ___x86_stw_width__1 tuchar)
                                          (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                          tint)
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            s_kprog_x86_store_xmm0_14
                            (Stmt.Sset _t'36
                              (Expr.Ecast (Expr.Etempvar _t'36 tuint) tuint)))
                          (Stmt.Sset _t'36
                            (Expr.Ecast (Expr.Etempvar _t'36 tuint) tuint)))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            s_kprog_x86_store_xmm0_15
                            (Stmt.Sset _t'36
                              (Expr.Ecast (Expr.Etempvar _t'36 tuint) tuint)))
                          (Stmt.Sset _t'36
                            (Expr.Ecast (Expr.Etempvar _t'36 tuint) tuint))))))
                  (Stmt.Sifthenelse (Expr.Ecast
                                      (Expr.Ebinop Binop.Oand
                                        (Expr.Ebinop Binop.Oshr
                                          (Expr.Etempvar _t'36 tuint)
                                          (Expr.Econst_int (Integers.Int.repr 4) tint)
                                          tuint)
                                        (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                        tuint) tuchar)
                    (Stmt.Sbuiltin none
                      (ExtFun.EF_vstore Chunk.Mint8unsigned)
                      [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
                      [(Expr.Eaddrof
                         (Expr.Ederef
                           (Expr.Ebinop Binop.Oadd
                             (Expr.Etempvar ___x86_stw_bytes__1 (tptr (tvolatile tuchar)))
                             (Expr.Econst_int (Integers.Int.repr 4) tint)
                             (tptr (tvolatile tuchar))) (tvolatile tuchar))
                         (tptr (tvolatile tuchar))),
                       (Expr.Ecast
                         (Expr.Ebinop Binop.Oshr
                           (Expr.Ecast
                             (Expr.Etempvar ___x86_stw_narrowed__1 tulong)
                             tulong)
                           (Expr.Ebinop Binop.Omul
                             (Expr.Econst_int (Integers.Int.repr 8) tuint)
                             (Expr.Ecast
                               (Expr.Econst_int (Integers.Int.repr 4) tint)
                               tuint) tuint) tulong) tuchar)])
                    Stmt.Sskip))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Etempvar ___x86_stw_width__1 tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                        tint)
                      (Stmt.Sset _t'37
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 1) tuint)
                          tuint))
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Etempvar ___x86_stw_width__1 tuchar)
                                          (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                          tint)
                        (Stmt.Ssequence
                          (Stmt.Sset _t'37
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 3) tuint)
                              tuint))
                          (Stmt.Sset _t'37
                            (Expr.Ecast (Expr.Etempvar _t'37 tuint) tuint)))
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Etempvar ___x86_stw_width__1 tuchar)
                                            (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                            tint)
                          (Stmt.Ssequence
                            s_kprog_x86_store_xmm0_16
                            (Stmt.Sset _t'37
                              (Expr.Ecast (Expr.Etempvar _t'37 tuint) tuint)))
                          (Stmt.Ssequence
                            s_kprog_x86_store_xmm0_17
                            (Stmt.Sset _t'37
                              (Expr.Ecast (Expr.Etempvar _t'37 tuint) tuint))))))
                    (Stmt.Sifthenelse (Expr.Ecast
                                        (Expr.Ebinop Binop.Oand
                                          (Expr.Ebinop Binop.Oshr
                                            (Expr.Etempvar _t'37 tuint)
                                            (Expr.Econst_int (Integers.Int.repr 5) tint)
                                            tuint)
                                          (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                          tuint) tuchar)
                      (Stmt.Sbuiltin none
                        (ExtFun.EF_vstore Chunk.Mint8unsigned)
                        [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
                        [(Expr.Eaddrof
                           (Expr.Ederef
                             (Expr.Ebinop Binop.Oadd
                               (Expr.Etempvar ___x86_stw_bytes__1 (tptr (tvolatile tuchar)))
                               (Expr.Econst_int (Integers.Int.repr 5) tint)
                               (tptr (tvolatile tuchar))) (tvolatile tuchar))
                           (tptr (tvolatile tuchar))),
                         (Expr.Ecast
                           (Expr.Ebinop Binop.Oshr
                             (Expr.Ecast
                               (Expr.Etempvar ___x86_stw_narrowed__1 tulong)
                               tulong)
                             (Expr.Ebinop Binop.Omul
                               (Expr.Econst_int (Integers.Int.repr 8) tuint)
                               (Expr.Ecast
                                 (Expr.Econst_int (Integers.Int.repr 5) tint)
                                 tuint) tuint) tulong) tuchar)])
                      Stmt.Sskip))
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Etempvar ___x86_stw_width__1 tuchar)
                                          (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                          tint)
                        (Stmt.Sset _t'38
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 1) tuint)
                            tuint))
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Etempvar ___x86_stw_width__1 tuchar)
                                            (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                            tint)
                          (Stmt.Ssequence
                            (Stmt.Sset _t'38
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 3) tuint)
                                tuint))
                            (Stmt.Sset _t'38
                              (Expr.Ecast (Expr.Etempvar _t'38 tuint) tuint)))
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Etempvar ___x86_stw_width__1 tuchar)
                                              (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                              tint)
                            s_kprog_x86_store_xmm0_18
                            s_kprog_x86_store_xmm0_19)))
                      (Stmt.Sifthenelse (Expr.Ecast
                                          (Expr.Ebinop Binop.Oand
                                            (Expr.Ebinop Binop.Oshr
                                              (Expr.Etempvar _t'38 tuint)
                                              (Expr.Econst_int (Integers.Int.repr 6) tint)
                                              tuint)
                                            (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                            tuint) tuchar)
                        (Stmt.Sbuiltin none
                          (ExtFun.EF_vstore Chunk.Mint8unsigned)
                          [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
                          [(Expr.Eaddrof
                             (Expr.Ederef
                               (Expr.Ebinop Binop.Oadd
                                 (Expr.Etempvar ___x86_stw_bytes__1 (tptr (tvolatile tuchar)))
                                 (Expr.Econst_int (Integers.Int.repr 6) tint)
                                 (tptr (tvolatile tuchar)))
                               (tvolatile tuchar)) (tptr (tvolatile tuchar))),
                           (Expr.Ecast
                             (Expr.Ebinop Binop.Oshr
                               (Expr.Ecast
                                 (Expr.Etempvar ___x86_stw_narrowed__1 tulong)
                                 tulong)
                               (Expr.Ebinop Binop.Omul
                                 (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                 (Expr.Ecast
                                   (Expr.Econst_int (Integers.Int.repr 6) tint)
                                   tuint) tuint) tulong) tuchar)])
                        Stmt.Sskip))
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Etempvar ___x86_stw_width__1 tuchar)
                                          (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                          tint)
                        (Stmt.Sset _t'39
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 1) tuint)
                            tuint))
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Etempvar ___x86_stw_width__1 tuchar)
                                            (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                            tint)
                          (Stmt.Ssequence
                            (Stmt.Sset _t'39
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 3) tuint)
                                tuint))
                            (Stmt.Sset _t'39
                              (Expr.Ecast (Expr.Etempvar _t'39 tuint) tuint)))
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Etempvar ___x86_stw_width__1 tuchar)
                                              (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                              tint)
                            s_kprog_x86_store_xmm0_20
                            s_kprog_x86_store_xmm0_21)))
                      (Stmt.Sifthenelse (Expr.Ecast
                                          (Expr.Ebinop Binop.Oand
                                            (Expr.Ebinop Binop.Oshr
                                              (Expr.Etempvar _t'39 tuint)
                                              (Expr.Econst_int (Integers.Int.repr 7) tint)
                                              tuint)
                                            (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                            tuint) tuchar)
                        (Stmt.Sbuiltin none
                          (ExtFun.EF_vstore Chunk.Mint8unsigned)
                          [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
                          [(Expr.Eaddrof
                             (Expr.Ederef
                               (Expr.Ebinop Binop.Oadd
                                 (Expr.Etempvar ___x86_stw_bytes__1 (tptr (tvolatile tuchar)))
                                 (Expr.Econst_int (Integers.Int.repr 7) tint)
                                 (tptr (tvolatile tuchar)))
                               (tvolatile tuchar)) (tptr (tvolatile tuchar))),
                           (Expr.Ecast
                             (Expr.Ebinop Binop.Oshr
                               (Expr.Ecast
                                 (Expr.Etempvar ___x86_stw_narrowed__1 tulong)
                                 tulong)
                               (Expr.Ebinop Binop.Omul
                                 (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                 (Expr.Ecast
                                   (Expr.Econst_int (Integers.Int.repr 7) tint)
                                   tuint) tuint) tulong) tuchar)])
                        Stmt.Sskip))))))))))))

def s_kprog_x86_store_xmm0_23 : Stmt :=
Stmt.Sbreak

def s_kprog_x86_store_xmm0_24 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_loss_value
    (Expr.Efield
      (Expr.Ederef
        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
        (Ty.Tstruct _x86_sim_register_state noattr)) _xmm0_lo tulong))
  (Stmt.Ssequence
    (Stmt.Sloop
      (Stmt.Ssequence
        (Stmt.Sset ___x86_stw_index
          (Expr.Ebinop Binop.Oadd
            (Expr.Ecast (Expr.Etempvar ___x86_loss_off tlong) tulong)
            (Expr.Ecast (Expr.Etempvar _capacity tuint) tulong) tulong))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Scall (some _t'24)
                (Expr.Evar _x86_width_effective (Ty.Tfunction [tuchar] tuchar
                                                  cc_default))
                [(Expr.Etempvar ___x86_loss_width tuchar)])
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar _t'24 tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                  tint)
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Ebinop Binop.Oand
                                      (Expr.Ecast
                                        (Expr.Etempvar ___x86_stw_index tulong)
                                        tulong)
                                      (Expr.Econst_int (Integers.Int.repr 7) tuint)
                                      tulong)
                                    (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                    tint)
                  (Stmt.Ssequence
                    (Stmt.Sset _t'25
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 1) tint) tint))
                    (Stmt.Sset _t'25
                      (Expr.Ecast (Expr.Etempvar _t'25 tint) tbool)))
                  (Stmt.Ssequence
                    (Stmt.Sset _t'25
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 0) tint) tint))
                    (Stmt.Sset _t'25
                      (Expr.Ecast (Expr.Etempvar _t'25 tint) tbool))))
                (Stmt.Sset _t'25
                  (Expr.Econst_int (Integers.Int.repr 0) tint))))
            (Stmt.Sifthenelse (Expr.Etempvar _t'25 tint)
              (Stmt.Sset _t'26
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tint)
                  tint))
              (Stmt.Sset _t'26
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                  tint))))
          (Stmt.Sifthenelse (Expr.Ecast (Expr.Etempvar _t'26 tint) tuchar)
            (Stmt.Ssequence
              (Stmt.Sset _t'142
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
                       (Expr.Etempvar _t'142 (tptr (tvolatile tulong)))
                       (Expr.Ebinop Binop.Oshr
                         (Expr.Ecast (Expr.Etempvar ___x86_stw_index tulong)
                           tulong)
                         (Expr.Econst_int (Integers.Int.repr 3) tint) tulong)
                       (tptr (tvolatile tulong))) (tvolatile tulong))
                   (tptr (tvolatile tulong))),
                 (Expr.Etempvar ___x86_loss_value tulong)]))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Scall (some _t'22)
                  (Expr.Evar _x86_width_effective (Ty.Tfunction [tuchar]
                                                    tuchar cc_default))
                  [(Expr.Etempvar ___x86_loss_width tuchar)])
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Etempvar _t'22 tuchar)
                                    (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                    tint)
                  (Stmt.Sset _t'23
                    (Expr.Ecast
                      (Expr.Ebinop Binop.Oeq
                        (Expr.Ebinop Binop.Oand
                          (Expr.Etempvar ___x86_stw_index tulong)
                          (Expr.Econst_int (Integers.Int.repr 3) tuint)
                          tulong)
                        (Expr.Econst_int (Integers.Int.repr 0) tint) tint)
                      tbool))
                  (Stmt.Sset _t'23
                    (Expr.Econst_int (Integers.Int.repr 0) tint))))
              (Stmt.Sifthenelse (Expr.Etempvar _t'23 tint)
                (Stmt.Ssequence
                  (Stmt.Sset _t'141
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                        (Ty.Tstruct _kprog_x86_arena noattr)) _d
                      (tptr (tvolatile tuint))))
                  (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint32)
                    [(tptr (tvolatile tuint)), (tvolatile tuint)]
                    [(Expr.Eaddrof
                       (Expr.Ederef
                         (Expr.Ebinop Binop.Oadd
                           (Expr.Etempvar _t'141 (tptr (tvolatile tuint)))
                           (Expr.Ebinop Binop.Odiv
                             (Expr.Etempvar ___x86_stw_index tulong)
                             (Expr.Econst_int (Integers.Int.repr 4) tuint)
                             tulong) (tptr (tvolatile tuint)))
                         (tvolatile tuint)) (tptr (tvolatile tuint))),
                     (Expr.Etempvar ___x86_loss_value tulong)]))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Scall (some _t'20)
                      (Expr.Evar _x86_width_effective (Ty.Tfunction [tuchar]
                                                        tuchar cc_default))
                      [(Expr.Etempvar ___x86_loss_width tuchar)])
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Etempvar _t'20 tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                        tint)
                      (Stmt.Sset _t'21
                        (Expr.Ecast
                          (Expr.Ebinop Binop.Oeq
                            (Expr.Ebinop Binop.Oand
                              (Expr.Etempvar ___x86_stw_index tulong)
                              (Expr.Econst_int (Integers.Int.repr 1) tuint)
                              tulong)
                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                            tint) tbool))
                      (Stmt.Sset _t'21
                        (Expr.Econst_int (Integers.Int.repr 0) tint))))
                  (Stmt.Sifthenelse (Expr.Etempvar _t'21 tint)
                    (Stmt.Ssequence
                      (Stmt.Sset _t'140
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                            (Ty.Tstruct _kprog_x86_arena noattr)) _w
                          (tptr (tvolatile tushort))))
                      (Stmt.Sbuiltin none
                        (ExtFun.EF_vstore Chunk.Mint16unsigned)
                        [(tptr (tvolatile tushort)), (tvolatile tushort)]
                        [(Expr.Eaddrof
                           (Expr.Ederef
                             (Expr.Ebinop Binop.Oadd
                               (Expr.Etempvar _t'140 (tptr (tvolatile tushort)))
                               (Expr.Ebinop Binop.Odiv
                                 (Expr.Etempvar ___x86_stw_index tulong)
                                 (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                 tulong) (tptr (tvolatile tushort)))
                             (tvolatile tushort)) (tptr (tvolatile tushort))),
                         (Expr.Etempvar ___x86_loss_value tulong)]))
                    (Stmt.Sloop
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sset _t'139
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                                (Ty.Tstruct _kprog_x86_arena noattr)) _b
                              (tptr (tvolatile tuchar))))
                          (Stmt.Sset ___x86_stw_bytes
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar _t'139 (tptr (tvolatile tuchar)))
                              (Expr.Etempvar ___x86_stw_index tulong)
                              (tptr (tvolatile tuchar)))))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Scall (some _t'11)
                              (Expr.Evar _x86_width_effective (Ty.Tfunction
                                                                [tuchar]
                                                                tuchar
                                                                cc_default))
                              [(Expr.Etempvar ___x86_loss_width tuchar)])
                            (Stmt.Sset ___x86_stw_width
                              (Expr.Ecast (Expr.Etempvar _t'11 tuchar)
                                tuchar)))
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Scall (some _t'12)
                                (Expr.Evar _x86_width_mask (Ty.Tfunction
                                                             [tuchar] tulong
                                                             cc_default))
                                [(Expr.Etempvar ___x86_stw_width tuchar)])
                              (Stmt.Sset ___x86_stw_narrowed
                                (Expr.Ebinop Binop.Oand
                                  (Expr.Etempvar ___x86_loss_value tulong)
                                  (Expr.Etempvar _t'12 tulong) tulong)))
                            (Stmt.Ssequence
                              (Stmt.Sbuiltin none
                                (ExtFun.EF_vstore Chunk.Mint8unsigned)
                                [(tptr (tvolatile tuchar)),
                                 (tvolatile tuchar)]
                                [(Expr.Eaddrof
                                   (Expr.Ederef
                                     (Expr.Ebinop Binop.Oadd
                                       (Expr.Etempvar ___x86_stw_bytes (tptr (tvolatile tuchar)))
                                       (Expr.Econst_int (Integers.Int.repr 0) tint)
                                       (tptr (tvolatile tuchar)))
                                     (tvolatile tuchar))
                                   (tptr (tvolatile tuchar))),
                                 (Expr.Ecast
                                   (Expr.Ebinop Binop.Oshr
                                     (Expr.Ecast
                                       (Expr.Etempvar ___x86_stw_narrowed tulong)
                                       tulong)
                                     (Expr.Ebinop Binop.Omul
                                       (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                       (Expr.Ecast
                                         (Expr.Econst_int (Integers.Int.repr 0) tint)
                                         tuint) tuint) tulong) tuchar)])
                              (Stmt.Ssequence
                                (Stmt.Ssequence
                                  s_kprog_x86_store_xmm0_3
                                  (Stmt.Sifthenelse (Expr.Ecast
                                                      (Expr.Ebinop Binop.Oand
                                                        (Expr.Ebinop Binop.Oshr
                                                          (Expr.Etempvar _t'13 tuint)
                                                          (Expr.Econst_int (Integers.Int.repr 1) tint)
                                                          tuint)
                                                        (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                                        tuint) tuchar)
                                    s_kprog_x86_store_xmm0_4
                                    Stmt.Sskip))
                                (Stmt.Ssequence
                                  s_kprog_x86_store_xmm0_5
                                  s_kprog_x86_store_xmm0_6))))))
                      Stmt.Sbreak))))))))
      Stmt.Sbreak)
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
                (Ty.Tunion __3119 noattr))
              (Positive.ofNat 18727075383868559167)
              (Ty.Tstruct __3120 noattr)) _rsp
            (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                          (Expr.Etempvar ___x86_loss_off tlong)
                          (Expr.Ecast
                            (Expr.Ecast (Expr.Etempvar _t'133 (tptr tvoid))
                              tlong) tlong) tint)
        (Stmt.Ssequence
          (Stmt.Sset ___x86_loss_i
            (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Sloop
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                  (Expr.Etempvar ___x86_loss_i tuint)
                                  (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                  tint)
                Stmt.Sskip
                Stmt.Sbreak)
              (Stmt.Ssequence
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                    (Expr.Etempvar ___x86_loss_i tuint)
                                    (Expr.Etempvar ___x86_loss_width tuchar)
                                    tint)
                  (Stmt.Ssequence
                    (Stmt.Sset _t'138
                      (Expr.Efield
                        (Expr.Efield
                          (Expr.Efield
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                (Ty.Tstruct _x86_sim_register_state noattr))
                              (Positive.ofNat 18727075383868559167)
                              (Ty.Tunion __3119 noattr))
                            (Positive.ofNat 18727075383868559167)
                            (Ty.Tstruct __3120 noattr)) _rsp
                          (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
                    (Stmt.Sset _t'47
                      (Expr.Ecast
                        (Expr.Ebinop Binop.Olt
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Etempvar ___x86_loss_off tlong)
                            (Expr.Etempvar ___x86_loss_i tuint) tlong)
                          (Expr.Ecast
                            (Expr.Ecast (Expr.Etempvar _t'138 (tptr tvoid))
                              tlong) tlong) tint) tbool)))
                  (Stmt.Sset _t'47
                    (Expr.Econst_int (Integers.Int.repr 0) tint)))
                (Stmt.Sifthenelse (Expr.Etempvar _t'47 tint)
                  (Stmt.Sloop
                    (Stmt.Ssequence
                      (Stmt.Sset ___x86_stw_index__1
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Ecast
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar ___x86_loss_off tlong)
                              (Expr.Etempvar ___x86_loss_i tuint) tlong)
                            tulong)
                          (Expr.Ecast (Expr.Etempvar _capacity tuint) tulong)
                          tulong))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Scall (some _t'44)
                              (Expr.Evar _x86_width_effective (Ty.Tfunction
                                                                [tuchar]
                                                                tuchar
                                                                cc_default))
                              [(Expr.Econst_int (Integers.Int.repr 1) tuint)])
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                (Expr.Etempvar _t'44 tuchar)
                                                (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                                tint)
                              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                  (Expr.Ebinop Binop.Oand
                                                    (Expr.Ecast
                                                      (Expr.Etempvar ___x86_stw_index__1 tulong)
                                                      tulong)
                                                    (Expr.Econst_int (Integers.Int.repr 7) tuint)
                                                    tulong)
                                                  (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                                  tint)
                                s_kprog_x86_store_xmm0_7
                                s_kprog_x86_store_xmm0_8)
                              (Stmt.Sset _t'45
                                (Expr.Econst_int (Integers.Int.repr 0) tint))))
                          (Stmt.Sifthenelse (Expr.Etempvar _t'45 tint)
                            (Stmt.Sset _t'46
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 1) tint)
                                tint))
                            (Stmt.Sset _t'46
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 0) tint)
                                tint))))
                        (Stmt.Sifthenelse (Expr.Ecast
                                            (Expr.Etempvar _t'46 tint)
                                            tuchar)
                          (Stmt.Ssequence
                            (Stmt.Scall (some _t'27)
                              (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                   [tuint]
                                                                   tulong
                                                                   cc_default))
                              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                            (Stmt.Ssequence
                              (Stmt.Sset _t'137
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
                                       (Expr.Etempvar _t'137 (tptr (tvolatile tulong)))
                                       (Expr.Ebinop Binop.Oshr
                                         (Expr.Ecast
                                           (Expr.Etempvar ___x86_stw_index__1 tulong)
                                           tulong)
                                         (Expr.Econst_int (Integers.Int.repr 3) tint)
                                         tulong) (tptr (tvolatile tulong)))
                                     (tvolatile tulong))
                                   (tptr (tvolatile tulong))),
                                 (Expr.Etempvar _t'27 tulong)])))
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Scall (some _t'42)
                                (Expr.Evar _x86_width_effective (Ty.Tfunction
                                                                  [tuchar]
                                                                  tuchar
                                                                  cc_default))
                                [(Expr.Econst_int (Integers.Int.repr 1) tuint)])
                              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                  (Expr.Etempvar _t'42 tuchar)
                                                  (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                                  tint)
                                s_kprog_x86_store_xmm0_9
                                (Stmt.Sset _t'43
                                  (Expr.Econst_int (Integers.Int.repr 0) tint))))
                            (Stmt.Sifthenelse (Expr.Etempvar _t'43 tint)
                              (Stmt.Ssequence
                                s_kprog_x86_store_xmm0_10
                                s_kprog_x86_store_xmm0_11)
                              (Stmt.Ssequence
                                s_kprog_x86_store_xmm0_12
                                (Stmt.Sifthenelse (Expr.Etempvar _t'41 tint)
                                  s_kprog_x86_store_xmm0_13
                                  (Stmt.Sloop
                                    s_kprog_x86_store_xmm0_22
                                    s_kprog_x86_store_xmm0_23))))))))
                    Stmt.Sbreak)
                  Stmt.Sskip)))
            (Stmt.Sset ___x86_loss_i
              (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_loss_i tuint)
                (Expr.Econst_int (Integers.Int.repr 1) tint) tuint))))
        Stmt.Sskip))))

def s_kprog_x86_store_xmm0_25 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Econst_int (Integers.Int.repr 1) tint)
                      (Expr.Econst_int (Integers.Int.repr 0) tuint) tint)
    (Stmt.Sset _t'48
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuint))
    (Stmt.Sset _t'48
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint)))
  (Stmt.Sset ___x86_sv_index__1
    (Expr.Ebinop Binop.Oadd
      (Expr.Ecast
        (Expr.Ebinop Binop.Oadd
          (Expr.Ebinop Binop.Oadd
            (Expr.Ecast
              (Expr.Ecast (Expr.Etempvar ___x86_l_base_ptr (tptr tvoid))
                tlong) tlong) (Expr.Etempvar ___x86_l_disp tlong) tlong)
          (Expr.Etempvar _t'48 tuint) tlong) tulong)
      (Expr.Ecast (Expr.Etempvar _capacity tuint) tulong) tulong)))

def s_kprog_x86_store_xmm0_26 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Scall (some _t'49)
      (Expr.Evar _x86_width_effective (Ty.Tfunction [tuchar] tuchar
                                        cc_default))
      [(Expr.Econst_int (Integers.Int.repr 8) tuint)])
    (Stmt.Sset ___x86_sv_width__1
      (Expr.Ecast (Expr.Etempvar _t'49 tuchar) tulong)))
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
          (Stmt.Ssequence
            (Stmt.Sset ___x86_sv_start__1
              (Expr.Ebinop Binop.Omul
                (Expr.Ecast (Expr.Etempvar ___x86_sv_i__1 tuint) tulong)
                (Expr.Econst_int (Integers.Int.repr 8) tuint) tulong))
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                  (Expr.Ebinop Binop.Osub
                                    (Expr.Etempvar ___x86_sv_index__1 tulong)
                                    (Expr.Etempvar ___x86_sv_start__1 tulong)
                                    tulong)
                                  (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                  tint)
                (Stmt.Sset _t'50
                  (Expr.Econst_int (Integers.Int.repr 1) tint))
                (Stmt.Sset _t'50
                  (Expr.Ecast
                    (Expr.Ebinop Binop.Olt
                      (Expr.Ebinop Binop.Osub
                        (Expr.Etempvar ___x86_sv_start__1 tulong)
                        (Expr.Etempvar ___x86_sv_index__1 tulong) tulong)
                      (Expr.Etempvar ___x86_sv_width__1 tulong) tint) tbool)))
              (Stmt.Sifthenelse (Expr.Etempvar _t'50 tint)
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sset _t'132
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                              (Expr.Etempvar ___x86_sv_i__1 tuint)
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
                              (Expr.Etempvar ___x86_sv_i__1 tuint)
                              (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                            (Ty.Tstruct _kprog_x86_stack_fact noattr))
                          _pointer (tptr (tptr tvoid))))
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Etempvar _t'131 (tptr (tptr tvoid)))
                          (tptr tvoid))
                        (Expr.Econst_int (Integers.Int.repr 0) tint))))
                  Stmt.Sbreak)
                Stmt.Sskip)))
          Stmt.Sbreak))
      (Stmt.Sset ___x86_sv_i__1
        (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_sv_i__1 tuint)
          (Expr.Econst_int (Integers.Int.repr 1) tint) tuint)))))

def s_kprog_x86_store_xmm0_27 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Econst_int (Integers.Int.repr 1) tint)
                      (Expr.Econst_int (Integers.Int.repr 0) tuint) tint)
    (Stmt.Sset _t'51
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuint))
    (Stmt.Sset _t'51
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint)))
  (Stmt.Sset ___x86_loss_off__1
    (Expr.Ebinop Binop.Oadd
      (Expr.Ebinop Binop.Oadd
        (Expr.Ecast
          (Expr.Ecast (Expr.Etempvar ___x86_l_base_ptr (tptr tvoid)) tlong)
          tlong) (Expr.Etempvar ___x86_l_disp tlong) tlong)
      (Expr.Etempvar _t'51 tuint) tlong)))

def s_kprog_x86_store_xmm0_28 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Etempvar ___x86_stw_width__2 tuchar)
                      (Expr.Econst_int (Integers.Int.repr 1) tuint) tint)
    (Stmt.Sset _t'55
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                        (Expr.Etempvar ___x86_stw_width__2 tuchar)
                        (Expr.Econst_int (Integers.Int.repr 2) tuint) tint)
      (Stmt.Ssequence
        (Stmt.Sset _t'55
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))
        (Stmt.Sset _t'55 (Expr.Ecast (Expr.Etempvar _t'55 tuint) tuint)))
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                          (Expr.Etempvar ___x86_stw_width__2 tuchar)
                          (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sset _t'55
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 15) tuint)
                tuint))
            (Stmt.Sset _t'55 (Expr.Ecast (Expr.Etempvar _t'55 tuint) tuint)))
          (Stmt.Sset _t'55 (Expr.Ecast (Expr.Etempvar _t'55 tuint) tuint)))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sset _t'55
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 255) tuint)
                tuint))
            (Stmt.Sset _t'55 (Expr.Ecast (Expr.Etempvar _t'55 tuint) tuint)))
          (Stmt.Sset _t'55 (Expr.Ecast (Expr.Etempvar _t'55 tuint) tuint))))))
  (Stmt.Sifthenelse (Expr.Ecast
                      (Expr.Ebinop Binop.Oand
                        (Expr.Ebinop Binop.Oshr (Expr.Etempvar _t'55 tuint)
                          (Expr.Econst_int (Integers.Int.repr 1) tint) tuint)
                        (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint)
                      tuchar)
    (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
      [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
      [(Expr.Eaddrof
         (Expr.Ederef
           (Expr.Ebinop Binop.Oadd
             (Expr.Etempvar ___x86_stw_bytes__2 (tptr (tvolatile tuchar)))
             (Expr.Econst_int (Integers.Int.repr 1) tint)
             (tptr (tvolatile tuchar))) (tvolatile tuchar))
         (tptr (tvolatile tuchar))),
       (Expr.Ecast
         (Expr.Ebinop Binop.Oshr
           (Expr.Ecast (Expr.Etempvar ___x86_stw_narrowed__2 tulong) tulong)
           (Expr.Ebinop Binop.Omul
             (Expr.Econst_int (Integers.Int.repr 8) tuint)
             (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tint) tuint)
             tuint) tulong) tuchar)])
    Stmt.Sskip))

def s_kprog_x86_store_xmm0_29 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                        (Expr.Etempvar ___x86_stw_width__2 tuchar)
                        (Expr.Econst_int (Integers.Int.repr 1) tuint) tint)
      (Stmt.Sset _t'56
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                          (Expr.Etempvar ___x86_stw_width__2 tuchar)
                          (Expr.Econst_int (Integers.Int.repr 2) tuint) tint)
        (Stmt.Ssequence
          (Stmt.Sset _t'56
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))
          (Stmt.Sset _t'56 (Expr.Ecast (Expr.Etempvar _t'56 tuint) tuint)))
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar ___x86_stw_width__2 tuchar)
                            (Expr.Econst_int (Integers.Int.repr 4) tuint)
                            tint)
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sset _t'56
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 15) tuint)
                  tuint))
              (Stmt.Sset _t'56
                (Expr.Ecast (Expr.Etempvar _t'56 tuint) tuint)))
            (Stmt.Sset _t'56 (Expr.Ecast (Expr.Etempvar _t'56 tuint) tuint)))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sset _t'56
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 255) tuint)
                  tuint))
              (Stmt.Sset _t'56
                (Expr.Ecast (Expr.Etempvar _t'56 tuint) tuint)))
            (Stmt.Sset _t'56 (Expr.Ecast (Expr.Etempvar _t'56 tuint) tuint))))))
    (Stmt.Sifthenelse (Expr.Ecast
                        (Expr.Ebinop Binop.Oand
                          (Expr.Ebinop Binop.Oshr (Expr.Etempvar _t'56 tuint)
                            (Expr.Econst_int (Integers.Int.repr 2) tint)
                            tuint)
                          (Expr.Econst_int (Integers.Int.repr 1) tuint)
                          tuint) tuchar)
      (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
        [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
        [(Expr.Eaddrof
           (Expr.Ederef
             (Expr.Ebinop Binop.Oadd
               (Expr.Etempvar ___x86_stw_bytes__2 (tptr (tvolatile tuchar)))
               (Expr.Econst_int (Integers.Int.repr 2) tint)
               (tptr (tvolatile tuchar))) (tvolatile tuchar))
           (tptr (tvolatile tuchar))),
         (Expr.Ecast
           (Expr.Ebinop Binop.Oshr
             (Expr.Ecast (Expr.Etempvar ___x86_stw_narrowed__2 tulong)
               tulong)
             (Expr.Ebinop Binop.Omul
               (Expr.Econst_int (Integers.Int.repr 8) tuint)
               (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tint)
                 tuint) tuint) tulong) tuchar)])
      Stmt.Sskip))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                          (Expr.Etempvar ___x86_stw_width__2 tuchar)
                          (Expr.Econst_int (Integers.Int.repr 1) tuint) tint)
        (Stmt.Sset _t'57
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar ___x86_stw_width__2 tuchar)
                            (Expr.Econst_int (Integers.Int.repr 2) tuint)
                            tint)
          (Stmt.Ssequence
            (Stmt.Sset _t'57
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint)
                tuint))
            (Stmt.Sset _t'57 (Expr.Ecast (Expr.Etempvar _t'57 tuint) tuint)))
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar ___x86_stw_width__2 tuchar)
                              (Expr.Econst_int (Integers.Int.repr 4) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'57
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 15) tuint)
                    tuint))
                (Stmt.Sset _t'57
                  (Expr.Ecast (Expr.Etempvar _t'57 tuint) tuint)))
              (Stmt.Sset _t'57
                (Expr.Ecast (Expr.Etempvar _t'57 tuint) tuint)))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'57
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 255) tuint)
                    tuint))
                (Stmt.Sset _t'57
                  (Expr.Ecast (Expr.Etempvar _t'57 tuint) tuint)))
              (Stmt.Sset _t'57
                (Expr.Ecast (Expr.Etempvar _t'57 tuint) tuint))))))
      (Stmt.Sifthenelse (Expr.Ecast
                          (Expr.Ebinop Binop.Oand
                            (Expr.Ebinop Binop.Oshr
                              (Expr.Etempvar _t'57 tuint)
                              (Expr.Econst_int (Integers.Int.repr 3) tint)
                              tuint)
                            (Expr.Econst_int (Integers.Int.repr 1) tuint)
                            tuint) tuchar)
        (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
          [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
          [(Expr.Eaddrof
             (Expr.Ederef
               (Expr.Ebinop Binop.Oadd
                 (Expr.Etempvar ___x86_stw_bytes__2 (tptr (tvolatile tuchar)))
                 (Expr.Econst_int (Integers.Int.repr 3) tint)
                 (tptr (tvolatile tuchar))) (tvolatile tuchar))
             (tptr (tvolatile tuchar))),
           (Expr.Ecast
             (Expr.Ebinop Binop.Oshr
               (Expr.Ecast (Expr.Etempvar ___x86_stw_narrowed__2 tulong)
                 tulong)
               (Expr.Ebinop Binop.Omul
                 (Expr.Econst_int (Integers.Int.repr 8) tuint)
                 (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tint)
                   tuint) tuint) tulong) tuchar)])
        Stmt.Sskip))
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar ___x86_stw_width__2 tuchar)
                            (Expr.Econst_int (Integers.Int.repr 1) tuint)
                            tint)
          (Stmt.Sset _t'58
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar ___x86_stw_width__2 tuchar)
                              (Expr.Econst_int (Integers.Int.repr 2) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Sset _t'58
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint)
                  tuint))
              (Stmt.Sset _t'58
                (Expr.Ecast (Expr.Etempvar _t'58 tuint) tuint)))
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Etempvar ___x86_stw_width__2 tuchar)
                                (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                tint)
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sset _t'58
                    (Expr.Ecast
                      (Expr.Econst_int (Integers.Int.repr 15) tuint) tuint))
                  (Stmt.Sset _t'58
                    (Expr.Ecast (Expr.Etempvar _t'58 tuint) tuint)))
                (Stmt.Sset _t'58
                  (Expr.Ecast (Expr.Etempvar _t'58 tuint) tuint)))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sset _t'58
                    (Expr.Ecast
                      (Expr.Econst_int (Integers.Int.repr 255) tuint) tuint))
                  (Stmt.Sset _t'58
                    (Expr.Ecast (Expr.Etempvar _t'58 tuint) tuint)))
                (Stmt.Sset _t'58
                  (Expr.Ecast (Expr.Etempvar _t'58 tuint) tuint))))))
        (Stmt.Sifthenelse (Expr.Ecast
                            (Expr.Ebinop Binop.Oand
                              (Expr.Ebinop Binop.Oshr
                                (Expr.Etempvar _t'58 tuint)
                                (Expr.Econst_int (Integers.Int.repr 4) tint)
                                tuint)
                              (Expr.Econst_int (Integers.Int.repr 1) tuint)
                              tuint) tuchar)
          (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
            [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
            [(Expr.Eaddrof
               (Expr.Ederef
                 (Expr.Ebinop Binop.Oadd
                   (Expr.Etempvar ___x86_stw_bytes__2 (tptr (tvolatile tuchar)))
                   (Expr.Econst_int (Integers.Int.repr 4) tint)
                   (tptr (tvolatile tuchar))) (tvolatile tuchar))
               (tptr (tvolatile tuchar))),
             (Expr.Ecast
               (Expr.Ebinop Binop.Oshr
                 (Expr.Ecast (Expr.Etempvar ___x86_stw_narrowed__2 tulong)
                   tulong)
                 (Expr.Ebinop Binop.Omul
                   (Expr.Econst_int (Integers.Int.repr 8) tuint)
                   (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 4) tint)
                     tuint) tuint) tulong) tuchar)])
          Stmt.Sskip))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar ___x86_stw_width__2 tuchar)
                              (Expr.Econst_int (Integers.Int.repr 1) tuint)
                              tint)
            (Stmt.Sset _t'59
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint)
                tuint))
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Etempvar ___x86_stw_width__2 tuchar)
                                (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                tint)
              (Stmt.Ssequence
                (Stmt.Sset _t'59
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint)
                    tuint))
                (Stmt.Sset _t'59
                  (Expr.Ecast (Expr.Etempvar _t'59 tuint) tuint)))
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar ___x86_stw_width__2 tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                  tint)
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sset _t'59
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 15) tuint) tuint))
                    (Stmt.Sset _t'59
                      (Expr.Ecast (Expr.Etempvar _t'59 tuint) tuint)))
                  (Stmt.Sset _t'59
                    (Expr.Ecast (Expr.Etempvar _t'59 tuint) tuint)))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sset _t'59
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 255) tuint)
                        tuint))
                    (Stmt.Sset _t'59
                      (Expr.Ecast (Expr.Etempvar _t'59 tuint) tuint)))
                  (Stmt.Sset _t'59
                    (Expr.Ecast (Expr.Etempvar _t'59 tuint) tuint))))))
          (Stmt.Sifthenelse (Expr.Ecast
                              (Expr.Ebinop Binop.Oand
                                (Expr.Ebinop Binop.Oshr
                                  (Expr.Etempvar _t'59 tuint)
                                  (Expr.Econst_int (Integers.Int.repr 5) tint)
                                  tuint)
                                (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                tuint) tuchar)
            (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
              [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
              [(Expr.Eaddrof
                 (Expr.Ederef
                   (Expr.Ebinop Binop.Oadd
                     (Expr.Etempvar ___x86_stw_bytes__2 (tptr (tvolatile tuchar)))
                     (Expr.Econst_int (Integers.Int.repr 5) tint)
                     (tptr (tvolatile tuchar))) (tvolatile tuchar))
                 (tptr (tvolatile tuchar))),
               (Expr.Ecast
                 (Expr.Ebinop Binop.Oshr
                   (Expr.Ecast (Expr.Etempvar ___x86_stw_narrowed__2 tulong)
                     tulong)
                   (Expr.Ebinop Binop.Omul
                     (Expr.Econst_int (Integers.Int.repr 8) tuint)
                     (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 5) tint)
                       tuint) tuint) tulong) tuchar)])
            Stmt.Sskip))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Etempvar ___x86_stw_width__2 tuchar)
                                (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                tint)
              (Stmt.Sset _t'60
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint)
                  tuint))
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar ___x86_stw_width__2 tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                  tint)
                (Stmt.Ssequence
                  (Stmt.Sset _t'60
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint)
                      tuint))
                  (Stmt.Sset _t'60
                    (Expr.Ecast (Expr.Etempvar _t'60 tuint) tuint)))
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Etempvar ___x86_stw_width__2 tuchar)
                                    (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                    tint)
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sset _t'60
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 15) tuint)
                          tuint))
                      (Stmt.Sset _t'60
                        (Expr.Ecast (Expr.Etempvar _t'60 tuint) tuint)))
                    (Stmt.Sset _t'60
                      (Expr.Ecast (Expr.Etempvar _t'60 tuint) tuint)))
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sset _t'60
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 255) tuint)
                          tuint))
                      (Stmt.Sset _t'60
                        (Expr.Ecast (Expr.Etempvar _t'60 tuint) tuint)))
                    (Stmt.Sset _t'60
                      (Expr.Ecast (Expr.Etempvar _t'60 tuint) tuint))))))
            (Stmt.Sifthenelse (Expr.Ecast
                                (Expr.Ebinop Binop.Oand
                                  (Expr.Ebinop Binop.Oshr
                                    (Expr.Etempvar _t'60 tuint)
                                    (Expr.Econst_int (Integers.Int.repr 6) tint)
                                    tuint)
                                  (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                  tuint) tuchar)
              (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
                [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
                [(Expr.Eaddrof
                   (Expr.Ederef
                     (Expr.Ebinop Binop.Oadd
                       (Expr.Etempvar ___x86_stw_bytes__2 (tptr (tvolatile tuchar)))
                       (Expr.Econst_int (Integers.Int.repr 6) tint)
                       (tptr (tvolatile tuchar))) (tvolatile tuchar))
                   (tptr (tvolatile tuchar))),
                 (Expr.Ecast
                   (Expr.Ebinop Binop.Oshr
                     (Expr.Ecast
                       (Expr.Etempvar ___x86_stw_narrowed__2 tulong) tulong)
                     (Expr.Ebinop Binop.Omul
                       (Expr.Econst_int (Integers.Int.repr 8) tuint)
                       (Expr.Ecast
                         (Expr.Econst_int (Integers.Int.repr 6) tint) tuint)
                       tuint) tulong) tuchar)])
              Stmt.Sskip))
          (Stmt.Ssequence
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Etempvar ___x86_stw_width__2 tuchar)
                                (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                tint)
              (Stmt.Sset _t'61
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint)
                  tuint))
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar ___x86_stw_width__2 tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                  tint)
                (Stmt.Ssequence
                  (Stmt.Sset _t'61
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint)
                      tuint))
                  (Stmt.Sset _t'61
                    (Expr.Ecast (Expr.Etempvar _t'61 tuint) tuint)))
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Etempvar ___x86_stw_width__2 tuchar)
                                    (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                    tint)
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sset _t'61
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 15) tuint)
                          tuint))
                      (Stmt.Sset _t'61
                        (Expr.Ecast (Expr.Etempvar _t'61 tuint) tuint)))
                    (Stmt.Sset _t'61
                      (Expr.Ecast (Expr.Etempvar _t'61 tuint) tuint)))
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sset _t'61
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 255) tuint)
                          tuint))
                      (Stmt.Sset _t'61
                        (Expr.Ecast (Expr.Etempvar _t'61 tuint) tuint)))
                    (Stmt.Sset _t'61
                      (Expr.Ecast (Expr.Etempvar _t'61 tuint) tuint))))))
            (Stmt.Sifthenelse (Expr.Ecast
                                (Expr.Ebinop Binop.Oand
                                  (Expr.Ebinop Binop.Oshr
                                    (Expr.Etempvar _t'61 tuint)
                                    (Expr.Econst_int (Integers.Int.repr 7) tint)
                                    tuint)
                                  (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                  tuint) tuchar)
              (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
                [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
                [(Expr.Eaddrof
                   (Expr.Ederef
                     (Expr.Ebinop Binop.Oadd
                       (Expr.Etempvar ___x86_stw_bytes__2 (tptr (tvolatile tuchar)))
                       (Expr.Econst_int (Integers.Int.repr 7) tint)
                       (tptr (tvolatile tuchar))) (tvolatile tuchar))
                   (tptr (tvolatile tuchar))),
                 (Expr.Ecast
                   (Expr.Ebinop Binop.Oshr
                     (Expr.Ecast
                       (Expr.Etempvar ___x86_stw_narrowed__2 tulong) tulong)
                     (Expr.Ebinop Binop.Omul
                       (Expr.Econst_int (Integers.Int.repr 8) tuint)
                       (Expr.Ecast
                         (Expr.Econst_int (Integers.Int.repr 7) tint) tuint)
                       tuint) tulong) tuchar)])
              Stmt.Sskip)))))))

def s_kprog_x86_store_xmm0_30 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                    (Expr.Ebinop Binop.Oand
                      (Expr.Ecast (Expr.Etempvar ___x86_stw_index__3 tulong)
                        tulong) (Expr.Econst_int (Integers.Int.repr 7) tuint)
                      tulong) (Expr.Econst_int (Integers.Int.repr 0) tuint)
                    tint)
  (Stmt.Ssequence
    (Stmt.Sset _t'87
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tint) tint))
    (Stmt.Sset _t'87 (Expr.Ecast (Expr.Etempvar _t'87 tint) tbool)))
  (Stmt.Ssequence
    (Stmt.Sset _t'87
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) tint))
    (Stmt.Sset _t'87 (Expr.Ecast (Expr.Etempvar _t'87 tint) tbool))))

def s_kprog_x86_store_xmm0_31 : Stmt :=
(Stmt.Scall (some _t'84)
  (Expr.Evar _x86_width_effective (Ty.Tfunction [tuchar] tuchar cc_default))
  [(Expr.Econst_int (Integers.Int.repr 1) tuint)])

def s_kprog_x86_store_xmm0_32 : Stmt :=
(Stmt.Sset _t'85
  (Expr.Ecast
    (Expr.Ebinop Binop.Oeq
      (Expr.Ebinop Binop.Oand (Expr.Etempvar ___x86_stw_index__3 tulong)
        (Expr.Econst_int (Integers.Int.repr 3) tuint) tulong)
      (Expr.Econst_int (Integers.Int.repr 0) tint) tint) tbool))

def s_kprog_x86_store_xmm0_33 : Stmt :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'70)
    (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                         cc_default))
    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
  (Stmt.Ssequence
    (Stmt.Sset _t'124
      (Expr.Efield
        (Expr.Ederef
          (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
          (Ty.Tstruct _kprog_x86_arena noattr)) _d (tptr (tvolatile tuint))))
    (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint32)
      [(tptr (tvolatile tuint)), (tvolatile tuint)]
      [(Expr.Eaddrof
         (Expr.Ederef
           (Expr.Ebinop Binop.Oadd
             (Expr.Etempvar _t'124 (tptr (tvolatile tuint)))
             (Expr.Ebinop Binop.Odiv
               (Expr.Etempvar ___x86_stw_index__3 tulong)
               (Expr.Econst_int (Integers.Int.repr 4) tuint) tulong)
             (tptr (tvolatile tuint))) (tvolatile tuint))
         (tptr (tvolatile tuint))), (Expr.Etempvar _t'70 tulong)])))

def s_kprog_x86_store_xmm0_34 : Stmt :=
(Stmt.Sset _t'75
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 15) tuint) tuint))

def s_kprog_x86_store_xmm0_35 : Stmt :=
(Stmt.Sset _t'75
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 255) tuint) tuint))

def s_kprog_x86_store_xmm0_36 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'76
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 15) tuint) tuint))
  (Stmt.Sset _t'76 (Expr.Ecast (Expr.Etempvar _t'76 tuint) tuint)))

def s_kprog_x86_store_xmm0_37 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'76
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 255) tuint) tuint))
  (Stmt.Sset _t'76 (Expr.Ecast (Expr.Etempvar _t'76 tuint) tuint)))

def s_kprog_x86_store_xmm0_38 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'77
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 15) tuint) tuint))
    (Stmt.Sset _t'77 (Expr.Ecast (Expr.Etempvar _t'77 tuint) tuint)))
  (Stmt.Sset _t'77 (Expr.Ecast (Expr.Etempvar _t'77 tuint) tuint)))

def s_kprog_x86_store_xmm0_39 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'77
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 255) tuint) tuint))
    (Stmt.Sset _t'77 (Expr.Ecast (Expr.Etempvar _t'77 tuint) tuint)))
  (Stmt.Sset _t'77 (Expr.Ecast (Expr.Etempvar _t'77 tuint) tuint)))

def s_kprog_x86_store_xmm0_40 : Stmt :=
(Stmt.Sset _t'78
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))

def s_kprog_x86_store_xmm0_41 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'78
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 15) tuint) tuint))
    (Stmt.Sset _t'78 (Expr.Ecast (Expr.Etempvar _t'78 tuint) tuint)))
  (Stmt.Sset _t'78 (Expr.Ecast (Expr.Etempvar _t'78 tuint) tuint)))

def s_kprog_x86_store_xmm0_42 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'78
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 255) tuint) tuint))
    (Stmt.Sset _t'78 (Expr.Ecast (Expr.Etempvar _t'78 tuint) tuint)))
  (Stmt.Sset _t'78 (Expr.Ecast (Expr.Etempvar _t'78 tuint) tuint)))

def s_kprog_x86_store_xmm0_43 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'79
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))
  (Stmt.Sset _t'79 (Expr.Ecast (Expr.Etempvar _t'79 tuint) tuint)))

def s_kprog_x86_store_xmm0_44 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                    (Expr.Etempvar ___x86_stw_width__3 tuchar)
                    (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sset _t'79
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 15) tuint) tuint))
      (Stmt.Sset _t'79 (Expr.Ecast (Expr.Etempvar _t'79 tuint) tuint)))
    (Stmt.Sset _t'79 (Expr.Ecast (Expr.Etempvar _t'79 tuint) tuint)))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sset _t'79
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 255) tuint) tuint))
      (Stmt.Sset _t'79 (Expr.Ecast (Expr.Etempvar _t'79 tuint) tuint)))
    (Stmt.Sset _t'79 (Expr.Ecast (Expr.Etempvar _t'79 tuint) tuint))))

def s_kprog_x86_store_xmm0_45 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'80
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))
  (Stmt.Sset _t'80 (Expr.Ecast (Expr.Etempvar _t'80 tuint) tuint)))

def s_kprog_x86_store_xmm0_46 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                    (Expr.Etempvar ___x86_stw_width__3 tuchar)
                    (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sset _t'80
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 15) tuint) tuint))
      (Stmt.Sset _t'80 (Expr.Ecast (Expr.Etempvar _t'80 tuint) tuint)))
    (Stmt.Sset _t'80 (Expr.Ecast (Expr.Etempvar _t'80 tuint) tuint)))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sset _t'80
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 255) tuint) tuint))
      (Stmt.Sset _t'80 (Expr.Ecast (Expr.Etempvar _t'80 tuint) tuint)))
    (Stmt.Sset _t'80 (Expr.Ecast (Expr.Etempvar _t'80 tuint) tuint))))

def s_kprog_x86_store_xmm0_47 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'81
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint) tuint))
  (Stmt.Sset _t'81 (Expr.Ecast (Expr.Etempvar _t'81 tuint) tuint)))

def s_kprog_x86_store_xmm0_48 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                    (Expr.Etempvar ___x86_stw_width__3 tuchar)
                    (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sset _t'81
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 15) tuint) tuint))
      (Stmt.Sset _t'81 (Expr.Ecast (Expr.Etempvar _t'81 tuint) tuint)))
    (Stmt.Sset _t'81 (Expr.Ecast (Expr.Etempvar _t'81 tuint) tuint)))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sset _t'81
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 255) tuint) tuint))
      (Stmt.Sset _t'81 (Expr.Ecast (Expr.Etempvar _t'81 tuint) tuint)))
    (Stmt.Sset _t'81 (Expr.Ecast (Expr.Etempvar _t'81 tuint) tuint))))

def s_kprog_x86_store_xmm0_49 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Scall (some _t'82)
      (Expr.Evar _x86_width_effective (Ty.Tfunction [tuchar] tuchar
                                        cc_default))
      [(Expr.Econst_int (Integers.Int.repr 1) tuint)])
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _t'82 tuchar)
                        (Expr.Econst_int (Integers.Int.repr 2) tuint) tint)
      (Stmt.Sset _t'83
        (Expr.Ecast
          (Expr.Ebinop Binop.Oeq
            (Expr.Ebinop Binop.Oand
              (Expr.Etempvar ___x86_stw_index__3 tulong)
              (Expr.Econst_int (Integers.Int.repr 1) tuint) tulong)
            (Expr.Econst_int (Integers.Int.repr 0) tint) tint) tbool))
      (Stmt.Sset _t'83 (Expr.Econst_int (Integers.Int.repr 0) tint))))
  (Stmt.Sifthenelse (Expr.Etempvar _t'83 tint)
    (Stmt.Ssequence
      (Stmt.Scall (some _t'71)
        (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                             cc_default))
        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
      (Stmt.Ssequence
        (Stmt.Sset _t'123
          (Expr.Efield
            (Expr.Ederef
              (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
              (Ty.Tstruct _kprog_x86_arena noattr)) _w
            (tptr (tvolatile tushort))))
        (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint16unsigned)
          [(tptr (tvolatile tushort)), (tvolatile tushort)]
          [(Expr.Eaddrof
             (Expr.Ederef
               (Expr.Ebinop Binop.Oadd
                 (Expr.Etempvar _t'123 (tptr (tvolatile tushort)))
                 (Expr.Ebinop Binop.Odiv
                   (Expr.Etempvar ___x86_stw_index__3 tulong)
                   (Expr.Econst_int (Integers.Int.repr 2) tuint) tulong)
                 (tptr (tvolatile tushort))) (tvolatile tushort))
             (tptr (tvolatile tushort))), (Expr.Etempvar _t'71 tulong)])))
    (Stmt.Sloop
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sset _t'122
            (Expr.Efield
              (Expr.Ederef
                (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                (Ty.Tstruct _kprog_x86_arena noattr)) _b
              (tptr (tvolatile tuchar))))
          (Stmt.Sset ___x86_stw_bytes__3
            (Expr.Ebinop Binop.Oadd
              (Expr.Etempvar _t'122 (tptr (tvolatile tuchar)))
              (Expr.Etempvar ___x86_stw_index__3 tulong)
              (tptr (tvolatile tuchar)))))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Scall (some _t'72)
              (Expr.Evar _x86_width_effective (Ty.Tfunction [tuchar] tuchar
                                                cc_default))
              [(Expr.Econst_int (Integers.Int.repr 1) tuint)])
            (Stmt.Sset ___x86_stw_width__3
              (Expr.Ecast (Expr.Etempvar _t'72 tuchar) tuchar)))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Scall (some _t'73)
                  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                       tulong cc_default))
                  [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                (Stmt.Scall (some _t'74)
                  (Expr.Evar _x86_width_mask (Ty.Tfunction [tuchar] tulong
                                               cc_default))
                  [(Expr.Etempvar ___x86_stw_width__3 tuchar)]))
              (Stmt.Sset ___x86_stw_narrowed__3
                (Expr.Ebinop Binop.Oand (Expr.Etempvar _t'73 tulong)
                  (Expr.Etempvar _t'74 tulong) tulong)))
            (Stmt.Ssequence
              (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint8unsigned)
                [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
                [(Expr.Eaddrof
                   (Expr.Ederef
                     (Expr.Ebinop Binop.Oadd
                       (Expr.Etempvar ___x86_stw_bytes__3 (tptr (tvolatile tuchar)))
                       (Expr.Econst_int (Integers.Int.repr 0) tint)
                       (tptr (tvolatile tuchar))) (tvolatile tuchar))
                   (tptr (tvolatile tuchar))),
                 (Expr.Ecast
                   (Expr.Ebinop Binop.Oshr
                     (Expr.Ecast
                       (Expr.Etempvar ___x86_stw_narrowed__3 tulong) tulong)
                     (Expr.Ebinop Binop.Omul
                       (Expr.Econst_int (Integers.Int.repr 8) tuint)
                       (Expr.Ecast
                         (Expr.Econst_int (Integers.Int.repr 0) tint) tuint)
                       tuint) tulong) tuchar)])
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar ___x86_stw_width__3 tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                      tint)
                    (Stmt.Sset _t'75
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 1) tuint) tuint))
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Etempvar ___x86_stw_width__3 tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                        tint)
                      (Stmt.Ssequence
                        (Stmt.Sset _t'75
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 3) tuint)
                            tuint))
                        (Stmt.Sset _t'75
                          (Expr.Ecast (Expr.Etempvar _t'75 tuint) tuint)))
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Etempvar ___x86_stw_width__3 tuchar)
                                          (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                          tint)
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            s_kprog_x86_store_xmm0_34
                            (Stmt.Sset _t'75
                              (Expr.Ecast (Expr.Etempvar _t'75 tuint) tuint)))
                          (Stmt.Sset _t'75
                            (Expr.Ecast (Expr.Etempvar _t'75 tuint) tuint)))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            s_kprog_x86_store_xmm0_35
                            (Stmt.Sset _t'75
                              (Expr.Ecast (Expr.Etempvar _t'75 tuint) tuint)))
                          (Stmt.Sset _t'75
                            (Expr.Ecast (Expr.Etempvar _t'75 tuint) tuint))))))
                  (Stmt.Sifthenelse (Expr.Ecast
                                      (Expr.Ebinop Binop.Oand
                                        (Expr.Ebinop Binop.Oshr
                                          (Expr.Etempvar _t'75 tuint)
                                          (Expr.Econst_int (Integers.Int.repr 1) tint)
                                          tuint)
                                        (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                        tuint) tuchar)
                    (Stmt.Sbuiltin none
                      (ExtFun.EF_vstore Chunk.Mint8unsigned)
                      [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
                      [(Expr.Eaddrof
                         (Expr.Ederef
                           (Expr.Ebinop Binop.Oadd
                             (Expr.Etempvar ___x86_stw_bytes__3 (tptr (tvolatile tuchar)))
                             (Expr.Econst_int (Integers.Int.repr 1) tint)
                             (tptr (tvolatile tuchar))) (tvolatile tuchar))
                         (tptr (tvolatile tuchar))),
                       (Expr.Ecast
                         (Expr.Ebinop Binop.Oshr
                           (Expr.Ecast
                             (Expr.Etempvar ___x86_stw_narrowed__3 tulong)
                             tulong)
                           (Expr.Ebinop Binop.Omul
                             (Expr.Econst_int (Integers.Int.repr 8) tuint)
                             (Expr.Ecast
                               (Expr.Econst_int (Integers.Int.repr 1) tint)
                               tuint) tuint) tulong) tuchar)])
                    Stmt.Sskip))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Etempvar ___x86_stw_width__3 tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                        tint)
                      (Stmt.Sset _t'76
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 1) tuint)
                          tuint))
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Etempvar ___x86_stw_width__3 tuchar)
                                          (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                          tint)
                        (Stmt.Ssequence
                          (Stmt.Sset _t'76
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 3) tuint)
                              tuint))
                          (Stmt.Sset _t'76
                            (Expr.Ecast (Expr.Etempvar _t'76 tuint) tuint)))
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Etempvar ___x86_stw_width__3 tuchar)
                                            (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                            tint)
                          (Stmt.Ssequence
                            s_kprog_x86_store_xmm0_36
                            (Stmt.Sset _t'76
                              (Expr.Ecast (Expr.Etempvar _t'76 tuint) tuint)))
                          (Stmt.Ssequence
                            s_kprog_x86_store_xmm0_37
                            (Stmt.Sset _t'76
                              (Expr.Ecast (Expr.Etempvar _t'76 tuint) tuint))))))
                    (Stmt.Sifthenelse (Expr.Ecast
                                        (Expr.Ebinop Binop.Oand
                                          (Expr.Ebinop Binop.Oshr
                                            (Expr.Etempvar _t'76 tuint)
                                            (Expr.Econst_int (Integers.Int.repr 2) tint)
                                            tuint)
                                          (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                          tuint) tuchar)
                      (Stmt.Sbuiltin none
                        (ExtFun.EF_vstore Chunk.Mint8unsigned)
                        [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
                        [(Expr.Eaddrof
                           (Expr.Ederef
                             (Expr.Ebinop Binop.Oadd
                               (Expr.Etempvar ___x86_stw_bytes__3 (tptr (tvolatile tuchar)))
                               (Expr.Econst_int (Integers.Int.repr 2) tint)
                               (tptr (tvolatile tuchar))) (tvolatile tuchar))
                           (tptr (tvolatile tuchar))),
                         (Expr.Ecast
                           (Expr.Ebinop Binop.Oshr
                             (Expr.Ecast
                               (Expr.Etempvar ___x86_stw_narrowed__3 tulong)
                               tulong)
                             (Expr.Ebinop Binop.Omul
                               (Expr.Econst_int (Integers.Int.repr 8) tuint)
                               (Expr.Ecast
                                 (Expr.Econst_int (Integers.Int.repr 2) tint)
                                 tuint) tuint) tulong) tuchar)])
                      Stmt.Sskip))
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Etempvar ___x86_stw_width__3 tuchar)
                                          (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                          tint)
                        (Stmt.Sset _t'77
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 1) tuint)
                            tuint))
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Etempvar ___x86_stw_width__3 tuchar)
                                            (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                            tint)
                          (Stmt.Ssequence
                            (Stmt.Sset _t'77
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 3) tuint)
                                tuint))
                            (Stmt.Sset _t'77
                              (Expr.Ecast (Expr.Etempvar _t'77 tuint) tuint)))
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Etempvar ___x86_stw_width__3 tuchar)
                                              (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                              tint)
                            s_kprog_x86_store_xmm0_38
                            s_kprog_x86_store_xmm0_39)))
                      (Stmt.Sifthenelse (Expr.Ecast
                                          (Expr.Ebinop Binop.Oand
                                            (Expr.Ebinop Binop.Oshr
                                              (Expr.Etempvar _t'77 tuint)
                                              (Expr.Econst_int (Integers.Int.repr 3) tint)
                                              tuint)
                                            (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                            tuint) tuchar)
                        (Stmt.Sbuiltin none
                          (ExtFun.EF_vstore Chunk.Mint8unsigned)
                          [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
                          [(Expr.Eaddrof
                             (Expr.Ederef
                               (Expr.Ebinop Binop.Oadd
                                 (Expr.Etempvar ___x86_stw_bytes__3 (tptr (tvolatile tuchar)))
                                 (Expr.Econst_int (Integers.Int.repr 3) tint)
                                 (tptr (tvolatile tuchar)))
                               (tvolatile tuchar)) (tptr (tvolatile tuchar))),
                           (Expr.Ecast
                             (Expr.Ebinop Binop.Oshr
                               (Expr.Ecast
                                 (Expr.Etempvar ___x86_stw_narrowed__3 tulong)
                                 tulong)
                               (Expr.Ebinop Binop.Omul
                                 (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                 (Expr.Ecast
                                   (Expr.Econst_int (Integers.Int.repr 3) tint)
                                   tuint) tuint) tulong) tuchar)])
                        Stmt.Sskip))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Etempvar ___x86_stw_width__3 tuchar)
                                            (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                            tint)
                          (Stmt.Sset _t'78
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 1) tuint)
                              tuint))
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Etempvar ___x86_stw_width__3 tuchar)
                                              (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                              tint)
                            (Stmt.Ssequence
                              s_kprog_x86_store_xmm0_40
                              (Stmt.Sset _t'78
                                (Expr.Ecast (Expr.Etempvar _t'78 tuint)
                                  tuint)))
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                (Expr.Etempvar ___x86_stw_width__3 tuchar)
                                                (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                                tint)
                              s_kprog_x86_store_xmm0_41
                              s_kprog_x86_store_xmm0_42)))
                        (Stmt.Sifthenelse (Expr.Ecast
                                            (Expr.Ebinop Binop.Oand
                                              (Expr.Ebinop Binop.Oshr
                                                (Expr.Etempvar _t'78 tuint)
                                                (Expr.Econst_int (Integers.Int.repr 4) tint)
                                                tuint)
                                              (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                              tuint) tuchar)
                          (Stmt.Sbuiltin none
                            (ExtFun.EF_vstore Chunk.Mint8unsigned)
                            [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
                            [(Expr.Eaddrof
                               (Expr.Ederef
                                 (Expr.Ebinop Binop.Oadd
                                   (Expr.Etempvar ___x86_stw_bytes__3 (tptr (tvolatile tuchar)))
                                   (Expr.Econst_int (Integers.Int.repr 4) tint)
                                   (tptr (tvolatile tuchar)))
                                 (tvolatile tuchar))
                               (tptr (tvolatile tuchar))),
                             (Expr.Ecast
                               (Expr.Ebinop Binop.Oshr
                                 (Expr.Ecast
                                   (Expr.Etempvar ___x86_stw_narrowed__3 tulong)
                                   tulong)
                                 (Expr.Ebinop Binop.Omul
                                   (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                   (Expr.Ecast
                                     (Expr.Econst_int (Integers.Int.repr 4) tint)
                                     tuint) tuint) tulong) tuchar)])
                          Stmt.Sskip))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Etempvar ___x86_stw_width__3 tuchar)
                                              (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                              tint)
                            (Stmt.Sset _t'79
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                tuint))
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                (Expr.Etempvar ___x86_stw_width__3 tuchar)
                                                (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                                tint)
                              s_kprog_x86_store_xmm0_43
                              s_kprog_x86_store_xmm0_44))
                          (Stmt.Sifthenelse (Expr.Ecast
                                              (Expr.Ebinop Binop.Oand
                                                (Expr.Ebinop Binop.Oshr
                                                  (Expr.Etempvar _t'79 tuint)
                                                  (Expr.Econst_int (Integers.Int.repr 5) tint)
                                                  tuint)
                                                (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                                tuint) tuchar)
                            (Stmt.Sbuiltin none
                              (ExtFun.EF_vstore Chunk.Mint8unsigned)
                              [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
                              [(Expr.Eaddrof
                                 (Expr.Ederef
                                   (Expr.Ebinop Binop.Oadd
                                     (Expr.Etempvar ___x86_stw_bytes__3 (tptr (tvolatile tuchar)))
                                     (Expr.Econst_int (Integers.Int.repr 5) tint)
                                     (tptr (tvolatile tuchar)))
                                   (tvolatile tuchar))
                                 (tptr (tvolatile tuchar))),
                               (Expr.Ecast
                                 (Expr.Ebinop Binop.Oshr
                                   (Expr.Ecast
                                     (Expr.Etempvar ___x86_stw_narrowed__3 tulong)
                                     tulong)
                                   (Expr.Ebinop Binop.Omul
                                     (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                     (Expr.Ecast
                                       (Expr.Econst_int (Integers.Int.repr 5) tint)
                                       tuint) tuint) tulong) tuchar)])
                            Stmt.Sskip))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                (Expr.Etempvar ___x86_stw_width__3 tuchar)
                                                (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                                tint)
                              (Stmt.Sset _t'80
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                  tuint))
                              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                  (Expr.Etempvar ___x86_stw_width__3 tuchar)
                                                  (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                                  tint)
                                s_kprog_x86_store_xmm0_45
                                s_kprog_x86_store_xmm0_46))
                            (Stmt.Sifthenelse (Expr.Ecast
                                                (Expr.Ebinop Binop.Oand
                                                  (Expr.Ebinop Binop.Oshr
                                                    (Expr.Etempvar _t'80 tuint)
                                                    (Expr.Econst_int (Integers.Int.repr 6) tint)
                                                    tuint)
                                                  (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                                  tuint) tuchar)
                              (Stmt.Sbuiltin none
                                (ExtFun.EF_vstore Chunk.Mint8unsigned)
                                [(tptr (tvolatile tuchar)),
                                 (tvolatile tuchar)]
                                [(Expr.Eaddrof
                                   (Expr.Ederef
                                     (Expr.Ebinop Binop.Oadd
                                       (Expr.Etempvar ___x86_stw_bytes__3 (tptr (tvolatile tuchar)))
                                       (Expr.Econst_int (Integers.Int.repr 6) tint)
                                       (tptr (tvolatile tuchar)))
                                     (tvolatile tuchar))
                                   (tptr (tvolatile tuchar))),
                                 (Expr.Ecast
                                   (Expr.Ebinop Binop.Oshr
                                     (Expr.Ecast
                                       (Expr.Etempvar ___x86_stw_narrowed__3 tulong)
                                       tulong)
                                     (Expr.Ebinop Binop.Omul
                                       (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                       (Expr.Ecast
                                         (Expr.Econst_int (Integers.Int.repr 6) tint)
                                         tuint) tuint) tulong) tuchar)])
                              Stmt.Sskip))
                          (Stmt.Ssequence
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                (Expr.Etempvar ___x86_stw_width__3 tuchar)
                                                (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                                tint)
                              (Stmt.Sset _t'81
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                  tuint))
                              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                  (Expr.Etempvar ___x86_stw_width__3 tuchar)
                                                  (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                                  tint)
                                s_kprog_x86_store_xmm0_47
                                s_kprog_x86_store_xmm0_48))
                            (Stmt.Sifthenelse (Expr.Ecast
                                                (Expr.Ebinop Binop.Oand
                                                  (Expr.Ebinop Binop.Oshr
                                                    (Expr.Etempvar _t'81 tuint)
                                                    (Expr.Econst_int (Integers.Int.repr 7) tint)
                                                    tuint)
                                                  (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                                  tuint) tuchar)
                              (Stmt.Sbuiltin none
                                (ExtFun.EF_vstore Chunk.Mint8unsigned)
                                [(tptr (tvolatile tuchar)),
                                 (tvolatile tuchar)]
                                [(Expr.Eaddrof
                                   (Expr.Ederef
                                     (Expr.Ebinop Binop.Oadd
                                       (Expr.Etempvar ___x86_stw_bytes__3 (tptr (tvolatile tuchar)))
                                       (Expr.Econst_int (Integers.Int.repr 7) tint)
                                       (tptr (tvolatile tuchar)))
                                     (tvolatile tuchar))
                                   (tptr (tvolatile tuchar))),
                                 (Expr.Ecast
                                   (Expr.Ebinop Binop.Oshr
                                     (Expr.Ecast
                                       (Expr.Etempvar ___x86_stw_narrowed__3 tulong)
                                       tulong)
                                     (Expr.Ebinop Binop.Omul
                                       (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                       (Expr.Ecast
                                         (Expr.Econst_int (Integers.Int.repr 7) tint)
                                         tuint) tuint) tulong) tuchar)])
                              Stmt.Sskip))))))))))))
      Stmt.Sbreak)))

def s_kprog_x86_store_xmm0_50 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Scall (some _t'52)
      (Expr.Evar _x86_width_effective (Ty.Tfunction [tuchar] tuchar
                                        cc_default))
      [(Expr.Econst_int (Integers.Int.repr 8) tuint)])
    (Stmt.Sset ___x86_loss_width__1
      (Expr.Ecast (Expr.Etempvar _t'52 tuchar) tuchar)))
  (Stmt.Ssequence
    (Stmt.Sset ___x86_loss_value__1
      (Expr.Efield
        (Expr.Ederef
          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
          (Ty.Tstruct _x86_sim_register_state noattr)) _xmm0_hi tulong))
    (Stmt.Ssequence
      (Stmt.Sloop
        (Stmt.Ssequence
          (Stmt.Sset ___x86_stw_index__2
            (Expr.Ebinop Binop.Oadd
              (Expr.Ecast (Expr.Etempvar ___x86_loss_off__1 tlong) tulong)
              (Expr.Ecast (Expr.Etempvar _capacity tuint) tulong) tulong))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Scall (some _t'66)
                  (Expr.Evar _x86_width_effective (Ty.Tfunction [tuchar]
                                                    tuchar cc_default))
                  [(Expr.Etempvar ___x86_loss_width__1 tuchar)])
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Etempvar _t'66 tuchar)
                                    (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                    tint)
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Ebinop Binop.Oand
                                        (Expr.Ecast
                                          (Expr.Etempvar ___x86_stw_index__2 tulong)
                                          tulong)
                                        (Expr.Econst_int (Integers.Int.repr 7) tuint)
                                        tulong)
                                      (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Sset _t'67
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 1) tint) tint))
                      (Stmt.Sset _t'67
                        (Expr.Ecast (Expr.Etempvar _t'67 tint) tbool)))
                    (Stmt.Ssequence
                      (Stmt.Sset _t'67
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 0) tint) tint))
                      (Stmt.Sset _t'67
                        (Expr.Ecast (Expr.Etempvar _t'67 tint) tbool))))
                  (Stmt.Sset _t'67
                    (Expr.Econst_int (Integers.Int.repr 0) tint))))
              (Stmt.Sifthenelse (Expr.Etempvar _t'67 tint)
                (Stmt.Sset _t'68
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tint)
                    tint))
                (Stmt.Sset _t'68
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                    tint))))
            (Stmt.Sifthenelse (Expr.Ecast (Expr.Etempvar _t'68 tint) tuchar)
              (Stmt.Ssequence
                (Stmt.Sset _t'130
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
                         (Expr.Etempvar _t'130 (tptr (tvolatile tulong)))
                         (Expr.Ebinop Binop.Oshr
                           (Expr.Ecast
                             (Expr.Etempvar ___x86_stw_index__2 tulong)
                             tulong)
                           (Expr.Econst_int (Integers.Int.repr 3) tint)
                           tulong) (tptr (tvolatile tulong)))
                       (tvolatile tulong)) (tptr (tvolatile tulong))),
                   (Expr.Etempvar ___x86_loss_value__1 tulong)]))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Scall (some _t'64)
                    (Expr.Evar _x86_width_effective (Ty.Tfunction [tuchar]
                                                      tuchar cc_default))
                    [(Expr.Etempvar ___x86_loss_width__1 tuchar)])
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar _t'64 tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                      tint)
                    (Stmt.Sset _t'65
                      (Expr.Ecast
                        (Expr.Ebinop Binop.Oeq
                          (Expr.Ebinop Binop.Oand
                            (Expr.Etempvar ___x86_stw_index__2 tulong)
                            (Expr.Econst_int (Integers.Int.repr 3) tuint)
                            tulong)
                          (Expr.Econst_int (Integers.Int.repr 0) tint) tint)
                        tbool))
                    (Stmt.Sset _t'65
                      (Expr.Econst_int (Integers.Int.repr 0) tint))))
                (Stmt.Sifthenelse (Expr.Etempvar _t'65 tint)
                  (Stmt.Ssequence
                    (Stmt.Sset _t'129
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                          (Ty.Tstruct _kprog_x86_arena noattr)) _d
                        (tptr (tvolatile tuint))))
                    (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint32)
                      [(tptr (tvolatile tuint)), (tvolatile tuint)]
                      [(Expr.Eaddrof
                         (Expr.Ederef
                           (Expr.Ebinop Binop.Oadd
                             (Expr.Etempvar _t'129 (tptr (tvolatile tuint)))
                             (Expr.Ebinop Binop.Odiv
                               (Expr.Etempvar ___x86_stw_index__2 tulong)
                               (Expr.Econst_int (Integers.Int.repr 4) tuint)
                               tulong) (tptr (tvolatile tuint)))
                           (tvolatile tuint)) (tptr (tvolatile tuint))),
                       (Expr.Etempvar ___x86_loss_value__1 tulong)]))
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Scall (some _t'62)
                        (Expr.Evar _x86_width_effective (Ty.Tfunction
                                                          [tuchar] tuchar
                                                          cc_default))
                        [(Expr.Etempvar ___x86_loss_width__1 tuchar)])
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Etempvar _t'62 tuchar)
                                          (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                          tint)
                        (Stmt.Sset _t'63
                          (Expr.Ecast
                            (Expr.Ebinop Binop.Oeq
                              (Expr.Ebinop Binop.Oand
                                (Expr.Etempvar ___x86_stw_index__2 tulong)
                                (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                tulong)
                              (Expr.Econst_int (Integers.Int.repr 0) tint)
                              tint) tbool))
                        (Stmt.Sset _t'63
                          (Expr.Econst_int (Integers.Int.repr 0) tint))))
                    (Stmt.Sifthenelse (Expr.Etempvar _t'63 tint)
                      (Stmt.Ssequence
                        (Stmt.Sset _t'128
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                              (Ty.Tstruct _kprog_x86_arena noattr)) _w
                            (tptr (tvolatile tushort))))
                        (Stmt.Sbuiltin none
                          (ExtFun.EF_vstore Chunk.Mint16unsigned)
                          [(tptr (tvolatile tushort)), (tvolatile tushort)]
                          [(Expr.Eaddrof
                             (Expr.Ederef
                               (Expr.Ebinop Binop.Oadd
                                 (Expr.Etempvar _t'128 (tptr (tvolatile tushort)))
                                 (Expr.Ebinop Binop.Odiv
                                   (Expr.Etempvar ___x86_stw_index__2 tulong)
                                   (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                   tulong) (tptr (tvolatile tushort)))
                               (tvolatile tushort))
                             (tptr (tvolatile tushort))),
                           (Expr.Etempvar ___x86_loss_value__1 tulong)]))
                      (Stmt.Sloop
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Sset _t'127
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                                  (Ty.Tstruct _kprog_x86_arena noattr)) _b
                                (tptr (tvolatile tuchar))))
                            (Stmt.Sset ___x86_stw_bytes__2
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Etempvar _t'127 (tptr (tvolatile tuchar)))
                                (Expr.Etempvar ___x86_stw_index__2 tulong)
                                (tptr (tvolatile tuchar)))))
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Scall (some _t'53)
                                (Expr.Evar _x86_width_effective (Ty.Tfunction
                                                                  [tuchar]
                                                                  tuchar
                                                                  cc_default))
                                [(Expr.Etempvar ___x86_loss_width__1 tuchar)])
                              (Stmt.Sset ___x86_stw_width__2
                                (Expr.Ecast (Expr.Etempvar _t'53 tuchar)
                                  tuchar)))
                            (Stmt.Ssequence
                              (Stmt.Ssequence
                                (Stmt.Scall (some _t'54)
                                  (Expr.Evar _x86_width_mask (Ty.Tfunction
                                                               [tuchar]
                                                               tulong
                                                               cc_default))
                                  [(Expr.Etempvar ___x86_stw_width__2 tuchar)])
                                (Stmt.Sset ___x86_stw_narrowed__2
                                  (Expr.Ebinop Binop.Oand
                                    (Expr.Etempvar ___x86_loss_value__1 tulong)
                                    (Expr.Etempvar _t'54 tulong) tulong)))
                              (Stmt.Ssequence
                                (Stmt.Sbuiltin none
                                  (ExtFun.EF_vstore Chunk.Mint8unsigned)
                                  [(tptr (tvolatile tuchar)),
                                   (tvolatile tuchar)]
                                  [(Expr.Eaddrof
                                     (Expr.Ederef
                                       (Expr.Ebinop Binop.Oadd
                                         (Expr.Etempvar ___x86_stw_bytes__2 (tptr (tvolatile tuchar)))
                                         (Expr.Econst_int (Integers.Int.repr 0) tint)
                                         (tptr (tvolatile tuchar)))
                                       (tvolatile tuchar))
                                     (tptr (tvolatile tuchar))),
                                   (Expr.Ecast
                                     (Expr.Ebinop Binop.Oshr
                                       (Expr.Ecast
                                         (Expr.Etempvar ___x86_stw_narrowed__2 tulong)
                                         tulong)
                                       (Expr.Ebinop Binop.Omul
                                         (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                         (Expr.Ecast
                                           (Expr.Econst_int (Integers.Int.repr 0) tint)
                                           tuint) tuint) tulong) tuchar)])
                                (Stmt.Ssequence
                                  s_kprog_x86_store_xmm0_28
                                  s_kprog_x86_store_xmm0_29)))))
                        Stmt.Sbreak))))))))
        Stmt.Sbreak)
      (Stmt.Ssequence
        (Stmt.Sset _t'121
          (Expr.Efield
            (Expr.Efield
              (Expr.Efield
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                    (Ty.Tstruct _x86_sim_register_state noattr))
                  (Positive.ofNat 18727075383868559167)
                  (Ty.Tunion __3119 noattr))
                (Positive.ofNat 18727075383868559167)
                (Ty.Tstruct __3120 noattr)) _rsp
              (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                            (Expr.Etempvar ___x86_loss_off__1 tlong)
                            (Expr.Ecast
                              (Expr.Ecast (Expr.Etempvar _t'121 (tptr tvoid))
                                tlong) tlong) tint)
          (Stmt.Ssequence
            (Stmt.Sset ___x86_loss_i__1
              (Expr.Econst_int (Integers.Int.repr 0) tint))
            (Stmt.Sloop
              (Stmt.Ssequence
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                    (Expr.Etempvar ___x86_loss_i__1 tuint)
                                    (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                    tint)
                  Stmt.Sskip
                  Stmt.Sbreak)
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                      (Expr.Etempvar ___x86_loss_i__1 tuint)
                                      (Expr.Etempvar ___x86_loss_width__1 tuchar)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Sset _t'126
                        (Expr.Efield
                          (Expr.Efield
                            (Expr.Efield
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                  (Ty.Tstruct _x86_sim_register_state noattr))
                                (Positive.ofNat 18727075383868559167)
                                (Ty.Tunion __3119 noattr))
                              (Positive.ofNat 18727075383868559167)
                              (Ty.Tstruct __3120 noattr)) _rsp
                            (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                          (tptr tvoid)))
                      (Stmt.Sset _t'89
                        (Expr.Ecast
                          (Expr.Ebinop Binop.Olt
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar ___x86_loss_off__1 tlong)
                              (Expr.Etempvar ___x86_loss_i__1 tuint) tlong)
                            (Expr.Ecast
                              (Expr.Ecast (Expr.Etempvar _t'126 (tptr tvoid))
                                tlong) tlong) tint) tbool)))
                    (Stmt.Sset _t'89
                      (Expr.Econst_int (Integers.Int.repr 0) tint)))
                  (Stmt.Sifthenelse (Expr.Etempvar _t'89 tint)
                    (Stmt.Sloop
                      (Stmt.Ssequence
                        (Stmt.Sset ___x86_stw_index__3
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Etempvar ___x86_loss_off__1 tlong)
                                (Expr.Etempvar ___x86_loss_i__1 tuint) tlong)
                              tulong)
                            (Expr.Ecast (Expr.Etempvar _capacity tuint)
                              tulong) tulong))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Scall (some _t'86)
                                (Expr.Evar _x86_width_effective (Ty.Tfunction
                                                                  [tuchar]
                                                                  tuchar
                                                                  cc_default))
                                [(Expr.Econst_int (Integers.Int.repr 1) tuint)])
                              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                  (Expr.Etempvar _t'86 tuchar)
                                                  (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                                  tint)
                                s_kprog_x86_store_xmm0_30
                                (Stmt.Sset _t'87
                                  (Expr.Econst_int (Integers.Int.repr 0) tint))))
                            (Stmt.Sifthenelse (Expr.Etempvar _t'87 tint)
                              (Stmt.Sset _t'88
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 1) tint)
                                  tint))
                              (Stmt.Sset _t'88
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 0) tint)
                                  tint))))
                          (Stmt.Sifthenelse (Expr.Ecast
                                              (Expr.Etempvar _t'88 tint)
                                              tuchar)
                            (Stmt.Ssequence
                              (Stmt.Scall (some _t'69)
                                (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                    [tuint]
                                                                    tulong
                                                                    cc_default))
                                [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                              (Stmt.Ssequence
                                (Stmt.Sset _t'125
                                  (Expr.Efield
                                    (Expr.Ederef
                                      (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                                      (Ty.Tstruct _kprog_x86_arena noattr))
                                    _q (tptr (tvolatile tulong))))
                                (Stmt.Sbuiltin none
                                  (ExtFun.EF_vstore Chunk.Mint64)
                                  [(tptr (tvolatile tulong)),
                                   (tvolatile tulong)]
                                  [(Expr.Eaddrof
                                     (Expr.Ederef
                                       (Expr.Ebinop Binop.Oadd
                                         (Expr.Etempvar _t'125 (tptr (tvolatile tulong)))
                                         (Expr.Ebinop Binop.Oshr
                                           (Expr.Ecast
                                             (Expr.Etempvar ___x86_stw_index__3 tulong)
                                             tulong)
                                           (Expr.Econst_int (Integers.Int.repr 3) tint)
                                           tulong) (tptr (tvolatile tulong)))
                                       (tvolatile tulong))
                                     (tptr (tvolatile tulong))),
                                   (Expr.Etempvar _t'69 tulong)])))
                            (Stmt.Ssequence
                              (Stmt.Ssequence
                                s_kprog_x86_store_xmm0_31
                                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                    (Expr.Etempvar _t'84 tuchar)
                                                    (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                                    tint)
                                  s_kprog_x86_store_xmm0_32
                                  (Stmt.Sset _t'85
                                    (Expr.Econst_int (Integers.Int.repr 0) tint))))
                              (Stmt.Sifthenelse (Expr.Etempvar _t'85 tint)
                                s_kprog_x86_store_xmm0_33
                                s_kprog_x86_store_xmm0_49)))))
                      Stmt.Sbreak)
                    Stmt.Sskip)))
              (Stmt.Sset ___x86_loss_i__1
                (Expr.Ebinop Binop.Oadd
                  (Expr.Etempvar ___x86_loss_i__1 tuint)
                  (Expr.Econst_int (Integers.Int.repr 1) tint) tuint))))
          Stmt.Sskip)))))

def s_kprog_x86_store_xmm0_51 : Stmt :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'92)
    (Expr.Evar _tag_of (Ty.Tfunction
                         [(tptr (Ty.Tstruct _x86_sim_register_state noattr)),
                          tulong] tuchar cc_default))
    [(Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
     (Expr.Etempvar _dst tulong)])
  (Stmt.Sset ___x86_st_tag (Expr.Ecast (Expr.Etempvar _t'92 tuchar) tuchar)))

def s_kprog_x86_store_xmm0_52 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'119
    (Expr.Efield
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
          (Expr.Etempvar ___x86_sv_i__2 tuint)
          (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
        (Ty.Tstruct _kprog_x86_stack_fact noattr)) _tag (tptr tuchar)))
  (Stmt.Sassign (Expr.Ederef (Expr.Etempvar _t'119 (tptr tuchar)) tuchar)
    (Expr.Econst_int (Integers.Int.repr 0) tuint)))

def s_kprog_x86_store_xmm0_53 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'118
    (Expr.Efield
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
          (Expr.Etempvar ___x86_sv_i__2 tuint)
          (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
        (Ty.Tstruct _kprog_x86_stack_fact noattr)) _pointer
      (tptr (tptr tvoid))))
  (Stmt.Sassign
    (Expr.Ederef (Expr.Etempvar _t'118 (tptr (tptr tvoid))) (tptr tvoid))
    (Expr.Econst_int (Integers.Int.repr 0) tint)))

def s_kprog_x86_store_xmm0_54 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_st_value
    (Expr.Efield
      (Expr.Ederef
        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
        (Ty.Tstruct _x86_sim_register_state noattr)) _xmm0_lo tulong))
  (Stmt.Ssequence
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                        (Expr.Etempvar ___x86_st_tag tuchar)
                        (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
      (Stmt.Sloop
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sset _t'120
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                  (Ty.Tstruct _kprog_x86_arena noattr)) _b
                (tptr (tvolatile tuchar))))
            (Stmt.Sset ___x86_sv_index__2
              (Expr.Ebinop Binop.Osub
                (Expr.Ecast
                  (Expr.Ecast (Expr.Etempvar ___x86_st_addr (tptr tvoid))
                    tlong) tulong)
                (Expr.Ecast
                  (Expr.Ecast
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Etempvar _t'120 (tptr (tvolatile tuchar)))
                      (Expr.Econst_int (Integers.Int.repr 0) tint)
                      (tptr (tvolatile tuchar))) tlong) tulong) tulong)))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Scall (some _t'93)
                (Expr.Evar _x86_width_effective (Ty.Tfunction [tuchar] tuchar
                                                  cc_default))
                [(Expr.Etempvar ___x86_st_width tuchar)])
              (Stmt.Sset ___x86_sv_width__2
                (Expr.Ecast (Expr.Etempvar _t'93 tuchar) tulong)))
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
                    (Stmt.Ssequence
                      (Stmt.Sset ___x86_sv_start__2
                        (Expr.Ebinop Binop.Omul
                          (Expr.Ecast (Expr.Etempvar ___x86_sv_i__2 tuint)
                            tulong)
                          (Expr.Econst_int (Integers.Int.repr 8) tuint)
                          tulong))
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                            (Expr.Ebinop Binop.Osub
                                              (Expr.Etempvar ___x86_sv_index__2 tulong)
                                              (Expr.Etempvar ___x86_sv_start__2 tulong)
                                              tulong)
                                            (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                            tint)
                          (Stmt.Sset _t'94
                            (Expr.Econst_int (Integers.Int.repr 1) tint))
                          (Stmt.Sset _t'94
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Olt
                                (Expr.Ebinop Binop.Osub
                                  (Expr.Etempvar ___x86_sv_start__2 tulong)
                                  (Expr.Etempvar ___x86_sv_index__2 tulong)
                                  tulong)
                                (Expr.Etempvar ___x86_sv_width__2 tulong)
                                tint) tbool)))
                        (Stmt.Sifthenelse (Expr.Etempvar _t'94 tint)
                          (Stmt.Sloop
                            (Stmt.Ssequence
                              s_kprog_x86_store_xmm0_52
                              s_kprog_x86_store_xmm0_53)
                            Stmt.Sbreak)
                          Stmt.Sskip)))
                    Stmt.Sbreak))
                (Stmt.Sset ___x86_sv_i__2
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Etempvar ___x86_sv_i__2 tuint)
                    (Expr.Econst_int (Integers.Int.repr 1) tint) tuint))))))
        Stmt.Sbreak)
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                          (Expr.Etempvar ___x86_st_tag tuchar)
                          (Expr.Econst_int (Integers.Int.repr 0) tuint) tint)
        (Stmt.Sloop
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
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sset _t'117
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                              (Expr.Etempvar ___x86_sv_i__3 tuint)
                              (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                            (Ty.Tstruct _kprog_x86_stack_fact noattr)) _tag
                          (tptr tuchar)))
                      (Stmt.Sassign
                        (Expr.Ederef (Expr.Etempvar _t'117 (tptr tuchar))
                          tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tuint)))
                    (Stmt.Ssequence
                      (Stmt.Sset _t'116
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                              (Expr.Etempvar ___x86_sv_i__3 tuint)
                              (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                            (Ty.Tstruct _kprog_x86_stack_fact noattr))
                          _pointer (tptr (tptr tvoid))))
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Etempvar _t'116 (tptr (tptr tvoid)))
                          (tptr tvoid))
                        (Expr.Econst_int (Integers.Int.repr 0) tint))))
                  Stmt.Sbreak))
              (Stmt.Sset ___x86_sv_i__3
                (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_sv_i__3 tuint)
                  (Expr.Econst_int (Integers.Int.repr 1) tint) tuint))))
          Stmt.Sbreak)
        Stmt.Sskip))
    (Stmt.Ssequence
      (Stmt.Scall none
        (Expr.Evar _kprog_x86_mem_store (Ty.Tfunction
                                          [(tptr tvoid), tuchar, tulong]
                                          tvoid cc_default))
        [(Expr.Etempvar ___x86_st_addr (tptr tvoid)),
         (Expr.Etempvar ___x86_st_width tuchar),
         (Expr.Etempvar ___x86_st_value tulong)])
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                          (Expr.Etempvar ___x86_st_tag tuchar)
                          (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
        (Stmt.Ssequence
          (Stmt.Sloop
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'115
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                      (Ty.Tstruct _kprog_x86_arena noattr)) _b
                    (tptr (tvolatile tuchar))))
                (Stmt.Sset ___x86_alias_delta
                  (Expr.Ebinop Binop.Osub
                    (Expr.Ecast
                      (Expr.Ecast (Expr.Etempvar ___x86_st_addr (tptr tvoid))
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
                                      (Expr.Etempvar _t'115 (tptr (tvolatile tuchar)))
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
              (Stmt.Sset ___x86_st_off
                (Expr.Ecast (Expr.Etempvar ___x86_alias_delta tulong) tlong)))
            Stmt.Sbreak)
          (Stmt.Ssequence
            (Stmt.Sset _t'113
              (Expr.Efield
                (Expr.Efield
                  (Expr.Efield
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                        (Ty.Tstruct _x86_sim_register_state noattr))
                      (Positive.ofNat 18727075383868559167)
                      (Ty.Tunion __3119 noattr))
                    (Positive.ofNat 18727075383868559167)
                    (Ty.Tstruct __3120 noattr)) _rsp
                  (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                (Expr.Etempvar ___x86_st_off tlong)
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Etempvar _t'113 (tptr tvoid))
                                    tlong) tlong) tint)
              (Stmt.Ssequence
                (Stmt.Sset ___x86_st_i
                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                        (Expr.Etempvar ___x86_st_i tuint)
                                        (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                        tint)
                      Stmt.Sskip
                      Stmt.Sbreak)
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Scall (some _t'96)
                          (Expr.Evar _x86_width_effective (Ty.Tfunction
                                                            [tuchar] tuchar
                                                            cc_default))
                          [(Expr.Etempvar ___x86_st_width tuchar)])
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                            (Expr.Etempvar ___x86_st_i tuint)
                                            (Expr.Etempvar _t'96 tuchar)
                                            tint)
                          (Stmt.Ssequence
                            (Stmt.Sset _t'114
                              (Expr.Efield
                                (Expr.Efield
                                  (Expr.Efield
                                    (Expr.Efield
                                      (Expr.Ederef
                                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                                        (Ty.Tstruct _x86_sim_register_state noattr))
                                      (Positive.ofNat 18727075383868559167)
                                      (Ty.Tunion __3119 noattr))
                                    (Positive.ofNat 18727075383868559167)
                                    (Ty.Tstruct __3120 noattr)) _rsp
                                  (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                                (tptr tvoid)))
                            (Stmt.Sset _t'97
                              (Expr.Ecast
                                (Expr.Ebinop Binop.Olt
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Etempvar ___x86_st_off tlong)
                                    (Expr.Etempvar ___x86_st_i tuint) tlong)
                                  (Expr.Ecast
                                    (Expr.Ecast
                                      (Expr.Etempvar _t'114 (tptr tvoid))
                                      tlong) tlong) tint) tbool)))
                          (Stmt.Sset _t'97
                            (Expr.Econst_int (Integers.Int.repr 0) tint))))
                      (Stmt.Sifthenelse (Expr.Etempvar _t'97 tint)
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'95)
                            (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                 [tuint]
                                                                 tulong
                                                                 cc_default))
                            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                          (Stmt.Sbuiltin none
                            (ExtFun.EF_vstore Chunk.Mint8unsigned)
                            [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
                            [(Expr.Eaddrof
                               (Expr.Ederef
                                 (Expr.Ebinop Binop.Oadd
                                   (Expr.Ecast
                                     (Expr.Etempvar ___x86_st_addr (tptr tvoid))
                                     (tptr (tvolatile tuchar)))
                                   (Expr.Etempvar ___x86_st_i tuint)
                                   (tptr (tvolatile tuchar)))
                                 (tvolatile tuchar))
                               (tptr (tvolatile tuchar))),
                             (Expr.Ecast (Expr.Etempvar _t'95 tulong) tuchar)]))
                        Stmt.Sskip)))
                  (Stmt.Sset ___x86_st_i
                    (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_st_i tuint)
                      (Expr.Econst_int (Integers.Int.repr 1) tint) tuint))))
              Stmt.Sskip)))
        Stmt.Sskip))))

def s_kprog_x86_store_xmm0_55 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                    (Expr.Econst_int (Integers.Int.repr 1) tint)
                    (Expr.Econst_int (Integers.Int.repr 0) tuint) tint)
  (Stmt.Sset _t'98
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuint))
  (Stmt.Sset _t'98
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint)))

def s_kprog_x86_store_xmm0_56 : Stmt :=
(Stmt.Sset ___x86_st_width__1
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 8) tuint) tuchar))

def s_kprog_x86_store_xmm0_57 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'111
    (Expr.Efield
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
          (Expr.Etempvar ___x86_sv_i__4 tuint)
          (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
        (Ty.Tstruct _kprog_x86_stack_fact noattr)) _tag (tptr tuchar)))
  (Stmt.Sassign (Expr.Ederef (Expr.Etempvar _t'111 (tptr tuchar)) tuchar)
    (Expr.Econst_int (Integers.Int.repr 0) tuint)))

def s_kprog_x86_store_xmm0_58 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'110
    (Expr.Efield
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
          (Expr.Etempvar ___x86_sv_i__4 tuint)
          (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
        (Ty.Tstruct _kprog_x86_stack_fact noattr)) _pointer
      (tptr (tptr tvoid))))
  (Stmt.Sassign
    (Expr.Ederef (Expr.Etempvar _t'110 (tptr (tptr tvoid))) (tptr tvoid))
    (Expr.Econst_int (Integers.Int.repr 0) tint)))

def s_kprog_x86_store_xmm0_59 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'106
    (Expr.Efield
      (Expr.Efield
        (Expr.Efield
          (Expr.Efield
            (Expr.Ederef
              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
              (Ty.Tstruct _x86_sim_register_state noattr))
            (Positive.ofNat 18727075383868559167) (Ty.Tunion __3119 noattr))
          (Positive.ofNat 18727075383868559167) (Ty.Tstruct __3120 noattr))
        _rsp (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
  (Stmt.Sset _t'104
    (Expr.Ecast
      (Expr.Ebinop Binop.Olt
        (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_st_off__1 tlong)
          (Expr.Etempvar ___x86_st_i__1 tuint) tlong)
        (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'106 (tptr tvoid)) tlong)
          tlong) tint) tbool)))

def s_kprog_x86_store_xmm0_60 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Scall (some _t'99)
      (Expr.Evar _tag_of (Ty.Tfunction
                           [(tptr (Ty.Tstruct _x86_sim_register_state noattr)),
                            tulong] tuchar cc_default))
      [(Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
       (Expr.Etempvar _dst tulong)])
    (Stmt.Sset ___x86_st_tag__1
      (Expr.Ecast (Expr.Etempvar _t'99 tuchar) tuchar)))
  (Stmt.Ssequence
    (Stmt.Sset ___x86_st_value__1
      (Expr.Efield
        (Expr.Ederef
          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
          (Ty.Tstruct _x86_sim_register_state noattr)) _xmm0_hi tulong))
    (Stmt.Ssequence
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                          (Expr.Etempvar ___x86_st_tag__1 tuchar)
                          (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
        (Stmt.Sloop
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sset _t'112
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                    (Ty.Tstruct _kprog_x86_arena noattr)) _b
                  (tptr (tvolatile tuchar))))
              (Stmt.Sset ___x86_sv_index__3
                (Expr.Ebinop Binop.Osub
                  (Expr.Ecast
                    (Expr.Ecast
                      (Expr.Etempvar ___x86_st_addr__1 (tptr tvoid)) tlong)
                    tulong)
                  (Expr.Ecast
                    (Expr.Ecast
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar _t'112 (tptr (tvolatile tuchar)))
                        (Expr.Econst_int (Integers.Int.repr 0) tint)
                        (tptr (tvolatile tuchar))) tlong) tulong) tulong)))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Scall (some _t'100)
                  (Expr.Evar _x86_width_effective (Ty.Tfunction [tuchar]
                                                    tuchar cc_default))
                  [(Expr.Etempvar ___x86_st_width__1 tuchar)])
                (Stmt.Sset ___x86_sv_width__3
                  (Expr.Ecast (Expr.Etempvar _t'100 tuchar) tulong)))
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
                                              (Expr.Etempvar _capacity tuint)
                                              tulong)
                                            (Expr.Econst_int (Integers.Int.repr 7) tuint)
                                            tulong)
                                          (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                          tulong) tint)
                      Stmt.Sskip
                      Stmt.Sbreak)
                    (Stmt.Sloop
                      (Stmt.Ssequence
                        (Stmt.Sset ___x86_sv_start__3
                          (Expr.Ebinop Binop.Omul
                            (Expr.Ecast (Expr.Etempvar ___x86_sv_i__4 tuint)
                              tulong)
                            (Expr.Econst_int (Integers.Int.repr 8) tuint)
                            tulong))
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                              (Expr.Ebinop Binop.Osub
                                                (Expr.Etempvar ___x86_sv_index__3 tulong)
                                                (Expr.Etempvar ___x86_sv_start__3 tulong)
                                                tulong)
                                              (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                              tint)
                            (Stmt.Sset _t'101
                              (Expr.Econst_int (Integers.Int.repr 1) tint))
                            (Stmt.Sset _t'101
                              (Expr.Ecast
                                (Expr.Ebinop Binop.Olt
                                  (Expr.Ebinop Binop.Osub
                                    (Expr.Etempvar ___x86_sv_start__3 tulong)
                                    (Expr.Etempvar ___x86_sv_index__3 tulong)
                                    tulong)
                                  (Expr.Etempvar ___x86_sv_width__3 tulong)
                                  tint) tbool)))
                          (Stmt.Sifthenelse (Expr.Etempvar _t'101 tint)
                            (Stmt.Sloop
                              (Stmt.Ssequence
                                s_kprog_x86_store_xmm0_57
                                s_kprog_x86_store_xmm0_58)
                              Stmt.Sbreak)
                            Stmt.Sskip)))
                      Stmt.Sbreak))
                  (Stmt.Sset ___x86_sv_i__4
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Etempvar ___x86_sv_i__4 tuint)
                      (Expr.Econst_int (Integers.Int.repr 1) tint) tuint))))))
          Stmt.Sbreak)
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar ___x86_st_tag__1 tuchar)
                            (Expr.Econst_int (Integers.Int.repr 0) tuint)
                            tint)
          (Stmt.Sloop
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
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sset _t'109
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                                (Expr.Etempvar ___x86_sv_i__5 tuint)
                                (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                              (Ty.Tstruct _kprog_x86_stack_fact noattr)) _tag
                            (tptr tuchar)))
                        (Stmt.Sassign
                          (Expr.Ederef (Expr.Etempvar _t'109 (tptr tuchar))
                            tuchar)
                          (Expr.Econst_int (Integers.Int.repr 0) tuint)))
                      (Stmt.Ssequence
                        (Stmt.Sset _t'108
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Etempvar _facts (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                                (Expr.Etempvar ___x86_sv_i__5 tuint)
                                (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)))
                              (Ty.Tstruct _kprog_x86_stack_fact noattr))
                            _pointer (tptr (tptr tvoid))))
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Etempvar _t'108 (tptr (tptr tvoid)))
                            (tptr tvoid))
                          (Expr.Econst_int (Integers.Int.repr 0) tint))))
                    Stmt.Sbreak))
                (Stmt.Sset ___x86_sv_i__5
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Etempvar ___x86_sv_i__5 tuint)
                    (Expr.Econst_int (Integers.Int.repr 1) tint) tuint))))
            Stmt.Sbreak)
          Stmt.Sskip))
      (Stmt.Ssequence
        (Stmt.Scall none
          (Expr.Evar _kprog_x86_mem_store (Ty.Tfunction
                                            [(tptr tvoid), tuchar, tulong]
                                            tvoid cc_default))
          [(Expr.Etempvar ___x86_st_addr__1 (tptr tvoid)),
           (Expr.Etempvar ___x86_st_width__1 tuchar),
           (Expr.Etempvar ___x86_st_value__1 tulong)])
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar ___x86_st_tag__1 tuchar)
                            (Expr.Econst_int (Integers.Int.repr 4) tuint)
                            tint)
          (Stmt.Ssequence
            (Stmt.Sloop
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sset _t'107
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr)))
                        (Ty.Tstruct _kprog_x86_arena noattr)) _b
                      (tptr (tvolatile tuchar))))
                  (Stmt.Sset ___x86_alias_delta__1
                    (Expr.Ebinop Binop.Osub
                      (Expr.Ecast
                        (Expr.Ecast
                          (Expr.Etempvar ___x86_st_addr__1 (tptr tvoid))
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
                                        (Expr.Etempvar _t'107 (tptr (tvolatile tuchar)))
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
                (Stmt.Sset ___x86_st_off__1
                  (Expr.Ecast (Expr.Etempvar ___x86_alias_delta__1 tulong)
                    tlong)))
              Stmt.Sbreak)
            (Stmt.Ssequence
              (Stmt.Sset _t'105
                (Expr.Efield
                  (Expr.Efield
                    (Expr.Efield
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                          (Ty.Tstruct _x86_sim_register_state noattr))
                        (Positive.ofNat 18727075383868559167)
                        (Ty.Tunion __3119 noattr))
                      (Positive.ofNat 18727075383868559167)
                      (Ty.Tstruct __3120 noattr)) _rsp
                    (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                  (Expr.Etempvar ___x86_st_off__1 tlong)
                                  (Expr.Ecast
                                    (Expr.Ecast
                                      (Expr.Etempvar _t'105 (tptr tvoid))
                                      tlong) tlong) tint)
                (Stmt.Ssequence
                  (Stmt.Sset ___x86_st_i__1
                    (Expr.Econst_int (Integers.Int.repr 0) tint))
                  (Stmt.Sloop
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                          (Expr.Etempvar ___x86_st_i__1 tuint)
                                          (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                          tint)
                        Stmt.Sskip
                        Stmt.Sbreak)
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'103)
                            (Expr.Evar _x86_width_effective (Ty.Tfunction
                                                              [tuchar] tuchar
                                                              cc_default))
                            [(Expr.Etempvar ___x86_st_width__1 tuchar)])
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                              (Expr.Etempvar ___x86_st_i__1 tuint)
                                              (Expr.Etempvar _t'103 tuchar)
                                              tint)
                            s_kprog_x86_store_xmm0_59
                            (Stmt.Sset _t'104
                              (Expr.Econst_int (Integers.Int.repr 0) tint))))
                        (Stmt.Sifthenelse (Expr.Etempvar _t'104 tint)
                          (Stmt.Ssequence
                            (Stmt.Scall (some _t'102)
                              (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                   [tuint]
                                                                   tulong
                                                                   cc_default))
                              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                            (Stmt.Sbuiltin none
                              (ExtFun.EF_vstore Chunk.Mint8unsigned)
                              [(tptr (tvolatile tuchar)), (tvolatile tuchar)]
                              [(Expr.Eaddrof
                                 (Expr.Ederef
                                   (Expr.Ebinop Binop.Oadd
                                     (Expr.Ecast
                                       (Expr.Etempvar ___x86_st_addr__1 (tptr tvoid))
                                       (tptr (tvolatile tuchar)))
                                     (Expr.Etempvar ___x86_st_i__1 tuint)
                                     (tptr (tvolatile tuchar)))
                                   (tvolatile tuchar))
                                 (tptr (tvolatile tuchar))),
                               (Expr.Ecast (Expr.Etempvar _t'102 tulong)
                                 tuchar)]))
                          Stmt.Sskip)))
                    (Stmt.Sset ___x86_st_i__1
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar ___x86_st_i__1 tuint)
                        (Expr.Econst_int (Integers.Int.repr 1) tint) tuint))))
                Stmt.Sskip)))
          Stmt.Sskip)))))

def f_kprog_x86_store_xmm0 : Function := {
  fn_return := tvoid,
  fn_callconv := cc_default,
  fn_params := [(_state, (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
                (_arena, (tptr (Ty.Tstruct _kprog_x86_arena noattr))),
                (_facts, (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr))),
                (_capacity, tuint), (_dst, tulong), (_aux, tulong),
                (_imm, tulong)],
  fn_vars := [],
  fn_temps := [(___x86_state,
                (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
               (___x86_l_disp, tlong), (___x86_l_arm, tuchar),
               (___x86_l_base_none, tuchar), (___x86_l_base_form, tuchar),
               (___x86_l_base_ptr, (tptr tvoid)), (___x86_sv_index, tulong),
               (___x86_sv_width, tulong), (___x86_sv_i, tuint),
               (___x86_sv_start, tulong), (___x86_loss_off, tlong),
               (___x86_loss_width, tuchar), (___x86_loss_value, tulong),
               (___x86_stw_index, tulong),
               (___x86_stw_bytes, (tptr (tvolatile tuchar))),
               (___x86_stw_width, tuchar), (___x86_stw_narrowed, tulong),
               (___x86_loss_i, tuint), (___x86_stw_index__1, tulong),
               (___x86_stw_bytes__1, (tptr (tvolatile tuchar))),
               (___x86_stw_width__1, tuchar),
               (___x86_stw_narrowed__1, tulong),
               (___x86_sv_index__1, tulong), (___x86_sv_width__1, tulong),
               (___x86_sv_i__1, tuint), (___x86_sv_start__1, tulong),
               (___x86_loss_off__1, tlong), (___x86_loss_width__1, tuchar),
               (___x86_loss_value__1, tulong), (___x86_stw_index__2, tulong),
               (___x86_stw_bytes__2, (tptr (tvolatile tuchar))),
               (___x86_stw_width__2, tuchar),
               (___x86_stw_narrowed__2, tulong), (___x86_loss_i__1, tuint),
               (___x86_stw_index__3, tulong),
               (___x86_stw_bytes__3, (tptr (tvolatile tuchar))),
               (___x86_stw_width__3, tuchar),
               (___x86_stw_narrowed__3, tulong),
               (___x86_l_addr, (tptr tvoid)), (___x86_st_addr, (tptr tvoid)),
               (___x86_st_width, tuchar), (___x86_st_tag, tuchar),
               (___x86_st_value, tulong), (___x86_sv_index__2, tulong),
               (___x86_sv_width__2, tulong), (___x86_sv_i__2, tuint),
               (___x86_sv_start__2, tulong), (___x86_sv_i__3, tuint),
               (___x86_st_off, tlong), (___x86_alias_delta, tulong),
               (___x86_st_i, tuint), (___x86_st_addr__1, (tptr tvoid)),
               (___x86_st_width__1, tuchar), (___x86_st_tag__1, tuchar),
               (___x86_st_value__1, tulong), (___x86_sv_index__3, tulong),
               (___x86_sv_width__3, tulong), (___x86_sv_i__4, tuint),
               (___x86_sv_start__3, tulong), (___x86_sv_i__5, tuint),
               (___x86_st_off__1, tlong), (___x86_alias_delta__1, tulong),
               (___x86_st_i__1, tuint), (_t'104, tint), (_t'103, tuchar),
               (_t'102, tulong), (_t'101, tint), (_t'100, tuchar),
               (_t'99, tuchar), (_t'98, tuint), (_t'97, tint),
               (_t'96, tuchar), (_t'95, tulong), (_t'94, tint),
               (_t'93, tuchar), (_t'92, tuchar), (_t'91, (tptr tvoid)),
               (_t'90, tuint), (_t'89, tint), (_t'88, tint), (_t'87, tint),
               (_t'86, tuchar), (_t'85, tint), (_t'84, tuchar),
               (_t'83, tint), (_t'82, tuchar), (_t'81, tuint),
               (_t'80, tuint), (_t'79, tuint), (_t'78, tuint),
               (_t'77, tuint), (_t'76, tuint), (_t'75, tuint),
               (_t'74, tulong), (_t'73, tulong), (_t'72, tuchar),
               (_t'71, tulong), (_t'70, tulong), (_t'69, tulong),
               (_t'68, tint), (_t'67, tint), (_t'66, tuchar), (_t'65, tint),
               (_t'64, tuchar), (_t'63, tint), (_t'62, tuchar),
               (_t'61, tuint), (_t'60, tuint), (_t'59, tuint),
               (_t'58, tuint), (_t'57, tuint), (_t'56, tuint),
               (_t'55, tuint), (_t'54, tulong), (_t'53, tuchar),
               (_t'52, tuchar), (_t'51, tuint), (_t'50, tint),
               (_t'49, tuchar), (_t'48, tuint), (_t'47, tint), (_t'46, tint),
               (_t'45, tint), (_t'44, tuchar), (_t'43, tint),
               (_t'42, tuchar), (_t'41, tint), (_t'40, tuchar),
               (_t'39, tuint), (_t'38, tuint), (_t'37, tuint),
               (_t'36, tuint), (_t'35, tuint), (_t'34, tuint),
               (_t'33, tuint), (_t'32, tulong), (_t'31, tulong),
               (_t'30, tuchar), (_t'29, tulong), (_t'28, tulong),
               (_t'27, tulong), (_t'26, tint), (_t'25, tint),
               (_t'24, tuchar), (_t'23, tint), (_t'22, tuchar),
               (_t'21, tint), (_t'20, tuchar), (_t'19, tuint),
               (_t'18, tuint), (_t'17, tuint), (_t'16, tuint),
               (_t'15, tuint), (_t'14, tuint), (_t'13, tuint),
               (_t'12, tulong), (_t'11, tuchar), (_t'10, tuchar),
               (_t'9, tint), (_t'8, tuchar), (_t'7, (tptr tvoid)),
               (_t'6, (tptr tvoid)), (_t'5, tuint), (_t'4, tint),
               (_t'3, tuchar), (_t'2, tlong), (_t'1, tlong),
               (_t'145, (tptr tvoid)), (_t'144, (tptr tuchar)),
               (_t'143, (tptr (tptr tvoid))),
               (_t'142, (tptr (tvolatile tulong))),
               (_t'141, (tptr (tvolatile tuint))),
               (_t'140, (tptr (tvolatile tushort))),
               (_t'139, (tptr (tvolatile tuchar))), (_t'138, (tptr tvoid)),
               (_t'137, (tptr (tvolatile tulong))),
               (_t'136, (tptr (tvolatile tuint))),
               (_t'135, (tptr (tvolatile tushort))),
               (_t'134, (tptr (tvolatile tuchar))), (_t'133, (tptr tvoid)),
               (_t'132, (tptr tuchar)), (_t'131, (tptr (tptr tvoid))),
               (_t'130, (tptr (tvolatile tulong))),
               (_t'129, (tptr (tvolatile tuint))),
               (_t'128, (tptr (tvolatile tushort))),
               (_t'127, (tptr (tvolatile tuchar))), (_t'126, (tptr tvoid)),
               (_t'125, (tptr (tvolatile tulong))),
               (_t'124, (tptr (tvolatile tuint))),
               (_t'123, (tptr (tvolatile tushort))),
               (_t'122, (tptr (tvolatile tuchar))), (_t'121, (tptr tvoid)),
               (_t'120, (tptr (tvolatile tuchar))), (_t'119, (tptr tuchar)),
               (_t'118, (tptr (tptr tvoid))), (_t'117, (tptr tuchar)),
               (_t'116, (tptr (tptr tvoid))),
               (_t'115, (tptr (tvolatile tuchar))), (_t'114, (tptr tvoid)),
               (_t'113, (tptr tvoid)), (_t'112, (tptr (tvolatile tuchar))),
               (_t'111, (tptr tuchar)), (_t'110, (tptr (tptr tvoid))),
               (_t'109, (tptr tuchar)), (_t'108, (tptr (tptr tvoid))),
               (_t'107, (tptr (tvolatile tuchar))), (_t'106, (tptr tvoid)),
               (_t'105, (tptr tvoid))],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_state
    (Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))))
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Scall (some _t'1)
            (Expr.Evar _x86_simm (Ty.Tfunction [tulong] tlong cc_default))
            [(Expr.Etempvar _imm tulong)])
          (Stmt.Scall (some _t'2)
            (Expr.Evar _kprog_x86_mem_offset (Ty.Tfunction
                                               [(tptr (Ty.Tstruct _x86_sim_register_state noattr)),
                                                (tptr (Ty.Tstruct _kprog_x86_arena noattr)),
                                                tuint, tulong, tlong] tlong
                                               cc_default))
            [(Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
             (Expr.Etempvar _arena (tptr (Ty.Tstruct _kprog_x86_arena noattr))),
             (Expr.Etempvar _capacity tuint), (Expr.Etempvar _aux tulong),
             (Expr.Etempvar _t'1 tlong)]))
        (Stmt.Sset ___x86_l_disp (Expr.Etempvar _t'2 tlong)))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Scall (some _t'3)
            (Expr.Evar _kprog_x86_xmm0_arm (Ty.Tfunction [tulong] tuchar
                                             cc_default))
            [(Expr.Ebinop Binop.Oeq (Expr.Etempvar _dst tulong)
               (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)])
          (Stmt.Sset ___x86_l_arm
            (Expr.Ecast (Expr.Etempvar _t'3 tuchar) tuchar)))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Etempvar _dst tulong)
                                (Expr.Econst_int (Integers.Int.repr 255) tuint)
                                tint)
              (Stmt.Sset _t'4
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tint)
                  tint))
              (Stmt.Sset _t'4
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                  tint)))
            (Stmt.Sset ___x86_l_base_none
              (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'4 tint) tuchar)
                tuchar)))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sset _t'5
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint)
                  tuint))
              (Stmt.Sset ___x86_l_base_form
                (Expr.Ecast (Expr.Etempvar _t'5 tuint) tuchar)))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sifthenelse (Expr.Etempvar ___x86_l_base_none tuchar)
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar ___x86_l_base_form tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Sset _t'6
                        (Expr.Ecast
                          (Expr.Ecast
                            (Expr.Ecast (Expr.Etempvar _imm tulong) tlong)
                            (tptr tvoid)) (tptr tvoid)))
                      (Stmt.Sset _t'6
                        (Expr.Ecast (Expr.Etempvar _t'6 (tptr tvoid))
                          (tptr tvoid))))
                    (Stmt.Ssequence
                      (Stmt.Sset _t'6
                        (Expr.Ecast
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                            (tptr tvoid)) (tptr tvoid)))
                      (Stmt.Sset _t'6
                        (Expr.Ecast (Expr.Etempvar _t'6 (tptr tvoid))
                          (tptr tvoid)))))
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                        (Expr.Ecast
                                          (Expr.Etempvar _dst tulong) tulong)
                                        (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                        tint)
                      (Stmt.Ssequence
                        (Stmt.Sset _t'145
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
                                      (Ty.Tunion __3119 noattr)) _gpr_cells
                                    (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))
                                  (Expr.Ecast (Expr.Etempvar _dst tulong)
                                    tuchar)
                                  (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                                (Ty.Tstruct _x86_sim_gpr_cell noattr)) _value
                              (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                            (tptr tvoid)))
                        (Stmt.Sset _t'7
                          (Expr.Ecast (Expr.Etempvar _t'145 (tptr tvoid))
                            (tptr tvoid))))
                      (Stmt.Sset _t'7
                        (Expr.Ecast
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                            (tptr tvoid)) (tptr tvoid))))
                    (Stmt.Sset _t'6
                      (Expr.Ecast
                        (Expr.Ecast (Expr.Etempvar _t'7 (tptr tvoid))
                          (tptr tvoid)) (tptr tvoid)))))
                (Stmt.Sset ___x86_l_base_ptr
                  (Expr.Etempvar _t'6 (tptr tvoid))))
              (Stmt.Sswitch (Expr.Etempvar ___x86_l_arm tuchar)
                (LStmts.LScons (some 0)
                  (Stmt.Ssequence
                    (Stmt.Sloop
                      (Stmt.Ssequence
                        (Stmt.Sloop
                          (Stmt.Ssequence
                            (Stmt.Sset ___x86_sv_index
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Ecast
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Ecast
                                      (Expr.Ecast
                                        (Expr.Etempvar ___x86_l_base_ptr (tptr tvoid))
                                        tlong) tlong)
                                    (Expr.Etempvar ___x86_l_disp tlong)
                                    tlong) tulong)
                                (Expr.Ecast (Expr.Etempvar _capacity tuint)
                                  tulong) tulong))
                            (Stmt.Ssequence
                              s_kprog_x86_store_xmm0_0
                              s_kprog_x86_store_xmm0_1))
                          Stmt.Sbreak)
                        (Stmt.Sloop
                          (Stmt.Ssequence
                            (Stmt.Sset ___x86_loss_off
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Etempvar ___x86_l_base_ptr (tptr tvoid))
                                    tlong) tlong)
                                (Expr.Etempvar ___x86_l_disp tlong) tlong))
                            (Stmt.Ssequence
                              s_kprog_x86_store_xmm0_2
                              s_kprog_x86_store_xmm0_24))
                          Stmt.Sbreak))
                      Stmt.Sbreak)
                    (Stmt.Ssequence
                      (Stmt.Sloop
                        (Stmt.Ssequence
                          (Stmt.Sloop
                            (Stmt.Ssequence
                              s_kprog_x86_store_xmm0_25
                              s_kprog_x86_store_xmm0_26)
                            Stmt.Sbreak)
                          (Stmt.Sloop
                            (Stmt.Ssequence
                              s_kprog_x86_store_xmm0_27
                              s_kprog_x86_store_xmm0_50)
                            Stmt.Sbreak))
                        Stmt.Sbreak)
                      Stmt.Sbreak))
                  (LStmts.LScons none
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Etempvar ___x86_l_base_form tuchar)
                                              (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                              tint)
                            (Stmt.Sset _t'90
                              (Expr.Ecast
                                (Expr.Eunop Unop.Onotbool
                                  (Expr.Etempvar ___x86_l_base_none tuchar)
                                  tint) tuint))
                            (Stmt.Sset _t'90
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                tuint)))
                          (Stmt.Sifthenelse (Expr.Etempvar _t'90 tuint)
                            (Stmt.Sset _t'91
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Ecast
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Ecast
                                        (Expr.Ecast
                                          (Expr.Etempvar ___x86_l_base_ptr (tptr tvoid))
                                          tulong) tulong)
                                      (Expr.Ecast
                                        (Expr.Etempvar ___x86_l_disp tlong)
                                        tulong) tulong) tulong)
                                  (tptr tuchar)) (tptr tvoid)))
                            (Stmt.Sset _t'91
                              (Expr.Ecast
                                (Expr.Etempvar ___x86_l_base_ptr (tptr tvoid))
                                (tptr tvoid)))))
                        (Stmt.Sset ___x86_l_addr
                          (Expr.Etempvar _t'91 (tptr tvoid))))
                      (Stmt.Ssequence
                        (Stmt.Sloop
                          (Stmt.Ssequence
                            (Stmt.Sset ___x86_st_addr
                              (Expr.Etempvar ___x86_l_addr (tptr tvoid)))
                            (Stmt.Ssequence
                              (Stmt.Sset ___x86_st_width
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                  tuchar))
                              (Stmt.Ssequence
                                s_kprog_x86_store_xmm0_51
                                s_kprog_x86_store_xmm0_54)))
                          Stmt.Sbreak)
                        (Stmt.Ssequence
                          (Stmt.Sloop
                            (Stmt.Ssequence
                              (Stmt.Ssequence
                                s_kprog_x86_store_xmm0_55
                                (Stmt.Sset ___x86_st_addr__1
                                  (Expr.Ecast
                                    (Expr.Ecast
                                      (Expr.Ebinop Binop.Oadd
                                        (Expr.Ecast
                                          (Expr.Ecast
                                            (Expr.Etempvar ___x86_l_addr (tptr tvoid))
                                            tulong) tulong)
                                        (Expr.Ecast
                                          (Expr.Etempvar _t'98 tuint) tulong)
                                        tulong) tulong) (tptr tuchar))))
                              (Stmt.Ssequence
                                s_kprog_x86_store_xmm0_56
                                s_kprog_x86_store_xmm0_60))
                            Stmt.Sbreak)
                          Stmt.Sbreak)))
                    LStmts.LSnil))))))))
    Stmt.Sbreak))
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
 (CompositeDef.Composite _xdp_md SU.Struct
   [(Member.Member_plain _data tuint), (Member.Member_plain _data_end tuint),
    (Member.Member_plain _data_meta tuint),
    (Member.Member_plain _ingress_ifindex tuint),
    (Member.Member_plain _rx_queue_index tuint),
    (Member.Member_plain _egress_ifindex tuint)]
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
 (CompositeDef.Composite __3120 SU.Struct
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
 (CompositeDef.Composite __3119 SU.Union
   [(Member.Member_plain (Positive.ofNat 18727075383868559167)
      (Ty.Tstruct __3120 noattr)),
    (Member.Member_plain _gpr_cells
      (tarray (Ty.Tstruct _x86_sim_gpr_cell noattr) 16))]
   noattr),
 (CompositeDef.Composite _x86_sim_register_state SU.Struct
   [(Member.Member_plain (Positive.ofNat 18727075383868559167)
      (Ty.Tunion __3119 noattr)),
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
    (Member.Member_plain _q (tptr (tvolatile tulong))),
    (Member.Member_plain _w (tptr (tvolatile tushort))),
    (Member.Member_plain _d (tptr (tvolatile tuint)))]
   noattr),
 (CompositeDef.Composite _kprog_x86_stack_fact SU.Struct
   [(Member.Member_plain _tag (tptr tuchar)),
    (Member.Member_plain _pointer (tptr (tptr tvoid)))]
   noattr),
 (CompositeDef.Composite __3440 SU.Union
   [(Member.Member_plain _ptr (tptr tvoid)),
    (Member.Member_plain _w tushort),
    (Member.Member_plain _b (tarray tuchar 8))]
   noattr),
 (CompositeDef.Composite __3446 SU.Union
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
 (_kprog_c_context_pointer,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_external "kprog_c_context_pointer"
                                   (mksignature
                                     [XType.Xptr, XType.Xint8unsigned,
                                      XType.Xint] XType.Xptr cc_default))
     [(tptr tvoid), tuchar, tuint] (tptr tvoid) cc_default)),
 (_kprog_c_pointer_bits,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_external "kprog_c_pointer_bits"
                                   (mksignature [XType.Xptr] XType.Xlong
                                     cc_default)) [(tptr tvoid)] tulong
     cc_default)),
 (_kprog_x86_bswap_value, GlobDef.Gfun (FunDef.Internal f_kprog_x86_bswap_value)),
 (_x86_width_mask, GlobDef.Gfun (FunDef.Internal f_x86_width_mask)),
 (_x86_apply_width, GlobDef.Gfun (FunDef.Internal f_x86_apply_width)),
 (_x86_width_effective, GlobDef.Gfun (FunDef.Internal f_x86_width_effective)),
 (_x86_bswap, GlobDef.Gfun (FunDef.Internal f_x86_bswap)),
 (_x86_simm, GlobDef.Gfun (FunDef.Internal f_x86_simm)),
 (_x86_store_imm_disp, GlobDef.Gfun (FunDef.Internal f_x86_store_imm_disp)),
 (_native_lab_entry_input,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_external "native_lab_entry_input"
                                   (mksignature [XType.Xint] XType.Xlong
                                     cc_default)) [tuint] tulong cc_default)),
 (_kprog_x86_mem_load, GlobDef.Gfun (FunDef.Internal f_kprog_x86_mem_load)),
 (_kprog_x86_mem_load_fixed, GlobDef.Gfun (FunDef.Internal f_kprog_x86_mem_load_fixed)),
 (_kprog_x86_mem_store, GlobDef.Gfun (FunDef.Internal f_kprog_x86_mem_store)),
 (_x86_sim_clight_load_pointer, GlobDef.Gfun (FunDef.Internal f_x86_sim_clight_load_pointer)),
 (_kprog_x86_mem_offset,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_external "kprog_x86_mem_offset"
                                   (mksignature
                                     [XType.Xptr, XType.Xptr, XType.Xint,
                                      XType.Xlong, XType.Xlong] XType.Xlong
                                     cc_default))
     [(tptr (Ty.Tstruct _x86_sim_register_state noattr)),
      (tptr (Ty.Tstruct _kprog_x86_arena noattr)), tuint, tulong, tlong]
     tlong cc_default)),
 (_kprog_x86_read_recovery_mem,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_external "kprog_x86_read_recovery_mem"
                                   (mksignature
                                     [XType.Xptr, XType.Xptr, XType.Xptr,
                                      XType.Xint, XType.Xlong, XType.Xlong,
                                      XType.Xlong, XType.Xlong] XType.Xint
                                     cc_default))
     [(tptr (Ty.Tstruct _x86_sim_register_state noattr)),
      (tptr (Ty.Tstruct _kprog_x86_arena noattr)),
      (tptr (Ty.Tstruct _kprog_x86_stack_fact noattr)), tuint, tulong,
      tulong, tulong, tlong] tint cc_default)),
 (_kprog_x86_stack_read,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_external "kprog_x86_stack_read"
                                   (mksignature
                                     [XType.Xptr, XType.Xptr, XType.Xint,
                                      XType.Xlong, XType.Xlong] XType.Xlong
                                     cc_default))
     [(tptr (Ty.Tstruct _x86_sim_register_state noattr)),
      (tptr (Ty.Tstruct _kprog_x86_arena noattr)), tuint, tlong, tulong]
     tulong cc_default)),
 (_kprog_x86_xmm0_arm,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_external "kprog_x86_xmm0_arm"
                                   (mksignature [XType.Xlong]
                                     XType.Xint8unsigned cc_default))
     [tulong] tuchar cc_default)),
 (_tag_of, GlobDef.Gfun (FunDef.Internal f_tag_of)),
 (_source_of, GlobDef.Gfun (FunDef.Internal f_source_of)),
 (_kprog_x86_movbe_width, GlobDef.Gfun (FunDef.Internal f_kprog_x86_movbe_width)),
 (_kprog_x86_movbe_arm, GlobDef.Gfun (FunDef.Internal f_kprog_x86_movbe_arm)),
 (_kprog_x86_read_mem_value, GlobDef.Gfun (FunDef.Internal f_kprog_x86_read_mem_value)),
 (_kprog_x86_movbe_load, GlobDef.Gfun (FunDef.Internal f_kprog_x86_movbe_load)),
 (_kprog_x86_store_memory, GlobDef.Gfun (FunDef.Internal f_kprog_x86_store_memory)),
 (_kprog_x86_load_xmm0, GlobDef.Gfun (FunDef.Internal f_kprog_x86_load_xmm0)),
 (_kprog_x86_store_xmm0, GlobDef.Gfun (FunDef.Internal f_kprog_x86_store_xmm0))]

def public_idents : List Ident :=
[_kprog_x86_store_xmm0, _kprog_x86_load_xmm0, _kprog_x86_store_memory,
 _kprog_x86_movbe_load, _kprog_x86_read_mem_value, _kprog_x86_movbe_arm,
 _kprog_x86_movbe_width, _kprog_x86_xmm0_arm, _kprog_x86_stack_read,
 _kprog_x86_read_recovery_mem, _kprog_x86_mem_offset,
 _native_lab_entry_input, _kprog_c_pointer_bits, _kprog_c_context_pointer,
 _kprog_c_trap, ___builtin_debug, ___builtin_write32_reversed,
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

end X86Memory

