
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `Adafruit_MPRLS` class instance
    auto sensor = getValue<input_DEV>(ctx);

    float pressure_PSI = sensor->readPressure();

    emitValue<output_hPa>(ctx,pressure_PSI * 68.947572932);
    emitValue<output_PSI>(ctx,pressure_PSI);
    emitValue<output_DONE>(ctx, 1);
}
