# Roots hidden by generated memory-base barriers

Read-only inspection of retained checked-native IR after ff02957cc, using
LLVM's existing getUnderlyingObjectsForCodeGen analysis on the pointer
before each generated register barrier. Counts distinguish provable private
arena roots from other or unknown roots. This diagnoses whether a narrower
barrier rule can expose stack aliases while preserving the absolute-address
contract; it changes no production source and supplies no runtime result.
