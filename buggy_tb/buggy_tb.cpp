#include "buggy_tb.h"

void MOTOR_TB_DISPLAY(buggyMotor &m, Potentiometer &ptn, C12832 &lcd) {
    lcd.cls();
    lcd.locate(0, 15);
    lcd.printf("DutyC: %d Period: %d \nDirection: %d Pot: %d", m.get_DutyC(), m.get_Period(), m.get_Direction(), (int)ptn.amplitudeMax(50));
    wait_ms(100);
}
void MOTOR_TB_MAIN(buggyMotor &m, Potentiometer &ptn1, Potentiometer &ptn2, Joystick &jstck) {
    if (jstck.firePressed()) {
        m.set_DutyC(ptn1.amplitudeMax(50));
        }
    if (jstck.upPressed())
        ++m;
    else if (jstck.downPressed())
        --m;
        
    if (ptn2.amplitude16bit() > 32768)
        m.set_Direction(1);
    else
        m.set_Direction(0);
}

void ENCODER_TB_DISPLAY(buggyEncoder &e, C12832 &lcd) {
    lcd.cls();
    lcd.locate(0, 15);
    lcd.printf("Pulse rate: %d \nSpeed(mm/s): %d", e.get_PulseRate(), e.get_Speed());
    wait_ms(100);
}

void ASENSOR_TB_DISPLAY(buggyASensor &s, C12832 &lcd) {
    lcd.cls();
    lcd.locate(0, 15);
    lcd.printf("Analog: %d", s.get_SensorVal());
    wait_ms(100);
}

void SPEED_TB_DISPLAY(buggySpeed &sp, Potentiometer &ptn1, Potentiometer &ptn2, C12832 &lcd) {
    lcd.cls();
    lcd.locate(0, 15);
    lcd.printf("Average speed: %d\nSetL: %d     SetR: %d", sp.get_AvgSpeed(), (int)ptn1.amplitudeMax(100), (int)ptn2.amplitudeMax(100));
    wait_ms(100);
}
void SPEED_TB_MAIN(buggySpeed &sp, Potentiometer &ptn1, Potentiometer &ptn2) {
    sp.set_SetSpeedR((int)ptn2.amplitudeMax(64000), 50);
    sp.set_SetSpeedL((int)ptn1.amplitudeMax(64000), 50);
}