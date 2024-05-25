%module SummerTTS

// %include "carrays.i"
// %array_functions(int, intp);
%{
#define SWIG_FILE_WITH_INIT
#include "SummerTTS.h"
%}
%include "numpy.i"
%init %{
import_array();
%}
%apply (short* INPLACE_ARRAY1, int DIM1) {(short* ret, int len)};
%include "SummerTTS.h"