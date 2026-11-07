# Completed older OTel compiler queue

The preserved older native input completed all 14 candidates: 10 compile and
four abort in LLVM. All compiler records, stderr, source/object hashes and the
native ELF hash are retained. The failed old driver stopped before link/install
or application execution. This is a compiler result, separate from the active
new-input v36 queue, and establishes no verifier or application success.

Under the cleanup order, old v18 raw objects/IR and its v15 frozen input files
are retired after this summary is committed. The current v36 compiler cache,
canonical native linker and shared component caches remain.
