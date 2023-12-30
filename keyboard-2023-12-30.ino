
#include <Keyboard.h>

int endnum = 0;
unsigned long starttime;
unsigned long stoptime;
unsigned long startdelaytime;
unsigned long stopdelaytime;
int tontsu[] = {0};
int alphamorusu[] = {0, 0, 101, 116, 105, 97, 110, 109, 115, 117, 114, 119, 100, 107, 103, 111, 104, 118, 102, 8, 108, 32, 112, 106, 98, 120, 99, 121, 122, 113, 45, 0, 10, 44, 46, 33, 63};

int memore = 1;
int ia = 0;

void setup() {
    // put your setup code here, to run once:
    pinMode(4, INPUT_PULLUP);

    Keyboard.begin(); // キーボードライブラリを初期化
    //Serial.begin(115200);
    //while (!Serial);
    //Serial.println("start");
}

void loop() {
    if (digitalRead(4) == LOW) {
        starttime = millis();
        while (digitalRead(4) == LOW) {};
        stoptime = millis();
        if (stoptime - starttime >= 10) {
            //Serial.print(stoptime - starttime);
            if (stoptime - starttime >= 160) { // threshold = 100ms
                //Serial.print("-");
                tontsu[endnum] = 2;
            } else {
                //Serial.print(".");
                tontsu[endnum] = 1;
            };
            endnum += 1;
        };
        startdelaytime = millis();
    }
    stopdelaytime = millis();


    if (stopdelaytime - startdelaytime >= 200) { // mojinokugiri = 200ms
        if (endnum != 0) {
            //Serial.println("end");
            int memore = 1;

            for (int i = 0; i < endnum; i++) {
                if (tontsu[i] == 1 || tontsu[i] == 2) {
                    memore += tontsu[i] * pow(2, endnum - i - 1);
                    tontsu[i] = 0;
                } else {

                    break;
                }


            };

            if (alphamorusu[memore] != 0 && memore <= 40) {
                //Serial.println(alphamorusu[memore] +60);
                Keyboard.write(alphamorusu[memore]);
            }
            int tontsu[] = {0};
            endnum = 0;
        };
    };


}
