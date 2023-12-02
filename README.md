# GPS_NMEA_data_to_location
Obtain location from GY-NEO6MV2 GPS NMEA data without fixing by parsing in Arduino.

GPS gives us NMEA data. In this data, we can find some values about latitude, longitude, time, speed and altitude.
Sometimes GPS libraries don't give us any output, because they wait for fixing. Fixing is to complete all values in the NMEA data.
Thanks to this parsing code we are not waiting for time, speed or altitude. If you need only latitude and longitude this code gives you that.

I hope this code can help you.
