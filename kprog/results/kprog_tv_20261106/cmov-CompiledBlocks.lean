import BPF
namespace KProgTV.Compiled
def tv_cmov16 : Array KProgFormal.Reference.Byte := #[0xbf, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x57, 0x03, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x15, 0x03, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x57, 0x02, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x57, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x4f, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbf, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x95, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]
@[simp] theorem tv_cmov16_decode_0 : BPF.decode tv_cmov16 0 = .ok ⟨191, 0, 1, 0, 0⟩ := by rfl
@[simp] theorem tv_cmov16_decode_1 : BPF.decode tv_cmov16 1 = .ok ⟨87, 3, 0, 0, 64⟩ := by rfl
@[simp] theorem tv_cmov16_decode_2 : BPF.decode tv_cmov16 2 = .ok ⟨21, 3, 0, 4, 0⟩ := by rfl
@[simp] theorem tv_cmov16_decode_3 : BPF.decode tv_cmov16 3 = .ok ⟨87, 2, 0, 0, 65535⟩ := by rfl
@[simp] theorem tv_cmov16_decode_4 : BPF.decode tv_cmov16 4 = .ok ⟨87, 0, 0, 0, 4294901760⟩ := by rfl
@[simp] theorem tv_cmov16_decode_5 : BPF.decode tv_cmov16 5 = .ok ⟨79, 2, 0, 0, 0⟩ := by rfl
@[simp] theorem tv_cmov16_decode_6 : BPF.decode tv_cmov16 6 = .ok ⟨191, 0, 2, 0, 0⟩ := by rfl
@[simp] theorem tv_cmov16_decode_7 : BPF.decode tv_cmov16 7 = .ok ⟨149, 0, 0, 0, 0⟩ := by rfl
def tv_cmov32 : Array KProgFormal.Reference.Byte := #[0xbf, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x57, 0x03, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x15, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbf, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x67, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x77, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x95, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]
@[simp] theorem tv_cmov32_decode_0 : BPF.decode tv_cmov32 0 = .ok ⟨191, 0, 1, 0, 0⟩ := by rfl
@[simp] theorem tv_cmov32_decode_1 : BPF.decode tv_cmov32 1 = .ok ⟨87, 3, 0, 0, 64⟩ := by rfl
@[simp] theorem tv_cmov32_decode_2 : BPF.decode tv_cmov32 2 = .ok ⟨21, 3, 0, 1, 0⟩ := by rfl
@[simp] theorem tv_cmov32_decode_3 : BPF.decode tv_cmov32 3 = .ok ⟨191, 0, 2, 0, 0⟩ := by rfl
@[simp] theorem tv_cmov32_decode_4 : BPF.decode tv_cmov32 4 = .ok ⟨103, 0, 0, 0, 32⟩ := by rfl
@[simp] theorem tv_cmov32_decode_5 : BPF.decode tv_cmov32 5 = .ok ⟨119, 0, 0, 0, 32⟩ := by rfl
@[simp] theorem tv_cmov32_decode_6 : BPF.decode tv_cmov32 6 = .ok ⟨149, 0, 0, 0, 0⟩ := by rfl
def tv_cmov64 : Array KProgFormal.Reference.Byte := #[0xbf, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x57, 0x03, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x15, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbf, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x95, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]
@[simp] theorem tv_cmov64_decode_0 : BPF.decode tv_cmov64 0 = .ok ⟨191, 0, 1, 0, 0⟩ := by rfl
@[simp] theorem tv_cmov64_decode_1 : BPF.decode tv_cmov64 1 = .ok ⟨87, 3, 0, 0, 64⟩ := by rfl
@[simp] theorem tv_cmov64_decode_2 : BPF.decode tv_cmov64 2 = .ok ⟨21, 3, 0, 1, 0⟩ := by rfl
@[simp] theorem tv_cmov64_decode_3 : BPF.decode tv_cmov64 3 = .ok ⟨191, 0, 2, 0, 0⟩ := by rfl
@[simp] theorem tv_cmov64_decode_4 : BPF.decode tv_cmov64 4 = .ok ⟨149, 0, 0, 0, 0⟩ := by rfl
@[simp] theorem imm_0 : (BitVec.ofNat 32 0).signExtend 64 = BitVec.ofNat 64 0 := by decide
@[simp] theorem imm_32 : (BitVec.ofNat 32 32).signExtend 64 = BitVec.ofNat 64 32 := by decide
@[simp] theorem imm_64 : (BitVec.ofNat 32 64).signExtend 64 = BitVec.ofNat 64 64 := by decide
@[simp] theorem imm_65535 : (BitVec.ofNat 32 65535).signExtend 64 = BitVec.ofNat 64 65535 := by decide
@[simp] theorem imm_4294901760 : (BitVec.ofNat 32 4294901760).signExtend 64 = BitVec.ofNat 64 18446744073709486080 := by decide
@[simp] theorem off_0 : (BitVec.ofNat 16 0).toInt = (0 : Int) := by decide
@[simp] theorem off_1 : (BitVec.ofNat 16 1).toInt = (1 : Int) := by decide
@[simp] theorem off_4 : (BitVec.ofNat 16 4).toInt = (4 : Int) := by decide
end KProgTV.Compiled
