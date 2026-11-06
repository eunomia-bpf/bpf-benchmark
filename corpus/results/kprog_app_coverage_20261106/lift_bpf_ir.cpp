/* Pure bytecode-to-IR frontend for runtime-created programs without source ELF. */
#include <linux/bpf.h>
#include "lift_bpf_ir_backend.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include <climits>
#include <map>
#include <sstream>
#include <iomanip>
int main(int argc,char **argv) {
    if(argc!=3){std::cerr<<"usage: lift-bpf-ir RAW-BPF OUTPUT.ll\n";return 1;}
    std::ifstream input(argv[1],std::ios::binary);
    if(!input){std::cerr<<"open BPF input failed\n";return 1;}
    std::vector<uint8_t> bytes((std::istreambuf_iterator<char>(input)),{});
    if(input.bad() || bytes.empty() || bytes.size()%sizeof(bpf_insn)) {
        std::cerr<<"BPF input is not a nonempty complete instruction array\n";return 1;
    }
    std::set<unsigned> helpers;
    for(size_t offset=0;offset<bytes.size();offset+=sizeof(bpf_insn)) {
        bpf_insn insn;std::memcpy(&insn,bytes.data()+offset,sizeof(insn));
        if(insn.code==(BPF_JMP|BPF_CALL)) {
            if(insn.src_reg==BPF_PSEUDO_KFUNC_CALL) {
                std::cerr<<"typed kfunc lifting requires its source BTF prototype\n";return 1;
            }
            if(insn.src_reg==0) {
                if(insn.imm<=0){std::cerr<<"invalid helper ID\n";return 1;}
                helpers.insert(static_cast<unsigned>(insn.imm));
            }
        }
    }
    const size_t count=bytes.size()/sizeof(bpf_insn);
    if(count>UINT16_MAX){std::cerr<<"LLVM source frontend PC width exceeded\n";return 1;}
    std::vector<bpf_insn> code(count);std::memcpy(code.data(),bytes.data(),bytes.size());
    std::set<unsigned> starts{0};
    for(size_t pc=0;pc<count;++pc) {
        const auto &insn=code[pc];
        if(insn.code==(BPF_LD|BPF_DW|BPF_IMM) && insn.src_reg==BPF_PSEUDO_FUNC) {
            std::cerr<<"function-address lowering requires its symbolic target relocation\n";return 1;
        }
        if(insn.code!=(BPF_JMP|BPF_CALL) || insn.src_reg!=BPF_PSEUDO_CALL)continue;
        const int64_t target=static_cast<int64_t>(pc)+1+insn.imm;
        if(target<0 || target>=static_cast<int64_t>(count)){std::cerr<<"local call target out of source range\n";return 1;}
        starts.insert(static_cast<unsigned>(target));
    }
    std::map<unsigned,unsigned> identifiers;
    std::map<unsigned,std::string> calls;
    unsigned id=INT_MAX;
    for(unsigned pc:starts) {
        while(helpers.contains(id))--id;
        std::ostringstream name;name<<"__llvmbpf_pseudo_call_pc_"<<std::hex<<std::setw(8)<<std::setfill('0')<<pc;
        identifiers[pc]=id;calls[id]=pc?name.str():"bpf_main";--id;
    }
    std::vector<LiftFunction> functions;
    for(auto it=starts.begin();it!=starts.end();++it) {
        const unsigned start=*it;const auto next=std::next(it);
        const unsigned end=next==starts.end()?count:*next;
        std::vector<bpf_insn> body(code.begin()+start,code.begin()+end);
        for(size_t local=0;local<body.size();++local) {
            auto &insn=body[local];
            if(insn.code==(BPF_JMP|BPF_CALL) && insn.src_reg==BPF_PSEUDO_CALL) {
                const auto target=static_cast<unsigned>(start+local+1+insn.imm);
                insn.src_reg=0;insn.imm=identifiers.at(target);
            }
        }
        LiftFunction function{start,calls.at(identifiers.at(start)),{}};
        function.bytes.resize(body.size()*sizeof(bpf_insn));
        std::memcpy(function.bytes.data(),body.data(),function.bytes.size());
        functions.push_back(std::move(function));
    }
    return lift_bpf_module(functions,helpers,calls,argv[2]);
}
