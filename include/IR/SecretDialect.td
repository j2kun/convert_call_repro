#ifndef INCLUDE_IR_SECRETDIALECT_TD_
#define INCLUDE_IR_SECRETDIALECT_TD_

include "mlir/IR/DialectBase.td"

def Secret_Dialect : Dialect {
  let name = "secret";
  let summary = "A dialect for computations that operate on encrypted secrets.";
  let description = [{
    TODO: better documentation (this is a prototype).
  }];

  let cppNamespace = "::mlir::heir::secret";
  let useDefaultTypePrinterParser = 1;
}

#endif  // INCLUDE_IR_SECRETDIALECT_TD_
