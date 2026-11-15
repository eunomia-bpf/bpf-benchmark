import Clightdefs
open CC

namespace X86Context

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
  def source_file : String := "c/X86Context.c"
  def normalized : Bool := true
end Info

def __150 : Ident := identOfString "_150"
def __151 : Ident := identOfString "_151"
def __3115 : Ident := identOfString "_3115"
def __3116 : Ident := identOfString "_3116"
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
def ___kprog_abi_kind : Ident := identOfString "__kprog_abi_kind"
def ___kprog_abi_offset : Ident := identOfString "__kprog_abi_offset"
def ___kprog_abi_tag : Ident := identOfString "__kprog_abi_tag"
def ___kprog_padding_flow_keys : Ident := identOfString "__kprog_padding_flow_keys"
def ___kprog_padding_sk : Ident := identOfString "__kprog_padding_sk"
def ___kprog_reserved : Ident := identOfString "__kprog_reserved"
def ___sk_buff : Ident := identOfString "__sk_buff"
def ___x86_captured_xdp_value : Ident := identOfString "__x86_captured_xdp_value"
def ___x86_cbr_addr : Ident := identOfString "__x86_cbr_addr"
def ___x86_cbr_value : Ident := identOfString "__x86_cbr_value"
def ___x86_sr_ctx : Ident := identOfString "__x86_sr_ctx"
def ___x86_sr_lane : Ident := identOfString "__x86_sr_lane"
def ___x86_sr_off : Ident := identOfString "__x86_sr_off"
def ___x86_sr_value : Ident := identOfString "__x86_sr_value"
def ___x86_sr_width : Ident := identOfString "__x86_sr_width"
def ___x86_state : Ident := identOfString "__x86_state"
def ___x86_xdp_ctx : Ident := identOfString "__x86_xdp_ctx"
def ___x86_xdp_off : Ident := identOfString "__x86_xdp_off"
def _abi_kind : Ident := identOfString "abi_kind"
def _address : Ident := identOfString "address"
def _af : Ident := identOfString "af"
def _b : Ident := identOfString "b"
def _base : Ident := identOfString "base"
def _bpf_flow_keys : Ident := identOfString "bpf_flow_keys"
def _bpf_sock : Ident := identOfString "bpf_sock"
def _call_depth : Ident := identOfString "call_depth"
def _cb : Ident := identOfString "cb"
def _cf : Ident := identOfString "cf"
def _context : Ident := identOfString "context"
def _data : Ident := identOfString "data"
def _data_end : Ident := identOfString "data_end"
def _data_meta : Ident := identOfString "data_meta"
def _egress_ifindex : Ident := identOfString "egress_ifindex"
def _family : Ident := identOfString "family"
def _flow_keys : Ident := identOfString "flow_keys"
def _gpr_cells : Ident := identOfString "gpr_cells"
def _gso_segs : Ident := identOfString "gso_segs"
def _gso_size : Ident := identOfString "gso_size"
def _hash : Ident := identOfString "hash"
def _helper_abi_base : Ident := identOfString "helper_abi_base"
def _helper_ctx : Ident := identOfString "helper_ctx"
def _hwtstamp : Ident := identOfString "hwtstamp"
def _ifindex : Ident := identOfString "ifindex"
def _ingress_ifindex : Ident := identOfString "ingress_ifindex"
def _is_xdp : Ident := identOfString "is_xdp"
def _kind : Ident := identOfString "kind"
def _kprog_c_context_pointer : Ident := identOfString "kprog_c_context_pointer"
def _kprog_c_pointer_bits : Ident := identOfString "kprog_c_pointer_bits"
def _kprog_c_trap : Ident := identOfString "kprog_c_trap"
def _kprog_x86_cb_read : Ident := identOfString "kprog_x86_cb_read"
def _kprog_x86_context_tag : Ident := identOfString "kprog_x86_context_tag"
def _kprog_x86_mem_load : Ident := identOfString "kprog_x86_mem_load"
def _kprog_x86_skb_read : Ident := identOfString "kprog_x86_skb_read"
def _kprog_x86_xdp_read : Ident := identOfString "kprog_x86_xdp_read"
def _len : Ident := identOfString "len"
def _local_ip4 : Ident := identOfString "local_ip4"
def _local_ip6 : Ident := identOfString "local_ip6"
def _local_port : Ident := identOfString "local_port"
def _main : Ident := identOfString "main"
def _mark : Ident := identOfString "mark"
def _napi_id : Ident := identOfString "napi_id"
def _native_stack_base : Ident := identOfString "native_stack_base"
def _observed : Ident := identOfString "observed"
def _observed__1 : Ident := identOfString "observed__1"
def _observed__2 : Ident := identOfString "observed__2"
def _observed__3 : Ident := identOfString "observed__3"
def _of : Ident := identOfString "of"
def _offset : Ident := identOfString "offset"
def _pad0 : Ident := identOfString "pad0"
def _pad1 : Ident := identOfString "pad1"
def _pad2 : Ident := identOfString "pad2"
def _pf : Ident := identOfString "pf"
def _pkt_type : Ident := identOfString "pkt_type"
def _priority : Ident := identOfString "priority"
def _protocol : Ident := identOfString "protocol"
def _ptr : Ident := identOfString "ptr"
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
def _result : Ident := identOfString "result"
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
def _x86_apply_width : Ident := identOfString "x86_apply_width"
def _x86_sim_gpr : Ident := identOfString "x86_sim_gpr"
def _x86_sim_gpr_cell : Ident := identOfString "x86_sim_gpr_cell"
def _x86_sim_register_state : Ident := identOfString "x86_sim_register_state"
def _x86_sim_skb_abi : Ident := identOfString "x86_sim_skb_abi"
def _x86_sim_xdp_abi : Ident := identOfString "x86_sim_xdp_abi"
def _xdp_abi : Ident := identOfString "xdp_abi"
def _xdp_md : Ident := identOfString "xdp_md"
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
def _t'4 : Ident := (Positive.ofNat 131)
def _t'5 : Ident := (Positive.ofNat 132)
def _t'6 : Ident := (Positive.ofNat 133)
def _t'7 : Ident := (Positive.ofNat 134)
def _t'8 : Ident := (Positive.ofNat 135)
def _t'9 : Ident := (Positive.ofNat 136)

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

def s_kprog_x86_skb_read_0 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sbuiltin (some _t'7) (ExtFun.EF_vload Chunk.Mint8unsigned)
    [(tptr (tvolatile tuchar))]
    [(Expr.Eaddrof
       (Expr.Ederef
         (Expr.Ebinop Binop.Oadd
           (Expr.Etempvar ___x86_cbr_addr (tptr (tvolatile tuchar)))
           (Expr.Econst_int (Integers.Int.repr 1) tint)
           (tptr (tvolatile tuchar))) (tvolatile tuchar))
       (tptr (tvolatile tuchar)))])
  (Stmt.Sset ___x86_cbr_value
    (Expr.Ebinop Binop.Oor (Expr.Etempvar ___x86_cbr_value tulong)
      (Expr.Ebinop Binop.Oshl
        (Expr.Ecast (Expr.Etempvar _t'7 (tvolatile tuchar)) tulong)
        (Expr.Econst_int (Integers.Int.repr 8) tint) tulong) tulong)))

def s_kprog_x86_skb_read_1 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oge (Expr.Etempvar _width tulong)
                    (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
  (Stmt.Ssequence
    (Stmt.Sbuiltin (some _t'8) (ExtFun.EF_vload Chunk.Mint8unsigned)
      [(tptr (tvolatile tuchar))]
      [(Expr.Eaddrof
         (Expr.Ederef
           (Expr.Ebinop Binop.Oadd
             (Expr.Etempvar ___x86_cbr_addr (tptr (tvolatile tuchar)))
             (Expr.Econst_int (Integers.Int.repr 2) tint)
             (tptr (tvolatile tuchar))) (tvolatile tuchar))
         (tptr (tvolatile tuchar)))])
    (Stmt.Sset ___x86_cbr_value
      (Expr.Ebinop Binop.Oor (Expr.Etempvar ___x86_cbr_value tulong)
        (Expr.Ebinop Binop.Oshl
          (Expr.Ecast (Expr.Etempvar _t'8 (tvolatile tuchar)) tulong)
          (Expr.Econst_int (Integers.Int.repr 16) tint) tulong) tulong)))
  Stmt.Sskip)

def s_kprog_x86_skb_read_2 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge (Expr.Etempvar _width tulong)
                      (Expr.Econst_int (Integers.Int.repr 4) tuint) tint)
    (Stmt.Ssequence
      (Stmt.Sbuiltin (some _t'9) (ExtFun.EF_vload Chunk.Mint8unsigned)
        [(tptr (tvolatile tuchar))]
        [(Expr.Eaddrof
           (Expr.Ederef
             (Expr.Ebinop Binop.Oadd
               (Expr.Etempvar ___x86_cbr_addr (tptr (tvolatile tuchar)))
               (Expr.Econst_int (Integers.Int.repr 3) tint)
               (tptr (tvolatile tuchar))) (tvolatile tuchar))
           (tptr (tvolatile tuchar)))])
      (Stmt.Sset ___x86_cbr_value
        (Expr.Ebinop Binop.Oor (Expr.Etempvar ___x86_cbr_value tulong)
          (Expr.Ebinop Binop.Oshl
            (Expr.Ecast (Expr.Etempvar _t'9 (tvolatile tuchar)) tulong)
            (Expr.Econst_int (Integers.Int.repr 24) tint) tulong) tulong)))
    Stmt.Sskip)
  (Stmt.Ssequence
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge (Expr.Etempvar _width tulong)
                        (Expr.Econst_int (Integers.Int.repr 8) tuint) tint)
      (Stmt.Ssequence
        (Stmt.Sbuiltin (some _t'10) (ExtFun.EF_vload Chunk.Mint8unsigned)
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
              (Expr.Ecast (Expr.Etempvar _t'10 (tvolatile tuchar)) tulong)
              (Expr.Econst_int (Integers.Int.repr 32) tint) tulong) tulong)))
      Stmt.Sskip)
    (Stmt.Ssequence
      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge (Expr.Etempvar _width tulong)
                          (Expr.Econst_int (Integers.Int.repr 8) tuint) tint)
        (Stmt.Ssequence
          (Stmt.Sbuiltin (some _t'11) (ExtFun.EF_vload Chunk.Mint8unsigned)
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
                (Expr.Ecast (Expr.Etempvar _t'11 (tvolatile tuchar)) tulong)
                (Expr.Econst_int (Integers.Int.repr 40) tint) tulong) tulong)))
        Stmt.Sskip)
      (Stmt.Ssequence
        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                            (Expr.Etempvar _width tulong)
                            (Expr.Econst_int (Integers.Int.repr 8) tuint)
                            tint)
          (Stmt.Ssequence
            (Stmt.Sbuiltin (some _t'12) (ExtFun.EF_vload Chunk.Mint8unsigned)
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
                  (Expr.Ecast (Expr.Etempvar _t'12 (tvolatile tuchar))
                    tulong) (Expr.Econst_int (Integers.Int.repr 48) tint)
                  tulong) tulong)))
          Stmt.Sskip)
        (Stmt.Ssequence
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                              (Expr.Etempvar _width tulong)
                              (Expr.Econst_int (Integers.Int.repr 8) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Sbuiltin (some _t'13)
                (ExtFun.EF_vload Chunk.Mint8unsigned)
                [(tptr (tvolatile tuchar))]
                [(Expr.Eaddrof
                   (Expr.Ederef
                     (Expr.Ebinop Binop.Oadd
                       (Expr.Etempvar ___x86_cbr_addr (tptr (tvolatile tuchar)))
                       (Expr.Econst_int (Integers.Int.repr 7) tint)
                       (tptr (tvolatile tuchar))) (tvolatile tuchar))
                   (tptr (tvolatile tuchar)))])
              (Stmt.Sset ___x86_cbr_value
                (Expr.Ebinop Binop.Oor
                  (Expr.Etempvar ___x86_cbr_value tulong)
                  (Expr.Ebinop Binop.Oshl
                    (Expr.Ecast (Expr.Etempvar _t'13 (tvolatile tuchar))
                      tulong) (Expr.Econst_int (Integers.Int.repr 56) tint)
                    tulong) tulong)))
            Stmt.Sskip)
          (Stmt.Sset ___x86_sr_value (Expr.Etempvar ___x86_cbr_value tulong)))))))

def s_kprog_x86_skb_read_3 : Stmt :=
(Stmt.Sset _t'20
  (Expr.Ecast
    (Expr.Ebinop Binop.Ole (Expr.Etempvar ___x86_sr_off tlong)
      (Expr.Ebinop Binop.Osub
        (Expr.Ebinop Binop.Oadd
          (Expr.Econst_int (Integers.Int.repr 144) tint)
          (Expr.Econst_int (Integers.Int.repr 4) tint) tint)
        (Expr.Etempvar ___x86_sr_width tuchar) tint) tint) tbool))

def s_kprog_x86_skb_read_4 : Stmt :=
(Stmt.Ssequence
  (Stmt.Sset _t'27
    (Expr.Efield
      (Expr.Ederef
        (Expr.Etempvar ___x86_sr_ctx (tptr (Ty.Tstruct ___sk_buff noattr)))
        (Ty.Tstruct ___sk_buff noattr)) _priority tuint))
  (Stmt.Scall (some _t'15)
    (Expr.Evar _x86_apply_width (Ty.Tfunction [tulong, tuchar] tulong
                                  cc_default))
    [(Expr.Ebinop Binop.Oshr (Expr.Ecast (Expr.Etempvar _t'27 tuint) tulong)
       (Expr.Ebinop Binop.Omul
         (Expr.Ebinop Binop.Osub (Expr.Etempvar ___x86_sr_off tlong)
           (Expr.Econst_int (Integers.Int.repr 144) tint) tlong)
         (Expr.Econst_int (Integers.Int.repr 8) tint) tlong) tulong),
     (Expr.Etempvar ___x86_sr_width tuchar)]))

def s_kprog_x86_skb_read_5 : Stmt :=
(Stmt.Sifthenelse (Expr.Ebinop Binop.Oge (Expr.Etempvar ___x86_sr_off tlong)
                    (Expr.Econst_int (Integers.Int.repr 168) tint) tint)
  (Stmt.Sset _t'19
    (Expr.Ecast
      (Expr.Ebinop Binop.Ole (Expr.Etempvar ___x86_sr_off tlong)
        (Expr.Ebinop Binop.Osub
          (Expr.Ebinop Binop.Oadd
            (Expr.Econst_int (Integers.Int.repr 168) tint)
            (Expr.Econst_int (Integers.Int.repr 4) tint) tint)
          (Expr.Etempvar ___x86_sr_width tuchar) tint) tint) tbool))
  (Stmt.Sset _t'19 (Expr.Econst_int (Integers.Int.repr 0) tint)))

def s_kprog_x86_skb_read_6 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sset _t'26
      (Expr.Efield
        (Expr.Ederef
          (Expr.Etempvar ___x86_sr_ctx (tptr (Ty.Tstruct ___sk_buff noattr)))
          (Ty.Tstruct ___sk_buff noattr)) _mark tuint))
    (Stmt.Scall (some _t'16)
      (Expr.Evar _x86_apply_width (Ty.Tfunction [tulong, tuchar] tulong
                                    cc_default))
      [(Expr.Ebinop Binop.Oshr
         (Expr.Ecast (Expr.Etempvar _t'26 tuint) tulong)
         (Expr.Ebinop Binop.Omul
           (Expr.Ebinop Binop.Osub (Expr.Etempvar ___x86_sr_off tlong)
             (Expr.Econst_int (Integers.Int.repr 168) tint) tlong)
           (Expr.Econst_int (Integers.Int.repr 8) tint) tlong) tulong),
       (Expr.Etempvar ___x86_sr_width tuchar)]))
  (Stmt.Sset ___x86_sr_value (Expr.Etempvar _t'16 tulong)))

def s_kprog_x86_skb_read_7 : Stmt :=
(Stmt.Ssequence
  (Stmt.Ssequence
    (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                        (Expr.Ecast (Expr.Etempvar _base tulong) tulong)
                        (Expr.Econst_int (Integers.Int.repr 16) tuint) tint)
      (Stmt.Ssequence
        (Stmt.Sset _t'25
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
                  (Expr.Ecast (Expr.Etempvar _base tulong) tuchar)
                  (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                (Ty.Tstruct _x86_sim_gpr_cell noattr)) _value
              (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
        (Stmt.Sset _t'17
          (Expr.Ecast (Expr.Etempvar _t'25 (tptr tvoid)) (tptr tvoid))))
      (Stmt.Sset _t'17
        (Expr.Ecast
          (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
            (tptr tvoid)) (tptr tvoid))))
    (Stmt.Scall (some _t'18)
      (Expr.Evar _kprog_x86_mem_load (Ty.Tfunction [(tptr tvoid), tuchar]
                                       tulong cc_default))
      [(Expr.Ecast
         (Expr.Ecast
           (Expr.Ebinop Binop.Oadd
             (Expr.Ecast
               (Expr.Ecast (Expr.Etempvar _t'17 (tptr tvoid)) tulong) tulong)
             (Expr.Ecast (Expr.Etempvar _offset tlong) tulong) tulong)
           tulong) (tptr tuchar)), (Expr.Etempvar _width tulong)]))
  (Stmt.Sset ___x86_sr_value (Expr.Etempvar _t'18 tulong)))

def s_kprog_x86_skb_read_8 : Stmt :=
Stmt.Sbreak

def f_kprog_x86_skb_read : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_state, (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
                (_base, tulong), (_offset, tlong), (_width, tulong)],
  fn_vars := [],
  fn_temps := [(___x86_state,
                (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
               (_result, tulong), (___x86_sr_width, tuchar),
               (___x86_sr_off, tlong),
               (___x86_sr_ctx, (tptr (Ty.Tstruct ___sk_buff noattr))),
               (___x86_sr_value, tulong), (___x86_sr_lane, tlong),
               (___x86_cbr_addr, (tptr (tvolatile tuchar))),
               (___x86_cbr_value, tulong), (_t'24, tint), (_t'23, tint),
               (_t'22, tint), (_t'21, tint), (_t'20, tint), (_t'19, tint),
               (_t'18, tulong), (_t'17, (tptr tvoid)), (_t'16, tulong),
               (_t'15, tulong), (_t'14, tulong), (_t'13, (tvolatile tuchar)),
               (_t'12, (tvolatile tuchar)), (_t'11, (tvolatile tuchar)),
               (_t'10, (tvolatile tuchar)), (_t'9, (tvolatile tuchar)),
               (_t'8, (tvolatile tuchar)), (_t'7, (tvolatile tuchar)),
               (_t'6, (tvolatile tuchar)), (_t'5, tulong), (_t'4, tulong),
               (_t'3, (tptr tvoid)), (_t'2, (tptr tvoid)),
               (_t'1, (tptr tvoid)), (_t'30, (tptr tvoid)),
               (_t'29, (tptr tvoid)), (_t'28, tuint), (_t'27, tuint),
               (_t'26, tuint), (_t'25, (tptr tvoid))],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_state
    (Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))))
  (Stmt.Ssequence
    (Stmt.Sloop
      (Stmt.Ssequence
        (Stmt.Sset ___x86_sr_width
          (Expr.Ecast (Expr.Etempvar _width tulong) tuchar))
        (Stmt.Ssequence
          (Stmt.Ssequence
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Olt
                                (Expr.Ecast (Expr.Etempvar _base tulong)
                                  tulong)
                                (Expr.Econst_int (Integers.Int.repr 16) tuint)
                                tint)
              (Stmt.Ssequence
                (Stmt.Sset _t'30
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
                          (Expr.Ecast (Expr.Etempvar _base tulong) tuchar)
                          (tptr (Ty.Tstruct _x86_sim_gpr_cell noattr)))
                        (Ty.Tstruct _x86_sim_gpr_cell noattr)) _value
                      (Ty.Tunion _x86_sim_gpr noattr)) _ptr (tptr tvoid)))
                (Stmt.Sset _t'1
                  (Expr.Ecast (Expr.Etempvar _t'30 (tptr tvoid))
                    (tptr tvoid))))
              (Stmt.Sset _t'1
                (Expr.Ecast
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                    (tptr tvoid)) (tptr tvoid))))
            (Stmt.Ssequence
              (Stmt.Sset _t'29
                (Expr.Efield
                  (Expr.Ederef
                    (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                    (Ty.Tstruct _x86_sim_register_state noattr))
                  _helper_abi_base (tptr tvoid)))
              (Stmt.Sset ___x86_sr_off
                (Expr.Ecast
                  (Expr.Ebinop Binop.Oadd
                    (Expr.Ebinop Binop.Osub
                      (Expr.Ecast
                        (Expr.Ecast (Expr.Etempvar _t'1 (tptr tvoid)) tlong)
                        tulong)
                      (Expr.Ecast
                        (Expr.Ecast (Expr.Etempvar _t'29 (tptr tvoid)) tlong)
                        tulong) tulong)
                    (Expr.Ecast (Expr.Etempvar _offset tlong) tulong) tulong)
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
                    (Stmt.Sset _t'23
                      (Expr.Ecast
                        (Expr.Ebinop Binop.Ole
                          (Expr.Etempvar ___x86_sr_off tlong)
                          (Expr.Ebinop Binop.Osub
                            (Expr.Ebinop Binop.Oadd
                              (Expr.Econst_long (Integers.Int64.repr 208) tlong)
                              (Expr.Econst_int (Integers.Int.repr 8) tint)
                              tlong) (Expr.Etempvar _width tulong) tulong)
                          tint) tbool))
                    (Stmt.Sset _t'23
                      (Expr.Econst_int (Integers.Int.repr 0) tint)))
                  (Stmt.Sifthenelse (Expr.Etempvar _t'23 tint)
                    (Stmt.Sset _t'24
                      (Expr.Econst_int (Integers.Int.repr 1) tint))
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                        (Expr.Etempvar ___x86_sr_off tlong)
                                        (Expr.Econst_long (Integers.Int64.repr 80) tlong)
                                        tint)
                      (Stmt.Ssequence
                        (Stmt.Sset _t'24
                          (Expr.Ecast
                            (Expr.Ebinop Binop.Ole
                              (Expr.Etempvar ___x86_sr_off tlong)
                              (Expr.Ebinop Binop.Osub
                                (Expr.Ebinop Binop.Oadd
                                  (Expr.Econst_long (Integers.Int64.repr 80) tlong)
                                  (Expr.Econst_int (Integers.Int.repr 8) tint)
                                  tlong) (Expr.Etempvar _width tulong)
                                tulong) tint) tbool))
                        (Stmt.Sset _t'24
                          (Expr.Ecast (Expr.Etempvar _t'24 tint) tbool)))
                      (Stmt.Sset _t'24
                        (Expr.Ecast
                          (Expr.Econst_int (Integers.Int.repr 0) tint) tbool)))))
                (Stmt.Sifthenelse (Expr.Etempvar _t'24 tint)
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                        (Expr.Etempvar ___x86_sr_off tlong)
                                        (Expr.Econst_long (Integers.Int64.repr 208) tlong)
                                        tint)
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'2)
                            (Expr.Evar _kprog_c_context_pointer (Ty.Tfunction
                                                                  [(tptr tvoid),
                                                                   tuchar,
                                                                   tuint]
                                                                  (tptr tvoid)
                                                                  cc_default))
                            [(Expr.Etempvar ___x86_sr_ctx (tptr (Ty.Tstruct ___sk_buff noattr))),
                             (Expr.Econst_int (Integers.Int.repr 1) tuint),
                             (Expr.Econst_long (Integers.Int64.repr 76) tulong)])
                          (Stmt.Sset ___x86_sr_value
                            (Expr.Ecast
                              (Expr.Ecast (Expr.Etempvar _t'2 (tptr tvoid))
                                tulong) tulong)))
                        (Stmt.Sset ___x86_sr_lane
                          (Expr.Ebinop Binop.Osub
                            (Expr.Etempvar ___x86_sr_off tlong)
                            (Expr.Econst_long (Integers.Int64.repr 208) tlong)
                            tlong)))
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'3)
                            (Expr.Evar _kprog_c_context_pointer (Ty.Tfunction
                                                                  [(tptr tvoid),
                                                                   tuchar,
                                                                   tuint]
                                                                  (tptr tvoid)
                                                                  cc_default))
                            [(Expr.Etempvar ___x86_sr_ctx (tptr (Ty.Tstruct ___sk_buff noattr))),
                             (Expr.Econst_int (Integers.Int.repr 1) tuint),
                             (Expr.Econst_long (Integers.Int64.repr 80) tulong)])
                          (Stmt.Sset ___x86_sr_value
                            (Expr.Ecast
                              (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                                tulong) tulong)))
                        (Stmt.Sset ___x86_sr_lane
                          (Expr.Ebinop Binop.Osub
                            (Expr.Etempvar ___x86_sr_off tlong)
                            (Expr.Econst_long (Integers.Int64.repr 80) tlong)
                            tlong))))
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.One
                                        (Expr.Etempvar _width tulong)
                                        (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                        tint)
                      (Stmt.Ssequence
                        (Stmt.Ssequence
                          (Stmt.Scall (some _t'4)
                            (Expr.Evar _kprog_c_pointer_bits (Ty.Tfunction
                                                               [(tptr tvoid)]
                                                               tulong
                                                               cc_default))
                            [(Expr.Ecast
                               (Expr.Ecast
                                 (Expr.Etempvar ___x86_sr_value tulong)
                                 tulong) (tptr tvoid))])
                          (Stmt.Scall (some _t'5)
                            (Expr.Evar _x86_apply_width (Ty.Tfunction
                                                          [tulong, tuchar]
                                                          tulong cc_default))
                            [(Expr.Ebinop Binop.Oshr
                               (Expr.Etempvar _t'4 tulong)
                               (Expr.Ebinop Binop.Omul
                                 (Expr.Etempvar ___x86_sr_lane tlong)
                                 (Expr.Econst_int (Integers.Int.repr 8) tint)
                                 tlong) tulong),
                             (Expr.Etempvar _width tulong)]))
                        (Stmt.Sset ___x86_sr_value
                          (Expr.Etempvar _t'5 tulong)))
                      Stmt.Sskip))
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                        (Expr.Etempvar ___x86_sr_off tlong)
                                        (Expr.Econst_long (Integers.Int64.repr 48) tlong)
                                        tint)
                      (Stmt.Sset _t'22
                        (Expr.Ecast
                          (Expr.Ebinop Binop.Ole
                            (Expr.Etempvar ___x86_sr_off tlong)
                            (Expr.Ebinop Binop.Osub
                              (Expr.Ebinop Binop.Oadd
                                (Expr.Econst_long (Integers.Int64.repr 48) tlong)
                                (Expr.Econst_int (Integers.Int.repr 20) tint)
                                tlong) (Expr.Etempvar _width tulong) tulong)
                            tint) tbool))
                      (Stmt.Sset _t'22
                        (Expr.Econst_int (Integers.Int.repr 0) tint)))
                    (Stmt.Sifthenelse (Expr.Etempvar _t'22 tint)
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
                              (Stmt.Sbuiltin (some _t'6)
                                (ExtFun.EF_vload Chunk.Mint8unsigned)
                                [(tptr (tvolatile tuchar))]
                                [(Expr.Eaddrof
                                   (Expr.Ederef
                                     (Expr.Ebinop Binop.Oadd
                                       (Expr.Etempvar ___x86_cbr_addr (tptr (tvolatile tuchar)))
                                       (Expr.Econst_int (Integers.Int.repr 0) tint)
                                       (tptr (tvolatile tuchar)))
                                     (tvolatile tuchar))
                                   (tptr (tvolatile tuchar)))])
                              (Stmt.Sset ___x86_cbr_value
                                (Expr.Ecast
                                  (Expr.Etempvar _t'6 (tvolatile tuchar))
                                  tulong)))
                            (Stmt.Ssequence
                              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                                  (Expr.Etempvar _width tulong)
                                                  (Expr.Econst_int (Integers.Int.repr 2) tuint)
                                                  tint)
                                s_kprog_x86_skb_read_0
                                Stmt.Sskip)
                              (Stmt.Ssequence
                                s_kprog_x86_skb_read_1
                                s_kprog_x86_skb_read_2))))
                        Stmt.Sbreak)
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                            (Expr.Etempvar ___x86_sr_off tlong)
                                            (Expr.Econst_int (Integers.Int.repr 134) tint)
                                            tint)
                          (Stmt.Sset _t'21
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Ole
                                (Expr.Etempvar ___x86_sr_off tlong)
                                (Expr.Ebinop Binop.Osub
                                  (Expr.Ebinop Binop.Oadd
                                    (Expr.Econst_int (Integers.Int.repr 134) tint)
                                    (Expr.Econst_int (Integers.Int.repr 2) tint)
                                    tint)
                                  (Expr.Etempvar ___x86_sr_width tuchar)
                                  tint) tint) tbool))
                          (Stmt.Sset _t'21
                            (Expr.Econst_int (Integers.Int.repr 0) tint)))
                        (Stmt.Sifthenelse (Expr.Etempvar _t'21 tint)
                          (Stmt.Ssequence
                            (Stmt.Ssequence
                              (Stmt.Sset _t'28
                                (Expr.Efield
                                  (Expr.Ederef
                                    (Expr.Etempvar ___x86_sr_ctx (tptr (Ty.Tstruct ___sk_buff noattr)))
                                    (Ty.Tstruct ___sk_buff noattr)) _tc_index
                                  tuint))
                              (Stmt.Scall (some _t'14)
                                (Expr.Evar _x86_apply_width (Ty.Tfunction
                                                              [tulong,
                                                               tuchar] tulong
                                                              cc_default))
                                [(Expr.Ebinop Binop.Oshr
                                   (Expr.Ecast (Expr.Etempvar _t'28 tuint)
                                     tulong)
                                   (Expr.Ebinop Binop.Omul
                                     (Expr.Ebinop Binop.Osub
                                       (Expr.Etempvar ___x86_sr_off tlong)
                                       (Expr.Econst_int (Integers.Int.repr 134) tint)
                                       tlong)
                                     (Expr.Econst_int (Integers.Int.repr 8) tint)
                                     tlong) tulong),
                                 (Expr.Etempvar ___x86_sr_width tuchar)]))
                            (Stmt.Sset ___x86_sr_value
                              (Expr.Etempvar _t'14 tulong)))
                          (Stmt.Ssequence
                            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                                (Expr.Etempvar ___x86_sr_off tlong)
                                                (Expr.Econst_int (Integers.Int.repr 144) tint)
                                                tint)
                              s_kprog_x86_skb_read_3
                              (Stmt.Sset _t'20
                                (Expr.Econst_int (Integers.Int.repr 0) tint)))
                            (Stmt.Sifthenelse (Expr.Etempvar _t'20 tint)
                              (Stmt.Ssequence
                                s_kprog_x86_skb_read_4
                                (Stmt.Sset ___x86_sr_value
                                  (Expr.Etempvar _t'15 tulong)))
                              (Stmt.Ssequence
                                s_kprog_x86_skb_read_5
                                (Stmt.Sifthenelse (Expr.Etempvar _t'19 tint)
                                  s_kprog_x86_skb_read_6
                                  (Stmt.Sloop
                                    s_kprog_x86_skb_read_7
                                    s_kprog_x86_skb_read_8)))))))))))
              (Stmt.Sset _result (Expr.Etempvar ___x86_sr_value tulong))))))
      Stmt.Sbreak)
    (Stmt.Sreturn (some (Expr.Etempvar _result tulong)))))
}

def f_kprog_x86_xdp_read : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_state, (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
                (_base, (tptr tvoid)), (_offset, tlong), (_width, tulong)],
  fn_vars := [],
  fn_temps := [(___x86_state,
                (tptr (Ty.Tstruct _x86_sim_register_state noattr))),
               (_result, tulong), (___x86_xdp_off, tlong),
               (___x86_xdp_ctx,
                (tptr (tvolatile (Ty.Tstruct _xdp_md noattr)))),
               (___x86_captured_xdp_value, tulong), (_t'7, tint),
               (_t'6, tint), (_t'5, tint), (_t'4, tulong),
               (_t'3, (tptr tvoid)), (_t'2, (tptr tvoid)),
               (_t'1, (tptr tvoid)), (_t'8, (tptr tvoid))],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sset ___x86_state
    (Expr.Etempvar _state (tptr (Ty.Tstruct _x86_sim_register_state noattr))))
  (Stmt.Ssequence
    (Stmt.Sloop
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sset _t'8
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
                    (Expr.Ecast (Expr.Etempvar _base (tptr tvoid)) tlong)
                    tulong)
                  (Expr.Ecast
                    (Expr.Ecast (Expr.Etempvar _t'8 (tptr tvoid)) tlong)
                    tulong) tulong)
                (Expr.Ecast (Expr.Etempvar _offset tlong) tulong) tulong)
              tlong)))
        (Stmt.Ssequence
          (Stmt.Sset ___x86_xdp_ctx
            (Expr.Efield
              (Expr.Ederef
                (Expr.Etempvar ___x86_state (tptr (Ty.Tstruct _x86_sim_register_state noattr)))
                (Ty.Tstruct _x86_sim_register_state noattr)) _helper_ctx
              (tptr tvoid)))
          (Stmt.Ssequence
            (Stmt.Sset ___x86_captured_xdp_value
              (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tint)
                tulong))
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Etempvar _width tulong)
                                    (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                    tint)
                  (Stmt.Sset _t'7
                    (Expr.Ecast
                      (Expr.Ebinop Binop.Oeq
                        (Expr.Etempvar ___x86_xdp_off tlong)
                        (Expr.Econst_long (Integers.Int64.repr 0) tlong)
                        tint) tbool))
                  (Stmt.Sset _t'7
                    (Expr.Econst_int (Integers.Int.repr 0) tint)))
                (Stmt.Sifthenelse (Expr.Etempvar _t'7 tint)
                  (Stmt.Ssequence
                    (Stmt.Scall (some _t'1)
                      (Expr.Evar _kprog_c_context_pointer (Ty.Tfunction
                                                            [(tptr tvoid),
                                                             tuchar, tuint]
                                                            (tptr tvoid)
                                                            cc_default))
                      [(Expr.Etempvar ___x86_xdp_ctx (tptr (tvolatile (Ty.Tstruct _xdp_md noattr)))),
                       (Expr.Econst_int (Integers.Int.repr 0) tuint),
                       (Expr.Econst_long (Integers.Int64.repr 0) tulong)])
                    (Stmt.Sset ___x86_captured_xdp_value
                      (Expr.Ecast
                        (Expr.Ecast (Expr.Etempvar _t'1 (tptr tvoid)) tulong)
                        tulong)))
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Etempvar _width tulong)
                                        (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                        tint)
                      (Stmt.Sset _t'6
                        (Expr.Ecast
                          (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar ___x86_xdp_off tlong)
                            (Expr.Econst_long (Integers.Int64.repr 8) tlong)
                            tint) tbool))
                      (Stmt.Sset _t'6
                        (Expr.Econst_int (Integers.Int.repr 0) tint)))
                    (Stmt.Sifthenelse (Expr.Etempvar _t'6 tint)
                      (Stmt.Ssequence
                        (Stmt.Scall (some _t'2)
                          (Expr.Evar _kprog_c_context_pointer (Ty.Tfunction
                                                                [(tptr tvoid),
                                                                 tuchar,
                                                                 tuint]
                                                                (tptr tvoid)
                                                                cc_default))
                          [(Expr.Etempvar ___x86_xdp_ctx (tptr (tvolatile (Ty.Tstruct _xdp_md noattr)))),
                           (Expr.Econst_int (Integers.Int.repr 0) tuint),
                           (Expr.Econst_long (Integers.Int64.repr 4) tulong)])
                        (Stmt.Sset ___x86_captured_xdp_value
                          (Expr.Ecast
                            (Expr.Ecast (Expr.Etempvar _t'2 (tptr tvoid))
                              tulong) tulong)))
                      (Stmt.Ssequence
                        (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                            (Expr.Etempvar _width tulong)
                                            (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                            tint)
                          (Stmt.Sset _t'5
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Oeq
                                (Expr.Etempvar ___x86_xdp_off tlong)
                                (Expr.Econst_int (Integers.Int.repr 16) tint)
                                tint) tbool))
                          (Stmt.Sset _t'5
                            (Expr.Econst_int (Integers.Int.repr 0) tint)))
                        (Stmt.Sifthenelse (Expr.Etempvar _t'5 tint)
                          (Stmt.Ssequence
                            (Stmt.Scall (some _t'3)
                              (Expr.Evar _kprog_c_context_pointer (Ty.Tfunction
                                                                    [(tptr tvoid),
                                                                    tuchar,
                                                                    tuint]
                                                                    (tptr tvoid)
                                                                    cc_default))
                              [(Expr.Etempvar ___x86_xdp_ctx (tptr (tvolatile (Ty.Tstruct _xdp_md noattr)))),
                               (Expr.Econst_int (Integers.Int.repr 0) tuint),
                               (Expr.Econst_long (Integers.Int64.repr 8) tulong)])
                            (Stmt.Sset ___x86_captured_xdp_value
                              (Expr.Ecast
                                (Expr.Ecast (Expr.Etempvar _t'3 (tptr tvoid))
                                  tulong) tulong)))
                          (Stmt.Sloop
                            (Stmt.Ssequence
                              (Stmt.Scall (some _t'4)
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
                                           (Expr.Etempvar _base (tptr tvoid))
                                           tulong) tulong)
                                       (Expr.Ecast
                                         (Expr.Etempvar _offset tlong)
                                         tulong) tulong) tulong)
                                   (tptr tuchar)),
                                 (Expr.Etempvar _width tulong)])
                              (Stmt.Sset ___x86_captured_xdp_value
                                (Expr.Etempvar _t'4 tulong)))
                            Stmt.Sbreak)))))))
              (Stmt.Sset _result
                (Expr.Etempvar ___x86_captured_xdp_value tulong))))))
      Stmt.Sbreak)
    (Stmt.Sreturn (some (Expr.Etempvar _result tulong)))))
}

def f_kprog_x86_cb_read : Function := {
  fn_return := tulong,
  fn_callconv := cc_default,
  fn_params := [(_context, (tptr tvoid)), (_offset, tlong), (_width, tulong)],
  fn_vars := [],
  fn_temps := [(_result, tulong),
               (___x86_cbr_addr, (tptr (tvolatile tuchar))),
               (___x86_cbr_value, tulong), (_t'8, (tvolatile tuchar)),
               (_t'7, (tvolatile tuchar)), (_t'6, (tvolatile tuchar)),
               (_t'5, (tvolatile tuchar)), (_t'4, (tvolatile tuchar)),
               (_t'3, (tvolatile tuchar)), (_t'2, (tvolatile tuchar)),
               (_t'1, (tvolatile tuchar))],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sset ___x86_cbr_addr
        (Expr.Ebinop Binop.Oadd
          (Expr.Ecast (Expr.Etempvar _context (tptr tvoid))
            (tptr (tvolatile tuchar))) (Expr.Etempvar _offset tlong)
          (tptr (tvolatile tuchar))))
      (Stmt.Ssequence
        (Stmt.Ssequence
          (Stmt.Sbuiltin (some _t'1) (ExtFun.EF_vload Chunk.Mint8unsigned)
            [(tptr (tvolatile tuchar))]
            [(Expr.Eaddrof
               (Expr.Ederef
                 (Expr.Ebinop Binop.Oadd
                   (Expr.Etempvar ___x86_cbr_addr (tptr (tvolatile tuchar)))
                   (Expr.Econst_int (Integers.Int.repr 0) tint)
                   (tptr (tvolatile tuchar))) (tvolatile tuchar))
               (tptr (tvolatile tuchar)))])
          (Stmt.Sset ___x86_cbr_value
            (Expr.Ecast (Expr.Etempvar _t'1 (tvolatile tuchar)) tulong)))
        (Stmt.Ssequence
          (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                              (Expr.Etempvar _width tulong)
                              (Expr.Econst_int (Integers.Int.repr 2) tuint)
                              tint)
            (Stmt.Ssequence
              (Stmt.Sbuiltin (some _t'2)
                (ExtFun.EF_vload Chunk.Mint8unsigned)
                [(tptr (tvolatile tuchar))]
                [(Expr.Eaddrof
                   (Expr.Ederef
                     (Expr.Ebinop Binop.Oadd
                       (Expr.Etempvar ___x86_cbr_addr (tptr (tvolatile tuchar)))
                       (Expr.Econst_int (Integers.Int.repr 1) tint)
                       (tptr (tvolatile tuchar))) (tvolatile tuchar))
                   (tptr (tvolatile tuchar)))])
              (Stmt.Sset ___x86_cbr_value
                (Expr.Ebinop Binop.Oor
                  (Expr.Etempvar ___x86_cbr_value tulong)
                  (Expr.Ebinop Binop.Oshl
                    (Expr.Ecast (Expr.Etempvar _t'2 (tvolatile tuchar))
                      tulong) (Expr.Econst_int (Integers.Int.repr 8) tint)
                    tulong) tulong)))
            Stmt.Sskip)
          (Stmt.Ssequence
            (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                (Expr.Etempvar _width tulong)
                                (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                tint)
              (Stmt.Ssequence
                (Stmt.Sbuiltin (some _t'3)
                  (ExtFun.EF_vload Chunk.Mint8unsigned)
                  [(tptr (tvolatile tuchar))]
                  [(Expr.Eaddrof
                     (Expr.Ederef
                       (Expr.Ebinop Binop.Oadd
                         (Expr.Etempvar ___x86_cbr_addr (tptr (tvolatile tuchar)))
                         (Expr.Econst_int (Integers.Int.repr 2) tint)
                         (tptr (tvolatile tuchar))) (tvolatile tuchar))
                     (tptr (tvolatile tuchar)))])
                (Stmt.Sset ___x86_cbr_value
                  (Expr.Ebinop Binop.Oor
                    (Expr.Etempvar ___x86_cbr_value tulong)
                    (Expr.Ebinop Binop.Oshl
                      (Expr.Ecast (Expr.Etempvar _t'3 (tvolatile tuchar))
                        tulong) (Expr.Econst_int (Integers.Int.repr 16) tint)
                      tulong) tulong)))
              Stmt.Sskip)
            (Stmt.Ssequence
              (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                  (Expr.Etempvar _width tulong)
                                  (Expr.Econst_int (Integers.Int.repr 4) tuint)
                                  tint)
                (Stmt.Ssequence
                  (Stmt.Sbuiltin (some _t'4)
                    (ExtFun.EF_vload Chunk.Mint8unsigned)
                    [(tptr (tvolatile tuchar))]
                    [(Expr.Eaddrof
                       (Expr.Ederef
                         (Expr.Ebinop Binop.Oadd
                           (Expr.Etempvar ___x86_cbr_addr (tptr (tvolatile tuchar)))
                           (Expr.Econst_int (Integers.Int.repr 3) tint)
                           (tptr (tvolatile tuchar))) (tvolatile tuchar))
                       (tptr (tvolatile tuchar)))])
                  (Stmt.Sset ___x86_cbr_value
                    (Expr.Ebinop Binop.Oor
                      (Expr.Etempvar ___x86_cbr_value tulong)
                      (Expr.Ebinop Binop.Oshl
                        (Expr.Ecast (Expr.Etempvar _t'4 (tvolatile tuchar))
                          tulong)
                        (Expr.Econst_int (Integers.Int.repr 24) tint) tulong)
                      tulong)))
                Stmt.Sskip)
              (Stmt.Ssequence
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                    (Expr.Etempvar _width tulong)
                                    (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                    tint)
                  (Stmt.Ssequence
                    (Stmt.Sbuiltin (some _t'5)
                      (ExtFun.EF_vload Chunk.Mint8unsigned)
                      [(tptr (tvolatile tuchar))]
                      [(Expr.Eaddrof
                         (Expr.Ederef
                           (Expr.Ebinop Binop.Oadd
                             (Expr.Etempvar ___x86_cbr_addr (tptr (tvolatile tuchar)))
                             (Expr.Econst_int (Integers.Int.repr 4) tint)
                             (tptr (tvolatile tuchar))) (tvolatile tuchar))
                         (tptr (tvolatile tuchar)))])
                    (Stmt.Sset ___x86_cbr_value
                      (Expr.Ebinop Binop.Oor
                        (Expr.Etempvar ___x86_cbr_value tulong)
                        (Expr.Ebinop Binop.Oshl
                          (Expr.Ecast (Expr.Etempvar _t'5 (tvolatile tuchar))
                            tulong)
                          (Expr.Econst_int (Integers.Int.repr 32) tint)
                          tulong) tulong)))
                  Stmt.Sskip)
                (Stmt.Ssequence
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                      (Expr.Etempvar _width tulong)
                                      (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Sbuiltin (some _t'6)
                        (ExtFun.EF_vload Chunk.Mint8unsigned)
                        [(tptr (tvolatile tuchar))]
                        [(Expr.Eaddrof
                           (Expr.Ederef
                             (Expr.Ebinop Binop.Oadd
                               (Expr.Etempvar ___x86_cbr_addr (tptr (tvolatile tuchar)))
                               (Expr.Econst_int (Integers.Int.repr 5) tint)
                               (tptr (tvolatile tuchar))) (tvolatile tuchar))
                           (tptr (tvolatile tuchar)))])
                      (Stmt.Sset ___x86_cbr_value
                        (Expr.Ebinop Binop.Oor
                          (Expr.Etempvar ___x86_cbr_value tulong)
                          (Expr.Ebinop Binop.Oshl
                            (Expr.Ecast
                              (Expr.Etempvar _t'6 (tvolatile tuchar)) tulong)
                            (Expr.Econst_int (Integers.Int.repr 40) tint)
                            tulong) tulong)))
                    Stmt.Sskip)
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                        (Expr.Etempvar _width tulong)
                                        (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                        tint)
                      (Stmt.Ssequence
                        (Stmt.Sbuiltin (some _t'7)
                          (ExtFun.EF_vload Chunk.Mint8unsigned)
                          [(tptr (tvolatile tuchar))]
                          [(Expr.Eaddrof
                             (Expr.Ederef
                               (Expr.Ebinop Binop.Oadd
                                 (Expr.Etempvar ___x86_cbr_addr (tptr (tvolatile tuchar)))
                                 (Expr.Econst_int (Integers.Int.repr 6) tint)
                                 (tptr (tvolatile tuchar)))
                               (tvolatile tuchar)) (tptr (tvolatile tuchar)))])
                        (Stmt.Sset ___x86_cbr_value
                          (Expr.Ebinop Binop.Oor
                            (Expr.Etempvar ___x86_cbr_value tulong)
                            (Expr.Ebinop Binop.Oshl
                              (Expr.Ecast
                                (Expr.Etempvar _t'7 (tvolatile tuchar))
                                tulong)
                              (Expr.Econst_int (Integers.Int.repr 48) tint)
                              tulong) tulong)))
                      Stmt.Sskip)
                    (Stmt.Ssequence
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oge
                                          (Expr.Etempvar _width tulong)
                                          (Expr.Econst_int (Integers.Int.repr 8) tuint)
                                          tint)
                        (Stmt.Ssequence
                          (Stmt.Sbuiltin (some _t'8)
                            (ExtFun.EF_vload Chunk.Mint8unsigned)
                            [(tptr (tvolatile tuchar))]
                            [(Expr.Eaddrof
                               (Expr.Ederef
                                 (Expr.Ebinop Binop.Oadd
                                   (Expr.Etempvar ___x86_cbr_addr (tptr (tvolatile tuchar)))
                                   (Expr.Econst_int (Integers.Int.repr 7) tint)
                                   (tptr (tvolatile tuchar)))
                                 (tvolatile tuchar))
                               (tptr (tvolatile tuchar)))])
                          (Stmt.Sset ___x86_cbr_value
                            (Expr.Ebinop Binop.Oor
                              (Expr.Etempvar ___x86_cbr_value tulong)
                              (Expr.Ebinop Binop.Oshl
                                (Expr.Ecast
                                  (Expr.Etempvar _t'8 (tvolatile tuchar))
                                  tulong)
                                (Expr.Econst_int (Integers.Int.repr 56) tint)
                                tulong) tulong)))
                        Stmt.Sskip)
                      (Stmt.Sset _result
                        (Expr.Etempvar ___x86_cbr_value tulong)))))))))))
    Stmt.Sbreak)
  (Stmt.Sreturn (some (Expr.Etempvar _result tulong))))
}

def f_kprog_x86_context_tag : Function := {
  fn_return := tuchar,
  fn_callconv := cc_default,
  fn_params := [(_kind, tulong), (_offset, tlong)],
  fn_vars := [],
  fn_temps := [(_tag, tuchar), (___kprog_abi_kind, tuchar),
               (___kprog_abi_offset, tlong), (___kprog_abi_tag, tuchar),
               (_t'4, tint), (_t'3, tint), (_t'2, tint), (_t'1, tint)],
  fn_body :=
(Stmt.Ssequence
  (Stmt.Sloop
    (Stmt.Ssequence
      (Stmt.Sset ___kprog_abi_kind
        (Expr.Ecast (Expr.Etempvar _kind tulong) tuchar))
      (Stmt.Ssequence
        (Stmt.Sset ___kprog_abi_offset (Expr.Etempvar _offset tlong))
        (Stmt.Ssequence
          (Stmt.Sset ___kprog_abi_tag
            (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 0) tuint) tuchar))
          (Stmt.Ssequence
            (Stmt.Ssequence
              (Stmt.Ssequence
                (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                    (Expr.Etempvar ___kprog_abi_kind tuchar)
                                    (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                    tint)
                  (Stmt.Sset _t'3
                    (Expr.Ecast
                      (Expr.Ebinop Binop.Oeq
                        (Expr.Etempvar ___kprog_abi_offset tlong)
                        (Expr.Econst_long (Integers.Int64.repr 0) tlong)
                        tint) tbool))
                  (Stmt.Sset _t'3
                    (Expr.Econst_int (Integers.Int.repr 0) tint)))
                (Stmt.Sifthenelse (Expr.Etempvar _t'3 tint)
                  (Stmt.Sset _t'4
                    (Expr.Econst_int (Integers.Int.repr 1) tint))
                  (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                      (Expr.Etempvar ___kprog_abi_kind tuchar)
                                      (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                      tint)
                    (Stmt.Ssequence
                      (Stmt.Sset _t'4
                        (Expr.Ecast
                          (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar ___kprog_abi_offset tlong)
                            (Expr.Econst_long (Integers.Int64.repr 208) tlong)
                            tint) tbool))
                      (Stmt.Sset _t'4
                        (Expr.Ecast (Expr.Etempvar _t'4 tint) tbool)))
                    (Stmt.Sset _t'4
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 0) tint) tbool)))))
              (Stmt.Sifthenelse (Expr.Etempvar _t'4 tint)
                (Stmt.Sset ___kprog_abi_tag
                  (Expr.Ecast (Expr.Econst_int (Integers.Int.repr 2) tuint)
                    tuchar))
                (Stmt.Ssequence
                  (Stmt.Ssequence
                    (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                        (Expr.Etempvar ___kprog_abi_kind tuchar)
                                        (Expr.Econst_int (Integers.Int.repr 0) tuint)
                                        tint)
                      (Stmt.Sset _t'1
                        (Expr.Ecast
                          (Expr.Ebinop Binop.Oeq
                            (Expr.Etempvar ___kprog_abi_offset tlong)
                            (Expr.Econst_long (Integers.Int64.repr 8) tlong)
                            tint) tbool))
                      (Stmt.Sset _t'1
                        (Expr.Econst_int (Integers.Int.repr 0) tint)))
                    (Stmt.Sifthenelse (Expr.Etempvar _t'1 tint)
                      (Stmt.Sset _t'2
                        (Expr.Econst_int (Integers.Int.repr 1) tint))
                      (Stmt.Sifthenelse (Expr.Ebinop Binop.Oeq
                                          (Expr.Etempvar ___kprog_abi_kind tuchar)
                                          (Expr.Econst_int (Integers.Int.repr 1) tuint)
                                          tint)
                        (Stmt.Ssequence
                          (Stmt.Sset _t'2
                            (Expr.Ecast
                              (Expr.Ebinop Binop.Oeq
                                (Expr.Etempvar ___kprog_abi_offset tlong)
                                (Expr.Econst_long (Integers.Int64.repr 80) tlong)
                                tint) tbool))
                          (Stmt.Sset _t'2
                            (Expr.Ecast (Expr.Etempvar _t'2 tint) tbool)))
                        (Stmt.Sset _t'2
                          (Expr.Ecast
                            (Expr.Econst_int (Integers.Int.repr 0) tint)
                            tbool)))))
                  (Stmt.Sifthenelse (Expr.Etempvar _t'2 tint)
                    (Stmt.Sset ___kprog_abi_tag
                      (Expr.Ecast
                        (Expr.Econst_int (Integers.Int.repr 3) tuint) tuchar))
                    Stmt.Sskip))))
            (Stmt.Sset _tag
              (Expr.Ecast (Expr.Etempvar ___kprog_abi_tag tuchar) tuchar))))))
    Stmt.Sbreak)
  (Stmt.Sreturn (some (Expr.Etempvar _tag tuchar))))
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
 (_x86_apply_width, GlobDef.Gfun (FunDef.Internal f_x86_apply_width)),
 (_kprog_x86_mem_load, GlobDef.Gfun (FunDef.Internal f_kprog_x86_mem_load)),
 (_kprog_x86_skb_read, GlobDef.Gfun (FunDef.Internal f_kprog_x86_skb_read)),
 (_kprog_x86_xdp_read, GlobDef.Gfun (FunDef.Internal f_kprog_x86_xdp_read)),
 (_kprog_x86_cb_read, GlobDef.Gfun (FunDef.Internal f_kprog_x86_cb_read)),
 (_kprog_x86_context_tag, GlobDef.Gfun (FunDef.Internal f_kprog_x86_context_tag))]

def public_idents : List Ident :=
[_kprog_x86_context_tag, _kprog_x86_cb_read, _kprog_x86_xdp_read,
 _kprog_x86_skb_read, _kprog_c_pointer_bits, _kprog_c_context_pointer,
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

end X86Context

