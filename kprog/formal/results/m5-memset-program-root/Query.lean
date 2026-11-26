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

#check X86AluNativeLogicByteCall.execute
#print axioms X86AluNativeLogicByteCall.execute
#check X86AluNativeLogicByteNative.execute
#print axioms X86AluNativeLogicByteNative.execute
#check X86AluNativeLogicDwordCall.execute
#print axioms X86AluNativeLogicDwordCall.execute
#check X86AluNativeLogicDwordNative.execute
#print axioms X86AluNativeLogicDwordNative.execute
#check X86AluNativeLogicEntry.from_call
#print axioms X86AluNativeLogicEntry.from_call
#check X86AluNativeLogicInputs.observations
#print axioms X86AluNativeLogicInputs.observations
#check X86AluNativeLogicInputs.source_shift
#print axioms X86AluNativeLogicInputs.source_shift
#check X86AluNativeLogicInputs.entry
#print axioms X86AluNativeLogicInputs.entry
#check X86AluNativeLogicQwordCall.execute
#print axioms X86AluNativeLogicQwordCall.execute
#check X86AluNativeLogicQwordNative.execute
#print axioms X86AluNativeLogicQwordNative.execute
#check X86AluNativeLogicWordCall.execute
#print axioms X86AluNativeLogicWordCall.execute
#check X86AluNativeLogicWordNative.execute
#print axioms X86AluNativeLogicWordNative.execute
#check X86AluNativeOperandsEntry.from_call
#print axioms X86AluNativeOperandsEntry.from_call
#check X86AluReadNativeOperands.read
#print axioms X86AluReadNativeOperands.read
#check X86AluReadNativeOperands.observations
#print axioms X86AluReadNativeOperands.observations
#check X86AluReadNativeTail.read
#print axioms X86AluReadNativeTail.read
#check X86RegisterReadNumeric.call
#print axioms X86RegisterReadNumeric.call
#check X86RegisterReadRspCall.call
#print axioms X86RegisterReadRspCall.call
#check X86RegisterReadRspNative.native_word
#print axioms X86RegisterReadRspNative.native_word
#check X86RegisterReadRspNative.call
#print axioms X86RegisterReadRspNative.call

#check X86RegisterWriteRspPrefix.execute
#print axioms X86RegisterWriteRspPrefix.execute
#check X86RegisterWriteRsp.run
#print axioms X86RegisterWriteRsp.run
#check X86RegisterWriteRspStorage.execute
#print axioms X86RegisterWriteRspStorage.execute
#check X86RegisterWriteRspTable.native
#print axioms X86RegisterWriteRspTable.native
#check X86RegisterWriteRspTable.writable
#print axioms X86RegisterWriteRspTable.writable
#check X86RegisterWriteRspWritable.execute
#print axioms X86RegisterWriteRspWritable.execute

#check X86RegisterWriteRspByte.source
#print axioms X86RegisterWriteRspByte.source
#check X86RegisterWriteRspByte.run
#print axioms X86RegisterWriteRspByte.run
#check X86RegisterWriteRspWord.source
#print axioms X86RegisterWriteRspWord.source
#check X86RegisterWriteRspWord.run
#print axioms X86RegisterWriteRspWord.run
#check X86RegisterWriteRspPartial.execute
#print axioms X86RegisterWriteRspPartial.execute

#check X86RegisterWriteRspRelease.unchanged
#print axioms X86RegisterWriteRspRelease.unchanged

#check X86RegisterWriteRspPrefix.execute_readback
#print axioms X86RegisterWriteRspPrefix.execute_readback
#check X86RegisterWriteRspStorage.execute_readback
#print axioms X86RegisterWriteRspStorage.execute_readback
#check X86RegisterWriteRspStable.execute
#print axioms X86RegisterWriteRspStable.execute

#check X86QwordRspSelectors.execute
#print axioms X86QwordRspSelectors.execute
#check X86FullWidthRspWriteback.from_storage
#print axioms X86FullWidthRspWriteback.from_storage
#check X86QwordRspWriteback.execute
#print axioms X86QwordRspWriteback.execute
#check X86QwordRspAllocated.execute
#print axioms X86QwordRspAllocated.execute

#check X86LogicQwordRspTail.execute
#print axioms X86LogicQwordRspTail.execute
#check X86AluLogicRspQwordCall.execute
#print axioms X86AluLogicRspQwordCall.execute
#check X86AluLogicRspQwordNative.execute
#print axioms X86AluLogicRspQwordNative.execute

#check X86DwordRspWriteback.execute
#print axioms X86DwordRspWriteback.execute
#check X86DwordRspWriteback.allocated
#print axioms X86DwordRspWriteback.allocated
#check X86LogicDwordRspTail.execute
#print axioms X86LogicDwordRspTail.execute
#check X86AluLogicRspDwordCall.execute
#print axioms X86AluLogicRspDwordCall.execute
#check X86AluLogicRspDwordNative.execute
#print axioms X86AluLogicRspDwordNative.execute

#check X86RegisterWriteRspScalarSuffix.source
#print axioms X86RegisterWriteRspScalarSuffix.source
#check X86RegisterWriteRspScalarSuffix.enter
#print axioms X86RegisterWriteRspScalarSuffix.enter
#check X86RegisterWriteRspScalarSuffix.run
#print axioms X86RegisterWriteRspScalarSuffix.run
#check X86RegisterWriteRspPartialStore.execute
#print axioms X86RegisterWriteRspPartialStore.execute
#check X86RegisterWriteRspPartialWriteback.from_leaf
#print axioms X86RegisterWriteRspPartialWriteback.from_leaf

#check X86PartialRspWriteback.execute
#print axioms X86PartialRspWriteback.execute

#check X86PartialRspAllocated.execute
#print axioms X86PartialRspAllocated.execute

#check X86LogicPartialRspTail.execute
#print axioms X86LogicPartialRspTail.execute

#check X86AluLogicRspPartialCall.execute
#print axioms X86AluLogicRspPartialCall.execute

#check X86AluLogicRspPartialNative.execute
#print axioms X86AluLogicRspPartialNative.execute

#check X86AluReadNativeXorOperands.read
#print axioms X86AluReadNativeXorOperands.read

#check X86AluNativeXorOperandsEntry.from_call
#print axioms X86AluNativeXorOperandsEntry.from_call

#check X86AluNativeXorResultEntry.from_call
#print axioms X86AluNativeXorResultEntry.from_call

#check X86AluNativeXorInputs.observations
#print axioms X86AluNativeXorInputs.observations

#check X86AluNativeXorInputs.source_shift
#print axioms X86AluNativeXorInputs.source_shift

#check X86AluNativeXorInputs.entry
#print axioms X86AluNativeXorInputs.entry

#check X86AluXorRspPartialCall.execute
#print axioms X86AluXorRspPartialCall.execute

#check X86AluXorRspDwordCall.execute
#print axioms X86AluXorRspDwordCall.execute

#check X86AluXorRspQwordCall.execute
#print axioms X86AluXorRspQwordCall.execute

#check X86AluXorRspPartialNative.execute
#print axioms X86AluXorRspPartialNative.execute

#check X86AluXorRspDwordNative.execute
#print axioms X86AluXorRspDwordNative.execute

#check X86AluXorRspQwordNative.execute
#print axioms X86AluXorRspQwordNative.execute

#check X86AluXorShortcutRspPartialCall.execute
#print axioms X86AluXorShortcutRspPartialCall.execute

#check X86AluXorShortcutRspDwordCall.execute
#print axioms X86AluXorShortcutRspDwordCall.execute

#check X86AluXorShortcutRspQwordCall.execute
#print axioms X86AluXorShortcutRspQwordCall.execute

#check X86AluXorShortcutRspPartialNative.execute
#print axioms X86AluXorShortcutRspPartialNative.execute

#check X86AluXorShortcutRspDwordNative.execute
#print axioms X86AluXorShortcutRspDwordNative.execute

#check X86AluXorShortcutRspQwordNative.execute
#print axioms X86AluXorShortcutRspQwordNative.execute

#check X86AluXorRspPartialAll.execute
#print axioms X86AluXorRspPartialAll.execute

#check X86AluXorRspDwordAll.execute
#print axioms X86AluXorRspDwordAll.execute

#check X86AluXorRspQwordAll.execute
#print axioms X86AluXorRspQwordAll.execute

#check X86AluNativeXorByteCall.execute
#print axioms X86AluNativeXorByteCall.execute

#check X86AluNativeXorByteNative.execute
#print axioms X86AluNativeXorByteNative.execute

#check X86AluNativeXorByteAll.execute
#print axioms X86AluNativeXorByteAll.execute

#check X86AluNativeXorWordCall.execute
#print axioms X86AluNativeXorWordCall.execute

#check X86AluNativeXorWordNative.execute
#print axioms X86AluNativeXorWordNative.execute

#check X86AluNativeXorWordAll.execute
#print axioms X86AluNativeXorWordAll.execute

#check X86AluNativeXorDwordCall.execute
#print axioms X86AluNativeXorDwordCall.execute

#check X86AluNativeXorDwordNative.execute
#print axioms X86AluNativeXorDwordNative.execute

#check X86AluNativeXorDwordAll.execute
#print axioms X86AluNativeXorDwordAll.execute

#check X86AluNativeXorQwordCall.execute
#print axioms X86AluNativeXorQwordCall.execute

#check X86AluNativeXorQwordNative.execute
#print axioms X86AluNativeXorQwordNative.execute

#check X86AluNativeXorQwordAll.execute
#print axioms X86AluNativeXorQwordAll.execute

#check X86RegisterWriteRspRelease.increasing_enter
#print axioms X86RegisterWriteRspRelease.increasing_enter

#check X86RegisterWriteRspReleaseLoop.source
#print axioms X86RegisterWriteRspReleaseLoop.source

#check X86RegisterWriteRspReleaseLoop.enter
#print axioms X86RegisterWriteRspReleaseLoop.enter

#check X86RegisterWriteRspReleaseLoop.from_table
#print axioms X86RegisterWriteRspReleaseLoop.from_table

#check X86RegisterWriteRspReleaseSelect.source
#print axioms X86RegisterWriteRspReleaseSelect.source

#check X86RegisterWriteRspReleaseSelect.choose
#print axioms X86RegisterWriteRspReleaseSelect.choose

#check X86RegisterWriteRspReleaseSelect.from_table
#print axioms X86RegisterWriteRspReleaseSelect.from_table

#check X86NopCall.entry
#print axioms X86NopCall.entry

#check X86NopCall.execute
#print axioms X86NopCall.execute

#check X86NopReference.flags_roundtrip
#print axioms X86NopReference.flags_roundtrip

#check X86NopReference.step
#print axioms X86NopReference.step

#check X86NopNative.execute
#print axioms X86NopNative.execute


#check X86RegisterWriteRspReleaseWord.layout_source
#print axioms X86RegisterWriteRspReleaseWord.layout_source

#check X86RegisterWriteRspReleaseWord.enter
#print axioms X86RegisterWriteRspReleaseWord.enter

#check X86RegisterWriteRspReleaseWord.returned
#print axioms X86RegisterWriteRspReleaseWord.returned

#check X86RegisterWriteRspReleaseWord.execute
#print axioms X86RegisterWriteRspReleaseWord.execute

#check X86RegisterWriteRspReleaseWord.selected
#print axioms X86RegisterWriteRspReleaseWord.selected


#check X86RegisterWriteRspReleaseByteLoop.source
#print axioms X86RegisterWriteRspReleaseByteLoop.source

#check X86RegisterWriteRspReleaseByteLoop.enter
#print axioms X86RegisterWriteRspReleaseByteLoop.enter

#check X86RegisterWriteRspReleaseByteLoop.choose
#print axioms X86RegisterWriteRspReleaseByteLoop.choose

#check X86RegisterWriteRspReleaseByteLoop.advance
#print axioms X86RegisterWriteRspReleaseByteLoop.advance

#check X86RegisterWriteRspReleaseByteLoop.exit
#print axioms X86RegisterWriteRspReleaseByteLoop.exit

#check X86RegisterWriteRspReleaseByteLoop.fallback
#print axioms X86RegisterWriteRspReleaseByteLoop.fallback

#check X86RegisterWriteRspReleaseByteCall.byte_cast
#print axioms X86RegisterWriteRspReleaseByteCall.byte_cast

#check X86RegisterWriteRspReleaseByteCall.enter
#print axioms X86RegisterWriteRspReleaseByteCall.enter

#check X86RegisterWriteRspReleaseByteCall.returned
#print axioms X86RegisterWriteRspReleaseByteCall.returned

#check X86RegisterWriteRspReleaseByteCall.execute
#print axioms X86RegisterWriteRspReleaseByteCall.execute

#check X86RegisterWriteRspReleaseByteCall.selected
#print axioms X86RegisterWriteRspReleaseByteCall.selected

#check X86RegisterWriteRspReleaseByteCall.skipped
#print axioms X86RegisterWriteRspReleaseByteCall.skipped

#check X86RegisterWriteRspReleaseAdvance.source
#print axioms X86RegisterWriteRspReleaseAdvance.source

#check X86RegisterWriteRspReleaseAdvance.advance
#print axioms X86RegisterWriteRspReleaseAdvance.advance

#check X86RegisterWriteRspReleaseAdvance.prepare
#print axioms X86RegisterWriteRspReleaseAdvance.prepare

#check X86RegisterWriteRspReleaseAdvance.next_iteration
#print axioms X86RegisterWriteRspReleaseAdvance.next_iteration

#check X86RegisterWriteRspReleaseAdvance.exit
#print axioms X86RegisterWriteRspReleaseAdvance.exit

#check X86RegisterWriteRspReleaseAdvance.frame_source
#print axioms X86RegisterWriteRspReleaseAdvance.frame_source

#check X86RegisterWriteRspReleaseAdvance.after_last
#print axioms X86RegisterWriteRspReleaseAdvance.after_last

#check X86CallFrameEntry.source
#print axioms X86CallFrameEntry.source

#check X86CallFrameEntry.entry
#print axioms X86CallFrameEntry.entry

#check X86CallFrameEntry.prefix_run
#print axioms X86CallFrameEntry.prefix_run

#check X86CallFrameEntry.call
#print axioms X86CallFrameEntry.call

#check X86CallFrameEntry.from_site
#print axioms X86CallFrameEntry.from_site

#check X86CallFrameEntry.from_last
#print axioms X86CallFrameEntry.from_last


#check X86CallFrameStages.source
#print axioms X86CallFrameStages.source

#check X86CallFrameStages.choose
#print axioms X86CallFrameStages.choose

#check X86CallFrameStages.finish
#print axioms X86CallFrameStages.finish

#check X86CallFrameStages.skipped
#print axioms X86CallFrameStages.skipped

#check X86CallFrameClear.source
#print axioms X86CallFrameClear.source

#check X86CallFrameClear.header_offset
#print axioms X86CallFrameClear.header_offset

#check X86CallFrameClear.execute
#print axioms X86CallFrameClear.execute

#check X86CallFrameClear.stable_temps
#print axioms X86CallFrameClear.stable_temps

#check X86CallFrameClear.selected
#print axioms X86CallFrameClear.selected

#check X86CallFrameComplete.body
#print axioms X86CallFrameComplete.body

#check X86CallFrameComplete.call
#print axioms X86CallFrameComplete.call

#check X86CallFrameComplete.from_site
#print axioms X86CallFrameComplete.from_site

#check X86CallFrameComplete.after_last
#print axioms X86CallFrameComplete.after_last


#check X86ReleaseProvider.access_rights
#print axioms X86ReleaseProvider.access_rights
#check X86ReleaseProvider.outcome_view
#print axioms X86ReleaseProvider.outcome_view
#check X86ReleaseProvider.view_transport
#print axioms X86ReleaseProvider.view_transport
#check X86ReleaseProvider.core_byte
#print axioms X86ReleaseProvider.core_byte
#check X86ReleaseProvider.core_control
#print axioms X86ReleaseProvider.core_control
#check X86ReleaseProvider.core_lane
#print axioms X86ReleaseProvider.core_lane
#check X86ReleaseProvider.core_word
#print axioms X86ReleaseProvider.core_word
#check X86ReleaseByteComplete.execute
#print axioms X86ReleaseByteComplete.execute
#check X86ReleaseOuterComplete.from_first
#print axioms X86ReleaseOuterComplete.from_first
#check X86ReleaseOuterComplete.execute
#print axioms X86ReleaseOuterComplete.execute
#check X86ReleaseOuterComplete.from_table
#print axioms X86ReleaseOuterComplete.from_table
#check X86ReleaseOuterComplete.all_offsets
#print axioms X86ReleaseOuterComplete.all_offsets
#check X86ReleaseReturn.registers
#print axioms X86ReleaseReturn.registers
#check X86ReleaseReturn.preserve_flags
#print axioms X86ReleaseReturn.preserve_flags
#check X86ReleaseReturn.execute
#print axioms X86ReleaseReturn.execute
#check X86ReleaseReturn.from_load
#print axioms X86ReleaseReturn.from_load
#check X86ReleaseStorageReturn.execute
#print axioms X86ReleaseStorageReturn.execute

#check X86FullWidthReleaseReturn.execute
#print axioms X86FullWidthReleaseReturn.execute
#check X86QwordRspSetup.to_storage
#print axioms X86QwordRspSetup.to_storage
#check X86QwordReleaseReturn.execute
#print axioms X86QwordReleaseReturn.execute

#check X86NopDispatch.handler_source
#print axioms X86NopDispatch.handler_source
#check X86NopDispatch.source
#print axioms X86NopDispatch.source
#check X86NopDispatch.execute
#print axioms X86NopDispatch.execute
#check X86NopDispatch.refines
#print axioms X86NopDispatch.refines

#check X86LogicQwordReleaseTail.execute
#print axioms X86LogicQwordReleaseTail.execute
#check X86AluLogicQwordReleaseCall.execute
#print axioms X86AluLogicQwordReleaseCall.execute
#check X86AluLogicQwordReleaseNative.execute
#print axioms X86AluLogicQwordReleaseNative.execute
#check X86AluXorQwordReleaseCall.execute
#print axioms X86AluXorQwordReleaseCall.execute
#check X86AluXorShortcutQwordReleaseCall.execute
#print axioms X86AluXorShortcutQwordReleaseCall.execute
#check X86AluXorQwordReleaseNative.execute
#print axioms X86AluXorQwordReleaseNative.execute
#check X86AluXorShortcutQwordReleaseNative.execute
#print axioms X86AluXorShortcutQwordReleaseNative.execute
#check X86AluXorQwordReleaseAll.execute
#print axioms X86AluXorQwordReleaseAll.execute

#check X86DwordRspSetup.to_storage
#print axioms X86DwordRspSetup.to_storage
#check X86DwordReleaseReturn.execute
#print axioms X86DwordReleaseReturn.execute
#check X86LogicDwordReleaseTail.execute
#print axioms X86LogicDwordReleaseTail.execute
#check X86AluLogicDwordReleaseCall.execute
#print axioms X86AluLogicDwordReleaseCall.execute
#check X86AluXorDwordReleaseCall.execute
#print axioms X86AluXorDwordReleaseCall.execute
#check X86AluXorShortcutDwordReleaseCall.execute
#print axioms X86AluXorShortcutDwordReleaseCall.execute
#check X86AluLogicDwordReleaseNative.execute
#print axioms X86AluLogicDwordReleaseNative.execute
#check X86AluXorDwordReleaseNative.execute
#print axioms X86AluXorDwordReleaseNative.execute
#check X86AluXorShortcutDwordReleaseNative.execute
#print axioms X86AluXorShortcutDwordReleaseNative.execute
#check X86AluXorDwordReleaseAll.execute
#print axioms X86AluXorDwordReleaseAll.execute

#check X86PartialRspSetup.to_leaf
#print axioms X86PartialRspSetup.to_leaf

#check X86PartialLeafReleaseReturn.execute
#print axioms X86PartialLeafReleaseReturn.execute

#check X86PartialReleaseReturn.execute
#print axioms X86PartialReleaseReturn.execute

#check X86LogicPartialReleaseTail.execute
#print axioms X86LogicPartialReleaseTail.execute

#check X86AluLogicPartialReleaseCall.execute
#print axioms X86AluLogicPartialReleaseCall.execute

#check X86AluXorPartialReleaseCall.execute
#print axioms X86AluXorPartialReleaseCall.execute

#check X86AluXorShortcutPartialReleaseCall.execute
#print axioms X86AluXorShortcutPartialReleaseCall.execute

#check X86AluLogicPartialReleaseNative.execute
#print axioms X86AluLogicPartialReleaseNative.execute

#check X86AluXorPartialReleaseNative.execute
#print axioms X86AluXorPartialReleaseNative.execute

#check X86AluXorShortcutPartialReleaseNative.execute
#print axioms X86AluXorShortcutPartialReleaseNative.execute

#check X86AluXorPartialReleaseAll.execute
#print axioms X86AluXorPartialReleaseAll.execute

#check X86ReleaseByteCacheFrame.same_position
#print axioms X86ReleaseByteCacheFrame.same_position

#check X86ReleaseByteCacheFrame.released_distinct_address
#print axioms X86ReleaseByteCacheFrame.released_distinct_address

#check X86ReleaseByteCacheFrame.frame_trans
#print axioms X86ReleaseByteCacheFrame.frame_trans

#check X86ReleaseByteCacheFrame.selected
#print axioms X86ReleaseByteCacheFrame.selected

#check X86ReleaseByteCompleteFrame.execute
#print axioms X86ReleaseByteCompleteFrame.execute


#check X86ReleaseWordCacheFrame.whole_disjoint
#print axioms X86ReleaseWordCacheFrame.whole_disjoint

#check X86ReleaseWordCacheFrame.store_frame
#print axioms X86ReleaseWordCacheFrame.store_frame

#check X86ReleaseWordCacheFrame.selected
#print axioms X86ReleaseWordCacheFrame.selected

#check X86ReleaseOuterCacheFrame.from_first
#print axioms X86ReleaseOuterCacheFrame.from_first

#check X86ReleaseOuterCacheFrame.execute
#print axioms X86ReleaseOuterCacheFrame.execute

#check X86ReleaseOuterCacheFrame.from_table
#print axioms X86ReleaseOuterCacheFrame.from_table

#check X86ReleaseOuterCacheFrame.all_offsets
#print axioms X86ReleaseOuterCacheFrame.all_offsets

#check X86ReleaseReturnCacheFrame.execute
#print axioms X86ReleaseReturnCacheFrame.execute

#check X86ReleaseReturnCacheFrame.from_load
#print axioms X86ReleaseReturnCacheFrame.from_load

#check X86ReleaseStorageCacheFrame.execute
#print axioms X86ReleaseStorageCacheFrame.execute


#check X86FullWidthReleaseCacheFrame.execute
#print axioms X86FullWidthReleaseCacheFrame.execute

#check X86PartialLeafCacheFrame.execute
#print axioms X86PartialLeafCacheFrame.execute

#check X86QwordReleaseCacheFrame.execute
#print axioms X86QwordReleaseCacheFrame.execute

#check X86DwordReleaseCacheFrame.execute
#print axioms X86DwordReleaseCacheFrame.execute

#check X86PartialReleaseCacheFrame.execute
#print axioms X86PartialReleaseCacheFrame.execute

#check X86LogicQwordCacheTail.execute
#print axioms X86LogicQwordCacheTail.execute

#check X86LogicDwordCacheTail.execute
#print axioms X86LogicDwordCacheTail.execute

#check X86LogicPartialCacheTail.execute
#print axioms X86LogicPartialCacheTail.execute

#check X86AluLogicQwordCacheCall.execute
#print axioms X86AluLogicQwordCacheCall.execute

#check X86AluXorQwordCacheCall.execute
#print axioms X86AluXorQwordCacheCall.execute

#check X86AluXorShortcutQwordCacheCall.execute
#print axioms X86AluXorShortcutQwordCacheCall.execute

#check X86AluLogicDwordCacheCall.execute
#print axioms X86AluLogicDwordCacheCall.execute

#check X86AluXorDwordCacheCall.execute
#print axioms X86AluXorDwordCacheCall.execute

#check X86AluXorShortcutDwordCacheCall.execute
#print axioms X86AluXorShortcutDwordCacheCall.execute

#check X86AluLogicPartialCacheCall.execute
#print axioms X86AluLogicPartialCacheCall.execute

#check X86AluXorPartialCacheCall.execute
#print axioms X86AluXorPartialCacheCall.execute

#check X86AluXorShortcutPartialCacheCall.execute
#print axioms X86AluXorShortcutPartialCacheCall.execute


#check X86ProducerCacheAllocation.owned
#print axioms X86ProducerCacheAllocation.owned

#check X86ProducerHeaderSource.source_prefix
#print axioms X86ProducerHeaderSource.source_prefix

#check X86ProducerHeaderSource.source_header
#print axioms X86ProducerHeaderSource.source_header

#check X86ProducerHeaderProgramSource.program_source
#print axioms X86ProducerHeaderProgramSource.program_source

#check X86ProducerHeaderLocals.header_local
#print axioms X86ProducerHeaderLocals.header_local

#check X86ProducerHeaderLocals.source_local
#print axioms X86ProducerHeaderLocals.source_local

#check X86ProducerHeaderLocals.source_separate
#print axioms X86ProducerHeaderLocals.source_separate

#check X86ProducerHeaderAddress.direct_offset
#print axioms X86ProducerHeaderAddress.direct_offset

#check X86ProducerHeaderAddress.values_offset
#print axioms X86ProducerHeaderAddress.values_offset

#check X86ProducerHeaderAddress.ghost_offset
#print axioms X86ProducerHeaderAddress.ghost_offset

#check X86ProducerHeaderRhs.rhs_pointer
#print axioms X86ProducerHeaderRhs.rhs_pointer

#check X86ProducerHeaderRhs.cast_pointer
#print axioms X86ProducerHeaderRhs.cast_pointer

#check X86ProducerHeaderTarget.target_address
#print axioms X86ProducerHeaderTarget.target_address

#check X86ProducerHeaderStore.write
#print axioms X86ProducerHeaderStore.write

#check X86ProducerHeaderInitialize.header_initialized
#print axioms X86ProducerHeaderInitialize.header_initialized

#check X86ProducerHeaderViews.initialized_views
#print axioms X86ProducerHeaderViews.initialized_views

#check KProgFormal.ClightRefinement.X86ProducerContextSource.source_context
#print axioms KProgFormal.ClightRefinement.X86ProducerContextSource.source_context
#check KProgFormal.ClightRefinement.X86ProducerContextSource.source_loop
#print axioms KProgFormal.ClightRefinement.X86ProducerContextSource.source_loop
#check KProgFormal.ClightRefinement.X86ProducerContextAddress.field_offset
#print axioms KProgFormal.ClightRefinement.X86ProducerContextAddress.field_offset
#check KProgFormal.ClightRefinement.X86ProducerContextAddress.target_address
#print axioms KProgFormal.ClightRefinement.X86ProducerContextAddress.target_address
#check KProgFormal.ClightRefinement.X86ProducerContextStore.rhs_value
#print axioms KProgFormal.ClightRefinement.X86ProducerContextStore.rhs_value
#check KProgFormal.ClightRefinement.X86ProducerContextStore.write
#print axioms KProgFormal.ClightRefinement.X86ProducerContextStore.write
#check KProgFormal.ClightRefinement.X86ProducerContextInitialize.context_initialized
#print axioms KProgFormal.ClightRefinement.X86ProducerContextInitialize.context_initialized
#check KProgFormal.ClightRefinement.X86ProducerBindLoop.source_call
#print axioms KProgFormal.ClightRefinement.X86ProducerBindLoop.source_call
#check KProgFormal.ClightRefinement.X86ProducerBindLoop.to_call
#print axioms KProgFormal.ClightRefinement.X86ProducerBindLoop.to_call
#check KProgFormal.ClightRefinement.X86ProducerHeaderComplete.to_first_call
#print axioms KProgFormal.ClightRefinement.X86ProducerHeaderComplete.to_first_call
#check KProgFormal.ClightRefinement.X86ProducerLayout.built
#print axioms KProgFormal.ClightRefinement.X86ProducerLayout.built
#check KProgFormal.ClightRefinement.X86ProducerLayout.layouts
#print axioms KProgFormal.ClightRefinement.X86ProducerLayout.layouts
#check KProgFormal.ClightRefinement.X86ProducerLayout.cells_offset
#print axioms KProgFormal.ClightRefinement.X86ProducerLayout.cells_offset
#check KProgFormal.ClightRefinement.X86ProducerLayout.registers_layout
#print axioms KProgFormal.ClightRefinement.X86ProducerLayout.registers_layout
#check KProgFormal.ClightRefinement.X86ProducerEntry.entry_valid
#print axioms KProgFormal.ClightRefinement.X86ProducerEntry.entry_valid
#check KProgFormal.ClightRefinement.X86ProducerEntry.entry_internal
#print axioms KProgFormal.ClightRefinement.X86ProducerEntry.entry_internal
#check KProgFormal.ClightRefinement.X86ProducerEntry.entry_frame
#print axioms KProgFormal.ClightRefinement.X86ProducerEntry.entry_frame
#check KProgFormal.ClightRefinement.X86ProducerHeaderBound.to_first_call
#print axioms KProgFormal.ClightRefinement.X86ProducerHeaderBound.to_first_call
#check KProgFormal.ClightRefinement.X86ProducerAbiSource.source_abi
#print axioms KProgFormal.ClightRefinement.X86ProducerAbiSource.source_abi
#check KProgFormal.ClightRefinement.X86ProducerAbiLayout.source_layout
#print axioms KProgFormal.ClightRefinement.X86ProducerAbiLayout.source_layout
#check KProgFormal.ClightRefinement.X86ProducerAbiLayout.field_offset
#print axioms KProgFormal.ClightRefinement.X86ProducerAbiLayout.field_offset
#check KProgFormal.ClightRefinement.X86ProducerAbiLayout.abi_local
#print axioms KProgFormal.ClightRefinement.X86ProducerAbiLayout.abi_local
#check KProgFormal.ClightRefinement.X86ProducerAbiAddress.target_address
#print axioms KProgFormal.ClightRefinement.X86ProducerAbiAddress.target_address
#check KProgFormal.ClightRefinement.X86ProducerAbiStore.rhs_value
#print axioms KProgFormal.ClightRefinement.X86ProducerAbiStore.rhs_value
#check KProgFormal.ClightRefinement.X86ProducerAbiStore.write
#print axioms KProgFormal.ClightRefinement.X86ProducerAbiStore.write
#check KProgFormal.ClightRefinement.X86ProducerAbiInitialize.abi_initialized
#print axioms KProgFormal.ClightRefinement.X86ProducerAbiInitialize.abi_initialized
#check KProgFormal.ClightRefinement.X86ProducerAbiInitialize.from_call
#print axioms KProgFormal.ClightRefinement.X86ProducerAbiInitialize.from_call
#check KProgFormal.ClightRefinement.X86ProducerGhostSource.source_ghosts
#print axioms KProgFormal.ClightRefinement.X86ProducerGhostSource.source_ghosts
#check KProgFormal.ClightRefinement.X86ProducerGhostSource.to_ghosts
#print axioms KProgFormal.ClightRefinement.X86ProducerGhostSource.to_ghosts
#check KProgFormal.ClightRefinement.X86ProducerGhostSource.after_ghosts
#print axioms KProgFormal.ClightRefinement.X86ProducerGhostSource.after_ghosts
#check KProgFormal.ClightRefinement.X86ProducerGhostStore.local_bindings
#print axioms KProgFormal.ClightRefinement.X86ProducerGhostStore.local_bindings
#check KProgFormal.ClightRefinement.X86ProducerGhostStore.write
#print axioms KProgFormal.ClightRefinement.X86ProducerGhostStore.write
#check KProgFormal.ClightRefinement.X86ProducerGhostInitialize.ghosts_initialized
#print axioms KProgFormal.ClightRefinement.X86ProducerGhostInitialize.ghosts_initialized
#check KProgFormal.ClightRefinement.X86ProducerGhostInitialize.setup_initialized
#print axioms KProgFormal.ClightRefinement.X86ProducerGhostInitialize.setup_initialized
#check KProgFormal.ClightRefinement.X86ProducerInitialPrefix.context_inputs
#print axioms KProgFormal.ClightRefinement.X86ProducerInitialPrefix.context_inputs
#check KProgFormal.ClightRefinement.X86ProducerInitialPrefix.from_call
#print axioms KProgFormal.ClightRefinement.X86ProducerInitialPrefix.from_call
#check KProgFormal.ClightRefinement.X86ProducerFirstInput.input_binding
#print axioms KProgFormal.ClightRefinement.X86ProducerFirstInput.input_binding
#check KProgFormal.ClightRefinement.X86ProducerFirstInput.call_source
#print axioms KProgFormal.ClightRefinement.X86ProducerFirstInput.call_source
#check KProgFormal.ClightRefinement.X86ProducerFirstInput.enter
#print axioms KProgFormal.ClightRefinement.X86ProducerFirstInput.enter
#check KProgFormal.ClightRefinement.X86ProducerFirstInputPrefix.from_call
#print axioms KProgFormal.ClightRefinement.X86ProducerFirstInputPrefix.from_call

#check KProgFormal.ClightRefinement.X86ProducerInputReturn.source_continuation
#print axioms KProgFormal.ClightRefinement.X86ProducerInputReturn.source_continuation
#check KProgFormal.ClightRefinement.X86ProducerInputReturn.source_saved
#print axioms KProgFormal.ClightRefinement.X86ProducerInputReturn.source_saved
#check KProgFormal.ClightRefinement.X86ProducerInputReturn.to_destination
#print axioms KProgFormal.ClightRefinement.X86ProducerInputReturn.to_destination

#check KProgFormal.ClightRefinement.X86ProducerGprLayout.source_layouts
#print axioms KProgFormal.ClightRefinement.X86ProducerGprLayout.source_layouts
#check KProgFormal.ClightRefinement.X86ProducerGprLayout.field_offsets
#print axioms KProgFormal.ClightRefinement.X86ProducerGprLayout.field_offsets
#check KProgFormal.ClightRefinement.X86ProducerGprLayout.nested_offsets
#print axioms KProgFormal.ClightRefinement.X86ProducerGprLayout.nested_offsets

#check KProgFormal.ClightRefinement.X86ProducerGprAddress.pointer_address
#print axioms KProgFormal.ClightRefinement.X86ProducerGprAddress.pointer_address
#check KProgFormal.ClightRefinement.X86ProducerGprAddress.tag_address
#print axioms KProgFormal.ClightRefinement.X86ProducerGprAddress.tag_address
#check KProgFormal.ClightRefinement.X86ProducerGprAddress.source_destination
#print axioms KProgFormal.ClightRefinement.X86ProducerGprAddress.source_destination
#check KProgFormal.ClightRefinement.X86ProducerGprAddress.source_tag
#print axioms KProgFormal.ClightRefinement.X86ProducerGprAddress.source_tag

#check KProgFormal.ClightRefinement.X86ProducerGprStore.write
#print axioms KProgFormal.ClightRefinement.X86ProducerGprStore.write

#check KProgFormal.ClightRefinement.X86ProducerRaxReturn.returned
#print axioms KProgFormal.ClightRefinement.X86ProducerRaxReturn.returned
#check KProgFormal.ClightRefinement.X86ProducerRaxReturn.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerRaxReturn.execute

#check KProgFormal.ClightRefinement.X86ProducerRaxPrefix.from_call
#print axioms KProgFormal.ClightRefinement.X86ProducerRaxPrefix.from_call

#check KProgFormal.ClightRefinement.X86ProducerGprSites.source_route
#print axioms KProgFormal.ClightRefinement.X86ProducerGprSites.source_route
#check KProgFormal.ClightRefinement.X86ProducerGprSites.source_stores
#print axioms KProgFormal.ClightRefinement.X86ProducerGprSites.source_stores
#check KProgFormal.ClightRefinement.X86ProducerGprSites.source_call
#print axioms KProgFormal.ClightRefinement.X86ProducerGprSites.source_call
#check KProgFormal.ClightRefinement.X86ProducerGprSites.source_saved
#print axioms KProgFormal.ClightRefinement.X86ProducerGprSites.source_saved
#check KProgFormal.ClightRefinement.X86ProducerGprSites.source_first
#print axioms KProgFormal.ClightRefinement.X86ProducerGprSites.source_first

#check KProgFormal.ClightRefinement.X86ProducerGprEnter.enter
#print axioms KProgFormal.ClightRefinement.X86ProducerGprEnter.enter
#check KProgFormal.ClightRefinement.X86ProducerGprEnter.returned
#print axioms KProgFormal.ClightRefinement.X86ProducerGprEnter.returned
#check KProgFormal.ClightRefinement.X86ProducerGprEnter.rsp
#print axioms KProgFormal.ClightRefinement.X86ProducerGprEnter.rsp

#check KProgFormal.ClightRefinement.X86ProducerGprPair.written
#print axioms KProgFormal.ClightRefinement.X86ProducerGprPair.written

#check KProgFormal.ClightRefinement.X86ProducerGprExecute.ordinary
#print axioms KProgFormal.ClightRefinement.X86ProducerGprExecute.ordinary
#check KProgFormal.ClightRefinement.X86ProducerGprExecute.rsp
#print axioms KProgFormal.ClightRefinement.X86ProducerGprExecute.rsp

#check KProgFormal.ClightRefinement.X86ProducerGprStage.local_separate
#print axioms KProgFormal.ClightRefinement.X86ProducerGprStage.local_separate
#check KProgFormal.ClightRefinement.X86ProducerGprStage.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerGprStage.execute

#check KProgFormal.ClightRefinement.X86ProducerGprChain.cursor_at
#print axioms KProgFormal.ClightRefinement.X86ProducerGprChain.cursor_at
#check KProgFormal.ClightRefinement.X86ProducerGprChain.cursor_next
#print axioms KProgFormal.ClightRefinement.X86ProducerGprChain.cursor_next
#check KProgFormal.ClightRefinement.X86ProducerGprChain.initialized_prefix
#print axioms KProgFormal.ClightRefinement.X86ProducerGprChain.initialized_prefix
#check KProgFormal.ClightRefinement.X86ProducerGprChain.complete
#print axioms KProgFormal.ClightRefinement.X86ProducerGprChain.complete

#check KProgFormal.ClightRefinement.X86ProducerGprPrefix.from_call
#print axioms KProgFormal.ClightRefinement.X86ProducerGprPrefix.from_call


#check KProgFormal.ClightRefinement.X86ProducerScalarSource.source_begin
#print axioms KProgFormal.ClightRefinement.X86ProducerScalarSource.source_begin
#check KProgFormal.ClightRefinement.X86ProducerScalarSource.source_route
#print axioms KProgFormal.ClightRefinement.X86ProducerScalarSource.source_route
#check KProgFormal.ClightRefinement.X86ProducerScalarSource.source_call
#print axioms KProgFormal.ClightRefinement.X86ProducerScalarSource.source_call
#check KProgFormal.ClightRefinement.X86ProducerScalarSource.source_assignment
#print axioms KProgFormal.ClightRefinement.X86ProducerScalarSource.source_assignment
#check KProgFormal.ClightRefinement.X86ProducerScalarSource.cursor_at
#print axioms KProgFormal.ClightRefinement.X86ProducerScalarSource.cursor_at
#check KProgFormal.ClightRefinement.X86ProducerScalarSource.cursor_next
#print axioms KProgFormal.ClightRefinement.X86ProducerScalarSource.cursor_next

#check KProgFormal.ClightRefinement.X86ProducerScalarValue.evaluated
#print axioms KProgFormal.ClightRefinement.X86ProducerScalarValue.evaluated
#check KProgFormal.ClightRefinement.X86ProducerScalarValue.cast
#print axioms KProgFormal.ClightRefinement.X86ProducerScalarValue.cast

#check KProgFormal.ClightRefinement.X86ProducerScalarStore.write
#print axioms KProgFormal.ClightRefinement.X86ProducerScalarStore.write

#check KProgFormal.ClightRefinement.X86ProducerScalarExecute.initial_zero
#print axioms KProgFormal.ClightRefinement.X86ProducerScalarExecute.initial_zero
#check KProgFormal.ClightRefinement.X86ProducerScalarExecute.enter
#print axioms KProgFormal.ClightRefinement.X86ProducerScalarExecute.enter
#check KProgFormal.ClightRefinement.X86ProducerScalarExecute.returned
#print axioms KProgFormal.ClightRefinement.X86ProducerScalarExecute.returned
#check KProgFormal.ClightRefinement.X86ProducerScalarExecute.stored
#print axioms KProgFormal.ClightRefinement.X86ProducerScalarExecute.stored
#check KProgFormal.ClightRefinement.X86ProducerScalarExecute.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerScalarExecute.execute

#check KProgFormal.ClightRefinement.X86ProducerScalarStage.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerScalarStage.execute

#check KProgFormal.ClightRefinement.X86ProducerScalarChain.initialized_prefix
#print axioms KProgFormal.ClightRefinement.X86ProducerScalarChain.initialized_prefix
#check KProgFormal.ClightRefinement.X86ProducerScalarChain.complete
#print axioms KProgFormal.ClightRefinement.X86ProducerScalarChain.complete

#check KProgFormal.ClightRefinement.X86ProducerScalarInitialize.initialized
#print axioms KProgFormal.ClightRefinement.X86ProducerScalarInitialize.initialized

#check KProgFormal.ClightRefinement.X86ProducerScalarPrefix.from_call
#print axioms KProgFormal.ClightRefinement.X86ProducerScalarPrefix.from_call

#check KProgFormal.ClightRefinement.X86ProducerStackBaseSource.source_route
#print axioms KProgFormal.ClightRefinement.X86ProducerStackBaseSource.source_route
#check KProgFormal.ClightRefinement.X86ProducerStackBaseSource.source_zero
#print axioms KProgFormal.ClightRefinement.X86ProducerStackBaseSource.source_zero
#check KProgFormal.ClightRefinement.X86ProducerStackBaseSource.source_call
#print axioms KProgFormal.ClightRefinement.X86ProducerStackBaseSource.source_call
#check KProgFormal.ClightRefinement.X86ProducerStackBaseSource.source_assignment
#print axioms KProgFormal.ClightRefinement.X86ProducerStackBaseSource.source_assignment
#check KProgFormal.ClightRefinement.X86ProducerStackBaseSource.return_zero
#print axioms KProgFormal.ClightRefinement.X86ProducerStackBaseSource.return_zero
#check KProgFormal.ClightRefinement.X86ProducerStackBaseSource.enter
#print axioms KProgFormal.ClightRefinement.X86ProducerStackBaseSource.enter

#check KProgFormal.ClightRefinement.X86ProducerStackBaseReturn.returned
#print axioms KProgFormal.ClightRefinement.X86ProducerStackBaseReturn.returned
#check KProgFormal.ClightRefinement.X86ProducerStackBaseReturn.stored
#print axioms KProgFormal.ClightRefinement.X86ProducerStackBaseReturn.stored
#check KProgFormal.ClightRefinement.X86ProducerStackBaseReturn.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerStackBaseReturn.execute

#check KProgFormal.ClightRefinement.X86ProducerStackBasePrefix.from_call
#print axioms KProgFormal.ClightRefinement.X86ProducerStackBasePrefix.from_call


#check KProgFormal.ClightRefinement.X86ProducerContextSetup.source_setup
#print axioms KProgFormal.ClightRefinement.X86ProducerContextSetup.source_setup
#check KProgFormal.ClightRefinement.X86ProducerContextSetup.helpers
#print axioms KProgFormal.ClightRefinement.X86ProducerContextSetup.helpers
#check KProgFormal.ClightRefinement.X86ProducerContextSetup.write
#print axioms KProgFormal.ClightRefinement.X86ProducerContextSetup.write
#check KProgFormal.ClightRefinement.X86ProducerContextSetup.context_preserved
#print axioms KProgFormal.ClightRefinement.X86ProducerContextSetup.context_preserved
#check KProgFormal.ClightRefinement.X86ProducerContextSetup.initialized
#print axioms KProgFormal.ClightRefinement.X86ProducerContextSetup.initialized
#check KProgFormal.ClightRefinement.X86ProducerContextSetup.context_inputs
#print axioms KProgFormal.ClightRefinement.X86ProducerContextSetup.context_inputs
#check KProgFormal.ClightRefinement.X86ProducerContextSetup.to_first_call
#print axioms KProgFormal.ClightRefinement.X86ProducerContextSetup.to_first_call

#check KProgFormal.ClightRefinement.X86ProducerStackBaseProvider.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerStackBaseProvider.execute

#check KProgFormal.ClightRefinement.X86ProducerEntryReady.from_call
#print axioms KProgFormal.ClightRefinement.X86ProducerEntryReady.from_call


#check KProgFormal.ClightRefinement.X86ProducerPushCall.source_call
#print axioms KProgFormal.ClightRefinement.X86ProducerPushCall.source_call
#check KProgFormal.ClightRefinement.X86ProducerPushCall.handler_binding
#print axioms KProgFormal.ClightRefinement.X86ProducerPushCall.handler_binding
#check KProgFormal.ClightRefinement.X86ProducerPushCall.arguments
#print axioms KProgFormal.ClightRefinement.X86ProducerPushCall.arguments
#check KProgFormal.ClightRefinement.X86ProducerPushCall.call
#print axioms KProgFormal.ClightRefinement.X86ProducerPushCall.call
#check KProgFormal.ClightRefinement.X86ProducerPushCall.entry
#print axioms KProgFormal.ClightRefinement.X86ProducerPushCall.entry

#check KProgFormal.ClightRefinement.X86ProducerPushWidth.source
#print axioms KProgFormal.ClightRefinement.X86ProducerPushWidth.source
#check KProgFormal.ClightRefinement.X86ProducerPushWidth.width_source
#print axioms KProgFormal.ClightRefinement.X86ProducerPushWidth.width_source
#check KProgFormal.ClightRefinement.X86ProducerPushWidth.width_assignment
#print axioms KProgFormal.ClightRefinement.X86ProducerPushWidth.width_assignment
#check KProgFormal.ClightRefinement.X86ProducerPushWidth.width_binding
#print axioms KProgFormal.ClightRefinement.X86ProducerPushWidth.width_binding
#check KProgFormal.ClightRefinement.X86ProducerPushWidth.enter
#print axioms KProgFormal.ClightRefinement.X86ProducerPushWidth.enter
#check KProgFormal.ClightRefinement.X86ProducerPushWidth.resume
#print axioms KProgFormal.ClightRefinement.X86ProducerPushWidth.resume
#check KProgFormal.ClightRefinement.X86ProducerPushWidth.from_call
#print axioms KProgFormal.ClightRefinement.X86ProducerPushWidth.from_call
#check KProgFormal.ClightRefinement.X86ProducerPushWidth.unchanged
#print axioms KProgFormal.ClightRefinement.X86ProducerPushWidth.unchanged

#check KProgFormal.ClightRefinement.X86ProducerPushDispatch.target_source
#print axioms KProgFormal.ClightRefinement.X86ProducerPushDispatch.target_source
#check KProgFormal.ClightRefinement.X86ProducerPushDispatch.executes
#print axioms KProgFormal.ClightRefinement.X86ProducerPushDispatch.executes
#check KProgFormal.ClightRefinement.X86ProducerPushDispatch.arguments
#print axioms KProgFormal.ClightRefinement.X86ProducerPushDispatch.arguments
#check KProgFormal.ClightRefinement.X86ProducerPushDispatch.source_continuation
#print axioms KProgFormal.ClightRefinement.X86ProducerPushDispatch.source_continuation

#check KProgFormal.ClightRefinement.X86ProducerPushBody.handler_binding
#print axioms KProgFormal.ClightRefinement.X86ProducerPushBody.handler_binding
#check KProgFormal.ClightRefinement.X86ProducerPushBody.call
#print axioms KProgFormal.ClightRefinement.X86ProducerPushBody.call
#check KProgFormal.ClightRefinement.X86ProducerPushBody.allocation_valid
#print axioms KProgFormal.ClightRefinement.X86ProducerPushBody.allocation_valid
#check KProgFormal.ClightRefinement.X86ProducerPushBody.entry
#print axioms KProgFormal.ClightRefinement.X86ProducerPushBody.entry
#check KProgFormal.ClightRefinement.X86ProducerPushBody.entry_frame
#print axioms KProgFormal.ClightRefinement.X86ProducerPushBody.entry_frame
#check KProgFormal.ClightRefinement.X86ProducerPushBody.local_storage
#print axioms KProgFormal.ClightRefinement.X86ProducerPushBody.local_storage

#check KProgFormal.ClightRefinement.X86ProducerPushResources.same_local
#print axioms KProgFormal.ClightRefinement.X86ProducerPushResources.same_local
#check KProgFormal.ClightRefinement.X86ProducerPushResources.old_access
#print axioms KProgFormal.ClightRefinement.X86ProducerPushResources.old_access
#check KProgFormal.ClightRefinement.X86ProducerPushResources.views
#print axioms KProgFormal.ClightRefinement.X86ProducerPushResources.views
#check KProgFormal.ClightRefinement.X86ProducerPushResources.observations
#print axioms KProgFormal.ClightRefinement.X86ProducerPushResources.observations

#check KProgFormal.ClightRefinement.X86ProducerPushPrefix.from_ready
#print axioms KProgFormal.ClightRefinement.X86ProducerPushPrefix.from_ready
#check KProgFormal.ClightRefinement.X86ProducerPushPrefix.from_call
#print axioms KProgFormal.ClightRefinement.X86ProducerPushPrefix.from_call

#check KProgFormal.ClightRefinement.X86ProducerPushTemporaries.undefined_exact
#print axioms KProgFormal.ClightRefinement.X86ProducerPushTemporaries.undefined_exact
#check KProgFormal.ClightRefinement.X86ProducerPushTemporaries.cached_binds
#print axioms KProgFormal.ClightRefinement.X86ProducerPushTemporaries.cached_binds
#check KProgFormal.ClightRefinement.X86ProducerPushTemporaries.exact_initial
#print axioms KProgFormal.ClightRefinement.X86ProducerPushTemporaries.exact_initial

#check KProgFormal.ClightRefinement.X86ProducerPushReadValue.layout
#print axioms KProgFormal.ClightRefinement.X86ProducerPushReadValue.layout
#check KProgFormal.ClightRefinement.X86ProducerPushReadValue.call
#print axioms KProgFormal.ClightRefinement.X86ProducerPushReadValue.call

#check KProgFormal.ClightRefinement.X86ProducerPushOperand.source_read
#print axioms KProgFormal.ClightRefinement.X86ProducerPushOperand.source_read
#check KProgFormal.ClightRefinement.X86ProducerPushOperand.exact_start
#print axioms KProgFormal.ClightRefinement.X86ProducerPushOperand.exact_start
#check KProgFormal.ClightRefinement.X86ProducerPushOperand.executes
#print axioms KProgFormal.ClightRefinement.X86ProducerPushOperand.executes
#check KProgFormal.ClightRefinement.X86ProducerPushOperand.arguments
#print axioms KProgFormal.ClightRefinement.X86ProducerPushOperand.arguments

#check KProgFormal.ClightRefinement.X86ProducerPushRead.reader_binding
#print axioms KProgFormal.ClightRefinement.X86ProducerPushRead.reader_binding
#check KProgFormal.ClightRefinement.X86ProducerPushRead.call
#print axioms KProgFormal.ClightRefinement.X86ProducerPushRead.call
#check KProgFormal.ClightRefinement.X86ProducerPushRead.from_body
#print axioms KProgFormal.ClightRefinement.X86ProducerPushRead.from_body

#check KProgFormal.ClightRefinement.X86ProducerPushReadReturn.source
#print axioms KProgFormal.ClightRefinement.X86ProducerPushReadReturn.source
#check KProgFormal.ClightRefinement.X86ProducerPushReadReturn.resume
#print axioms KProgFormal.ClightRefinement.X86ProducerPushReadReturn.resume
#check KProgFormal.ClightRefinement.X86ProducerPushReadReturn.saved
#print axioms KProgFormal.ClightRefinement.X86ProducerPushReadReturn.saved
#check KProgFormal.ClightRefinement.X86ProducerPushReadReturn.from_body
#print axioms KProgFormal.ClightRefinement.X86ProducerPushReadReturn.from_body

#check KProgFormal.ClightRefinement.X86ProducerPushReadPrefix.from_ready
#print axioms KProgFormal.ClightRefinement.X86ProducerPushReadPrefix.from_ready
#check KProgFormal.ClightRefinement.X86ProducerPushReadPrefix.from_call
#print axioms KProgFormal.ClightRefinement.X86ProducerPushReadPrefix.from_call

#check KProgFormal.ClightRefinement.X86ProducerPushRspSource.source
#print axioms KProgFormal.ClightRefinement.X86ProducerPushRspSource.source
#check KProgFormal.ClightRefinement.X86ProducerPushRspSource.reads
#print axioms KProgFormal.ClightRefinement.X86ProducerPushRspSource.reads
#check KProgFormal.ClightRefinement.X86ProducerPushRspSource.following_source
#print axioms KProgFormal.ClightRefinement.X86ProducerPushRspSource.following_source
#check KProgFormal.ClightRefinement.X86ProducerPushRspSource.enter
#print axioms KProgFormal.ClightRefinement.X86ProducerPushRspSource.enter
#check KProgFormal.ClightRefinement.X86ProducerPushRspSource.inputs
#print axioms KProgFormal.ClightRefinement.X86ProducerPushRspSource.inputs

#check KProgFormal.ClightRefinement.X86ProducerPushRspStore.write
#print axioms KProgFormal.ClightRefinement.X86ProducerPushRspStore.write

#check KProgFormal.ClightRefinement.X86ProducerPushRspAddress.original
#print axioms KProgFormal.ClightRefinement.X86ProducerPushRspAddress.original
#check KProgFormal.ClightRefinement.X86ProducerPushRspAddress.header_value
#print axioms KProgFormal.ClightRefinement.X86ProducerPushRspAddress.header_value
#check KProgFormal.ClightRefinement.X86ProducerPushRspAddress.pointer_address
#print axioms KProgFormal.ClightRefinement.X86ProducerPushRspAddress.pointer_address
#check KProgFormal.ClightRefinement.X86ProducerPushRspAddress.current_value
#print axioms KProgFormal.ClightRefinement.X86ProducerPushRspAddress.current_value

#check KProgFormal.ClightRefinement.X86ProducerPushRspValue.source
#print axioms KProgFormal.ClightRefinement.X86ProducerPushRspValue.source
#check KProgFormal.ClightRefinement.X86ProducerPushRspValue.evaluate
#print axioms KProgFormal.ClightRefinement.X86ProducerPushRspValue.evaluate

#check KProgFormal.ClightRefinement.X86ProducerPushRspRead.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerPushRspRead.execute
#check KProgFormal.ClightRefinement.X86ProducerPushRspRead.from_ready
#print axioms KProgFormal.ClightRefinement.X86ProducerPushRspRead.from_ready

#check KProgFormal.ClightRefinement.X86ProducerPushRspExecute.assignment
#print axioms KProgFormal.ClightRefinement.X86ProducerPushRspExecute.assignment
#check KProgFormal.ClightRefinement.X86ProducerPushRspExecute.from_ready
#print axioms KProgFormal.ClightRefinement.X86ProducerPushRspExecute.from_ready

#check KProgFormal.ClightRefinement.X86ProducerPushRspResources.views
#print axioms KProgFormal.ClightRefinement.X86ProducerPushRspResources.views

#check KProgFormal.ClightRefinement.X86ProducerPushRspPrefix.from_ready
#print axioms KProgFormal.ClightRefinement.X86ProducerPushRspPrefix.from_ready
#check KProgFormal.ClightRefinement.X86ProducerPushRspPrefix.from_call
#print axioms KProgFormal.ClightRefinement.X86ProducerPushRspPrefix.from_call
#check KProgFormal.ClightRefinement.X86ProducerPushRspPrefix.Result.run
#print axioms KProgFormal.ClightRefinement.X86ProducerPushRspPrefix.Result.run
#check KProgFormal.ClightRefinement.X86ProducerPushRspPrefix.Result.rsp_read
#print axioms KProgFormal.ClightRefinement.X86ProducerPushRspPrefix.Result.rsp_read
#check KProgFormal.ClightRefinement.X86ProducerPushRspPrefix.Result.rows
#print axioms KProgFormal.ClightRefinement.X86ProducerPushRspPrefix.Result.rows
#check KProgFormal.ClightRefinement.X86ProducerPushRspPrefix.Result.cache_view
#print axioms KProgFormal.ClightRefinement.X86ProducerPushRspPrefix.Result.cache_view
#check KProgFormal.ClightRefinement.X86ProducerPushRspPrefix.Result.ghost_view
#print axioms KProgFormal.ClightRefinement.X86ProducerPushRspPrefix.Result.ghost_view
#check KProgFormal.ClightRefinement.X86ProducerPushRspPrefix.Result.rsp_tag
#print axioms KProgFormal.ClightRefinement.X86ProducerPushRspPrefix.Result.rsp_tag
#check KProgFormal.ClightRefinement.X86ProducerPushRspPrefix.Result.caller_loads
#print axioms KProgFormal.ClightRefinement.X86ProducerPushRspPrefix.Result.caller_loads
#check KProgFormal.ClightRefinement.X86ProducerPushRspPrefix.Result.post_provider_frame
#print axioms KProgFormal.ClightRefinement.X86ProducerPushRspPrefix.Result.post_provider_frame

#check KProgFormal.ClightRefinement.X86ProducerPushCacheCurrent.preserve
#print axioms KProgFormal.ClightRefinement.X86ProducerPushCacheCurrent.preserve

#check KProgFormal.ClightRefinement.X86ProducerPushCacheExecute.continuation_source
#print axioms KProgFormal.ClightRefinement.X86ProducerPushCacheExecute.continuation_source
#check KProgFormal.ClightRefinement.X86ProducerPushCacheExecute.load_header
#print axioms KProgFormal.ClightRefinement.X86ProducerPushCacheExecute.load_header
#check KProgFormal.ClightRefinement.X86ProducerPushCacheExecute.assignment
#print axioms KProgFormal.ClightRefinement.X86ProducerPushCacheExecute.assignment
#check KProgFormal.ClightRefinement.X86ProducerPushCacheExecute.from_metadata
#print axioms KProgFormal.ClightRefinement.X86ProducerPushCacheExecute.from_metadata

#check KProgFormal.ClightRefinement.X86ProducerPushCachePrefix.from_metadata
#print axioms KProgFormal.ClightRefinement.X86ProducerPushCachePrefix.from_metadata
#check KProgFormal.ClightRefinement.X86ProducerPushCachePrefix.from_call
#print axioms KProgFormal.ClightRefinement.X86ProducerPushCachePrefix.from_call
#check KProgFormal.ClightRefinement.X86ProducerPushCachePrefix.inputs
#print axioms KProgFormal.ClightRefinement.X86ProducerPushCachePrefix.inputs
#check KProgFormal.ClightRefinement.X86ProducerPushCachePrefix.Result.run
#print axioms KProgFormal.ClightRefinement.X86ProducerPushCachePrefix.Result.run
#check KProgFormal.ClightRefinement.X86ProducerPushCachePrefix.Result.word_read
#print axioms KProgFormal.ClightRefinement.X86ProducerPushCachePrefix.Result.word_read
#check KProgFormal.ClightRefinement.X86ProducerPushCachePrefix.Result.rsp_read
#print axioms KProgFormal.ClightRefinement.X86ProducerPushCachePrefix.Result.rsp_read
#check KProgFormal.ClightRefinement.X86ProducerPushCachePrefix.Result.tag_read
#print axioms KProgFormal.ClightRefinement.X86ProducerPushCachePrefix.Result.tag_read
#check KProgFormal.ClightRefinement.X86ProducerPushCachePrefix.Result.pointer_read
#print axioms KProgFormal.ClightRefinement.X86ProducerPushCachePrefix.Result.pointer_read
#check KProgFormal.ClightRefinement.X86ProducerPushCachePrefix.Result.cache_view
#print axioms KProgFormal.ClightRefinement.X86ProducerPushCachePrefix.Result.cache_view
#check KProgFormal.ClightRefinement.X86ProducerPushCachePrefix.Result.caller_loads
#print axioms KProgFormal.ClightRefinement.X86ProducerPushCachePrefix.Result.caller_loads
#check KProgFormal.ClightRefinement.X86ProducerPushCachePrefix.Result.post_provider_frame
#print axioms KProgFormal.ClightRefinement.X86ProducerPushCachePrefix.Result.post_provider_frame

#check KProgFormal.ClightRefinement.X86ProducerPushCacheAddress.source
#print axioms KProgFormal.ClightRefinement.X86ProducerPushCacheAddress.source
#check KProgFormal.ClightRefinement.X86ProducerPushCacheAddress.read_value
#print axioms KProgFormal.ClightRefinement.X86ProducerPushCacheAddress.read_value
#check KProgFormal.ClightRefinement.X86ProducerPushCacheAddress.address
#print axioms KProgFormal.ClightRefinement.X86ProducerPushCacheAddress.address

#check KProgFormal.ClightRefinement.X86ProducerPushCacheStore.write
#print axioms KProgFormal.ClightRefinement.X86ProducerPushCacheStore.write

#check KProgFormal.ClightRefinement.X86ProducerEffectiveWidth.invoke
#print axioms KProgFormal.ClightRefinement.X86ProducerEffectiveWidth.invoke

#check KProgFormal.ClightRefinement.X86ProducerPushExit.following_source
#print axioms KProgFormal.ClightRefinement.X86ProducerPushExit.following_source
#check KProgFormal.ClightRefinement.X86ProducerPushExit.leave_storage
#print axioms KProgFormal.ClightRefinement.X86ProducerPushExit.leave_storage
#check KProgFormal.ClightRefinement.X86ProducerPushExit.from_cache
#print axioms KProgFormal.ClightRefinement.X86ProducerPushExit.from_cache

#check KProgFormal.ClightRefinement.X86ProducerPushDeallocate.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerPushDeallocate.execute

#check KProgFormal.ClightRefinement.X86ProducerPushExitSource.source
#print axioms KProgFormal.ClightRefinement.X86ProducerPushExitSource.source
#check KProgFormal.ClightRefinement.X86ProducerPushExitSource.finish_loop
#print axioms KProgFormal.ClightRefinement.X86ProducerPushExitSource.finish_loop
#check KProgFormal.ClightRefinement.X86ProducerPushExitSource.finish
#print axioms KProgFormal.ClightRefinement.X86ProducerPushExitSource.finish

#check KProgFormal.ClightRefinement.X86ProducerPushLossCheck.source
#print axioms KProgFormal.ClightRefinement.X86ProducerPushLossCheck.source
#check KProgFormal.ClightRefinement.X86ProducerPushLossCheck.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerPushLossCheck.execute
#check KProgFormal.ClightRefinement.X86ProducerPushLossCheck.from_cache
#print axioms KProgFormal.ClightRefinement.X86ProducerPushLossCheck.from_cache

#check KProgFormal.ClightRefinement.X86ProducerPushMetadataClearAddress.tag_value
#print axioms KProgFormal.ClightRefinement.X86ProducerPushMetadataClearAddress.tag_value
#check KProgFormal.ClightRefinement.X86ProducerPushMetadataClearAddress.pointer_value
#print axioms KProgFormal.ClightRefinement.X86ProducerPushMetadataClearAddress.pointer_value

#check KProgFormal.ClightRefinement.X86ProducerPushMetadataClearSource.source
#print axioms KProgFormal.ClightRefinement.X86ProducerPushMetadataClearSource.source
#check KProgFormal.ClightRefinement.X86ProducerPushMetadataClearSource.reads
#print axioms KProgFormal.ClightRefinement.X86ProducerPushMetadataClearSource.reads
#check KProgFormal.ClightRefinement.X86ProducerPushMetadataClearSource.stores
#print axioms KProgFormal.ClightRefinement.X86ProducerPushMetadataClearSource.stores

#check KProgFormal.ClightRefinement.X86ProducerPushMetadataClear.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerPushMetadataClear.execute
#check KProgFormal.ClightRefinement.X86ProducerPushMetadataClear.stable
#print axioms KProgFormal.ClightRefinement.X86ProducerPushMetadataClear.stable

#check KProgFormal.ClightRefinement.X86ProducerPushMetadataCurrent.preserve
#print axioms KProgFormal.ClightRefinement.X86ProducerPushMetadataCurrent.preserve

#check KProgFormal.ClightRefinement.X86ProducerPushMetadataExecute.resume
#print axioms KProgFormal.ClightRefinement.X86ProducerPushMetadataExecute.resume
#check KProgFormal.ClightRefinement.X86ProducerPushMetadataExecute.from_rsp
#print axioms KProgFormal.ClightRefinement.X86ProducerPushMetadataExecute.from_rsp
#check KProgFormal.ClightRefinement.X86ProducerPushMetadataExecute.inputs
#print axioms KProgFormal.ClightRefinement.X86ProducerPushMetadataExecute.inputs

#check KProgFormal.ClightRefinement.X86ProducerPushMetadataPrefix.from_rsp
#print axioms KProgFormal.ClightRefinement.X86ProducerPushMetadataPrefix.from_rsp
#check KProgFormal.ClightRefinement.X86ProducerPushMetadataPrefix.from_call
#print axioms KProgFormal.ClightRefinement.X86ProducerPushMetadataPrefix.from_call
#check KProgFormal.ClightRefinement.X86ProducerPushMetadataPrefix.Result.run
#print axioms KProgFormal.ClightRefinement.X86ProducerPushMetadataPrefix.Result.run
#check KProgFormal.ClightRefinement.X86ProducerPushMetadataPrefix.Result.tag_read
#print axioms KProgFormal.ClightRefinement.X86ProducerPushMetadataPrefix.Result.tag_read
#check KProgFormal.ClightRefinement.X86ProducerPushMetadataPrefix.Result.pointer_read
#print axioms KProgFormal.ClightRefinement.X86ProducerPushMetadataPrefix.Result.pointer_read
#check KProgFormal.ClightRefinement.X86ProducerPushMetadataPrefix.Result.rsp_read
#print axioms KProgFormal.ClightRefinement.X86ProducerPushMetadataPrefix.Result.rsp_read
#check KProgFormal.ClightRefinement.X86ProducerPushMetadataPrefix.Result.cache_view
#print axioms KProgFormal.ClightRefinement.X86ProducerPushMetadataPrefix.Result.cache_view
#check KProgFormal.ClightRefinement.X86ProducerPushMetadataPrefix.Result.ghost_view
#print axioms KProgFormal.ClightRefinement.X86ProducerPushMetadataPrefix.Result.ghost_view
#check KProgFormal.ClightRefinement.X86ProducerPushMetadataPrefix.Result.caller_loads
#print axioms KProgFormal.ClightRefinement.X86ProducerPushMetadataPrefix.Result.caller_loads
#check KProgFormal.ClightRefinement.X86ProducerPushMetadataPrefix.Result.post_provider_frame
#print axioms KProgFormal.ClightRefinement.X86ProducerPushMetadataPrefix.Result.post_provider_frame

#check KProgFormal.ClightRefinement.X86ProducerPushMetadataSource.source
#print axioms KProgFormal.ClightRefinement.X86ProducerPushMetadataSource.source
#check KProgFormal.ClightRefinement.X86ProducerPushMetadataSource.stage_source
#print axioms KProgFormal.ClightRefinement.X86ProducerPushMetadataSource.stage_source
#check KProgFormal.ClightRefinement.X86ProducerPushMetadataSource.flag_names
#print axioms KProgFormal.ClightRefinement.X86ProducerPushMetadataSource.flag_names

#check KProgFormal.ClightRefinement.X86ProducerPushComplete.from_cache
#print axioms KProgFormal.ClightRefinement.X86ProducerPushComplete.from_cache
#check KProgFormal.ClightRefinement.X86ProducerPushComplete.from_call
#print axioms KProgFormal.ClightRefinement.X86ProducerPushComplete.from_call
#check KProgFormal.ClightRefinement.X86ProducerPushComplete.Result.run
#print axioms KProgFormal.ClightRefinement.X86ProducerPushComplete.Result.run
#check KProgFormal.ClightRefinement.X86ProducerPushComplete.Result.freed
#print axioms KProgFormal.ClightRefinement.X86ProducerPushComplete.Result.freed
#check KProgFormal.ClightRefinement.X86ProducerPushComplete.Result.released
#print axioms KProgFormal.ClightRefinement.X86ProducerPushComplete.Result.released
#check KProgFormal.ClightRefinement.X86ProducerPushComplete.Result.old_frame
#print axioms KProgFormal.ClightRefinement.X86ProducerPushComplete.Result.old_frame
#check KProgFormal.ClightRefinement.X86ProducerPushComplete.Result.word_read
#print axioms KProgFormal.ClightRefinement.X86ProducerPushComplete.Result.word_read
#check KProgFormal.ClightRefinement.X86ProducerPushComplete.Result.rsp_read
#print axioms KProgFormal.ClightRefinement.X86ProducerPushComplete.Result.rsp_read
#check KProgFormal.ClightRefinement.X86ProducerPushComplete.Result.rsp_tag
#print axioms KProgFormal.ClightRefinement.X86ProducerPushComplete.Result.rsp_tag
#check KProgFormal.ClightRefinement.X86ProducerPushComplete.Result.tag_read
#print axioms KProgFormal.ClightRefinement.X86ProducerPushComplete.Result.tag_read
#check KProgFormal.ClightRefinement.X86ProducerPushComplete.Result.pointer_read
#print axioms KProgFormal.ClightRefinement.X86ProducerPushComplete.Result.pointer_read
#check KProgFormal.ClightRefinement.X86ProducerPushComplete.Result.cache_view
#print axioms KProgFormal.ClightRefinement.X86ProducerPushComplete.Result.cache_view
#check KProgFormal.ClightRefinement.X86ProducerPushComplete.Result.ghost_view
#print axioms KProgFormal.ClightRefinement.X86ProducerPushComplete.Result.ghost_view
#check KProgFormal.ClightRefinement.X86ProducerPushComplete.Result.caller_loads
#print axioms KProgFormal.ClightRefinement.X86ProducerPushComplete.Result.caller_loads
#check KProgFormal.ClightRefinement.X86ProducerPushComplete.Result.post_provider_frame
#print axioms KProgFormal.ClightRefinement.X86ProducerPushComplete.Result.post_provider_frame

#check KProgFormal.ClightRefinement.X86ProducerPushReturnResources.preserve
#print axioms KProgFormal.ClightRefinement.X86ProducerPushReturnResources.preserve

#check KProgFormal.ClightRefinement.X86ProducerPushReturn.resume
#print axioms KProgFormal.ClightRefinement.X86ProducerPushReturn.resume
#check KProgFormal.ClightRefinement.X86ProducerPushReturn.from_cache
#print axioms KProgFormal.ClightRefinement.X86ProducerPushReturn.from_cache

#check KProgFormal.ClightRefinement.X86ProducerPushStackSetup.index_source
#print axioms KProgFormal.ClightRefinement.X86ProducerPushStackSetup.index_source
#check KProgFormal.ClightRefinement.X86ProducerPushStackSetup.index_value
#print axioms KProgFormal.ClightRefinement.X86ProducerPushStackSetup.index_value
#check KProgFormal.ClightRefinement.X86ProducerPushStackSetup.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerPushStackSetup.execute
#check KProgFormal.ClightRefinement.X86ProducerPushStackSetup.from_rsp
#print axioms KProgFormal.ClightRefinement.X86ProducerPushStackSetup.from_rsp
#check KProgFormal.ClightRefinement.X86ProducerPushStackSetup.inputs
#print axioms KProgFormal.ClightRefinement.X86ProducerPushStackSetup.inputs

#check KProgFormal.ClightRefinement.X86ProducerPushPointerRead.scalar
#print axioms KProgFormal.ClightRefinement.X86ProducerPushPointerRead.scalar

#check KProgFormal.ClightRefinement.X86ProducerPushStackSource.loop_source
#print axioms KProgFormal.ClightRefinement.X86ProducerPushStackSource.loop_source
#check KProgFormal.ClightRefinement.X86ProducerPushStackSource.body_source
#print axioms KProgFormal.ClightRefinement.X86ProducerPushStackSource.body_source
#check KProgFormal.ClightRefinement.X86ProducerPushStackSource.prepare_source
#print axioms KProgFormal.ClightRefinement.X86ProducerPushStackSource.prepare_source
#check KProgFormal.ClightRefinement.X86ProducerPushStackSource.reads_source
#print axioms KProgFormal.ClightRefinement.X86ProducerPushStackSource.reads_source
#check KProgFormal.ClightRefinement.X86ProducerPushStackSource.width_source
#print axioms KProgFormal.ClightRefinement.X86ProducerPushStackSource.width_source

#check KProgFormal.ClightRefinement.X86ProducerPushStackWidth.call
#print axioms KProgFormal.ClightRefinement.X86ProducerPushStackWidth.call
#check KProgFormal.ClightRefinement.X86ProducerPushStackWidth.resume
#print axioms KProgFormal.ClightRefinement.X86ProducerPushStackWidth.resume
#check KProgFormal.ClightRefinement.X86ProducerPushStackWidth.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerPushStackWidth.execute
#check KProgFormal.ClightRefinement.X86ProducerPushStackWidth.from_rsp
#print axioms KProgFormal.ClightRefinement.X86ProducerPushStackWidth.from_rsp
#check KProgFormal.ClightRefinement.X86ProducerPushStackWidth.inputs
#print axioms KProgFormal.ClightRefinement.X86ProducerPushStackWidth.inputs

#check KProgFormal.ClightRefinement.X86ProducerPushStorageSelect.guard_inputs
#print axioms KProgFormal.ClightRefinement.X86ProducerPushStorageSelect.guard_inputs
#check KProgFormal.ClightRefinement.X86ProducerPushStorageSelect.cache_inputs
#print axioms KProgFormal.ClightRefinement.X86ProducerPushStorageSelect.cache_inputs
#check KProgFormal.ClightRefinement.X86ProducerPushStorageSelect.from_metadata
#print axioms KProgFormal.ClightRefinement.X86ProducerPushStorageSelect.from_metadata

#check KProgFormal.ClightRefinement.X86ProducerPushStorageSetup.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerPushStorageSetup.execute
#check KProgFormal.ClightRefinement.X86ProducerPushStorageSetup.from_metadata
#print axioms KProgFormal.ClightRefinement.X86ProducerPushStorageSetup.from_metadata
#check KProgFormal.ClightRefinement.X86ProducerPushStorageSetup.inputs
#print axioms KProgFormal.ClightRefinement.X86ProducerPushStorageSetup.inputs

#check KProgFormal.ClightRefinement.X86ProducerPushStorageSource.source
#print axioms KProgFormal.ClightRefinement.X86ProducerPushStorageSource.source
#check KProgFormal.ClightRefinement.X86ProducerPushStorageSource.inputs_source
#print axioms KProgFormal.ClightRefinement.X86ProducerPushStorageSource.inputs_source
#check KProgFormal.ClightRefinement.X86ProducerPushStorageSource.width_source
#print axioms KProgFormal.ClightRefinement.X86ProducerPushStorageSource.width_source

#check KProgFormal.ClightRefinement.X86ProducerPushMetadataSelect.executes
#print axioms KProgFormal.ClightRefinement.X86ProducerPushMetadataSelect.executes
#check KProgFormal.ClightRefinement.X86ProducerPushMetadataSelect.source_continuation
#print axioms KProgFormal.ClightRefinement.X86ProducerPushMetadataSelect.source_continuation
#check KProgFormal.ClightRefinement.X86ProducerPushMetadataSelect.decisions
#print axioms KProgFormal.ClightRefinement.X86ProducerPushMetadataSelect.decisions
#check KProgFormal.ClightRefinement.X86ProducerPushMetadataSelect.inputs
#print axioms KProgFormal.ClightRefinement.X86ProducerPushMetadataSelect.inputs
#check KProgFormal.ClightRefinement.X86ProducerPushLocal.rsp_run
#print axioms KProgFormal.ClightRefinement.X86ProducerPushLocal.rsp_run
#check KProgFormal.ClightRefinement.X86ProducerPushLocal.metadata_run
#print axioms KProgFormal.ClightRefinement.X86ProducerPushLocal.metadata_run
#check KProgFormal.ClightRefinement.X86ProducerPushLocal.cache_run
#print axioms KProgFormal.ClightRefinement.X86ProducerPushLocal.cache_run
#check KProgFormal.ClightRefinement.X86ProducerPushLocal.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerPushLocal.execute
#check KProgFormal.ClightRefinement.X86ProducerPushLocal.silent
#print axioms KProgFormal.ClightRefinement.X86ProducerPushLocal.silent
#check KProgFormal.ClightRefinement.X86ProducerPushGprView.table
#print axioms KProgFormal.ClightRefinement.X86ProducerPushGprView.table
#check KProgFormal.ClightRefinement.X86ProducerPushGprView.initial_sp
#print axioms KProgFormal.ClightRefinement.X86ProducerPushGprView.initial_sp
#check KProgFormal.ClightRefinement.X86ProducerPushGprView.registers
#print axioms KProgFormal.ClightRefinement.X86ProducerPushGprView.registers
#check KProgFormal.ClightRefinement.X86ProducerPushNativeRegisters.payload
#print axioms KProgFormal.ClightRefinement.X86ProducerPushNativeRegisters.payload
#check KProgFormal.ClightRefinement.X86ProducerPushNativeRegisters.delta
#print axioms KProgFormal.ClightRefinement.X86ProducerPushNativeRegisters.delta
#check KProgFormal.ClightRefinement.X86ProducerPushNativeRegisters.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerPushNativeRegisters.execute
#check KProgFormal.ClightRefinement.X86ProducerPushCacheFrame.outside
#print axioms KProgFormal.ClightRefinement.X86ProducerPushCacheFrame.outside
#check KProgFormal.ClightRefinement.X86ProducerPushCacheFrame.lower_bytes
#print axioms KProgFormal.ClightRefinement.X86ProducerPushCacheFrame.lower_bytes
#check KProgFormal.ClightRefinement.X86ScalarStoreBytes.load
#print axioms KProgFormal.ClightRefinement.X86ScalarStoreBytes.load
#check KProgFormal.ClightRefinement.X86ProducerPushCacheBytes.written
#print axioms KProgFormal.ClightRefinement.X86ProducerPushCacheBytes.written
#check KProgFormal.ClightRefinement.X86ProducerPushCacheBytes.table
#print axioms KProgFormal.ClightRefinement.X86ProducerPushCacheBytes.table
#check KProgFormal.ClightRefinement.X86ProducerPushCacheBytes.native_payload
#print axioms KProgFormal.ClightRefinement.X86ProducerPushCacheBytes.native_payload
#check KProgFormal.ClightRefinement.X86StackCacheView.address
#print axioms KProgFormal.ClightRefinement.X86StackCacheView.address
#check KProgFormal.ClightRefinement.X86StackCacheView.Represents
#print axioms KProgFormal.ClightRefinement.X86StackCacheView.Represents
#check KProgFormal.ClightRefinement.X86StackCacheView.displacement
#print axioms KProgFormal.ClightRefinement.X86StackCacheView.displacement
#check KProgFormal.ClightRefinement.X86StackCacheView.store
#print axioms KProgFormal.ClightRefinement.X86StackCacheView.store
#check KProgFormal.ClightRefinement.X86ProducerPushNativeCache.memory
#print axioms KProgFormal.ClightRefinement.X86ProducerPushNativeCache.memory
#check KProgFormal.ClightRefinement.X86ProducerPushNativeCache.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerPushNativeCache.execute
#check KProgFormal.ClightRefinement.X86PushChecked.reads
#print axioms KProgFormal.ClightRefinement.X86PushChecked.reads
#check KProgFormal.ClightRefinement.X86PushChecked.success
#print axioms KProgFormal.ClightRefinement.X86PushChecked.success
#check KProgFormal.ClightRefinement.X86PushNativeBytes.table
#print axioms KProgFormal.ClightRefinement.X86PushNativeBytes.table
#check KProgFormal.ClightRefinement.X86PushMemoryView.view
#print axioms KProgFormal.ClightRefinement.X86PushMemoryView.view
#check KProgFormal.ClightRefinement.X86PushMemoryView.values
#print axioms KProgFormal.ClightRefinement.X86PushMemoryView.values
#check KProgFormal.ClightRefinement.X86PushMemoryView.represented
#print axioms KProgFormal.ClightRefinement.X86PushMemoryView.represented
#check KProgFormal.ClightRefinement.X86ProducerPushChecked.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerPushChecked.execute
#check KProgFormal.ClightRefinement.X86PushNativePayload.coordinate
#print axioms KProgFormal.ClightRefinement.X86PushNativePayload.coordinate
#check KProgFormal.ClightRefinement.X86PushNativePayload.bytes
#print axioms KProgFormal.ClightRefinement.X86PushNativePayload.bytes
#check KProgFormal.ClightRefinement.X86NativeByteFold.storeBytes
#print axioms KProgFormal.ClightRefinement.X86NativeByteFold.storeBytes
#check KProgFormal.ClightRefinement.X86NativeByteFold.byte_value
#print axioms KProgFormal.ClightRefinement.X86NativeByteFold.byte_value
#check KProgFormal.ClightRefinement.X86NativeByteFold.byte_initialized
#print axioms KProgFormal.ClightRefinement.X86NativeByteFold.byte_initialized
#check KProgFormal.ClightRefinement.X86NativeByteFold.selected
#print axioms KProgFormal.ClightRefinement.X86NativeByteFold.selected
#check KProgFormal.ClightRefinement.X86NativeByteFold.observations
#print axioms KProgFormal.ClightRefinement.X86NativeByteFold.observations
#check KProgFormal.ClightRefinement.X86NativeByteFold.scalar
#print axioms KProgFormal.ClightRefinement.X86NativeByteFold.scalar
#check KProgFormal.ClightRefinement.X86PushReference.step
#print axioms KProgFormal.ClightRefinement.X86PushReference.step
#check KProgFormal.ClightRefinement.X86ProducerPushLocalFrame.loads
#print axioms KProgFormal.ClightRefinement.X86ProducerPushLocalFrame.loads
#check KProgFormal.ClightRefinement.X86ProducerPushLocalFrame.scalars
#print axioms KProgFormal.ClightRefinement.X86ProducerPushLocalFrame.scalars
#check KProgFormal.ClightRefinement.X86ProducerPushReference.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerPushReference.execute
#check KProgFormal.ClightRefinement.X86ProducerScalarView.flag
#print axioms KProgFormal.ClightRefinement.X86ProducerScalarView.flag
#check KProgFormal.ClightRefinement.X86ProducerScalarView.Represents
#print axioms KProgFormal.ClightRefinement.X86ProducerScalarView.Represents
#check KProgFormal.ClightRefinement.X86ProducerScalarView.preserve
#print axioms KProgFormal.ClightRefinement.X86ProducerScalarView.preserve
#check KProgFormal.ClightRefinement.X86ProducerScalarView.reference
#print axioms KProgFormal.ClightRefinement.X86ProducerScalarView.reference
#check KProgFormal.ClightRefinement.X86ProducerPushStateView.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerPushStateView.execute
#check KProgFormal.ClightRefinement.X86ProducerPushInputOrigin.origins
#print axioms KProgFormal.ClightRefinement.X86ProducerPushInputOrigin.origins
#check KProgFormal.ClightRefinement.X86ProducerPushInputOrigin.base
#print axioms KProgFormal.ClightRefinement.X86ProducerPushInputOrigin.base
#check KProgFormal.ClightRefinement.X86ProducerPushInputOrigin.native_stack
#print axioms KProgFormal.ClightRefinement.X86ProducerPushInputOrigin.native_stack
#check KProgFormal.ClightRefinement.X86ProducerPushStoreObservation.event
#print axioms KProgFormal.ClightRefinement.X86ProducerPushStoreObservation.event
#check KProgFormal.ClightRefinement.X86ProducerPushStoreObservation.source
#print axioms KProgFormal.ClightRefinement.X86ProducerPushStoreObservation.source
#check KProgFormal.ClightRefinement.X86ProducerPushStoreObservation.correspondence
#print axioms KProgFormal.ClightRefinement.X86ProducerPushStoreObservation.correspondence
#check KProgFormal.ClightRefinement.X86ProducerPushBoundary.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerPushBoundary.execute
#check KProgFormal.ClightRefinement.X86ProducerPushDecode.decode
#print axioms KProgFormal.ClightRefinement.X86ProducerPushDecode.decode
#check KProgFormal.ClightRefinement.X86ProducerPushDecode.step
#print axioms KProgFormal.ClightRefinement.X86ProducerPushDecode.step
#check KProgFormal.ClightRefinement.X86ProducerPushDecode.source_successor
#print axioms KProgFormal.ClightRefinement.X86ProducerPushDecode.source_successor
#check KProgFormal.ClightRefinement.X86ProducerPushNextCall.enter
#print axioms KProgFormal.ClightRefinement.X86ProducerPushNextCall.enter
#check KProgFormal.ClightRefinement.X86ProducerPushNextCall.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerPushNextCall.execute
#check KProgFormal.ClightRefinement.X86ProducerHeaderViews.initialized_views_with_reads
#print axioms KProgFormal.ClightRefinement.X86ProducerHeaderViews.initialized_views_with_reads
#check KProgFormal.ClightRefinement.X86ProducerHeaderComplete.to_first_call_with_reads
#print axioms KProgFormal.ClightRefinement.X86ProducerHeaderComplete.to_first_call_with_reads
#check KProgFormal.ClightRefinement.X86ProducerHeaderBound.to_first_call_with_reads
#print axioms KProgFormal.ClightRefinement.X86ProducerHeaderBound.to_first_call_with_reads
#check KProgFormal.ClightRefinement.X86ProducerContextSetup.to_first_call_with_reads
#print axioms KProgFormal.ClightRefinement.X86ProducerContextSetup.to_first_call_with_reads
#check KProgFormal.ClightRefinement.X86ProducerEntryReady.HeaderReads
#print axioms KProgFormal.ClightRefinement.X86ProducerEntryReady.HeaderReads
#check KProgFormal.ClightRefinement.X86ProducerEntryReady.from_call_with_header
#print axioms KProgFormal.ClightRefinement.X86ProducerEntryReady.from_call_with_header
#check KProgFormal.ClightRefinement.X86SubImmediateChecked.checked
#print axioms KProgFormal.ClightRefinement.X86SubImmediateChecked.checked
#check KProgFormal.ClightRefinement.X86SubImmediateChecked.reads
#print axioms KProgFormal.ClightRefinement.X86SubImmediateChecked.reads
#check KProgFormal.ClightRefinement.X86SubImmediateChecked.numeric
#print axioms KProgFormal.ClightRefinement.X86SubImmediateChecked.numeric
#check KProgFormal.ClightRefinement.X86SubRspDecode.decode
#print axioms KProgFormal.ClightRefinement.X86SubRspDecode.decode
#check KProgFormal.ClightRefinement.X86SubImmediateReference.step
#print axioms KProgFormal.ClightRefinement.X86SubImmediateReference.step
#check KProgFormal.ClightRefinement.X86ProducerHeaderReady.source_block
#print axioms KProgFormal.ClightRefinement.X86ProducerHeaderReady.source_block
#check KProgFormal.ClightRefinement.X86ProducerHeaderReady.preserve
#print axioms KProgFormal.ClightRefinement.X86ProducerHeaderReady.preserve
#check KProgFormal.ClightRefinement.X86ProducerHeaderReady.current
#print axioms KProgFormal.ClightRefinement.X86ProducerHeaderReady.current
#check KProgFormal.ClightRefinement.X86ProducerHeaderReady.from_call
#print axioms KProgFormal.ClightRefinement.X86ProducerHeaderReady.from_call
#check KProgFormal.ClightRefinement.X86ProducerRspReady.call
#print axioms KProgFormal.ClightRefinement.X86ProducerRspReady.call
#check KProgFormal.ClightRefinement.X86ProducerSubCall.source_site
#print axioms KProgFormal.ClightRefinement.X86ProducerSubCall.source_site
#check KProgFormal.ClightRefinement.X86ProducerSubCall.source_call
#print axioms KProgFormal.ClightRefinement.X86ProducerSubCall.source_call
#check KProgFormal.ClightRefinement.X86ProducerSubCall.handler_binding
#print axioms KProgFormal.ClightRefinement.X86ProducerSubCall.handler_binding
#check KProgFormal.ClightRefinement.X86ProducerSubCall.arguments
#print axioms KProgFormal.ClightRefinement.X86ProducerSubCall.arguments
#check KProgFormal.ClightRefinement.X86ProducerSubCall.call
#print axioms KProgFormal.ClightRefinement.X86ProducerSubCall.call
#check KProgFormal.ClightRefinement.X86ProducerSubCall.entry
#print axioms KProgFormal.ClightRefinement.X86ProducerSubCall.entry
#check KProgFormal.ClightRefinement.X86ProducerSubEntry.call
#print axioms KProgFormal.ClightRefinement.X86ProducerSubEntry.call
#check KProgFormal.ClightRefinement.X86ProducerSubEntry.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerSubEntry.execute
#check KProgFormal.ClightRefinement.X86ProducerSubWidth.source
#print axioms KProgFormal.ClightRefinement.X86ProducerSubWidth.source
#check KProgFormal.ClightRefinement.X86ProducerSubWidth.width_source
#print axioms KProgFormal.ClightRefinement.X86ProducerSubWidth.width_source
#check KProgFormal.ClightRefinement.X86ProducerSubWidth.width_assignment
#print axioms KProgFormal.ClightRefinement.X86ProducerSubWidth.width_assignment
#check KProgFormal.ClightRefinement.X86ProducerSubWidth.enter
#print axioms KProgFormal.ClightRefinement.X86ProducerSubWidth.enter
#check KProgFormal.ClightRefinement.X86ProducerSubWidth.resume
#print axioms KProgFormal.ClightRefinement.X86ProducerSubWidth.resume
#check KProgFormal.ClightRefinement.X86ProducerSubWidth.from_call
#print axioms KProgFormal.ClightRefinement.X86ProducerSubWidth.from_call
#check KProgFormal.ClightRefinement.X86ProducerSubWidth.unchanged
#print axioms KProgFormal.ClightRefinement.X86ProducerSubWidth.unchanged
#check KProgFormal.ClightRefinement.X86ProducerSubDispatch.target_source
#print axioms KProgFormal.ClightRefinement.X86ProducerSubDispatch.target_source
#check KProgFormal.ClightRefinement.X86ProducerSubDispatch.executes
#print axioms KProgFormal.ClightRefinement.X86ProducerSubDispatch.executes
#check KProgFormal.ClightRefinement.X86ProducerSubDispatch.arguments
#print axioms KProgFormal.ClightRefinement.X86ProducerSubDispatch.arguments
#check KProgFormal.ClightRefinement.X86ProducerSubDispatch.source_continuation
#print axioms KProgFormal.ClightRefinement.X86ProducerSubDispatch.source_continuation
#check KProgFormal.ClightRefinement.X86ProducerSubPrefix.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerSubPrefix.execute
#check KProgFormal.ClightRefinement.X86ProducerSubBody.handler_binding
#print axioms KProgFormal.ClightRefinement.X86ProducerSubBody.handler_binding
#check KProgFormal.ClightRefinement.X86ProducerSubBody.call
#print axioms KProgFormal.ClightRefinement.X86ProducerSubBody.call
#check KProgFormal.ClightRefinement.X86ProducerSubBody.allocation_valid
#print axioms KProgFormal.ClightRefinement.X86ProducerSubBody.allocation_valid
#check KProgFormal.ClightRefinement.X86ProducerSubBody.entry
#print axioms KProgFormal.ClightRefinement.X86ProducerSubBody.entry
#check KProgFormal.ClightRefinement.X86ProducerSubBody.entry_frame
#print axioms KProgFormal.ClightRefinement.X86ProducerSubBody.entry_frame
#check KProgFormal.ClightRefinement.X86ProducerSubBody.local_storage
#print axioms KProgFormal.ClightRefinement.X86ProducerSubBody.local_storage
#check KProgFormal.ClightRefinement.X86ProducerSubResources.frontier
#print axioms KProgFormal.ClightRefinement.X86ProducerSubResources.frontier
#check KProgFormal.ClightRefinement.X86ProducerSubResources.old_local
#print axioms KProgFormal.ClightRefinement.X86ProducerSubResources.old_local
#check KProgFormal.ClightRefinement.X86ProducerSubResources.old_access
#print axioms KProgFormal.ClightRefinement.X86ProducerSubResources.old_access
#check KProgFormal.ClightRefinement.X86ProducerSubResources.headers
#print axioms KProgFormal.ClightRefinement.X86ProducerSubResources.headers
#check KProgFormal.ClightRefinement.X86ProducerSubResources.current
#print axioms KProgFormal.ClightRefinement.X86ProducerSubResources.current
#check KProgFormal.ClightRefinement.X86ProducerSubResources.views
#print axioms KProgFormal.ClightRefinement.X86ProducerSubResources.views
#check KProgFormal.ClightRefinement.X86ProducerSubResources.observations
#print axioms KProgFormal.ClightRefinement.X86ProducerSubResources.observations
#check KProgFormal.ClightRefinement.X86ProducerSubReadValue.call
#print axioms KProgFormal.ClightRefinement.X86ProducerSubReadValue.call
#check KProgFormal.ClightRefinement.X86ProducerSubAllocated.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerSubAllocated.execute
#check KProgFormal.ClightRefinement.X86ProducerSubAllocated.from_call
#print axioms KProgFormal.ClightRefinement.X86ProducerSubAllocated.from_call
#check KProgFormal.ClightRefinement.X86ProducerSubTemporaries.undefined_exact
#print axioms KProgFormal.ClightRefinement.X86ProducerSubTemporaries.undefined_exact
#check KProgFormal.ClightRefinement.X86ProducerSubTemporaries.cached_binds
#print axioms KProgFormal.ClightRefinement.X86ProducerSubTemporaries.cached_binds
#check KProgFormal.ClightRefinement.X86ProducerSubTemporaries.exact_initial
#print axioms KProgFormal.ClightRefinement.X86ProducerSubTemporaries.exact_initial
#check KProgFormal.ClightRefinement.X86ProducerSubSetup.width_source
#print axioms KProgFormal.ClightRefinement.X86ProducerSubSetup.width_source
#check KProgFormal.ClightRefinement.X86ProducerSubSetup.exact_start
#print axioms KProgFormal.ClightRefinement.X86ProducerSubSetup.exact_start
#check KProgFormal.ClightRefinement.X86ProducerSubSetup.original_run
#print axioms KProgFormal.ClightRefinement.X86ProducerSubSetup.original_run
#check KProgFormal.ClightRefinement.X86ProducerSubSetup.executes
#print axioms KProgFormal.ClightRefinement.X86ProducerSubSetup.executes
#check KProgFormal.ClightRefinement.X86ProducerSubSetup.arguments
#print axioms KProgFormal.ClightRefinement.X86ProducerSubSetup.arguments
#check KProgFormal.ClightRefinement.X86ProducerSubSetup.invoke
#print axioms KProgFormal.ClightRefinement.X86ProducerSubSetup.invoke
#check KProgFormal.ClightRefinement.X86ProducerSubReadSite.source_read
#print axioms KProgFormal.ClightRefinement.X86ProducerSubReadSite.source_read
#check KProgFormal.ClightRefinement.X86ProducerSubReadSite.executes
#print axioms KProgFormal.ClightRefinement.X86ProducerSubReadSite.executes
#check KProgFormal.ClightRefinement.X86ProducerSubReadSite.arguments
#print axioms KProgFormal.ClightRefinement.X86ProducerSubReadSite.arguments
#check KProgFormal.ClightRefinement.X86ProducerSubReadSite.call
#print axioms KProgFormal.ClightRefinement.X86ProducerSubReadSite.call
#check KProgFormal.ClightRefinement.X86ProducerSubReadSite.from_body
#print axioms KProgFormal.ClightRefinement.X86ProducerSubReadSite.from_body
#check KProgFormal.ClightRefinement.X86ProducerSubLhs.source
#print axioms KProgFormal.ClightRefinement.X86ProducerSubLhs.source
#check KProgFormal.ClightRefinement.X86ProducerSubLhs.resume
#print axioms KProgFormal.ClightRefinement.X86ProducerSubLhs.resume
#check KProgFormal.ClightRefinement.X86ProducerSubLhs.saved
#print axioms KProgFormal.ClightRefinement.X86ProducerSubLhs.saved
#check KProgFormal.ClightRefinement.X86ProducerSubLhs.from_body
#print axioms KProgFormal.ClightRefinement.X86ProducerSubLhs.from_body
#check KProgFormal.ClightRefinement.X86ProducerSubLhs.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerSubLhs.execute
#check KProgFormal.ClightRefinement.X86ProducerSubLhs.from_call
#print axioms KProgFormal.ClightRefinement.X86ProducerSubLhs.from_call
#check KProgFormal.ClightRefinement.X86StoreImmediate32.internal
#print axioms KProgFormal.ClightRefinement.X86StoreImmediate32.internal
#check KProgFormal.ClightRefinement.X86ProducerSubRhsSite.source_call
#print axioms KProgFormal.ClightRefinement.X86ProducerSubRhsSite.source_call
#check KProgFormal.ClightRefinement.X86ProducerSubRhsSite.executes
#print axioms KProgFormal.ClightRefinement.X86ProducerSubRhsSite.executes
#check KProgFormal.ClightRefinement.X86ProducerSubRhsSite.arguments
#print axioms KProgFormal.ClightRefinement.X86ProducerSubRhsSite.arguments
#check KProgFormal.ClightRefinement.X86ProducerSubRhsSite.lhs_kept
#print axioms KProgFormal.ClightRefinement.X86ProducerSubRhsSite.lhs_kept
#check KProgFormal.ClightRefinement.X86ProducerSubRhsSite.helper_binding
#print axioms KProgFormal.ClightRefinement.X86ProducerSubRhsSite.helper_binding
#check KProgFormal.ClightRefinement.X86ProducerSubRhsSite.call
#print axioms KProgFormal.ClightRefinement.X86ProducerSubRhsSite.call
#check KProgFormal.ClightRefinement.X86ProducerSubRhsSite.from_lhs
#print axioms KProgFormal.ClightRefinement.X86ProducerSubRhsSite.from_lhs
#check KProgFormal.ClightRefinement.X86ProducerSubOperands.source
#print axioms KProgFormal.ClightRefinement.X86ProducerSubOperands.source
#check KProgFormal.ClightRefinement.X86ProducerSubOperands.resume
#print axioms KProgFormal.ClightRefinement.X86ProducerSubOperands.resume
#check KProgFormal.ClightRefinement.X86ProducerSubOperands.operands
#print axioms KProgFormal.ClightRefinement.X86ProducerSubOperands.operands
#check KProgFormal.ClightRefinement.X86ProducerSubOperands.from_lhs
#print axioms KProgFormal.ClightRefinement.X86ProducerSubOperands.from_lhs
#check KProgFormal.ClightRefinement.X86ProducerSubOperands.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerSubOperands.execute
#check KProgFormal.ClightRefinement.X86ProducerSubOperands.from_call
#print axioms KProgFormal.ClightRefinement.X86ProducerSubOperands.from_call
#check KProgFormal.ClightRefinement.X86SubtractAlu.internal
#print axioms KProgFormal.ClightRefinement.X86SubtractAlu.internal
#check KProgFormal.ClightRefinement.X86ProducerSubResultSite.source_call
#print axioms KProgFormal.ClightRefinement.X86ProducerSubResultSite.source_call
#check KProgFormal.ClightRefinement.X86ProducerSubResultSite.executes
#print axioms KProgFormal.ClightRefinement.X86ProducerSubResultSite.executes
#check KProgFormal.ClightRefinement.X86ProducerSubResultSite.arguments
#print axioms KProgFormal.ClightRefinement.X86ProducerSubResultSite.arguments
#check KProgFormal.ClightRefinement.X86ProducerSubResultSite.lhs_kept
#print axioms KProgFormal.ClightRefinement.X86ProducerSubResultSite.lhs_kept
#check KProgFormal.ClightRefinement.X86ProducerSubResultSite.helper_binding
#print axioms KProgFormal.ClightRefinement.X86ProducerSubResultSite.helper_binding
#check KProgFormal.ClightRefinement.X86ProducerSubResultSite.call
#print axioms KProgFormal.ClightRefinement.X86ProducerSubResultSite.call
#check KProgFormal.ClightRefinement.X86ProducerSubResultSite.from_operands
#print axioms KProgFormal.ClightRefinement.X86ProducerSubResultSite.from_operands
#check KProgFormal.ClightRefinement.X86ProducerSubResult.source
#print axioms KProgFormal.ClightRefinement.X86ProducerSubResult.source
#check KProgFormal.ClightRefinement.X86ProducerSubResult.resume
#print axioms KProgFormal.ClightRefinement.X86ProducerSubResult.resume
#check KProgFormal.ClightRefinement.X86ProducerSubResult.inputs
#print axioms KProgFormal.ClightRefinement.X86ProducerSubResult.inputs
#check KProgFormal.ClightRefinement.X86ProducerSubResult.saved
#print axioms KProgFormal.ClightRefinement.X86ProducerSubResult.saved
#check KProgFormal.ClightRefinement.X86ProducerSubResult.from_operands
#print axioms KProgFormal.ClightRefinement.X86ProducerSubResult.from_operands
#check KProgFormal.ClightRefinement.X86ProducerSubResult.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerSubResult.execute
#check KProgFormal.ClightRefinement.X86ProducerSubResult.from_call
#print axioms KProgFormal.ClightRefinement.X86ProducerSubResult.from_call
#check KProgFormal.ClightRefinement.X86ProducerSubNativeResult.native
#print axioms KProgFormal.ClightRefinement.X86ProducerSubNativeResult.native
#check KProgFormal.ClightRefinement.X86ProducerSubNativeResult.saved
#print axioms KProgFormal.ClightRefinement.X86ProducerSubNativeResult.saved
#check KProgFormal.ClightRefinement.X86ProducerSubNativeResult.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerSubNativeResult.execute
#check KProgFormal.ClightRefinement.X86ProducerSubScalarResources.access
#print axioms KProgFormal.ClightRefinement.X86ProducerSubScalarResources.access
#check KProgFormal.ClightRefinement.X86ProducerSubScalarResources.rights
#print axioms KProgFormal.ClightRefinement.X86ProducerSubScalarResources.rights
#check KProgFormal.ClightRefinement.X86ProducerSubScalarResources.scalars
#print axioms KProgFormal.ClightRefinement.X86ProducerSubScalarResources.scalars
#check KProgFormal.ClightRefinement.X86ProducerSubScalarResources.headers
#print axioms KProgFormal.ClightRefinement.X86ProducerSubScalarResources.headers
#check KProgFormal.ClightRefinement.X86ProducerSubFlagSource.pointer_source
#print axioms KProgFormal.ClightRefinement.X86ProducerSubFlagSource.pointer_source
#check KProgFormal.ClightRefinement.X86ProducerSubFlagSource.executes
#print axioms KProgFormal.ClightRefinement.X86ProducerSubFlagSource.executes
#check KProgFormal.ClightRefinement.X86ProducerSubFlagSource.binding
#print axioms KProgFormal.ClightRefinement.X86ProducerSubFlagSource.binding
#check KProgFormal.ClightRefinement.X86ProducerSubOldCf.pointer
#print axioms KProgFormal.ClightRefinement.X86ProducerSubOldCf.pointer
#check KProgFormal.ClightRefinement.X86ProducerSubOldCf.byte_source
#print axioms KProgFormal.ClightRefinement.X86ProducerSubOldCf.byte_source
#check KProgFormal.ClightRefinement.X86ProducerSubOldCf.source
#print axioms KProgFormal.ClightRefinement.X86ProducerSubOldCf.source
#check KProgFormal.ClightRefinement.X86ProducerSubOldCf.byte
#print axioms KProgFormal.ClightRefinement.X86ProducerSubOldCf.byte
#check KProgFormal.ClightRefinement.X86ProducerSubOldCf.from_result
#print axioms KProgFormal.ClightRefinement.X86ProducerSubOldCf.from_result
#check KProgFormal.ClightRefinement.X86ProducerSubCfPrefix.observations
#print axioms KProgFormal.ClightRefinement.X86ProducerSubCfPrefix.observations
#check KProgFormal.ClightRefinement.X86ProducerSubCfPrefix.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerSubCfPrefix.execute
#check KProgFormal.ClightRefinement.X86ProducerSubCfPrefix.from_call
#print axioms KProgFormal.ClightRefinement.X86ProducerSubCfPrefix.from_call
#check KProgFormal.ClightRefinement.X86ProducerSubFlagRoute.source_call
#print axioms KProgFormal.ClightRefinement.X86ProducerSubFlagRoute.source_call
#check KProgFormal.ClightRefinement.X86ProducerSubFlagRoute.executes
#print axioms KProgFormal.ClightRefinement.X86ProducerSubFlagRoute.executes
#check KProgFormal.ClightRefinement.X86ProducerSubFlagRoute.arguments
#print axioms KProgFormal.ClightRefinement.X86ProducerSubFlagRoute.arguments
#check KProgFormal.ClightRefinement.X86ProducerSubFlagWidth.invoke
#print axioms KProgFormal.ClightRefinement.X86ProducerSubFlagWidth.invoke
#check KProgFormal.ClightRefinement.X86ProducerSubFlagWidth.from_old_cf
#print axioms KProgFormal.ClightRefinement.X86ProducerSubFlagWidth.from_old_cf
#check KProgFormal.ClightRefinement.X86ProducerSubFlagWidth.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerSubFlagWidth.execute
#check KProgFormal.ClightRefinement.X86ProducerSubFlagWidth.from_call
#print axioms KProgFormal.ClightRefinement.X86ProducerSubFlagWidth.from_call
#check KProgFormal.ClightRefinement.X86ProducerSubFlagMask.source_call
#print axioms KProgFormal.ClightRefinement.X86ProducerSubFlagMask.source_call
#check KProgFormal.ClightRefinement.X86ProducerSubFlagMask.executes
#print axioms KProgFormal.ClightRefinement.X86ProducerSubFlagMask.executes
#check KProgFormal.ClightRefinement.X86ProducerSubFlagMask.arguments
#print axioms KProgFormal.ClightRefinement.X86ProducerSubFlagMask.arguments
#check KProgFormal.ClightRefinement.X86WidthSign64.internal
#print axioms KProgFormal.ClightRefinement.X86WidthSign64.internal
#check KProgFormal.ClightRefinement.X86ProducerWidthBindings.mask_binding
#print axioms KProgFormal.ClightRefinement.X86ProducerWidthBindings.mask_binding
#check KProgFormal.ClightRefinement.X86ProducerWidthBindings.sign_binding
#print axioms KProgFormal.ClightRefinement.X86ProducerWidthBindings.sign_binding
#check KProgFormal.ClightRefinement.X86ProducerSubMaskCall.invoke
#print axioms KProgFormal.ClightRefinement.X86ProducerSubMaskCall.invoke
#check KProgFormal.ClightRefinement.X86ProducerSubMaskCall.from_width
#print axioms KProgFormal.ClightRefinement.X86ProducerSubMaskCall.from_width
#check KProgFormal.ClightRefinement.X86ProducerSubMaskCall.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerSubMaskCall.execute
#check KProgFormal.ClightRefinement.X86ProducerSubMaskCall.from_call
#print axioms KProgFormal.ClightRefinement.X86ProducerSubMaskCall.from_call
#check KProgFormal.ClightRefinement.X86ProducerSubSignSetup.source_call
#print axioms KProgFormal.ClightRefinement.X86ProducerSubSignSetup.source_call
#check KProgFormal.ClightRefinement.X86ProducerSubSignSetup.executes
#print axioms KProgFormal.ClightRefinement.X86ProducerSubSignSetup.executes
#check KProgFormal.ClightRefinement.X86ProducerSubSignSetup.arguments
#print axioms KProgFormal.ClightRefinement.X86ProducerSubSignSetup.arguments
#check KProgFormal.ClightRefinement.X86ProducerSubSignCall.invoke
#print axioms KProgFormal.ClightRefinement.X86ProducerSubSignCall.invoke
#check KProgFormal.ClightRefinement.X86ProducerSubSignCall.from_masks
#print axioms KProgFormal.ClightRefinement.X86ProducerSubSignCall.from_masks
#check KProgFormal.ClightRefinement.X86ProducerSubSignCall.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerSubSignCall.execute
#check KProgFormal.ClightRefinement.X86ProducerSubSignCall.from_call
#print axioms KProgFormal.ClightRefinement.X86ProducerSubSignCall.from_call
#check KProgFormal.ClightRefinement.X86ProducerSubCfSource.source_pointer
#print axioms KProgFormal.ClightRefinement.X86ProducerSubCfSource.source_pointer
#check KProgFormal.ClightRefinement.X86ProducerSubCfSource.executes
#print axioms KProgFormal.ClightRefinement.X86ProducerSubCfSource.executes
#check KProgFormal.ClightRefinement.X86ProducerSubCfSource.binding
#print axioms KProgFormal.ClightRefinement.X86ProducerSubCfSource.binding
#check KProgFormal.ClightRefinement.X86ProducerSubCfSource.operands
#print axioms KProgFormal.ClightRefinement.X86ProducerSubCfSource.operands
#check KProgFormal.ClightRefinement.X86ProducerSubCfSource.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerSubCfSource.execute
#check KProgFormal.ClightRefinement.X86ProducerSubCfSource.from_call
#print axioms KProgFormal.ClightRefinement.X86ProducerSubCfSource.from_call
#check KProgFormal.ClightRefinement.X86ProducerSubFlagStorage.writable
#print axioms KProgFormal.ClightRefinement.X86ProducerSubFlagStorage.writable
#check KProgFormal.ClightRefinement.X86ProducerSubFlagStorage.write_current
#print axioms KProgFormal.ClightRefinement.X86ProducerSubFlagStorage.write_current
#check KProgFormal.ClightRefinement.X86ProducerSubFlagStorage.write
#print axioms KProgFormal.ClightRefinement.X86ProducerSubFlagStorage.write
#check KProgFormal.ClightRefinement.X86SubFlagValues.cf
#print axioms KProgFormal.ClightRefinement.X86SubFlagValues.cf
#check KProgFormal.ClightRefinement.X86SubFlagValues.zf
#print axioms KProgFormal.ClightRefinement.X86SubFlagValues.zf
#check KProgFormal.ClightRefinement.X86SubFlagValues.af
#print axioms KProgFormal.ClightRefinement.X86SubFlagValues.af
#check KProgFormal.ClightRefinement.X86SubFlagValues.pf_sf
#print axioms KProgFormal.ClightRefinement.X86SubFlagValues.pf_sf
#check KProgFormal.ClightRefinement.X86SubFlagValues.sf_source
#print axioms KProgFormal.ClightRefinement.X86SubFlagValues.sf_source
#check KProgFormal.ClightRefinement.X86SubFlagValues.pf_source
#print axioms KProgFormal.ClightRefinement.X86SubFlagValues.pf_source
#check KProgFormal.ClightRefinement.X86SubFlagValues.of_source
#print axioms KProgFormal.ClightRefinement.X86SubFlagValues.of_source
#check KProgFormal.ClightRefinement.X86ProducerSubCfStore.source_store
#print axioms KProgFormal.ClightRefinement.X86ProducerSubCfStore.source_store
#check KProgFormal.ClightRefinement.X86ProducerSubCfStore.source_following
#print axioms KProgFormal.ClightRefinement.X86ProducerSubCfStore.source_following
#check KProgFormal.ClightRefinement.X86ProducerSubCfStore.at_site
#print axioms KProgFormal.ClightRefinement.X86ProducerSubCfStore.at_site
#check KProgFormal.ClightRefinement.X86ProducerSubCfStore.native_value
#print axioms KProgFormal.ClightRefinement.X86ProducerSubCfStore.native_value
#check KProgFormal.ClightRefinement.X86ProducerSubCfStore.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerSubCfStore.execute
#check KProgFormal.ClightRefinement.X86ProducerSubCfStore.from_call
#print axioms KProgFormal.ClightRefinement.X86ProducerSubCfStore.from_call
#check KProgFormal.ClightRefinement.X86ProducerSubZfSource.source_pointer
#print axioms KProgFormal.ClightRefinement.X86ProducerSubZfSource.source_pointer
#check KProgFormal.ClightRefinement.X86ProducerSubZfSource.executes
#print axioms KProgFormal.ClightRefinement.X86ProducerSubZfSource.executes
#check KProgFormal.ClightRefinement.X86ProducerSubZfSource.binding
#print axioms KProgFormal.ClightRefinement.X86ProducerSubZfSource.binding
#check KProgFormal.ClightRefinement.X86ProducerSubZfSource.operands
#print axioms KProgFormal.ClightRefinement.X86ProducerSubZfSource.operands
#check KProgFormal.ClightRefinement.X86ProducerSubZfSource.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerSubZfSource.execute
#check KProgFormal.ClightRefinement.X86ProducerSubZfSource.from_call
#print axioms KProgFormal.ClightRefinement.X86ProducerSubZfSource.from_call
#check KProgFormal.ClightRefinement.X86ProducerSubZfStore.source_store
#print axioms KProgFormal.ClightRefinement.X86ProducerSubZfStore.source_store
#check KProgFormal.ClightRefinement.X86ProducerSubZfStore.source_following
#print axioms KProgFormal.ClightRefinement.X86ProducerSubZfStore.source_following
#check KProgFormal.ClightRefinement.X86ProducerSubZfStore.at_site
#print axioms KProgFormal.ClightRefinement.X86ProducerSubZfStore.at_site
#check KProgFormal.ClightRefinement.X86ProducerSubZfStore.native_value
#print axioms KProgFormal.ClightRefinement.X86ProducerSubZfStore.native_value
#check KProgFormal.ClightRefinement.X86ProducerSubZfStore.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerSubZfStore.execute
#check KProgFormal.ClightRefinement.X86ProducerSubZfStore.from_call
#print axioms KProgFormal.ClightRefinement.X86ProducerSubZfStore.from_call
#check KProgFormal.ClightRefinement.X86ProducerScalarSeparation.separate
#print axioms KProgFormal.ClightRefinement.X86ProducerScalarSeparation.separate
#check KProgFormal.ClightRefinement.X86ProducerSubSfStore.source_body
#print axioms KProgFormal.ClightRefinement.X86ProducerSubSfStore.source_body
#check KProgFormal.ClightRefinement.X86ProducerSubSfStore.source_route
#print axioms KProgFormal.ClightRefinement.X86ProducerSubSfStore.source_route
#check KProgFormal.ClightRefinement.X86ProducerSubSfStore.observations
#print axioms KProgFormal.ClightRefinement.X86ProducerSubSfStore.observations
#check KProgFormal.ClightRefinement.X86ProducerSubSfStore.at_site
#print axioms KProgFormal.ClightRefinement.X86ProducerSubSfStore.at_site
#check KProgFormal.ClightRefinement.X86ProducerSubSfStore.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerSubSfStore.execute
#check KProgFormal.ClightRefinement.X86ProducerSubSfStore.from_call
#print axioms KProgFormal.ClightRefinement.X86ProducerSubSfStore.from_call
#check KProgFormal.ClightRefinement.X86ProducerSubOfStore.source_body
#print axioms KProgFormal.ClightRefinement.X86ProducerSubOfStore.source_body
#check KProgFormal.ClightRefinement.X86ProducerSubOfStore.source_route
#print axioms KProgFormal.ClightRefinement.X86ProducerSubOfStore.source_route
#check KProgFormal.ClightRefinement.X86ProducerSubOfStore.observations
#print axioms KProgFormal.ClightRefinement.X86ProducerSubOfStore.observations
#check KProgFormal.ClightRefinement.X86ProducerSubOfStore.at_site
#print axioms KProgFormal.ClightRefinement.X86ProducerSubOfStore.at_site
#check KProgFormal.ClightRefinement.X86ProducerSubOfStore.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerSubOfStore.execute
#check KProgFormal.ClightRefinement.X86ProducerSubOfStore.from_call
#print axioms KProgFormal.ClightRefinement.X86ProducerSubOfStore.from_call
#check KProgFormal.ClightRefinement.X86ProducerSubPfStore.source_body
#print axioms KProgFormal.ClightRefinement.X86ProducerSubPfStore.source_body
#check KProgFormal.ClightRefinement.X86ProducerSubPfStore.source_route
#print axioms KProgFormal.ClightRefinement.X86ProducerSubPfStore.source_route
#check KProgFormal.ClightRefinement.X86ProducerSubPfStore.observations
#print axioms KProgFormal.ClightRefinement.X86ProducerSubPfStore.observations
#check KProgFormal.ClightRefinement.X86ProducerSubPfStore.at_site
#print axioms KProgFormal.ClightRefinement.X86ProducerSubPfStore.at_site
#check KProgFormal.ClightRefinement.X86ProducerSubPfStore.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerSubPfStore.execute
#check KProgFormal.ClightRefinement.X86ProducerSubPfStore.from_call
#print axioms KProgFormal.ClightRefinement.X86ProducerSubPfStore.from_call
#check KProgFormal.ClightRefinement.X86ProducerSubAfStore.source_body
#print axioms KProgFormal.ClightRefinement.X86ProducerSubAfStore.source_body
#check KProgFormal.ClightRefinement.X86ProducerSubAfStore.source_route
#print axioms KProgFormal.ClightRefinement.X86ProducerSubAfStore.source_route
#check KProgFormal.ClightRefinement.X86ProducerSubAfStore.observations
#print axioms KProgFormal.ClightRefinement.X86ProducerSubAfStore.observations
#check KProgFormal.ClightRefinement.X86ProducerSubAfStore.native_value
#print axioms KProgFormal.ClightRefinement.X86ProducerSubAfStore.native_value
#check KProgFormal.ClightRefinement.X86ProducerSubAfStore.at_site
#print axioms KProgFormal.ClightRefinement.X86ProducerSubAfStore.at_site
#check KProgFormal.ClightRefinement.X86ProducerSubAfStore.execute
#print axioms KProgFormal.ClightRefinement.X86ProducerSubAfStore.execute
#check KProgFormal.ClightRefinement.X86ProducerSubAfStore.from_call
#print axioms KProgFormal.ClightRefinement.X86ProducerSubAfStore.from_call

#check Arm64MemsetReturn.locals_source
#print axioms Arm64MemsetReturn.locals_source
#check Arm64MemsetReturn.continuation_source
#print axioms Arm64MemsetReturn.continuation_source
#check Arm64MemsetReturn.free
#print axioms Arm64MemsetReturn.free
#check Arm64MemsetReturn.exit
#print axioms Arm64MemsetReturn.exit
#check Arm64MemsetFreeState.local_load
#print axioms Arm64MemsetFreeState.local_load
#check Arm64MemsetFreeState.storage
#print axioms Arm64MemsetFreeState.storage
#check Arm64MemsetFreeState.header
#print axioms Arm64MemsetFreeState.header
#check Arm64MemsetFreeState.tail
#print axioms Arm64MemsetFreeState.tail
#check Arm64MemsetFreeState.gpr
#print axioms Arm64MemsetFreeState.gpr
#check Arm64MemsetFreeState.flag
#print axioms Arm64MemsetFreeState.flag
#check Arm64MemsetFreeState.resources
#print axioms Arm64MemsetFreeState.resources
#check Arm64MemsetFreeState.ready
#print axioms Arm64MemsetFreeState.ready
#check Arm64MemsetFreeState.complete
#print axioms Arm64MemsetFreeState.complete
#check Arm64MemsetComplete.original
#print axioms Arm64MemsetComplete.original
#check Arm64MemsetProgramCaller.source
#print axioms Arm64MemsetProgramCaller.source
#check Arm64MemsetProgramCaller.next_source
#print axioms Arm64MemsetProgramCaller.next_source
#check Arm64MemsetProgramCaller.call_source
#print axioms Arm64MemsetProgramCaller.call_source
#check Arm64MemsetProgramCaller.binding
#print axioms Arm64MemsetProgramCaller.binding
#check Arm64MemsetProgramCaller.ready
#print axioms Arm64MemsetProgramCaller.ready
#check Arm64MemsetProgramCaller.returned
#print axioms Arm64MemsetProgramCaller.returned
#check Arm64MemsetProgramCaller.original
#print axioms Arm64MemsetProgramCaller.original
