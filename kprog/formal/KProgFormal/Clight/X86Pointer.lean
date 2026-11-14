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
def __3138 : Ident := identOfString "_3138"
def __3144 : Ident := identOfString "_3144"
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
def ___kprog_x86_lane : Ident := identOfString "__kprog_x86_lane"
def ___kprog_x86_lane__1 : Ident := identOfString "__kprog_x86_lane__1"
def ___kprog_x86_partial : Ident := identOfString "__kprog_x86_partial"
def ___kprog_x86_partial__1 : Ident := identOfString "__kprog_x86_partial__1"
def ___kprog_x86_pw_tag : Ident := identOfString "__kprog_x86_pw_tag"
def ___kprog_x86_source_tag : Ident := identOfString "__kprog_x86_source_tag"
def ___sk_buff : Ident := identOfString "__sk_buff"
def ___x86_l_pw_tag : Ident := identOfString "__x86_l_pw_tag"
def ___x86_l_tag : Ident := identOfString "__x86_l_tag"
def ___x86_release_i : Ident := identOfString "__x86_release_i"
def ___x86_release_i__1 : Ident := identOfString "__x86_release_i__1"
def ___x86_release_lane : Ident := identOfString "__x86_release_lane"
def ___x86_release_lane__1 : Ident := identOfString "__x86_release_lane__1"
def ___x86_release_new : Ident := identOfString "__x86_release_new"
def ___x86_release_new__1 : Ident := identOfString "__x86_release_new__1"
def ___x86_release_off : Ident := identOfString "__x86_release_off"
def ___x86_release_off__1 : Ident := identOfString "__x86_release_off__1"
def ___x86_release_old : Ident := identOfString "__x86_release_old"
def ___x86_release_old__1 : Ident := identOfString "__x86_release_old__1"
def ___x86_stack_delta : Ident := identOfString "__x86_stack_delta"
def ___x86_stack_delta__1 : Ident := identOfString "__x86_stack_delta__1"
def ___x86_state : Ident := identOfString "__x86_state"
def ___x86_sv_i : Ident := identOfString "__x86_sv_i"
def ___x86_sv_i__1 : Ident := identOfString "__x86_sv_i__1"
def ___x86_sv_sp : Ident := identOfString "__x86_sv_sp"
def ___x86_sv_sp__1 : Ident := identOfString "__x86_sv_sp__1"
def ___x86_wr_cell : Ident := identOfString "__x86_wr_cell"
def ___x86_wr_cell_tag : Ident := identOfString "__x86_wr_cell_tag"
def ___x86_wr_next : Ident := identOfString "__x86_wr_next"
def ___x86_wr_next_ptr : Ident := identOfString "__x86_wr_next_ptr"
def ___x86_wr_next_ptr__1 : Ident := identOfString "__x86_wr_next_ptr__1"
def ___x86_wr_next_tag : Ident := identOfString "__x86_wr_next_tag"
def ___x86_wr_next_tag__1 : Ident := identOfString "__x86_wr_next_tag__1"
def ___x86_wr_raw_width : Ident := identOfString "__x86_wr_raw_width"
def ___x86_wr_shift : Ident := identOfString "__x86_wr_shift"
def ___x86_wr_stack_bits : Ident := identOfString "__x86_wr_stack_bits"
def ___x86_wr_stack_bits__1 : Ident := identOfString "__x86_wr_stack_bits__1"
def ___x86_wr_width : Ident := identOfString "__x86_wr_width"
def ___x86_write_old_sp : Ident := identOfString "__x86_write_old_sp"
def ___x86_write_old_sp__1 : Ident := identOfString "__x86_write_old_sp__1"
def _abi_kind : Ident := identOfString "abi_kind"
def _af : Ident := identOfString "af"
def _aux : Ident := identOfString "aux"
def _b : Ident := identOfString "b"
def _bpf_flow_keys : Ident := identOfString "bpf_flow_keys"
def _bpf_sock : Ident := identOfString "bpf_sock"
def _call_depth : Ident := identOfString "call_depth"
def _cb : Ident := identOfString "cb"
def _cf : Ident := identOfString "cf"
def _code : Ident := identOfString "code"
def _d : Ident := identOfString "d"
def _data : Ident := identOfString "data"
def _data_end : Ident := identOfString "data_end"
def _data_meta : Ident := identOfString "data_meta"
def _dst : Ident := identOfString "dst"
def _family : Ident := identOfString "family"
def _flow_keys : Ident := identOfString "flow_keys"
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
def _kprog_x86_ptr_load : Ident := identOfString "kprog_x86_ptr_load"
def _len : Ident := identOfString "len"
def _local_ip4 : Ident := identOfString "local_ip4"
def _local_ip6 : Ident := identOfString "local_ip6"
def _local_port : Ident := identOfString "local_port"
def _main : Ident := identOfString "main"
def _mark : Ident := identOfString "mark"
def _napi_id : Ident := identOfString "napi_id"
def _native_lab_entry_input : Ident := identOfString "native_lab_entry_input"
def _native_stack_base : Ident := identOfString "native_stack_base"
def _of : Ident := identOfString "of"
def _op : Ident := identOfString "op"
def _pad0 : Ident := identOfString "pad0"
def _pad1 : Ident := identOfString "pad1"
def _pad2 : Ident := identOfString "pad2"
def _pf : Ident := identOfString "pf"
def _pkt_type : Ident := identOfString "pkt_type"
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
def _remote_ip4 : Ident := identOfString "remote_ip4"
def _remote_ip6 : Ident := identOfString "remote_ip6"
def _remote_port : Ident := identOfString "remote_port"
def _ret_addr : Ident := identOfString "ret_addr"
def _rsi : Ident := identOfString "rsi"
def _rsi_tag : Ident := identOfString "rsi_tag"
def _rsp : Ident := identOfString "rsp"
def _rsp_tag : Ident := identOfString "rsp_tag"
def _sf : Ident := identOfString "sf"
def _sk : Ident := identOfString "sk"
def _skb_abi : Ident := identOfString "skb_abi"
def _skb_ctx : Ident := identOfString "skb_ctx"
def _stack_mem : Ident := identOfString "stack_mem"
def _state : Ident := identOfString "state"
def _tc_classid : Ident := identOfString "tc_classid"
def _tc_index : Ident := identOfString "tc_index"
def _tstamp : Ident := identOfString "tstamp"
def _tstamp_type : Ident := identOfString "tstamp_type"
def _value_ptrs : Ident := identOfString "value_ptrs"
def _value_tags : Ident := identOfString "value_tags"
def _vlan_present : Ident := identOfString "vlan_present"
def _vlan_proto : Ident := identOfString "vlan_proto"
def _vlan_tci : Ident := identOfString "vlan_tci"
def _w : Ident := identOfString "w"
def _wire_len : Ident := identOfString "wire_len"
def _x86_sim_gpr : Ident := identOfString "x86_sim_gpr"
def _x86_sim_skb_abi : Ident := identOfString "x86_sim_skb_abi"
def _x86_sim_stack_mem : Ident := identOfString "x86_sim_stack_mem"
def _x86_sim_state : Ident := identOfString "x86_sim_state"
def _x86_sim_xdp_abi : Ident := identOfString "x86_sim_xdp_abi"
def _x86_width_effective : Ident := identOfString "x86_width_effective"
def _xdp_abi : Ident := identOfString "xdp_abi"
def _xmm0_hi : Ident := identOfString "xmm0_hi"
def _xmm0_lo : Ident := identOfString "xmm0_lo"
def _zf : Ident := identOfString "zf"
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
def _t'8 : Ident := (Positive.ofNat 135)
def _t'9 : Ident := (Positive.ofNat 136)

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

def s_kprog_x86_ptr_load_0 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'71
    (Expr.Efield
      (Expr.Efield
        (Expr.Ederef
          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
          (Ty.Tstruct _x86_sim_state noattr)) _rax
        (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
  (Stmt.Sset _t'3
    (Expr.Ecast (Expr.Etempvar _t'71 (tptr tvoid)) (tptr tvoid))))

def s_kprog_x86_ptr_load_1 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'65
      (Expr.Efield
        (Expr.Efield
          (Expr.Ederef
            (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
            (Ty.Tstruct _x86_sim_state noattr)) _rsi
          (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
    (Stmt.Sset _t'3
      (Expr.Ecast (Expr.Etempvar _t'65 (tptr tvoid)) (tptr tvoid))))
  (Stmt.Sset _t'3
    (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))

def s_kprog_x86_ptr_load_2 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sset _t'64
            (Expr.Efield
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                  (Ty.Tstruct _x86_sim_state noattr)) _rdi
                (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
          (Stmt.Sset _t'3
            (Expr.Ecast (Expr.Etempvar _t'64 (tptr tvoid)) (tptr tvoid))))
        (Stmt.Sset _t'3
          (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
      (Stmt.Sset _t'3
        (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
    (Stmt.Sset _t'3
      (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
  (Stmt.Sset _t'3
    (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))

def s_kprog_x86_ptr_load_3 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'63
                  (Expr.Efield
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                        (Ty.Tstruct _x86_sim_state noattr)) _r8
                      (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
                (Stmt.Sset _t'3
                  (Expr.Ecast (Expr.Etempvar _t'63 (tptr tvoid))
                    (tptr tvoid))))
              (Stmt.Sset _t'3
                (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
            (Stmt.Sset _t'3
              (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
          (Stmt.Sset _t'3
            (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
        (Stmt.Sset _t'3
          (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
      (Stmt.Sset _t'3
        (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
    (Stmt.Sset _t'3
      (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
  (Stmt.Sset _t'3
    (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))

def s_kprog_x86_ptr_load_4 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sset _t'62
                      (Expr.Efield
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                            (Ty.Tstruct _x86_sim_state noattr)) _r9
                          (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
                    (Stmt.Sset _t'3
                      (Expr.Ecast (Expr.Etempvar _t'62 (tptr tvoid))
                        (tptr tvoid))))
                  (Stmt.Sset _t'3
                    (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                      (tptr tvoid))))
                (Stmt.Sset _t'3
                  (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
              (Stmt.Sset _t'3
                (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
            (Stmt.Sset _t'3
              (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
          (Stmt.Sset _t'3
            (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
        (Stmt.Sset _t'3
          (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
      (Stmt.Sset _t'3
        (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
    (Stmt.Sset _t'3
      (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
  (Stmt.Sset _t'3
    (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))

def s_kprog_x86_ptr_load_5 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'59
      (Expr.Efield
        (Expr.Efield
          (Expr.Ederef
            (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
            (Ty.Tstruct _x86_sim_state noattr)) _r12
          (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
    (Stmt.Sset _t'3
      (Expr.Ecast (Expr.Etempvar _t'59 (tptr tvoid)) (tptr tvoid))))
  (Stmt.Sset _t'3
    (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))

def s_kprog_x86_ptr_load_6 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sset _t'58
            (Expr.Efield
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                  (Ty.Tstruct _x86_sim_state noattr)) _r13
                (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
          (Stmt.Sset _t'3
            (Expr.Ecast (Expr.Etempvar _t'58 (tptr tvoid)) (tptr tvoid))))
        (Stmt.Sset _t'3
          (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
      (Stmt.Sset _t'3
        (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
    (Stmt.Sset _t'3
      (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
  (Stmt.Sset _t'3
    (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))

def s_kprog_x86_ptr_load_7 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'57
                  (Expr.Efield
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                        (Ty.Tstruct _x86_sim_state noattr)) _r14
                      (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
                (Stmt.Sset _t'3
                  (Expr.Ecast (Expr.Etempvar _t'57 (tptr tvoid))
                    (tptr tvoid))))
              (Stmt.Sset _t'3
                (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
            (Stmt.Sset _t'3
              (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
          (Stmt.Sset _t'3
            (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
        (Stmt.Sset _t'3
          (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
      (Stmt.Sset _t'3
        (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
    (Stmt.Sset _t'3
      (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
  (Stmt.Sset _t'3
    (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))

def s_kprog_x86_ptr_load_8 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sset _t'56
                        (Expr.Efield
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                              (Ty.Tstruct _x86_sim_state noattr)) _r15
                            (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                          (tptr tvoid)))
                      (Stmt.Sset _t'3
                        (Expr.Ecast (Expr.Etempvar _t'56 (tptr tvoid))
                          (tptr tvoid))))
                    (Stmt.Sset _t'3
                      (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                        (tptr tvoid))))
                  (Stmt.Sset _t'3
                    (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                      (tptr tvoid))))
                (Stmt.Sset _t'3
                  (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
              (Stmt.Sset _t'3
                (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
            (Stmt.Sset _t'3
              (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
          (Stmt.Sset _t'3
            (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
        (Stmt.Sset _t'3
          (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
      (Stmt.Sset _t'3
        (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
    (Stmt.Sset _t'3
      (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
  (Stmt.Sset _t'3
    (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))

def s_kprog_x86_ptr_load_9 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sset _t'3
                      (Expr.Ecast
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 0) tint)
                          (tptr tvoid)) (tptr tvoid)))
                    (Stmt.Sset _t'3
                      (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                        (tptr tvoid))))
                  (Stmt.Sset _t'3
                    (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                      (tptr tvoid))))
                (Stmt.Sset _t'3
                  (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
              (Stmt.Sset _t'3
                (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
            (Stmt.Sset _t'3
              (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
          (Stmt.Sset _t'3
            (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
        (Stmt.Sset _t'3
          (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
      (Stmt.Sset _t'3
        (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
    (Stmt.Sset _t'3
      (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
  (Stmt.Sset _t'3
    (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))

def s_kprog_x86_ptr_load_10 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _dst tuchar)
                    (Expr.Econst_int (Integers.Int.repr 10) tuint) tint)
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sset _t'61
                          (Expr.Efield
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                (Ty.Tstruct _x86_sim_state noattr)) _r10
                              (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                            (tptr tvoid)))
                        (Stmt.Sset _t'3
                          (Expr.Ecast (Expr.Etempvar _t'61 (tptr tvoid))
                            (tptr tvoid))))
                      (Stmt.Sset _t'3
                        (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                          (tptr tvoid))))
                    (Stmt.Sset _t'3
                      (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                        (tptr tvoid))))
                  (Stmt.Sset _t'3
                    (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                      (tptr tvoid))))
                (Stmt.Sset _t'3
                  (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
              (Stmt.Sset _t'3
                (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
            (Stmt.Sset _t'3
              (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
          (Stmt.Sset _t'3
            (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
        (Stmt.Sset _t'3
          (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
      (Stmt.Sset _t'3
        (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
    (Stmt.Sset _t'3
      (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _dst tuchar)
                      (Expr.Econst_int (Integers.Int.repr 11) tuint) tint)
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Sset _t'60
                              (Expr.Efield
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                    (Ty.Tstruct _x86_sim_state noattr)) _r11
                                  (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                                (tptr tvoid)))
                            (Stmt.Sset _t'3
                              (Expr.Ecast (Expr.Etempvar _t'60 (tptr tvoid))
                                (tptr tvoid))))
                          (Stmt.Sset _t'3
                            (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                              (tptr tvoid))))
                        (Stmt.Sset _t'3
                          (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                            (tptr tvoid))))
                      (Stmt.Sset _t'3
                        (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                          (tptr tvoid))))
                    (Stmt.Sset _t'3
                      (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                        (tptr tvoid))))
                  (Stmt.Sset _t'3
                    (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                      (tptr tvoid))))
                (Stmt.Sset _t'3
                  (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
              (Stmt.Sset _t'3
                (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
            (Stmt.Sset _t'3
              (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
          (Stmt.Sset _t'3
            (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
        (Stmt.Sset _t'3
          (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
      (Stmt.Sset _t'3
        (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _dst tuchar)
                        (Expr.Econst_int (Integers.Int.repr 12) tuint) tint)
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            s_kprog_x86_ptr_load_5
                            (Stmt.Sset _t'3
                              (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                                (tptr tvoid))))
                          (Stmt.Sset _t'3
                            (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                              (tptr tvoid))))
                        (Stmt.Sset _t'3
                          (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                            (tptr tvoid))))
                      (Stmt.Sset _t'3
                        (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                          (tptr tvoid))))
                    (Stmt.Sset _t'3
                      (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                        (tptr tvoid))))
                  (Stmt.Sset _t'3
                    (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                      (tptr tvoid))))
                (Stmt.Sset _t'3
                  (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
              (Stmt.Sset _t'3
                (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
            (Stmt.Sset _t'3
              (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
          (Stmt.Sset _t'3
            (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
        (Stmt.Sset _t'3
          (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _dst tuchar)
                          (Expr.Econst_int (Integers.Int.repr 13) tuint)
                          tint)
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          s_kprog_x86_ptr_load_6
                          (Stmt.Sset _t'3
                            (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                              (tptr tvoid))))
                        (Stmt.Sset _t'3
                          (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                            (tptr tvoid))))
                      (Stmt.Sset _t'3
                        (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                          (tptr tvoid))))
                    (Stmt.Sset _t'3
                      (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                        (tptr tvoid))))
                  (Stmt.Sset _t'3
                    (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                      (tptr tvoid))))
                (Stmt.Sset _t'3
                  (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
              (Stmt.Sset _t'3
                (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
            (Stmt.Sset _t'3
              (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
          (Stmt.Sset _t'3
            (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _dst tuchar)
                            (Expr.Econst_int (Integers.Int.repr 14) tuint)
                            tint)
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        s_kprog_x86_ptr_load_7
                        (Stmt.Sset _t'3
                          (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                            (tptr tvoid))))
                      (Stmt.Sset _t'3
                        (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                          (tptr tvoid))))
                    (Stmt.Sset _t'3
                      (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                        (tptr tvoid))))
                  (Stmt.Sset _t'3
                    (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                      (tptr tvoid))))
                (Stmt.Sset _t'3
                  (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
              (Stmt.Sset _t'3
                (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
            (Stmt.Sset _t'3
              (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar _dst tuchar)
                              (Expr.Econst_int (Integers.Int.repr 15) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      s_kprog_x86_ptr_load_8
                      (Stmt.Sset _t'3
                        (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                          (tptr tvoid))))
                    (Stmt.Sset _t'3
                      (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                        (tptr tvoid))))
                  (Stmt.Sset _t'3
                    (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                      (tptr tvoid))))
                (Stmt.Sset _t'3
                  (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
              (Stmt.Sset _t'3
                (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      s_kprog_x86_ptr_load_9
                      (Stmt.Sset _t'3
                        (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                          (tptr tvoid))))
                    (Stmt.Sset _t'3
                      (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                        (tptr tvoid))))
                  (Stmt.Sset _t'3
                    (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                      (tptr tvoid))))
                (Stmt.Sset _t'3
                  (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
              (Stmt.Sset _t'3
                (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))))))))

def s_kprog_x86_ptr_load_11 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _dst tuchar)
                    (Expr.Econst_int (Integers.Int.repr 1) tuint) tint)
  (Stmt.Ssequence
    (Stmt.Ssequence
      (Stmt.Sset _t'70
        (Expr.Efield
          (Expr.Efield
            (Expr.Ederef
              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
              (Ty.Tstruct _x86_sim_state noattr)) _rcx
            (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
      (Stmt.Sset _t'3
        (Expr.Ecast (Expr.Etempvar _t'70 (tptr tvoid)) (tptr tvoid))))
    (Stmt.Sset _t'3
      (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _dst tuchar)
                      (Expr.Econst_int (Integers.Int.repr 2) tuint) tint)
    (Stmt.Ssequence
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sset _t'69
            (Expr.Efield
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                  (Ty.Tstruct _x86_sim_state noattr)) _rdx
                (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
          (Stmt.Sset _t'3
            (Expr.Ecast (Expr.Etempvar _t'69 (tptr tvoid)) (tptr tvoid))))
        (Stmt.Sset _t'3
          (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
      (Stmt.Sset _t'3
        (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _dst tuchar)
                        (Expr.Econst_int (Integers.Int.repr 3) tuint) tint)
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sset _t'68
                (Expr.Efield
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                      (Ty.Tstruct _x86_sim_state noattr)) _rbx
                    (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
              (Stmt.Sset _t'3
                (Expr.Ecast (Expr.Etempvar _t'68 (tptr tvoid)) (tptr tvoid))))
            (Stmt.Sset _t'3
              (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
          (Stmt.Sset _t'3
            (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
        (Stmt.Sset _t'3
          (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _dst tuchar)
                          (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sset _t'67
                    (Expr.Efield
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                          (Ty.Tstruct _x86_sim_state noattr)) _rsp
                        (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
                  (Stmt.Sset _t'3
                    (Expr.Ecast (Expr.Etempvar _t'67 (tptr tvoid))
                      (tptr tvoid))))
                (Stmt.Sset _t'3
                  (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
              (Stmt.Sset _t'3
                (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
            (Stmt.Sset _t'3
              (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
          (Stmt.Sset _t'3
            (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _dst tuchar)
                            (Expr.Econst_int (Integers.Int.repr 5) tuint)
                            tint)
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sset _t'66
                        (Expr.Efield
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                              (Ty.Tstruct _x86_sim_state noattr)) _rbp
                            (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                          (tptr tvoid)))
                      (Stmt.Sset _t'3
                        (Expr.Ecast (Expr.Etempvar _t'66 (tptr tvoid))
                          (tptr tvoid))))
                    (Stmt.Sset _t'3
                      (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                        (tptr tvoid))))
                  (Stmt.Sset _t'3
                    (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                      (tptr tvoid))))
                (Stmt.Sset _t'3
                  (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
              (Stmt.Sset _t'3
                (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
            (Stmt.Sset _t'3
              (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Etempvar _dst tuchar)
                              (Expr.Econst_int (Integers.Int.repr 6) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      s_kprog_x86_ptr_load_1
                      (Stmt.Sset _t'3
                        (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                          (tptr tvoid))))
                    (Stmt.Sset _t'3
                      (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                        (tptr tvoid))))
                  (Stmt.Sset _t'3
                    (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                      (tptr tvoid))))
                (Stmt.Sset _t'3
                  (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
              (Stmt.Sset _t'3
                (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                (Expr.Etempvar _dst tuchar)
                                (Expr.Econst_int (Integers.Int.repr 7) tuint)
                                tint)
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    s_kprog_x86_ptr_load_2
                    (Stmt.Sset _t'3
                      (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                        (tptr tvoid))))
                  (Stmt.Sset _t'3
                    (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                      (tptr tvoid))))
                (Stmt.Sset _t'3
                  (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid)) (tptr tvoid))))
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar _dst tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                  tint)
                (Stmt.Ssequence
                  s_kprog_x86_ptr_load_3
                  (Stmt.Sset _t'3
                    (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                      (tptr tvoid))))
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Etempvar _dst tuchar)
                                    (Expr.Econst_int (Integers.Int.repr 9) tuint)
                                    tint)
                  s_kprog_x86_ptr_load_4
                  s_kprog_x86_ptr_load_10)))))))))

def s_kprog_x86_ptr_load_12 : Stmt :=
(Stmt.Sset ___x86_l_tag
  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuchar))

def s_kprog_x86_ptr_load_13 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sswitch (Expr.Etempvar _dst tuchar)
    (LStmts.LScons (some 0)
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sset _t'55
            (Expr.Efield
              (Expr.Ederef
                (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                (Ty.Tstruct _x86_sim_state noattr)) _rax_tag tuchar))
          (Stmt.Sset ___x86_l_tag
            (Expr.Ecast (Expr.Etempvar _t'55 tuchar) tuchar)))
        Stmt.Sbreak)
      (LStmts.LScons (some 1)
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sset _t'54
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                  (Ty.Tstruct _x86_sim_state noattr)) _rcx_tag tuchar))
            (Stmt.Sset ___x86_l_tag
              (Expr.Ecast (Expr.Etempvar _t'54 tuchar) tuchar)))
          Stmt.Sbreak)
        (LStmts.LScons (some 2)
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sset _t'53
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                    (Ty.Tstruct _x86_sim_state noattr)) _rdx_tag tuchar))
              (Stmt.Sset ___x86_l_tag
                (Expr.Ecast (Expr.Etempvar _t'53 tuchar) tuchar)))
            Stmt.Sbreak)
          (LStmts.LScons (some 3)
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'52
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                      (Ty.Tstruct _x86_sim_state noattr)) _rbx_tag tuchar))
                (Stmt.Sset ___x86_l_tag
                  (Expr.Ecast (Expr.Etempvar _t'52 tuchar) tuchar)))
              Stmt.Sbreak)
            (LStmts.LScons (some 4)
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sset _t'51
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                        (Ty.Tstruct _x86_sim_state noattr)) _rsp_tag tuchar))
                  (Stmt.Sset ___x86_l_tag
                    (Expr.Ecast (Expr.Etempvar _t'51 tuchar) tuchar)))
                Stmt.Sbreak)
              (LStmts.LScons (some 5)
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sset _t'50
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                          (Ty.Tstruct _x86_sim_state noattr)) _rbp_tag
                        tuchar))
                    (Stmt.Sset ___x86_l_tag
                      (Expr.Ecast (Expr.Etempvar _t'50 tuchar) tuchar)))
                  Stmt.Sbreak)
                (LStmts.LScons (some 6)
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sset _t'49
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                            (Ty.Tstruct _x86_sim_state noattr)) _rsi_tag
                          tuchar))
                      (Stmt.Sset ___x86_l_tag
                        (Expr.Ecast (Expr.Etempvar _t'49 tuchar) tuchar)))
                    Stmt.Sbreak)
                  (LStmts.LScons (some 7)
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sset _t'48
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                              (Ty.Tstruct _x86_sim_state noattr)) _rdi_tag
                            tuchar))
                        (Stmt.Sset ___x86_l_tag
                          (Expr.Ecast (Expr.Etempvar _t'48 tuchar) tuchar)))
                      Stmt.Sbreak)
                    (LStmts.LScons (some 8)
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Sset _t'47
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                (Ty.Tstruct _x86_sim_state noattr)) _r8_tag
                              tuchar))
                          (Stmt.Sset ___x86_l_tag
                            (Expr.Ecast (Expr.Etempvar _t'47 tuchar) tuchar)))
                        Stmt.Sbreak)
                      (LStmts.LScons (some 9)
                        (Stmt.Ssequence
                          (Stmt.Ssequence
                            (Stmt.Sset _t'46
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                  (Ty.Tstruct _x86_sim_state noattr)) _r9_tag
                                tuchar))
                            (Stmt.Sset ___x86_l_tag
                              (Expr.Ecast (Expr.Etempvar _t'46 tuchar)
                                tuchar)))
                          Stmt.Sbreak)
                        (LStmts.LScons (some 10)
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Sset _t'45
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                    (Ty.Tstruct _x86_sim_state noattr))
                                  _r10_tag tuchar))
                              (Stmt.Sset ___x86_l_tag
                                (Expr.Ecast (Expr.Etempvar _t'45 tuchar)
                                  tuchar)))
                            Stmt.Sbreak)
                          (LStmts.LScons (some 11)
                            (Stmt.Ssequence
                              (Stmt.Ssequence
                                (Stmt.Sset _t'44
                                  (Expr.Efield
                                    (Expr.Ederef
                                      (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                      (Ty.Tstruct _x86_sim_state noattr))
                                    _r11_tag tuchar))
                                (Stmt.Sset ___x86_l_tag
                                  (Expr.Ecast (Expr.Etempvar _t'44 tuchar)
                                    tuchar)))
                              Stmt.Sbreak)
                            (LStmts.LScons (some 12)
                              (Stmt.Ssequence
                                (Stmt.Ssequence
                                  (Stmt.Sset _t'43
                                    (Expr.Efield
                                      (Expr.Ederef
                                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                        (Ty.Tstruct _x86_sim_state noattr))
                                      _r12_tag tuchar))
                                  (Stmt.Sset ___x86_l_tag
                                    (Expr.Ecast (Expr.Etempvar _t'43 tuchar)
                                      tuchar)))
                                Stmt.Sbreak)
                              (LStmts.LScons (some 13)
                                (Stmt.Ssequence
                                  (Stmt.Ssequence
                                    (Stmt.Sset _t'42
                                      (Expr.Efield
                                        (Expr.Ederef
                                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                          (Ty.Tstruct _x86_sim_state noattr))
                                        _r13_tag tuchar))
                                    (Stmt.Sset ___x86_l_tag
                                      (Expr.Ecast
                                        (Expr.Etempvar _t'42 tuchar) tuchar)))
                                  Stmt.Sbreak)
                                (LStmts.LScons (some 14)
                                  (Stmt.Ssequence
                                    (Stmt.Ssequence
                                      (Stmt.Sset _t'41
                                        (Expr.Efield
                                          (Expr.Ederef
                                            (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                            (Ty.Tstruct _x86_sim_state noattr))
                                          _r14_tag tuchar))
                                      (Stmt.Sset ___x86_l_tag
                                        (Expr.Ecast
                                          (Expr.Etempvar _t'41 tuchar)
                                          tuchar)))
                                    Stmt.Sbreak)
                                  (LStmts.LScons (some 15)
                                    (Stmt.Ssequence
                                      (Stmt.Ssequence
                                        (Stmt.Sset _t'40
                                          (Expr.Efield
                                            (Expr.Ederef
                                              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                              (Ty.Tstruct _x86_sim_state noattr))
                                            _r15_tag tuchar))
                                        (Stmt.Sset ___x86_l_tag
                                          (Expr.Ecast
                                            (Expr.Etempvar _t'40 tuchar)
                                            tuchar)))
                                      Stmt.Sbreak)
                                    (LStmts.LScons none
                                      Stmt.Sbreak
                                      LStmts.LSnil))))))))))))))))))
  (Stmt.Sset ___x86_wr_cell_tag
    (Expr.Ecast (Expr.Etempvar ___x86_l_tag tuchar) tuchar)))

def s_kprog_x86_ptr_load_14 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                    (Expr.Ecast (Expr.Etempvar ___x86_wr_width tuchar)
                      tuchar) (Expr.Econst_int (Integers.Int.repr 1) tuint)
                    tint)
  (Stmt.Sset _t'8
    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuint))
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
                          tuchar)
                        (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
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
        (Stmt.Sset _t'8 (Expr.Ecast (Expr.Etempvar _t'8 tuint) tuint))))))

def s_kprog_x86_ptr_load_15 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _dst tuchar)
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
              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
              (Ty.Tstruct _x86_sim_state noattr)) _native_stack_base tulong))
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
              (Stmt.Sset _t'37
                (Expr.Efield
                  (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                  _ptr (tptr tvoid)))
              (Stmt.Sset ___x86_stack_delta
                (Expr.Ebinop Binop.Osub
                  (Expr.Ecast
                    (Expr.Ecast (Expr.Etempvar _t'37 (tptr tvoid)) tlong)
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
                                    (Expr.Efield
                                      (Expr.Efield
                                        (Expr.Ederef
                                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                          (Ty.Tstruct _x86_sim_state noattr))
                                        _stack_mem
                                        (Ty.Tunion _x86_sim_stack_mem noattr))
                                      _b (tarray tuchar 64))
                                    (Expr.Econst_int (Integers.Int.repr 0) tint)
                                    (tptr tuchar)) tulong) tulong)
                              (Expr.Ecast
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 0) tint)
                                    tulong)
                                  (Expr.Ecast
                                    (Expr.Econst_int (Integers.Int.repr 64) tuint)
                                    tulong) tulong) tulong) tulong) tulong)
                          (tptr tuchar)) (tptr tvoid)) tlong) tulong) tulong)))
            (Stmt.Ssequence
              (Stmt.Sset _t'36
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                    (Ty.Tstruct _x86_sim_state noattr)) _native_stack_base
                  tulong))
              (Stmt.Sset ___x86_wr_stack_bits
                (Expr.Ebinop Binop.Oadd
                  (Expr.Etempvar ___x86_stack_delta tulong)
                  (Expr.Etempvar _t'36 tulong) tulong))))
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
              (Stmt.Sset _t'35
                (Expr.Efield
                  (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                  _ptr (tptr tvoid)))
              (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
                [(tptr (tvolatile (tptr tvoid))), (tvolatile (tptr tvoid))]
                [(Expr.Eaddrof
                   (Expr.Efield
                     (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3138 noattr)))
                     _ptr (tvolatile (tptr tvoid)))
                   (tptr (tvolatile (tptr tvoid)))),
                 (Expr.Etempvar _t'35 (tptr tvoid))]))
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                  (Expr.Etempvar ___x86_wr_shift tuchar)
                                  (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                  tint)
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3138 noattr)))
                        _b (tvolatile (tarray tuchar 8)))
                      (Expr.Econst_int (Integers.Int.repr 1) tint)
                      (tptr tuchar)) tuchar)
                  (Expr.Etempvar ___kprog_x86_lane tuchar))
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3138 noattr)))
                        _b (tvolatile (tarray tuchar 8)))
                      (Expr.Econst_int (Integers.Int.repr 0) tint)
                      (tptr tuchar)) tuchar)
                  (Expr.Etempvar ___kprog_x86_lane tuchar)))
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sbuiltin (some _t'4) (ExtFun.EF_vload Chunk.Mint64)
                    [(tptr (tvolatile (tptr tvoid)))]
                    [(Expr.Eaddrof
                       (Expr.Efield
                         (Expr.Evar ___kprog_x86_partial (tvolatile (Ty.Tunion __3138 noattr)))
                         _ptr (tvolatile (tptr tvoid)))
                       (tptr (tvolatile (tptr tvoid))))])
                  (Stmt.Sset ___kprog_x86_bits
                    (Expr.Ecast
                      (Expr.Ecast
                        (Expr.Etempvar _t'4 (tvolatile (tptr tvoid))) tlong)
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

def s_kprog_x86_ptr_load_16 : Stmt :=
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
                      (Expr.Econst_int (Integers.Int.repr 1) tuint) tint)
    (Stmt.Ssequence
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _dst tuchar)
                          (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
        (Stmt.Ssequence
          (Stmt.Sset _t'33
            (Expr.Efield
              (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr)) _ptr
              (tptr tvoid)))
          (Stmt.Ssequence
            (Stmt.Sset _t'34
              (Expr.Efield
                (Expr.Ederef
                  (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                  (Ty.Tstruct _x86_sim_state noattr)) _native_stack_base
                tulong))
            (Stmt.Sassign
              (Expr.Efield
                (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                _ptr (tptr tvoid))
              (Expr.Ecast
                (Expr.Ecast
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Ecast
                      (Expr.Ecast (Expr.Etempvar _t'33 (tptr tvoid)) tlong)
                      tulong) (Expr.Etempvar _t'34 tulong) tulong) tlong)
                (tptr tvoid)))))
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar ___x86_wr_cell_tag tuchar)
                            (Expr.Econst_int (Integers.Int.repr 4) tuint)
                            tint)
          (Stmt.Ssequence
            (Stmt.Sloop
              (Stmt.Ssequence
                (Stmt.Ssequence
                  (Stmt.Sset _t'32
                    (Expr.Efield
                      (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                      _ptr (tptr tvoid)))
                  (Stmt.Sset ___x86_stack_delta__1
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
                                        (Expr.Efield
                                          (Expr.Efield
                                            (Expr.Ederef
                                              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                              (Ty.Tstruct _x86_sim_state noattr))
                                            _stack_mem
                                            (Ty.Tunion _x86_sim_stack_mem noattr))
                                          _b (tarray tuchar 64))
                                        (Expr.Econst_int (Integers.Int.repr 0) tint)
                                        (tptr tuchar)) tulong) tulong)
                                  (Expr.Ecast
                                    (Expr.Ebinop Binop.Oadd
                                      (Expr.Ecast
                                        (Expr.Econst_int (Integers.Int.repr 0) tint)
                                        tulong)
                                      (Expr.Ecast
                                        (Expr.Econst_int (Integers.Int.repr 64) tuint)
                                        tulong) tulong) tulong) tulong)
                                tulong) (tptr tuchar)) (tptr tvoid)) tlong)
                        tulong) tulong)))
                (Stmt.Ssequence
                  (Stmt.Sset _t'31
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                        (Ty.Tstruct _x86_sim_state noattr))
                      _native_stack_base tulong))
                  (Stmt.Sset ___x86_wr_stack_bits__1
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Etempvar ___x86_stack_delta__1 tulong)
                      (Expr.Etempvar _t'31 tulong) tulong))))
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
                  (Stmt.Sset _t'30
                    (Expr.Efield
                      (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                      _ptr (tptr tvoid)))
                  (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint64)
                    [(tptr (tvolatile (tptr tvoid))),
                     (tvolatile (tptr tvoid))]
                    [(Expr.Eaddrof
                       (Expr.Efield
                         (Expr.Evar ___kprog_x86_partial__1 (tvolatile (Ty.Tunion __3144 noattr)))
                         _ptr (tvolatile (tptr tvoid)))
                       (tptr (tvolatile (tptr tvoid)))),
                     (Expr.Etempvar _t'30 (tptr tvoid))]))
                (Stmt.Ssequence
                  (Stmt.Sbuiltin none (ExtFun.EF_vstore Chunk.Mint16unsigned)
                    [(tptr (tvolatile tushort)), (tvolatile tushort)]
                    [(Expr.Eaddrof
                       (Expr.Efield
                         (Expr.Evar ___kprog_x86_partial__1 (tvolatile (Ty.Tunion __3144 noattr)))
                         _w (tvolatile tushort)) (tptr (tvolatile tushort))),
                     (Expr.Etempvar ___kprog_x86_lane__1 tushort)])
                  (Stmt.Ssequence
                    (Stmt.Ssequence
                      (Stmt.Sbuiltin (some _t'5)
                        (ExtFun.EF_vload Chunk.Mint64)
                        [(tptr (tvolatile (tptr tvoid)))]
                        [(Expr.Eaddrof
                           (Expr.Efield
                             (Expr.Evar ___kprog_x86_partial__1 (tvolatile (Ty.Tunion __3144 noattr)))
                             _ptr (tvolatile (tptr tvoid)))
                           (tptr (tvolatile (tptr tvoid))))])
                      (Stmt.Sset ___kprog_x86_bits__1
                        (Expr.Ecast
                          (Expr.Ecast
                            (Expr.Etempvar _t'5 (tvolatile (tptr tvoid)))
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
        (Stmt.Sset _t'6
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuint))
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                            (Expr.Ecast
                              (Expr.Etempvar ___x86_wr_width tuchar) tuchar)
                            (Expr.Econst_int (Integers.Int.repr 2) tuint)
                            tint)
          (Stmt.Ssequence
            (Stmt.Sset _t'6
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 1) tuint)
                tuint))
            (Stmt.Sset _t'6 (Expr.Ecast (Expr.Etempvar _t'6 tuint) tuint)))
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                              (Expr.Ecast
                                (Expr.Etempvar ___x86_wr_width tuchar)
                                tuchar)
                              (Expr.Econst_int (Integers.Int.repr 4) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'6
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint)
                    tuint))
                (Stmt.Sset _t'6
                  (Expr.Ecast (Expr.Etempvar _t'6 tuint) tuint)))
              (Stmt.Sset _t'6 (Expr.Ecast (Expr.Etempvar _t'6 tuint) tuint)))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'6
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 3) tuint)
                    tuint))
                (Stmt.Sset _t'6
                  (Expr.Ecast (Expr.Etempvar _t'6 tuint) tuint)))
              (Stmt.Sset _t'6 (Expr.Ecast (Expr.Etempvar _t'6 tuint) tuint))))))
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _t'6 tuint)
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

def s_kprog_x86_ptr_load_17 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _dst tuchar)
                    (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
  (Stmt.Ssequence
    (Stmt.Sset _t'28
      (Expr.Efield (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
        _ptr (tptr tvoid)))
    (Stmt.Ssequence
      (Stmt.Sset _t'29
        (Expr.Efield
          (Expr.Ederef
            (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
            (Ty.Tstruct _x86_sim_state noattr)) _native_stack_base tulong))
      (Stmt.Sassign
        (Expr.Efield
          (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr)) _ptr
          (tptr tvoid))
        (Expr.Ecast
          (Expr.Ecast
            (Expr.Ebinop Binop.Osub
              (Expr.Ecast
                (Expr.Ecast (Expr.Etempvar _t'28 (tptr tvoid)) tlong) tulong)
              (Expr.Etempvar _t'29 tulong) tulong) tlong) (tptr tvoid)))))
  Stmt.Sskip)

def s_kprog_x86_ptr_load_18 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Ole
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Etempvar ___x86_release_i tuint)
                      (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint)
                    (Expr.Econst_int (Integers.Int.repr 64) tuint) tint)
  (Stmt.Sset _t'13
    (Expr.Ecast
      (Expr.Ebinop Binop.Oge (Expr.Etempvar ___x86_release_off tlong)
        (Expr.Etempvar ___x86_release_old tlong) tint) tbool))
  (Stmt.Sset _t'13 (Expr.Econst_int (Integers.Int.repr 0) tint)))

def s_kprog_x86_ptr_load_19 : Stmt :=
(Stmt.Sset _t'14
  (Expr.Ecast
    (Expr.Ebinop Binop.Ole
      (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_release_off tlong)
        (Expr.Econst_int (Integers.Int.repr 8) tint) tlong)
      (Expr.Etempvar ___x86_release_new tlong) tint) tbool))

def s_kprog_x86_ptr_load_20 : Stmt :=
(Stmt.Ssequence
  (Stmt.Scall (some _t'9)
    (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                         cc_default))
    [(Expr.Econst_int (Integers.Int.repr 6) tint)])
  (Stmt.Sassign
    (Expr.Ederef
      (Expr.Ebinop Binop.Oadd
        (Expr.Efield
          (Expr.Efield
            (Expr.Ederef
              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
              (Ty.Tstruct _x86_sim_state noattr)) _stack_mem
            (Ty.Tunion _x86_sim_stack_mem noattr)) _q (tarray tulong 8))
        (Expr.Ebinop Binop.Odiv (Expr.Etempvar ___x86_release_i tuint)
          (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint) (tptr tulong))
      tulong) (Expr.Etempvar _t'9 tulong)))

def s_kprog_x86_ptr_load_21 : Stmt :=
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
                                tuint)
                              (Expr.Econst_int (Integers.Int.repr 64) tuint)
                              tint)
            (Stmt.Sset _t'11
              (Expr.Ecast
                (Expr.Ebinop Binop.Oge
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Etempvar ___x86_release_off tlong)
                    (Expr.Etempvar ___x86_release_lane tuint) tlong)
                  (Expr.Etempvar ___x86_release_old tlong) tint) tbool))
            (Stmt.Sset _t'11 (Expr.Econst_int (Integers.Int.repr 0) tint)))
          (Stmt.Sifthenelse (Expr.Etempvar _t'11 tint)
            (Stmt.Sset _t'12
              (Expr.Ecast
                (Expr.Ebinop Binop.Olt
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Etempvar ___x86_release_off tlong)
                    (Expr.Etempvar ___x86_release_lane tuint) tlong)
                  (Expr.Etempvar ___x86_release_new tlong) tint) tbool))
            (Stmt.Sset _t'12 (Expr.Econst_int (Integers.Int.repr 0) tint))))
        (Stmt.Sifthenelse (Expr.Etempvar _t'12 tint)
          (Stmt.Ssequence
            (Stmt.Scall (some _t'10)
              (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint] tulong
                                                   cc_default))
              [(Expr.Econst_int (Integers.Int.repr 6) tint)])
            (Stmt.Sassign
              (Expr.Ederef
                (Expr.Ebinop Binop.Oadd
                  (Expr.Efield
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                        (Ty.Tstruct _x86_sim_state noattr)) _stack_mem
                      (Ty.Tunion _x86_sim_stack_mem noattr)) _b
                    (tarray tuchar 64))
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Etempvar ___x86_release_i tuint)
                    (Expr.Etempvar ___x86_release_lane tuint) tuint)
                  (tptr tuchar)) tuchar)
              (Expr.Ecast (Expr.Etempvar _t'10 tulong) tuchar)))
          Stmt.Sskip)))
    (Stmt.Sset ___x86_release_lane
      (Expr.Ebinop Binop.Oadd (Expr.Etempvar ___x86_release_lane tuint)
        (Expr.Econst_int (Integers.Int.repr 1) tint) tuint))))

def s_kprog_x86_ptr_load_22 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                    (Expr.Ebinop Binop.Osub
                      (Expr.Ecast
                        (Expr.Ebinop Binop.Omul
                          (Expr.Ecast (Expr.Etempvar ___x86_sv_i tuint)
                            tulong)
                          (Expr.Econst_int (Integers.Int.repr 8) tuint)
                          tulong) tlong)
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 64) tuint) tlong)
                      tlong) (Expr.Etempvar ___x86_sv_sp tlong) tint)
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd (Expr.Etempvar _value_tags (tptr tuchar))
            (Expr.Etempvar ___x86_sv_i tuint) (tptr tuchar)) tuchar)
        (Expr.Econst_int (Integers.Int.repr 0) tuint))
      (Stmt.Sassign
        (Expr.Ederef
          (Expr.Ebinop Binop.Oadd
            (Expr.Etempvar _value_ptrs (tptr (tptr tvoid)))
            (Expr.Etempvar ___x86_sv_i tuint) (tptr (tptr tvoid)))
          (tptr tvoid)) (Expr.Econst_int (Integers.Int.repr 0) tint)))
    Stmt.Sbreak)
  Stmt.Sskip)

def s_kprog_x86_ptr_load_23 : Stmt :=
Stmt.Sbreak

def s_kprog_x86_ptr_load_24 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_wr_next_ptr
    (Expr.Efield (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
      _ptr (tptr tvoid)))
  (Stmt.Ssequence
    (Stmt.Sset ___x86_wr_next_tag
      (Expr.Ecast (Expr.Etempvar ___x86_wr_cell_tag tuchar) tuchar))
    (Stmt.Ssequence
      (Stmt.Sswitch (Expr.Etempvar _dst tuchar)
        (LStmts.LScons (some 0)
          (Stmt.Ssequence
            (Stmt.Sassign
              (Expr.Efield
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                    (Ty.Tstruct _x86_sim_state noattr)) _rax
                  (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid))
              (Expr.Etempvar ___x86_wr_next_ptr (tptr tvoid)))
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                    (Ty.Tstruct _x86_sim_state noattr)) _rax_tag tuchar)
                (Expr.Etempvar ___x86_wr_next_tag tuchar))
              Stmt.Sbreak))
          (LStmts.LScons (some 1)
            (Stmt.Ssequence
              (Stmt.Sassign
                (Expr.Efield
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                      (Ty.Tstruct _x86_sim_state noattr)) _rcx
                    (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid))
                (Expr.Etempvar ___x86_wr_next_ptr (tptr tvoid)))
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                      (Ty.Tstruct _x86_sim_state noattr)) _rcx_tag tuchar)
                  (Expr.Etempvar ___x86_wr_next_tag tuchar))
                Stmt.Sbreak))
            (LStmts.LScons (some 2)
              (Stmt.Ssequence
                (Stmt.Sassign
                  (Expr.Efield
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                        (Ty.Tstruct _x86_sim_state noattr)) _rdx
                      (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid))
                  (Expr.Etempvar ___x86_wr_next_ptr (tptr tvoid)))
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                        (Ty.Tstruct _x86_sim_state noattr)) _rdx_tag tuchar)
                    (Expr.Etempvar ___x86_wr_next_tag tuchar))
                  Stmt.Sbreak))
              (LStmts.LScons (some 3)
                (Stmt.Ssequence
                  (Stmt.Sassign
                    (Expr.Efield
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                          (Ty.Tstruct _x86_sim_state noattr)) _rbx
                        (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid))
                    (Expr.Etempvar ___x86_wr_next_ptr (tptr tvoid)))
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                          (Ty.Tstruct _x86_sim_state noattr)) _rbx_tag
                        tuchar) (Expr.Etempvar ___x86_wr_next_tag tuchar))
                    Stmt.Sbreak))
                (LStmts.LScons (some 4)
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Efield
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                            (Ty.Tstruct _x86_sim_state noattr)) _rsp
                          (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid))
                      (Expr.Etempvar ___x86_wr_next_ptr (tptr tvoid)))
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                            (Ty.Tstruct _x86_sim_state noattr)) _rsp_tag
                          tuchar) (Expr.Etempvar ___x86_wr_next_tag tuchar))
                      Stmt.Sbreak))
                  (LStmts.LScons (some 5)
                    (Stmt.Ssequence
                      (Stmt.Sassign
                        (Expr.Efield
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                              (Ty.Tstruct _x86_sim_state noattr)) _rbp
                            (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                          (tptr tvoid))
                        (Expr.Etempvar ___x86_wr_next_ptr (tptr tvoid)))
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Ederef
                              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                              (Ty.Tstruct _x86_sim_state noattr)) _rbp_tag
                            tuchar)
                          (Expr.Etempvar ___x86_wr_next_tag tuchar))
                        Stmt.Sbreak))
                    (LStmts.LScons (some 6)
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                (Ty.Tstruct _x86_sim_state noattr)) _rsi
                              (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                            (tptr tvoid))
                          (Expr.Etempvar ___x86_wr_next_ptr (tptr tvoid)))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                (Ty.Tstruct _x86_sim_state noattr)) _rsi_tag
                              tuchar)
                            (Expr.Etempvar ___x86_wr_next_tag tuchar))
                          Stmt.Sbreak))
                      (LStmts.LScons (some 7)
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                  (Ty.Tstruct _x86_sim_state noattr)) _rdi
                                (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                              (tptr tvoid))
                            (Expr.Etempvar ___x86_wr_next_ptr (tptr tvoid)))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                  (Ty.Tstruct _x86_sim_state noattr))
                                _rdi_tag tuchar)
                              (Expr.Etempvar ___x86_wr_next_tag tuchar))
                            Stmt.Sbreak))
                        (LStmts.LScons (some 8)
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                    (Ty.Tstruct _x86_sim_state noattr)) _r8
                                  (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                                (tptr tvoid))
                              (Expr.Etempvar ___x86_wr_next_ptr (tptr tvoid)))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                    (Ty.Tstruct _x86_sim_state noattr))
                                  _r8_tag tuchar)
                                (Expr.Etempvar ___x86_wr_next_tag tuchar))
                              Stmt.Sbreak))
                          (LStmts.LScons (some 9)
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Efield
                                    (Expr.Ederef
                                      (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                      (Ty.Tstruct _x86_sim_state noattr)) _r9
                                    (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                                  (tptr tvoid))
                                (Expr.Etempvar ___x86_wr_next_ptr (tptr tvoid)))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Efield
                                    (Expr.Ederef
                                      (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                      (Ty.Tstruct _x86_sim_state noattr))
                                    _r9_tag tuchar)
                                  (Expr.Etempvar ___x86_wr_next_tag tuchar))
                                Stmt.Sbreak))
                            (LStmts.LScons (some 10)
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Efield
                                    (Expr.Efield
                                      (Expr.Ederef
                                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                        (Ty.Tstruct _x86_sim_state noattr))
                                      _r10 (Ty.Tunion _x86_sim_gpr noattr))
                                    _ptr (tptr tvoid))
                                  (Expr.Etempvar ___x86_wr_next_ptr (tptr tvoid)))
                                (Stmt.Ssequence
                                  (Stmt.Sassign
                                    (Expr.Efield
                                      (Expr.Ederef
                                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                        (Ty.Tstruct _x86_sim_state noattr))
                                      _r10_tag tuchar)
                                    (Expr.Etempvar ___x86_wr_next_tag tuchar))
                                  Stmt.Sbreak))
                              (LStmts.LScons (some 11)
                                (Stmt.Ssequence
                                  (Stmt.Sassign
                                    (Expr.Efield
                                      (Expr.Efield
                                        (Expr.Ederef
                                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                          (Ty.Tstruct _x86_sim_state noattr))
                                        _r11 (Ty.Tunion _x86_sim_gpr noattr))
                                      _ptr (tptr tvoid))
                                    (Expr.Etempvar ___x86_wr_next_ptr (tptr tvoid)))
                                  (Stmt.Ssequence
                                    (Stmt.Sassign
                                      (Expr.Efield
                                        (Expr.Ederef
                                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                          (Ty.Tstruct _x86_sim_state noattr))
                                        _r11_tag tuchar)
                                      (Expr.Etempvar ___x86_wr_next_tag tuchar))
                                    Stmt.Sbreak))
                                (LStmts.LScons (some 12)
                                  (Stmt.Ssequence
                                    (Stmt.Sassign
                                      (Expr.Efield
                                        (Expr.Efield
                                          (Expr.Ederef
                                            (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                            (Ty.Tstruct _x86_sim_state noattr))
                                          _r12
                                          (Ty.Tunion _x86_sim_gpr noattr))
                                        _ptr (tptr tvoid))
                                      (Expr.Etempvar ___x86_wr_next_ptr (tptr tvoid)))
                                    (Stmt.Ssequence
                                      (Stmt.Sassign
                                        (Expr.Efield
                                          (Expr.Ederef
                                            (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                            (Ty.Tstruct _x86_sim_state noattr))
                                          _r12_tag tuchar)
                                        (Expr.Etempvar ___x86_wr_next_tag tuchar))
                                      Stmt.Sbreak))
                                  (LStmts.LScons (some 13)
                                    (Stmt.Ssequence
                                      (Stmt.Sassign
                                        (Expr.Efield
                                          (Expr.Efield
                                            (Expr.Ederef
                                              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                              (Ty.Tstruct _x86_sim_state noattr))
                                            _r13
                                            (Ty.Tunion _x86_sim_gpr noattr))
                                          _ptr (tptr tvoid))
                                        (Expr.Etempvar ___x86_wr_next_ptr (tptr tvoid)))
                                      (Stmt.Ssequence
                                        (Stmt.Sassign
                                          (Expr.Efield
                                            (Expr.Ederef
                                              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                              (Ty.Tstruct _x86_sim_state noattr))
                                            _r13_tag tuchar)
                                          (Expr.Etempvar ___x86_wr_next_tag tuchar))
                                        Stmt.Sbreak))
                                    (LStmts.LScons (some 14)
                                      (Stmt.Ssequence
                                        (Stmt.Sassign
                                          (Expr.Efield
                                            (Expr.Efield
                                              (Expr.Ederef
                                                (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                                (Ty.Tstruct _x86_sim_state noattr))
                                              _r14
                                              (Ty.Tunion _x86_sim_gpr noattr))
                                            _ptr (tptr tvoid))
                                          (Expr.Etempvar ___x86_wr_next_ptr (tptr tvoid)))
                                        (Stmt.Ssequence
                                          (Stmt.Sassign
                                            (Expr.Efield
                                              (Expr.Ederef
                                                (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                                (Ty.Tstruct _x86_sim_state noattr))
                                              _r14_tag tuchar)
                                            (Expr.Etempvar ___x86_wr_next_tag tuchar))
                                          Stmt.Sbreak))
                                      (LStmts.LScons (some 15)
                                        (Stmt.Ssequence
                                          (Stmt.Sassign
                                            (Expr.Efield
                                              (Expr.Efield
                                                (Expr.Ederef
                                                  (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                                  (Ty.Tstruct _x86_sim_state noattr))
                                                _r15
                                                (Ty.Tunion _x86_sim_gpr noattr))
                                              _ptr (tptr tvoid))
                                            (Expr.Etempvar ___x86_wr_next_ptr (tptr tvoid)))
                                          (Stmt.Ssequence
                                            (Stmt.Sassign
                                              (Expr.Efield
                                                (Expr.Ederef
                                                  (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                                  (Ty.Tstruct _x86_sim_state noattr))
                                                _r15_tag tuchar)
                                              (Expr.Etempvar ___x86_wr_next_tag tuchar))
                                            Stmt.Sbreak))
                                        (LStmts.LScons none
                                          Stmt.Sbreak
                                          LStmts.LSnil))))))))))))))))))
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq (Expr.Etempvar _dst tuchar)
                          (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
        (Stmt.Sloop
          (Stmt.Ssequence
            (Stmt.Sset ___x86_release_old
              (Expr.Etempvar ___x86_write_old_sp tlong))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sset _t'27
                  (Expr.Efield
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                        (Ty.Tstruct _x86_sim_state noattr)) _rsp
                      (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
                (Stmt.Sset ___x86_release_new
                  (Expr.Ecast
                    (Expr.Ecast (Expr.Etempvar _t'27 (tptr tvoid)) tlong)
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
                                            (Expr.Econst_int (Integers.Int.repr 64) tuint)
                                            tint)
                          Stmt.Sskip
                          Stmt.Sbreak)
                        (Stmt.Ssequence
                          (Stmt.Sset ___x86_release_off
                            (Expr.Ebinop Binop.Osub
                              (Expr.Ecast
                                (Expr.Etempvar ___x86_release_i tuint) tlong)
                              (Expr.Ecast
                                (Expr.Econst_int (Integers.Int.repr 64) tuint)
                                tlong) tlong))
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              s_kprog_x86_ptr_load_18
                              (Stmt.Sifthenelse (Expr.Etempvar _t'13 tint)
                                s_kprog_x86_ptr_load_19
                                (Stmt.Sset _t'14
                                  (Expr.Econst_int (Integers.Int.repr 0) tint))))
                            (Stmt.Sifthenelse (Expr.Etempvar _t'14 tint)
                              s_kprog_x86_ptr_load_20
                              s_kprog_x86_ptr_load_21))))
                      (Stmt.Sset ___x86_release_i
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Etempvar ___x86_release_i tuint)
                          (Expr.Econst_int (Integers.Int.repr 8) tuint)
                          tuint))))
                  (Stmt.Sloop
                    (Stmt.Ssequence
                      (Stmt.Ssequence
                        (Stmt.Sset _t'26
                          (Expr.Efield
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                (Ty.Tstruct _x86_sim_state noattr)) _rsp
                              (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                            (tptr tvoid)))
                        (Stmt.Sset ___x86_sv_sp
                          (Expr.Ecast
                            (Expr.Ecast (Expr.Etempvar _t'26 (tptr tvoid))
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
                                                      (Expr.Econst_int (Integers.Int.repr 64) tuint)
                                                      tulong)
                                                    (Expr.Econst_int (Integers.Int.repr 7) tuint)
                                                    tulong)
                                                  (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                                  tulong) tint)
                              Stmt.Sskip
                              Stmt.Sbreak)
                            (Stmt.Sloop
                              s_kprog_x86_ptr_load_22
                              s_kprog_x86_ptr_load_23))
                          (Stmt.Sset ___x86_sv_i
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Etempvar ___x86_sv_i tuint)
                              (Expr.Econst_int (Integers.Int.repr 1) tint)
                              tuint)))))
                    Stmt.Sbreak))
                Stmt.Sskip)))
          Stmt.Sbreak)
        Stmt.Sskip))))

def s_kprog_x86_ptr_load_25 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset ___x86_release_i__1
      (Expr.Econst_int (Integers.Int.repr 0) tint))
    (Stmt.Sloop
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                            (Expr.Etempvar ___x86_release_i__1 tuint)
                            (Expr.Econst_int (Integers.Int.repr 64) tuint)
                            tint)
          Stmt.Sskip
          Stmt.Sbreak)
        (Stmt.Ssequence
          (Stmt.Sset ___x86_release_off__1
            (Expr.Ebinop Binop.Osub
              (Expr.Ecast (Expr.Etempvar ___x86_release_i__1 tuint) tlong)
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 64) tuint)
                tlong) tlong))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Ole
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Etempvar ___x86_release_i__1 tuint)
                                    (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                    tuint)
                                  (Expr.Econst_int (Integers.Int.repr 64) tuint)
                                  tint)
                (Stmt.Sset _t'20
                  (Expr.Ecast
                    (Expr.Ebinop Binop.Oge
                      (Expr.Etempvar ___x86_release_off__1 tlong)
                      (Expr.Etempvar ___x86_release_old__1 tlong) tint)
                    tbool))
                (Stmt.Sset _t'20
                  (Expr.Econst_int (Integers.Int.repr 0) tint)))
              (Stmt.Sifthenelse (Expr.Etempvar _t'20 tint)
                (Stmt.Sset _t'21
                  (Expr.Ecast
                    (Expr.Ebinop Binop.Ole
                      (Expr.Ebinop Binop.Oadd
                        (Expr.Etempvar ___x86_release_off__1 tlong)
                        (Expr.Econst_int (Integers.Int.repr 8) tint) tlong)
                      (Expr.Etempvar ___x86_release_new__1 tlong) tint)
                    tbool))
                (Stmt.Sset _t'21
                  (Expr.Econst_int (Integers.Int.repr 0) tint))))
            (Stmt.Sifthenelse (Expr.Etempvar _t'21 tint)
              (Stmt.Ssequence
                (Stmt.Scall (some _t'16)
                  (Expr.Evar _native_lab_entry_input (Ty.Tfunction [tuint]
                                                       tulong cc_default))
                  [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                (Stmt.Sassign
                  (Expr.Ederef
                    (Expr.Ebinop Binop.Oadd
                      (Expr.Efield
                        (Expr.Efield
                          (Expr.Ederef
                            (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                            (Ty.Tstruct _x86_sim_state noattr)) _stack_mem
                          (Ty.Tunion _x86_sim_stack_mem noattr)) _q
                        (tarray tulong 8))
                      (Expr.Ebinop Binop.Odiv
                        (Expr.Etempvar ___x86_release_i__1 tuint)
                        (Expr.Econst_int (Integers.Int.repr 8) tuint) tuint)
                      (tptr tulong)) tulong) (Expr.Etempvar _t'16 tulong)))
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
                                            (Expr.Econst_int (Integers.Int.repr 64) tuint)
                                            tint)
                          (Stmt.Sset _t'18
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Oge
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Etempvar ___x86_release_off__1 tlong)
                                  (Expr.Etempvar ___x86_release_lane__1 tuint)
                                  tlong)
                                (Expr.Etempvar ___x86_release_old__1 tlong)
                                tint) tbool))
                          (Stmt.Sset _t'18
                            (Expr.Econst_int (Integers.Int.repr 0) tint)))
                        (Stmt.Sifthenelse (Expr.Etempvar _t'18 tint)
                          (Stmt.Sset _t'19
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Olt
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Etempvar ___x86_release_off__1 tlong)
                                  (Expr.Etempvar ___x86_release_lane__1 tuint)
                                  tlong)
                                (Expr.Etempvar ___x86_release_new__1 tlong)
                                tint) tbool))
                          (Stmt.Sset _t'19
                            (Expr.Econst_int (Integers.Int.repr 0) tint))))
                      (Stmt.Sifthenelse (Expr.Etempvar _t'19 tint)
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'17)
                            (Expr.Evar _native_lab_entry_input (Ty.Tfunction
                                                                 [tuint]
                                                                 tulong
                                                                 cc_default))
                            [(Expr.Econst_int (Integers.Int.repr 6) tint)])
                          (Stmt.Sassign
                            (Expr.Ederef
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Efield
                                  (Expr.Efield
                                    (Expr.Ederef
                                      (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                      (Ty.Tstruct _x86_sim_state noattr))
                                    _stack_mem
                                    (Ty.Tunion _x86_sim_stack_mem noattr)) _b
                                  (tarray tuchar 64))
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Etempvar ___x86_release_i__1 tuint)
                                  (Expr.Etempvar ___x86_release_lane__1 tuint)
                                  tuint) (tptr tuchar)) tuchar)
                            (Expr.Ecast (Expr.Etempvar _t'17 tulong) tuchar)))
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
        (Stmt.Sset _t'22
          (Expr.Efield
            (Expr.Efield
              (Expr.Ederef
                (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                (Ty.Tstruct _x86_sim_state noattr)) _rsp
              (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
        (Stmt.Sset ___x86_sv_sp__1
          (Expr.Ecast (Expr.Ecast (Expr.Etempvar _t'22 (tptr tvoid)) tlong)
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
                                      (Expr.Econst_int (Integers.Int.repr 64) tuint)
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
                                    (Expr.Ecast
                                      (Expr.Econst_int (Integers.Int.repr 64) tuint)
                                      tlong) tlong)
                                  (Expr.Etempvar ___x86_sv_sp__1 tlong) tint)
                (Stmt.Sloop
                  (Stmt.Ssequence
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Etempvar _value_tags (tptr tuchar))
                          (Expr.Etempvar ___x86_sv_i__1 tuint) (tptr tuchar))
                        tuchar)
                      (Expr.Econst_int (Integers.Int.repr 0) tuint))
                    (Stmt.Sassign
                      (Expr.Ederef
                        (Expr.Ebinop Binop.Oadd
                          (Expr.Etempvar _value_ptrs (tptr (tptr tvoid)))
                          (Expr.Etempvar ___x86_sv_i__1 tuint)
                          (tptr (tptr tvoid))) (tptr tvoid))
                      (Expr.Econst_int (Integers.Int.repr 0) tint)))
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
  fn_params := [(_state, (tptr (Ty.Tstruct _x86_sim_state noattr))),
                (_value_tags, (tptr tuchar)),
                (_value_ptrs, (tptr (tptr tvoid))), (_op, tuchar),
                (_dst, tuchar), (_aux, tuint), (_imm, tulong)],
  fn_vars := [(___x86_wr_cell, (Ty.Tunion _x86_sim_gpr noattr)),
              (___kprog_x86_partial, (tvolatile (Ty.Tunion __3138 noattr))),
              (___kprog_x86_partial__1,
               (tvolatile (Ty.Tunion __3144 noattr)))],
  fn_temps := [(___x86_state, (tptr (Ty.Tstruct _x86_sim_state noattr))),
               (___x86_l_pw_tag, tuchar), (___kprog_x86_source_tag, tuchar),
               (___kprog_x86_pw_tag, tuchar), (___x86_write_old_sp, tlong),
               (___x86_wr_raw_width, tuchar), (___x86_wr_width, tuchar),
               (___x86_wr_shift, tuchar), (___x86_wr_next, tulong),
               (___x86_wr_cell_tag, tuchar), (___x86_l_tag, tuchar),
               (___x86_wr_stack_bits, tulong), (___x86_stack_delta, tulong),
               (___kprog_x86_lane, tuchar), (___kprog_x86_bits, tulong),
               (___x86_wr_stack_bits__1, tulong),
               (___x86_stack_delta__1, tulong),
               (___kprog_x86_lane__1, tushort),
               (___kprog_x86_bits__1, tulong),
               (___x86_wr_next_ptr, (tptr tvoid)),
               (___x86_wr_next_tag, tuchar), (___x86_release_old, tlong),
               (___x86_release_new, tlong), (___x86_release_i, tuint),
               (___x86_release_off, tlong), (___x86_release_lane, tuint),
               (___x86_sv_sp, tlong), (___x86_sv_i, tuint),
               (___x86_write_old_sp__1, tlong),
               (___x86_wr_next_ptr__1, (tptr tvoid)),
               (___x86_wr_next_tag__1, tuchar),
               (___x86_release_old__1, tlong),
               (___x86_release_new__1, tlong), (___x86_release_i__1, tuint),
               (___x86_release_off__1, tlong),
               (___x86_release_lane__1, tuint), (___x86_sv_sp__1, tlong),
               (___x86_sv_i__1, tuint), (_t'21, tint), (_t'20, tint),
               (_t'19, tint), (_t'18, tint), (_t'17, tulong),
               (_t'16, tulong), (_t'15, tulong), (_t'14, tint),
               (_t'13, tint), (_t'12, tint), (_t'11, tint), (_t'10, tulong),
               (_t'9, tulong), (_t'8, tuint), (_t'7, tuint), (_t'6, tuint),
               (_t'5, (tvolatile (tptr tvoid))),
               (_t'4, (tvolatile (tptr tvoid))), (_t'3, (tptr tvoid)),
               (_t'2, tuchar), (_t'1, tint), (_t'72, (tptr tvoid)),
               (_t'71, (tptr tvoid)), (_t'70, (tptr tvoid)),
               (_t'69, (tptr tvoid)), (_t'68, (tptr tvoid)),
               (_t'67, (tptr tvoid)), (_t'66, (tptr tvoid)),
               (_t'65, (tptr tvoid)), (_t'64, (tptr tvoid)),
               (_t'63, (tptr tvoid)), (_t'62, (tptr tvoid)),
               (_t'61, (tptr tvoid)), (_t'60, (tptr tvoid)),
               (_t'59, (tptr tvoid)), (_t'58, (tptr tvoid)),
               (_t'57, (tptr tvoid)), (_t'56, (tptr tvoid)), (_t'55, tuchar),
               (_t'54, tuchar), (_t'53, tuchar), (_t'52, tuchar),
               (_t'51, tuchar), (_t'50, tuchar), (_t'49, tuchar),
               (_t'48, tuchar), (_t'47, tuchar), (_t'46, tuchar),
               (_t'45, tuchar), (_t'44, tuchar), (_t'43, tuchar),
               (_t'42, tuchar), (_t'41, tuchar), (_t'40, tuchar),
               (_t'39, tulong), (_t'38, (tptr tvoid)), (_t'37, (tptr tvoid)),
               (_t'36, tulong), (_t'35, (tptr tvoid)), (_t'34, tulong),
               (_t'33, (tptr tvoid)), (_t'32, (tptr tvoid)), (_t'31, tulong),
               (_t'30, (tptr tvoid)), (_t'29, tulong), (_t'28, (tptr tvoid)),
               (_t'27, (tptr tvoid)), (_t'26, (tptr tvoid)),
               (_t'25, (tptr tvoid)), (_t'24, tulong), (_t'23, (tptr tvoid)),
               (_t'22, (tptr tvoid))],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_state
    (Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_state noattr))))
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
                (Stmt.Sset _t'72
                  (Expr.Efield
                    (Expr.Efield
                      (Expr.Ederef
                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                        (Ty.Tstruct _x86_sim_state noattr)) _rsp
                      (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
                (Stmt.Sset ___x86_write_old_sp
                  (Expr.Ecast
                    (Expr.Ecast (Expr.Etempvar _t'72 (tptr tvoid)) tlong)
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
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                              (Expr.Etempvar _dst tuchar)
                                              (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                              tint)
                            s_kprog_x86_ptr_load_0
                            s_kprog_x86_ptr_load_11)
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Evar ___x86_wr_cell (Ty.Tunion _x86_sim_gpr noattr))
                              _ptr (tptr tvoid))
                            (Expr.Etempvar _t'3 (tptr tvoid))))
                        (Stmt.Ssequence
                          (Stmt.Sloop
                            (Stmt.Ssequence
                              s_kprog_x86_ptr_load_12
                              s_kprog_x86_ptr_load_13)
                            Stmt.Sbreak)
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              s_kprog_x86_ptr_load_14
                              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                                  (Expr.Etempvar _t'8 tuint)
                                                  (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                                  tint)
                                s_kprog_x86_ptr_load_15
                                s_kprog_x86_ptr_load_16))
                            (Stmt.Ssequence
                              s_kprog_x86_ptr_load_17
                              s_kprog_x86_ptr_load_24)))))))))
            Stmt.Sbreak)
          Stmt.Sskip)
        (Stmt.Sloop
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Sset _t'25
                (Expr.Efield
                  (Expr.Efield
                    (Expr.Ederef
                      (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                      (Ty.Tstruct _x86_sim_state noattr)) _rsp
                    (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
              (Stmt.Sset ___x86_write_old_sp__1
                (Expr.Ecast
                  (Expr.Ecast (Expr.Etempvar _t'25 (tptr tvoid)) tlong)
                  tlong)))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Etempvar _dst tuchar)
                                    (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                    tint)
                  (Stmt.Ssequence
                    (Stmt.Sset _t'24
                      (Expr.Efield
                        (Expr.Ederef
                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                          (Ty.Tstruct _x86_sim_state noattr))
                        _native_stack_base tulong))
                    (Stmt.Sset _t'15
                      (Expr.Ecast (Expr.Etempvar _t'24 tulong) tulong)))
                  (Stmt.Sset _t'15
                    (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                      tulong)))
                (Stmt.Sset ___x86_wr_next_ptr__1
                  (Expr.Ecast
                    (Expr.Ecast
                      (Expr.Ecast
                        (Expr.Ebinop Binop.Osub
                          (Expr.Ecast (Expr.Etempvar _imm tulong) tulong)
                          (Expr.Etempvar _t'15 tulong) tulong) tlong)
                      (tptr tvoid)) (tptr tvoid))))
              (Stmt.Ssequence
                (Stmt.Sset ___x86_wr_next_tag__1
                  (Expr.Ecast (Expr.Etempvar ___x86_l_pw_tag tuchar) tuchar))
                (Stmt.Ssequence
                  (Stmt.Sswitch (Expr.Etempvar _dst tuchar)
                    (LStmts.LScons (some 0)
                      (Stmt.Ssequence
                        (Stmt.Sassign
                          (Expr.Efield
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                (Ty.Tstruct _x86_sim_state noattr)) _rax
                              (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                            (tptr tvoid))
                          (Expr.Etempvar ___x86_wr_next_ptr__1 (tptr tvoid)))
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Ederef
                                (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                (Ty.Tstruct _x86_sim_state noattr)) _rax_tag
                              tuchar)
                            (Expr.Etempvar ___x86_wr_next_tag__1 tuchar))
                          Stmt.Sbreak))
                      (LStmts.LScons (some 1)
                        (Stmt.Ssequence
                          (Stmt.Sassign
                            (Expr.Efield
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                  (Ty.Tstruct _x86_sim_state noattr)) _rcx
                                (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                              (tptr tvoid))
                            (Expr.Etempvar ___x86_wr_next_ptr__1 (tptr tvoid)))
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Ederef
                                  (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                  (Ty.Tstruct _x86_sim_state noattr))
                                _rcx_tag tuchar)
                              (Expr.Etempvar ___x86_wr_next_tag__1 tuchar))
                            Stmt.Sbreak))
                        (LStmts.LScons (some 2)
                          (Stmt.Ssequence
                            (Stmt.Sassign
                              (Expr.Efield
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                    (Ty.Tstruct _x86_sim_state noattr)) _rdx
                                  (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                                (tptr tvoid))
                              (Expr.Etempvar ___x86_wr_next_ptr__1 (tptr tvoid)))
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                    (Ty.Tstruct _x86_sim_state noattr))
                                  _rdx_tag tuchar)
                                (Expr.Etempvar ___x86_wr_next_tag__1 tuchar))
                              Stmt.Sbreak))
                          (LStmts.LScons (some 3)
                            (Stmt.Ssequence
                              (Stmt.Sassign
                                (Expr.Efield
                                  (Expr.Efield
                                    (Expr.Ederef
                                      (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                      (Ty.Tstruct _x86_sim_state noattr))
                                    _rbx (Ty.Tunion _x86_sim_gpr noattr))
                                  _ptr (tptr tvoid))
                                (Expr.Etempvar ___x86_wr_next_ptr__1 (tptr tvoid)))
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Efield
                                    (Expr.Ederef
                                      (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                      (Ty.Tstruct _x86_sim_state noattr))
                                    _rbx_tag tuchar)
                                  (Expr.Etempvar ___x86_wr_next_tag__1 tuchar))
                                Stmt.Sbreak))
                            (LStmts.LScons (some 4)
                              (Stmt.Ssequence
                                (Stmt.Sassign
                                  (Expr.Efield
                                    (Expr.Efield
                                      (Expr.Ederef
                                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                        (Ty.Tstruct _x86_sim_state noattr))
                                      _rsp (Ty.Tunion _x86_sim_gpr noattr))
                                    _ptr (tptr tvoid))
                                  (Expr.Etempvar ___x86_wr_next_ptr__1 (tptr tvoid)))
                                (Stmt.Ssequence
                                  (Stmt.Sassign
                                    (Expr.Efield
                                      (Expr.Ederef
                                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                        (Ty.Tstruct _x86_sim_state noattr))
                                      _rsp_tag tuchar)
                                    (Expr.Etempvar ___x86_wr_next_tag__1 tuchar))
                                  Stmt.Sbreak))
                              (LStmts.LScons (some 5)
                                (Stmt.Ssequence
                                  (Stmt.Sassign
                                    (Expr.Efield
                                      (Expr.Efield
                                        (Expr.Ederef
                                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                          (Ty.Tstruct _x86_sim_state noattr))
                                        _rbp (Ty.Tunion _x86_sim_gpr noattr))
                                      _ptr (tptr tvoid))
                                    (Expr.Etempvar ___x86_wr_next_ptr__1 (tptr tvoid)))
                                  (Stmt.Ssequence
                                    (Stmt.Sassign
                                      (Expr.Efield
                                        (Expr.Ederef
                                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                          (Ty.Tstruct _x86_sim_state noattr))
                                        _rbp_tag tuchar)
                                      (Expr.Etempvar ___x86_wr_next_tag__1 tuchar))
                                    Stmt.Sbreak))
                                (LStmts.LScons (some 6)
                                  (Stmt.Ssequence
                                    (Stmt.Sassign
                                      (Expr.Efield
                                        (Expr.Efield
                                          (Expr.Ederef
                                            (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                            (Ty.Tstruct _x86_sim_state noattr))
                                          _rsi
                                          (Ty.Tunion _x86_sim_gpr noattr))
                                        _ptr (tptr tvoid))
                                      (Expr.Etempvar ___x86_wr_next_ptr__1 (tptr tvoid)))
                                    (Stmt.Ssequence
                                      (Stmt.Sassign
                                        (Expr.Efield
                                          (Expr.Ederef
                                            (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                            (Ty.Tstruct _x86_sim_state noattr))
                                          _rsi_tag tuchar)
                                        (Expr.Etempvar ___x86_wr_next_tag__1 tuchar))
                                      Stmt.Sbreak))
                                  (LStmts.LScons (some 7)
                                    (Stmt.Ssequence
                                      (Stmt.Sassign
                                        (Expr.Efield
                                          (Expr.Efield
                                            (Expr.Ederef
                                              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                              (Ty.Tstruct _x86_sim_state noattr))
                                            _rdi
                                            (Ty.Tunion _x86_sim_gpr noattr))
                                          _ptr (tptr tvoid))
                                        (Expr.Etempvar ___x86_wr_next_ptr__1 (tptr tvoid)))
                                      (Stmt.Ssequence
                                        (Stmt.Sassign
                                          (Expr.Efield
                                            (Expr.Ederef
                                              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                              (Ty.Tstruct _x86_sim_state noattr))
                                            _rdi_tag tuchar)
                                          (Expr.Etempvar ___x86_wr_next_tag__1 tuchar))
                                        Stmt.Sbreak))
                                    (LStmts.LScons (some 8)
                                      (Stmt.Ssequence
                                        (Stmt.Sassign
                                          (Expr.Efield
                                            (Expr.Efield
                                              (Expr.Ederef
                                                (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                                (Ty.Tstruct _x86_sim_state noattr))
                                              _r8
                                              (Ty.Tunion _x86_sim_gpr noattr))
                                            _ptr (tptr tvoid))
                                          (Expr.Etempvar ___x86_wr_next_ptr__1 (tptr tvoid)))
                                        (Stmt.Ssequence
                                          (Stmt.Sassign
                                            (Expr.Efield
                                              (Expr.Ederef
                                                (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                                (Ty.Tstruct _x86_sim_state noattr))
                                              _r8_tag tuchar)
                                            (Expr.Etempvar ___x86_wr_next_tag__1 tuchar))
                                          Stmt.Sbreak))
                                      (LStmts.LScons (some 9)
                                        (Stmt.Ssequence
                                          (Stmt.Sassign
                                            (Expr.Efield
                                              (Expr.Efield
                                                (Expr.Ederef
                                                  (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                                  (Ty.Tstruct _x86_sim_state noattr))
                                                _r9
                                                (Ty.Tunion _x86_sim_gpr noattr))
                                              _ptr (tptr tvoid))
                                            (Expr.Etempvar ___x86_wr_next_ptr__1 (tptr tvoid)))
                                          (Stmt.Ssequence
                                            (Stmt.Sassign
                                              (Expr.Efield
                                                (Expr.Ederef
                                                  (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                                  (Ty.Tstruct _x86_sim_state noattr))
                                                _r9_tag tuchar)
                                              (Expr.Etempvar ___x86_wr_next_tag__1 tuchar))
                                            Stmt.Sbreak))
                                        (LStmts.LScons (some 10)
                                          (Stmt.Ssequence
                                            (Stmt.Sassign
                                              (Expr.Efield
                                                (Expr.Efield
                                                  (Expr.Ederef
                                                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                                    (Ty.Tstruct _x86_sim_state noattr))
                                                  _r10
                                                  (Ty.Tunion _x86_sim_gpr noattr))
                                                _ptr (tptr tvoid))
                                              (Expr.Etempvar ___x86_wr_next_ptr__1 (tptr tvoid)))
                                            (Stmt.Ssequence
                                              (Stmt.Sassign
                                                (Expr.Efield
                                                  (Expr.Ederef
                                                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                                    (Ty.Tstruct _x86_sim_state noattr))
                                                  _r10_tag tuchar)
                                                (Expr.Etempvar ___x86_wr_next_tag__1 tuchar))
                                              Stmt.Sbreak))
                                          (LStmts.LScons (some 11)
                                            (Stmt.Ssequence
                                              (Stmt.Sassign
                                                (Expr.Efield
                                                  (Expr.Efield
                                                    (Expr.Ederef
                                                      (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                                      (Ty.Tstruct _x86_sim_state noattr))
                                                    _r11
                                                    (Ty.Tunion _x86_sim_gpr noattr))
                                                  _ptr (tptr tvoid))
                                                (Expr.Etempvar ___x86_wr_next_ptr__1 (tptr tvoid)))
                                              (Stmt.Ssequence
                                                (Stmt.Sassign
                                                  (Expr.Efield
                                                    (Expr.Ederef
                                                      (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                                      (Ty.Tstruct _x86_sim_state noattr))
                                                    _r11_tag tuchar)
                                                  (Expr.Etempvar ___x86_wr_next_tag__1 tuchar))
                                                Stmt.Sbreak))
                                            (LStmts.LScons (some 12)
                                              (Stmt.Ssequence
                                                (Stmt.Sassign
                                                  (Expr.Efield
                                                    (Expr.Efield
                                                      (Expr.Ederef
                                                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                                        (Ty.Tstruct _x86_sim_state noattr))
                                                      _r12
                                                      (Ty.Tunion _x86_sim_gpr noattr))
                                                    _ptr (tptr tvoid))
                                                  (Expr.Etempvar ___x86_wr_next_ptr__1 (tptr tvoid)))
                                                (Stmt.Ssequence
                                                  (Stmt.Sassign
                                                    (Expr.Efield
                                                      (Expr.Ederef
                                                        (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                                        (Ty.Tstruct _x86_sim_state noattr))
                                                      _r12_tag tuchar)
                                                    (Expr.Etempvar ___x86_wr_next_tag__1 tuchar))
                                                  Stmt.Sbreak))
                                              (LStmts.LScons (some 13)
                                                (Stmt.Ssequence
                                                  (Stmt.Sassign
                                                    (Expr.Efield
                                                      (Expr.Efield
                                                        (Expr.Ederef
                                                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                                          (Ty.Tstruct _x86_sim_state noattr))
                                                        _r13
                                                        (Ty.Tunion _x86_sim_gpr noattr))
                                                      _ptr (tptr tvoid))
                                                    (Expr.Etempvar ___x86_wr_next_ptr__1 (tptr tvoid)))
                                                  (Stmt.Ssequence
                                                    (Stmt.Sassign
                                                      (Expr.Efield
                                                        (Expr.Ederef
                                                          (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                                          (Ty.Tstruct _x86_sim_state noattr))
                                                        _r13_tag tuchar)
                                                      (Expr.Etempvar ___x86_wr_next_tag__1 tuchar))
                                                    Stmt.Sbreak))
                                                (LStmts.LScons (some 14)
                                                  (Stmt.Ssequence
                                                    (Stmt.Sassign
                                                      (Expr.Efield
                                                        (Expr.Efield
                                                          (Expr.Ederef
                                                            (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                                            (Ty.Tstruct _x86_sim_state noattr))
                                                          _r14
                                                          (Ty.Tunion _x86_sim_gpr noattr))
                                                        _ptr (tptr tvoid))
                                                      (Expr.Etempvar ___x86_wr_next_ptr__1 (tptr tvoid)))
                                                    (Stmt.Ssequence
                                                      (Stmt.Sassign
                                                        (Expr.Efield
                                                          (Expr.Ederef
                                                            (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                                            (Ty.Tstruct _x86_sim_state noattr))
                                                          _r14_tag tuchar)
                                                        (Expr.Etempvar ___x86_wr_next_tag__1 tuchar))
                                                      Stmt.Sbreak))
                                                  (LStmts.LScons (some 15)
                                                    (Stmt.Ssequence
                                                      (Stmt.Sassign
                                                        (Expr.Efield
                                                          (Expr.Efield
                                                            (Expr.Ederef
                                                              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                                              (Ty.Tstruct _x86_sim_state noattr))
                                                            _r15
                                                            (Ty.Tunion _x86_sim_gpr noattr))
                                                          _ptr (tptr tvoid))
                                                        (Expr.Etempvar ___x86_wr_next_ptr__1 (tptr tvoid)))
                                                      (Stmt.Ssequence
                                                        (Stmt.Sassign
                                                          (Expr.Efield
                                                            (Expr.Ederef
                                                              (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                                              (Ty.Tstruct _x86_sim_state noattr))
                                                            _r15_tag tuchar)
                                                          (Expr.Etempvar ___x86_wr_next_tag__1 tuchar))
                                                        Stmt.Sbreak))
                                                    (LStmts.LScons none
                                                      Stmt.Sbreak
                                                      LStmts.LSnil))))))))))))))))))
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
                            (Stmt.Sset _t'23
                              (Expr.Efield
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_state noattr)))
                                    (Ty.Tstruct _x86_sim_state noattr)) _rsp
                                  (Ty.Tunion _x86_sim_gpr noattr)) _ptr
                                (tptr tvoid)))
                            (Stmt.Sset ___x86_release_new__1
                              (Expr.Ecast
                                (Expr.Ecast
                                  (Expr.Etempvar _t'23 (tptr tvoid)) tlong)
                                tlong)))
                          (Stmt.Sifthenelse (Expr.Ebinop Binop.Ogt
                                              (Expr.Etempvar ___x86_release_new__1 tlong)
                                              (Expr.Etempvar ___x86_release_old__1 tlong)
                                              tint)
                            s_kprog_x86_ptr_load_25
                            Stmt.Sskip)))
                      Stmt.Sbreak)
                    Stmt.Sskip)))))
          Stmt.Sbreak)))
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
 (CompositeDef.Composite _x86_sim_stack_mem SU.Union
   [(Member.Member_plain _b (tarray tuchar 64)),
    (Member.Member_plain _w (tarray tushort 32)),
    (Member.Member_plain _d (tarray tuint 16)),
    (Member.Member_plain _q (tarray tulong 8))]
   noattr),
 (CompositeDef.Composite _x86_sim_state SU.Struct
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
    (Member.Member_plain _r15_tag tuchar),
    (Member.Member_plain _native_stack_base tulong),
    (Member.Member_plain _cf tuchar), (Member.Member_plain _zf tuchar),
    (Member.Member_plain _sf tuchar), (Member.Member_plain _of tuchar),
    (Member.Member_plain _pf tuchar), (Member.Member_plain _af tuchar),
    (Member.Member_plain _xmm0_lo tulong),
    (Member.Member_plain _xmm0_hi tulong),
    (Member.Member_plain _ret_addr tulong),
    (Member.Member_plain _call_depth tuint),
    (Member.Member_plain _stack_mem (Ty.Tunion _x86_sim_stack_mem noattr)),
    (Member.Member_plain _xdp_abi (Ty.Tstruct _x86_sim_xdp_abi noattr)),
    (Member.Member_plain _skb_abi (Ty.Tstruct _x86_sim_skb_abi noattr)),
    (Member.Member_plain _skb_ctx (tptr (Ty.Tstruct ___sk_buff noattr))),
    (Member.Member_plain _helper_ctx (tptr tvoid)),
    (Member.Member_plain _is_xdp tuchar),
    (Member.Member_plain _helper_abi_base (tptr tvoid)),
    (Member.Member_plain _abi_kind tuchar)]
   noattr),
 (CompositeDef.Composite __3138 SU.Union
   [(Member.Member_plain _ptr (tptr tvoid)),
    (Member.Member_plain _w tushort),
    (Member.Member_plain _b (tarray tuchar 8))]
   noattr),
 (CompositeDef.Composite __3144 SU.Union
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
 (_x86_width_effective, GlobDef.Gfun (FunDef.Internal f_x86_width_effective)),
 (_native_lab_entry_input,
   GlobDef.Gfun (FunDef.External (ExtFun.EF_external "native_lab_entry_input"
                                   (mksignature [XType.Xint] XType.Xlong
                                     cc_default)) [tuint] tulong cc_default)),
 (_kprog_x86_ptr_load, GlobDef.Gfun (FunDef.Internal f_kprog_x86_ptr_load))]

def public_idents : List Ident :=
[_kprog_x86_ptr_load, _native_lab_entry_input, ___builtin_debug,
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

end X86Pointer

