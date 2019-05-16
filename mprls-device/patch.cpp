// Tell XOD where it could download the library:
#pragma XOD require "https://github.com/WaylandM/MTW_Adafruit_MPRLS"

//Include C++ libraries
{{#global}}
#include <Wire.h>
#include <MTW_Adafruit_MPRLS.h>
{{/global}}

// Reserve memory to store an instance of the class,
// and create the instance later:
struct State {
    uint8_t mem[sizeof(Adafruit_MPRLS)];
};

// Define our custom type as a pointer on the class instance.
using Type = Adafruit_MPRLS*;

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // It should be evaluated only once on the first (setup) transaction
    if (!isSettingUp())
        return;

    auto state = getState(ctx);

    // Create a new object in the memory area reserved previously.
    Type sensor = new (state->mem) Adafruit_MPRLS();

    emitValue<output_DEV>(ctx, sensor);
}
