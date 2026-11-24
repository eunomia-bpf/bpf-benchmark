import KProgFormal
open KProgFormal.ClightRefinement

#check Arm64ProgramEntryCntPrefixNative.entry_corresponds
#print axioms Arm64ProgramEntryCntPrefixNative.entry_corresponds

#check Arm64Cnt.Call.execute
#print axioms Arm64Cnt.Call.execute

#check Arm64Cnt.Call.returned
#print axioms Arm64Cnt.Call.returned

#check Arm64Cnt.Call.Result.all_behaviors
#print axioms Arm64Cnt.Call.Result.all_behaviors

#check Arm64Cnt.Call.Result.pointers
#print axioms Arm64Cnt.Call.Result.pointers

#check Arm64Cnt.Call.Result.borrowed
#print axioms Arm64Cnt.Call.Result.borrowed

#check Arm64Cnt.Call.Result.warm
#print axioms Arm64Cnt.Call.Result.warm

#check Arm64ProgramEntryCntAdmission.next_admission
#print axioms Arm64ProgramEntryCntAdmission.next_admission

#check Arm64ProgramEntryCntAdmission.setup_next
#print axioms Arm64ProgramEntryCntAdmission.setup_next

#check Arm64ProgramEntryFmovPrefixNative.entry_corresponds
#print axioms Arm64ProgramEntryFmovPrefixNative.entry_corresponds

#check Arm64Cnt.Body.corresponds
#print axioms Arm64Cnt.Body.corresponds

#check Arm64ProgramEntryCntCall.enter
#print axioms Arm64ProgramEntryCntCall.enter

#check Arm64ProgramEntryCntCall.leave
#print axioms Arm64ProgramEntryCntCall.leave

#check X86AluXorByteCall.execute
#print axioms X86AluXorByteCall.execute

#check X86AluXorByteNative.execute
#print axioms X86AluXorByteNative.execute

#check X86LogicByteOperands.scalar
#print axioms X86LogicByteOperands.scalar

#check X86LogicByteOperands.xor_step
#print axioms X86LogicByteOperands.xor_step

#check X86LogicReferenceView.flags
#print axioms X86LogicReferenceView.flags

#check X86LogicReferenceView.represented
#print axioms X86LogicReferenceView.represented

#check X86AluXorInputs.entry
#print axioms X86AluXorInputs.entry

#check X86AluXorShortcutInputs.observations
#print axioms X86AluXorShortcutInputs.observations

#check X86AluXorShortcutInputs.entry
#print axioms X86AluXorShortcutInputs.entry

#check X86AluXorShortcutByteCall.execute
#print axioms X86AluXorShortcutByteCall.execute

#check X86AluXorShortcutByteNative.execute
#print axioms X86AluXorShortcutByteNative.execute

#check X86AluXorByteAll.execute
#print axioms X86AluXorByteAll.execute

#check Arm64ProgramEntryUaddlvPrefixNative.entry_corresponds
#print axioms Arm64ProgramEntryUaddlvPrefixNative.entry_corresponds

#check Arm64Uaddlv.Call.execute
#print axioms Arm64Uaddlv.Call.execute

#check Arm64Uaddlv.Call.returned
#print axioms Arm64Uaddlv.Call.returned

#check Arm64Uaddlv.Call.Result.all_behaviors
#print axioms Arm64Uaddlv.Call.Result.all_behaviors

#check Arm64Uaddlv.Call.Result.pointers
#print axioms Arm64Uaddlv.Call.Result.pointers

#check Arm64Uaddlv.Call.Result.borrowed
#print axioms Arm64Uaddlv.Call.Result.borrowed

#check Arm64Uaddlv.Call.Result.warm
#print axioms Arm64Uaddlv.Call.Result.warm

#check Arm64ProgramEntryUaddlvAdmission.next_admission
#print axioms Arm64ProgramEntryUaddlvAdmission.next_admission

#check Arm64ProgramEntryUaddlvAdmission.setup_next
#print axioms Arm64ProgramEntryUaddlvAdmission.setup_next

#check Arm64Uaddlv.Body.corresponds
#print axioms Arm64Uaddlv.Body.corresponds

#check Arm64ProgramEntryUaddlvCall.enter
#print axioms Arm64ProgramEntryUaddlvCall.enter

#check Arm64ProgramEntryUaddlvCall.leave
#print axioms Arm64ProgramEntryUaddlvCall.leave

#check Arm64Uaddlv.Lanes.word
#print axioms Arm64Uaddlv.Lanes.word

#check Arm64Uaddlv.Lanes.halves128
#print axioms Arm64Uaddlv.Lanes.halves128

#check Arm64Uaddlv.Path.execute
#print axioms Arm64Uaddlv.Path.execute

#check Arm64Uaddlv.VectorWrite.execute
#print axioms Arm64Uaddlv.VectorWrite.execute

#check Arm64Uaddlv.Reduction.corresponds
#print axioms Arm64Uaddlv.Reduction.corresponds

#check X86FullWidthStorage.source
#print axioms X86FullWidthStorage.source

#check X86FullWidthStorage.writable
#print axioms X86FullWidthStorage.writable

#check X86FullWidthStorage.select
#print axioms X86FullWidthStorage.select

#check X86FullWidthStorage.execute
#print axioms X86FullWidthStorage.execute

#check X86FullWidthTable.native
#print axioms X86FullWidthTable.native

#check X86FullWidthTable.writable
#print axioms X86FullWidthTable.writable

#check X86FullWidthWriteback.table
#print axioms X86FullWidthWriteback.table

#check X86FullWidthWriteback.from_storage
#print axioms X86FullWidthWriteback.from_storage

#check X86RegisterWriterInputs.casts
#print axioms X86RegisterWriterInputs.casts

#check X86RegisterWriterInputs.cell
#print axioms X86RegisterWriterInputs.cell

#check X86RegisterWriterInputs.stack
#print axioms X86RegisterWriterInputs.stack

#check X86DwordWriteback.execute
#print axioms X86DwordWriteback.execute

#check X86DwordWriteback.allocated
#print axioms X86DwordWriteback.allocated

#check X86LogicDwordTail.execute
#print axioms X86LogicDwordTail.execute

#check X86AluXorDwordCall.execute
#print axioms X86AluXorDwordCall.execute

#check X86LogicRegisterReference.native_step
#print axioms X86LogicRegisterReference.native_step

#check X86LogicRegisterReference.step
#print axioms X86LogicRegisterReference.step

#check X86LogicDwordOperands.scalar
#print axioms X86LogicDwordOperands.scalar

#check X86LogicDwordOperands.xor_step
#print axioms X86LogicDwordOperands.xor_step

#check X86AluXorDwordNative.execute
#print axioms X86AluXorDwordNative.execute

#check X86AluXorShortcutDwordCall.execute
#print axioms X86AluXorShortcutDwordCall.execute

#check X86AluXorShortcutDwordNative.execute
#print axioms X86AluXorShortcutDwordNative.execute

#check X86AluXorDwordAll.execute
#print axioms X86AluXorDwordAll.execute

