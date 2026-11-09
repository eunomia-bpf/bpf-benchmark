"""Exercise the production decoder and module pair fields on assembler words."""
from pathlib import Path
import subprocess,sys
R=Path(__file__).resolve().parents[3]
O=Path(sys.argv[1]);O.mkdir(parents=True,exist_ok=True)
rust=(R/'kprog/x86/native_lab/native_link/src/main.rs').read_text()
body=rust[rust.index('fn arm64_load_destination('):rust.index('fn arm64_decoded_load_sites(')]
words=[(0x08207c82,0),(0x48207c82,0),(0xc8a07c81,0),(0x88a07c81,0),(0x08a07c81,0),(0x48a07c81,0),
       (0xc8227c23,None),(0xc87f7c20,0),(0x88227c23,None),(0x887f7c20,0)]
tests='\n'.join(f'if arm64_load_destination(0x{w:08x}) != '+('None' if d is None else f'Some({d})')+f' {{ eprintln!("word {w:08x} destination {{:?}}",arm64_load_destination(0x{w:08x})); errors+=1; }}' for w,d in words)
(O/'decoder.rs').write_text(body+'fn main() { let mut errors=0;'+tests+' println!("arm64 production load-site decoder: {} words, {} discrepancies",10,errors); std::process::exit(if errors==0 {0} else {1}); }')
subprocess.run(['rustc','-O',str(O/'decoder.rs'),'-o',str(O/'decoder')],check=True)
res=subprocess.run([str(O/'decoder')])
c=(R/'kinsn/module/arm64/bpf_arm64_native_lab.c').read_text();start=c.index('        if ((word & 0x3e400000U)');end=c.index('        if (pair)',start)
block=c[start:end]
driver='#include <stdint.h>\n#include <stdio.h>\n#include <stdbool.h>\ntypedef uint32_t u32;\nstatic unsigned pair_field(u32 word,u32 reg) { u32 second=31;bool pair=false;'+block+'return pair?second+32:0; }\nint main(void) { unsigned errors=0;'
for w,e in [(0x08207c82,33),(0x48207c82,33),(0xc8227c23,0),(0x88227c23,0),(0xc87f7c20,63),(0x887f7c20,63)]:
 driver+=f'if(pair_field(0x{w:08x},0)!={e}) {{ ++errors;printf("word {w:08x} pair field %u\\n",pair_field(0x{w:08x},0));}}'
driver+='printf("arm64 production pair metadata: 6 words, %u discrepancies\\n",errors);return !!errors;}'
(O/'pairs.c').write_text(driver)
subprocess.run(['gcc','-O2',str(O/'pairs.c'),'-o',str(O/'pairs')],check=True)
pairs=subprocess.run([str(O/'pairs')])
raise SystemExit(int(bool(res.returncode or pairs.returncode)))
