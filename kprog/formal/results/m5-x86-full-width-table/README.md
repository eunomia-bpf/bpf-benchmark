The two actual32/64-bit table stores implement native whole-register
writeback and scalarize the selected ordinary row. Every other register
retains its raw word, tag and pointer origin, regardless of the overwritten
row representation. Initial table permissions construct both stores, native
GPR correspondence, unchanged access/frontier and other-block load frame.

Focused build166 and two public type/axiom queries pass at original
200000/512,j1,32GiB inside shared timing. These memory/native-view theorems
use only standard logical axioms. The actual Clight table caller is next.
