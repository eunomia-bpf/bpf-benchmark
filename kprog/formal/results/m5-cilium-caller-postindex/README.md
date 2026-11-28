# Original caller post-index loop

The original statement after the memory writer retains both pointer-writer
call branches. Its actual encoded addressing flag has bit2 clear: the first
conditional selects zero, the original cast sets the signed post-index
temporary to zero, and the original nonzero test skips both call branches.

Eleven actual internal transitions execute this loop and return to its
supplied continuation. The complete heap, caller environment and all
temporaries except t210 and l_pp__1 remain. No SP load, writer call or
post-index memory change occurs on this source path. The statement and
condition certificates inspect the retained original Clight AST.

This is a local continuation proof in the actual linked world. The preceding
provider/writer outcome theorem retains its explicit supplied resources;
whole-entry width/resource composition and native/global refinement remain
open. M6 follows completion and recount of M5.
