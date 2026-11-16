import KProgFormal.ClightRefinement.Arm64ProducerPrefix
open KProgFormal.ClightRefinement
#eval Arm64Producer.cachePrefix.length
#eval (Arm64Producer.ge.genv_cenv.get Arm64Entry._arm64_sim_skb_abi).map (fun c => c.co_sizeof)
#eval [Arm64Entry._pad0, Arm64Entry._cb, Arm64Entry._pad1, Arm64Entry._data_end,
  Arm64Entry._pad2, Arm64Entry._data].map (fun id =>
  (Arm64Producer.ge.genv_cenv.get Arm64Entry._arm64_sim_skb_abi).bind (fun c =>
    match CC.fieldOffset Arm64Producer.ge.genv_cenv id c.co_members with
    | .OK (offset, _) => some offset
    | _ => none))
