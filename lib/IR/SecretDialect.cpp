#include "include/IR/SecretDialect.h"

#include "include/IR/SecretDialect.cpp.inc"
#include "include/IR/SecretOps.h"
#include "include/IR/SecretTypes.h"
#include "llvm/include/llvm/ADT/TypeSwitch.h"            // from @llvm-project
#include "mlir/include/mlir/IR/Builders.h"               // from @llvm-project
#include "mlir/include/mlir/IR/DialectImplementation.h"  // from @llvm-project
#define GET_TYPEDEF_CLASSES
#include "include/IR/SecretTypes.cpp.inc"
#define GET_OP_CLASSES
#include "include/IR/SecretOps.cpp.inc"

namespace mlir {
namespace heir {
namespace secret {

//===----------------------------------------------------------------------===//
// Secret dialect.
//===----------------------------------------------------------------------===//

// Dialect construction: there is one instance per context and it registers its
// operations, types, and interfaces here.
void SecretDialect::initialize() {
  addTypes<
#define GET_TYPEDEF_LIST
#include "include/IR/SecretTypes.cpp.inc"
      >();
  addOperations<
#define GET_OP_LIST
#include "include/IR/SecretOps.cpp.inc"
      >();
}

}  // namespace secret
}  // namespace heir
}  // namespace mlir
