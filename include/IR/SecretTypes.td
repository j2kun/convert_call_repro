#ifndef INCLUDE_IR_SECRETTYPES_TD_
#define INCLUDE_IR_SECRETTYPES_TD_

include "SecretDialect.td"

include "mlir/IR/DialectBase.td"
include "mlir/IR/AttrTypeBase.td"

// A base class for all types in this dialect
class Secret_Type<string name, string typeMnemonic>
    : TypeDef<Secret_Dialect, name> {
  let mnemonic = typeMnemonic;
}

def Secret : Secret_Type<"Secret", "secret"> {
  let summary = "A secret value";

  let description = [{
    TODO: add better documentation.
  }];

  let parameters = (ins "Type":$valueType);
  let builders = [
    TypeBuilderWithInferredContext<(ins "Type":$valueType), [{
      return $_get(valueType.getContext(), valueType);
    }]>
  ];
  let hasCustomAssemblyFormat = 1;
  let skipDefaultBuilders = 1;
}

#endif  // INCLUDE_IR_SECRETTYPES_TD_
