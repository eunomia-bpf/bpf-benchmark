/* Pure bytecode-to-IR frontend for runtime-created programs without source ELF. */
#include <linux/bpf.h>
#include <array>
#include <deque>
#include <optional>
#include <algorithm>
#include <stdexcept>
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
// Track only possible frame-relative address ranges, never values/conditions.
// Unknown stack arithmetic and stack pointers passed to local functions retain
// the entire architectural frame. No byte is initialized by this analysis.
unsigned source_stack_extent(const LiftFunction &function,
    const std::map<unsigned,std::string> &calls, unsigned frame_capacity) {
    const int64_t frame_limit=frame_capacity;
    using Range=std::optional<std::pair<int64_t,int64_t>>;
    using State=std::array<Range,11>;
    std::vector<bpf_insn> code(function.bytes.size()/sizeof(bpf_insn));
    std::memcpy(code.data(),function.bytes.data(),function.bytes.size());
    std::vector<std::optional<State>> states(code.size());
    State initial{};initial[10]=std::pair<int64_t,int64_t>{0,0};states[0]=initial;
    std::deque<size_t> queue{0};unsigned required=1;
    const auto whole=std::pair<int64_t,int64_t>{-frame_limit,0};
    auto bound=[&](int64_t low,int64_t high) {
        return low < -frame_limit || high > 0 ? whole : std::pair{low,high};
    };
    auto observe=[&](const Range &range,int64_t displacement=0) {
        if(range)required=std::max(required,static_cast<unsigned>(
            -std::min<int64_t>(0,std::max<int64_t>(-frame_limit,range->first+displacement))));
    };
    auto push=[&](int64_t target,const State &state) {
        if(target<0 || target>=static_cast<int64_t>(code.size()))
            throw std::runtime_error("source frame CFG target out of function range");
        auto &old=states[static_cast<size_t>(target)];
        State joined=old?*old:state;
        if(old)for(size_t reg=0;reg<joined.size();++reg) {
            if(!state[reg])continue;
            if(!joined[reg])joined[reg]=state[reg];
            else joined[reg]=std::pair{std::min(joined[reg]->first,state[reg]->first),
                                      std::max(joined[reg]->second,state[reg]->second)};
        }
        if(!old || joined!=*old){old=joined;queue.push_back(static_cast<size_t>(target));}
    };
    while(!queue.empty()) {
        const size_t pc=queue.front();queue.pop_front();
        State state=*states[pc];const auto insn=code[pc];
        if(insn.dst_reg>10 || insn.src_reg>10)throw std::runtime_error("source frame invalid register");
        const auto cls=BPF_CLASS(insn.code),op=BPF_OP(insn.code);
        size_t next=pc+1;
        if(insn.code==(BPF_LD|BPF_DW|BPF_IMM)){state[insn.dst_reg].reset();++next;}
        else if(cls==BPF_LDX) {
            observe(state[insn.src_reg],insn.off);
            state[insn.dst_reg]=BPF_SIZE(insn.code)==BPF_DW?Range{whole}:std::nullopt;
        } else if(cls==BPF_ST || cls==BPF_STX)observe(state[insn.dst_reg],insn.off);
        else if(cls==BPF_ALU || cls==BPF_ALU64) {
            auto &dst=state[insn.dst_reg];
            if(cls==BPF_ALU)dst.reset();
            else if(op==BPF_MOV)dst=BPF_SRC(insn.code)==BPF_X?state[insn.src_reg]:std::nullopt;
            else if(dst) {
                if((op==BPF_ADD || op==BPF_SUB) && BPF_SRC(insn.code)==BPF_K) {
                    const int64_t delta=op==BPF_ADD?int64_t(insn.imm):-int64_t(insn.imm);
                    dst=bound(dst->first+delta,dst->second+delta);
                } else dst=whole;
            } else if(op==BPF_ADD && BPF_SRC(insn.code)==BPF_X && state[insn.src_reg])dst=whole;
            observe(dst);
        } else if(cls==BPF_JMP || cls==BPF_JMP32) {
            if(op==BPF_EXIT)continue;
            if(op==BPF_CALL) {
                if(calls.contains(static_cast<unsigned>(insn.imm)))
                    for(size_t reg=1;reg<=5;++reg)if(state[reg])required=frame_limit;
                for(size_t reg=0;reg<=5;++reg)state[reg].reset();
            } else {
                push(static_cast<int64_t>(pc)+1+((op==BPF_JA && cls==BPF_JMP32)?insn.imm:insn.off),state);
                if(op==BPF_JA)continue;
            }
        }
        if(next<code.size())push(static_cast<int64_t>(next),state);
    }
    return (required+7)&~7U;
}
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
