#ifndef TMAP_H
#define	TMAP_H

// Temperature = Index / 2 (Tempreatures in 0.5 °C increments)
// Voltage = Value
extern const float temperature_map[201];

float LookupTemperature(float voltage);


#endif	/* TMAP_H */

