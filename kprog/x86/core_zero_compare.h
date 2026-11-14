// The BPF backend may compare a widened field in a 32- or 64-bit register.
// Read the original ELF rather than infer that width from the C field type.
#include "llvm/Object/ELFObjectFile.h"
#include "llvm/Support/Endian.h"
#include <cstring>
#include <optional>

template<class T> static T coreTake(Expected<T> Value) {
  if (!Value) fail(Twine("read CO-RE source ELF: ")+toString(Value.takeError()));
  return std::move(*Value);
}
static std::optional<unsigned> coreFirstZeroJump(ArrayRef<bpf_insn> Code,
                                                size_t At,size_t End,unsigned Reg) {
  for (size_t N=At+1;N<End;++N) {
    const auto &I=Code[N];unsigned Class=BPF_CLASS(I.code);
    if (Class==BPF_JMP || Class==BPF_JMP32) {
      unsigned Op=BPF_OP(I.code);
      if ((Op==BPF_JEQ || Op==BPF_JNE) && BPF_SRC(I.code)==BPF_K &&
          I.dst_reg==Reg && I.imm==0) return Class==BPF_JMP32?32:64;
      return std::nullopt; // A different branch/call needs control-flow analysis.
    }
    if (Class==BPF_LD) {
      if (I.code!=(BPF_LD|BPF_DW|BPF_IMM) || I.dst_reg==Reg || N+1>=End)
        return std::nullopt;
      ++N;
    } else if (Class==BPF_LDX) {
      if (I.dst_reg==Reg || I.src_reg==Reg) return std::nullopt;
    } else if (Class==BPF_ST || Class==BPF_STX) {
      if (I.dst_reg==Reg || (Class==BPF_STX && I.src_reg==Reg)) return std::nullopt;
    } else if (Class==BPF_ALU || Class==BPF_ALU64) {
      if (I.dst_reg==Reg || (BPF_SRC(I.code)==BPF_X && I.src_reg==Reg)) return std::nullopt;
    } else return std::nullopt;
  }
  return std::nullopt;
}
static std::optional<unsigned> coreZeroJumpWidth(StringRef Path,const btf *LocalBTF,
                                                unsigned Id,StringRef Access,
                                                StringRef Function) {
  auto Binary=coreTake(object::createBinary(Path));
  auto *Obj=dyn_cast<object::ObjectFile>(Binary.getBinary());
  if (!Obj || Obj->getArch()!=Triple::bpfel || !Obj->isLittleEndian())
    fail("CO-RE zero comparisons require a little-endian original BPF ELF");
  std::optional<object::SectionRef> FunctionSection;
  uint64_t Begin=0,End=0;
  for (auto S:Obj->symbols()) if (coreTake(S.getName())==Function &&
                                 coreTake(S.getType())==object::SymbolRef::ST_Function) {
    if (FunctionSection) fail("ambiguous original BPF function symbol");
    auto Section=coreTake(S.getSection());
    if (Section==Obj->section_end()) fail("original BPF function has no section");
    FunctionSection=*Section;Begin=coreTake(S.getAddress());
    End=Begin+object::ELFSymbolRef(S).getSize();
  }
  if (!FunctionSection) return std::nullopt;
  auto Name=coreTake(FunctionSection->getName());
  auto Bytes=coreTake(FunctionSection->getContents());
  if (Begin%8 || End%8 || End>Bytes.size() || End<=Begin)
    fail("malformed original BPF function range");
  std::vector<bpf_insn> Code(Bytes.size()/8);
  if (Bytes.size()%8) fail("unaligned original BPF section");
  std::memcpy(Code.data(),Bytes.data(),Bytes.size());
  StringRef Ext;
  for (auto Section:Obj->sections()) if (coreTake(Section.getName())==".BTF.ext")
    Ext=coreTake(Section.getContents());
  if (Ext.size()<32) fail("original BPF ELF lacks extended CO-RE header");
  auto U32=[&](size_t At) {
    if (At>Ext.size() || Ext.size()-At<4) fail("truncated original CO-RE records");
    return support::endian::read32le(Ext.data()+At);
  };
  uint64_t Start=uint64_t(U32(4))+U32(24),Limit=Start+U32(28);
  if (Limit>Ext.size() || Start+4>Limit) fail("invalid original CO-RE record range");
  unsigned RecordBytes=U32(Start);
  if (RecordBytes<16) fail("short original CO-RE relocation record");
  std::optional<unsigned> Width;
  for (uint64_t At=Start+4;At<Limit;) {
    if (Limit-At<8) fail("truncated original CO-RE section");
    const char *SectionName=btf__name_by_offset(LocalBTF,U32(At));
    unsigned Count=U32(At+4);At+=8;
    if (!SectionName || uint64_t(Count)*RecordBytes>Limit-At)
      fail("invalid original CO-RE section records");
    for (unsigned N=0;N<Count;++N,At+=RecordBytes) {
      if (Name!=SectionName || U32(At+4)!=Id || U32(At+12)!=BPF_CORE_FIELD_BYTE_OFFSET) continue;
      const char *Spec=btf__name_by_offset(LocalBTF,U32(At+8));
      if (!Spec) fail("original CO-RE access string absent");
      uint64_t Offset=U32(At);
      if (Access!=Spec || Offset<Begin || Offset>=End) continue;
      if (Offset%8) fail("unaligned original CO-RE instruction");
      const auto &I=Code[Offset/8];
      if (BPF_CLASS(I.code)!=BPF_LDX) continue;
      if (BPF_MODE(I.code)!=BPF_MEM) return std::nullopt;
      auto Current=coreFirstZeroJump(Code,Offset/8,End/8,I.dst_reg);
      if (!Current || (Width && Width!=Current)) return std::nullopt;
      Width=Current;
    }
  }
  return Width;
}
