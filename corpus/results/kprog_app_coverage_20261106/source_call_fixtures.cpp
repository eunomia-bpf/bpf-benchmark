/* Source-call ABI regression inputs: all five args, saved R6, backwards calls. */
#include <linux/bpf.h>
#include <filesystem>
#include <fstream>
#include <vector>
#include <cstdint>
#include <iostream>
static bpf_insn insn(unsigned code,unsigned dst=0,unsigned src=0,int imm=0) {
    bpf_insn out{};out.code=code;out.dst_reg=dst;out.src_reg=src;out.imm=imm;return out;
}
static auto mov(unsigned dst,int value){return insn(BPF_ALU64|BPF_MOV|BPF_K,dst,0,value);}
static auto ret(){return insn(BPF_JMP|BPF_EXIT);}
static auto call(int displacement){return insn(BPF_JMP|BPF_CALL,0,BPF_PSEUDO_CALL,displacement);}
static void arguments(std::vector<bpf_insn> &body){for(unsigned i=1;i<=5;++i)body.push_back(mov(i,11*i));}
static void sum(std::vector<bpf_insn> &body){
    body.push_back(insn(BPF_ALU64|BPF_MOV|BPF_X,0,1));
    for(unsigned i=2;i<=5;++i)body.push_back(insn(BPF_ALU64|BPF_ADD|BPF_X,0,i));
}
int main(int argc,char **argv) {
    if(argc!=2)return 2;
    std::filesystem::create_directories(argv[1]);
    auto write=[&](const char *name,const std::vector<bpf_insn> &code){
        std::ofstream out(std::filesystem::path(argv[1])/(std::string(name)+".bpf.bin"),std::ios::binary);
        out.write(reinterpret_cast<const char*>(code.data()),code.size()*sizeof(bpf_insn));
        if(!out)throw std::runtime_error("source fixture write failed");
    };
    std::vector<bpf_insn> simple;arguments(simple);simple.push_back(call(1));simple.push_back(ret());sum(simple);simple.push_back(ret());write("five_args",simple);
    std::vector<bpf_insn> saved{mov(6,12)};arguments(saved);saved.push_back(call(2));
    saved.push_back(insn(BPF_ALU64|BPF_ADD|BPF_X,0,6));saved.push_back(ret());sum(saved);saved.push_back(mov(6,99));saved.push_back(ret());write("saved_r6",saved);
    std::vector<bpf_insn> back;arguments(back);back.push_back(call(7));back.push_back(ret());
    sum(back);back.push_back(ret()); // A at7, B at13, B calls A backwards.
    arguments(back);back.push_back(call(-12));back.push_back(ret());write("backwards",back);
    std::cout<<"wrote three source-call ABI regression inputs\n";
}
