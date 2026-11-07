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
static uint64_t random64(uint64_t &s) {s^=s<<13;s^=s>>7;s^=s<<17;return s;}
static uint64_t native_read(uint64_t v,unsigned bytes,unsigned shift) {
 uint64_t out;
 if(bytes==1 && shift==8) {asm("movzbl %h1, %k0":"=a"(out):"b"(v));return out;}
 if(bytes==1) {asm("movzbl %b1, %k0":"=a"(out):"b"(v));return out;}
 if(bytes==2) {asm("movzwl %w1, %k0":"=a"(out):"b"(v));return out;}
 if(bytes==4) {asm("movl %k1, %k0":"=a"(out):"b"(v));return out;}
 asm("movq %1, %0":"=a"(out):"b"(v));return out;
}
static uint64_t byte_oracle(uint64_t value,unsigned bytes,unsigned shift) {
 std::array<uint8_t,8> encoded{};std::memcpy(encoded.data(),&value,8);
 unsigned start=bytes==1?shift/8:0;uint64_t result=0;
 for(unsigned i=0;i<bytes;i++)result|=uint64_t(encoded[start+i])<<(8*i);
 return result;
}
int main(int argc,char **argv) {
 if(argc!=2)return 2;std::string root=argv[1];
 std::ofstream table(root+"/forms.tsv"),bad(root+"/mismatches.jsonl");
 table<<"variant\tform\twidth_argument\tbytes\tbyte_shift\tguarded\tcases\tguard_taken\tjit_vs_bytes\tnative_vs_bytes\thost_vs_bytes\tjit_vs_native\tmemory_writes\n";
 uint64_t total=0,failures=0;
 constexpr unsigned exhaustive=4*65536,random_cases=65536,positive=8192,count=exhaustive+random_cases+positive;
 for(const auto &variant:{"before","candidate"})for(const auto &c:cases) {
  std::ifstream file(root+"/"+variant+"/"+c.name+".bin",std::ios::binary);
  std::vector<uint8_t> code((std::istreambuf_iterator<char>(file)),{});
  if(code.empty())return 3;bpftime::llvmbpf_vm vm;
  if(vm.load_code(code.data(),code.size())<0||!vm.compile()) {std::cerr<<variant<<" "<<c.name<<" "<<vm.get_error_message()<<"\n";return 4;}
  uint64_t state=0x6b70726f67460001ULL,jb=0,nb=0,hb=0,jn=0,mw=0,taken=0;
  for(unsigned i=0;i<count;i++) {
   Frame frame{};uint64_t value;
   const uint64_t upper[]={0,0xffffffffffff0000ULL,0x8000000000000000ULL,0xaaaaaaaaaaaa0000ULL};
   if(i<exhaustive)value=upper[i/65536]|(i&65535);
   else {
    value=random64(state);
    if(i>=exhaustive+random_cases) {
     unsigned shift=c.bytes==1?c.shift:0;uint64_t mask=c.bytes==8?~uint64_t(0):((uint64_t(1)<<(8*c.bytes))-1);
     value=(value&~(mask<<shift))|(uint64_t(i&15)<<shift);
    }
   }
   frame.value=value;for(auto &x:frame.table)x=uint32_t(random64(state));for(auto &x:frame.canary)x=random64(state);
   const Frame before=frame;
   uint64_t small=byte_oracle(value,c.bytes,c.shift),narrow=native_read(value,c.bytes,c.shift);
   taken+=c.guard && small<=15;
   uint64_t want=c.guard?(small<=15?uint32_t(uint64_t(frame.table[small])+(value>>8)):0):small;
   uint64_t native=c.guard?(narrow<=15?uint32_t(uint64_t(frame.table[narrow])+(value>>8)):0):narrow;
   uint64_t host=c.host(&frame),jit=0;
   if(vm.exec(&frame,sizeof(frame),jit)<0)return 5;
   bool j=jit!=want,n=native!=want,h=host!=want,x=jit!=native,m=std::memcmp(&frame,&before,sizeof(frame));
   jb+=j;nb+=n;hb+=h;jn+=x;mw+=m;
   if(j||n||h||x||m) {
    bad<<"{\"variant\":\""<<variant<<"\",\"form\":\""<<c.name<<"\",\"sample\":"<<i<<",\"value\":"<<value<<",\"expected\":"<<want<<",\"native\":"<<native<<",\"host\":"<<host<<",\"jit\":"<<jit<<",\"memory_write\":"<<m<<",\"table\":[";
    for(unsigned k=0;k<16;k++)bad<<(k?",":"")<<before.table[k];
    bad<<"],\"canary\":[";for(unsigned k=0;k<4;k++)bad<<(k?",":"")<<before.canary[k];bad<<"]}\n";
   }
  }
  table<<variant<<"\t"<<c.name<<"\t"<<c.width<<"\t"<<c.bytes<<"\t"<<c.shift<<"\t"<<c.guard<<"\t"<<count<<"\t"<<taken<<"\t"<<jb<<"\t"<<nb<<"\t"<<hb<<"\t"<<jn<<"\t"<<mw<<"\n";
  total+=count;failures+=jb+nb+hb+jn+mw;
 }
 std::cout<<"forms=40 states="<<total<<" aggregate_differences="<<failures<<"\n";
 return failures?1:0;
}
