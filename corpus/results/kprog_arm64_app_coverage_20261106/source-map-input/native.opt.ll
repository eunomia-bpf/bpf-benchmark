; ModuleID = '/workspaces/repository/corpus/results/kprog_app_coverage_20261106/startup-lift/bcc_map_value/native.ll'
source_filename = "bpf-source"

@__native_source_map_0 = external local_unnamed_addr global i8

; Function Attrs: mustprogress nofree norecurse nosync nounwind willreturn memory(write, argmem: none, inaccessiblemem: none)
define noundef i64 @bpf_main(ptr nocapture readnone %0) local_unnamed_addr #0 {
setupBlock:
  store i64 42, ptr @__native_source_map_0, align 8
  ret i64 0
}

attributes #0 = { mustprogress nofree norecurse nosync nounwind willreturn memory(write, argmem: none, inaccessiblemem: none) }
