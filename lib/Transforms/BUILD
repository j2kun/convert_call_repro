package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "Transforms",
    hdrs = [
        "@bug//include/Transforms:Passes.h",
    ],
    deps = [
        ":ForgetSecrets",
        "@llvm-project//mlir:IR",
    ],
)

cc_library(
    name = "ForgetSecrets",
    srcs = ["ForgetSecrets.cpp"],
    hdrs = [
        "@bug//include/Transforms:ForgetSecrets.h",
    ],
    includes = ["@bug//include"],
    deps = [
        "@bug//include/Transforms:pass_inc_gen",
        "@bug//lib/IR:SecretOps",
        "@llvm-project//mlir:FuncDialect",
        "@llvm-project//mlir:FuncTransforms",
        "@llvm-project//mlir:IR",
        "@llvm-project//mlir:Pass",
        "@llvm-project//mlir:Transforms",
    ],
)
