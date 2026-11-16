import Clightdefs
open CC

namespace Arm64Entry

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
  def source_file : String := "c/Arm64Entry.c"
  def normalized : Bool := true
end Info

def __150 : Ident := identOfString "_150"
def __151 : Ident := identOfString "_151"
def __2854 : Ident := identOfString "_2854"
def __2856 : Ident := identOfString "_2856"
def __2946 : Ident := identOfString "_2946"
def __2948 : Ident := identOfString "_2948"
def __3040 : Ident := identOfString "_3040"
def __3042 : Ident := identOfString "_3042"
def ___a64_c : Ident := identOfString "__a64_c"
def ___a64_cells : Ident := identOfString "__a64_cells"
def ___a64_lr : Ident := identOfString "__a64_lr"
def ___a64_n : Ident := identOfString "__a64_n"
def ___a64_numeric_return : Ident := identOfString "__a64_numeric_return"
def ___a64_numeric_return_valid : Ident := identOfString "__a64_numeric_return_valid"
def ___a64_numeric_sp : Ident := identOfString "__a64_numeric_sp"
def ___a64_numeric_sp_valid : Ident := identOfString "__a64_numeric_sp_valid"
def ___a64_sim_abi : Ident := identOfString "__a64_sim_abi"
def ___a64_sim_abi_kind : Ident := identOfString "__a64_sim_abi_kind"
def ___a64_sim_helper_abi_base : Ident := identOfString "__a64_sim_helper_abi_base"
def ___a64_sim_helper_ctx : Ident := identOfString "__a64_sim_helper_ctx"
def ___a64_sim_is_xdp : Ident := identOfString "__a64_sim_is_xdp"
def ___a64_sim_skb_ctx : Ident := identOfString "__a64_sim_skb_ctx"
def ___a64_sp : Ident := identOfString "__a64_sp"
def ___a64_stack : Ident := identOfString "__a64_stack"
def ___a64_stack_payload : Ident := identOfString "__a64_stack_payload"
def ___a64_stack_tag : Ident := identOfString "__a64_stack_tag"
def ___a64_tag_cells : Ident := identOfString "__a64_tag_cells"
def ___a64_v : Ident := identOfString "__a64_v"
def ___a64_vectors : Ident := identOfString "__a64_vectors"
def ___a64_x0 : Ident := identOfString "__a64_x0"
def ___a64_x0_tag : Ident := identOfString "__a64_x0_tag"
def ___a64_x1 : Ident := identOfString "__a64_x1"
def ___a64_x10 : Ident := identOfString "__a64_x10"
def ___a64_x10_tag : Ident := identOfString "__a64_x10_tag"
def ___a64_x11 : Ident := identOfString "__a64_x11"
def ___a64_x11_tag : Ident := identOfString "__a64_x11_tag"
def ___a64_x12 : Ident := identOfString "__a64_x12"
def ___a64_x12_tag : Ident := identOfString "__a64_x12_tag"
def ___a64_x13 : Ident := identOfString "__a64_x13"
def ___a64_x13_tag : Ident := identOfString "__a64_x13_tag"
def ___a64_x14 : Ident := identOfString "__a64_x14"
def ___a64_x14_tag : Ident := identOfString "__a64_x14_tag"
def ___a64_x15 : Ident := identOfString "__a64_x15"
def ___a64_x15_tag : Ident := identOfString "__a64_x15_tag"
def ___a64_x16 : Ident := identOfString "__a64_x16"
def ___a64_x16_tag : Ident := identOfString "__a64_x16_tag"
def ___a64_x17 : Ident := identOfString "__a64_x17"
def ___a64_x17_tag : Ident := identOfString "__a64_x17_tag"
def ___a64_x18 : Ident := identOfString "__a64_x18"
def ___a64_x18_tag : Ident := identOfString "__a64_x18_tag"
def ___a64_x19 : Ident := identOfString "__a64_x19"
def ___a64_x19_tag : Ident := identOfString "__a64_x19_tag"
def ___a64_x1_tag : Ident := identOfString "__a64_x1_tag"
def ___a64_x2 : Ident := identOfString "__a64_x2"
def ___a64_x20 : Ident := identOfString "__a64_x20"
def ___a64_x20_tag : Ident := identOfString "__a64_x20_tag"
def ___a64_x21 : Ident := identOfString "__a64_x21"
def ___a64_x21_tag : Ident := identOfString "__a64_x21_tag"
def ___a64_x22 : Ident := identOfString "__a64_x22"
def ___a64_x22_tag : Ident := identOfString "__a64_x22_tag"
def ___a64_x23 : Ident := identOfString "__a64_x23"
def ___a64_x23_tag : Ident := identOfString "__a64_x23_tag"
def ___a64_x24 : Ident := identOfString "__a64_x24"
def ___a64_x24_tag : Ident := identOfString "__a64_x24_tag"
def ___a64_x25 : Ident := identOfString "__a64_x25"
def ___a64_x25_tag : Ident := identOfString "__a64_x25_tag"
def ___a64_x26 : Ident := identOfString "__a64_x26"
def ___a64_x26_tag : Ident := identOfString "__a64_x26_tag"
def ___a64_x27 : Ident := identOfString "__a64_x27"
def ___a64_x27_tag : Ident := identOfString "__a64_x27_tag"
def ___a64_x28 : Ident := identOfString "__a64_x28"
def ___a64_x28_tag : Ident := identOfString "__a64_x28_tag"
def ___a64_x29 : Ident := identOfString "__a64_x29"
def ___a64_x29_tag : Ident := identOfString "__a64_x29_tag"
def ___a64_x2_tag : Ident := identOfString "__a64_x2_tag"
def ___a64_x3 : Ident := identOfString "__a64_x3"
def ___a64_x30 : Ident := identOfString "__a64_x30"
def ___a64_x30_tag : Ident := identOfString "__a64_x30_tag"
def ___a64_x3_tag : Ident := identOfString "__a64_x3_tag"
def ___a64_x4 : Ident := identOfString "__a64_x4"
def ___a64_x4_tag : Ident := identOfString "__a64_x4_tag"
def ___a64_x5 : Ident := identOfString "__a64_x5"
def ___a64_x5_tag : Ident := identOfString "__a64_x5_tag"
def ___a64_x6 : Ident := identOfString "__a64_x6"
def ___a64_x6_tag : Ident := identOfString "__a64_x6_tag"
def ___a64_x7 : Ident := identOfString "__a64_x7"
def ___a64_x7_tag : Ident := identOfString "__a64_x7_tag"
def ___a64_x8 : Ident := identOfString "__a64_x8"
def ___a64_x8_tag : Ident := identOfString "__a64_x8_tag"
def ___a64_x9 : Ident := identOfString "__a64_x9"
def ___a64_x9_tag : Ident := identOfString "__a64_x9_tag"
def ___a64_z : Ident := identOfString "__a64_z"
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
def ___sk_buff : Ident := identOfString "__sk_buff"
def _abi : Ident := identOfString "abi"
def _abi_kind : Ident := identOfString "abi_kind"
def _arm64_sim_gpr : Ident := identOfString "arm64_sim_gpr"
def _arm64_sim_skb_abi : Ident := identOfString "arm64_sim_skb_abi"
def _arm64_sim_xdp_abi : Ident := identOfString "arm64_sim_xdp_abi"
def _b : Ident := identOfString "b"
def _bias : Ident := identOfString "bias"
def _bpf_cast_to_kern_ctx : Ident := identOfString "bpf_cast_to_kern_ctx"
def _bpf_flow_keys : Ident := identOfString "bpf_flow_keys"
def _bpf_sock : Ident := identOfString "bpf_sock"
def _c : Ident := identOfString "c"
def _capacity : Ident := identOfString "capacity"
def _cb : Ident := identOfString "cb"
def _cells : Ident := identOfString "cells"
def _continuation : Ident := identOfString "continuation"
def _ctx : Ident := identOfString "ctx"
def _data : Ident := identOfString "data"
def _data_end : Ident := identOfString "data_end"
def _data_meta : Ident := identOfString "data_meta"
def _egress_ifindex : Ident := identOfString "egress_ifindex"
def _entry : Ident := identOfString "entry"
def _family : Ident := identOfString "family"
def _flow_keys : Ident := identOfString "flow_keys"
def _gso_segs : Ident := identOfString "gso_segs"
def _gso_size : Ident := identOfString "gso_size"
def _hash : Ident := identOfString "hash"
def _helper_abi_base : Ident := identOfString "helper_abi_base"
def _helper_context : Ident := identOfString "helper_context"
def _hi : Ident := identOfString "hi"
def _hwtstamp : Ident := identOfString "hwtstamp"
def _i : Ident := identOfString "i"
def _ifindex : Ident := identOfString "ifindex"
def _index : Ident := identOfString "index"
def _ingress_ifindex : Ident := identOfString "ingress_ifindex"
def _is_xdp : Ident := identOfString "is_xdp"
def _kprog_arm64_entry : Ident := identOfString "kprog_arm64_entry"
def _kprog_arm64_entry_raw : Ident := identOfString "kprog_arm64_entry_raw"
def _kprog_arm64_entry_skb : Ident := identOfString "kprog_arm64_entry_skb"
def _kprog_arm64_entry_xdp : Ident := identOfString "kprog_arm64_entry_xdp"
def _kprog_arm64_payload_load : Ident := identOfString "kprog_arm64_payload_load"
def _kprog_arm64_payload_store : Ident := identOfString "kprog_arm64_payload_store"
def _kprog_c_context_pointer : Ident := identOfString "kprog_c_context_pointer"
def _len : Ident := identOfString "len"
def _lo : Ident := identOfString "lo"
def _local_ip4 : Ident := identOfString "local_ip4"
def _local_ip6 : Ident := identOfString "local_ip6"
def _local_port : Ident := identOfString "local_port"
def _lr : Ident := identOfString "lr"
def _main : Ident := identOfString "main"
def _mark : Ident := identOfString "mark"
def _n : Ident := identOfString "n"
def _napi_id : Ident := identOfString "napi_id"
def _native_lab_entry_input : Ident := identOfString "native_lab_entry_input"
def _pad0 : Ident := identOfString "pad0"
def _pad1 : Ident := identOfString "pad1"
def _pad2 : Ident := identOfString "pad2"
def _payload : Ident := identOfString "payload"
def _payload_load : Ident := identOfString "payload_load"
def _payload_store : Ident := identOfString "payload_store"
def _payload_words : Ident := identOfString "payload_words"
def _pkt_type : Ident := identOfString "pkt_type"
def _priority : Ident := identOfString "priority"
def _protocol : Ident := identOfString "protocol"
def _ptr : Ident := identOfString "ptr"
def _q : Ident := identOfString "q"
def _queue_mapping : Ident := identOfString "queue_mapping"
def _remote_ip4 : Ident := identOfString "remote_ip4"
def _remote_ip6 : Ident := identOfString "remote_ip6"
def _remote_port : Ident := identOfString "remote_port"
def _return_base : Ident := identOfString "return_base"
def _return_valid : Ident := identOfString "return_valid"
def _rx_queue_index : Ident := identOfString "rx_queue_index"
def _sk : Ident := identOfString "sk"
def _skb_context : Ident := identOfString "skb_context"
def _sp : Ident := identOfString "sp"
def _sp_base : Ident := identOfString "sp_base"
def _sp_valid : Ident := identOfString "sp_valid"
def _stack_tags : Ident := identOfString "stack_tags"
def _tag_bytes : Ident := identOfString "tag_bytes"
def _tag_cells : Ident := identOfString "tag_cells"
def _tc_classid : Ident := identOfString "tc_classid"
def _tc_index : Ident := identOfString "tc_index"
def _tstamp : Ident := identOfString "tstamp"
def _tstamp_type : Ident := identOfString "tstamp_type"
def _v : Ident := identOfString "v"
def _value : Ident := identOfString "value"
def _vector_hi : Ident := identOfString "vector_hi"
def _vector_lo : Ident := identOfString "vector_lo"
def _vlan_present : Ident := identOfString "vlan_present"
def _vlan_proto : Ident := identOfString "vlan_proto"
def _vlan_tci : Ident := identOfString "vlan_tci"
def _w : Ident := identOfString "w"
def _wire_len : Ident := identOfString "wire_len"
def _x : Ident := identOfString "x"
def _xdp_md : Ident := identOfString "xdp_md"
def _z : Ident := identOfString "z"
def _t'1 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437439)
def _t'10 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437448)
def _t'100 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437538)
def _t'101 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437539)
def _t'102 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437540)
def _t'103 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437541)
def _t'104 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437542)
def _t'105 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437543)
def _t'106 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437544)
def _t'107 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437545)
def _t'108 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437546)
def _t'109 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437547)
def _t'11 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437449)
def _t'110 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437548)
def _t'111 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437549)
def _t'112 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437550)
def _t'113 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437551)
def _t'114 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437552)
def _t'115 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437553)
def _t'116 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437554)
def _t'117 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437555)
def _t'118 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437556)
def _t'119 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437557)
def _t'12 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437450)
def _t'120 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437558)
def _t'121 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437559)
def _t'122 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437560)
def _t'123 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437561)
def _t'124 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437562)
def _t'125 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437563)
def _t'126 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437564)
def _t'127 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437565)
def _t'128 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437566)
def _t'129 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437567)
def _t'13 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437451)
def _t'130 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437568)
def _t'131 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437569)
def _t'132 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437570)
def _t'133 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437571)
def _t'14 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437452)
def _t'15 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437453)
def _t'16 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437454)
def _t'17 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437455)
def _t'18 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437456)
def _t'19 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437457)
def _t'2 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437440)
def _t'20 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437458)
def _t'21 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437459)
def _t'22 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437460)
def _t'23 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437461)
def _t'24 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437462)
def _t'25 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437463)
def _t'26 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437464)
def _t'27 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437465)
def _t'28 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437466)
def _t'29 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437467)
def _t'3 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437441)
def _t'30 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437468)
def _t'31 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437469)
def _t'32 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437470)
def _t'33 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437471)
def _t'34 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437472)
def _t'35 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437473)
def _t'36 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437474)
def _t'37 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437475)
def _t'38 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437476)
def _t'39 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437477)
def _t'4 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437442)
def _t'40 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437478)
def _t'41 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437479)
def _t'42 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437480)
def _t'43 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437481)
def _t'44 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437482)
def _t'45 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437483)
def _t'46 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437484)
def _t'47 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437485)
def _t'48 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437486)
def _t'49 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437487)
def _t'5 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437443)
def _t'50 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437488)
def _t'51 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437489)
def _t'52 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437490)
def _t'53 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437491)
def _t'54 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437492)
def _t'55 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437493)
def _t'56 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437494)
def _t'57 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437495)
def _t'58 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437496)
def _t'59 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437497)
def _t'6 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437444)
def _t'60 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437498)
def _t'61 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437499)
def _t'62 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437500)
def _t'63 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437501)
def _t'64 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437502)
def _t'65 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437503)
def _t'66 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437504)
def _t'67 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437505)
def _t'68 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437506)
def _t'69 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437507)
def _t'7 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437445)
def _t'70 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437508)
def _t'71 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437509)
def _t'72 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437510)
def _t'73 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437511)
def _t'74 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437512)
def _t'75 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437513)
def _t'76 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437514)
def _t'77 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437515)
def _t'78 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437516)
def _t'79 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437517)
def _t'8 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437446)
def _t'80 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437518)
def _t'81 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437519)
def _t'82 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437520)
def _t'83 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437521)
def _t'84 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437522)
def _t'85 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437523)
def _t'86 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437524)
def _t'87 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437525)
def _t'88 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437526)
def _t'89 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437527)
def _t'9 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437447)
def _t'90 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437528)
def _t'91 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437529)
def _t'92 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437530)
def _t'93 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437531)
def _t'94 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437532)
def _t'95 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437533)
def _t'96 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437534)
def _t'97 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437535)
def _t'98 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437536)
def _t'99 : Ident := (Positive.ofNat 110306860349216524390340943932069010249388437537)

def f_kprog_arm64_payload_load : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(___a64_stack_payload, (tptr (tvolatile tulong))),
                (_index, tulong)],
  fn_vars := [],
  fn_temps := [(_t'1, (tvolatile tulong))],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sbuiltin (some _t'1) (ExtFun.EF_vload Chunk.Mint64)
    [(tptr (tvolatile tulong))]
    [(Expr.Eaddrof
       (Expr.Ederef
         (Expr.Ebinop Binop.Oadd
           (Expr.Etempvar ___a64_stack_payload (tptr (tvolatile tulong)))
           (Expr.Etempvar _index tulong) (tptr (tvolatile tulong)))
         (tvolatile tulong)) (tptr (tvolatile tulong)))])
  (Stmt.Sreturn (some (Expr.Etempvar _t'1 (tvolatile tulong)))))
}

def f_kprog_arm64_payload_store : Function := {
  fn_return := tvoid,
  fn_callconv := cc_default,
  fn_params := [(___a64_stack_payload, (tptr (tvolatile tulong))),
                (_index, tulong), (_value, tulong)],
  fn_vars := [],
  fn_temps := [],
  fn_body :=
(Stmt.Sloop
  (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
    [(tptr (tvolatile tulong)), (tvolatile tulong)]
    [(Expr.Eaddrof
       (Expr.Ederef
         (Expr.Ebinop Binop.Oadd
           (Expr.Etempvar ___a64_stack_payload (tptr (tvolatile tulong)))
           (Expr.Etempvar _index tulong) (tptr (tvolatile tulong)))
         (tvolatile tulong)) (tptr (tvolatile tulong))),
     (Expr.Etempvar _value tulong)])
  Stmt.Sbreak)
}

@[noinline] def s_kprog_arm64_entry_raw_0 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield
        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
        _pad0 (tarray tuchar 48))
      (Expr.Econst_int (Integers.Int.repr 15) tint) (tptr tuchar)) tuchar)
  (Expr.Econst_int (Integers.Int.repr 0) tint))

@[noinline] def s_kprog_arm64_entry_raw_1 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield
        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
        _pad0 (tarray tuchar 48))
      (Expr.Econst_int (Integers.Int.repr 32) tint) (tptr tuchar)) tuchar)
  (Expr.Econst_int (Integers.Int.repr 0) tint))

@[noinline] def s_kprog_arm64_entry_raw_2 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield
        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr)) _cb
        (tarray tuint 5)) (Expr.Econst_int (Integers.Int.repr 1) tint)
      (tptr tuint)) tuint) (Expr.Econst_int (Integers.Int.repr 0) tint))

@[noinline] def s_kprog_arm64_entry_raw_3 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield
        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
        _pad2 (tarray tuchar 120))
      (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tuchar)) tuchar)
  (Expr.Econst_int (Integers.Int.repr 0) tint))

@[noinline] def s_kprog_arm64_entry_raw_4 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield
        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
        _pad2 (tarray tuchar 120))
      (Expr.Econst_int (Integers.Int.repr 17) tint) (tptr tuchar)) tuchar)
  (Expr.Econst_int (Integers.Int.repr 0) tint))

@[noinline] def s_kprog_arm64_entry_raw_5 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield
        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
        _pad2 (tarray tuchar 120))
      (Expr.Econst_int (Integers.Int.repr 34) tint) (tptr tuchar)) tuchar)
  (Expr.Econst_int (Integers.Int.repr 0) tint))

@[noinline] def s_kprog_arm64_entry_raw_6 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield
        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
        _pad2 (tarray tuchar 120))
      (Expr.Econst_int (Integers.Int.repr 51) tint) (tptr tuchar)) tuchar)
  (Expr.Econst_int (Integers.Int.repr 0) tint))

@[noinline] def s_kprog_arm64_entry_raw_7 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield
        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
        _pad2 (tarray tuchar 120))
      (Expr.Econst_int (Integers.Int.repr 68) tint) (tptr tuchar)) tuchar)
  (Expr.Econst_int (Integers.Int.repr 0) tint))

@[noinline] def s_kprog_arm64_entry_raw_8 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield
        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
        _pad2 (tarray tuchar 120))
      (Expr.Econst_int (Integers.Int.repr 85) tint) (tptr tuchar)) tuchar)
  (Expr.Econst_int (Integers.Int.repr 0) tint))

@[noinline] def s_kprog_arm64_entry_raw_9 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield
        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
        _pad2 (tarray tuchar 120))
      (Expr.Econst_int (Integers.Int.repr 102) tint) (tptr tuchar)) tuchar)
  (Expr.Econst_int (Integers.Int.repr 0) tint))

@[noinline] def s_kprog_arm64_entry_raw_10 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield
        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
        _pad2 (tarray tuchar 120))
      (Expr.Econst_int (Integers.Int.repr 119) tint) (tptr tuchar)) tuchar)
  (Expr.Econst_int (Integers.Int.repr 0) tint))

@[noinline] def s_kprog_arm64_entry_raw_11 : Stmt :=
(Stmt.Scall (some _t'4)
  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong cc_default))
  [(Expr.Econst_int (Integers.Int.repr 6) tint)])

@[noinline] def s_kprog_arm64_entry_raw_12 : Stmt :=
(Stmt.Sset _t'5
  (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong) tulong))

@[noinline] def s_kprog_arm64_entry_raw_13 : Stmt :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'6)
    (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                         cc_default))
    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
  (Stmt.Sset _t'5 (Expr.Ecast (Expr.Etempvar _t'6 tulong) tulong)))

@[noinline] def s_kprog_arm64_entry_raw_14 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Econst_int (Integers.Int.repr 3) tuint)
                      (Expr.Econst_int (Integers.Int.repr 30) tuint) tint)
    (Stmt.Sset _t'7
      (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong) tulong))
    (Stmt.Ssequence
      (Stmt.Scall (some _t'8)
        (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                             cc_default))
        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
      (Stmt.Sset _t'7 (Expr.Ecast (Expr.Etempvar _t'8 tulong) tulong))))
  (Stmt.Sassign
    (Expr.Efield (Expr.Evar ___a64_x3 (Ty.Tunion _arm64_sim_gpr noattr)) _x
      tulong) (Expr.Etempvar _t'7 tulong)))

@[noinline] def s_kprog_arm64_entry_raw_15 : Stmt :=
(Stmt.Sset _t'21
  (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong) tulong))

@[noinline] def s_kprog_arm64_entry_raw_16 : Stmt :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'22)
    (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                         cc_default))
    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
  (Stmt.Sset _t'21 (Expr.Ecast (Expr.Etempvar _t'22 tulong) tulong)))

@[noinline] def s_kprog_arm64_entry_raw_17 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                    (Expr.Econst_int (Integers.Int.repr 11) tuint)
                    (Expr.Econst_int (Integers.Int.repr 30) tuint) tint)
  (Stmt.Sset _t'23
    (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong) tulong))
  (Stmt.Ssequence
    (Stmt.Scall (some _t'24)
      (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                           cc_default))
      [(Expr.Econst_int (Integers.Int.repr 6) tint)])
    (Stmt.Sset _t'23 (Expr.Ecast (Expr.Etempvar _t'24 tulong) tulong))))

@[noinline] def s_kprog_arm64_entry_raw_18 : Stmt :=
(Stmt.Sassign (Expr.Evar ___a64_x11_tag tuchar)
  (Expr.Econst_int (Integers.Int.repr 0) tuint))

@[noinline] def s_kprog_arm64_entry_raw_19 : Stmt :=
(Stmt.Scall (some _t'38)
  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong cc_default))
  [(Expr.Econst_int (Integers.Int.repr 6) tint)])

@[noinline] def s_kprog_arm64_entry_raw_20 : Stmt :=
(Stmt.Sset _t'39
  (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong) tulong))

@[noinline] def s_kprog_arm64_entry_raw_21 : Stmt :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'40)
    (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                         cc_default))
    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
  (Stmt.Sset _t'39 (Expr.Ecast (Expr.Etempvar _t'40 tulong) tulong)))

@[noinline] def s_kprog_arm64_entry_raw_22 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Econst_int (Integers.Int.repr 20) tuint)
                      (Expr.Econst_int (Integers.Int.repr 30) tuint) tint)
    (Stmt.Sset _t'41
      (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong) tulong))
    (Stmt.Ssequence
      (Stmt.Scall (some _t'42)
        (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                             cc_default))
        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
      (Stmt.Sset _t'41 (Expr.Ecast (Expr.Etempvar _t'42 tulong) tulong))))
  (Stmt.Sassign
    (Expr.Efield (Expr.Evar ___a64_x20 (Ty.Tunion _arm64_sim_gpr noattr)) _x
      tulong) (Expr.Etempvar _t'41 tulong)))

@[noinline] def s_kprog_arm64_entry_raw_23 : Stmt :=
(Stmt.Sset _t'55
  (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong) tulong))

@[noinline] def s_kprog_arm64_entry_raw_24 : Stmt :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'56)
    (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                         cc_default))
    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
  (Stmt.Sset _t'55 (Expr.Ecast (Expr.Etempvar _t'56 tulong) tulong)))

@[noinline] def s_kprog_arm64_entry_raw_25 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                    (Expr.Econst_int (Integers.Int.repr 28) tuint)
                    (Expr.Econst_int (Integers.Int.repr 30) tuint) tint)
  (Stmt.Sset _t'57
    (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong) tulong))
  (Stmt.Ssequence
    (Stmt.Scall (some _t'58)
      (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                           cc_default))
      [(Expr.Econst_int (Integers.Int.repr 6) tint)])
    (Stmt.Sset _t'57 (Expr.Ecast (Expr.Etempvar _t'58 tulong) tulong))))

@[noinline] def s_kprog_arm64_entry_raw_26 : Stmt :=
(Stmt.Sassign (Expr.Evar ___a64_x28_tag tuchar)
  (Expr.Econst_int (Integers.Int.repr 0) tuint))

@[noinline] def s_kprog_arm64_entry_raw_27 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
      (Expr.Econst_int (Integers.Int.repr 12) tint)
      (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
    (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
  (Expr.Eaddrof (Expr.Evar ___a64_x12 (Ty.Tunion _arm64_sim_gpr noattr))
    (tptr (Ty.Tunion _arm64_sim_gpr noattr))))

@[noinline] def s_kprog_arm64_entry_raw_28 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
      (Expr.Econst_int (Integers.Int.repr 29) tint)
      (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
    (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
  (Expr.Eaddrof (Expr.Evar ___a64_x29 (Ty.Tunion _arm64_sim_gpr noattr))
    (tptr (Ty.Tunion _arm64_sim_gpr noattr))))

@[noinline] def s_kprog_arm64_entry_raw_29 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
      (Expr.Econst_int (Integers.Int.repr 15) tint) (tptr (tptr tuchar)))
    (tptr tuchar))
  (Expr.Eaddrof (Expr.Evar ___a64_x15_tag tuchar) (tptr tuchar)))

@[noinline] def s_kprog_arm64_entry_raw_30 : Stmt :=
(Stmt.Scall (some _t'63)
  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong cc_default))
  [(Expr.Econst_int (Integers.Int.repr 6) tint)])

@[noinline] def s_kprog_arm64_entry_raw_31 : Stmt :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'64)
    (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                         cc_default))
    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
  (Stmt.Sassign (Expr.Evar ___a64_z tuchar)
    (Expr.Ebinop Binop.Oand (Expr.Etempvar _t'64 tulong)
      (Expr.Econst_int (Integers.Int.repr 1) tint) tulong)))

@[noinline] def s_kprog_arm64_entry_raw_32 : Stmt :=
(Stmt.Scall (some _t'79)
  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong cc_default))
  [(Expr.Econst_int (Integers.Int.repr 6) tint)])

@[noinline] def s_kprog_arm64_entry_raw_33 : Stmt :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'80)
    (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                         cc_default))
    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
  (Stmt.Sassign
    (Expr.Efield
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
          (Expr.Econst_int (Integers.Int.repr 6) tint)
          (tptr (Ty.Tstruct __2854 noattr))) (Ty.Tstruct __2854 noattr)) _hi
      tulong) (Expr.Etempvar _t'80 tulong)))

@[noinline] def s_kprog_arm64_entry_raw_34 : Stmt :=
(Stmt.Scall (some _t'96)
  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong cc_default))
  [(Expr.Econst_int (Integers.Int.repr 6) tint)])

@[noinline] def s_kprog_arm64_entry_raw_35 : Stmt :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'97)
    (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                         cc_default))
    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
  (Stmt.Sassign
    (Expr.Efield
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
          (Expr.Econst_int (Integers.Int.repr 15) tint)
          (tptr (Ty.Tstruct __2854 noattr))) (Ty.Tstruct __2854 noattr)) _lo
      tulong) (Expr.Etempvar _t'97 tulong)))

@[noinline] def s_kprog_arm64_entry_raw_36 : Stmt :=
(Stmt.Scall (some _t'113)
  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong cc_default))
  [(Expr.Econst_int (Integers.Int.repr 6) tint)])

@[noinline] def s_kprog_arm64_entry_raw_37 : Stmt :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'114)
    (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                         cc_default))
    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
  (Stmt.Sassign
    (Expr.Efield
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
          (Expr.Econst_int (Integers.Int.repr 23) tint)
          (tptr (Ty.Tstruct __2854 noattr))) (Ty.Tstruct __2854 noattr)) _hi
      tulong) (Expr.Etempvar _t'114 tulong)))

@[noinline] def s_kprog_arm64_entry_raw_38 : Stmt :=
(Stmt.Scall (some _t'130)
  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong cc_default))
  [(Expr.Econst_int (Integers.Int.repr 6) tint)])

@[noinline] def s_kprog_arm64_entry_raw_39 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
      (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tuchar)) tuchar)
  (Expr.Econst_int (Integers.Int.repr 0) tint))

@[noinline] def s_kprog_arm64_entry_raw_40 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
      (Expr.Econst_int (Integers.Int.repr 17) tint) (tptr tuchar)) tuchar)
  (Expr.Econst_int (Integers.Int.repr 0) tint))

@[noinline] def s_kprog_arm64_entry_raw_41 : Stmt :=
(Stmt.Sassign
  (Expr.Efield (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
    _return_base (tptr tulong))
  (Expr.Eaddrof (Expr.Evar ___a64_numeric_return tulong) (tptr tulong)))

@[noinline] def s_kprog_arm64_entry_raw_42 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
        _vector_lo (tarray (tptr tulong) 32))
      (Expr.Econst_int (Integers.Int.repr 8) tint) (tptr (tptr tulong)))
    (tptr tulong))
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))

@[noinline] def s_kprog_arm64_entry_raw_43 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
        _vector_lo (tarray (tptr tulong) 32))
      (Expr.Econst_int (Integers.Int.repr 25) tint) (tptr (tptr tulong)))
    (tptr tulong))
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))

@[noinline] def s_kprog_arm64_entry_raw_44 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
        _vector_hi (tarray (tptr tulong) 32))
      (Expr.Econst_int (Integers.Int.repr 10) tint) (tptr (tptr tulong)))
    (tptr tulong))
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))

@[noinline] def s_kprog_arm64_entry_raw_45 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
        _vector_hi (tarray (tptr tulong) 32))
      (Expr.Econst_int (Integers.Int.repr 27) tint) (tptr (tptr tulong)))
    (tptr tulong))
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))

@[noinline] def s_kprog_arm64_entry_raw_46 : Stmt :=
(Stmt.Sassign
  (Expr.Efield (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
    _is_xdp (tptr tuchar))
  (Expr.Eaddrof (Expr.Evar ___a64_sim_is_xdp tuchar) (tptr tuchar)))

@[noinline] def s_kprog_arm64_entry_raw_47 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Efield (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
      _abi_kind (tptr tuchar))
    (Expr.Eaddrof (Expr.Evar ___a64_sim_abi_kind tuchar) (tptr tuchar)))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Efield (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
        _skb_context (tptr (tptr (Ty.Tstruct ___sk_buff noattr))))
      (Expr.Eaddrof
        (Expr.Evar ___a64_sim_skb_ctx (tptr (Ty.Tstruct ___sk_buff noattr)))
        (tptr (tptr (Ty.Tstruct ___sk_buff noattr)))))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Efield
          (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr)) _abi
          (tptr tvoid))
        (Expr.Eaddrof
          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
          (tptr (Ty.Tstruct _arm64_sim_skb_abi noattr))))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sset _i (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Sloop
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                  (Expr.Etempvar _i tuint)
                                  (Expr.Econst_int (Integers.Int.repr 32) tint)
                                  tint)
                Stmt.Sskip
                Stmt.Sbreak)
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                        _vector_lo (tarray (tptr tulong) 32))
                      (Expr.Etempvar _i tuint) (tptr (tptr tulong)))
                    (tptr tulong))
                  (Expr.Eaddrof
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                          (Expr.Etempvar _i tuint)
                          (tptr (Ty.Tstruct __2854 noattr)))
                        (Ty.Tstruct __2854 noattr)) _lo tulong)
                    (tptr tulong)))
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                        _vector_hi (tarray (tptr tulong) 32))
                      (Expr.Etempvar _i tuint) (tptr (tptr tulong)))
                    (tptr tulong))
                  (Expr.Eaddrof
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                          (Expr.Etempvar _i tuint)
                          (tptr (Ty.Tstruct __2854 noattr)))
                        (Ty.Tstruct __2854 noattr)) _hi tulong)
                    (tptr tulong)))))
            (Stmt.Sset _i
              (Expr.Ebinop Binop.Oadd (Expr.Etempvar _i tuint)
                (Expr.Econst_int (Integers.Int.repr 1) tint) tuint))))
        (Stmt.Ssequence
          (Stmt.Scall (some _t'131)
            (Expr.Etempvar _continuation (tptr (Ty.Tfunction
                                                 [(tptr (Ty.Tstruct _kprog_arm64_entry noattr))]
                                                 tuint cc_default)))
            [(Expr.Eaddrof
               (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
               (tptr (Ty.Tstruct _kprog_arm64_entry noattr)))])
          (Stmt.Sreturn (some (Expr.Etempvar _t'131 tuint))))))))

@[noinline] def s_kprog_arm64_entry_raw_48 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Efield
          (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
          _vector_hi (tarray (tptr tulong) 32))
        (Expr.Econst_int (Integers.Int.repr 28) tint) (tptr (tptr tulong)))
      (tptr tulong))
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Efield
            (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
            _vector_hi (tarray (tptr tulong) 32))
          (Expr.Econst_int (Integers.Int.repr 29) tint) (tptr (tptr tulong)))
        (tptr tulong))
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
              _vector_hi (tarray (tptr tulong) 32))
            (Expr.Econst_int (Integers.Int.repr 30) tint)
            (tptr (tptr tulong))) (tptr tulong))
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
          (tptr tvoid)))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                _vector_hi (tarray (tptr tulong) 32))
              (Expr.Econst_int (Integers.Int.repr 31) tint)
              (tptr (tptr tulong))) (tptr tulong))
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
            (tptr tvoid)))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Efield
              (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr)) _b
              (tptr (tvolatile tuchar)))
            (Expr.Efield
              (Expr.Evar ___a64_stack (tvolatile (Ty.Tunion __2856 noattr)))
              _b (tvolatile (tarray tuchar 160))))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Efield
                (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr)) _q
                (tptr (tvolatile tulong)))
              (Expr.Efield
                (Expr.Evar ___a64_stack (tvolatile (Ty.Tunion __2856 noattr)))
                _q (tvolatile (tarray tulong 20))))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                  _payload (tptr (tvolatile tulong)))
                (Expr.Evar ___a64_stack_payload (tarray (tvolatile tulong) 20)))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Efield
                    (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                    _payload_load
                    (tptr (Ty.Tfunction [(tptr (tvolatile tulong)), tulong]
                            tulong cc_default)))
                  (Expr.Evar _kprog_arm64_payload_load (Ty.Tfunction
                                                         [(tptr (tvolatile tulong)),
                                                          tulong] tulong
                                                         cc_default)))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Efield
                      (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                      _payload_store
                      (tptr (Ty.Tfunction
                              [(tptr (tvolatile tulong)), tulong, tulong]
                              tvoid cc_default)))
                    (Expr.Evar _kprog_arm64_payload_store (Ty.Tfunction
                                                            [(tptr (tvolatile tulong)),
                                                             tulong, tulong]
                                                            tvoid cc_default)))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Efield
                        (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                        _stack_tags (tptr tuchar))
                      (Expr.Evar ___a64_stack_tag (tarray tuchar 24)))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Efield
                          (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                          _capacity tuint)
                        (Expr.Esizeof (tarray (tvolatile tuchar) 160) tulong))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                            _payload_words tuint)
                          (Expr.Ebinop Binop.Odiv
                            (Expr.Esizeof (tarray (tvolatile tulong) 20) tulong)
                            (Expr.Esizeof (tvolatile tulong) tulong) tulong))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                              _tag_bytes tuint)
                            (Expr.Esizeof (tarray tuchar 24) tulong))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                _bias tlong)
                              (Expr.Econst_long (Integers.Int64.repr 96) tlong))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                  _helper_context (tptr (tptr tvoid)))
                                (Expr.Eaddrof
                                  (Expr.Evar ___a64_sim_helper_ctx (tptr tvoid))
                                  (tptr (tptr tvoid))))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Efield
                                    (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                    _helper_abi_base (tptr (tptr tvoid)))
                                  (Expr.Eaddrof
                                    (Expr.Evar ___a64_sim_helper_abi_base (tptr tvoid))
                                    (tptr (tptr tvoid))))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_raw_46
                                  s_kprog_arm64_entry_raw_47)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_raw_49 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Efield
          (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
          _vector_hi (tarray (tptr tulong) 32))
        (Expr.Econst_int (Integers.Int.repr 11) tint) (tptr (tptr tulong)))
      (tptr tulong))
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Efield
            (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
            _vector_hi (tarray (tptr tulong) 32))
          (Expr.Econst_int (Integers.Int.repr 12) tint) (tptr (tptr tulong)))
        (tptr tulong))
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
              _vector_hi (tarray (tptr tulong) 32))
            (Expr.Econst_int (Integers.Int.repr 13) tint)
            (tptr (tptr tulong))) (tptr tulong))
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
          (tptr tvoid)))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                _vector_hi (tarray (tptr tulong) 32))
              (Expr.Econst_int (Integers.Int.repr 14) tint)
              (tptr (tptr tulong))) (tptr tulong))
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
            (tptr tvoid)))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                  _vector_hi (tarray (tptr tulong) 32))
                (Expr.Econst_int (Integers.Int.repr 15) tint)
                (tptr (tptr tulong))) (tptr tulong))
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
              (tptr tvoid)))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                    _vector_hi (tarray (tptr tulong) 32))
                  (Expr.Econst_int (Integers.Int.repr 16) tint)
                  (tptr (tptr tulong))) (tptr tulong))
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                (tptr tvoid)))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Efield
                      (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                      _vector_hi (tarray (tptr tulong) 32))
                    (Expr.Econst_int (Integers.Int.repr 17) tint)
                    (tptr (tptr tulong))) (tptr tulong))
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                  (tptr tvoid)))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                        _vector_hi (tarray (tptr tulong) 32))
                      (Expr.Econst_int (Integers.Int.repr 18) tint)
                      (tptr (tptr tulong))) (tptr tulong))
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                    (tptr tvoid)))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                          _vector_hi (tarray (tptr tulong) 32))
                        (Expr.Econst_int (Integers.Int.repr 19) tint)
                        (tptr (tptr tulong))) (tptr tulong))
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                      (tptr tvoid)))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Efield
                            (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                            _vector_hi (tarray (tptr tulong) 32))
                          (Expr.Econst_int (Integers.Int.repr 20) tint)
                          (tptr (tptr tulong))) (tptr tulong))
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 0) tint)
                        (tptr tvoid)))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                              _vector_hi (tarray (tptr tulong) 32))
                            (Expr.Econst_int (Integers.Int.repr 21) tint)
                            (tptr (tptr tulong))) (tptr tulong))
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                          (tptr tvoid)))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                _vector_hi (tarray (tptr tulong) 32))
                              (Expr.Econst_int (Integers.Int.repr 22) tint)
                              (tptr (tptr tulong))) (tptr tulong))
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                            (tptr tvoid)))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                  _vector_hi (tarray (tptr tulong) 32))
                                (Expr.Econst_int (Integers.Int.repr 23) tint)
                                (tptr (tptr tulong))) (tptr tulong))
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 0) tint)
                              (tptr tvoid)))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                    _vector_hi (tarray (tptr tulong) 32))
                                  (Expr.Econst_int (Integers.Int.repr 24) tint)
                                  (tptr (tptr tulong))) (tptr tulong))
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 0) tint)
                                (tptr tvoid)))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                      _vector_hi (tarray (tptr tulong) 32))
                                    (Expr.Econst_int (Integers.Int.repr 25) tint)
                                    (tptr (tptr tulong))) (tptr tulong))
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 0) tint)
                                  (tptr tvoid)))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Efield
                                        (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                        _vector_hi (tarray (tptr tulong) 32))
                                      (Expr.Econst_int (Integers.Int.repr 26) tint)
                                      (tptr (tptr tulong))) (tptr tulong))
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 0) tint)
                                    (tptr tvoid)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_raw_45
                                  s_kprog_arm64_entry_raw_48)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_raw_50 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Efield
          (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
          _vector_lo (tarray (tptr tulong) 32))
        (Expr.Econst_int (Integers.Int.repr 26) tint) (tptr (tptr tulong)))
      (tptr tulong))
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Efield
            (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
            _vector_lo (tarray (tptr tulong) 32))
          (Expr.Econst_int (Integers.Int.repr 27) tint) (tptr (tptr tulong)))
        (tptr tulong))
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
              _vector_lo (tarray (tptr tulong) 32))
            (Expr.Econst_int (Integers.Int.repr 28) tint)
            (tptr (tptr tulong))) (tptr tulong))
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
          (tptr tvoid)))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                _vector_lo (tarray (tptr tulong) 32))
              (Expr.Econst_int (Integers.Int.repr 29) tint)
              (tptr (tptr tulong))) (tptr tulong))
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
            (tptr tvoid)))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                  _vector_lo (tarray (tptr tulong) 32))
                (Expr.Econst_int (Integers.Int.repr 30) tint)
                (tptr (tptr tulong))) (tptr tulong))
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
              (tptr tvoid)))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                    _vector_lo (tarray (tptr tulong) 32))
                  (Expr.Econst_int (Integers.Int.repr 31) tint)
                  (tptr (tptr tulong))) (tptr tulong))
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                (tptr tvoid)))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Efield
                      (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                      _vector_hi (tarray (tptr tulong) 32))
                    (Expr.Econst_int (Integers.Int.repr 0) tint)
                    (tptr (tptr tulong))) (tptr tulong))
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                  (tptr tvoid)))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                        _vector_hi (tarray (tptr tulong) 32))
                      (Expr.Econst_int (Integers.Int.repr 1) tint)
                      (tptr (tptr tulong))) (tptr tulong))
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                    (tptr tvoid)))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                          _vector_hi (tarray (tptr tulong) 32))
                        (Expr.Econst_int (Integers.Int.repr 2) tint)
                        (tptr (tptr tulong))) (tptr tulong))
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                      (tptr tvoid)))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Efield
                            (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                            _vector_hi (tarray (tptr tulong) 32))
                          (Expr.Econst_int (Integers.Int.repr 3) tint)
                          (tptr (tptr tulong))) (tptr tulong))
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 0) tint)
                        (tptr tvoid)))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                              _vector_hi (tarray (tptr tulong) 32))
                            (Expr.Econst_int (Integers.Int.repr 4) tint)
                            (tptr (tptr tulong))) (tptr tulong))
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                          (tptr tvoid)))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                _vector_hi (tarray (tptr tulong) 32))
                              (Expr.Econst_int (Integers.Int.repr 5) tint)
                              (tptr (tptr tulong))) (tptr tulong))
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                            (tptr tvoid)))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                  _vector_hi (tarray (tptr tulong) 32))
                                (Expr.Econst_int (Integers.Int.repr 6) tint)
                                (tptr (tptr tulong))) (tptr tulong))
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 0) tint)
                              (tptr tvoid)))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                    _vector_hi (tarray (tptr tulong) 32))
                                  (Expr.Econst_int (Integers.Int.repr 7) tint)
                                  (tptr (tptr tulong))) (tptr tulong))
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 0) tint)
                                (tptr tvoid)))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                      _vector_hi (tarray (tptr tulong) 32))
                                    (Expr.Econst_int (Integers.Int.repr 8) tint)
                                    (tptr (tptr tulong))) (tptr tulong))
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 0) tint)
                                  (tptr tvoid)))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Efield
                                        (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                        _vector_hi (tarray (tptr tulong) 32))
                                      (Expr.Econst_int (Integers.Int.repr 9) tint)
                                      (tptr (tptr tulong))) (tptr tulong))
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 0) tint)
                                    (tptr tvoid)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_raw_44
                                  s_kprog_arm64_entry_raw_49)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_raw_51 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Efield
          (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
          _vector_lo (tarray (tptr tulong) 32))
        (Expr.Econst_int (Integers.Int.repr 9) tint) (tptr (tptr tulong)))
      (tptr tulong))
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Efield
            (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
            _vector_lo (tarray (tptr tulong) 32))
          (Expr.Econst_int (Integers.Int.repr 10) tint) (tptr (tptr tulong)))
        (tptr tulong))
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
              _vector_lo (tarray (tptr tulong) 32))
            (Expr.Econst_int (Integers.Int.repr 11) tint)
            (tptr (tptr tulong))) (tptr tulong))
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
          (tptr tvoid)))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                _vector_lo (tarray (tptr tulong) 32))
              (Expr.Econst_int (Integers.Int.repr 12) tint)
              (tptr (tptr tulong))) (tptr tulong))
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
            (tptr tvoid)))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                  _vector_lo (tarray (tptr tulong) 32))
                (Expr.Econst_int (Integers.Int.repr 13) tint)
                (tptr (tptr tulong))) (tptr tulong))
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
              (tptr tvoid)))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                    _vector_lo (tarray (tptr tulong) 32))
                  (Expr.Econst_int (Integers.Int.repr 14) tint)
                  (tptr (tptr tulong))) (tptr tulong))
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                (tptr tvoid)))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Efield
                      (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                      _vector_lo (tarray (tptr tulong) 32))
                    (Expr.Econst_int (Integers.Int.repr 15) tint)
                    (tptr (tptr tulong))) (tptr tulong))
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                  (tptr tvoid)))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                        _vector_lo (tarray (tptr tulong) 32))
                      (Expr.Econst_int (Integers.Int.repr 16) tint)
                      (tptr (tptr tulong))) (tptr tulong))
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                    (tptr tvoid)))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                          _vector_lo (tarray (tptr tulong) 32))
                        (Expr.Econst_int (Integers.Int.repr 17) tint)
                        (tptr (tptr tulong))) (tptr tulong))
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                      (tptr tvoid)))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Efield
                            (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                            _vector_lo (tarray (tptr tulong) 32))
                          (Expr.Econst_int (Integers.Int.repr 18) tint)
                          (tptr (tptr tulong))) (tptr tulong))
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 0) tint)
                        (tptr tvoid)))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                              _vector_lo (tarray (tptr tulong) 32))
                            (Expr.Econst_int (Integers.Int.repr 19) tint)
                            (tptr (tptr tulong))) (tptr tulong))
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                          (tptr tvoid)))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                _vector_lo (tarray (tptr tulong) 32))
                              (Expr.Econst_int (Integers.Int.repr 20) tint)
                              (tptr (tptr tulong))) (tptr tulong))
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                            (tptr tvoid)))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                  _vector_lo (tarray (tptr tulong) 32))
                                (Expr.Econst_int (Integers.Int.repr 21) tint)
                                (tptr (tptr tulong))) (tptr tulong))
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 0) tint)
                              (tptr tvoid)))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                    _vector_lo (tarray (tptr tulong) 32))
                                  (Expr.Econst_int (Integers.Int.repr 22) tint)
                                  (tptr (tptr tulong))) (tptr tulong))
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 0) tint)
                                (tptr tvoid)))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                      _vector_lo (tarray (tptr tulong) 32))
                                    (Expr.Econst_int (Integers.Int.repr 23) tint)
                                    (tptr (tptr tulong))) (tptr tulong))
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 0) tint)
                                  (tptr tvoid)))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Efield
                                        (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                        _vector_lo (tarray (tptr tulong) 32))
                                      (Expr.Econst_int (Integers.Int.repr 24) tint)
                                      (tptr (tptr tulong))) (tptr tulong))
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 0) tint)
                                    (tptr tvoid)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_raw_43
                                  s_kprog_arm64_entry_raw_50)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_raw_52 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Efield (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
      _lr (tptr tulong))
    (Expr.Eaddrof (Expr.Evar ___a64_lr tulong) (tptr tulong)))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Efield (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
        _sp (tptr tlong))
      (Expr.Eaddrof (Expr.Evar ___a64_sp tlong) (tptr tlong)))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Efield
          (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr)) _sp_valid
          (tptr tuchar))
        (Expr.Eaddrof (Expr.Evar ___a64_numeric_sp_valid tuchar)
          (tptr tuchar)))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Efield
            (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
            _return_valid (tptr tuchar))
          (Expr.Eaddrof (Expr.Evar ___a64_numeric_return_valid tuchar)
            (tptr tuchar)))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Efield
              (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr)) _n
              (tptr tuchar))
            (Expr.Eaddrof (Expr.Evar ___a64_n tuchar) (tptr tuchar)))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Efield
                (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr)) _z
                (tptr tuchar))
              (Expr.Eaddrof (Expr.Evar ___a64_z tuchar) (tptr tuchar)))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                  _c (tptr tuchar))
                (Expr.Eaddrof (Expr.Evar ___a64_c tuchar) (tptr tuchar)))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Efield
                    (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                    _v (tptr tuchar))
                  (Expr.Eaddrof (Expr.Evar ___a64_v tuchar) (tptr tuchar)))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                          _vector_lo (tarray (tptr tulong) 32))
                        (Expr.Econst_int (Integers.Int.repr 0) tint)
                        (tptr (tptr tulong))) (tptr tulong))
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                      (tptr tvoid)))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Efield
                            (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                            _vector_lo (tarray (tptr tulong) 32))
                          (Expr.Econst_int (Integers.Int.repr 1) tint)
                          (tptr (tptr tulong))) (tptr tulong))
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 0) tint)
                        (tptr tvoid)))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                              _vector_lo (tarray (tptr tulong) 32))
                            (Expr.Econst_int (Integers.Int.repr 2) tint)
                            (tptr (tptr tulong))) (tptr tulong))
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                          (tptr tvoid)))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                _vector_lo (tarray (tptr tulong) 32))
                              (Expr.Econst_int (Integers.Int.repr 3) tint)
                              (tptr (tptr tulong))) (tptr tulong))
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                            (tptr tvoid)))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                  _vector_lo (tarray (tptr tulong) 32))
                                (Expr.Econst_int (Integers.Int.repr 4) tint)
                                (tptr (tptr tulong))) (tptr tulong))
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 0) tint)
                              (tptr tvoid)))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                    _vector_lo (tarray (tptr tulong) 32))
                                  (Expr.Econst_int (Integers.Int.repr 5) tint)
                                  (tptr (tptr tulong))) (tptr tulong))
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 0) tint)
                                (tptr tvoid)))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                      _vector_lo (tarray (tptr tulong) 32))
                                    (Expr.Econst_int (Integers.Int.repr 6) tint)
                                    (tptr (tptr tulong))) (tptr tulong))
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 0) tint)
                                  (tptr tvoid)))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Efield
                                        (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                        _vector_lo (tarray (tptr tulong) 32))
                                      (Expr.Econst_int (Integers.Int.repr 7) tint)
                                      (tptr (tptr tulong))) (tptr tulong))
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 0) tint)
                                    (tptr tvoid)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_raw_42
                                  s_kprog_arm64_entry_raw_51)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_raw_53 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
        (Expr.Econst_int (Integers.Int.repr 18) tint) (tptr tuchar)) tuchar)
    (Expr.Econst_int (Integers.Int.repr 0) tint))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
          (Expr.Econst_int (Integers.Int.repr 19) tint) (tptr tuchar))
        tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
            (Expr.Econst_int (Integers.Int.repr 20) tint) (tptr tuchar))
          tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
              (Expr.Econst_int (Integers.Int.repr 21) tint) (tptr tuchar))
            tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                (Expr.Econst_int (Integers.Int.repr 22) tint) (tptr tuchar))
              tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                  (Expr.Econst_int (Integers.Int.repr 23) tint)
                  (tptr tuchar)) tuchar)
              (Expr.Econst_int (Integers.Int.repr 0) tint))
            (Stmt.Ssequence
              (Stmt.Sassign (Expr.Evar ___a64_sp tlong)
                (Expr.Econst_int (Integers.Int.repr 0) tint))
              (Stmt.Ssequence
                (Stmt.Sassign (Expr.Evar ___a64_sim_helper_ctx (tptr tvoid))
                  (Expr.Ecast (Expr.Etempvar _ctx (tptr tvoid)) (tptr tvoid)))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Evar ___a64_sim_helper_abi_base (tptr tvoid))
                    (Expr.Ecast (Expr.Etempvar _ctx (tptr tvoid))
                      (tptr tvoid)))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Efield
                        (Expr.Evar ___a64_x0 (Ty.Tunion _arm64_sim_gpr noattr))
                        _ptr (tptr tvoid))
                      (Expr.Ecast (Expr.Etempvar _ctx (tptr tvoid))
                        (tptr tvoid)))
                    (Stmt.Ssequence
                      (Stmt.Sassign (Expr.Evar ___a64_x30_tag tuchar)
                        (Expr.Econst_int (Integers.Int.repr 10) tuint))
                      (Stmt.Ssequence
                        (Stmt.Sassign (Expr.Evar ___a64_x0_tag tuchar)
                          (Expr.Econst_int (Integers.Int.repr 1) tuint))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                              _cells
                              (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                            (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31)))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                _tag_cells (tptr (tptr tuchar)))
                              (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31)))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                  _sp_base (tptr tulong))
                                (Expr.Eaddrof
                                  (Expr.Evar ___a64_numeric_sp tulong)
                                  (tptr tulong)))
                              (Stmt.Ssequence
                                s_kprog_arm64_entry_raw_41
                                s_kprog_arm64_entry_raw_52))))))))))))))))

@[noinline] def s_kprog_arm64_entry_raw_54 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
        (Expr.Econst_int (Integers.Int.repr 1) tint) (tptr tuchar)) tuchar)
    (Expr.Econst_int (Integers.Int.repr 0) tint))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
          (Expr.Econst_int (Integers.Int.repr 2) tint) (tptr tuchar)) tuchar)
      (Expr.Econst_int (Integers.Int.repr 0) tint))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
            (Expr.Econst_int (Integers.Int.repr 3) tint) (tptr tuchar))
          tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
              (Expr.Econst_int (Integers.Int.repr 4) tint) (tptr tuchar))
            tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                (Expr.Econst_int (Integers.Int.repr 5) tint) (tptr tuchar))
              tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                  (Expr.Econst_int (Integers.Int.repr 6) tint) (tptr tuchar))
                tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                    (Expr.Econst_int (Integers.Int.repr 7) tint)
                    (tptr tuchar)) tuchar)
                (Expr.Econst_int (Integers.Int.repr 0) tint))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                      (Expr.Econst_int (Integers.Int.repr 8) tint)
                      (tptr tuchar)) tuchar)
                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                        (Expr.Econst_int (Integers.Int.repr 9) tint)
                        (tptr tuchar)) tuchar)
                    (Expr.Econst_int (Integers.Int.repr 0) tint))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                          (Expr.Econst_int (Integers.Int.repr 10) tint)
                          (tptr tuchar)) tuchar)
                      (Expr.Econst_int (Integers.Int.repr 0) tint))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                            (Expr.Econst_int (Integers.Int.repr 11) tint)
                            (tptr tuchar)) tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tint))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                              (Expr.Econst_int (Integers.Int.repr 12) tint)
                              (tptr tuchar)) tuchar)
                          (Expr.Econst_int (Integers.Int.repr 0) tint))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                                (Expr.Econst_int (Integers.Int.repr 13) tint)
                                (tptr tuchar)) tuchar)
                            (Expr.Econst_int (Integers.Int.repr 0) tint))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                                  (Expr.Econst_int (Integers.Int.repr 14) tint)
                                  (tptr tuchar)) tuchar)
                              (Expr.Econst_int (Integers.Int.repr 0) tint))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                                    (Expr.Econst_int (Integers.Int.repr 15) tint)
                                    (tptr tuchar)) tuchar)
                                (Expr.Econst_int (Integers.Int.repr 0) tint))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                                      (Expr.Econst_int (Integers.Int.repr 16) tint)
                                      (tptr tuchar)) tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_raw_40
                                  s_kprog_arm64_entry_raw_53)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_raw_55 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Scall (some _t'115)
      (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                           cc_default))
      [(Expr.Econst_int (Integers.Int.repr 6) tint)])
    (Stmt.Sassign
      (Expr.Efield
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
            (Expr.Econst_int (Integers.Int.repr 24) tint)
            (tptr (Ty.Tstruct __2854 noattr))) (Ty.Tstruct __2854 noattr))
        _lo tulong) (Expr.Etempvar _t'115 tulong)))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Scall (some _t'116)
        (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                             cc_default))
        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
      (Stmt.Sassign
        (Expr.Efield
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
              (Expr.Econst_int (Integers.Int.repr 24) tint)
              (tptr (Ty.Tstruct __2854 noattr))) (Ty.Tstruct __2854 noattr))
          _hi tulong) (Expr.Etempvar _t'116 tulong)))
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Scall (some _t'117)
          (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                               cc_default))
          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
        (Stmt.Sassign
          (Expr.Efield
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                (Expr.Econst_int (Integers.Int.repr 25) tint)
                (tptr (Ty.Tstruct __2854 noattr)))
              (Ty.Tstruct __2854 noattr)) _lo tulong)
          (Expr.Etempvar _t'117 tulong)))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Scall (some _t'118)
            (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                 cc_default))
            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
          (Stmt.Sassign
            (Expr.Efield
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                  (Expr.Econst_int (Integers.Int.repr 25) tint)
                  (tptr (Ty.Tstruct __2854 noattr)))
                (Ty.Tstruct __2854 noattr)) _hi tulong)
            (Expr.Etempvar _t'118 tulong)))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Scall (some _t'119)
              (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                   cc_default))
              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
            (Stmt.Sassign
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                    (Expr.Econst_int (Integers.Int.repr 26) tint)
                    (tptr (Ty.Tstruct __2854 noattr)))
                  (Ty.Tstruct __2854 noattr)) _lo tulong)
              (Expr.Etempvar _t'119 tulong)))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Scall (some _t'120)
                (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                     tulong cc_default))
                [(Expr.Econst_int (Integers.Int.repr 6) tint)])
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                      (Expr.Econst_int (Integers.Int.repr 26) tint)
                      (tptr (Ty.Tstruct __2854 noattr)))
                    (Ty.Tstruct __2854 noattr)) _hi tulong)
                (Expr.Etempvar _t'120 tulong)))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Scall (some _t'121)
                  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                       tulong cc_default))
                  [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                (Stmt.Sassign
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                        (Expr.Econst_int (Integers.Int.repr 27) tint)
                        (tptr (Ty.Tstruct __2854 noattr)))
                      (Ty.Tstruct __2854 noattr)) _lo tulong)
                  (Expr.Etempvar _t'121 tulong)))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Scall (some _t'122)
                    (Expr.Evar _native_lab_entry_input (Ty.Tfunction 
                                                         [tuint] tulong
                                                         cc_default))
                    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                  (Stmt.Sassign
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                          (Expr.Econst_int (Integers.Int.repr 27) tint)
                          (tptr (Ty.Tstruct __2854 noattr)))
                        (Ty.Tstruct __2854 noattr)) _hi tulong)
                    (Expr.Etempvar _t'122 tulong)))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Scall (some _t'123)
                      (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                           [tuint] tulong
                                                           cc_default))
                      [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                    (Stmt.Sassign
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                            (Expr.Econst_int (Integers.Int.repr 28) tint)
                            (tptr (Ty.Tstruct __2854 noattr)))
                          (Ty.Tstruct __2854 noattr)) _lo tulong)
                      (Expr.Etempvar _t'123 tulong)))
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Scall (some _t'124)
                        (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                             [tuint] tulong
                                                             cc_default))
                        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                      (Stmt.Sassign
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                              (Expr.Econst_int (Integers.Int.repr 28) tint)
                              (tptr (Ty.Tstruct __2854 noattr)))
                            (Ty.Tstruct __2854 noattr)) _hi tulong)
                        (Expr.Etempvar _t'124 tulong)))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Scall (some _t'125)
                          (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                               [tuint] tulong
                                                               cc_default))
                          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                                (Expr.Econst_int (Integers.Int.repr 29) tint)
                                (tptr (Ty.Tstruct __2854 noattr)))
                              (Ty.Tstruct __2854 noattr)) _lo tulong)
                          (Expr.Etempvar _t'125 tulong)))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'126)
                            (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                 [tuint]
                                                                 tulong
                                                                 cc_default))
                            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                                  (Expr.Econst_int (Integers.Int.repr 29) tint)
                                  (tptr (Ty.Tstruct __2854 noattr)))
                                (Ty.Tstruct __2854 noattr)) _hi tulong)
                            (Expr.Etempvar _t'126 tulong)))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Scall (some _t'127)
                              (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                   [tuint]
                                                                   tulong
                                                                   cc_default))
                              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                                    (Expr.Econst_int (Integers.Int.repr 30) tint)
                                    (tptr (Ty.Tstruct __2854 noattr)))
                                  (Ty.Tstruct __2854 noattr)) _lo tulong)
                              (Expr.Etempvar _t'127 tulong)))
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Scall (some _t'128)
                                (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                    [tuint]
                                                                    tulong
                                                                    cc_default))
                                [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                                      (Expr.Econst_int (Integers.Int.repr 30) tint)
                                      (tptr (Ty.Tstruct __2854 noattr)))
                                    (Ty.Tstruct __2854 noattr)) _hi tulong)
                                (Expr.Etempvar _t'128 tulong)))
                            (Stmt.Ssequence
                              (Stmt.Ssequence
                                (Stmt.Scall (some _t'129)
                                  (Expr.Evar _native_lab_entry_input 
                                  (Ty.Tfunction [tuint] tulong cc_default))
                                  [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                                (Stmt.Sassign
                                  (Expr.Efield
                                    (Expr.Ederef
                                      (Expr.Ebinop Binop.Oadd
                                        (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                                        (Expr.Econst_int (Integers.Int.repr 31) tint)
                                        (tptr (Ty.Tstruct __2854 noattr)))
                                      (Ty.Tstruct __2854 noattr)) _lo tulong)
                                  (Expr.Etempvar _t'129 tulong)))
                              (Stmt.Ssequence
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_raw_38
                                  (Stmt.Sassign
                                    (Expr.Efield
                                      (Expr.Ederef
                                        (Expr.Ebinop Binop.Oadd
                                          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                                          (Expr.Econst_int (Integers.Int.repr 31) tint)
                                          (tptr (Ty.Tstruct __2854 noattr)))
                                        (Ty.Tstruct __2854 noattr)) _hi
                                      tulong) (Expr.Etempvar _t'130 tulong)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_raw_39
                                  s_kprog_arm64_entry_raw_54)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_raw_56 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Scall (some _t'98)
      (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                           cc_default))
      [(Expr.Econst_int (Integers.Int.repr 6) tint)])
    (Stmt.Sassign
      (Expr.Efield
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
            (Expr.Econst_int (Integers.Int.repr 15) tint)
            (tptr (Ty.Tstruct __2854 noattr))) (Ty.Tstruct __2854 noattr))
        _hi tulong) (Expr.Etempvar _t'98 tulong)))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Scall (some _t'99)
        (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                             cc_default))
        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
      (Stmt.Sassign
        (Expr.Efield
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
              (Expr.Econst_int (Integers.Int.repr 16) tint)
              (tptr (Ty.Tstruct __2854 noattr))) (Ty.Tstruct __2854 noattr))
          _lo tulong) (Expr.Etempvar _t'99 tulong)))
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Scall (some _t'100)
          (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                               cc_default))
          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
        (Stmt.Sassign
          (Expr.Efield
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                (Expr.Econst_int (Integers.Int.repr 16) tint)
                (tptr (Ty.Tstruct __2854 noattr)))
              (Ty.Tstruct __2854 noattr)) _hi tulong)
          (Expr.Etempvar _t'100 tulong)))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Scall (some _t'101)
            (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                 cc_default))
            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
          (Stmt.Sassign
            (Expr.Efield
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                  (Expr.Econst_int (Integers.Int.repr 17) tint)
                  (tptr (Ty.Tstruct __2854 noattr)))
                (Ty.Tstruct __2854 noattr)) _lo tulong)
            (Expr.Etempvar _t'101 tulong)))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Scall (some _t'102)
              (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                   cc_default))
              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
            (Stmt.Sassign
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                    (Expr.Econst_int (Integers.Int.repr 17) tint)
                    (tptr (Ty.Tstruct __2854 noattr)))
                  (Ty.Tstruct __2854 noattr)) _hi tulong)
              (Expr.Etempvar _t'102 tulong)))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Scall (some _t'103)
                (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                     tulong cc_default))
                [(Expr.Econst_int (Integers.Int.repr 6) tint)])
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                      (Expr.Econst_int (Integers.Int.repr 18) tint)
                      (tptr (Ty.Tstruct __2854 noattr)))
                    (Ty.Tstruct __2854 noattr)) _lo tulong)
                (Expr.Etempvar _t'103 tulong)))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Scall (some _t'104)
                  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                       tulong cc_default))
                  [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                (Stmt.Sassign
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                        (Expr.Econst_int (Integers.Int.repr 18) tint)
                        (tptr (Ty.Tstruct __2854 noattr)))
                      (Ty.Tstruct __2854 noattr)) _hi tulong)
                  (Expr.Etempvar _t'104 tulong)))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Scall (some _t'105)
                    (Expr.Evar _native_lab_entry_input (Ty.Tfunction 
                                                         [tuint] tulong
                                                         cc_default))
                    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                  (Stmt.Sassign
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                          (Expr.Econst_int (Integers.Int.repr 19) tint)
                          (tptr (Ty.Tstruct __2854 noattr)))
                        (Ty.Tstruct __2854 noattr)) _lo tulong)
                    (Expr.Etempvar _t'105 tulong)))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Scall (some _t'106)
                      (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                           [tuint] tulong
                                                           cc_default))
                      [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                    (Stmt.Sassign
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                            (Expr.Econst_int (Integers.Int.repr 19) tint)
                            (tptr (Ty.Tstruct __2854 noattr)))
                          (Ty.Tstruct __2854 noattr)) _hi tulong)
                      (Expr.Etempvar _t'106 tulong)))
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Scall (some _t'107)
                        (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                             [tuint] tulong
                                                             cc_default))
                        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                      (Stmt.Sassign
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                              (Expr.Econst_int (Integers.Int.repr 20) tint)
                              (tptr (Ty.Tstruct __2854 noattr)))
                            (Ty.Tstruct __2854 noattr)) _lo tulong)
                        (Expr.Etempvar _t'107 tulong)))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Scall (some _t'108)
                          (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                               [tuint] tulong
                                                               cc_default))
                          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                                (Expr.Econst_int (Integers.Int.repr 20) tint)
                                (tptr (Ty.Tstruct __2854 noattr)))
                              (Ty.Tstruct __2854 noattr)) _hi tulong)
                          (Expr.Etempvar _t'108 tulong)))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'109)
                            (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                 [tuint]
                                                                 tulong
                                                                 cc_default))
                            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                                  (Expr.Econst_int (Integers.Int.repr 21) tint)
                                  (tptr (Ty.Tstruct __2854 noattr)))
                                (Ty.Tstruct __2854 noattr)) _lo tulong)
                            (Expr.Etempvar _t'109 tulong)))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Scall (some _t'110)
                              (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                   [tuint]
                                                                   tulong
                                                                   cc_default))
                              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                                    (Expr.Econst_int (Integers.Int.repr 21) tint)
                                    (tptr (Ty.Tstruct __2854 noattr)))
                                  (Ty.Tstruct __2854 noattr)) _hi tulong)
                              (Expr.Etempvar _t'110 tulong)))
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Scall (some _t'111)
                                (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                    [tuint]
                                                                    tulong
                                                                    cc_default))
                                [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                                      (Expr.Econst_int (Integers.Int.repr 22) tint)
                                      (tptr (Ty.Tstruct __2854 noattr)))
                                    (Ty.Tstruct __2854 noattr)) _lo tulong)
                                (Expr.Etempvar _t'111 tulong)))
                            (Stmt.Ssequence
                              (Stmt.Ssequence
                                (Stmt.Scall (some _t'112)
                                  (Expr.Evar _native_lab_entry_input 
                                  (Ty.Tfunction [tuint] tulong cc_default))
                                  [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                                (Stmt.Sassign
                                  (Expr.Efield
                                    (Expr.Ederef
                                      (Expr.Ebinop Binop.Oadd
                                        (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                                        (Expr.Econst_int (Integers.Int.repr 22) tint)
                                        (tptr (Ty.Tstruct __2854 noattr)))
                                      (Ty.Tstruct __2854 noattr)) _hi tulong)
                                  (Expr.Etempvar _t'112 tulong)))
                              (Stmt.Ssequence
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_raw_36
                                  (Stmt.Sassign
                                    (Expr.Efield
                                      (Expr.Ederef
                                        (Expr.Ebinop Binop.Oadd
                                          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                                          (Expr.Econst_int (Integers.Int.repr 23) tint)
                                          (tptr (Ty.Tstruct __2854 noattr)))
                                        (Ty.Tstruct __2854 noattr)) _lo
                                      tulong) (Expr.Etempvar _t'113 tulong)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_raw_37
                                  s_kprog_arm64_entry_raw_55)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_raw_57 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Scall (some _t'81)
      (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                           cc_default))
      [(Expr.Econst_int (Integers.Int.repr 6) tint)])
    (Stmt.Sassign
      (Expr.Efield
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
            (Expr.Econst_int (Integers.Int.repr 7) tint)
            (tptr (Ty.Tstruct __2854 noattr))) (Ty.Tstruct __2854 noattr))
        _lo tulong) (Expr.Etempvar _t'81 tulong)))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Scall (some _t'82)
        (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                             cc_default))
        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
      (Stmt.Sassign
        (Expr.Efield
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
              (Expr.Econst_int (Integers.Int.repr 7) tint)
              (tptr (Ty.Tstruct __2854 noattr))) (Ty.Tstruct __2854 noattr))
          _hi tulong) (Expr.Etempvar _t'82 tulong)))
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Scall (some _t'83)
          (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                               cc_default))
          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
        (Stmt.Sassign
          (Expr.Efield
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                (Expr.Econst_int (Integers.Int.repr 8) tint)
                (tptr (Ty.Tstruct __2854 noattr)))
              (Ty.Tstruct __2854 noattr)) _lo tulong)
          (Expr.Etempvar _t'83 tulong)))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Scall (some _t'84)
            (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                 cc_default))
            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
          (Stmt.Sassign
            (Expr.Efield
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                  (Expr.Econst_int (Integers.Int.repr 8) tint)
                  (tptr (Ty.Tstruct __2854 noattr)))
                (Ty.Tstruct __2854 noattr)) _hi tulong)
            (Expr.Etempvar _t'84 tulong)))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Scall (some _t'85)
              (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                   cc_default))
              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
            (Stmt.Sassign
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                    (Expr.Econst_int (Integers.Int.repr 9) tint)
                    (tptr (Ty.Tstruct __2854 noattr)))
                  (Ty.Tstruct __2854 noattr)) _lo tulong)
              (Expr.Etempvar _t'85 tulong)))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Scall (some _t'86)
                (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                     tulong cc_default))
                [(Expr.Econst_int (Integers.Int.repr 6) tint)])
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                      (Expr.Econst_int (Integers.Int.repr 9) tint)
                      (tptr (Ty.Tstruct __2854 noattr)))
                    (Ty.Tstruct __2854 noattr)) _hi tulong)
                (Expr.Etempvar _t'86 tulong)))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Scall (some _t'87)
                  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                       tulong cc_default))
                  [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                (Stmt.Sassign
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                        (Expr.Econst_int (Integers.Int.repr 10) tint)
                        (tptr (Ty.Tstruct __2854 noattr)))
                      (Ty.Tstruct __2854 noattr)) _lo tulong)
                  (Expr.Etempvar _t'87 tulong)))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Scall (some _t'88)
                    (Expr.Evar _native_lab_entry_input (Ty.Tfunction 
                                                         [tuint] tulong
                                                         cc_default))
                    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                  (Stmt.Sassign
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                          (Expr.Econst_int (Integers.Int.repr 10) tint)
                          (tptr (Ty.Tstruct __2854 noattr)))
                        (Ty.Tstruct __2854 noattr)) _hi tulong)
                    (Expr.Etempvar _t'88 tulong)))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Scall (some _t'89)
                      (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                           [tuint] tulong
                                                           cc_default))
                      [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                    (Stmt.Sassign
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                            (Expr.Econst_int (Integers.Int.repr 11) tint)
                            (tptr (Ty.Tstruct __2854 noattr)))
                          (Ty.Tstruct __2854 noattr)) _lo tulong)
                      (Expr.Etempvar _t'89 tulong)))
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Scall (some _t'90)
                        (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                             [tuint] tulong
                                                             cc_default))
                        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                      (Stmt.Sassign
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                              (Expr.Econst_int (Integers.Int.repr 11) tint)
                              (tptr (Ty.Tstruct __2854 noattr)))
                            (Ty.Tstruct __2854 noattr)) _hi tulong)
                        (Expr.Etempvar _t'90 tulong)))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Scall (some _t'91)
                          (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                               [tuint] tulong
                                                               cc_default))
                          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                                (Expr.Econst_int (Integers.Int.repr 12) tint)
                                (tptr (Ty.Tstruct __2854 noattr)))
                              (Ty.Tstruct __2854 noattr)) _lo tulong)
                          (Expr.Etempvar _t'91 tulong)))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'92)
                            (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                 [tuint]
                                                                 tulong
                                                                 cc_default))
                            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                                  (Expr.Econst_int (Integers.Int.repr 12) tint)
                                  (tptr (Ty.Tstruct __2854 noattr)))
                                (Ty.Tstruct __2854 noattr)) _hi tulong)
                            (Expr.Etempvar _t'92 tulong)))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Scall (some _t'93)
                              (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                   [tuint]
                                                                   tulong
                                                                   cc_default))
                              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                                    (Expr.Econst_int (Integers.Int.repr 13) tint)
                                    (tptr (Ty.Tstruct __2854 noattr)))
                                  (Ty.Tstruct __2854 noattr)) _lo tulong)
                              (Expr.Etempvar _t'93 tulong)))
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Scall (some _t'94)
                                (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                    [tuint]
                                                                    tulong
                                                                    cc_default))
                                [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                                      (Expr.Econst_int (Integers.Int.repr 13) tint)
                                      (tptr (Ty.Tstruct __2854 noattr)))
                                    (Ty.Tstruct __2854 noattr)) _hi tulong)
                                (Expr.Etempvar _t'94 tulong)))
                            (Stmt.Ssequence
                              (Stmt.Ssequence
                                (Stmt.Scall (some _t'95)
                                  (Expr.Evar _native_lab_entry_input 
                                  (Ty.Tfunction [tuint] tulong cc_default))
                                  [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                                (Stmt.Sassign
                                  (Expr.Efield
                                    (Expr.Ederef
                                      (Expr.Ebinop Binop.Oadd
                                        (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                                        (Expr.Econst_int (Integers.Int.repr 14) tint)
                                        (tptr (Ty.Tstruct __2854 noattr)))
                                      (Ty.Tstruct __2854 noattr)) _lo tulong)
                                  (Expr.Etempvar _t'95 tulong)))
                              (Stmt.Ssequence
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_raw_34
                                  (Stmt.Sassign
                                    (Expr.Efield
                                      (Expr.Ederef
                                        (Expr.Ebinop Binop.Oadd
                                          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                                          (Expr.Econst_int (Integers.Int.repr 14) tint)
                                          (tptr (Ty.Tstruct __2854 noattr)))
                                        (Ty.Tstruct __2854 noattr)) _hi
                                      tulong) (Expr.Etempvar _t'96 tulong)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_raw_35
                                  s_kprog_arm64_entry_raw_56)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_raw_58 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Scall (some _t'65)
      (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                           cc_default))
      [(Expr.Econst_int (Integers.Int.repr 6) tint)])
    (Stmt.Sassign (Expr.Evar ___a64_c tuchar)
      (Expr.Ebinop Binop.Oand (Expr.Etempvar _t'65 tulong)
        (Expr.Econst_int (Integers.Int.repr 1) tint) tulong)))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Scall (some _t'66)
        (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                             cc_default))
        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
      (Stmt.Sassign (Expr.Evar ___a64_v tuchar)
        (Expr.Ebinop Binop.Oand (Expr.Etempvar _t'66 tulong)
          (Expr.Econst_int (Integers.Int.repr 1) tint) tulong)))
    (Stmt.Ssequence
      (Stmt.Sassign (Expr.Evar ___a64_lr tulong)
        (Expr.Econst_int (Integers.Int.repr 0) tint))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Scall (some _t'67)
            (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                 cc_default))
            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
          (Stmt.Sassign
            (Expr.Efield
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                  (Expr.Econst_int (Integers.Int.repr 0) tint)
                  (tptr (Ty.Tstruct __2854 noattr)))
                (Ty.Tstruct __2854 noattr)) _lo tulong)
            (Expr.Etempvar _t'67 tulong)))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Scall (some _t'68)
              (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                   cc_default))
              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
            (Stmt.Sassign
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                    (Expr.Econst_int (Integers.Int.repr 0) tint)
                    (tptr (Ty.Tstruct __2854 noattr)))
                  (Ty.Tstruct __2854 noattr)) _hi tulong)
              (Expr.Etempvar _t'68 tulong)))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Scall (some _t'69)
                (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                     tulong cc_default))
                [(Expr.Econst_int (Integers.Int.repr 6) tint)])
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                      (Expr.Econst_int (Integers.Int.repr 1) tint)
                      (tptr (Ty.Tstruct __2854 noattr)))
                    (Ty.Tstruct __2854 noattr)) _lo tulong)
                (Expr.Etempvar _t'69 tulong)))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Scall (some _t'70)
                  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                       tulong cc_default))
                  [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                (Stmt.Sassign
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                        (Expr.Econst_int (Integers.Int.repr 1) tint)
                        (tptr (Ty.Tstruct __2854 noattr)))
                      (Ty.Tstruct __2854 noattr)) _hi tulong)
                  (Expr.Etempvar _t'70 tulong)))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Scall (some _t'71)
                    (Expr.Evar _native_lab_entry_input (Ty.Tfunction 
                                                         [tuint] tulong
                                                         cc_default))
                    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                  (Stmt.Sassign
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                          (Expr.Econst_int (Integers.Int.repr 2) tint)
                          (tptr (Ty.Tstruct __2854 noattr)))
                        (Ty.Tstruct __2854 noattr)) _lo tulong)
                    (Expr.Etempvar _t'71 tulong)))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Scall (some _t'72)
                      (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                           [tuint] tulong
                                                           cc_default))
                      [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                    (Stmt.Sassign
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                            (Expr.Econst_int (Integers.Int.repr 2) tint)
                            (tptr (Ty.Tstruct __2854 noattr)))
                          (Ty.Tstruct __2854 noattr)) _hi tulong)
                      (Expr.Etempvar _t'72 tulong)))
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Scall (some _t'73)
                        (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                             [tuint] tulong
                                                             cc_default))
                        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                      (Stmt.Sassign
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                              (Expr.Econst_int (Integers.Int.repr 3) tint)
                              (tptr (Ty.Tstruct __2854 noattr)))
                            (Ty.Tstruct __2854 noattr)) _lo tulong)
                        (Expr.Etempvar _t'73 tulong)))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Scall (some _t'74)
                          (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                               [tuint] tulong
                                                               cc_default))
                          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                                (Expr.Econst_int (Integers.Int.repr 3) tint)
                                (tptr (Ty.Tstruct __2854 noattr)))
                              (Ty.Tstruct __2854 noattr)) _hi tulong)
                          (Expr.Etempvar _t'74 tulong)))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'75)
                            (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                 [tuint]
                                                                 tulong
                                                                 cc_default))
                            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                                  (Expr.Econst_int (Integers.Int.repr 4) tint)
                                  (tptr (Ty.Tstruct __2854 noattr)))
                                (Ty.Tstruct __2854 noattr)) _lo tulong)
                            (Expr.Etempvar _t'75 tulong)))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Scall (some _t'76)
                              (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                   [tuint]
                                                                   tulong
                                                                   cc_default))
                              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                                    (Expr.Econst_int (Integers.Int.repr 4) tint)
                                    (tptr (Ty.Tstruct __2854 noattr)))
                                  (Ty.Tstruct __2854 noattr)) _hi tulong)
                              (Expr.Etempvar _t'76 tulong)))
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Scall (some _t'77)
                                (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                    [tuint]
                                                                    tulong
                                                                    cc_default))
                                [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                                      (Expr.Econst_int (Integers.Int.repr 5) tint)
                                      (tptr (Ty.Tstruct __2854 noattr)))
                                    (Ty.Tstruct __2854 noattr)) _lo tulong)
                                (Expr.Etempvar _t'77 tulong)))
                            (Stmt.Ssequence
                              (Stmt.Ssequence
                                (Stmt.Scall (some _t'78)
                                  (Expr.Evar _native_lab_entry_input 
                                  (Ty.Tfunction [tuint] tulong cc_default))
                                  [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                                (Stmt.Sassign
                                  (Expr.Efield
                                    (Expr.Ederef
                                      (Expr.Ebinop Binop.Oadd
                                        (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                                        (Expr.Econst_int (Integers.Int.repr 5) tint)
                                        (tptr (Ty.Tstruct __2854 noattr)))
                                      (Ty.Tstruct __2854 noattr)) _hi tulong)
                                  (Expr.Etempvar _t'78 tulong)))
                              (Stmt.Ssequence
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_raw_32
                                  (Stmt.Sassign
                                    (Expr.Efield
                                      (Expr.Ederef
                                        (Expr.Ebinop Binop.Oadd
                                          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2854 noattr) 32))
                                          (Expr.Econst_int (Integers.Int.repr 6) tint)
                                          (tptr (Ty.Tstruct __2854 noattr)))
                                        (Ty.Tstruct __2854 noattr)) _lo
                                      tulong) (Expr.Etempvar _t'79 tulong)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_raw_33
                                  s_kprog_arm64_entry_raw_57)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_raw_59 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
        (Expr.Econst_int (Integers.Int.repr 16) tint) (tptr (tptr tuchar)))
      (tptr tuchar))
    (Expr.Eaddrof (Expr.Evar ___a64_x16_tag tuchar) (tptr tuchar)))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
          (Expr.Econst_int (Integers.Int.repr 17) tint) (tptr (tptr tuchar)))
        (tptr tuchar))
      (Expr.Eaddrof (Expr.Evar ___a64_x17_tag tuchar) (tptr tuchar)))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
            (Expr.Econst_int (Integers.Int.repr 18) tint)
            (tptr (tptr tuchar))) (tptr tuchar))
        (Expr.Eaddrof (Expr.Evar ___a64_x18_tag tuchar) (tptr tuchar)))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
              (Expr.Econst_int (Integers.Int.repr 19) tint)
              (tptr (tptr tuchar))) (tptr tuchar))
          (Expr.Eaddrof (Expr.Evar ___a64_x19_tag tuchar) (tptr tuchar)))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                (Expr.Econst_int (Integers.Int.repr 20) tint)
                (tptr (tptr tuchar))) (tptr tuchar))
            (Expr.Eaddrof (Expr.Evar ___a64_x20_tag tuchar) (tptr tuchar)))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                  (Expr.Econst_int (Integers.Int.repr 21) tint)
                  (tptr (tptr tuchar))) (tptr tuchar))
              (Expr.Eaddrof (Expr.Evar ___a64_x21_tag tuchar) (tptr tuchar)))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                    (Expr.Econst_int (Integers.Int.repr 22) tint)
                    (tptr (tptr tuchar))) (tptr tuchar))
                (Expr.Eaddrof (Expr.Evar ___a64_x22_tag tuchar)
                  (tptr tuchar)))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                      (Expr.Econst_int (Integers.Int.repr 23) tint)
                      (tptr (tptr tuchar))) (tptr tuchar))
                  (Expr.Eaddrof (Expr.Evar ___a64_x23_tag tuchar)
                    (tptr tuchar)))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                        (Expr.Econst_int (Integers.Int.repr 24) tint)
                        (tptr (tptr tuchar))) (tptr tuchar))
                    (Expr.Eaddrof (Expr.Evar ___a64_x24_tag tuchar)
                      (tptr tuchar)))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                          (Expr.Econst_int (Integers.Int.repr 25) tint)
                          (tptr (tptr tuchar))) (tptr tuchar))
                      (Expr.Eaddrof (Expr.Evar ___a64_x25_tag tuchar)
                        (tptr tuchar)))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                            (Expr.Econst_int (Integers.Int.repr 26) tint)
                            (tptr (tptr tuchar))) (tptr tuchar))
                        (Expr.Eaddrof (Expr.Evar ___a64_x26_tag tuchar)
                          (tptr tuchar)))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                              (Expr.Econst_int (Integers.Int.repr 27) tint)
                              (tptr (tptr tuchar))) (tptr tuchar))
                          (Expr.Eaddrof (Expr.Evar ___a64_x27_tag tuchar)
                            (tptr tuchar)))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                (Expr.Econst_int (Integers.Int.repr 28) tint)
                                (tptr (tptr tuchar))) (tptr tuchar))
                            (Expr.Eaddrof (Expr.Evar ___a64_x28_tag tuchar)
                              (tptr tuchar)))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                  (Expr.Econst_int (Integers.Int.repr 29) tint)
                                  (tptr (tptr tuchar))) (tptr tuchar))
                              (Expr.Eaddrof (Expr.Evar ___a64_x29_tag tuchar)
                                (tptr tuchar)))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                    (Expr.Econst_int (Integers.Int.repr 30) tint)
                                    (tptr (tptr tuchar))) (tptr tuchar))
                                (Expr.Eaddrof
                                  (Expr.Evar ___a64_x30_tag tuchar)
                                  (tptr tuchar)))
                              (Stmt.Ssequence
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_raw_30
                                  (Stmt.Sassign (Expr.Evar ___a64_n tuchar)
                                    (Expr.Ebinop Binop.Oand
                                      (Expr.Etempvar _t'63 tulong)
                                      (Expr.Econst_int (Integers.Int.repr 1) tint)
                                      tulong)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_raw_31
                                  s_kprog_arm64_entry_raw_58)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_raw_60 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
        (Expr.Econst_int (Integers.Int.repr 30) tint)
        (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
      (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
    (Expr.Eaddrof (Expr.Evar ___a64_x30 (Ty.Tunion _arm64_sim_gpr noattr))
      (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
          (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr (tptr tuchar)))
        (tptr tuchar))
      (Expr.Eaddrof (Expr.Evar ___a64_x0_tag tuchar) (tptr tuchar)))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
            (Expr.Econst_int (Integers.Int.repr 1) tint)
            (tptr (tptr tuchar))) (tptr tuchar))
        (Expr.Eaddrof (Expr.Evar ___a64_x1_tag tuchar) (tptr tuchar)))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
              (Expr.Econst_int (Integers.Int.repr 2) tint)
              (tptr (tptr tuchar))) (tptr tuchar))
          (Expr.Eaddrof (Expr.Evar ___a64_x2_tag tuchar) (tptr tuchar)))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                (Expr.Econst_int (Integers.Int.repr 3) tint)
                (tptr (tptr tuchar))) (tptr tuchar))
            (Expr.Eaddrof (Expr.Evar ___a64_x3_tag tuchar) (tptr tuchar)))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                  (Expr.Econst_int (Integers.Int.repr 4) tint)
                  (tptr (tptr tuchar))) (tptr tuchar))
              (Expr.Eaddrof (Expr.Evar ___a64_x4_tag tuchar) (tptr tuchar)))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                    (Expr.Econst_int (Integers.Int.repr 5) tint)
                    (tptr (tptr tuchar))) (tptr tuchar))
                (Expr.Eaddrof (Expr.Evar ___a64_x5_tag tuchar) (tptr tuchar)))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                      (Expr.Econst_int (Integers.Int.repr 6) tint)
                      (tptr (tptr tuchar))) (tptr tuchar))
                  (Expr.Eaddrof (Expr.Evar ___a64_x6_tag tuchar)
                    (tptr tuchar)))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                        (Expr.Econst_int (Integers.Int.repr 7) tint)
                        (tptr (tptr tuchar))) (tptr tuchar))
                    (Expr.Eaddrof (Expr.Evar ___a64_x7_tag tuchar)
                      (tptr tuchar)))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                          (Expr.Econst_int (Integers.Int.repr 8) tint)
                          (tptr (tptr tuchar))) (tptr tuchar))
                      (Expr.Eaddrof (Expr.Evar ___a64_x8_tag tuchar)
                        (tptr tuchar)))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                            (Expr.Econst_int (Integers.Int.repr 9) tint)
                            (tptr (tptr tuchar))) (tptr tuchar))
                        (Expr.Eaddrof (Expr.Evar ___a64_x9_tag tuchar)
                          (tptr tuchar)))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                              (Expr.Econst_int (Integers.Int.repr 10) tint)
                              (tptr (tptr tuchar))) (tptr tuchar))
                          (Expr.Eaddrof (Expr.Evar ___a64_x10_tag tuchar)
                            (tptr tuchar)))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                (Expr.Econst_int (Integers.Int.repr 11) tint)
                                (tptr (tptr tuchar))) (tptr tuchar))
                            (Expr.Eaddrof (Expr.Evar ___a64_x11_tag tuchar)
                              (tptr tuchar)))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                  (Expr.Econst_int (Integers.Int.repr 12) tint)
                                  (tptr (tptr tuchar))) (tptr tuchar))
                              (Expr.Eaddrof (Expr.Evar ___a64_x12_tag tuchar)
                                (tptr tuchar)))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                    (Expr.Econst_int (Integers.Int.repr 13) tint)
                                    (tptr (tptr tuchar))) (tptr tuchar))
                                (Expr.Eaddrof
                                  (Expr.Evar ___a64_x13_tag tuchar)
                                  (tptr tuchar)))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                      (Expr.Econst_int (Integers.Int.repr 14) tint)
                                      (tptr (tptr tuchar))) (tptr tuchar))
                                  (Expr.Eaddrof
                                    (Expr.Evar ___a64_x14_tag tuchar)
                                    (tptr tuchar)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_raw_29
                                  s_kprog_arm64_entry_raw_59)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_raw_61 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
        (Expr.Econst_int (Integers.Int.repr 13) tint)
        (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
      (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
    (Expr.Eaddrof (Expr.Evar ___a64_x13 (Ty.Tunion _arm64_sim_gpr noattr))
      (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
          (Expr.Econst_int (Integers.Int.repr 14) tint)
          (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
        (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
      (Expr.Eaddrof (Expr.Evar ___a64_x14 (Ty.Tunion _arm64_sim_gpr noattr))
        (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
            (Expr.Econst_int (Integers.Int.repr 15) tint)
            (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
          (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
        (Expr.Eaddrof
          (Expr.Evar ___a64_x15 (Ty.Tunion _arm64_sim_gpr noattr))
          (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
              (Expr.Econst_int (Integers.Int.repr 16) tint)
              (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
            (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
          (Expr.Eaddrof
            (Expr.Evar ___a64_x16 (Ty.Tunion _arm64_sim_gpr noattr))
            (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                (Expr.Econst_int (Integers.Int.repr 17) tint)
                (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
              (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
            (Expr.Eaddrof
              (Expr.Evar ___a64_x17 (Ty.Tunion _arm64_sim_gpr noattr))
              (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                  (Expr.Econst_int (Integers.Int.repr 18) tint)
                  (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
              (Expr.Eaddrof
                (Expr.Evar ___a64_x18 (Ty.Tunion _arm64_sim_gpr noattr))
                (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                    (Expr.Econst_int (Integers.Int.repr 19) tint)
                    (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                  (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                (Expr.Eaddrof
                  (Expr.Evar ___a64_x19 (Ty.Tunion _arm64_sim_gpr noattr))
                  (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                      (Expr.Econst_int (Integers.Int.repr 20) tint)
                      (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                    (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                  (Expr.Eaddrof
                    (Expr.Evar ___a64_x20 (Ty.Tunion _arm64_sim_gpr noattr))
                    (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                        (Expr.Econst_int (Integers.Int.repr 21) tint)
                        (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                      (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                    (Expr.Eaddrof
                      (Expr.Evar ___a64_x21 (Ty.Tunion _arm64_sim_gpr noattr))
                      (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                          (Expr.Econst_int (Integers.Int.repr 22) tint)
                          (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                        (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                      (Expr.Eaddrof
                        (Expr.Evar ___a64_x22 (Ty.Tunion _arm64_sim_gpr noattr))
                        (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                            (Expr.Econst_int (Integers.Int.repr 23) tint)
                            (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                          (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                        (Expr.Eaddrof
                          (Expr.Evar ___a64_x23 (Ty.Tunion _arm64_sim_gpr noattr))
                          (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                              (Expr.Econst_int (Integers.Int.repr 24) tint)
                              (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                            (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                          (Expr.Eaddrof
                            (Expr.Evar ___a64_x24 (Ty.Tunion _arm64_sim_gpr noattr))
                            (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                (Expr.Econst_int (Integers.Int.repr 25) tint)
                                (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                              (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                            (Expr.Eaddrof
                              (Expr.Evar ___a64_x25 (Ty.Tunion _arm64_sim_gpr noattr))
                              (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                  (Expr.Econst_int (Integers.Int.repr 26) tint)
                                  (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                              (Expr.Eaddrof
                                (Expr.Evar ___a64_x26 (Ty.Tunion _arm64_sim_gpr noattr))
                                (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                    (Expr.Econst_int (Integers.Int.repr 27) tint)
                                    (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                  (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                                (Expr.Eaddrof
                                  (Expr.Evar ___a64_x27 (Ty.Tunion _arm64_sim_gpr noattr))
                                  (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                      (Expr.Econst_int (Integers.Int.repr 28) tint)
                                      (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                    (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                                  (Expr.Eaddrof
                                    (Expr.Evar ___a64_x28 (Ty.Tunion _arm64_sim_gpr noattr))
                                    (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_raw_28
                                  s_kprog_arm64_entry_raw_60)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_raw_62 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                        (Expr.Econst_int (Integers.Int.repr 29) tuint)
                        (Expr.Econst_int (Integers.Int.repr 30) tuint) tint)
      (Stmt.Sset _t'59
        (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong) tulong))
      (Stmt.Ssequence
        (Stmt.Scall (some _t'60)
          (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                               cc_default))
          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
        (Stmt.Sset _t'59 (Expr.Ecast (Expr.Etempvar _t'60 tulong) tulong))))
    (Stmt.Sassign
      (Expr.Efield (Expr.Evar ___a64_x29 (Ty.Tunion _arm64_sim_gpr noattr))
        _x tulong) (Expr.Etempvar _t'59 tulong)))
  (Stmt.Ssequence
    (Stmt.Sassign (Expr.Evar ___a64_x29_tag tuchar)
      (Expr.Econst_int (Integers.Int.repr 0) tuint))
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Econst_int (Integers.Int.repr 30) tuint)
                            (Expr.Econst_int (Integers.Int.repr 30) tuint)
                            tint)
          (Stmt.Sset _t'61
            (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong)
              tulong))
          (Stmt.Ssequence
            (Stmt.Scall (some _t'62)
              (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                   cc_default))
              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
            (Stmt.Sset _t'61
              (Expr.Ecast (Expr.Etempvar _t'62 tulong) tulong))))
        (Stmt.Sassign
          (Expr.Efield
            (Expr.Evar ___a64_x30 (Ty.Tunion _arm64_sim_gpr noattr)) _x
            tulong) (Expr.Etempvar _t'61 tulong)))
      (Stmt.Ssequence
        (Stmt.Sassign (Expr.Evar ___a64_x30_tag tuchar)
          (Expr.Econst_int (Integers.Int.repr 0) tuint))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                (Expr.Econst_int (Integers.Int.repr 0) tint)
                (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
              (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
            (Expr.Eaddrof
              (Expr.Evar ___a64_x0 (Ty.Tunion _arm64_sim_gpr noattr))
              (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                  (Expr.Econst_int (Integers.Int.repr 1) tint)
                  (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
              (Expr.Eaddrof
                (Expr.Evar ___a64_x1 (Ty.Tunion _arm64_sim_gpr noattr))
                (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                    (Expr.Econst_int (Integers.Int.repr 2) tint)
                    (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                  (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                (Expr.Eaddrof
                  (Expr.Evar ___a64_x2 (Ty.Tunion _arm64_sim_gpr noattr))
                  (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                      (Expr.Econst_int (Integers.Int.repr 3) tint)
                      (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                    (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                  (Expr.Eaddrof
                    (Expr.Evar ___a64_x3 (Ty.Tunion _arm64_sim_gpr noattr))
                    (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                        (Expr.Econst_int (Integers.Int.repr 4) tint)
                        (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                      (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                    (Expr.Eaddrof
                      (Expr.Evar ___a64_x4 (Ty.Tunion _arm64_sim_gpr noattr))
                      (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                          (Expr.Econst_int (Integers.Int.repr 5) tint)
                          (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                        (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                      (Expr.Eaddrof
                        (Expr.Evar ___a64_x5 (Ty.Tunion _arm64_sim_gpr noattr))
                        (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                            (Expr.Econst_int (Integers.Int.repr 6) tint)
                            (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                          (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                        (Expr.Eaddrof
                          (Expr.Evar ___a64_x6 (Ty.Tunion _arm64_sim_gpr noattr))
                          (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                              (Expr.Econst_int (Integers.Int.repr 7) tint)
                              (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                            (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                          (Expr.Eaddrof
                            (Expr.Evar ___a64_x7 (Ty.Tunion _arm64_sim_gpr noattr))
                            (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                (Expr.Econst_int (Integers.Int.repr 8) tint)
                                (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                              (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                            (Expr.Eaddrof
                              (Expr.Evar ___a64_x8 (Ty.Tunion _arm64_sim_gpr noattr))
                              (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                  (Expr.Econst_int (Integers.Int.repr 9) tint)
                                  (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                              (Expr.Eaddrof
                                (Expr.Evar ___a64_x9 (Ty.Tunion _arm64_sim_gpr noattr))
                                (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                    (Expr.Econst_int (Integers.Int.repr 10) tint)
                                    (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                  (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                                (Expr.Eaddrof
                                  (Expr.Evar ___a64_x10 (Ty.Tunion _arm64_sim_gpr noattr))
                                  (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                      (Expr.Econst_int (Integers.Int.repr 11) tint)
                                      (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                    (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                                  (Expr.Eaddrof
                                    (Expr.Evar ___a64_x11 (Ty.Tunion _arm64_sim_gpr noattr))
                                    (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_raw_27
                                  s_kprog_arm64_entry_raw_61)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_raw_63 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign (Expr.Evar ___a64_x20_tag tuchar)
    (Expr.Econst_int (Integers.Int.repr 0) tuint))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                          (Expr.Econst_int (Integers.Int.repr 21) tuint)
                          (Expr.Econst_int (Integers.Int.repr 30) tuint)
                          tint)
        (Stmt.Sset _t'43
          (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong)
            tulong))
        (Stmt.Ssequence
          (Stmt.Scall (some _t'44)
            (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                 cc_default))
            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
          (Stmt.Sset _t'43 (Expr.Ecast (Expr.Etempvar _t'44 tulong) tulong))))
      (Stmt.Sassign
        (Expr.Efield (Expr.Evar ___a64_x21 (Ty.Tunion _arm64_sim_gpr noattr))
          _x tulong) (Expr.Etempvar _t'43 tulong)))
    (Stmt.Ssequence
      (Stmt.Sassign (Expr.Evar ___a64_x21_tag tuchar)
        (Expr.Econst_int (Integers.Int.repr 0) tuint))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Econst_int (Integers.Int.repr 22) tuint)
                              (Expr.Econst_int (Integers.Int.repr 30) tuint)
                              tint)
            (Stmt.Sset _t'45
              (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                tulong))
            (Stmt.Ssequence
              (Stmt.Scall (some _t'46)
                (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                     tulong cc_default))
                [(Expr.Econst_int (Integers.Int.repr 6) tint)])
              (Stmt.Sset _t'45
                (Expr.Ecast (Expr.Etempvar _t'46 tulong) tulong))))
          (Stmt.Sassign
            (Expr.Efield
              (Expr.Evar ___a64_x22 (Ty.Tunion _arm64_sim_gpr noattr)) _x
              tulong) (Expr.Etempvar _t'45 tulong)))
        (Stmt.Ssequence
          (Stmt.Sassign (Expr.Evar ___a64_x22_tag tuchar)
            (Expr.Econst_int (Integers.Int.repr 0) tuint))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Econst_int (Integers.Int.repr 23) tuint)
                                  (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                  tint)
                (Stmt.Sset _t'47
                  (Expr.Ecast
                    (Expr.Econst_long (Integers.Int64.repr 0) tulong) tulong))
                (Stmt.Ssequence
                  (Stmt.Scall (some _t'48)
                    (Expr.Evar _native_lab_entry_input (Ty.Tfunction 
                                                         [tuint] tulong
                                                         cc_default))
                    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                  (Stmt.Sset _t'47
                    (Expr.Ecast (Expr.Etempvar _t'48 tulong) tulong))))
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Evar ___a64_x23 (Ty.Tunion _arm64_sim_gpr noattr)) _x
                  tulong) (Expr.Etempvar _t'47 tulong)))
            (Stmt.Ssequence
              (Stmt.Sassign (Expr.Evar ___a64_x23_tag tuchar)
                (Expr.Econst_int (Integers.Int.repr 0) tuint))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Econst_int (Integers.Int.repr 24) tuint)
                                      (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                      tint)
                    (Stmt.Sset _t'49
                      (Expr.Ecast
                        (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                        tulong))
                    (Stmt.Ssequence
                      (Stmt.Scall (some _t'50)
                        (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                             [tuint] tulong
                                                             cc_default))
                        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                      (Stmt.Sset _t'49
                        (Expr.Ecast (Expr.Etempvar _t'50 tulong) tulong))))
                  (Stmt.Sassign
                    (Expr.Efield
                      (Expr.Evar ___a64_x24 (Ty.Tunion _arm64_sim_gpr noattr))
                      _x tulong) (Expr.Etempvar _t'49 tulong)))
                (Stmt.Ssequence
                  (Stmt.Sassign (Expr.Evar ___a64_x24_tag tuchar)
                    (Expr.Econst_int (Integers.Int.repr 0) tuint))
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Econst_int (Integers.Int.repr 25) tuint)
                                          (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                          tint)
                        (Stmt.Sset _t'51
                          (Expr.Ecast
                            (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                            tulong))
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'52)
                            (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                 [tuint]
                                                                 tulong
                                                                 cc_default))
                            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                          (Stmt.Sset _t'51
                            (Expr.Ecast (Expr.Etempvar _t'52 tulong) tulong))))
                      (Stmt.Sassign
                        (Expr.Efield
                          (Expr.Evar ___a64_x25 (Ty.Tunion _arm64_sim_gpr noattr))
                          _x tulong) (Expr.Etempvar _t'51 tulong)))
                    (Stmt.Ssequence
                      (Stmt.Sassign (Expr.Evar ___a64_x25_tag tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tuint))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Econst_int (Integers.Int.repr 26) tuint)
                                              (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                              tint)
                            (Stmt.Sset _t'53
                              (Expr.Ecast
                                (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                                tulong))
                            (Stmt.Ssequence
                              (Stmt.Scall (some _t'54)
                                (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                    [tuint]
                                                                    tulong
                                                                    cc_default))
                                [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                              (Stmt.Sset _t'53
                                (Expr.Ecast (Expr.Etempvar _t'54 tulong)
                                  tulong))))
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Evar ___a64_x26 (Ty.Tunion _arm64_sim_gpr noattr))
                              _x tulong) (Expr.Etempvar _t'53 tulong)))
                        (Stmt.Ssequence
                          (Stmt.Sassign (Expr.Evar ___a64_x26_tag tuchar)
                            (Expr.Econst_int (Integers.Int.repr 0) tuint))
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                  (Expr.Econst_int (Integers.Int.repr 27) tuint)
                                                  (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                                  tint)
                                s_kprog_arm64_entry_raw_23
                                s_kprog_arm64_entry_raw_24)
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Evar ___a64_x27 (Ty.Tunion _arm64_sim_gpr noattr))
                                  _x tulong) (Expr.Etempvar _t'55 tulong)))
                            (Stmt.Ssequence
                              (Stmt.Sassign (Expr.Evar ___a64_x27_tag tuchar)
                                (Expr.Econst_int (Integers.Int.repr 0) tuint))
                              (Stmt.Ssequence
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_raw_25
                                  (Stmt.Sassign
                                    (Expr.Efield
                                      (Expr.Evar ___a64_x28 (Ty.Tunion _arm64_sim_gpr noattr))
                                      _x tulong)
                                    (Expr.Etempvar _t'57 tulong)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_raw_26
                                  s_kprog_arm64_entry_raw_62)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_raw_64 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                        (Expr.Econst_int (Integers.Int.repr 12) tuint)
                        (Expr.Econst_int (Integers.Int.repr 30) tuint) tint)
      (Stmt.Sset _t'25
        (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong) tulong))
      (Stmt.Ssequence
        (Stmt.Scall (some _t'26)
          (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                               cc_default))
          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
        (Stmt.Sset _t'25 (Expr.Ecast (Expr.Etempvar _t'26 tulong) tulong))))
    (Stmt.Sassign
      (Expr.Efield (Expr.Evar ___a64_x12 (Ty.Tunion _arm64_sim_gpr noattr))
        _x tulong) (Expr.Etempvar _t'25 tulong)))
  (Stmt.Ssequence
    (Stmt.Sassign (Expr.Evar ___a64_x12_tag tuchar)
      (Expr.Econst_int (Integers.Int.repr 0) tuint))
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Econst_int (Integers.Int.repr 13) tuint)
                            (Expr.Econst_int (Integers.Int.repr 30) tuint)
                            tint)
          (Stmt.Sset _t'27
            (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong)
              tulong))
          (Stmt.Ssequence
            (Stmt.Scall (some _t'28)
              (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                   cc_default))
              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
            (Stmt.Sset _t'27
              (Expr.Ecast (Expr.Etempvar _t'28 tulong) tulong))))
        (Stmt.Sassign
          (Expr.Efield
            (Expr.Evar ___a64_x13 (Ty.Tunion _arm64_sim_gpr noattr)) _x
            tulong) (Expr.Etempvar _t'27 tulong)))
      (Stmt.Ssequence
        (Stmt.Sassign (Expr.Evar ___a64_x13_tag tuchar)
          (Expr.Econst_int (Integers.Int.repr 0) tuint))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Econst_int (Integers.Int.repr 14) tuint)
                                (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                tint)
              (Stmt.Sset _t'29
                (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                  tulong))
              (Stmt.Ssequence
                (Stmt.Scall (some _t'30)
                  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                       tulong cc_default))
                  [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                (Stmt.Sset _t'29
                  (Expr.Ecast (Expr.Etempvar _t'30 tulong) tulong))))
            (Stmt.Sassign
              (Expr.Efield
                (Expr.Evar ___a64_x14 (Ty.Tunion _arm64_sim_gpr noattr)) _x
                tulong) (Expr.Etempvar _t'29 tulong)))
          (Stmt.Ssequence
            (Stmt.Sassign (Expr.Evar ___a64_x14_tag tuchar)
              (Expr.Econst_int (Integers.Int.repr 0) tuint))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Econst_int (Integers.Int.repr 15) tuint)
                                    (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                    tint)
                  (Stmt.Sset _t'31
                    (Expr.Ecast
                      (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                      tulong))
                  (Stmt.Ssequence
                    (Stmt.Scall (some _t'32)
                      (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                           [tuint] tulong
                                                           cc_default))
                      [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                    (Stmt.Sset _t'31
                      (Expr.Ecast (Expr.Etempvar _t'32 tulong) tulong))))
                (Stmt.Sassign
                  (Expr.Efield
                    (Expr.Evar ___a64_x15 (Ty.Tunion _arm64_sim_gpr noattr))
                    _x tulong) (Expr.Etempvar _t'31 tulong)))
              (Stmt.Ssequence
                (Stmt.Sassign (Expr.Evar ___a64_x15_tag tuchar)
                  (Expr.Econst_int (Integers.Int.repr 0) tuint))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                        (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                        tint)
                      (Stmt.Sset _t'33
                        (Expr.Ecast
                          (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                          tulong))
                      (Stmt.Ssequence
                        (Stmt.Scall (some _t'34)
                          (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                               [tuint] tulong
                                                               cc_default))
                          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                        (Stmt.Sset _t'33
                          (Expr.Ecast (Expr.Etempvar _t'34 tulong) tulong))))
                    (Stmt.Sassign
                      (Expr.Efield
                        (Expr.Evar ___a64_x16 (Ty.Tunion _arm64_sim_gpr noattr))
                        _x tulong) (Expr.Etempvar _t'33 tulong)))
                  (Stmt.Ssequence
                    (Stmt.Sassign (Expr.Evar ___a64_x16_tag tuchar)
                      (Expr.Econst_int (Integers.Int.repr 0) tuint))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Econst_int (Integers.Int.repr 17) tuint)
                                            (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                            tint)
                          (Stmt.Sset _t'35
                            (Expr.Ecast
                              (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                              tulong))
                          (Stmt.Ssequence
                            (Stmt.Scall (some _t'36)
                              (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                   [tuint]
                                                                   tulong
                                                                   cc_default))
                              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                            (Stmt.Sset _t'35
                              (Expr.Ecast (Expr.Etempvar _t'36 tulong)
                                tulong))))
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Evar ___a64_x17 (Ty.Tunion _arm64_sim_gpr noattr))
                            _x tulong) (Expr.Etempvar _t'35 tulong)))
                      (Stmt.Ssequence
                        (Stmt.Sassign (Expr.Evar ___a64_x17_tag tuchar)
                          (Expr.Econst_int (Integers.Int.repr 0) tuint))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                (Expr.Econst_int (Integers.Int.repr 18) tuint)
                                                (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                                tint)
                              (Stmt.Sset _t'37
                                (Expr.Ecast
                                  (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                                  tulong))
                              (Stmt.Ssequence
                                s_kprog_arm64_entry_raw_19
                                (Stmt.Sset _t'37
                                  (Expr.Ecast (Expr.Etempvar _t'38 tulong)
                                    tulong))))
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Evar ___a64_x18 (Ty.Tunion _arm64_sim_gpr noattr))
                                _x tulong) (Expr.Etempvar _t'37 tulong)))
                          (Stmt.Ssequence
                            (Stmt.Sassign (Expr.Evar ___a64_x18_tag tuchar)
                              (Expr.Econst_int (Integers.Int.repr 0) tuint))
                            (Stmt.Ssequence
                              (Stmt.Ssequence
                                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                    (Expr.Econst_int (Integers.Int.repr 19) tuint)
                                                    (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                                    tint)
                                  s_kprog_arm64_entry_raw_20
                                  s_kprog_arm64_entry_raw_21)
                                (Stmt.Sassign
                                  (Expr.Efield
                                    (Expr.Evar ___a64_x19 (Ty.Tunion _arm64_sim_gpr noattr))
                                    _x tulong) (Expr.Etempvar _t'39 tulong)))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Evar ___a64_x19_tag tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 0) tuint))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_raw_22
                                  s_kprog_arm64_entry_raw_63)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_raw_65 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign (Expr.Evar ___a64_x3_tag tuchar)
    (Expr.Econst_int (Integers.Int.repr 0) tuint))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                          (Expr.Econst_int (Integers.Int.repr 4) tuint)
                          (Expr.Econst_int (Integers.Int.repr 30) tuint)
                          tint)
        (Stmt.Sset _t'9
          (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong)
            tulong))
        (Stmt.Ssequence
          (Stmt.Scall (some _t'10)
            (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                 cc_default))
            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
          (Stmt.Sset _t'9 (Expr.Ecast (Expr.Etempvar _t'10 tulong) tulong))))
      (Stmt.Sassign
        (Expr.Efield (Expr.Evar ___a64_x4 (Ty.Tunion _arm64_sim_gpr noattr))
          _x tulong) (Expr.Etempvar _t'9 tulong)))
    (Stmt.Ssequence
      (Stmt.Sassign (Expr.Evar ___a64_x4_tag tuchar)
        (Expr.Econst_int (Integers.Int.repr 0) tuint))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Econst_int (Integers.Int.repr 5) tuint)
                              (Expr.Econst_int (Integers.Int.repr 30) tuint)
                              tint)
            (Stmt.Sset _t'11
              (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                tulong))
            (Stmt.Ssequence
              (Stmt.Scall (some _t'12)
                (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                     tulong cc_default))
                [(Expr.Econst_int (Integers.Int.repr 6) tint)])
              (Stmt.Sset _t'11
                (Expr.Ecast (Expr.Etempvar _t'12 tulong) tulong))))
          (Stmt.Sassign
            (Expr.Efield
              (Expr.Evar ___a64_x5 (Ty.Tunion _arm64_sim_gpr noattr)) _x
              tulong) (Expr.Etempvar _t'11 tulong)))
        (Stmt.Ssequence
          (Stmt.Sassign (Expr.Evar ___a64_x5_tag tuchar)
            (Expr.Econst_int (Integers.Int.repr 0) tuint))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Econst_int (Integers.Int.repr 6) tuint)
                                  (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                  tint)
                (Stmt.Sset _t'13
                  (Expr.Ecast
                    (Expr.Econst_long (Integers.Int64.repr 0) tulong) tulong))
                (Stmt.Ssequence
                  (Stmt.Scall (some _t'14)
                    (Expr.Evar _native_lab_entry_input (Ty.Tfunction 
                                                         [tuint] tulong
                                                         cc_default))
                    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                  (Stmt.Sset _t'13
                    (Expr.Ecast (Expr.Etempvar _t'14 tulong) tulong))))
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Evar ___a64_x6 (Ty.Tunion _arm64_sim_gpr noattr)) _x
                  tulong) (Expr.Etempvar _t'13 tulong)))
            (Stmt.Ssequence
              (Stmt.Sassign (Expr.Evar ___a64_x6_tag tuchar)
                (Expr.Econst_int (Integers.Int.repr 0) tuint))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Econst_int (Integers.Int.repr 7) tuint)
                                      (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                      tint)
                    (Stmt.Sset _t'15
                      (Expr.Ecast
                        (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                        tulong))
                    (Stmt.Ssequence
                      (Stmt.Scall (some _t'16)
                        (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                             [tuint] tulong
                                                             cc_default))
                        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                      (Stmt.Sset _t'15
                        (Expr.Ecast (Expr.Etempvar _t'16 tulong) tulong))))
                  (Stmt.Sassign
                    (Expr.Efield
                      (Expr.Evar ___a64_x7 (Ty.Tunion _arm64_sim_gpr noattr))
                      _x tulong) (Expr.Etempvar _t'15 tulong)))
                (Stmt.Ssequence
                  (Stmt.Sassign (Expr.Evar ___a64_x7_tag tuchar)
                    (Expr.Econst_int (Integers.Int.repr 0) tuint))
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                          (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                          tint)
                        (Stmt.Sset _t'17
                          (Expr.Ecast
                            (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                            tulong))
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'18)
                            (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                 [tuint]
                                                                 tulong
                                                                 cc_default))
                            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                          (Stmt.Sset _t'17
                            (Expr.Ecast (Expr.Etempvar _t'18 tulong) tulong))))
                      (Stmt.Sassign
                        (Expr.Efield
                          (Expr.Evar ___a64_x8 (Ty.Tunion _arm64_sim_gpr noattr))
                          _x tulong) (Expr.Etempvar _t'17 tulong)))
                    (Stmt.Ssequence
                      (Stmt.Sassign (Expr.Evar ___a64_x8_tag tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tuint))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Econst_int (Integers.Int.repr 9) tuint)
                                              (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                              tint)
                            (Stmt.Sset _t'19
                              (Expr.Ecast
                                (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                                tulong))
                            (Stmt.Ssequence
                              (Stmt.Scall (some _t'20)
                                (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                    [tuint]
                                                                    tulong
                                                                    cc_default))
                                [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                              (Stmt.Sset _t'19
                                (Expr.Ecast (Expr.Etempvar _t'20 tulong)
                                  tulong))))
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Evar ___a64_x9 (Ty.Tunion _arm64_sim_gpr noattr))
                              _x tulong) (Expr.Etempvar _t'19 tulong)))
                        (Stmt.Ssequence
                          (Stmt.Sassign (Expr.Evar ___a64_x9_tag tuchar)
                            (Expr.Econst_int (Integers.Int.repr 0) tuint))
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                  (Expr.Econst_int (Integers.Int.repr 10) tuint)
                                                  (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                                  tint)
                                s_kprog_arm64_entry_raw_15
                                s_kprog_arm64_entry_raw_16)
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Evar ___a64_x10 (Ty.Tunion _arm64_sim_gpr noattr))
                                  _x tulong) (Expr.Etempvar _t'21 tulong)))
                            (Stmt.Ssequence
                              (Stmt.Sassign (Expr.Evar ___a64_x10_tag tuchar)
                                (Expr.Econst_int (Integers.Int.repr 0) tuint))
                              (Stmt.Ssequence
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_raw_17
                                  (Stmt.Sassign
                                    (Expr.Efield
                                      (Expr.Evar ___a64_x11 (Ty.Tunion _arm64_sim_gpr noattr))
                                      _x tulong)
                                    (Expr.Etempvar _t'23 tulong)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_raw_18
                                  s_kprog_arm64_entry_raw_64)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_raw_66 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Efield
      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr)) _data
      (tptr tvoid))
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Evar ___a64_sim_skb_ctx (tptr (Ty.Tstruct ___sk_buff noattr)))
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
        (tptr (Ty.Tstruct ___sk_buff noattr))))
    (Stmt.Ssequence
      (Stmt.Sassign (Expr.Evar ___a64_sim_abi_kind tuchar)
        (Expr.Econst_int (Integers.Int.repr 2) tuint))
      (Stmt.Ssequence
        (Stmt.Sassign (Expr.Evar ___a64_numeric_sp tulong)
          (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Ssequence
          (Stmt.Sassign (Expr.Evar ___a64_numeric_return tulong)
            (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Ssequence
            (Stmt.Sassign (Expr.Evar ___a64_numeric_sp_valid tuchar)
              (Expr.Econst_int (Integers.Int.repr 0) tint))
            (Stmt.Ssequence
              (Stmt.Sassign (Expr.Evar ___a64_numeric_return_valid tuchar)
                (Expr.Econst_int (Integers.Int.repr 0) tint))
              (Stmt.Ssequence
                (Stmt.Sassign (Expr.Evar ___a64_sim_is_xdp tuchar)
                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Evar ___a64_sim_helper_ctx (tptr tvoid))
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                      (tptr tvoid)))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Evar ___a64_sim_helper_abi_base (tptr tvoid))
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 0) tint)
                        (tptr tvoid)))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                            (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                            tint)
                          (Stmt.Sset _t'1
                            (Expr.Ecast
                              (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                              tulong))
                          (Stmt.Ssequence
                            (Stmt.Scall (some _t'2)
                              (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                   [tuint]
                                                                   tulong
                                                                   cc_default))
                              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                            (Stmt.Sset _t'1
                              (Expr.Ecast (Expr.Etempvar _t'2 tulong) tulong))))
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Evar ___a64_x0 (Ty.Tunion _arm64_sim_gpr noattr))
                            _x tulong) (Expr.Etempvar _t'1 tulong)))
                      (Stmt.Ssequence
                        (Stmt.Sassign (Expr.Evar ___a64_x0_tag tuchar)
                          (Expr.Econst_int (Integers.Int.repr 0) tuint))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                                (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                                tint)
                              (Stmt.Sset _t'3
                                (Expr.Ecast
                                  (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                                  tulong))
                              (Stmt.Ssequence
                                s_kprog_arm64_entry_raw_11
                                (Stmt.Sset _t'3
                                  (Expr.Ecast (Expr.Etempvar _t'4 tulong)
                                    tulong))))
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Evar ___a64_x1 (Ty.Tunion _arm64_sim_gpr noattr))
                                _x tulong) (Expr.Etempvar _t'3 tulong)))
                          (Stmt.Ssequence
                            (Stmt.Sassign (Expr.Evar ___a64_x1_tag tuchar)
                              (Expr.Econst_int (Integers.Int.repr 0) tuint))
                            (Stmt.Ssequence
                              (Stmt.Ssequence
                                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                    (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                                    (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                                    tint)
                                  s_kprog_arm64_entry_raw_12
                                  s_kprog_arm64_entry_raw_13)
                                (Stmt.Sassign
                                  (Expr.Efield
                                    (Expr.Evar ___a64_x2 (Ty.Tunion _arm64_sim_gpr noattr))
                                    _x tulong) (Expr.Etempvar _t'5 tulong)))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Evar ___a64_x2_tag tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 0) tuint))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_raw_14
                                  s_kprog_arm64_entry_raw_65)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_raw_67 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Efield
          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
          _pad2 (tarray tuchar 120))
        (Expr.Econst_int (Integers.Int.repr 103) tint) (tptr tuchar)) tuchar)
    (Expr.Econst_int (Integers.Int.repr 0) tint))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Efield
            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
            _pad2 (tarray tuchar 120))
          (Expr.Econst_int (Integers.Int.repr 104) tint) (tptr tuchar))
        tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
              _pad2 (tarray tuchar 120))
            (Expr.Econst_int (Integers.Int.repr 105) tint) (tptr tuchar))
          tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                _pad2 (tarray tuchar 120))
              (Expr.Econst_int (Integers.Int.repr 106) tint) (tptr tuchar))
            tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                  _pad2 (tarray tuchar 120))
                (Expr.Econst_int (Integers.Int.repr 107) tint) (tptr tuchar))
              tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                    _pad2 (tarray tuchar 120))
                  (Expr.Econst_int (Integers.Int.repr 108) tint)
                  (tptr tuchar)) tuchar)
              (Expr.Econst_int (Integers.Int.repr 0) tint))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Efield
                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                      _pad2 (tarray tuchar 120))
                    (Expr.Econst_int (Integers.Int.repr 109) tint)
                    (tptr tuchar)) tuchar)
                (Expr.Econst_int (Integers.Int.repr 0) tint))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                        _pad2 (tarray tuchar 120))
                      (Expr.Econst_int (Integers.Int.repr 110) tint)
                      (tptr tuchar)) tuchar)
                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                          _pad2 (tarray tuchar 120))
                        (Expr.Econst_int (Integers.Int.repr 111) tint)
                        (tptr tuchar)) tuchar)
                    (Expr.Econst_int (Integers.Int.repr 0) tint))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Efield
                            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                            _pad2 (tarray tuchar 120))
                          (Expr.Econst_int (Integers.Int.repr 112) tint)
                          (tptr tuchar)) tuchar)
                      (Expr.Econst_int (Integers.Int.repr 0) tint))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                              _pad2 (tarray tuchar 120))
                            (Expr.Econst_int (Integers.Int.repr 113) tint)
                            (tptr tuchar)) tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tint))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                _pad2 (tarray tuchar 120))
                              (Expr.Econst_int (Integers.Int.repr 114) tint)
                              (tptr tuchar)) tuchar)
                          (Expr.Econst_int (Integers.Int.repr 0) tint))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                  _pad2 (tarray tuchar 120))
                                (Expr.Econst_int (Integers.Int.repr 115) tint)
                                (tptr tuchar)) tuchar)
                            (Expr.Econst_int (Integers.Int.repr 0) tint))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                    _pad2 (tarray tuchar 120))
                                  (Expr.Econst_int (Integers.Int.repr 116) tint)
                                  (tptr tuchar)) tuchar)
                              (Expr.Econst_int (Integers.Int.repr 0) tint))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                      _pad2 (tarray tuchar 120))
                                    (Expr.Econst_int (Integers.Int.repr 117) tint)
                                    (tptr tuchar)) tuchar)
                                (Expr.Econst_int (Integers.Int.repr 0) tint))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Efield
                                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                        _pad2 (tarray tuchar 120))
                                      (Expr.Econst_int (Integers.Int.repr 118) tint)
                                      (tptr tuchar)) tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_raw_10
                                  s_kprog_arm64_entry_raw_66)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_raw_68 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Efield
          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
          _pad2 (tarray tuchar 120))
        (Expr.Econst_int (Integers.Int.repr 86) tint) (tptr tuchar)) tuchar)
    (Expr.Econst_int (Integers.Int.repr 0) tint))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Efield
            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
            _pad2 (tarray tuchar 120))
          (Expr.Econst_int (Integers.Int.repr 87) tint) (tptr tuchar))
        tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
              _pad2 (tarray tuchar 120))
            (Expr.Econst_int (Integers.Int.repr 88) tint) (tptr tuchar))
          tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                _pad2 (tarray tuchar 120))
              (Expr.Econst_int (Integers.Int.repr 89) tint) (tptr tuchar))
            tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                  _pad2 (tarray tuchar 120))
                (Expr.Econst_int (Integers.Int.repr 90) tint) (tptr tuchar))
              tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                    _pad2 (tarray tuchar 120))
                  (Expr.Econst_int (Integers.Int.repr 91) tint)
                  (tptr tuchar)) tuchar)
              (Expr.Econst_int (Integers.Int.repr 0) tint))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Efield
                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                      _pad2 (tarray tuchar 120))
                    (Expr.Econst_int (Integers.Int.repr 92) tint)
                    (tptr tuchar)) tuchar)
                (Expr.Econst_int (Integers.Int.repr 0) tint))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                        _pad2 (tarray tuchar 120))
                      (Expr.Econst_int (Integers.Int.repr 93) tint)
                      (tptr tuchar)) tuchar)
                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                          _pad2 (tarray tuchar 120))
                        (Expr.Econst_int (Integers.Int.repr 94) tint)
                        (tptr tuchar)) tuchar)
                    (Expr.Econst_int (Integers.Int.repr 0) tint))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Efield
                            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                            _pad2 (tarray tuchar 120))
                          (Expr.Econst_int (Integers.Int.repr 95) tint)
                          (tptr tuchar)) tuchar)
                      (Expr.Econst_int (Integers.Int.repr 0) tint))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                              _pad2 (tarray tuchar 120))
                            (Expr.Econst_int (Integers.Int.repr 96) tint)
                            (tptr tuchar)) tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tint))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                _pad2 (tarray tuchar 120))
                              (Expr.Econst_int (Integers.Int.repr 97) tint)
                              (tptr tuchar)) tuchar)
                          (Expr.Econst_int (Integers.Int.repr 0) tint))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                  _pad2 (tarray tuchar 120))
                                (Expr.Econst_int (Integers.Int.repr 98) tint)
                                (tptr tuchar)) tuchar)
                            (Expr.Econst_int (Integers.Int.repr 0) tint))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                    _pad2 (tarray tuchar 120))
                                  (Expr.Econst_int (Integers.Int.repr 99) tint)
                                  (tptr tuchar)) tuchar)
                              (Expr.Econst_int (Integers.Int.repr 0) tint))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                      _pad2 (tarray tuchar 120))
                                    (Expr.Econst_int (Integers.Int.repr 100) tint)
                                    (tptr tuchar)) tuchar)
                                (Expr.Econst_int (Integers.Int.repr 0) tint))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Efield
                                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                        _pad2 (tarray tuchar 120))
                                      (Expr.Econst_int (Integers.Int.repr 101) tint)
                                      (tptr tuchar)) tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_raw_9
                                  s_kprog_arm64_entry_raw_67)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_raw_69 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Efield
          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
          _pad2 (tarray tuchar 120))
        (Expr.Econst_int (Integers.Int.repr 69) tint) (tptr tuchar)) tuchar)
    (Expr.Econst_int (Integers.Int.repr 0) tint))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Efield
            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
            _pad2 (tarray tuchar 120))
          (Expr.Econst_int (Integers.Int.repr 70) tint) (tptr tuchar))
        tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
              _pad2 (tarray tuchar 120))
            (Expr.Econst_int (Integers.Int.repr 71) tint) (tptr tuchar))
          tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                _pad2 (tarray tuchar 120))
              (Expr.Econst_int (Integers.Int.repr 72) tint) (tptr tuchar))
            tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                  _pad2 (tarray tuchar 120))
                (Expr.Econst_int (Integers.Int.repr 73) tint) (tptr tuchar))
              tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                    _pad2 (tarray tuchar 120))
                  (Expr.Econst_int (Integers.Int.repr 74) tint)
                  (tptr tuchar)) tuchar)
              (Expr.Econst_int (Integers.Int.repr 0) tint))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Efield
                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                      _pad2 (tarray tuchar 120))
                    (Expr.Econst_int (Integers.Int.repr 75) tint)
                    (tptr tuchar)) tuchar)
                (Expr.Econst_int (Integers.Int.repr 0) tint))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                        _pad2 (tarray tuchar 120))
                      (Expr.Econst_int (Integers.Int.repr 76) tint)
                      (tptr tuchar)) tuchar)
                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                          _pad2 (tarray tuchar 120))
                        (Expr.Econst_int (Integers.Int.repr 77) tint)
                        (tptr tuchar)) tuchar)
                    (Expr.Econst_int (Integers.Int.repr 0) tint))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Efield
                            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                            _pad2 (tarray tuchar 120))
                          (Expr.Econst_int (Integers.Int.repr 78) tint)
                          (tptr tuchar)) tuchar)
                      (Expr.Econst_int (Integers.Int.repr 0) tint))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                              _pad2 (tarray tuchar 120))
                            (Expr.Econst_int (Integers.Int.repr 79) tint)
                            (tptr tuchar)) tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tint))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                _pad2 (tarray tuchar 120))
                              (Expr.Econst_int (Integers.Int.repr 80) tint)
                              (tptr tuchar)) tuchar)
                          (Expr.Econst_int (Integers.Int.repr 0) tint))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                  _pad2 (tarray tuchar 120))
                                (Expr.Econst_int (Integers.Int.repr 81) tint)
                                (tptr tuchar)) tuchar)
                            (Expr.Econst_int (Integers.Int.repr 0) tint))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                    _pad2 (tarray tuchar 120))
                                  (Expr.Econst_int (Integers.Int.repr 82) tint)
                                  (tptr tuchar)) tuchar)
                              (Expr.Econst_int (Integers.Int.repr 0) tint))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                      _pad2 (tarray tuchar 120))
                                    (Expr.Econst_int (Integers.Int.repr 83) tint)
                                    (tptr tuchar)) tuchar)
                                (Expr.Econst_int (Integers.Int.repr 0) tint))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Efield
                                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                        _pad2 (tarray tuchar 120))
                                      (Expr.Econst_int (Integers.Int.repr 84) tint)
                                      (tptr tuchar)) tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_raw_8
                                  s_kprog_arm64_entry_raw_68)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_raw_70 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Efield
          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
          _pad2 (tarray tuchar 120))
        (Expr.Econst_int (Integers.Int.repr 52) tint) (tptr tuchar)) tuchar)
    (Expr.Econst_int (Integers.Int.repr 0) tint))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Efield
            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
            _pad2 (tarray tuchar 120))
          (Expr.Econst_int (Integers.Int.repr 53) tint) (tptr tuchar))
        tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
              _pad2 (tarray tuchar 120))
            (Expr.Econst_int (Integers.Int.repr 54) tint) (tptr tuchar))
          tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                _pad2 (tarray tuchar 120))
              (Expr.Econst_int (Integers.Int.repr 55) tint) (tptr tuchar))
            tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                  _pad2 (tarray tuchar 120))
                (Expr.Econst_int (Integers.Int.repr 56) tint) (tptr tuchar))
              tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                    _pad2 (tarray tuchar 120))
                  (Expr.Econst_int (Integers.Int.repr 57) tint)
                  (tptr tuchar)) tuchar)
              (Expr.Econst_int (Integers.Int.repr 0) tint))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Efield
                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                      _pad2 (tarray tuchar 120))
                    (Expr.Econst_int (Integers.Int.repr 58) tint)
                    (tptr tuchar)) tuchar)
                (Expr.Econst_int (Integers.Int.repr 0) tint))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                        _pad2 (tarray tuchar 120))
                      (Expr.Econst_int (Integers.Int.repr 59) tint)
                      (tptr tuchar)) tuchar)
                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                          _pad2 (tarray tuchar 120))
                        (Expr.Econst_int (Integers.Int.repr 60) tint)
                        (tptr tuchar)) tuchar)
                    (Expr.Econst_int (Integers.Int.repr 0) tint))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Efield
                            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                            _pad2 (tarray tuchar 120))
                          (Expr.Econst_int (Integers.Int.repr 61) tint)
                          (tptr tuchar)) tuchar)
                      (Expr.Econst_int (Integers.Int.repr 0) tint))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                              _pad2 (tarray tuchar 120))
                            (Expr.Econst_int (Integers.Int.repr 62) tint)
                            (tptr tuchar)) tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tint))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                _pad2 (tarray tuchar 120))
                              (Expr.Econst_int (Integers.Int.repr 63) tint)
                              (tptr tuchar)) tuchar)
                          (Expr.Econst_int (Integers.Int.repr 0) tint))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                  _pad2 (tarray tuchar 120))
                                (Expr.Econst_int (Integers.Int.repr 64) tint)
                                (tptr tuchar)) tuchar)
                            (Expr.Econst_int (Integers.Int.repr 0) tint))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                    _pad2 (tarray tuchar 120))
                                  (Expr.Econst_int (Integers.Int.repr 65) tint)
                                  (tptr tuchar)) tuchar)
                              (Expr.Econst_int (Integers.Int.repr 0) tint))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                      _pad2 (tarray tuchar 120))
                                    (Expr.Econst_int (Integers.Int.repr 66) tint)
                                    (tptr tuchar)) tuchar)
                                (Expr.Econst_int (Integers.Int.repr 0) tint))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Efield
                                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                        _pad2 (tarray tuchar 120))
                                      (Expr.Econst_int (Integers.Int.repr 67) tint)
                                      (tptr tuchar)) tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_raw_7
                                  s_kprog_arm64_entry_raw_69)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_raw_71 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Efield
          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
          _pad2 (tarray tuchar 120))
        (Expr.Econst_int (Integers.Int.repr 35) tint) (tptr tuchar)) tuchar)
    (Expr.Econst_int (Integers.Int.repr 0) tint))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Efield
            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
            _pad2 (tarray tuchar 120))
          (Expr.Econst_int (Integers.Int.repr 36) tint) (tptr tuchar))
        tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
              _pad2 (tarray tuchar 120))
            (Expr.Econst_int (Integers.Int.repr 37) tint) (tptr tuchar))
          tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                _pad2 (tarray tuchar 120))
              (Expr.Econst_int (Integers.Int.repr 38) tint) (tptr tuchar))
            tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                  _pad2 (tarray tuchar 120))
                (Expr.Econst_int (Integers.Int.repr 39) tint) (tptr tuchar))
              tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                    _pad2 (tarray tuchar 120))
                  (Expr.Econst_int (Integers.Int.repr 40) tint)
                  (tptr tuchar)) tuchar)
              (Expr.Econst_int (Integers.Int.repr 0) tint))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Efield
                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                      _pad2 (tarray tuchar 120))
                    (Expr.Econst_int (Integers.Int.repr 41) tint)
                    (tptr tuchar)) tuchar)
                (Expr.Econst_int (Integers.Int.repr 0) tint))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                        _pad2 (tarray tuchar 120))
                      (Expr.Econst_int (Integers.Int.repr 42) tint)
                      (tptr tuchar)) tuchar)
                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                          _pad2 (tarray tuchar 120))
                        (Expr.Econst_int (Integers.Int.repr 43) tint)
                        (tptr tuchar)) tuchar)
                    (Expr.Econst_int (Integers.Int.repr 0) tint))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Efield
                            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                            _pad2 (tarray tuchar 120))
                          (Expr.Econst_int (Integers.Int.repr 44) tint)
                          (tptr tuchar)) tuchar)
                      (Expr.Econst_int (Integers.Int.repr 0) tint))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                              _pad2 (tarray tuchar 120))
                            (Expr.Econst_int (Integers.Int.repr 45) tint)
                            (tptr tuchar)) tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tint))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                _pad2 (tarray tuchar 120))
                              (Expr.Econst_int (Integers.Int.repr 46) tint)
                              (tptr tuchar)) tuchar)
                          (Expr.Econst_int (Integers.Int.repr 0) tint))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                  _pad2 (tarray tuchar 120))
                                (Expr.Econst_int (Integers.Int.repr 47) tint)
                                (tptr tuchar)) tuchar)
                            (Expr.Econst_int (Integers.Int.repr 0) tint))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                    _pad2 (tarray tuchar 120))
                                  (Expr.Econst_int (Integers.Int.repr 48) tint)
                                  (tptr tuchar)) tuchar)
                              (Expr.Econst_int (Integers.Int.repr 0) tint))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                      _pad2 (tarray tuchar 120))
                                    (Expr.Econst_int (Integers.Int.repr 49) tint)
                                    (tptr tuchar)) tuchar)
                                (Expr.Econst_int (Integers.Int.repr 0) tint))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Efield
                                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                        _pad2 (tarray tuchar 120))
                                      (Expr.Econst_int (Integers.Int.repr 50) tint)
                                      (tptr tuchar)) tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_raw_6
                                  s_kprog_arm64_entry_raw_70)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_raw_72 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Efield
          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
          _pad2 (tarray tuchar 120))
        (Expr.Econst_int (Integers.Int.repr 18) tint) (tptr tuchar)) tuchar)
    (Expr.Econst_int (Integers.Int.repr 0) tint))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Efield
            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
            _pad2 (tarray tuchar 120))
          (Expr.Econst_int (Integers.Int.repr 19) tint) (tptr tuchar))
        tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
              _pad2 (tarray tuchar 120))
            (Expr.Econst_int (Integers.Int.repr 20) tint) (tptr tuchar))
          tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                _pad2 (tarray tuchar 120))
              (Expr.Econst_int (Integers.Int.repr 21) tint) (tptr tuchar))
            tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                  _pad2 (tarray tuchar 120))
                (Expr.Econst_int (Integers.Int.repr 22) tint) (tptr tuchar))
              tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                    _pad2 (tarray tuchar 120))
                  (Expr.Econst_int (Integers.Int.repr 23) tint)
                  (tptr tuchar)) tuchar)
              (Expr.Econst_int (Integers.Int.repr 0) tint))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Efield
                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                      _pad2 (tarray tuchar 120))
                    (Expr.Econst_int (Integers.Int.repr 24) tint)
                    (tptr tuchar)) tuchar)
                (Expr.Econst_int (Integers.Int.repr 0) tint))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                        _pad2 (tarray tuchar 120))
                      (Expr.Econst_int (Integers.Int.repr 25) tint)
                      (tptr tuchar)) tuchar)
                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                          _pad2 (tarray tuchar 120))
                        (Expr.Econst_int (Integers.Int.repr 26) tint)
                        (tptr tuchar)) tuchar)
                    (Expr.Econst_int (Integers.Int.repr 0) tint))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Efield
                            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                            _pad2 (tarray tuchar 120))
                          (Expr.Econst_int (Integers.Int.repr 27) tint)
                          (tptr tuchar)) tuchar)
                      (Expr.Econst_int (Integers.Int.repr 0) tint))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                              _pad2 (tarray tuchar 120))
                            (Expr.Econst_int (Integers.Int.repr 28) tint)
                            (tptr tuchar)) tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tint))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                _pad2 (tarray tuchar 120))
                              (Expr.Econst_int (Integers.Int.repr 29) tint)
                              (tptr tuchar)) tuchar)
                          (Expr.Econst_int (Integers.Int.repr 0) tint))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                  _pad2 (tarray tuchar 120))
                                (Expr.Econst_int (Integers.Int.repr 30) tint)
                                (tptr tuchar)) tuchar)
                            (Expr.Econst_int (Integers.Int.repr 0) tint))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                    _pad2 (tarray tuchar 120))
                                  (Expr.Econst_int (Integers.Int.repr 31) tint)
                                  (tptr tuchar)) tuchar)
                              (Expr.Econst_int (Integers.Int.repr 0) tint))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                      _pad2 (tarray tuchar 120))
                                    (Expr.Econst_int (Integers.Int.repr 32) tint)
                                    (tptr tuchar)) tuchar)
                                (Expr.Econst_int (Integers.Int.repr 0) tint))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Efield
                                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                        _pad2 (tarray tuchar 120))
                                      (Expr.Econst_int (Integers.Int.repr 33) tint)
                                      (tptr tuchar)) tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_raw_5
                                  s_kprog_arm64_entry_raw_71)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_raw_73 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Efield
          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
          _pad2 (tarray tuchar 120))
        (Expr.Econst_int (Integers.Int.repr 1) tint) (tptr tuchar)) tuchar)
    (Expr.Econst_int (Integers.Int.repr 0) tint))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Efield
            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
            _pad2 (tarray tuchar 120))
          (Expr.Econst_int (Integers.Int.repr 2) tint) (tptr tuchar)) tuchar)
      (Expr.Econst_int (Integers.Int.repr 0) tint))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
              _pad2 (tarray tuchar 120))
            (Expr.Econst_int (Integers.Int.repr 3) tint) (tptr tuchar))
          tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                _pad2 (tarray tuchar 120))
              (Expr.Econst_int (Integers.Int.repr 4) tint) (tptr tuchar))
            tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                  _pad2 (tarray tuchar 120))
                (Expr.Econst_int (Integers.Int.repr 5) tint) (tptr tuchar))
              tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                    _pad2 (tarray tuchar 120))
                  (Expr.Econst_int (Integers.Int.repr 6) tint) (tptr tuchar))
                tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Efield
                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                      _pad2 (tarray tuchar 120))
                    (Expr.Econst_int (Integers.Int.repr 7) tint)
                    (tptr tuchar)) tuchar)
                (Expr.Econst_int (Integers.Int.repr 0) tint))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                        _pad2 (tarray tuchar 120))
                      (Expr.Econst_int (Integers.Int.repr 8) tint)
                      (tptr tuchar)) tuchar)
                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                          _pad2 (tarray tuchar 120))
                        (Expr.Econst_int (Integers.Int.repr 9) tint)
                        (tptr tuchar)) tuchar)
                    (Expr.Econst_int (Integers.Int.repr 0) tint))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Efield
                            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                            _pad2 (tarray tuchar 120))
                          (Expr.Econst_int (Integers.Int.repr 10) tint)
                          (tptr tuchar)) tuchar)
                      (Expr.Econst_int (Integers.Int.repr 0) tint))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                              _pad2 (tarray tuchar 120))
                            (Expr.Econst_int (Integers.Int.repr 11) tint)
                            (tptr tuchar)) tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tint))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                _pad2 (tarray tuchar 120))
                              (Expr.Econst_int (Integers.Int.repr 12) tint)
                              (tptr tuchar)) tuchar)
                          (Expr.Econst_int (Integers.Int.repr 0) tint))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                  _pad2 (tarray tuchar 120))
                                (Expr.Econst_int (Integers.Int.repr 13) tint)
                                (tptr tuchar)) tuchar)
                            (Expr.Econst_int (Integers.Int.repr 0) tint))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                    _pad2 (tarray tuchar 120))
                                  (Expr.Econst_int (Integers.Int.repr 14) tint)
                                  (tptr tuchar)) tuchar)
                              (Expr.Econst_int (Integers.Int.repr 0) tint))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                      _pad2 (tarray tuchar 120))
                                    (Expr.Econst_int (Integers.Int.repr 15) tint)
                                    (tptr tuchar)) tuchar)
                                (Expr.Econst_int (Integers.Int.repr 0) tint))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Efield
                                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                        _pad2 (tarray tuchar 120))
                                      (Expr.Econst_int (Integers.Int.repr 16) tint)
                                      (tptr tuchar)) tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_raw_4
                                  s_kprog_arm64_entry_raw_72)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_raw_74 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Efield
          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
          _cb (tarray tuint 5)) (Expr.Econst_int (Integers.Int.repr 2) tint)
        (tptr tuint)) tuint) (Expr.Econst_int (Integers.Int.repr 0) tint))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Efield
            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
            _cb (tarray tuint 5))
          (Expr.Econst_int (Integers.Int.repr 3) tint) (tptr tuint)) tuint)
      (Expr.Econst_int (Integers.Int.repr 0) tint))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
              _cb (tarray tuint 5))
            (Expr.Econst_int (Integers.Int.repr 4) tint) (tptr tuint)) tuint)
        (Expr.Econst_int (Integers.Int.repr 0) tint))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                _pad1 (tarray tuchar 12))
              (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tuchar))
            tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                  _pad1 (tarray tuchar 12))
                (Expr.Econst_int (Integers.Int.repr 1) tint) (tptr tuchar))
              tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                    _pad1 (tarray tuchar 12))
                  (Expr.Econst_int (Integers.Int.repr 2) tint) (tptr tuchar))
                tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Efield
                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                      _pad1 (tarray tuchar 12))
                    (Expr.Econst_int (Integers.Int.repr 3) tint)
                    (tptr tuchar)) tuchar)
                (Expr.Econst_int (Integers.Int.repr 0) tint))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                        _pad1 (tarray tuchar 12))
                      (Expr.Econst_int (Integers.Int.repr 4) tint)
                      (tptr tuchar)) tuchar)
                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                          _pad1 (tarray tuchar 12))
                        (Expr.Econst_int (Integers.Int.repr 5) tint)
                        (tptr tuchar)) tuchar)
                    (Expr.Econst_int (Integers.Int.repr 0) tint))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Efield
                            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                            _pad1 (tarray tuchar 12))
                          (Expr.Econst_int (Integers.Int.repr 6) tint)
                          (tptr tuchar)) tuchar)
                      (Expr.Econst_int (Integers.Int.repr 0) tint))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                              _pad1 (tarray tuchar 12))
                            (Expr.Econst_int (Integers.Int.repr 7) tint)
                            (tptr tuchar)) tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tint))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                _pad1 (tarray tuchar 12))
                              (Expr.Econst_int (Integers.Int.repr 8) tint)
                              (tptr tuchar)) tuchar)
                          (Expr.Econst_int (Integers.Int.repr 0) tint))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                  _pad1 (tarray tuchar 12))
                                (Expr.Econst_int (Integers.Int.repr 9) tint)
                                (tptr tuchar)) tuchar)
                            (Expr.Econst_int (Integers.Int.repr 0) tint))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                    _pad1 (tarray tuchar 12))
                                  (Expr.Econst_int (Integers.Int.repr 10) tint)
                                  (tptr tuchar)) tuchar)
                              (Expr.Econst_int (Integers.Int.repr 0) tint))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                      _pad1 (tarray tuchar 12))
                                    (Expr.Econst_int (Integers.Int.repr 11) tint)
                                    (tptr tuchar)) tuchar)
                                (Expr.Econst_int (Integers.Int.repr 0) tint))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Efield
                                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                    _data_end (tptr tvoid))
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 0) tint)
                                    (tptr tvoid)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_raw_3
                                  s_kprog_arm64_entry_raw_73)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_raw_75 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Efield
          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
          _pad0 (tarray tuchar 48))
        (Expr.Econst_int (Integers.Int.repr 33) tint) (tptr tuchar)) tuchar)
    (Expr.Econst_int (Integers.Int.repr 0) tint))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Efield
            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
            _pad0 (tarray tuchar 48))
          (Expr.Econst_int (Integers.Int.repr 34) tint) (tptr tuchar))
        tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
              _pad0 (tarray tuchar 48))
            (Expr.Econst_int (Integers.Int.repr 35) tint) (tptr tuchar))
          tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                _pad0 (tarray tuchar 48))
              (Expr.Econst_int (Integers.Int.repr 36) tint) (tptr tuchar))
            tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                  _pad0 (tarray tuchar 48))
                (Expr.Econst_int (Integers.Int.repr 37) tint) (tptr tuchar))
              tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                    _pad0 (tarray tuchar 48))
                  (Expr.Econst_int (Integers.Int.repr 38) tint)
                  (tptr tuchar)) tuchar)
              (Expr.Econst_int (Integers.Int.repr 0) tint))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Efield
                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                      _pad0 (tarray tuchar 48))
                    (Expr.Econst_int (Integers.Int.repr 39) tint)
                    (tptr tuchar)) tuchar)
                (Expr.Econst_int (Integers.Int.repr 0) tint))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                        _pad0 (tarray tuchar 48))
                      (Expr.Econst_int (Integers.Int.repr 40) tint)
                      (tptr tuchar)) tuchar)
                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                          _pad0 (tarray tuchar 48))
                        (Expr.Econst_int (Integers.Int.repr 41) tint)
                        (tptr tuchar)) tuchar)
                    (Expr.Econst_int (Integers.Int.repr 0) tint))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Efield
                            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                            _pad0 (tarray tuchar 48))
                          (Expr.Econst_int (Integers.Int.repr 42) tint)
                          (tptr tuchar)) tuchar)
                      (Expr.Econst_int (Integers.Int.repr 0) tint))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                              _pad0 (tarray tuchar 48))
                            (Expr.Econst_int (Integers.Int.repr 43) tint)
                            (tptr tuchar)) tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tint))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                _pad0 (tarray tuchar 48))
                              (Expr.Econst_int (Integers.Int.repr 44) tint)
                              (tptr tuchar)) tuchar)
                          (Expr.Econst_int (Integers.Int.repr 0) tint))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                  _pad0 (tarray tuchar 48))
                                (Expr.Econst_int (Integers.Int.repr 45) tint)
                                (tptr tuchar)) tuchar)
                            (Expr.Econst_int (Integers.Int.repr 0) tint))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                    _pad0 (tarray tuchar 48))
                                  (Expr.Econst_int (Integers.Int.repr 46) tint)
                                  (tptr tuchar)) tuchar)
                              (Expr.Econst_int (Integers.Int.repr 0) tint))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                      _pad0 (tarray tuchar 48))
                                    (Expr.Econst_int (Integers.Int.repr 47) tint)
                                    (tptr tuchar)) tuchar)
                                (Expr.Econst_int (Integers.Int.repr 0) tint))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Efield
                                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                        _cb (tarray tuint 5))
                                      (Expr.Econst_int (Integers.Int.repr 0) tint)
                                      (tptr tuint)) tuint)
                                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_raw_2
                                  s_kprog_arm64_entry_raw_74)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_raw_76 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Efield
          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
          _pad0 (tarray tuchar 48))
        (Expr.Econst_int (Integers.Int.repr 16) tint) (tptr tuchar)) tuchar)
    (Expr.Econst_int (Integers.Int.repr 0) tint))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Efield
            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
            _pad0 (tarray tuchar 48))
          (Expr.Econst_int (Integers.Int.repr 17) tint) (tptr tuchar))
        tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
              _pad0 (tarray tuchar 48))
            (Expr.Econst_int (Integers.Int.repr 18) tint) (tptr tuchar))
          tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                _pad0 (tarray tuchar 48))
              (Expr.Econst_int (Integers.Int.repr 19) tint) (tptr tuchar))
            tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                  _pad0 (tarray tuchar 48))
                (Expr.Econst_int (Integers.Int.repr 20) tint) (tptr tuchar))
              tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                    _pad0 (tarray tuchar 48))
                  (Expr.Econst_int (Integers.Int.repr 21) tint)
                  (tptr tuchar)) tuchar)
              (Expr.Econst_int (Integers.Int.repr 0) tint))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Efield
                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                      _pad0 (tarray tuchar 48))
                    (Expr.Econst_int (Integers.Int.repr 22) tint)
                    (tptr tuchar)) tuchar)
                (Expr.Econst_int (Integers.Int.repr 0) tint))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                        _pad0 (tarray tuchar 48))
                      (Expr.Econst_int (Integers.Int.repr 23) tint)
                      (tptr tuchar)) tuchar)
                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                          _pad0 (tarray tuchar 48))
                        (Expr.Econst_int (Integers.Int.repr 24) tint)
                        (tptr tuchar)) tuchar)
                    (Expr.Econst_int (Integers.Int.repr 0) tint))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Efield
                            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                            _pad0 (tarray tuchar 48))
                          (Expr.Econst_int (Integers.Int.repr 25) tint)
                          (tptr tuchar)) tuchar)
                      (Expr.Econst_int (Integers.Int.repr 0) tint))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                              _pad0 (tarray tuchar 48))
                            (Expr.Econst_int (Integers.Int.repr 26) tint)
                            (tptr tuchar)) tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tint))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                _pad0 (tarray tuchar 48))
                              (Expr.Econst_int (Integers.Int.repr 27) tint)
                              (tptr tuchar)) tuchar)
                          (Expr.Econst_int (Integers.Int.repr 0) tint))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                  _pad0 (tarray tuchar 48))
                                (Expr.Econst_int (Integers.Int.repr 28) tint)
                                (tptr tuchar)) tuchar)
                            (Expr.Econst_int (Integers.Int.repr 0) tint))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                    _pad0 (tarray tuchar 48))
                                  (Expr.Econst_int (Integers.Int.repr 29) tint)
                                  (tptr tuchar)) tuchar)
                              (Expr.Econst_int (Integers.Int.repr 0) tint))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                      _pad0 (tarray tuchar 48))
                                    (Expr.Econst_int (Integers.Int.repr 30) tint)
                                    (tptr tuchar)) tuchar)
                                (Expr.Econst_int (Integers.Int.repr 0) tint))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Efield
                                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                        _pad0 (tarray tuchar 48))
                                      (Expr.Econst_int (Integers.Int.repr 31) tint)
                                      (tptr tuchar)) tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_raw_1
                                  s_kprog_arm64_entry_raw_75)))))))))))))))))

@[noinline] def l_kprog_arm64_entry_raw_temps_0 : List (Ident × Ty) :=
[(_i, tuint), (_t'131, tuint), (_t'130, tulong), (_t'129, tulong),
 (_t'128, tulong), (_t'127, tulong), (_t'126, tulong), (_t'125, tulong),
 (_t'124, tulong), (_t'123, tulong), (_t'122, tulong), (_t'121, tulong),
 (_t'120, tulong), (_t'119, tulong), (_t'118, tulong), (_t'117, tulong),
 (_t'116, tulong), (_t'115, tulong), (_t'114, tulong), (_t'113, tulong),
 (_t'112, tulong), (_t'111, tulong), (_t'110, tulong), (_t'109, tulong),
 (_t'108, tulong), (_t'107, tulong), (_t'106, tulong), (_t'105, tulong),
 (_t'104, tulong), (_t'103, tulong), (_t'102, tulong), (_t'101, tulong),
 (_t'100, tulong), (_t'99, tulong), (_t'98, tulong), (_t'97, tulong),
 (_t'96, tulong), (_t'95, tulong), (_t'94, tulong), (_t'93, tulong),
 (_t'92, tulong), (_t'91, tulong), (_t'90, tulong), (_t'89, tulong),
 (_t'88, tulong), (_t'87, tulong), (_t'86, tulong), (_t'85, tulong),
 (_t'84, tulong), (_t'83, tulong), (_t'82, tulong), (_t'81, tulong),
 (_t'80, tulong), (_t'79, tulong), (_t'78, tulong), (_t'77, tulong),
 (_t'76, tulong), (_t'75, tulong), (_t'74, tulong), (_t'73, tulong),
 (_t'72, tulong), (_t'71, tulong), (_t'70, tulong), (_t'69, tulong),
 (_t'68, tulong), (_t'67, tulong)]

@[noinline] def l_kprog_arm64_entry_raw_temps_1 : List (Ident × Ty) :=
[(_t'66, tulong), (_t'65, tulong), (_t'64, tulong), (_t'63, tulong),
 (_t'62, tulong), (_t'61, tulong), (_t'60, tulong), (_t'59, tulong),
 (_t'58, tulong), (_t'57, tulong), (_t'56, tulong), (_t'55, tulong),
 (_t'54, tulong), (_t'53, tulong), (_t'52, tulong), (_t'51, tulong),
 (_t'50, tulong), (_t'49, tulong), (_t'48, tulong), (_t'47, tulong),
 (_t'46, tulong), (_t'45, tulong), (_t'44, tulong), (_t'43, tulong),
 (_t'42, tulong), (_t'41, tulong), (_t'40, tulong), (_t'39, tulong),
 (_t'38, tulong), (_t'37, tulong), (_t'36, tulong), (_t'35, tulong),
 (_t'34, tulong), (_t'33, tulong), (_t'32, tulong), (_t'31, tulong),
 (_t'30, tulong), (_t'29, tulong), (_t'28, tulong), (_t'27, tulong),
 (_t'26, tulong), (_t'25, tulong), (_t'24, tulong), (_t'23, tulong),
 (_t'22, tulong), (_t'21, tulong), (_t'20, tulong), (_t'19, tulong),
 (_t'18, tulong), (_t'17, tulong), (_t'16, tulong), (_t'15, tulong),
 (_t'14, tulong), (_t'13, tulong), (_t'12, tulong), (_t'11, tulong),
 (_t'10, tulong), (_t'9, tulong), (_t'8, tulong), (_t'7, tulong),
 (_t'6, tulong), (_t'5, tulong), (_t'4, tulong), (_t'3, tulong),
 (_t'2, tulong), (_t'1, tulong)]

def f_kprog_arm64_entry_raw : Function := {
  fn_return := tuint,
  fn_callconv := cc_default,
  fn_params := [(_ctx, (tptr tvoid)),
                (_continuation,
                 (tptr (Ty.Tfunction
                         [(tptr (Ty.Tstruct _kprog_arm64_entry noattr))]
                         tuint cc_default)))],
  fn_vars := [(___a64_sim_abi, (Ty.Tstruct _arm64_sim_skb_abi noattr)),
              (___a64_sim_skb_ctx, (tptr (Ty.Tstruct ___sk_buff noattr))),
              (___a64_sim_abi_kind, tuchar), (___a64_numeric_sp, tulong),
              (___a64_numeric_return, tulong),
              (___a64_numeric_sp_valid, tuchar),
              (___a64_numeric_return_valid, tuchar),
              (___a64_sim_is_xdp, tuchar),
              (___a64_sim_helper_ctx, (tptr tvoid)),
              (___a64_sim_helper_abi_base, (tptr tvoid)),
              (___a64_x0, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x0_tag, tuchar),
              (___a64_x1, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x1_tag, tuchar),
              (___a64_x2, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x2_tag, tuchar),
              (___a64_x3, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x3_tag, tuchar),
              (___a64_x4, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x4_tag, tuchar),
              (___a64_x5, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x5_tag, tuchar),
              (___a64_x6, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x6_tag, tuchar),
              (___a64_x7, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x7_tag, tuchar),
              (___a64_x8, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x8_tag, tuchar),
              (___a64_x9, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x9_tag, tuchar),
              (___a64_x10, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x10_tag, tuchar),
              (___a64_x11, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x11_tag, tuchar),
              (___a64_x12, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x12_tag, tuchar),
              (___a64_x13, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x13_tag, tuchar),
              (___a64_x14, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x14_tag, tuchar),
              (___a64_x15, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x15_tag, tuchar),
              (___a64_x16, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x16_tag, tuchar),
              (___a64_x17, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x17_tag, tuchar),
              (___a64_x18, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x18_tag, tuchar),
              (___a64_x19, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x19_tag, tuchar),
              (___a64_x20, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x20_tag, tuchar),
              (___a64_x21, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x21_tag, tuchar),
              (___a64_x22, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x22_tag, tuchar),
              (___a64_x23, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x23_tag, tuchar),
              (___a64_x24, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x24_tag, tuchar),
              (___a64_x25, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x25_tag, tuchar),
              (___a64_x26, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x26_tag, tuchar),
              (___a64_x27, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x27_tag, tuchar),
              (___a64_x28, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x28_tag, tuchar),
              (___a64_x29, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x29_tag, tuchar),
              (___a64_x30, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x30_tag, tuchar),
              (___a64_cells,
               (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31)),
              (___a64_tag_cells, (tarray (tptr tuchar) 31)),
              (___a64_n, tuchar), (___a64_z, tuchar), (___a64_c, tuchar),
              (___a64_v, tuchar), (___a64_lr, tulong),
              (___a64_vectors, (tarray (Ty.Tstruct __2854 noattr) 32)),
              (___a64_stack, (tvolatile (Ty.Tunion __2856 noattr))),
              (___a64_stack_payload, (tarray (tvolatile tulong) 20)),
              (___a64_stack_tag, (tarray tuchar 24)), (___a64_sp, tlong),
              (_entry, (Ty.Tstruct _kprog_arm64_entry noattr))],
  fn_temps := (l_kprog_arm64_entry_raw_temps_0 ++ l_kprog_arm64_entry_raw_temps_1),
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Efield
          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
          _pad0 (tarray tuchar 48))
        (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tuchar)) tuchar)
    (Expr.Econst_int (Integers.Int.repr 0) tint))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Efield
            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
            _pad0 (tarray tuchar 48))
          (Expr.Econst_int (Integers.Int.repr 1) tint) (tptr tuchar)) tuchar)
      (Expr.Econst_int (Integers.Int.repr 0) tint))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
              _pad0 (tarray tuchar 48))
            (Expr.Econst_int (Integers.Int.repr 2) tint) (tptr tuchar))
          tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                _pad0 (tarray tuchar 48))
              (Expr.Econst_int (Integers.Int.repr 3) tint) (tptr tuchar))
            tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                  _pad0 (tarray tuchar 48))
                (Expr.Econst_int (Integers.Int.repr 4) tint) (tptr tuchar))
              tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                    _pad0 (tarray tuchar 48))
                  (Expr.Econst_int (Integers.Int.repr 5) tint) (tptr tuchar))
                tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Efield
                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                      _pad0 (tarray tuchar 48))
                    (Expr.Econst_int (Integers.Int.repr 6) tint)
                    (tptr tuchar)) tuchar)
                (Expr.Econst_int (Integers.Int.repr 0) tint))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                        _pad0 (tarray tuchar 48))
                      (Expr.Econst_int (Integers.Int.repr 7) tint)
                      (tptr tuchar)) tuchar)
                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                          _pad0 (tarray tuchar 48))
                        (Expr.Econst_int (Integers.Int.repr 8) tint)
                        (tptr tuchar)) tuchar)
                    (Expr.Econst_int (Integers.Int.repr 0) tint))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Efield
                            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                            _pad0 (tarray tuchar 48))
                          (Expr.Econst_int (Integers.Int.repr 9) tint)
                          (tptr tuchar)) tuchar)
                      (Expr.Econst_int (Integers.Int.repr 0) tint))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                              _pad0 (tarray tuchar 48))
                            (Expr.Econst_int (Integers.Int.repr 10) tint)
                            (tptr tuchar)) tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tint))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                _pad0 (tarray tuchar 48))
                              (Expr.Econst_int (Integers.Int.repr 11) tint)
                              (tptr tuchar)) tuchar)
                          (Expr.Econst_int (Integers.Int.repr 0) tint))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                  _pad0 (tarray tuchar 48))
                                (Expr.Econst_int (Integers.Int.repr 12) tint)
                                (tptr tuchar)) tuchar)
                            (Expr.Econst_int (Integers.Int.repr 0) tint))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                    _pad0 (tarray tuchar 48))
                                  (Expr.Econst_int (Integers.Int.repr 13) tint)
                                  (tptr tuchar)) tuchar)
                              (Expr.Econst_int (Integers.Int.repr 0) tint))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                      _pad0 (tarray tuchar 48))
                                    (Expr.Econst_int (Integers.Int.repr 14) tint)
                                    (tptr tuchar)) tuchar)
                                (Expr.Econst_int (Integers.Int.repr 0) tint))
                              (Stmt.Ssequence
                                s_kprog_arm64_entry_raw_0
                                s_kprog_arm64_entry_raw_76))))))))))))))))
}

@[noinline] def s_kprog_arm64_entry_xdp_0 : Stmt :=
(Stmt.Sassign (Expr.Evar ___a64_sim_helper_abi_base (tptr tvoid))
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))

@[noinline] def s_kprog_arm64_entry_xdp_1 : Stmt :=
(Stmt.Scall (some _t'16)
  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong cc_default))
  [(Expr.Econst_int (Integers.Int.repr 6) tint)])

@[noinline] def s_kprog_arm64_entry_xdp_2 : Stmt :=
(Stmt.Sset _t'17
  (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong) tulong))

@[noinline] def s_kprog_arm64_entry_xdp_3 : Stmt :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'18)
    (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                         cc_default))
    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
  (Stmt.Sset _t'17 (Expr.Ecast (Expr.Etempvar _t'18 tulong) tulong)))

@[noinline] def s_kprog_arm64_entry_xdp_4 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Econst_int (Integers.Int.repr 8) tuint)
                      (Expr.Econst_int (Integers.Int.repr 30) tuint) tint)
    (Stmt.Sset _t'19
      (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong) tulong))
    (Stmt.Ssequence
      (Stmt.Scall (some _t'20)
        (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                             cc_default))
        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
      (Stmt.Sset _t'19 (Expr.Ecast (Expr.Etempvar _t'20 tulong) tulong))))
  (Stmt.Sassign
    (Expr.Efield (Expr.Evar ___a64_x8 (Ty.Tunion _arm64_sim_gpr noattr)) _x
      tulong) (Expr.Etempvar _t'19 tulong)))

@[noinline] def s_kprog_arm64_entry_xdp_5 : Stmt :=
(Stmt.Sset _t'33
  (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong) tulong))

@[noinline] def s_kprog_arm64_entry_xdp_6 : Stmt :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'34)
    (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                         cc_default))
    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
  (Stmt.Sset _t'33 (Expr.Ecast (Expr.Etempvar _t'34 tulong) tulong)))

@[noinline] def s_kprog_arm64_entry_xdp_7 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                    (Expr.Econst_int (Integers.Int.repr 16) tuint)
                    (Expr.Econst_int (Integers.Int.repr 30) tuint) tint)
  (Stmt.Sset _t'35
    (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong) tulong))
  (Stmt.Ssequence
    (Stmt.Scall (some _t'36)
      (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                           cc_default))
      [(Expr.Econst_int (Integers.Int.repr 6) tint)])
    (Stmt.Sset _t'35 (Expr.Ecast (Expr.Etempvar _t'36 tulong) tulong))))

@[noinline] def s_kprog_arm64_entry_xdp_8 : Stmt :=
(Stmt.Sassign (Expr.Evar ___a64_x16_tag tuchar)
  (Expr.Econst_int (Integers.Int.repr 0) tuint))

@[noinline] def s_kprog_arm64_entry_xdp_9 : Stmt :=
(Stmt.Scall (some _t'50)
  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong cc_default))
  [(Expr.Econst_int (Integers.Int.repr 6) tint)])

@[noinline] def s_kprog_arm64_entry_xdp_10 : Stmt :=
(Stmt.Sset _t'51
  (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong) tulong))

@[noinline] def s_kprog_arm64_entry_xdp_11 : Stmt :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'52)
    (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                         cc_default))
    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
  (Stmt.Sset _t'51 (Expr.Ecast (Expr.Etempvar _t'52 tulong) tulong)))

@[noinline] def s_kprog_arm64_entry_xdp_12 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Econst_int (Integers.Int.repr 25) tuint)
                      (Expr.Econst_int (Integers.Int.repr 30) tuint) tint)
    (Stmt.Sset _t'53
      (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong) tulong))
    (Stmt.Ssequence
      (Stmt.Scall (some _t'54)
        (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                             cc_default))
        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
      (Stmt.Sset _t'53 (Expr.Ecast (Expr.Etempvar _t'54 tulong) tulong))))
  (Stmt.Sassign
    (Expr.Efield (Expr.Evar ___a64_x25 (Ty.Tunion _arm64_sim_gpr noattr)) _x
      tulong) (Expr.Etempvar _t'53 tulong)))

@[noinline] def s_kprog_arm64_entry_xdp_13 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
      (Expr.Econst_int (Integers.Int.repr 5) tint)
      (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
    (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
  (Expr.Eaddrof (Expr.Evar ___a64_x5 (Ty.Tunion _arm64_sim_gpr noattr))
    (tptr (Ty.Tunion _arm64_sim_gpr noattr))))

@[noinline] def s_kprog_arm64_entry_xdp_14 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
      (Expr.Econst_int (Integers.Int.repr 22) tint)
      (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
    (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
  (Expr.Eaddrof (Expr.Evar ___a64_x22 (Ty.Tunion _arm64_sim_gpr noattr))
    (tptr (Ty.Tunion _arm64_sim_gpr noattr))))

@[noinline] def s_kprog_arm64_entry_xdp_15 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
      (Expr.Econst_int (Integers.Int.repr 8) tint) (tptr (tptr tuchar)))
    (tptr tuchar))
  (Expr.Eaddrof (Expr.Evar ___a64_x8_tag tuchar) (tptr tuchar)))

@[noinline] def s_kprog_arm64_entry_xdp_16 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
      (Expr.Econst_int (Integers.Int.repr 25) tint) (tptr (tptr tuchar)))
    (tptr tuchar))
  (Expr.Eaddrof (Expr.Evar ___a64_x25_tag tuchar) (tptr tuchar)))

@[noinline] def s_kprog_arm64_entry_xdp_17 : Stmt :=
(Stmt.Scall (some _t'74)
  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong cc_default))
  [(Expr.Econst_int (Integers.Int.repr 6) tint)])

@[noinline] def s_kprog_arm64_entry_xdp_18 : Stmt :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'75)
    (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                         cc_default))
    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
  (Stmt.Sassign
    (Expr.Efield
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
          (Expr.Econst_int (Integers.Int.repr 3) tint)
          (tptr (Ty.Tstruct __2946 noattr))) (Ty.Tstruct __2946 noattr)) _lo
      tulong) (Expr.Etempvar _t'75 tulong)))

@[noinline] def s_kprog_arm64_entry_xdp_19 : Stmt :=
(Stmt.Scall (some _t'91)
  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong cc_default))
  [(Expr.Econst_int (Integers.Int.repr 6) tint)])

@[noinline] def s_kprog_arm64_entry_xdp_20 : Stmt :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'92)
    (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                         cc_default))
    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
  (Stmt.Sassign
    (Expr.Efield
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
          (Expr.Econst_int (Integers.Int.repr 11) tint)
          (tptr (Ty.Tstruct __2946 noattr))) (Ty.Tstruct __2946 noattr)) _hi
      tulong) (Expr.Etempvar _t'92 tulong)))

@[noinline] def s_kprog_arm64_entry_xdp_21 : Stmt :=
(Stmt.Scall (some _t'108)
  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong cc_default))
  [(Expr.Econst_int (Integers.Int.repr 6) tint)])

@[noinline] def s_kprog_arm64_entry_xdp_22 : Stmt :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'109)
    (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                         cc_default))
    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
  (Stmt.Sassign
    (Expr.Efield
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
          (Expr.Econst_int (Integers.Int.repr 20) tint)
          (tptr (Ty.Tstruct __2946 noattr))) (Ty.Tstruct __2946 noattr)) _lo
      tulong) (Expr.Etempvar _t'109 tulong)))

@[noinline] def s_kprog_arm64_entry_xdp_23 : Stmt :=
(Stmt.Scall (some _t'125)
  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong cc_default))
  [(Expr.Econst_int (Integers.Int.repr 6) tint)])

@[noinline] def s_kprog_arm64_entry_xdp_24 : Stmt :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'126)
    (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                         cc_default))
    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
  (Stmt.Sassign
    (Expr.Efield
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
          (Expr.Econst_int (Integers.Int.repr 28) tint)
          (tptr (Ty.Tstruct __2946 noattr))) (Ty.Tstruct __2946 noattr)) _hi
      tulong) (Expr.Etempvar _t'126 tulong)))

@[noinline] def s_kprog_arm64_entry_xdp_25 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
      (Expr.Econst_int (Integers.Int.repr 10) tint) (tptr tuchar)) tuchar)
  (Expr.Econst_int (Integers.Int.repr 0) tint))

@[noinline] def s_kprog_arm64_entry_xdp_26 : Stmt :=
(Stmt.Sassign (Expr.Evar ___a64_sim_helper_abi_base (tptr tvoid))
  (Expr.Eaddrof
    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_xdp_abi noattr))
    (tptr (Ty.Tstruct _arm64_sim_xdp_abi noattr))))

@[noinline] def s_kprog_arm64_entry_xdp_27 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
        _vector_lo (tarray (tptr tulong) 32))
      (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr (tptr tulong)))
    (tptr tulong))
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))

@[noinline] def s_kprog_arm64_entry_xdp_28 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
        _vector_lo (tarray (tptr tulong) 32))
      (Expr.Econst_int (Integers.Int.repr 17) tint) (tptr (tptr tulong)))
    (tptr tulong))
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))

@[noinline] def s_kprog_arm64_entry_xdp_29 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
        _vector_hi (tarray (tptr tulong) 32))
      (Expr.Econst_int (Integers.Int.repr 2) tint) (tptr (tptr tulong)))
    (tptr tulong))
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))

@[noinline] def s_kprog_arm64_entry_xdp_30 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
        _vector_hi (tarray (tptr tulong) 32))
      (Expr.Econst_int (Integers.Int.repr 19) tint) (tptr (tptr tulong)))
    (tptr tulong))
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))

@[noinline] def s_kprog_arm64_entry_xdp_31 : Stmt :=
(Stmt.Sassign
  (Expr.Efield (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
    _payload_store
    (tptr (Ty.Tfunction [(tptr (tvolatile tulong)), tulong, tulong] tvoid
            cc_default)))
  (Expr.Evar _kprog_arm64_payload_store (Ty.Tfunction
                                          [(tptr (tvolatile tulong)), tulong,
                                           tulong] tvoid cc_default)))

@[noinline] def s_kprog_arm64_entry_xdp_32 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Efield (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
      _stack_tags (tptr tuchar))
    (Expr.Evar ___a64_stack_tag (tarray tuchar 24)))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Efield (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
        _capacity tuint)
      (Expr.Esizeof (tarray (tvolatile tuchar) 160) tulong))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Efield
          (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
          _payload_words tuint)
        (Expr.Ebinop Binop.Odiv
          (Expr.Esizeof (tarray (tvolatile tulong) 20) tulong)
          (Expr.Esizeof (tvolatile tulong) tulong) tulong))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Efield
            (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
            _tag_bytes tuint) (Expr.Esizeof (tarray tuchar 24) tulong))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Efield
              (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr)) _bias
              tlong) (Expr.Econst_long (Integers.Int64.repr 96) tlong))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Efield
                (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                _helper_context (tptr (tptr tvoid)))
              (Expr.Eaddrof (Expr.Evar ___a64_sim_helper_ctx (tptr tvoid))
                (tptr (tptr tvoid))))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                  _helper_abi_base (tptr (tptr tvoid)))
                (Expr.Eaddrof
                  (Expr.Evar ___a64_sim_helper_abi_base (tptr tvoid))
                  (tptr (tptr tvoid))))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Efield
                    (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                    _is_xdp (tptr tuchar))
                  (Expr.Eaddrof (Expr.Evar ___a64_sim_is_xdp tuchar)
                    (tptr tuchar)))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Efield
                      (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                      _abi_kind (tptr tuchar))
                    (Expr.Eaddrof (Expr.Evar ___a64_sim_abi_kind tuchar)
                      (tptr tuchar)))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Efield
                        (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                        _skb_context
                        (tptr (tptr (Ty.Tstruct ___sk_buff noattr))))
                      (Expr.Eaddrof
                        (Expr.Evar ___a64_sim_skb_ctx (tptr (Ty.Tstruct ___sk_buff noattr)))
                        (tptr (tptr (Ty.Tstruct ___sk_buff noattr)))))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Efield
                          (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                          _abi (tptr tvoid))
                        (Expr.Eaddrof
                          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_xdp_abi noattr))
                          (tptr (Ty.Tstruct _arm64_sim_xdp_abi noattr))))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sset _i
                            (Expr.Econst_int (Integers.Int.repr 0) tint))
                          (Stmt.Sloop
                            (Stmt.Ssequence
                              (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                                  (Expr.Etempvar _i tuint)
                                                  (Expr.Econst_int (Integers.Int.repr 32) tint)
                                                  tint)
                                Stmt.Sskip
                                Stmt.Sbreak)
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Efield
                                        (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                        _vector_lo (tarray (tptr tulong) 32))
                                      (Expr.Etempvar _i tuint)
                                      (tptr (tptr tulong))) (tptr tulong))
                                  (Expr.Eaddrof
                                    (Expr.Efield
                                      (Expr.Ederef
                                        (Expr.Ebinop Binop.Oadd
                                          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                                          (Expr.Etempvar _i tuint)
                                          (tptr (Ty.Tstruct __2946 noattr)))
                                        (Ty.Tstruct __2946 noattr)) _lo
                                      tulong) (tptr tulong)))
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Efield
                                        (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                        _vector_hi (tarray (tptr tulong) 32))
                                      (Expr.Etempvar _i tuint)
                                      (tptr (tptr tulong))) (tptr tulong))
                                  (Expr.Eaddrof
                                    (Expr.Efield
                                      (Expr.Ederef
                                        (Expr.Ebinop Binop.Oadd
                                          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                                          (Expr.Etempvar _i tuint)
                                          (tptr (Ty.Tstruct __2946 noattr)))
                                        (Ty.Tstruct __2946 noattr)) _hi
                                      tulong) (tptr tulong)))))
                            (Stmt.Sset _i
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Etempvar _i tuint)
                                (Expr.Econst_int (Integers.Int.repr 1) tint)
                                tuint))))
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'133)
                            (Expr.Etempvar _continuation (tptr (Ty.Tfunction
                                                                 [(tptr (Ty.Tstruct _kprog_arm64_entry noattr))]
                                                                 tuint
                                                                 cc_default)))
                            [(Expr.Eaddrof
                               (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                               (tptr (Ty.Tstruct _kprog_arm64_entry noattr)))])
                          (Stmt.Sreturn (some (Expr.Etempvar _t'133 tuint))))))))))))))))

@[noinline] def s_kprog_arm64_entry_xdp_33 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Efield
          (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
          _vector_hi (tarray (tptr tulong) 32))
        (Expr.Econst_int (Integers.Int.repr 20) tint) (tptr (tptr tulong)))
      (tptr tulong))
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Efield
            (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
            _vector_hi (tarray (tptr tulong) 32))
          (Expr.Econst_int (Integers.Int.repr 21) tint) (tptr (tptr tulong)))
        (tptr tulong))
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
              _vector_hi (tarray (tptr tulong) 32))
            (Expr.Econst_int (Integers.Int.repr 22) tint)
            (tptr (tptr tulong))) (tptr tulong))
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
          (tptr tvoid)))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                _vector_hi (tarray (tptr tulong) 32))
              (Expr.Econst_int (Integers.Int.repr 23) tint)
              (tptr (tptr tulong))) (tptr tulong))
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
            (tptr tvoid)))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                  _vector_hi (tarray (tptr tulong) 32))
                (Expr.Econst_int (Integers.Int.repr 24) tint)
                (tptr (tptr tulong))) (tptr tulong))
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
              (tptr tvoid)))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                    _vector_hi (tarray (tptr tulong) 32))
                  (Expr.Econst_int (Integers.Int.repr 25) tint)
                  (tptr (tptr tulong))) (tptr tulong))
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                (tptr tvoid)))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Efield
                      (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                      _vector_hi (tarray (tptr tulong) 32))
                    (Expr.Econst_int (Integers.Int.repr 26) tint)
                    (tptr (tptr tulong))) (tptr tulong))
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                  (tptr tvoid)))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                        _vector_hi (tarray (tptr tulong) 32))
                      (Expr.Econst_int (Integers.Int.repr 27) tint)
                      (tptr (tptr tulong))) (tptr tulong))
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                    (tptr tvoid)))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                          _vector_hi (tarray (tptr tulong) 32))
                        (Expr.Econst_int (Integers.Int.repr 28) tint)
                        (tptr (tptr tulong))) (tptr tulong))
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                      (tptr tvoid)))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Efield
                            (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                            _vector_hi (tarray (tptr tulong) 32))
                          (Expr.Econst_int (Integers.Int.repr 29) tint)
                          (tptr (tptr tulong))) (tptr tulong))
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 0) tint)
                        (tptr tvoid)))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                              _vector_hi (tarray (tptr tulong) 32))
                            (Expr.Econst_int (Integers.Int.repr 30) tint)
                            (tptr (tptr tulong))) (tptr tulong))
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                          (tptr tvoid)))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                _vector_hi (tarray (tptr tulong) 32))
                              (Expr.Econst_int (Integers.Int.repr 31) tint)
                              (tptr (tptr tulong))) (tptr tulong))
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                            (tptr tvoid)))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                              _b (tptr (tvolatile tuchar)))
                            (Expr.Efield
                              (Expr.Evar ___a64_stack (tvolatile (Ty.Tunion __2948 noattr)))
                              _b (tvolatile (tarray tuchar 160))))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                _q (tptr (tvolatile tulong)))
                              (Expr.Efield
                                (Expr.Evar ___a64_stack (tvolatile (Ty.Tunion __2948 noattr)))
                                _q (tvolatile (tarray tulong 20))))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                  _payload (tptr (tvolatile tulong)))
                                (Expr.Evar ___a64_stack_payload (tarray (tvolatile tulong) 20)))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Efield
                                    (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                    _payload_load
                                    (tptr (Ty.Tfunction
                                            [(tptr (tvolatile tulong)),
                                             tulong] tulong cc_default)))
                                  (Expr.Evar _kprog_arm64_payload_load 
                                  (Ty.Tfunction
                                    [(tptr (tvolatile tulong)), tulong]
                                    tulong cc_default)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_xdp_31
                                  s_kprog_arm64_entry_xdp_32)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_xdp_34 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Efield
          (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
          _vector_hi (tarray (tptr tulong) 32))
        (Expr.Econst_int (Integers.Int.repr 3) tint) (tptr (tptr tulong)))
      (tptr tulong))
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Efield
            (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
            _vector_hi (tarray (tptr tulong) 32))
          (Expr.Econst_int (Integers.Int.repr 4) tint) (tptr (tptr tulong)))
        (tptr tulong))
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
              _vector_hi (tarray (tptr tulong) 32))
            (Expr.Econst_int (Integers.Int.repr 5) tint)
            (tptr (tptr tulong))) (tptr tulong))
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
          (tptr tvoid)))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                _vector_hi (tarray (tptr tulong) 32))
              (Expr.Econst_int (Integers.Int.repr 6) tint)
              (tptr (tptr tulong))) (tptr tulong))
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
            (tptr tvoid)))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                  _vector_hi (tarray (tptr tulong) 32))
                (Expr.Econst_int (Integers.Int.repr 7) tint)
                (tptr (tptr tulong))) (tptr tulong))
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
              (tptr tvoid)))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                    _vector_hi (tarray (tptr tulong) 32))
                  (Expr.Econst_int (Integers.Int.repr 8) tint)
                  (tptr (tptr tulong))) (tptr tulong))
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                (tptr tvoid)))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Efield
                      (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                      _vector_hi (tarray (tptr tulong) 32))
                    (Expr.Econst_int (Integers.Int.repr 9) tint)
                    (tptr (tptr tulong))) (tptr tulong))
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                  (tptr tvoid)))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                        _vector_hi (tarray (tptr tulong) 32))
                      (Expr.Econst_int (Integers.Int.repr 10) tint)
                      (tptr (tptr tulong))) (tptr tulong))
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                    (tptr tvoid)))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                          _vector_hi (tarray (tptr tulong) 32))
                        (Expr.Econst_int (Integers.Int.repr 11) tint)
                        (tptr (tptr tulong))) (tptr tulong))
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                      (tptr tvoid)))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Efield
                            (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                            _vector_hi (tarray (tptr tulong) 32))
                          (Expr.Econst_int (Integers.Int.repr 12) tint)
                          (tptr (tptr tulong))) (tptr tulong))
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 0) tint)
                        (tptr tvoid)))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                              _vector_hi (tarray (tptr tulong) 32))
                            (Expr.Econst_int (Integers.Int.repr 13) tint)
                            (tptr (tptr tulong))) (tptr tulong))
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                          (tptr tvoid)))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                _vector_hi (tarray (tptr tulong) 32))
                              (Expr.Econst_int (Integers.Int.repr 14) tint)
                              (tptr (tptr tulong))) (tptr tulong))
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                            (tptr tvoid)))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                  _vector_hi (tarray (tptr tulong) 32))
                                (Expr.Econst_int (Integers.Int.repr 15) tint)
                                (tptr (tptr tulong))) (tptr tulong))
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 0) tint)
                              (tptr tvoid)))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                    _vector_hi (tarray (tptr tulong) 32))
                                  (Expr.Econst_int (Integers.Int.repr 16) tint)
                                  (tptr (tptr tulong))) (tptr tulong))
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 0) tint)
                                (tptr tvoid)))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                      _vector_hi (tarray (tptr tulong) 32))
                                    (Expr.Econst_int (Integers.Int.repr 17) tint)
                                    (tptr (tptr tulong))) (tptr tulong))
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 0) tint)
                                  (tptr tvoid)))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Efield
                                        (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                        _vector_hi (tarray (tptr tulong) 32))
                                      (Expr.Econst_int (Integers.Int.repr 18) tint)
                                      (tptr (tptr tulong))) (tptr tulong))
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 0) tint)
                                    (tptr tvoid)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_xdp_30
                                  s_kprog_arm64_entry_xdp_33)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_xdp_35 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Efield
          (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
          _vector_lo (tarray (tptr tulong) 32))
        (Expr.Econst_int (Integers.Int.repr 18) tint) (tptr (tptr tulong)))
      (tptr tulong))
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Efield
            (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
            _vector_lo (tarray (tptr tulong) 32))
          (Expr.Econst_int (Integers.Int.repr 19) tint) (tptr (tptr tulong)))
        (tptr tulong))
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
              _vector_lo (tarray (tptr tulong) 32))
            (Expr.Econst_int (Integers.Int.repr 20) tint)
            (tptr (tptr tulong))) (tptr tulong))
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
          (tptr tvoid)))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                _vector_lo (tarray (tptr tulong) 32))
              (Expr.Econst_int (Integers.Int.repr 21) tint)
              (tptr (tptr tulong))) (tptr tulong))
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
            (tptr tvoid)))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                  _vector_lo (tarray (tptr tulong) 32))
                (Expr.Econst_int (Integers.Int.repr 22) tint)
                (tptr (tptr tulong))) (tptr tulong))
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
              (tptr tvoid)))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                    _vector_lo (tarray (tptr tulong) 32))
                  (Expr.Econst_int (Integers.Int.repr 23) tint)
                  (tptr (tptr tulong))) (tptr tulong))
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                (tptr tvoid)))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Efield
                      (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                      _vector_lo (tarray (tptr tulong) 32))
                    (Expr.Econst_int (Integers.Int.repr 24) tint)
                    (tptr (tptr tulong))) (tptr tulong))
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                  (tptr tvoid)))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                        _vector_lo (tarray (tptr tulong) 32))
                      (Expr.Econst_int (Integers.Int.repr 25) tint)
                      (tptr (tptr tulong))) (tptr tulong))
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                    (tptr tvoid)))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                          _vector_lo (tarray (tptr tulong) 32))
                        (Expr.Econst_int (Integers.Int.repr 26) tint)
                        (tptr (tptr tulong))) (tptr tulong))
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                      (tptr tvoid)))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Efield
                            (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                            _vector_lo (tarray (tptr tulong) 32))
                          (Expr.Econst_int (Integers.Int.repr 27) tint)
                          (tptr (tptr tulong))) (tptr tulong))
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 0) tint)
                        (tptr tvoid)))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                              _vector_lo (tarray (tptr tulong) 32))
                            (Expr.Econst_int (Integers.Int.repr 28) tint)
                            (tptr (tptr tulong))) (tptr tulong))
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                          (tptr tvoid)))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                _vector_lo (tarray (tptr tulong) 32))
                              (Expr.Econst_int (Integers.Int.repr 29) tint)
                              (tptr (tptr tulong))) (tptr tulong))
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                            (tptr tvoid)))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                  _vector_lo (tarray (tptr tulong) 32))
                                (Expr.Econst_int (Integers.Int.repr 30) tint)
                                (tptr (tptr tulong))) (tptr tulong))
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 0) tint)
                              (tptr tvoid)))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                    _vector_lo (tarray (tptr tulong) 32))
                                  (Expr.Econst_int (Integers.Int.repr 31) tint)
                                  (tptr (tptr tulong))) (tptr tulong))
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 0) tint)
                                (tptr tvoid)))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                      _vector_hi (tarray (tptr tulong) 32))
                                    (Expr.Econst_int (Integers.Int.repr 0) tint)
                                    (tptr (tptr tulong))) (tptr tulong))
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 0) tint)
                                  (tptr tvoid)))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Efield
                                        (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                        _vector_hi (tarray (tptr tulong) 32))
                                      (Expr.Econst_int (Integers.Int.repr 1) tint)
                                      (tptr (tptr tulong))) (tptr tulong))
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 0) tint)
                                    (tptr tvoid)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_xdp_29
                                  s_kprog_arm64_entry_xdp_34)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_xdp_36 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Efield
          (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
          _vector_lo (tarray (tptr tulong) 32))
        (Expr.Econst_int (Integers.Int.repr 1) tint) (tptr (tptr tulong)))
      (tptr tulong))
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Efield
            (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
            _vector_lo (tarray (tptr tulong) 32))
          (Expr.Econst_int (Integers.Int.repr 2) tint) (tptr (tptr tulong)))
        (tptr tulong))
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
              _vector_lo (tarray (tptr tulong) 32))
            (Expr.Econst_int (Integers.Int.repr 3) tint)
            (tptr (tptr tulong))) (tptr tulong))
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
          (tptr tvoid)))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                _vector_lo (tarray (tptr tulong) 32))
              (Expr.Econst_int (Integers.Int.repr 4) tint)
              (tptr (tptr tulong))) (tptr tulong))
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
            (tptr tvoid)))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                  _vector_lo (tarray (tptr tulong) 32))
                (Expr.Econst_int (Integers.Int.repr 5) tint)
                (tptr (tptr tulong))) (tptr tulong))
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
              (tptr tvoid)))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                    _vector_lo (tarray (tptr tulong) 32))
                  (Expr.Econst_int (Integers.Int.repr 6) tint)
                  (tptr (tptr tulong))) (tptr tulong))
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                (tptr tvoid)))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Efield
                      (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                      _vector_lo (tarray (tptr tulong) 32))
                    (Expr.Econst_int (Integers.Int.repr 7) tint)
                    (tptr (tptr tulong))) (tptr tulong))
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                  (tptr tvoid)))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                        _vector_lo (tarray (tptr tulong) 32))
                      (Expr.Econst_int (Integers.Int.repr 8) tint)
                      (tptr (tptr tulong))) (tptr tulong))
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                    (tptr tvoid)))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                          _vector_lo (tarray (tptr tulong) 32))
                        (Expr.Econst_int (Integers.Int.repr 9) tint)
                        (tptr (tptr tulong))) (tptr tulong))
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                      (tptr tvoid)))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Efield
                            (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                            _vector_lo (tarray (tptr tulong) 32))
                          (Expr.Econst_int (Integers.Int.repr 10) tint)
                          (tptr (tptr tulong))) (tptr tulong))
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 0) tint)
                        (tptr tvoid)))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                              _vector_lo (tarray (tptr tulong) 32))
                            (Expr.Econst_int (Integers.Int.repr 11) tint)
                            (tptr (tptr tulong))) (tptr tulong))
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                          (tptr tvoid)))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                _vector_lo (tarray (tptr tulong) 32))
                              (Expr.Econst_int (Integers.Int.repr 12) tint)
                              (tptr (tptr tulong))) (tptr tulong))
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                            (tptr tvoid)))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                  _vector_lo (tarray (tptr tulong) 32))
                                (Expr.Econst_int (Integers.Int.repr 13) tint)
                                (tptr (tptr tulong))) (tptr tulong))
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 0) tint)
                              (tptr tvoid)))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                    _vector_lo (tarray (tptr tulong) 32))
                                  (Expr.Econst_int (Integers.Int.repr 14) tint)
                                  (tptr (tptr tulong))) (tptr tulong))
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 0) tint)
                                (tptr tvoid)))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                      _vector_lo (tarray (tptr tulong) 32))
                                    (Expr.Econst_int (Integers.Int.repr 15) tint)
                                    (tptr (tptr tulong))) (tptr tulong))
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 0) tint)
                                  (tptr tvoid)))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Efield
                                        (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                        _vector_lo (tarray (tptr tulong) 32))
                                      (Expr.Econst_int (Integers.Int.repr 16) tint)
                                      (tptr (tptr tulong))) (tptr tulong))
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 0) tint)
                                    (tptr tvoid)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_xdp_28
                                  s_kprog_arm64_entry_xdp_35)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_xdp_37 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Efield (Expr.Evar ___a64_x0 (Ty.Tunion _arm64_sim_gpr noattr)) _ptr
      (tptr tvoid))
    (Expr.Ecast (Expr.Etempvar _ctx (tptr (Ty.Tstruct _xdp_md noattr)))
      (tptr tvoid)))
  (Stmt.Ssequence
    (Stmt.Sassign (Expr.Evar ___a64_x30_tag tuchar)
      (Expr.Econst_int (Integers.Int.repr 10) tuint))
    (Stmt.Ssequence
      (Stmt.Sassign (Expr.Evar ___a64_x0_tag tuchar)
        (Expr.Econst_int (Integers.Int.repr 1) tuint))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Efield
            (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr)) _cells
            (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
          (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31)))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Efield
              (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
              _tag_cells (tptr (tptr tuchar)))
            (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31)))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Efield
                (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                _sp_base (tptr tulong))
              (Expr.Eaddrof (Expr.Evar ___a64_numeric_sp tulong)
                (tptr tulong)))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                  _return_base (tptr tulong))
                (Expr.Eaddrof (Expr.Evar ___a64_numeric_return tulong)
                  (tptr tulong)))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Efield
                    (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                    _lr (tptr tulong))
                  (Expr.Eaddrof (Expr.Evar ___a64_lr tulong) (tptr tulong)))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Efield
                      (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                      _sp (tptr tlong))
                    (Expr.Eaddrof (Expr.Evar ___a64_sp tlong) (tptr tlong)))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Efield
                        (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                        _sp_valid (tptr tuchar))
                      (Expr.Eaddrof
                        (Expr.Evar ___a64_numeric_sp_valid tuchar)
                        (tptr tuchar)))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Efield
                          (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                          _return_valid (tptr tuchar))
                        (Expr.Eaddrof
                          (Expr.Evar ___a64_numeric_return_valid tuchar)
                          (tptr tuchar)))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                            _n (tptr tuchar))
                          (Expr.Eaddrof (Expr.Evar ___a64_n tuchar)
                            (tptr tuchar)))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                              _z (tptr tuchar))
                            (Expr.Eaddrof (Expr.Evar ___a64_z tuchar)
                              (tptr tuchar)))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                _c (tptr tuchar))
                              (Expr.Eaddrof (Expr.Evar ___a64_c tuchar)
                                (tptr tuchar)))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                  _v (tptr tuchar))
                                (Expr.Eaddrof (Expr.Evar ___a64_v tuchar)
                                  (tptr tuchar)))
                              (Stmt.Ssequence
                                s_kprog_arm64_entry_xdp_27
                                s_kprog_arm64_entry_xdp_36))))))))))))))))

@[noinline] def s_kprog_arm64_entry_xdp_38 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
        (Expr.Econst_int (Integers.Int.repr 11) tint) (tptr tuchar)) tuchar)
    (Expr.Econst_int (Integers.Int.repr 0) tint))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
          (Expr.Econst_int (Integers.Int.repr 12) tint) (tptr tuchar))
        tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
            (Expr.Econst_int (Integers.Int.repr 13) tint) (tptr tuchar))
          tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
              (Expr.Econst_int (Integers.Int.repr 14) tint) (tptr tuchar))
            tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                (Expr.Econst_int (Integers.Int.repr 15) tint) (tptr tuchar))
              tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                  (Expr.Econst_int (Integers.Int.repr 16) tint)
                  (tptr tuchar)) tuchar)
              (Expr.Econst_int (Integers.Int.repr 0) tint))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                    (Expr.Econst_int (Integers.Int.repr 17) tint)
                    (tptr tuchar)) tuchar)
                (Expr.Econst_int (Integers.Int.repr 0) tint))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                      (Expr.Econst_int (Integers.Int.repr 18) tint)
                      (tptr tuchar)) tuchar)
                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                        (Expr.Econst_int (Integers.Int.repr 19) tint)
                        (tptr tuchar)) tuchar)
                    (Expr.Econst_int (Integers.Int.repr 0) tint))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                          (Expr.Econst_int (Integers.Int.repr 20) tint)
                          (tptr tuchar)) tuchar)
                      (Expr.Econst_int (Integers.Int.repr 0) tint))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                            (Expr.Econst_int (Integers.Int.repr 21) tint)
                            (tptr tuchar)) tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tint))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                              (Expr.Econst_int (Integers.Int.repr 22) tint)
                              (tptr tuchar)) tuchar)
                          (Expr.Econst_int (Integers.Int.repr 0) tint))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                                (Expr.Econst_int (Integers.Int.repr 23) tint)
                                (tptr tuchar)) tuchar)
                            (Expr.Econst_int (Integers.Int.repr 0) tint))
                          (Stmt.Ssequence
                            (Stmt.Sassign (Expr.Evar ___a64_sp tlong)
                              (Expr.Econst_int (Integers.Int.repr 0) tint))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Evar ___a64_sim_is_xdp tuchar)
                                (Expr.Econst_int (Integers.Int.repr 1) tint))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Evar ___a64_sim_helper_ctx (tptr tvoid))
                                  (Expr.Ecast
                                    (Expr.Etempvar _ctx (tptr (Ty.Tstruct _xdp_md noattr)))
                                    (tptr tvoid)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_xdp_26
                                  s_kprog_arm64_entry_xdp_37)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_xdp_39 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Scall (some _t'127)
      (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                           cc_default))
      [(Expr.Econst_int (Integers.Int.repr 6) tint)])
    (Stmt.Sassign
      (Expr.Efield
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
            (Expr.Econst_int (Integers.Int.repr 29) tint)
            (tptr (Ty.Tstruct __2946 noattr))) (Ty.Tstruct __2946 noattr))
        _lo tulong) (Expr.Etempvar _t'127 tulong)))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Scall (some _t'128)
        (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                             cc_default))
        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
      (Stmt.Sassign
        (Expr.Efield
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
              (Expr.Econst_int (Integers.Int.repr 29) tint)
              (tptr (Ty.Tstruct __2946 noattr))) (Ty.Tstruct __2946 noattr))
          _hi tulong) (Expr.Etempvar _t'128 tulong)))
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Scall (some _t'129)
          (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                               cc_default))
          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
        (Stmt.Sassign
          (Expr.Efield
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                (Expr.Econst_int (Integers.Int.repr 30) tint)
                (tptr (Ty.Tstruct __2946 noattr)))
              (Ty.Tstruct __2946 noattr)) _lo tulong)
          (Expr.Etempvar _t'129 tulong)))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Scall (some _t'130)
            (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                 cc_default))
            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
          (Stmt.Sassign
            (Expr.Efield
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                  (Expr.Econst_int (Integers.Int.repr 30) tint)
                  (tptr (Ty.Tstruct __2946 noattr)))
                (Ty.Tstruct __2946 noattr)) _hi tulong)
            (Expr.Etempvar _t'130 tulong)))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Scall (some _t'131)
              (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                   cc_default))
              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
            (Stmt.Sassign
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                    (Expr.Econst_int (Integers.Int.repr 31) tint)
                    (tptr (Ty.Tstruct __2946 noattr)))
                  (Ty.Tstruct __2946 noattr)) _lo tulong)
              (Expr.Etempvar _t'131 tulong)))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Scall (some _t'132)
                (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                     tulong cc_default))
                [(Expr.Econst_int (Integers.Int.repr 6) tint)])
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                      (Expr.Econst_int (Integers.Int.repr 31) tint)
                      (tptr (Ty.Tstruct __2946 noattr)))
                    (Ty.Tstruct __2946 noattr)) _hi tulong)
                (Expr.Etempvar _t'132 tulong)))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                    (Expr.Econst_int (Integers.Int.repr 0) tint)
                    (tptr tuchar)) tuchar)
                (Expr.Econst_int (Integers.Int.repr 0) tint))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                      (Expr.Econst_int (Integers.Int.repr 1) tint)
                      (tptr tuchar)) tuchar)
                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                        (Expr.Econst_int (Integers.Int.repr 2) tint)
                        (tptr tuchar)) tuchar)
                    (Expr.Econst_int (Integers.Int.repr 0) tint))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                          (Expr.Econst_int (Integers.Int.repr 3) tint)
                          (tptr tuchar)) tuchar)
                      (Expr.Econst_int (Integers.Int.repr 0) tint))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                            (Expr.Econst_int (Integers.Int.repr 4) tint)
                            (tptr tuchar)) tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tint))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                              (Expr.Econst_int (Integers.Int.repr 5) tint)
                              (tptr tuchar)) tuchar)
                          (Expr.Econst_int (Integers.Int.repr 0) tint))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                                (Expr.Econst_int (Integers.Int.repr 6) tint)
                                (tptr tuchar)) tuchar)
                            (Expr.Econst_int (Integers.Int.repr 0) tint))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                                  (Expr.Econst_int (Integers.Int.repr 7) tint)
                                  (tptr tuchar)) tuchar)
                              (Expr.Econst_int (Integers.Int.repr 0) tint))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                                    (Expr.Econst_int (Integers.Int.repr 8) tint)
                                    (tptr tuchar)) tuchar)
                                (Expr.Econst_int (Integers.Int.repr 0) tint))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                                      (Expr.Econst_int (Integers.Int.repr 9) tint)
                                      (tptr tuchar)) tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_xdp_25
                                  s_kprog_arm64_entry_xdp_38)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_xdp_40 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Scall (some _t'110)
      (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                           cc_default))
      [(Expr.Econst_int (Integers.Int.repr 6) tint)])
    (Stmt.Sassign
      (Expr.Efield
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
            (Expr.Econst_int (Integers.Int.repr 20) tint)
            (tptr (Ty.Tstruct __2946 noattr))) (Ty.Tstruct __2946 noattr))
        _hi tulong) (Expr.Etempvar _t'110 tulong)))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Scall (some _t'111)
        (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                             cc_default))
        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
      (Stmt.Sassign
        (Expr.Efield
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
              (Expr.Econst_int (Integers.Int.repr 21) tint)
              (tptr (Ty.Tstruct __2946 noattr))) (Ty.Tstruct __2946 noattr))
          _lo tulong) (Expr.Etempvar _t'111 tulong)))
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Scall (some _t'112)
          (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                               cc_default))
          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
        (Stmt.Sassign
          (Expr.Efield
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                (Expr.Econst_int (Integers.Int.repr 21) tint)
                (tptr (Ty.Tstruct __2946 noattr)))
              (Ty.Tstruct __2946 noattr)) _hi tulong)
          (Expr.Etempvar _t'112 tulong)))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Scall (some _t'113)
            (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                 cc_default))
            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
          (Stmt.Sassign
            (Expr.Efield
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                  (Expr.Econst_int (Integers.Int.repr 22) tint)
                  (tptr (Ty.Tstruct __2946 noattr)))
                (Ty.Tstruct __2946 noattr)) _lo tulong)
            (Expr.Etempvar _t'113 tulong)))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Scall (some _t'114)
              (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                   cc_default))
              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
            (Stmt.Sassign
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                    (Expr.Econst_int (Integers.Int.repr 22) tint)
                    (tptr (Ty.Tstruct __2946 noattr)))
                  (Ty.Tstruct __2946 noattr)) _hi tulong)
              (Expr.Etempvar _t'114 tulong)))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Scall (some _t'115)
                (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                     tulong cc_default))
                [(Expr.Econst_int (Integers.Int.repr 6) tint)])
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                      (Expr.Econst_int (Integers.Int.repr 23) tint)
                      (tptr (Ty.Tstruct __2946 noattr)))
                    (Ty.Tstruct __2946 noattr)) _lo tulong)
                (Expr.Etempvar _t'115 tulong)))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Scall (some _t'116)
                  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                       tulong cc_default))
                  [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                (Stmt.Sassign
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                        (Expr.Econst_int (Integers.Int.repr 23) tint)
                        (tptr (Ty.Tstruct __2946 noattr)))
                      (Ty.Tstruct __2946 noattr)) _hi tulong)
                  (Expr.Etempvar _t'116 tulong)))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Scall (some _t'117)
                    (Expr.Evar _native_lab_entry_input (Ty.Tfunction 
                                                         [tuint] tulong
                                                         cc_default))
                    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                  (Stmt.Sassign
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                          (Expr.Econst_int (Integers.Int.repr 24) tint)
                          (tptr (Ty.Tstruct __2946 noattr)))
                        (Ty.Tstruct __2946 noattr)) _lo tulong)
                    (Expr.Etempvar _t'117 tulong)))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Scall (some _t'118)
                      (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                           [tuint] tulong
                                                           cc_default))
                      [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                    (Stmt.Sassign
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                            (Expr.Econst_int (Integers.Int.repr 24) tint)
                            (tptr (Ty.Tstruct __2946 noattr)))
                          (Ty.Tstruct __2946 noattr)) _hi tulong)
                      (Expr.Etempvar _t'118 tulong)))
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Scall (some _t'119)
                        (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                             [tuint] tulong
                                                             cc_default))
                        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                      (Stmt.Sassign
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                              (Expr.Econst_int (Integers.Int.repr 25) tint)
                              (tptr (Ty.Tstruct __2946 noattr)))
                            (Ty.Tstruct __2946 noattr)) _lo tulong)
                        (Expr.Etempvar _t'119 tulong)))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Scall (some _t'120)
                          (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                               [tuint] tulong
                                                               cc_default))
                          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                                (Expr.Econst_int (Integers.Int.repr 25) tint)
                                (tptr (Ty.Tstruct __2946 noattr)))
                              (Ty.Tstruct __2946 noattr)) _hi tulong)
                          (Expr.Etempvar _t'120 tulong)))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'121)
                            (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                 [tuint]
                                                                 tulong
                                                                 cc_default))
                            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                                  (Expr.Econst_int (Integers.Int.repr 26) tint)
                                  (tptr (Ty.Tstruct __2946 noattr)))
                                (Ty.Tstruct __2946 noattr)) _lo tulong)
                            (Expr.Etempvar _t'121 tulong)))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Scall (some _t'122)
                              (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                   [tuint]
                                                                   tulong
                                                                   cc_default))
                              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                                    (Expr.Econst_int (Integers.Int.repr 26) tint)
                                    (tptr (Ty.Tstruct __2946 noattr)))
                                  (Ty.Tstruct __2946 noattr)) _hi tulong)
                              (Expr.Etempvar _t'122 tulong)))
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Scall (some _t'123)
                                (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                    [tuint]
                                                                    tulong
                                                                    cc_default))
                                [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                                      (Expr.Econst_int (Integers.Int.repr 27) tint)
                                      (tptr (Ty.Tstruct __2946 noattr)))
                                    (Ty.Tstruct __2946 noattr)) _lo tulong)
                                (Expr.Etempvar _t'123 tulong)))
                            (Stmt.Ssequence
                              (Stmt.Ssequence
                                (Stmt.Scall (some _t'124)
                                  (Expr.Evar _native_lab_entry_input 
                                  (Ty.Tfunction [tuint] tulong cc_default))
                                  [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                                (Stmt.Sassign
                                  (Expr.Efield
                                    (Expr.Ederef
                                      (Expr.Ebinop Binop.Oadd
                                        (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                                        (Expr.Econst_int (Integers.Int.repr 27) tint)
                                        (tptr (Ty.Tstruct __2946 noattr)))
                                      (Ty.Tstruct __2946 noattr)) _hi tulong)
                                  (Expr.Etempvar _t'124 tulong)))
                              (Stmt.Ssequence
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_xdp_23
                                  (Stmt.Sassign
                                    (Expr.Efield
                                      (Expr.Ederef
                                        (Expr.Ebinop Binop.Oadd
                                          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                                          (Expr.Econst_int (Integers.Int.repr 28) tint)
                                          (tptr (Ty.Tstruct __2946 noattr)))
                                        (Ty.Tstruct __2946 noattr)) _lo
                                      tulong) (Expr.Etempvar _t'125 tulong)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_xdp_24
                                  s_kprog_arm64_entry_xdp_39)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_xdp_41 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Scall (some _t'93)
      (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                           cc_default))
      [(Expr.Econst_int (Integers.Int.repr 6) tint)])
    (Stmt.Sassign
      (Expr.Efield
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
            (Expr.Econst_int (Integers.Int.repr 12) tint)
            (tptr (Ty.Tstruct __2946 noattr))) (Ty.Tstruct __2946 noattr))
        _lo tulong) (Expr.Etempvar _t'93 tulong)))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Scall (some _t'94)
        (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                             cc_default))
        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
      (Stmt.Sassign
        (Expr.Efield
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
              (Expr.Econst_int (Integers.Int.repr 12) tint)
              (tptr (Ty.Tstruct __2946 noattr))) (Ty.Tstruct __2946 noattr))
          _hi tulong) (Expr.Etempvar _t'94 tulong)))
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Scall (some _t'95)
          (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                               cc_default))
          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
        (Stmt.Sassign
          (Expr.Efield
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                (Expr.Econst_int (Integers.Int.repr 13) tint)
                (tptr (Ty.Tstruct __2946 noattr)))
              (Ty.Tstruct __2946 noattr)) _lo tulong)
          (Expr.Etempvar _t'95 tulong)))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Scall (some _t'96)
            (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                 cc_default))
            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
          (Stmt.Sassign
            (Expr.Efield
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                  (Expr.Econst_int (Integers.Int.repr 13) tint)
                  (tptr (Ty.Tstruct __2946 noattr)))
                (Ty.Tstruct __2946 noattr)) _hi tulong)
            (Expr.Etempvar _t'96 tulong)))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Scall (some _t'97)
              (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                   cc_default))
              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
            (Stmt.Sassign
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                    (Expr.Econst_int (Integers.Int.repr 14) tint)
                    (tptr (Ty.Tstruct __2946 noattr)))
                  (Ty.Tstruct __2946 noattr)) _lo tulong)
              (Expr.Etempvar _t'97 tulong)))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Scall (some _t'98)
                (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                     tulong cc_default))
                [(Expr.Econst_int (Integers.Int.repr 6) tint)])
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                      (Expr.Econst_int (Integers.Int.repr 14) tint)
                      (tptr (Ty.Tstruct __2946 noattr)))
                    (Ty.Tstruct __2946 noattr)) _hi tulong)
                (Expr.Etempvar _t'98 tulong)))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Scall (some _t'99)
                  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                       tulong cc_default))
                  [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                (Stmt.Sassign
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                        (Expr.Econst_int (Integers.Int.repr 15) tint)
                        (tptr (Ty.Tstruct __2946 noattr)))
                      (Ty.Tstruct __2946 noattr)) _lo tulong)
                  (Expr.Etempvar _t'99 tulong)))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Scall (some _t'100)
                    (Expr.Evar _native_lab_entry_input (Ty.Tfunction 
                                                         [tuint] tulong
                                                         cc_default))
                    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                  (Stmt.Sassign
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                          (Expr.Econst_int (Integers.Int.repr 15) tint)
                          (tptr (Ty.Tstruct __2946 noattr)))
                        (Ty.Tstruct __2946 noattr)) _hi tulong)
                    (Expr.Etempvar _t'100 tulong)))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Scall (some _t'101)
                      (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                           [tuint] tulong
                                                           cc_default))
                      [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                    (Stmt.Sassign
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                            (Expr.Econst_int (Integers.Int.repr 16) tint)
                            (tptr (Ty.Tstruct __2946 noattr)))
                          (Ty.Tstruct __2946 noattr)) _lo tulong)
                      (Expr.Etempvar _t'101 tulong)))
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Scall (some _t'102)
                        (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                             [tuint] tulong
                                                             cc_default))
                        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                      (Stmt.Sassign
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                              (Expr.Econst_int (Integers.Int.repr 16) tint)
                              (tptr (Ty.Tstruct __2946 noattr)))
                            (Ty.Tstruct __2946 noattr)) _hi tulong)
                        (Expr.Etempvar _t'102 tulong)))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Scall (some _t'103)
                          (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                               [tuint] tulong
                                                               cc_default))
                          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                                (Expr.Econst_int (Integers.Int.repr 17) tint)
                                (tptr (Ty.Tstruct __2946 noattr)))
                              (Ty.Tstruct __2946 noattr)) _lo tulong)
                          (Expr.Etempvar _t'103 tulong)))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'104)
                            (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                 [tuint]
                                                                 tulong
                                                                 cc_default))
                            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                                  (Expr.Econst_int (Integers.Int.repr 17) tint)
                                  (tptr (Ty.Tstruct __2946 noattr)))
                                (Ty.Tstruct __2946 noattr)) _hi tulong)
                            (Expr.Etempvar _t'104 tulong)))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Scall (some _t'105)
                              (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                   [tuint]
                                                                   tulong
                                                                   cc_default))
                              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                                    (Expr.Econst_int (Integers.Int.repr 18) tint)
                                    (tptr (Ty.Tstruct __2946 noattr)))
                                  (Ty.Tstruct __2946 noattr)) _lo tulong)
                              (Expr.Etempvar _t'105 tulong)))
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Scall (some _t'106)
                                (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                    [tuint]
                                                                    tulong
                                                                    cc_default))
                                [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                                      (Expr.Econst_int (Integers.Int.repr 18) tint)
                                      (tptr (Ty.Tstruct __2946 noattr)))
                                    (Ty.Tstruct __2946 noattr)) _hi tulong)
                                (Expr.Etempvar _t'106 tulong)))
                            (Stmt.Ssequence
                              (Stmt.Ssequence
                                (Stmt.Scall (some _t'107)
                                  (Expr.Evar _native_lab_entry_input 
                                  (Ty.Tfunction [tuint] tulong cc_default))
                                  [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                                (Stmt.Sassign
                                  (Expr.Efield
                                    (Expr.Ederef
                                      (Expr.Ebinop Binop.Oadd
                                        (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                                        (Expr.Econst_int (Integers.Int.repr 19) tint)
                                        (tptr (Ty.Tstruct __2946 noattr)))
                                      (Ty.Tstruct __2946 noattr)) _lo tulong)
                                  (Expr.Etempvar _t'107 tulong)))
                              (Stmt.Ssequence
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_xdp_21
                                  (Stmt.Sassign
                                    (Expr.Efield
                                      (Expr.Ederef
                                        (Expr.Ebinop Binop.Oadd
                                          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                                          (Expr.Econst_int (Integers.Int.repr 19) tint)
                                          (tptr (Ty.Tstruct __2946 noattr)))
                                        (Ty.Tstruct __2946 noattr)) _hi
                                      tulong) (Expr.Etempvar _t'108 tulong)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_xdp_22
                                  s_kprog_arm64_entry_xdp_40)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_xdp_42 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Scall (some _t'76)
      (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                           cc_default))
      [(Expr.Econst_int (Integers.Int.repr 6) tint)])
    (Stmt.Sassign
      (Expr.Efield
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
            (Expr.Econst_int (Integers.Int.repr 3) tint)
            (tptr (Ty.Tstruct __2946 noattr))) (Ty.Tstruct __2946 noattr))
        _hi tulong) (Expr.Etempvar _t'76 tulong)))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Scall (some _t'77)
        (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                             cc_default))
        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
      (Stmt.Sassign
        (Expr.Efield
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
              (Expr.Econst_int (Integers.Int.repr 4) tint)
              (tptr (Ty.Tstruct __2946 noattr))) (Ty.Tstruct __2946 noattr))
          _lo tulong) (Expr.Etempvar _t'77 tulong)))
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Scall (some _t'78)
          (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                               cc_default))
          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
        (Stmt.Sassign
          (Expr.Efield
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                (Expr.Econst_int (Integers.Int.repr 4) tint)
                (tptr (Ty.Tstruct __2946 noattr)))
              (Ty.Tstruct __2946 noattr)) _hi tulong)
          (Expr.Etempvar _t'78 tulong)))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Scall (some _t'79)
            (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                 cc_default))
            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
          (Stmt.Sassign
            (Expr.Efield
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                  (Expr.Econst_int (Integers.Int.repr 5) tint)
                  (tptr (Ty.Tstruct __2946 noattr)))
                (Ty.Tstruct __2946 noattr)) _lo tulong)
            (Expr.Etempvar _t'79 tulong)))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Scall (some _t'80)
              (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                   cc_default))
              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
            (Stmt.Sassign
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                    (Expr.Econst_int (Integers.Int.repr 5) tint)
                    (tptr (Ty.Tstruct __2946 noattr)))
                  (Ty.Tstruct __2946 noattr)) _hi tulong)
              (Expr.Etempvar _t'80 tulong)))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Scall (some _t'81)
                (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                     tulong cc_default))
                [(Expr.Econst_int (Integers.Int.repr 6) tint)])
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                      (Expr.Econst_int (Integers.Int.repr 6) tint)
                      (tptr (Ty.Tstruct __2946 noattr)))
                    (Ty.Tstruct __2946 noattr)) _lo tulong)
                (Expr.Etempvar _t'81 tulong)))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Scall (some _t'82)
                  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                       tulong cc_default))
                  [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                (Stmt.Sassign
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                        (Expr.Econst_int (Integers.Int.repr 6) tint)
                        (tptr (Ty.Tstruct __2946 noattr)))
                      (Ty.Tstruct __2946 noattr)) _hi tulong)
                  (Expr.Etempvar _t'82 tulong)))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Scall (some _t'83)
                    (Expr.Evar _native_lab_entry_input (Ty.Tfunction 
                                                         [tuint] tulong
                                                         cc_default))
                    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                  (Stmt.Sassign
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                          (Expr.Econst_int (Integers.Int.repr 7) tint)
                          (tptr (Ty.Tstruct __2946 noattr)))
                        (Ty.Tstruct __2946 noattr)) _lo tulong)
                    (Expr.Etempvar _t'83 tulong)))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Scall (some _t'84)
                      (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                           [tuint] tulong
                                                           cc_default))
                      [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                    (Stmt.Sassign
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                            (Expr.Econst_int (Integers.Int.repr 7) tint)
                            (tptr (Ty.Tstruct __2946 noattr)))
                          (Ty.Tstruct __2946 noattr)) _hi tulong)
                      (Expr.Etempvar _t'84 tulong)))
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Scall (some _t'85)
                        (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                             [tuint] tulong
                                                             cc_default))
                        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                      (Stmt.Sassign
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                              (Expr.Econst_int (Integers.Int.repr 8) tint)
                              (tptr (Ty.Tstruct __2946 noattr)))
                            (Ty.Tstruct __2946 noattr)) _lo tulong)
                        (Expr.Etempvar _t'85 tulong)))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Scall (some _t'86)
                          (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                               [tuint] tulong
                                                               cc_default))
                          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                                (Expr.Econst_int (Integers.Int.repr 8) tint)
                                (tptr (Ty.Tstruct __2946 noattr)))
                              (Ty.Tstruct __2946 noattr)) _hi tulong)
                          (Expr.Etempvar _t'86 tulong)))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'87)
                            (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                 [tuint]
                                                                 tulong
                                                                 cc_default))
                            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                                  (Expr.Econst_int (Integers.Int.repr 9) tint)
                                  (tptr (Ty.Tstruct __2946 noattr)))
                                (Ty.Tstruct __2946 noattr)) _lo tulong)
                            (Expr.Etempvar _t'87 tulong)))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Scall (some _t'88)
                              (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                   [tuint]
                                                                   tulong
                                                                   cc_default))
                              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                                    (Expr.Econst_int (Integers.Int.repr 9) tint)
                                    (tptr (Ty.Tstruct __2946 noattr)))
                                  (Ty.Tstruct __2946 noattr)) _hi tulong)
                              (Expr.Etempvar _t'88 tulong)))
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Scall (some _t'89)
                                (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                    [tuint]
                                                                    tulong
                                                                    cc_default))
                                [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                                      (Expr.Econst_int (Integers.Int.repr 10) tint)
                                      (tptr (Ty.Tstruct __2946 noattr)))
                                    (Ty.Tstruct __2946 noattr)) _lo tulong)
                                (Expr.Etempvar _t'89 tulong)))
                            (Stmt.Ssequence
                              (Stmt.Ssequence
                                (Stmt.Scall (some _t'90)
                                  (Expr.Evar _native_lab_entry_input 
                                  (Ty.Tfunction [tuint] tulong cc_default))
                                  [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                                (Stmt.Sassign
                                  (Expr.Efield
                                    (Expr.Ederef
                                      (Expr.Ebinop Binop.Oadd
                                        (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                                        (Expr.Econst_int (Integers.Int.repr 10) tint)
                                        (tptr (Ty.Tstruct __2946 noattr)))
                                      (Ty.Tstruct __2946 noattr)) _hi tulong)
                                  (Expr.Etempvar _t'90 tulong)))
                              (Stmt.Ssequence
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_xdp_19
                                  (Stmt.Sassign
                                    (Expr.Efield
                                      (Expr.Ederef
                                        (Expr.Ebinop Binop.Oadd
                                          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                                          (Expr.Econst_int (Integers.Int.repr 11) tint)
                                          (tptr (Ty.Tstruct __2946 noattr)))
                                        (Ty.Tstruct __2946 noattr)) _lo
                                      tulong) (Expr.Etempvar _t'91 tulong)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_xdp_20
                                  s_kprog_arm64_entry_xdp_41)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_xdp_43 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
        (Expr.Econst_int (Integers.Int.repr 26) tint) (tptr (tptr tuchar)))
      (tptr tuchar))
    (Expr.Eaddrof (Expr.Evar ___a64_x26_tag tuchar) (tptr tuchar)))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
          (Expr.Econst_int (Integers.Int.repr 27) tint) (tptr (tptr tuchar)))
        (tptr tuchar))
      (Expr.Eaddrof (Expr.Evar ___a64_x27_tag tuchar) (tptr tuchar)))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
            (Expr.Econst_int (Integers.Int.repr 28) tint)
            (tptr (tptr tuchar))) (tptr tuchar))
        (Expr.Eaddrof (Expr.Evar ___a64_x28_tag tuchar) (tptr tuchar)))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
              (Expr.Econst_int (Integers.Int.repr 29) tint)
              (tptr (tptr tuchar))) (tptr tuchar))
          (Expr.Eaddrof (Expr.Evar ___a64_x29_tag tuchar) (tptr tuchar)))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                (Expr.Econst_int (Integers.Int.repr 30) tint)
                (tptr (tptr tuchar))) (tptr tuchar))
            (Expr.Eaddrof (Expr.Evar ___a64_x30_tag tuchar) (tptr tuchar)))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Scall (some _t'65)
                (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                     tulong cc_default))
                [(Expr.Econst_int (Integers.Int.repr 6) tint)])
              (Stmt.Sassign (Expr.Evar ___a64_n tuchar)
                (Expr.Ebinop Binop.Oand (Expr.Etempvar _t'65 tulong)
                  (Expr.Econst_int (Integers.Int.repr 1) tint) tulong)))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Scall (some _t'66)
                  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                       tulong cc_default))
                  [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                (Stmt.Sassign (Expr.Evar ___a64_z tuchar)
                  (Expr.Ebinop Binop.Oand (Expr.Etempvar _t'66 tulong)
                    (Expr.Econst_int (Integers.Int.repr 1) tint) tulong)))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Scall (some _t'67)
                    (Expr.Evar _native_lab_entry_input (Ty.Tfunction 
                                                         [tuint] tulong
                                                         cc_default))
                    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                  (Stmt.Sassign (Expr.Evar ___a64_c tuchar)
                    (Expr.Ebinop Binop.Oand (Expr.Etempvar _t'67 tulong)
                      (Expr.Econst_int (Integers.Int.repr 1) tint) tulong)))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Scall (some _t'68)
                      (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                           [tuint] tulong
                                                           cc_default))
                      [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                    (Stmt.Sassign (Expr.Evar ___a64_v tuchar)
                      (Expr.Ebinop Binop.Oand (Expr.Etempvar _t'68 tulong)
                        (Expr.Econst_int (Integers.Int.repr 1) tint) tulong)))
                  (Stmt.Ssequence
                    (Stmt.Sassign (Expr.Evar ___a64_lr tulong)
                      (Expr.Econst_int (Integers.Int.repr 0) tint))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Scall (some _t'69)
                          (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                               [tuint] tulong
                                                               cc_default))
                          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                                (Expr.Econst_int (Integers.Int.repr 0) tint)
                                (tptr (Ty.Tstruct __2946 noattr)))
                              (Ty.Tstruct __2946 noattr)) _lo tulong)
                          (Expr.Etempvar _t'69 tulong)))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'70)
                            (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                 [tuint]
                                                                 tulong
                                                                 cc_default))
                            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                                  (Expr.Econst_int (Integers.Int.repr 0) tint)
                                  (tptr (Ty.Tstruct __2946 noattr)))
                                (Ty.Tstruct __2946 noattr)) _hi tulong)
                            (Expr.Etempvar _t'70 tulong)))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Scall (some _t'71)
                              (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                   [tuint]
                                                                   tulong
                                                                   cc_default))
                              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                                    (Expr.Econst_int (Integers.Int.repr 1) tint)
                                    (tptr (Ty.Tstruct __2946 noattr)))
                                  (Ty.Tstruct __2946 noattr)) _lo tulong)
                              (Expr.Etempvar _t'71 tulong)))
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Scall (some _t'72)
                                (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                    [tuint]
                                                                    tulong
                                                                    cc_default))
                                [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                                      (Expr.Econst_int (Integers.Int.repr 1) tint)
                                      (tptr (Ty.Tstruct __2946 noattr)))
                                    (Ty.Tstruct __2946 noattr)) _hi tulong)
                                (Expr.Etempvar _t'72 tulong)))
                            (Stmt.Ssequence
                              (Stmt.Ssequence
                                (Stmt.Scall (some _t'73)
                                  (Expr.Evar _native_lab_entry_input 
                                  (Ty.Tfunction [tuint] tulong cc_default))
                                  [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                                (Stmt.Sassign
                                  (Expr.Efield
                                    (Expr.Ederef
                                      (Expr.Ebinop Binop.Oadd
                                        (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                                        (Expr.Econst_int (Integers.Int.repr 2) tint)
                                        (tptr (Ty.Tstruct __2946 noattr)))
                                      (Ty.Tstruct __2946 noattr)) _lo tulong)
                                  (Expr.Etempvar _t'73 tulong)))
                              (Stmt.Ssequence
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_xdp_17
                                  (Stmt.Sassign
                                    (Expr.Efield
                                      (Expr.Ederef
                                        (Expr.Ebinop Binop.Oadd
                                          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __2946 noattr) 32))
                                          (Expr.Econst_int (Integers.Int.repr 2) tint)
                                          (tptr (Ty.Tstruct __2946 noattr)))
                                        (Ty.Tstruct __2946 noattr)) _hi
                                      tulong) (Expr.Etempvar _t'74 tulong)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_xdp_18
                                  s_kprog_arm64_entry_xdp_42)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_xdp_44 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
        (Expr.Econst_int (Integers.Int.repr 9) tint) (tptr (tptr tuchar)))
      (tptr tuchar))
    (Expr.Eaddrof (Expr.Evar ___a64_x9_tag tuchar) (tptr tuchar)))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
          (Expr.Econst_int (Integers.Int.repr 10) tint) (tptr (tptr tuchar)))
        (tptr tuchar))
      (Expr.Eaddrof (Expr.Evar ___a64_x10_tag tuchar) (tptr tuchar)))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
            (Expr.Econst_int (Integers.Int.repr 11) tint)
            (tptr (tptr tuchar))) (tptr tuchar))
        (Expr.Eaddrof (Expr.Evar ___a64_x11_tag tuchar) (tptr tuchar)))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
              (Expr.Econst_int (Integers.Int.repr 12) tint)
              (tptr (tptr tuchar))) (tptr tuchar))
          (Expr.Eaddrof (Expr.Evar ___a64_x12_tag tuchar) (tptr tuchar)))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                (Expr.Econst_int (Integers.Int.repr 13) tint)
                (tptr (tptr tuchar))) (tptr tuchar))
            (Expr.Eaddrof (Expr.Evar ___a64_x13_tag tuchar) (tptr tuchar)))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                  (Expr.Econst_int (Integers.Int.repr 14) tint)
                  (tptr (tptr tuchar))) (tptr tuchar))
              (Expr.Eaddrof (Expr.Evar ___a64_x14_tag tuchar) (tptr tuchar)))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                    (Expr.Econst_int (Integers.Int.repr 15) tint)
                    (tptr (tptr tuchar))) (tptr tuchar))
                (Expr.Eaddrof (Expr.Evar ___a64_x15_tag tuchar)
                  (tptr tuchar)))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                      (Expr.Econst_int (Integers.Int.repr 16) tint)
                      (tptr (tptr tuchar))) (tptr tuchar))
                  (Expr.Eaddrof (Expr.Evar ___a64_x16_tag tuchar)
                    (tptr tuchar)))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                        (Expr.Econst_int (Integers.Int.repr 17) tint)
                        (tptr (tptr tuchar))) (tptr tuchar))
                    (Expr.Eaddrof (Expr.Evar ___a64_x17_tag tuchar)
                      (tptr tuchar)))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                          (Expr.Econst_int (Integers.Int.repr 18) tint)
                          (tptr (tptr tuchar))) (tptr tuchar))
                      (Expr.Eaddrof (Expr.Evar ___a64_x18_tag tuchar)
                        (tptr tuchar)))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                            (Expr.Econst_int (Integers.Int.repr 19) tint)
                            (tptr (tptr tuchar))) (tptr tuchar))
                        (Expr.Eaddrof (Expr.Evar ___a64_x19_tag tuchar)
                          (tptr tuchar)))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                              (Expr.Econst_int (Integers.Int.repr 20) tint)
                              (tptr (tptr tuchar))) (tptr tuchar))
                          (Expr.Eaddrof (Expr.Evar ___a64_x20_tag tuchar)
                            (tptr tuchar)))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                (Expr.Econst_int (Integers.Int.repr 21) tint)
                                (tptr (tptr tuchar))) (tptr tuchar))
                            (Expr.Eaddrof (Expr.Evar ___a64_x21_tag tuchar)
                              (tptr tuchar)))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                  (Expr.Econst_int (Integers.Int.repr 22) tint)
                                  (tptr (tptr tuchar))) (tptr tuchar))
                              (Expr.Eaddrof (Expr.Evar ___a64_x22_tag tuchar)
                                (tptr tuchar)))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                    (Expr.Econst_int (Integers.Int.repr 23) tint)
                                    (tptr (tptr tuchar))) (tptr tuchar))
                                (Expr.Eaddrof
                                  (Expr.Evar ___a64_x23_tag tuchar)
                                  (tptr tuchar)))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                      (Expr.Econst_int (Integers.Int.repr 24) tint)
                                      (tptr (tptr tuchar))) (tptr tuchar))
                                  (Expr.Eaddrof
                                    (Expr.Evar ___a64_x24_tag tuchar)
                                    (tptr tuchar)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_xdp_16
                                  s_kprog_arm64_entry_xdp_43)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_xdp_45 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
        (Expr.Econst_int (Integers.Int.repr 23) tint)
        (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
      (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
    (Expr.Eaddrof (Expr.Evar ___a64_x23 (Ty.Tunion _arm64_sim_gpr noattr))
      (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
          (Expr.Econst_int (Integers.Int.repr 24) tint)
          (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
        (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
      (Expr.Eaddrof (Expr.Evar ___a64_x24 (Ty.Tunion _arm64_sim_gpr noattr))
        (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
            (Expr.Econst_int (Integers.Int.repr 25) tint)
            (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
          (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
        (Expr.Eaddrof
          (Expr.Evar ___a64_x25 (Ty.Tunion _arm64_sim_gpr noattr))
          (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
              (Expr.Econst_int (Integers.Int.repr 26) tint)
              (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
            (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
          (Expr.Eaddrof
            (Expr.Evar ___a64_x26 (Ty.Tunion _arm64_sim_gpr noattr))
            (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                (Expr.Econst_int (Integers.Int.repr 27) tint)
                (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
              (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
            (Expr.Eaddrof
              (Expr.Evar ___a64_x27 (Ty.Tunion _arm64_sim_gpr noattr))
              (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                  (Expr.Econst_int (Integers.Int.repr 28) tint)
                  (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
              (Expr.Eaddrof
                (Expr.Evar ___a64_x28 (Ty.Tunion _arm64_sim_gpr noattr))
                (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                    (Expr.Econst_int (Integers.Int.repr 29) tint)
                    (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                  (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                (Expr.Eaddrof
                  (Expr.Evar ___a64_x29 (Ty.Tunion _arm64_sim_gpr noattr))
                  (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                      (Expr.Econst_int (Integers.Int.repr 30) tint)
                      (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                    (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                  (Expr.Eaddrof
                    (Expr.Evar ___a64_x30 (Ty.Tunion _arm64_sim_gpr noattr))
                    (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                        (Expr.Econst_int (Integers.Int.repr 0) tint)
                        (tptr (tptr tuchar))) (tptr tuchar))
                    (Expr.Eaddrof (Expr.Evar ___a64_x0_tag tuchar)
                      (tptr tuchar)))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                          (Expr.Econst_int (Integers.Int.repr 1) tint)
                          (tptr (tptr tuchar))) (tptr tuchar))
                      (Expr.Eaddrof (Expr.Evar ___a64_x1_tag tuchar)
                        (tptr tuchar)))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                            (Expr.Econst_int (Integers.Int.repr 2) tint)
                            (tptr (tptr tuchar))) (tptr tuchar))
                        (Expr.Eaddrof (Expr.Evar ___a64_x2_tag tuchar)
                          (tptr tuchar)))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                              (Expr.Econst_int (Integers.Int.repr 3) tint)
                              (tptr (tptr tuchar))) (tptr tuchar))
                          (Expr.Eaddrof (Expr.Evar ___a64_x3_tag tuchar)
                            (tptr tuchar)))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                (Expr.Econst_int (Integers.Int.repr 4) tint)
                                (tptr (tptr tuchar))) (tptr tuchar))
                            (Expr.Eaddrof (Expr.Evar ___a64_x4_tag tuchar)
                              (tptr tuchar)))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                  (Expr.Econst_int (Integers.Int.repr 5) tint)
                                  (tptr (tptr tuchar))) (tptr tuchar))
                              (Expr.Eaddrof (Expr.Evar ___a64_x5_tag tuchar)
                                (tptr tuchar)))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                    (Expr.Econst_int (Integers.Int.repr 6) tint)
                                    (tptr (tptr tuchar))) (tptr tuchar))
                                (Expr.Eaddrof
                                  (Expr.Evar ___a64_x6_tag tuchar)
                                  (tptr tuchar)))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                      (Expr.Econst_int (Integers.Int.repr 7) tint)
                                      (tptr (tptr tuchar))) (tptr tuchar))
                                  (Expr.Eaddrof
                                    (Expr.Evar ___a64_x7_tag tuchar)
                                    (tptr tuchar)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_xdp_15
                                  s_kprog_arm64_entry_xdp_44)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_xdp_46 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
        (Expr.Econst_int (Integers.Int.repr 6) tint)
        (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
      (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
    (Expr.Eaddrof (Expr.Evar ___a64_x6 (Ty.Tunion _arm64_sim_gpr noattr))
      (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
          (Expr.Econst_int (Integers.Int.repr 7) tint)
          (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
        (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
      (Expr.Eaddrof (Expr.Evar ___a64_x7 (Ty.Tunion _arm64_sim_gpr noattr))
        (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
            (Expr.Econst_int (Integers.Int.repr 8) tint)
            (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
          (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
        (Expr.Eaddrof (Expr.Evar ___a64_x8 (Ty.Tunion _arm64_sim_gpr noattr))
          (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
              (Expr.Econst_int (Integers.Int.repr 9) tint)
              (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
            (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
          (Expr.Eaddrof
            (Expr.Evar ___a64_x9 (Ty.Tunion _arm64_sim_gpr noattr))
            (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                (Expr.Econst_int (Integers.Int.repr 10) tint)
                (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
              (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
            (Expr.Eaddrof
              (Expr.Evar ___a64_x10 (Ty.Tunion _arm64_sim_gpr noattr))
              (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                  (Expr.Econst_int (Integers.Int.repr 11) tint)
                  (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
              (Expr.Eaddrof
                (Expr.Evar ___a64_x11 (Ty.Tunion _arm64_sim_gpr noattr))
                (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                    (Expr.Econst_int (Integers.Int.repr 12) tint)
                    (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                  (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                (Expr.Eaddrof
                  (Expr.Evar ___a64_x12 (Ty.Tunion _arm64_sim_gpr noattr))
                  (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                      (Expr.Econst_int (Integers.Int.repr 13) tint)
                      (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                    (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                  (Expr.Eaddrof
                    (Expr.Evar ___a64_x13 (Ty.Tunion _arm64_sim_gpr noattr))
                    (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                        (Expr.Econst_int (Integers.Int.repr 14) tint)
                        (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                      (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                    (Expr.Eaddrof
                      (Expr.Evar ___a64_x14 (Ty.Tunion _arm64_sim_gpr noattr))
                      (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                          (Expr.Econst_int (Integers.Int.repr 15) tint)
                          (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                        (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                      (Expr.Eaddrof
                        (Expr.Evar ___a64_x15 (Ty.Tunion _arm64_sim_gpr noattr))
                        (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                            (Expr.Econst_int (Integers.Int.repr 16) tint)
                            (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                          (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                        (Expr.Eaddrof
                          (Expr.Evar ___a64_x16 (Ty.Tunion _arm64_sim_gpr noattr))
                          (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                              (Expr.Econst_int (Integers.Int.repr 17) tint)
                              (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                            (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                          (Expr.Eaddrof
                            (Expr.Evar ___a64_x17 (Ty.Tunion _arm64_sim_gpr noattr))
                            (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                (Expr.Econst_int (Integers.Int.repr 18) tint)
                                (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                              (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                            (Expr.Eaddrof
                              (Expr.Evar ___a64_x18 (Ty.Tunion _arm64_sim_gpr noattr))
                              (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                  (Expr.Econst_int (Integers.Int.repr 19) tint)
                                  (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                              (Expr.Eaddrof
                                (Expr.Evar ___a64_x19 (Ty.Tunion _arm64_sim_gpr noattr))
                                (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                    (Expr.Econst_int (Integers.Int.repr 20) tint)
                                    (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                  (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                                (Expr.Eaddrof
                                  (Expr.Evar ___a64_x20 (Ty.Tunion _arm64_sim_gpr noattr))
                                  (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                      (Expr.Econst_int (Integers.Int.repr 21) tint)
                                      (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                    (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                                  (Expr.Eaddrof
                                    (Expr.Evar ___a64_x21 (Ty.Tunion _arm64_sim_gpr noattr))
                                    (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_xdp_14
                                  s_kprog_arm64_entry_xdp_45)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_xdp_47 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign (Expr.Evar ___a64_x25_tag tuchar)
    (Expr.Econst_int (Integers.Int.repr 0) tuint))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                          (Expr.Econst_int (Integers.Int.repr 26) tuint)
                          (Expr.Econst_int (Integers.Int.repr 30) tuint)
                          tint)
        (Stmt.Sset _t'55
          (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong)
            tulong))
        (Stmt.Ssequence
          (Stmt.Scall (some _t'56)
            (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                 cc_default))
            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
          (Stmt.Sset _t'55 (Expr.Ecast (Expr.Etempvar _t'56 tulong) tulong))))
      (Stmt.Sassign
        (Expr.Efield (Expr.Evar ___a64_x26 (Ty.Tunion _arm64_sim_gpr noattr))
          _x tulong) (Expr.Etempvar _t'55 tulong)))
    (Stmt.Ssequence
      (Stmt.Sassign (Expr.Evar ___a64_x26_tag tuchar)
        (Expr.Econst_int (Integers.Int.repr 0) tuint))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Econst_int (Integers.Int.repr 27) tuint)
                              (Expr.Econst_int (Integers.Int.repr 30) tuint)
                              tint)
            (Stmt.Sset _t'57
              (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                tulong))
            (Stmt.Ssequence
              (Stmt.Scall (some _t'58)
                (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                     tulong cc_default))
                [(Expr.Econst_int (Integers.Int.repr 6) tint)])
              (Stmt.Sset _t'57
                (Expr.Ecast (Expr.Etempvar _t'58 tulong) tulong))))
          (Stmt.Sassign
            (Expr.Efield
              (Expr.Evar ___a64_x27 (Ty.Tunion _arm64_sim_gpr noattr)) _x
              tulong) (Expr.Etempvar _t'57 tulong)))
        (Stmt.Ssequence
          (Stmt.Sassign (Expr.Evar ___a64_x27_tag tuchar)
            (Expr.Econst_int (Integers.Int.repr 0) tuint))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Econst_int (Integers.Int.repr 28) tuint)
                                  (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                  tint)
                (Stmt.Sset _t'59
                  (Expr.Ecast
                    (Expr.Econst_long (Integers.Int64.repr 0) tulong) tulong))
                (Stmt.Ssequence
                  (Stmt.Scall (some _t'60)
                    (Expr.Evar _native_lab_entry_input (Ty.Tfunction 
                                                         [tuint] tulong
                                                         cc_default))
                    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                  (Stmt.Sset _t'59
                    (Expr.Ecast (Expr.Etempvar _t'60 tulong) tulong))))
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Evar ___a64_x28 (Ty.Tunion _arm64_sim_gpr noattr)) _x
                  tulong) (Expr.Etempvar _t'59 tulong)))
            (Stmt.Ssequence
              (Stmt.Sassign (Expr.Evar ___a64_x28_tag tuchar)
                (Expr.Econst_int (Integers.Int.repr 0) tuint))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Econst_int (Integers.Int.repr 29) tuint)
                                      (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                      tint)
                    (Stmt.Sset _t'61
                      (Expr.Ecast
                        (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                        tulong))
                    (Stmt.Ssequence
                      (Stmt.Scall (some _t'62)
                        (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                             [tuint] tulong
                                                             cc_default))
                        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                      (Stmt.Sset _t'61
                        (Expr.Ecast (Expr.Etempvar _t'62 tulong) tulong))))
                  (Stmt.Sassign
                    (Expr.Efield
                      (Expr.Evar ___a64_x29 (Ty.Tunion _arm64_sim_gpr noattr))
                      _x tulong) (Expr.Etempvar _t'61 tulong)))
                (Stmt.Ssequence
                  (Stmt.Sassign (Expr.Evar ___a64_x29_tag tuchar)
                    (Expr.Econst_int (Integers.Int.repr 0) tuint))
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                          (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                          tint)
                        (Stmt.Sset _t'63
                          (Expr.Ecast
                            (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                            tulong))
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'64)
                            (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                 [tuint]
                                                                 tulong
                                                                 cc_default))
                            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                          (Stmt.Sset _t'63
                            (Expr.Ecast (Expr.Etempvar _t'64 tulong) tulong))))
                      (Stmt.Sassign
                        (Expr.Efield
                          (Expr.Evar ___a64_x30 (Ty.Tunion _arm64_sim_gpr noattr))
                          _x tulong) (Expr.Etempvar _t'63 tulong)))
                    (Stmt.Ssequence
                      (Stmt.Sassign (Expr.Evar ___a64_x30_tag tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tuint))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                              (Expr.Econst_int (Integers.Int.repr 0) tint)
                              (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                            (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                          (Expr.Eaddrof
                            (Expr.Evar ___a64_x0 (Ty.Tunion _arm64_sim_gpr noattr))
                            (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                (Expr.Econst_int (Integers.Int.repr 1) tint)
                                (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                              (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                            (Expr.Eaddrof
                              (Expr.Evar ___a64_x1 (Ty.Tunion _arm64_sim_gpr noattr))
                              (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                  (Expr.Econst_int (Integers.Int.repr 2) tint)
                                  (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                              (Expr.Eaddrof
                                (Expr.Evar ___a64_x2 (Ty.Tunion _arm64_sim_gpr noattr))
                                (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                    (Expr.Econst_int (Integers.Int.repr 3) tint)
                                    (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                  (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                                (Expr.Eaddrof
                                  (Expr.Evar ___a64_x3 (Ty.Tunion _arm64_sim_gpr noattr))
                                  (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                      (Expr.Econst_int (Integers.Int.repr 4) tint)
                                      (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                    (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                                  (Expr.Eaddrof
                                    (Expr.Evar ___a64_x4 (Ty.Tunion _arm64_sim_gpr noattr))
                                    (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_xdp_13
                                  s_kprog_arm64_entry_xdp_46)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_xdp_48 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                        (Expr.Econst_int (Integers.Int.repr 17) tuint)
                        (Expr.Econst_int (Integers.Int.repr 30) tuint) tint)
      (Stmt.Sset _t'37
        (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong) tulong))
      (Stmt.Ssequence
        (Stmt.Scall (some _t'38)
          (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                               cc_default))
          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
        (Stmt.Sset _t'37 (Expr.Ecast (Expr.Etempvar _t'38 tulong) tulong))))
    (Stmt.Sassign
      (Expr.Efield (Expr.Evar ___a64_x17 (Ty.Tunion _arm64_sim_gpr noattr))
        _x tulong) (Expr.Etempvar _t'37 tulong)))
  (Stmt.Ssequence
    (Stmt.Sassign (Expr.Evar ___a64_x17_tag tuchar)
      (Expr.Econst_int (Integers.Int.repr 0) tuint))
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Econst_int (Integers.Int.repr 18) tuint)
                            (Expr.Econst_int (Integers.Int.repr 30) tuint)
                            tint)
          (Stmt.Sset _t'39
            (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong)
              tulong))
          (Stmt.Ssequence
            (Stmt.Scall (some _t'40)
              (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                   cc_default))
              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
            (Stmt.Sset _t'39
              (Expr.Ecast (Expr.Etempvar _t'40 tulong) tulong))))
        (Stmt.Sassign
          (Expr.Efield
            (Expr.Evar ___a64_x18 (Ty.Tunion _arm64_sim_gpr noattr)) _x
            tulong) (Expr.Etempvar _t'39 tulong)))
      (Stmt.Ssequence
        (Stmt.Sassign (Expr.Evar ___a64_x18_tag tuchar)
          (Expr.Econst_int (Integers.Int.repr 0) tuint))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Econst_int (Integers.Int.repr 19) tuint)
                                (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                tint)
              (Stmt.Sset _t'41
                (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                  tulong))
              (Stmt.Ssequence
                (Stmt.Scall (some _t'42)
                  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                       tulong cc_default))
                  [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                (Stmt.Sset _t'41
                  (Expr.Ecast (Expr.Etempvar _t'42 tulong) tulong))))
            (Stmt.Sassign
              (Expr.Efield
                (Expr.Evar ___a64_x19 (Ty.Tunion _arm64_sim_gpr noattr)) _x
                tulong) (Expr.Etempvar _t'41 tulong)))
          (Stmt.Ssequence
            (Stmt.Sassign (Expr.Evar ___a64_x19_tag tuchar)
              (Expr.Econst_int (Integers.Int.repr 0) tuint))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Econst_int (Integers.Int.repr 20) tuint)
                                    (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                    tint)
                  (Stmt.Sset _t'43
                    (Expr.Ecast
                      (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                      tulong))
                  (Stmt.Ssequence
                    (Stmt.Scall (some _t'44)
                      (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                           [tuint] tulong
                                                           cc_default))
                      [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                    (Stmt.Sset _t'43
                      (Expr.Ecast (Expr.Etempvar _t'44 tulong) tulong))))
                (Stmt.Sassign
                  (Expr.Efield
                    (Expr.Evar ___a64_x20 (Ty.Tunion _arm64_sim_gpr noattr))
                    _x tulong) (Expr.Etempvar _t'43 tulong)))
              (Stmt.Ssequence
                (Stmt.Sassign (Expr.Evar ___a64_x20_tag tuchar)
                  (Expr.Econst_int (Integers.Int.repr 0) tuint))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Econst_int (Integers.Int.repr 21) tuint)
                                        (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                        tint)
                      (Stmt.Sset _t'45
                        (Expr.Ecast
                          (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                          tulong))
                      (Stmt.Ssequence
                        (Stmt.Scall (some _t'46)
                          (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                               [tuint] tulong
                                                               cc_default))
                          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                        (Stmt.Sset _t'45
                          (Expr.Ecast (Expr.Etempvar _t'46 tulong) tulong))))
                    (Stmt.Sassign
                      (Expr.Efield
                        (Expr.Evar ___a64_x21 (Ty.Tunion _arm64_sim_gpr noattr))
                        _x tulong) (Expr.Etempvar _t'45 tulong)))
                  (Stmt.Ssequence
                    (Stmt.Sassign (Expr.Evar ___a64_x21_tag tuchar)
                      (Expr.Econst_int (Integers.Int.repr 0) tuint))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Econst_int (Integers.Int.repr 22) tuint)
                                            (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                            tint)
                          (Stmt.Sset _t'47
                            (Expr.Ecast
                              (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                              tulong))
                          (Stmt.Ssequence
                            (Stmt.Scall (some _t'48)
                              (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                   [tuint]
                                                                   tulong
                                                                   cc_default))
                              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                            (Stmt.Sset _t'47
                              (Expr.Ecast (Expr.Etempvar _t'48 tulong)
                                tulong))))
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Evar ___a64_x22 (Ty.Tunion _arm64_sim_gpr noattr))
                            _x tulong) (Expr.Etempvar _t'47 tulong)))
                      (Stmt.Ssequence
                        (Stmt.Sassign (Expr.Evar ___a64_x22_tag tuchar)
                          (Expr.Econst_int (Integers.Int.repr 0) tuint))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                (Expr.Econst_int (Integers.Int.repr 23) tuint)
                                                (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                                tint)
                              (Stmt.Sset _t'49
                                (Expr.Ecast
                                  (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                                  tulong))
                              (Stmt.Ssequence
                                s_kprog_arm64_entry_xdp_9
                                (Stmt.Sset _t'49
                                  (Expr.Ecast (Expr.Etempvar _t'50 tulong)
                                    tulong))))
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Evar ___a64_x23 (Ty.Tunion _arm64_sim_gpr noattr))
                                _x tulong) (Expr.Etempvar _t'49 tulong)))
                          (Stmt.Ssequence
                            (Stmt.Sassign (Expr.Evar ___a64_x23_tag tuchar)
                              (Expr.Econst_int (Integers.Int.repr 0) tuint))
                            (Stmt.Ssequence
                              (Stmt.Ssequence
                                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                    (Expr.Econst_int (Integers.Int.repr 24) tuint)
                                                    (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                                    tint)
                                  s_kprog_arm64_entry_xdp_10
                                  s_kprog_arm64_entry_xdp_11)
                                (Stmt.Sassign
                                  (Expr.Efield
                                    (Expr.Evar ___a64_x24 (Ty.Tunion _arm64_sim_gpr noattr))
                                    _x tulong) (Expr.Etempvar _t'51 tulong)))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Evar ___a64_x24_tag tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 0) tuint))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_xdp_12
                                  s_kprog_arm64_entry_xdp_47)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_xdp_49 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign (Expr.Evar ___a64_x8_tag tuchar)
    (Expr.Econst_int (Integers.Int.repr 0) tuint))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                          (Expr.Econst_int (Integers.Int.repr 9) tuint)
                          (Expr.Econst_int (Integers.Int.repr 30) tuint)
                          tint)
        (Stmt.Sset _t'21
          (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong)
            tulong))
        (Stmt.Ssequence
          (Stmt.Scall (some _t'22)
            (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                 cc_default))
            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
          (Stmt.Sset _t'21 (Expr.Ecast (Expr.Etempvar _t'22 tulong) tulong))))
      (Stmt.Sassign
        (Expr.Efield (Expr.Evar ___a64_x9 (Ty.Tunion _arm64_sim_gpr noattr))
          _x tulong) (Expr.Etempvar _t'21 tulong)))
    (Stmt.Ssequence
      (Stmt.Sassign (Expr.Evar ___a64_x9_tag tuchar)
        (Expr.Econst_int (Integers.Int.repr 0) tuint))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Econst_int (Integers.Int.repr 10) tuint)
                              (Expr.Econst_int (Integers.Int.repr 30) tuint)
                              tint)
            (Stmt.Sset _t'23
              (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                tulong))
            (Stmt.Ssequence
              (Stmt.Scall (some _t'24)
                (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                     tulong cc_default))
                [(Expr.Econst_int (Integers.Int.repr 6) tint)])
              (Stmt.Sset _t'23
                (Expr.Ecast (Expr.Etempvar _t'24 tulong) tulong))))
          (Stmt.Sassign
            (Expr.Efield
              (Expr.Evar ___a64_x10 (Ty.Tunion _arm64_sim_gpr noattr)) _x
              tulong) (Expr.Etempvar _t'23 tulong)))
        (Stmt.Ssequence
          (Stmt.Sassign (Expr.Evar ___a64_x10_tag tuchar)
            (Expr.Econst_int (Integers.Int.repr 0) tuint))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Econst_int (Integers.Int.repr 11) tuint)
                                  (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                  tint)
                (Stmt.Sset _t'25
                  (Expr.Ecast
                    (Expr.Econst_long (Integers.Int64.repr 0) tulong) tulong))
                (Stmt.Ssequence
                  (Stmt.Scall (some _t'26)
                    (Expr.Evar _native_lab_entry_input (Ty.Tfunction 
                                                         [tuint] tulong
                                                         cc_default))
                    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                  (Stmt.Sset _t'25
                    (Expr.Ecast (Expr.Etempvar _t'26 tulong) tulong))))
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Evar ___a64_x11 (Ty.Tunion _arm64_sim_gpr noattr)) _x
                  tulong) (Expr.Etempvar _t'25 tulong)))
            (Stmt.Ssequence
              (Stmt.Sassign (Expr.Evar ___a64_x11_tag tuchar)
                (Expr.Econst_int (Integers.Int.repr 0) tuint))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Econst_int (Integers.Int.repr 12) tuint)
                                      (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                      tint)
                    (Stmt.Sset _t'27
                      (Expr.Ecast
                        (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                        tulong))
                    (Stmt.Ssequence
                      (Stmt.Scall (some _t'28)
                        (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                             [tuint] tulong
                                                             cc_default))
                        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                      (Stmt.Sset _t'27
                        (Expr.Ecast (Expr.Etempvar _t'28 tulong) tulong))))
                  (Stmt.Sassign
                    (Expr.Efield
                      (Expr.Evar ___a64_x12 (Ty.Tunion _arm64_sim_gpr noattr))
                      _x tulong) (Expr.Etempvar _t'27 tulong)))
                (Stmt.Ssequence
                  (Stmt.Sassign (Expr.Evar ___a64_x12_tag tuchar)
                    (Expr.Econst_int (Integers.Int.repr 0) tuint))
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Econst_int (Integers.Int.repr 13) tuint)
                                          (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                          tint)
                        (Stmt.Sset _t'29
                          (Expr.Ecast
                            (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                            tulong))
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'30)
                            (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                 [tuint]
                                                                 tulong
                                                                 cc_default))
                            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                          (Stmt.Sset _t'29
                            (Expr.Ecast (Expr.Etempvar _t'30 tulong) tulong))))
                      (Stmt.Sassign
                        (Expr.Efield
                          (Expr.Evar ___a64_x13 (Ty.Tunion _arm64_sim_gpr noattr))
                          _x tulong) (Expr.Etempvar _t'29 tulong)))
                    (Stmt.Ssequence
                      (Stmt.Sassign (Expr.Evar ___a64_x13_tag tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tuint))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Econst_int (Integers.Int.repr 14) tuint)
                                              (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                              tint)
                            (Stmt.Sset _t'31
                              (Expr.Ecast
                                (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                                tulong))
                            (Stmt.Ssequence
                              (Stmt.Scall (some _t'32)
                                (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                    [tuint]
                                                                    tulong
                                                                    cc_default))
                                [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                              (Stmt.Sset _t'31
                                (Expr.Ecast (Expr.Etempvar _t'32 tulong)
                                  tulong))))
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Evar ___a64_x14 (Ty.Tunion _arm64_sim_gpr noattr))
                              _x tulong) (Expr.Etempvar _t'31 tulong)))
                        (Stmt.Ssequence
                          (Stmt.Sassign (Expr.Evar ___a64_x14_tag tuchar)
                            (Expr.Econst_int (Integers.Int.repr 0) tuint))
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                  (Expr.Econst_int (Integers.Int.repr 15) tuint)
                                                  (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                                  tint)
                                s_kprog_arm64_entry_xdp_5
                                s_kprog_arm64_entry_xdp_6)
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Evar ___a64_x15 (Ty.Tunion _arm64_sim_gpr noattr))
                                  _x tulong) (Expr.Etempvar _t'33 tulong)))
                            (Stmt.Ssequence
                              (Stmt.Sassign (Expr.Evar ___a64_x15_tag tuchar)
                                (Expr.Econst_int (Integers.Int.repr 0) tuint))
                              (Stmt.Ssequence
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_xdp_7
                                  (Stmt.Sassign
                                    (Expr.Efield
                                      (Expr.Evar ___a64_x16 (Ty.Tunion _arm64_sim_gpr noattr))
                                      _x tulong)
                                    (Expr.Etempvar _t'35 tulong)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_xdp_8
                                  s_kprog_arm64_entry_xdp_48)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_xdp_50 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                        (Expr.Econst_int (Integers.Int.repr 0) tuint)
                        (Expr.Econst_int (Integers.Int.repr 30) tuint) tint)
      (Stmt.Sset _t'3
        (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong) tulong))
      (Stmt.Ssequence
        (Stmt.Scall (some _t'4)
          (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                               cc_default))
          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
        (Stmt.Sset _t'3 (Expr.Ecast (Expr.Etempvar _t'4 tulong) tulong))))
    (Stmt.Sassign
      (Expr.Efield (Expr.Evar ___a64_x0 (Ty.Tunion _arm64_sim_gpr noattr)) _x
        tulong) (Expr.Etempvar _t'3 tulong)))
  (Stmt.Ssequence
    (Stmt.Sassign (Expr.Evar ___a64_x0_tag tuchar)
      (Expr.Econst_int (Integers.Int.repr 0) tuint))
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Econst_int (Integers.Int.repr 1) tuint)
                            (Expr.Econst_int (Integers.Int.repr 30) tuint)
                            tint)
          (Stmt.Sset _t'5
            (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong)
              tulong))
          (Stmt.Ssequence
            (Stmt.Scall (some _t'6)
              (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                   cc_default))
              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
            (Stmt.Sset _t'5 (Expr.Ecast (Expr.Etempvar _t'6 tulong) tulong))))
        (Stmt.Sassign
          (Expr.Efield
            (Expr.Evar ___a64_x1 (Ty.Tunion _arm64_sim_gpr noattr)) _x
            tulong) (Expr.Etempvar _t'5 tulong)))
      (Stmt.Ssequence
        (Stmt.Sassign (Expr.Evar ___a64_x1_tag tuchar)
          (Expr.Econst_int (Integers.Int.repr 0) tuint))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                tint)
              (Stmt.Sset _t'7
                (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                  tulong))
              (Stmt.Ssequence
                (Stmt.Scall (some _t'8)
                  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                       tulong cc_default))
                  [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                (Stmt.Sset _t'7
                  (Expr.Ecast (Expr.Etempvar _t'8 tulong) tulong))))
            (Stmt.Sassign
              (Expr.Efield
                (Expr.Evar ___a64_x2 (Ty.Tunion _arm64_sim_gpr noattr)) _x
                tulong) (Expr.Etempvar _t'7 tulong)))
          (Stmt.Ssequence
            (Stmt.Sassign (Expr.Evar ___a64_x2_tag tuchar)
              (Expr.Econst_int (Integers.Int.repr 0) tuint))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Econst_int (Integers.Int.repr 3) tuint)
                                    (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                    tint)
                  (Stmt.Sset _t'9
                    (Expr.Ecast
                      (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                      tulong))
                  (Stmt.Ssequence
                    (Stmt.Scall (some _t'10)
                      (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                           [tuint] tulong
                                                           cc_default))
                      [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                    (Stmt.Sset _t'9
                      (Expr.Ecast (Expr.Etempvar _t'10 tulong) tulong))))
                (Stmt.Sassign
                  (Expr.Efield
                    (Expr.Evar ___a64_x3 (Ty.Tunion _arm64_sim_gpr noattr))
                    _x tulong) (Expr.Etempvar _t'9 tulong)))
              (Stmt.Ssequence
                (Stmt.Sassign (Expr.Evar ___a64_x3_tag tuchar)
                  (Expr.Econst_int (Integers.Int.repr 0) tuint))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                        (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                        tint)
                      (Stmt.Sset _t'11
                        (Expr.Ecast
                          (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                          tulong))
                      (Stmt.Ssequence
                        (Stmt.Scall (some _t'12)
                          (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                               [tuint] tulong
                                                               cc_default))
                          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                        (Stmt.Sset _t'11
                          (Expr.Ecast (Expr.Etempvar _t'12 tulong) tulong))))
                    (Stmt.Sassign
                      (Expr.Efield
                        (Expr.Evar ___a64_x4 (Ty.Tunion _arm64_sim_gpr noattr))
                        _x tulong) (Expr.Etempvar _t'11 tulong)))
                  (Stmt.Ssequence
                    (Stmt.Sassign (Expr.Evar ___a64_x4_tag tuchar)
                      (Expr.Econst_int (Integers.Int.repr 0) tuint))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Econst_int (Integers.Int.repr 5) tuint)
                                            (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                            tint)
                          (Stmt.Sset _t'13
                            (Expr.Ecast
                              (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                              tulong))
                          (Stmt.Ssequence
                            (Stmt.Scall (some _t'14)
                              (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                   [tuint]
                                                                   tulong
                                                                   cc_default))
                              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                            (Stmt.Sset _t'13
                              (Expr.Ecast (Expr.Etempvar _t'14 tulong)
                                tulong))))
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Evar ___a64_x5 (Ty.Tunion _arm64_sim_gpr noattr))
                            _x tulong) (Expr.Etempvar _t'13 tulong)))
                      (Stmt.Ssequence
                        (Stmt.Sassign (Expr.Evar ___a64_x5_tag tuchar)
                          (Expr.Econst_int (Integers.Int.repr 0) tuint))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                (Expr.Econst_int (Integers.Int.repr 6) tuint)
                                                (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                                tint)
                              (Stmt.Sset _t'15
                                (Expr.Ecast
                                  (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                                  tulong))
                              (Stmt.Ssequence
                                s_kprog_arm64_entry_xdp_1
                                (Stmt.Sset _t'15
                                  (Expr.Ecast (Expr.Etempvar _t'16 tulong)
                                    tulong))))
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Evar ___a64_x6 (Ty.Tunion _arm64_sim_gpr noattr))
                                _x tulong) (Expr.Etempvar _t'15 tulong)))
                          (Stmt.Ssequence
                            (Stmt.Sassign (Expr.Evar ___a64_x6_tag tuchar)
                              (Expr.Econst_int (Integers.Int.repr 0) tuint))
                            (Stmt.Ssequence
                              (Stmt.Ssequence
                                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                    (Expr.Econst_int (Integers.Int.repr 7) tuint)
                                                    (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                                    tint)
                                  s_kprog_arm64_entry_xdp_2
                                  s_kprog_arm64_entry_xdp_3)
                                (Stmt.Sassign
                                  (Expr.Efield
                                    (Expr.Evar ___a64_x7 (Ty.Tunion _arm64_sim_gpr noattr))
                                    _x tulong) (Expr.Etempvar _t'17 tulong)))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Evar ___a64_x7_tag tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 0) tuint))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_xdp_4
                                  s_kprog_arm64_entry_xdp_49)))))))))))))))))

@[noinline] def l_kprog_arm64_entry_xdp_temps_0 : List (Ident × Ty) :=
[(_i, tuint), (_t'133, tuint), (_t'132, tulong), (_t'131, tulong),
 (_t'130, tulong), (_t'129, tulong), (_t'128, tulong), (_t'127, tulong),
 (_t'126, tulong), (_t'125, tulong), (_t'124, tulong), (_t'123, tulong),
 (_t'122, tulong), (_t'121, tulong), (_t'120, tulong), (_t'119, tulong),
 (_t'118, tulong), (_t'117, tulong), (_t'116, tulong), (_t'115, tulong),
 (_t'114, tulong), (_t'113, tulong), (_t'112, tulong), (_t'111, tulong),
 (_t'110, tulong), (_t'109, tulong), (_t'108, tulong), (_t'107, tulong),
 (_t'106, tulong), (_t'105, tulong), (_t'104, tulong), (_t'103, tulong),
 (_t'102, tulong), (_t'101, tulong), (_t'100, tulong), (_t'99, tulong),
 (_t'98, tulong), (_t'97, tulong), (_t'96, tulong), (_t'95, tulong),
 (_t'94, tulong), (_t'93, tulong), (_t'92, tulong), (_t'91, tulong),
 (_t'90, tulong), (_t'89, tulong), (_t'88, tulong), (_t'87, tulong),
 (_t'86, tulong), (_t'85, tulong), (_t'84, tulong), (_t'83, tulong),
 (_t'82, tulong), (_t'81, tulong), (_t'80, tulong), (_t'79, tulong),
 (_t'78, tulong), (_t'77, tulong), (_t'76, tulong), (_t'75, tulong),
 (_t'74, tulong), (_t'73, tulong), (_t'72, tulong), (_t'71, tulong),
 (_t'70, tulong), (_t'69, tulong), (_t'68, tulong)]

@[noinline] def l_kprog_arm64_entry_xdp_temps_1 : List (Ident × Ty) :=
[(_t'67, tulong), (_t'66, tulong), (_t'65, tulong), (_t'64, tulong),
 (_t'63, tulong), (_t'62, tulong), (_t'61, tulong), (_t'60, tulong),
 (_t'59, tulong), (_t'58, tulong), (_t'57, tulong), (_t'56, tulong),
 (_t'55, tulong), (_t'54, tulong), (_t'53, tulong), (_t'52, tulong),
 (_t'51, tulong), (_t'50, tulong), (_t'49, tulong), (_t'48, tulong),
 (_t'47, tulong), (_t'46, tulong), (_t'45, tulong), (_t'44, tulong),
 (_t'43, tulong), (_t'42, tulong), (_t'41, tulong), (_t'40, tulong),
 (_t'39, tulong), (_t'38, tulong), (_t'37, tulong), (_t'36, tulong),
 (_t'35, tulong), (_t'34, tulong), (_t'33, tulong), (_t'32, tulong),
 (_t'31, tulong), (_t'30, tulong), (_t'29, tulong), (_t'28, tulong),
 (_t'27, tulong), (_t'26, tulong), (_t'25, tulong), (_t'24, tulong),
 (_t'23, tulong), (_t'22, tulong), (_t'21, tulong), (_t'20, tulong),
 (_t'19, tulong), (_t'18, tulong), (_t'17, tulong), (_t'16, tulong),
 (_t'15, tulong), (_t'14, tulong), (_t'13, tulong), (_t'12, tulong),
 (_t'11, tulong), (_t'10, tulong), (_t'9, tulong), (_t'8, tulong),
 (_t'7, tulong), (_t'6, tulong), (_t'5, tulong), (_t'4, tulong),
 (_t'3, tulong), (_t'2, (tptr tvoid)), (_t'1, (tptr tvoid))]

def f_kprog_arm64_entry_xdp : Function := {
  fn_return := tuint,
  fn_callconv := cc_default,
  fn_params := [(_ctx, (tptr (Ty.Tstruct _xdp_md noattr))),
                (_continuation,
                 (tptr (Ty.Tfunction
                         [(tptr (Ty.Tstruct _kprog_arm64_entry noattr))]
                         tuint cc_default)))],
  fn_vars := [(___a64_sim_abi, (Ty.Tstruct _arm64_sim_xdp_abi noattr)),
              (___a64_sim_skb_ctx, (tptr (Ty.Tstruct ___sk_buff noattr))),
              (___a64_sim_abi_kind, tuchar), (___a64_numeric_sp, tulong),
              (___a64_numeric_return, tulong),
              (___a64_numeric_sp_valid, tuchar),
              (___a64_numeric_return_valid, tuchar),
              (___a64_sim_is_xdp, tuchar),
              (___a64_sim_helper_ctx, (tptr tvoid)),
              (___a64_sim_helper_abi_base, (tptr tvoid)),
              (___a64_x0, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x0_tag, tuchar),
              (___a64_x1, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x1_tag, tuchar),
              (___a64_x2, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x2_tag, tuchar),
              (___a64_x3, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x3_tag, tuchar),
              (___a64_x4, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x4_tag, tuchar),
              (___a64_x5, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x5_tag, tuchar),
              (___a64_x6, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x6_tag, tuchar),
              (___a64_x7, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x7_tag, tuchar),
              (___a64_x8, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x8_tag, tuchar),
              (___a64_x9, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x9_tag, tuchar),
              (___a64_x10, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x10_tag, tuchar),
              (___a64_x11, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x11_tag, tuchar),
              (___a64_x12, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x12_tag, tuchar),
              (___a64_x13, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x13_tag, tuchar),
              (___a64_x14, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x14_tag, tuchar),
              (___a64_x15, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x15_tag, tuchar),
              (___a64_x16, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x16_tag, tuchar),
              (___a64_x17, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x17_tag, tuchar),
              (___a64_x18, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x18_tag, tuchar),
              (___a64_x19, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x19_tag, tuchar),
              (___a64_x20, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x20_tag, tuchar),
              (___a64_x21, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x21_tag, tuchar),
              (___a64_x22, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x22_tag, tuchar),
              (___a64_x23, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x23_tag, tuchar),
              (___a64_x24, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x24_tag, tuchar),
              (___a64_x25, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x25_tag, tuchar),
              (___a64_x26, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x26_tag, tuchar),
              (___a64_x27, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x27_tag, tuchar),
              (___a64_x28, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x28_tag, tuchar),
              (___a64_x29, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x29_tag, tuchar),
              (___a64_x30, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x30_tag, tuchar),
              (___a64_cells,
               (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31)),
              (___a64_tag_cells, (tarray (tptr tuchar) 31)),
              (___a64_n, tuchar), (___a64_z, tuchar), (___a64_c, tuchar),
              (___a64_v, tuchar), (___a64_lr, tulong),
              (___a64_vectors, (tarray (Ty.Tstruct __2946 noattr) 32)),
              (___a64_stack, (tvolatile (Ty.Tunion __2948 noattr))),
              (___a64_stack_payload, (tarray (tvolatile tulong) 20)),
              (___a64_stack_tag, (tarray tuchar 24)), (___a64_sp, tlong),
              (_entry, (Ty.Tstruct _kprog_arm64_entry noattr))],
  fn_temps := (l_kprog_arm64_entry_xdp_temps_0 ++ l_kprog_arm64_entry_xdp_temps_1),
  fn_body :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Scall (some _t'1)
      (Expr.Evar _kprog_c_context_pointer (Ty.Tfunction
                                            [(tptr tvoid), tuchar, tuint]
                                            (tptr tvoid) cc_default))
      [(Expr.Etempvar _ctx (tptr (Ty.Tstruct _xdp_md noattr))),
       (Expr.Econst_int (Integers.Int.repr 0) tuint),
       (Expr.Econst_long (Integers.Int64.repr 0) tulong)])
    (Stmt.Sassign
      (Expr.Efield
        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_xdp_abi noattr))
        _data (tptr tvoid)) (Expr.Etempvar _t'1 (tptr tvoid))))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Scall (some _t'2)
        (Expr.Evar _kprog_c_context_pointer (Ty.Tfunction
                                              [(tptr tvoid), tuchar, tuint]
                                              (tptr tvoid) cc_default))
        [(Expr.Etempvar _ctx (tptr (Ty.Tstruct _xdp_md noattr))),
         (Expr.Econst_int (Integers.Int.repr 0) tuint),
         (Expr.Econst_long (Integers.Int64.repr 4) tulong)])
      (Stmt.Sassign
        (Expr.Efield
          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_xdp_abi noattr))
          _data_end (tptr tvoid)) (Expr.Etempvar _t'2 (tptr tvoid))))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_xdp_abi noattr))
              _cb (tarray tuint 5))
            (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tuint)) tuint)
        (Expr.Econst_int (Integers.Int.repr 0) tint))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_xdp_abi noattr))
                _cb (tarray tuint 5))
              (Expr.Econst_int (Integers.Int.repr 1) tint) (tptr tuint))
            tuint) (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_xdp_abi noattr))
                  _cb (tarray tuint 5))
                (Expr.Econst_int (Integers.Int.repr 2) tint) (tptr tuint))
              tuint) (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_xdp_abi noattr))
                    _cb (tarray tuint 5))
                  (Expr.Econst_int (Integers.Int.repr 3) tint) (tptr tuint))
                tuint) (Expr.Econst_int (Integers.Int.repr 0) tint))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Efield
                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_xdp_abi noattr))
                      _cb (tarray tuint 5))
                    (Expr.Econst_int (Integers.Int.repr 4) tint)
                    (tptr tuint)) tuint)
                (Expr.Econst_int (Integers.Int.repr 0) tint))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Evar ___a64_sim_skb_ctx (tptr (Ty.Tstruct ___sk_buff noattr)))
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                    (tptr (Ty.Tstruct ___sk_buff noattr))))
                (Stmt.Ssequence
                  (Stmt.Sassign (Expr.Evar ___a64_sim_abi_kind tuchar)
                    (Expr.Econst_int (Integers.Int.repr 0) tuint))
                  (Stmt.Ssequence
                    (Stmt.Sassign (Expr.Evar ___a64_numeric_sp tulong)
                      (Expr.Econst_int (Integers.Int.repr 0) tint))
                    (Stmt.Ssequence
                      (Stmt.Sassign (Expr.Evar ___a64_numeric_return tulong)
                        (Expr.Econst_int (Integers.Int.repr 0) tint))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Evar ___a64_numeric_sp_valid tuchar)
                          (Expr.Econst_int (Integers.Int.repr 0) tint))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Evar ___a64_numeric_return_valid tuchar)
                            (Expr.Econst_int (Integers.Int.repr 0) tint))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Evar ___a64_sim_is_xdp tuchar)
                              (Expr.Econst_int (Integers.Int.repr 0) tint))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Evar ___a64_sim_helper_ctx (tptr tvoid))
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 0) tint)
                                  (tptr tvoid)))
                              (Stmt.Ssequence
                                s_kprog_arm64_entry_xdp_0
                                s_kprog_arm64_entry_xdp_50))))))))))))))))
}

@[noinline] def s_kprog_arm64_entry_skb_0 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield
        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
        _pad0 (tarray tuchar 48))
      (Expr.Econst_int (Integers.Int.repr 15) tint) (tptr tuchar)) tuchar)
  (Expr.Econst_int (Integers.Int.repr 0) tint))

@[noinline] def s_kprog_arm64_entry_skb_1 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield
        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
        _pad0 (tarray tuchar 48))
      (Expr.Econst_int (Integers.Int.repr 32) tint) (tptr tuchar)) tuchar)
  (Expr.Econst_int (Integers.Int.repr 0) tint))

@[noinline] def s_kprog_arm64_entry_skb_2 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield
        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr)) _cb
        (tarray tuint 5)) (Expr.Econst_int (Integers.Int.repr 1) tint)
      (tptr tuint)) tuint) (Expr.Econst_int (Integers.Int.repr 0) tint))

@[noinline] def s_kprog_arm64_entry_skb_3 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield
        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
        _pad2 (tarray tuchar 120))
      (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tuchar)) tuchar)
  (Expr.Econst_int (Integers.Int.repr 0) tint))

@[noinline] def s_kprog_arm64_entry_skb_4 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield
        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
        _pad2 (tarray tuchar 120))
      (Expr.Econst_int (Integers.Int.repr 17) tint) (tptr tuchar)) tuchar)
  (Expr.Econst_int (Integers.Int.repr 0) tint))

@[noinline] def s_kprog_arm64_entry_skb_5 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield
        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
        _pad2 (tarray tuchar 120))
      (Expr.Econst_int (Integers.Int.repr 34) tint) (tptr tuchar)) tuchar)
  (Expr.Econst_int (Integers.Int.repr 0) tint))

@[noinline] def s_kprog_arm64_entry_skb_6 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield
        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
        _pad2 (tarray tuchar 120))
      (Expr.Econst_int (Integers.Int.repr 51) tint) (tptr tuchar)) tuchar)
  (Expr.Econst_int (Integers.Int.repr 0) tint))

@[noinline] def s_kprog_arm64_entry_skb_7 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield
        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
        _pad2 (tarray tuchar 120))
      (Expr.Econst_int (Integers.Int.repr 68) tint) (tptr tuchar)) tuchar)
  (Expr.Econst_int (Integers.Int.repr 0) tint))

@[noinline] def s_kprog_arm64_entry_skb_8 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield
        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
        _pad2 (tarray tuchar 120))
      (Expr.Econst_int (Integers.Int.repr 85) tint) (tptr tuchar)) tuchar)
  (Expr.Econst_int (Integers.Int.repr 0) tint))

@[noinline] def s_kprog_arm64_entry_skb_9 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield
        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
        _pad2 (tarray tuchar 120))
      (Expr.Econst_int (Integers.Int.repr 102) tint) (tptr tuchar)) tuchar)
  (Expr.Econst_int (Integers.Int.repr 0) tint))

@[noinline] def s_kprog_arm64_entry_skb_10 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield
        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
        _pad2 (tarray tuchar 120))
      (Expr.Econst_int (Integers.Int.repr 119) tint) (tptr tuchar)) tuchar)
  (Expr.Econst_int (Integers.Int.repr 0) tint))

@[noinline] def s_kprog_arm64_entry_skb_11 : Stmt :=
(Stmt.Scall (some _t'4)
  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong cc_default))
  [(Expr.Econst_int (Integers.Int.repr 6) tint)])

@[noinline] def s_kprog_arm64_entry_skb_12 : Stmt :=
(Stmt.Sset _t'5
  (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong) tulong))

@[noinline] def s_kprog_arm64_entry_skb_13 : Stmt :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'6)
    (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                         cc_default))
    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
  (Stmt.Sset _t'5 (Expr.Ecast (Expr.Etempvar _t'6 tulong) tulong)))

@[noinline] def s_kprog_arm64_entry_skb_14 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Econst_int (Integers.Int.repr 3) tuint)
                      (Expr.Econst_int (Integers.Int.repr 30) tuint) tint)
    (Stmt.Sset _t'7
      (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong) tulong))
    (Stmt.Ssequence
      (Stmt.Scall (some _t'8)
        (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                             cc_default))
        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
      (Stmt.Sset _t'7 (Expr.Ecast (Expr.Etempvar _t'8 tulong) tulong))))
  (Stmt.Sassign
    (Expr.Efield (Expr.Evar ___a64_x3 (Ty.Tunion _arm64_sim_gpr noattr)) _x
      tulong) (Expr.Etempvar _t'7 tulong)))

@[noinline] def s_kprog_arm64_entry_skb_15 : Stmt :=
(Stmt.Sset _t'21
  (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong) tulong))

@[noinline] def s_kprog_arm64_entry_skb_16 : Stmt :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'22)
    (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                         cc_default))
    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
  (Stmt.Sset _t'21 (Expr.Ecast (Expr.Etempvar _t'22 tulong) tulong)))

@[noinline] def s_kprog_arm64_entry_skb_17 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                    (Expr.Econst_int (Integers.Int.repr 11) tuint)
                    (Expr.Econst_int (Integers.Int.repr 30) tuint) tint)
  (Stmt.Sset _t'23
    (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong) tulong))
  (Stmt.Ssequence
    (Stmt.Scall (some _t'24)
      (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                           cc_default))
      [(Expr.Econst_int (Integers.Int.repr 6) tint)])
    (Stmt.Sset _t'23 (Expr.Ecast (Expr.Etempvar _t'24 tulong) tulong))))

@[noinline] def s_kprog_arm64_entry_skb_18 : Stmt :=
(Stmt.Sassign (Expr.Evar ___a64_x11_tag tuchar)
  (Expr.Econst_int (Integers.Int.repr 0) tuint))

@[noinline] def s_kprog_arm64_entry_skb_19 : Stmt :=
(Stmt.Scall (some _t'38)
  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong cc_default))
  [(Expr.Econst_int (Integers.Int.repr 6) tint)])

@[noinline] def s_kprog_arm64_entry_skb_20 : Stmt :=
(Stmt.Sset _t'39
  (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong) tulong))

@[noinline] def s_kprog_arm64_entry_skb_21 : Stmt :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'40)
    (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                         cc_default))
    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
  (Stmt.Sset _t'39 (Expr.Ecast (Expr.Etempvar _t'40 tulong) tulong)))

@[noinline] def s_kprog_arm64_entry_skb_22 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                      (Expr.Econst_int (Integers.Int.repr 20) tuint)
                      (Expr.Econst_int (Integers.Int.repr 30) tuint) tint)
    (Stmt.Sset _t'41
      (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong) tulong))
    (Stmt.Ssequence
      (Stmt.Scall (some _t'42)
        (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                             cc_default))
        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
      (Stmt.Sset _t'41 (Expr.Ecast (Expr.Etempvar _t'42 tulong) tulong))))
  (Stmt.Sassign
    (Expr.Efield (Expr.Evar ___a64_x20 (Ty.Tunion _arm64_sim_gpr noattr)) _x
      tulong) (Expr.Etempvar _t'41 tulong)))

@[noinline] def s_kprog_arm64_entry_skb_23 : Stmt :=
(Stmt.Sset _t'55
  (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong) tulong))

@[noinline] def s_kprog_arm64_entry_skb_24 : Stmt :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'56)
    (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                         cc_default))
    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
  (Stmt.Sset _t'55 (Expr.Ecast (Expr.Etempvar _t'56 tulong) tulong)))

@[noinline] def s_kprog_arm64_entry_skb_25 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                    (Expr.Econst_int (Integers.Int.repr 28) tuint)
                    (Expr.Econst_int (Integers.Int.repr 30) tuint) tint)
  (Stmt.Sset _t'57
    (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong) tulong))
  (Stmt.Ssequence
    (Stmt.Scall (some _t'58)
      (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                           cc_default))
      [(Expr.Econst_int (Integers.Int.repr 6) tint)])
    (Stmt.Sset _t'57 (Expr.Ecast (Expr.Etempvar _t'58 tulong) tulong))))

@[noinline] def s_kprog_arm64_entry_skb_26 : Stmt :=
(Stmt.Sassign (Expr.Evar ___a64_x28_tag tuchar)
  (Expr.Econst_int (Integers.Int.repr 0) tuint))

@[noinline] def s_kprog_arm64_entry_skb_27 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
      (Expr.Econst_int (Integers.Int.repr 12) tint)
      (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
    (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
  (Expr.Eaddrof (Expr.Evar ___a64_x12 (Ty.Tunion _arm64_sim_gpr noattr))
    (tptr (Ty.Tunion _arm64_sim_gpr noattr))))

@[noinline] def s_kprog_arm64_entry_skb_28 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
      (Expr.Econst_int (Integers.Int.repr 29) tint)
      (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
    (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
  (Expr.Eaddrof (Expr.Evar ___a64_x29 (Ty.Tunion _arm64_sim_gpr noattr))
    (tptr (Ty.Tunion _arm64_sim_gpr noattr))))

@[noinline] def s_kprog_arm64_entry_skb_29 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
      (Expr.Econst_int (Integers.Int.repr 15) tint) (tptr (tptr tuchar)))
    (tptr tuchar))
  (Expr.Eaddrof (Expr.Evar ___a64_x15_tag tuchar) (tptr tuchar)))

@[noinline] def s_kprog_arm64_entry_skb_30 : Stmt :=
(Stmt.Scall (some _t'63)
  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong cc_default))
  [(Expr.Econst_int (Integers.Int.repr 6) tint)])

@[noinline] def s_kprog_arm64_entry_skb_31 : Stmt :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'64)
    (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                         cc_default))
    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
  (Stmt.Sassign (Expr.Evar ___a64_z tuchar)
    (Expr.Ebinop Binop.Oand (Expr.Etempvar _t'64 tulong)
      (Expr.Econst_int (Integers.Int.repr 1) tint) tulong)))

@[noinline] def s_kprog_arm64_entry_skb_32 : Stmt :=
(Stmt.Scall (some _t'79)
  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong cc_default))
  [(Expr.Econst_int (Integers.Int.repr 6) tint)])

@[noinline] def s_kprog_arm64_entry_skb_33 : Stmt :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'80)
    (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                         cc_default))
    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
  (Stmt.Sassign
    (Expr.Efield
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
          (Expr.Econst_int (Integers.Int.repr 6) tint)
          (tptr (Ty.Tstruct __3040 noattr))) (Ty.Tstruct __3040 noattr)) _hi
      tulong) (Expr.Etempvar _t'80 tulong)))

@[noinline] def s_kprog_arm64_entry_skb_34 : Stmt :=
(Stmt.Scall (some _t'96)
  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong cc_default))
  [(Expr.Econst_int (Integers.Int.repr 6) tint)])

@[noinline] def s_kprog_arm64_entry_skb_35 : Stmt :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'97)
    (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                         cc_default))
    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
  (Stmt.Sassign
    (Expr.Efield
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
          (Expr.Econst_int (Integers.Int.repr 15) tint)
          (tptr (Ty.Tstruct __3040 noattr))) (Ty.Tstruct __3040 noattr)) _lo
      tulong) (Expr.Etempvar _t'97 tulong)))

@[noinline] def s_kprog_arm64_entry_skb_36 : Stmt :=
(Stmt.Scall (some _t'113)
  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong cc_default))
  [(Expr.Econst_int (Integers.Int.repr 6) tint)])

@[noinline] def s_kprog_arm64_entry_skb_37 : Stmt :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'114)
    (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                         cc_default))
    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
  (Stmt.Sassign
    (Expr.Efield
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
          (Expr.Econst_int (Integers.Int.repr 23) tint)
          (tptr (Ty.Tstruct __3040 noattr))) (Ty.Tstruct __3040 noattr)) _hi
      tulong) (Expr.Etempvar _t'114 tulong)))

@[noinline] def s_kprog_arm64_entry_skb_38 : Stmt :=
(Stmt.Scall (some _t'130)
  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong cc_default))
  [(Expr.Econst_int (Integers.Int.repr 6) tint)])

@[noinline] def s_kprog_arm64_entry_skb_39 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
      (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tuchar)) tuchar)
  (Expr.Econst_int (Integers.Int.repr 0) tint))

@[noinline] def s_kprog_arm64_entry_skb_40 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
      (Expr.Econst_int (Integers.Int.repr 17) tint) (tptr tuchar)) tuchar)
  (Expr.Econst_int (Integers.Int.repr 0) tint))

@[noinline] def s_kprog_arm64_entry_skb_41 : Stmt :=
(Stmt.Sassign
  (Expr.Efield (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
    _return_base (tptr tulong))
  (Expr.Eaddrof (Expr.Evar ___a64_numeric_return tulong) (tptr tulong)))

@[noinline] def s_kprog_arm64_entry_skb_42 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
        _vector_lo (tarray (tptr tulong) 32))
      (Expr.Econst_int (Integers.Int.repr 8) tint) (tptr (tptr tulong)))
    (tptr tulong))
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))

@[noinline] def s_kprog_arm64_entry_skb_43 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
        _vector_lo (tarray (tptr tulong) 32))
      (Expr.Econst_int (Integers.Int.repr 25) tint) (tptr (tptr tulong)))
    (tptr tulong))
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))

@[noinline] def s_kprog_arm64_entry_skb_44 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
        _vector_hi (tarray (tptr tulong) 32))
      (Expr.Econst_int (Integers.Int.repr 10) tint) (tptr (tptr tulong)))
    (tptr tulong))
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))

@[noinline] def s_kprog_arm64_entry_skb_45 : Stmt :=
(Stmt.Sassign
  (Expr.Ederef
    (Expr.Ebinop Binop.Oadd
      (Expr.Efield (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
        _vector_hi (tarray (tptr tulong) 32))
      (Expr.Econst_int (Integers.Int.repr 27) tint) (tptr (tptr tulong)))
    (tptr tulong))
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))

@[noinline] def s_kprog_arm64_entry_skb_46 : Stmt :=
(Stmt.Sassign
  (Expr.Efield (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
    _is_xdp (tptr tuchar))
  (Expr.Eaddrof (Expr.Evar ___a64_sim_is_xdp tuchar) (tptr tuchar)))

@[noinline] def s_kprog_arm64_entry_skb_47 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Efield (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
      _abi_kind (tptr tuchar))
    (Expr.Eaddrof (Expr.Evar ___a64_sim_abi_kind tuchar) (tptr tuchar)))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Efield (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
        _skb_context (tptr (tptr (Ty.Tstruct ___sk_buff noattr))))
      (Expr.Eaddrof
        (Expr.Evar ___a64_sim_skb_ctx (tptr (Ty.Tstruct ___sk_buff noattr)))
        (tptr (tptr (Ty.Tstruct ___sk_buff noattr)))))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Efield
          (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr)) _abi
          (tptr tvoid))
        (Expr.Eaddrof
          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
          (tptr (Ty.Tstruct _arm64_sim_skb_abi noattr))))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sset _i (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Sloop
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                  (Expr.Etempvar _i tuint)
                                  (Expr.Econst_int (Integers.Int.repr 32) tint)
                                  tint)
                Stmt.Sskip
                Stmt.Sbreak)
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                        _vector_lo (tarray (tptr tulong) 32))
                      (Expr.Etempvar _i tuint) (tptr (tptr tulong)))
                    (tptr tulong))
                  (Expr.Eaddrof
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                          (Expr.Etempvar _i tuint)
                          (tptr (Ty.Tstruct __3040 noattr)))
                        (Ty.Tstruct __3040 noattr)) _lo tulong)
                    (tptr tulong)))
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                        _vector_hi (tarray (tptr tulong) 32))
                      (Expr.Etempvar _i tuint) (tptr (tptr tulong)))
                    (tptr tulong))
                  (Expr.Eaddrof
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                          (Expr.Etempvar _i tuint)
                          (tptr (Ty.Tstruct __3040 noattr)))
                        (Ty.Tstruct __3040 noattr)) _hi tulong)
                    (tptr tulong)))))
            (Stmt.Sset _i
              (Expr.Ebinop Binop.Oadd (Expr.Etempvar _i tuint)
                (Expr.Econst_int (Integers.Int.repr 1) tint) tuint))))
        (Stmt.Ssequence
          (Stmt.Scall (some _t'132)
            (Expr.Etempvar _continuation (tptr (Ty.Tfunction
                                                 [(tptr (Ty.Tstruct _kprog_arm64_entry noattr))]
                                                 tuint cc_default)))
            [(Expr.Eaddrof
               (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
               (tptr (Ty.Tstruct _kprog_arm64_entry noattr)))])
          (Stmt.Sreturn (some (Expr.Etempvar _t'132 tuint))))))))

@[noinline] def s_kprog_arm64_entry_skb_48 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Efield
          (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
          _vector_hi (tarray (tptr tulong) 32))
        (Expr.Econst_int (Integers.Int.repr 28) tint) (tptr (tptr tulong)))
      (tptr tulong))
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Efield
            (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
            _vector_hi (tarray (tptr tulong) 32))
          (Expr.Econst_int (Integers.Int.repr 29) tint) (tptr (tptr tulong)))
        (tptr tulong))
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
              _vector_hi (tarray (tptr tulong) 32))
            (Expr.Econst_int (Integers.Int.repr 30) tint)
            (tptr (tptr tulong))) (tptr tulong))
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
          (tptr tvoid)))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                _vector_hi (tarray (tptr tulong) 32))
              (Expr.Econst_int (Integers.Int.repr 31) tint)
              (tptr (tptr tulong))) (tptr tulong))
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
            (tptr tvoid)))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Efield
              (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr)) _b
              (tptr (tvolatile tuchar)))
            (Expr.Efield
              (Expr.Evar ___a64_stack (tvolatile (Ty.Tunion __3042 noattr)))
              _b (tvolatile (tarray tuchar 160))))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Efield
                (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr)) _q
                (tptr (tvolatile tulong)))
              (Expr.Efield
                (Expr.Evar ___a64_stack (tvolatile (Ty.Tunion __3042 noattr)))
                _q (tvolatile (tarray tulong 20))))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                  _payload (tptr (tvolatile tulong)))
                (Expr.Evar ___a64_stack_payload (tarray (tvolatile tulong) 20)))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Efield
                    (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                    _payload_load
                    (tptr (Ty.Tfunction [(tptr (tvolatile tulong)), tulong]
                            tulong cc_default)))
                  (Expr.Evar _kprog_arm64_payload_load (Ty.Tfunction
                                                         [(tptr (tvolatile tulong)),
                                                          tulong] tulong
                                                         cc_default)))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Efield
                      (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                      _payload_store
                      (tptr (Ty.Tfunction
                              [(tptr (tvolatile tulong)), tulong, tulong]
                              tvoid cc_default)))
                    (Expr.Evar _kprog_arm64_payload_store (Ty.Tfunction
                                                            [(tptr (tvolatile tulong)),
                                                             tulong, tulong]
                                                            tvoid cc_default)))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Efield
                        (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                        _stack_tags (tptr tuchar))
                      (Expr.Evar ___a64_stack_tag (tarray tuchar 24)))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Efield
                          (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                          _capacity tuint)
                        (Expr.Esizeof (tarray (tvolatile tuchar) 160) tulong))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                            _payload_words tuint)
                          (Expr.Ebinop Binop.Odiv
                            (Expr.Esizeof (tarray (tvolatile tulong) 20) tulong)
                            (Expr.Esizeof (tvolatile tulong) tulong) tulong))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                              _tag_bytes tuint)
                            (Expr.Esizeof (tarray tuchar 24) tulong))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                _bias tlong)
                              (Expr.Econst_long (Integers.Int64.repr 96) tlong))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                  _helper_context (tptr (tptr tvoid)))
                                (Expr.Eaddrof
                                  (Expr.Evar ___a64_sim_helper_ctx (tptr tvoid))
                                  (tptr (tptr tvoid))))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Efield
                                    (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                    _helper_abi_base (tptr (tptr tvoid)))
                                  (Expr.Eaddrof
                                    (Expr.Evar ___a64_sim_helper_abi_base (tptr tvoid))
                                    (tptr (tptr tvoid))))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_skb_46
                                  s_kprog_arm64_entry_skb_47)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_skb_49 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Efield
          (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
          _vector_hi (tarray (tptr tulong) 32))
        (Expr.Econst_int (Integers.Int.repr 11) tint) (tptr (tptr tulong)))
      (tptr tulong))
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Efield
            (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
            _vector_hi (tarray (tptr tulong) 32))
          (Expr.Econst_int (Integers.Int.repr 12) tint) (tptr (tptr tulong)))
        (tptr tulong))
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
              _vector_hi (tarray (tptr tulong) 32))
            (Expr.Econst_int (Integers.Int.repr 13) tint)
            (tptr (tptr tulong))) (tptr tulong))
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
          (tptr tvoid)))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                _vector_hi (tarray (tptr tulong) 32))
              (Expr.Econst_int (Integers.Int.repr 14) tint)
              (tptr (tptr tulong))) (tptr tulong))
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
            (tptr tvoid)))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                  _vector_hi (tarray (tptr tulong) 32))
                (Expr.Econst_int (Integers.Int.repr 15) tint)
                (tptr (tptr tulong))) (tptr tulong))
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
              (tptr tvoid)))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                    _vector_hi (tarray (tptr tulong) 32))
                  (Expr.Econst_int (Integers.Int.repr 16) tint)
                  (tptr (tptr tulong))) (tptr tulong))
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                (tptr tvoid)))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Efield
                      (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                      _vector_hi (tarray (tptr tulong) 32))
                    (Expr.Econst_int (Integers.Int.repr 17) tint)
                    (tptr (tptr tulong))) (tptr tulong))
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                  (tptr tvoid)))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                        _vector_hi (tarray (tptr tulong) 32))
                      (Expr.Econst_int (Integers.Int.repr 18) tint)
                      (tptr (tptr tulong))) (tptr tulong))
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                    (tptr tvoid)))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                          _vector_hi (tarray (tptr tulong) 32))
                        (Expr.Econst_int (Integers.Int.repr 19) tint)
                        (tptr (tptr tulong))) (tptr tulong))
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                      (tptr tvoid)))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Efield
                            (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                            _vector_hi (tarray (tptr tulong) 32))
                          (Expr.Econst_int (Integers.Int.repr 20) tint)
                          (tptr (tptr tulong))) (tptr tulong))
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 0) tint)
                        (tptr tvoid)))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                              _vector_hi (tarray (tptr tulong) 32))
                            (Expr.Econst_int (Integers.Int.repr 21) tint)
                            (tptr (tptr tulong))) (tptr tulong))
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                          (tptr tvoid)))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                _vector_hi (tarray (tptr tulong) 32))
                              (Expr.Econst_int (Integers.Int.repr 22) tint)
                              (tptr (tptr tulong))) (tptr tulong))
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                            (tptr tvoid)))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                  _vector_hi (tarray (tptr tulong) 32))
                                (Expr.Econst_int (Integers.Int.repr 23) tint)
                                (tptr (tptr tulong))) (tptr tulong))
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 0) tint)
                              (tptr tvoid)))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                    _vector_hi (tarray (tptr tulong) 32))
                                  (Expr.Econst_int (Integers.Int.repr 24) tint)
                                  (tptr (tptr tulong))) (tptr tulong))
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 0) tint)
                                (tptr tvoid)))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                      _vector_hi (tarray (tptr tulong) 32))
                                    (Expr.Econst_int (Integers.Int.repr 25) tint)
                                    (tptr (tptr tulong))) (tptr tulong))
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 0) tint)
                                  (tptr tvoid)))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Efield
                                        (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                        _vector_hi (tarray (tptr tulong) 32))
                                      (Expr.Econst_int (Integers.Int.repr 26) tint)
                                      (tptr (tptr tulong))) (tptr tulong))
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 0) tint)
                                    (tptr tvoid)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_skb_45
                                  s_kprog_arm64_entry_skb_48)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_skb_50 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Efield
          (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
          _vector_lo (tarray (tptr tulong) 32))
        (Expr.Econst_int (Integers.Int.repr 26) tint) (tptr (tptr tulong)))
      (tptr tulong))
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Efield
            (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
            _vector_lo (tarray (tptr tulong) 32))
          (Expr.Econst_int (Integers.Int.repr 27) tint) (tptr (tptr tulong)))
        (tptr tulong))
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
              _vector_lo (tarray (tptr tulong) 32))
            (Expr.Econst_int (Integers.Int.repr 28) tint)
            (tptr (tptr tulong))) (tptr tulong))
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
          (tptr tvoid)))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                _vector_lo (tarray (tptr tulong) 32))
              (Expr.Econst_int (Integers.Int.repr 29) tint)
              (tptr (tptr tulong))) (tptr tulong))
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
            (tptr tvoid)))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                  _vector_lo (tarray (tptr tulong) 32))
                (Expr.Econst_int (Integers.Int.repr 30) tint)
                (tptr (tptr tulong))) (tptr tulong))
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
              (tptr tvoid)))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                    _vector_lo (tarray (tptr tulong) 32))
                  (Expr.Econst_int (Integers.Int.repr 31) tint)
                  (tptr (tptr tulong))) (tptr tulong))
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                (tptr tvoid)))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Efield
                      (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                      _vector_hi (tarray (tptr tulong) 32))
                    (Expr.Econst_int (Integers.Int.repr 0) tint)
                    (tptr (tptr tulong))) (tptr tulong))
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                  (tptr tvoid)))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                        _vector_hi (tarray (tptr tulong) 32))
                      (Expr.Econst_int (Integers.Int.repr 1) tint)
                      (tptr (tptr tulong))) (tptr tulong))
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                    (tptr tvoid)))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                          _vector_hi (tarray (tptr tulong) 32))
                        (Expr.Econst_int (Integers.Int.repr 2) tint)
                        (tptr (tptr tulong))) (tptr tulong))
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                      (tptr tvoid)))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Efield
                            (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                            _vector_hi (tarray (tptr tulong) 32))
                          (Expr.Econst_int (Integers.Int.repr 3) tint)
                          (tptr (tptr tulong))) (tptr tulong))
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 0) tint)
                        (tptr tvoid)))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                              _vector_hi (tarray (tptr tulong) 32))
                            (Expr.Econst_int (Integers.Int.repr 4) tint)
                            (tptr (tptr tulong))) (tptr tulong))
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                          (tptr tvoid)))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                _vector_hi (tarray (tptr tulong) 32))
                              (Expr.Econst_int (Integers.Int.repr 5) tint)
                              (tptr (tptr tulong))) (tptr tulong))
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                            (tptr tvoid)))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                  _vector_hi (tarray (tptr tulong) 32))
                                (Expr.Econst_int (Integers.Int.repr 6) tint)
                                (tptr (tptr tulong))) (tptr tulong))
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 0) tint)
                              (tptr tvoid)))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                    _vector_hi (tarray (tptr tulong) 32))
                                  (Expr.Econst_int (Integers.Int.repr 7) tint)
                                  (tptr (tptr tulong))) (tptr tulong))
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 0) tint)
                                (tptr tvoid)))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                      _vector_hi (tarray (tptr tulong) 32))
                                    (Expr.Econst_int (Integers.Int.repr 8) tint)
                                    (tptr (tptr tulong))) (tptr tulong))
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 0) tint)
                                  (tptr tvoid)))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Efield
                                        (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                        _vector_hi (tarray (tptr tulong) 32))
                                      (Expr.Econst_int (Integers.Int.repr 9) tint)
                                      (tptr (tptr tulong))) (tptr tulong))
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 0) tint)
                                    (tptr tvoid)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_skb_44
                                  s_kprog_arm64_entry_skb_49)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_skb_51 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Efield
          (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
          _vector_lo (tarray (tptr tulong) 32))
        (Expr.Econst_int (Integers.Int.repr 9) tint) (tptr (tptr tulong)))
      (tptr tulong))
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Efield
            (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
            _vector_lo (tarray (tptr tulong) 32))
          (Expr.Econst_int (Integers.Int.repr 10) tint) (tptr (tptr tulong)))
        (tptr tulong))
      (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
              _vector_lo (tarray (tptr tulong) 32))
            (Expr.Econst_int (Integers.Int.repr 11) tint)
            (tptr (tptr tulong))) (tptr tulong))
        (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
          (tptr tvoid)))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                _vector_lo (tarray (tptr tulong) 32))
              (Expr.Econst_int (Integers.Int.repr 12) tint)
              (tptr (tptr tulong))) (tptr tulong))
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
            (tptr tvoid)))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                  _vector_lo (tarray (tptr tulong) 32))
                (Expr.Econst_int (Integers.Int.repr 13) tint)
                (tptr (tptr tulong))) (tptr tulong))
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
              (tptr tvoid)))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                    _vector_lo (tarray (tptr tulong) 32))
                  (Expr.Econst_int (Integers.Int.repr 14) tint)
                  (tptr (tptr tulong))) (tptr tulong))
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                (tptr tvoid)))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Efield
                      (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                      _vector_lo (tarray (tptr tulong) 32))
                    (Expr.Econst_int (Integers.Int.repr 15) tint)
                    (tptr (tptr tulong))) (tptr tulong))
                (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                  (tptr tvoid)))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                        _vector_lo (tarray (tptr tulong) 32))
                      (Expr.Econst_int (Integers.Int.repr 16) tint)
                      (tptr (tptr tulong))) (tptr tulong))
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                    (tptr tvoid)))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                          _vector_lo (tarray (tptr tulong) 32))
                        (Expr.Econst_int (Integers.Int.repr 17) tint)
                        (tptr (tptr tulong))) (tptr tulong))
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                      (tptr tvoid)))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Efield
                            (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                            _vector_lo (tarray (tptr tulong) 32))
                          (Expr.Econst_int (Integers.Int.repr 18) tint)
                          (tptr (tptr tulong))) (tptr tulong))
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 0) tint)
                        (tptr tvoid)))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                              _vector_lo (tarray (tptr tulong) 32))
                            (Expr.Econst_int (Integers.Int.repr 19) tint)
                            (tptr (tptr tulong))) (tptr tulong))
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                          (tptr tvoid)))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                _vector_lo (tarray (tptr tulong) 32))
                              (Expr.Econst_int (Integers.Int.repr 20) tint)
                              (tptr (tptr tulong))) (tptr tulong))
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                            (tptr tvoid)))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                  _vector_lo (tarray (tptr tulong) 32))
                                (Expr.Econst_int (Integers.Int.repr 21) tint)
                                (tptr (tptr tulong))) (tptr tulong))
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 0) tint)
                              (tptr tvoid)))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                    _vector_lo (tarray (tptr tulong) 32))
                                  (Expr.Econst_int (Integers.Int.repr 22) tint)
                                  (tptr (tptr tulong))) (tptr tulong))
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 0) tint)
                                (tptr tvoid)))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                      _vector_lo (tarray (tptr tulong) 32))
                                    (Expr.Econst_int (Integers.Int.repr 23) tint)
                                    (tptr (tptr tulong))) (tptr tulong))
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 0) tint)
                                  (tptr tvoid)))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Efield
                                        (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                        _vector_lo (tarray (tptr tulong) 32))
                                      (Expr.Econst_int (Integers.Int.repr 24) tint)
                                      (tptr (tptr tulong))) (tptr tulong))
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 0) tint)
                                    (tptr tvoid)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_skb_43
                                  s_kprog_arm64_entry_skb_50)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_skb_52 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Efield (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
      _lr (tptr tulong))
    (Expr.Eaddrof (Expr.Evar ___a64_lr tulong) (tptr tulong)))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Efield (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
        _sp (tptr tlong))
      (Expr.Eaddrof (Expr.Evar ___a64_sp tlong) (tptr tlong)))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Efield
          (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr)) _sp_valid
          (tptr tuchar))
        (Expr.Eaddrof (Expr.Evar ___a64_numeric_sp_valid tuchar)
          (tptr tuchar)))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Efield
            (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
            _return_valid (tptr tuchar))
          (Expr.Eaddrof (Expr.Evar ___a64_numeric_return_valid tuchar)
            (tptr tuchar)))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Efield
              (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr)) _n
              (tptr tuchar))
            (Expr.Eaddrof (Expr.Evar ___a64_n tuchar) (tptr tuchar)))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Efield
                (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr)) _z
                (tptr tuchar))
              (Expr.Eaddrof (Expr.Evar ___a64_z tuchar) (tptr tuchar)))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                  _c (tptr tuchar))
                (Expr.Eaddrof (Expr.Evar ___a64_c tuchar) (tptr tuchar)))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Efield
                    (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                    _v (tptr tuchar))
                  (Expr.Eaddrof (Expr.Evar ___a64_v tuchar) (tptr tuchar)))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                          _vector_lo (tarray (tptr tulong) 32))
                        (Expr.Econst_int (Integers.Int.repr 0) tint)
                        (tptr (tptr tulong))) (tptr tulong))
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                      (tptr tvoid)))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Efield
                            (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                            _vector_lo (tarray (tptr tulong) 32))
                          (Expr.Econst_int (Integers.Int.repr 1) tint)
                          (tptr (tptr tulong))) (tptr tulong))
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 0) tint)
                        (tptr tvoid)))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                              _vector_lo (tarray (tptr tulong) 32))
                            (Expr.Econst_int (Integers.Int.repr 2) tint)
                            (tptr (tptr tulong))) (tptr tulong))
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                          (tptr tvoid)))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                _vector_lo (tarray (tptr tulong) 32))
                              (Expr.Econst_int (Integers.Int.repr 3) tint)
                              (tptr (tptr tulong))) (tptr tulong))
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                            (tptr tvoid)))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                  _vector_lo (tarray (tptr tulong) 32))
                                (Expr.Econst_int (Integers.Int.repr 4) tint)
                                (tptr (tptr tulong))) (tptr tulong))
                            (Expr.Ecast
                              (Expr.Econst_int (Integers.Int.repr 0) tint)
                              (tptr tvoid)))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                    _vector_lo (tarray (tptr tulong) 32))
                                  (Expr.Econst_int (Integers.Int.repr 5) tint)
                                  (tptr (tptr tulong))) (tptr tulong))
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 0) tint)
                                (tptr tvoid)))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                      _vector_lo (tarray (tptr tulong) 32))
                                    (Expr.Econst_int (Integers.Int.repr 6) tint)
                                    (tptr (tptr tulong))) (tptr tulong))
                                (Expr.Ecast
                                  (Expr.Econst_int (Integers.Int.repr 0) tint)
                                  (tptr tvoid)))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Efield
                                        (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                        _vector_lo (tarray (tptr tulong) 32))
                                      (Expr.Econst_int (Integers.Int.repr 7) tint)
                                      (tptr (tptr tulong))) (tptr tulong))
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 0) tint)
                                    (tptr tvoid)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_skb_42
                                  s_kprog_arm64_entry_skb_51)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_skb_53 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
        (Expr.Econst_int (Integers.Int.repr 18) tint) (tptr tuchar)) tuchar)
    (Expr.Econst_int (Integers.Int.repr 0) tint))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
          (Expr.Econst_int (Integers.Int.repr 19) tint) (tptr tuchar))
        tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
            (Expr.Econst_int (Integers.Int.repr 20) tint) (tptr tuchar))
          tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
              (Expr.Econst_int (Integers.Int.repr 21) tint) (tptr tuchar))
            tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                (Expr.Econst_int (Integers.Int.repr 22) tint) (tptr tuchar))
              tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                  (Expr.Econst_int (Integers.Int.repr 23) tint)
                  (tptr tuchar)) tuchar)
              (Expr.Econst_int (Integers.Int.repr 0) tint))
            (Stmt.Ssequence
              (Stmt.Sassign (Expr.Evar ___a64_sp tlong)
                (Expr.Econst_int (Integers.Int.repr 0) tint))
              (Stmt.Ssequence
                (Stmt.Sassign (Expr.Evar ___a64_sim_helper_ctx (tptr tvoid))
                  (Expr.Ecast
                    (Expr.Etempvar _ctx (tptr (Ty.Tstruct ___sk_buff noattr)))
                    (tptr tvoid)))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Scall (some _t'131)
                      (Expr.Etempvar _bpf_cast_to_kern_ctx (tptr (Ty.Tfunction
                                                                   [(tptr tvoid)]
                                                                   (tptr tvoid)
                                                                   cc_default)))
                      [(Expr.Ecast
                         (Expr.Etempvar _ctx (tptr (Ty.Tstruct ___sk_buff noattr)))
                         (tptr tvoid))])
                    (Stmt.Sassign
                      (Expr.Evar ___a64_sim_helper_abi_base (tptr tvoid))
                      (Expr.Etempvar _t'131 (tptr tvoid))))
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sset _t'133
                        (Expr.Evar ___a64_sim_helper_abi_base (tptr tvoid)))
                      (Stmt.Sassign
                        (Expr.Efield
                          (Expr.Evar ___a64_x0 (Ty.Tunion _arm64_sim_gpr noattr))
                          _ptr (tptr tvoid))
                        (Expr.Etempvar _t'133 (tptr tvoid))))
                    (Stmt.Ssequence
                      (Stmt.Sassign (Expr.Evar ___a64_x30_tag tuchar)
                        (Expr.Econst_int (Integers.Int.repr 10) tuint))
                      (Stmt.Ssequence
                        (Stmt.Sassign (Expr.Evar ___a64_x0_tag tuchar)
                          (Expr.Econst_int (Integers.Int.repr 1) tuint))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                              _cells
                              (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                            (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31)))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                _tag_cells (tptr (tptr tuchar)))
                              (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31)))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Evar _entry (Ty.Tstruct _kprog_arm64_entry noattr))
                                  _sp_base (tptr tulong))
                                (Expr.Eaddrof
                                  (Expr.Evar ___a64_numeric_sp tulong)
                                  (tptr tulong)))
                              (Stmt.Ssequence
                                s_kprog_arm64_entry_skb_41
                                s_kprog_arm64_entry_skb_52))))))))))))))))

@[noinline] def s_kprog_arm64_entry_skb_54 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
        (Expr.Econst_int (Integers.Int.repr 1) tint) (tptr tuchar)) tuchar)
    (Expr.Econst_int (Integers.Int.repr 0) tint))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
          (Expr.Econst_int (Integers.Int.repr 2) tint) (tptr tuchar)) tuchar)
      (Expr.Econst_int (Integers.Int.repr 0) tint))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
            (Expr.Econst_int (Integers.Int.repr 3) tint) (tptr tuchar))
          tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
              (Expr.Econst_int (Integers.Int.repr 4) tint) (tptr tuchar))
            tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                (Expr.Econst_int (Integers.Int.repr 5) tint) (tptr tuchar))
              tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                  (Expr.Econst_int (Integers.Int.repr 6) tint) (tptr tuchar))
                tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                    (Expr.Econst_int (Integers.Int.repr 7) tint)
                    (tptr tuchar)) tuchar)
                (Expr.Econst_int (Integers.Int.repr 0) tint))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                      (Expr.Econst_int (Integers.Int.repr 8) tint)
                      (tptr tuchar)) tuchar)
                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                        (Expr.Econst_int (Integers.Int.repr 9) tint)
                        (tptr tuchar)) tuchar)
                    (Expr.Econst_int (Integers.Int.repr 0) tint))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                          (Expr.Econst_int (Integers.Int.repr 10) tint)
                          (tptr tuchar)) tuchar)
                      (Expr.Econst_int (Integers.Int.repr 0) tint))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                            (Expr.Econst_int (Integers.Int.repr 11) tint)
                            (tptr tuchar)) tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tint))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                              (Expr.Econst_int (Integers.Int.repr 12) tint)
                              (tptr tuchar)) tuchar)
                          (Expr.Econst_int (Integers.Int.repr 0) tint))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                                (Expr.Econst_int (Integers.Int.repr 13) tint)
                                (tptr tuchar)) tuchar)
                            (Expr.Econst_int (Integers.Int.repr 0) tint))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                                  (Expr.Econst_int (Integers.Int.repr 14) tint)
                                  (tptr tuchar)) tuchar)
                              (Expr.Econst_int (Integers.Int.repr 0) tint))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                                    (Expr.Econst_int (Integers.Int.repr 15) tint)
                                    (tptr tuchar)) tuchar)
                                (Expr.Econst_int (Integers.Int.repr 0) tint))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Evar ___a64_stack_tag (tarray tuchar 24))
                                      (Expr.Econst_int (Integers.Int.repr 16) tint)
                                      (tptr tuchar)) tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_skb_40
                                  s_kprog_arm64_entry_skb_53)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_skb_55 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Scall (some _t'115)
      (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                           cc_default))
      [(Expr.Econst_int (Integers.Int.repr 6) tint)])
    (Stmt.Sassign
      (Expr.Efield
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
            (Expr.Econst_int (Integers.Int.repr 24) tint)
            (tptr (Ty.Tstruct __3040 noattr))) (Ty.Tstruct __3040 noattr))
        _lo tulong) (Expr.Etempvar _t'115 tulong)))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Scall (some _t'116)
        (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                             cc_default))
        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
      (Stmt.Sassign
        (Expr.Efield
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
              (Expr.Econst_int (Integers.Int.repr 24) tint)
              (tptr (Ty.Tstruct __3040 noattr))) (Ty.Tstruct __3040 noattr))
          _hi tulong) (Expr.Etempvar _t'116 tulong)))
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Scall (some _t'117)
          (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                               cc_default))
          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
        (Stmt.Sassign
          (Expr.Efield
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                (Expr.Econst_int (Integers.Int.repr 25) tint)
                (tptr (Ty.Tstruct __3040 noattr)))
              (Ty.Tstruct __3040 noattr)) _lo tulong)
          (Expr.Etempvar _t'117 tulong)))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Scall (some _t'118)
            (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                 cc_default))
            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
          (Stmt.Sassign
            (Expr.Efield
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                  (Expr.Econst_int (Integers.Int.repr 25) tint)
                  (tptr (Ty.Tstruct __3040 noattr)))
                (Ty.Tstruct __3040 noattr)) _hi tulong)
            (Expr.Etempvar _t'118 tulong)))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Scall (some _t'119)
              (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                   cc_default))
              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
            (Stmt.Sassign
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                    (Expr.Econst_int (Integers.Int.repr 26) tint)
                    (tptr (Ty.Tstruct __3040 noattr)))
                  (Ty.Tstruct __3040 noattr)) _lo tulong)
              (Expr.Etempvar _t'119 tulong)))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Scall (some _t'120)
                (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                     tulong cc_default))
                [(Expr.Econst_int (Integers.Int.repr 6) tint)])
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                      (Expr.Econst_int (Integers.Int.repr 26) tint)
                      (tptr (Ty.Tstruct __3040 noattr)))
                    (Ty.Tstruct __3040 noattr)) _hi tulong)
                (Expr.Etempvar _t'120 tulong)))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Scall (some _t'121)
                  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                       tulong cc_default))
                  [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                (Stmt.Sassign
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                        (Expr.Econst_int (Integers.Int.repr 27) tint)
                        (tptr (Ty.Tstruct __3040 noattr)))
                      (Ty.Tstruct __3040 noattr)) _lo tulong)
                  (Expr.Etempvar _t'121 tulong)))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Scall (some _t'122)
                    (Expr.Evar _native_lab_entry_input (Ty.Tfunction 
                                                         [tuint] tulong
                                                         cc_default))
                    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                  (Stmt.Sassign
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                          (Expr.Econst_int (Integers.Int.repr 27) tint)
                          (tptr (Ty.Tstruct __3040 noattr)))
                        (Ty.Tstruct __3040 noattr)) _hi tulong)
                    (Expr.Etempvar _t'122 tulong)))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Scall (some _t'123)
                      (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                           [tuint] tulong
                                                           cc_default))
                      [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                    (Stmt.Sassign
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                            (Expr.Econst_int (Integers.Int.repr 28) tint)
                            (tptr (Ty.Tstruct __3040 noattr)))
                          (Ty.Tstruct __3040 noattr)) _lo tulong)
                      (Expr.Etempvar _t'123 tulong)))
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Scall (some _t'124)
                        (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                             [tuint] tulong
                                                             cc_default))
                        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                      (Stmt.Sassign
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                              (Expr.Econst_int (Integers.Int.repr 28) tint)
                              (tptr (Ty.Tstruct __3040 noattr)))
                            (Ty.Tstruct __3040 noattr)) _hi tulong)
                        (Expr.Etempvar _t'124 tulong)))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Scall (some _t'125)
                          (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                               [tuint] tulong
                                                               cc_default))
                          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                                (Expr.Econst_int (Integers.Int.repr 29) tint)
                                (tptr (Ty.Tstruct __3040 noattr)))
                              (Ty.Tstruct __3040 noattr)) _lo tulong)
                          (Expr.Etempvar _t'125 tulong)))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'126)
                            (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                 [tuint]
                                                                 tulong
                                                                 cc_default))
                            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                                  (Expr.Econst_int (Integers.Int.repr 29) tint)
                                  (tptr (Ty.Tstruct __3040 noattr)))
                                (Ty.Tstruct __3040 noattr)) _hi tulong)
                            (Expr.Etempvar _t'126 tulong)))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Scall (some _t'127)
                              (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                   [tuint]
                                                                   tulong
                                                                   cc_default))
                              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                                    (Expr.Econst_int (Integers.Int.repr 30) tint)
                                    (tptr (Ty.Tstruct __3040 noattr)))
                                  (Ty.Tstruct __3040 noattr)) _lo tulong)
                              (Expr.Etempvar _t'127 tulong)))
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Scall (some _t'128)
                                (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                    [tuint]
                                                                    tulong
                                                                    cc_default))
                                [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                                      (Expr.Econst_int (Integers.Int.repr 30) tint)
                                      (tptr (Ty.Tstruct __3040 noattr)))
                                    (Ty.Tstruct __3040 noattr)) _hi tulong)
                                (Expr.Etempvar _t'128 tulong)))
                            (Stmt.Ssequence
                              (Stmt.Ssequence
                                (Stmt.Scall (some _t'129)
                                  (Expr.Evar _native_lab_entry_input 
                                  (Ty.Tfunction [tuint] tulong cc_default))
                                  [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                                (Stmt.Sassign
                                  (Expr.Efield
                                    (Expr.Ederef
                                      (Expr.Ebinop Binop.Oadd
                                        (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                                        (Expr.Econst_int (Integers.Int.repr 31) tint)
                                        (tptr (Ty.Tstruct __3040 noattr)))
                                      (Ty.Tstruct __3040 noattr)) _lo tulong)
                                  (Expr.Etempvar _t'129 tulong)))
                              (Stmt.Ssequence
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_skb_38
                                  (Stmt.Sassign
                                    (Expr.Efield
                                      (Expr.Ederef
                                        (Expr.Ebinop Binop.Oadd
                                          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                                          (Expr.Econst_int (Integers.Int.repr 31) tint)
                                          (tptr (Ty.Tstruct __3040 noattr)))
                                        (Ty.Tstruct __3040 noattr)) _hi
                                      tulong) (Expr.Etempvar _t'130 tulong)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_skb_39
                                  s_kprog_arm64_entry_skb_54)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_skb_56 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Scall (some _t'98)
      (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                           cc_default))
      [(Expr.Econst_int (Integers.Int.repr 6) tint)])
    (Stmt.Sassign
      (Expr.Efield
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
            (Expr.Econst_int (Integers.Int.repr 15) tint)
            (tptr (Ty.Tstruct __3040 noattr))) (Ty.Tstruct __3040 noattr))
        _hi tulong) (Expr.Etempvar _t'98 tulong)))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Scall (some _t'99)
        (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                             cc_default))
        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
      (Stmt.Sassign
        (Expr.Efield
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
              (Expr.Econst_int (Integers.Int.repr 16) tint)
              (tptr (Ty.Tstruct __3040 noattr))) (Ty.Tstruct __3040 noattr))
          _lo tulong) (Expr.Etempvar _t'99 tulong)))
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Scall (some _t'100)
          (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                               cc_default))
          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
        (Stmt.Sassign
          (Expr.Efield
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                (Expr.Econst_int (Integers.Int.repr 16) tint)
                (tptr (Ty.Tstruct __3040 noattr)))
              (Ty.Tstruct __3040 noattr)) _hi tulong)
          (Expr.Etempvar _t'100 tulong)))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Scall (some _t'101)
            (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                 cc_default))
            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
          (Stmt.Sassign
            (Expr.Efield
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                  (Expr.Econst_int (Integers.Int.repr 17) tint)
                  (tptr (Ty.Tstruct __3040 noattr)))
                (Ty.Tstruct __3040 noattr)) _lo tulong)
            (Expr.Etempvar _t'101 tulong)))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Scall (some _t'102)
              (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                   cc_default))
              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
            (Stmt.Sassign
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                    (Expr.Econst_int (Integers.Int.repr 17) tint)
                    (tptr (Ty.Tstruct __3040 noattr)))
                  (Ty.Tstruct __3040 noattr)) _hi tulong)
              (Expr.Etempvar _t'102 tulong)))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Scall (some _t'103)
                (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                     tulong cc_default))
                [(Expr.Econst_int (Integers.Int.repr 6) tint)])
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                      (Expr.Econst_int (Integers.Int.repr 18) tint)
                      (tptr (Ty.Tstruct __3040 noattr)))
                    (Ty.Tstruct __3040 noattr)) _lo tulong)
                (Expr.Etempvar _t'103 tulong)))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Scall (some _t'104)
                  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                       tulong cc_default))
                  [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                (Stmt.Sassign
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                        (Expr.Econst_int (Integers.Int.repr 18) tint)
                        (tptr (Ty.Tstruct __3040 noattr)))
                      (Ty.Tstruct __3040 noattr)) _hi tulong)
                  (Expr.Etempvar _t'104 tulong)))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Scall (some _t'105)
                    (Expr.Evar _native_lab_entry_input (Ty.Tfunction 
                                                         [tuint] tulong
                                                         cc_default))
                    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                  (Stmt.Sassign
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                          (Expr.Econst_int (Integers.Int.repr 19) tint)
                          (tptr (Ty.Tstruct __3040 noattr)))
                        (Ty.Tstruct __3040 noattr)) _lo tulong)
                    (Expr.Etempvar _t'105 tulong)))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Scall (some _t'106)
                      (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                           [tuint] tulong
                                                           cc_default))
                      [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                    (Stmt.Sassign
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                            (Expr.Econst_int (Integers.Int.repr 19) tint)
                            (tptr (Ty.Tstruct __3040 noattr)))
                          (Ty.Tstruct __3040 noattr)) _hi tulong)
                      (Expr.Etempvar _t'106 tulong)))
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Scall (some _t'107)
                        (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                             [tuint] tulong
                                                             cc_default))
                        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                      (Stmt.Sassign
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                              (Expr.Econst_int (Integers.Int.repr 20) tint)
                              (tptr (Ty.Tstruct __3040 noattr)))
                            (Ty.Tstruct __3040 noattr)) _lo tulong)
                        (Expr.Etempvar _t'107 tulong)))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Scall (some _t'108)
                          (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                               [tuint] tulong
                                                               cc_default))
                          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                                (Expr.Econst_int (Integers.Int.repr 20) tint)
                                (tptr (Ty.Tstruct __3040 noattr)))
                              (Ty.Tstruct __3040 noattr)) _hi tulong)
                          (Expr.Etempvar _t'108 tulong)))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'109)
                            (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                 [tuint]
                                                                 tulong
                                                                 cc_default))
                            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                                  (Expr.Econst_int (Integers.Int.repr 21) tint)
                                  (tptr (Ty.Tstruct __3040 noattr)))
                                (Ty.Tstruct __3040 noattr)) _lo tulong)
                            (Expr.Etempvar _t'109 tulong)))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Scall (some _t'110)
                              (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                   [tuint]
                                                                   tulong
                                                                   cc_default))
                              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                                    (Expr.Econst_int (Integers.Int.repr 21) tint)
                                    (tptr (Ty.Tstruct __3040 noattr)))
                                  (Ty.Tstruct __3040 noattr)) _hi tulong)
                              (Expr.Etempvar _t'110 tulong)))
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Scall (some _t'111)
                                (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                    [tuint]
                                                                    tulong
                                                                    cc_default))
                                [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                                      (Expr.Econst_int (Integers.Int.repr 22) tint)
                                      (tptr (Ty.Tstruct __3040 noattr)))
                                    (Ty.Tstruct __3040 noattr)) _lo tulong)
                                (Expr.Etempvar _t'111 tulong)))
                            (Stmt.Ssequence
                              (Stmt.Ssequence
                                (Stmt.Scall (some _t'112)
                                  (Expr.Evar _native_lab_entry_input 
                                  (Ty.Tfunction [tuint] tulong cc_default))
                                  [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                                (Stmt.Sassign
                                  (Expr.Efield
                                    (Expr.Ederef
                                      (Expr.Ebinop Binop.Oadd
                                        (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                                        (Expr.Econst_int (Integers.Int.repr 22) tint)
                                        (tptr (Ty.Tstruct __3040 noattr)))
                                      (Ty.Tstruct __3040 noattr)) _hi tulong)
                                  (Expr.Etempvar _t'112 tulong)))
                              (Stmt.Ssequence
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_skb_36
                                  (Stmt.Sassign
                                    (Expr.Efield
                                      (Expr.Ederef
                                        (Expr.Ebinop Binop.Oadd
                                          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                                          (Expr.Econst_int (Integers.Int.repr 23) tint)
                                          (tptr (Ty.Tstruct __3040 noattr)))
                                        (Ty.Tstruct __3040 noattr)) _lo
                                      tulong) (Expr.Etempvar _t'113 tulong)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_skb_37
                                  s_kprog_arm64_entry_skb_55)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_skb_57 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Scall (some _t'81)
      (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                           cc_default))
      [(Expr.Econst_int (Integers.Int.repr 6) tint)])
    (Stmt.Sassign
      (Expr.Efield
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
            (Expr.Econst_int (Integers.Int.repr 7) tint)
            (tptr (Ty.Tstruct __3040 noattr))) (Ty.Tstruct __3040 noattr))
        _lo tulong) (Expr.Etempvar _t'81 tulong)))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Scall (some _t'82)
        (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                             cc_default))
        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
      (Stmt.Sassign
        (Expr.Efield
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
              (Expr.Econst_int (Integers.Int.repr 7) tint)
              (tptr (Ty.Tstruct __3040 noattr))) (Ty.Tstruct __3040 noattr))
          _hi tulong) (Expr.Etempvar _t'82 tulong)))
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Scall (some _t'83)
          (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                               cc_default))
          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
        (Stmt.Sassign
          (Expr.Efield
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                (Expr.Econst_int (Integers.Int.repr 8) tint)
                (tptr (Ty.Tstruct __3040 noattr)))
              (Ty.Tstruct __3040 noattr)) _lo tulong)
          (Expr.Etempvar _t'83 tulong)))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Scall (some _t'84)
            (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                 cc_default))
            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
          (Stmt.Sassign
            (Expr.Efield
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                  (Expr.Econst_int (Integers.Int.repr 8) tint)
                  (tptr (Ty.Tstruct __3040 noattr)))
                (Ty.Tstruct __3040 noattr)) _hi tulong)
            (Expr.Etempvar _t'84 tulong)))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Scall (some _t'85)
              (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                   cc_default))
              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
            (Stmt.Sassign
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                    (Expr.Econst_int (Integers.Int.repr 9) tint)
                    (tptr (Ty.Tstruct __3040 noattr)))
                  (Ty.Tstruct __3040 noattr)) _lo tulong)
              (Expr.Etempvar _t'85 tulong)))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Scall (some _t'86)
                (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                     tulong cc_default))
                [(Expr.Econst_int (Integers.Int.repr 6) tint)])
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                      (Expr.Econst_int (Integers.Int.repr 9) tint)
                      (tptr (Ty.Tstruct __3040 noattr)))
                    (Ty.Tstruct __3040 noattr)) _hi tulong)
                (Expr.Etempvar _t'86 tulong)))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Scall (some _t'87)
                  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                       tulong cc_default))
                  [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                (Stmt.Sassign
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                        (Expr.Econst_int (Integers.Int.repr 10) tint)
                        (tptr (Ty.Tstruct __3040 noattr)))
                      (Ty.Tstruct __3040 noattr)) _lo tulong)
                  (Expr.Etempvar _t'87 tulong)))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Scall (some _t'88)
                    (Expr.Evar _native_lab_entry_input (Ty.Tfunction 
                                                         [tuint] tulong
                                                         cc_default))
                    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                  (Stmt.Sassign
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                          (Expr.Econst_int (Integers.Int.repr 10) tint)
                          (tptr (Ty.Tstruct __3040 noattr)))
                        (Ty.Tstruct __3040 noattr)) _hi tulong)
                    (Expr.Etempvar _t'88 tulong)))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Scall (some _t'89)
                      (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                           [tuint] tulong
                                                           cc_default))
                      [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                    (Stmt.Sassign
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                            (Expr.Econst_int (Integers.Int.repr 11) tint)
                            (tptr (Ty.Tstruct __3040 noattr)))
                          (Ty.Tstruct __3040 noattr)) _lo tulong)
                      (Expr.Etempvar _t'89 tulong)))
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Scall (some _t'90)
                        (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                             [tuint] tulong
                                                             cc_default))
                        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                      (Stmt.Sassign
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                              (Expr.Econst_int (Integers.Int.repr 11) tint)
                              (tptr (Ty.Tstruct __3040 noattr)))
                            (Ty.Tstruct __3040 noattr)) _hi tulong)
                        (Expr.Etempvar _t'90 tulong)))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Scall (some _t'91)
                          (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                               [tuint] tulong
                                                               cc_default))
                          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                                (Expr.Econst_int (Integers.Int.repr 12) tint)
                                (tptr (Ty.Tstruct __3040 noattr)))
                              (Ty.Tstruct __3040 noattr)) _lo tulong)
                          (Expr.Etempvar _t'91 tulong)))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'92)
                            (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                 [tuint]
                                                                 tulong
                                                                 cc_default))
                            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                                  (Expr.Econst_int (Integers.Int.repr 12) tint)
                                  (tptr (Ty.Tstruct __3040 noattr)))
                                (Ty.Tstruct __3040 noattr)) _hi tulong)
                            (Expr.Etempvar _t'92 tulong)))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Scall (some _t'93)
                              (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                   [tuint]
                                                                   tulong
                                                                   cc_default))
                              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                                    (Expr.Econst_int (Integers.Int.repr 13) tint)
                                    (tptr (Ty.Tstruct __3040 noattr)))
                                  (Ty.Tstruct __3040 noattr)) _lo tulong)
                              (Expr.Etempvar _t'93 tulong)))
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Scall (some _t'94)
                                (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                    [tuint]
                                                                    tulong
                                                                    cc_default))
                                [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                                      (Expr.Econst_int (Integers.Int.repr 13) tint)
                                      (tptr (Ty.Tstruct __3040 noattr)))
                                    (Ty.Tstruct __3040 noattr)) _hi tulong)
                                (Expr.Etempvar _t'94 tulong)))
                            (Stmt.Ssequence
                              (Stmt.Ssequence
                                (Stmt.Scall (some _t'95)
                                  (Expr.Evar _native_lab_entry_input 
                                  (Ty.Tfunction [tuint] tulong cc_default))
                                  [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                                (Stmt.Sassign
                                  (Expr.Efield
                                    (Expr.Ederef
                                      (Expr.Ebinop Binop.Oadd
                                        (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                                        (Expr.Econst_int (Integers.Int.repr 14) tint)
                                        (tptr (Ty.Tstruct __3040 noattr)))
                                      (Ty.Tstruct __3040 noattr)) _lo tulong)
                                  (Expr.Etempvar _t'95 tulong)))
                              (Stmt.Ssequence
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_skb_34
                                  (Stmt.Sassign
                                    (Expr.Efield
                                      (Expr.Ederef
                                        (Expr.Ebinop Binop.Oadd
                                          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                                          (Expr.Econst_int (Integers.Int.repr 14) tint)
                                          (tptr (Ty.Tstruct __3040 noattr)))
                                        (Ty.Tstruct __3040 noattr)) _hi
                                      tulong) (Expr.Etempvar _t'96 tulong)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_skb_35
                                  s_kprog_arm64_entry_skb_56)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_skb_58 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Scall (some _t'65)
      (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                           cc_default))
      [(Expr.Econst_int (Integers.Int.repr 6) tint)])
    (Stmt.Sassign (Expr.Evar ___a64_c tuchar)
      (Expr.Ebinop Binop.Oand (Expr.Etempvar _t'65 tulong)
        (Expr.Econst_int (Integers.Int.repr 1) tint) tulong)))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Scall (some _t'66)
        (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                             cc_default))
        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
      (Stmt.Sassign (Expr.Evar ___a64_v tuchar)
        (Expr.Ebinop Binop.Oand (Expr.Etempvar _t'66 tulong)
          (Expr.Econst_int (Integers.Int.repr 1) tint) tulong)))
    (Stmt.Ssequence
      (Stmt.Sassign (Expr.Evar ___a64_lr tulong)
        (Expr.Econst_int (Integers.Int.repr 0) tint))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Scall (some _t'67)
            (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                 cc_default))
            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
          (Stmt.Sassign
            (Expr.Efield
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                  (Expr.Econst_int (Integers.Int.repr 0) tint)
                  (tptr (Ty.Tstruct __3040 noattr)))
                (Ty.Tstruct __3040 noattr)) _lo tulong)
            (Expr.Etempvar _t'67 tulong)))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Scall (some _t'68)
              (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                   cc_default))
              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
            (Stmt.Sassign
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                    (Expr.Econst_int (Integers.Int.repr 0) tint)
                    (tptr (Ty.Tstruct __3040 noattr)))
                  (Ty.Tstruct __3040 noattr)) _hi tulong)
              (Expr.Etempvar _t'68 tulong)))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Scall (some _t'69)
                (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                     tulong cc_default))
                [(Expr.Econst_int (Integers.Int.repr 6) tint)])
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                      (Expr.Econst_int (Integers.Int.repr 1) tint)
                      (tptr (Ty.Tstruct __3040 noattr)))
                    (Ty.Tstruct __3040 noattr)) _lo tulong)
                (Expr.Etempvar _t'69 tulong)))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Scall (some _t'70)
                  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                       tulong cc_default))
                  [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                (Stmt.Sassign
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                        (Expr.Econst_int (Integers.Int.repr 1) tint)
                        (tptr (Ty.Tstruct __3040 noattr)))
                      (Ty.Tstruct __3040 noattr)) _hi tulong)
                  (Expr.Etempvar _t'70 tulong)))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Scall (some _t'71)
                    (Expr.Evar _native_lab_entry_input (Ty.Tfunction 
                                                         [tuint] tulong
                                                         cc_default))
                    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                  (Stmt.Sassign
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                          (Expr.Econst_int (Integers.Int.repr 2) tint)
                          (tptr (Ty.Tstruct __3040 noattr)))
                        (Ty.Tstruct __3040 noattr)) _lo tulong)
                    (Expr.Etempvar _t'71 tulong)))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Scall (some _t'72)
                      (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                           [tuint] tulong
                                                           cc_default))
                      [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                    (Stmt.Sassign
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                            (Expr.Econst_int (Integers.Int.repr 2) tint)
                            (tptr (Ty.Tstruct __3040 noattr)))
                          (Ty.Tstruct __3040 noattr)) _hi tulong)
                      (Expr.Etempvar _t'72 tulong)))
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Scall (some _t'73)
                        (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                             [tuint] tulong
                                                             cc_default))
                        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                      (Stmt.Sassign
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                              (Expr.Econst_int (Integers.Int.repr 3) tint)
                              (tptr (Ty.Tstruct __3040 noattr)))
                            (Ty.Tstruct __3040 noattr)) _lo tulong)
                        (Expr.Etempvar _t'73 tulong)))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Scall (some _t'74)
                          (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                               [tuint] tulong
                                                               cc_default))
                          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                                (Expr.Econst_int (Integers.Int.repr 3) tint)
                                (tptr (Ty.Tstruct __3040 noattr)))
                              (Ty.Tstruct __3040 noattr)) _hi tulong)
                          (Expr.Etempvar _t'74 tulong)))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'75)
                            (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                 [tuint]
                                                                 tulong
                                                                 cc_default))
                            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                                  (Expr.Econst_int (Integers.Int.repr 4) tint)
                                  (tptr (Ty.Tstruct __3040 noattr)))
                                (Ty.Tstruct __3040 noattr)) _lo tulong)
                            (Expr.Etempvar _t'75 tulong)))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Scall (some _t'76)
                              (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                   [tuint]
                                                                   tulong
                                                                   cc_default))
                              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                                    (Expr.Econst_int (Integers.Int.repr 4) tint)
                                    (tptr (Ty.Tstruct __3040 noattr)))
                                  (Ty.Tstruct __3040 noattr)) _hi tulong)
                              (Expr.Etempvar _t'76 tulong)))
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Scall (some _t'77)
                                (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                    [tuint]
                                                                    tulong
                                                                    cc_default))
                                [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                                      (Expr.Econst_int (Integers.Int.repr 5) tint)
                                      (tptr (Ty.Tstruct __3040 noattr)))
                                    (Ty.Tstruct __3040 noattr)) _lo tulong)
                                (Expr.Etempvar _t'77 tulong)))
                            (Stmt.Ssequence
                              (Stmt.Ssequence
                                (Stmt.Scall (some _t'78)
                                  (Expr.Evar _native_lab_entry_input 
                                  (Ty.Tfunction [tuint] tulong cc_default))
                                  [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                                (Stmt.Sassign
                                  (Expr.Efield
                                    (Expr.Ederef
                                      (Expr.Ebinop Binop.Oadd
                                        (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                                        (Expr.Econst_int (Integers.Int.repr 5) tint)
                                        (tptr (Ty.Tstruct __3040 noattr)))
                                      (Ty.Tstruct __3040 noattr)) _hi tulong)
                                  (Expr.Etempvar _t'78 tulong)))
                              (Stmt.Ssequence
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_skb_32
                                  (Stmt.Sassign
                                    (Expr.Efield
                                      (Expr.Ederef
                                        (Expr.Ebinop Binop.Oadd
                                          (Expr.Evar ___a64_vectors (tarray (Ty.Tstruct __3040 noattr) 32))
                                          (Expr.Econst_int (Integers.Int.repr 6) tint)
                                          (tptr (Ty.Tstruct __3040 noattr)))
                                        (Ty.Tstruct __3040 noattr)) _lo
                                      tulong) (Expr.Etempvar _t'79 tulong)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_skb_33
                                  s_kprog_arm64_entry_skb_57)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_skb_59 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
        (Expr.Econst_int (Integers.Int.repr 16) tint) (tptr (tptr tuchar)))
      (tptr tuchar))
    (Expr.Eaddrof (Expr.Evar ___a64_x16_tag tuchar) (tptr tuchar)))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
          (Expr.Econst_int (Integers.Int.repr 17) tint) (tptr (tptr tuchar)))
        (tptr tuchar))
      (Expr.Eaddrof (Expr.Evar ___a64_x17_tag tuchar) (tptr tuchar)))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
            (Expr.Econst_int (Integers.Int.repr 18) tint)
            (tptr (tptr tuchar))) (tptr tuchar))
        (Expr.Eaddrof (Expr.Evar ___a64_x18_tag tuchar) (tptr tuchar)))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
              (Expr.Econst_int (Integers.Int.repr 19) tint)
              (tptr (tptr tuchar))) (tptr tuchar))
          (Expr.Eaddrof (Expr.Evar ___a64_x19_tag tuchar) (tptr tuchar)))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                (Expr.Econst_int (Integers.Int.repr 20) tint)
                (tptr (tptr tuchar))) (tptr tuchar))
            (Expr.Eaddrof (Expr.Evar ___a64_x20_tag tuchar) (tptr tuchar)))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                  (Expr.Econst_int (Integers.Int.repr 21) tint)
                  (tptr (tptr tuchar))) (tptr tuchar))
              (Expr.Eaddrof (Expr.Evar ___a64_x21_tag tuchar) (tptr tuchar)))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                    (Expr.Econst_int (Integers.Int.repr 22) tint)
                    (tptr (tptr tuchar))) (tptr tuchar))
                (Expr.Eaddrof (Expr.Evar ___a64_x22_tag tuchar)
                  (tptr tuchar)))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                      (Expr.Econst_int (Integers.Int.repr 23) tint)
                      (tptr (tptr tuchar))) (tptr tuchar))
                  (Expr.Eaddrof (Expr.Evar ___a64_x23_tag tuchar)
                    (tptr tuchar)))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                        (Expr.Econst_int (Integers.Int.repr 24) tint)
                        (tptr (tptr tuchar))) (tptr tuchar))
                    (Expr.Eaddrof (Expr.Evar ___a64_x24_tag tuchar)
                      (tptr tuchar)))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                          (Expr.Econst_int (Integers.Int.repr 25) tint)
                          (tptr (tptr tuchar))) (tptr tuchar))
                      (Expr.Eaddrof (Expr.Evar ___a64_x25_tag tuchar)
                        (tptr tuchar)))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                            (Expr.Econst_int (Integers.Int.repr 26) tint)
                            (tptr (tptr tuchar))) (tptr tuchar))
                        (Expr.Eaddrof (Expr.Evar ___a64_x26_tag tuchar)
                          (tptr tuchar)))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                              (Expr.Econst_int (Integers.Int.repr 27) tint)
                              (tptr (tptr tuchar))) (tptr tuchar))
                          (Expr.Eaddrof (Expr.Evar ___a64_x27_tag tuchar)
                            (tptr tuchar)))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                (Expr.Econst_int (Integers.Int.repr 28) tint)
                                (tptr (tptr tuchar))) (tptr tuchar))
                            (Expr.Eaddrof (Expr.Evar ___a64_x28_tag tuchar)
                              (tptr tuchar)))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                  (Expr.Econst_int (Integers.Int.repr 29) tint)
                                  (tptr (tptr tuchar))) (tptr tuchar))
                              (Expr.Eaddrof (Expr.Evar ___a64_x29_tag tuchar)
                                (tptr tuchar)))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                    (Expr.Econst_int (Integers.Int.repr 30) tint)
                                    (tptr (tptr tuchar))) (tptr tuchar))
                                (Expr.Eaddrof
                                  (Expr.Evar ___a64_x30_tag tuchar)
                                  (tptr tuchar)))
                              (Stmt.Ssequence
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_skb_30
                                  (Stmt.Sassign (Expr.Evar ___a64_n tuchar)
                                    (Expr.Ebinop Binop.Oand
                                      (Expr.Etempvar _t'63 tulong)
                                      (Expr.Econst_int (Integers.Int.repr 1) tint)
                                      tulong)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_skb_31
                                  s_kprog_arm64_entry_skb_58)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_skb_60 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
        (Expr.Econst_int (Integers.Int.repr 30) tint)
        (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
      (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
    (Expr.Eaddrof (Expr.Evar ___a64_x30 (Ty.Tunion _arm64_sim_gpr noattr))
      (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
          (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr (tptr tuchar)))
        (tptr tuchar))
      (Expr.Eaddrof (Expr.Evar ___a64_x0_tag tuchar) (tptr tuchar)))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
            (Expr.Econst_int (Integers.Int.repr 1) tint)
            (tptr (tptr tuchar))) (tptr tuchar))
        (Expr.Eaddrof (Expr.Evar ___a64_x1_tag tuchar) (tptr tuchar)))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
              (Expr.Econst_int (Integers.Int.repr 2) tint)
              (tptr (tptr tuchar))) (tptr tuchar))
          (Expr.Eaddrof (Expr.Evar ___a64_x2_tag tuchar) (tptr tuchar)))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                (Expr.Econst_int (Integers.Int.repr 3) tint)
                (tptr (tptr tuchar))) (tptr tuchar))
            (Expr.Eaddrof (Expr.Evar ___a64_x3_tag tuchar) (tptr tuchar)))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                  (Expr.Econst_int (Integers.Int.repr 4) tint)
                  (tptr (tptr tuchar))) (tptr tuchar))
              (Expr.Eaddrof (Expr.Evar ___a64_x4_tag tuchar) (tptr tuchar)))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                    (Expr.Econst_int (Integers.Int.repr 5) tint)
                    (tptr (tptr tuchar))) (tptr tuchar))
                (Expr.Eaddrof (Expr.Evar ___a64_x5_tag tuchar) (tptr tuchar)))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                      (Expr.Econst_int (Integers.Int.repr 6) tint)
                      (tptr (tptr tuchar))) (tptr tuchar))
                  (Expr.Eaddrof (Expr.Evar ___a64_x6_tag tuchar)
                    (tptr tuchar)))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                        (Expr.Econst_int (Integers.Int.repr 7) tint)
                        (tptr (tptr tuchar))) (tptr tuchar))
                    (Expr.Eaddrof (Expr.Evar ___a64_x7_tag tuchar)
                      (tptr tuchar)))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                          (Expr.Econst_int (Integers.Int.repr 8) tint)
                          (tptr (tptr tuchar))) (tptr tuchar))
                      (Expr.Eaddrof (Expr.Evar ___a64_x8_tag tuchar)
                        (tptr tuchar)))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                            (Expr.Econst_int (Integers.Int.repr 9) tint)
                            (tptr (tptr tuchar))) (tptr tuchar))
                        (Expr.Eaddrof (Expr.Evar ___a64_x9_tag tuchar)
                          (tptr tuchar)))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                              (Expr.Econst_int (Integers.Int.repr 10) tint)
                              (tptr (tptr tuchar))) (tptr tuchar))
                          (Expr.Eaddrof (Expr.Evar ___a64_x10_tag tuchar)
                            (tptr tuchar)))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                (Expr.Econst_int (Integers.Int.repr 11) tint)
                                (tptr (tptr tuchar))) (tptr tuchar))
                            (Expr.Eaddrof (Expr.Evar ___a64_x11_tag tuchar)
                              (tptr tuchar)))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                  (Expr.Econst_int (Integers.Int.repr 12) tint)
                                  (tptr (tptr tuchar))) (tptr tuchar))
                              (Expr.Eaddrof (Expr.Evar ___a64_x12_tag tuchar)
                                (tptr tuchar)))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                    (Expr.Econst_int (Integers.Int.repr 13) tint)
                                    (tptr (tptr tuchar))) (tptr tuchar))
                                (Expr.Eaddrof
                                  (Expr.Evar ___a64_x13_tag tuchar)
                                  (tptr tuchar)))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Evar ___a64_tag_cells (tarray (tptr tuchar) 31))
                                      (Expr.Econst_int (Integers.Int.repr 14) tint)
                                      (tptr (tptr tuchar))) (tptr tuchar))
                                  (Expr.Eaddrof
                                    (Expr.Evar ___a64_x14_tag tuchar)
                                    (tptr tuchar)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_skb_29
                                  s_kprog_arm64_entry_skb_59)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_skb_61 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
        (Expr.Econst_int (Integers.Int.repr 13) tint)
        (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
      (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
    (Expr.Eaddrof (Expr.Evar ___a64_x13 (Ty.Tunion _arm64_sim_gpr noattr))
      (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
          (Expr.Econst_int (Integers.Int.repr 14) tint)
          (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
        (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
      (Expr.Eaddrof (Expr.Evar ___a64_x14 (Ty.Tunion _arm64_sim_gpr noattr))
        (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
            (Expr.Econst_int (Integers.Int.repr 15) tint)
            (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
          (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
        (Expr.Eaddrof
          (Expr.Evar ___a64_x15 (Ty.Tunion _arm64_sim_gpr noattr))
          (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
              (Expr.Econst_int (Integers.Int.repr 16) tint)
              (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
            (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
          (Expr.Eaddrof
            (Expr.Evar ___a64_x16 (Ty.Tunion _arm64_sim_gpr noattr))
            (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                (Expr.Econst_int (Integers.Int.repr 17) tint)
                (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
              (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
            (Expr.Eaddrof
              (Expr.Evar ___a64_x17 (Ty.Tunion _arm64_sim_gpr noattr))
              (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                  (Expr.Econst_int (Integers.Int.repr 18) tint)
                  (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
              (Expr.Eaddrof
                (Expr.Evar ___a64_x18 (Ty.Tunion _arm64_sim_gpr noattr))
                (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                    (Expr.Econst_int (Integers.Int.repr 19) tint)
                    (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                  (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                (Expr.Eaddrof
                  (Expr.Evar ___a64_x19 (Ty.Tunion _arm64_sim_gpr noattr))
                  (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                      (Expr.Econst_int (Integers.Int.repr 20) tint)
                      (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                    (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                  (Expr.Eaddrof
                    (Expr.Evar ___a64_x20 (Ty.Tunion _arm64_sim_gpr noattr))
                    (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                        (Expr.Econst_int (Integers.Int.repr 21) tint)
                        (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                      (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                    (Expr.Eaddrof
                      (Expr.Evar ___a64_x21 (Ty.Tunion _arm64_sim_gpr noattr))
                      (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                          (Expr.Econst_int (Integers.Int.repr 22) tint)
                          (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                        (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                      (Expr.Eaddrof
                        (Expr.Evar ___a64_x22 (Ty.Tunion _arm64_sim_gpr noattr))
                        (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                            (Expr.Econst_int (Integers.Int.repr 23) tint)
                            (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                          (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                        (Expr.Eaddrof
                          (Expr.Evar ___a64_x23 (Ty.Tunion _arm64_sim_gpr noattr))
                          (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                              (Expr.Econst_int (Integers.Int.repr 24) tint)
                              (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                            (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                          (Expr.Eaddrof
                            (Expr.Evar ___a64_x24 (Ty.Tunion _arm64_sim_gpr noattr))
                            (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                (Expr.Econst_int (Integers.Int.repr 25) tint)
                                (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                              (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                            (Expr.Eaddrof
                              (Expr.Evar ___a64_x25 (Ty.Tunion _arm64_sim_gpr noattr))
                              (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                  (Expr.Econst_int (Integers.Int.repr 26) tint)
                                  (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                              (Expr.Eaddrof
                                (Expr.Evar ___a64_x26 (Ty.Tunion _arm64_sim_gpr noattr))
                                (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                    (Expr.Econst_int (Integers.Int.repr 27) tint)
                                    (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                  (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                                (Expr.Eaddrof
                                  (Expr.Evar ___a64_x27 (Ty.Tunion _arm64_sim_gpr noattr))
                                  (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                      (Expr.Econst_int (Integers.Int.repr 28) tint)
                                      (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                    (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                                  (Expr.Eaddrof
                                    (Expr.Evar ___a64_x28 (Ty.Tunion _arm64_sim_gpr noattr))
                                    (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_skb_28
                                  s_kprog_arm64_entry_skb_60)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_skb_62 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                        (Expr.Econst_int (Integers.Int.repr 29) tuint)
                        (Expr.Econst_int (Integers.Int.repr 30) tuint) tint)
      (Stmt.Sset _t'59
        (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong) tulong))
      (Stmt.Ssequence
        (Stmt.Scall (some _t'60)
          (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                               cc_default))
          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
        (Stmt.Sset _t'59 (Expr.Ecast (Expr.Etempvar _t'60 tulong) tulong))))
    (Stmt.Sassign
      (Expr.Efield (Expr.Evar ___a64_x29 (Ty.Tunion _arm64_sim_gpr noattr))
        _x tulong) (Expr.Etempvar _t'59 tulong)))
  (Stmt.Ssequence
    (Stmt.Sassign (Expr.Evar ___a64_x29_tag tuchar)
      (Expr.Econst_int (Integers.Int.repr 0) tuint))
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Econst_int (Integers.Int.repr 30) tuint)
                            (Expr.Econst_int (Integers.Int.repr 30) tuint)
                            tint)
          (Stmt.Sset _t'61
            (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong)
              tulong))
          (Stmt.Ssequence
            (Stmt.Scall (some _t'62)
              (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                   cc_default))
              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
            (Stmt.Sset _t'61
              (Expr.Ecast (Expr.Etempvar _t'62 tulong) tulong))))
        (Stmt.Sassign
          (Expr.Efield
            (Expr.Evar ___a64_x30 (Ty.Tunion _arm64_sim_gpr noattr)) _x
            tulong) (Expr.Etempvar _t'61 tulong)))
      (Stmt.Ssequence
        (Stmt.Sassign (Expr.Evar ___a64_x30_tag tuchar)
          (Expr.Econst_int (Integers.Int.repr 0) tuint))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                (Expr.Econst_int (Integers.Int.repr 0) tint)
                (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
              (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
            (Expr.Eaddrof
              (Expr.Evar ___a64_x0 (Ty.Tunion _arm64_sim_gpr noattr))
              (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                  (Expr.Econst_int (Integers.Int.repr 1) tint)
                  (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
              (Expr.Eaddrof
                (Expr.Evar ___a64_x1 (Ty.Tunion _arm64_sim_gpr noattr))
                (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                    (Expr.Econst_int (Integers.Int.repr 2) tint)
                    (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                  (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                (Expr.Eaddrof
                  (Expr.Evar ___a64_x2 (Ty.Tunion _arm64_sim_gpr noattr))
                  (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                      (Expr.Econst_int (Integers.Int.repr 3) tint)
                      (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                    (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                  (Expr.Eaddrof
                    (Expr.Evar ___a64_x3 (Ty.Tunion _arm64_sim_gpr noattr))
                    (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                        (Expr.Econst_int (Integers.Int.repr 4) tint)
                        (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                      (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                    (Expr.Eaddrof
                      (Expr.Evar ___a64_x4 (Ty.Tunion _arm64_sim_gpr noattr))
                      (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                          (Expr.Econst_int (Integers.Int.repr 5) tint)
                          (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                        (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                      (Expr.Eaddrof
                        (Expr.Evar ___a64_x5 (Ty.Tunion _arm64_sim_gpr noattr))
                        (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                            (Expr.Econst_int (Integers.Int.repr 6) tint)
                            (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                          (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                        (Expr.Eaddrof
                          (Expr.Evar ___a64_x6 (Ty.Tunion _arm64_sim_gpr noattr))
                          (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                              (Expr.Econst_int (Integers.Int.repr 7) tint)
                              (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                            (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                          (Expr.Eaddrof
                            (Expr.Evar ___a64_x7 (Ty.Tunion _arm64_sim_gpr noattr))
                            (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                (Expr.Econst_int (Integers.Int.repr 8) tint)
                                (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                              (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                            (Expr.Eaddrof
                              (Expr.Evar ___a64_x8 (Ty.Tunion _arm64_sim_gpr noattr))
                              (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                  (Expr.Econst_int (Integers.Int.repr 9) tint)
                                  (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                              (Expr.Eaddrof
                                (Expr.Evar ___a64_x9 (Ty.Tunion _arm64_sim_gpr noattr))
                                (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                    (Expr.Econst_int (Integers.Int.repr 10) tint)
                                    (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                  (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                                (Expr.Eaddrof
                                  (Expr.Evar ___a64_x10 (Ty.Tunion _arm64_sim_gpr noattr))
                                  (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Evar ___a64_cells (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31))
                                      (Expr.Econst_int (Integers.Int.repr 11) tint)
                                      (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                    (tptr (Ty.Tunion _arm64_sim_gpr noattr)))
                                  (Expr.Eaddrof
                                    (Expr.Evar ___a64_x11 (Ty.Tunion _arm64_sim_gpr noattr))
                                    (tptr (Ty.Tunion _arm64_sim_gpr noattr))))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_skb_27
                                  s_kprog_arm64_entry_skb_61)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_skb_63 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign (Expr.Evar ___a64_x20_tag tuchar)
    (Expr.Econst_int (Integers.Int.repr 0) tuint))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                          (Expr.Econst_int (Integers.Int.repr 21) tuint)
                          (Expr.Econst_int (Integers.Int.repr 30) tuint)
                          tint)
        (Stmt.Sset _t'43
          (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong)
            tulong))
        (Stmt.Ssequence
          (Stmt.Scall (some _t'44)
            (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                 cc_default))
            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
          (Stmt.Sset _t'43 (Expr.Ecast (Expr.Etempvar _t'44 tulong) tulong))))
      (Stmt.Sassign
        (Expr.Efield (Expr.Evar ___a64_x21 (Ty.Tunion _arm64_sim_gpr noattr))
          _x tulong) (Expr.Etempvar _t'43 tulong)))
    (Stmt.Ssequence
      (Stmt.Sassign (Expr.Evar ___a64_x21_tag tuchar)
        (Expr.Econst_int (Integers.Int.repr 0) tuint))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Econst_int (Integers.Int.repr 22) tuint)
                              (Expr.Econst_int (Integers.Int.repr 30) tuint)
                              tint)
            (Stmt.Sset _t'45
              (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                tulong))
            (Stmt.Ssequence
              (Stmt.Scall (some _t'46)
                (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                     tulong cc_default))
                [(Expr.Econst_int (Integers.Int.repr 6) tint)])
              (Stmt.Sset _t'45
                (Expr.Ecast (Expr.Etempvar _t'46 tulong) tulong))))
          (Stmt.Sassign
            (Expr.Efield
              (Expr.Evar ___a64_x22 (Ty.Tunion _arm64_sim_gpr noattr)) _x
              tulong) (Expr.Etempvar _t'45 tulong)))
        (Stmt.Ssequence
          (Stmt.Sassign (Expr.Evar ___a64_x22_tag tuchar)
            (Expr.Econst_int (Integers.Int.repr 0) tuint))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Econst_int (Integers.Int.repr 23) tuint)
                                  (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                  tint)
                (Stmt.Sset _t'47
                  (Expr.Ecast
                    (Expr.Econst_long (Integers.Int64.repr 0) tulong) tulong))
                (Stmt.Ssequence
                  (Stmt.Scall (some _t'48)
                    (Expr.Evar _native_lab_entry_input (Ty.Tfunction 
                                                         [tuint] tulong
                                                         cc_default))
                    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                  (Stmt.Sset _t'47
                    (Expr.Ecast (Expr.Etempvar _t'48 tulong) tulong))))
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Evar ___a64_x23 (Ty.Tunion _arm64_sim_gpr noattr)) _x
                  tulong) (Expr.Etempvar _t'47 tulong)))
            (Stmt.Ssequence
              (Stmt.Sassign (Expr.Evar ___a64_x23_tag tuchar)
                (Expr.Econst_int (Integers.Int.repr 0) tuint))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Econst_int (Integers.Int.repr 24) tuint)
                                      (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                      tint)
                    (Stmt.Sset _t'49
                      (Expr.Ecast
                        (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                        tulong))
                    (Stmt.Ssequence
                      (Stmt.Scall (some _t'50)
                        (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                             [tuint] tulong
                                                             cc_default))
                        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                      (Stmt.Sset _t'49
                        (Expr.Ecast (Expr.Etempvar _t'50 tulong) tulong))))
                  (Stmt.Sassign
                    (Expr.Efield
                      (Expr.Evar ___a64_x24 (Ty.Tunion _arm64_sim_gpr noattr))
                      _x tulong) (Expr.Etempvar _t'49 tulong)))
                (Stmt.Ssequence
                  (Stmt.Sassign (Expr.Evar ___a64_x24_tag tuchar)
                    (Expr.Econst_int (Integers.Int.repr 0) tuint))
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Econst_int (Integers.Int.repr 25) tuint)
                                          (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                          tint)
                        (Stmt.Sset _t'51
                          (Expr.Ecast
                            (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                            tulong))
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'52)
                            (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                 [tuint]
                                                                 tulong
                                                                 cc_default))
                            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                          (Stmt.Sset _t'51
                            (Expr.Ecast (Expr.Etempvar _t'52 tulong) tulong))))
                      (Stmt.Sassign
                        (Expr.Efield
                          (Expr.Evar ___a64_x25 (Ty.Tunion _arm64_sim_gpr noattr))
                          _x tulong) (Expr.Etempvar _t'51 tulong)))
                    (Stmt.Ssequence
                      (Stmt.Sassign (Expr.Evar ___a64_x25_tag tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tuint))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Econst_int (Integers.Int.repr 26) tuint)
                                              (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                              tint)
                            (Stmt.Sset _t'53
                              (Expr.Ecast
                                (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                                tulong))
                            (Stmt.Ssequence
                              (Stmt.Scall (some _t'54)
                                (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                    [tuint]
                                                                    tulong
                                                                    cc_default))
                                [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                              (Stmt.Sset _t'53
                                (Expr.Ecast (Expr.Etempvar _t'54 tulong)
                                  tulong))))
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Evar ___a64_x26 (Ty.Tunion _arm64_sim_gpr noattr))
                              _x tulong) (Expr.Etempvar _t'53 tulong)))
                        (Stmt.Ssequence
                          (Stmt.Sassign (Expr.Evar ___a64_x26_tag tuchar)
                            (Expr.Econst_int (Integers.Int.repr 0) tuint))
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                  (Expr.Econst_int (Integers.Int.repr 27) tuint)
                                                  (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                                  tint)
                                s_kprog_arm64_entry_skb_23
                                s_kprog_arm64_entry_skb_24)
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Evar ___a64_x27 (Ty.Tunion _arm64_sim_gpr noattr))
                                  _x tulong) (Expr.Etempvar _t'55 tulong)))
                            (Stmt.Ssequence
                              (Stmt.Sassign (Expr.Evar ___a64_x27_tag tuchar)
                                (Expr.Econst_int (Integers.Int.repr 0) tuint))
                              (Stmt.Ssequence
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_skb_25
                                  (Stmt.Sassign
                                    (Expr.Efield
                                      (Expr.Evar ___a64_x28 (Ty.Tunion _arm64_sim_gpr noattr))
                                      _x tulong)
                                    (Expr.Etempvar _t'57 tulong)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_skb_26
                                  s_kprog_arm64_entry_skb_62)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_skb_64 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                        (Expr.Econst_int (Integers.Int.repr 12) tuint)
                        (Expr.Econst_int (Integers.Int.repr 30) tuint) tint)
      (Stmt.Sset _t'25
        (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong) tulong))
      (Stmt.Ssequence
        (Stmt.Scall (some _t'26)
          (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                               cc_default))
          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
        (Stmt.Sset _t'25 (Expr.Ecast (Expr.Etempvar _t'26 tulong) tulong))))
    (Stmt.Sassign
      (Expr.Efield (Expr.Evar ___a64_x12 (Ty.Tunion _arm64_sim_gpr noattr))
        _x tulong) (Expr.Etempvar _t'25 tulong)))
  (Stmt.Ssequence
    (Stmt.Sassign (Expr.Evar ___a64_x12_tag tuchar)
      (Expr.Econst_int (Integers.Int.repr 0) tuint))
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Econst_int (Integers.Int.repr 13) tuint)
                            (Expr.Econst_int (Integers.Int.repr 30) tuint)
                            tint)
          (Stmt.Sset _t'27
            (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong)
              tulong))
          (Stmt.Ssequence
            (Stmt.Scall (some _t'28)
              (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                   cc_default))
              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
            (Stmt.Sset _t'27
              (Expr.Ecast (Expr.Etempvar _t'28 tulong) tulong))))
        (Stmt.Sassign
          (Expr.Efield
            (Expr.Evar ___a64_x13 (Ty.Tunion _arm64_sim_gpr noattr)) _x
            tulong) (Expr.Etempvar _t'27 tulong)))
      (Stmt.Ssequence
        (Stmt.Sassign (Expr.Evar ___a64_x13_tag tuchar)
          (Expr.Econst_int (Integers.Int.repr 0) tuint))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Econst_int (Integers.Int.repr 14) tuint)
                                (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                tint)
              (Stmt.Sset _t'29
                (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                  tulong))
              (Stmt.Ssequence
                (Stmt.Scall (some _t'30)
                  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                       tulong cc_default))
                  [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                (Stmt.Sset _t'29
                  (Expr.Ecast (Expr.Etempvar _t'30 tulong) tulong))))
            (Stmt.Sassign
              (Expr.Efield
                (Expr.Evar ___a64_x14 (Ty.Tunion _arm64_sim_gpr noattr)) _x
                tulong) (Expr.Etempvar _t'29 tulong)))
          (Stmt.Ssequence
            (Stmt.Sassign (Expr.Evar ___a64_x14_tag tuchar)
              (Expr.Econst_int (Integers.Int.repr 0) tuint))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Econst_int (Integers.Int.repr 15) tuint)
                                    (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                    tint)
                  (Stmt.Sset _t'31
                    (Expr.Ecast
                      (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                      tulong))
                  (Stmt.Ssequence
                    (Stmt.Scall (some _t'32)
                      (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                           [tuint] tulong
                                                           cc_default))
                      [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                    (Stmt.Sset _t'31
                      (Expr.Ecast (Expr.Etempvar _t'32 tulong) tulong))))
                (Stmt.Sassign
                  (Expr.Efield
                    (Expr.Evar ___a64_x15 (Ty.Tunion _arm64_sim_gpr noattr))
                    _x tulong) (Expr.Etempvar _t'31 tulong)))
              (Stmt.Ssequence
                (Stmt.Sassign (Expr.Evar ___a64_x15_tag tuchar)
                  (Expr.Econst_int (Integers.Int.repr 0) tuint))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                        (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                        tint)
                      (Stmt.Sset _t'33
                        (Expr.Ecast
                          (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                          tulong))
                      (Stmt.Ssequence
                        (Stmt.Scall (some _t'34)
                          (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                               [tuint] tulong
                                                               cc_default))
                          [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                        (Stmt.Sset _t'33
                          (Expr.Ecast (Expr.Etempvar _t'34 tulong) tulong))))
                    (Stmt.Sassign
                      (Expr.Efield
                        (Expr.Evar ___a64_x16 (Ty.Tunion _arm64_sim_gpr noattr))
                        _x tulong) (Expr.Etempvar _t'33 tulong)))
                  (Stmt.Ssequence
                    (Stmt.Sassign (Expr.Evar ___a64_x16_tag tuchar)
                      (Expr.Econst_int (Integers.Int.repr 0) tuint))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Econst_int (Integers.Int.repr 17) tuint)
                                            (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                            tint)
                          (Stmt.Sset _t'35
                            (Expr.Ecast
                              (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                              tulong))
                          (Stmt.Ssequence
                            (Stmt.Scall (some _t'36)
                              (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                   [tuint]
                                                                   tulong
                                                                   cc_default))
                              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                            (Stmt.Sset _t'35
                              (Expr.Ecast (Expr.Etempvar _t'36 tulong)
                                tulong))))
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Evar ___a64_x17 (Ty.Tunion _arm64_sim_gpr noattr))
                            _x tulong) (Expr.Etempvar _t'35 tulong)))
                      (Stmt.Ssequence
                        (Stmt.Sassign (Expr.Evar ___a64_x17_tag tuchar)
                          (Expr.Econst_int (Integers.Int.repr 0) tuint))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                (Expr.Econst_int (Integers.Int.repr 18) tuint)
                                                (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                                tint)
                              (Stmt.Sset _t'37
                                (Expr.Ecast
                                  (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                                  tulong))
                              (Stmt.Ssequence
                                s_kprog_arm64_entry_skb_19
                                (Stmt.Sset _t'37
                                  (Expr.Ecast (Expr.Etempvar _t'38 tulong)
                                    tulong))))
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Evar ___a64_x18 (Ty.Tunion _arm64_sim_gpr noattr))
                                _x tulong) (Expr.Etempvar _t'37 tulong)))
                          (Stmt.Ssequence
                            (Stmt.Sassign (Expr.Evar ___a64_x18_tag tuchar)
                              (Expr.Econst_int (Integers.Int.repr 0) tuint))
                            (Stmt.Ssequence
                              (Stmt.Ssequence
                                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                    (Expr.Econst_int (Integers.Int.repr 19) tuint)
                                                    (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                                    tint)
                                  s_kprog_arm64_entry_skb_20
                                  s_kprog_arm64_entry_skb_21)
                                (Stmt.Sassign
                                  (Expr.Efield
                                    (Expr.Evar ___a64_x19 (Ty.Tunion _arm64_sim_gpr noattr))
                                    _x tulong) (Expr.Etempvar _t'39 tulong)))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Evar ___a64_x19_tag tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 0) tuint))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_skb_22
                                  s_kprog_arm64_entry_skb_63)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_skb_65 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign (Expr.Evar ___a64_x3_tag tuchar)
    (Expr.Econst_int (Integers.Int.repr 0) tuint))
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                          (Expr.Econst_int (Integers.Int.repr 4) tuint)
                          (Expr.Econst_int (Integers.Int.repr 30) tuint)
                          tint)
        (Stmt.Sset _t'9
          (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong)
            tulong))
        (Stmt.Ssequence
          (Stmt.Scall (some _t'10)
            (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                 cc_default))
            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
          (Stmt.Sset _t'9 (Expr.Ecast (Expr.Etempvar _t'10 tulong) tulong))))
      (Stmt.Sassign
        (Expr.Efield (Expr.Evar ___a64_x4 (Ty.Tunion _arm64_sim_gpr noattr))
          _x tulong) (Expr.Etempvar _t'9 tulong)))
    (Stmt.Ssequence
      (Stmt.Sassign (Expr.Evar ___a64_x4_tag tuchar)
        (Expr.Econst_int (Integers.Int.repr 0) tuint))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Econst_int (Integers.Int.repr 5) tuint)
                              (Expr.Econst_int (Integers.Int.repr 30) tuint)
                              tint)
            (Stmt.Sset _t'11
              (Expr.Ecast (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                tulong))
            (Stmt.Ssequence
              (Stmt.Scall (some _t'12)
                (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                     tulong cc_default))
                [(Expr.Econst_int (Integers.Int.repr 6) tint)])
              (Stmt.Sset _t'11
                (Expr.Ecast (Expr.Etempvar _t'12 tulong) tulong))))
          (Stmt.Sassign
            (Expr.Efield
              (Expr.Evar ___a64_x5 (Ty.Tunion _arm64_sim_gpr noattr)) _x
              tulong) (Expr.Etempvar _t'11 tulong)))
        (Stmt.Ssequence
          (Stmt.Sassign (Expr.Evar ___a64_x5_tag tuchar)
            (Expr.Econst_int (Integers.Int.repr 0) tuint))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Econst_int (Integers.Int.repr 6) tuint)
                                  (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                  tint)
                (Stmt.Sset _t'13
                  (Expr.Ecast
                    (Expr.Econst_long (Integers.Int64.repr 0) tulong) tulong))
                (Stmt.Ssequence
                  (Stmt.Scall (some _t'14)
                    (Expr.Evar _native_lab_entry_input (Ty.Tfunction 
                                                         [tuint] tulong
                                                         cc_default))
                    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                  (Stmt.Sset _t'13
                    (Expr.Ecast (Expr.Etempvar _t'14 tulong) tulong))))
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Evar ___a64_x6 (Ty.Tunion _arm64_sim_gpr noattr)) _x
                  tulong) (Expr.Etempvar _t'13 tulong)))
            (Stmt.Ssequence
              (Stmt.Sassign (Expr.Evar ___a64_x6_tag tuchar)
                (Expr.Econst_int (Integers.Int.repr 0) tuint))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Econst_int (Integers.Int.repr 7) tuint)
                                      (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                      tint)
                    (Stmt.Sset _t'15
                      (Expr.Ecast
                        (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                        tulong))
                    (Stmt.Ssequence
                      (Stmt.Scall (some _t'16)
                        (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                             [tuint] tulong
                                                             cc_default))
                        [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                      (Stmt.Sset _t'15
                        (Expr.Ecast (Expr.Etempvar _t'16 tulong) tulong))))
                  (Stmt.Sassign
                    (Expr.Efield
                      (Expr.Evar ___a64_x7 (Ty.Tunion _arm64_sim_gpr noattr))
                      _x tulong) (Expr.Etempvar _t'15 tulong)))
                (Stmt.Ssequence
                  (Stmt.Sassign (Expr.Evar ___a64_x7_tag tuchar)
                    (Expr.Econst_int (Integers.Int.repr 0) tuint))
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                          (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                          tint)
                        (Stmt.Sset _t'17
                          (Expr.Ecast
                            (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                            tulong))
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'18)
                            (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                 [tuint]
                                                                 tulong
                                                                 cc_default))
                            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                          (Stmt.Sset _t'17
                            (Expr.Ecast (Expr.Etempvar _t'18 tulong) tulong))))
                      (Stmt.Sassign
                        (Expr.Efield
                          (Expr.Evar ___a64_x8 (Ty.Tunion _arm64_sim_gpr noattr))
                          _x tulong) (Expr.Etempvar _t'17 tulong)))
                    (Stmt.Ssequence
                      (Stmt.Sassign (Expr.Evar ___a64_x8_tag tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tuint))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Econst_int (Integers.Int.repr 9) tuint)
                                              (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                              tint)
                            (Stmt.Sset _t'19
                              (Expr.Ecast
                                (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                                tulong))
                            (Stmt.Ssequence
                              (Stmt.Scall (some _t'20)
                                (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                    [tuint]
                                                                    tulong
                                                                    cc_default))
                                [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                              (Stmt.Sset _t'19
                                (Expr.Ecast (Expr.Etempvar _t'20 tulong)
                                  tulong))))
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Evar ___a64_x9 (Ty.Tunion _arm64_sim_gpr noattr))
                              _x tulong) (Expr.Etempvar _t'19 tulong)))
                        (Stmt.Ssequence
                          (Stmt.Sassign (Expr.Evar ___a64_x9_tag tuchar)
                            (Expr.Econst_int (Integers.Int.repr 0) tuint))
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                  (Expr.Econst_int (Integers.Int.repr 10) tuint)
                                                  (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                                  tint)
                                s_kprog_arm64_entry_skb_15
                                s_kprog_arm64_entry_skb_16)
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Evar ___a64_x10 (Ty.Tunion _arm64_sim_gpr noattr))
                                  _x tulong) (Expr.Etempvar _t'21 tulong)))
                            (Stmt.Ssequence
                              (Stmt.Sassign (Expr.Evar ___a64_x10_tag tuchar)
                                (Expr.Econst_int (Integers.Int.repr 0) tuint))
                              (Stmt.Ssequence
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_skb_17
                                  (Stmt.Sassign
                                    (Expr.Efield
                                      (Expr.Evar ___a64_x11 (Ty.Tunion _arm64_sim_gpr noattr))
                                      _x tulong)
                                    (Expr.Etempvar _t'23 tulong)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_skb_18
                                  s_kprog_arm64_entry_skb_64)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_skb_66 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Efield
      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr)) _data
      (tptr tvoid))
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tvoid)))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Evar ___a64_sim_skb_ctx (tptr (Ty.Tstruct ___sk_buff noattr)))
      (Expr.Etempvar _ctx (tptr (Ty.Tstruct ___sk_buff noattr))))
    (Stmt.Ssequence
      (Stmt.Sassign (Expr.Evar ___a64_sim_abi_kind tuchar)
        (Expr.Econst_int (Integers.Int.repr 1) tuint))
      (Stmt.Ssequence
        (Stmt.Sassign (Expr.Evar ___a64_numeric_sp tulong)
          (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Ssequence
          (Stmt.Sassign (Expr.Evar ___a64_numeric_return tulong)
            (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Ssequence
            (Stmt.Sassign (Expr.Evar ___a64_numeric_sp_valid tuchar)
              (Expr.Econst_int (Integers.Int.repr 0) tint))
            (Stmt.Ssequence
              (Stmt.Sassign (Expr.Evar ___a64_numeric_return_valid tuchar)
                (Expr.Econst_int (Integers.Int.repr 0) tint))
              (Stmt.Ssequence
                (Stmt.Sassign (Expr.Evar ___a64_sim_is_xdp tuchar)
                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Evar ___a64_sim_helper_ctx (tptr tvoid))
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                      (tptr tvoid)))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Evar ___a64_sim_helper_abi_base (tptr tvoid))
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 0) tint)
                        (tptr tvoid)))
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                            (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                            tint)
                          (Stmt.Sset _t'1
                            (Expr.Ecast
                              (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                              tulong))
                          (Stmt.Ssequence
                            (Stmt.Scall (some _t'2)
                              (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                   [tuint]
                                                                   tulong
                                                                   cc_default))
                              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                            (Stmt.Sset _t'1
                              (Expr.Ecast (Expr.Etempvar _t'2 tulong) tulong))))
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Evar ___a64_x0 (Ty.Tunion _arm64_sim_gpr noattr))
                            _x tulong) (Expr.Etempvar _t'1 tulong)))
                      (Stmt.Ssequence
                        (Stmt.Sassign (Expr.Evar ___a64_x0_tag tuchar)
                          (Expr.Econst_int (Integers.Int.repr 0) tuint))
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                                (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                                tint)
                              (Stmt.Sset _t'3
                                (Expr.Ecast
                                  (Expr.Econst_long (Integers.Int64.repr 0) tulong)
                                  tulong))
                              (Stmt.Ssequence
                                s_kprog_arm64_entry_skb_11
                                (Stmt.Sset _t'3
                                  (Expr.Ecast (Expr.Etempvar _t'4 tulong)
                                    tulong))))
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Evar ___a64_x1 (Ty.Tunion _arm64_sim_gpr noattr))
                                _x tulong) (Expr.Etempvar _t'3 tulong)))
                          (Stmt.Ssequence
                            (Stmt.Sassign (Expr.Evar ___a64_x1_tag tuchar)
                              (Expr.Econst_int (Integers.Int.repr 0) tuint))
                            (Stmt.Ssequence
                              (Stmt.Ssequence
                                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                    (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                                    (Expr.Econst_int (Integers.Int.repr 30) tuint)
                                                    tint)
                                  s_kprog_arm64_entry_skb_12
                                  s_kprog_arm64_entry_skb_13)
                                (Stmt.Sassign
                                  (Expr.Efield
                                    (Expr.Evar ___a64_x2 (Ty.Tunion _arm64_sim_gpr noattr))
                                    _x tulong) (Expr.Etempvar _t'5 tulong)))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Evar ___a64_x2_tag tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 0) tuint))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_skb_14
                                  s_kprog_arm64_entry_skb_65)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_skb_67 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Efield
          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
          _pad2 (tarray tuchar 120))
        (Expr.Econst_int (Integers.Int.repr 103) tint) (tptr tuchar)) tuchar)
    (Expr.Econst_int (Integers.Int.repr 0) tint))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Efield
            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
            _pad2 (tarray tuchar 120))
          (Expr.Econst_int (Integers.Int.repr 104) tint) (tptr tuchar))
        tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
              _pad2 (tarray tuchar 120))
            (Expr.Econst_int (Integers.Int.repr 105) tint) (tptr tuchar))
          tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                _pad2 (tarray tuchar 120))
              (Expr.Econst_int (Integers.Int.repr 106) tint) (tptr tuchar))
            tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                  _pad2 (tarray tuchar 120))
                (Expr.Econst_int (Integers.Int.repr 107) tint) (tptr tuchar))
              tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                    _pad2 (tarray tuchar 120))
                  (Expr.Econst_int (Integers.Int.repr 108) tint)
                  (tptr tuchar)) tuchar)
              (Expr.Econst_int (Integers.Int.repr 0) tint))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Efield
                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                      _pad2 (tarray tuchar 120))
                    (Expr.Econst_int (Integers.Int.repr 109) tint)
                    (tptr tuchar)) tuchar)
                (Expr.Econst_int (Integers.Int.repr 0) tint))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                        _pad2 (tarray tuchar 120))
                      (Expr.Econst_int (Integers.Int.repr 110) tint)
                      (tptr tuchar)) tuchar)
                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                          _pad2 (tarray tuchar 120))
                        (Expr.Econst_int (Integers.Int.repr 111) tint)
                        (tptr tuchar)) tuchar)
                    (Expr.Econst_int (Integers.Int.repr 0) tint))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Efield
                            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                            _pad2 (tarray tuchar 120))
                          (Expr.Econst_int (Integers.Int.repr 112) tint)
                          (tptr tuchar)) tuchar)
                      (Expr.Econst_int (Integers.Int.repr 0) tint))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                              _pad2 (tarray tuchar 120))
                            (Expr.Econst_int (Integers.Int.repr 113) tint)
                            (tptr tuchar)) tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tint))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                _pad2 (tarray tuchar 120))
                              (Expr.Econst_int (Integers.Int.repr 114) tint)
                              (tptr tuchar)) tuchar)
                          (Expr.Econst_int (Integers.Int.repr 0) tint))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                  _pad2 (tarray tuchar 120))
                                (Expr.Econst_int (Integers.Int.repr 115) tint)
                                (tptr tuchar)) tuchar)
                            (Expr.Econst_int (Integers.Int.repr 0) tint))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                    _pad2 (tarray tuchar 120))
                                  (Expr.Econst_int (Integers.Int.repr 116) tint)
                                  (tptr tuchar)) tuchar)
                              (Expr.Econst_int (Integers.Int.repr 0) tint))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                      _pad2 (tarray tuchar 120))
                                    (Expr.Econst_int (Integers.Int.repr 117) tint)
                                    (tptr tuchar)) tuchar)
                                (Expr.Econst_int (Integers.Int.repr 0) tint))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Efield
                                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                        _pad2 (tarray tuchar 120))
                                      (Expr.Econst_int (Integers.Int.repr 118) tint)
                                      (tptr tuchar)) tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_skb_10
                                  s_kprog_arm64_entry_skb_66)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_skb_68 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Efield
          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
          _pad2 (tarray tuchar 120))
        (Expr.Econst_int (Integers.Int.repr 86) tint) (tptr tuchar)) tuchar)
    (Expr.Econst_int (Integers.Int.repr 0) tint))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Efield
            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
            _pad2 (tarray tuchar 120))
          (Expr.Econst_int (Integers.Int.repr 87) tint) (tptr tuchar))
        tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
              _pad2 (tarray tuchar 120))
            (Expr.Econst_int (Integers.Int.repr 88) tint) (tptr tuchar))
          tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                _pad2 (tarray tuchar 120))
              (Expr.Econst_int (Integers.Int.repr 89) tint) (tptr tuchar))
            tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                  _pad2 (tarray tuchar 120))
                (Expr.Econst_int (Integers.Int.repr 90) tint) (tptr tuchar))
              tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                    _pad2 (tarray tuchar 120))
                  (Expr.Econst_int (Integers.Int.repr 91) tint)
                  (tptr tuchar)) tuchar)
              (Expr.Econst_int (Integers.Int.repr 0) tint))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Efield
                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                      _pad2 (tarray tuchar 120))
                    (Expr.Econst_int (Integers.Int.repr 92) tint)
                    (tptr tuchar)) tuchar)
                (Expr.Econst_int (Integers.Int.repr 0) tint))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                        _pad2 (tarray tuchar 120))
                      (Expr.Econst_int (Integers.Int.repr 93) tint)
                      (tptr tuchar)) tuchar)
                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                          _pad2 (tarray tuchar 120))
                        (Expr.Econst_int (Integers.Int.repr 94) tint)
                        (tptr tuchar)) tuchar)
                    (Expr.Econst_int (Integers.Int.repr 0) tint))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Efield
                            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                            _pad2 (tarray tuchar 120))
                          (Expr.Econst_int (Integers.Int.repr 95) tint)
                          (tptr tuchar)) tuchar)
                      (Expr.Econst_int (Integers.Int.repr 0) tint))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                              _pad2 (tarray tuchar 120))
                            (Expr.Econst_int (Integers.Int.repr 96) tint)
                            (tptr tuchar)) tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tint))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                _pad2 (tarray tuchar 120))
                              (Expr.Econst_int (Integers.Int.repr 97) tint)
                              (tptr tuchar)) tuchar)
                          (Expr.Econst_int (Integers.Int.repr 0) tint))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                  _pad2 (tarray tuchar 120))
                                (Expr.Econst_int (Integers.Int.repr 98) tint)
                                (tptr tuchar)) tuchar)
                            (Expr.Econst_int (Integers.Int.repr 0) tint))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                    _pad2 (tarray tuchar 120))
                                  (Expr.Econst_int (Integers.Int.repr 99) tint)
                                  (tptr tuchar)) tuchar)
                              (Expr.Econst_int (Integers.Int.repr 0) tint))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                      _pad2 (tarray tuchar 120))
                                    (Expr.Econst_int (Integers.Int.repr 100) tint)
                                    (tptr tuchar)) tuchar)
                                (Expr.Econst_int (Integers.Int.repr 0) tint))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Efield
                                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                        _pad2 (tarray tuchar 120))
                                      (Expr.Econst_int (Integers.Int.repr 101) tint)
                                      (tptr tuchar)) tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_skb_9
                                  s_kprog_arm64_entry_skb_67)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_skb_69 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Efield
          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
          _pad2 (tarray tuchar 120))
        (Expr.Econst_int (Integers.Int.repr 69) tint) (tptr tuchar)) tuchar)
    (Expr.Econst_int (Integers.Int.repr 0) tint))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Efield
            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
            _pad2 (tarray tuchar 120))
          (Expr.Econst_int (Integers.Int.repr 70) tint) (tptr tuchar))
        tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
              _pad2 (tarray tuchar 120))
            (Expr.Econst_int (Integers.Int.repr 71) tint) (tptr tuchar))
          tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                _pad2 (tarray tuchar 120))
              (Expr.Econst_int (Integers.Int.repr 72) tint) (tptr tuchar))
            tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                  _pad2 (tarray tuchar 120))
                (Expr.Econst_int (Integers.Int.repr 73) tint) (tptr tuchar))
              tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                    _pad2 (tarray tuchar 120))
                  (Expr.Econst_int (Integers.Int.repr 74) tint)
                  (tptr tuchar)) tuchar)
              (Expr.Econst_int (Integers.Int.repr 0) tint))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Efield
                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                      _pad2 (tarray tuchar 120))
                    (Expr.Econst_int (Integers.Int.repr 75) tint)
                    (tptr tuchar)) tuchar)
                (Expr.Econst_int (Integers.Int.repr 0) tint))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                        _pad2 (tarray tuchar 120))
                      (Expr.Econst_int (Integers.Int.repr 76) tint)
                      (tptr tuchar)) tuchar)
                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                          _pad2 (tarray tuchar 120))
                        (Expr.Econst_int (Integers.Int.repr 77) tint)
                        (tptr tuchar)) tuchar)
                    (Expr.Econst_int (Integers.Int.repr 0) tint))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Efield
                            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                            _pad2 (tarray tuchar 120))
                          (Expr.Econst_int (Integers.Int.repr 78) tint)
                          (tptr tuchar)) tuchar)
                      (Expr.Econst_int (Integers.Int.repr 0) tint))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                              _pad2 (tarray tuchar 120))
                            (Expr.Econst_int (Integers.Int.repr 79) tint)
                            (tptr tuchar)) tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tint))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                _pad2 (tarray tuchar 120))
                              (Expr.Econst_int (Integers.Int.repr 80) tint)
                              (tptr tuchar)) tuchar)
                          (Expr.Econst_int (Integers.Int.repr 0) tint))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                  _pad2 (tarray tuchar 120))
                                (Expr.Econst_int (Integers.Int.repr 81) tint)
                                (tptr tuchar)) tuchar)
                            (Expr.Econst_int (Integers.Int.repr 0) tint))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                    _pad2 (tarray tuchar 120))
                                  (Expr.Econst_int (Integers.Int.repr 82) tint)
                                  (tptr tuchar)) tuchar)
                              (Expr.Econst_int (Integers.Int.repr 0) tint))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                      _pad2 (tarray tuchar 120))
                                    (Expr.Econst_int (Integers.Int.repr 83) tint)
                                    (tptr tuchar)) tuchar)
                                (Expr.Econst_int (Integers.Int.repr 0) tint))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Efield
                                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                        _pad2 (tarray tuchar 120))
                                      (Expr.Econst_int (Integers.Int.repr 84) tint)
                                      (tptr tuchar)) tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_skb_8
                                  s_kprog_arm64_entry_skb_68)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_skb_70 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Efield
          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
          _pad2 (tarray tuchar 120))
        (Expr.Econst_int (Integers.Int.repr 52) tint) (tptr tuchar)) tuchar)
    (Expr.Econst_int (Integers.Int.repr 0) tint))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Efield
            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
            _pad2 (tarray tuchar 120))
          (Expr.Econst_int (Integers.Int.repr 53) tint) (tptr tuchar))
        tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
              _pad2 (tarray tuchar 120))
            (Expr.Econst_int (Integers.Int.repr 54) tint) (tptr tuchar))
          tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                _pad2 (tarray tuchar 120))
              (Expr.Econst_int (Integers.Int.repr 55) tint) (tptr tuchar))
            tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                  _pad2 (tarray tuchar 120))
                (Expr.Econst_int (Integers.Int.repr 56) tint) (tptr tuchar))
              tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                    _pad2 (tarray tuchar 120))
                  (Expr.Econst_int (Integers.Int.repr 57) tint)
                  (tptr tuchar)) tuchar)
              (Expr.Econst_int (Integers.Int.repr 0) tint))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Efield
                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                      _pad2 (tarray tuchar 120))
                    (Expr.Econst_int (Integers.Int.repr 58) tint)
                    (tptr tuchar)) tuchar)
                (Expr.Econst_int (Integers.Int.repr 0) tint))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                        _pad2 (tarray tuchar 120))
                      (Expr.Econst_int (Integers.Int.repr 59) tint)
                      (tptr tuchar)) tuchar)
                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                          _pad2 (tarray tuchar 120))
                        (Expr.Econst_int (Integers.Int.repr 60) tint)
                        (tptr tuchar)) tuchar)
                    (Expr.Econst_int (Integers.Int.repr 0) tint))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Efield
                            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                            _pad2 (tarray tuchar 120))
                          (Expr.Econst_int (Integers.Int.repr 61) tint)
                          (tptr tuchar)) tuchar)
                      (Expr.Econst_int (Integers.Int.repr 0) tint))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                              _pad2 (tarray tuchar 120))
                            (Expr.Econst_int (Integers.Int.repr 62) tint)
                            (tptr tuchar)) tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tint))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                _pad2 (tarray tuchar 120))
                              (Expr.Econst_int (Integers.Int.repr 63) tint)
                              (tptr tuchar)) tuchar)
                          (Expr.Econst_int (Integers.Int.repr 0) tint))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                  _pad2 (tarray tuchar 120))
                                (Expr.Econst_int (Integers.Int.repr 64) tint)
                                (tptr tuchar)) tuchar)
                            (Expr.Econst_int (Integers.Int.repr 0) tint))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                    _pad2 (tarray tuchar 120))
                                  (Expr.Econst_int (Integers.Int.repr 65) tint)
                                  (tptr tuchar)) tuchar)
                              (Expr.Econst_int (Integers.Int.repr 0) tint))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                      _pad2 (tarray tuchar 120))
                                    (Expr.Econst_int (Integers.Int.repr 66) tint)
                                    (tptr tuchar)) tuchar)
                                (Expr.Econst_int (Integers.Int.repr 0) tint))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Efield
                                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                        _pad2 (tarray tuchar 120))
                                      (Expr.Econst_int (Integers.Int.repr 67) tint)
                                      (tptr tuchar)) tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_skb_7
                                  s_kprog_arm64_entry_skb_69)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_skb_71 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Efield
          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
          _pad2 (tarray tuchar 120))
        (Expr.Econst_int (Integers.Int.repr 35) tint) (tptr tuchar)) tuchar)
    (Expr.Econst_int (Integers.Int.repr 0) tint))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Efield
            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
            _pad2 (tarray tuchar 120))
          (Expr.Econst_int (Integers.Int.repr 36) tint) (tptr tuchar))
        tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
              _pad2 (tarray tuchar 120))
            (Expr.Econst_int (Integers.Int.repr 37) tint) (tptr tuchar))
          tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                _pad2 (tarray tuchar 120))
              (Expr.Econst_int (Integers.Int.repr 38) tint) (tptr tuchar))
            tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                  _pad2 (tarray tuchar 120))
                (Expr.Econst_int (Integers.Int.repr 39) tint) (tptr tuchar))
              tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                    _pad2 (tarray tuchar 120))
                  (Expr.Econst_int (Integers.Int.repr 40) tint)
                  (tptr tuchar)) tuchar)
              (Expr.Econst_int (Integers.Int.repr 0) tint))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Efield
                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                      _pad2 (tarray tuchar 120))
                    (Expr.Econst_int (Integers.Int.repr 41) tint)
                    (tptr tuchar)) tuchar)
                (Expr.Econst_int (Integers.Int.repr 0) tint))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                        _pad2 (tarray tuchar 120))
                      (Expr.Econst_int (Integers.Int.repr 42) tint)
                      (tptr tuchar)) tuchar)
                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                          _pad2 (tarray tuchar 120))
                        (Expr.Econst_int (Integers.Int.repr 43) tint)
                        (tptr tuchar)) tuchar)
                    (Expr.Econst_int (Integers.Int.repr 0) tint))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Efield
                            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                            _pad2 (tarray tuchar 120))
                          (Expr.Econst_int (Integers.Int.repr 44) tint)
                          (tptr tuchar)) tuchar)
                      (Expr.Econst_int (Integers.Int.repr 0) tint))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                              _pad2 (tarray tuchar 120))
                            (Expr.Econst_int (Integers.Int.repr 45) tint)
                            (tptr tuchar)) tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tint))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                _pad2 (tarray tuchar 120))
                              (Expr.Econst_int (Integers.Int.repr 46) tint)
                              (tptr tuchar)) tuchar)
                          (Expr.Econst_int (Integers.Int.repr 0) tint))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                  _pad2 (tarray tuchar 120))
                                (Expr.Econst_int (Integers.Int.repr 47) tint)
                                (tptr tuchar)) tuchar)
                            (Expr.Econst_int (Integers.Int.repr 0) tint))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                    _pad2 (tarray tuchar 120))
                                  (Expr.Econst_int (Integers.Int.repr 48) tint)
                                  (tptr tuchar)) tuchar)
                              (Expr.Econst_int (Integers.Int.repr 0) tint))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                      _pad2 (tarray tuchar 120))
                                    (Expr.Econst_int (Integers.Int.repr 49) tint)
                                    (tptr tuchar)) tuchar)
                                (Expr.Econst_int (Integers.Int.repr 0) tint))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Efield
                                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                        _pad2 (tarray tuchar 120))
                                      (Expr.Econst_int (Integers.Int.repr 50) tint)
                                      (tptr tuchar)) tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_skb_6
                                  s_kprog_arm64_entry_skb_70)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_skb_72 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Efield
          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
          _pad2 (tarray tuchar 120))
        (Expr.Econst_int (Integers.Int.repr 18) tint) (tptr tuchar)) tuchar)
    (Expr.Econst_int (Integers.Int.repr 0) tint))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Efield
            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
            _pad2 (tarray tuchar 120))
          (Expr.Econst_int (Integers.Int.repr 19) tint) (tptr tuchar))
        tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
              _pad2 (tarray tuchar 120))
            (Expr.Econst_int (Integers.Int.repr 20) tint) (tptr tuchar))
          tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                _pad2 (tarray tuchar 120))
              (Expr.Econst_int (Integers.Int.repr 21) tint) (tptr tuchar))
            tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                  _pad2 (tarray tuchar 120))
                (Expr.Econst_int (Integers.Int.repr 22) tint) (tptr tuchar))
              tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                    _pad2 (tarray tuchar 120))
                  (Expr.Econst_int (Integers.Int.repr 23) tint)
                  (tptr tuchar)) tuchar)
              (Expr.Econst_int (Integers.Int.repr 0) tint))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Efield
                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                      _pad2 (tarray tuchar 120))
                    (Expr.Econst_int (Integers.Int.repr 24) tint)
                    (tptr tuchar)) tuchar)
                (Expr.Econst_int (Integers.Int.repr 0) tint))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                        _pad2 (tarray tuchar 120))
                      (Expr.Econst_int (Integers.Int.repr 25) tint)
                      (tptr tuchar)) tuchar)
                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                          _pad2 (tarray tuchar 120))
                        (Expr.Econst_int (Integers.Int.repr 26) tint)
                        (tptr tuchar)) tuchar)
                    (Expr.Econst_int (Integers.Int.repr 0) tint))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Efield
                            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                            _pad2 (tarray tuchar 120))
                          (Expr.Econst_int (Integers.Int.repr 27) tint)
                          (tptr tuchar)) tuchar)
                      (Expr.Econst_int (Integers.Int.repr 0) tint))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                              _pad2 (tarray tuchar 120))
                            (Expr.Econst_int (Integers.Int.repr 28) tint)
                            (tptr tuchar)) tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tint))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                _pad2 (tarray tuchar 120))
                              (Expr.Econst_int (Integers.Int.repr 29) tint)
                              (tptr tuchar)) tuchar)
                          (Expr.Econst_int (Integers.Int.repr 0) tint))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                  _pad2 (tarray tuchar 120))
                                (Expr.Econst_int (Integers.Int.repr 30) tint)
                                (tptr tuchar)) tuchar)
                            (Expr.Econst_int (Integers.Int.repr 0) tint))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                    _pad2 (tarray tuchar 120))
                                  (Expr.Econst_int (Integers.Int.repr 31) tint)
                                  (tptr tuchar)) tuchar)
                              (Expr.Econst_int (Integers.Int.repr 0) tint))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                      _pad2 (tarray tuchar 120))
                                    (Expr.Econst_int (Integers.Int.repr 32) tint)
                                    (tptr tuchar)) tuchar)
                                (Expr.Econst_int (Integers.Int.repr 0) tint))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Efield
                                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                        _pad2 (tarray tuchar 120))
                                      (Expr.Econst_int (Integers.Int.repr 33) tint)
                                      (tptr tuchar)) tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_skb_5
                                  s_kprog_arm64_entry_skb_71)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_skb_73 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Efield
          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
          _pad2 (tarray tuchar 120))
        (Expr.Econst_int (Integers.Int.repr 1) tint) (tptr tuchar)) tuchar)
    (Expr.Econst_int (Integers.Int.repr 0) tint))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Efield
            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
            _pad2 (tarray tuchar 120))
          (Expr.Econst_int (Integers.Int.repr 2) tint) (tptr tuchar)) tuchar)
      (Expr.Econst_int (Integers.Int.repr 0) tint))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
              _pad2 (tarray tuchar 120))
            (Expr.Econst_int (Integers.Int.repr 3) tint) (tptr tuchar))
          tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                _pad2 (tarray tuchar 120))
              (Expr.Econst_int (Integers.Int.repr 4) tint) (tptr tuchar))
            tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                  _pad2 (tarray tuchar 120))
                (Expr.Econst_int (Integers.Int.repr 5) tint) (tptr tuchar))
              tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                    _pad2 (tarray tuchar 120))
                  (Expr.Econst_int (Integers.Int.repr 6) tint) (tptr tuchar))
                tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Efield
                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                      _pad2 (tarray tuchar 120))
                    (Expr.Econst_int (Integers.Int.repr 7) tint)
                    (tptr tuchar)) tuchar)
                (Expr.Econst_int (Integers.Int.repr 0) tint))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                        _pad2 (tarray tuchar 120))
                      (Expr.Econst_int (Integers.Int.repr 8) tint)
                      (tptr tuchar)) tuchar)
                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                          _pad2 (tarray tuchar 120))
                        (Expr.Econst_int (Integers.Int.repr 9) tint)
                        (tptr tuchar)) tuchar)
                    (Expr.Econst_int (Integers.Int.repr 0) tint))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Efield
                            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                            _pad2 (tarray tuchar 120))
                          (Expr.Econst_int (Integers.Int.repr 10) tint)
                          (tptr tuchar)) tuchar)
                      (Expr.Econst_int (Integers.Int.repr 0) tint))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                              _pad2 (tarray tuchar 120))
                            (Expr.Econst_int (Integers.Int.repr 11) tint)
                            (tptr tuchar)) tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tint))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                _pad2 (tarray tuchar 120))
                              (Expr.Econst_int (Integers.Int.repr 12) tint)
                              (tptr tuchar)) tuchar)
                          (Expr.Econst_int (Integers.Int.repr 0) tint))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                  _pad2 (tarray tuchar 120))
                                (Expr.Econst_int (Integers.Int.repr 13) tint)
                                (tptr tuchar)) tuchar)
                            (Expr.Econst_int (Integers.Int.repr 0) tint))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                    _pad2 (tarray tuchar 120))
                                  (Expr.Econst_int (Integers.Int.repr 14) tint)
                                  (tptr tuchar)) tuchar)
                              (Expr.Econst_int (Integers.Int.repr 0) tint))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                      _pad2 (tarray tuchar 120))
                                    (Expr.Econst_int (Integers.Int.repr 15) tint)
                                    (tptr tuchar)) tuchar)
                                (Expr.Econst_int (Integers.Int.repr 0) tint))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Efield
                                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                        _pad2 (tarray tuchar 120))
                                      (Expr.Econst_int (Integers.Int.repr 16) tint)
                                      (tptr tuchar)) tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_skb_4
                                  s_kprog_arm64_entry_skb_72)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_skb_74 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Efield
          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
          _cb (tarray tuint 5)) (Expr.Econst_int (Integers.Int.repr 2) tint)
        (tptr tuint)) tuint) (Expr.Econst_int (Integers.Int.repr 0) tint))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Efield
            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
            _cb (tarray tuint 5))
          (Expr.Econst_int (Integers.Int.repr 3) tint) (tptr tuint)) tuint)
      (Expr.Econst_int (Integers.Int.repr 0) tint))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
              _cb (tarray tuint 5))
            (Expr.Econst_int (Integers.Int.repr 4) tint) (tptr tuint)) tuint)
        (Expr.Econst_int (Integers.Int.repr 0) tint))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                _pad1 (tarray tuchar 12))
              (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tuchar))
            tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                  _pad1 (tarray tuchar 12))
                (Expr.Econst_int (Integers.Int.repr 1) tint) (tptr tuchar))
              tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                    _pad1 (tarray tuchar 12))
                  (Expr.Econst_int (Integers.Int.repr 2) tint) (tptr tuchar))
                tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Efield
                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                      _pad1 (tarray tuchar 12))
                    (Expr.Econst_int (Integers.Int.repr 3) tint)
                    (tptr tuchar)) tuchar)
                (Expr.Econst_int (Integers.Int.repr 0) tint))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                        _pad1 (tarray tuchar 12))
                      (Expr.Econst_int (Integers.Int.repr 4) tint)
                      (tptr tuchar)) tuchar)
                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                          _pad1 (tarray tuchar 12))
                        (Expr.Econst_int (Integers.Int.repr 5) tint)
                        (tptr tuchar)) tuchar)
                    (Expr.Econst_int (Integers.Int.repr 0) tint))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Efield
                            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                            _pad1 (tarray tuchar 12))
                          (Expr.Econst_int (Integers.Int.repr 6) tint)
                          (tptr tuchar)) tuchar)
                      (Expr.Econst_int (Integers.Int.repr 0) tint))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                              _pad1 (tarray tuchar 12))
                            (Expr.Econst_int (Integers.Int.repr 7) tint)
                            (tptr tuchar)) tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tint))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                _pad1 (tarray tuchar 12))
                              (Expr.Econst_int (Integers.Int.repr 8) tint)
                              (tptr tuchar)) tuchar)
                          (Expr.Econst_int (Integers.Int.repr 0) tint))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                  _pad1 (tarray tuchar 12))
                                (Expr.Econst_int (Integers.Int.repr 9) tint)
                                (tptr tuchar)) tuchar)
                            (Expr.Econst_int (Integers.Int.repr 0) tint))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                    _pad1 (tarray tuchar 12))
                                  (Expr.Econst_int (Integers.Int.repr 10) tint)
                                  (tptr tuchar)) tuchar)
                              (Expr.Econst_int (Integers.Int.repr 0) tint))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                      _pad1 (tarray tuchar 12))
                                    (Expr.Econst_int (Integers.Int.repr 11) tint)
                                    (tptr tuchar)) tuchar)
                                (Expr.Econst_int (Integers.Int.repr 0) tint))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Efield
                                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                    _data_end (tptr tvoid))
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 0) tint)
                                    (tptr tvoid)))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_skb_3
                                  s_kprog_arm64_entry_skb_73)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_skb_75 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Efield
          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
          _pad0 (tarray tuchar 48))
        (Expr.Econst_int (Integers.Int.repr 33) tint) (tptr tuchar)) tuchar)
    (Expr.Econst_int (Integers.Int.repr 0) tint))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Efield
            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
            _pad0 (tarray tuchar 48))
          (Expr.Econst_int (Integers.Int.repr 34) tint) (tptr tuchar))
        tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
              _pad0 (tarray tuchar 48))
            (Expr.Econst_int (Integers.Int.repr 35) tint) (tptr tuchar))
          tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                _pad0 (tarray tuchar 48))
              (Expr.Econst_int (Integers.Int.repr 36) tint) (tptr tuchar))
            tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                  _pad0 (tarray tuchar 48))
                (Expr.Econst_int (Integers.Int.repr 37) tint) (tptr tuchar))
              tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                    _pad0 (tarray tuchar 48))
                  (Expr.Econst_int (Integers.Int.repr 38) tint)
                  (tptr tuchar)) tuchar)
              (Expr.Econst_int (Integers.Int.repr 0) tint))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Efield
                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                      _pad0 (tarray tuchar 48))
                    (Expr.Econst_int (Integers.Int.repr 39) tint)
                    (tptr tuchar)) tuchar)
                (Expr.Econst_int (Integers.Int.repr 0) tint))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                        _pad0 (tarray tuchar 48))
                      (Expr.Econst_int (Integers.Int.repr 40) tint)
                      (tptr tuchar)) tuchar)
                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                          _pad0 (tarray tuchar 48))
                        (Expr.Econst_int (Integers.Int.repr 41) tint)
                        (tptr tuchar)) tuchar)
                    (Expr.Econst_int (Integers.Int.repr 0) tint))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Efield
                            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                            _pad0 (tarray tuchar 48))
                          (Expr.Econst_int (Integers.Int.repr 42) tint)
                          (tptr tuchar)) tuchar)
                      (Expr.Econst_int (Integers.Int.repr 0) tint))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                              _pad0 (tarray tuchar 48))
                            (Expr.Econst_int (Integers.Int.repr 43) tint)
                            (tptr tuchar)) tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tint))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                _pad0 (tarray tuchar 48))
                              (Expr.Econst_int (Integers.Int.repr 44) tint)
                              (tptr tuchar)) tuchar)
                          (Expr.Econst_int (Integers.Int.repr 0) tint))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                  _pad0 (tarray tuchar 48))
                                (Expr.Econst_int (Integers.Int.repr 45) tint)
                                (tptr tuchar)) tuchar)
                            (Expr.Econst_int (Integers.Int.repr 0) tint))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                    _pad0 (tarray tuchar 48))
                                  (Expr.Econst_int (Integers.Int.repr 46) tint)
                                  (tptr tuchar)) tuchar)
                              (Expr.Econst_int (Integers.Int.repr 0) tint))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                      _pad0 (tarray tuchar 48))
                                    (Expr.Econst_int (Integers.Int.repr 47) tint)
                                    (tptr tuchar)) tuchar)
                                (Expr.Econst_int (Integers.Int.repr 0) tint))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Efield
                                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                        _cb (tarray tuint 5))
                                      (Expr.Econst_int (Integers.Int.repr 0) tint)
                                      (tptr tuint)) tuint)
                                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_skb_2
                                  s_kprog_arm64_entry_skb_74)))))))))))))))))

@[noinline] def s_kprog_arm64_entry_skb_76 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Efield
          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
          _pad0 (tarray tuchar 48))
        (Expr.Econst_int (Integers.Int.repr 16) tint) (tptr tuchar)) tuchar)
    (Expr.Econst_int (Integers.Int.repr 0) tint))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Efield
            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
            _pad0 (tarray tuchar 48))
          (Expr.Econst_int (Integers.Int.repr 17) tint) (tptr tuchar))
        tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
              _pad0 (tarray tuchar 48))
            (Expr.Econst_int (Integers.Int.repr 18) tint) (tptr tuchar))
          tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                _pad0 (tarray tuchar 48))
              (Expr.Econst_int (Integers.Int.repr 19) tint) (tptr tuchar))
            tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                  _pad0 (tarray tuchar 48))
                (Expr.Econst_int (Integers.Int.repr 20) tint) (tptr tuchar))
              tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                    _pad0 (tarray tuchar 48))
                  (Expr.Econst_int (Integers.Int.repr 21) tint)
                  (tptr tuchar)) tuchar)
              (Expr.Econst_int (Integers.Int.repr 0) tint))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Efield
                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                      _pad0 (tarray tuchar 48))
                    (Expr.Econst_int (Integers.Int.repr 22) tint)
                    (tptr tuchar)) tuchar)
                (Expr.Econst_int (Integers.Int.repr 0) tint))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                        _pad0 (tarray tuchar 48))
                      (Expr.Econst_int (Integers.Int.repr 23) tint)
                      (tptr tuchar)) tuchar)
                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                          _pad0 (tarray tuchar 48))
                        (Expr.Econst_int (Integers.Int.repr 24) tint)
                        (tptr tuchar)) tuchar)
                    (Expr.Econst_int (Integers.Int.repr 0) tint))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Efield
                            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                            _pad0 (tarray tuchar 48))
                          (Expr.Econst_int (Integers.Int.repr 25) tint)
                          (tptr tuchar)) tuchar)
                      (Expr.Econst_int (Integers.Int.repr 0) tint))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                              _pad0 (tarray tuchar 48))
                            (Expr.Econst_int (Integers.Int.repr 26) tint)
                            (tptr tuchar)) tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tint))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                _pad0 (tarray tuchar 48))
                              (Expr.Econst_int (Integers.Int.repr 27) tint)
                              (tptr tuchar)) tuchar)
                          (Expr.Econst_int (Integers.Int.repr 0) tint))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                  _pad0 (tarray tuchar 48))
                                (Expr.Econst_int (Integers.Int.repr 28) tint)
                                (tptr tuchar)) tuchar)
                            (Expr.Econst_int (Integers.Int.repr 0) tint))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                    _pad0 (tarray tuchar 48))
                                  (Expr.Econst_int (Integers.Int.repr 29) tint)
                                  (tptr tuchar)) tuchar)
                              (Expr.Econst_int (Integers.Int.repr 0) tint))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                      _pad0 (tarray tuchar 48))
                                    (Expr.Econst_int (Integers.Int.repr 30) tint)
                                    (tptr tuchar)) tuchar)
                                (Expr.Econst_int (Integers.Int.repr 0) tint))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Ederef
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Efield
                                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                        _pad0 (tarray tuchar 48))
                                      (Expr.Econst_int (Integers.Int.repr 31) tint)
                                      (tptr tuchar)) tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                                (Stmt.Ssequence
                                  s_kprog_arm64_entry_skb_1
                                  s_kprog_arm64_entry_skb_75)))))))))))))))))

@[noinline] def l_kprog_arm64_entry_skb_temps_0 : List (Ident × Ty) :=
[(_i, tuint), (_t'132, tuint), (_t'131, (tptr tvoid)), (_t'130, tulong),
 (_t'129, tulong), (_t'128, tulong), (_t'127, tulong), (_t'126, tulong),
 (_t'125, tulong), (_t'124, tulong), (_t'123, tulong), (_t'122, tulong),
 (_t'121, tulong), (_t'120, tulong), (_t'119, tulong), (_t'118, tulong),
 (_t'117, tulong), (_t'116, tulong), (_t'115, tulong), (_t'114, tulong),
 (_t'113, tulong), (_t'112, tulong), (_t'111, tulong), (_t'110, tulong),
 (_t'109, tulong), (_t'108, tulong), (_t'107, tulong), (_t'106, tulong),
 (_t'105, tulong), (_t'104, tulong), (_t'103, tulong), (_t'102, tulong),
 (_t'101, tulong), (_t'100, tulong), (_t'99, tulong), (_t'98, tulong),
 (_t'97, tulong), (_t'96, tulong), (_t'95, tulong), (_t'94, tulong),
 (_t'93, tulong), (_t'92, tulong), (_t'91, tulong), (_t'90, tulong),
 (_t'89, tulong), (_t'88, tulong), (_t'87, tulong), (_t'86, tulong),
 (_t'85, tulong), (_t'84, tulong), (_t'83, tulong), (_t'82, tulong),
 (_t'81, tulong), (_t'80, tulong), (_t'79, tulong), (_t'78, tulong),
 (_t'77, tulong), (_t'76, tulong), (_t'75, tulong), (_t'74, tulong),
 (_t'73, tulong), (_t'72, tulong), (_t'71, tulong), (_t'70, tulong),
 (_t'69, tulong), (_t'68, tulong), (_t'67, tulong)]

@[noinline] def l_kprog_arm64_entry_skb_temps_1 : List (Ident × Ty) :=
[(_t'66, tulong), (_t'65, tulong), (_t'64, tulong), (_t'63, tulong),
 (_t'62, tulong), (_t'61, tulong), (_t'60, tulong), (_t'59, tulong),
 (_t'58, tulong), (_t'57, tulong), (_t'56, tulong), (_t'55, tulong),
 (_t'54, tulong), (_t'53, tulong), (_t'52, tulong), (_t'51, tulong),
 (_t'50, tulong), (_t'49, tulong), (_t'48, tulong), (_t'47, tulong),
 (_t'46, tulong), (_t'45, tulong), (_t'44, tulong), (_t'43, tulong),
 (_t'42, tulong), (_t'41, tulong), (_t'40, tulong), (_t'39, tulong),
 (_t'38, tulong), (_t'37, tulong), (_t'36, tulong), (_t'35, tulong),
 (_t'34, tulong), (_t'33, tulong), (_t'32, tulong), (_t'31, tulong),
 (_t'30, tulong), (_t'29, tulong), (_t'28, tulong), (_t'27, tulong),
 (_t'26, tulong), (_t'25, tulong), (_t'24, tulong), (_t'23, tulong),
 (_t'22, tulong), (_t'21, tulong), (_t'20, tulong), (_t'19, tulong),
 (_t'18, tulong), (_t'17, tulong), (_t'16, tulong), (_t'15, tulong),
 (_t'14, tulong), (_t'13, tulong), (_t'12, tulong), (_t'11, tulong),
 (_t'10, tulong), (_t'9, tulong), (_t'8, tulong), (_t'7, tulong),
 (_t'6, tulong), (_t'5, tulong), (_t'4, tulong), (_t'3, tulong),
 (_t'2, tulong), (_t'1, tulong), (_t'133, (tptr tvoid))]

def f_kprog_arm64_entry_skb : Function := {
  fn_return := tuint,
  fn_callconv := cc_default,
  fn_params := [(_ctx, (tptr (Ty.Tstruct ___sk_buff noattr))),
                (_bpf_cast_to_kern_ctx,
                 (tptr (Ty.Tfunction [(tptr tvoid)] (tptr tvoid) cc_default))),
                (_continuation,
                 (tptr (Ty.Tfunction
                         [(tptr (Ty.Tstruct _kprog_arm64_entry noattr))]
                         tuint cc_default)))],
  fn_vars := [(___a64_sim_abi, (Ty.Tstruct _arm64_sim_skb_abi noattr)),
              (___a64_sim_skb_ctx, (tptr (Ty.Tstruct ___sk_buff noattr))),
              (___a64_sim_abi_kind, tuchar), (___a64_numeric_sp, tulong),
              (___a64_numeric_return, tulong),
              (___a64_numeric_sp_valid, tuchar),
              (___a64_numeric_return_valid, tuchar),
              (___a64_sim_is_xdp, tuchar),
              (___a64_sim_helper_ctx, (tptr tvoid)),
              (___a64_sim_helper_abi_base, (tptr tvoid)),
              (___a64_x0, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x0_tag, tuchar),
              (___a64_x1, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x1_tag, tuchar),
              (___a64_x2, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x2_tag, tuchar),
              (___a64_x3, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x3_tag, tuchar),
              (___a64_x4, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x4_tag, tuchar),
              (___a64_x5, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x5_tag, tuchar),
              (___a64_x6, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x6_tag, tuchar),
              (___a64_x7, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x7_tag, tuchar),
              (___a64_x8, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x8_tag, tuchar),
              (___a64_x9, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x9_tag, tuchar),
              (___a64_x10, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x10_tag, tuchar),
              (___a64_x11, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x11_tag, tuchar),
              (___a64_x12, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x12_tag, tuchar),
              (___a64_x13, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x13_tag, tuchar),
              (___a64_x14, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x14_tag, tuchar),
              (___a64_x15, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x15_tag, tuchar),
              (___a64_x16, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x16_tag, tuchar),
              (___a64_x17, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x17_tag, tuchar),
              (___a64_x18, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x18_tag, tuchar),
              (___a64_x19, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x19_tag, tuchar),
              (___a64_x20, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x20_tag, tuchar),
              (___a64_x21, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x21_tag, tuchar),
              (___a64_x22, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x22_tag, tuchar),
              (___a64_x23, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x23_tag, tuchar),
              (___a64_x24, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x24_tag, tuchar),
              (___a64_x25, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x25_tag, tuchar),
              (___a64_x26, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x26_tag, tuchar),
              (___a64_x27, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x27_tag, tuchar),
              (___a64_x28, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x28_tag, tuchar),
              (___a64_x29, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x29_tag, tuchar),
              (___a64_x30, (Ty.Tunion _arm64_sim_gpr noattr)),
              (___a64_x30_tag, tuchar),
              (___a64_cells,
               (tarray (tptr (Ty.Tunion _arm64_sim_gpr noattr)) 31)),
              (___a64_tag_cells, (tarray (tptr tuchar) 31)),
              (___a64_n, tuchar), (___a64_z, tuchar), (___a64_c, tuchar),
              (___a64_v, tuchar), (___a64_lr, tulong),
              (___a64_vectors, (tarray (Ty.Tstruct __3040 noattr) 32)),
              (___a64_stack, (tvolatile (Ty.Tunion __3042 noattr))),
              (___a64_stack_payload, (tarray (tvolatile tulong) 20)),
              (___a64_stack_tag, (tarray tuchar 24)), (___a64_sp, tlong),
              (_entry, (Ty.Tstruct _kprog_arm64_entry noattr))],
  fn_temps := (l_kprog_arm64_entry_skb_temps_0 ++ l_kprog_arm64_entry_skb_temps_1),
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Efield
          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
          _pad0 (tarray tuchar 48))
        (Expr.Econst_int (Integers.Int.repr 0) tint) (tptr tuchar)) tuchar)
    (Expr.Econst_int (Integers.Int.repr 0) tint))
  (Stmt.Ssequence
    (Stmt.Sassign
      (Expr.Ederef
        (Expr.Ebinop Binop.Oadd
          (Expr.Efield
            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
            _pad0 (tarray tuchar 48))
          (Expr.Econst_int (Integers.Int.repr 1) tint) (tptr tuchar)) tuchar)
      (Expr.Econst_int (Integers.Int.repr 0) tint))
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Efield
              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
              _pad0 (tarray tuchar 48))
            (Expr.Econst_int (Integers.Int.repr 2) tint) (tptr tuchar))
          tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
      (Stmt.Ssequence
        (Stmt.Sassign
          (Expr.Ederef
            (Expr.Ebinop Binop.Oadd
              (Expr.Efield
                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                _pad0 (tarray tuchar 48))
              (Expr.Econst_int (Integers.Int.repr 3) tint) (tptr tuchar))
            tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
        (Stmt.Ssequence
          (Stmt.Sassign
            (Expr.Ederef
              (Expr.Ebinop Binop.Oadd
                (Expr.Efield
                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                  _pad0 (tarray tuchar 48))
                (Expr.Econst_int (Integers.Int.repr 4) tint) (tptr tuchar))
              tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                    _pad0 (tarray tuchar 48))
                  (Expr.Econst_int (Integers.Int.repr 5) tint) (tptr tuchar))
                tuchar) (Expr.Econst_int (Integers.Int.repr 0) tint))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Ederef
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Efield
                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                      _pad0 (tarray tuchar 48))
                    (Expr.Econst_int (Integers.Int.repr 6) tint)
                    (tptr tuchar)) tuchar)
                (Expr.Econst_int (Integers.Int.repr 0) tint))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                        _pad0 (tarray tuchar 48))
                      (Expr.Econst_int (Integers.Int.repr 7) tint)
                      (tptr tuchar)) tuchar)
                  (Expr.Econst_int (Integers.Int.repr 0) tint))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Ederef
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Efield
                          (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                          _pad0 (tarray tuchar 48))
                        (Expr.Econst_int (Integers.Int.repr 8) tint)
                        (tptr tuchar)) tuchar)
                    (Expr.Econst_int (Integers.Int.repr 0) tint))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Efield
                            (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                            _pad0 (tarray tuchar 48))
                          (Expr.Econst_int (Integers.Int.repr 9) tint)
                          (tptr tuchar)) tuchar)
                      (Expr.Econst_int (Integers.Int.repr 0) tint))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Ederef
                          (Expr.Ebinop Binop.Oadd
                            (Expr.Efield
                              (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                              _pad0 (tarray tuchar 48))
                            (Expr.Econst_int (Integers.Int.repr 10) tint)
                            (tptr tuchar)) tuchar)
                        (Expr.Econst_int (Integers.Int.repr 0) tint))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Ederef
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Efield
                                (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                _pad0 (tarray tuchar 48))
                              (Expr.Econst_int (Integers.Int.repr 11) tint)
                              (tptr tuchar)) tuchar)
                          (Expr.Econst_int (Integers.Int.repr 0) tint))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                  _pad0 (tarray tuchar 48))
                                (Expr.Econst_int (Integers.Int.repr 12) tint)
                                (tptr tuchar)) tuchar)
                            (Expr.Econst_int (Integers.Int.repr 0) tint))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Ederef
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Efield
                                    (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                    _pad0 (tarray tuchar 48))
                                  (Expr.Econst_int (Integers.Int.repr 13) tint)
                                  (tptr tuchar)) tuchar)
                              (Expr.Econst_int (Integers.Int.repr 0) tint))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Ederef
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Efield
                                      (Expr.Evar ___a64_sim_abi (Ty.Tstruct _arm64_sim_skb_abi noattr))
                                      _pad0 (tarray tuchar 48))
                                    (Expr.Econst_int (Integers.Int.repr 14) tint)
                                    (tptr tuchar)) tuchar)
                                (Expr.Econst_int (Integers.Int.repr 0) tint))
                              (Stmt.Ssequence
                                s_kprog_arm64_entry_skb_0
                                s_kprog_arm64_entry_skb_76))))))))))))))))
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
 (CompositeDef.Composite _arm64_sim_gpr SU.Union
   [(Member.Member_plain _ptr (tptr tvoid)), (Member.Member_plain _x tulong),
    (Member.Member_plain _w tuint)]
   noattr),
 (CompositeDef.Composite _arm64_sim_xdp_abi SU.Struct
   [(Member.Member_plain _data (tptr tvoid)),
    (Member.Member_plain _data_end (tptr tvoid)),
    (Member.Member_plain _cb (tarray tuint 5))]
   noattr),
 (CompositeDef.Composite _arm64_sim_skb_abi SU.Struct
   [(Member.Member_plain _pad0 (tarray tuchar 48)),
    (Member.Member_plain _cb (tarray tuint 5)),
    (Member.Member_plain _pad1 (tarray tuchar 12)),
    (Member.Member_plain _data_end (tptr tvoid)),
    (Member.Member_plain _pad2 (tarray tuchar 120)),
    (Member.Member_plain _data (tptr tvoid))]
   noattr),
 (CompositeDef.Composite _kprog_arm64_entry SU.Struct
   [(Member.Member_plain _cells
      (tptr (tptr (Ty.Tunion _arm64_sim_gpr noattr)))),
    (Member.Member_plain _tag_cells (tptr (tptr tuchar))),
    (Member.Member_plain _sp_base (tptr tulong)),
    (Member.Member_plain _return_base (tptr tulong)),
    (Member.Member_plain _lr (tptr tulong)),
    (Member.Member_plain _sp (tptr tlong)),
    (Member.Member_plain _sp_valid (tptr tuchar)),
    (Member.Member_plain _return_valid (tptr tuchar)),
    (Member.Member_plain _n (tptr tuchar)),
    (Member.Member_plain _z (tptr tuchar)),
    (Member.Member_plain _c (tptr tuchar)),
    (Member.Member_plain _v (tptr tuchar)),
    (Member.Member_plain _vector_lo (tarray (tptr tulong) 32)),
    (Member.Member_plain _vector_hi (tarray (tptr tulong) 32)),
    (Member.Member_plain _b (tptr (tvolatile tuchar))),
    (Member.Member_plain _q (tptr (tvolatile tulong))),
    (Member.Member_plain _payload (tptr (tvolatile tulong))),
    (Member.Member_plain _payload_load
      (tptr (Ty.Tfunction [(tptr (tvolatile tulong)), tulong] tulong
              cc_default))),
    (Member.Member_plain _payload_store
      (tptr (Ty.Tfunction [(tptr (tvolatile tulong)), tulong, tulong] tvoid
              cc_default))), (Member.Member_plain _stack_tags (tptr tuchar)),
    (Member.Member_plain _capacity tuint),
    (Member.Member_plain _payload_words tuint),
    (Member.Member_plain _tag_bytes tuint),
    (Member.Member_plain _bias tlong),
    (Member.Member_plain _helper_context (tptr (tptr tvoid))),
    (Member.Member_plain _helper_abi_base (tptr (tptr tvoid))),
    (Member.Member_plain _is_xdp (tptr tuchar)),
    (Member.Member_plain _abi_kind (tptr tuchar)),
    (Member.Member_plain _skb_context
      (tptr (tptr (Ty.Tstruct ___sk_buff noattr)))),
    (Member.Member_plain _abi (tptr tvoid))]
   noattr),
 (CompositeDef.Composite __2854 SU.Struct
   [(Member.Member_plain _lo tulong), (Member.Member_plain _hi tulong)]
   noattr),
 (CompositeDef.Composite __2856 SU.Union
   [(Member.Member_plain _b (tarray tuchar 160)),
    (Member.Member_plain _q (tarray tulong 20))]
   noattr),
 (CompositeDef.Composite __2946 SU.Struct
   [(Member.Member_plain _lo tulong), (Member.Member_plain _hi tulong)]
   noattr),
 (CompositeDef.Composite __2948 SU.Union
   [(Member.Member_plain _b (tarray tuchar 160)),
    (Member.Member_plain _q (tarray tulong 20))]
   noattr),
 (CompositeDef.Composite __3040 SU.Struct
   [(Member.Member_plain _lo tulong), (Member.Member_plain _hi tulong)]
   noattr),
 (CompositeDef.Composite __3042 SU.Union
   [(Member.Member_plain _b (tarray tuchar 160)),
    (Member.Member_plain _q (tarray tulong 20))]
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
 (_kprog_c_context_pointer,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_external "kprog_c_context_pointer"
                                   (mksignature
                                     [XType.Xptr, XType.Xint8unsigned,
                                      XType.Xint] XType.Xptr cc_default))
     [(tptr tvoid), tuchar, tuint] (tptr tvoid) cc_default)),
 (_native_lab_entry_input,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_external "native_lab_entry_input"
                                   (mksignature [XType.Xint] XType.Xlong
                                     cc_default)) [tuint] tulong cc_default)),
 (_kprog_arm64_payload_load, GlobDef.Gfun (FunDef.Internal f_kprog_arm64_payload_load)),
 (_kprog_arm64_payload_store, GlobDef.Gfun (FunDef.Internal f_kprog_arm64_payload_store)),
 (_kprog_arm64_entry_raw, GlobDef.Gfun (FunDef.Internal f_kprog_arm64_entry_raw)),
 (_kprog_arm64_entry_xdp, GlobDef.Gfun (FunDef.Internal f_kprog_arm64_entry_xdp)),
 (_kprog_arm64_entry_skb, GlobDef.Gfun (FunDef.Internal f_kprog_arm64_entry_skb))]

def public_idents : List Ident :=
[_kprog_arm64_entry_skb, _kprog_arm64_entry_xdp, _kprog_arm64_entry_raw,
 _native_lab_entry_input, _kprog_c_context_pointer, ___builtin_debug,
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

end Arm64Entry

