#ifndef RGBLED_H
#define RGBLED_H

class RgbLed {
private:
    int redPin;
    int greenPin;
    int bluePin;

public:
    void on();
    void off();
    void set_color(int red, int green, int blue);
};

#endif // RGBLED_H