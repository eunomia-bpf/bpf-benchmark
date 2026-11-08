# Use the stack index origin for helper frame erasure

The raw stack index is `offset + capacity`. Helper-frame metadata erasure now translates an arena word back with `word_index*8 - capacity`, using that same origin. The previous `capacity-8` translation retained metadata for the word immediately below the current SP. Native helpers may use that deallocated space. Allocated caller words retain their original facts; every native byte and raw operation keeps its existing representation.

The before control compiles0 and reports the boundary mismatch at SP-120/slot-128. The corrected model passes3872 word/SP/helper boundary scenes with ASan/UBSan, including byte-granular SP positions and both existing readonly helper result forms. Existing native pointer-byte52992 and lifetime552 cases pass ASan/UBSan, and the existing29+1micro generation/compiler target exits0. This repairs the arithmetic in an existing metadata predicate. Runtime admission additions0.

The archived Makefile/run.py and micro.py reproduce these observations. Original and corrected headers, commands, generated C/BPF and actual diagnostics are retained. Existing app queues keep their captured source epochs; the serial Tetragon successor uses the corrected source snapshot.
