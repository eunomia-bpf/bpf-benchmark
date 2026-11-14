target triple = "bpf"
define i32 @tied(ptr %ctx) section "xdp" {
%endptr = getelementptr i8, ptr %ctx, i64 4
%start32 = load volatile i32, ptr %ctx, align 4
%end32 = load volatile i32, ptr %endptr, align 4
%opaque = call i32 asm sideeffect "", "=r,0"(i32 %end32)
%start = zext i32 %start32 to i64
%end = zext i32 %opaque to i64
%length = sub i64 %end, %start
%short = icmp ult i64 %length, 64
%result = zext i1 %short to i32
ret i32 %result
}
define i32 @untied(ptr %ctx) section "xdp" {
%endptr = getelementptr i8, ptr %ctx, i64 4
%start32 = load volatile i32, ptr %ctx, align 4
%end32 = load volatile i32, ptr %endptr, align 4
%opaque = call i32 asm sideeffect "", "=r,r"(i32 %end32)
%start = zext i32 %start32 to i64
%end = zext i32 %opaque to i64
%length = sub i64 %end, %start
%short = icmp ult i64 %length, 64
%result = zext i1 %short to i32
ret i32 %result
}
