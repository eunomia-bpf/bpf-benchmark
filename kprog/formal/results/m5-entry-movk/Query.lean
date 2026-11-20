import KProgFormal.ClightRefinement.Arm64ProgramEntryMovCall

open KProgFormal.ClightRefinement

#check Arm64MovKeep.mergeWord_low16
#print axioms Arm64MovKeep.mergeWord_low16

#check Arm64MovKeep.after_read_word_bound
#print axioms Arm64MovKeep.after_read_word_bound

#check Arm64MovKeep.writer_call_word_bound
#print axioms Arm64MovKeep.writer_call_word_bound

#check Arm64MovKeep.scalar_writer_call_word_bound
#print axioms Arm64MovKeep.scalar_writer_call_word_bound

#check Arm64MovKeep.call_scalar_word_returns_bound
#print axioms Arm64MovKeep.call_scalar_word_returns_bound

#check Arm64MovKeep.call_scalar_returns_bound
#print axioms Arm64MovKeep.call_scalar_returns_bound

#check Arm64MovKeep.LinkedWord.call
#print axioms Arm64MovKeep.LinkedWord.call

#check Arm64ProgramEntryMovCall.keep_aux_eval
#print axioms Arm64ProgramEntryMovCall.keep_aux_eval

#check Arm64ProgramEntryMovCall.keep_enter
#print axioms Arm64ProgramEntryMovCall.keep_enter

#check Arm64ProgramEntryMovCall.keep_leave
#print axioms Arm64ProgramEntryMovCall.keep_leave

#check Arm64ProgramEntryMovCall.execute_keep
#print axioms Arm64ProgramEntryMovCall.execute_keep

#check Arm64ProgramEntryMovCall.execute
#print axioms Arm64ProgramEntryMovCall.execute
