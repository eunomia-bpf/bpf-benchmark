# Offline frozen-scalar folding probe

The staged P reproduces the exact captured selected-entry proof (SHA equality). Both compiler invocations use that same input, the same existing compiler and common x86 backend policy, and no PERF context conversion. Only the actual frozen scalar facts differ. No live image, native installation, benchmark, kernel, producer or core loader change.

no-facts: object 156712 bytes; debug helper relocations 106; debug symbol present True.

   text	   data	    bss	    dec	    hex	filename
  29668	   1404	      0	  31072	   7960	/workspaces/kprog-raw/perf/x86-otel-perf-20261127/frozen-ir-20261127T193558Z/no-facts.o

frozen-facts: object 118200 bytes; debug helper relocations 0; debug symbol present False.

   text	   data	    bss	    dec	    hex	filename
  13090	   1404	      0	  14494	   389e	/workspaces/kprog-raw/perf/x86-otel-perf-20261127/frozen-ir-20261127T193558Z/frozen-facts.o


The facts remove the debug-print helper entirely. Object size includes data and metadata; it is not installed native bytes. This is a compiler opportunity, not execution equivalence or a performance gain. Next implement the common allowed linker/header route, preserve actual bound data semantics and check the installed code with the frozen 10-second recipe. The frozen core loader remains unchanged.
