/* Detect selecting equal-length anonymous startup probes by length or order. */
#include "native_loader_manifest.hpp"
#include <filesystem>
#include <iostream>
#include <sstream>
#include <iomanip>

int main(int argc, char **argv) {
    if(argc!=2)return 2;
    const std::filesystem::path directory=argv[1];
    std::filesystem::create_directories(directory);
    const auto manifest=directory/"manifest.json";
    const auto native=directory/"native.o";
    {std::ofstream out(native);out<<"manifest resolver fixture";if(!out)return 1;}
    std::vector<bpf_insn> zero(2), one(2);
    zero[0].code=BPF_ALU64|BPF_MOV|BPF_K;zero[1].code=BPF_JMP|BPF_EXIT;
    one=zero;one[0].imm=1;
    auto hex=[](const auto &code){std::ostringstream out;out<<std::hex<<std::setfill('0');
        const auto *bytes=reinterpret_cast<const unsigned char *>(code.data());
        for(size_t i=0;i<code.size()*sizeof(bpf_insn);++i)out<<std::setw(2)<<unsigned(bytes[i]);
        return out.str();};
    const auto z=hex(zero),o=hex(one);
    auto entry=[&](std::string program,std::string selector,std::string symbol){
        return "{\"program\":\""+program+"\",\"native_object\":\"native.o\",\"symbol\":\""+symbol+"\""+selector+"}";};
    auto write=[&](std::string body){std::ofstream out(manifest);out<<"{\"objects\":["<<body<<"]}";
        if(!out)throw std::runtime_error("write manifest failed");};
    auto select=[&](const auto &code,std::string name=""){
        bpf_prog_info info{};info.type=BPF_PROG_TYPE_SOCKET_FILTER;
        if(name.size()>=sizeof(info.name))throw std::runtime_error("test name too long");
        std::memcpy(info.name,name.data(),name.size());
        return resolve_native_manifest(manifest,info,code,[](int){return bpf_map_info{};});};
    unsigned checks=0;
    auto require=[&](bool condition){if(!condition)throw std::runtime_error("manifest regression");++checks;};
    auto fails=[&](auto test,const char *message){try{test();}catch(const std::runtime_error &error){
        if(std::string(error.what()).find(message)==std::string::npos)throw;
        ++checks;return;}
        throw std::runtime_error("malformed manifest accepted");};
    write(entry("",",\"source_bytecode_hex\":\""+o+"\"","one")+","+
          entry("",",\"source_bytecode_hex\":\""+z+"\"","zero"));
    require(select(zero)->symbol_name=="zero");require(select(one)->symbol_name=="one");
    write(entry("",",\"source_bytecode_hex\":\""+z+"\"","zero"));
    require(!select(one));
    auto upper=z;for(char &ch:upper)ch=std::toupper(static_cast<unsigned char>(ch));
    write(entry("",",\"source_bytecode_hex\":\""+upper+"\"","zero"));require(select(zero).has_value());
    write(entry("","","zero"));fails([&]{select(zero);},"requires source_bytecode_hex");
    for(auto bad: {std::string("b7"),std::string(z.size(),'q')}){
        write(entry("",",\"source_bytecode_hex\":\""+bad+"\"","zero"));
        fails([&]{select(zero);},bad=="b7"?"complete BPF instructions":"non-hexadecimal");}
    write(entry("",",\"source_bytecode_hex\":\""+z+z+"\"","zero"));require(!select(zero));
    write(entry("",",\"source_bytecode_hex\":\""+z+"\",\"prog_type\":6","zero"));require(!select(zero));
    write(entry("",",\"source_bytecode_hex\":\""+z+"\"","zero")+","+
          entry("",",\"source_bytecode_hex\":\""+z+"\"","other"));
    fails([&]{select(zero);},"ambiguous entries");
    write(entry("named","","legacy"));require(select(zero,"named")->symbol_name=="legacy");
    std::cout<<"anonymous exact-byte selection PASS ("<<checks<<" checks)\n";
}
