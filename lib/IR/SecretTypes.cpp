#include "include/IR/SecretTypes.h"

namespace mlir {
namespace heir {
namespace secret {

void SecretType::print(AsmPrinter &printer) const {
  printer << "<";
  printer.printType(getValueType());
  printer << '>';
}

Type SecretType::parse(mlir::AsmParser &parser) {
  Type ty;
  if (parser.parseLess() || parser.parseType(ty) || parser.parseGreater()) {
    parser.emitError(parser.getNameLoc(), "failed to parse secret value type");
    return Type();
  }
  return SecretType::get(ty);
}

}  // namespace secret
}  // namespace heir
}  // namespace mlir
