The first compile of bcc_capable_kprobe__cap_capable_exit overlapped the
initial header-freezing rewrite of its source file. Clang memory-mapped the
file while it changed, producing syntax/UTF-8 errors and a frontend crash.
The complete original compiler record is retained here. Later compile
invocations use an immutable per-case source copy and retry this case.
