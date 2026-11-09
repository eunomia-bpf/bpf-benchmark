Numeric ELF map identities

The shared metadata grammar accepts numeric-leading ELF identities, including kernel map names derived from hashed source filenames. The existing C alias mechanism retains each ELF name through an asm label and supplies a C identifier to the emitter. This removes the first-character restriction that stopped 23 initial census rows.

All 23 captured kernel metadata/facts pairs now normalize through the same service function. Their map declarations compile with Clang 18, and the resulting ELF symbol tables retain all original map names. These are metadata and map-declaration outcomes; simulator generation, program compilation and stock-verifier stages retain their own actual counts. The existing TrustedMetadata unit group passes. Application program loads: 0; native execution requests: 0. Runtime admission predicates added: 0.
