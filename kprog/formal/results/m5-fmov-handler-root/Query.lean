import KProgFormal
open KProgFormal.ClightRefinement
#check Arm64Fmov.Dispatch.body_source
#print axioms Arm64Fmov.Dispatch.body_source
#check Arm64Fmov.Dispatch.body_dispatch
#print axioms Arm64Fmov.Dispatch.body_dispatch
#check Arm64Fmov.Body.execute
#print axioms Arm64Fmov.Body.execute
#check Arm64Fmov.Body.corresponds
#print axioms Arm64Fmov.Body.corresponds
#check Arm64Fmov.VectorView.gpr
#print axioms Arm64Fmov.VectorView.gpr
#check Arm64Fmov.VectorView.sp
#print axioms Arm64Fmov.VectorView.sp
#check Arm64Fmov.VectorView.flags
#print axioms Arm64Fmov.VectorView.flags
#check Arm64Fmov.VectorView.selected
#print axioms Arm64Fmov.VectorView.selected
#check Arm64Fmov.VectorView.other
#print axioms Arm64Fmov.VectorView.other
#check Arm64Fmov.NativeView.gpr
#print axioms Arm64Fmov.NativeView.gpr
#check Arm64Fmov.NativeView.sp
#print axioms Arm64Fmov.NativeView.sp
#check Arm64Fmov.NativeView.flag
#print axioms Arm64Fmov.NativeView.flag
#check Arm64Fmov.NativeView.other
#print axioms Arm64Fmov.NativeView.other
#check Arm64Fmov.NativeView.source
#print axioms Arm64Fmov.NativeView.source
#check Arm64Fmov.NativeView.represents
#print axioms Arm64Fmov.NativeView.represents
#check Arm64Fmov.Call.execute
#print axioms Arm64Fmov.Call.execute
#check Arm64Fmov.Call.Result.all_behaviors
#print axioms Arm64Fmov.Call.Result.all_behaviors
#check Arm64Fmov.Call.returned
#print axioms Arm64Fmov.Call.returned
#check Arm64ProgramEntryFmovAdmission.next_admission
#print axioms Arm64ProgramEntryFmovAdmission.next_admission
#check Arm64ProgramEntryFmovAdmission.setup_next
#print axioms Arm64ProgramEntryFmovAdmission.setup_next
