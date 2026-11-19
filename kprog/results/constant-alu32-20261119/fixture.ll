target triple = "bpf"

define i32 @constant8() {
  %v = call i32 asm sideeffect "$0 = $0", "=w,0"(i32 8)
  ret i32 %v
}
define i32 @constant4() {
  %v = call i32 asm sideeffect "$0 = $0", "=w,0"(i32 4)
  ret i32 %v
}
define i32 @constant_negative() {
  %v = call i32 asm sideeffect "$0 = $0", "=w,0"(i32 -1)
  ret i32 %v
}
define i32 @constant_high() {
  %v = call i32 asm sideeffect "$0 = $0", "=w,0"(i32 -2147483648)
  ret i32 %v
}
define i32 @live(i32 %input) {
  %v = call i32 asm sideeffect "$0 = $0", "=w,0"(i32 %input)
  ret i32 %v
}
define i32 @memory_clobber() {
  %v = call i32 asm sideeffect "$0 = $0", "=w,0,~{memory}"(i32 8)
  ret i32 %v
}
define i64 @wide() {
  %v = call i64 asm sideeffect "$0 = $0", "=r,0"(i64 8)
  ret i64 %v
}
