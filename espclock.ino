#include <Arduino.h>

#include <WiFiManager.h>

void setup(void)
{
    Serial.begin(115200);

    WiFiManager wifiManager;
    wifiManager.autoConnect("ESPKLOK");

    configTime("CET-1CEST,M3.5.0/02,M10.5.0/03", "nl.pool.ntp.org");
}

void loop(void)
{
    static time_t last = 0;

    time_t now;
    time(&now);

    if (now != last) {
        last = now;
        struct tm * info = localtime(&now);
        Serial.printf("Date/time is now %4d-%02d-%02d %02d:%02d:%02d\n",
            1900 + info->tm_year, 1 + info->tm_mon, info->tm_mday,
            info->tm_hour, info->tm_min, info->tm_sec);
    }
}

