#include "SummerTTS.h"
#include <iostream>

SummerTTS::SummerTTS(char * modelName) {
    modelSize = ttsLoadModel(modelName, &dataWeight);
    synthesizer = new SynthesizerTrn(dataWeight, modelSize);
}

void SummerTTS::transformToSound(char * input) {
    std::string line;
    std::string content(input);
    for(auto ch : content) {
        if(ch != '\n') line += ch;
        else {
            line += "  ";
        }
    }

    data = synthesizer->infer(line, 0, 1.0, retLen);
    return;
}

SummerTTS::~SummerTTS() {
    tts_free_data(dataWeight);
    delete synthesizer;
}

int SummerTTS::getRetLen() {
    if(retLen == 0) {
        cout << "error! you should call transformToSound first!" << endl;
    }
    return retLen;
}

void SummerTTS::getRetData(short * ret, int len) {
    if(data == NULL) {
        cout << "error! you should call transformToSound first!" << endl;
    }
    memcpy(ret, data, sizeof(int16_t) * len);
    return;
}