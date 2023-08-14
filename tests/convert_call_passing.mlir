// RUN: bug-opt %s --secret-forget-secrets | FileCheck %s

func.func @example_fn(
    %s1 : !secret.secret<i32>) -> !secret.secret<i32> {
  func.return %s1 : !secret.secret<i32>
}

func.func @test_convert_call() -> i32 {
  %0 = arith.constant 7 : i32
  %1 = secret.conceal %0 : i32 -> !secret.secret<i32>
  // CHECK-NOT: secret
  %4 = func.call @example_fn(%1) : (!secret.secret<i32>) -> !secret.secret<i32>
  %5 = secret.reveal %4 : !secret.secret<i32> -> i32
  func.return %5 : i32
}
