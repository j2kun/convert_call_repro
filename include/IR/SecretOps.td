#ifndef INCLUDE_IR_SECRETOPS_TD_
#define INCLUDE_IR_SECRETOPS_TD_

include "SecretDialect.td"
include "SecretTypes.td"
include "mlir/IR/BuiltinAttributeInterfaces.td"
include "mlir/Interfaces/ControlFlowInterfaces.td"
include "mlir/Interfaces/InferTypeOpInterface.td"
include "mlir/Interfaces/SideEffectInterfaces.td"

class Secret_Op<string mnemonic, list<Trait> traits = []> :
        Op<Secret_Dialect, mnemonic, traits> {
  let cppNamespace = "::mlir::heir::secret";
}

def Secret_ConcealOp : Secret_Op<"conceal", [Pure]> {
  let summary = "Convert a non-secret value into a secret";
  let description = [{
  }];

  let arguments = (ins AnyType:$cleartext);
  let results = (outs Secret:$output);
  let assemblyFormat = "$cleartext attr-dict `:` type($cleartext) `->` type($output)";

  let builders = [
    OpBuilder<(ins "Value":$cleartext)>
  ];
}

def Secret_RevealOp : Secret_Op<"reveal", [Pure]> {
  let summary = "Convert a secret value into a non-secret";
  let description = [{
  }];

  let arguments = (ins Secret:$input);
  let results = (outs AnyType:$cleartext);
  let assemblyFormat = "$input attr-dict `:` type($input) `->` type($cleartext)";

  let builders = [
    OpBuilder<(ins "Value":$secret)>
  ];
}

#endif  // INCLUDE_IR_SECRETOPS_TD_
