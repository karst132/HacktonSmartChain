#include "RelationStateFacade.h"
#include <Arduino.h>

RelationStateFacade::RelationStateFacade(IRgbLed* rgbLed, IButton* button, int (*colors)[3], int colorCount) 
    : rgbLed(rgbLed), button(button), colors(colors), colorCount(colorCount), currentColorIndex(0) {
}

void RelationStateFacade::loop() {
    // Update button state
    button->update();
    
    // Check if button was pressed (only triggers once per press)
    if (button->has_been_pressed()) {
        // Get current color values
        int red = colors[currentColorIndex][0];
        int green = colors[currentColorIndex][1];
        int blue = colors[currentColorIndex][2];
        
        // Print to serial monitor
        Serial.print("Color Index: ");
        Serial.print(currentColorIndex);
        Serial.print(" | RGB: ");
        Serial.print(red);
        Serial.print(", ");
        Serial.print(green);
        Serial.print(", ");
        Serial.println(blue);
        
        // Set the LED color
        rgbLed->set_color(red, green, blue);
        
        // Move to next color (cycle back to 0 at the end)
        currentColorIndex = (currentColorIndex + 1) % colorCount;
    }
}