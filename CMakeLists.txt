cmake_minimum_required(VERSION 3.5)

project(SummerTTS LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "-fPIC -O3 -fopenmp -std=c++11 ")
set(CMAKE_C_FLAGS "-fPIC -O3 -fopenmp -std=c++11 ")

include_directories(./eigen-3.4.0
                    ./src/tn/header
                    ./include
                    ./src/header)

find_package (Python3 COMPONENTS Interpreter Development)
include_directories(${Python3_INCLUDE_DIRS})
link_libraries(${Python3_LIBRARIES})

include_directories(${PROJECT_SOURCE_DIR}/src)

find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})

set(CMAKE_SWIG_OUTDIR ${CMAKE_CURRENT_BINARY_DIR}/python)
set(SWIG_OUTFILE_DIR ${CMAKE_CURRENT_BINARY_DIR}/cpp)

set_property(SOURCE ./src/SummerTTS.i PROPERTY CPLUSPLUS ON)
swig_add_library(SummerTTS LANGUAGE python SOURCES ./src/SummerTTS.i ./src/SummerTTS.cpp ./src/SummerTTS.h
./src/tn/glog/src/demangle.cc
./src/tn/glog/src/logging.cc
./src/tn/glog/src/raw_logging.cc
./src/tn/glog/src/symbolize.cc
./src/tn/glog/src/utilities.cc
./src/tn/glog/src/vlog_is_on.cc
./src/tn/glog/src/signalhandler.cc
./src/tn/gflags/src/gflags.cc
./src/tn/gflags/src/gflags_reporting.cc
./src/tn/gflags/src/gflags_completions.cc
./src/tn/openfst/src/lib/compat.cc
./src/tn/openfst/src/lib/flags.cc
./src/tn/openfst/src/lib/fst.cc
./src/tn/openfst/src/lib/fst-types.cc
./src/tn/openfst/src/lib/mapped-file.cc
./src/tn/openfst/src/lib/properties.cc
./src/tn/openfst/src/lib/symbol-table.cc
./src/tn/openfst/src/lib/symbol-table-ops.cc
./src/tn/openfst/src/lib/util.cc
./src/tn/openfst/src/lib/weight.cc
./src/tn/processor.cc
./src/tn/token_parser.cc
./src/tn/utf8_string.cc
./src/engipa/EnglishText2Id.cpp
./src/engipa/InitIPASymbols.cpp
./src/engipa/alphabet.cpp
./src/engipa/ipa.cpp
./src/hz2py/hanzi2phoneid.cpp
./src/hz2py/Hanz2Piny.cpp
./src/hz2py/pinyinmap.cpp
./src/nn_op/nn_conv1d.cpp
./src/nn_op/nn_softmax.cpp
./src/nn_op/nn_layer_norm.cpp
./src/nn_op/nn_relu.cpp
./src/nn_op/nn_gelu.cpp
./src/nn_op/nn_tanh.cpp
./src/nn_op/nn_flip.cpp
./src/nn_op/nn_cumsum.cpp
./src/nn_op/nn_softplus.cpp
./src/nn_op/nn_clamp_min.cpp
./src/nn_op/nn_sigmoid.cpp
./src/nn_op/nn_conv1d_transposed.cpp
./src/nn_op/nn_leaky_relu.cpp
./src/platform/tts_file_io.cpp
./src/platform/tts_logger.cpp
./src/utils/utils.cpp
./src/modules/iStft.cpp
./src/modules/hann.cpp
./src/modules/attention_encoder.cpp
./src/modules/multi_head_attention.cpp
./src/modules/ffn.cpp
./src/modules/ConvFlow.cpp
./src/modules/DDSConv.cpp
./src/modules/ElementwiseAffine.cpp
./src/modules/random_gen.cpp
./src/modules/ResidualCouplingLayer.cpp
./src/modules/ResBlock1.cpp
./src/modules/WN.cpp
./src/modules/pqmf.cpp
./src/models/TextEncoder.cpp
./src/models/StochasticDurationPredictor.cpp
./src/models/FixDurationPredictor.cpp
./src/models/DurationPredictor_base.cpp
./src/models/ResidualCouplingBlock.cpp
./src/models/Generator_base.cpp
./src/models/Generator_hifigan.cpp
./src/models/Generator_MS.cpp
./src/models/Generator_Istft.cpp
./src/models/Generator_MBB.cpp
./src/models/SynthesizerTrn.cpp)              