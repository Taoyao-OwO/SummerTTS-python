import SummerTTS
import sounddevice as sd
import numpy as np
from scipy.io import wavfile

tts = SummerTTS.SummerTTS("../models/single_speaker_fast.bin")

tts.transformToSound("朋友们好啊，我是混元形意太极门掌门人马保国，刚才有个朋友问我马老师发生甚么事了，我说怎么回事？给我发了两张截图，我一看！噢，原来是昨天有两个年轻人。")
size = tts.getRetLen()
# print(size)
audio = np.zeros(shape=(size,), dtype=np.int16)
tts.getRetData(audio)

# sd.play(audio, samplerate=16000)
# sd.wait()
rate = 16000
wavfile.write("out.wav", rate, audio)