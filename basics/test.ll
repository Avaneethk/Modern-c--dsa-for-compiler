define i32 @foo() {
entry:
  %1 = add i32 10,20
  %2 = mul i32 %1,2
  %3 = add i32 %2,100

  ret i32 10
}