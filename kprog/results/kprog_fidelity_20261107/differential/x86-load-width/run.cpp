#include <llvmbpf.hpp>
#include <array>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include "cases.h"
static uint64_t rng(uint64_t &s) {
 s=s*6364136223846793005ULL+1442695040888963407ULL;return s;
}
int main(int argc,char **argv) {
 if(argc!=2) return 2;
 std::string root=argv[1];
 std::ofstream rows(root+"/forms.tsv"), bad(root+"/mismatches.jsonl");
 rows<<"variant\tform\twidth_argument\tbytes\tdisplacement\tcases\tjit_vs_bytes\thost_vs_bytes\tjit_vs_host\tmemory_writes\n";
 uint64_t total=0,fail=0;
 for(const auto &variant:{"before","current"}) for(const auto &c:cases) {
  std::ifstream f(root+"/"+variant+"/"+c.name+".bin",std::ios::binary);
  std::vector<uint8_t> code((std::istreambuf_iterator<char>(f)),{});
  if(code.empty()) return 3;
  bpftime::llvmbpf_vm vm;
  if(vm.load_code(code.data(),code.size())<0||!vm.compile()) {
   std::cerr<<variant<<" "<<c.name<<" "<<vm.get_error_message()<<"\n";return 4;
  }
  uint64_t jb=0,hb=0,jh=0,mw=0,n=0,s=0x12345678;
  std::array<uint8_t,65560> mem{},before{};
  for(unsigned align=0;align<8;align++) for(unsigned i=0;i<1024;i++) {
   uint8_t *base=mem.data()+32768+align;
   uint8_t *at=base+c.disp;
   for(unsigned k=0;k<8;k++)
    at[k]=i==0?0:i==1?255:i==2?128:i==3?(k&1?0xaa:0x55):uint8_t(rng(s)>>33);
   before=mem;
   uint64_t want=0;
   for(unsigned k=0;k<c.bytes;k++)want|=uint64_t(at[k])<<(8*k);
   uint64_t cpu=c.host(base),got=0;
   if(vm.exec(base,mem.size()-32768-align,got)<0) return 5;
   bool j=got!=want,h=cpu!=want,x=got!=cpu,m=mem!=before;
   jb+=j;hb+=h;jh+=x;mw+=m;n++;
   if(j||h||x||m) {
    bad<<"{\"variant\":\""<<variant<<"\",\"form\":\""<<c.name<<"\",\"alignment\":"<<align<<",\"sample\":"<<i<<",\"input\":[";
    for(unsigned k=0;k<8;k++)bad<<(k?",":"")<<unsigned(before[32768+align+c.disp+k]);
    bad<<"],\"expected\":"<<want<<",\"cpu\":"<<cpu<<",\"jit\":"<<got<<",\"memory_write\":"<<m<<"}\n";
   }
  }
  rows<<variant<<"\t"<<c.name<<"\t"<<c.width<<"\t"<<c.bytes<<"\t"<<c.disp<<"\t"<<n<<"\t"<<jb<<"\t"<<hb<<"\t"<<jh<<"\t"<<mw<<"\n";
  total+=n;fail+=jb+hb+jh+mw;
 }
 std::cout<<"states="<<total<<" aggregate_differences="<<fail<<"\n";
 return fail?1:0;
}
