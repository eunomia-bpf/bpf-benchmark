; ModuleID = '/workspaces/repository/corpus/results/kprog_arm64_app_coverage_20261106/startup-stack-frame-v9/startup_6.ll'
source_filename = "bpf-source"

define i64 @bpf_main(ptr nocapture readnone %0) local_unnamed_addr {
setupBlock:
  %stackBegin2 = alloca [8 x i8], align 8
  %stackEnd = getelementptr inbounds i8, ptr %stackBegin2, i64 8
  %1 = ptrtoint ptr %stackEnd to i64
  %2 = add i64 %1, -8
  %3 = call i64 @bpf_probe_read_kernel(i64 %2, i64 8, i64 0)
  ret i64 %3
}

declare i64 @bpf_probe_read_kernel(i64, i64, i64) local_unnamed_addr
