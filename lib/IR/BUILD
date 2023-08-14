package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "Dialect",
    srcs = [
        "SecretDialect.cpp",
    ],
    hdrs = [
        "@bug//include/IR:SecretDialect.h",
        "@bug//include/IR:SecretOps.h",
        "@bug//include/IR:SecretTypes.h",
    ],
    includes = ["@bug//include"],
    deps = [
        ":SecretOps",
        ":SecretTypes",
        "@llvm-project//llvm:Support",
        "@llvm-project//mlir:IR",
    ],
)

cc_library(
    name = "SecretTypes",
    srcs = [
        "SecretTypes.cpp",
    ],
    hdrs = [
        "@bug//include/IR:SecretDialect.h",
        "@bug//include/IR:SecretTypes.h",
    ],
    includes = ["@bug//include"],
    deps = [
        "@bug//include/IR:dialect_inc_gen",
        "@bug//include/IR:types_inc_gen",
        "@llvm-project//llvm:Support",
        "@llvm-project//mlir:IR",
        "@llvm-project//mlir:InferTypeOpInterface",
    ],
)

cc_library(
    name = "SecretOps",
    srcs = [
        "SecretOps.cpp",
    ],
    hdrs = [
        "@bug//include/IR:SecretDialect.h",
        "@bug//include/IR:SecretOps.h",
        "@bug//include/IR:SecretTypes.h",
    ],
    includes = ["@bug//include"],
    deps = [
        "@bug//include/IR:dialect_inc_gen",
        "@bug//include/IR:ops_inc_gen",
        "@bug//include/IR:types_inc_gen",
        "@llvm-project//llvm:Support",
        "@llvm-project//mlir:ControlFlowInterfaces",
        "@llvm-project//mlir:IR",
        "@llvm-project//mlir:InferTypeOpInterface",
    ],
)
