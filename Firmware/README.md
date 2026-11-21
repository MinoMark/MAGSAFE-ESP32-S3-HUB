# About Firmware

This took me a while to learn. I've used about 30% AI to help me make the code. I've also used it at the end after coding to clean up the rest and make it more efficient. Of course, I tried doing it myself, then got AI to finish it off. I used it to only help me with this and NOT do it for me.

## Explaining the code to prove I understand it

There are libraries and pins, and each one has one or more jobs. For example, SPI communicates between the screen and the touchscreen chip. Stuff like Adafruit_GFX allows you to draw things like triangles etc.

I searched it up and looked in old forums (not outdated) on creating the objects.

Adafruit_ILI9341 tft = Adafruit_ILI9341(&SPI, tftDC, tftCS, tftReset);
XPT2046_Touchscreen touch(touchCS);
I2SClass i2s;

I used things like this to create objects for the tft screen, touch, and the i2s for audio. After this, everything else is done through these, like tft.print(...) or touch.touched().

I created some basic sound settings so I can tweak them or use them later in the code. Stuff like int sampleRate = 22050;.

Now the tricky part. Making the sound with playNote(). I've learnt that a pure tone is a sine wave. This is basically a smooth wave that just goes up and down. The function builds it one number at a time.

Now it's time for the user interface. This is the part that I or anyone else will be interacting with to make sound play or change the volume. I used showVolume(), which draws a grey box in the middle showing "Vol 5". It reuses the button() function because it looks the same.
