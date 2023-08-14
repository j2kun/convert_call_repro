package(
    default_visibility = ["//visibility:public"],
)

# Custom `mlir-opt` replacement that links our dialect and passes
cc_binary(
    name = "bug-opt",
    srcs = ["bug-opt.cpp"],
    includes = ["include"],
    deps = [
        "@bug//lib/IR:Dialect",
        "@bug//lib/Transforms",
        "@llvm-project//mlir:AffineDialect",
        "@llvm-project//mlir:AllPassesAndDialects",
        "@llvm-project//mlir:ArithDialect",
        "@llvm-project//mlir:FuncDialect",
        "@llvm-project//mlir:MemRefDialect",
        "@llvm-project//mlir:MlirOptLib",
        "@llvm-project//mlir:Pass",
        "@llvm-project//mlir:SCFDialect",
    ],
)
