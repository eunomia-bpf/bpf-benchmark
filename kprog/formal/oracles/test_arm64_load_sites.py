"""Exercise the production decoder and module pair fields on assembler words."""
from pathlib import Path
import subprocess,sys
R=Path(__file__).resolve().parents[3]
O=Path(sys.argv[1]);O.mkdir(parents=True,exist_ok=True)
rust=(R/'kprog/x86/native_lab/native_link/src/main.rs').read_text()
body=rust[rust.index('fn arm64_load_destination('):rust.index('fn rewrite_arm64(')]
body='#[derive(Debug,PartialEq)] struct LoadSite {offset:u32,insn_len:u16,destination:u16}\n'+body
words=[(0x08207c82,0),(0x48207c82,0),(0xc8a07c81,0),(0x88a07c81,0),(0x08a07c81,0),(0x48a07c81,0),
       (0xc8227c23,None),(0xc87f7c20,0),(0x88227c23,None),(0x887f7c20,0)]
tests='\n'.join(f'if arm64_load_destination(0x{w:08x}) != '+('None' if d is None else f'Some({d})')+f' {{ eprintln!("word {w:08x} destination {{:?}}",arm64_load_destination(0x{w:08x})); errors+=1; }}' for w,d in words)
collector='let mut blob=0xc8227c23u32.to_le_bytes().to_vec();blob.extend(0xc87f7c20u32.to_le_bytes());blob.extend(0x08207c82u32.to_le_bytes());if arm64_decoded_load_sites(&blob,2)!=vec![LoadSite{offset:4,insn_len:4,destination:0}]{errors+=1;eprintln!("code range metadata differs");}'
(O/'decoder.rs').write_text(body+'fn main() { let mut errors=0;'+tests+collector+' println!("arm64 production load-site decoder: {} words plus final-code range, {} discrepancies",10,errors); std::process::exit(if errors==0 {0} else {1}); }')
subprocess.run(['rustc','--edition=2021','-O',str(O/'decoder.rs'),'-o',str(O/'decoder')],check=True)
res=subprocess.run([str(O/'decoder')])
pair_exit=0
for label,source in [('legacy','kinsn/module/arm64/bpf_arm64_native_lab.c'),('stock','kprog/stock-path/module/kprog_stock.c')]:
    c=(R/source).read_text();start=c.index('if ((word & 0x3e400000U)');end=c.index('if (pair)',start)
    block=c[start:end]
    driver='#include <stdint.h>\n#include <stdio.h>\n#include <stdbool.h>\ntypedef uint32_t u32;\nstatic unsigned pair_field(u32 word,u32 reg) { u32 second=31;bool pair=false;'+block+'return pair?second+32:0; }\nint main(void) { unsigned errors=0;'
    for w,e in [(0x08207c82,33),(0x48207c82,33),(0xc8227c23,0),(0x88227c23,0),(0xc87f7c20,63),(0x887f7c20,63)]:
     driver+=f'if(pair_field(0x{w:08x},0)!={e}) {{ ++errors;printf("word {w:08x} pair field %u\\n",pair_field(0x{w:08x},0));}}'
    driver+='printf("arm64 production pair metadata: 6 words, %u discrepancies\\n",errors);return !!errors;}'
    (O/(label+'-pairs.c')).write_text(driver)
    subprocess.run(['gcc','-O2',str(O/(label+'-pairs.c')),'-o',str(O/(label+'-pairs'))],check=True)
    pair_exit |= subprocess.run([str(O/(label+'-pairs'))]).returncode
raise SystemExit(int(bool(res.returncode or pair_exit)))
