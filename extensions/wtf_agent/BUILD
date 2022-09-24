load(
    "@envoy//bazel:envoy_build_system.bzl",
    "envoy_cc_library",
    "envoy_package",
)

envoy_package()

envoy_cc_library(
    name = "wtf_agent.wasm",
    srcs = [
        "plugin.cc",
    ],
    hdrs = [
        "plugin.h",
    ],
    repository = "@envoy",
    visibility = ["//visibility:public"],
    deps = [
        "@envoy//envoy/buffer:buffer_interface",
        "@envoy//envoy/network:connection_interface",
        "@envoy//envoy/network:filter_interface",
        "@envoy//source/common/common:assert_lib",
        "@envoy//source/common/common:logger_lib",
    ],
)

#load("//bazel:wasm.bzl", "declare_wasm_image_targets")

#wasm_cc_binary(
#    name = "wtf_agent.wasm",
#    srcs = [
        #"plugin.cc",
        #"plugin.h",
#    ],
#    deps = [
        #"@proxy_wasm_cpp_sdk//:proxy_wasm_intrinsics",
#    ],
#)

#declare_wasm_image_targets(
#    name = "wtf_agent",
#    wasm_file = ":wtf_agent.wasm",
#)
