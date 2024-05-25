#include <string.h>
#include <string>
#include "utils.h"
#include "SynthesizerTrn.h"

class SummerTTS {
    public:
        SummerTTS(char * modelName);
        void transformToSound(char * input);
        ~SummerTTS();
        int getRetLen();
        void getRetData(short * ret, int len);
    private:
        float * dataWeight = NULL;
        int modelSize = 0;
        int retLen = 0;
        int16_t * data = NULL;
        SynthesizerTrn * synthesizer;
};