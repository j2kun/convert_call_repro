#include "include/IR/SecretOps.h"

namespace mlir {
namespace heir {
namespace secret {

void ConcealOp::build(OpBuilder &builder, OperationState &result,
                      Value cleartextValue) {
  Type resultType = SecretType::get(cleartextValue.getType());
  build(builder, result, resultType, cleartextValue);
}

void RevealOp::build(OpBuilder &builder, OperationState &result,
                      Value secretValue) {
  Type resultType = llvm::dyn_cast<SecretType>(secretValue.getType()).getValueType();
  build(builder, result, resultType, secretValue);
}

}  // namespace secret
}  // namespace heir
}  // namespace mlir
