# Silent Cilium BTF write refusal

Observed terminal B1392 u16 store through trusted_ptr_sk_buff(off134), SCHED_CLS type3 and EACCES. Source check_ptr_to_btf_access delegates nonallocated BTF writes to tc_cls_act_btf_struct_access; that callback returns silent EACCES when nfct provider is absent, and the current nfct provider rejects non-nf_conn types if present. Callback value/branch was not dynamically recorded.

Names the rejected access class, not a claimed dynamic callback-pointer observation. No fabricated only-read diagnostic; exact build-to-runtime callback registration is not independently traced. Source policy plus captured type/instruction/errno supports this classification. No repair or acceptance change.

All100 final refusals now have names: {"infinite loop": 25, "context layout": 1, "typed field layout": 1, "modified context pointer": 1, "unbounded memory access": 1, "scalar memory access": 8, "packet bounds": 13, "BTF typed object write": 1, "map value bounds": 12, "stack bounds": 26, "jump sequence complexity": 11}. Acceptance remains45/145 with all28 controls preserved. Full archived log and load metadata hashes checked against committed3052-file receipt. The archive parts are retained; no RAW copy or guest/compiler/header/kernel/framework change.
