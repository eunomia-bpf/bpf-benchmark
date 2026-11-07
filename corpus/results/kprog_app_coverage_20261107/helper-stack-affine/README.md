# Generic affine transport of helper stack origins

The common native ABI analysis carries finite private-stack offset alternatives
and an external-pointer case through constant displacement, known scaled index
and64-bit ADD/SUB constants. Helper copy effects therefore receive every
translated origin. Opaque-byte taint and the external case retain their existing
conservative merge. Variable-index unresolved origins keep the existing error.
The C simulator, architectural flags, native input bytes and compiler settings
retain their captured semantics and values.

The generic checker passes141 encoder/ABI cases, including nine new controls:
four affine forms with defined data, the same four forms carrying unspecified
ABI bytes, and a variable-index origin control. The earlier implementation is
detected by the positive affine control. Existing3072 CL host/UBSan cases,
19 rendered MOVX host/BPF cases and context/width/REX controls also pass.

These tests support the generic analysis implementation. The universal ABI
bridge retains the finite-set translation and helper-copy taint preservation
law as its formal responsibility. Whole Tetragon and helper-preserving Tracee
application replays follow this source adoption through the common service.

observations.json records the counts and source identities. raw.tar.gz retains
both source versions/patches, the generic check runner, terminal output,
prior-control outcome and compiled generic fixture directory contents.
