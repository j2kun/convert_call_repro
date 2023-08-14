#ifndef INCLUDE_TRANSFORMS_FORGETSECRETS_H_
#define INCLUDE_TRANSFORMS_FORGETSECRETS_H_

#include "mlir/include/mlir/Pass/Pass.h"  // from @llvm-project

namespace mlir {
namespace heir {
namespace secret {

#define GEN_PASS_DECL
#include "include/Transforms/Passes.h.inc"

}  // namespace secret
}  // namespace heir
}  // namespace mlir

#endif  // INCLUDE_TRANSFORMS_FORGETSECRETS_H_
