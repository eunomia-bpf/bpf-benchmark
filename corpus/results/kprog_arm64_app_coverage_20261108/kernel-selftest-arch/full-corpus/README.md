Complete ARM upstream annotated C compiler cohort

The existing architecture-enabled selftest script visits all1917 annotations, including657 C bodies and1260 BPF inline-assembly bodies. It compiles each C body with the same upstream source and kernel annotation metadata, using the retained ARM kernel type header and corpus Armv8.1-LSE ABI. Actual loop exit0.

Native compilation succeeds for382 C bodies;380 native entries are present. Companion BPF objects are available for378 bodies. Every source row, native/BPF compiler diagnostic and entry-presence outcome remains in programs.json. The two native entries absent after preprocessing are dummy_test in verifier_gotol.c and verifier_sdiv.c. Compiler and symbol outcomes supply the input census for R kernel sweep. R owns stock verifier/native execution and annotation agreement; those outcomes have their own records.

inputs.tar.gz retains the full generated C/native/BPF build population, exact type header and source driver. compiler.log.gz and summary.json retain actual terminal status and counts.
