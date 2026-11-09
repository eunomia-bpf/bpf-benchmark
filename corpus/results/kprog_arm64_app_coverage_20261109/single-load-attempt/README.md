AArch64 shared first-attempt loader build

The coordinator08:50 decision supplies the existing16MiB diagnostic buffer on the first BPF_PROG_LOAD and retains that call FD/error. Shared sourcefb23a234d is captured atd99b636c40fc7a04bd5d28fca14d3f6cf7a58047. The existing ARM CMake object cache builds native_loader, native_loader_shared, trusted-native-loader and trusted-service-client incrementally. Make exit:0. Source hashes, exact build logs, recipes and successful runtime outputs accompany this report. The active paired BCC guest retains its captured runtime; the successor loader serves subsequent replay cohorts. Guest verifier/native execution outcomes follow separately. Runtime admission additions:0.

The terminal collector records and repairs a local variable-name collision after compilation and archive creation; completed build outputs retain their captured hashes.
