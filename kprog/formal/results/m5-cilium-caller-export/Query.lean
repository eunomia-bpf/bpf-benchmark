import KProgFormal.Clight.Arm64CiliumCaller
#check Arm64CiliumCallerUnit.prog
#print axioms Arm64CiliumCallerUnit.prog
#check Arm64CiliumCallerUnit.f_trusted_arm64_arm64_sim_xdp
#print axioms Arm64CiliumCallerUnit.f_trusted_arm64_arm64_sim_xdp
example : Arm64CiliumCallerUnit.Info.source_file = "c/Arm64CiliumCallerUnit.c" := rfl
example : Arm64CiliumCallerUnit.f_trusted_arm64_arm64_sim_xdp.fn_params =
    [(Arm64CiliumCallerUnit._ctx, CC.tptr (.Tstruct Arm64CiliumCallerUnit._xdp_md CC.noattr))] := rfl
