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

