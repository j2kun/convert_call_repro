load("//bazel:lit.bzl", "glob_lit_tests")

package(
    default_visibility = ["//visibility:public"],
)

# Bundle together all of the test utilities that are used by tests.
filegroup(
    name = "test_utilities",
    testonly = True,
    data = [
        "@bug//tests:lit.cfg.py",
        "@bug//tools:bug-opt",
        "@bug_pip_deps_lit//:pkg",
        "@llvm-project//llvm:FileCheck",
        "@llvm-project//llvm:count",
        "@llvm-project//llvm:not",
    ],
)

glob_lit_tests(
    name = "all_tests",
    data = [":test_utilities"],
    driver = "@bug//tests:run_lit.sh",
    test_file_exts = ["mlir"],
)

exports_files(
    [
        "run_lit.sh",
    ],
)
