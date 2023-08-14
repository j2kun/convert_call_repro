#ifndef INCLUDE_TRANSFORMS_PASSES_H_
#define INCLUDE_TRANSFORMS_PASSES_H_

#include "include/IR/SecretDialect.h"
#include "include/Transforms/ForgetSecrets.h"

namespace mlir {
namespace heir {
namespace secret {

#define GEN_PASS_REGISTRATION
#include "include/Transforms/Passes.h.inc"

}  // namespace secret
}  // namespace heir
}  // namespace mlir

#endif  // INCLUDE_TRANSFORMS_PASSES_H_
