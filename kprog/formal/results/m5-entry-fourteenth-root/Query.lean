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

#check Arm64ProgramEntryResultPrefix.entry_corresponds
#print axioms Arm64ProgramEntryResultPrefix.entry_corresponds

#check Arm64ProgramEntryResultRead.both
#print axioms Arm64ProgramEntryResultRead.both

#check Arm64ProgramEntryResultVector.execute
#print axioms Arm64ProgramEntryResultVector.execute

#check Arm64ProgramEntryResultCondition.execute
#print axioms Arm64ProgramEntryResultCondition.execute

#check Arm64ProgramEntryResultCondition.invoke
#print axioms Arm64ProgramEntryResultCondition.invoke

#check Arm64ProgramEntryResultCondition.call_step
#print axioms Arm64ProgramEntryResultCondition.call_step

#check Arm64ProgramEntryResultCondition.remainder_cast
#print axioms Arm64ProgramEntryResultCondition.remainder_cast

#check Arm64ConditionAll.internal
#print axioms Arm64ConditionAll.internal

#check Arm64ConditionAll.from_storage
#print axioms Arm64ConditionAll.from_storage

#check X86RegisterTagCall.execute
#print axioms X86RegisterTagCall.execute

#check X86QwordSelection.source
#print axioms X86QwordSelection.source

#check X86QwordSelection.enter
#print axioms X86QwordSelection.enter

#check X86QwordTagStage.first
#print axioms X86QwordTagStage.first

#check X86QwordDestination.source
#print axioms X86QwordDestination.source

#check X86QwordDestination.enter
#print axioms X86QwordDestination.enter

#check X86QwordDestinationScalar.finish
#print axioms X86QwordDestinationScalar.finish

#check X86QwordDestinationScalar.execute
#print axioms X86QwordDestinationScalar.execute

#check X86RegisterTagSite.execute
#print axioms X86RegisterTagSite.execute

#check X86QwordDestination.call_source
#print axioms X86QwordDestination.call_source

#check X86QwordDestination.prepare
#print axioms X86QwordDestination.prepare

#check X86QwordSource.source
#print axioms X86QwordSource.source

#check X86QwordSource.execute
#print axioms X86QwordSource.execute

#check X86QwordWriterSelectors.destination_get
#print axioms X86QwordWriterSelectors.destination_get

#check X86QwordWriterSelectors.get
#print axioms X86QwordWriterSelectors.get

#check X86QwordWriterSelectors.execute
#print axioms X86QwordWriterSelectors.execute

#check X86QwordWriteback.execute
#print axioms X86QwordWriteback.execute

#check X86QwordAllocated.execute
#print axioms X86QwordAllocated.execute

#check X86LogicQwordTail.source_shift
#print axioms X86LogicQwordTail.source_shift

#check X86LogicQwordTail.execute
#print axioms X86LogicQwordTail.execute

#check X86AluXorInputs.source_shift
#print axioms X86AluXorInputs.source_shift

#check X86AluXorShortcutInputs.source_shift
#print axioms X86AluXorShortcutInputs.source_shift

#check X86AluXorQwordCall.execute
#print axioms X86AluXorQwordCall.execute

#check X86LogicQwordOperands.scalar
#print axioms X86LogicQwordOperands.scalar

#check X86LogicQwordOperands.xor_step
#print axioms X86LogicQwordOperands.xor_step

#check X86AluXorShortcutQwordCall.execute
#print axioms X86AluXorShortcutQwordCall.execute

#check X86AluXorQwordNative.execute
#print axioms X86AluXorQwordNative.execute

#check X86AluXorShortcutQwordNative.execute
#print axioms X86AluXorShortcutQwordNative.execute

#check X86AluXorQwordAll.execute
#print axioms X86AluXorQwordAll.execute


#check X86WordMemory.load
#print axioms X86WordMemory.load

#check X86WordMemory.native
#print axioms X86WordMemory.native

#check X86WordMemory.readback
#print axioms X86WordMemory.readback

#check X86WordStorage.select
#print axioms X86WordStorage.select

#check X86WordStorage.enter
#print axioms X86WordStorage.enter

#check X86WordStorage.store
#print axioms X86WordStorage.store

#check X86WordStorage.exit
#print axioms X86WordStorage.exit

#check X86WordStorage.run
#print axioms X86WordStorage.run

#check X86WordStorage.execute
#print axioms X86WordStorage.execute

#check X86WordTable.writable
#print axioms X86WordTable.writable

#check X86WordWriteback.table
#print axioms X86WordWriteback.table

#check X86WordWriteback.from_storage
#print axioms X86WordWriteback.from_storage

#check X86WordWriter.execute
#print axioms X86WordWriter.execute

#check X86WordAllocated.execute
#print axioms X86WordAllocated.execute

#check X86LogicWordTail.execute
#print axioms X86LogicWordTail.execute

#check X86AluXorWordCall.execute
#print axioms X86AluXorWordCall.execute

#check X86LogicWordOperands.scalar
#print axioms X86LogicWordOperands.scalar

#check X86LogicWordOperands.xor_step
#print axioms X86LogicWordOperands.xor_step

#check X86AluXorWordNative.execute
#print axioms X86AluXorWordNative.execute

#check X86AluXorShortcutWordCall.execute
#print axioms X86AluXorShortcutWordCall.execute

#check X86AluXorShortcutWordNative.execute
#print axioms X86AluXorShortcutWordNative.execute

#check X86AluXorWordAll.execute
#print axioms X86AluXorWordAll.execute

#check Arm64ProgramEntryRepeatMovNative.pointer_control
#print axioms Arm64ProgramEntryRepeatMovNative.pointer_control
#check Arm64ProgramEntryRepeatMovNative.execute
#print axioms Arm64ProgramEntryRepeatMovNative.execute
#check Arm64ProgramEntryRepeatMovAdmission.admission
#print axioms Arm64ProgramEntryRepeatMovAdmission.admission
#check Arm64MovImmediate.OrdinaryCall.corresponds
#print axioms Arm64MovImmediate.OrdinaryCall.corresponds
#check Arm64ProgramEntryOrdinaryMoveNative.first
#print axioms Arm64ProgramEntryOrdinaryMoveNative.first
#check Arm64ProgramEntryOrdinaryMoveNative.constant
#print axioms Arm64ProgramEntryOrdinaryMoveNative.constant
#check Arm64ProgramEntryOrdinaryMovePath.first
#print axioms Arm64ProgramEntryOrdinaryMovePath.first
#check Arm64ProgramEntryOrdinaryMovePath.constant
#print axioms Arm64ProgramEntryOrdinaryMovePath.constant
#check Arm64ProgramEntryPointerWrites.execute
#print axioms Arm64ProgramEntryPointerWrites.execute

#check X86AluNonXorOperandsEntry.from_call
#print axioms X86AluNonXorOperandsEntry.from_call
#check X86AluLogicResultEntry.from_call
#print axioms X86AluLogicResultEntry.from_call
#check X86AluLogicInputs.observations
#print axioms X86AluLogicInputs.observations
#check X86AluLogicInputs.source_shift
#print axioms X86AluLogicInputs.source_shift
#check X86AluLogicInputs.entry
#print axioms X86AluLogicInputs.entry
#check X86RegisterReadRsp.base_offset
#print axioms X86RegisterReadRsp.base_offset
#check X86RegisterReadRsp.materialize_rsp
#print axioms X86RegisterReadRsp.materialize_rsp
#check X86AluLogicByteCall.execute
#print axioms X86AluLogicByteCall.execute
#check X86LogicByteReference.step
#print axioms X86LogicByteReference.step
#check X86AluLogicByteNative.execute
#print axioms X86AluLogicByteNative.execute
#check X86AluLogicWordCall.execute
#print axioms X86AluLogicWordCall.execute
#check X86LogicWordReference.step
#print axioms X86LogicWordReference.step
#check X86AluLogicWordNative.execute
#print axioms X86AluLogicWordNative.execute
#check X86AluLogicDwordCall.execute
#print axioms X86AluLogicDwordCall.execute
#check X86LogicDwordReference.step
#print axioms X86LogicDwordReference.step
#check X86AluLogicDwordNative.execute
#print axioms X86AluLogicDwordNative.execute
#check X86AluLogicQwordCall.execute
#print axioms X86AluLogicQwordCall.execute
#check X86LogicQwordReference.step
#print axioms X86LogicQwordReference.step
#check X86AluLogicQwordNative.execute
#print axioms X86AluLogicQwordNative.execute

#check Arm64ProgramEntryRepeatMovAdmission.next_admission
#print axioms Arm64ProgramEntryRepeatMovAdmission.next_admission
#check Arm64ProgramEntryConstantMovNative.execute
#print axioms Arm64ProgramEntryConstantMovNative.execute
